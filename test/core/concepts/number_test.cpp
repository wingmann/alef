#include <alef/core.h>
#include <alef/core/concepts/numeric.h>

#include <gtest/gtest.h>

using namespace alef::concepts::numeric;

auto is_numeric_number = [](number auto value)
{
    return true;
};

TEST(alef_core_concepts, numeric_number)
{
    EXPECT_TRUE(is_numeric_number(alef::int8{}));
    EXPECT_TRUE(is_numeric_number(alef::uint8{}));
    EXPECT_TRUE(is_numeric_number(alef::int16{}));
    EXPECT_TRUE(is_numeric_number(alef::uint16{}));
    EXPECT_TRUE(is_numeric_number(alef::int32{}));
    EXPECT_TRUE(is_numeric_number(alef::uint32{}));
    EXPECT_TRUE(is_numeric_number(alef::int64{}));
    EXPECT_TRUE(is_numeric_number(alef::uint64{}));
    EXPECT_TRUE(is_numeric_number(alef::float32{}));
    EXPECT_TRUE(is_numeric_number(alef::float64{}));
    EXPECT_TRUE(is_numeric_number(alef::float128{}));
}
