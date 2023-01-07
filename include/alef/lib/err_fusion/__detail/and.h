#ifndef ALEF_LIB_ERR_FUSION_DETAIL_AND_H
#define ALEF_LIB_ERR_FUSION_DETAIL_AND_H

#include "alef/lib/err_fusion/__detail/and_impl.h"

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
