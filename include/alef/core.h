/// @file   core.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Contains fundamental types and includes.
/// @date   2022-10-26
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the GNU GPL v3 License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALEF_CORE_H
#define WINGMANN_ALEF_CORE_H

#include <cstddef>

namespace alef {

using schar = signed char;
using uchar = unsigned char;

using int8   = schar;
using uint8  = uchar;
using int16  = signed short int;
using uint16 = unsigned short int;
using int32  = signed int;
using uint32 = unsigned int;
#if defined(__WORDSIZE) && __WORDSIZE == 64
using int64  = signed long int;
using uint64 = unsigned long int;
#else
using int64  = signed long long int;
using uint64 = unsigned long long int;
#endif

namespace {

enum { _size_of_ptr = sizeof(std::size_t) };

} // namespace

#if _size_of_ptr == 8
using ssize   = int64;
using size    = uint64;
using ptrdiff = uint64;
#elif _size_of_ptr == 4
using ssize   = int32;
using size    = uint32;
using ptrdiff = uint32;
#endif

using float32 = float;
using float64 = double;
using float128 = long double;

using wchar  = wchar_t;
using char8  = char8_t;
using char16 = char16_t;
using char32 = char32_t;

} // namespace alef

#endif // WINGMANN_ALEF_CORE_H
