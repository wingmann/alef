#ifndef ALEF_CORE_IO_FILE_H
#define ALEF_CORE_IO_FILE_H

#include "alef/core/io/__detail.h"

namespace alf::io {

using input_file     = alf::core::io::__detail::input_file;
using wc_input_file  = alf::core::io::__detail::wc_input_file;

using output_file    = alf::core::io::__detail::output_file;
using wc_output_file = alf::core::io::__detail::wc_output_file;

using file           = alf::core::io::__detail::file;
using wc_file        = alf::core::io::__detail::wc_file;

using file_buffer    = alf::core::io::__detail::file_buffer;
using wc_file_buffer = alf::core::io::__detail::wc_file_buffer;

} // namespace alf::io

#endif // ALEF_CORE_IO_FILE_H
