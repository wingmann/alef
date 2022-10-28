#ifndef ALEF_CORE_CONCEPTS_NUMERIC_H
#define ALEF_CORE_CONCEPTS_NUMERIC_H

#include "alef/core/__detail/concepts.h"

namespace alef::concepts::numeric {

template<typename T>
concept integral = __detail::is_integral_v<T>;

template<typename T>
concept signed_integral = integral<T> && static_cast<T>(-1) < static_cast<T>(0);

template<typename T>
concept unsigned_integral = integral<T> && static_cast<T>(-1) > static_cast<T>(0);

template<typename T>
concept floating_point = __detail::is_floating_point_v<T>;

template<typename T>
concept number = floating_point<T> || integral<T>;

} // namespace alef::concepts::numeric

#endif // ALEF_CORE_CONCEPTS_NUMERIC_H
