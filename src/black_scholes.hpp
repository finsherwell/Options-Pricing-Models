#pragma once

#include <cmath>
#include <algorithm>

#include "utils.cpp"

namespace opm {

// Closed-form Black-Scholes European (no dividends)
/*
    S - Asset Price
    K - Strike Price
    T - Time to Expiry
    sigma - Volatility (annual)
    r - Risk-Free Rate (annual)
*/

// Call Price
inline double black_scholes_call(double S, double K, double T, double sigma, double r) {
    if (T <= 0.0) return std::max(S - K, 0.0);
    double sqrtT = std::sqrt(T);
    double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrtT);
    double d2 = d1 - sigma * sqrtT;
    return S * opm::utils::norm_cdf(d1) - K * std::exp(-r * T) * opm::utils::norm_cdf(d2);
}

// Put Price
inline double black_scholes_put(double S, double K, double T, double sigma, double r) {
    if (T <= 0.0) return std::max(K - S, 0.0);
    double call = black_scholes_call(S, K, T, sigma, r);
    return call - S + K * std::exp(-r * T);
}

} // namespace opm