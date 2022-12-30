#ifndef ALEF_CORE_STRINGS_STRING_STREAM_H
#define ALEF_CORE_STRINGS_STRING_STREAM_H

#include "alef/core/io/__detail.h"

namespace alf {

using input_string_stream     = alf::core::io::__detail::input_string_stream;
using wc_input_string_stream  = alf::core::io::__detail::wc_input_stream;

using output_string_stream    = alf::core::io::__detail::output_string_stream;
using wc_output_string_stream = alf::core::io::__detail::wc_output_string_stream;

using string_stream           = alf::core::io::__detail::string_stream;
using wc_string_stream        = alf::core::io::__detail::wc_string_stream;

} // namespace alf

#endif // ALEF_CORE_STRINGS_STRING_STREAM_H
