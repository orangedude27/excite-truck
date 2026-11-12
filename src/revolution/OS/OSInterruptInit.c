#include <revolution/AI.h>
#include <revolution/BASE.h>
#include <revolution/DSP.h>
#include <revolution/EXI.h>
#include <revolution/IPC.h>
#include <revolution/OS.h>

#include <string.h>

// Shared with the rest of the SDK's OSInterrupt.c, kept in
// src/revolution/OS/OSInterruptRest.c: the MEM1 handler table, the helper that
// rewrites one hardware group's interrupt-mask register, and the handler this
// file installs for the external-interrupt exception.
extern OSInterruptHandler* InterruptHandlerTable;
extern u32 SetInterruptMask(u32 type, u32 mask);
extern void ExternalInterruptHandler(u8 type, OSContext* ctx);

/**
 * @brief Bring the interrupt subsystem up, as part of OSInit.
 *
 * Clears the MEM1 interrupt-handler table and the two shadow copies of the
 * interrupt mask (the "previous" and "current" masks that
 * __OSMaskInterrupts()/__OSUnmaskInterrupts() build on), leaves the four lines
 * the other hardware registers own masked in PI_INTMR, lets the PPC side of
 * IPC interrupt, and then unmasks every source the OS services in the
 * register of its own hardware group.  The external-interrupt exception is
 * finally pointed at ExternalInterruptHandler(), which dispatches through the
 * handler table.
 */
void __OSInterruptInit(void) {
    InterruptHandlerTable =
        (OSInterruptHandler*)OSPhysicalToCached(OS_PHYS_INTR_HANDLER_TABLE);
    memset(InterruptHandlerTable, 0, sizeof(OSInterruptHandler) * OS_INTR_MAX);

    // nothing is masked in either shadow copy
    *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) = 0;
    *(u32*)OSPhysicalToCached(OS_PHYS_CURRENT_INTR_MASK) = 0;

    // EXI, AI, DSP and MEM reach the PPC through their own registers, so the
    // PI keeps their bits masked (see SetInterruptMask())
    PI_HW_REGS[PI_INTMR] =
        PI_INTMR_EXI | PI_INTMR_AI | PI_INTMR_DSP | PI_INTMR_MEM;

    // the PPC may be interrupted by IPC
    IPC_HW_REGS_PPC[IPC_PPCIRQMASK] = IPC_PPCIRQMASK_IPC;

    {
        // every source the OS services: OS_INTR_MEM_0 through OS_INTR_PI_ACR
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

        // of the sources to enable, the ones not already unmasked
        u32 workMask = userMask & ~(prevMask | currMask);
        u32 loopMask;
        userMask = prevMask | userMask;
        *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) = userMask;
        loopMask = userMask | currMask;

        // one call per hardware group the sources are spread over
        while (workMask != 0) {
            workMask = SetInterruptMask(workMask, loopMask);
        }

        OSRestoreInterrupts(enabled);
    }

    __OSSetExceptionHandler(OS_ERR_EXT_INTERRUPT, ExternalInterruptHandler);
}
