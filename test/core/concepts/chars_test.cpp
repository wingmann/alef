#include <alef/core.h>
#include <alef/core/concepts/chars.h>

#include <gtest/gtest.h>

using namespace alef::concepts::chars;

auto is_character = [](character auto value)
{
    return true;
};

TEST(alef_core_concepts, character)
{
    EXPECT_TRUE(is_character(char{}));
    EXPECT_TRUE(is_character(alef::schar{}));
    EXPECT_TRUE(is_character(alef::uchar{}));
    EXPECT_TRUE(is_character(alef::wchar{}));
    EXPECT_TRUE(is_character(alef::char8{}));
    EXPECT_TRUE(is_character(alef::char16{}));
    EXPECT_TRUE(is_character(alef::char32{}));
}
