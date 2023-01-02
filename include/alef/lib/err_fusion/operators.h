#ifndef ALEF_LIB_ERR_FUSION_OPERATORS_H
#define ALEF_LIB_ERR_FUSION_OPERATORS_H

#include "__detail.h"

namespace alf::ef {

template<std::equality_comparable T, std::equality_comparable E>
bool operator==(const result<T, E>& lhs, const result<T, E>& rhs)
{
    if (lhs.is_ok() && rhs.is_ok())
        return lhs.storage().template get<T>() == rhs.storage().template get<T>();

    if (lhs.is_err() && rhs.is_err())
        return lhs.storage().template get<E>() == rhs.storage().template get<E>();
}

template<std::equality_comparable T, typename E>
bool operator==(const result<T, E>& lhs, ok_type<T> ok)
{
    if (!lhs.is_ok())
        return false;
    return lhs.storage().template get<T>() == ok.value;
}

template<typename E>
bool operator==(const result<void, E>& lhs, ok_type<void>)
{
    return lhs.is_ok();
}

template<typename T, std::equality_comparable E>
bool operator==(const result<T, E>& lhs, err_type<E> err)
{
    if (!lhs.is_err())
        return false;
    return lhs.storage().template get<E>() == err.value;
}

} // alf::ef

#endif // ALEF_LIB_ERR_FUSION_OPERATORS_H
