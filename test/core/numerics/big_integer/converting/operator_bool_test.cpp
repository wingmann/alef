#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_converting, operator_bool_positive)
{
    EXPECT_TRUE(big_integer{1024});
}

TEST(alef_core_numerics_biginteger_converting, operator_bool_negative)
{
    EXPECT_TRUE(big_integer{-1024});
}

TEST(alef_core_numerics_biginteger_converting, operator_bool_zero)
{
    EXPECT_FALSE(big_integer{0});
}
