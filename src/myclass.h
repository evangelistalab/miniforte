#include "psi4/liboptions/liboptions.h"

namespace miniforte {

class MyClass {
public:
  void use_psi4_options(psi::Options options) {
    options.add_bool("WORKS", true);
  }
};

} // namespace miniforte
