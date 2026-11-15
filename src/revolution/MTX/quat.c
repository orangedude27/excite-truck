#include <revolution/MTX.h>

// Despite its SDK name, PSQUATMultiply is not a quaternion product. It leaves
// sqrt((a.x-b.x)^2 + (a.y-b.y)^2 + (a.z-b.z)^2) -- the distance between the
// vector parts of the two quaternions -- in f1, even though the prototype
// says void; the w components and `prod` are never read. The game calls it
// that way, as a plain 3-float point distance whose result is used as a float.
//
// The paired loads below take two floats at a time, so offset 0 holds (x, y)
// and offset 4 holds (y, z): the sum of squares covers x, y and z only.

// 0.5f and 3.0f live in the shared sdata2 pool (as in vec.c); naming the pool's
// labels keeps this file's own .sdata2 empty, the way its object was built.
extern const f32 lbl_80560C68; // 0.5f
extern const f32 lbl_80560C6C; // 3.0f

asm void PSQUATMultiply(register const Quaternion* a, register const Quaternion* b,
                        register Quaternion* prod) {
    // clang-format off
    nofralloc
    psq_l f0, Quaternion.y(a), 0, 0 // f0 = (a.y, a.z)
    psq_l f1, Quaternion.y(b), 0, 0 // f1 = (b.y, b.z)
    lfs f3, lbl_80560C68              // f3 = 0.5f, for the refinement below
    ps_sub f2, f0, f1               // f2 = (dy, dz)
    psq_l f0, Quaternion.x(a), 0, 0 // f0 = (a.x, a.y)
    psq_l f1, Quaternion.x(b), 0, 0 // f1 = (b.x, b.y)
    fsubs f4, f3, f3                // f4 = 0.0f
    ps_mul f2, f2, f2               // f2 = (dy^2, dz^2)
    ps_sub f0, f0, f1               // f0 = (dx, dy)
    ps_madd f1, f0, f0, f2          // f1 = (dx^2+dy^2, dy^2+dz^2)
    ps_sum0 f1, f1, f2, f2          // f1 = dx^2 + dy^2 + dz^2
    fcmpu cr0, f4, f1
    beqlr                           // coincident points: return 0.0f
    frsqrte f0, f1                  // f0 ~= 1 / sqrt(dist^2)
    lfs f4, 3.0f                    // f4 = 3.0f
    fmuls f2, f0, f0                // f2 = rsqrt^2
    fmuls f0, f0, f3                // f0 = rsqrt * 0.5
    fnmsubs f2, f2, f1, f4          // f2 = 3 - dist^2 * rsqrt^2
    fmuls f0, f2, f0                // f0 = (3 - dist^2 * rsqrt^2) * (rsqrt * 0.5)
    fmuls f1, f1, f0                // f1 = dist^2 * rsqrt(dist^2) = dist
    blr
    // clang-format on
}
