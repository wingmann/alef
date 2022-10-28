#include <alef/core.h>
#include <alef/core/concepts/logic.h>

#include <gtest/gtest.h>

using namespace alef::concepts::logic;

auto is_boolean = [](boolean auto value)
{
    return true;
};

auto is_not_boolean = [](not_boolean auto value)
{
    return true;
};

TEST(alef_core_concepts, boolean)
{
    EXPECT_TRUE(is_boolean(bool{}));
}

TEST(alef_core_concepts, not_boolean)
{
    EXPECT_TRUE(is_not_boolean(alef::int32{}));
}
