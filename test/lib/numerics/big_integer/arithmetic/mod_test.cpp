#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_arithmetic, operator_mod)
{
    EXPECT_EQ(big_integer{64} % 8, 0);
}

TEST(alef_core_numerics_biginteger_arithmetic, mod)
{
    EXPECT_EQ(0, big_integer{64}.mod(8));
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_mod_throw)
{
    EXPECT_THROW(big_integer{} % 0, std::invalid_argument);
}
