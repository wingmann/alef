#ifndef WINGMANN_ALEF_INCLUDE_ALEF_CORE_NUMERICS_RADIX_TYPE_H
#define WINGMANN_ALEF_INCLUDE_ALEF_CORE_NUMERICS_RADIX_TYPE_H

namespace alef::numerics {

/// @brief The base of a system of number.
enum class radix_type : uint8 {
    binary = 2,
    octal = 8,
    decimal = 10,
    hexadecimal = 16,
};

} // namespace alef::numerics

#endif //WINGMANN_ALEF_INCLUDE_ALEF_CORE_NUMERICS_RADIX_TYPE_H
