#include <revolution/AX.h>

/* Review-source carve for the REXE01 game-region AX/DSP accessor stubs
 * (unattributed duplicates of SDK AX helpers, dispatched indirectly via
 * function-pointer tables):
 *
 *   __AXGetStudio_8000AC2C      -> &lbl_8034F520
 *   __AXGetStudio_8000D82C      -> &lbl_802FC200
 *   __AXGetStudio_800324C4      -> &lbl_80363BE0  (AXSTUDIOStorage)
 *   __AXFXGetLfoSinTable_8003313C -> &lbl_80363C60
 *   __AXDSPInitCallback_800216B8 -> s_flag_2 = 2
 *   __AXDSPInitCallback_80031F90 -> s_flag_1 = 1
 *   __AXDSPInitCallback_8004DDC4 -> s_flag_3 = 1
 *
 * None of the queue-listed addresses are reachable by a direct bl; they are
 * registered as DSP/init callbacks.  This TU stays unconfigured/review only.
 */

extern u8 lbl_80363BE0[0x80];
extern u8 lbl_8034F520[0x80];
extern u8 lbl_802FC200[];
extern u16 lbl_80363C60[];

extern u32 lbl_8055D62C;
extern u32 lbl_8055D770;
extern u32 lbl_8055DA44;

void* __AXGetStudio_8000AC2C(void) {
    return &lbl_8034F520;
}

void* __AXGetStudio_8000D82C(void) {
    return &lbl_802FC200;
}

AXSTUDIO* __AXGetStudio_800324C4(void) {
    return (AXSTUDIO*)&lbl_80363BE0;
}

s32* __AXFXGetLfoSinTable_8003313C(void) {
    return (s32*)lbl_80363C60;
}

void __AXDSPInitCallback_800216B8(void) {
    lbl_8055D62C = 2;
}

void __AXDSPInitCallback_80031F90(void) {
    lbl_8055D770 = 1;
}

void __AXDSPInitCallback_8004DDC4(void) {
    lbl_8055DA44 = 1;
}