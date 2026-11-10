#include <revolution/BASE.h>
#include <revolution/DSP.h>
#include <revolution/OS.h>

extern int vprintf(const char*, va_list);

// SRR1 bit 11 of a program exception: the instruction that trapped uses the
// floating-point unit, which the faulting thread does not currently own. The
// floating-point exception handler is the one that can deal with it.
#define SRR1_FP_UNAVAILABLE (1 << (31 - 11))

OSErrorHandler __OSErrorTable[OS_ERR_MAX];
u32 __OSFpscrEnableBits = FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE | FPSCR_XE;

DECL_WEAK void OSReport(const char* msg, ...) {
    va_list list;
    va_start(list, msg);
    vprintf(msg, list);
    va_end(list);
}

asm void __VprintfThunk(void) {
    // clang-format off
    nofralloc
    b vprintf
    // clang-format on
}

/* Print a formatted panic message with source location, dump a stack backtrace, then halt. */
DECL_WEAK void OSPanic(const char* file, int line, const char* msg, ...) {
    u32 depth;
    u32* sp;
    va_list list;

    OSDisableInterrupts();

    va_start(list, msg);
    vprintf(msg, list);
    va_end(list);
    OSReport(" in \"%s\" on line %d.\n", file, line);

    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (depth = 0, sp = (u32*)OSGetStackPointer();
         sp != NULL && sp != (u32*)0xFFFFFFFF && depth++ < 16; sp = (u32*)*sp) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", sp, sp[0], sp[1]);
    }

    PPCHalt();
}

/**
 * Installs @handler as the handler for exception @error and returns the handler
 * that was installed there before.
 *
 * The floating-point exception is special: whether it has a handler is what
 * turns floating-point exception reporting on or off in the whole system, so
 * every thread on the active queue is walked with interrupts disabled.
 * Installing sets MSR[FE0:FE1] in each thread's saved MSR together with the
 * FPSCR exception enables, and poisons the FP and PS registers of a thread that
 * holds no FPU state yet so that its first floating-point instruction reports
 * an invalid operation. Removing the handler clears the same bits again. The
 * CPU's own FPSCR and MSR are brought in line with the threads at the end.
 */
OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler) {
    OSErrorHandler oldHandler;
    BOOL enabled = OSDisableInterrupts();

    oldHandler = __OSErrorTable[error];
    __OSErrorTable[error] = handler;

    if (error == OS_ERR_FP_EXCEPTION) {
        OSThread* thread;
        u32 msr;
        u32 fpscr;

        // FPSCR itself can only be read once the FPU is turned on here.
        msr = PPCMfmsr();
        PPCMtmsr(msr | MSR_FP);
        fpscr = PPCMffpscr();

        if (handler != NULL) {
            int i;
            for (thread = OS_THREAD_QUEUE.head; thread != NULL;
                 thread = thread->nextActive) {
                // Resume this thread with FP exception reporting enabled.
                thread->context.srr1 |= (MSR_FE0 | MSR_FE1);

                if (!(thread->context.state & OS_CONTEXT_STATE_FP_SAVED)) {
                    // The thread owns no FPU state: mark that it now does and
                    // leave its registers as all-ones QNaNs, which raise an
                    // invalid operation as soon as the thread uses them.
                    thread->context.state |= OS_CONTEXT_STATE_FP_SAVED;

                    for (i = 0; i < 32; i++) {
                        *(u64*)&thread->context.fprs[i] = 0xFFFFFFFFFFFFFFFF;
                        *(u64*)&thread->context.psfs[i] = 0xFFFFFFFFFFFFFFFF;
                    }

                    thread->context.fpscr = FPSCR_NI;
                }
                thread->context.fpscr |=
                    __OSFpscrEnableBits & FPSCR_ENABLE;
                thread->context.fpscr &= FPSCR_KEEP;
            }

            fpscr |= __OSFpscrEnableBits & FPSCR_ENABLE;
            msr |= (MSR_FE0 | MSR_FE1);
        } else {
            for (thread = OS_THREAD_QUEUE.head; thread != NULL;
                 thread = thread->nextActive) {
                thread->context.srr1 &= ~(MSR_FE0 | MSR_FE1);
                thread->context.fpscr &= ~FPSCR_ENABLE;
                thread->context.fpscr &= FPSCR_KEEP;
            }

            fpscr &= ~FPSCR_ENABLE;
            msr &= ~(MSR_FE0 | MSR_FE1);
        }

        PPCMtfpscr(fpscr & FPSCR_KEEP);
        PPCMtmsr(msr);
    }

    OSRestoreInterrupts(enabled);
    return oldHandler;
}

void __OSUnhandledException(u8 error, OSContext* ctx, u32 dsisr, u32 dar) {
    // Last resort for an exception: reached from OSDefaultExceptionHandler with
    // the exception's OSErrorType number, the context saved at the exception
    // and the DSISR/DAR that describe it. Runs the installed error handler with
    // the scheduler locked and resumes from the context, or reports everything
    // known about the exception and halts.
    s64 tb = OSGetTime();

    // Without MSR[RI] the interrupted state is not restartable.
    if (!(ctx->srr1 & MSR_RI)) {
        OSReport("Non-recoverable Exception %d", error);
    } else {
        // A program exception raised by a floating-point instruction this
        // thread may not execute belongs to the FP exception handler.
        if (error == OS_ERR_PROGRAM && ctx->srr1 & SRR1_FP_UNAVAILABLE &&
            __OSErrorTable[OS_ERR_FP_EXCEPTION] != NULL) {
            u32 msr;
            u32 fpscr;

            error = OS_ERR_FP_EXCEPTION;

            // Enable the FPU so FPSCR itself can be read and cleaned.
            msr = PPCMfmsr();
            PPCMtmsr(msr | MSR_FP);

            if (OS_CURRENT_FPU_CONTEXT != NULL) {
                OSSaveFPUContext(OS_CURRENT_FPU_CONTEXT);
            }

            fpscr = PPCMffpscr();
            PPCMtfpscr(fpscr & FPSCR_KEEP);
            PPCMtmsr(msr);

            if (OS_CURRENT_FPU_CONTEXT == ctx) {
                // The faulting thread owns the FPU: report it, then take the
                // FPU away again (MSR[FP] cleared) so its next floating-point
                // instruction traps and the FPU is handed over cleanly.
                OSDisableScheduler();
                __OSErrorTable[error](error, ctx, dsisr, dar);
                ctx->srr1 &= ~MSR_FP;
                OS_CURRENT_FPU_CONTEXT = NULL;
                ctx->fpscr &= FPSCR_KEEP;
                OSEnableScheduler();
                __OSReschedule();
            } else {
                ctx->srr1 &= ~MSR_FP;
                OS_CURRENT_FPU_CONTEXT = NULL;
            }

            OSLoadContext(ctx);
        }

        // A handler for the exception takes over the thread when it returns.
        if (__OSErrorTable[error] != NULL) {
            OSDisableScheduler();
            __OSErrorTable[error](error, ctx, dsisr, dar);
            OSEnableScheduler();
            __OSReschedule();
            OSLoadContext(ctx);
        }

        // The decrementer exception has a handler of its own; the thread just
        // continues if we ever get here with it.
        if (error == OS_ERR_DECREMENTER) {
            OSLoadContext(ctx);
        }

        OSReport("Unhandled Exception %d", error);
    }

    OSReport("\n");
    OSDumpContext(ctx);
    OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    OSReport("TB = 0x%016llx\n", tb);
    // Say what the faulting address was, as far as the exception tells us.
    switch (error) {
    case OS_ERR_DSI:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access "
                 "invalid address 0x%x (read from DAR)\n",
                 ctx->srr0, dar);
        break;
    case OS_ERR_ISI:
        OSReport("\nAttempted to fetch instruction from invalid address 0x%x "
                 "(read from SRR0)\n",
                 ctx->srr0);
        break;
    case OS_ERR_ALIGNMENT:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access "
                 "unaligned address 0x%x (read from DAR)\n",
                 ctx->srr0, dar);
        break;
    case OS_ERR_PROGRAM:
        OSReport("\nProgram exception : Possible illegal instruction/operation "
                 "at or around 0x%x (read from SRR0)\n",
                 ctx->srr0, dar);
        break;
    case OS_ERR_PROTECTION:
        // A DSP/DMA protection fault: show the addresses each DMA engine was
        // working on.
        OSReport("\n");
        OSReport("AI DMA Address =   0x%04x%04x\n",
                 DSP_HW_REGS[DSP_AI_DMA_START_H],
                 DSP_HW_REGS[DSP_AI_DMA_START_L]);
        OSReport("ARAM DMA Address = 0x%04x%04x\n",
                 DSP_HW_REGS[DSP_AR_DMA_MMADDR_H],
                 DSP_HW_REGS[DSP_AR_DMA_MMADDR_L]);
        OSReport("DI DMA Address =   0x%08x\n", DI_HW_REGS[DI_DMA_ADDR]);
        break;
    }

    // The last interrupt may well be what went wrong.
    OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n",
             __OSLastInterrupt, __OSLastInterruptSrr0, __OSLastInterruptTime);
    PPCHalt();
}
