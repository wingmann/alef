#ifndef ALEF_CORE_IO_TYPES_H
#define ALEF_CORE_IO_TYPES_H

#include "alef/core.h"

#include <istream>
#include <ostream>

namespace alef::io {

using input = std::basic_istream<char, std::char_traits<char>>;
using print = std::basic_ostream<char, std::char_traits<char>>;
using error = std::basic_ostream<char, std::char_traits<char>>;
using log   = std::basic_ostream<char, std::char_traits<char>>;

using winput = std::basic_istream<wchar, std::char_traits<wchar>>;
using wprint = std::basic_ostream<wchar, std::char_traits<wchar>>;
using werror = std::basic_ostream<wchar, std::char_traits<wchar>>;
using wlog   = std::basic_ostream<wchar, std::char_traits<wchar>>;

} // alef::io

#endif // ALEF_CORE_IO_TYPES_H
