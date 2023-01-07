#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OK_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OK_H

#include "alef/lib/err_fusion/__detail/utility.h"

#include <functional>

namespace alf::ef {

template<typename T, typename E>
class result;

} // namespace alf::ef

namespace alf::ef::__detail::ok::impl {

template<typename T>
struct map_type;

template<typename Ret, typename Class, typename Arg>
struct map_type<Ret(Class::*)(Arg) const> : public map_type<Ret(Arg)> { };

template<typename Ret, typename Class, typename Arg>
struct map_type<Ret(Class::*)(Arg)> : public map_type<Ret(Arg)> { };

// General implementation.
template<typename Ret, typename Arg>
struct map_type<Ret(Arg)> {
    template<typename T, typename E, typename Func>
    requires (!is_result<Ret>::value) && (std::same_as<T, Arg> || std::convertible_to<T, Arg>)
    static result<Ret, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto res = func(result.storage().template get<T>());
            return ok_type<Ret>(std::move(res));
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for callback returning void.
template<typename Arg>
struct map_type<void(Arg)> {
    template<typename T, typename E, typename Func>
    static result<void, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            func(result.storage().template get<T>());
            return alf::ef::ok_type<void>();
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for a void result.
template<typename Ret>
struct map_type<Ret(void)> {
    template<std::same_as<void> T, typename E, typename Func>
    static result<Ret, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto ret = func();
            return ok_type<Ret>(std::move(ret));
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for callback returning void on a void result.
template<>
struct map_type<void(void)> {
    template<std::same_as<void> T, typename E, typename Func>
    static result<void, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            func();
            return ok_type<void>();
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// General specialization for a callback returning a Result
template<typename U, typename E, typename Arg>
struct map_type<result<U, E>(Arg)> {
    template<typename T, typename Func>
    requires std::same_as<T, Arg> || std::convertible_to<T, Arg>
    static result<U, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto res = func(result.storage().template get<T>());
            return res;
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

// Specialization for a void callback returning a result.
template<typename U, typename E>
struct map_type<result<U, E>(void)> {
    template<std::same_as<void> T, typename Func>
    static result<U, E> map(const result<T, E>& result, Func func)
    {
        if (result.is_ok()) {
            auto res = func();
            return res;
        }
        return err_type<E>(result.storage().template get<E>());
    }
};

} // namespace alf::ef::__detail::ok::impl

namespace alf::ef::__detail::ok {

template<typename Func> struct map : public impl::map_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct map<Ret(*)(Args...)> : public impl::map_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct map<Ret(Class::*)(Args...)> : public impl::map_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct map<Ret(Class::*)(Args...) const> : public impl::map_type<Ret (Args...)> { };

template<typename Ret, typename... Args>
struct map<std::function<Ret(Args...)>> : public impl::map_type<Ret (Args...)> { };

} // namespace alf::ef::__detail::ok

#endif // ALEF_LIB_ERR_FUSION_DETAIL_OK_H
