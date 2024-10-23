#include <vector>

#include <Imath/ImathBox.h>
#include <Imath/ImathVec.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

using Imath::Box3d, Imath::V3d;

Box3d bounds(std::vector<V3d> vecs)
{
    Box3d bounds;
    for (V3d vec : vecs) {
        bounds.extendBy(vec);
    }
    return bounds;
}

PYBIND11_MODULE(pybindexample, m)
{
    m.def("bounds", &bounds);
}
