#ifndef ALEF_CORE_SERIALIZING_JSON_CONST_WRAPPER_H
#define ALEF_CORE_SERIALIZING_JSON_CONST_WRAPPER_H

#include <utility>

namespace alf::serializing::__json_detail {

template<typename Container>
class json_const_wrapper {
private:
    const Container* object_;

public:
    explicit json_const_wrapper(const Container* value) : object_{value} { }
    explicit json_const_wrapper(std::nullptr_t) : object_{nullptr} { }

    [[nodiscard]]
    typename Container::const_iterator begin() const
    {
        return object_ ? object_->begin() : typename Container::const_iterator{};
    }

    [[nodiscard]]
    typename Container::const_iterator end() const
    {
        return object_ ? object_->end() : typename Container::const_iterator{};
    }
};

} // alf::serializing::__json_detail

#endif // ALEF_CORE_SERIALIZING_JSON_CONST_WRAPPER_H
