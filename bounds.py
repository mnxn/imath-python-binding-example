import nanobindimath as nbimath
import nanobindexample as nbexample

import pybindimath as pbimath
import pybindexample as pbexample

nbresult = nbexample.bounds(
    [
        nbimath.V3d(1, 2, 3),
        nbimath.V3d(2, 3, 1),
        nbimath.V3d(3, 1, 2),
    ]
)

pbresult = pbexample.bounds(
    [
        pbimath.V3d(1, 2, 3),
        pbimath.V3d(2, 3, 1),
        pbimath.V3d(3, 1, 2),
    ]
)


def print_result(name, box):
    print(f"{name}:")
    print(f"  (min) <{box.min.x}, {box.min.y}, {box.min.z}>")
    print(f"  (max) <{box.max.x}, {box.max.y}, {box.max.z}>")
    print()


print_result("nanobind", nbresult)
print_result("pybind11", pbresult)
