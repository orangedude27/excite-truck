#include "types.h"
extern void *lbl_8055D740;
extern u8 lbl_8035E820[];
extern u16 lbl_8055D730;
extern u16 lbl_8055D732;
extern s32 lbl_8055D738;
extern void *lbl_8055D744;
extern s32 lbl_8055D748;
extern s32 lbl_8055D750;
extern s32 lbl_8055D754;
extern s32 lbl_8055D758;
extern s32 lbl_8055D774;
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void OSSleepThread(void *);
extern void AIStopDMA(void);
extern void __DSPHandler(void *);
extern volatile u32 lbl_8055D778;
extern volatile u32 lbl_8055D77C;
extern volatile u32 lbl_8055D784;
extern u32 lbl_8055D780;
extern u32 lbl_8055D75C;
extern u8 lbl_8035F700[];
extern u8 lbl_8035FB80[];
extern u64 OSGetTime(void);
extern void CircleBufferInitialize(u32);
extern void DSPAssertTask(void *);
extern void AIInitDMA(void *, u32);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned short lbl_8055D734;
extern void *lbl_8055D728;
extern void *lbl_8055D71C;
extern void *lbl_8055D724;
extern void *lbl_8055D718;
extern void *lbl_8055D720;
extern void *lbl_8055D714;

extern void *lbl_8055D73C;
extern void *lbl_8055D6A8;
void TRKConstructEvent(void) {
    lbl_8055D6A8 = 0;
}

void TRKDispatchMessage(void **arg0) {
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D728 != 0) {
        *arg0 = lbl_8035BFA0 + lbl_8055D6F8 * 0x480;
        return;
    }
    *arg0 = 0;
}

void __AXGetAuxAOutput(void **arg0) {
    extern u8 lbl_8035BFA0[];
    extern s32 lbl_8055D6F4;
    *arg0 = lbl_8035BFA0 + lbl_8055D6F4 * 0x480;
}

extern u8 lbl_8035DAA0[];
extern u8 lbl_8035BFA0[];
extern s32 lbl_8055D6F8;
extern s32 lbl_8055D6F4;
void __AXGetAuxAInputDpl2(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F8 * 0x480 + 0x180;
}

void __AXGetAuxAOutputDpl2R(void **arg0) {
    *arg0 = lbl_8035BFA0 + lbl_8055D6F4 * 0x480 + 0x180;
}

void __AXGetAuxAOutputDpl2Ls(void **arg0) {
    *arg0 = lbl_8035BFA0 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxAOutputDpl2Rs(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F4 * 0x480 + 0x180;
}

void __AXGetAuxAInput(void **arg0) {
    extern u8 lbl_8035CD20[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D724 != 0) {
        *arg0 = lbl_8035CD20 + lbl_8055D6F8 * 0x480;
        return;
    }
    *arg0 = 0;
}

void __AXGetAuxBOutput(void **arg0) {
    extern u8 lbl_8035CD20[];
    extern s32 lbl_8055D6F4;
    *arg0 = lbl_8035CD20 + lbl_8055D6F4 * 0x480;
}

void __AXGetAuxBInputDpl2(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F8 * 0x480 + 0x300;
}

extern u8 lbl_8035CD20[];
void __AXGetAuxBOutputDpl2R(void **arg0) {
    *arg0 = lbl_8035CD20 + lbl_8055D6F4 * 0x480 + 0x180;
}

void __AXGetAuxBOutputDpl2Ls(void **arg0) {
    *arg0 = lbl_8035CD20 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxBOutputDpl2Rs(void **arg0) {
    *arg0 = lbl_8035DAA0 + lbl_8055D6F4 * 0x480 + 0x300;
}

void __AXGetAuxBInput(void **arg0) {
    extern u8 lbl_8035DAA0[];
    extern s32 lbl_8055D6F8;
    if (lbl_8055D720 != 0) {
        *arg0 = lbl_8035DAA0 + lbl_8055D6F8 * 0x480;
        return;
    }
    *arg0 = 0;
}

void __AXGetAuxCOutput(void **arg0) {
    extern u8 lbl_8035DAA0[];
    extern s32 lbl_8055D6F4;
    *arg0 = lbl_8035DAA0 + lbl_8055D6F4 * 0x480;
}

void AXRegisterAuxACallback(void *arg0, void *arg1) {
    lbl_8055D728 = arg0;
    lbl_8055D71C = arg1;
}

void AXRegisterAuxBCallback(void *arg0, void *arg1) {
    lbl_8055D724 = arg0;
    lbl_8055D718 = arg1;
}

void AXRegisterAuxCCallback(void *arg0, void *arg1) {
    lbl_8055D720 = arg0;
    lbl_8055D714 = arg1;
}

void AXGetAuxACallback(void **arg0, void **arg1) {
    *arg0 = lbl_8055D728;
    *arg1 = lbl_8055D71C;
}

void AXGetAuxBCallback(void **arg0, void **arg1) {
    *arg0 = lbl_8055D724;
    *arg1 = lbl_8055D718;
}

void AXGetAuxCCallback(void **arg0, void **arg1) {
    *arg0 = lbl_8055D720;
    *arg1 = lbl_8055D714;
}

void* fn_80031248(void) {
    return lbl_8055D73C;
}

void CircleBufferWriteBytes(void) {
    lbl_8055D740 = 0;
    lbl_8055D748 = 0;
    lbl_8055D744 = lbl_8035E820;
    lbl_8055D738 = 1;
    lbl_8055D734 = 0x8000;
    lbl_8055D732 = 0x8000;
    lbl_8055D730 = 0x8000;
}

void fn_80031C68(void) {

}

extern void *lbl_8055D740;
void fn_80031C6C(void* hi) {
    lbl_8055D740 = hi;
}

u16 fn_80031C74(void) {
    return lbl_8055D734;
}

u16 fn_80031C7C(void) {
    return lbl_8055D732;
}

u16 fn_80031C84(void) {
    return lbl_8055D730;
}

void fn_80031C8C(unsigned short arg0) {
    lbl_8055D734 = arg0;
}

void fn_80031ED4(void) {
    u64 time;
    if ((s32)lbl_8055D780 == 0) {
        time = OSGetTime();
        lbl_8055D77C = (u32)time;
        lbl_8055D778 = (u32)(time >> 32);
    }
    if (lbl_8055D780 == 1U) {
        lbl_8055D780 = 0;
        CircleBufferInitialize(0);
    } else {
        lbl_8055D780 = 2;
        DSPAssertTask(lbl_8035FB80);
    }
    if (lbl_8055D75C == 1U) {
        AIInitDMA(lbl_8035F700 + lbl_8055D784 * 0x180, 0x180);
        lbl_8055D784 += 1;
        lbl_8055D784 %= 3;
    }
}

extern s32 lbl_8055D770;
extern s32 lbl_8055D76C;
extern s32 lbl_8055D760;
extern volatile u32 lbl_8055D778;
extern volatile u32 lbl_8055D77C;
extern volatile u32 lbl_8055D784;
extern u32 lbl_8055D780;
extern u32 lbl_8055D75C;
extern u8 lbl_8035F700[];
extern u8 lbl_8035FB80[];
extern u64 OSGetTime(void);
extern void CircleBufferInitialize(u32);
extern void OSWakeupThread(void *);
extern void DSPAssertTask(void *);
extern void AIInitDMA(void *, u32);
void __AXDSPInitCallback_80031F90(void) {
    lbl_8055D770 = 1;
}

void fn_80031F9C(void) {
    if (lbl_8055D780 == 2U) {
        lbl_8055D780 = 0;
        CircleBufferInitialize((u32)(OSGetTime() - (((u64)lbl_8055D778 << 32) | lbl_8055D77C)) >> 2);
    } else {
        lbl_8055D780 = 1;
    }
}

void __AXDSPDoneCallback(void) {
    lbl_8055D76C = 1;
    OSWakeupThread(&lbl_8055D760);
}

void fn_80032000(void) {

}

void fn_800322E4(void) {
    s32 enabled = OSDisableInterrupts();
    lbl_8055D774 = 0;
    __DSPHandler(lbl_8035FB80);
    OSSleepThread(&lbl_8055D760);
    AIStopDMA();
    OSRestoreInterrupts(enabled);
}

s32 AXRmtGetSamplesLeft(void) {
    s32 result;
    s32 samples = lbl_8055D754 - 0x24;
    if (samples < 0) {
        samples += lbl_8055D758;
    }
    result = samples - lbl_8055D750;
    if (result < 0) {
        return result + lbl_8055D758;
    }
    return result;
}

