#ifndef WINGMANN_ALEF_CORE_CONSTANTS_DETAIL_H
#define WINGMANN_ALEF_CORE_CONSTANTS_DETAIL_H

#include "alef/core/types/general/type_literals.h"

namespace alf::constants::__detail {

// Min ---------------------------------------------------------------------------------------------
const alf::i8   i8_min  {-127_i8 - 1_i8};
const alf::ui8  ui8_min {0_ui8};

const alf::i16  i16_min {-32'767_i16 - 1_i16};
const alf::ui16 ui16_min{0_ui16};

const alf::i32  i32_min {-2'147'483'647_i32 - 1_i32};
const alf::ui32 ui32_min{0_ui32};

const alf::i64  i64_min {-9'223'372'036'854'775'807_i64 - 1_i64};
const alf::ui64 ui64_min{0_ui64};

#ifdef _WIN64 // todo
const isize isize_min   {i64_min};
const usize usize_min   {ui64_min};
#else
const isize isize_min   {i32_min};
const usize usize_min   {ui32_min};
#endif

// Max ---------------------------------------------------------------------------------------------
const alf::i8   i8_max  {127_i8};
const alf::ui8  ui8_max {0xff_ui8};

const alf::i16  i16_max {32'767_i16};
const alf::ui16 ui16_max{0xffff_ui16};

const alf::i32  i32_max {2'147'483'647_i32};
const alf::ui32 ui32_max{0xffff'ffff_ui32};

const alf::i64  i64_max {9'223'372'036'854'775'807_i64};
const alf::ui64 ui64_max{0xffff'ffff'ffff'ffff_ui64};

#ifdef _WIN64 // todo
const isize isize_max   {i64_max};
const usize usize_max   {ui64_max};
#else
const isize isize_max   {i32_max};
const usize usize_max   {ui32_max};
#endif

} // namespace alf::constants::integral

#endif // WINGMANN_ALEF_CORE_CONSTANTS_DETAIL_H
