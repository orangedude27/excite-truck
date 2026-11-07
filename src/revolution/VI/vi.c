#include <revolution/GX.h>
#include <revolution/OS.h>
#include <revolution/SC.h>
#include <revolution/VI.h>
#include <revolution/VI/vi.h>
#include <revolution/VI/vihardware.h>
#include <revolution/IPC/ipcHardware.h>

#define __VIRegs VI_HW_REGS

extern u32 OS_BUS_CLOCK_SPEED;
extern s32 lbl_8055DBE8;
extern volatile u32 lbl_8055DB60;
extern volatile u32 lbl_8055DB70;
extern u32 lbl_8055DB98;
extern u32 lbl_8055DBC8;
extern u32 lbl_8055DBCC;
extern u32 CurrTvMode_8055DB9C;
extern u8 lbl_80311B50[0x570];
extern u32 lbl_80558FB8;
extern u8 lbl_80558FC0;
extern u8 lbl_80558FC1;
extern u8 lbl_80558FC2;
extern u8 lbl_80558FC3;
extern u8 lbl_80558FC4;
extern u8 lbl_80558FC5;
extern u8 lbl_80558FC6;
extern u8 lbl_80558FC7;
extern u8 lbl_80558FC8;
extern u8 lbl_80558FC9;
extern u8 lbl_80558FCA;
extern u8 lbl_80558FD0;
extern u32 lbl_8055DBF0;
extern u32 lbl_8055DBE4;
extern u32* jumptable_80311940[];
extern u8 lbl_80311738[];
extern u32 lbl_8055DB84;
extern u32 lbl_8055DBA4;

typedef struct {
    u8 bytes[2];
} __attribute__((packed)) u16_bytes;

typedef struct {
    u8 equ;
    u16 acv;
    u16 prbOdd;
    u16 prbEven;
    u16 psbOdd;
    u16 psbEven;
    u8 bs1;
    u8 bs2;
    u8 bs3;
    u8 bs4;
    u16 be1;
    u16 be2;
    u16 be3;
    u16 be4;
    u16 nhlines;
    u16 hlw;
    u8 hsy;
    u8 hcs;
    u8 hce;
    u8 hbe640;
    u16 hbs640;
    u8 hbeCCIR656;
    u16 hbsCCIR656;
} VITiming;

extern VITiming* lbl_8055DBA0;

typedef struct {
    u16 DispPosX;
    u16 DispPosY;
    u16 DispSizeX;
    u16 DispSizeY;
    u16 AdjustedDispPosX;
    u16 AdjustedDispPosY;
    u16 AdjustedDispSizeY;
    u16 AdjustedPanPosY;
    u16 AdjustedPanSizeY;
    u16 FBSizeX;
    u16 FBSizeY;
    u16 PanPosX;
    u16 PanPosY;
    u16 PanSizeX;
    u16 PanSizeY;
    VIXFBMode FBMode;
    u32 nonInter;
    u32 tv;
    u8 wordPerLine;
    u8 std;
    u8 wpl;
    u32 bufAddr;
    u32 tfbb;
    u32 bfbb;
    u8 xof;
    BOOL black;
    BOOL threeD;
    u32 rbufAddr;
    u32 rtfbb;
    u32 rbfbb;
    VITiming *timing;
    u8 unk_0x58[0x28];
} SomeVIStruct;

static volatile u32 retraceCount;
static u32 changeMode;
static volatile u32 flushFlag;
static struct OSThreadQueue retraceQueue;
static void (*PreCB)(u32);
static void (*PostCB)(u32);
static u32 encoderType;
static s16 displayOffsetH;
static s16 displayOffsetV;
static volatile u64 changed;
static u16 regs[59];
static volatile u64 shdwChanged;
static u16 shdwRegs[59];

#define MARK_CHANGED(index) (changed |= 1LL << (63 - (index)))

static VITiming timing[7] =
{
    { 6, 240, 24, 25, 3, 2, 12, 13, 12, 13, 520, 519, 520, 519, 525, 429, 64, 71, 105, 162, 373, 122, 412 },
    { 6, 240, 24, 24, 4, 4, 12, 12, 12, 12, 520, 520, 520, 520, 526, 429, 64, 71, 105, 162, 373, 122, 412 },
    { 5, 287, 35, 36, 1, 0, 13, 12, 11, 10, 619, 618, 617, 620, 625, 432, 64, 75, 106, 172, 380, 133, 420 },
    { 5, 287, 35, 35, 2, 2, 13, 11, 13, 11, 619, 621, 619, 621, 626, 432, 64, 75, 106, 172, 380, 133, 420 },
    { 6, 240, 24, 25, 3, 2, 16, 15, 14, 13, 518, 517, 516, 519, 525, 429, 64, 78, 112, 162, 373, 122, 412 },
    { 6, 240, 24, 24, 4, 4, 16, 14, 16, 14, 518, 520, 518, 520, 526, 429, 64, 78, 112, 162, 373, 122, 412 },
    { 12, 480, 44, 44, 10, 10, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 162, 373, 122, 412 },
};
static u16 taps[25] = {
    0x01F0, 0x01DC,
    0x01AE, 0x0174,
    0x0129, 0x00DB,
    0x008E, 0x0046,
    0x000C, 0x00E2,
    0x00CB, 0x00C0,
    0x00C4, 0x00CF,
    0x00DE, 0x00EC,
    0x00FC, 0x0008,
    0x000F, 0x0013,
    0x0013, 0x000F,
    0x000C, 0x0008,
    0x0001
};

static SomeVIStruct HorVer;
static u32 FBSet;

static u32 getCurrentFieldEvenOdd(void);
void fn_8005CC68(void);

static u32 getEncoderType(void)
{
    return 1;
}

static s32 cntlzd(u64 bit)
{
    u32 hi;
    u32 lo;
    s32 value;

    hi = bit >> 32;
    lo = bit & 0xFFFFFFFF;
    value = __cntlzw(hi);
    if (value < 32) {
        return value;
    }
    return __cntlzw(lo) + 32;
}

static int VISetRegs(void)
{
    s32 regIndex;

    if (changeMode != 1 || getCurrentFieldEvenOdd() != 0) {
        while (shdwChanged != 0) {
            regIndex = cntlzd(shdwChanged);
            __VIRegs[regIndex] = shdwRegs[regIndex];
            shdwChanged &= ~((u64)1 << (63 - regIndex));
        }
        changeMode = 0;
        return 1;
    }
    return 0;
}

static void __VIRetraceHandler(s16 unused, OSContext *context)
{
    OSContext exceptionContext;
    u16 reg;
    u32 inter;
#if DEBUG
    static u32 dbgCount;
#endif

    inter = 0;
    reg = __VIRegs[0x18];
    if (reg & 0x8000) {
        __VIRegs[0x18] = reg & ~0x8000;
        inter |= 1;
    }
    reg = __VIRegs[0x1A];
    if (reg & 0x8000) {
        __VIRegs[0x1A] = reg & ~0x8000;
        inter |= 2;
    }
    reg = __VIRegs[0x1C];
    if (reg & 0x8000) {
        __VIRegs[0x1C] = reg & ~0x8000;
        inter |= 4;
    }
    reg = __VIRegs[0x1E];
    if (reg & 0x8000) {
        __VIRegs[0x1E] = reg & ~0x8000;
        inter |= 8;
    }
    reg = __VIRegs[0x1E];
    if ((inter & 4) || (inter & 8)) {
        OSSetCurrentContext(context);
        return;
    }
    if (inter == 0) {
        ASSERTLINE(0x2BA, FALSE);
    }
    retraceCount += 1;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (PreCB) {
        PreCB(retraceCount);
    }
    if (flushFlag != 0) {
#if DEBUG
        dbgCount = 0;
#endif
        if (VISetRegs() != 0) {
            flushFlag = 0;
        }
    }
#if DEBUG
    else if (changed != 0) {
        dbgCount++;
        if (dbgCount > 60) {
            OSReport("Warning: VIFlush() was not called for 60 frames although VI settings were changed\n");
            dbgCount = 0;
        }
    }
#endif
    if (PostCB) {
        OSClearContext(&exceptionContext);
        PostCB(retraceCount);
    }
    OSWakeupThread(&retraceQueue);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback cb)
{
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = PreCB;
    enabled = OSDisableInterrupts();
    PreCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback cb)
{
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = PostCB;
    enabled = OSDisableInterrupts();
    PostCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

#pragma dont_inline on
static VITiming *getTiming(VITVMode mode)
{
    switch (mode) {
    case VI_TVMODE_NTSC_INT:  return &timing[0];
    case VI_TVMODE_NTSC_DS:   return &timing[1];
    case VI_TVMODE_PAL_INT:   return &timing[2];
    case VI_TVMODE_PAL_DS:    return &timing[3];
    case VI_TVMODE_MPAL_INT:  return &timing[4];
    case VI_TVMODE_MPAL_DS:   return &timing[5];
    case VI_TVMODE_NTSC_PROG: return &timing[6];
    default: return NULL;
    }
}
#pragma dont_inline reset

s32 fn_80058A00(s32 arg0, s32 arg1)
{
    if (arg0 == 0) {
        switch (arg1) {
        case 1:
        case 2:
        case 3:
            fn_8005CC68();
            return 1;
        case 0:
        case 4:
        case 5:
        case 6:
            return 1;
        }
    } else {
        return 1;
    }
    return arg0;
}

VIRetraceCallback fn_800591AC(VIRetraceCallback cb)
{
    extern VIRetraceCallback lbl_8055DBAC;
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = lbl_8055DBAC;
    enabled = OSDisableInterrupts();
    lbl_8055DBAC = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

VIRetraceCallback AIRegisterDMACallback_800591F0(VIRetraceCallback cb)
{
    extern VIRetraceCallback lbl_8055DBA8;
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = lbl_8055DBA8;
    enabled = OSDisableInterrupts();
    lbl_8055DBA8 = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

u32 fn_80059234(u32 index)
{
    switch (index) {
    case 0x0:
    case 0x14:
        return (u32)lbl_80311738;
    case 0x1:
    case 0x15:
        return (u32)lbl_80311738 + 0x26;
    case 0x2:
        return (u32)lbl_80311738 + 0x4C;
    case 0x3:
        return (u32)lbl_80311738 + 0x72;
    case 0x4:
        return (u32)lbl_80311738;
    case 0x5:
        return (u32)lbl_80311738 + 0x26;
    case 0x6:
        return (u32)lbl_80311738 + 0x98;
    case 0x7:
        return (u32)lbl_80311738 + 0xBE;
    case 0x8:
    case 0x16:
        return (u32)lbl_80311738 + 0xE4;
    case 0x9:
        return (u32)lbl_80311738 + 0x10A;
    case 0xA:
    case 0x10:
        return (u32)lbl_80311738 + 0x4C;
    case 0xB:
    case 0x11:
        return (u32)lbl_80311738 + 0x72;
    case 0xC:
        return (u32)lbl_80311738 + 0x130;
    case 0xD:
        return (u32)lbl_80311738 + 0x156;
    case 0xE:
        return lbl_8055DB84;
    case 0x1E:
    default:
        return 0;
    }
}

void __VIInit(VITVMode mode)
{
    VITiming *tm;
    u32 nonInter;
    s32 tv;
    volatile u32 a;

    nonInter = mode & 3;
    tv = (u32)mode >> 2;
    *(u32 *)0x800000CC = tv;
    tm = getTiming(mode);
    __VIRegs[1] = 2;
    for (a = 0; a < 1000; a++) {
    }
    __VIRegs[1] = 0;
    __VIRegs[3] = tm->hlw;
    __VIRegs[2] = tm->hce | (tm->hcs << 8);
    __VIRegs[5] = tm->hsy | ((tm->hbe640 & 0x1FF) << 7);
    __VIRegs[4] = (tm->hbe640 >> 9) | ((tm->hbs640 & 0xFFFF) << 1);
    if (lbl_8055DBA4 == 0) {
        __VIRegs[0x39] = tm->hbeCCIR656 | 0x8000;
        __VIRegs[0x3A] = tm->hbsCCIR656;
    }
    __VIRegs[0] = tm->equ;
    __VIRegs[7] = tm->prbOdd + tm->acv * 2 - 2;
    __VIRegs[6] = tm->psbOdd + 2;
    __VIRegs[9] = tm->prbEven + tm->acv * 2 - 2;
    __VIRegs[8] = tm->psbEven + 2;
    __VIRegs[11] = tm->bs1 | (tm->be1 << 5);
    __VIRegs[10] = tm->bs3 | (tm->be3 << 5);
    __VIRegs[13] = tm->bs2 | (tm->be2 << 5);
    __VIRegs[12] = tm->bs4 | (tm->be4 << 5);
    __VIRegs[36] = 0x2828;
    __VIRegs[27] = 1;
    __VIRegs[26] = 0x1001;
    __VIRegs[25] = tm->hlw + 1;
    __VIRegs[24] = (tm->nhlines / 2) + 1 | 0x1000;
    if (tv >= 4) {
        tv = 0;
    } else if (tv >= 1) {
        __VIRegs[1] = (tv << 8) | (nonInter << 2) | 1;
        __VIRegs[54] = 0;
    } else {
        __VIRegs[1] = (tv << 8) | (nonInter << 2) | 1;
        __VIRegs[54] = 0;
    }
    if (tv == 0) {
        __VIRegs[1] = (tv << 8) | 5;
        __VIRegs[54] = 1;
    }
}

void fn_8005954C(void)
{
    extern BOOL lbl_8055DB38;
    extern const char* lbl_80558F98;
    extern u16 lbl_803118DC[];
    extern VITVFormat lbl_8055DBD0;
    extern volatile u64 lbl_8055DB68;
    extern volatile u64 lbl_8055DB78;
    extern s16 lbl_8055DB5C, lbl_8055DB5E;
    extern SomeVIStruct lbl_8038F398;
    extern u16 lbl_8038F418[];
    extern OSThreadQueue lbl_8055DBB0;
    extern VIRetraceCallback lbl_8055DBAC, lbl_8055DBA8;
    extern OSShutdownFunctionInfo lbl_80311910;
    extern u32 lbl_8055DB48, lbl_8055DB4C, lbl_8055DB50, lbl_8055DB54, lbl_8055DB44;
    extern volatile u32 lbl_8055DBC4, lbl_8055DBC0;
    extern void fn_80058A60(s16, OSContext*);
    u16 dspCfg;
    u32 value;
    u32 tv;
    VITiming* tm;
    BOOL enabled;
    u32 bootTv;
    s32 coeff, frac;
    BOOL screenSaver;
    u16 acv;

    if (lbl_8055DB38) return;
    OSRegisterVersion(lbl_80558F98);
    lbl_8055DB38 = TRUE;
    if (!(__VIRegs[1] & 1)) __VIInit(VI_TVMODE_NTSC_INT);
    lbl_8055DBD0 = 0;
    lbl_8055DB68 = 0;
    lbl_8055DB78 = 0;
    lbl_8055DB60 = 0;
    lbl_8055DB70 = 0;
    lbl_8055DBCC = 0;
    lbl_8055DBC8 = 0;
    __VIRegs[39] = lbl_803118DC[0] | ((lbl_803118DC[1] & 0x3F) << 10);
    __VIRegs[38] = (lbl_803118DC[1] >> 6) | (lbl_803118DC[2] << 4);
    __VIRegs[41] = lbl_803118DC[3] | ((lbl_803118DC[4] & 0x3F) << 10);
    __VIRegs[40] = (lbl_803118DC[4] >> 6) | (lbl_803118DC[5] << 4);
    __VIRegs[43] = lbl_803118DC[6] | ((lbl_803118DC[7] & 0x3F) << 10);
    __VIRegs[42] = (lbl_803118DC[7] >> 6) | (lbl_803118DC[8] << 4);
    __VIRegs[45] = lbl_803118DC[9] | (lbl_803118DC[10] << 8);
    __VIRegs[44] = lbl_803118DC[11] | (lbl_803118DC[12] << 8);
    __VIRegs[47] = lbl_803118DC[13] | (lbl_803118DC[14] << 8);
    __VIRegs[46] = lbl_803118DC[15] | (lbl_803118DC[16] << 8);
    __VIRegs[49] = lbl_803118DC[17] | (lbl_803118DC[18] << 8);
    __VIRegs[48] = lbl_803118DC[19] | (lbl_803118DC[20] << 8);
    __VIRegs[51] = lbl_803118DC[21] | (lbl_803118DC[22] << 8);
    __VIRegs[50] = lbl_803118DC[23] | (lbl_803118DC[24] << 8);
    __VIRegs[56] = 0x280;
    lbl_8055DB5C = SCGetDisplayOffsetH();
    lbl_8055DB5E = 0;
    bootTv = *(u32*)0x800000CC;
    dspCfg = __VIRegs[1];
    enabled = OSDisableInterrupts();
    if (((u32)__VIRegs[54] & 1) == 1) value = 2;
    else value = !!((__VIRegs[1] >> 2) & 1);
    OSRestoreInterrupts(enabled);
    lbl_8038F398.nonInter = value;
    lbl_8038F398.tv = (dspCfg >> 8) & 3;
    if (bootTv == 5 || (bootTv == 1 && lbl_8038F398.tv == 0)) lbl_8038F398.tv = 5;
    tv = lbl_8038F398.tv == 3 ? 0 : lbl_8038F398.tv;
    tm = (VITiming*)fn_80059234((tv << 2) + lbl_8038F398.nonInter);
    lbl_8038F398.timing = tm;
    lbl_8055DBA0 = tm;
    lbl_8038F418[1] = dspCfg;
    CurrTvMode_8055DB9C = lbl_8038F398.tv;
    lbl_8038F398.DispSizeX = 640;
    lbl_8038F398.DispSizeY = tm->acv * 2;
    lbl_8038F398.DispPosX = (720 - lbl_8038F398.DispSizeX) / 2;
    lbl_8038F398.DispPosY = 0;
    acv = tm->acv;
    lbl_8038F398.AdjustedDispPosX = (s16)lbl_8038F398.DispPosX + lbl_8055DB5C > 720 - lbl_8038F398.DispSizeX
        ? 720 - lbl_8038F398.DispSizeX : (s16)lbl_8038F398.DispPosX + lbl_8055DB5C < 0
        ? 0 : (s16)lbl_8038F398.DispPosX + lbl_8055DB5C;
    coeff = lbl_8038F398.FBMode == VI_XFBMODE_SF ? 2 : 1;
    frac = lbl_8038F398.DispPosY & 1;
    lbl_8038F398.AdjustedDispPosY = MAX((s16)lbl_8038F398.DispPosY + lbl_8055DB5E, frac);
    lbl_8038F398.AdjustedDispSizeY = lbl_8038F398.DispSizeY
        + MIN((s16)lbl_8038F398.DispPosY + lbl_8055DB5E - frac, 0)
        - MAX((s16)lbl_8038F398.DispPosY + (s16)lbl_8038F398.DispSizeY + lbl_8055DB5E - (((s16)acv * 2) - frac), 0);
    lbl_8038F398.AdjustedPanPosY = lbl_8038F398.PanPosY
        - MIN((s16)lbl_8038F398.DispPosY + lbl_8055DB5E - frac, 0) / coeff;
    lbl_8038F398.AdjustedPanSizeY = lbl_8038F398.PanSizeY
        + MIN((s16)lbl_8038F398.DispPosY + lbl_8055DB5E - frac, 0) / coeff
        - MAX((s16)lbl_8038F398.DispPosY + (s16)lbl_8038F398.DispSizeY + lbl_8055DB5E - (((s16)acv * 2) - frac), 0) / coeff;
    lbl_8038F398.FBSizeX = 640;
    lbl_8038F398.FBSizeY = tm->acv * 2;
    lbl_8038F398.PanPosX = 0;
    lbl_8038F398.PanPosY = 0;
    lbl_8038F398.PanSizeX = 640;
    lbl_8038F398.PanSizeY = tm->acv * 2;
    lbl_8038F398.FBMode = 0;
    lbl_8038F398.wordPerLine = 40;
    lbl_8038F398.std = 40;
    lbl_8038F398.wpl = 40;
    lbl_8038F398.xof = 0;
    lbl_8038F398.black = 1;
    lbl_8038F398.threeD = 0;
    OSInitThreadQueue(&lbl_8055DBB0);
    value = __VIRegs[24];
    __VIRegs[24] = value & ~0x8000;
    value = __VIRegs[26];
    __VIRegs[26] = value & ~0x8000;
    lbl_8055DBAC = NULL;
    lbl_8055DBA8 = NULL;
    __OSSetInterruptHandler(0x18, fn_80058A60);
    __OSUnmaskInterrupts(0x80);
    OSRegisterShutdownFunction(&lbl_80311910);
    enabled = OSDisableInterrupts();
    tv = CurrTvMode_8055DB9C;
    switch (tv) {
    case 0: case 3: case 6: case 7:
        tv = 0;
        break;
    case 1: case 4:
        tv = 1;
        break;
    case 2: case 5:
        break;
    }
    OSRestoreInterrupts(enabled);
    if (tv == 1) {
        lbl_8055DB48 = 15000;
        lbl_8055DB4C = 90000;
    } else {
        lbl_8055DB48 = 18000;
        lbl_8055DB4C = 108000;
    }
    lbl_8055DB50 = 0;
    lbl_8055DB54 = 0;
    lbl_8055DB44 = 1;
    screenSaver = TRUE;
    (void)lbl_8055DBC4;
    if (SCGetScreenSaverMode() == 0) screenSaver = FALSE;
    lbl_8055DBC4 = screenSaver;
    (void)lbl_8055DBC0;
    lbl_8055DBC0 = 0;
    __VISetRevolutionModeSimple();
}

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef CLAMP
#define CLAMP(val, min, max) ((val) > (max) ? (max) : (val) < (min) ? (min) : (val))
#endif

static void AdjustPosition(u16 acv)
{
    s32 coeff;
    s32 frac;

    HorVer.AdjustedDispPosX = CLAMP((s16)HorVer.DispPosX + displayOffsetH, 0, 0x2D0 - HorVer.DispSizeX);
    coeff = (HorVer.FBMode == VI_XFBMODE_SF) ? 2 : 1;
    frac = HorVer.DispPosY & 1;
    HorVer.AdjustedDispPosY = MAX((s16)HorVer.DispPosY + displayOffsetV, frac);
    HorVer.AdjustedDispSizeY = HorVer.DispSizeY
                             + MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0)
                             - MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + displayOffsetV - (((s16)acv * 2) - frac), 0);
    HorVer.AdjustedPanPosY = HorVer.PanPosY
                           - (MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) / coeff);
    HorVer.AdjustedPanSizeY = HorVer.PanSizeY
                            + (MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) / coeff)
                            - (MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + displayOffsetV - (((s16)acv * 2) - frac), 0) / coeff);
}

static void ImportAdjustingValues(void)
{
    displayOffsetH = SCGetDisplayOffsetH();
    displayOffsetV = 0;
}

void VIInit(void)
{
    u16 dspCfg;
    u32 value;
    u32 tv;

    encoderType = getEncoderType();
    if (!(__VIRegs[1] & 1)) {
        __VIInit(VI_TVMODE_NTSC_INT);
    }
    retraceCount = 0;
    changed = 0;
    shdwChanged = 0;
    changeMode = 0;
    flushFlag = 0;
    __VIRegs[39] = taps[0] | ((taps[1] & 0x3F) << 10);
    __VIRegs[38] = (taps[1] >> 6) | (taps[2] << 4);
    __VIRegs[41] = taps[3] | ((taps[4] & 0x3F) << 10);
    __VIRegs[40] = (taps[4] >> 6) | (taps[5] << 4);
    __VIRegs[43] = taps[6] | ((taps[7] & 0x3F) << 10);
    __VIRegs[42] = (taps[7] >> 6) | (taps[8] << 4);
    __VIRegs[45] = taps[9] | (taps[10] << 8);
    __VIRegs[44] = taps[11] | (taps[12] << 8);
    __VIRegs[47] = taps[13] | (taps[14] << 8);
    __VIRegs[46] = taps[15] | (taps[16] << 8);
    __VIRegs[49] = taps[17] | (taps[18] << 8);
    __VIRegs[48] = taps[19] | (taps[20] << 8);
    __VIRegs[51] = taps[21] | (taps[22] << 8);
    __VIRegs[50] = taps[23] | (taps[24] << 8);
    __VIRegs[56] = 0x280;
    ImportAdjustingValues();
    HorVer.DispSizeX = 0x280U;
    HorVer.DispSizeY = 0x1E0U;
    HorVer.DispPosX = (0x2D0 - HorVer.DispSizeX) / 2;
    HorVer.DispPosY = (0x1E0 - HorVer.DispSizeY) / 2;
    AdjustPosition(0xF0U);
    HorVer.FBSizeX = 0x280;
    HorVer.FBSizeY = 0x1E0;
    HorVer.PanPosX = 0;
    HorVer.PanPosY = 0;
    HorVer.PanSizeX = 0x280;
    HorVer.PanSizeY = 0x1E0;
    HorVer.FBMode = 0;
    dspCfg = __VIRegs[1];
    HorVer.nonInter = (s32) ((dspCfg >> 2U) & 1);
    HorVer.tv = (u32) ((dspCfg >> 8U) & 3);
    tv = (HorVer.tv == 3) ? 0 : HorVer.tv;
    HorVer.timing = getTiming((tv << 2) + HorVer.nonInter);
    regs[1] = dspCfg;
    HorVer.wordPerLine = 0x28;
    HorVer.std = 0x28;
    HorVer.wpl = 0x28;
    HorVer.xof = 0;
    HorVer.black = 1;
    HorVer.threeD = 0;
    OSInitThreadQueue(&retraceQueue);
    value = __VIRegs[24];
    value &= ~0x8000;
#if !DEBUG
    value = (u16)value;
#endif
    __VIRegs[24] = value;
    value = __VIRegs[26];
    value = value & ~0x8000;
#if !DEBUG
    value = (u16)value;
#endif
    __VIRegs[26] = value;
    PreCB = NULL;
    PostCB = NULL;
    __OSSetInterruptHandler(0x18, __VIRetraceHandler);
    __OSUnmaskInterrupts(0x80);
}

void VIWaitForRetrace(void)
{
    BOOL enabled;
    u32 count;

    enabled = OSDisableInterrupts();
    count = retraceCount;
    do {
        OSSleepThread(&retraceQueue);
    } while (count == retraceCount);
    OSRestoreInterrupts(enabled);
}

static void calcFbbs(u32 bufAddr, u16 panPosX, u16 panPosY, u8 wordPerLine, VIXFBMode xfbMode, u16 dispPosY, u32 *tfbb, u32 *bfbb);
void fn_80059AD8(SomeVIStruct* HorVer, u32* tfbb, u32* bfbb, u32* rtfbb, u32* rbfbb) {
    u32 shifted;
    u16 *r;

    calcFbbs(HorVer->bufAddr, HorVer->PanPosX, HorVer->AdjustedPanPosY, HorVer->wordPerLine, HorVer->FBMode, HorVer->AdjustedDispPosY, tfbb, bfbb);
    if (HorVer->threeD) {
        calcFbbs(HorVer->rbufAddr, HorVer->PanPosX, HorVer->AdjustedPanPosY, HorVer->wordPerLine, HorVer->FBMode, HorVer->AdjustedDispPosY, rtfbb, rbfbb);
    }

    if (*tfbb < 0x01000000U && *bfbb < 0x01000000U && *rtfbb < 0x01000000U && *rbfbb < 0x01000000U) {
        shifted = 0;
    } else {
        shifted = 1;
    }
    if (shifted) {
        *tfbb >>= 5;
        *bfbb >>= 5;
        *rtfbb >>= 5;
        *rbfbb >>= 5;
    }

    r = regs;
    r[15] = (u16)*tfbb & 0xFFFF;
    MARK_CHANGED(15);
    r[14] = (shifted << 12) | ((*tfbb >> 16) | (HorVer->xof << 8));
    MARK_CHANGED(14);
    r[19] = (u16)*bfbb & 0xFFFF;
    MARK_CHANGED(19);
    r[18] = (*bfbb >> 16);
    MARK_CHANGED(18);
    if (HorVer->threeD) {
        r[17] = (u16)*rtfbb & 0xFFFF;
        MARK_CHANGED(17);
        r[16] = *rtfbb >> 16;
        MARK_CHANGED(16);
        r[21] = (u16)*rbfbb & 0xFFFF;
        MARK_CHANGED(21);
        r[20] = *rbfbb >> 16;
        MARK_CHANGED(20);
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80059D90(u16 dispPosY, u16 dispSizeY, u8 equ, u16 acv, u16 prbOdd, u16 prbEven, u16 psbOdd, u16 psbEven, int black)
{
    u16 actualPrbOdd;
    u16 actualPrbEven;
    u16 actualPsbOdd;
    u16 actualPsbEven;
    u16 c;
    u16 d;
    u16 reg0;

    if ((regs[54] & 1) != 0) {
        c = 1;
        d = 2;
    } else {
        c = 2;
        d = 1;
    }

    if ((dispPosY % 2) == 0) {
        actualPsbOdd = (u16)(psbOdd + (d * (((c * acv) - dispSizeY) - dispPosY)));
        actualPrbOdd = prbOdd + (d * dispPosY);
        actualPsbEven = psbEven + (d * (((c * acv) - dispSizeY) - dispPosY));
        actualPrbEven = prbEven + (d * dispPosY);
    } else {
        actualPsbOdd = (u16)(psbEven + (d * (((c * acv) - dispSizeY) - dispPosY)));
        actualPrbOdd = prbEven + (d * dispPosY);
        actualPrbEven = prbOdd + (d * dispPosY);
        actualPsbEven = psbOdd + (d * (((c * acv) - dispSizeY) - dispPosY));
    }

    psbEven = dispSizeY / c;

    if (black) {
        actualPsbOdd += 2;
        actualPrbOdd += (psbEven * 2) - 2;
        actualPsbEven += 2;
        actualPrbEven += (psbEven * 2) - 2;
        psbEven = 0;
    }

    reg0 = equ | (psbEven << 4);
    MARK_CHANGED(0);
    regs[7] = actualPrbOdd;
    MARK_CHANGED(7);
    regs[0] = reg0;
    MARK_CHANGED(6);
    regs[6] = actualPsbOdd;
    MARK_CHANGED(9);
    regs[9] = actualPrbEven;
    regs[8] = actualPsbEven;
    MARK_CHANGED(8);
}
#pragma pop
static void setInterruptRegs(VITiming *tm)
{
#if DEBUG
    u16 vct, hct;
#else
    u16 hct, vct;
#endif
    u16 borrow;

    vct = tm->nhlines / 2;
    borrow = tm->nhlines % 2;
    if (borrow != 0) {
        hct = tm->hlw;
    } else {
        hct = 0;
    }
    vct++;
    hct++;
    regs[25] = (u16)(u32)hct;
    MARK_CHANGED(25);
    regs[24] = vct | 0x1000;
    MARK_CHANGED(24);

    vct;
}

static void setPicConfig(u16 fbSizeX, VIXFBMode xfbMode, u16 panPosX, u16 panSizeX, u8 *wordPerLine, u8 *std, u8 *wpl, u8 *xof)
{
    *wordPerLine = (fbSizeX + 15) / 16;
    *std = (xfbMode == VI_XFBMODE_SF) ? *wordPerLine : (u8)(*wordPerLine * 2);
    *xof = panPosX % 16;
    *wpl = (*xof + panSizeX + 15) / 16;
    regs[0x24] = *std | (*wpl << 8);
    changed |= 0x8000000;
}

static void setBBIntervalRegs(VITiming *tm)
{
    u16 val;

    val = tm->bs1 | (tm->be1 << 5);
    regs[11] = val;
    changed |= 0x10000000000000;

    val = tm->bs3 | (tm->be3 << 5);
    regs[10] = val;
    changed |= 0x20000000000000;

    val = tm->bs2 | (tm->be2 << 5);
    regs[13] = val;
    changed |= 0x4000000000000;

    val = tm->bs4 | (tm->be4 << 5);
    regs[12] = val;
    changed |= (1LL << (63-12));
}

static void setScalingRegs(u16 panSizeX, u16 dispSizeX, BOOL threeD)
{
    u32 scale;

    panSizeX = threeD ? (panSizeX << 1) : panSizeX;
    if (panSizeX < dispSizeX) {
        scale = (u32)(dispSizeX + (panSizeX << 8) - 1) / dispSizeX;
        regs[37] = scale | 0x1000;
        changed |= 0x04000000;
        regs[56] = (u32)panSizeX;
        changed |= 0x80;
    } else {
        regs[37] = 0x100;
        changed |= 0x04000000;
    }
}

static void calcFbbs(u32 bufAddr, u16 panPosX, u16 panPosY, u8 wordPerLine, VIXFBMode xfbMode, u16 dispPosY, u32 *tfbb, u32 *bfbb)
{
    u32 bytesPerLine;
    u32 xoffInWords;
    u32 tmp;

    xoffInWords = (panPosX & ~0xF) >> 4;
    bytesPerLine = (wordPerLine & 0xFF) << 5;
    *tfbb = bufAddr + (xoffInWords << 5) + (bytesPerLine * panPosY);
    *bfbb = (xfbMode == VI_XFBMODE_SF) ? *tfbb : *tfbb + bytesPerLine;
    if (dispPosY % 2 == 1) {
        tmp = *tfbb;
        *tfbb = *bfbb;
        *bfbb = tmp;
    }
    *tfbb &= 0x3FFFFFFF;
    *bfbb &= 0x3FFFFFFF;
}

static void setFbbRegs(SomeVIStruct *HorVer, u32 *tfbb, u32 *bfbb, u32 *rtfbb, u32 *rbfbb)
{
    u32 shifted;

    calcFbbs(HorVer->bufAddr, HorVer->PanPosX, HorVer->AdjustedPanPosY, HorVer->wordPerLine, HorVer->FBMode, HorVer->AdjustedDispPosY, tfbb, bfbb);
    if (HorVer->threeD) {
        calcFbbs(HorVer->rbufAddr, HorVer->PanPosX, HorVer->AdjustedPanPosY, HorVer->wordPerLine, HorVer->FBMode, HorVer->AdjustedDispPosY, rtfbb, rbfbb);
    }
    if (*tfbb < 0x01000000U && *bfbb < 0x01000000U && *rtfbb < 0x01000000U && *rbfbb < 0x01000000U) {
        shifted = 0;
    } else {
        shifted = 1;
    }
    if (shifted) {
        *tfbb >>= 5;
        *bfbb >>= 5;
        *rtfbb >>= 5;
        *rbfbb >>= 5;
    }

    regs[15] = (u16)*tfbb & 0xFFFF;
    MARK_CHANGED(15);
    regs[14] = (shifted << 12) | ((*tfbb >> 16) | (HorVer->xof << 8));
    MARK_CHANGED(14);
    regs[19] = (u16)*bfbb & 0xFFFF;
    MARK_CHANGED(19);
    regs[18] = (*bfbb >> 16);
    MARK_CHANGED(18);
    if (HorVer->threeD) {
        regs[17] = (u16)*rtfbb & 0xFFFF;
        MARK_CHANGED(17);
        regs[16] = *rtfbb >> 16;
        MARK_CHANGED(16);
        regs[21] = (u16)*rbfbb & 0xFFFF;
        MARK_CHANGED(21);
        regs[20] = *rbfbb >> 16;
        MARK_CHANGED(20);
    }
}

static void setHorizontalRegs(VITiming *tm, u16 dispPosX, u16 dispSizeX)
{
    u32 hbe;
    u32 hbs;
    u32 hbeLo;
    u32 hbeHi;

    regs[3] = (u16)(u32)tm->hlw;
    MARK_CHANGED(3);
    regs[2] = tm->hce | (tm->hcs << 8);
    MARK_CHANGED(2);
    hbe = tm->hbe640 - 40 + dispPosX;
    hbs = tm->hbs640 + 40 + dispPosX - (720 - dispSizeX);
    hbeLo = hbe & 0x1FF;
    hbeHi = hbe >> 9;
    regs[5] = tm->hsy | (hbeLo << 7);
    MARK_CHANGED(5);
    regs[4] = hbeHi | (hbs * 2);
    MARK_CHANGED(4);
}

static void setVerticalRegs(u16 dispPosY, u16 dispSizeY, u8 equ, u16 acv, u16 prbOdd, u16 prbEven, u16 psbOdd, u16 psbEven, int black)
{
    u16 actualPrbOdd;
    u16 actualPrbEven;
    u16 actualPsbOdd;
    u16 actualPsbEven;
    u16 actualAcv;
    u16 c;
    u16 d;

    if (equ >= 10) {
        c = 1;
        d = 2;
    } else {
        c = 2;
        d = 1;
    }
    if ((dispPosY % 2) == 0) {
        actualPrbOdd = prbOdd + (d * dispPosY);
        actualPsbOdd = psbOdd + (d * (((c * acv) - dispSizeY) - dispPosY));
        actualPrbEven = prbEven + (d * dispPosY);
        actualPsbEven = psbEven + (d * (((c * acv) - dispSizeY) - dispPosY));
    } else {
        actualPrbOdd = prbEven + (d * dispPosY);
        actualPsbOdd = psbEven + (d * (((c * acv) - dispSizeY) - dispPosY));
        actualPrbEven = prbOdd + (d * dispPosY);
        actualPsbEven = psbOdd + (d * (((c * acv) - dispSizeY) - dispPosY));
    }
    actualAcv = dispSizeY / c;
    if (black) {
        actualPrbOdd += dispSizeY - 2;
        actualPsbOdd += 2;
        actualPrbEven += dispSizeY - 2;
        actualPsbEven += 2;
        actualAcv = 0;
    }
    regs[0] = equ | (actualAcv << 4);
    MARK_CHANGED(0);
    regs[7] = (u16)(u32)actualPrbOdd;
    MARK_CHANGED(7);
    regs[6] = (u16)(u32)actualPsbOdd;
    MARK_CHANGED(6);
    regs[9] = (u16)(u32)actualPrbEven;
    MARK_CHANGED(9);
    regs[8] = (u16)(u32)actualPsbEven;
    MARK_CHANGED(8);
}

void VIConfigure(const GXRenderModeObj *rm)
{
    VITiming *tm;
    u32 reg;
    int enabled;
    u32 newNonInter;
    u32 tvInBootrom;
    u32 tvInGame;

    ASSERTMSGLINEV(0x601, (rm->viHeight & 1) == 0,
        "VIConfigure(): Odd number(%d) is specified to viHeight\n",
        rm->viHeight);

    if (rm->xfbMode == VI_XFBMODE_DF || rm->tvInfo == VI_TVMODE_NTSC_PROG) {
        ASSERTMSGLINEV(0x607, rm->xfbHeight == rm->viHeight,
            "VIConfigure(): xfbHeight(%d) is not equal to viHeight(%d) when DF XFB mode or progressive mode is specified\n",
            rm->xfbHeight, rm->viHeight);
    }
    if (rm->xfbMode == VI_XFBMODE_SF && rm->tvInfo != VI_TVMODE_NTSC_PROG) {
        ASSERTMSGLINEV(0x60E, rm->viHeight == rm->xfbHeight * 2,
            "VIConfigure(): xfbHeight(%d) is not as twice as viHeight(%d) when SF XFB mode is specified\n",
            rm->xfbHeight, rm->viHeight);
    }

    enabled = OSDisableInterrupts();
    if (rm->tvInfo == VI_TVMODE_NTSC_PROG) {
        HorVer.nonInter = 2;
    } else {
        newNonInter = rm->tvInfo & 1;
        if (HorVer.nonInter != newNonInter) {
            changeMode = 1;
        }
        HorVer.nonInter = newNonInter;
    }

    tvInBootrom = VIGetTvFormat();
    tvInGame = (u32)rm->tvInfo >> 2;
    ASSERTMSGLINEV(0x635, tvInBootrom == tvInGame || (tvInBootrom == 2 && tvInGame == 0) || (tvInBootrom == 0 && tvInGame == 2),
        "Doesn't match TV format: TV format in bootrom is %d but TV format specified in the game is %d (0:NTSC, 1:PAL, 2:MPAL)\n"
        /* BUG: forgot to pass in additional parameters! */);

    HorVer.tv        = tvInBootrom;
    HorVer.DispPosX  = rm->viXOrigin;
    HorVer.DispPosY  = (HorVer.nonInter == 1) ? (u16)(rm->viYOrigin * 2) : rm->viYOrigin;
    HorVer.DispSizeX = rm->viWidth;
    HorVer.FBSizeX   = rm->fbWidth;
    HorVer.FBSizeY   = rm->xfbHeight;
    HorVer.FBMode    = rm->xfbMode;
    HorVer.PanSizeX  = HorVer.FBSizeX;
    HorVer.PanSizeY  = HorVer.FBSizeY;
    HorVer.PanPosX   = 0;
    HorVer.PanPosY   = 0;
    HorVer.DispSizeY = (HorVer.nonInter == 2) ? HorVer.PanSizeY
                     : (HorVer.FBMode == VI_XFBMODE_SF) ? (u16)(HorVer.PanSizeY * 2)
                     : HorVer.PanSizeY;
    tm = getTiming(rm->tvInfo);
    HorVer.timing = tm;
    AdjustPosition(tm->acv);
    ASSERTMSGLINEV(0x654, rm->viXOrigin <= tm->hlw + 40 - tm->hbe640,
        "VIConfigure(): viXOrigin(%d) cannot be greater than %d in this TV mode\n",
        rm->viXOrigin, tm->hlw + 40 - tm->hbe640);
    ASSERTMSGLINEV(0x659,  rm->viXOrigin + rm->viWidth >= 0x2A8 - tm->hbs640,
        "VIConfigure(): viXOrigin + viWidth (%d) cannot be less than %d in this TV mode\n",
        rm->viXOrigin + rm->viWidth, 0x2A8 - tm->hbs640);

    if (encoderType == 0) {
        HorVer.tv = 3;
    }
    setInterruptRegs(tm);
    reg = regs[1];
    SET_REG_FIELD(0x66A, reg, 1, 2, (HorVer.nonInter & 1));
    SET_REG_FIELD(0x66B, reg, 2, 8, HorVer.tv);
    regs[1] = reg;
    MARK_CHANGED(1);
    setScalingRegs(HorVer.PanSizeX, HorVer.DispSizeX, HorVer.threeD);
    setHorizontalRegs(tm, HorVer.AdjustedDispPosX, HorVer.DispSizeX);
    setBBIntervalRegs(tm);
    setPicConfig(HorVer.FBSizeX, HorVer.FBMode, HorVer.PanPosX, HorVer.PanSizeX, &HorVer.wordPerLine, &HorVer.std, &HorVer.wpl, &HorVer.xof);
    if (FBSet != 0) {
        setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    }
    setVerticalRegs(HorVer.AdjustedDispPosY, HorVer.AdjustedDispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

void VIConfigurePan(u16 xOrg, u16 yOrg, u16 width, u16 height)
{
    BOOL enabled;
    VITiming *tm;
#if DEBUG
    ASSERTMSGLINEV(0x69C, (xOrg & 1) == 0, "VIConfigurePan(): Odd number(%d) is specified to xOrg\n", xOrg);
    if (HorVer.FBMode == VI_XFBMODE_DF) {
        ASSERTMSGLINEV(0x6A1, (height & 1) == 0, "VIConfigurePan(): Odd number(%d) is specified to height when DF XFB mode\n", height);
    }
#endif
    enabled = OSDisableInterrupts();
    HorVer.PanPosX = xOrg;
    HorVer.PanPosY = yOrg;
    HorVer.PanSizeX = width;
    HorVer.PanSizeY = height;
    if (HorVer.FBMode != 2 && HorVer.FBMode != 3 && HorVer.nonInter == 0) {
        HorVer.DispSizeY = HorVer.PanSizeY * 2;
    } else {
        HorVer.DispSizeY = HorVer.PanSizeY;
    }
    tm = HorVer.timing;
    AdjustPosition(tm->acv);
    setScalingRegs(HorVer.PanSizeX, HorVer.DispSizeX, HorVer.threeD);
    setPicConfig(HorVer.FBSizeX, HorVer.FBMode, HorVer.PanPosX, HorVer.PanSizeX, &HorVer.wordPerLine, &HorVer.std, &HorVer.wpl, &HorVer.xof);
    if (FBSet != 0) setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    setVerticalRegs(HorVer.AdjustedDispPosY, HorVer.DispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

void VIFlush(void)
{
    BOOL enabled;
    s32 regIndex;

    enabled = OSDisableInterrupts();
    lbl_8055DB70 |= lbl_8055DB60;
    lbl_8055DB60 = 0;
    shdwChanged |= changed;
    while (changed != 0) {
        regIndex = cntlzd(changed);
        shdwRegs[regIndex] = regs[regIndex];
        changed &= ~((u64)1 << (63 - regIndex));
    }
    lbl_8055DBCC = 1;
    lbl_8055DBC8 = 1;
    lbl_8055DB98 = HorVer.bufAddr;
    OSRestoreInterrupts(enabled);
}

void VISetNextFrameBuffer(void *fb)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    HorVer.bufAddr = (u32)fb;
    FBSet = 1;
    setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    OSRestoreInterrupts(enabled);
}

VITVFormat fn_8005AB88(void) {
    extern VITVFormat lbl_8055DB94;
    return lbl_8055DB94;
}

void VISetNextRightFrameBuffer(void *fb)
{
    BOOL enabled;

    ASSERTMSGLINEV(0x71F, ((u32)fb & 0x1F) == 0,
        "VISetNextFrameBuffer(): Frame buffer address(0x%08x) is not 32byte aligned\n",
        fb);
    enabled = OSDisableInterrupts();
    HorVer.rbufAddr = (u32)fb;
    FBSet = 1;
    setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    OSRestoreInterrupts(enabled);
}

void VISetBlack(BOOL black)
{
    BOOL enabled;
    VITiming *tm;

    enabled = OSDisableInterrupts();
    HorVer.black = black;
    tm = HorVer.timing;
    setVerticalRegs(HorVer.AdjustedDispPosY, HorVer.DispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

VITVFormat fn_8005AC08(void) {
    extern VITVFormat lbl_8055DBD0;
    return lbl_8055DBD0;
}

void VISet3D(BOOL threeD)
{
    BOOL enabled;
    u32 reg;

    enabled = OSDisableInterrupts();
    HorVer.threeD = threeD;
    reg = regs[1];
    SET_REG_FIELD(0x766, reg, 1, 3, HorVer.threeD);
    regs[1] = reg;
    MARK_CHANGED(1);
    setScalingRegs(HorVer.PanSizeX, HorVer.DispSizeX, HorVer.threeD);
    OSRestoreInterrupts(enabled);
}

s32 VIGetRetraceCount(void)
{
    return retraceCount;
}

static u32 getCurrentHalfLine(void)
{
    u32 vcount;
    u32 hcount;
    u32 vcount0;
    VITiming *tm;

    vcount = __VIRegs[22] & 0x7FF;
    do {
        vcount0 = vcount;
        hcount = __VIRegs[23] & 0x7FF;
        vcount = __VIRegs[22] & 0x7FF;
    } while (vcount0 != vcount);
    tm = lbl_8055DBA0;
    return ((vcount - 1) * 2) + ((hcount - 1) / tm->hlw);
}

static u32 getCurrentFieldEvenOdd(void)
{
    u16 value;
    u32 nin;
    u32 fmt;
    VITVMode tvMode;
    u32 nhlines;
    VITiming *tm;

    if (__VIRegs[54] & 1) {
        tm = getTiming(VI_TVMODE_NTSC_PROG);
    } else {
        value = __VIRegs[1];
        nin = ((value >> 2U) & 1);
        fmt = ((value >> 8U) & 3);
        tvMode = (fmt << 2) + nin;
        tm = getTiming(tvMode);
    }
    nhlines = tm->nhlines;
    if (getCurrentHalfLine() < nhlines) {
        return 1U;
    }
    return 0U;
}

u32 VIGetNextField(void)
{
    extern SomeVIStruct lbl_8038F398;
    u32 vcount;
    u32 hcount;
    u32 vcount0;
    VITiming *tm;
    u32 halfLine;
    u32 nextField;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    vcount = __VIRegs[22] & 0x7FF;
    do {
        vcount0 = vcount;
        hcount = __VIRegs[23] & 0x7FF;
        vcount = __VIRegs[22] & 0x7FF;
    } while (vcount0 != vcount);
    tm = lbl_8055DBA0;
    halfLine = ((vcount - 1) * 2) + ((hcount - 1) / tm->hlw);
    nextField = halfLine < tm->nhlines;
    OSRestoreInterrupts(enabled);
    return (nextField ^ 1) ^ (lbl_8038F398.AdjustedDispPosY & 1);
}

u32 VIGetCurrentLine(void)
{
    u32 halfLine;
    VITiming *tm;
    BOOL enabled;

    tm = lbl_8055DBA0;
    enabled = OSDisableInterrupts();
    halfLine = getCurrentHalfLine();
    OSRestoreInterrupts(enabled);
    if (halfLine >= tm->nhlines) {
        halfLine -= tm->nhlines;
    }
    return halfLine >> 1U;
}

VITVFormat VIGetTvFormat(void)
{
    BOOL enabled;
    u32 format;

    enabled = OSDisableInterrupts();
    format = CurrTvMode_8055DB9C;
    switch (format) {
    case 0:
    case 3:
    case 6:
    case 7:
        format = 0;
        break;
    case 1:
    case 4:
        format = 1;
        break;
    case 2:
    case 5:
        break;
    }
    OSRestoreInterrupts(enabled);
    return format;
}

u32 fn_8005AD9C(void)
{
    BOOL enabled;
    u32 status;

    enabled = OSDisableInterrupts();
    status = __VIRegs[VI_VISEL] & 3;
    OSRestoreInterrupts(enabled);
    return status & VI_VISEL_COMPONENT;
}

void __VIDisplayPositionToXY(u16 param_1, u16 param_2, s16 *param_3, u16 *param_4)
{
    extern SomeVIStruct lbl_8038F398;
    VITiming *timing = lbl_8055DBA0;
    u32 tv = lbl_8038F398.tv;
    u32 nhlines = timing->nhlines;
    u32 index = ((u32)(param_1 - 1)) / timing->hlw + ((u32)(param_2 - 1)) * 2;

    if (tv == 0) {
        if (index < nhlines) {
            u8 equ = timing->equ;
            u16 prbOdd = timing->prbOdd;
            u16 psbOdd = timing->psbOdd;
            u32 maxOdd = prbOdd + (u32)equ * 3;
            if (index >= maxOdd) {
                param_3[0] = -1;
            } else if (index < nhlines - psbOdd) {
                param_3[0] = -1;
            } else {
                u32 tmp = index;
                tmp = tmp - (u32)equ * 3;
                tmp = tmp - prbOdd;
                param_3[0] = (s16)(tmp >> 1);
            }
        } else {
            u8 equ = timing->equ;
            u16 prbEven = timing->prbEven;
            u16 psbEven = timing->psbEven;
            u32 diff = nhlines - index;
            u32 maxEven = prbEven + (u32)equ * 3;
            if (diff < maxEven) {
                param_3[0] = -1;
            } else if (diff < nhlines - psbEven) {
                param_3[0] = -1;
            } else {
                u32 tmp = diff;
                tmp = tmp - (u32)equ * 3;
                tmp = tmp - prbEven;
                param_3[0] = (s16)((tmp >> 1) + 1);
            }
        }
    } else if (tv == 1) {
        u8 equ = timing->equ;
        u16 prbOdd = timing->prbOdd;
        u16 psbOdd = timing->psbOdd;
        u32 diff = nhlines - index;
        u32 maxOdd = prbOdd + (u32)equ * 3;
        if (diff >= maxOdd) {
            param_3[0] = -1;
        } else if (diff < nhlines - psbOdd) {
            param_3[0] = -1;
        } else {
            u32 tmp = diff;
            tmp = tmp - (u32)equ * 3;
            tmp = tmp - prbOdd;
            param_3[0] = (s16)(tmp >> 1);
        }
    } else if (tv == 2) {
        if (index >= nhlines) {
            u8 equ = timing->equ;
            u16 prbEven = timing->prbEven;
            u16 psbEven = timing->psbEven;
            u32 diff = index - nhlines;
            u32 maxEven = prbEven + (u32)equ * 3;
            if (diff < maxEven) {
                param_3[0] = -1;
            } else if (diff < nhlines - psbEven) {
                param_3[0] = -1;
            } else {
                u32 tmp = diff;
                tmp = tmp - (u32)equ * 3;
                tmp = tmp - prbEven;
                param_3[0] = (s16)(tmp >> 1);
            }
        } else {
            u8 equ = timing->equ;
            u16 prbOdd = timing->prbOdd;
            u16 psbOdd = timing->psbOdd;
            u32 maxOdd = prbOdd + (u32)equ * 3;
            if (index >= maxOdd) {
                param_3[0] = -1;
            } else if (index < nhlines - psbOdd) {
                param_3[0] = -1;
            } else {
                u32 tmp = index;
                tmp = tmp - (u32)equ * 3;
                tmp = tmp - prbOdd;
                param_3[0] = (s16)(tmp >> 1);
            }
        }
    } else {
        param_3[0] = 0;
    }
    param_4[0] = param_1 - 1;
}

s32 fn_8005B00C(void) {
    extern s32 lbl_8055DBBC;
    lbl_8055DBBC = 0;
    return 1;
}

s32 fn_8005B01C(void) {
    extern s32 lbl_8055DBB8;
    lbl_8055DBB8 = 0;
    return 1;
}

void WaitMicroTime(s32 time) DECOMP_DONT_INLINE
{
    OSTime start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < time) {
    }
}

u32 sendSlaveAddr(u32 addr)
{
    u32 gpio_out;
    OSTime start;
    s32 i;

    if (lbl_80558FB8 == 0) {
        gpio_out = IPC_HW_REGS[IPC_GPIO1BOUT] & ~0x8000;
        IPC_HW_REGS[IPC_GPIO1BOUT] = gpio_out | 0x8000;
    } else {
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x8000;
    }
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x4000;
    for (i = 0; i < 8; i++) {
        if (addr & 0x80) {
            if (lbl_80558FB8 == 0)
                IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x8000;
            else
                IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~0x8000) | 0x8000;
        } else {
            if (lbl_80558FB8 == 0)
                IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~0x8000) | 0x8000;
            else
                IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x8000;
        }
        start = __OSGetSystemTime();
        while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~0x4000) | 0x4000;
        start = __OSGetSystemTime();
        while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x4000;
        addr = (u8)(addr << 1);
    }
    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~0x8000) | 0x4000;
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~0x4000) | 0x4000;
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    if (lbl_80558FB8 == 1 && ((IPC_HW_REGS[IPC_GPIO1BIN] >> 15) & 1))
        return 0;
    if (*(volatile u32 *)&lbl_80558FB8 == 0)
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~0x8000) | 0x8000;
    else
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x8000;
    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~0x8000) | 0xC000;
    IPC_HW_REGS[IPC_GPIO1BOUT] &= ~0x4000;
    return 1;
}

void __VISetYUVSEL(u8 value)
{
    u8 data[2];

    switch ((s32)OS_TV_FORMAT) {
    case 1:
    case 5:
        lbl_8055DBF0 = 2;
        break;
    case 2:
        lbl_8055DBF0 = 1;
        break;
    case 0:
        lbl_8055DBF0 = 0;
        break;
    default:
        lbl_8055DBF0 = 0;
        break;
    }
    data[0] = 1;
    data[1] = (value << 5) | lbl_8055DBF0;
    __VISendI2CData(0xE0, data, 2);
    WaitMicroTime(2);
}

void fn_8005BAEC(u8 value)
{
    u8 data[2];

    data[0] = 0x6E;
    data[1] = value;
    __VISendI2CData(0xE0, data, 2);
    WaitMicroTime(2);
}

void __VISetCGMS(void)
{
    u8 data[3];

    data[0] = 5;
    data[1] = ((lbl_80558FC1 & 0xF) << 2) | (lbl_80558FC0 & 3);
    data[2] = lbl_80558FC2;
    __VISendI2CData(0xE0, data, 3);
    WaitMicroTime(2);
}

void __VISetWSS(void)
{
    u8 data[3];

    data[0] = 8;
    data[1] = ((lbl_80558FC4 & 0xF) << 4) | (lbl_80558FC3 & 0xF);
    data[2] = ((lbl_80558FC6 & 7) << 3) | (lbl_80558FC5 & 7);
    __VISendI2CData(0xE0, data, 3);
    WaitMicroTime(2);
}

void __VISetClosedCaption(void)
{
    u8 data[5];

    data[0] = 0x7A;
    data[1] = lbl_80558FC7 & 0x7F;
    data[2] = lbl_80558FC8 & 0x7F;
    data[3] = lbl_80558FC9 & 0x7F;
    data[4] = lbl_80558FCA & 0x7F;
    __VISendI2CData(0xE0, data, 5);
    WaitMicroTime(2);
}

extern s32 lbl_8055DBEC;
extern s32 lbl_80558FCC;
extern u8 lbl_8038F490[];
void __VISetMacrovision(void) {
    u8 *base = (u8*)lbl_80311B50;
    volatile u8 payload0[0x1B];
    volatile u8 payload1[0x1B];
    volatile u8 payload2[0x1B];
    volatile u8 payload3[0x1B];
    volatile u8 payload4[0x1B];
    volatile u8 payload5[0x1B];
    volatile u8 payload6[0x1B];
    volatile u8 payload7[0x1B];
    volatile u8 payload8[0x1B];
    volatile u8 payload9[0x1B];
    volatile u8 payload10[0x1B];
    volatile u8 payload11[0x1B];
    volatile u8 payload12[0x1B];
    switch ((s32)lbl_8055DBEC) {
    case 2:
        switch ((s32)lbl_80558FCC) {
        case 0: {
            volatile u8 *src = (volatile u8 *)(base + 0x420);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload0[1] = t0;
            t0 = src[8];
            payload0[2] = t1;
            t1 = src[9];
            payload0[3] = t2;
            t2 = src[10];
            payload0[4] = t3;
            t3 = src[11];
            payload0[5] = t4;
            t4 = src[12];
            payload0[6] = t5;
            t5 = src[13];
            payload0[7] = t6;
            t6 = src[14];
            payload0[8] = t7;
            t7 = src[15];
            payload0[9] = t0;
            t0 = src[16];
            payload0[10] = t1;
            t1 = src[17];
            payload0[11] = t2;
            t2 = src[18];
            payload0[12] = t3;
            t3 = src[19];
            payload0[13] = t4;
            t4 = src[20];
            payload0[14] = t5;
            t5 = src[21];
            payload0[15] = t6;
            t6 = src[22];
            payload0[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload0[0] = 0x40;
            payload0[17] = t0;
            payload0[18] = t1;
            payload0[19] = t2;
            payload0[20] = t3;
            payload0[21] = t4;
            payload0[22] = t5;
            payload0[23] = t6;
            payload0[24] = t7;
            payload0[25] = t8;
            payload0[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload0, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 1: {
            volatile u8 *src = (volatile u8 *)(base + 0x474);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload1[1] = t0;
            t0 = src[8];
            payload1[2] = t1;
            t1 = src[9];
            payload1[3] = t2;
            t2 = src[10];
            payload1[4] = t3;
            t3 = src[11];
            payload1[5] = t4;
            t4 = src[12];
            payload1[6] = t5;
            t5 = src[13];
            payload1[7] = t6;
            t6 = src[14];
            payload1[8] = t7;
            t7 = src[15];
            payload1[9] = t0;
            t0 = src[16];
            payload1[10] = t1;
            t1 = src[17];
            payload1[11] = t2;
            t2 = src[18];
            payload1[12] = t3;
            t3 = src[19];
            payload1[13] = t4;
            t4 = src[20];
            payload1[14] = t5;
            t5 = src[21];
            payload1[15] = t6;
            t6 = src[22];
            payload1[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload1[0] = 0x40;
            payload1[17] = t0;
            payload1[18] = t1;
            payload1[19] = t2;
            payload1[20] = t3;
            payload1[21] = t4;
            payload1[22] = t5;
            payload1[23] = t6;
            payload1[24] = t7;
            payload1[25] = t8;
            payload1[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload1, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 2: {
            volatile u8 *src = (volatile u8 *)(base + 0x51C);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload2[1] = t0;
            t0 = src[8];
            payload2[2] = t1;
            t1 = src[9];
            payload2[3] = t2;
            t2 = src[10];
            payload2[4] = t3;
            t3 = src[11];
            payload2[5] = t4;
            t4 = src[12];
            payload2[6] = t5;
            t5 = src[13];
            payload2[7] = t6;
            t6 = src[14];
            payload2[8] = t7;
            t7 = src[15];
            payload2[9] = t0;
            t0 = src[16];
            payload2[10] = t1;
            t1 = src[17];
            payload2[11] = t2;
            t2 = src[18];
            payload2[12] = t3;
            t3 = src[19];
            payload2[13] = t4;
            t4 = src[20];
            payload2[14] = t5;
            t5 = src[21];
            payload2[15] = t6;
            t6 = src[22];
            payload2[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload2[0] = 0x40;
            payload2[17] = t0;
            payload2[18] = t1;
            payload2[19] = t2;
            payload2[20] = t3;
            payload2[21] = t4;
            payload2[22] = t5;
            payload2[23] = t6;
            payload2[24] = t7;
            payload2[25] = t8;
            payload2[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload2, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 5: {
            volatile u8 *src = (volatile u8 *)(base + 0x4C8);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload3[1] = t0;
            t0 = src[8];
            payload3[2] = t1;
            t1 = src[9];
            payload3[3] = t2;
            t2 = src[10];
            payload3[4] = t3;
            t3 = src[11];
            payload3[5] = t4;
            t4 = src[12];
            payload3[6] = t5;
            t5 = src[13];
            payload3[7] = t6;
            t6 = src[14];
            payload3[8] = t7;
            t7 = src[15];
            payload3[9] = t0;
            t0 = src[16];
            payload3[10] = t1;
            t1 = src[17];
            payload3[11] = t2;
            t2 = src[18];
            payload3[12] = t3;
            t3 = src[19];
            payload3[13] = t4;
            t4 = src[20];
            payload3[14] = t5;
            t5 = src[21];
            payload3[15] = t6;
            t6 = src[22];
            payload3[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload3[0] = 0x40;
            payload3[17] = t0;
            payload3[18] = t1;
            payload3[19] = t2;
            payload3[20] = t3;
            payload3[21] = t4;
            payload3[22] = t5;
            payload3[23] = t6;
            payload3[24] = t7;
            payload3[25] = t8;
            payload3[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload3, 0x1B);
            WaitMicroTime(2);
            return;
        }
        default:
            return;
        }
    case 3:
        switch ((s32)lbl_80558FCC) {
        case 0: {
            volatile u8 *src = (volatile u8 *)(base + 0x43C);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload4[1] = t0;
            t0 = src[8];
            payload4[2] = t1;
            t1 = src[9];
            payload4[3] = t2;
            t2 = src[10];
            payload4[4] = t3;
            t3 = src[11];
            payload4[5] = t4;
            t4 = src[12];
            payload4[6] = t5;
            t5 = src[13];
            payload4[7] = t6;
            t6 = src[14];
            payload4[8] = t7;
            t7 = src[15];
            payload4[9] = t0;
            t0 = src[16];
            payload4[10] = t1;
            t1 = src[17];
            payload4[11] = t2;
            t2 = src[18];
            payload4[12] = t3;
            t3 = src[19];
            payload4[13] = t4;
            t4 = src[20];
            payload4[14] = t5;
            t5 = src[21];
            payload4[15] = t6;
            t6 = src[22];
            payload4[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload4[0] = 0x40;
            payload4[17] = t0;
            payload4[18] = t1;
            payload4[19] = t2;
            payload4[20] = t3;
            payload4[21] = t4;
            payload4[22] = t5;
            payload4[23] = t6;
            payload4[24] = t7;
            payload4[25] = t8;
            payload4[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload4, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 1: {
            volatile u8 *src = (volatile u8 *)(base + 0x490);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload5[1] = t0;
            t0 = src[8];
            payload5[2] = t1;
            t1 = src[9];
            payload5[3] = t2;
            t2 = src[10];
            payload5[4] = t3;
            t3 = src[11];
            payload5[5] = t4;
            t4 = src[12];
            payload5[6] = t5;
            t5 = src[13];
            payload5[7] = t6;
            t6 = src[14];
            payload5[8] = t7;
            t7 = src[15];
            payload5[9] = t0;
            t0 = src[16];
            payload5[10] = t1;
            t1 = src[17];
            payload5[11] = t2;
            t2 = src[18];
            payload5[12] = t3;
            t3 = src[19];
            payload5[13] = t4;
            t4 = src[20];
            payload5[14] = t5;
            t5 = src[21];
            payload5[15] = t6;
            t6 = src[22];
            payload5[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload5[0] = 0x40;
            payload5[17] = t0;
            payload5[18] = t1;
            payload5[19] = t2;
            payload5[20] = t3;
            payload5[21] = t4;
            payload5[22] = t5;
            payload5[23] = t6;
            payload5[24] = t7;
            payload5[25] = t8;
            payload5[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload5, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 2: {
            volatile u8 *src = (volatile u8 *)(base + 0x538);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload6[1] = t0;
            t0 = src[8];
            payload6[2] = t1;
            t1 = src[9];
            payload6[3] = t2;
            t2 = src[10];
            payload6[4] = t3;
            t3 = src[11];
            payload6[5] = t4;
            t4 = src[12];
            payload6[6] = t5;
            t5 = src[13];
            payload6[7] = t6;
            t6 = src[14];
            payload6[8] = t7;
            t7 = src[15];
            payload6[9] = t0;
            t0 = src[16];
            payload6[10] = t1;
            t1 = src[17];
            payload6[11] = t2;
            t2 = src[18];
            payload6[12] = t3;
            t3 = src[19];
            payload6[13] = t4;
            t4 = src[20];
            payload6[14] = t5;
            t5 = src[21];
            payload6[15] = t6;
            t6 = src[22];
            payload6[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload6[0] = 0x40;
            payload6[17] = t0;
            payload6[18] = t1;
            payload6[19] = t2;
            payload6[20] = t3;
            payload6[21] = t4;
            payload6[22] = t5;
            payload6[23] = t6;
            payload6[24] = t7;
            payload6[25] = t8;
            payload6[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload6, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 5: {
            volatile u8 *src = (volatile u8 *)(base + 0x4E4);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload7[1] = t0;
            t0 = src[8];
            payload7[2] = t1;
            t1 = src[9];
            payload7[3] = t2;
            t2 = src[10];
            payload7[4] = t3;
            t3 = src[11];
            payload7[5] = t4;
            t4 = src[12];
            payload7[6] = t5;
            t5 = src[13];
            payload7[7] = t6;
            t6 = src[14];
            payload7[8] = t7;
            t7 = src[15];
            payload7[9] = t0;
            t0 = src[16];
            payload7[10] = t1;
            t1 = src[17];
            payload7[11] = t2;
            t2 = src[18];
            payload7[12] = t3;
            t3 = src[19];
            payload7[13] = t4;
            t4 = src[20];
            payload7[14] = t5;
            t5 = src[21];
            payload7[15] = t6;
            t6 = src[22];
            payload7[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload7[0] = 0x40;
            payload7[17] = t0;
            payload7[18] = t1;
            payload7[19] = t2;
            payload7[20] = t3;
            payload7[21] = t4;
            payload7[22] = t5;
            payload7[23] = t6;
            payload7[24] = t7;
            payload7[25] = t8;
            payload7[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload7, 0x1B);
            WaitMicroTime(2);
            return;
        }
        default:
            return;
        }
    case 4:
        switch ((s32)lbl_80558FCC) {
        case 0: {
            volatile u8 *src = (volatile u8 *)(base + 0x458);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload8[1] = t0;
            t0 = src[8];
            payload8[2] = t1;
            t1 = src[9];
            payload8[3] = t2;
            t2 = src[10];
            payload8[4] = t3;
            t3 = src[11];
            payload8[5] = t4;
            t4 = src[12];
            payload8[6] = t5;
            t5 = src[13];
            payload8[7] = t6;
            t6 = src[14];
            payload8[8] = t7;
            t7 = src[15];
            payload8[9] = t0;
            t0 = src[16];
            payload8[10] = t1;
            t1 = src[17];
            payload8[11] = t2;
            t2 = src[18];
            payload8[12] = t3;
            t3 = src[19];
            payload8[13] = t4;
            t4 = src[20];
            payload8[14] = t5;
            t5 = src[21];
            payload8[15] = t6;
            t6 = src[22];
            payload8[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload8[0] = 0x40;
            payload8[17] = t0;
            payload8[18] = t1;
            payload8[19] = t2;
            payload8[20] = t3;
            payload8[21] = t4;
            payload8[22] = t5;
            payload8[23] = t6;
            payload8[24] = t7;
            payload8[25] = t8;
            payload8[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload8, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 1: {
            volatile u8 *src = (volatile u8 *)(base + 0x4AC);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload9[1] = t0;
            t0 = src[8];
            payload9[2] = t1;
            t1 = src[9];
            payload9[3] = t2;
            t2 = src[10];
            payload9[4] = t3;
            t3 = src[11];
            payload9[5] = t4;
            t4 = src[12];
            payload9[6] = t5;
            t5 = src[13];
            payload9[7] = t6;
            t6 = src[14];
            payload9[8] = t7;
            t7 = src[15];
            payload9[9] = t0;
            t0 = src[16];
            payload9[10] = t1;
            t1 = src[17];
            payload9[11] = t2;
            t2 = src[18];
            payload9[12] = t3;
            t3 = src[19];
            payload9[13] = t4;
            t4 = src[20];
            payload9[14] = t5;
            t5 = src[21];
            payload9[15] = t6;
            t6 = src[22];
            payload9[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload9[0] = 0x40;
            payload9[17] = t0;
            payload9[18] = t1;
            payload9[19] = t2;
            payload9[20] = t3;
            payload9[21] = t4;
            payload9[22] = t5;
            payload9[23] = t6;
            payload9[24] = t7;
            payload9[25] = t8;
            payload9[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload9, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 2: {
            volatile u8 *src = (volatile u8 *)(base + 0x554);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload10[1] = t0;
            t0 = src[8];
            payload10[2] = t1;
            t1 = src[9];
            payload10[3] = t2;
            t2 = src[10];
            payload10[4] = t3;
            t3 = src[11];
            payload10[5] = t4;
            t4 = src[12];
            payload10[6] = t5;
            t5 = src[13];
            payload10[7] = t6;
            t6 = src[14];
            payload10[8] = t7;
            t7 = src[15];
            payload10[9] = t0;
            t0 = src[16];
            payload10[10] = t1;
            t1 = src[17];
            payload10[11] = t2;
            t2 = src[18];
            payload10[12] = t3;
            t3 = src[19];
            payload10[13] = t4;
            t4 = src[20];
            payload10[14] = t5;
            t5 = src[21];
            payload10[15] = t6;
            t6 = src[22];
            payload10[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload10[0] = 0x40;
            payload10[17] = t0;
            payload10[18] = t1;
            payload10[19] = t2;
            payload10[20] = t3;
            payload10[21] = t4;
            payload10[22] = t5;
            payload10[23] = t6;
            payload10[24] = t7;
            payload10[25] = t8;
            payload10[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload10, 0x1B);
            WaitMicroTime(2);
            return;
        }
        case 5: {
            volatile u8 *src = (volatile u8 *)(base + 0x500);
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload11[1] = t0;
            t0 = src[8];
            payload11[2] = t1;
            t1 = src[9];
            payload11[3] = t2;
            t2 = src[10];
            payload11[4] = t3;
            t3 = src[11];
            payload11[5] = t4;
            t4 = src[12];
            payload11[6] = t5;
            t5 = src[13];
            payload11[7] = t6;
            t6 = src[14];
            payload11[8] = t7;
            t7 = src[15];
            payload11[9] = t0;
            t0 = src[16];
            payload11[10] = t1;
            t1 = src[17];
            payload11[11] = t2;
            t2 = src[18];
            payload11[12] = t3;
            t3 = src[19];
            payload11[13] = t4;
            t4 = src[20];
            payload11[14] = t5;
            t5 = src[21];
            payload11[15] = t6;
            t6 = src[22];
            payload11[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload11[0] = 0x40;
            payload11[17] = t0;
            payload11[18] = t1;
            payload11[19] = t2;
            payload11[20] = t3;
            payload11[21] = t4;
            payload11[22] = t5;
            payload11[23] = t6;
            payload11[24] = t7;
            payload11[25] = t8;
            payload11[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload11, 0x1B);
            WaitMicroTime(2);
            return;
        }
        default:
            return;
        }
    case 1: {
        volatile u8 *src = (volatile u8 *)lbl_8038F490;
            u32 t7;
            u32 t6;
            u32 t5;
            u32 t4;
            u32 t3;
            u32 t2;
            u32 t1;
            u32 t0;
            u8 t8;
            u8 t9;
            t0 = src[0];
            t1 = src[1];
            t2 = src[2];
            t3 = src[3];
            t4 = src[4];
            t5 = src[5];
            t6 = src[6];
            t7 = src[7];
            payload12[1] = t0;
            t0 = src[8];
            payload12[2] = t1;
            t1 = src[9];
            payload12[3] = t2;
            t2 = src[10];
            payload12[4] = t3;
            t3 = src[11];
            payload12[5] = t4;
            t4 = src[12];
            payload12[6] = t5;
            t5 = src[13];
            payload12[7] = t6;
            t6 = src[14];
            payload12[8] = t7;
            t7 = src[15];
            payload12[9] = t0;
            t0 = src[16];
            payload12[10] = t1;
            t1 = src[17];
            payload12[11] = t2;
            t2 = src[18];
            payload12[12] = t3;
            t3 = src[19];
            payload12[13] = t4;
            t4 = src[20];
            payload12[14] = t5;
            t5 = src[21];
            payload12[15] = t6;
            t6 = src[22];
            payload12[16] = t7;
            t7 = src[23];
            t8 = src[24];
            t9 = src[25];
            payload12[0] = 0x40;
            payload12[17] = t0;
            payload12[18] = t1;
            payload12[19] = t2;
            payload12[20] = t3;
            payload12[21] = t4;
            payload12[22] = t5;
            payload12[23] = t6;
            payload12[24] = t7;
            payload12[25] = t8;
            payload12[26] = t9;
            __VISendI2CData(0xE0, (u8*)payload12, 0x1B);
            WaitMicroTime(2);
        return;
    }
    default:
        return;
    }
}

void __VISetGammaImm(u8* dataIn)
{
    u8 data[0x22];

    data[0] = 0x10;
    data[1] = ((u32)*(u16*)(dataIn + 0)) >> 8;
    data[2] = *(u16*)(dataIn + 0);
    data[3] = ((u32)*(u16*)(dataIn + 2)) >> 8;
    data[4] = *(u16*)(dataIn + 2);
    data[5] = ((u32)*(u16*)(dataIn + 4)) >> 8;
    data[6] = *(u16*)(dataIn + 4);
    data[7] = ((u32)*(u16*)(dataIn + 6)) >> 8;
    data[8] = *(u16*)(dataIn + 6);
    data[9] = ((u32)*(u16*)(dataIn + 8)) >> 8;
    data[10] = *(u16*)(dataIn + 8);
    data[11] = ((u32)*(u16*)(dataIn + 0xA)) >> 8;
    data[12] = *(u16*)(dataIn + 0xA);
    data[13] = dataIn[0xC];
    data[14] = dataIn[0xD];
    data[15] = dataIn[0xE];
    data[16] = dataIn[0xF];
    data[17] = dataIn[0x10];
    data[18] = dataIn[0x11];
    data[19] = dataIn[0x12];
    data[20] = ((u32)*(u16*)(dataIn + 0x14)) >> 8;
    data[21] = *(u16*)(dataIn + 0x14) & 0xC0;
    data[22] = ((u32)*(u16*)(dataIn + 0x16)) >> 8;
    data[23] = *(u16*)(dataIn + 0x16) & 0xC0;
    data[24] = ((u32)*(u16*)(dataIn + 0x18)) >> 8;
    data[25] = *(u16*)(dataIn + 0x18) & 0xC0;
    data[26] = ((u32)*(u16*)(dataIn + 0x1A)) >> 8;
    data[27] = *(u16*)(dataIn + 0x1A) & 0xC0;
    data[28] = ((u32)*(u16*)(dataIn + 0x1C)) >> 8;
    data[29] = *(u16*)(dataIn + 0x1C) & 0xC0;
    data[30] = ((u32)*(u16*)(dataIn + 0x1E)) >> 8;
    data[31] = *(u16*)(dataIn + 0x1E) & 0xC0;
    data[32] = ((u32)*(u16*)(dataIn + 0x20)) >> 8;
    data[33] = *(u16*)(dataIn + 0x20) & 0xC0;
    __VISendI2CData(0xE0, data, 0x22);
    WaitMicroTime(2);
}

void __VISetAdjustingValues(s16 x, s16 y)
{
    BOOL enabled;
    VITiming *tm;

    ASSERTMSGLINE(0x822, (y & 1) == 0, "__VISetAdjustValues(): y offset should be an even number");
    enabled = OSDisableInterrupts();
    displayOffsetH = x;
    displayOffsetV = y;
    tm = HorVer.timing;
    AdjustPosition(tm->acv);
    setHorizontalRegs(tm, HorVer.AdjustedDispPosX, HorVer.DispSizeX);
    if (FBSet != 0) {
        setFbbRegs(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    }
    setVerticalRegs(HorVer.AdjustedDispPosY, HorVer.AdjustedDispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

void __VIGetAdjustingValues(s16 *x, s16 *y)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    *x = displayOffsetH;
    *y = displayOffsetV;
    	OSRestoreInterrupts(enabled);
}

void fn_8005CB70(void)
{
	__VISetGammaImm((u8*)&lbl_80311B50 + lbl_8055DBE8 * 0x22);
}

void __VISetTrapFilter(void)
{
    u8 data[2];

    data[0] = 3;
    if (lbl_80558FD0 == 1) {
        data[1] = 0;
    } else {
        data[1] = 1;
    }
    __VISendI2CData(0xE0, data, 2);
    WaitMicroTime(2);
}

void __VISetRGBOverDrive(void)
{
    u8 data[2];

    if ((s32)lbl_8055DBF0 == 3) {
        data[0] = 10;
        data[1] = (lbl_8055DBE4 * 2) | 1;
        __VISendI2CData(0xE0, data, 2);
        WaitMicroTime(2);
    } else {
        data[0] = 10;
        data[1] = 0;
        __VISendI2CData(0xE0, data, 2);
        WaitMicroTime(2);
    }
}

#pragma dont_inline on
void fn_8005CC68(void)
{
    u8 data[2];

    lbl_8055DBF0 = 3;
    data[0] = 1;
    data[1] = 3;
    __VISendI2CData(0xE0, data, 2);
    WaitMicroTime(2);
}

extern u32 lbl_8055DBE0;
void __VISetRevolutionModeSimple(void)
{
    u8 a[2], b[2], c[2], d[3], e[2], f[3], g[3], h[5], j[2], k[2];
    volatile u8 i[27];
    register u32 value asm("r28") = 1;
    a[0]=0x6a; a[1]=value; __VISendI2CData(0xe0,a,2); WaitMicroTime(2);
    b[0]=0x65; b[1]=value; __VISendI2CData(0xe0,b,2); WaitMicroTime(2);
    __VISetYUVSEL((u8)fn_8005AD9C());
    value=0; c[0]=value; c[1]=value; __VISendI2CData(0xe0,c,2); WaitMicroTime(2);
    d[0]=0x71; d[1]=0x8e; d[2]=0x8e; __VISendI2CData(0xe0,d,3); WaitMicroTime(2);
    e[0]=2; e[1]=7; __VISendI2CData(0xe0,e,2); WaitMicroTime(2);
    lbl_80558FC0=value; lbl_80558FC1=value; lbl_80558FC2=value;
    f[0]=5; f[1]=value; f[2]=value; __VISendI2CData(0xe0,f,3); WaitMicroTime(2);
    if (lbl_80558FC3 || lbl_80558FC4 || lbl_80558FC5 || lbl_80558FC6) {
      lbl_80558FC3=0; lbl_80558FC4=0; lbl_80558FC5=0; lbl_80558FC6=0; lbl_8055DBE0 |= 2;
    }
    g[0]=8; g[1]=((lbl_80558FC4 & 15)<<4)|(lbl_80558FC3 & 15);
    g[2]=((lbl_80558FC6 & 7)<<3)|(lbl_80558FC5 & 7);
    __VISendI2CData(0xe0,g,3); WaitMicroTime(2);
    if (lbl_80558FC7 || lbl_80558FC8 || lbl_80558FC9 || lbl_80558FCA) {
      lbl_80558FC7=0; lbl_80558FC8=0; lbl_80558FC9=0; lbl_80558FCA=0; lbl_8055DBE0 |= 4;
    }
    h[0]=0x7a; h[1]=lbl_80558FC7&127; h[2]=lbl_80558FC8&127; h[3]=lbl_80558FC9&127; h[4]=lbl_80558FCA&127;
    __VISendI2CData(0xe0,h,5); WaitMicroTime(2);
    { volatile u8 *src = lbl_8038F490; u8 t7,t6,t5,t4,t3,t2,t1,t0; u8 t8,t9;
t0=src[0];
t1=src[1];
t2=src[2];
t3=src[3];
t4=src[4];
t5=src[5];
t6=src[6];
t7=src[7];
i[1]=t0; t0=src[8];
i[2]=t1; t1=src[9];
i[3]=t2; t2=src[10];
i[4]=t3; t3=src[11];
i[5]=t4; t4=src[12];
i[6]=t5; t5=src[13];
i[7]=t6; t6=src[14];
i[8]=t7; t7=src[15];
i[9]=t0; t0=src[16];
i[10]=t1; t1=src[17];
i[11]=t2; t2=src[18];
i[12]=t3; t3=src[19];
i[13]=t4; t4=src[20];
i[14]=t5; t5=src[21];
i[15]=t6; t6=src[22];
i[16]=t7; t7=src[23];
t8=src[24]; t9=src[25]; value=0x40; i[0]=value;
i[17]=t0;
i[18]=t1;
i[19]=t2;
i[20]=t3;
i[21]=t4;
i[22]=t5;
i[23]=t6;
i[24]=t7;
i[25]=t8;
i[26]=t9;
    }
    __VISendI2CData(0xe0,(u8*)i,27); WaitMicroTime(2);
    if ((s32)lbl_8055DBE4 != 1) { lbl_8055DBE4=1; lbl_8055DBE0 |= 0x40; }
    if ((s32)lbl_8055DBF0 == 3) { j[0]=10; j[1]=(lbl_8055DBE4<<1)|1; __VISendI2CData(0xe0,j,2); WaitMicroTime(2); }
    else { j[0]=10; j[1]=0; __VISendI2CData(0xe0,j,2); WaitMicroTime(2); }
    k[0]=3; k[1]=1; __VISendI2CData(0xe0,k,2); WaitMicroTime(2);
    __VISetGammaImm(lbl_80311B50+0x154);
}

#pragma dont_inline reset
typedef unsigned short undefined2;
