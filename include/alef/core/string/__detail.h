#ifndef ALEF_CORE_STRING_DETAIL_H
#define ALEF_CORE_STRING_DETAIL_H

#include "alef/core/io/__detail.h"

namespace alf::core::string::__detail {

using string            = std::basic_string<char,   std::char_traits<char>,   std::allocator<char>>;
using wc_string         = std::basic_string<wchar,  std::char_traits<wchar>,  std::allocator<wchar>>;
using utf8_string       = std::basic_string<char8,  std::char_traits<char8>,  std::allocator<char8>>;
using utf16_string      = std::basic_string<char16, std::char_traits<char16>, std::allocator<char16>>;
using utf32_string      = std::basic_string<char32, std::char_traits<char32>, std::allocator<char32>>;

using string_view       = std::basic_string_view<char>;
using wc_string_view    = std::basic_string_view<wchar>;
using utf8_string_view  = std::basic_string_view<char8>;
using utf16_string_view = std::basic_string_view<char16>;
using utf32_string_view = std::basic_string_view<char32>;

} // namespace alf

#endif // ALEF_CORE_STRING_DETAIL_H
