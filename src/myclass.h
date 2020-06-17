#include <pybind11/pybind11.h>

#include <string>
#include <vector>

namespace py = pybind11;

namespace psi {
class Options;
}

namespace miniforte {

class MyClass {
public:

  void use_psi4_options(psi::Options &options);

private:
  pybind11::dict dict_;
  std::string group_ = "";
};
} // namespace miniforte
