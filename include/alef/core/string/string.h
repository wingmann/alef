#ifndef WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_H
#define WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_H

#include "alef/core/string/__detail.h"

namespace alf {

using string       = alf::core::string::__detail::string;
using wc_string    = alf::core::string::__detail::wc_string;
using utf8_string  = alf::core::string::__detail::utf8_string;
using utf16_string = alf::core::string::__detail::utf16_string;
using utf32_string = alf::core::string::__detail::utf32_string;

// String literals ---------------------------------------------------------------------------------
[[nodiscard]]
constexpr auto operator""_s(const char* str, alf::usize length)
{
    return alf::string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::wchar* str, alf::usize length)
{
    return alf::wc_string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::char8* str, alf::usize length)
{
    return alf::utf8_string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::char16* str, alf::usize length)
{
    return alf::utf16_string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::char32* str, alf::usize length)
{
    return alf::utf32_string(str, length);
}

} // namespace alf

#endif //WINGMANN_ALEF_INCLUDE_ALEF_CORE_STRING_STRING_H
