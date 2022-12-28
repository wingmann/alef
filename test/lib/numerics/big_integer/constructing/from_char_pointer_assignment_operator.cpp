#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_constructing, from_char_pointer_assignment_operator)
{
    big_integer number = "2048";
    EXPECT_EQ(number, 2048);
}
