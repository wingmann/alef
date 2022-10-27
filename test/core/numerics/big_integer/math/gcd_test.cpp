#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_math, gcd_1)
{
    EXPECT_EQ(2 * 3, big_integer{2 * 2 * 3}.gcd(2 * 3 * 3));
}
