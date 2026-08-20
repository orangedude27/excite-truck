#include <revolution/AI.h>
#include <revolution/BASE.h>
#include <revolution/DSP.h>
#include <revolution/EXI.h>
#include <revolution/IPC.h>
#include <revolution/OS.h>

#include <string.h>

// Shared with OSInterrupt.c
extern OSInterruptHandler* InterruptHandlerTable;
extern u32 SetInterruptMask(u32 type, u32 mask);
extern void ExternalInterruptHandler(u8 type, OSContext* ctx);

void __OSInterruptInit(void) {
    InterruptHandlerTable =
        (OSInterruptHandler*)OSPhysicalToCached(OS_PHYS_INTR_HANDLER_TABLE);
    memset(InterruptHandlerTable, 0, sizeof(OSInterruptHandler) * OS_INTR_MAX);

    *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) = 0;
    *(u32*)OSPhysicalToCached(OS_PHYS_CURRENT_INTR_MASK) = 0;

    PI_HW_REGS[PI_INTMR] =
        PI_INTMR_EXI | PI_INTMR_AI | PI_INTMR_DSP | PI_INTMR_MEM;

    IPC_HW_REGS_PPC[IPC_PPCIRQMASK] = 0x40000000;

    {
        u32 userMask =
            OS_INTR_MASK(OS_INTR_MEM_0) | OS_INTR_MASK(OS_INTR_MEM_1) |
            OS_INTR_MASK(OS_INTR_MEM_2) | OS_INTR_MASK(OS_INTR_MEM_3) |
            OS_INTR_MASK(OS_INTR_MEM_ADDRESS) | OS_INTR_MASK(OS_INTR_DSP_AI) |
            OS_INTR_MASK(OS_INTR_DSP_ARAM) | OS_INTR_MASK(OS_INTR_DSP_DSP) |
            OS_INTR_MASK(OS_INTR_AI_AI) | OS_INTR_MASK(OS_INTR_EXI_0_EXI) |
            OS_INTR_MASK(OS_INTR_EXI_0_TC) | OS_INTR_MASK(OS_INTR_EXI_0_EXT) |
            OS_INTR_MASK(OS_INTR_EXI_1_EXI) | OS_INTR_MASK(OS_INTR_EXI_1_TC) |
            OS_INTR_MASK(OS_INTR_EXI_1_EXT) | OS_INTR_MASK(OS_INTR_EXI_2_EXI) |
            OS_INTR_MASK(OS_INTR_EXI_2_TC) | OS_INTR_MASK(OS_INTR_PI_CP) |
            OS_INTR_MASK(OS_INTR_PI_PE_TOKEN) | OS_INTR_MASK(OS_INTR_PI_PE_FINISH) |
            OS_INTR_MASK(OS_INTR_PI_SI) | OS_INTR_MASK(OS_INTR_PI_DI) |
            OS_INTR_MASK(OS_INTR_PI_RSW) | OS_INTR_MASK(OS_INTR_PI_ERROR) |
            OS_INTR_MASK(OS_INTR_PI_VI) | OS_INTR_MASK(OS_INTR_PI_DEBUG) |
            OS_INTR_MASK(OS_INTR_PI_HSP) | OS_INTR_MASK(OS_INTR_PI_ACR);
        BOOL enabled = OSDisableInterrupts();
        u32 prevMask = *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK);
        u32 currMask = *(u32*)OSPhysicalToCached(OS_PHYS_CURRENT_INTR_MASK);

        u32 workMask = userMask & ~(prevMask | currMask);
        u32 loopMask;
        userMask = prevMask | userMask;
        *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) = userMask;
        loopMask = userMask | currMask;

        while (workMask != 0) {
            workMask = SetInterruptMask(workMask, loopMask);
        }

        OSRestoreInterrupts(enabled);
    }

    __OSSetExceptionHandler(OS_ERR_EXT_INTERRUPT, ExternalInterruptHandler);
}
