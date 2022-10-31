#ifndef ALEF_CORE_TYPES_INTEGERS_BASIC_INTEGER_H
#define ALEF_CORE_TYPES_INTEGERS_BASIC_INTEGER_H

#include "alef/concepts.h"

namespace alef {

template<concepts::numeric::integral T>
class basic_integer {
public:
    basic_integer() = default;
    virtual ~basic_integer() = default;
};

} // namespace alef



#endif // ALEF_CORE_TYPES_INTEGERS_BASIC_INTEGER_H
