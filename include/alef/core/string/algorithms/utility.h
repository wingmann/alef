#ifndef ALEF_CORE_STRING_ALGORITHMS_UTILITY_H
#define ALEF_CORE_STRING_ALGORITHMS_UTILITY_H

#include "alef/core/string/string.h"
#include "alef/core/string/string_stream.h"

#include <vector>

namespace alf::algo::str {

std::vector<alf::string> split(const alf::string& text, char delimiter)
{
    alf::string_stream stream{text};
    alf::string item;
    std::vector<alf::string> data;

    while (std::getline(stream, item, delimiter))
        data.emplace_back(item);

    return data;
}

} // namespace alf::algo::str

#endif // ALEF_CORE_STRING_ALGORITHMS_UTILITY_H
