#include <types.h>

extern void **OSExceptionTable_8055D9D0;
extern void OSExceptionVector(void);
extern void OSReport(const char *, ...);
extern u32 OSGetConsoleType(void);
extern u32 OSGetConsoleSimulatedMem1Size(void);
extern u32 OSGetConsoleSimulatedMem2Size(void);
extern void *OSGetMEM1ArenaLo(void);
extern void *OSGetMEM1ArenaHi(void);
extern void *OSGetMEM2ArenaLo(void);
extern void *OSGetMEM2ArenaHi(void);

typedef enum {
    OS_CONSOLE_MASK = 0xF0000000,
    OS_CONSOLE_MASK_RVL = 0x00000000,
    OS_CONSOLE_MASK_EMU = 0x10000000,
    OS_CONSOLE_MASK_TDEV = 0x20000000,

    OS_CONSOLE_RVL_PP_1 = 0x00000011,
    OS_CONSOLE_RVL_PP_2_1 = 0x00000012,
    OS_CONSOLE_RVL_PP_2_2 = 0x00000020,

    OS_CONSOLE_RVL_EMU = 0x10000008,
    OS_CONSOLE_NDEV_1_0 = 0x10000010,
    OS_CONSOLE_NDEV_1_1 = 0x10000011,
    OS_CONSOLE_NDEV_1_2 = 0x10000012,
    OS_CONSOLE_NDEV_2_0 = 0x10000020,
    OS_CONSOLE_NDEV_2_1 = 0x10000021
} OSConsoleType_Report;

typedef struct {
    u8 idHi;
    u8 idLo;
    u8 verMajor;
    u8 verMinor;
    u8 buildMon;
    u8 buildDay;
    u16 buildYear;
} OSIOSRev_Report;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void __OSGetIOSRev(void *arg_rev) {
    OSIOSRev_Report *rev = (OSIOSRev_Report *)arg_rev;
    u32 version = *(u32 *)0xC0003140;
    u32 builddate = *(u32 *)0xC0003144;

    rev->idHi = version >> 24;
    rev->idLo = (version >> 16) & 0xFF;
    rev->verMajor = (version >> 8) & 0xFF;
    rev->buildMon = (builddate >> 16) & 0xFF;
    rev->buildDay = ((builddate >> 12) & 0xF) * 10 + ((builddate >> 8) & 0xF);
    rev->buildYear = (builddate & 0xFF) + 2000;
    rev->verMinor = version;
}

void ReportOSInfo_8004AA40(void) {
    u32 type;
    OSIOSRev_Report rev;
    u32 category;
    u32 tdev;

    OSReport("\nRevolution OS\n");
    OSReport("Kernel built : %s %s\n", "Sep 21 2006", "14:32:13");

    OSReport("Console Type : ");
    type = OSGetConsoleType();
    category = type & OS_CONSOLE_MASK;
    switch (category) {
    case OS_CONSOLE_MASK_RVL:
        switch (type) {
        case OS_CONSOLE_RVL_PP_1:
            OSReport("Pre-production board 1\n");
            break;
        case OS_CONSOLE_RVL_PP_2_1:
            OSReport("Pre-production board 2-1\n");
            break;
        case OS_CONSOLE_RVL_PP_2_2:
            OSReport("Pre-production board 2-2\n");
            break;
        default:
            OSReport("Retail %d\n", type);
            break;
        }
        break;
    case OS_CONSOLE_MASK_EMU:
        switch (type) {
        case OS_CONSOLE_NDEV_2_1:
            OSReport("NDEV 2.1\n");
            break;
        case OS_CONSOLE_NDEV_2_0:
            OSReport("NDEV 2.0\n");
            break;
        case OS_CONSOLE_NDEV_1_2:
            OSReport("NDEV 1.2\n");
            break;
        case OS_CONSOLE_NDEV_1_1:
            OSReport("NDEV 1.1\n");
            break;
        case OS_CONSOLE_NDEV_1_0:
            OSReport("NDEV 1.0\n");
            break;
        case OS_CONSOLE_RVL_EMU:
            OSReport("Revolution Emulator\n");
            break;
        default:
            OSReport("Emulation platform (%08x)\n", type);
            break;
        }
        break;
    case OS_CONSOLE_MASK_TDEV:
        tdev = type & 0x0FFFFFFF;
        OSReport("TDEV-based emulation HW%d\n", tdev - 3);
        break;
    default:
        OSReport("%08x\n", type);
        break;
    }

    __OSGetIOSRev((char *)&rev);
    OSReport("Firmware     : %d.%d.%d ", rev.idLo, rev.verMajor, rev.verMinor);
    OSReport("(%d/%d/%d)\n", rev.buildMon, rev.buildDay, rev.buildYear);

    OSReport("Memory %d MB\n", (OSGetConsoleSimulatedMem1Size() + OSGetConsoleSimulatedMem2Size()) >> 20);
    OSReport("MEM1 Arena : 0x%x - 0x%x\n", OSGetMEM1ArenaLo(), OSGetMEM1ArenaHi());
    OSReport("MEM2 Arena : 0x%x - 0x%x\n", OSGetMEM2ArenaLo(), OSGetMEM2ArenaHi());
}

void __OSDBIntegrator(void) {
    volatile u32 *p = (volatile u32 *)0x48;
    * (volatile u32 *)0x4C = __builtin_return_address(0);
    *(volatile u32 *)0x48 |= 0x80000000;
    __builtin_unreachable();
}

extern void __OSDBJump(void) {
    OSExceptionVector();
}

#pragma small_data on
void *__OSSetExceptionHandler(u8 type, void *handler) {
    void *old = OSExceptionTable_8055D9D0[type];
    OSExceptionTable_8055D9D0[type] = handler;
    return old;
}

extern void **OSExceptionTable_8055D9D0;
#pragma small_data on
void *__OSGetExceptionHandler(s32 arg0) {
    return OSExceptionTable_8055D9D0[(u8)arg0];
}

void __OSPSInit(void) {
    PPCMthid2(PPCMfhid2() | 0xA0000000);
    ICFlashInvalidate();
    __sync();
    OSInitFastCast();
}

u32 __OSGetDIConfig(void) {
    return *(volatile u32 *)0xCD006024 & 0xFF;
}

extern void OSReport(const char *, ...);
extern const char lbl_80558F0C[];
extern const char lbl_80558F0C[4];
void OSRegisterVersion(const char *ver) {
    OSReport(lbl_80558F0C, ver);
}

extern BOOL __OSInIPL;
extern const char *AppGameNameForSysMenu;
extern char GameNameBuffer[5];
extern u8 DriveInfo[4];
u8 OSGetAppType(void) {
    if (__OSInIPL) return 0x40;
    return *(u8 *)0x80003184;
}

