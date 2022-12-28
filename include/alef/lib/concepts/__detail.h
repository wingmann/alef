#ifndef WINGMANN_ALEF_CORE_CONCEPTS_DETAIL_CONCEPTS_H
#define WINGMANN_ALEF_CORE_CONCEPTS_DETAIL_CONCEPTS_H

#include <concepts>

namespace alf::concepts::__detail {

template<typename T, typename... Types>
constexpr auto is_any_of_v = std::disjunction_v<std::is_same<T, Types>...>;

template<typename T>
constexpr auto is_integral_v = is_any_of_v<
    std::remove_cv_t<T>,
    signed char,
    unsigned char,
    signed short int,
    unsigned short int,
    signed int,
    unsigned int,
    signed long int,
    unsigned long int,
    signed long long int,
    unsigned long long int>;

template<typename T>
constexpr auto is_floating_point_v = is_any_of_v<
    std::remove_cv_t<T>,
    float,
    double,
    long double>;

template<typename T>
constexpr auto is_character_v = is_any_of_v<
    std::remove_cv_t<T>,
    char,
    signed char,
    unsigned char,
    wchar_t,
    char8_t,
    char16_t,
    char32_t>;

template<typename T, typename U>
concept same_impl = std::is_same_v<T, U>;

} // namespace alf::concepts::__detail

#endif // WINGMANN_ALEF_CORE_CONCEPTS_DETAIL_CONCEPTS_H
