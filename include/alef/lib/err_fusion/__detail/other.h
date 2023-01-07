#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OTHER_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OTHER_H

namespace alf::ef::__detail::other::impl {

template<typename Func>
struct wise_type;

template<typename Ret, typename... Args>
struct wise_type<Ret(*)(Args...)> : public wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise_type<Ret(Class::*)(Args...)> : public wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise_type<Ret(Class::*)(Args...) const> : public wise_type<Ret (Args...)> { };

template<std::same_as<void> Ret, typename Arg>
struct wise_type<Ret(Arg)> {
    template<typename T, typename E, typename Func>
    requires std::same_as<E, Arg> || std::convertible_to<E, Arg>
    static result<T, E> otherwise(const result<T, E>& result, Func func)
    {
        if (result.is_err())
            func(result.storage().template get<E>());

        return result;
    }
};

} // namespace alf::ef::__detail::other::impl

namespace alf::ef::__detail::other {

template<typename Func>
struct wise : public impl::wise_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct wise<Ret(*)(Args...)> : public impl::wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise<Ret(Class::*)(Args...)> : public impl::wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise<Ret(Class::*)(Args...) const> : public impl::wise_type<Ret (Args...)> { };

} // namespace alf::ef::__detail::other

#endif // ALEF_LIB_ERR_FUSION_DETAIL_OTHER_H
