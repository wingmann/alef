#ifndef WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_VIEW_H
#define WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_VIEW_H

#include "alef/core/io/__detail.h"

namespace alf {

using string_view      = std::basic_string_view<char>;
using wstring_view     = std::basic_string_view<wchar>;
using utf8string_view  = std::basic_string_view<char8>;
using utf16string_view = std::basic_string_view<char16>;
using utf32string_view = std::basic_string_view<char32>;

} // namespace alf

#endif //WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_VIEW_H
