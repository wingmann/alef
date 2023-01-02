#include <alef/alef.h>
#include <alef/lib/concepts/logic.h>

#include <gtest/gtest.h>

auto is_boolean = [](alf::concepts::logic::boolean auto value)
{
    return true;
};

auto is_not_boolean = [](alf::concepts::logic::not_boolean auto value)
{
    return true;
};

TEST(alef_lib_concepts_logic, boolean)
{
    EXPECT_TRUE(is_boolean(bool{}));
}

TEST(alef_lib_concepts_logic, not_boolean)
{
    EXPECT_TRUE(is_not_boolean(alf::i32{}));
}
