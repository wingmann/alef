#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_comparison, not_equivalent_1)
{
    EXPECT_TRUE(big_integer{1024} != big_integer{-1024});
}

TEST(alef_core_numerics_biginteger_comparison, not_equivalent_2)
{
    EXPECT_TRUE(big_integer{-256} != big_integer{256});
}

TEST(alef_core_numerics_biginteger_comparison, not_equivalent_3)
{
    EXPECT_FALSE(big_integer{0} != big_integer{0});
}
