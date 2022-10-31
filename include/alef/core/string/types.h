#ifndef ALEF_CORE_STRING_TYPES_H
#define ALEF_CORE_STRING_TYPES_H

#include "alef/core/detail/streams.h"

namespace alef {

using string      = std::basic_string<char,   std::char_traits<char>,   std::allocator<char>>;
using wstring     = std::basic_string<wchar,  std::char_traits<wchar>,  std::allocator<wchar>>;
using utf8string  = std::basic_string<char8,  std::char_traits<char8>,  std::allocator<char8>>;
using utf16string = std::basic_string<char16, std::char_traits<char16>, std::allocator<char16>>;
using utf32string = std::basic_string<char32, std::char_traits<char32>, std::allocator<char32>>;

using string_view      = std::basic_string_view<char>;
using wstring_view     = std::basic_string_view<wchar>;
using utf8string_view  = std::basic_string_view<char8>;
using utf16string_view = std::basic_string_view<char16>;
using utf32string_view = std::basic_string_view<char32>;

using istring_stream = alef::stream::istring_stream;
using ostring_stream = alef::stream::ostring_stream;
using string_stream  = alef::stream::string_stream;

using wistring_stream = alef::stream::wistring_stream;
using wostring_stream = alef::stream::wostring_stream;
using wstring_stream  = alef::stream::wstring_stream;

} // namespace alef

#endif // ALEF_CORE_STRING_TYPES_H
