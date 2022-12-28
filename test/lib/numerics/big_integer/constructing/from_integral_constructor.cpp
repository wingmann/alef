#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_constructing, from_integral_constructor)
{
    EXPECT_EQ(big_integer{2048}, 2048);
}
