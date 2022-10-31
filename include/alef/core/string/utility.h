#ifndef ALEF_CORE_UTILITY_STRINGS_H
#define ALEF_CORE_UTILITY_STRINGS_H

#include "alef/string.h"

#include <vector>

namespace alef::strings {

std::vector<alef::string> split(const alef::string& text, char delimiter)
{
    alef::string_stream stream{text};
    alef::string item;
    std::vector<alef::string> data;

    while (std::getline(stream, item, delimiter))
        data.emplace_back(item);

    return data;
}

} // namespace alef::strings

#endif // ALEF_CORE_UTILITY_STRINGS_H
