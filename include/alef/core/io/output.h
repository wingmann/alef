#ifndef ALEF_CORE_IO_OUTPUT_H
#define ALEF_CORE_IO_OUTPUT_H

#include "alef/core/io/__detail.h"

#include <iostream>

namespace alf {

alf::io::__detail::output_stream& print = std::cout;
alf::io::__detail::woutput_stream& wprint = std::wcout;

alf::io::__detail::output_stream& eprint = std::cerr;
alf::io::__detail::woutput_stream& ewprint = std::wcerr;

alf::io::__detail::output_stream& log = std::clog;
alf::io::__detail::woutput_stream& wlog = std::wclog;

} // namespace alf

#endif // ALEF_CORE_IO_OUTPUT_H
