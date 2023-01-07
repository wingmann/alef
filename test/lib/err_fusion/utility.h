#ifndef ALEF_TEST_LIB_ERROR_UTILITY_H
#define ALEF_TEST_LIB_ERROR_UTILITY_H

#include "logic_error.h"

alf::ef::result<int, logic_error> convert_to_int(const std::string& value)
{
    try {
        return alf::ef::ok(std::stoi(value));
    }
    catch (std::invalid_argument&) {
        return alf::ef::err(logic_error{logic_error::kind::invalid_argument, "invalid argument"});
    }
    catch (std::out_of_range&) {
        return alf::ef::err(logic_error{logic_error::kind::out_of_range, "out of range"});
    }
}

#endif // ALEF_TEST_LIB_ERROR_UTILITY_H
