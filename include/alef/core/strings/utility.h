#ifndef ALEF_CORE_UTILITY_STRINGS_H
#define ALEF_CORE_UTILITY_STRINGS_H

#include "alef/core/strings/string.h"
#include "alef/core/strings/string_streams.h"

#include <vector>

namespace alf::strings {

std::vector<alf::string> split(const alf::string& text, char delimiter)
{
    alf::string_stream stream{text};
    alf::string item;
    std::vector<alf::string> data;

    while (std::getline(stream, item, delimiter))
        data.emplace_back(item);

    return data;
}

} // namespace alf::strings

#endif // ALEF_CORE_UTILITY_STRINGS_H
