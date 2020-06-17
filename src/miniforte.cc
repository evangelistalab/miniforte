#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "myclass.h"

namespace miniforte {

int add(int i, int j) { return i + j; }

PYBIND11_MODULE(miniforte, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  m.def("add", &add, "A function which adds two numbers");

  py::class_<MyClass, std::shared_ptr<MyClass>>(m, "MyClass")
      .def(py::init<>())
      .def("use_psi4_options", &MyClass::use_psi4_options);
}
} // namespace miniforte
