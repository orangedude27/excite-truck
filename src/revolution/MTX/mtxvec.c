#include <revolution/MTX.h>

// NOTE: In the original binary the dtk auto-names drift by one slot around
// here: the 0x28-byte function at 0x80049EF8 builds a scale matrix (real
// PSMTXScale) and the 0x54-byte function at 0x80049F20 is the real
// PSMTXMultVec. C_MTXFrustum / PSMTXTrans etc. were stripped by the linker.
// symbols.txt carries the corrected names; match against those.

// .sdata2 zero literal used by PSMTXScale
extern f32 lbl_80560C4C;

/* Build a scale matrix: sx/sy/sz on the diagonal, zero elsewhere; the paired-single stores fill two zero entries at a time. */
void PSMTXScale(Mtx m, f32 sx, f32 sy, f32 sz) {
    register f32 c0 = lbl_80560C4C;
    register void* mp = m;
    register f32 rsx = sx, rsy = sy, rsz = sz;

    // clang-format off
    asm {
        stfs    rsx, 0x0(mp)
        psq_st  c0, 0x4(mp), 0, 0
        psq_st  c0, 0xc(mp), 0, 0
        stfs    rsy, 0x14(mp)
        psq_st  c0, 0x18(mp), 0, 0
        psq_st  c0, 0x20(mp), 0, 0
        stfs    rsz, 0x28(mp)
        stfs    c0,  0x2c(mp)
    }
    // clang-format on
}

/*
 * PSMTXMultVec - transform a point by a 3x4 row-major matrix (below).
 *
 * out = mtx * (vec, 1): every component is the dot product of one matrix row
 * with the vector.  The vector's Z is loaded with the paired-load "w" bit set
 * (psq_l f1, Vec.z(vec), 1, 0), so that load hands back {VZ, 1.0} and each
 * row's translation element mtx[row][3] takes part in the sum - this maps
 * points, not directions.
 *
 * The body is the Revolution SDK's own hand-written assembly, kept as the SDK
 * wrote it: a row's four products are done as two paired-single operations,
 * ps_sum0 folds the pair's halves into one scalar, and the next row's loads
 * are issued before the store of the finished component.  No C reproduces
 * that schedule, so the body stays assembly.
 */

asm void PSMTXMultVec(register const Mtx mtx, register const Vec* vec,
                      register Vec* out) {
    // clang-format off
    nofralloc

    // out->x = dot(mtx[0], (vec,1))
    psq_l   f0, Vec.x(vec), 0, 0 // VX,            VY
    psq_l   f2, 0(mtx),     0, 0 // M0X,           M0Y
    psq_l   f1, Vec.z(vec), 1, 0 // VZ,            1  <- "w" bit fills w=1.0
    ps_mul  f4, f2, f0           // M0X*VX,        M0Y*VY
    psq_l   f3, 8(mtx),     0, 0 // M0Z,           M0W (translation)
    ps_madd f5, f3, f1, f4       // M0Z*VZ+M0X*VX, M0W+M0Y*VY
    psq_l   f8, 16(mtx),    0, 0 // M1X,           M1Y (head start on Y)
    ps_sum0 f6, f5, f6, f5       // add the pair's halves -> tx

    // Y's products, issued while X is stored
    psq_l  f9,  24(mtx), 0, 0    // M1Z, M1W
    ps_mul f10, f8, f0           // M1X*VX, M1Y*VY

    // tx
    psq_st f6, Vec.x(out), 1, 0

    // out->y = dot(mtx[1], (vec,1))
    ps_madd f11, f9,  f1,  f10   // M1Z*VZ+M1X*VX, M1W+M1Y*VY
    psq_l   f2,  32(mtx), 0, 0   // M2X, M2Y       (head start on Z)
    ps_sum0 f12, f11, f12, f11   // add the pair's halves -> ty

    // Z's products, issued while Y is stored
    psq_l  f3, 40(mtx), 0, 0     // M2Z, M2W
    ps_mul f4, f2, f0            // M2X*VX, M2Y*VY

    // ty
    psq_st f12, Vec.y(out), 1, 0

    // out->z = dot(mtx[2], (vec,1))
    ps_madd f5, f3, f1, f4       // M2Z*VZ+M2X*VX, M2W+M2Y*VY
    ps_sum0 f6, f5, f6, f5       // add the pair's halves -> tz

    // tz
    psq_st f6, Vec.z(out), 1, 0

    blr
    // clang-format on
}
