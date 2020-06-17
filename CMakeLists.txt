if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string

project(miniforte
        VERSION 0.1
        LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(TargetOpenMP_FIND_COMPONENTS "CXX")

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(psi4OptionsTools)

#find_package(psi4 1.1 REQUIRED COMPONENTS ambit chemps2)
find_package(pybind11 2.5.0 REQUIRED)
find_package(psi4 1.3 REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-c++1z-extensions") # avoid warnings for C++17

# List of CC files
pybind11_add_module(miniforte
src/miniforte.cc
)

target_link_libraries(miniforte PRIVATE psi4::core)
target_include_directories(miniforte PRIVATE src)
#target_link_libraries(forte PRIVATE tgt::MathOpenMP)
#set_target_properties(forte PROPERTIES PREFIX "")
#target_link_libraries(forte PRIVATE ambit::ambit)
#if(TARGET CheMPS2::chemps2)
#    target_link_libraries(forte PRIVATE CheMPS2::chemps2)
#    add_definitions(-DHAVE_CHEMPS2)
#endif()






##
## Forte tests
##
#option(ENABLE_ForteTests "Enable Forte tests." ON)


#if (ENABLE_ForteTests)
#  project (forte_tests)
#  include_directories(${CMAKE_BINARY_DIR} ${CMAKE_BINARY_DIR}/catch2/src/catch2/single_include)
#  add_executable(forte_tests
#    tests/code/test_determinant.cc
#    tests/code/test_uint64.cc)

#  project (forte_benchmarks)
#  include_directories(${CMAKE_BINARY_DIR})
#  add_executable(forte_benchmarks
#    tests/benchmark/determinant_benchmark.cc)
#endif (ENABLE_ForteTests)
