#include <alef/core.h>
#include <alef/core/concepts.h>

#include <gtest/gtest.h>

using namespace alef::concepts::numeric;

auto is_numeric_floating_point = [](floating_point auto value)
{
    return true;
};

TEST(alef_core_concepts, numeric_floating_point)
{
    EXPECT_TRUE(is_numeric_floating_point(alef::float32{}));
    EXPECT_TRUE(is_numeric_floating_point(alef::float64{}));
    EXPECT_TRUE(is_numeric_floating_point(alef::float128{}));
}
