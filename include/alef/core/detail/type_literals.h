#ifndef ALEF_CORE_DETAIL_TYPE_LITERALS_H
#define ALEF_CORE_DETAIL_TYPE_LITERALS_H

#include "alef/core/string/types.h"

namespace alef {

// Integers ----------------------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_i8(alef::size value)
{
    return static_cast<alef::int8>(value);
}

[[nodiscard]]
constexpr auto operator""_ui8(alef::size value)
{
    return static_cast<alef::uint8>(value);
}

[[nodiscard]]
constexpr auto operator""_i16(alef::size value)
{
    return static_cast<alef::int16>(value);
}

[[nodiscard]]
constexpr auto operator""_ui16(alef::size value)
{
    return static_cast<alef::uint16>(value);
}

[[nodiscard]]
constexpr auto operator""_i32(alef::size value)
{
    return static_cast<alef::int32>(value);
}

[[nodiscard]]
constexpr auto operator""_ui32(alef::size value)
{
    return static_cast<alef::uint32>(value);
}

[[nodiscard]]
constexpr auto operator""_i64(alef::size value)
{
    return static_cast<alef::int64>(value);
}

[[nodiscard]]
constexpr auto operator""_ui64(alef::size value)
{
    return static_cast<alef::uint64>(value);
}

[[nodiscard]]
constexpr auto operator""_ssz(alef::size value)
{
    return static_cast<alef::ssize>(value);
}

[[nodiscard]]
constexpr auto operator""_sz(alef::size value)
{
    return value;
}

// Floating point ----------------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_f32(alef::float128 value)
{
    return static_cast<alef::float32>(value);
}

[[nodiscard]]
constexpr auto operator""_f64(alef::float128 value)
{
    return static_cast<alef::float64>(value);
}

[[nodiscard]]
constexpr auto operator""_f128(alef::float128 value)
{
    return value;
}

// Characters --------------------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_ch(char value)
{
    return char{value};
}

[[nodiscard]]
constexpr auto operator""_wch(alef::wchar value)
{
    return alef::wchar{value};
}

[[nodiscard]]
constexpr auto operator""_ch8(alef::char8 value)
{
    return alef::char8{value};
}

[[nodiscard]]
constexpr auto operator""_ch16(alef::char16 value)
{
    return alef::char16{value};
}

[[nodiscard]]
constexpr auto operator""_ch32(alef::char32 value)
{
    return alef::char32{value};
}

} // namespace alef

#endif // ALEF_CORE_DETAIL_TYPE_LITERALS_H
