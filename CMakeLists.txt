cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string

project(miniforte
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(psi4OptionsTools)

set(CMAKE_C_COMPILER          "/home/travis/miniconda/envs/tenv/bin/x86_64-conda_cos6-linux-gnu-gcc" CACHE STRING "")
set(CMAKE_CXX_COMPILER        "/home/travis/miniconda/envs/tenv/bin/x86_64-conda_cos6-linux-gnu-g++" CACHE STRING "")
set(CMAKE_Fortran_COMPILER    "/home/travis/miniconda/envs/tenv/bin/x86_64-conda_cos6-linux-gnu-gfortran" CACHE STRING "")

set(CMAKE_C_FLAGS             "-march=native" CACHE STRING "")
set(CMAKE_CXX_FLAGS           "-march=native" CACHE STRING "")
set(CMAKE_Fortran_FLAGS       "-march=native" CACHE STRING "")

set(ENABLE_OPENMP             ON CACHE BOOL "")
set(OpenMP_LIBRARY_DIRS       "/home/travis/miniconda/envs/tenv/lib" CACHE STRING "")

set(CMAKE_INSTALL_LIBDIR      "lib" CACHE STRING "")
set(CMAKE_INSTALL_BINDIR      "bin" CACHE STRING "")
set(CMAKE_INSTALL_DATADIR     "share" CACHE STRING "")
set(CMAKE_INSTALL_INCLUDEDIR  "include" CACHE STRING "")
set(PYMOD_INSTALL_LIBDIR      "/python3.7/site-packages" CACHE STRING "")

set(CMAKE_INSTALL_MESSAGE     "LAZY" CACHE STRING "")
#set(pybind11_DIR              "/home/travis/miniconda/envs/tenv/share/cmake/pybind11" CACHE PATH "")
set(pybind11_DIR              "/home/travis/build/evangelistalab/miniforte/pybind11" CACHE PATH "")
set(PYTHON_EXECUTABLE         "/home/travis/miniconda/envs/tenv/bin/python" CACHE STRING "")


find_package(pybind11 2.5.0 REQUIRED)
find_package(psi4 1.3 REQUIRED)

pybind11_add_module(miniforte
src/miniforte.cc
)

target_include_directories(miniforte PRIVATE src)
target_link_libraries(miniforte PRIVATE psi4::core)
