GM2Calc
=======

GM2Calc calculates the SUSY contributions to the anomalous magnetic
moment of the muon a_mu = (g-2)/2 in the real MSSM at the 1- and
leading 2-loop level.

 * Homepage:                https://gm2calc.hepforge.org
 * Source code repository:  https://github.com/gm2calc
 * References:              Eur.Phys.J. C76 (2016) no.2, 62
   [[arxiv:1510.08071](https://arxiv.org/abs/1510.08071)]


Requirements
============

 * C++ compiler (g++ >= 4.6.3 or clang++ >= 3.4 or icpc >= 14.0.3)
 * Boost (version 1.37.0 or higher) [http://www.boost.org]
 * Eigen 3 (version 3.1 or higher) [http://eigen.tuxfamily.org]


Compilation
===========

To compile GM2Calc run:

    mkdir build
    cd build
    cmake ..
    make

The GM2Calc executable can then be found in `bin/gm2calc.x` and the
GM2Calc library can be found in the `lib/` directory.  The used
compiler and package paths can be passed as arguments to cmake.

Example:

    cmake \
       -DCMAKE_CXX_COMPILER=icpc \
       -DEIGEN3_INCLUDE_DIR=/opt/eigen3/eigen3 \
       -DBOOST_ROOT=/opt/boost \
       ..


Example programs
----------------

GM2Calc ships two C++ example programs:

    examples/example-gm2calc.cpp
    examples/example-slha.cpp

and two C example programs:

    examples/example-gm2calc_c.c
    examples/example-slha_c.c

These example programs illustrate how to use routines of GM2Calc at
the C/C++ level.  The examples are build by default and the compiled
executables can be found in the `bin/` directory.


Running GM2Calc
===============

GM2Calc can be run with either an SLHA interface or with a custom
GM2Calc interface (similar to SLHA, but different definition of input
parameters).  See `bin/gm2calc.x --help` for all options.

Example using the SLHA interface:

    bin/gm2calc.x --slha-input-file=input/example.slha

or

    cat input/example.slha | bin/gm2calc.x --slha-input-file=-

Example using the GM2Calc interface:

    bin/gm2calc.x --gm2calc-input-file=input/example.gm2

or

    cat input/example.gm2 | bin/gm2calc.x --gm2calc-input-file=-


SLHA interface
==============

When the input parameters are provided in SLHA-compliant form, GM2Calc
reads the input parameters from the following blocks:

 * `SMINPUTS`: Standard Model fermion masses, W and Z pole masses,
   alpha_s(MZ)

 * `MASS`: pole masses of SUSY particles, W pole mass.  If the W pole
   mass is given in `MASS[24]`, then this value will be used instead
   of the W pole mass given in `SMINPUTS[9]`.

 * `HMIX`: tan(beta), mu parameter, renormalization scale

 * `AU`, `AD`, `AE`: soft-breaking trilinear couplings,
   renormalization scale

 * `MSOFT`: soft-breaking gaugino masses, soft-breaking sfermion
   masses, renormalization scale

 * `GM2CalcInput`: alpha_em(MZ), alpha_em in the Thomson limit


GM2Calc interface
=================

When the input parameters are provided in GM2Calc specific form,
GM2Calc reads the input parameters from the following blocks:

 * `SMINPUTS`: Standard Model fermion masses, W and Z pole masses,
   alpha_s(MZ)

 * `GM2CalcInput`: renormalization scale, alpha_em(MZ), alpha_em in
   the Thomson limit, tan(beta), mu parameter, soft-breaking gaugino
   masses, soft-breaking Bmu parameter, soft-breaking sfermion masses,
   soft-breaking trilinear couplings


C/C++ interface
===============

GM2Calc provides a C and a C++ interface.  To use the routines of
GM2Calc in a C++ program, the following C++ header files have to be
included:

    src/gm2_1loop.hpp
    src/gm2_2loop.hpp
    src/gm2_uncertainty.hpp
    src/MSSMNoFV_onshell.hpp

To use the routines of GM2Calc in a C program, the following C header
files have to be included:

    src/gm2_1loop.h
    src/gm2_2loop.h
    src/gm2_uncertainty.h
    src/MSSMNoFV_onshell.h

Please refer to the content of these header files for a precise
definition of all interface functions.  The C/C++ example programs
also serve as an illustration of the interface routines.


Mathematica interface
=====================

When Mathematica is installed, a MathLink executable for GM2Calc is
build, which allows one to run GM2Calc from within Mathematica.  The
MathLink executable can be found in

    bin/gm2calc.mx

This executable can be installed in Mathematica by calling

    Install["bin/gm2calc.mx"]

Afterwards, the GM2Calc Mathematica interface functions can be used,
see `examples/example-slha.m` and `examples/example-gm2calc.m`.


Configuration options
=====================

The calculation of a_mu can be controlled in the GM2CalcConfig block.

 * `GM2CalcConfig[0]`: output format (`0` ... `4`)

   `0`: minimal output (a single number)  
   `1`: detailed (a detailed output of the various contributions)  
   `2`: write the value of (g-2)/2 into `LOWEN` block, entry `6`  
   `3`: write the value of (g-2)/2 into `SPhenoLowEnergy` block, entry `21`  
   `4`: write the value of (g-2)/2 into `GM2CalcOutput` block, entry `0`

 * `GM2CalcConfig[1]`: loop order of the calculation (`0`, `1` or `2`)

 * `GM2CalcConfig[2]`: disable/enable tan(beta) resummation (`0` or `1`)

 * `GM2CalcConfig[3]`: force output even if physical problem has
   occured (`0` or `1`).  **WARNING**: The result might not be trusted
   if a problem has occured!

 * `GM2CalcConfig[4]`: disable/enable verbose output (`0` or `1`).

 * `GM2CalcConfig[5]`: disable/enable uncertainty estimation (`0` or `1`).
   Depending on the chosen output format, `GM2CalcConfig[0]`, the
   uncertainty is written

   * as a single number to stdout   in case of minimal output,
   * to the first line              in case of detailed output,
   * to `GM2CalcOutput[1]`          otherwise.


Source code documentation
=========================

GM2Calc uses Doxygen to document the source code.  The complete source
code documentation can be generated by running

    make doc

Afterwards, the generated HTML pages can be found in `doc/html/` and
can be openend with your favourite web browser, e.g.

    firefox doc/html/index.html
