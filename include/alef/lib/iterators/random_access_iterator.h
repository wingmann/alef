/// @file   random_access_iterator.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Random access iterator implementation.
/// @date   2022-10-13
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_ITERATORS_RANDOM_ACCESS_ITERATOR_H
#define ALEF_CORE_ITERATORS_RANDOM_ACCESS_ITERATOR_H

#include "alef/core.h"

#include <iterator>

namespace alf::iterators {

template<typename T>
class random_access_iterator {
public:
    // Aliases.
    using value_type        = T;
    using reference         = value_type&;
    using pointer           = value_type*;
    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = alf::ptrdiff;
    using iterator_concept  = std::contiguous_iterator_tag;

private:
    pointer iterator_;

public:
    constexpr random_access_iterator(T* iter = nullptr) : iterator_{iter}
    {
    }

    // Increment/decrement operators ---------------------------------------------------------------

    constexpr random_access_iterator& operator++() noexcept
    {
        ++iterator_;
        return *this;
    }

    constexpr random_access_iterator operator++(int) noexcept
    {
        random_access_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    constexpr random_access_iterator& operator--() noexcept
    {
        --iterator_;
        return *this;
    }

    constexpr random_access_iterator operator--(int) noexcept
    {
        random_access_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    // Additional assignment operators -------------------------------------------------------------

    constexpr random_access_iterator& operator+=(const difference_type other) noexcept
    {
        iterator_ += other;
        return *this;
    }

    constexpr random_access_iterator& operator-=(const difference_type other) noexcept
    {
        iterator_ -= other;
        return *this;
    }

    // Operators -----------------------------------------------------------------------------------

    constexpr reference operator*() const noexcept
    {
        return *iterator_;
    }

    constexpr pointer operator->() const noexcept
    {
        return iterator_;
    }

    friend constexpr random_access_iterator operator+(
        difference_type first,
        const random_access_iterator& other) noexcept
    {
        return other.iterator_ + first;
    }

    friend constexpr random_access_iterator operator+(
        const random_access_iterator& first,
        difference_type other) noexcept
    {
        return first.iterator_ + other;
    }

    friend constexpr random_access_iterator operator-(
        const random_access_iterator& first,
        const difference_type other) noexcept
    {
        return first.iterator_ - other;
    }

    constexpr difference_type operator-(const random_access_iterator& other) const noexcept
    {
        return std::distance(iterator_, other.iterator_);
    }

    // Access operators ----------------------------------------------------------------------------

    constexpr reference operator[](std::size_t index) const
    {
        return iterator_[index];
    }

    // Comparison operators ------------------------------------------------------------------------

    constexpr auto operator<=>(const random_access_iterator&) const = default;

    constexpr friend bool operator==(
        const random_access_iterator& first,
        const random_access_iterator& second)
    {
        return first.iterator_ == second.iterator_;
    }
};

} // namespace alef::iterators

#endif // ALEF_CORE_ITERATORS_RANDOM_ACCESS_ITERATOR_H
