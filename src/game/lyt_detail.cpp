#include <types.h>

/* Review carves for the REXE01 nw4r/nw4hbm lyout cluster
 * (auto_03_800D58C4_text / auto_03_800A485C_text):
 *
 *   IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc
 *   MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc
 *
 * Review-only; not configured.
 */

extern "C" u32 __dt__Q36nw4hbm3lyt8BoundingFv(void* this_, s32 flag);

extern "C" u32 IsModulateVertexColor__Q34nw4r3lyt6detailFPQ34nw4r2ut5ColorUc(
    const u32* p, u32 val) {
    if (val != 0xFF) {
        return 1;
    }

    if (p != NULL && !(p[0] == 0xFFFFFFFF && p[1] == 0xFFFFFFFF &&
                        p[2] == 0xFFFFFFFF && p[3] == 0xFFFFFFFF)) {
        return 1;
    }

    return 0;
}

extern "C" void MultipleAlpha__Q34nw4r3lyt6detailFQ34nw4r2ut5ColorUc(
    u8* out, const u8* src, u32 alpha) {
    out[0] = src[0];
    out[1] = src[1];
    out[2] = src[2];
    out[3] = src[3];

    if (alpha != 0xFF) {
        out[3] = (u8)(((s32)((u8)src[3] * (u8)alpha)) / 255);
    }
}