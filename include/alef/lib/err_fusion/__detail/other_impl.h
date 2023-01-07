#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OTHER_IMPL_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OTHER_IMPL_H

#include "alef/lib/concepts/general.h"

namespace alf::ef {

template<typename T, typename E>
class result;

} // namespace alf::ef

namespace alf::ef::__detail::other::impl {

template<typename Func>
struct wise_type;

template<typename Ret, typename... Args>
struct wise_type<Ret(*)(Args...)> : public wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise_type<Ret(Class::*)(Args...)> : public wise_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct wise_type<Ret(Class::*)(Args...) const> : public wise_type<Ret (Args...)> { };

template<alf::concepts::same_as<void> Ret, typename Arg>
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

#endif // ALEF_LIB_ERR_FUSION_DETAIL_OTHER_IMPL_H
