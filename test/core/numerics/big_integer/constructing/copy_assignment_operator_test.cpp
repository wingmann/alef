#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_constructing, copy_assignment_operator)
{
    big_integer from{1024};
    big_integer same = from;

    EXPECT_EQ(from, same);
}
