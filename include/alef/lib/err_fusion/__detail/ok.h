#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OK_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OK_H

#include "alef/lib/err_fusion/__detail/ok_impl.h"

#include <functional>

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
