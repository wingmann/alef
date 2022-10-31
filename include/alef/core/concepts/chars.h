#ifndef ALEF_CORE_CONCEPTS_CHARS_H
#define ALEF_CORE_CONCEPTS_CHARS_H

#include "alef/core/detail/concepts.h"

namespace alef::concepts::chars {

template<typename T>
concept character = alef::concepts::__detail::is_character_v<T>;

} // namespace alef::concepts::chars

#endif // ALEF_CORE_CONCEPTS_CHARS_H
