#ifndef ALEF_CORE_CONCEPTS_SORTING_H
#define ALEF_CORE_CONCEPTS_SORTING_H

#include "general.h"

namespace alf::concepts::sorting {

template<typename T>
concept totally_ordered_swappable = totally_ordered<T> && swappable<T>;

} // namespace alf::concepts::sorting

#endif // ALEF_CORE_CONCEPTS_SORTING_H
