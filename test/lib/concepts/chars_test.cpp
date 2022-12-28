#include <alef/core.h>
#include <alef/lib/concepts/chars.h>

#include <gtest/gtest.h>

using namespace alf::concepts::chars;

auto is_character = [](character auto value)
{
    return true;
};

TEST(alef_core_concepts, character)
{
    EXPECT_TRUE(is_character(char{}));
    EXPECT_TRUE(is_character(alf::schar{}));
    EXPECT_TRUE(is_character(alf::uchar{}));
    EXPECT_TRUE(is_character(alf::wchar{}));
    EXPECT_TRUE(is_character(alf::char8{}));
    EXPECT_TRUE(is_character(alf::char16{}));
    EXPECT_TRUE(is_character(alf::char32{}));
}
