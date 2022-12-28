#ifndef ALEF_CORE_IO_FILE_H
#define ALEF_CORE_IO_FILE_H

#include "alef/core/io/__detail.h"

namespace alf::io {

using input_file   = alf::io::__detail::input_file;
using winput_file  = alf::io::__detail::winput_file;

using output_file  = alf::io::__detail::output_file;
using woutput_file = alf::io::__detail::woutput_file;

using file         = alf::io::__detail::file;
using wfile        = alf::io::__detail::wfile;

using file_buffer  = alf::io::__detail::file_buffer;
using wfile_buffer = alf::io::__detail::wfile_buffer;

} // namespace alef::io

#endif // ALEF_CORE_IO_FILE_H
