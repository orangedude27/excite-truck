#include <revolution/MTX.h>

// Despite its SDK name, PSQUATMultiply is not a quaternion product. It leaves
// sqrt((a.x-b.x)^2 + (a.y-b.y)^2 + (a.z-b.z)^2) -- the distance between the
// vector parts of the two quaternions -- in f1, even though the prototype
// says void; the w components and `prod` are never read. The game calls it
// that way, as a plain 3-float point distance whose result is used as a float.
//
// The paired loads below take two floats at a time, so offset 0 holds (x, y)
// and offset 4 holds (y, z): the sum of squares covers x, y and z only.

asm void PSQUATMultiply(register const Quaternion* a, register const Quaternion* b,
                        register Quaternion* prod) {
    // clang-format off
    nofralloc
    psq_l f0, 4(r3), 0, 0
    psq_l f1, 4(r4), 0, 0
    lfs f3, 0.5f
    ps_sub f2, f0, f1
    psq_l f0, 0(r3), 0, 0
    psq_l f1, 0(r4), 0, 0
    fsubs f4, f3, f3
    ps_mul f2, f2, f2
    ps_sub f0, f0, f1
    ps_madd f1, f0, f0, f2
    ps_sum0 f1, f1, f2, f2
    fcmpu cr0, f4, f1
    beqlr
    frsqrte f0, f1
    lfs f4, 3.0f
    fmuls f2, f0, f0
    fmuls f0, f0, f3
    fnmsubs f2, f2, f1, f4
    fmuls f0, f2, f0
    fmuls f1, f1, f0
    blr
    // clang-format on
}
