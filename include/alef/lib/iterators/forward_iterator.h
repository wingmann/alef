/// @file   forward_iterator.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Forward iterator implementation.
/// @date   2022-10-28
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef ALEF_CORE_ITERATORS_FORWARD_ITERATOR_H
#define ALEF_CORE_ITERATORS_FORWARD_ITERATOR_H

#include "alef/alef.h"

#include <iterator>

namespace alf::iterators {

template<typename T, typename Node>
class forward_iterator {
public:
    using value_type        = T;
    using reference         = T&;
    using pointer           = value_type*;
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = alf::ptrdiff;
    using node_type         = Node;
    using node_pointer      = node_type*;

private:
    node_pointer iterator_;

public:
    constexpr forward_iterator(node_pointer iter = nullptr) : iterator_{iter}
    {
    }

    // Increment operators -------------------------------------------------------------------------

    constexpr forward_iterator& operator++() noexcept
    {
        iterator_ = iterator_->next;
        return *this;
    }

    constexpr forward_iterator operator++(int) noexcept
    {
        forward_iterator temp{*this};
        iterator_ = iterator_->next;
        return temp;
    }

    // Access --------------------------------------------------------------------------------------

    constexpr node_pointer get_node_address() const noexcept
    {
        return iterator_;
    }

    constexpr node_pointer get_node_next_address() const noexcept
    {
        return iterator_->next;
    }

    // Operators -----------------------------------------------------------------------------------

    constexpr reference operator*() const noexcept
    {
        return iterator_->data;
    }

    constexpr pointer operator->() const noexcept
    {
        return iterator_;
    }

    // Comparison operators ------------------------------------------------------------------------

    constexpr friend bool operator==(
        const forward_iterator& first,
        const forward_iterator& second) noexcept
    {
        return (first.iterator_ == second.iterator_);
    }

    constexpr friend bool operator!=(
        const forward_iterator& first,
        const forward_iterator& second) noexcept
    {
        return first.iterator_ != second.iterator_;
    }
};

} // namespace alef::iterators

#endif // ALEF_CORE_ITERATORS_FORWARD_ITERATOR_H
