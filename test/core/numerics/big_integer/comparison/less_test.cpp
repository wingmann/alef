#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_comparison, less_1)
{
    EXPECT_TRUE(big_integer{128} < big_integer{256});
}

TEST(alef_core_numerics_biginteger_comparison, less_2)
{
    EXPECT_TRUE(big_integer{-128} < big_integer{256});
}

TEST(alef_core_numerics_biginteger_comparison, less_3)
{
    EXPECT_TRUE(big_integer{-128} < big_integer{-64});
}

TEST(alef_core_numerics_biginteger_comparison, less_4)
{
    EXPECT_FALSE(big_integer{0} < big_integer{0});
}
