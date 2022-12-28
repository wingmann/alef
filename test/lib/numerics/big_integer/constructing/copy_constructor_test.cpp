#include "alef/lib/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alf::numerics;

TEST(alef_core_numerics_biginteger_constructing, copy_constructor)
{
    big_integer from{1024};
    big_integer same{from};

    EXPECT_EQ(from, same);
}
