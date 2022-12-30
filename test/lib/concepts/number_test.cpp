#include <alef/alef.h>
#include <alef/lib/concepts/numeric.h>

#include <gtest/gtest.h>

using namespace alf::concepts::numeric;

auto is_numeric_number = [](number auto value)
{
    return true;
};

TEST(alef_core_concepts, numeric_number)
{
    EXPECT_TRUE(is_numeric_number(alf::i8{}));
    EXPECT_TRUE(is_numeric_number(alf::ui8{}));
    EXPECT_TRUE(is_numeric_number(alf::i16{}));
    EXPECT_TRUE(is_numeric_number(alf::ui16{}));
    EXPECT_TRUE(is_numeric_number(alf::i32{}));
    EXPECT_TRUE(is_numeric_number(alf::ui32{}));
    EXPECT_TRUE(is_numeric_number(alf::i64{}));
    EXPECT_TRUE(is_numeric_number(alf::ui64{}));
    EXPECT_TRUE(is_numeric_number(alf::f32{}));
    EXPECT_TRUE(is_numeric_number(alf::f64{}));
    EXPECT_TRUE(is_numeric_number(alf::f128{}));
}
