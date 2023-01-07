#ifndef ALEF_CORE_IO_STREAMS_H
#define ALEF_CORE_IO_STREAMS_H

#include "alef/core/io/__detail.h"

namespace alf::io {

using input_stream     = alf::core::io::__detail::input_stream;
using output_stream    = alf::core::io::__detail::output_stream;
using io_stream        = alf::core::io::__detail::io_stream;

using wc_input_stream  = alf::core::io::__detail::wc_input_stream;
using wc_output_stream = alf::core::io::__detail::wc_output_stream;
using wc_io_stream     = alf::core::io::__detail::wc_io_stream;

} // namespace alf::io

#endif // ALEF_CORE_IO_STREAMS_H
