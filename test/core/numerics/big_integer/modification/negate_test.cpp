#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_modification, operator_tilde_positive)
{
    EXPECT_EQ(-1782737, big_integer{1782737}.negate());
}

TEST(alef_core_numerics_biginteger_modification, operator_tilde_negative)
{
    EXPECT_EQ(327327389182, big_integer{-327327389182}.negate());
}

TEST(alef_core_numerics_biginteger_modification, operator_tilde_zero)
{
    EXPECT_EQ(0, big_integer{}.negate());
}
