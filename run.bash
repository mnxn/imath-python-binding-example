#!/usr/bin/env bash
set -e

cmake . -B _build
cmake --build _build

# assuming Imath's pybind11 and nanobind bindings were installed here
PYTHONPATH=/usr/local/lib/python3.12/site-packages:_build python3.12 bounds.py
