#include <alef/string.h>

#include <gtest/gtest.h>

using namespace alf::strings;

TEST(alef_core_strings, split)
{
    auto result = split("Lorem|ipsum|dolor sit amet", '|');

    EXPECT_EQ(result[0], "Lorem");
    EXPECT_EQ(result[1], "ipsum");
    EXPECT_EQ(result[2], "dolor sit amet");
}
