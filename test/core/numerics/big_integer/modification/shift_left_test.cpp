#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_modification, shift_left_1)
{
    EXPECT_EQ(40, big_integer{10}.shift_left(2));
}

TEST(alef_core_numerics_biginteger_modification, shift_left_shift_2)
{
    EXPECT_EQ(4096, big_integer{512}.shift_left(3));
}

TEST(alef_core_numerics_biginteger_modification, shift_left_throw)
{
    EXPECT_THROW(auto temp = big_integer{10}.shift_left(-2), std::invalid_argument);
}
