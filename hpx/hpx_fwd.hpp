//  Copyright (c) 2007-2011 Hartmut Kaiser
//  Copyright (c) 2011      Bryce Lelbach
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_HPX_FWD_MAR_24_2008_1119AM)
#define HPX_HPX_FWD_MAR_24_2008_1119AM

#include <cstdlib>
#include <vector>

#include <boost/config.hpp>
#include <boost/version.hpp>

#if BOOST_VERSION < 104200
// Please update your Boost installation (see www.boost.org for details).
#error HPX cannot be compiled with a Boost version earlier than V1.42.
#endif

#if defined(BOOST_WINDOWS)
#include <winsock2.h>
#include <windows.h>
#endif

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/cstdint.hpp>
#include <boost/coroutine/coroutine.hpp>
#include <hpx/config.hpp>
#include <hpx/util/unused.hpp>
#include <hpx/runtime/threads/detail/tagged_thread_state.hpp>

/// \namespace hpx
///
/// The namespace \a hpx is the main namespace of the HPX library. All classes
/// functions and variables are defined inside this namespace.

namespace hpx
{
    /// \namespace applier
    ///
    /// The namespace \a applier contains all definitions needed for the
    /// class \a hpx#applier#applier and its related functionality. This 
    /// namespace is part of the HPX core module.
    namespace applier
    {
        class HPX_API_EXPORT applier;

        /// The function \a get_applier returns a reference to the (thread
        /// specific) applier instance.
        HPX_API_EXPORT applier& get_applier();
        HPX_API_EXPORT applier* get_applier_ptr();

        /// The function \a get_prefix_id returns the id of this locality
        HPX_API_EXPORT boost::uint32_t get_prefix_id();
    }

    /// \namespace actions
    ///
    /// The namespace \a actions contains all definitions needed for the
    /// class \a hpx#action_manager#action_manager and its related 
    /// functionality. This namespace is part of the HPX core module.
    namespace actions
    {
        struct HPX_API_EXPORT base_action;
        typedef boost::shared_ptr<base_action> action_type;

        class HPX_API_EXPORT continuation;
        typedef boost::shared_ptr<continuation> continuation_type;

        class HPX_API_EXPORT action_manager;
    }

    /// \namespace naming
    ///
    /// The namespace \a naming contains all definitions needed for the AGAS
    /// (Distributed Global Address Space) service.
    namespace naming
    {
        struct HPX_API_EXPORT gid_type;
        struct HPX_API_EXPORT id_type;
        struct HPX_API_EXPORT address;
        class HPX_API_EXPORT locality;
        class HPX_API_EXPORT resolver_client;
        class HPX_API_EXPORT resolver_server;

        namespace server
        {
            class reply;
            class request;
        }

        HPX_API_EXPORT resolver_client& get_agas_client();
    }

    ///////////////////////////////////////////////////////////////////////////
    /// \namespace parcelset
    namespace parcelset
    {
        class HPX_API_EXPORT parcel;
        class HPX_API_EXPORT parcelport;
        class parcelport_connection;
        class HPX_API_EXPORT parcelhandler;
        
        namespace server
        {
            class parcelport_queue;
            class parcelport_server_connection;

            struct parcelhandler_queue_base;

            namespace policies
            {
                struct global_parcelhandler_queue;

                typedef global_parcelhandler_queue parcelhandler_queue;
            }
        }
    }

    /// \namespace threads
    ///
    /// The namespace \a threadmanager contains all the definitions required 
    /// for the scheduling, execution and general management of \a 
    /// hpx#threadmanager#thread's.
    namespace threads
    {
        namespace policies
        {
            class HPX_API_EXPORT global_queue_scheduler;
            class HPX_API_EXPORT local_queue_scheduler;
            class HPX_API_EXPORT local_priority_queue_scheduler;
            struct HPX_API_EXPORT abp_queue_scheduler;
            class HPX_API_EXPORT callback_notifier;

            // define the default scheduler to use
            typedef local_queue_scheduler queue_scheduler;
        }

        struct HPX_API_EXPORT threadmanager_base;
        class HPX_API_EXPORT thread;

        template <
            typename SchedulingPolicy, 
            typename NotificationPolicy = threads::policies::callback_notifier> 
        class HPX_API_EXPORT threadmanager_impl;

        /// \enum thread_state_enum
        ///
        /// The \a thread_state_enum enumerator encodes the current state of a
        /// \a thread instance
        enum thread_state_enum
        {
            unknown = 0,
            active = 1,         /*!< thread is currently active (running,
                                     has resources) */
            pending = 2,        /*!< thread is pending (ready to run, but
                                     no hardware resource available) */
            suspended = 3,      /*!< thread has been suspended (waiting for
                                     synchronization event, but still
                                     known and under control of the
                                     threadmanager) */
            depleted = 4,       /*!< thread has been depleted (deeply
                                     suspended, it is not known to the
                                     thread manager) */
            terminated = 5      /*!< thread has been stopped an may be
                                     garbage collected */
        };

        /// \enum thread_priority
        enum thread_priority
        {
            thread_priority_default = 0,      ///< use default priority
            thread_priority_low = 1,          ///< low thread priority 
            thread_priority_normal = 2,       ///< normal thread priority (default)
            thread_priority_critical = 3      ///< high thread priority
        };

        typedef threads::detail::tagged_thread_state<thread_state_enum> thread_state;

        HPX_API_EXPORT char const* get_thread_state_name(thread_state_enum state);
        HPX_API_EXPORT char const* get_thread_priority_name(thread_priority priority);

        /// \enum thread_state_ex_enum
        ///
        /// The \a thread_state_ex_enum enumerator encodes the reason why a
        /// thread is being restarted
        enum thread_state_ex_enum
        {
            wait_unknown = -1,
            wait_signaled = 0,  ///< The thread has been signaled
            wait_timeout = 1,   ///< The thread has been reactivated after a timeout
            wait_terminate = 2, ///< The thread needs to be terminated
            wait_abort = 3,     ///< The thread needs to be aborted
        };

        typedef threads::detail::tagged_thread_state<thread_state_ex_enum> thread_state_ex;

        typedef thread_state_enum thread_function_type(thread_state_ex_enum);

        ///////////////////////////////////////////////////////////////////////
        namespace detail
        {
            template <typename CoroutineImpl> struct coroutine_allocator; 
        }
        typedef boost::coroutines::coroutine<
            thread_function_type, detail::coroutine_allocator> coroutine_type;
        typedef coroutine_type::thread_id_type thread_id_type;
        typedef coroutine_type::self thread_self;

        /// The function \a get_self returns a reference to the (OS thread 
        /// specific) self reference to the current PX thread.
        HPX_API_EXPORT thread_self& get_self();

        /// The function \a get_self returns a pointer to the (OS thread 
        /// specific) self reference to the current PX thread.
        HPX_API_EXPORT thread_self* get_self_ptr();

        /// The function \a get_self_id returns the PX thread id of the current
        /// thread (or zero if the current thread is not a PX thread).
        HPX_API_EXPORT thread_id_type get_self_id();

        /// The function \a get_parent_id returns the PX thread id of the 
        /// currents thread parent (or zero if the current thread is not a 
        /// PX thread).
        HPX_API_EXPORT thread_id_type get_parent_id();

        /// The function \a get_parent_phase returns the PX phase of the 
        /// currents thread parent (or zero if the current thread is not a 
        /// PX thread).
        HPX_API_EXPORT std::size_t get_parent_phase();

        /// The function \a get_parent_prefix returns the id of the locality of
        /// the currents thread parent (or zero if the current thread is not a 
        /// PX thread).
        HPX_API_EXPORT boost::uint32_t get_parent_prefix();

        /// The function \a get_self_component_id returns the lva of the 
        /// component the current thread is acting on
        HPX_API_EXPORT boost::uint64_t get_self_component_id();

        /// The function \a get_thread_manager returns a reference to the
        /// current thread manager.
        HPX_API_EXPORT threadmanager_base& get_thread_manager();

        /// The function \a suspend will return control to the thread manager
        /// (suspends the current thread). It sets the new state of this thread
        /// to the thread state passed as the parameter.
        HPX_API_EXPORT void suspend(thread_state_enum state = pending);
    }

    class HPX_API_EXPORT runtime;

    /// A HPX runtime can be executed in two different modes: console mode
    /// and worker mode.
    enum runtime_mode
    {
        runtime_mode_invalid = -1,
        runtime_mode_console = 0,   ///< The runtime is the console locality
        runtime_mode_worker = 1,    ///< The runtime is a worker locality
        runtime_mode_connect = 2,   ///< The runtime is a worker locality 
                                    ///< connecting late
        runtime_mode_default = 3,   ///< The runtime mode will be determinded 
                                    ///< based on the command line arguments
        runtime_mode_last = 3
    };

    /// Get the readable string representing the name of the given runtime_mode
    /// constant.
    HPX_API_EXPORT char const* get_runtime_mode_name(runtime_mode state);

    namespace agas
    {
        enum router_mode
        {
            router_mode_invalid = -1,
            router_mode_bootstrap = 0,
            router_mode_hosted = 1,
        };
    }

    ///////////////////////////////////////////////////////////////////////////
    /// Retrieve the string value of a configuration entry as given by \p key.
    HPX_API_EXPORT std::string get_config_entry(std::string const& key, 
        std::string const& dflt);
    /// Retrieve the integer value of a configuration entry as given by \p key.
    HPX_API_EXPORT std::string get_config_entry(std::string const& key, 
        std::size_t dflt);

#if HPX_AGAS_VERSION > 0x10
    ///////////////////////////////////////////////////////////////////////////
    /// Add a function to be executed inside a HPX thread before hpx_main
    typedef boost::function<void()> startup_function_type;
    HPX_API_EXPORT void register_startup_function(startup_function_type const&);

    /// Add a function to be executed inside a HPX thread during hpx::finalize
    typedef boost::function<void()> shutdown_function_type;
    HPX_API_EXPORT void register_shutdown_function(shutdown_function_type const&);
#endif

    template <
        typename SchedulingPolicy, 
        typename NotificationPolicy = threads::policies::callback_notifier> 
    class HPX_API_EXPORT runtime_impl;

    /// The function \a get_runtime returns a reference to the (thread
    /// specific) runtime instance.
    HPX_API_EXPORT runtime& get_runtime();
    HPX_API_EXPORT runtime* get_runtime_ptr();

    /// The function \a get_locality returns a reference to the locality
    HPX_API_EXPORT naming::locality const& get_locality();

    /// The function \a get_runtime_instance_number returns a unique number
    /// associated with the runtime instance the current thread is running in.
    HPX_API_EXPORT std::size_t get_runtime_instance_number();

    HPX_API_EXPORT void report_error(std::size_t num_thread
      , boost::exception_ptr const& e);

    HPX_API_EXPORT void report_error(boost::exception_ptr const& e);

    /// Register a function to be called during system shutdown
    HPX_API_EXPORT bool register_on_exit(boost::function<void()>);

    enum logging_destination
    {
        destination_hpx = 0,
        destination_timing = 1,
        destination_agas = 2,
        destination_app = 3,
    };

    /// \namespace components
    namespace components
    {
        namespace detail 
        { 
            struct this_type {};
            struct fixed_component_tag {};
            struct simple_component_tag {};
            struct managed_component_tag {};
        }

        ///////////////////////////////////////////////////////////////////////
        enum component_type
        {
            component_invalid = -1,
            component_runtime_support = 0,  // runtime support (needed to create components, etc.)
            component_memory = 1,           // general memory address
            component_memory_block = 2,     // general memory block

            // LCO's
            component_base_lco = 3,         ///< the base of all LCO's not waiting on a value
            component_base_lco_with_value = 4,
                                            ///< base LCO's blocking on a value
            component_future =              ///< a future executing the action and 
                                            ///< allowing to wait for the result
                ((5 << 16) | component_base_lco_with_value),
            component_value_adaptor = 6,    ///< an adaptor to access specific slot of an LCO
            component_barrier =             ///< a LCO implementing a barrier
                ((7 << 16) | component_base_lco),
            component_thread =              ///< a ParalleX thread
                ((8 << 16) | component_base_lco_with_value),
            component_dataflow_variable =   ///< a LCO implementing dataflow var.
                ((9 << 16) | component_base_lco_with_value),
            component_thunk =               ///< a LCO implementing a thunk
                ((10 << 16) | component_base_lco_with_value),

            component_dataflow_block = 11,  ///< a dataflow block

            component_agas_primary_namespace = 12,
            component_agas_component_namespace = 13,
            component_agas_symbol_namespace = 14,

            component_last,
            component_first_dynamic = component_last
        };

        ///////////////////////////////////////////////////////////////////////
        template <boost::uint64_t MSB, boost::uint64_t LSB,
            typename Component = detail::this_type>
        struct fixed_component_base;

        template <typename Component> 
        struct fixed_component;

        template <typename Component = detail::this_type>
        class simple_component_base; 

        template <typename Component> 
        class simple_component;

        template <typename Component, typename Wrapper = detail::this_type>
        class managed_component_base;

        template <typename Component, typename Derived = detail::this_type>
        class managed_component;

        struct HPX_API_EXPORT component_factory_base;

        template <typename Component> 
        struct component_factory;

        class runtime_support;
        class memory;
        class memory_block;

        namespace stubs 
        {
            struct runtime_support;
            struct memory;
            struct memory_block;
        }

        namespace server
        {
            class HPX_API_EXPORT runtime_support;
            class HPX_API_EXPORT memory;
            class HPX_API_EXPORT memory_block;
        }

        HPX_EXPORT void console_logging(logging_destination dest,
            std::size_t level, std::string const& msg);
        HPX_EXPORT void cleanup_logging();
        HPX_EXPORT void activate_logging();
    }

    /// \namespace lcos
    namespace lcos
    {
        class base_lco;
        template <typename Result, typename RemoteResult = Result> 
        class base_lco_with_value;

        template <typename Result>
        struct future_value_remote_result;

        template <typename Result>
        struct future_value_local_result;

        template <typename Result, 
            typename RemoteResult = 
                typename future_value_remote_result<Result>::type, 
            int N = 1> 
        class future_value;

        template <typename Value, typename RemoteValue = Value>
        class local_dataflow_variable;

        template <typename Action, 
            typename Result = typename future_value_local_result<
                typename Action::result_type>::type,
            typename DirectExecute = typename Action::direct_execution> 
        class eager_future;

        template <typename Action, 
            typename Result = typename future_value_local_result<
                typename Action::result_type>::type,
            typename DirectExecute = typename Action::direct_execution> 
        class lazy_future;

        template <typename Action, 
            typename Result = typename future_value_local_result<
                typename Action::result_type>::type,
            typename DirectExecute = typename Action::direct_execution> 
        class contin;

        template <typename Thunk>
        class thunk_client;

        template <typename ValueType>
        struct object_semaphore;

        namespace stubs
        {
            template <typename ValueType>
            struct object_semaphore;
        }

        namespace server
        {
            template <typename ValueType>
            struct object_semaphore;
        }
    }

    /// \namespace util
    namespace util
    {
        class HPX_API_EXPORT section;
        class runtime_configuration;

        template <typename Connection, typename Key = boost::uint32_t>
        class connection_cache;
    }

    class error_code;

    // predefined error_code object used as "throw on error" tag
    HPX_EXCEPTION_EXPORT extern error_code throws;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Return the global id representing this locality
    HPX_API_EXPORT naming::id_type find_here();

    /// \brief Return the list of prefixes of the localities supporting the 
    ///        given component type. By default this function will return the 
    ///        list of all localities.
    HPX_API_EXPORT std::vector<naming::id_type> find_all_localities();
    HPX_API_EXPORT std::vector<naming::id_type> find_all_localities(
        components::component_type type);

    HPX_API_EXPORT naming::gid_type get_next_id();

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Return the number of OS-threads running in the runtime instance
    ///        the current thread is associated with
    HPX_API_EXPORT std::size_t get_num_os_threads();
}

#endif

