#pragma once

#include <vector>
#include <cmath>

namespace opm {

// Cox-Ross-Rubinstein Binomial Model European
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
    if (steps <= 0) return std::max(S - K, 0.0);
    double dt = T / steps;
    double u = std::exp(sigma * std::sqrt(dt));
    double d = 1.0 / u;
    double disc = std::exp(-r * dt);
    double p = (std::exp(r * dt) - d) / (u - d); // risk-neutral prob

    // build terminal payoffs
    std::vector<double> prices(steps + 1);
    for (int i = 0; i <= steps; ++i) {
        double ST = S * std::pow(u, steps - i) * std::pow(d, i);
        prices[i] = std::max(ST - K, 0.0);
    }

    // step back
    for (int step = steps - 1; step >= 0; --step) {
        for (int i = 0; i <= step; ++i) {
            prices[i] = disc * (p * prices[i] + (1.0 - p) * prices[i + 1]);
        }
    }

    return prices[0];
}

// Put Price
inline double binomial_crr_put() {

}

} // namespace opm