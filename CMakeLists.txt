cmake_minimum_required(VERSION 3.15...3.27)
project(imath_python_binding_example)

if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.12 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT)

find_package(nanobind CONFIG REQUIRED)
find_package(pybind11 REQUIRED)

nanobind_add_module(nanobindexample nanobindexample.cpp)

pybind11_add_module(pybindexample pybindexample.cpp)
