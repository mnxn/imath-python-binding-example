#include <vector>

#include <Imath/ImathBox.h>
#include <Imath/ImathVec.h>
#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>

using Imath::Box3d, Imath::V3d;

Box3d bounds(std::vector<V3d> vecs)
{
    Box3d bounds;
    for (V3d vec : vecs) {
        bounds.extendBy(vec);
    }
    return bounds;
}

NB_MODULE(nanobindexample, m)
{
    m.def("bounds", &bounds);
}
