#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_math, pow10_1)
{
    EXPECT_EQ(big_integer{16}.pow10(), "10000000000000000");
}

TEST(alef_core_numerics_biginteger_math, pow10_2)
{
    EXPECT_EQ(
        big_integer{64}.pow10(),
        "10000000000000000000000000000000000000000000000000000000000000000");
}
