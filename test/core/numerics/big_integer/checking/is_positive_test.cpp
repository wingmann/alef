#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_checking, is_positive_1)
{
    EXPECT_FALSE(big_integer{-512}.is_positive());
}

TEST(alef_core_numerics_biginteger_checking, is_positive_2)
{
    EXPECT_TRUE(big_integer{256}.is_positive());
}

TEST(alef_core_numerics_biginteger_checking, is_positive_zero)
{
    EXPECT_TRUE(big_integer{0}.is_positive());
}
