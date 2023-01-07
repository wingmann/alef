#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OR_IMPL_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OR_IMPL_H

#include "alef/lib/concepts/general.h"

namespace alf::ef::__detail::or_ns::impl {

template<typename Func>
struct else_type;

template<typename Ret, typename... Args>
struct else_type<Ret(*)(Args...)> : public else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_type<Ret(Class::*)(Args...)> : public else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_type<Ret(Class::*)(Args...) const> : public else_type<Ret (Args...)> { };

template<typename T, typename F, typename Arg>
struct else_type<result<T, F>(Arg)> {
    template<typename E, typename Func>
    requires alf::concepts::same_as<E, Arg> || alf::concepts::convertible_to<E, Arg>
    static result<T, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return res;
        }
        return ok_type<T>(result.storage().template get<T>());
    }

    template<typename E, typename Func>
    requires alf::concepts::same_as<E, Arg> || alf::concepts::convertible_to<E, Arg>
    static result<void, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return res;
        }
        return ok_type<void>();
    }
};

template<alf::concepts::same_as<void> T, typename F>
struct else_type<result<T, F> (void)> {
    template<typename E, typename Func>
    static result<T, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func();
            return res;
        }
        return ok_type<T>(result.storage().template get<T>());
    }

    template<typename E, typename Func>
    static result<void, F> or_else(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func();
            return res;
        }
        return ok_type<void>();
    }
};

} // namespace alf::ef::__detail::or_ns::impl

#endif // ALEF_LIB_ERR_FUSION_DETAIL_OR_IMPL_H
