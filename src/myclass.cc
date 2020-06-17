#include "myclass.h"

using namespace psi;

namespace miniforte {

void MyClass::use_psi4_options(psi::Options &options) {
  options.add_bool("WORKS", true);
}

} // namespace miniforte
