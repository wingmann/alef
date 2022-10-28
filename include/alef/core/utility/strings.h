#ifndef ALEF_CORE_UTILITY_STRINGS_H
#define ALEF_CORE_UTILITY_STRINGS_H

#include <sstream>
#include <vector>

namespace alef::utility {

std::vector<std::string> split(const std::string& text, char delimiter)
{
    std::stringstream ss{text};
    std::string item;
    std::vector<std::string> data;

    while (std::getline(ss, item, delimiter))
        data.emplace_back(item);

    return data;
}

} // namespace alef::utility

#endif // ALEF_CORE_UTILITY_STRINGS_H
