#include <cassert>
#include <cmath>
#include <iostream>

#include "src/black_scholes.hpp"

int main() {
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double sigma = 0.2;
    double r = 0.05;

    // Expected results (from known Black-Scholes values)
    double expected_call = 10.4506;
    double expected_put  = 5.5735;

    double call = opm::black_scholes_call(S, K, T, sigma, r);
    double put = opm::black_scholes_put(S, K, T, sigma, r);

    assert(std::fabs(call - expected_call) < 1e-3);
    assert(std::fabs(put - expected_put) < 1e-3);

    std::cout << "All tests passed!\n";
    return 0;
}