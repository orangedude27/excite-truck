#include <types.h>

#include <math.h>

/* Review carve for REXE01 PSMTXInverse@0x80049D4C (auto_03_8003DB9C_text).
 *
 * This is the GCN-era MTXRotRad-style wrapper: computes sin/cos of the
 * angle and delegates to PSMTXInvXpose(m, axis, sinA, cosA).  The public
 * mtx.h prototypes (const Mtx, Mtx) reflect the newer SDK shape; the
 * REXE01 body takes (Mtx m, char axis, f32 rad).  Review-only, not
 * configured.
 */

typedef f32 Mtx[3][4];

u32 PSMTXInvXpose(Mtx m, char axis, f32 sinA, f32 cosA);

u32 PSMTXInverse(Mtx m, char axis, f32 rad) {
    f32 sinA;
    f32 cosA;

    sinA = sinf(rad);
    cosA = cosf(rad);

    return PSMTXInvXpose(m, axis, sinA, cosA);
}