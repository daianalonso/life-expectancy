#include <iostream>
#include "linear_regression.h"

#include <pybind11/embed.h>

namespace py = pybind11;

int main(int argc, char** argv){

  py::scoped_interpreter guard{};

  py::print("Hola pybind!");

  return 0;
}
