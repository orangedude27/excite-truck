#include <revolution/MTX.h>

/**
 * This translation unit contains a single SDK function (as linked into the
 * DOL at 0x8004A204). Despite its symbol-map name, the body computes the
 * Euclidean distance between two quaternions' xyz triples:
 *
 *   d2 = dx*dx + dy*dy + dz*dz
 *   if (d2 == 0.0f) return d2;
 *   rs = __frsqrte(d2);                       // initial estimate
 *   rs = (3.0f - d2 * rs * rs) * rs * 0.5f;   // Newton-Raphson refine
 *   return d2 * rs;                           // == sqrt(d2)
 *
 * The other PSQUAT/C_QUAT functions from the standard SDK source were
 * dead-stripped by the original link.
 */

DECOMP_FORCELITERAL(quat_c, 0.5f, 3.0f);

void PSQUATMultiply(register const Quaternion* a, register const Quaternion* b,
                    register Quaternion* prod) {
    register f32 ayz, ayzB, dyz, axyA, axyB, dxy, dot;
    register f32 c_half, c_three, zero, rs, rs2, nr, res;

    // clang-format off
    asm {
        psq_l   ayz,  Quaternion.y(a), 0, 0
        psq_l   ayzB, Quaternion.y(b), 0, 0
    }

    // lfs f3, lbl_80560C68@sda21(r0)
    c_half = 0.5f;

    asm {
        ps_sub  dyz,  ayz,  ayzB
        psq_l   axyA, Quaternion.x(a), 0, 0
        psq_l   axyB, Quaternion.x(b), 0, 0
        fsubs   zero, c_half, c_half
        ps_mul  dyz,  dyz,  dyz
        ps_sub  dxy,  axyA, axyB
        ps_madd dot,  dxy,  dxy, dyz
        ps_sum0 dot,  dot,  dyz, dyz
        fcmpu   cr0,  zero, dot
        beqlr
        frsqrte rs,   dot
    }

    // lfs f4, lbl_80560C6C@sda21(r0)
    c_three = 3.0f;

    asm {
        fmuls   rs2, rs,   rs
        fmuls   rs,  rs,   c_half
        fnmsubs rs2, rs2,  dot, c_three
        fmuls   nr,  rs2,  rs
        fmuls   res, dot,  nr
    }
    // clang-format on

    // Silence "unused" warnings for the result registers; the compiler
    // discards these without emitting code.
    (void)res;
    (void)prod;
}
