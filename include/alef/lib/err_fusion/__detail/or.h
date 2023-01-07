#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OR_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OR_H

#include "alef/lib/err_fusion/__detail/or_impl.h"

namespace alf::ef::__detail::or_ns {

template<typename Func>
struct else_t : public impl::else_type<decltype(&Func::operator())> { };

template<typename Ret, typename... Args>
struct else_t<Ret(*)(Args...)> : public impl::else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_t<Ret(Class::*)(Args...)> : public impl::else_type<Ret (Args...)> { };

template<typename Ret, typename Class, typename... Args>
struct else_t<Ret(Class::*)(Args...) const> : public impl::else_type<Ret (Args...)> { };

} // namespace alf::ef::__detail::or_ns

#endif // ALEF_LIB_ERR_FUSION_DETAIL_OR_H
