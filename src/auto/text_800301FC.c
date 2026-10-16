#include "types.h"
extern u32 lbl_8055D6E8;
extern u32 lbl_80558DD8;
extern u32 lbl_8035BF20[];
extern void TRKReleaseBuffer(void *);
extern void TRKAppendBuffer1_ui64(void);
extern void TRKAppendBuffer_ui32(void);
extern void OSRegisterVersion(s32);
extern void fn_80033404(void);
extern void fn_80032778(void);
extern void usr_puts_serial(void);
extern void fn_800331A0(void);
extern void __AXSPBInit(void);
extern void TRKGetInput(void);
extern void fn_800320E8(s32);
extern void fn_80031C68(void);
extern void fn_800322E4(void);
extern void CircleBufferWriteBytes(void);
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

void TRKMessageSend(void) {
    OSRegisterVersion(lbl_80558DD8);
    TRKAppendBuffer_ui32();
    fn_800331A0();
    __AXSPBInit();
    TRKGetInput();
    CircleBufferWriteBytes();
    fn_800320E8(0);
}

void TRKReadBuffer_ui32(void) {
    TRKAppendBuffer1_ui64();
    fn_80033404();
    fn_80032778();
    usr_puts_serial();
    fn_80031C68();
    fn_800322E4();
}

extern int lbl_8035BEA0[4];
int TRKReadBuffer_ui8(int index) { return lbl_8035BEA0[index]; }

void TRKReadBuffer1_ui64(void) {
    typedef struct TRKBuf {
        struct TRKBuf *next;
        u32 unk4;
        struct TRKBuf *queue_next;
        u32 active;
        void (*callback)(struct TRKBuf *);
    } TRKBuf;
    TRKBuf *buf = (TRKBuf *)lbl_8055D6E8;
    if (buf != 0) lbl_8055D6E8 = (u32)buf->queue_next;
    while (buf != 0) {
        if (buf->active != 0) {
            if (buf->callback != 0) buf->callback(buf);
            TRKReleaseBuffer(buf);
            buf->next = (TRKBuf *)lbl_8035BEA0;
            lbl_8035BEA0[0] = (s32)buf;
            buf->active = 0;
        }
        buf = (TRKBuf *)lbl_8055D6E8;
        if (buf != 0) lbl_8055D6E8 = (u32)buf->queue_next;
    }
}

void TRKAppendBuffer_ui32(void) {
    u32 *a = lbl_8035BF20;
    u32 *b = (u32 *)lbl_8035BEA0;
    s32 count = 2;
    lbl_8055D6E8 = 0;
    do {
        a[0]=0; b[0]=0; a[1]=0; b[1]=0;
        a[2]=0; b[2]=0; a[3]=0; b[3]=0;
        a[4]=0; b[4]=0; a[5]=0; b[5]=0;
        a[6]=0; b[6]=0; a[7]=0; b[7]=0;
        a[8]=0; b[8]=0; a[9]=0; b[9]=0;
        a[10]=0; b[10]=0; a[11]=0; b[11]=0;
        a[12]=0; b[12]=0; a[13]=0; b[13]=0;
        a[14]=0; b[14]=0; a[15]=0; a += 16; b[15]=0; b += 16;
    } while (--count);
}

void usr_puts_serial(void) {
    lbl_8055D728 = 0;
    lbl_8055D724 = 0;
    lbl_8055D720 = 0;
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

void fn_80031C94(unsigned short arg0) {
    lbl_8055D732 = arg0;
}

void fn_80031C9C(unsigned short arg0) {
    lbl_8055D730 = arg0;
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

u32 AIRegisterDMACallback(u32 value) {
    u32 old = lbl_8055D774;
    BOOL enabled = OSDisableInterrupts();
    lbl_8055D774 = value;
    OSRestoreInterrupts(enabled);
    return old;
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

extern u8 lbl_80363BE0[];
void *__AXGetStudio_800324C4(void) {
    return lbl_80363BE0;
}

