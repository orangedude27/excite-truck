#include <revolution/AI.h>
#include <revolution/BASE.h>
#include <revolution/DSP.h>
#include <revolution/EXI.h>
#include <revolution/IPC.h>
#include <revolution/OS.h>

#include <string.h>

extern OSInterruptHandler* InterruptHandlerTable;

asm BOOL OSDisableInterrupts(void) {
    // clang-format off
    nofralloc

    entry __RAS_OSDisableInterrupts_begin

    mfmsr r3
    // Clear external interrupts bit
    rlwinm r4, r3, 0, 17, 15
    mtmsr r4

    entry __RAS_OSDisableInterrupts_end

    // Return old interrupt status
    rlwinm r3, r3, 17, 31, 31
    blr
    // clang-format on
}

asm BOOL OSEnableInterrupts(void) {
    // clang-format off
    nofralloc

    mfmsr r3
    // Set external interrupts bit
    ori r4, r3, MSR_EE
    mtmsr r4

    // Return old interrupt status
    rlwinm r3, r3, 17, 31, 31
    blr
    // clang-format on
}

asm BOOL OSRestoreInterrupts(register BOOL status){
    // clang-format off
    nofralloc

    cmpwi status, 0
    mfmsr r4
    beq disable

    // Set external interrupts bit
    ori r5, r4, MSR_EE
    b set_msr

disable:
    // Clear external interrupts bit
    rlwinm r5, r4, 0, 17, 15

set_msr:
    mtmsr r5
    // Return old interrupt status
    rlwinm r3, r4, 17, 31, 31
    blr
    // clang-format on
}

OSInterruptHandler
    __OSSetInterruptHandler(OSInterruptType type, OSInterruptHandler handler) {
    OSInterruptHandler old = InterruptHandlerTable[type];
    InterruptHandlerTable[type] = handler;
    return old;
}

OSInterruptHandler __OSGetInterruptHandler(OSInterruptType type) {
    return InterruptHandlerTable[type];
}

