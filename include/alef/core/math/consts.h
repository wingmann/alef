#ifndef ALEF_CORE_MATH_CONSTS_H
#define ALEF_CORE_MATH_CONSTS_H

#include "alef/alef.h"

#include <numbers>

namespace alf::math::consts {

// E
constexpr auto e_f32  = std::numbers::e_v<alf::f32>;
constexpr auto e_f64  = std::numbers::e_v<alf::f64>;
constexpr auto e_f128 = std::numbers::e_v<alf::f128>;

// log2(E)
constexpr auto log2e_f32  = std::numbers::log2e_v<alf::f32>;
constexpr auto log2e_f64  = std::numbers::log2e_v<alf::f64>;
constexpr auto log2e_f128 = std::numbers::log2e_v<alf::f128>;

// log10(E)
constexpr auto log10e_f32  = std::numbers::log10e_v<alf::f32>;
constexpr auto log10e_f64  = std::numbers::log10e_v<alf::f64>;
constexpr auto log10e_f128 = std::numbers::log10e_v<alf::f128>;

// PI
constexpr auto pi_f32  = std::numbers::pi_v<alf::f32>;
constexpr auto pi_f64  = std::numbers::pi_v<alf::f64>;
constexpr auto pi_f128 = std::numbers::pi_v<alf::f128>;

// 1/PI
constexpr auto inv_pi_f32  = std::numbers::inv_pi_v<alf::f32>;
constexpr auto inv_pi_f64  = std::numbers::inv_pi_v<alf::f64>;
constexpr auto inv_pi_f128 = std::numbers::inv_pi_v<alf::f128>;

// 1/sqrt(PI)
constexpr auto inv_sqrtpi_f32  = std::numbers::inv_sqrtpi_v<alf::f32>;
constexpr auto inv_sqrtpi_f64  = std::numbers::inv_sqrtpi_v<alf::f64>;
constexpr auto inv_sqrtpi_f128 = std::numbers::inv_sqrtpi_v<alf::f128>;

// ln(2)
constexpr auto ln2_f32  = std::numbers::ln2_v<alf::f32>;
constexpr auto ln2_f64  = std::numbers::ln2_v<alf::f64>;
constexpr auto ln2_f128 = std::numbers::ln2_v<alf::f128>;

// ln(10)
constexpr auto ln10_f32  = std::numbers::ln10_v<alf::f32>;
constexpr auto ln10_f64  = std::numbers::ln10_v<alf::f64>;
constexpr auto ln10_f128 = std::numbers::ln10_v<alf::f128>;

// sqrt(2)
constexpr auto sqrt2_f32  = std::numbers::sqrt2_v<alf::f32>;
constexpr auto sqrt2_f64  = std::numbers::sqrt2_v<alf::f64>;
constexpr auto sqrt2_f128 = std::numbers::sqrt2_v<alf::f128>;

// sqrt(3)
constexpr auto sqrt3_f32  = std::numbers::sqrt3_v<alf::f32>;
constexpr auto sqrt3_f64  = std::numbers::sqrt3_v<alf::f64>;
constexpr auto sqrt3_f128 = std::numbers::sqrt3_v<alf::f128>;

// 1/sqrt(3)
constexpr auto inv_sqrt3_f32  = std::numbers::inv_sqrt3_v<alf::f32>;
constexpr auto inv_sqrt3_f64  = std::numbers::inv_sqrt3_v<alf::f64>;
constexpr auto inv_sqrt3_f128 = std::numbers::inv_sqrt3_v<alf::f128>;

// The Euler–Mascheroni constant
constexpr auto egamma_f32  = std::numbers::egamma_v<alf::f32>;
constexpr auto egamma_f64  = std::numbers::egamma_v<alf::f64>;
constexpr auto egamma_f128 = std::numbers::egamma_v<alf::f128>;

// The golden ratio PHI constant
constexpr auto phi_f32  = std::numbers::phi_v<alf::f32>;
constexpr auto phi_f64  = std::numbers::phi_v<alf::f64>;
constexpr auto phi_f128 = std::numbers::phi_v<alf::f128>;

} // namespace alf::math::consts

#endif // ALEF_CORE_MATH_CONSTS_H
