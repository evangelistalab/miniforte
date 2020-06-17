cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string

project(miniforte
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(psi4OptionsTools)

find_package(pybind11 2.5.0 REQUIRED)
find_package(psi4 1.3 REQUIRED)

pybind11_add_module(miniforte
src/miniforte.cc
)

target_include_directories(miniforte PRIVATE src)
target_link_libraries(miniforte PRIVATE psi4::core)
