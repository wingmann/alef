#ifndef ALEF_CORE_IO_STDIN_H
#define ALEF_CORE_IO_STDIN_H

#include "alef/core/io/__detail.h"

namespace alf {

class io_stdin {
public:
    alf::core::io::__detail::input_stream&    read    = std::cin;
    alf::core::io::__detail::wc_input_stream& wc_read = std::wcin;
};

} // namespace alf

#endif // ALEF_CORE_IO_STDIN_H
