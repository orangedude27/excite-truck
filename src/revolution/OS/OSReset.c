#include <revolution/DVD.h>
#include <revolution/OS.h>
#include <revolution/PAD.h>
#include <revolution/SC.h>
#include <revolution/VI.h>

#include <string.h>

static OSShutdownFunctionQueue ShutdownFunctionQueue;
static void KillThreads(void);

void OSRegisterShutdownFunction(OSShutdownFunctionInfo* info) {
    OSShutdownFunctionInfo* it;
    OSShutdownFunctionInfo* prev;
    OSShutdownFunctionInfo* tail;

    for (it = ShutdownFunctionQueue.head; it != NULL && it->prio <= info->prio;
         it = it->next) {
        ;
    }

    if (it == NULL) {

        tail = ShutdownFunctionQueue.tail;
        if (tail == NULL) {
            ShutdownFunctionQueue.head = info;
        } else {
            ShutdownFunctionQueue.tail->next = info;
        }

        info->prev = tail;
        info->next = NULL;

        it = ShutdownFunctionQueue.head;
        ShutdownFunctionQueue.tail = info;
    } else {
        info->next = it;

        prev = it->prev;
        it->prev = info;
        info->prev = prev;

        if (prev == NULL) {
            ShutdownFunctionQueue.head = info;
        } else {
            prev->next = info;
        }
    }
}

BOOL __OSCallShutdownFunctions(u32 arg0, u32 arg1) {
    OSShutdownFunctionInfo* iter;
    BOOL failure;
    u32 prio;

    prio = 0;
    failure = FALSE;

    for (iter = ShutdownFunctionQueue.head; iter != NULL; iter = iter->next) {
        if (failure && prio != iter->prio) {
            break;
        }

        failure |= !iter->func(arg0, arg1);
        prio = iter->prio;
    }

    failure |= !__OSSyncSram();

    return !failure;
}

void __OSShutdownDevices(u32 arg0) {
    BOOL padIntr;
    BOOL osIntr;
    BOOL keepEnable;

    switch (arg0) {
    case 0:
    case 4:
    case 5:
    case 6:
        keepEnable = FALSE;
        break;
    case 1:
    case 2:
    case 3:
    default:
        keepEnable = TRUE;
        break;
    }

    __OSStopAudioSystem();

    if (!keepEnable) {
        padIntr = __PADDisableRecalibration(TRUE);
    }

    while (!__OSCallShutdownFunctions(0, arg0)) {
        ;
    }

    while (!__OSSyncSram()) {
        ;
    }

    osIntr = OSDisableInterrupts();
    __OSCallShutdownFunctions(1, arg0);
    LCDisable();

    if (!keepEnable) {
        __PADDisableRecalibration(padIntr);
    }

    KillThreads();
}

static void KillThreads(void) {
    OSThread* iter;
    OSThread* next;

    for (iter = OS_THREAD_QUEUE.head; iter != NULL; iter = next) {
        next = iter->nextActive;

        switch (iter->state) {
        case OS_THREAD_STATE_SLEEPING:
        case OS_THREAD_STATE_READY:
            OSCancelThread(iter);
            break;
        }
    }
}

void OSShutdownSystem(void) {
    SCIdleModeInfo idleMode;
    OSStateFlags stateFlags;
    u32 rtcFlags;
    OSIOSRev iosRev;

    memset(&idleMode, 0, 2);
    SCInit();
    while (SCCheckStatus() == 1) {
        ;
    }
    SCGetIdleMode(&idleMode);

    __OSStopPlayRecord();
    __OSUnRegisterStateEvent();
    __DVDPrepareReset();
    __OSReadStateFlags(&stateFlags);

    if (__DVDGetCoverStatus() != 2) {
        stateFlags.discState = 3;
    } else {
        __OSGetRTCFlags(&rtcFlags);
        if (rtcFlags != 0) {
            stateFlags.discState = 2;
        } else {
            stateFlags.discState = 1;
        }
    }

    if (idleMode.wc24 == 1) {
        stateFlags.BYTE_0x5 = 5;
    } else {
        stateFlags.BYTE_0x5 = 1;
    }

    __OSClearRTCFlags();
    __OSWriteStateFlags(&stateFlags);
    __OSGetIOSRev(&iosRev);

    if (idleMode.wc24 == 1) {
        OSDisableScheduler();
        __OSShutdownDevices(5);
        OSEnableScheduler();
        __OSLaunchMenu();
    } else {
        OSDisableScheduler();
        __OSShutdownDevices(2);
        __OSShutdownToSBY();
    }
}

extern u8 OSGetAppType(void);
extern void fn_8004E3F0(void);
extern void fn_80052390(u32, u32);
extern u32 lbl_8055DA78[2];

void fn_800527CC(u32 param_1) {
    u8 flag;

    flag = OSGetAppType();
    __OSStopPlayRecord();
    __OSUnRegisterStateEvent();

    if (flag == 0x81) {
        OSDisableScheduler();
        __OSShutdownDevices(4);
        OSEnableScheduler();
        fn_8004E3F0();
    } else if (flag == 0x80) {
        OSDisableScheduler();
        __OSShutdownDevices(4);
        OSEnableScheduler();
        fn_80052390(param_1, lbl_8055DA78[0]);
    }

    OSDisableScheduler();
    __OSShutdownDevices(1);
    __OSHotReset();
}

void OSReturnToMenu(void) {
    OSStateFlags stateFlags;
    u32 rtcFlags;

    __OSStopPlayRecord();
    __OSUnRegisterStateEvent();
    __DVDPrepareReset();

    __OSReadStateFlags(&stateFlags);
    if (__DVDGetCoverStatus() != 2) {
        stateFlags.discState = 3;
    } else {
        __OSGetRTCFlags(&rtcFlags);
        if (rtcFlags != 0) {
            stateFlags.discState = 2;
        } else {
            stateFlags.discState = 1;
        }
    }
    stateFlags.BYTE_0x5 = 3;
    __OSClearRTCFlags();
    __OSWriteStateFlags(&stateFlags);

    OSDisableScheduler();
    __OSShutdownDevices(5);
    OSEnableScheduler();

    __OSLaunchMenu();
    OSPanic("OSReset.c", 0x30f, "OSReturnToMenu(): Falied to boot system menu.\n");
}
u32 OSGetResetCode(void) {
    if (__OSRebootParams.WORD_0x0 != 0) {
        return __OSRebootParams.WORD_0x4 | 0x80000000;
    }

    return PI_HW_REGS[PI_RESET] >> 3;
}

void OSResetSystem(u32 arg0, u32 arg1, u32 arg2) {
    // clang-format off
#line 935
    OSPanic("OSReset.c", 0x3a7, "OSResetSystem() is obsoleted. It doesn't work any longer.\n");
    // clang-format on
}