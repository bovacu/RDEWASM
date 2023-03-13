//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___ATOMIC_ATOMIC_BASE_H
#define _LIBCPP___ATOMIC_ATOMIC_BASE_H

#include <__atomic/atomic_sync.h>
#include <__atomic/check_memory_order.h>
#include <__atomic/cxx_atomic_impl.h>
#include <__atomic/is_always_lock_free.h>
#include <__atomic/memory_order.h>
#include <__availability>
#include <__config>
#include <__type_traits/is_integral.h>
#include <__type_traits/is_nothrow_default_constructible.h>
#include <__type_traits/is_same.h>
#include <version>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

template <class _Tp, bool = is_integral<_Tp>::value && !is_same<_Tp, bool>::value>
struct __atomic_base  // false
{
    mutable __cxx_atomic_impl<_Tp> __a_;

#if defined(__cpp_lib_atomic_is_always_lock_free)
  static _LIBCPP_CONSTEXPR bool is_always_lock_free = __libcpp_is_always_lock_free<__cxx_atomic_impl<_Tp> >::__value;
#endif

    _LIBCPP_INLINE_VISIBILITY
    bool is_lock_free() const volatile _NOEXCEPT
        {return __cxx_atomic_is_lock_free(sizeof(_Tp));}
    _LIBCPP_INLINE_VISIBILITY
    bool is_lock_free() const _NOEXCEPT
        {return static_cast<__atomic_base const volatile*>(this)->is_lock_free();}
    _LIBCPP_INLINE_VISIBILITY
    void store(_Tp __d, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
      _LIBCPP_CHECK_STORE_MEMORY_ORDER(__m)
        {std::__cxx_atomic_store(&__a_, __d, __m);}
    _LIBCPP_INLINE_VISIBILITY
    void store(_Tp __d, memory_order __m = memory_order_seq_cst) _NOEXCEPT
      _LIBCPP_CHECK_STORE_MEMORY_ORDER(__m)
        {std::__cxx_atomic_store(&__a_, __d, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp load(memory_order __m = memory_order_seq_cst) const volatile _NOEXCEPT
      _LIBCPP_CHECK_LOAD_MEMORY_ORDER(__m)
        {return std::__cxx_atomic_load(&__a_, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp load(memory_order __m = memory_order_seq_cst) const _NOEXCEPT
      _LIBCPP_CHECK_LOAD_MEMORY_ORDER(__m)
        {return std::__cxx_atomic_load(&__a_, __m);}
    _LIBCPP_INLINE_VISIBILITY
    operator _Tp() const volatile _NOEXCEPT {return load();}
    _LIBCPP_INLINE_VISIBILITY
    operator _Tp() const _NOEXCEPT          {return load();}
    _LIBCPP_INLINE_VISIBILITY
    _Tp exchange(_Tp __d, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_exchange(&__a_, __d, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp exchange(_Tp __d, memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_exchange(&__a_, __d, __m);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                               memory_order __s, memory_order __f) volatile _NOEXCEPT
      _LIBCPP_CHECK_EXCHANGE_MEMORY_ORDER(__s, __f)
        {return std::__cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __s, __f);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                               memory_order __s, memory_order __f) _NOEXCEPT
      _LIBCPP_CHECK_EXCHANGE_MEMORY_ORDER(__s, __f)
        {return std::__cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __s, __f);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                                 memory_order __s, memory_order __f) volatile _NOEXCEPT
      _LIBCPP_CHECK_EXCHANGE_MEMORY_ORDER(__s, __f)
        {return std::__cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __s, __f);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                                 memory_order __s, memory_order __f) _NOEXCEPT
      _LIBCPP_CHECK_EXCHANGE_MEMORY_ORDER(__s, __f)
        {return std::__cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __s, __f);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                              memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __m, __m);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_weak(_Tp& __e, _Tp __d,
                               memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_compare_exchange_weak(&__a_, &__e, __d, __m, __m);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                              memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __m, __m);}
    _LIBCPP_INLINE_VISIBILITY
    bool compare_exchange_strong(_Tp& __e, _Tp __d,
                                 memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_compare_exchange_strong(&__a_, &__e, __d, __m, __m);}

    _LIBCPP_AVAILABILITY_SYNC _LIBCPP_INLINE_VISIBILITY void wait(_Tp __v, memory_order __m = memory_order_seq_cst) const volatile _NOEXCEPT
        {std::__cxx_atomic_wait(&__a_, __v, __m);}
    _LIBCPP_AVAILABILITY_SYNC _LIBCPP_INLINE_VISIBILITY void wait(_Tp __v, memory_order __m = memory_order_seq_cst) const _NOEXCEPT
        {std::__cxx_atomic_wait(&__a_, __v, __m);}
    _LIBCPP_AVAILABILITY_SYNC _LIBCPP_INLINE_VISIBILITY void notify_one() volatile _NOEXCEPT
        {std::__cxx_atomic_notify_one(&__a_);}
    _LIBCPP_AVAILABILITY_SYNC _LIBCPP_INLINE_VISIBILITY void notify_one() _NOEXCEPT
        {std::__cxx_atomic_notify_one(&__a_);}
    _LIBCPP_AVAILABILITY_SYNC _LIBCPP_INLINE_VISIBILITY void notify_all() volatile _NOEXCEPT
        {std::__cxx_atomic_notify_all(&__a_);}
    _LIBCPP_AVAILABILITY_SYNC _LIBCPP_INLINE_VISIBILITY void notify_all() _NOEXCEPT
        {std::__cxx_atomic_notify_all(&__a_);}

#if _LIBCPP_STD_VER >= 20
    _LIBCPP_INLINE_VISIBILITY constexpr
    __atomic_base() noexcept(is_nothrow_default_constructible_v<_Tp>) : __a_(_Tp()) {}
#else
    _LIBCPP_INLINE_VISIBILITY
    __atomic_base() _NOEXCEPT = default;
#endif

    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR
    __atomic_base(_Tp __d) _NOEXCEPT : __a_(__d) {}

    __atomic_base(const __atomic_base&) = delete;
};

#if defined(__cpp_lib_atomic_is_always_lock_free)
template <class _Tp, bool __b>
_LIBCPP_CONSTEXPR bool __atomic_base<_Tp, __b>::is_always_lock_free;
#endif

// atomic<Integral>

template <class _Tp>
struct __atomic_base<_Tp, true>
    : public __atomic_base<_Tp, false>
{
    typedef __atomic_base<_Tp, false> __base;

    _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
    __atomic_base() _NOEXCEPT = default;

    _LIBCPP_INLINE_VISIBILITY
    _LIBCPP_CONSTEXPR __atomic_base(_Tp __d) _NOEXCEPT : __base(__d) {}

    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_add(_Tp __op, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_fetch_add(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_add(_Tp __op, memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_fetch_add(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_sub(_Tp __op, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_fetch_sub(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_sub(_Tp __op, memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_fetch_sub(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_and(_Tp __op, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_fetch_and(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_and(_Tp __op, memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_fetch_and(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_or(_Tp __op, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_fetch_or(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_or(_Tp __op, memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_fetch_or(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_xor(_Tp __op, memory_order __m = memory_order_seq_cst) volatile _NOEXCEPT
        {return std::__cxx_atomic_fetch_xor(&this->__a_, __op, __m);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp fetch_xor(_Tp __op, memory_order __m = memory_order_seq_cst) _NOEXCEPT
        {return std::__cxx_atomic_fetch_xor(&this->__a_, __op, __m);}

    _LIBCPP_INLINE_VISIBILITY
    _Tp operator++(int) volatile _NOEXCEPT      {return fetch_add(_Tp(1));}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator++(int) _NOEXCEPT               {return fetch_add(_Tp(1));}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator--(int) volatile _NOEXCEPT      {return fetch_sub(_Tp(1));}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator--(int) _NOEXCEPT               {return fetch_sub(_Tp(1));}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator++() volatile _NOEXCEPT         {return fetch_add(_Tp(1)) + _Tp(1);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator++() _NOEXCEPT                  {return fetch_add(_Tp(1)) + _Tp(1);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator--() volatile _NOEXCEPT         {return fetch_sub(_Tp(1)) - _Tp(1);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator--() _NOEXCEPT                  {return fetch_sub(_Tp(1)) - _Tp(1);}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator+=(_Tp __op) volatile _NOEXCEPT {return fetch_add(__op) + __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator+=(_Tp __op) _NOEXCEPT          {return fetch_add(__op) + __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator-=(_Tp __op) volatile _NOEXCEPT {return fetch_sub(__op) - __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator-=(_Tp __op) _NOEXCEPT          {return fetch_sub(__op) - __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator&=(_Tp __op) volatile _NOEXCEPT {return fetch_and(__op) & __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator&=(_Tp __op) _NOEXCEPT          {return fetch_and(__op) & __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator|=(_Tp __op) volatile _NOEXCEPT {return fetch_or(__op) | __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator|=(_Tp __op) _NOEXCEPT          {return fetch_or(__op) | __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator^=(_Tp __op) volatile _NOEXCEPT {return fetch_xor(__op) ^ __op;}
    _LIBCPP_INLINE_VISIBILITY
    _Tp operator^=(_Tp __op) _NOEXCEPT          {return fetch_xor(__op) ^ __op;}
};

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___ATOMIC_ATOMIC_BASE_H