#include <pybind11/pybind11.h>
#include "psi4/liboptions/liboptions.h"

#include <string>
#include <vector>

namespace py = pybind11;

//namespace psi {
//class Options;
//}

namespace miniforte {

/**
 * @brief The ForteOptions class
 */
class MyClass {
public:

  void use_psi4_options(psi::Options &options);

private:
  pybind11::dict dict_;
  std::string group_ = "";
};
} // namespace miniforte
