//  Copyright (c) 2007-2013 Hartmut Kaiser
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_RUNTIME_THREADS_DETAIL_CREATE_WORK_JAN_13_2013_0526PM)
#define HPX_RUNTIME_THREADS_DETAIL_CREATE_WORK_JAN_13_2013_0526PM

#include <hpx/config.hpp>
#include <hpx/errors.hpp>
#include <hpx/logging.hpp>
#include <hpx/threading_base/scheduler_base.hpp>
#include <hpx/threading_base/thread_data.hpp>
#include <hpx/threading_base/thread_init_data.hpp>

#include <sstream>

namespace hpx { namespace threads { namespace detail {
    inline void create_work(policies::scheduler_base* scheduler,
        thread_init_data& data, error_code& ec = throws)
    {
        // verify parameters
        switch (data.initial_state)
        {
        case pending:
        case pending_do_not_schedule:
        case pending_boost:
        case suspended:
            break;

        default:
        {
            std::ostringstream strm;
            strm << "invalid initial state: "
                 << get_thread_state_name(data.initial_state);
            HPX_THROWS_IF(
                ec, bad_parameter, "thread::detail::create_work", strm.str());
            return;
        }
        }

#ifdef HPX_HAVE_THREAD_DESCRIPTION
        if (!data.description)
        {
            HPX_THROWS_IF(ec, bad_parameter, "thread::detail::create_work",
                "description is nullptr");
            return;
        }
#endif

        LTM_(info) << "create_work: initial_state("
                   << get_thread_state_name(data.initial_state)
                   << "), thread_priority("
                   << get_thread_priority_name(data.priority)
#ifdef HPX_HAVE_THREAD_DESCRIPTION
                   << "), description(" << data.description
#endif
                   << ")";

        thread_self* self = get_self_ptr();

#ifdef HPX_HAVE_THREAD_PARENT_REFERENCE
        if (nullptr == data.parent_id)
        {
            if (self)
            {
                data.parent_id = threads::get_self_id();
                data.parent_phase = self->get_thread_phase();
            }
        }
        if (0 == data.parent_locality_id)
            data.parent_locality_id = detail::get_locality_id(hpx::throws);
#endif

        if (nullptr == data.scheduler_base)
            data.scheduler_base = scheduler;

        // Pass critical priority from parent to child.
        if (self)
        {
            if (data.priority == thread_priority_default &&
                thread_priority_high_recursive ==
                    threads::get_self_id_data()->get_priority())
            {
                data.priority = thread_priority_high_recursive;
            }
        }

        // create the new thread
        if (data.priority == thread_priority_default)
            data.priority = thread_priority_normal;

        if (thread_priority_high == data.priority ||
            thread_priority_high_recursive == data.priority ||
            thread_priority_boost == data.priority)
        {
            // For critical priority threads, create the thread immediately.
            scheduler->create_thread(
                data, nullptr, data.initial_state, true, ec);
        }
        else
        {
            // Create a task description for the new thread.
            scheduler->create_thread(
                data, nullptr, data.initial_state, false, ec);
        }

        // NOTE: Don't care if the hint is a NUMA hint, just want to wake up a
        // thread.
        scheduler->do_some_work(data.schedulehint.hint);
    }
}}}    // namespace hpx::threads::detail

#endif
