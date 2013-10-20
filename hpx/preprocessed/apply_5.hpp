// Copyright (c) 2007-2013 Hartmut Kaiser
// Copyright (c) 2012-2013 Thomas Heller
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This file has been automatically generated using the Boost.Wave tool.
// Do not edit manually.


namespace hpx
{
    
    
    template <typename F>
    bool apply(threads::executor& sched, BOOST_FWD_REF(F) f)
    {
        sched.add(boost::forward<F>(f), "hpx::apply");
        return false; 
    }
    template <typename F>
    bool apply(BOOST_FWD_REF(F) f)
    {
        threads::register_thread(boost::forward<F>(f), "hpx::apply");
        return false; 
    }
    
    
    
    template <typename F, typename A0> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 )), "hpx::apply"); return false; } template <typename F, typename A0> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(threads::executor& sched, BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6) { sched.add(util::bind(util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )), "hpx::apply"); return false; } template <typename F, typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6> typename boost::enable_if_c< !traits::is_action<typename util::decay<F>::type>::value , bool >::type apply(BOOST_FWD_REF(F) f, BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6) { threads::register_thread(util::bind( util::protect(boost::forward<F>(f)), boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )), "hpx::apply"); return false; }
}
namespace hpx
{
    
    
    template <
        typename Action
      , typename T0
    >
    bool apply(
        BOOST_RV_REF(HPX_UTIL_STRIP((
            hpx::util::detail::bound_action1<
                Action
              , T0
            >))) bound)
    {
        return bound.apply();
    }
    
    template < typename Action , typename T0 , typename A0 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 ) { return bound.apply(boost::forward<A0>( a0 )); } template < typename Action , typename T0 , typename A0 , typename A1 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )); } template < typename Action , typename T0 , typename A0 , typename A1 , typename A2 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )); } template < typename Action , typename T0 , typename A0 , typename A1 , typename A2 , typename A3 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )); } template < typename Action , typename T0 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )); } template < typename Action , typename T0 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )); } template < typename Action , typename T0 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action1< Action , T0 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )); }
}
namespace hpx
{
    
    
    template <
        typename Action
      , typename T0 , typename T1
    >
    bool apply(
        BOOST_RV_REF(HPX_UTIL_STRIP((
            hpx::util::detail::bound_action2<
                Action
              , T0 , T1
            >))) bound)
    {
        return bound.apply();
    }
    
    template < typename Action , typename T0 , typename T1 , typename A0 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 ) { return bound.apply(boost::forward<A0>( a0 )); } template < typename Action , typename T0 , typename T1 , typename A0 , typename A1 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )); } template < typename Action , typename T0 , typename T1 , typename A0 , typename A1 , typename A2 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )); } template < typename Action , typename T0 , typename T1 , typename A0 , typename A1 , typename A2 , typename A3 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )); } template < typename Action , typename T0 , typename T1 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )); } template < typename Action , typename T0 , typename T1 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )); } template < typename Action , typename T0 , typename T1 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action2< Action , T0 , T1 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )); }
}
namespace hpx
{
    
    
    template <
        typename Action
      , typename T0 , typename T1 , typename T2
    >
    bool apply(
        BOOST_RV_REF(HPX_UTIL_STRIP((
            hpx::util::detail::bound_action3<
                Action
              , T0 , T1 , T2
            >))) bound)
    {
        return bound.apply();
    }
    
    template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 ) { return bound.apply(boost::forward<A0>( a0 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 , typename A1 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 , typename A1 , typename A2 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 , typename A1 , typename A2 , typename A3 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action3< Action , T0 , T1 , T2 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )); }
}
namespace hpx
{
    
    
    template <
        typename Action
      , typename T0 , typename T1 , typename T2 , typename T3
    >
    bool apply(
        BOOST_RV_REF(HPX_UTIL_STRIP((
            hpx::util::detail::bound_action4<
                Action
              , T0 , T1 , T2 , T3
            >))) bound)
    {
        return bound.apply();
    }
    
    template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 ) { return bound.apply(boost::forward<A0>( a0 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 , typename A1 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 , typename A1 , typename A2 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 , typename A1 , typename A2 , typename A3 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action4< Action , T0 , T1 , T2 , T3 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )); }
}
namespace hpx
{
    
    
    template <
        typename Action
      , typename T0 , typename T1 , typename T2 , typename T3 , typename T4
    >
    bool apply(
        BOOST_RV_REF(HPX_UTIL_STRIP((
            hpx::util::detail::bound_action5<
                Action
              , T0 , T1 , T2 , T3 , T4
            >))) bound)
    {
        return bound.apply();
    }
    
    template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 ) { return bound.apply(boost::forward<A0>( a0 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 , typename A1 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 , typename A1 , typename A2 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 , typename A1 , typename A2 , typename A3 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 )); } template < typename Action , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 > bool apply( BOOST_RV_REF(HPX_UTIL_STRIP(( hpx::util::detail::bound_action5< Action , T0 , T1 , T2 , T3 , T4 >))) bound , BOOST_FWD_REF(A0) a0 , BOOST_FWD_REF(A1) a1 , BOOST_FWD_REF(A2) a2 , BOOST_FWD_REF(A3) a3 , BOOST_FWD_REF(A4) a4 , BOOST_FWD_REF(A5) a5 , BOOST_FWD_REF(A6) a6 ) { return bound.apply(boost::forward<A0>( a0 ) , boost::forward<A1>( a1 ) , boost::forward<A2>( a2 ) , boost::forward<A3>( a3 ) , boost::forward<A4>( a4 ) , boost::forward<A5>( a5 ) , boost::forward<A6>( a6 )); }
}
