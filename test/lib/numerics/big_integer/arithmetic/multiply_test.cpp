#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_arithmetic, operator_multiply_pp)
{
    EXPECT_EQ(1'048'576, big_integer{1024} * 1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_multiply_pn)
{
    EXPECT_EQ(-1'048'576, big_integer{1024} * -1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_multiply_np)
{
    EXPECT_EQ(-1'048'576, big_integer{-1024} * 1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, operator_multiply_nn)
{
    EXPECT_EQ(1'048'576, big_integer{-1024} * -1024);
}

TEST(alef_core_numerics_biginteger_arithmetic, multiply_pp_1)
{
    EXPECT_EQ(1'048'576, big_integer{1024}.multiply(1024));
}

TEST(alef_core_numerics_biginteger_arithmetic, multiply_pn_1)
{
    EXPECT_EQ(-1'048'576, big_integer{1024}.multiply(-1024));
}

TEST(alef_core_numerics_biginteger_arithmetic, multiply_np_1)
{
    EXPECT_EQ(-1'048'576, big_integer{-1024}.multiply(1024));
}

TEST(alef_core_numerics_biginteger_arithmetic, multiply_nn_1)
{
    EXPECT_EQ(1'048'576, big_integer{-1024}.multiply(-1024));
}
