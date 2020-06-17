#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psi4
import miniforte

print(f"Welcome to miniforte!")
print(miniforte.add(3,4))
psi_options = psi4.core.get_options()
psi_options.set_current_module('FORTE')
#    forte_options.push_options_to_psi4(psi_options)
