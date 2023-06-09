// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___CHRONO_CONCEPTS_H
#define _LIBCPP___CHRONO_CONCEPTS_H

#include <__chrono/hh_mm_ss.h>
#include <__config>
#include <__type_traits/is_specialization.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

#if _LIBCPP_STD_VER > 17

template <class _Tp>
concept __is_hh_mm_ss = __is_specialization_v<_Tp, chrono::hh_mm_ss>;

#endif // _LIBCPP_STD_VER > 17

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___CHRONO_CONCEPTS_H
