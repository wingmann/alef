/// @file   utility.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Fibonacci functions.
/// @date   2022-10-07
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_MATH_UTILITY_H
#define ALEF_CORE_MATH_UTILITY_H

#include "alef/lib/concepts/numeric.h"

namespace alf::math {

// Fibonacci ---------------------------------------------------------------------------------------

/// @brief Recursively computes fibonacci number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Fibonacci number.
///
/// @see https://en.wikipedia.org/wiki/Fibonacci_number
///
template<alf::concepts::numeric::integral T>
T fibonacci(T value)
{
    return (value <= 1) ? value : fibonacci(value - 1) + fibonacci(value - 2);
}

/// @brief Computes fibonacci number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Fibonacci number.
///
/// @see https://en.wikipedia.org/wiki/Fibonacci_number
///
template<alf::concepts::numeric::integral T>
T fibonacci_loop(T value)
{
    T first{};
    T second{1};
    T next;

    for (T i = 3; i <= value + 1; ++i) {
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}

// Factorial ---------------------------------------------------------------------------------------

/// @brief Recursively computes factorial of number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Factorial of value.
///
/// @see https://en.wikipedia.org/wiki/Factorial
///
template<alf::concepts::numeric::integral T>
T factorial(T value)
{
    return (value <= 0) ? 1 : value * factorial(value - 1);
}

/// @brief Computes factorial of number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Factorial of value.
///
/// @see https://en.wikipedia.org/wiki/Factorial
///
template<alf::concepts::numeric::integral T>
T factorial_loop(T value)
{
    T result{1};

    for (int i = value; i >= 1; --i)
        result *= i;

    return result;
}

// Other -------------------------------------------------------------------------------------------



} // namespace alf::math

#endif // ALEF_CORE_MATH_UTILITY_H
