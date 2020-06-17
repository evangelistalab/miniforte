#include "psi4/liboptions/liboptions.h"
#include "psi4/libpsi4util/PsiOutStream.h"

#include "myclass.h"

using namespace pybind11::literals;

using namespace psi;

namespace miniforte {

void MyClass::use_psi4_options(psi::Options &options) {
  options.add_bool("WORKS", true);
}

} // namespace miniforte
