#ifndef ALEF_CORE_IO_FILE_H
#define ALEF_CORE_IO_FILE_H

#include "alef/core/detail/streams.h"

namespace alef::io {

using input_file   = alef::stream::input_file;
using output_file  = alef::stream::output_file;
using file         = alef::stream::file;
using file_buffer  = alef::stream::file_buffer;

using winput_file  = alef::stream::winput_file;
using woutput_file = alef::stream::woutput_file;
using wfile        = alef::stream::wfile;
using wfile_buffer = alef::stream::wfile_buffer;

} // namespace alef::io

#endif // ALEF_CORE_IO_FILE_H
