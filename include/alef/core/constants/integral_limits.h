#ifndef ALEF_CORE_CONSTANTS_INTEGRAL_LIMITS_H
#define ALEF_CORE_CONSTANTS_INTEGRAL_LIMITS_H

#include "alef/core/constants/__detail.h"

namespace alf::limits {

// Min ---------------------------------------------------------------------------------------------
constexpr auto i8_min()    { return alf::constants::__detail::i8_min;    }
constexpr auto ui8_min()   { return alf::constants::__detail::ui8_min;   }

constexpr auto i16_min()   { return alf::constants::__detail::ui16_min;  }
constexpr auto ui16_min()  { return alf::constants::__detail::ui16_min;  }

constexpr auto i32_min()   { return alf::constants::__detail::ui32_min;  }
constexpr auto ui32_min()  { return alf::constants::__detail::ui32_min;  }

constexpr auto i64_min()   { return alf::constants::__detail::ui64_min;  }
constexpr auto ui64_min()  { return alf::constants::__detail::ui64_min;  }

constexpr auto isize_min() { return alf::constants::__detail::isize_min; }
constexpr auto usize_min() { return alf::constants::__detail::usize_min; }

// Max ---------------------------------------------------------------------------------------------
constexpr auto i8_max()    { return alf::constants::__detail::i8_max;    }
constexpr auto ui8_max()   { return alf::constants::__detail::ui8_max;   }

constexpr auto i16_max()   { return alf::constants::__detail::ui16_max;  }
constexpr auto ui16_max()  { return alf::constants::__detail::ui16_max;  }

constexpr auto i32_max()   { return alf::constants::__detail::ui32_max;  }
constexpr auto ui32_max()  { return alf::constants::__detail::ui32_max;  }

constexpr auto i64_max()   { return alf::constants::__detail::ui64_max;  }
constexpr auto ui64_max()  { return alf::constants::__detail::ui64_max;  }

constexpr auto isize_max() { return alf::constants::__detail::isize_max; }
constexpr auto usize_max() { return alf::constants::__detail::usize_max; }

} // namespace alef::limits

#endif // ALEF_CORE_CONSTANTS_INTEGRAL_LIMITS_H
