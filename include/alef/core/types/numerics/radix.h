#ifndef WINGMANN_ALEF_CORE_TYPES_NUMERICS_H
#define WINGMANN_ALEF_CORE_TYPES_NUMERICS_H

#include "alef/core.h"

namespace alf::types {

/// @brief The base of a system of number.
enum class radix : alf::ui8 {
    binary = 2,
    octal = 8,
    decimal = 10,
    hexadecimal = 16,
};

} // namespace alf::types

#endif // WINGMANN_ALEF_CORE_TYPES_NUMERICS_H
