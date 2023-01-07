#ifndef ALEF_LIB_ERR_FUSION_DETAIL_ERR_H
#define ALEF_LIB_ERR_FUSION_DETAIL_ERR_H

#include "alef/lib/err_fusion/__detail/utility.h"

namespace alf::ef {

template<typename T, typename E>
class result;

} // namespace alf::ef

namespace alf::ef::__detail::err::impl {

template<typename T>
struct map_type;

template<typename Ret, typename Class, typename Arg>
struct map_type<Ret(Class::*)(Arg) const> {
    template<typename T, typename E, typename Func>
    requires (!is_result<Ret>::value)
    static result<T, Ret> map(const result<T, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return err_type<Ret>(res);
        }
        return ok_type<T>(result.storage().template get<T>());
    }

    template<typename E, typename Func>
    requires (!is_result<Ret>::value)
    static result<void, Ret> map(const result<void, E>& result, Func func)
    {
        if (result.is_err()) {
            auto res = func(result.storage().template get<E>());
            return err_type<Ret>(res);
        }
        return ok_type<void>();
    }
};

} // namespace alf::ef::__detail::err::impl

namespace alf::ef::__detail::err {

template<typename Func>
struct map : public impl::map_type<decltype(&Func::operator())> { };

} // namespace alf::ef::__detail::err

#endif // ALEF_LIB_ERR_FUSION_DETAIL_ERR_H
