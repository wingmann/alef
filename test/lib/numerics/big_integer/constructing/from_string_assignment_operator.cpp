#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_constructing, from_string_assignment_operator)
{
    std::string value{"2048"};
    big_integer number = value;

    EXPECT_EQ(number, 2048);
}
