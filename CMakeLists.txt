# pybind11 module
find_package(pybind11 REQUIRED)


pybind11_add_module(opm
src/bindings.cpp
)


target_include_directories(opm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)