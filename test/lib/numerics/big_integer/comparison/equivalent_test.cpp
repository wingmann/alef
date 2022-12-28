#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_comparison, equivalent_1)
{
    EXPECT_TRUE(big_integer{1024} == big_integer{1024});
}

TEST(alef_core_numerics_biginteger_comparison, equivalent_2)
{
    EXPECT_TRUE(big_integer{-256} == big_integer{-256});
}

TEST(alef_core_numerics_biginteger_comparison, equivalent_3)
{
    EXPECT_TRUE(big_integer{0} == big_integer{0});
}

TEST(alef_core_numerics_biginteger_comparison, equivalent_4)
{
    EXPECT_FALSE(big_integer{1} == big_integer{-1});
}
