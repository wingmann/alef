#ifndef ALEF_CORE_CONCEPTS_LOGIC_H
#define ALEF_CORE_CONCEPTS_LOGIC_H

#include "general.h"

namespace alf::concepts {

template<typename T>
concept boolean = alf::concepts::same_as<T, bool>;

template<typename T>
concept not_boolean = !boolean<T>;

} // namespace alf::concepts

#endif // ALEF_CORE_CONCEPTS_LOGIC_H
