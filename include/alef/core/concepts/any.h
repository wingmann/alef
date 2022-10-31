#ifndef ALEF_CORE_CONCEPTS_ANY_H
#define ALEF_CORE_CONCEPTS_ANY_H

#include "alef/core/concepts/chars.h"
#include "alef/core/concepts/numeric.h"
#include "alef/core/concepts/logic.h"

namespace alef::concepts::any {

template<typename T>
concept primitive =
    alef::concepts::numeric::number<T>  ||
    alef::concepts::chars::character<T> ||
    alef::concepts::logic::boolean<T>;

} // namespace alef::concepts::any

#endif // ALEF_CORE_CONCEPTS_ANY_H
