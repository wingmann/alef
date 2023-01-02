#include <alef/core/string/algorithms/search/kmp.h>

#include <gtest/gtest.h>

TEST(alef_core_string_algorithms_search_kmp, found)
{
    auto text{"A string-matching algorithm wants to find the starting index"};
    EXPECT_TRUE(alf::algo::str::kmp(text, "ring-match"));
}

TEST(alef_core_string_algorithms_search_kmp, not_found)
{
    auto text{"A string-matching algorithm wants to find the starting index"};
    EXPECT_FALSE(alf::algo::str::kmp(text, "hctam-gnir"));
}
