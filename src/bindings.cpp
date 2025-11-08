#include <pybind11/pybind11.h>
#include <pybind11/complex.h>
#include <pybind11/stl.h>

#include "src/binomial.hpp"
#include "src/black_scholes.hpp"
#include "src/monte_carlo.hpp"

namespace py = pybind11;

PYBIND11_MODULE(opm, m) {
    m.doc() = "Option Pricing Models (C++ -> Python bindings)";

    m.def("black_scholes_call", &opm::black_scholes_call);
    m.def("black_scholes_put", &opm::black_scholes_put);
}