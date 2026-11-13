#include <types.h>
#include <revolution/OS/OSHardware.h>
#include <revolution/OS/OSMemory.h>
#include <revolution/BASE/PPCArch.h>
#include <revolution/OS/OSContext.h>

void __OSDBJUMPSTART(void);
void __OSDBJUMPDEST(void);
void __OSDBJUMPEND(void);
void __OSEVStart(void);
void __DBVECTOR(void);
void __OSEVSetNumber(void);
void __OSEVEnd(void);

extern char DriveInfo[];

extern BOOL __OSInIPL;
extern const char lbl_80558F0C[4];

extern void **OSExceptionTable_8055D9D0;
extern void OSReport(const char *, ...);
extern u32 OSGetConsoleType(void);
extern u32 OSGetConsoleSimulatedMem1Size(void);
extern u32 OSGetConsoleSimulatedMem2Size(void);
extern void *OSGetMEM1ArenaLo(void);
extern void *OSGetMEM1ArenaHi(void);
extern void *OSGetMEM2ArenaLo(void);
extern void *OSGetMEM2ArenaHi(void);

const char *__OSVersion = "<< RVL_SDK - OS \trelease build: Sep 21 2006 14:32:13 (0x4200_60422) >>\0";

// Copy of <revolution/OS/OS.h>'s OSConsoleType.  This unit keeps its own
// because OS.h also declares __OSGetIOSRev(OSIOSRev*), which this file
// declares as taking a void*.  Top nibble of the type picks the kind of
// hardware: 0 = retail RVL board, 1 = emulator/dev (OS_CONSOLE_MASK_EMU),
// 2 = TDEV; the low byte is the board revision (0x1x = "1", 0x2x = "2").
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

/*
 * OSGetConsoleType - what kind of hardware is this running on?
 *
 * Returns an OSConsoleType.  Normally that is just the value the boot info
 * left in its consoleType field (OSInit points BootInfo_8055D9F8 at
 * OS_BOOT_INFO, i.e. the boot ROM's info block in MEM1).  When there is no
 * boot info to ask, the type is worked out here instead: the DVD drive's
 * device code says whether a real drive is fitted (its "read" bit set means
 * a retail drive, so the answer carries no OS_CONSOLE_MASK_EMU bit), and the
 * Hollywood revision picks the board revision - 0-2 are the "1" boards,
 * 0x10-0x11 the "2" boards, and anything newer counts as the newest one.
 * With no usable drive either, 64MB of MEM2 means a retail board and less
 * means an emulator/dev board.
 */
u32 OSGetConsoleType(void) {
    extern void *BootInfo_8055D9F8;
    u32 hollywood;
    u32 mem2size;
    u32 deviceCode;

    if (BootInfo_8055D9F8 == 0 ||
        ((OSBootInfo*)BootInfo_8055D9F8)->consoleType == 0) {
        return 0x10000002;  // no boot info: dev board
    }

    deviceCode = OS_DVD_DEVICE_CODE;
    hollywood = OS_HOLLYWOOD_REV;

    if (deviceCode & DVD_DEVICE_CODE_READ) {
        // Re-read the code: only a drive that answers tells us anything.
        switch (OS_DVD_DEVICE_CODE & ~DVD_DEVICE_CODE_READ) {
        case 0x0002:
        case 0x0003:
        case 0x0203:
            // Retail drive: retail (RVL) board types.
            switch (hollywood) {
            case 0x00000000:
                return 0x00000010;
            case 0x00000001:
                return OS_CONSOLE_RVL_PP_1;
            case 0x00000002:
                return OS_CONSOLE_RVL_PP_2_1;
            case 0x00000010:
                return OS_CONSOLE_RVL_PP_2_2;
            case 0x00000011:
                return 0x00000021;
            }

            if (hollywood > 0x00000011) {
                return 0x00000021;
            }

        case 0x0202:
        case 0x0201:
            // Dev drive: same boards, flagged as emulator/dev hardware.
            switch (hollywood) {
            case 0x00000000:
                return OS_CONSOLE_NDEV_1_0;
            case 0x00000001:
                return OS_CONSOLE_NDEV_1_1;
            case 0x00000002:
                return OS_CONSOLE_NDEV_1_2;
            case 0x00000010:
                return OS_CONSOLE_NDEV_2_0;
            case 0x00000011:
                return OS_CONSOLE_NDEV_2_1;
            }

            if (hollywood > 0x00000011) {
                return OS_CONSOLE_NDEV_2_1;
            }
        }
    }

    // No drive to ask: the MEM2 size tells retail from emulator.
    mem2size = OSGetPhysicalMem2Size();

    switch (hollywood) {
    case 0x00000000:
        if (mem2size == OS_MEM_MB_TO_B(64)) {
            return 0x00000010;
        }
        return OS_CONSOLE_NDEV_1_0;
    case 0x00000001:
        if (mem2size == OS_MEM_MB_TO_B(64)) {
            return OS_CONSOLE_RVL_PP_1;
        }
        return OS_CONSOLE_NDEV_1_1;
    case 0x00000002:
        if (mem2size == OS_MEM_MB_TO_B(64)) {
            return OS_CONSOLE_RVL_PP_2_1;
        }
        return OS_CONSOLE_NDEV_1_2;
    case 0x00000010:
        if (mem2size == OS_MEM_MB_TO_B(64)) {
            return OS_CONSOLE_RVL_PP_2_2;
        }
        return OS_CONSOLE_NDEV_2_0;
    case 0x00000011:
        if (mem2size == OS_MEM_MB_TO_B(64)) {
            return 0x00000021;
        }
        return OS_CONSOLE_NDEV_2_1;
    }

    if (hollywood > 0x00000011) {
        if (mem2size == OS_MEM_MB_TO_B(64)) {
            return 0x00000021;
        }
        return OS_CONSOLE_NDEV_2_1;
    }

    return ((OSBootInfo*)BootInfo_8055D9F8)->consoleType;
}

extern unsigned int OSGetResetCode(void);
extern unsigned int OSGetArenaHi(void);
extern unsigned int OSGetArenaLo(void);
extern void DCZeroRange(const void *, unsigned int);
extern void DCFlushRange(unsigned int, unsigned int);
extern unsigned int __OSRebootParams[];
static inline unsigned int AddBaseOffset(unsigned int base, unsigned int offset);

static inline void ClearMEM2Range(void *mem, u32 size) {
    void *flush = (0x40000 < size) ? (u8 *)((u32)mem + (size - 0x40000)) : mem;
    DCZeroRange(mem, size);
    DCFlushRange((u32)flush, 0x40000);
}
#pragma push
#pragma scheduling invalid_target
void ClearArena(void) {
    unsigned int reset;
    unsigned int base;
    unsigned int flush;
    unsigned int size;
    reset = OSGetResetCode();

    if ((reset >> 31) == 0) {
        size = OSGetArenaHi();
        size -= OSGetArenaLo();
        base = OSGetArenaLo();
        if (size <= 0x40000)
            goto clear0_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear0_join;
    clear0_small:
        flush = base;
    clear0_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
        return;
    }

    if (__OSRebootParams[3] == 0 || (__OSRebootParams[3] & 0x30000000) != 0) {
        size = OSGetArenaHi();
        size -= OSGetArenaLo();
        base = OSGetArenaLo();
        if (size <= 0x40000)
            goto clear1_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear1_join;
    clear1_small:
        flush = base;
    clear1_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
        return;
    }

    if (OSGetArenaLo() >= __OSRebootParams[3])
        return;

    if (OSGetArenaHi() <= __OSRebootParams[3]) {
        size = OSGetArenaHi();
        size -= OSGetArenaLo();
        base = OSGetArenaLo();
        if (size <= 0x40000)
            goto clear2_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear2_join;
    clear2_small:
        flush = base;
    clear2_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
        return;
    }

    size = __OSRebootParams[3] - OSGetArenaLo();
    base = OSGetArenaLo();
    if (size <= 0x40000)
        goto clear3_small;
    flush = size - 0x40000;
    flush = base + flush;
    goto clear3_join;
clear3_small:
    flush = base;
clear3_join:
    DCZeroRange((void *)base, size);
    DCFlushRange(flush, 0x40000);

    base = __OSRebootParams[4];
    if (OSGetArenaHi() > base) {
        size = OSGetArenaHi();
        size -= base;
        if (size <= 0x40000)
            goto clear4_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear4_join;
    clear4_small:
        flush = base;
    clear4_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void ClearMEM2Arena(void) {
    unsigned int reset = OSGetResetCode();
    unsigned int base;
    unsigned int flush;
    unsigned int size;

    if ((reset >> 31) == 0) {
        size = (unsigned int)OSGetMEM2ArenaHi();
        size -= (unsigned int)OSGetMEM2ArenaLo();
        base = (unsigned int)OSGetMEM2ArenaLo();
        if (size <= 0x40000)
            goto clear0_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear0_join;
    clear0_small:
        flush = base;
    clear0_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
        return;
    }

    if (__OSRebootParams[3] == 0 ||
        (__OSRebootParams[3] & 0x30000000) != 0x10000000) {
        size = (unsigned int)OSGetMEM2ArenaHi();
        size -= (unsigned int)OSGetMEM2ArenaLo();
        base = (unsigned int)OSGetMEM2ArenaLo();
        if (size <= 0x40000)
            goto clear1_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear1_join;
    clear1_small:
        flush = base;
    clear1_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
        return;
    }

    if ((unsigned int)OSGetMEM2ArenaLo() >= __OSRebootParams[3])
        return;

    if ((unsigned int)OSGetMEM2ArenaHi() <= __OSRebootParams[3]) {
        size = (unsigned int)OSGetMEM2ArenaHi();
        size -= (unsigned int)OSGetMEM2ArenaLo();
        base = (unsigned int)OSGetMEM2ArenaLo();
        if (size <= 0x40000)
            goto clear2_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear2_join;
    clear2_small:
        flush = base;
    clear2_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
        return;
    }

    size = __OSRebootParams[3] - (unsigned int)OSGetMEM2ArenaLo();
    base = (unsigned int)OSGetMEM2ArenaLo();
    if (size <= 0x40000)
        goto clear3_small;
    flush = size - 0x40000;
    flush = base + flush;
    goto clear3_join;
clear3_small:
    flush = base;
clear3_join:
    DCZeroRange((void *)base, size);
    DCFlushRange(flush, 0x40000);

    base = __OSRebootParams[4];
    if ((unsigned int)OSGetMEM2ArenaHi() > base) {
        size = (unsigned int)OSGetMEM2ArenaHi();
        size -= base;
        if (size <= 0x40000)
            goto clear4_small;
        flush = size - 0x40000;
        flush = base + flush;
        goto clear4_join;
    clear4_small:
        flush = base;
    clear4_join:
        DCZeroRange((void *)base, size);
        DCFlushRange(flush, 0x40000);
    }
}
#pragma pop
#pragma push
#pragma small_data off
void InquiryCallback(s32 result, struct DVDCommandBlock* arg1) {
    switch (*(u32*)((u8*)arg1 + 0xC)) {
    case 0:
        *(u16*)0x800030E6 = *(u16*)(DriveInfo + 2) | 0x8000;
        break;
    default:
        *(u16*)0x800030E6 = 1;
        break;
    }
}
#pragma small_data on
extern const char lbl_80558F04[];
#pragma small_data on
extern const char lbl_80558F04[6];
#pragma small_data on

void ReportOSInfo_8004AA40(void) {
    u32 type;
    u32 version;
    u32 builddate;

    OSReport("\nRevolution OS\n");
    OSReport("Kernel built : %s %s\n\0\0", "Sep 21 2006", "14:32:13\0\0\0");

    OSReport("Console Type : ");
    type = OSGetConsoleType();
    switch (type & OS_CONSOLE_MASK) {
    case OS_CONSOLE_MASK_RVL:
        switch (type) {
        case OS_CONSOLE_RVL_PP_1:
            OSReport("Pre-production board 1\n");
            break;
        case OS_CONSOLE_RVL_PP_2_1:
            OSReport("Pre-production board 2-1\n\0\0");
            break;
        case OS_CONSOLE_RVL_PP_2_2:
            OSReport("Pre-production board 2-2\n\0\0");
            break;
        default:
            OSReport("Retail %d\n\0", type);
            break;
        }
        break;
    case OS_CONSOLE_MASK_EMU:
        switch (type) {
        case OS_CONSOLE_NDEV_2_1:
            OSReport("NDEV 2.1\n\0\0");
            break;
        case OS_CONSOLE_NDEV_2_0:
            OSReport("NDEV 2.0\n\0\0");
            break;
        case OS_CONSOLE_NDEV_1_2:
            OSReport("NDEV 1.2\n\0\0");
            break;
        case OS_CONSOLE_NDEV_1_1:
            OSReport("NDEV 1.1\n\0\0");
            break;
        case OS_CONSOLE_NDEV_1_0:
            OSReport("NDEV 1.0\n\0\0");
            break;
        case OS_CONSOLE_RVL_EMU:
            OSReport("Revolution Emulator\n\0\0\0");
            break;
        default:
            OSReport("Emulation platform (%08x)\n\0", type);
            break;
        }
        break;
    case OS_CONSOLE_MASK_TDEV:
        OSReport("TDEV-based emulation HW%d\n\0", (type & 0x0FFFFFFF) - 3);
        break;
    default:
        OSReport(lbl_80558F04, type);
        break;
    }

    version = *(u32 *)0xC0003140;
    builddate = *(u32 *)0xC0003144;
    OSReport("Firmware     : %d.%d.%d \0\0\0", (version >> 16) & 0xFF, (version >> 8) & 0xFF, version & 0xFF);
    {
        u32 day_hi = (builddate >> 12) & 0xF;
        u32 year_lo = builddate & 0xFF;
        u32 day_hi_10 = day_hi * 10;
        u32 day_lo = (builddate >> 8) & 0xF;
        u16 year = year_lo + 2000;
        u8 day = day_lo + day_hi_10;
        u8 mon = (builddate >> 16) & 0xFF;
        OSReport("(%d/%d/%d)\n", mon, day, year);
    }

    OSReport("Memory %d MB\n\0\0", (OSGetConsoleSimulatedMem1Size() + OSGetConsoleSimulatedMem2Size()) >> 20);
    OSReport("MEM1 Arena : 0x%x - 0x%x\n\0\0", OSGetMEM1ArenaLo(), OSGetMEM1ArenaHi());
    OSReport("MEM2 Arena : 0x%x - 0x%x\n", OSGetMEM2ArenaLo(), OSGetMEM2ArenaHi());
}

#pragma push
#pragma small_data on
extern BOOL AreWeInitialized_8055D9CC;
extern u32 BI2DebugFlagHolder_8055D9F0;
extern u32* BI2DebugFlag_8055D9F4;
extern void* BootInfo_8055D9F8;
extern u32 __PADSpec;
extern u64 __OSStartTime;
extern u64 __OSGetSystemTime(void);
extern u8 __ArenaLo[];
extern u8 __ArenaHi[];
extern u8 _stack_addr[];
extern BOOL __OSInNandBoot;
extern BOOL __OSIsGcam;
extern BOOL __OSInReboot;
extern BOOL __DVDLongFileNameFlag;
extern void OSExceptionInit(void);
extern void ClearMEM2Arena(void);
extern void __OSInitIPCBuffer(void);
extern void __OSInitSystemCall(void);
extern void __OSInitAlarm(void);
extern void __OSModuleInit(void);
extern void __OSInterruptInit(void);
extern void __OSContextInit(void);
extern void __OSCacheInit(void);
extern void EXIInit(void);
extern void SIInit(void);
extern void __OSInitSram(void);
extern void __OSThreadInit(void);
extern void __OSInitAudioSystem(void);
extern void PPCMtmmcr0(u32);
extern void PPCMtmmcr1(u32);
extern void PPCMtpmc1(u32);
extern void PPCMtpmc2(u32);
extern void PPCMtpmc3(u32);
extern void PPCMtpmc4(u32);
extern void PPCMthid4(u32);
extern void PPCDisableSpeculation(void);
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32);
extern void PPCSetFpNonIEEEMode(void);
extern void __OSInitMemoryProtection(void);
extern void EnableMetroTRKInterrupts(void);
extern void OSEnableInterrupts(void);
extern void IPCCltInit(void);
extern void __OSInitSTM(void);
extern void SCInit(void);
extern u32 SCCheckStatus(void);
extern void DVDInit(void);
extern void DCInvalidateRange(void*, u32);
struct DVDCommandBlock;
struct DVDDriveInfo;
extern BOOL DVDInquiryAsync(struct DVDCommandBlock*, struct DVDDriveInfo*, void (*)(s32, struct DVDCommandBlock*));
extern void InquiryCallback(s32, struct DVDCommandBlock*);
extern void __OSStartPlayRecord(void);
extern void OSSetMEM1ArenaLo(void*);
extern void OSSetMEM1ArenaHi(void*);
extern void OSSetMEM2ArenaLo(void*);
extern void OSSetMEM2ArenaHi(void*);
extern void OSPanic(const char*, s32, const char*, ...);
void OSInit(void) {
    OSBI2* bi2;
    u8* rebootParams = (u8*)__OSRebootParams;
    void* mem1lo;
    void* mem1hi;
    void* mem2lo;
    void* mem2hi;

    if (!AreWeInitialized_8055D9CC) {
        AreWeInitialized_8055D9CC = 1;
        __OSStartTime = __OSGetSystemTime();
        OSDisableInterrupts();
        __OSGetExecParams(rebootParams);
        PPCMtmmcr0(0);
        PPCMtmmcr1(0);
        PPCMtpmc1(0);
        PPCMtpmc2(0);
        PPCMtpmc3(0);
        PPCMtpmc4(0);
        PPCMthid4(0x83900000);
        PPCDisableSpeculation();
        PPCSetFpNonIEEEMode();
        BootInfo_8055D9F8 = (OSBootInfo*)0x80000000;
        BI2DebugFlag_8055D9F4 = NULL;
        __DVDLongFileNameFlag = 0;
        bi2 = *(OSBI2**)OSPhysicalToCached(OS_PHYS_DVD_BI2);
        if (bi2 != NULL) {
            BI2DebugFlag_8055D9F4 = &bi2->debugFlag;
            __PADSpec = bi2->padSpec;
            *(u8*)OSPhysicalToCached(OS_PHYS_BI2_DEBUG_FLAG) = *BI2DebugFlag_8055D9F4;
            *(u8*)OSPhysicalToCached(OS_PHYS_PAD_SPEC) = __PADSpec;
        } else if (((OSBootInfo*)BootInfo_8055D9F8)->arenaHi != NULL) {
            BI2DebugFlagHolder_8055D9F0 = *(u8*)0x800030E8;
            BI2DebugFlag_8055D9F4 = &BI2DebugFlagHolder_8055D9F0;
            __PADSpec = *(u8*)0x800030E9;
        }
        __DVDLongFileNameFlag = 1;
        mem1lo = *(void**)OSPhysicalToCached(OS_PHYS_USABLE_MEM1_START);
        if (mem1lo == NULL) {
            if (((u32)__ArenaLo & 0x30000000) == 0) {
                mem1lo = ((OSBootInfo*)BootInfo_8055D9F8)->arenaLo == NULL
                            ? __ArenaLo
                            : *(void**)((u8*)BootInfo_8055D9F8 + 0x30);
                if (*(void**)((u8*)*(void * volatile *)&BootInfo_8055D9F8 + 0x30) == NULL &&
                    BI2DebugFlag_8055D9F4 != NULL && *BI2DebugFlag_8055D9F4 < 2) {
                    mem1lo = (void*)(((u32)_stack_addr + 0x1F) & 0xFFFFFFE0);
                }
            } else {
                mem1lo = (void*)0x80004000;
            }
        }
        OSSetMEM1ArenaLo(mem1lo);
        mem1hi = *(void**)OSPhysicalToCached(OS_PHYS_USABLE_MEM1_END);
        if (mem1hi == NULL) {
            mem1hi = ((OSBootInfo*)BootInfo_8055D9F8)->arenaHi;
            if (mem1hi == NULL) {
                mem1hi = __ArenaHi;
            }
        }
        OSSetMEM1ArenaHi(mem1hi);
        mem2lo = *(void**)0x80003124;
        if (mem2lo != NULL) {
            if (((u32)__ArenaLo & 0x30000000) == 0x10000000) {
                mem2lo = __ArenaLo;
                if (BI2DebugFlag_8055D9F4 != NULL && *BI2DebugFlag_8055D9F4 < 2) {
                    mem2lo = (void*)(((u32)_stack_addr + 0x1F) & 0xFFFFFFE0);
                }
            } else if ((u32)mem2lo >= 0x90000000 && (u32)mem2lo < 0x90000800) {
                mem2lo = (void*)0x90000800;
            }
            OSSetMEM2ArenaLo(mem2lo);
        }
        mem2hi = *(void**)0x80003128;
        if (mem2hi != NULL) {
            OSSetMEM2ArenaHi(mem2hi);
        }
        __OSInitIPCBuffer();
        OSExceptionInit();
        __OSInitSystemCall();
        __OSInitAlarm();
        __OSModuleInit();
        __OSInterruptInit();
        __OSContextInit();
        __OSCacheInit();
        EXIInit();
        SIInit();
        __OSInitSram();
        __OSThreadInit();
        __OSInitAudioSystem();
        PPCMthid2(PPCMfhid2() & 0xBFFFFFFF);
        if (__OSInIPL == 0) {
            __OSInitMemoryProtection();
        }
        ReportOSInfo_8004AA40();
        OSReport(lbl_80558F0C, __OSVersion);
        if (BI2DebugFlag_8055D9F4 != NULL && *BI2DebugFlag_8055D9F4 >= 2) {
            EnableMetroTRKInterrupts();
        }
        ClearArena();
        ClearMEM2Arena();
        OSEnableInterrupts();
        IPCCltInit();
        if (__OSInNandBoot == 0 && __OSInReboot == 0) {
            __OSInitSTM();
            SCInit();
            while (SCCheckStatus() == 1) {
            }
        }
        if (__OSInIPL == 0) {
            switch (*(u8*)0x8000315C) {
            case 0x81:
                #line 1099 "src/revolution/OS/OS.c"
                // clang-format off
                OSReport("OS ERROR: boot program is not for RVL target. Please use "
                         "correct boot program.\n");
                OSPanic(__FILE__, __LINE__, "Failed to run app");
                break;
            case 0x80:
            default:
                break;
            }
            switch (*(u8*)0x8000315D) {
            case 0x81:
                #line 1117 "src/revolution/OS/OS.c"
                // clang-format off
                OSReport("OS ERROR: apploader[D].img is not for RVL target. Please use "
                         "correct apploader[D].img.\n");
                OSPanic(__FILE__, __LINE__, "Failed to run app");
                break;
            case 0x80:
            default:
                break;
            }
            DVDInit();
            if (__OSIsGcam != 0) {
                *(volatile u16*)0x800030E6 = 0x9000;
            } else if (*(volatile u16*)0x800030E6 == 0) {
                DCInvalidateRange(rebootParams + 0x20, 0x20);
                DVDInquiryAsync((void*)(rebootParams + 0x20), (void*)(rebootParams + 0x40), InquiryCallback);
            }
        }
        if (__OSInIPL == 0 && __OSInNandBoot == 0 && __OSInReboot == 0) {
            __OSStartPlayRecord();
        }
    }
}

extern void DBPrintf(const char *, ...);
extern u8 __DBIsExceptionMarked(u8);
extern void *memcpy(void *, const void *, unsigned int);
extern void DCFlushRangeNoSync(const void *, u32);
extern void ICInvalidateRange(const void *, u32);
extern void __OSDBINTSTART(void);
extern void __OSDBINTEND(void);
extern void *__OSSetExceptionHandler(u8, void *);
extern void OSDefaultExceptionHandler(u8, void *);
void OSExceptionInit(void) {
    u32 *pInst;
    u32 inst;
    void *vectorCode;
    u32 vectorSize;
    u32 *dst;
    u8 i;
    int j;
    u32 *code;
    u32 size2;
    pInst = (u32 *)__OSEVSetNumber;
    inst = *pInst;
    vectorCode = (void *)__OSEVStart;
    vectorSize = (u32)__OSEVEnd - (u32)__OSEVStart;
    dst = (u32 *)0x80000060;
    if (*dst == 0) {
        DBPrintf("Installing OSDBIntegrator\n");
        size2 = (u32)__OSDBINTEND - (u32)__OSDBINTSTART;
        memcpy(dst, (void *)__OSDBINTSTART, size2);
        DCFlushRangeNoSync(dst, size2);
        __sync();
        ICInvalidateRange(dst, size2);
    }
    for (i = 0; i < 15; i++) {
        if (BI2DebugFlag_8055D9F4 != 0 && *BI2DebugFlag_8055D9F4 >= 2 && __DBIsExceptionMarked(i)) {
            DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n", i);
        } else {
            *pInst = inst | i;
            if (__DBIsExceptionMarked(i)) {
                DBPrintf(">>> OSINIT: exception %d vectored to debugger\n", i);
                memcpy((void *)__DBVECTOR, (void *)__OSDBJUMPSTART, (u32)__OSDBJUMPEND - (u32)__OSDBJUMPSTART);
            } else {
                code = (u32 *)__DBVECTOR;
                for (j = 0; j < (u32)__OSDBJUMPEND - (u32)__OSDBJUMPSTART; j += 4, code++) {
                    *code = 0x60000000;
                }
            }
            dst = (u32 *)0x80000000;
            memcpy(dst, vectorCode, vectorSize);
            DCFlushRangeNoSync(dst, vectorSize);
            __sync();
            ICInvalidateRange(dst, vectorSize);
        }
    }
    OSExceptionTable_8055D9D0 = (void **)0x80003000;
    for (i = 0; i < 15; i++) {
        __OSSetExceptionHandler(i, (void *)OSDefaultExceptionHandler);
    }
    *pInst = inst;
    DBPrintf("Exceptions initialized...\n");
}

#pragma pop

void __OSDBIntegrator(void) {
    register volatile unsigned int *base = (volatile unsigned int *)0x40;
    base[3] = 0;
    base[2] |= 0x80000000;
    PPCMtmsr(0x30);
}

asm void __OSDBJump(void) {
    nofralloc
    entry __OSDBJUMPSTART
    bl __OSDBJUMPDEST
    entry __OSDBJUMPEND
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

void OSDefaultExceptionHandler(u8 exception, void *context);
asm void OSExceptionVector(void) {
    nofralloc
    entry __OSEVStart
    mtsprg0 r4
    lwz r4, 0x000000C0(0)
    stw r3, OSContext.gprs[3](r4)
    mfsprg0 r3
    stw r3, OSContext.gprs[4](r4)
    stw r5, OSContext.gprs[5](r4)
    lhz r3, OSContext.state(r4)
    ori r3, r3, 0x2
    sth r3, OSContext.state(r4)
    mfcr r3
    stw r3, OSContext.cr(r4)
    mflr r3
    stw r3, OSContext.lr(r4)
    mfctr r3

    entry __OSDBJUMPDEST

    stw r3, OSContext.ctr(r4)
    mfxer r3
    stw r3, OSContext.xer(r4)
    mfsrr0 r3
    stw r3, OSContext.srr0(r4)
    mfsrr1 r3
    stw r3, OSContext.srr1(r4)
    mr r5, r3

    entry __DBVECTOR

    nop
    mfmsr r3
    ori r3, r3, (MSR_IR | MSR_DR)
    mtsrr1 r3

    entry __OSEVSetNumber

    li r3, 0
    lwz r4, 0x000000D4(r0)
    rlwinm. r5, r5, 0, 30, 30
    bne lbl_800ECF70
    lis r5, OSDefaultExceptionHandler@ha;
    addi r5, r5, OSDefaultExceptionHandler@l;
    mtsrr0 r5
    rfi

lbl_800ECF70:
    rlwinm r5, r3, 2, 22, 29
    lwz r5, 0x3000(r5)
    mtsrr0 r5
    rfi

    entry __OSEVEnd

    nop
}

extern void __OSUnhandledException(u8, void *, u32, u32);
asm void OSDefaultExceptionHandler(u8 exception, void *context) {
    nofralloc
    stw r0, 0x0(r4)
    stw r1, 0x4(r4)
    stw r2, 0x8(r4)
    stmw r6, 0x18(r4)
    mfspr r0, GQR1
    stw r0, 0x1a8(r4)
    mfspr r0, GQR2
    stw r0, 0x1ac(r4)
    mfspr r0, GQR3
    stw r0, 0x1b0(r4)
    mfspr r0, GQR4
    stw r0, 0x1b4(r4)
    mfspr r0, GQR5
    stw r0, 0x1b8(r4)
    mfspr r0, GQR6
    stw r0, 0x1bc(r4)
    mfspr r0, GQR7
    stw r0, 0x1c0(r4)
    mfdsisr r5
    mfdar r6
    stwu r1, -0x8(r1)
    b __OSUnhandledException
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

const char *OSGetAppGamename(void) {
    extern const char *AppGameNameForSysMenu;
    extern char GameNameBuffer[5];
    const char *name = (const char *)0x80003180;
    if (__OSInIPL) {
        name = AppGameNameForSysMenu;
    }
    GameNameBuffer[0] = name[0];
    GameNameBuffer[1] = name[1];
    GameNameBuffer[2] = name[2];
    GameNameBuffer[3] = name[3];
    GameNameBuffer[4] = 0;
    return GameNameBuffer;
}

extern BOOL __OSInIPL;
extern const char *AppGameNameForSysMenu;
extern char GameNameBuffer[5];
u8 OSGetAppType(void) {
    if (__OSInIPL) return 0x40;
    return *(u8 *)0x80003184;
}
static inline unsigned int AddBaseOffset(unsigned int base, unsigned int offset) {
    return base + offset;
}
