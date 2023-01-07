#ifndef ALEF_TEST_LIB_ERROR_LOGIC_ERROR_H
#define ALEF_TEST_LIB_ERROR_LOGIC_ERROR_H

#include <alef/core/string/string.h>
#include "alef/lib/err_fusion/err_fusion.h"

struct logic_error {
public:
    enum class kind { invalid_argument, out_of_range };

private:
    kind kind_;
    alf::string message_;

public:
    logic_error(kind value, alf::string msg) : kind_{value}, message_{std::move(msg)} { }

public:
    [[nodiscard]]
    kind get() const { return kind_; }

    [[nodiscard]]
    alf::string what() const { return message_; }
};

#endif // ALEF_TEST_LIB_ERROR_LOGIC_ERROR_H
