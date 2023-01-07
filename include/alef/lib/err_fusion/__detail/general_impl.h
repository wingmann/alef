#ifndef ALEF_LIB_ERR_FUSION_DETAIL_GENERAL_IMPL_H
#define ALEF_LIB_ERR_FUSION_DETAIL_GENERAL_IMPL_H

namespace alf::ef::__detail::impl {

template<typename Func>
struct result_of;

template<typename Ret, typename Class, typename... Args>
struct result_of<Ret (Class::*)(Args...)> : public result_of<Ret (Args...)> { };

template<typename Ret, typename... Args>
struct result_of<Ret (Args...)> {
    using type = Ret;
};

} // namespace alf::ef::__detail::impl

#endif // ALEF_LIB_ERR_FUSION_DETAIL_GENERAL_IMPL_H
