#include "alef/core/types/integer/integer.h"

#include <gtest/gtest.h>

using namespace alef;

TEST(alef_core_types, integer_default_init)
{
    integer<int8> i8{};
    integer<uint8> u8{};
    integer<int16> i16{};
    integer<uint16> u16{};
    integer<int32> i32{};
    integer<uint32> u32{};
    integer<int64> i64{};
    integer<uint64> u64{};

    EXPECT_EQ(i8.get(), int8{});
    EXPECT_EQ(u8.get(), uint8{});
    EXPECT_EQ(i16.get(), int16{});
    EXPECT_EQ(u16.get(), uint16{});
    EXPECT_EQ(i32.get(), int32{});
    EXPECT_EQ(u32.get(), uint32{});
    EXPECT_EQ(i64.get(), int64{});
    EXPECT_EQ(u64.get(), uint64{});
}

TEST(alef_core_types, integer_init)
{
    integer i8{int8{}};
    integer u8{uint8{}};
    integer i16{int16{}};
    integer u16{uint16{}};
    integer i32{int32{}};
    integer u32{uint32{}};
    integer i64{int64{}};
    integer u64{uint64{}};

    EXPECT_EQ(i8.get(), int8{});
    EXPECT_EQ(u8.get(), uint8{});
    EXPECT_EQ(i16.get(), int16{});
    EXPECT_EQ(u16.get(), uint16{});
    EXPECT_EQ(i32.get(), int32{});
    EXPECT_EQ(u32.get(), uint32{});
    EXPECT_EQ(i64.get(), int64{});
    EXPECT_EQ(u64.get(), uint64{});
}

TEST(alef_core_types, integer_fp_init)
{
    integer<int32> integer1{float32{}};
    integer<int32> integer2{float64{}};
    integer<int64> integer3{float128{}};

    EXPECT_EQ(integer1.get(), int32{});
    EXPECT_EQ(integer2.get(), int32{});
    EXPECT_EQ(integer3.get(), int64{});
}

TEST(alef_core_types, integer_chars_init)
{
    integer<int32> integer1{char{}};
    integer<int32> integer2{wchar{}};
    integer<int32> integer3{char8{}};
    integer<int32> integer4{char16{}};
    integer<int32> integer5{char32{}};

    EXPECT_EQ(integer1.get(), int32{});
    EXPECT_EQ(integer2.get(), int32{});
    EXPECT_EQ(integer3.get(), int32{});
    EXPECT_EQ(integer4.get(), int32{});
    EXPECT_EQ(integer5.get(), int32{});
}

TEST(alef_core_types, check_type)
{
    integer<int8> i8{};
    integer<uint8> u8{};
    integer<int16> i16{};
    integer<uint16> u16{};
    integer<int32> i32{};
    integer<uint32> u32{};
    integer<int64> i64{};
    integer<uint64> u64{};

    EXPECT_EQ(i8.get_type(), type::primitive_type::int8);
    EXPECT_EQ(u8.get_type(), type::primitive_type::uint8);
    EXPECT_EQ(i16.get_type(), type::primitive_type::int16);
    EXPECT_EQ(u16.get_type(), type::primitive_type::uint16);
    EXPECT_EQ(i32.get_type(), type::primitive_type::int32);
    EXPECT_EQ(u32.get_type(), type::primitive_type::uint32);
    EXPECT_EQ(i64.get_type(), type::primitive_type::int64);
    EXPECT_EQ(u64.get_type(), type::primitive_type::uint64);
}

TEST(alef_core_types, integer_math_add)
{
    EXPECT_EQ(integer{64}.add(64).get(), 128);
}

TEST(alef_core_types, integer_math_subtract)
{
    EXPECT_EQ(integer{128}.subtract(64).get(), 64);
}

TEST(alef_core_types, integer_math_multiply)
{
    EXPECT_EQ(integer{16}.multiply(8).get(), 128);
}

TEST(alef_core_types, integer_math_divide)
{
    EXPECT_EQ(integer{128}.divide(8).get(), 16);
}

TEST(alef_core_types, integer_math_mod)
{
    EXPECT_EQ(integer{64}.mod(3).get(), 1);
}

TEST(alef_core_types, integer_math_pow)
{
    EXPECT_EQ(integer{8}.pow(10).get(), 1'073'741'824);
}
