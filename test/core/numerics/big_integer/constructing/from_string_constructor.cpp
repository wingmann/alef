#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_constructing, from_string_constructor)
{
    std::string value{"2048"};
    big_integer number{value};

    EXPECT_EQ(number, 2048);
}
