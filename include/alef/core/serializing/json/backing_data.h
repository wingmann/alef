#ifndef WINGMANN_ALEF_INCLUDE_ALEF_CORE_SERIALIZING_JSON_BACKING_DATA_H
#define WINGMANN_ALEF_INCLUDE_ALEF_CORE_SERIALIZING_JSON_BACKING_DATA_H

#include "alef/core/serializing/json/types.h"

namespace alef::serializing::__json_detail {

union backing_data {
    list_type*   json_list;
    map_type*    json_map;
    std::string* json_string;
    float_type   json_float;
    int_type     json_int;
    bool         json_bool;

    backing_data() = default;

    explicit backing_data(float_type value) : json_float{value}
    {
    }

    explicit backing_data(int_type value) : json_int{value}
    {
    }

    explicit backing_data(bool value) : json_bool{value}
    {
    }

    explicit backing_data(std::string value) : json_string{new std::string{std::move(value)}}
    {
    }
};

} // namespace alef::serializing::__json_detail

#endif //WINGMANN_ALEF_INCLUDE_ALEF_CORE_SERIALIZING_JSON_BACKING_DATA_H
