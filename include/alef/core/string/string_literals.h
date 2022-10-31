#ifndef ALEF_CORE_STRING_STRING_LITERALS_H
#define ALEF_CORE_STRING_STRING_LITERALS_H

#include "alef/core/string/types.h"

namespace alef {

// String literals ---------------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_s(const char* str, alef::size length)
{
    return alef::string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alef::wchar* str, alef::size length)
{
    return alef::wstring(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alef::char8* str, alef::size length)
{
    return alef::utf8string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alef::char16* str, alef::size length)
{
    return alef::utf16string(str, length);
}

[[nodiscard]]
constexpr auto operator""_s(const alef::char32* str, alef::size length)
{
    return alef::utf32string(str, length);
}

// String view literals ----------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_sv(const char* str, alef::size length)
{
    return alef::string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alef::wchar* str, alef::size length)
{
    return alef::wstring_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alef::char8* str, alef::size length)
{
    return alef::utf8string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alef::char16* str, alef::size length)
{
    return alef::utf16string_view(str, length);
}

[[nodiscard]]
constexpr auto operator""_sv(const alef::char32* str, alef::size length)
{
    return alef::utf32string_view(str, length);
}

} // namespace alef

#endif // ALEF_CORE_STRING_STRING_LITERALS_H
