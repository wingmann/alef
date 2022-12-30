/// @file   basic.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Contains fundamental type aliases.
/// @date   2022-10-28
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the GNU GPL v3 License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_TYPES_GENERAL_BASIC_H
#define ALEF_CORE_TYPES_GENERAL_BASIC_H

#include "alef/core/types/general/__detail.h"

namespace alf {

// Integrals ---------------------------------------------------------------------------------------
using i8        = alf::core::types::general::__detail::integer::__i8;
using ui8       = alf::core::types::general::__detail::integer::__ui8;
using i16       = alf::core::types::general::__detail::integer::__i16;
using ui16      = alf::core::types::general::__detail::integer::__ui16;
using i32       = alf::core::types::general::__detail::integer::__i32;
using ui32      = alf::core::types::general::__detail::integer::__ui32;
using i64       = alf::core::types::general::__detail::integer::__i64;
using ui64      = alf::core::types::general::__detail::integer::__ui64;

// Architecture specific integers ------------------------------------------------------------------
using isize     = alf::core::types::general::__detail::integer::__isize;
using usize     = alf::core::types::general::__detail::integer::__usize;
using ptrdiff   = alf::core::types::general::__detail::integer::__ptrdiff;
using intptr    = alf::core::types::general::__detail::integer::__intptr;

// Floating point ----------------------------------------------------------------------------------
using f32       = alf::core::types::general::__detail::floating_point::__f32;
using f64       = alf::core::types::general::__detail::floating_point::__f64;
using f128      = alf::core::types::general::__detail::floating_point::__f128;

// Character ---------------------------------------------------------------------------------------
using schar     = alf::core::types::general::__detail::character::__schar;
using uchar     = alf::core::types::general::__detail::character::__uchar;
using character = alf::core::types::general::__detail::character::__character;
using wchar     = alf::core::types::general::__detail::character::__wchar;
using char8     = alf::core::types::general::__detail::character::__char8;
using char16    = alf::core::types::general::__detail::character::__char16;
using char32    = alf::core::types::general::__detail::character::__char32;

} // namespace alf

#endif // ALEF_CORE_TYPES_GENERAL_BASIC_H
