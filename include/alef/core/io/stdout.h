#ifndef ALEF_CORE_IO_STDOUT_H
#define ALEF_CORE_IO_STDOUT_H

#include "alef/core/io/__detail.h"

namespace alf {

class io_stdout {
public:
    alf::core::io::__detail::output_stream&    print        = std::cout;
    alf::core::io::__detail::wc_output_stream& wc_print     = std::wcout;
    alf::core::io::__detail::output_stream&    err_print    = std::cerr;
    alf::core::io::__detail::wc_output_stream& wc_err_print = std::wcerr;
    alf::core::io::__detail::output_stream&    log          = std::clog;
    alf::core::io::__detail::wc_output_stream& wc_log       = std::wclog;
};

} // namespace alf

#endif // ALEF_CORE_IO_STDOUT_H
