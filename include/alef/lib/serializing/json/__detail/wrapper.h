#ifndef ALEF_CORE_SERIALIZING_JSON_WRAPPER_H
#define ALEF_CORE_SERIALIZING_JSON_WRAPPER_H

#include <utility>

namespace alf::serializing::__detail::json {

template<typename Container>
class json_wrapper {
private:
    Container* object_;

public:
    explicit json_wrapper(Container* value) : object_{value}
    {
    }

    explicit json_wrapper(std::nullptr_t) : object_{nullptr}
    {
    }

    typename Container::iterator begin()
    {
        return object_ ? object_->begin() : typename Container::iterator{};
    }

    [[nodiscard]]
    typename Container::const_iterator begin() const
    {
        return object_ ? object_->begin() : typename Container::iterator{};
    }

    typename Container::iterator end()
    {
        return object_ ? object_->end() : typename Container::iterator{};
    }

    [[nodiscard]]
    typename Container::const_iterator end() const
    {
        return object_ ? object_->end() : typename Container::iterator{};
    }
};

} // namespace alf::serializing::__detail::json

#endif // ALEF_CORE_SERIALIZING_JSON_WRAPPER_H
