#ifndef ALEF_CORE_CONCEPTS_ANY_H
#define ALEF_CORE_CONCEPTS_ANY_H

#include "chars.h"
#include "numeric.h"
#include "logic.h"

namespace alf::concepts::any {

template<typename T>
concept primitive =
    alf::concepts::numeric::number<T>  ||
    alf::concepts::chars::character<T> ||
    alf::concepts::logic::boolean<T>;

} // namespace alf::concepts::any

#endif // ALEF_CORE_CONCEPTS_ANY_H
