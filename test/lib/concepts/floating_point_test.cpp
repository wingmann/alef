#include <alef/core.h>
#include <alef/lib/concepts/numeric.h>

#include <gtest/gtest.h>

using namespace alf::concepts::numeric;

auto is_numeric_floating_point = [](floating_point auto value)
{
    return true;
};

TEST(alef_core_concepts, numeric_floating_point)
{
    EXPECT_TRUE(is_numeric_floating_point(alf::f32{}));
    EXPECT_TRUE(is_numeric_floating_point(alf::f64{}));
    EXPECT_TRUE(is_numeric_floating_point(alf::f128{}));
}
