#ifndef ALEF_LIB_ERR_FUSION_DETAIL_OTHER_H
#define ALEF_LIB_ERR_FUSION_DETAIL_OTHER_H

#include "alef/lib/err_fusion/__detail/other_impl.h"

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
