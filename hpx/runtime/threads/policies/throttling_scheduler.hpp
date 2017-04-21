//  Copyright (c) 2007-2017 Hartmut Kaiser
//  Copyright (c) 2011      Bryce Lelbach
//  Copyright (c) 2014      Allan Porterfield
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_THREADMANAGER_SCHEDULING_THROTTLING_POLICY_APR_14_2017_1447PM)
#define HPX_THREADMANAGER_SCHEDULING_THROTTLING_POLICY_APR_14_2017_1447PM

#include <hpx/config.hpp>

#if defined(HPX_HAVE_THROTTLING_SCHEDULER) && defined(HPX_HAVE_ALLSCALE)
#include <hpx/runtime/threads/policies/local_queue_scheduler.hpp>
#include <hpx/runtime/get_worker_thread_num.hpp>
#include <hpx/runtime/threads_fwd.hpp>

#include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <time.h>
#include <vector>

#include <hpx/config/warnings_prefix.hpp>

static boost::shared_mutex init_mutex;


///////////////////////////////////////////////////////////////////////////////
namespace hpx { namespace threads { namespace policies
{
    ///////////////////////////////////////////////////////////////////////////
    /// The throttling_scheduler extends local_queue_scheduler.
    /// The local_queue_scheduler maintains exactly one queue of work
    /// items (threads) per OS thread, where this OS thread pulls its next work
    /// from. Additionally it maintains separate queues: several for high
    /// priority threads and one for low priority threads.
    /// High priority threads are executed by the first N OS threads before any
    /// other work is executed. Low priority threads are executed by the last
    /// OS thread whenever no other work is available. 
    template <typename Mutex = boost::mutex,
        typename PendingQueuing = lockfree_fifo,
        typename StagedQueuing = lockfree_fifo,
        typename TerminatedQueuing = lockfree_lifo>
    class HPX_EXPORT throttling_scheduler
      : public local_queue_scheduler<
            Mutex, PendingQueuing, StagedQueuing, TerminatedQueuing>
    {
    private:
        typedef local_queue_scheduler<
                Mutex, PendingQueuing, StagedQueuing, TerminatedQueuing
            > base_type;

    public:
        typedef typename base_type::has_periodic_maintenance
            has_periodic_maintenance;
        typedef typename base_type::thread_queue_type thread_queue_type;
        typedef typename base_type::init_parameter_type init_parameter_type;

        using local_queue_scheduler<
            Mutex, PendingQueuing, StagedQueuing, TerminatedQueuing>::queues_;
        using local_queue_scheduler<
            Mutex, PendingQueuing, StagedQueuing, TerminatedQueuing>::cond_; 
        using local_queue_scheduler<
            Mutex, PendingQueuing, StagedQueuing, TerminatedQueuing>::curr_queue_;


        throttling_scheduler(init_parameter_type const& init,
                bool deferred_initialization = true)
          : base_type(init, deferred_initialization)
        {
            disabled_os_threads_.resize(hpx::get_os_thread_count());
        }

        virtual ~throttling_scheduler()
        {
//            enable_more(disabled_os_threads_.size());	   //Does it make sense here?
        }

        static std::string get_scheduler_name()
        {
            return "throttling_scheduler";
        }

	/// Check if the OS thread disabled
        bool disabled(std::size_t shepherd) {
             return disabled_os_threads_[shepherd];
        }

        /// Return the next thread to be executed, return false if none is
        /// available
        virtual bool get_next_thread(std::size_t num_thread, bool running,
            std::int64_t& idle_loop_count, threads::thread_data*& thrd)
        {
	    //Drain the queue of the disableed OS thread
            while (disabled(num_thread)) {
                thread_queue_type* q = queues_[num_thread];
	        while (q->get_next_thread(thrd)) {
		      this->wait_or_add_new(num_thread, running, idle_loop_count) ;
        	      this->schedule_thread(thrd, num_thread, thread_priority_unknown); 
		}

		boost::chrono::milliseconds period(1);
		boost::unique_lock<boost::mutex> l(mtx_);
        	cond_.wait_for(l, period);
            }

            // grab work if available
            return this->base_type::get_next_thread(
                num_thread, running, idle_loop_count, thrd);
        }


        /// Schedule the passed thread
        void schedule_thread(threads::thread_data* thrd, std::size_t num_thread,
            thread_priority priority = thread_priority_normal)
        {
	    // Loop and find a thread that is not disabled
            if (std::size_t(-1) == num_thread)
               num_thread = curr_queue_++ % queues_.size();
	    else 
	    {
		    for(std::size_t tid=0; tid<queues_.size(); tid++) { 
		    // Loop and find a thread that is not disabled
			    if (!disabled(tid)) {
				    num_thread = tid; 
				    break;
			    }
		    }
	    }

	    HPX_ASSERT(num_thread < queues_.size());

	    queues_[num_thread]->schedule_thread(thrd);
        }

	/// Disables specific OS thread requested by the user/application
        void disable(std::size_t shepherd) 
	{
		std::lock_guard<mutex_type> l(throttle_mtx_);
		
		if (disabled(shepherd))
		    return;

	        if (disabled_os_threads_.size() - disabled_os_threads_.count() < 2 ) {
		    return;
		}

		const std::size_t wtid = hpx::get_worker_thread_num();

		if (shepherd == wtid)
		   return;

		if (shepherd >= disabled_os_threads_.size()) {
		    HPX_THROW_EXCEPTION(hpx::bad_parameter, "throttling_scheduler::disable",
			"invalid thread number");
		}

		if (!disabled(shepherd)) {
		    disabled_os_threads_[shepherd] = true;
		}
	}

	/// Decides itself which OS threads to disable.
	/// Currently it picks up thread ids sequentially
        void disable_more(std::size_t num_threads = 1)
        {
                std::lock_guard<mutex_type> l(throttle_mtx_);

                if (num_threads >= disabled_os_threads_.size()) {
                   HPX_THROW_EXCEPTION(hpx::bad_parameter, "throttling_scheduler::disable_more",
                        "invalid number of threads");
                }

	        if (disabled_os_threads_.size() - disabled_os_threads_.count() < 2 ) {
                    return;
                }

		const std::size_t wtid = hpx::get_worker_thread_num();

                std::size_t cnt = 0;
                for (std::size_t i=0; i<disabled_os_threads_.size(); i++)
                    if (!disabled_os_threads_[i] && i != wtid) {
                       disabled_os_threads_[i] = true;
                       cnt++;
                       std::cout << "Disable worker_id: " << i << std::endl;
                       if (cnt == num_threads) break;
                    }
        }

	/// Enable specific OS thread requested by the user/application
 	void enable(std::size_t shepherd) 
	{
	        std::lock_guard<mutex_type> l(throttle_mtx_);

		if (shepherd == -1)
		   return;

		if (shepherd >= disabled_os_threads_.size()) {
		    HPX_THROW_EXCEPTION(hpx::bad_parameter, "throttling_scheduler::enable",
			"invalid thread number");
		}

	        disabled_os_threads_[shepherd] = false; 
		cond_.notify_one();
	}


	/// Decides itself which OS threads to enable.
	/// Currently it picks up thread ids sequentially
        void enable_more(std::size_t num_threads = 1)
        {
                std::lock_guard<mutex_type> l(throttle_mtx_);

		std::size_t cnt = 0;
                if (disabled_os_threads_.any()) {
                   for (std::size_t i=0; i<disabled_os_threads_.size(); i++)
                       if (disabled_os_threads_[i]) {
                          disabled_os_threads_[i] = false;
                          cond_.notify_one();
			  cnt++;
                          std::cout << "Enabled worker_id: " << i << std::endl;
			  if (cnt == num_threads) break;
                       }
                }
        }

	/// Return the thread bitset 
	boost::dynamic_bitset<> const & get_disabled_os_threads()
	{
		return disabled_os_threads_;
	}

    protected:
	typedef hpx::lcos::local::spinlock mutex_type;
	mutex_type throttle_mtx_;
	mutable boost::mutex mtx_;
        mutable boost::dynamic_bitset<> disabled_os_threads_;
    };
}}}

#include <hpx/config/warnings_suffix.hpp>

#endif

#endif
