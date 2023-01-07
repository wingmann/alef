#ifndef ALEF_LIB_ERR_FUSION_DETAIL_ERR_H
#define ALEF_LIB_ERR_FUSION_DETAIL_ERR_H

#include "alef/lib/err_fusion/__detail/err_impl.h"

namespace alf::ef::__detail::err {

template<typename Func>
struct map : public impl::map_type<decltype(&Func::operator())> { };

} // namespace alf::ef::__detail::err

#endif // ALEF_LIB_ERR_FUSION_DETAIL_ERR_H
