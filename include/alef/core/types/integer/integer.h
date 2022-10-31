#ifndef ALEF_CORE_TYPES_INTEGERS_INTEGER_H
#define ALEF_CORE_TYPES_INTEGERS_INTEGER_H

#include "alef/string.h"
#include "alef/core/detail/type_flags.h"
#include "alef/core/types/integer/basic_integer.h"

#include <cmath>

namespace alef {

template<typename T>
class integer : public basic_integer<T> {
    T value_;

public:
    integer() = default;
    ~integer() override = default;

    integer(T value) : value_{value}
    {
    }

    integer(alef::concepts::numeric::number auto value) : value_{static_cast<T>(value)}
    {
    }

    integer(const integer& other) : value_{static_cast<T>(other.value_)}
    {
    }

    integer(integer&& other) noexcept : value_{static_cast<T>(other.value_)}
    {
        other.value_ = T{};
    }

public:
    integer& operator=(const integer& other)
    {
        value_ = static_cast<T>(other.value_);
        return *this;
    }

    integer& operator=(integer&& other) noexcept
    {
        value_ = static_cast<T>(other.value_);
        other.value_ = T{};
        return *this;
    }

public:
    T get()
    {
        return value_;
    }

    void set(T new_value)
    {
        value_ = new_value;
    }

    type::primitive_type get_type()
    {
        return type::type_id<T>{}();
    }

    std::string to_string()
    {
        return std::to_string(value_);
    }

public:
    template<concepts::numeric::number U>
    integer add(U other)
    {
        return value_ + other;
    }

    template<concepts::numeric::number U>
    integer subtract(U other)
    {
        return value_ - other;
    }

    template<concepts::numeric::number U>
    integer multiply(U other)
    {
        return value_ * other;
    }

    template<concepts::numeric::number U>
    integer divide(U other)
    {
        return value_ / other;
    }

    template<concepts::numeric::number U>
    integer mod(U other)
    {
        return value_ % other;
    }

    template<concepts::numeric::number U>
    integer pow(U other)
    {
        return std::pow(value_, other);
    }
};

} // namespace alef

#endif // ALEF_CORE_TYPES_INTEGERS_INTEGER_H
