#ifndef ALEF_CORE_IO_INPUT_H
#define ALEF_CORE_IO_INPUT_H

#include "alef/core/io/__detail.h"

namespace alf {

alf::io::__detail::input_stream& input = std::cin;
alf::io::__detail::winput_stream& winput = std::wcin;

} // namespace alf

#endif // ALEF_CORE_IO_INPUT_H
