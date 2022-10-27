#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_modification, decrement_prefix)
{
    big_integer number{256};
    EXPECT_EQ(255, --number);
}

TEST(alef_core_numerics_biginteger_modification, decrement_postfix)
{
    big_integer number{512};

    auto temp = number--;
    auto decremented_value = number;

    EXPECT_EQ(temp, 512);
    EXPECT_EQ(decremented_value, 511);
}
