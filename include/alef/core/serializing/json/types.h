#ifndef WINGMANN_ALEF_INCLUDE_ALEF_CORE_SERIALIZING_JSON_TYPES_H
#define WINGMANN_ALEF_INCLUDE_ALEF_CORE_SERIALIZING_JSON_TYPES_H

#include "alef/core/serializing/json/const_wrapper.h"
#include "alef/core/serializing/json/wrapper.h"

#include <deque>
#include <map>
#include <string>

namespace alef::serializing {

class json;

namespace __json_detail {

using list_type  = std::deque<json>;
using map_type   = std::map<std::string, json>;
using float_type = double;
using int_type   = std::int64_t;

using list_wrapper_type       = json_wrapper<list_type>;
using const_list_wrapper_type = json_const_wrapper<list_type>;
using map_wrapper_type        = json_wrapper<map_type>;
using const_map_wrapper_type  = json_const_wrapper<map_type>;

} // namespace __json_detail

} // namespace alef::serializing

#endif //WINGMANN_ALEF_INCLUDE_ALEF_CORE_SERIALIZING_JSON_TYPES_H
