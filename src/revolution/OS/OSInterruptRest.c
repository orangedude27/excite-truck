#include <revolution/AI.h>
#include <revolution/BASE.h>
#include <revolution/DSP.h>
#include <revolution/EXI.h>
#include <revolution/IPC.h>
#include <revolution/OS.h>

#include <string.h>

OSInterruptHandler* InterruptHandlerTable;
s64 __OSLastInterruptTime;
s16 __OSLastInterrupt;
u32 __OSLastInterruptSrr0;

/*
 * Order in which __OSDispatchInterrupt() services the sources that fired: the
 * first entry sharing a bit with the pending mask wins, and the last entry
 * catches everything else.  Each bit is one OSInterruptType, as numbered by
 * OS_INTR_MASK().
 */
static u32 InterruptPrioTable[] = {
    OS_INTR_MASK(OS_INTR_PI_ERROR), OS_INTR_MASK(OS_INTR_PI_DEBUG),
    /* the memory-interface errors all share one level */
    OS_INTR_MASK(OS_INTR_MEM_0) | OS_INTR_MASK(OS_INTR_MEM_1) |
        OS_INTR_MASK(OS_INTR_MEM_2) | OS_INTR_MASK(OS_INTR_MEM_3) |
        OS_INTR_MASK(OS_INTR_MEM_ADDRESS),
    OS_INTR_MASK(OS_INTR_PI_RSW), OS_INTR_MASK(OS_INTR_PI_VI),
    OS_INTR_MASK(OS_INTR_PI_ACR),
    OS_INTR_MASK(OS_INTR_PI_PE_TOKEN) | OS_INTR_MASK(OS_INTR_PI_PE_FINISH),
    OS_INTR_MASK(OS_INTR_PI_HSP),
    /* streaming audio, the EXI channels and the other PI slow sources */
    OS_INTR_MASK(OS_INTR_DSP_ARAM) | OS_INTR_MASK(OS_INTR_DSP_DSP) |
        OS_INTR_MASK(OS_INTR_AI_AI) | OS_INTR_MASK(OS_INTR_EXI_0_EXI) |
        OS_INTR_MASK(OS_INTR_EXI_0_TC) | OS_INTR_MASK(OS_INTR_EXI_0_EXT) |
        OS_INTR_MASK(OS_INTR_EXI_1_EXI) | OS_INTR_MASK(OS_INTR_EXI_1_TC) |
        OS_INTR_MASK(OS_INTR_EXI_1_EXT) | OS_INTR_MASK(OS_INTR_EXI_2_EXI) |
        OS_INTR_MASK(OS_INTR_EXI_2_TC) | OS_INTR_MASK(OS_INTR_PI_SI) |
        OS_INTR_MASK(OS_INTR_PI_DI),
    OS_INTR_MASK(OS_INTR_DSP_AI), OS_INTR_MASK(OS_INTR_PI_CP),
    0xFFFFFFFF /* anything left over */
};

void ExternalInterruptHandler(u8 type, OSContext* ctx);
u32 SetInterruptMask(u32 type, u32 mask);

/**
 * @brief Apply the requested interrupt mask to the hardware register that
 *        owns one group of sources, and report which sources it handled.
 *
 * @p type is the set of sources still to be dealt with (the callers' work
 * mask, built with OS_INTR_MASK()); @p mask is the set that must stay
 * enabled.  __cntlzw() picks out the highest source number in @p type, which
 * says which group this round owns: the memory interface, the DSP, the AI,
 * one of the three EXI channels or the PI.  That group's register is then
 * rewritten whole - every source of the group that is missing from @p mask
 * gets its mask bit set, the others are cleared - so a caller that mixes
 * groups has to come back for each one; that is what the loop in
 * __OSMaskInterrupts()/__OSUnmaskInterrupts() does.
 *
 * The return value is @p type with this group's sources removed, so the
 * caller can use it as the remaining work mask.  A source number outside
 * every group leaves the hardware alone and is handed back unchanged, which
 * also ends those loops.
 *
 * Writing the register whole is why some groups clear more than the mask
 * bits: the DSP case also drops the three cause bits, the AI case the
 * sound-code reset, and EXI channel 0 the ROM-disable bit.
 */
u32 SetInterruptMask(u32 type, u32 mask) {
    u32 miMask;
    u32 dspMask;
    u32 aiMask;
    u32 exi0Mask, exi1Mask, exi2Mask;
    u32 piMask;

    switch (__cntlzw(type)) {
    /* memory interface: MI_INTMR is write-only here, so the register is
     * rebuilt from nothing */
    case OS_INTR_MEM_0:
    case OS_INTR_MEM_1:
    case OS_INTR_MEM_2:
    case OS_INTR_MEM_3:
    case OS_INTR_MEM_ADDRESS:
        miMask = 0;

        if (!(mask & OS_INTR_MASK(OS_INTR_MEM_0))) {
            miMask |= MI_INTMR_MEM0;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_MEM_1))) {
            miMask |= MI_INTMR_MEM1;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_MEM_2))) {
            miMask |= MI_INTMR_MEM2;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_MEM_3))) {
            miMask |= MI_INTMR_MEM3;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_MEM_ADDRESS))) {
            miMask |= MI_INTMR_ADDR;
        }

        MI_HW_REGS[MI_INTMR] = miMask;
        return type &
               ~(OS_INTR_MASK(OS_INTR_MEM_0) | OS_INTR_MASK(OS_INTR_MEM_1) |
                 OS_INTR_MASK(OS_INTR_MEM_2) | OS_INTR_MASK(OS_INTR_MEM_3) |
                 OS_INTR_MASK(OS_INTR_MEM_ADDRESS));
    /* DSP: AI/ARAM/DSP requests, all in the DSP control/status register */
    case OS_INTR_DSP_AI:
    case OS_INTR_DSP_ARAM:
    case OS_INTR_DSP_DSP:
        dspMask = DSP_HW_REGS[DSP_CSR];
        dspMask &= ~(DSP_CSR_AIDINT | DSP_CSR_AIDINTMSK | DSP_CSR_ARINT |
                     DSP_CSR_ARINTMSK | DSP_CSR_DSPINT | DSP_CSR_DSPINTMSK);

        if (!(mask & OS_INTR_MASK(OS_INTR_DSP_AI))) {
            dspMask |= DSP_CSR_AIDINTMSK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_DSP_ARAM))) {
            dspMask |= DSP_CSR_ARINTMSK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_DSP_DSP))) {
            dspMask |= DSP_CSR_DSPINTMSK;
        }

        DSP_HW_REGS[DSP_CSR] = dspMask;
        return type &
               ~(OS_INTR_MASK(OS_INTR_DSP_AI) | OS_INTR_MASK(OS_INTR_DSP_ARAM) |
                 OS_INTR_MASK(OS_INTR_DSP_DSP));
    /* AI: the one audio request, next to the sound-code reset bit */
    case OS_INTR_AI_AI:
        aiMask = AI_HW_REGS[AI_AICR];
        aiMask &= ~(AI_AICR_AIINTMSK | AI_AICR_AIINT | AI_AICR_SCRESET);

        if (!(mask & OS_INTR_MASK(OS_INTR_AI_AI))) {
            aiMask |= AI_AICR_AIINTMSK;
        }

        AI_HW_REGS[AI_AICR] = aiMask;
        return type & ~OS_INTR_MASK(OS_INTR_AI_AI);
    /* EXI channel 0 (flash/game interface); its register also holds ROMDIS */
    case OS_INTR_EXI_0_EXI:
    case OS_INTR_EXI_0_TC:
    case OS_INTR_EXI_0_EXT:
        exi0Mask = EXI_CHAN_PARAMS[EXI_CHAN_0].cpr;
        exi0Mask &= ~(EXI_CPR_EXIINTMASK | EXI_CPR_EXIINT | EXI_CPR_TCINTMASK |
                      EXI_CPR_TCINT | EXI_CPR_EXTINTMASK | EXI_CPR_EXTINT |
                      EXI_CPR_ROMDIS);

        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_0_EXI))) {
            exi0Mask |= EXI_CPR_EXIINTMASK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_0_TC))) {
            exi0Mask |= EXI_CPR_TCINTMASK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_0_EXT))) {
            exi0Mask |= EXI_CPR_EXTINTMASK;
        }

        EXI_CHAN_PARAMS[EXI_CHAN_0].cpr = exi0Mask;
        return type & ~(OS_INTR_MASK(OS_INTR_EXI_0_EXI) |
                        OS_INTR_MASK(OS_INTR_EXI_0_TC) |
                        OS_INTR_MASK(OS_INTR_EXI_0_EXT));
    /* EXI channel 1 (Bluetooth on this game) */
    case OS_INTR_EXI_1_EXI:
    case OS_INTR_EXI_1_TC:
    case OS_INTR_EXI_1_EXT:
        exi1Mask = EXI_CHAN_PARAMS[EXI_CHAN_1].cpr;
        exi1Mask &= ~(EXI_CPR_EXIINTMASK | EXI_CPR_EXIINT | EXI_CPR_TCINTMASK |
                      EXI_CPR_TCINT | EXI_CPR_EXTINTMASK | EXI_CPR_EXTINT);

        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_1_EXI))) {
            exi1Mask |= EXI_CPR_EXIINTMASK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_1_TC))) {
            exi1Mask |= EXI_CPR_TCINTMASK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_1_EXT))) {
            exi1Mask |= EXI_CPR_EXTINTMASK;
        }

        EXI_CHAN_PARAMS[EXI_CHAN_1].cpr = exi1Mask;
        return type & ~(OS_INTR_MASK(OS_INTR_EXI_1_EXI) |
                        OS_INTR_MASK(OS_INTR_EXI_1_TC) |
                        OS_INTR_MASK(OS_INTR_EXI_1_EXT));
    /* EXI channel 2: no external interrupt line, so no EXT bit */
    case OS_INTR_EXI_2_EXI:
    case OS_INTR_EXI_2_TC:
        exi2Mask = EXI_CHAN_PARAMS[EXI_CHAN_2].cpr;
        exi2Mask &= ~(EXI_CPR_EXIINTMASK | EXI_CPR_EXIINT | EXI_CPR_TCINTMASK |
                      EXI_CPR_TCINT);

        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_2_EXI))) {
            exi2Mask |= EXI_CPR_EXIINTMASK;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_EXI_2_TC))) {
            exi2Mask |= EXI_CPR_TCINTMASK;
        }

        EXI_CHAN_PARAMS[EXI_CHAN_2].cpr = exi2Mask;
        return type & ~(OS_INTR_MASK(OS_INTR_EXI_2_EXI) |
                        OS_INTR_MASK(OS_INTR_EXI_2_TC));
    /* PI: everything else, in one 16-bit register */
    case OS_INTR_PI_CP:
    case OS_INTR_PI_PE_TOKEN:
    case OS_INTR_PI_PE_FINISH:
    case OS_INTR_PI_SI:
    case OS_INTR_PI_DI:
    case OS_INTR_PI_RSW:
    case OS_INTR_PI_ERROR:
    case OS_INTR_PI_VI:
    case OS_INTR_PI_DEBUG:
    case OS_INTR_PI_HSP:
    case OS_INTR_PI_ACR:
        /* the four sources owned by other registers above stay masked */
        piMask = PI_INTMR_EXI | PI_INTMR_AI | PI_INTMR_DSP | PI_INTMR_MEM;

        if (!(mask & OS_INTR_MASK(OS_INTR_PI_CP))) {
            piMask |= PI_INTMR_CP;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_SI))) {
            piMask |= PI_INTMR_SI;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_DI))) {
            piMask |= PI_INTMR_DI;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_RSW))) {
            piMask |= PI_INTMR_RSW;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_ERROR))) {
            piMask |= PI_INTMR_ERROR;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_VI))) {
            piMask |= PI_INTMR_VI;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_DEBUG))) {
            piMask |= PI_INTMR_DEBUG;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_PE_TOKEN))) {
            piMask |= PI_INTMR_PE_TOKEN;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_PE_FINISH))) {
            piMask |= PI_INTMR_PE_FINISH;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_HSP))) {
            piMask |= PI_INTMR_HSP;
        }
        if (!(mask & OS_INTR_MASK(OS_INTR_PI_ACR))) {
            piMask |= PI_INTMR_ACR;
        }

        PI_HW_REGS[PI_INTMR] = piMask;
        return type &
               ~(OS_INTR_MASK(OS_INTR_PI_CP) |
                 OS_INTR_MASK(OS_INTR_PI_PE_TOKEN) |
                 OS_INTR_MASK(OS_INTR_PI_PE_FINISH) |
                 OS_INTR_MASK(OS_INTR_PI_SI) | OS_INTR_MASK(OS_INTR_PI_DI) |
                 OS_INTR_MASK(OS_INTR_PI_RSW) | OS_INTR_MASK(OS_INTR_PI_ERROR) |
                 OS_INTR_MASK(OS_INTR_PI_VI) | OS_INTR_MASK(OS_INTR_PI_DEBUG) |
                 OS_INTR_MASK(OS_INTR_PI_HSP) | OS_INTR_MASK(OS_INTR_PI_ACR));
    /* not a source number: nothing to mask, and the caller's loop stops */
    default:
        return type;
    }
}

/**
 * @brief Mask (disable) the given interrupt sources, and hand back the mask
 *        that was in effect before.
 *
 * @p userMask is a set of OSInterruptType bits as built by OS_INTR_MASK().
 * The OS keeps two shadow copies of the interrupt mask in MEM1: the "previous"
 * one is what the application as a whole has masked with this call and
 * __OSUnmaskInterrupts(), the "current" one what the shorter-lived
 * OSMaskInterrupts()/OSUnmaskInterrupts() have put on top of it.  A source
 * reaches the CPU only while it is unmasked in *both*, which is exactly the
 * set SetInterruptMask() is told to keep enabled below.
 *
 * With interrupts off, the new previous mask is stored, and every source this
 * call newly masks -- one hardware group per pass, since SetInterruptMask()
 * rewrites a whole group's register at a time -- is pushed to the hardware.
 *
 * @return the previous mask, which is what a caller hands back to
 *         __OSUnmaskInterrupts() when it is done.
 */
u32 __OSMaskInterrupts(u32 userMask) {
    BOOL enabled = OSDisableInterrupts();
    u32 prevMask = *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK);
    u32 currMask = *(u32*)OSPhysicalToCached(OS_PHYS_CURRENT_INTR_MASK);

    /* the sources that were unmasked until now, so their hardware bit changes;
     * the merged mask is the one the hardware has to end up with */
    u32 workMask = userMask & ~(prevMask | currMask);
    userMask = prevMask | userMask;
    *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) = userMask;

    while (workMask != 0) {
        workMask = SetInterruptMask(workMask, userMask | currMask);
    }

    OSRestoreInterrupts(enabled);
    return prevMask;
}

/* Unmask interrupt bits in the previous interrupt mask, reapplying the effective mask while interrupts are disabled. */
u32 __OSUnmaskInterrupts(u32 userMask) {
    BOOL enabled = OSDisableInterrupts();
    u32 prevMask = *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK);
    u32 currMask = *(u32*)OSPhysicalToCached(OS_PHYS_CURRENT_INTR_MASK);

    u32 workMask = userMask & (prevMask | currMask);
    userMask = prevMask & ~userMask;
    *(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) = userMask;

    while (workMask != 0) {
        workMask = SetInterruptMask(workMask, userMask | currMask);
    }

    OSRestoreInterrupts(enabled);
    return prevMask;
}

/**
 * @brief Second half of the external interrupt entry: work out which sources
 *        fired, run the highest-priority installed handler and resume the game
 *        through a CPU context.  Never returns.
 *
 * ExternalInterruptHandler saves the interrupted state into @p ctx and tail
 * jumps here.  @p intr is the interrupt vector number, which is not needed:
 * the causes are re-read from the peripheral registers themselves.
 */
void __OSDispatchInterrupt(u8 intr, OSContext* ctx) {
    u32 piStatus;
    u32 causeMask, activeMask;
    u32 miCause;
    u32 dspCause;
    u32 exi0Cause, exi1Cause, exi2Cause;
    u32 piMask;

    /* Sources waiting in the PI interrupt status register.  RSWST is the
     * RSW's own status edge rather than a source, so drop it. */
    piStatus = PI_HW_REGS[PI_INTSR];
    piStatus &= ~PI_INTSR_RSWST;

    /* Nothing pending, or everything pending is masked out: resume at once. */
    piMask = PI_HW_REGS[PI_INTMR];
    if (piStatus == 0 || !(piStatus & piMask)) {
        OSLoadContext(ctx);
    }

    /* Translate the per-processor status bits into one OSInterruptType mask. */
    causeMask = 0;
    activeMask = 0;

    /* MEM interrupts: the MI tells us which of its five sources fired. */
    if (piStatus & PI_INTMR_MEM) {
        miCause = MI_HW_REGS[MI_INTSR];
        if (miCause & MI_INTSR_MEM0) {
            causeMask |= OS_INTR_MASK(OS_INTR_MEM_0);
        }
        if (miCause & MI_INTSR_MEM1) {
            causeMask |= OS_INTR_MASK(OS_INTR_MEM_1);
        }
        if (miCause & MI_INTSR_MEM2) {
            causeMask |= OS_INTR_MASK(OS_INTR_MEM_2);
        }
        if (miCause & MI_INTSR_MEM3) {
            causeMask |= OS_INTR_MASK(OS_INTR_MEM_3);
        }
        if (miCause & MI_INTSR_ADDR) {
            causeMask |= OS_INTR_MASK(OS_INTR_MEM_ADDRESS);
        }
    }

    /* DSP interrupts */
    if (piStatus & PI_INTSR_DSP) {
        dspCause = DSP_HW_REGS[DSP_CSR];
        if (dspCause & DSP_CSR_AIDINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_DSP_AI);
        }
        if (dspCause & DSP_CSR_ARINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_DSP_ARAM);
        }
        if (dspCause & DSP_CSR_DSPINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_DSP_DSP);
        }
    }

    /* AI interrupts */
    if ((piStatus & PI_INTSR_AI) && (AI_HW_REGS[AI_AICR] & AI_AICR_AIINT)) {
        causeMask |= OS_INTR_MASK(OS_INTR_AI_AI);
    }

    /* EXI interrupts: each channel reports its own three sources.  Channel 2
     * has no external interrupt line. */
    if (piStatus & PI_INTSR_EXI) {
        exi0Cause = EXI_CHAN_PARAMS[EXI_CHAN_0].cpr;
        if (exi0Cause & EXI_CPR_EXIINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_0_EXI);
        }
        if (exi0Cause & EXI_CPR_TCINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_0_TC);
        }
        if (exi0Cause & EXI_CPR_EXTINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_0_EXT);
        }

        exi1Cause = EXI_CHAN_PARAMS[EXI_CHAN_1].cpr;
        if (exi1Cause & EXI_CPR_EXIINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_1_EXI);
        }
        if (exi1Cause & EXI_CPR_TCINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_1_TC);
        }
        if (exi1Cause & EXI_CPR_EXTINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_1_EXT);
        }

        exi2Cause = EXI_CHAN_PARAMS[EXI_CHAN_2].cpr;
        if (exi2Cause & EXI_CPR_EXIINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_2_EXI);
        }
        if (exi2Cause & EXI_CPR_TCINT) {
            causeMask |= OS_INTR_MASK(OS_INTR_EXI_2_TC);
        }
    }

    /* PI interrupts: these report themselves, no second register to read. */
    if (piStatus & PI_INTSR_HSP) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_HSP);
    }
    if (piStatus & PI_INTSR_DEBUG) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_DEBUG);
    }
    if (piStatus & PI_INTSR_PE_FINISH) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_PE_FINISH);
    }
    if (piStatus & PI_INTSR_PE_TOKEN) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_PE_TOKEN);
    }
    if (piStatus & PI_INTSR_VI) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_VI);
    }
    if (piStatus & PI_INTSR_SI) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_SI);
    }
    if (piStatus & PI_INTSR_DI) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_DI);
    }
    if (piStatus & PI_INTSR_RSW) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_RSW);
    }
    if (piStatus & PI_INTSR_CP) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_CP);
    }
    if (piStatus & PI_INTSR_ERROR) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_ERROR);
    }
    if (piStatus & PI_INTSR_ACR) {
        causeMask |= OS_INTR_MASK(OS_INTR_PI_ACR);
    }

    /* Keep only the sources the application has not masked off with
     * __OSMaskInterrupts(); those are the ones we have handlers to run. */
    activeMask = causeMask &
                 ~(*(u32*)OSPhysicalToCached(OS_PHYS_PREV_INTR_MASK) |
                   *(u32*)OSPhysicalToCached(OS_PHYS_CURRENT_INTR_MASK));

    if (activeMask != 0) {
        OSInterruptHandler handler;
        u32* pPrioMask;
        s16 intrType;

        /* Walk the priority table; the first level that overlaps wins, and
         * its leading zero count is that source's OSInterruptType. */
        for (pPrioMask = InterruptPrioTable; TRUE; pPrioMask++) {
            if (activeMask & *pPrioMask) {
                intrType = __cntlzw(activeMask & *pPrioMask);
                break;
            }
        }

        handler = InterruptHandlerTable[intrType];
        if (handler != NULL) {
            /* Note the interrupt for the panic report in OSError.c (the MEM
             * sources are errors, not real interrupts, so skip those). */
            if (intrType > OS_INTR_MEM_ADDRESS) {
                __OSLastInterrupt = intrType;
                __OSLastInterruptTime = OSGetTime();
                __OSLastInterruptSrr0 = ctx->srr0;
            }

            /* The handler may make another thread runnable: hold the
             * scheduler around it, then let it choose the thread to resume. */
            OSDisableScheduler();
            handler(intrType, ctx);
            OSEnableScheduler();
            __OSReschedule();
            OSLoadContext(ctx);
        }
    }

    /* No handler for it: go straight back to the interrupted code. */
    OSLoadContext(ctx);
}

asm void ExternalInterruptHandler(register u8 type,
                                  register OSContext* ctx) {
    // clang-format off
    nofralloc

    stw r0, ctx->gprs[0]
    stw r1, ctx->gprs[1]
    stw r2, ctx->gprs[2]
    stmw r6, ctx->gprs[6]

    mfspr r0, GQR1
    stw r0, ctx->gqrs[1]
    mfspr r0, GQR2
    stw r0, ctx->gqrs[2]
    mfspr r0, GQR3
    stw r0, ctx->gqrs[3]
    mfspr r0, GQR4
    stw r0, ctx->gqrs[4]
    mfspr r0, GQR5
    stw r0, ctx->gqrs[5]
    mfspr r0, GQR6
    stw r0, ctx->gqrs[6]
    mfspr r0, GQR7
    stw r0, ctx->gqrs[7]

    stwu r1, -8(r1)
    b __OSDispatchInterrupt
    // clang-format on
}
