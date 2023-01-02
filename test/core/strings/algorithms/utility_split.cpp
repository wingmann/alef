#include <alef/string.h>

#include <gtest/gtest.h>

TEST(alef_core_string_algorithms_utility_split, correct)
{
    auto result = alf::algo::str::split("Lorem|ipsum|dolor sit amet", '|');

    EXPECT_EQ(result[0], "Lorem");
    EXPECT_EQ(result[1], "ipsum");
    EXPECT_EQ(result[2], "dolor sit amet");
}

TEST(alef_core_string_algorithms_utility_split, empty)
{
    auto result = alf::algo::str::split("Lorem ipsum dolor sit amet", '|');
    EXPECT_TRUE(result.size() == 1);
}
