#pragma once

#include <vector>

namespace opm {

// Closed-form Black-Scholes European (no dividends)
/*
    S - Asset Price
    K - Strike Price
    T - Time to Expiry
    sigma - Volatility
    r - Risk-Free Rate
    steps - Number of Steps
*/

// Call Price
inline double binomial_crr_call(double S, double K, double T, double sigma, double r, int steps) {

}

// Put Price
inline double binomial_crr_put() {

}

} // namespace opm