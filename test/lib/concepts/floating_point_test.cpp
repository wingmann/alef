#include <alef/alef.h>
#include <alef/lib/concepts/numeric.h>

#include <gtest/gtest.h>

auto is_numeric_floating_point = [](alf::concepts::numeric::floating_point auto value)
{
    return true;
};

TEST(alef_lib_concepts_numeric_floating_point, init)
{
    EXPECT_TRUE(is_numeric_floating_point(alf::f32{}));
    EXPECT_TRUE(is_numeric_floating_point(alf::f64{}));
    EXPECT_TRUE(is_numeric_floating_point(alf::f128{}));
}
