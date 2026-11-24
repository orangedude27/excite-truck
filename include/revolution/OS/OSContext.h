#ifndef RVL_SDK_OS_CONTEXT_H
#define RVL_SDK_OS_CONTEXT_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OS_CONTEXT_STATE_FP_SAVED = (1 << 0),
    // The context also holds the caller-saved registers r5-r12: OSLoadContext()
    // restores r5-r31 instead of r13-r31 and clears this as it goes, and the
    // scheduler (SelectThread) sees no need to OSSaveContext() over them.
    OS_CONTEXT_STATE_GPRS_SAVED = (1 << 1),
} OSContextState;

typedef struct OSContext {
    u32 gprs[32];  // at 0x0
    u32 cr;        // at 0x80
    u32 lr;        // at 0x84
    u32 ctr;       // at 0x88
    u32 xer;       // at 0x8C
    f64 fprs[32];  // at 0x90
    u32 fpscr_pad; // at 0x190
    u32 fpscr;     // at 0x194
    u32 srr0;      // at 0x198
    u32 srr1;      // at 0x19C
    u16 mode;      // at 0x1A0
    u16 state;     // at 0x1A2
    u32 gqrs[8];   // at 0x1A4
    u32 psf_pad;   // at 0x1C4
    f64 psfs[32];  // at 0x1C8
} OSContext;

/* Save the current FPU state into ctx (tail-branches to __OSSaveFPUContext); hand-written assembly. */
void OSSaveFPUContext(OSContext* ctx);
/* Make ctx the current OS context: publish it and its 4-byte-aligned physical
   address in the OS globals, then enable the FPU (MSR_FP in srr1/MSR) when ctx
   owns the current FPU context and disable it otherwise. Hand-written assembly. */
/* Make ctx the current OS context: publish it and its 4-byte-aligned physical
   address in the OS globals, then enable the FPU (MSR_FP in srr1/MSR) when ctx
   owns the current FPU context and disable it otherwise. Hand-written assembly. */
void OSSetCurrentContext(OSContext* ctx);
OSContext* OSGetCurrentContext(void);
/* Save the current CPU context into ctx: GPRs r13-r31, GQRs 1-7, CR, LR,
   SRR0/SRR1, CTR, XER and the stack/TOC pointers. r3 is stored as 1 so a
   resumed context returns TRUE. Hand-written assembly. */
/* Save the current CPU context into ctx: GPRs r13-r31, GQRs 1-7, CR, LR,
   SRR0/SRR1, CTR, XER and the stack/TOC pointers. r3 is stored as 1 so a
   resumed context returns TRUE. Hand-written assembly. */
BOOL OSSaveContext(OSContext* ctx);
void OSLoadContext(OSContext* ctx);
/* Return the current stack pointer (GPR r1); hand-written assembly. */
void* OSGetStackPointer(void);
void OSSwitchFiber(void* func, void* stack);
void OSSwitchFiberEx(u32 r3, u32 r4, u32 r5, u32 r6, void* func, void* stack);
void OSClearContext(OSContext* ctx);
/* Initialize a fresh thread context for a new thread: _srr0 is the thread's
   entry point (stored into srr0), stack its initial stack pointer. Also sets
   srr1 to the default machine state (0x9032), zeros the GPRs/GQRs/CR/XER while
   preserving r2/r13, and tail-calls OSClearContext to clear mode/state/FPU.
   Hand-written assembly. */
void OSInitContext(OSContext* ctx, void* _srr0, void* stack);
void OSDumpContext(const OSContext* ctx);
void __OSContextInit(void);

#ifdef __cplusplus
}
#endif
#endif
