#include <alef/alef.h>
#include <alef/lib/concepts/chars.h>

#include <gtest/gtest.h>

auto is_character = [](alf::concepts::character auto value)
{
    return true;
};

TEST(alef_lib_concepts_chars, init)
{
    EXPECT_TRUE(is_character(char{}));
    EXPECT_TRUE(is_character(alf::schar{}));
    EXPECT_TRUE(is_character(alf::uchar{}));
    EXPECT_TRUE(is_character(alf::wchar{}));
    EXPECT_TRUE(is_character(alf::char8{}));
    EXPECT_TRUE(is_character(alf::char16{}));
    EXPECT_TRUE(is_character(alf::char32{}));
}
