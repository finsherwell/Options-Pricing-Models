#pragma once

#include <cmath>

namespace opm {
namespace utils {

    inline double norm_cdf(double x) {
        return 0.5 * std::erfc(-x * std::sqrt(0.5));
    }

} // namespace utils
} // namespace opm