#ifndef ALEF_LIB_ERR_FUSION_ERR_TYPE_H
#define ALEF_LIB_ERR_FUSION_ERR_TYPE_H

#include <utility>

namespace alf::ef {

template<typename E>
struct err_type {
    E value;

public:
    err_type(const E& value) : value(value) { }
    err_type(E&& value) : value(std::move(value)) { }
};

template<typename E, typename CleanE = typename std::decay<E>::type>
err_type<CleanE> err(E&& value)
{
    return err_type<CleanE>(std::forward<E>(value));
}

} // namespace alf::ef

#endif // ALEF_LIB_ERR_FUSION_ERR_TYPE_H
