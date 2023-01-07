#ifndef ALEF_LIB_ERR_FUSION_DETAIL_GENERAL_H
#define ALEF_LIB_ERR_FUSION_DETAIL_GENERAL_H

#include "alef/lib/err_fusion/__detail/and.h"
#include "alef/lib/err_fusion/__detail/constructor.h"
#include "alef/lib/err_fusion/__detail/err.h"
#include "alef/lib/err_fusion/__detail/ok.h"
#include "alef/lib/err_fusion/__detail/or.h"
#include "alef/lib/err_fusion/__detail/other.h"
#include "alef/lib/err_fusion/__detail/storage.h"

namespace alf::ef {

template<typename T, typename E>
class result;

} // namespace alf::ef

namespace alf::ef::__detail::impl {

template<typename Func>
struct result_of;

template<typename Ret, typename Class, typename... Args>
struct result_of<Ret (Class::*)(Args...)> : public result_of<Ret (Args...)> { };

template<typename Ret, typename... Args>
struct result_of<Ret (Args...)> {
    using type = Ret;
};

} // namespace alf::ef::__detail::impl

namespace alf::ef::__detail {

template<typename ...>
struct void_t {
    using type = void;
};

template<typename Func>
struct result_of : public impl::result_of<decltype(&Func::operator())> { };

template<typename Ret, typename Class, typename... Args>
struct result_of<Ret(Class::*) (Args...) const> {
    using type = Ret;
};

template<typename Ret, typename... Args>
struct result_of<Ret(*)(Args...)> {
    using type = Ret;
};

template<typename R>
struct result_ok_type {
    using type = typename std::decay<R>::type;
};

template<typename T, typename E>
struct result_ok_type<result<T, E>> {
    using type = T;
};

template<typename R>
struct result_err_type {
    using type = R;
};

template<typename T, typename E>
struct result_err_type<result<T, E>> {
    using type = typename std::remove_reference<E>::type;
};

template<
    typename T,
    typename E,
    typename Func,
    typename Ret = result<
        typename __detail::result_ok_type<typename __detail::result_of<Func>::type>::type, E>>
Ret map(const result<T, E>& result, Func func)
{
    return ok::map<Func>::map(result, func);
}

template<
    typename T,
    typename E,
    typename Func,
    typename Ret = result<
        T,
        typename __detail::result_err_type<typename __detail::result_of<Func>::type>::type>>
Ret map_error(const result<T, E>& result, Func func)
{
    return err::map<Func>::map(result, func);
}

template<typename T, typename E, typename Func>
result<T, E> then(const result<T, E>& result, Func func)
{
    return and_ns::then<Func>::then(result, func);
}

template<typename T, typename E, typename Func>
result<T, E> otherwise(const result<T, E>& result, Func func)
{
    return other::wise<Func>::otherwise(result, func);
}

template<
    typename T,
    typename E,
    typename Func,
    typename Ret = result<
        T,
        typename __detail::result_err_type<typename __detail::result_of<Func>::type>::type>>
Ret or_else_t(const result<T, E>& result, Func func)
{
    return or_ns::else_t<Func>::or_else(result, func);
}

} // namespace alf::ef::__detail

#endif // ALEF_LIB_ERR_FUSION_DETAIL_GENERAL_H
