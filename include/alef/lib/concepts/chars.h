#ifndef ALEF_CORE_CONCEPTS_CHARS_H
#define ALEF_CORE_CONCEPTS_CHARS_H

#include "__detail.h"

namespace alf::concepts {

template<typename T>
concept character = alf::concepts::__detail::is_character_v<T>;

} // namespace alf::concepts

#endif // ALEF_CORE_CONCEPTS_CHARS_H
