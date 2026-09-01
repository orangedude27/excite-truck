#include <revolution/MTX.h>

#define qr0 0

void PSMTXIdentity(register Mtx m) {
    register f32 c_zero = 0.0f;
    register f32 c_one = 1.0f;
    register f32 c_01;
    register f32 c_10;

    asm {
        ps_merge01 c_01, c_zero, c_one
        ps_merge10 c_10, c_one, c_zero

        psq_st c_10, 0(m), 0, qr0
        psq_st c_zero, 8(m), 0, qr0
        psq_st c_01, 16(m), 0, qr0
        psq_st c_zero, 24(m), 0, qr0
        psq_st c_zero, 32(m), 0, qr0
        psq_st c_10, 40(m), 0, qr0
    }
}

asm void PSMTXCopy(register const Mtx src, register Mtx dst) {
    // clang-format off
    nofralloc
    psq_l f0, 0(src), 0, qr0
    psq_st f0, 0(dst), 0, qr0
    psq_l f1, 8(src), 0, qr0
    psq_st f1, 8(dst), 0, qr0
    psq_l f2, 16(src), 0, qr0
    psq_st f2, 16(dst), 0, qr0
    psq_l f3, 24(src), 0, qr0
    psq_st f3, 24(dst), 0, qr0
    psq_l f4, 32(src), 0, qr0
    psq_st f4, 32(dst), 0, qr0
    psq_l f5, 40(src), 0, qr0
    psq_st f5, 40(dst), 0, qr0
    blr
    // clang-format on
}