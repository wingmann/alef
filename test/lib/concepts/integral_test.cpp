#include <alef/alef.h>
#include <alef/lib/concepts/numeric.h>

#include <gtest/gtest.h>

auto is_numeric_integral = [](alf::concepts::integral auto value)
{
    return true;
};

auto is_numeric_signed_integral = [](alf::concepts::signed_integral auto value)
{
    return true;
};

auto is_numeric_unsigned_integral = [](alf::concepts::unsigned_integral auto value)
{
    return true;
};

TEST(alef_lib_concepts_integral, init)
{
    EXPECT_TRUE(is_numeric_integral(alf::i8{}));
    EXPECT_TRUE(is_numeric_integral(alf::ui8{}));
    EXPECT_TRUE(is_numeric_integral(alf::i16{}));
    EXPECT_TRUE(is_numeric_integral(alf::ui16{}));
    EXPECT_TRUE(is_numeric_integral(alf::i32{}));
    EXPECT_TRUE(is_numeric_integral(alf::ui32{}));
    EXPECT_TRUE(is_numeric_integral(alf::i64{}));
    EXPECT_TRUE(is_numeric_integral(alf::ui64{}));
}

TEST(alef_lib_concepts_integral, signed_init)
{
    EXPECT_TRUE(is_numeric_signed_integral(alf::i8{}));
    EXPECT_TRUE(is_numeric_signed_integral(alf::i16{}));
    EXPECT_TRUE(is_numeric_signed_integral(alf::i32{}));
    EXPECT_TRUE(is_numeric_signed_integral(alf::i64{}));
}

TEST(alef_lib_concepts_integral, unsigned_init)
{
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui8{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui16{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui32{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui64{}));
}
