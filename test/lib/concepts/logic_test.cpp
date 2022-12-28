#include <alef/core.h>
#include <alef/lib/concepts/logic.h>

#include <gtest/gtest.h>

using namespace alf::concepts::logic;

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
    EXPECT_TRUE(is_not_boolean(alf::i32{}));
}
