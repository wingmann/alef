#include "utility.h"

#include <gtest/gtest.h>

TEST(alef_lib_err_fusion, invalid_argument)
{
    auto number = convert_to_int("ERR1024");

    if (number.is_err()) {
        switch (number.unwrap_err().get()) {
        case logic_error::kind::invalid_argument:
            EXPECT_EQ(number.unwrap_err().what(), "invalid argument");
            break;
        default:
            break;
        }
    }
}

TEST(alef_lib_err_fusion, out_of_range)
{
    auto number = convert_to_int("99999999999999");

    if (number.is_err()) {
        switch (number.unwrap_err().get()) {
        case logic_error::kind::out_of_range:
            EXPECT_EQ(number.unwrap_err().what(), "out of range");
            break;
        default:
            EXPECT_TRUE(false);
            break;
        }
    }
}

TEST(alef_lib_err_fusion, correct)
{
    auto number = convert_to_int("1024");

    if (number.is_ok())
        EXPECT_EQ(number.unwrap(), 1024);
    else
        EXPECT_TRUE(false);
}
