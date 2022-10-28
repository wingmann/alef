#ifndef ALEF_CORE_CONCEPTS_SORTING_H
#define ALEF_CORE_CONCEPTS_SORTING_H

#include "alef/core/concepts/general.h"

namespace alef::concepts::sorting {

template<typename T>
concept totally_ordered_swappable = totally_ordered<T> && swappable<T>;

} // namespace alef::concepts::sorting

#endif // ALEF_CORE_CONCEPTS_SORTING_H
