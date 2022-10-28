#include <alef/core/utility/strings.h>

#include <gtest/gtest.h>

using namespace alef::utility;

TEST(alef_core_utility, split)
{
    auto result = split("Lorem|ipsum|dolor sit amet", '|');

    EXPECT_EQ(result[0], "Lorem");
    EXPECT_EQ(result[1], "ipsum");
    EXPECT_EQ(result[2], "dolor sit amet");
}
