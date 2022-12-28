#include <alef/core.h>
#include <alef/lib/concepts/numeric.h>

#include <gtest/gtest.h>

using namespace alf::concepts::numeric;

auto is_numeric_integral = [](integral auto value)
{
    return true;
};

auto is_numeric_signed_integral = [](signed_integral auto value)
{
    return true;
};

auto is_numeric_unsigned_integral = [](unsigned_integral auto value)
{
    return true;
};

TEST(alef_core_concepts, numeric_integral)
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

TEST(alef_core_concepts, numeric_signed_integral)
{
    EXPECT_TRUE(is_numeric_signed_integral(alf::i8{}));
    EXPECT_TRUE(is_numeric_signed_integral(alf::i16{}));
    EXPECT_TRUE(is_numeric_signed_integral(alf::i32{}));
    EXPECT_TRUE(is_numeric_signed_integral(alf::i64{}));
}

TEST(alef_core_concepts, numeric_unsigned_integral)
{
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui8{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui16{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui32{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alf::ui64{}));
}
