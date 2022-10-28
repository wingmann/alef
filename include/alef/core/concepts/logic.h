#ifndef ALEF_CORE_CONCEPTS_LOGIC_H
#define ALEF_CORE_CONCEPTS_LOGIC_H

#include "alef/core/concepts/general.h"

namespace alef::concepts::logic {

template<typename T>
concept boolean = same_as<T, bool>;

template<typename T>
concept not_boolean = !boolean<T>;

} // namespace alef::concepts::logic

#endif // ALEF_CORE_CONCEPTS_LOGIC_H
