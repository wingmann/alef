/// @file   kmp.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Knuth-Morris-Pratt substring searching algorithm implementation.
/// @date   2022-10-02
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_STRING_ALGORITHMS_SEARCH_KMP_H
#define ALEF_CORE_STRING_ALGORITHMS_SEARCH_KMP_H

#include "alef/alef.h"
#include "alef/core/string/string.h"

#include <vector>

namespace alf::algo::str {

namespace {

// Gets failure array.
auto get_failure = [](const alf::string& pattern)
{
    auto pattern_size = pattern.size();
    auto failure = std::vector<alf::usize>(pattern_size + 1);
    failure[0] = -1;

    for (alf::usize i = 0, j = failure[0]; i < pattern_size; i++) {
        while ((j != alf::string::npos) && (pattern[j] != pattern[i]))
            j = failure[j];

        failure[i + 1] = ++j;
    }
    return failure;
};

} // namespace

/// @brief  KMP algorithm to find a pattern in a text.
///
/// @param text    Text in which to search.
/// @param pattern String pattern to search.
/// @return        Search result.
///
/// @see https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
///
bool kmp(const alf::string& text, const alf::string& pattern)
{
    auto text_size = text.size();
    auto pattern_size = pattern.size();
    auto failure = get_failure(pattern);

    for (alf::usize i = 0, j = 0; i < text_size; i++) {
        while ((j != alf::string::npos) && (pattern[j] != text[i]))
            j = failure[j];

        if (++j == pattern_size) return true;
    }
    return {};
}

} // namespace alf::algo::str

#endif // ALEF_CORE_STRING_ALGORITHMS_SEARCH_KMP_H
