#include "psi4/liboptions/liboptions.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace miniforte {

class MyClass {
public:
  void use_psi4_options(psi::Options &options);
};

} // namespace miniforte
