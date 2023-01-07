#ifndef WINGMANN_ALEF_CORE_TYPES_NUMERICS_H
#define WINGMANN_ALEF_CORE_TYPES_NUMERICS_H

#include "alef/alef.h"

namespace alf::types::numerics {

/// @brief The base of a system of number.
enum class radix : alf::ui8 {
    binary = 2,
    octal = 8,
    decimal = 10,
    hexadecimal = 16
};

} // namespace alf::types::numerics

#endif // WINGMANN_ALEF_CORE_TYPES_NUMERICS_H
