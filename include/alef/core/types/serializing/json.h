#ifndef ALEF_CORE_TYPES_SERIALIZING_JSON_H
#define ALEF_CORE_TYPES_SERIALIZING_JSON_H

namespace alf::types::serializing {

enum class json_class {
    null,
    object,
    array,
    string,
    floating,
    integral,
    boolean
};

} // namespace alf::types::serializing

#endif // ALEF_CORE_TYPES_SERIALIZING_JSON_H
