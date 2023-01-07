#ifndef ALEF_LIB_ERR_FUSION_OK_TYPE_H
#define ALEF_LIB_ERR_FUSION_OK_TYPE_H

#include <utility>

namespace alf::ef {

template<typename T>
struct ok_type {
    T value;

public:
    ok_type(const T& value) : value{value}
    {
    }

    ok_type(T&& value) : value{std::move(value)}
    {
    }
};

template<>
struct ok_type<void> { };

template<typename T, typename CleanT = typename std::decay<T>::type>
ok_type<CleanT> ok(T&& value)
{
    return ok_type<CleanT>(std::forward<T>(value));
}

inline ok_type<void> ok()
{
    return {};
}

} // namespace alf::ef

#endif // ALEF_LIB_ERR_FUSION_OK_TYPE_H
