#ifndef ALEF_CORE_IO_TYPES_H
#define ALEF_CORE_IO_TYPES_H

#include "alef/core/detail/streams.h"

#include <istream>
#include <ostream>
#include <fstream>

namespace alef::io {

using input = alef::stream::input_stream;
using print = alef::stream::output_stream;
using error = alef::stream::output_stream;
using log   = alef::stream::output_stream;

using winput = alef::stream::winput_stream;
using wprint = alef::stream::woutput_stream;
using werror = alef::stream::woutput_stream;
using wlog   = alef::stream::woutput_stream;

} // alef::io

#endif // ALEF_CORE_IO_TYPES_H
