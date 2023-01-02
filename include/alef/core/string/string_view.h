#ifndef ALEF_CORE_STRING_STRING_VIEW_H
#define ALEF_CORE_STRING_STRING_VIEW_H

#include "alef/core/string/__detail.h"

namespace alf {

using string_view       = alf::core::string::__detail::string_view;
using wc_string_view    = alf::core::string::__detail::wc_string_view;
using utf8_string_view  = alf::core::string::__detail::utf8_string_view;
using utf16_string_view = alf::core::string::__detail::utf16_string_view;
using utf32_string_view = alf::core::string::__detail::utf32_string_view;

// String view literals ----------------------------------------------------------------------------
[[nodiscard]]
constexpr auto operator""_sv(const char* str, alf::usize length)
{
    return alf::string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::wchar* str, alf::usize length)
{
    return alf::wc_string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::char8* str, alf::usize length)
{
    return alf::utf8_string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::char16* str, alf::usize length)
{
    return alf::utf16_string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::char32* str, alf::usize length)
{
    return alf::utf32_string_view(str, length);
}

} // namespace alf

#endif // ALEF_CORE_STRING_STRING_VIEW_H
