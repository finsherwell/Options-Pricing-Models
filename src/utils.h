#pragma once
#define _USE_MATH_DEFINES

#include <cmath>

namespace opm {
    inline double norm_cdf(double x) {
        return 0.5 * erfc(-x * M_SQRT1_2);
    }
}