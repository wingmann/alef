#ifndef ALEF_LIB_ERR_FUSION_DETAIL_AND_H
#define ALEF_LIB_ERR_FUSION_DETAIL_AND_H

#include "alef/lib/concepts/general.h"

namespace alf::ef {

template<typename T, typename E>
class result;

} // namespace alf::ef

namespace alf::ef::__detail::and_ns::impl {

template<typename Func>
struct then_type;

template<typename Ret, typename... Args>
struct then_type<Ret(*)(Args...)> : public then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then_type<Ret(Class::*)(Args...)> : public then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then_type<Ret(Class::*)(Args...) const> : public then_type<Ret (Args...)> { };

template<std::same_as<void> Ret, typename Arg>
struct then_type<Ret(Arg)> {
    template<typename T, typename E, typename Func>
    static result<T, E> then(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            func(result.storage().template get<T>());
        }
        return result;
    }
};

template<std::same_as<void> Ret>
struct then_type<Ret (void)> {
    template<std::same_as<void> T, typename E, typename Func>
    static result<T, E> then(const result<T, E>& result, Func func)
    {
        if (result.is_ok())
            func();

        return result;
    }
};

} // namespace alf::ef::__detail::and_ns::impl

namespace alf::ef::__detail::and_ns {

template<typename Func>
struct then : public impl::then_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct then<Ret(*)(Args...)> : public impl::then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then<Ret(Class::*)(Args...)> : public impl::then_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct then<Ret(Class::*)(Args...) const> : public impl::then_type<Ret (Args...)> { };

} // namespace alf::ef::__detail::and_ns

#endif // ALEF_LIB_ERR_FUSION_DETAIL_AND_H
