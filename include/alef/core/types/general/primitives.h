/// @file   primitives.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Contains fundamental type aliases.
/// @date   2022-10-28
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the GNU GPL v3 License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_TYPES_GENERAL_PRIMITIVES_H
#define ALEF_CORE_TYPES_GENERAL_PRIMITIVES_H

namespace alf {

// Integrals ---------------------------------------------------------------------------------------
using schar     = signed char;
using uchar     = unsigned char;

using i8        = schar;
using ui8       = uchar;
using i16       = signed short int;
using ui16      = unsigned short int;
using i32       = signed int;
using ui32      = unsigned int;

#if defined(__WORDSIZE) && __WORDSIZE == 64
using i64       = signed long int;
using ui64      = unsigned long int;
#else
using i64       = signed long long int;
using ui64      = unsigned long long int;
#endif

// Architecture specific integrals -----------------------------------------------------------------
#ifdef _WIN64 // todo Add unix-like macro checking
using isize     = i64;
using usize     = ui64;
using ptrdiff   = ui64;
using intptr    = i64;
#else
using isize     = i32;
using usize     = ui32;
using ptrdiff   = ui32;
using intptr    = i32;
#endif

// Floating point ----------------------------------------------------------------------------------
using f32       = float;
using f64       = double;
using f128      = long double;

// Character ---------------------------------------------------------------------------------------
using character = char;
using wchar     = wchar_t;
using char8     = char8_t;
using char16    = char16_t;
using char32    = char32_t;

} // namespace alf

#endif // ALEF_CORE_TYPES_GENERAL_PRIMITIVES_H
