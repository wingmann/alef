#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_comparison, greater_1)
{
    EXPECT_TRUE(big_integer{256} > big_integer{128});
}

TEST(alef_core_numerics_biginteger_comparison, greater_2)
{
    EXPECT_TRUE(big_integer{256} > big_integer{-128});
}

TEST(alef_core_numerics_biginteger_comparison, greater_3)
{
    EXPECT_TRUE(big_integer{-64} > big_integer{-128});
}

TEST(alef_core_numerics_biginteger_comparison, greater_4)
{
    EXPECT_FALSE(big_integer{0} > big_integer{0});
}
