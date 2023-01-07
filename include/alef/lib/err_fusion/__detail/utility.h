#ifndef ALEF_LIB_ERR_FUSION_DETAIL_UTILITY_H
#define ALEF_LIB_ERR_FUSION_DETAIL_UTILITY_H

#include <type_traits>

namespace alf::ef {

template<typename T, typename E>
class result;

} // namespace alf::ef

namespace alf::ef::__detail {

template<typename R>
struct is_result : public std::false_type { };

template<typename T, typename E>
struct is_result<result<T, E>> : public std::true_type { };

} // namespace alf::ef::__detail

#endif // ALEF_LIB_ERR_FUSION_DETAIL_UTILITY_H
