#ifndef ALEF_CORE_DETAIL_STREAMS_H
#define ALEF_CORE_DETAIL_STREAMS_H

#include "alef/core/detail/types.h"

#include <sstream>

namespace alef::stream {

// Basic -------------------------------------------------------------------------------------------

using ios  = std::basic_ios<char,  std::char_traits<char>>;
using wios = std::basic_ios<wchar, std::char_traits<wchar>>;

// Buffers -----------------------------------------------------------------------------------------

using stream_buffer  = std::basic_streambuf<char,  std::char_traits<char>>;
using wstream_buffer = std::basic_streambuf<wchar, std::char_traits<wchar>>;

using string_buffer  = std::basic_stringbuf<char,  std::char_traits<char>,  std::allocator<char>>;
using wstring_buffer = std::basic_stringbuf<wchar, std::char_traits<wchar>, std::allocator<wchar>>;

using sync_buffer    = std::basic_syncbuf<char>;
using wsync_buffer   = std::basic_syncbuf<wchar>;

using file_buffer    = std::basic_filebuf<char,   std::char_traits<char>>;
using wfile_buffer   = std::basic_filebuf<wchar,  std::char_traits<wchar>>;

// File streams ------------------------------------------------------------------------------------

using input_file   = std::basic_ifstream<char,  std::char_traits<char>>;
using output_file  = std::basic_ofstream<char,  std::char_traits<char>>;
using file         = std::basic_fstream<char,   std::char_traits<char>>;

using winput_file  = std::basic_ifstream<wchar, std::char_traits<wchar>>;
using woutput_file = std::basic_ofstream<wchar, std::char_traits<wchar>>;
using wfile        = std::basic_fstream<wchar,  std::char_traits<wchar>>;

// Stdin/Stdout streams ----------------------------------------------------------------------------

using input_stream   = std::basic_istream<char,   std::char_traits<char>>;
using output_stream  = std::basic_ostream<char,   std::char_traits<char>>;
using io_stream      = std::basic_iostream<char,  std::char_traits<char>>;

using winput_stream  = std::basic_istream<wchar,  std::char_traits<wchar>>;
using woutput_stream = std::basic_ostream<wchar,  std::char_traits<wchar>>;
using wio_stream     = std::basic_iostream<wchar, std::char_traits<wchar>>;

// String streams ----------------------------------------------------------------------------------

using istring_stream  = std::basic_istringstream<char,  std::char_traits<char>, std::allocator<char>>;
using ostring_stream  = std::basic_ostringstream<char,  std::char_traits<char>, std::allocator<char>>;
using string_stream   = std::basic_stringstream<char,   std::char_traits<char>, std::allocator<char>>;

using wistring_stream = std::basic_istringstream<wchar, std::char_traits<wchar>, std::allocator<wchar>>;
using wostring_stream = std::basic_ostringstream<wchar, std::char_traits<wchar>, std::allocator<wchar>>;
using wstring_stream  = std::basic_stringstream<wchar,  std::char_traits<wchar>, std::allocator<wchar>>;

// Sync streams ------------------------------------------------------------------------------------

using osyncstream  = std::basic_osyncstream<char>;
using wosyncstream = std::basic_osyncstream<wchar>;

} // alef::streams

#endif // ALEF_CORE_DETAIL_STREAMS_H
