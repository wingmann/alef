#ifndef ALEF_CORE_TYPES_GENERAL_DETAIL_H
#define ALEF_CORE_TYPES_GENERAL_DETAIL_H

namespace alf::core::types::general::__detail::character {

using __schar     = signed char;
using __uchar     = unsigned char;
using __wchar     = wchar_t;
using __char8     = char8_t;
using __char16    = char16_t;
using __char32    = char32_t;

} // namespace alf::core::types::general::__detail::character

namespace alf::core::types::general::__detail::integer {

using __i8        = alf::core::types::general::__detail::character::__schar;
using __ui8       = alf::core::types::general::__detail::character::__uchar;
using __i16       = signed short int;
using __ui16      = unsigned short int;
using __i32       = signed int;
using __ui32      = unsigned int;

#if defined(__WORDSIZE) && __WORDSIZE == 64
using __i64       = signed long int;
using __ui64      = unsigned long int;
#else
using __i64       = signed long long int;
using __ui64      = unsigned long long int;
#endif

// Architecture specific integrals -----------------------------------------------------------------
#ifdef _WIN64 // todo Add unix-like macro checking
using __isize     = __i64;
using __usize     = __ui64;
using __ptrdiff   = __ui64;
using __intptr    = __i64;
#else
using __isize     = __i32;
using __usize     = __ui32;
using __ptrdiff   = __ui32;
using __intptr    = __i32;
#endif

} // namespace alf::core::types::general::__detail::integers

namespace alf::core::types::general::__detail::floating_point {

using __f32       = float;
using __f64       = double;
using __f128      = long double;

} // namespace alf::core::types::general::__detail::floating_point

#endif // ALEF_CORE_TYPES_GENERAL_DETAIL_H
