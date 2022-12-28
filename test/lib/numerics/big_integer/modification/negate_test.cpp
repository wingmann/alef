#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_modification, operator_tilde_positive)
{
    EXPECT_EQ(-1'782'737, big_integer{1'782'737}.negate());
}

TEST(alef_core_numerics_biginteger_modification, operator_tilde_negative)
{
    EXPECT_EQ(327'327'389'182, big_integer{-327'327'389'182}.negate());
}

TEST(alef_core_numerics_biginteger_modification, operator_tilde_zero)
{
    EXPECT_EQ(0, big_integer{}.negate());
}
