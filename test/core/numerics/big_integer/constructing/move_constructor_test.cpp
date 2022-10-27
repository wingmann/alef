#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_constructing, move_constructor)
{
    big_integer from{1024};
    big_integer to{std::move(from)};

    EXPECT_NE(from, to);
    EXPECT_EQ(from, 0);
    EXPECT_EQ(to, 1024);
}
