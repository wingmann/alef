/// @file   concepts.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Concept types.
/// @date   2022-10-27
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the GNU GPL v3 License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_CONCEPTS_H
#define ALEF_CORE_CONCEPTS_H

#include <concepts>

namespace alef::concepts {

namespace __detail { // ----------------------------------------------------------------------------

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
concept same_helper = std::is_same_v<T, U>;

} // namespace __detail

// General -----------------------------------------------------------------------------------------

template<typename T, typename U>
concept same_as = __detail::same_helper<T, U> && __detail::same_helper<U, T>;

template<typename Derived, typename Base>
concept derived_from =
    std::is_base_of_v<Base, Derived> &&
    std::is_convertible_v<const volatile Derived*, const volatile Base*>;

template<typename From, typename To>
concept convertible_to = std::is_convertible_v<From, To> && requires {
    static_cast<To>(std::declval<From>());
};

template<typename T, typename U>
concept common_reference_with =
    same_as<std::common_reference_t<T, U>, std::common_reference_t<U, T>> &&
    convertible_to<T, std::common_reference_t<T, U>> &&
    convertible_to<U, std::common_reference_t<T, U>>;

template<typename T, typename U>
concept common_with =
    same_as<std::common_type_t<T, U>, std::common_type_t<U, T>> &&
    requires {
        static_cast<std::common_type_t<T, U>>(std::declval<T>());
        static_cast<std::common_type_t<T, U>>(std::declval<U>());
    } &&
    common_reference_with<
        std::add_lvalue_reference_t<const T>,
        std::add_lvalue_reference_t<const U>> &&
    common_reference_with<
        std::add_lvalue_reference_t<std::common_type_t<T, U>>,
        std::common_reference_t<
            std::add_lvalue_reference_t<const T>,
            std::add_lvalue_reference_t<const U>>>;

template<typename T, typename U>
concept assignable_from =
    std::is_lvalue_reference_v<T> &&
    common_reference_with<const std::remove_reference_t<T>&, const std::remove_reference_t<U>&> &&
    requires(T lhs, U&& rhs) {
        { lhs = std::forward<U>(rhs) } -> same_as<T>;
    };

template<typename T>
concept swappable = requires(T& a, T& b) {
    std::ranges::swap(a, b);
};

template<typename T, typename U>
concept swappable_with =
    common_reference_with<T, U> &&
    requires(T&& t, U&& u) {
        std::ranges::swap(std::forward<T>(t), std::forward<T>(t));
        std::ranges::swap(std::forward<U>(u), std::forward<U>(u));
        std::ranges::swap(std::forward<T>(t), std::forward<U>(u));
        std::ranges::swap(std::forward<U>(u), std::forward<T>(t));
    };

template<typename T>
concept destructible = std::is_nothrow_destructible_v<T>;

template<typename T, typename... Args>
concept constructible_from = destructible<T> && std::is_constructible_v<T, Args...>;

template<typename T>
concept default_initializable =
    constructible_from<T> &&
    requires { T{}; } &&
    requires { ::new (static_cast<void*>(nullptr)) T; };

template<typename T>
concept move_constructible = constructible_from<T, T> && convertible_to<T, T>;

template<typename T>
concept copy_constructible =
    move_constructible<T> &&
    constructible_from<T, T&> && convertible_to<T&, T> &&
    constructible_from<T, const T&> && convertible_to<const T&, T> &&
    constructible_from<T, const T> && convertible_to<const T, T>;

template<typename T>
concept equality_comparable = std::equality_comparable<T>;

template<typename T, typename U>
concept equality_comparable_with = std::equality_comparable_with<T, U>;

template<typename T>
concept totally_ordered = std::totally_ordered<T>;

template<typename T, typename U>
concept totally_ordered_with = std::totally_ordered_with<T, U>;

// template<typename T>
// concept three_way_comparable = ...

// template<typename T, typename U>
// concept three_way_comparable_with = ...

template<typename T>
concept movable =
    std::is_object_v<T> &&
    move_constructible<T> &&
    assignable_from<T&, T> &&
    swappable<T>;

template<typename T>
concept copyable =
    copy_constructible<T> &&
    movable<T> &&
    assignable_from<T&, T&> &&
    assignable_from<T&, const T&> &&
    assignable_from<T&, const T>;

template<typename T>
concept semiregular = copyable<T> && default_initializable<T>;

template<typename T>
concept regular = semiregular<T> && equality_comparable<T>;

template<typename F, typename... Args>
concept invocable = std::invocable<F, Args...>;

template<typename F, typename... Args>
concept regular_invocable = invocable<F, Args...>;

template<typename T, typename... Args>
concept predicate = std::predicate<T, Args...>;

template<typename R, typename T, typename U>
concept relation =
    predicate<R, T, T> &&
    predicate<R, U, U> &&
    predicate<R, T, U> &&
    predicate<R, U, T>;

template<typename R, typename T, typename U>
concept equivalence_relation = relation<R, T, U>;

template<typename R, typename T, typename U>
concept strict_weak_order = relation<R, T, U>;

namespace numeric { // -----------------------------------------------------------------------------

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

} // namespace numeric

namespace chars { // -------------------------------------------------------------------------------

template<typename T>
concept character = __detail::is_character_v<T>;

} // namespace chars

namespace logic { // -------------------------------------------------------------------------------

template<typename T>
concept boolean = same_as<T, bool>;

template<typename T>
concept not_boolean = !boolean<T>;

} // namespace logic

namespace sorting { // -----------------------------------------------------------------------------

template<typename T>
concept totally_ordered_swappable = totally_ordered<T> && swappable<T>;

} // namespace sorting

} // namespace alef::concepts

#endif // ALEF_CORE_CONCEPTS_H
