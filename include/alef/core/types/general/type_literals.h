#ifndef ALEF_CORE_GENERAL_TYPE_LITERALS_H
#define ALEF_CORE_GENERAL_TYPE_LITERALS_H

#include "alef/core/types/general/primitives.h"

namespace alf {

// Integers ----------------------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_i8(alf::usize value)
{
    return static_cast<alf::i8>(value);
}

[[nodiscard]]
constexpr auto operator""_ui8(alf::usize value)
{
    return static_cast<alf::ui8>(value);
}

[[nodiscard]]
constexpr auto operator""_i16(alf::usize value)
{
    return static_cast<alf::i16>(value);
}

[[nodiscard]]
constexpr auto operator""_ui16(alf::usize value)
{
    return static_cast<alf::ui16>(value);
}

[[nodiscard]]
constexpr auto operator""_i32(alf::usize value)
{
    return static_cast<alf::i32>(value);
}

[[nodiscard]]
constexpr auto operator""_ui32(alf::usize value)
{
    return static_cast<alf::ui32>(value);
}

[[nodiscard]]
constexpr auto operator""_i64(alf::usize value)
{
    return static_cast<alf::i64>(value);
}

[[nodiscard]]
constexpr auto operator""_ui64(alf::usize value)
{
    return static_cast<alf::ui64>(value);
}

[[nodiscard]]
constexpr auto operator""_isz(alf::usize value)
{
    return static_cast<alf::isize>(value);
}

[[nodiscard]]
constexpr auto operator""_usz(alf::usize value)
{
    return value;
}

// Floating point ----------------------------------------------------------------------------------

[[nodiscard]]
constexpr auto operator""_f32(alf::f128 value)
{
    return static_cast<alf::f32>(value);
}

[[nodiscard]]
constexpr auto operator""_f64(alf::f128 value)
{
    return static_cast<alf::f64>(value);
}

[[nodiscard]]
constexpr auto operator""_f128(alf::f128 value)
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
constexpr auto operator""_wch(alf::wchar value)
{
    return alf::wchar{value};
}

[[nodiscard]]
constexpr auto operator""_ch8(alf::char8 value)
{
    return alf::char8{value};
}

[[nodiscard]]
constexpr auto operator""_ch16(alf::char16 value)
{
    return alf::char16{value};
}

[[nodiscard]]
constexpr auto operator""_ch32(alf::char32 value)
{
    return alf::char32{value};
}

} // namespace alf

#endif // ALEF_CORE_GENERAL_TYPE_LITERALS_H
