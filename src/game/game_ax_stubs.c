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
/* __AXDSPInitCallback_800B7860 (auto_03_800A485C_text): zeroes a flag. */
extern u32 lbl_8055DD10;

void __AXDSPInitCallback_800B7860(void) {
    lbl_8055DD10 = 0;
}

/* REXE01 game-region AX/DSP accessor stubs (auto_03_801281A0_text,
 * auto_03_801293B4_text, auto_03_80129400_text):
 *
 *   __AXGetStudio_80129164     -> &lbl_8032A068
 *   __AXFXGetLfoSinTable_801297F4 -> &lbl_804223C0
 *   __AXDSPInitCallback_801293D0 -> s_flag = 0 (lbl_8055DFC0)
 *   __AXGetStudio_80165834     -> &lbl_8041E180
 *   __AXDSPInitCallback_801769E0 -> s_flag = 1 (lbl_8055E3C0)
 *   __AXGetStudio_80178C90     -> &lbl_80421F80
 *   __AXDSPInitCallback_80134770 -> s_flag = 0 (lbl_8055E0AC)
 *   __AXGetStackHead_80137CFC   -> lbl_8042F798[arg*4]
 *   __AXFXGetLfoSinTable_801769CC -> &lbl_804303E0
 *   __AXDSPInitCallback_801AFC38 -> s_flag = 0 (lbl_8055E650)
 *   __AXDSPInitCallback_801B8BE8 -> s_flag = 0 (lbl_8055E764)
 *   __AXDSPInitCallback_801D0CF0 -> s_flag = 0 (lbl_8055E8E8)
 *   __AXDSPInitCallback_801D32D0 -> s_flag = 0 (lbl_8055E940)
 *   __AXFXGetLfoSinTable_801D64F4 -> &lbl_803387A8
 *   __AXGetStackHead_802BC30C   -> lbl_804C0098[arg*4]
 *
 * All 0xC-B 3-instruction stubs; far references for .data/.bss,
 * sda21 for .sbss flags. */
extern u8 lbl_8032A068[0xA];     /* .data */
extern u8 lbl_804223C0[0x38];    /* .bss */
extern u32 lbl_8055DFC0;         /* .sbss */
extern u8 lbl_8041E180[];        /* .data */
extern u32 lbl_8055E3C0;         /* .sbss */
extern u8 lbl_80421F80[];        /* .data */
extern u32 lbl_8055E0AC;         /* .sbss */
extern u8 lbl_8042F798[0x10];    /* .bss */
extern u8 lbl_804303E0[0x38];    /* .bss */
extern u32 lbl_8055E650;         /* .sbss */
extern u32 lbl_8055E764;         /* .sbss */
extern u32 lbl_8055E8E8;         /* .sbss */
extern u32 lbl_8055E940;         /* .sbss */
extern u8 lbl_803387A8[];        /* .data */
extern u8 lbl_804C0098[0x18];    /* .bss */

void* __AXGetStudio_80129164(void) {
    return &lbl_8032A068;
}

s32* __AXFXGetLfoSinTable_801297F4(void) {
    return (s32*)lbl_804223C0;
}

void __AXDSPInitCallback_801293D0(void) {
    lbl_8055DFC0 = 0;
}

void* __AXGetStudio_80165834(void) {
    return (void*)lbl_8041E180;
}

void __AXDSPInitCallback_801769E0(void) {
    lbl_8055E3C0 = 1;
}

void* __AXGetStudio_80178C90(void) {
    return (void*)lbl_80421F80;
}

void __AXDSPInitCallback_80134770(void) {
    lbl_8055E0AC = 0;
}

u32 __AXGetStackHead_80137CFC(u32 arg) {
    return *(u32*)&lbl_8042F798[arg * 4];
}

s32* __AXFXGetLfoSinTable_801769CC(void) {
    return (s32*)lbl_804303E0;
}

void __AXDSPInitCallback_801AFC38(void) {
    lbl_8055E650 = 0;
}

void __AXDSPInitCallback_801B8BE8(void) {
    lbl_8055E764 = 0;
}

void __AXDSPInitCallback_801D0CF0(void) {
    lbl_8055E8E8 = 0;
}

void __AXDSPInitCallback_801D32D0(void) {
    lbl_8055E940 = 0;
}

s32* __AXFXGetLfoSinTable_801D64F4(void) {
    return (s32*)lbl_803387A8;
}

u32 __AXGetStackHead_802BC30C(u32 arg) {
    return *(u32*)&lbl_804C0098[arg * 4];
}
