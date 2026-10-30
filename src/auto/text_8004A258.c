#include <types.h>
#include <revolution/OS/OSHardware.h>

extern u8 DriveInfo[4];

extern BOOL __OSInIPL;
extern const char lbl_80558F0C[4];

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

const char *__OSVersion = "<< RVL_SDK - OS \trelease build: Sep 21 2006 14:32:13 (0x4200_60422) >>\0";

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

u32 OSGetConsoleType(void) {
    extern void *BootInfo_8055D9F8;
    u32 *boot=(u32*)BootInfo_8055D9F8;
    u32 mem; u32 console; u16 rev;
    if (boot==0 || boot[11]==0) return 0x10000002;
    console=*(u32*)0x80003138;
    rev=*(u16*)0x800030E6;
    if (rev&0x8000) {
        rev&=0x7FFF;
        if (rev<0x201 && rev<4 && rev>=2 || rev==0x203) {
            if(console==0) return 0x10;
            if(console==2) return 0x12;
            if(console==16) return 0x20;
            if(console==17) return 0x21;
            if(console==1) return 0x11;
            return 0x21;
        }
        if (rev>=0x201 && rev!=0x203 || rev>=4 || rev<2) {
            if(console==0) return 0x10000010;
            if(console==1) return 0x10000011;
            if(console==2) return 0x10000012;
            if(console==16) return 0x10000020;
            if(console==17) return 0x10000021;
            if(console<=0x11) return 0x10000021;
            return 0x10000021;
        }
    }
    mem=OSGetPhysicalMem2Size();
    if(console==0) return mem==0x40000000 ? 0x10 : 0x10000010;
    if(console==1) return mem==0x40000000 ? 0x11 : 0x10000011;
    if(console==2) return mem==0x40000000 ? 0x12 : 0x10000012;
    if(console==16) return mem==0x40000000 ? 0x20 : 0x10000020;
    if(console==17) return mem==0x40000000 ? 0x21 : 0x10000021;
    if(console<=0x11) return mem==0x40000000 ? 0x21 : 0x10000021;
    return 0x10000002;
}

extern unsigned int OSGetResetCode(void);
extern unsigned int OSGetArenaHi(void);
extern unsigned int OSGetArenaLo(void);
extern void DCZeroRange(const void *, unsigned int);
extern void DCFlushRange(unsigned int, unsigned int);
extern unsigned int __OSRebootParams[];

static inline void ClearMEM2Range(unsigned int base, unsigned int size) {
    unsigned int flush = base;
    if (size > 0x40000)
        flush += size - 0x40000;
    DCZeroRange((void *)base, size);
    DCFlushRange(flush, 0x40000);
}
void ClearArena(void) {
    unsigned int reset = OSGetResetCode();
    unsigned int start;
    unsigned int size;

    if ((reset >> 31) == 0) {
        size = OSGetArenaHi();
        size -= OSGetArenaLo();
        start = OSGetArenaLo();
        if (size > 0x40000)
            start += size - 0x40000;
        DCZeroRange((void *)start, size);
        DCFlushRange(start, 0x40000);
        return;
    }

    if (__OSRebootParams[3] == 0 || (__OSRebootParams[3] & 0x30000000) != 0) {
        size = OSGetArenaHi();
        size -= OSGetArenaLo();
        start = OSGetArenaLo();
        if (size > 0x40000)
            start += size - 0x40000;
        DCZeroRange((void *)start, size);
        DCFlushRange(start, 0x40000);
        return;
    }

    start = OSGetArenaLo();
    if (start >= __OSRebootParams[3])
        return;

    if (OSGetArenaHi() <= __OSRebootParams[3]) {
        size = OSGetArenaHi();
        size -= OSGetArenaLo();
        start = OSGetArenaLo();
        if (size > 0x40000)
            start += size - 0x40000;
        DCZeroRange((void *)start, size);
        DCFlushRange(start, 0x40000);
        return;
    }

    start = OSGetArenaLo();
    size = __OSRebootParams[3] - start;
    start = OSGetArenaLo();
    if (size > 0x40000)
        start += size - 0x40000;
    DCZeroRange((void *)start, size);
    DCFlushRange(start, 0x40000);

    start = __OSRebootParams[4];
    if (OSGetArenaHi() > start) {
        size = OSGetArenaHi() - start;
        if (size > 0x40000)
            start += size - 0x40000;
        DCZeroRange((void *)start, size);
        DCFlushRange(start, 0x40000);
    }
}

#pragma push
#pragma scheduling invalid_target
void ClearMEM2Arena(void) {
    unsigned int reset = OSGetResetCode();
    register unsigned int base;
    register unsigned int flush;
    register unsigned int size;

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
void InquiryCallback(s32 result, struct DVDCommandBlock* arg1) {
    if (*(u32*)((u8*)arg1 + 0xC) == 0) goto read_drive;
    goto set_one;
read_drive:
    *(u16*)0x800030E6 = *(u16*)(DriveInfo + 2) | 0x8000;
    return;
set_one:
    *(u16*)0x800030E6 = 1;
}
#pragma small_data on
extern const char lbl_80558F04[];
#pragma small_data on
extern const char lbl_80558F04[6];
#pragma small_data on

void ReportOSInfo_8004AA40(void) {
    u32 type;
    u32 category;
    u32 tdev;
    u32 version;
    u32 builddate;

    OSReport("\nRevolution OS\n");
    OSReport("Kernel built : %s %s\n\0\0", "Sep 21 2006", "14:32:13\0\0\0");

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
        tdev = type & 0x0FFFFFFF;
        OSReport("TDEV-based emulation HW%d\n\0", tdev - 3);
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

    if (AreWeInitialized_8055D9CC == 0) {
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
                if (*(void**)((u8*)BootInfo_8055D9F8 + 0x30) == NULL &&
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
#pragma pop

void __OSDBIntegrator(void) {
    register volatile u32 *base = (volatile u32 *)0x40;
    base[3] = 0;
    base[2] |= 0x80000000;
    PPCMtmsr(0x30);
}

extern void __OSDBJump(void) {
    (void)(OSExceptionVector(), 0);
    return;
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

extern void __OSUnhandledException(u8, void *, u32, u32);
void OSDefaultExceptionHandler(u8 exception, void *context) {
    __OSUnhandledException(exception, context, 0, 0);
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
extern u8 DriveInfo[4];
u8 OSGetAppType(void) {
    if (__OSInIPL) return 0x40;
    return *(u8 *)0x80003184;
}
static inline unsigned int AddBaseOffset(unsigned int base, unsigned int offset) {
    return base + offset;
}
