#include <revolution/GX.h>
#include <revolution/OS.h>
#include <revolution/SC.h>
#include <revolution/VI.h>
#include <revolution/VI/vi.h>
#include <revolution/VI/vihardware.h>
#include <revolution/IPC/ipcHardware.h>

#define __VIRegs VI_HW_REGS

extern u32 OS_BUS_CLOCK_SPEED;

// --- .sdata (0x80558F98 - 0x80558FD8) ---
static const char *lbl_80558F98 = "<< RVL_SDK - VI 	release build: Sep 26 2006 17:27:57 (0x4200_60422) >>";
static u32 lbl_80558F9C = 999;
static u32 lbl_80558FA0 = 999;
static u32 lbl_80558FA4 = 1;
static u32 lbl_80558FA8 = 1;
char lbl_80558FAC[] = "vi.c";
static u32 lbl_80558FB8[2] __attribute__((aligned(8))) = { 1, 0 };
static u8 lbl_80558FC0 = 0xFF;
static u8 lbl_80558FC1 = 0xFF;
static u8 lbl_80558FC2 = 0xFF;
static u8 lbl_80558FC3 = 0xFF;
static u8 lbl_80558FC4 = 0xFF;
static u8 lbl_80558FC5 = 0xFF;
static u8 lbl_80558FC6 = 0xFF;
static u8 lbl_80558FC7 = 0xFF;
static u8 lbl_80558FC8 = 0xFF;
static u8 lbl_80558FC9 = 0xFF;
static u8 lbl_80558FCA = 0xFF;
static u32 lbl_80558FCC = 0xFF;
static u8 lbl_80558FD0[8] = { 0xFF };

#define viI2cSdaNonInverted (lbl_80558FB8[0])

// Forward declarations
typedef struct VITiming VITiming;
typedef struct SomeVIStruct SomeVIStruct;
s32 fn_80058A00(s32 arg0, s32 arg1);
extern u8 lbl_80311B50[];

// --- .sbss (0x8055DB38 - 0x8055DBF8) ---
BOOL lbl_8055DB38;
u32 lbl_8055DB3C;
u32 lbl_8055DB40;
u32 lbl_8055DB44;
u32 lbl_8055DB48;
u32 lbl_8055DB4C;
u32 lbl_8055DB50;
u32 lbl_8055DB54;
VIPositionCallback lbl_8055DB58;
s16 lbl_8055DB5C;
s16 lbl_8055DB5E;
u32 lbl_8055DB60;
u32 lbl_8055DB64;
u64 lbl_8055DB68;
u32 lbl_8055DB70;
u32 lbl_8055DB74;
u64 lbl_8055DB78;
u32 lbl_8055DB80;
u32 lbl_8055DB84;
u32 lbl_8055DB88;
u32 lbl_8055DB8C;
u32 lbl_8055DB90;
u32 lbl_8055DB94;
u32 lbl_8055DB98;
static u32 CurrTvMode;
VITiming *lbl_8055DBA0;
u32 lbl_8055DBA4;
VIRetraceCallback lbl_8055DBA8;
VIRetraceCallback lbl_8055DBAC;
OSThreadQueue lbl_8055DBB0;
u32 lbl_8055DBB8;
u32 lbl_8055DBBC;
u32 lbl_8055DBC0;
u32 lbl_8055DBC4;
volatile u32 lbl_8055DBC8;
u32 lbl_8055DBCC;
volatile u32 lbl_8055DBD0;
u32 lbl_8055DBD4;
u32 lbl_8055DBD8;
u32 lbl_8055DBDC;
u32 lbl_8055DBE0;
u32 lbl_8055DBE4;
s32 lbl_8055DBE8;
u32 lbl_8055DBEC;
u32 lbl_8055DBF0;
u32 gap_10_8055DBF4_sbss;

#define changed lbl_8055DB68
#define shdwChanged lbl_8055DB78
#define displayOffsetH lbl_8055DB5C
#define displayOffsetV lbl_8055DB5E
#define PreCB lbl_8055DBAC
#define PostCB lbl_8055DBA8
#define retraceQueue lbl_8055DBB0
#define retraceCount lbl_8055DBD0
#define FBSet lbl_8055DB80

typedef struct {
    u8 bytes[2];
} __attribute__((packed)) u16_bytes;

struct VITiming {
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
    u8 hbe640;
    u8 hce;
    u8 hcs;
    u8 hsy;
    u16 hbs640;
    u8 hbeCCIR656;
    u8 pad;
    u16 hbsCCIR656;
};

struct SomeVIStruct {
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
};

// --- .bss (0x8038F320 - 0x8038F4C0) ---
static u16 regs[60];
static SomeVIStruct HorVer;
static u16 shdwRegs[60];
static u8 lbl_8038F490[0x30];

#define MARK_CHANGED(index) (changed |= (u64)1 << (63 - (index)))

#define SET_REG_FIELD(line, reg, size, shift, val) \
    ((reg) = ((u32)(reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))

static inline VITVFormat VIGetTvFormatInline(void)
{
    BOOL enabled;
    u32 format;

    enabled = OSDisableInterrupts();
    format = CurrTvMode;
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
    return (VITVFormat)format;
}

static VITiming timing[11] =
{
    { 6, 240, 24, 25, 3, 2, 12, 13, 12, 13, 520, 519, 520, 519, 525, 429, 64, 71, 105, 162, 373, 122, 0, 412 },
    { 6, 240, 24, 24, 4, 4, 12, 12, 12, 12, 520, 520, 520, 520, 526, 429, 64, 71, 105, 162, 373, 122, 0, 412 },
    { 5, 287, 35, 36, 1, 0, 13, 12, 11, 10, 619, 618, 617, 620, 625, 432, 64, 75, 106, 172, 380, 133, 0, 420 },
    { 5, 287, 33, 33, 2, 2, 13, 11, 13, 11, 619, 621, 619, 621, 624, 432, 64, 75, 106, 172, 380, 133, 0, 420 },
    { 6, 240, 24, 25, 3, 2, 16, 15, 14, 13, 518, 517, 516, 519, 525, 429, 64, 78, 112, 162, 373, 122, 0, 412 },
    { 6, 240, 24, 24, 4, 4, 16, 14, 16, 14, 518, 520, 518, 520, 526, 429, 64, 78, 112, 162, 373, 122, 0, 412 },
    { 12, 480, 48, 48, 6, 6, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 162, 373, 122, 0, 412 },
    { 12, 480, 44, 44, 10, 10, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 168, 379, 122, 0, 412 },
    { 6, 241, 24, 25, 1, 0, 12, 13, 12, 13, 520, 519, 520, 519, 525, 429, 64, 71, 105, 159, 370, 122, 0, 412 },
    { 12, 480, 48, 48, 6, 6, 24, 24, 24, 24, 1038, 1038, 1038, 1038, 1050, 429, 64, 71, 105, 180, 391, 122, 0, 412 },
    { 10, 576, 62, 62, 6, 6, 20, 20, 20, 20, 1240, 1240, 1240, 1240, 1250, 432, 64, 75, 106, 172, 380, 122, 0, 412 },
};
#define lbl_80311738 timing
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

static u32 getCurrentFieldEvenOdd(void);
void fn_8005CC68(void);

static inline u32 getEncoderType(void)
{
    return 1;
}

static inline s32 cntlzd(u64 bit)
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

static inline VITiming *getTiming(VITVMode mode)
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

static OSShutdownFunctionInfo lbl_80311910 = {
    (OSShutdownFunction)fn_80058A00,
    127,
    NULL,
    NULL
};

void OSClearContext(OSContext* ctx);
void OSSetCurrentContext(OSContext* ctx);
void OSWakeupThread(OSThreadQueue*);
void SIRefreshSamplingRate(void);
s32 __OSSetVIForceDimming(u32, u32, u32);
void __VIDisplayPositionToXY(s32, s32, s16*, s16*);
void __VISetCGMS(void);
void __VISetClosedCaption(void);
void __VISetMacrovision(void);
void __VISetRGBOverDrive(void);
void __VISetTrapFilter(void);
void __VISetWSS(void);
void __VISetYUVSEL(u8);
u64 fn_8002FD30(u32, u32, s32, void*);
void fn_80039CD8(void*, u32);
void fn_80039CE0(void);
void fn_8005BAEC(u8);
void fn_8005CB70(void);

extern u32 lbl_8037B5B0;

#pragma dont_inline on
void fn_80058A60(s16 intr, OSContext *context) {
    OSContext exceptionContext;
    BOOL intr1;
    s16 spA;
    s16 sp8;
    s32 *var_r3;
    s32 temp_r26;
    s32 temp_r26_3;
    s32 temp_r3_6;
    s32 temp_r4;
    s32 var_ctr;
    s32 var_r4_3;
    s32 var_r6;
    s32 var_r6_2;
    u16 temp_r3;
    u16 temp_r3_2;
    u16 temp_r3_3;
    u16 temp_r3_4;
    u16 temp_r3_5;
    u32 temp_r26_2;
    u32 temp_r4_2;
    u32 temp_r5;
    u32 temp_r6;
    u32 temp_r6_2;
    u32 var_r29;
    u32 var_r4;
    u32 var_r4_2;
    u32 var_r7;
    u64 temp_r3_7;
    u64 temp_ret;
    void *temp_r3_8;
    void *temp_r3_9;
    void *temp_r6_3;
    temp_r3 = *(u16 *)0xCC002030;
    var_r6 = 0;
    if (temp_r3 & 0x8000) {
        var_r6 = 1;
        *(u16 *)0xCC002030 = temp_r3 & 0x7FFF;
    }
    temp_r3_2 = *(u16 *)0xCC002034;
    if (temp_r3_2 & 0x8000) {
        var_r6 |= 2;
        *(u16 *)0xCC002034 = temp_r3_2 & 0x7FFF;
    }
    temp_r3_3 = *(u16 *)0xCC002038;
    if (temp_r3_3 & 0x8000) {
        var_r6 |= 4;
        *(u16 *)0xCC002038 = temp_r3_3 & 0x7FFF;
    }
    temp_r3_4 = *(u16 *)0xCC00203C;
    if (temp_r3_4 & 0x8000) {
        var_r6 |= 8;
        *(u16 *)0xCC00203C = temp_r3_4 & 0x7FFF;
    }
    if ((var_r6 & 4) || (var_r6 & 8)) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        if (lbl_8055DB58 != NULL) {
            var_r4 = *(volatile u16 *)0xCC00202C & 0x7FF;
            do {
                temp_r3 = *(volatile u16 *)0xCC00202E & 0x7FF;
                temp_r6 = var_r4;
                var_r4 = *(volatile u16 *)0xCC00202C & 0x7FF;
            } while (temp_r6 != var_r4);
            __VIDisplayPositionToXY(temp_r3, var_r4, &spA, &sp8);
            lbl_8055DB58(spA, sp8);
        }
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
        return;
    }
    temp_r4 = lbl_8055DBD0;
    lbl_8055DBD0 = temp_r4 + 1;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (( lbl_8055DBAC) != NULL) {
        lbl_8055DBAC(lbl_8055DBD0);
    }
    if ((s32) lbl_8055DB40 != 0) {
        var_r4_2 = *(volatile u16 *)0xCC00202C & 0x7FF;
        do {
            temp_r5 = var_r4_2;
            var_r4_2 = *(volatile u16 *)0xCC00202C & 0x7FF;
        } while (temp_r5 != var_r4_2);
        if ((var_r4_2 != 1) && (var_r4_2 != (u32) (((u16) lbl_8055DBA0->nhlines >> 1U) + 1))) {
            lbl_8055DB3C += 1;
        }
    }
    if ((s32) lbl_8055DBCC != 0) {
        if ((u32) lbl_8055DB70 == 1U) {
            var_r7 = *(volatile u16 *)0xCC00202C & 0x7FF;
            do {
                temp_r5 = *(volatile u16 *)0xCC00202E & 0x7FF;
                temp_r6_2 = var_r7;
                var_r7 = *(volatile u16 *)0xCC00202C & 0x7FF;
            } while (temp_r6_2 != var_r7);
            temp_r3_5 = lbl_8055DBA0->nhlines;
            if (((u32) (temp_r3_5 << __cntlzw(temp_r3_5 ^ (((var_r7 - 1) * 2) + ((temp_r5 - 1) / (u16) lbl_8055DBA0->hlw)))) >> 0x1FU) != 0) {
                goto block_28;
            }
            var_r6_2 = 0;
        } else {
block_28:
            while (lbl_8055DB78 != 0) {
                var_r4_3 = cntlzd(lbl_8055DB78);
                temp_r3_6 = var_r4_3 * 2;
                temp_r6_3 = (void*)(temp_r3_6 + 0xCC000000);
                *(volatile u16*)(0xCC002000 + temp_r3_6) = regs[var_r4_3];
                temp_ret = fn_8002FD30(0, 1, 0x3F - var_r4_3, temp_r6_3);
                lbl_8055DB78 &= ~((u64)1 << (63 - var_r4_3));
            }
            temp_r3_8 = &HorVer;
            var_r6_2 = 1;
            lbl_8055DB70 = 0U;
            lbl_8055DBA0 = HorVer.timing;
            CurrTvMode = HorVer.tv;
            lbl_8055DB94 = lbl_8055DB98;
        }
        if (var_r6_2 != 0) {
            lbl_8055DBCC = 0;
            SIRefreshSamplingRate();
        }
    }
    intr1 = OSDisableInterrupts();
    temp_r26 = *(volatile u16 *)0xCC00206E & 3;
    OSRestoreInterrupts(intr1);
    temp_r26_2 = temp_r26 & 1;
    if (temp_r26_2 != (u32) lbl_80558F9C) {
        __VISetYUVSEL(temp_r26_2);
    }
    lbl_80558F9C = temp_r26_2;
    intr1 = OSDisableInterrupts();
    switch (CurrTvMode) {
    case 0:
    case 3:
    case 6:
    case 7:
        var_r29 = 0;
        break;
    case 1:
    case 4:
        var_r29 = 1;
        break;
    case 2:
    case 5:
        var_r29 = CurrTvMode;
        break;
    }
    OSRestoreInterrupts(intr1);
    if (var_r29 != (u32) lbl_80558FA0) {
        if (var_r29 == 5) {
            fn_8005BAEC(1);
        } else {
            fn_8005BAEC(0);
        }
        if ((s32) var_r29 != 1) {
            lbl_8055DB48 = 0x4650U;
            lbl_8055DB4C = 0x1A5E0U;
        } else {
            lbl_8055DB48 = 0x3A98U;
            lbl_8055DB4C = 0x15F90U;
        }
        lbl_8055DB50 = 0U;
        lbl_8055DB54 = 0U;
    }
    lbl_80558FA0 = var_r29;
    if ((s32) lbl_8055DBC8 != 0) {
loop_79:
        if ((s32) lbl_8055DBE0 != 0) {
            temp_r26_3 = 1 << (0x1F - __cntlzw(lbl_8055DBE0));
            switch (temp_r26_3) {
            case 0x1:
                __VISetCGMS();
                break;
            case 0x2:
                __VISetWSS();
                break;
            case 0x4:
                __VISetClosedCaption();
                break;
            case 0x8:
                __VISetMacrovision();
                break;
            case 0x10:
                fn_8005CB70();
                break;
            case 0x20:
                __VISetTrapFilter();
                break;
            case 0x40:
                __VISetRGBOverDrive();
                break;
            }
            lbl_8055DBE0 &= ~temp_r26_3;
            goto loop_79;
        }
        lbl_8055DBC8 = 0;
    }
    if (( lbl_8055DBA8) != NULL) {
        OSClearContext(&exceptionContext);
        lbl_8055DBA8(lbl_8055DBD0);
    }
    OSWakeupThread(&lbl_8055DBB0);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
    if (((s32) lbl_8055DB44 == 1) && (__OSSetVIForceDimming(0, 0, 0) == 1)) {
        lbl_8055DB44 = 0;
        lbl_8055DB50 = 0U;
    }
    var_r3 = (s32*)HorVer.unk_0x58;
    var_ctr = 0xA;
loop_87:
    if ((s32) *var_r3 == 0) {
        ((s32*)HorVer.unk_0x58)[0] = 0;
    } else {
        var_r3 += 1;
        var_ctr -= 1;
        if (var_ctr != 0) {
            goto loop_87;
        }
    }
    if (((s32) lbl_8055DBBC != 0) && ((s32) lbl_8055DBB8 != 0) && (((s32*)HorVer.unk_0x58)[0] != 0)) {
        if (((s32) lbl_8055DBC4 == 1) && ((u32) lbl_8055DB50 < -1U)) {
            lbl_8055DB50 += 1;
        }
        if (((s32) lbl_8055DBC0 == 1) && ((u32) lbl_8055DB54 < -1U)) {
            lbl_8055DB54 += 1;
        }
    } else {
        if ((u32) lbl_8055DB50 >= (u32) lbl_8055DB48) {
            lbl_8055DB8C = 1;
        }
        if ((u32) lbl_8055DB54 >= (u32) lbl_8055DB4C) {
            fn_80039CE0();
        }
        lbl_8055DB50 = 0U;
        lbl_8055DB54 = 0U;
    }
    if ((s32) lbl_80558FA4 != (s32) lbl_8055DBC4) {
        if (((s32) lbl_8055DBC4 == 0) && ((u32) lbl_8055DB50 >= (u32) lbl_8055DB48)) {
            lbl_8055DB8C = 1;
        }
        lbl_8055DB50 = 0U;
    }
    if ((u32) lbl_8055DB50 == (u32) lbl_8055DB48) {
        lbl_8055DB88 = 1;
    }
    if (((s32) lbl_8055DB8C != 0) && (__OSSetVIForceDimming(0, 2, 2) == 1)) {
        lbl_8055DB8C = 0;
    }
    if (((s32) lbl_8055DB88 != 0) && (__OSSetVIForceDimming(1, 2, 2) == 1)) {
        lbl_8055DB88 = 0;
    }
    if ((s32) lbl_80558FA8 != (s32) lbl_8055DBC0) {
        if (((s32) lbl_8055DBC0 == 0) && ((u32) lbl_8055DB54 >= (u32) lbl_8055DB4C)) {
            fn_80039CE0();
        }
        lbl_8055DB54 = 0U;
    }
    if ((u32) lbl_8055DB54 == (u32) lbl_8055DB4C) {
        fn_80039CD8(&lbl_8037B5B0, 0);
    }
    temp_r3_9 = (s32*)HorVer.unk_0x58;
    lbl_8055DBBC = 1;
    lbl_8055DBB8 = 1;
    ((s32*)temp_r3_9)[0] = 1;
    ((s32*)temp_r3_9)[1] = 1;
    ((s32*)temp_r3_9)[2] = 1;
    ((s32*)temp_r3_9)[3] = 1;
    ((s32*)temp_r3_9)[4] = 1;
    ((s32*)temp_r3_9)[5] = 1;
    ((s32*)temp_r3_9)[6] = 1;
    ((s32*)temp_r3_9)[7] = 1;
    ((s32*)temp_r3_9)[8] = 1;
    ((s32*)temp_r3_9)[9] = 1;
    lbl_80558FA4 = lbl_8055DBC4;
    lbl_80558FA8 = lbl_8055DBC0;
}
#pragma dont_inline reset

VIRetraceCallback fn_800591AC(VIRetraceCallback cb)
{
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
    BOOL enabled;
    VIRetraceCallback oldcb;

    oldcb = lbl_8055DBA8;
    enabled = OSDisableInterrupts();
    lbl_8055DBA8 = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

// Return a pointer/offset into lbl_80311738 based on the given index.
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
    u32 temp;

    nonInter = mode & 3;
    tv = (u32)mode >> 2;
    *(u32 *)0x800000CC = tv;
    tm = (VITiming *)fn_80059234(mode);
    __VIRegs[1] = 2;
    for (a = 0; a < 1000; a++) {
    }
    __VIRegs[1] = 0;
    __VIRegs[3] = tm->hlw;
    __VIRegs[2] = (tm->hce << 8) | tm->hcs;
    __VIRegs[5] = tm->hbe640 | (tm->hsy << 7);
    __VIRegs[4] = (u16)(tm->hbs640 << 1);
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
    temp = (u16)(((u32)tm->nhlines >> 1) + 1);
    __VIRegs[25] = tm->hlw + 1;
    __VIRegs[24] = temp | 0x1000;
    if (tv >= 4 || tv < 1) {
        tv = 0;
    }
    if (nonInter <= 1) {
        __VIRegs[1] = (tv << 8) | ((nonInter & 1) << 2) | 1;
        __VIRegs[54] = 0;
    } else {
        __VIRegs[1] = (tv << 8) | 5;
        __VIRegs[54] = 1;
    }
}

void fn_8005954C(void)
{

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
    lbl_8055DB5C = SCGetDisplayOffsetH();
    lbl_8055DB5E = 0;
    bootTv = *(u32*)0x800000CC;
    dspCfg = __VIRegs[1];
    enabled = OSDisableInterrupts();
    if (((u32)__VIRegs[54] & 1) == 1) value = 2;
    else value = !!((__VIRegs[1] >> 2) & 1);
    OSRestoreInterrupts(enabled);
    HorVer.nonInter = value;
    HorVer.tv = (dspCfg >> 8) & 3;
    if (bootTv == 5 || (bootTv == 1 && HorVer.tv == 0)) HorVer.tv = 5;
    tv = HorVer.tv == 3 ? 0 : HorVer.tv;
    tm = (VITiming*)fn_80059234((tv << 2) + HorVer.nonInter);
    HorVer.timing = tm;
    lbl_8055DBA0 = tm;
    regs[1] = dspCfg;
    CurrTvMode = HorVer.tv;
    HorVer.DispSizeX = 640;
    HorVer.DispSizeY = tm->acv * 2;
    HorVer.DispPosX = (720 - HorVer.DispSizeX) / 2;
    HorVer.DispPosY = 0;
    acv = tm->acv;
    HorVer.AdjustedDispPosX = (s16)HorVer.DispPosX + lbl_8055DB5C > 720 - HorVer.DispSizeX
        ? 720 - HorVer.DispSizeX : (s16)HorVer.DispPosX + lbl_8055DB5C < 0
        ? 0 : (s16)HorVer.DispPosX + lbl_8055DB5C;
    coeff = HorVer.FBMode == VI_XFBMODE_SF ? 2 : 1;
    frac = HorVer.DispPosY & 1;
    HorVer.AdjustedDispPosY = MAX((s16)HorVer.DispPosY + lbl_8055DB5E, frac);
    HorVer.AdjustedDispSizeY = HorVer.DispSizeY
        + MIN((s16)HorVer.DispPosY + lbl_8055DB5E - frac, 0)
        - MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + lbl_8055DB5E - (((s16)acv * 2) - frac), 0);
    HorVer.AdjustedPanPosY = HorVer.PanPosY
        - MIN((s16)HorVer.DispPosY + lbl_8055DB5E - frac, 0) / coeff;
    HorVer.AdjustedPanSizeY = HorVer.PanSizeY
        + MIN((s16)HorVer.DispPosY + lbl_8055DB5E - frac, 0) / coeff
        - MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + lbl_8055DB5E - (((s16)acv * 2) - frac), 0) / coeff;
    HorVer.FBSizeX = 640;
    HorVer.FBSizeY = tm->acv * 2;
    HorVer.PanPosX = 0;
    HorVer.PanPosY = 0;
    HorVer.PanSizeX = 640;
    HorVer.PanSizeY = tm->acv * 2;
    HorVer.FBMode = 0;
    HorVer.wordPerLine = 40;
    HorVer.std = 40;
    HorVer.wpl = 40;
    HorVer.xof = 0;
    HorVer.black = 1;
    HorVer.threeD = 0;
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
    tv = CurrTvMode;
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

    shdwRegs[15] = (u16)*tfbb;
    MARK_CHANGED(15);
    MARK_CHANGED(14);
    shdwRegs[14] = (shifted << 12) | ((*tfbb >> 16) | (HorVer->xof << 8));
    shdwRegs[19] = (u16)*bfbb;
    MARK_CHANGED(19);
    shdwRegs[18] = *bfbb >> 16;
    MARK_CHANGED(18);
    if (HorVer->threeD) {
        shdwRegs[17] = (u16)*rtfbb;
        MARK_CHANGED(17);
        MARK_CHANGED(16);
        shdwRegs[16] = *rtfbb >> 16;
        shdwRegs[21] = (u16)*rbfbb;
        MARK_CHANGED(21);
        shdwRegs[20] = *rbfbb >> 16;
        MARK_CHANGED(20);
    }
}

/* Recomputes the vertical porch/blanking shadow registers (0 and 6-9) for the
   picture window at dispPosY with dispSizeY active lines, from the current
   timing's odd/even porch values (equ: equalizing pulses, acv: total active
   lines). With black set the picture window is collapsed to zero height, so the
   display shows black while keeping the same TV timing. */
void fn_80059D90(s32 dispPosY, s32 dispSizeY, u8 equ, s32 acv, s32 prbOdd, s32 prbEven, s32 psbOdd, s32 psbEven, BOOL black)
{
    BOOL b = black;
    s32 c, d;
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r8;
    u16 actualPrbOdd;
    u16 actualPrbEven;
    u16 actualPsbOdd;
    u16 actualPsbEven;
    u16 psb;

    if (shdwRegs[54] & 1) {
        c = 1;
        d = 2;
    } else {
        c = 2;
        d = 1;
    }

    if (dispPosY % 2 == 0) {
        temp_r31 = d * (((c * acv) - dispSizeY) - dispPosY);
        temp_r3 = d * dispPosY;
        actualPsbOdd = psbOdd + temp_r31;
        actualPrbOdd = prbOdd + temp_r3;
        actualPsbEven = psbEven + temp_r31;
        actualPrbEven = prbEven + temp_r3;
    } else {
        temp_r31 = d * (((c * acv) - dispSizeY) - dispPosY);
        temp_r3 = d * dispPosY;
        actualPsbOdd = psbEven + temp_r31;
        actualPrbOdd = prbEven + temp_r3;
        actualPrbEven = prbOdd + temp_r3;
        actualPsbEven = psbOdd + temp_r31;
    }

    psb = (u16)(dispSizeY / c);
    if (b) {
        temp_r8 = ((psb * 2) & 0x1FFFE) - 2;
        psb = 0;
        actualPsbOdd += 2;
        actualPsbEven += 2;
        actualPrbOdd += temp_r8;
        actualPrbEven += temp_r8;
    }

    MARK_CHANGED(0);
    shdwRegs[7] = actualPrbOdd;
    MARK_CHANGED(7);
    shdwRegs[0] = equ | (psb << 4);
    MARK_CHANGED(6);
    shdwRegs[6] = actualPsbOdd;
    MARK_CHANGED(9);
    shdwRegs[9] = actualPrbEven;
    shdwRegs[8] = actualPsbEven;
    MARK_CHANGED(8);
}
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
    shdwRegs[25] = (u16)(u32)hct;
    MARK_CHANGED(25);
    shdwRegs[24] = vct | 0x1000;
    MARK_CHANGED(24);
}

static inline void AdjustPosition(u16 acv)
{
    s32 coeff;
    s32 frac;

    HorVer.AdjustedDispPosX = (s16)HorVer.DispPosX + displayOffsetH > 720 - HorVer.DispSizeX
        ? 720 - HorVer.DispSizeX : (s16)HorVer.DispPosX + displayOffsetH < 0
        ? 0 : (s16)HorVer.DispPosX + displayOffsetH;
    coeff = HorVer.FBMode == VI_XFBMODE_SF ? 2 : 1;
    frac = HorVer.DispPosY & 1;
    HorVer.AdjustedDispPosY = MAX((s16)HorVer.DispPosY + displayOffsetV, frac);
    HorVer.AdjustedDispSizeY = HorVer.DispSizeY
        + MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0)
        - MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + displayOffsetV - (((s16)acv * 2) - frac), 0);
    HorVer.AdjustedPanPosY = HorVer.PanPosY
        - MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) / coeff;
    HorVer.AdjustedPanSizeY = HorVer.PanSizeY
        + MIN((s16)HorVer.DispPosY + displayOffsetV - frac, 0) / coeff
        - MAX((s16)HorVer.DispPosY + (s16)HorVer.DispSizeY + displayOffsetV - (((s16)acv * 2) - frac), 0) / coeff;
}

static void setPicConfig(u16 fbSizeX, VIXFBMode xfbMode, u16 panPosX, u16 panSizeX, u8 *wordPerLine, u8 *std, u8 *wpl, u8 *xof)
{
    *wordPerLine = (fbSizeX + 15) / 16;
    *std = (xfbMode == VI_XFBMODE_SF) ? *wordPerLine : (u8)(*wordPerLine * 2);
    *xof = panPosX % 16;
    *wpl = (*xof + panSizeX + 15) / 16;
    shdwRegs[36] = (*wpl << 8) | *std;
    MARK_CHANGED(36);
}

static void setBBIntervalRegs(VITiming *tm)
{
    u16 val;

    val = tm->bs1 | (tm->be1 << 5);
    shdwRegs[11] = val;
    MARK_CHANGED(11);

    val = tm->bs3 | (tm->be3 << 5);
    shdwRegs[10] = val;
    MARK_CHANGED(10);

    val = tm->bs2 | (tm->be2 << 5);
    shdwRegs[13] = val;
    MARK_CHANGED(13);

    val = tm->bs4 | (tm->be4 << 5);
    shdwRegs[12] = val;
    MARK_CHANGED(12);
}

static void setScalingRegs(u16 panSizeX, u16 dispSizeX, BOOL threeD)
{
    u32 scale;

    panSizeX = threeD ? (panSizeX << 1) : panSizeX;
    if (panSizeX < dispSizeX) {
        scale = (u32)(dispSizeX + (panSizeX << 8) - 1) / dispSizeX;
        shdwRegs[37] = scale | 0x1000;
        MARK_CHANGED(37);
        shdwRegs[56] = (u32)panSizeX;
        MARK_CHANGED(56);
    } else {
        shdwRegs[37] = 0x100;
        MARK_CHANGED(37);
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

static void setHorizontalRegs(VITiming *tm, u16 dispPosX, u16 dispSizeX)
{
    u32 hbe;
    u32 hbs;
    u32 hbeLo;
    u32 hbeHi;

    shdwRegs[3] = (u16)(u32)tm->hlw;
    MARK_CHANGED(3);
    shdwRegs[2] = tm->hce | (tm->hcs << 8);
    MARK_CHANGED(2);
    hbe = tm->hbe640 - 40 + dispPosX;
    hbs = tm->hbs640 + 40 + dispPosX - (720 - dispSizeX);
    hbeLo = hbe & 0x1FF;
    hbeHi = hbe >> 9;
    shdwRegs[5] = tm->hsy | (hbeLo << 7);
    MARK_CHANGED(5);
    shdwRegs[4] = hbeHi | (hbs * 2);
    MARK_CHANGED(4);
}

extern char lbl_803116F0[];
void VIConfigure(const GXRenderModeObj *rm)
{
    char *msgBase = lbl_803116F0;
    VITiming *tm;
    u32 reg;
    int enabled;
    u32 newNonInter;
    s32 tvInBootrom;
    u32 tvInGame;
    u16 hct;
    u16 vct;
    u16 borrow;
    u16 bbVal;
    enabled = OSDisableInterrupts();
    newNonInter = rm->tvInfo & 3;
    if (HorVer.nonInter != newNonInter) {
        HorVer.nonInter = newNonInter;
        lbl_8055DB60 = 1;
    }
    tvInBootrom = *(s32*)0x800000CC;
    tvInGame = (u32)rm->tvInfo >> 2;
    if (tvInGame == 4 && lbl_8055DB90 == 0) {
        lbl_8055DB90 = 1;
        OSReport(msgBase + 0x2ec);
        OSReport(msgBase + 0x318);
        OSReport(msgBase + 0x344);
        OSReport(msgBase + 0x370);
        OSReport(msgBase + 0x39c);
        OSReport(msgBase + 0x3c8);
        OSReport(msgBase + 0x2ec);
    }
    switch (tvInBootrom) {
    case 0:
    case 2:
    case 6:
    case 7:
        if (tvInGame == 0 || tvInGame == 2 || tvInGame == 6 || tvInGame == 7) {
            break;
        }
    case 1:
    case 5:
        if (tvInGame == 1 || tvInGame == 5) {
            break;
        }
    default:
        OSPanic(lbl_80558FAC, 0x9A1, msgBase + 0x3f4, tvInBootrom, tvInGame);
        break;
    }
    if (tvInGame == 0 || tvInGame == 2) {
        HorVer.tv = tvInBootrom;
    } else {
        HorVer.tv = tvInGame;
    }
    HorVer.DispPosX = rm->viXOrigin;
    HorVer.DispPosY = (HorVer.nonInter == 1) ? (u16)(rm->viYOrigin * 2) : rm->viYOrigin;
    HorVer.DispSizeX = rm->viWidth;
    HorVer.FBSizeX = rm->fbWidth;
    HorVer.FBSizeY = rm->xfbHeight;
    HorVer.FBMode = rm->xfbMode;
    HorVer.PanSizeX = rm->fbWidth;
    HorVer.PanSizeY = rm->xfbHeight;
    HorVer.PanPosX = 0;
    HorVer.PanPosY = 0;
    HorVer.DispSizeY = HorVer.PanSizeY;
    if (HorVer.nonInter == 2 || HorVer.nonInter == 3) {
    } else if (HorVer.FBMode == VI_XFBMODE_SF) {
        HorVer.DispSizeY = (u16)(HorVer.PanSizeY * 2);
    }
    HorVer.threeD = (HorVer.nonInter == 3);
    tm = (VITiming*)fn_80059234(HorVer.tv * 4 + HorVer.nonInter);
    HorVer.timing = tm;
    AdjustPosition(tm->acv);
    vct = tm->nhlines / 2;
    borrow = tm->nhlines % 2;
    if (borrow != 0) {
        hct = tm->hlw;
    } else {
        hct = 0;
    }
    vct++;
    hct++;
    shdwRegs[25] = (u16)(u32)hct;
    MARK_CHANGED(25);
    shdwRegs[24] = vct | 0x1000;
    MARK_CHANGED(24);
    {
        u32 var_r5_2;
        u16 var_r10;
        u16 var_r9;
        if (HorVer.nonInter == 2 || HorVer.nonInter == 3) {
            var_r5_2 = (shdwRegs[1] & ~4) | 4;
            var_r10 = (shdwRegs[54] & ~1) | 1;
        } else {
            var_r10 = shdwRegs[54] & ~1;
            var_r5_2 = (shdwRegs[1] & ~4) | ((HorVer.nonInter << 2) & 4);
        }
        var_r9 = ((var_r5_2 & ~8) | (HorVer.threeD * 8)) & ~0x300;
        if (HorVer.tv == 1 || HorVer.tv == 2 || HorVer.tv == 3) {
            var_r9 |= HorVer.tv << 8;
        }
        MARK_CHANGED(1);
        shdwRegs[1] = var_r9;
        MARK_CHANGED(54);
        shdwRegs[54] = var_r10;
    }
    setScalingRegs(HorVer.PanSizeX, HorVer.DispSizeX, HorVer.threeD);
    setHorizontalRegs(tm, HorVer.AdjustedDispPosX, HorVer.DispSizeX);
    bbVal = tm->bs1 | (tm->be1 << 5);
    shdwRegs[11] = bbVal;
    MARK_CHANGED(11);
    bbVal = tm->bs3 | (tm->be3 << 5);
    shdwRegs[10] = bbVal;
    MARK_CHANGED(10);
    bbVal = tm->bs2 | (tm->be2 << 5);
    shdwRegs[13] = bbVal;
    MARK_CHANGED(13);
    bbVal = tm->bs4 | (tm->be4 << 5);
    shdwRegs[12] = bbVal;
    MARK_CHANGED(12);
    setPicConfig(HorVer.FBSizeX, HorVer.FBMode, HorVer.PanPosX, HorVer.PanSizeX, &HorVer.wordPerLine, &HorVer.std, &HorVer.wpl, &HorVer.xof);
    if (FBSet != 0) {
        fn_80059AD8(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    }
    fn_80059D90(HorVer.AdjustedDispPosY, HorVer.AdjustedDispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
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
    if (HorVer.nonInter != 2 && HorVer.nonInter != 3 && HorVer.FBMode == 0) {
        height <<= 1;
    }
    HorVer.DispSizeY = height;
    tm = HorVer.timing;
    AdjustPosition(tm->acv);
    setScalingRegs(HorVer.PanSizeX, HorVer.DispSizeX, HorVer.threeD);
    setPicConfig(HorVer.FBSizeX, HorVer.FBMode, HorVer.PanPosX, HorVer.PanSizeX, &HorVer.wordPerLine, &HorVer.std, &HorVer.wpl, &HorVer.xof);
    if (FBSet != 0) fn_80059AD8(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    fn_80059D90(HorVer.AdjustedDispPosY, HorVer.DispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

/* Commits pending VI register and framebuffer state changes (shadow -> hardware view) under disabled interrupts. */
void VIFlush(void)
{
    BOOL interrupts;
    s32 regIndex;
    u64 mask;
    u32 tmp;

    interrupts = OSDisableInterrupts();
    tmp = lbl_8055DB70 | lbl_8055DB60;
    lbl_8055DB70 = tmp;
    lbl_8055DB60 = 0;
    shdwChanged |= changed;
    while (changed != 0) {
        regIndex = cntlzd(changed);
        regs[regIndex] = shdwRegs[regIndex];
        mask = fn_8002FD30(0, 1, 0x3F - regIndex, (void*)(regIndex * 2));
        changed &= ~mask;
    }
    lbl_8055DBCC = 1;
    lbl_8055DBC8 = 1;
    lbl_8055DB98 = HorVer.bufAddr;
    OSRestoreInterrupts(interrupts);
}

void VISetNextFrameBuffer(void *fb)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    HorVer.bufAddr = (u32)fb;
    FBSet = 1;
    fn_80059AD8(&HorVer, &HorVer.tfbb, &HorVer.bfbb, &HorVer.rtfbb, &HorVer.rbfbb);
    OSRestoreInterrupts(enabled);
}

VITVFormat fn_8005AB88(void) {
    return lbl_8055DB94;
}

/* Shows black on the screen (black TRUE) or the picture again (FALSE): records
   the flag in the VI state and recomputes the vertical registers, which collapse
   the active picture window to zero height so the display goes black without
   changing the TV timing. */
void VISetBlack(BOOL black)
{
    BOOL enabled;
    VITiming *tm;

    enabled = OSDisableInterrupts();
    HorVer.black = black;
    tm = HorVer.timing;
    // setVerticalRegs(): rebuild the vertical porch/blanking registers for the new black state.
    fn_80059D90(HorVer.AdjustedDispPosY, HorVer.DispSizeY, tm->equ, tm->acv, tm->prbOdd, tm->prbEven, tm->psbOdd, tm->psbEven, HorVer.black);
    OSRestoreInterrupts(enabled);
}

VITVFormat fn_8005AC08(void) {
    return lbl_8055DBD0;
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

/* Read VI regs to determine the next field and combine with adjusted display Y parity. */
u32 VIGetNextField(void)
{
    u32 vcount;
    u32 hcount;
    u32 prevVCount;
    VITiming *timing;
    u32 halfLineIndex;
    u32 isNextFieldFirst;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    vcount = __VIRegs[22] & 0x7FF;
    do {
        prevVCount = vcount;
        hcount = __VIRegs[23] & 0x7FF;
        vcount = __VIRegs[22] & 0x7FF;
    } while (prevVCount != vcount);
    timing = lbl_8055DBA0;
    halfLineIndex = ((vcount - 1) * 2) + ((hcount - 1) / timing->hlw);
    isNextFieldFirst = halfLineIndex < timing->nhlines;
    OSRestoreInterrupts(enabled);
    return (isNextFieldFirst ^ 1) ^ (HorVer.AdjustedDispPosY & 1);
}

u32 VIGetCurrentLine(void)
{
    /* Read current half-line under interrupt disable, wrap by timing nhlines, and return the line number. */
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
    return VIGetTvFormatInline();
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

void __VIDisplayPositionToXY(s32 hpos, s32 vpos, s16 *px, s16 *py)
{
    /* Convert a display (hpos,vpos) to XY using current timing/interlace state, or -1 if in blanking. */
    u32 index = (u32)(vpos - 1) * 2 + (u32)(hpos - 1) / lbl_8055DBA0->hlw;

    if (HorVer.nonInter == 0) {
        if (index < lbl_8055DBA0->nhlines) {
            if (index < lbl_8055DBA0->equ * 3 + lbl_8055DBA0->prbOdd) {
                *py = -1;
            } else if (index >= lbl_8055DBA0->nhlines - lbl_8055DBA0->psbOdd) {
                *py = -1;
            } else {
                *py = ((index - lbl_8055DBA0->equ * 3) - lbl_8055DBA0->prbOdd) & ~1;
            }
        } else {
            index -= lbl_8055DBA0->nhlines;
            if (index < lbl_8055DBA0->equ * 3 + lbl_8055DBA0->prbEven) {
                *py = -1;
            } else if (index >= lbl_8055DBA0->nhlines - lbl_8055DBA0->psbEven) {
                *py = -1;
            } else {
                *py = (((index - lbl_8055DBA0->equ * 3) - lbl_8055DBA0->prbEven) & ~1) + 1;
            }
        }
    } else if (HorVer.nonInter == 1) {
        if (index >= lbl_8055DBA0->nhlines) {
            index -= lbl_8055DBA0->nhlines;
        }
        if (index < lbl_8055DBA0->equ * 3 + lbl_8055DBA0->prbOdd) {
            *py = -1;
        } else if (index >= lbl_8055DBA0->nhlines - lbl_8055DBA0->psbOdd) {
            *py = -1;
        } else {
            *py = ((index - lbl_8055DBA0->equ * 3) - lbl_8055DBA0->prbOdd) & ~1;
        }
    } else if (HorVer.nonInter == 2) {
        if (index < lbl_8055DBA0->nhlines) {
            if (index < lbl_8055DBA0->equ * 3 + lbl_8055DBA0->prbOdd) {
                *py = -1;
            } else if (index >= lbl_8055DBA0->nhlines - lbl_8055DBA0->psbOdd) {
                *py = -1;
            } else {
                *py = (index - lbl_8055DBA0->equ * 3) - lbl_8055DBA0->prbOdd;
            }
        } else {
            index -= lbl_8055DBA0->nhlines;
            if (index < lbl_8055DBA0->equ * 3 + lbl_8055DBA0->prbEven) {
                *py = -1;
            } else if (index >= lbl_8055DBA0->nhlines - lbl_8055DBA0->psbEven) {
                *py = -1;
            } else {
                *py = ((index - lbl_8055DBA0->equ * 3) - lbl_8055DBA0->prbEven) & ~1;
            }
        }
    }
    *px = hpos - 1;
}

s32 fn_8005B00C(void) {
    lbl_8055DBBC = 0;
    return 1;
}

s32 fn_8005B01C(void) {
    lbl_8055DBB8 = 0;
    return 1;
}

/* Busy-wait until at least `microseconds` have elapsed, measured from OS system time. */
void WaitMicroTime(s32 microseconds) DECOMP_DONT_INLINE
{
    OSTime start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < microseconds) {
    }
}

// Bit-bangs one I2C address byte to the AVE video encoder on the GPIO1B pins
// and reads the slave's acknowledge: addr is the whole address byte (7 bit
// address with the read/write bit in it), sent most significant bit first, one
// bit per pulse of GPIO_AVE_SCL.  Returns 1 when the slave pulled SDA low to
// acknowledge, 0 when it kept the line high.  Every level is timed by polling
// the time base, so the caller (__VISendI2CData) has interrupts disabled.
u32 sendSlaveAddr(u32 addr)
{
    u32 gpio_out;
    OSTime start;
    s32 i;

    // start: SDA to its idle level for this board, then SCL low
    if (viI2cSdaNonInverted == 0) {
        gpio_out = IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA;
        IPC_HW_REGS[IPC_GPIO1BOUT] = gpio_out | GPIO_AVE_SDA;
    } else {
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
    }
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {} // WaitMicroTime(2), inlined
    IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SCL;

    for (i = 0; i < 8; i++) {
        // the bit to send, complemented when the SDA line is inverted
        if (addr & 0x80) {
            if (viI2cSdaNonInverted == 0)
                IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
            else
                IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
        } else {
            if (viI2cSdaNonInverted == 0)
                IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
            else
                IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
        }
        start = __OSGetSystemTime();
        while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {} // data set up, ...
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SCL) | GPIO_AVE_SCL;
        start = __OSGetSystemTime();
        while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {} // ... clocked, ...
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SCL;                 // ... and clock low
        addr = (u8)(addr << 1);                                      // next bit, MSB first
    }

    // ninth clock: hand SDA over to the slave and see whether it answers
    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | GPIO_AVE_SCL;
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SCL) | GPIO_AVE_SCL;
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    if (viI2cSdaNonInverted == 1 && ((IPC_HW_REGS[IPC_GPIO1BIN] >> 15) & 1))
        return 0; // SDA still high: no acknowledge

    // release SDA back at its idle level, both lines outputs again, clock low
    if (*(volatile u32 *)&viI2cSdaNonInverted == 0)
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
    else
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | (GPIO_AVE_SDA | GPIO_AVE_SCL);
    IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SCL;
    return 1;
}

// Cleared at boot; set by the first __VISendI2CData, which uses it to pick the
// SDA polarity (viI2cSdaNonInverted, above) once and for all before touching
// the bus. Nothing else in the game writes either of the two.
#define viI2cBusUsed lbl_8055DBD8

// Writes size bytes to an I2C slave - always the AVE video encoder, whose
// address 0xE0 the callers pass - by bit-banging the GPIO1B clock and data
// lines, with interrupts off so nothing stretches a pulse. The transfer is a
// start condition and the address byte (sendSlaveAddr), then one byte at a
// time, most significant bit first, each followed by a ninth clock whose SDA
// level is the slave's acknowledge, and finally a stop condition: SDA released
// while the clock is high. Returns 1 when every byte was acknowledged, and 0
// as soon as one acknowledge is missing.
s32 __VISendI2CData(u8 addr, u8 *data, s32 size)
{
    OSTime start;
    s32 i;
    u8 byte;
    BOOL enabled;

    // first transfer on this bus: settle on the non-inverted SDA polarity
    if (!viI2cBusUsed) {
        viI2cSdaNonInverted = 1;
        viI2cBusUsed = 1;
    }
    enabled = OSDisableInterrupts();
    // both lines driven, clock idle high, ...
    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | (GPIO_AVE_SCL | GPIO_AVE_SDA);
    IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SCL) | GPIO_AVE_SCL;
    // ... and SDA at its idle level
    if (viI2cSdaNonInverted == 0) {
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
    } else {
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
    }
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}

    // start condition + address byte; give up when the slave stays silent
    if (!sendSlaveAddr(addr)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | (GPIO_AVE_SCL | GPIO_AVE_SDA);

    while (size != 0) {
        byte = *data++;
        for (i = 0; i < 8; i++) {
            // the bit to send, complemented when the SDA line is inverted
            if (byte & 0x80) {
                if (viI2cSdaNonInverted == 0) {
                    IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
                } else {
                    IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
                }
            } else {
                if (viI2cSdaNonInverted == 0) {
                    IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
                } else {
                    IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
                }
            }
            start = __OSGetSystemTime();
            while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {} // data set up, ...
            IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SCL) | GPIO_AVE_SCL;
            start = __OSGetSystemTime();
            while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {} // ... clocked, ...
            byte = (u8)(byte << 1);
            IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SCL;                 // ... and clock low
        }

        // ninth clock: hand SDA over to the slave and see whether it answers
        IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | GPIO_AVE_SCL;
        start = __OSGetSystemTime();
        while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SCL) | GPIO_AVE_SCL;
        start = __OSGetSystemTime();
        while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}

        if (viI2cSdaNonInverted == 1 && ((IPC_HW_REGS[IPC_GPIO1BIN] >> 15) & 1)) {
            // GPIO_AVE_SDA still high: the slave did not acknowledge
            OSRestoreInterrupts(enabled);
            return 0;
        }

        // SDA back to its idle level, driven again, clock low for the next byte
        if (viI2cSdaNonInverted == 0) {
            IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
        } else {
            IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
        }
        size--;
        IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | (GPIO_AVE_SCL | GPIO_AVE_SDA);
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SCL;
    }

    // stop: SDA to its other level, clock high, then release SDA while it stays high
    IPC_HW_REGS[IPC_GPIO1BDIR] = (IPC_HW_REGS[IPC_GPIO1BDIR] & ~GPIO_AVE_SDA) | (GPIO_AVE_SCL | GPIO_AVE_SDA);
    if (viI2cSdaNonInverted == 0) {
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
    } else {
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
    }
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SCL) | GPIO_AVE_SCL;
    start = __OSGetSystemTime();
    while (OS_TICKS_TO_USEC(__OSGetSystemTime() - start) < 2) {}
    if (viI2cSdaNonInverted == 0) {
        IPC_HW_REGS[IPC_GPIO1BOUT] &= ~GPIO_AVE_SDA;
    } else {
        IPC_HW_REGS[IPC_GPIO1BOUT] = (IPC_HW_REGS[IPC_GPIO1BOUT] & ~GPIO_AVE_SDA) | GPIO_AVE_SDA;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

void __VISetYUVSEL(u8 value)
{
    /* Program the VI encoder YUV select over I2C, choosing mode based on the current TV format. */
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

void __VISetMacrovision(void) {
    register u8 *base asm("r3") = (u8*)lbl_80311B50;
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
            register volatile u8 *src asm("r30") = (volatile u8 *)(base + 0x420);
            register u32 header asm("r31") = 0x40;
            u32 t0;
            u32 t1;
            u32 t2;
            u32 t3;
            u32 t4;
            u32 t5;
            u32 t6;
            u32 t7;
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
            payload0[0] = header;
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
            volatile u8 *src = (volatile u8 *)(base + 0x3CC);
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
    /* Pack gamma table/coefficients into I2C payload (cmd 0x10) and send to AVE. */
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

void fn_8005CB70(void)
{
	__VISetGammaImm((u8*)&lbl_80311B50 + lbl_8055DBE8 * 0x22);
}

void __VISetTrapFilter(void)
{
    u8 data[2];

    data[0] = 3;
    if (lbl_80558FD0[0] == 1) {
        data[1] = 0;
    } else {
        data[1] = 1;
    }
    __VISendI2CData(0xE0, data, 2);
    WaitMicroTime(2);
}

void __VISetRGBOverDrive(void)
{
    /* Configure AVE RGB overdrive via I2C register 0x0A. */
    u8 cmd[2];

    if ((s32)lbl_8055DBF0 == 3) {
        cmd[0] = 10;
        cmd[1] = (lbl_8055DBE4 * 2) | 1;
        __VISendI2CData(0xE0, cmd, 2);
        WaitMicroTime(2);
    } else {
        cmd[0] = 10;
        cmd[1] = 0;
        __VISendI2CData(0xE0, cmd, 2);
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

void __VISetRevolutionModeSimple(void)
{
    u8 a[2], b[2], c[2], d[3], e[2], f[3], g[3], h[5], j[2], k[2];
    volatile u8 i[27];
    a[0]=0x6a; a[1]=1; __VISendI2CData(0xe0,a,2); WaitMicroTime(2);
    b[0]=0x65; b[1]=1; __VISendI2CData(0xe0,b,2); WaitMicroTime(2);
    __VISetYUVSEL((u8)fn_8005AD9C());
    c[0]=0; c[1]=0; __VISendI2CData(0xe0,c,2); WaitMicroTime(2);
    d[0]=0x71; d[1]=0x8e; d[2]=0x8e; __VISendI2CData(0xe0,d,3); WaitMicroTime(2);
    e[0]=2; e[1]=7; __VISendI2CData(0xe0,e,2); WaitMicroTime(2);
    lbl_80558FC0=0; lbl_80558FC1=0; lbl_80558FC2=0;
    f[0]=5; f[1]=0; f[2]=0; __VISendI2CData(0xe0,f,3); WaitMicroTime(2);
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
t8=src[24]; t9=src[25]; i[0]=0x40;
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

#include <revolution/VI/vi_data_gamma.inc>
