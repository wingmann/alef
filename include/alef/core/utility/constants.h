#ifndef ALEF_CORE_UTILITY_CONSTANTS_H
#define ALEF_CORE_UTILITY_CONSTANTS_H

#include "alef/core/detail/type_literals.h"

namespace alef::utility {

constexpr auto int8_min()  { return (-127_i8 - 1);                  }
constexpr auto int16_min() { return (-32767_i16 - 1);               }
constexpr auto int32_min() { return (-2147483647_i32 - 1);          }
constexpr auto int64_min() { return (-9223372036854775807_i64 - 1); }

constexpr auto uint8_min()  { return 0_ui8;  }
constexpr auto uint16_min() { return 0_ui16; }
constexpr auto uint32_min() { return 0_ui32; }
constexpr auto uint64_min() { return 0_ui64; }

constexpr auto int8_max()  { return 127_i8;                  }
constexpr auto int16_max() { return 32767_i16;               }
constexpr auto int32_max() { return 2147483647_i32;          }
constexpr auto int64_max() { return 9223372036854775807_i64; }

constexpr auto uint8_max()  { return 0xff_ui8;               }
constexpr auto uint16_max() { return 0xffff_ui16;             }
constexpr auto uint32_max() { return 0xffffffff_ui32;         }
constexpr auto uint64_max() { return 0xffffffffffffffff_ui64; }

#ifdef _WIN64 // todo
constexpr auto ssize_min() { return static_cast<alef::ssize>(int64_min()); }
constexpr auto size_min()  { return static_cast<alef::size>(uint64_min()); }

constexpr auto ssize_max() { return static_cast<alef::ssize>(int64_max()); }
constexpr auto size_max()  { return static_cast<alef::size>(uint64_max()); }
#else
constexpr auto ssize_min() { return static_cast<alef::ssize>(int32_min()); }
constexpr auto size_min()  { return static_cast<alef::size>(uint32_min()); }

constexpr auto ssize_max() { return static_cast<alef::ssize>(int32_max()); }
constexpr auto size_max()  { return static_cast<alef::size>(uint32_max()); }
#endif

} // namespace alef::utility

#endif // ALEF_CORE_UTILITY_CONSTANTS_H
