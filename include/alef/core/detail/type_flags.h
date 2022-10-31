#ifndef ALEF_CORE_TYPES_INTEGER_INTEGER_TYPE_H
#define ALEF_CORE_TYPES_INTEGER_INTEGER_TYPE_H

#include "alef/core/concepts/any.h"
#include "alef/core/detail/types.h"

namespace alef::type {

enum class primitive_type : int {
    // Integers.
    int8 = 10,
    uint8,
    int16,
    uint16,
    int32,
    uint32,
    int64,
    uint64,

    // Floating point.
    float32 = 100,
    float64,
    float128,

    // Characters.
    character = 1000,
    wchar,
    char8,
    char16,
    char32,

    // Boolean.
    boolean
};

enum class integer_type : int {
    int8   = static_cast<int>(primitive_type::int8),
    uint8  = static_cast<int>(primitive_type::uint8),
    int16  = static_cast<int>(primitive_type::int16),
    uint16 = static_cast<int>(primitive_type::uint16),
    int32  = static_cast<int>(primitive_type::int32),
    uint32 = static_cast<int>(primitive_type::uint32),
    int64  = static_cast<int>(primitive_type::int64),
    uint64 = static_cast<int>(primitive_type::uint64),
};

enum class floating_point_type : int {
    float32  = static_cast<int>(primitive_type::float32),
    float64  = static_cast<int>(primitive_type::float64),
    float128 = static_cast<int>(primitive_type::float128),
};

enum class character_type : int {
    character = static_cast<int>(primitive_type::character),
    wchar     = static_cast<int>(primitive_type::wchar),
    char8     = static_cast<int>(primitive_type::char8),
    char16    = static_cast<int>(primitive_type::char16),
    char32    = static_cast<int>(primitive_type::char32),
};

template<concepts::any::primitive T>
class type_id {
public:
    primitive_type operator()();
};

// Integers ----------------------------------------------------------------------------------------

template<>
class type_id<int8> {
public:
    primitive_type operator()() { return primitive_type::int8; }
};

template<>
class type_id<uint8> {
public:
    primitive_type operator()() { return primitive_type::uint8; }
};

template<>
class type_id<int16> {
public:
    primitive_type operator()() { return primitive_type::int16; }
};

template<>
class type_id<uint16> {
public:
    primitive_type operator()() { return primitive_type::uint16; }
};

template<>
class type_id<int32> {
public:
    primitive_type operator()() { return primitive_type::int32; }
};

template<>
class type_id<uint32> {
public:
    primitive_type operator()() { return primitive_type::uint32; }
};

template<>
class type_id<int64> {
public:
    primitive_type operator()() { return primitive_type::int64; }
};

template<>
class type_id<uint64> {
public:
    primitive_type operator()() { return primitive_type::uint64; }
};

// Floating point ----------------------------------------------------------------------------------

template<>
class type_id<float32> {
public:
    primitive_type operator()() { return primitive_type::float32; }
};

template<>
class type_id<float64> {
public:
    primitive_type operator()() { return primitive_type::float64; }
};

template<>
class type_id<float128> {
public:
    primitive_type operator()() { return primitive_type::float128; }
};

// Characters --------------------------------------------------------------------------------------

template<>
class type_id<char> {
public:
    primitive_type operator()() { return primitive_type::character; }
};

template<>
class type_id<wchar> {
public:
    primitive_type operator()() { return primitive_type::wchar; }
};

template<>
class type_id<char8> {
public:
    primitive_type operator()() { return primitive_type::char8; }
};

template<>
class type_id<char16> {
public:
    primitive_type operator()() { return primitive_type::char16; }
};

template<>
class type_id<char32> {
public:
    primitive_type operator()() { return primitive_type::char32; }
};

// Boolean -----------------------------------------------------------------------------------------

template<>
class type_id<bool> {
public:
    primitive_type operator()() { return primitive_type::boolean; }
};


//
//
//
//
//template<>
//primitive_type type_id<int8>()
//{
//    return primitive_type::int8;
//}
//
//template<>
//primitive_type type_id<uint8>()
//{
//    return primitive_type::uint8;
//}
//
//template<>
//primitive_type type_id<int16>()
//{
//    return primitive_type::int16;
//}
//
//template<>
//primitive_type type_id<uint16>()
//{
//    return primitive_type::uint16;
//}
//
//template<>
//primitive_type type_id<int32>()
//{
//    return primitive_type::int32;
//}
//
//template<>
//primitive_type type_id<uint32>()
//{
//    return primitive_type::uint32;
//}
//
//template<>
//primitive_type type_id<int64>()
//{
//    return primitive_type::int64;
//}
//
//template<>
//primitive_type type_id<uint64>()
//{
//    return primitive_type::uint64;
//}
//
//
//
//template<>
//primitive_type type_id<float32>()
//{
//    return primitive_type::float32;
//}
//
//template<>
//primitive_type type_id<float64>()
//{
//    return primitive_type::float64;
//}
//
//template<>
//primitive_type type_id<float128>()
//{
//    return primitive_type::float128;
//}
//
//
//
//template<>
//primitive_type type_id<char>()
//{
//    return primitive_type::character;
//}
//
//template<>
//primitive_type type_id<wchar>()
//{
//    return primitive_type::wchar;
//}
//
//template<>
//primitive_type type_id<char8>()
//{
//    return primitive_type::char8;
//}
//
//template<>
//primitive_type type_id<char16>()
//{
//    return primitive_type::char16;
//}
//
//template<>
//primitive_type type_id<char32>()
//{
//    return primitive_type::char32;
//}
//
//
//
//template<>
//primitive_type type_id<bool>()
//{
//    return primitive_type::boolean;
//}

} // namespace alef::type

#endif // ALEF_CORE_TYPES_INTEGER_INTEGER_TYPE_H
