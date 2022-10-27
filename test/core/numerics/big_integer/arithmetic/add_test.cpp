#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_arithmetic, operator_plus_pp)
{
    EXPECT_EQ(2048, big_integer{1024} + 1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_plus_pn)
{
    EXPECT_EQ(0, big_integer{1024} + -1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_plus_np)
{
    EXPECT_EQ(0, big_integer{-1024} + 1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_plus_nn)
{
    EXPECT_EQ(-2048, big_integer{-1024} + -1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, add_pp)
{
    EXPECT_EQ(2048, big_integer{1024}.add(1024));
}

TEST(alef_core_numerics_biginteger_arithmetic, add_pn)
{
    EXPECT_EQ(0, big_integer{1024}.add(-1024));
}

TEST(alef_core_numerics_biginteger_arithmetic, add_np)
{
    EXPECT_EQ(0, big_integer{-1024}.add(1024));
}

TEST(alef_core_numerics_biginteger_arithmetic, add_nn)
{
    EXPECT_EQ(-2048, big_integer{-1024}.add(-1024));
}
