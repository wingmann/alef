#ifndef ALEF_CORE_IO_DETAIL_STREAMS_H
#define ALEF_CORE_IO_DETAIL_STREAMS_H

#include "alef/core/types/general/basic.h"
#include "alef/core/io/manip.h"

#include <fstream>
#include <sstream>

namespace alf::core::io::__detail {

// Basic -------------------------------------------------------------------------------------------
using ios                     = std::basic_ios<char,  std::char_traits<char>>;
using wc_ios                  = std::basic_ios<wchar, std::char_traits<wchar>>;

// Buffers -----------------------------------------------------------------------------------------
using stream_buffer           = std::basic_streambuf<char,  std::char_traits<char>>;
using wc_stream_buffer        = std::basic_streambuf<wchar, std::char_traits<wchar>>;

using string_buffer           = std::basic_stringbuf<char,  std::char_traits<char>,  std::allocator<char>>;
using wc_string_buffer        = std::basic_stringbuf<wchar, std::char_traits<wchar>, std::allocator<wchar>>;

using sync_buffer             = std::basic_syncbuf<char>;
using wc_sync_buffer          = std::basic_syncbuf<wchar>;

using file_buffer             = std::basic_filebuf<char,   std::char_traits<char>>;
using wc_file_buffer          = std::basic_filebuf<wchar,  std::char_traits<wchar>>;

// File streams ------------------------------------------------------------------------------------
using input_file              = std::basic_ifstream<char,  std::char_traits<char>>;
using output_file             = std::basic_ofstream<char,  std::char_traits<char>>;
using file                    = std::basic_fstream<char,   std::char_traits<char>>;

using wc_input_file           = std::basic_ifstream<wchar, std::char_traits<wchar>>;
using wc_output_file          = std::basic_ofstream<wchar, std::char_traits<wchar>>;
using wc_file                 = std::basic_fstream<wchar,  std::char_traits<wchar>>;

// Stdin/stdout streams ----------------------------------------------------------------------------
using input_stream            = std::basic_istream<char,   std::char_traits<char>>;
using output_stream           = std::basic_ostream<char,   std::char_traits<char>>;
using io_stream               = std::basic_iostream<char,  std::char_traits<char>>;

using wc_input_stream         = std::basic_istream<wchar,  std::char_traits<wchar>>;
using wc_output_stream        = std::basic_ostream<wchar,  std::char_traits<wchar>>;
using wc_io_stream            = std::basic_iostream<wchar, std::char_traits<wchar>>;

// String streams ----------------------------------------------------------------------------------
using input_string_stream     = std::basic_istringstream<char,  std::char_traits<char>, std::allocator<char>>;
using output_string_stream    = std::basic_ostringstream<char,  std::char_traits<char>, std::allocator<char>>;
using string_stream           = std::basic_stringstream<char,   std::char_traits<char>, std::allocator<char>>;

using wc_input_string_stream  = std::basic_istringstream<wchar, std::char_traits<wchar>, std::allocator<wchar>>;
using wc_output_string_stream = std::basic_ostringstream<wchar, std::char_traits<wchar>, std::allocator<wchar>>;
using wc_string_stream        = std::basic_stringstream<wchar,  std::char_traits<wchar>, std::allocator<wchar>>;

// Sync streams ------------------------------------------------------------------------------------
using output_sync_stream      = std::basic_osyncstream<char>;
using wc_output_sync_stream   = std::basic_osyncstream<wchar>;

} // namespace alf::core::io::__detail

#endif // ALEF_CORE_IO_DETAIL_STREAMS_H
