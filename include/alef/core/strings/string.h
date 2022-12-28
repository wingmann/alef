#ifndef WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_H
#define WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_H

#include "alef/core/io/__detail.h"

namespace alf {

using string      = std::basic_string<char,   std::char_traits<char>,   std::allocator<char>>;
using wstring     = std::basic_string<wchar,  std::char_traits<wchar>,  std::allocator<wchar>>;
using utf8string  = std::basic_string<char8,  std::char_traits<char8>,  std::allocator<char8>>;
using utf16string = std::basic_string<char16, std::char_traits<char16>, std::allocator<char16>>;
using utf32string = std::basic_string<char32, std::char_traits<char32>, std::allocator<char32>>;

} // namespace alf

#endif //WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_H
