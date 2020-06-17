#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psi4
import miniforte

print(f"Welcome to miniforte!")
print(miniforte.add(3,4))
psi_options = psi4.core.get_options()
psi_options.set_current_module('FORTE')
myclass = miniforte.MyClass()
myclass.use_psi4_options(psi_options)
print(f"Execution ended.")
