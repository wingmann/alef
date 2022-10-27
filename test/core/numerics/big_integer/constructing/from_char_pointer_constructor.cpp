#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_constructing, from_char_pointer_constructor)
{
    EXPECT_EQ(big_integer{"2048"}, 2048);
}
