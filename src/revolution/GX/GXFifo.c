#include <revolution/GX.h>
#include <revolution/OS.h>

#include <string.h>

/* Review carve for the REXE01 GX FIFO/TLUT auto-unit functions
 * (auto_03_8003DB9C_text):
 *
 *   __GXFifoInit@8003F800
 *   __GXIsGPFifoReady@8003F5B8
 *   __GXDefaultTlutRegionCallback@8003DC90
 *
 * REXE01's __GXData layout puts TlutRegions at +0x3D8 (the project header
 * models the later SDK layout at +0x2D0), so the callback uses byte
 * arithmetic with the documented REXE01 offset.  CPUFifo/GPFifo objects
 * at lbl_8037C0C0/lbl_8037C0E4 (0x24 each); sbss ready flags at
 * lbl_8055D948/lbl_8055D949, thread at lbl_8055D95C.
 * Review-only; not configured.
 */

extern struct __GXData_struct* gx;

extern u8 lbl_8037C0C0[0x24];
extern u8 lbl_8037C0E4[0x24];

extern u8 lbl_8055D948;
extern u8 lbl_8055D949;
extern u32 lbl_8055D958;
extern OSThread* lbl_8055D95C;

extern void GXCPInterruptHandler(s16 intr, OSContext* ctx);

void __GXFifoInit(void) {
    __OSSetInterruptHandler(OS_INTR_PI_CP, GXCPInterruptHandler);
    __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_PI_CP));
    lbl_8055D95C = OSGetCurrentThread();
    lbl_8055D958 = FALSE;
    memset(&lbl_8037C0E4, 0, 0x24);
    memset(&lbl_8037C0C0, 0, 0x24);
    lbl_8055D948 = FALSE;
    lbl_8055D949 = FALSE;
}

u8 __GXIsGPFifoReady(void) {
    return lbl_8055D949;
}

void* __GXDefaultTlutRegionCallback(u32 idx) {
    if (idx >= 20) {
        return NULL;
    }

    return (u8*)gx + 0x3D8 + idx * 16;
}