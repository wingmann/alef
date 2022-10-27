#include <alef/core.h>
#include <alef/core/concepts.h>

#include <gtest/gtest.h>

using namespace alef::concepts::numeric;

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
    EXPECT_TRUE(is_numeric_integral(alef::int8{}));
    EXPECT_TRUE(is_numeric_integral(alef::uint8{}));
    EXPECT_TRUE(is_numeric_integral(alef::int16{}));
    EXPECT_TRUE(is_numeric_integral(alef::uint16{}));
    EXPECT_TRUE(is_numeric_integral(alef::int32{}));
    EXPECT_TRUE(is_numeric_integral(alef::uint32{}));
    EXPECT_TRUE(is_numeric_integral(alef::int64{}));
    EXPECT_TRUE(is_numeric_integral(alef::uint64{}));
}

TEST(alef_core_concepts, numeric_signed_integral)
{
    EXPECT_TRUE(is_numeric_signed_integral(alef::int8{}));
    EXPECT_TRUE(is_numeric_signed_integral(alef::int16{}));
    EXPECT_TRUE(is_numeric_signed_integral(alef::int32{}));
    EXPECT_TRUE(is_numeric_signed_integral(alef::int64{}));
}

TEST(alef_core_concepts, numeric_unsigned_integral)
{
    EXPECT_TRUE(is_numeric_unsigned_integral(alef::uint8{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alef::uint16{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alef::uint32{}));
    EXPECT_TRUE(is_numeric_unsigned_integral(alef::uint64{}));
}
