#ifndef ALEF_LIB_SERIALIZING_JSON_DETAIL_TYPES_H
#define ALEF_LIB_SERIALIZING_JSON_DETAIL_TYPES_H

#include "alef/alef.h"
#include "alef/core/string/string.h"
#include "alef/lib/serializing/json/__detail/const_wrapper.h"
#include "alef/lib/serializing/json/__detail/wrapper.h"

#include <deque>
#include <map>

namespace alf::serializing {

class json;

} // namespace alf::serializing

namespace alf::serializing::__detail::json {

using list_type  = std::deque<alf::serializing::json>;
using map_type   = std::map<alf::string, alf::serializing::json>;
using float_type = alf::f64;
using int_type   = alf::i64;

using list_wrapper_type       = json_wrapper<list_type>;
using const_list_wrapper_type = json_const_wrapper<list_type>;
using map_wrapper_type        = json_wrapper<map_type>;
using const_map_wrapper_type  = json_const_wrapper<map_type>;

} // namespace alf::serializing::__detail::json

#endif // ALEF_LIB_SERIALIZING_JSON_DETAIL_TYPES_H
