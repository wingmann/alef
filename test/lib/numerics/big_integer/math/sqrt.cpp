#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_math, sqrt_1)
{
    EXPECT_EQ(big_integer{64}.sqrt(), 8);
}

TEST(alef_core_numerics_biginteger_math, sqrt_2)
{
    EXPECT_EQ(big_integer{104857600}.sqrt(), 10240);
}
