#include "types.h"
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

void fn_80031C68(void) {

}

extern void *lbl_8055D740;
void fn_80031C6C(void* hi) {
    lbl_8055D740 = hi;
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

