#ifndef ALEF_CORE_CONCEPTS_ANY_H
#define ALEF_CORE_CONCEPTS_ANY_H

#include "chars.h"
#include "logic.h"
#include "numeric.h"

namespace alf::concepts {

template<typename T>
concept primitive =
    alf::concepts::number<T> ||
    alf::concepts::character<T> ||
    alf::concepts::boolean<T>;

} // namespace alf::concepts

#endif // ALEF_CORE_CONCEPTS_ANY_H
