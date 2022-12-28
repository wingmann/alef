#ifndef ALEF_CORE_IO_OUTPUT_H
#define ALEF_CORE_IO_OUTPUT_H

#include "alef/core/io/__detail.h"

namespace alf::io {

using print   = alf::io::__detail::output_stream;
using wprint  = alf::io::__detail::woutput_stream;

using eprint  = alf::io::__detail::output_stream;
using weprint = alf::io::__detail::woutput_stream;

using log     = alf::io::__detail::output_stream;
using wlog    = alf::io::__detail::woutput_stream;

} // namespace alf::io

#endif // ALEF_CORE_IO_OUTPUT_H
