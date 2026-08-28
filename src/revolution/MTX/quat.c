#include <revolution/MTX.h>

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
