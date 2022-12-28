#ifndef ALEF_CORE_STRING_STRING_LITERALS_H
#define ALEF_CORE_STRING_STRING_LITERALS_H

#include "alef/core/strings/string.h"
#include "alef/core/strings/string_view.h"

namespace alf {

// String literals ---------------------------------------------------------------------------------
[[nodiscard]]
constexpr auto operator""_s(const char* str, alf::usize length)
{
    return alf::string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::wchar* str, alf::usize length)
{
    return alf::wstring(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::char8* str, alf::usize length)
{
    return alf::utf8string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::char16* str, alf::usize length)
{
    return alf::utf16string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alf::char32* str, alf::usize length)
{
    return alf::utf32string(str, length);
}

// String view literals ----------------------------------------------------------------------------
[[nodiscard]]
constexpr auto operator""_sv(const char* str, alf::usize length)
{
    return alf::string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::wchar* str, alf::usize length)
{
    return alf::wstring_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::char8* str, alf::usize length)
{
    return alf::utf8string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::char16* str, alf::usize length)
{
    return alf::utf16string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alf::char32* str, alf::usize length)
{
    return alf::utf32string_view(str, length);
}

} // namespace alf

#endif // ALEF_CORE_STRING_STRING_LITERALS_H
