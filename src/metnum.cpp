#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "linear_regression.h"


namespace py=pybind11;

PYBIND11_MODULE(metnum, m) {
    py::class_<LinearRegression>(m, "LinearRegression")
        .def(py::init<>())
        .def("fit", &LinearRegression::fit)
        .def("predict", &LinearRegression::predict);
}
