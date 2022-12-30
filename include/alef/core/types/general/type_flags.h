#ifndef ALEF_CORE_TYPES_GENERAL_TYPE_FLAGS_H
#define ALEF_CORE_TYPES_GENERAL_TYPE_FLAGS_H

#include "alef/core/types/general/basic.h"

#include "alef/lib/concepts/any.h"

namespace alf::type {

enum class basic_type : ui8 {
    int8 = 0,
    uint8,
    int16,
    uint16,
    int32,
    uint32,
    int64,
    uint64,

    float32 = 10,
    float64,
    float128,

    character = 100,
    wchar,
    char8,
    char16,
    char32,

    boolean = 110,
};

enum class integer_type : ui8 {
    int8   = static_cast<alf::ui8>(basic_type::int8),
    uint8  = static_cast<alf::ui8>(basic_type::uint8),
    int16  = static_cast<alf::ui8>(basic_type::int16),
    uint16 = static_cast<alf::ui8>(basic_type::uint16),
    int32  = static_cast<alf::ui8>(basic_type::int32),
    uint32 = static_cast<alf::ui8>(basic_type::uint32),
    int64  = static_cast<alf::ui8>(basic_type::int64),
    uint64 = static_cast<alf::ui8>(basic_type::uint64),
};

enum class floating_point_type : ui8 {
    float32  = static_cast<alf::ui8>(basic_type::float32),
    float64  = static_cast<alf::ui8>(basic_type::float64),
    float128 = static_cast<alf::ui8>(basic_type::float128),
};

enum class character_type : ui8 {
    character = static_cast<alf::ui8>(basic_type::character),
    wchar     = static_cast<alf::ui8>(basic_type::wchar),
    char8     = static_cast<alf::ui8>(basic_type::char8),
    char16    = static_cast<alf::ui8>(basic_type::char16),
    char32    = static_cast<alf::ui8>(basic_type::char32),
};

template<concepts::any::primitive T>
class type_id {
public:
    basic_type operator()();
};

// Integers ----------------------------------------------------------------------------------------

template<>
class type_id<i8> {
public:
    basic_type operator()() { return basic_type::int8; }
};

template<>
class type_id<ui8> {
public:
    basic_type operator()() { return basic_type::uint8; }
};

template<>
class type_id<i16> {
public:
    basic_type operator()() { return basic_type::int16; }
};

template<>
class type_id<ui16> {
public:
    basic_type operator()() { return basic_type::uint16; }
};

template<>
class type_id<i32> {
public:
    basic_type operator()() { return basic_type::int32; }
};

template<>
class type_id<ui32> {
public:
    basic_type operator()() { return basic_type::uint32; }
};

template<>
class type_id<i64> {
public:
    basic_type operator()() { return basic_type::int64; }
};

template<>
class type_id<ui64> {
public:
    basic_type operator()() { return basic_type::uint64; }
};

// Floating point ----------------------------------------------------------------------------------

template<>
class type_id<f32> {
public:
    basic_type operator()() { return basic_type::float32; }
};

template<>
class type_id<f64> {
public:
    basic_type operator()() { return basic_type::float64; }
};

template<>
class type_id<f128> {
public:
    basic_type operator()() { return basic_type::float128; }
};

// Characters --------------------------------------------------------------------------------------

template<>
class type_id<char> {
public:
    basic_type operator()() { return basic_type::character; }
};

template<>
class type_id<wchar> {
public:
    basic_type operator()() { return basic_type::wchar; }
};

template<>
class type_id<char8> {
public:
    basic_type operator()() { return basic_type::char8; }
};

template<>
class type_id<char16> {
public:
    basic_type operator()() { return basic_type::char16; }
};

template<>
class type_id<char32> {
public:
    basic_type operator()() { return basic_type::char32; }
};

// Boolean -----------------------------------------------------------------------------------------

template<>
class type_id<bool> {
public:
    basic_type operator()() { return basic_type::boolean; }
};

} // namespace alf::type

#endif // ALEF_CORE_TYPES_GENERAL_TYPE_FLAGS_H
