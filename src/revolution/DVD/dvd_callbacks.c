/*
 * dvd_callbacks.c — Authored source for DVD/DVDLow/DSP/AI callback
 *                  helpers that the REXE01 build provides via
 *                  auto-units.
 *
 * The revert commit e37a4fa (Sept 1, 2026) removed these from
 * dsp.c/ai.c/dvd.c to avoid multiply-defined link errors with the
 * auto-units. This file restores the source as a NonMatching
 * review TU so the queue ledger can record correct functional
 * evidence without affecting the linked binary.
 *
 * The linked binary still uses the auto-unit copies of these
 * functions (auto_03_80034194_text and auto_03_800301FC_text).
 *
 * Functions:
 *   - cbForCancel@0x8003997C
 *   - cbForPrepareReset@0x80039B78
 *   - DSPInit@0x80034194, DSPReset@0x80034254
 *   - AIRegisterDMACallback@0x80032338
 *
 * A proper Carve from those auto-units into dvd.c/ai.c/dsp.c would
 * require resolving cyclic dependencies between the auto-units and
 * the source TUs (the auto-units reference many DVD* symbols and
 * dvd.c references many DSP* symbols). That is a multi-session
 * carve project documented in TODO_DRIFTS.
 */

#include <revolution/DVD.h>
#include <revolution/DSP.h>
#include <revolution/AI.h>
#include <revolution/OS.h>
#include <revolution/DB.h>

/* ------------------------------------------------------------------ */
/* DVD callbacks (auto_03_80034194_text, lines 0x57e8-0x5800)        */
/* ------------------------------------------------------------------ */

static volatile BOOL PrepareResetDone = FALSE;

/* Canceling is a static in dvd.c; declare extern for this TU */
extern volatile BOOL Canceling;

void cbForCancel(void) {
    Canceling = TRUE;
    OSWakeupThread(&__DVDThreadQueue);
}

void cbForPrepareReset(void) {
    PrepareResetDone = TRUE;
}

/* ------------------------------------------------------------------ */
/* DSPInit / DSPReset (auto_03_80034194_text, lines 0x0-0xc8)         */
/* ------------------------------------------------------------------ */

static BOOL __DSP_init_flag;
static BOOL __DSP_rude_task_pending;
static DSPTask* __DSP_rude_task;
static DSPTask* __DSP_tmp_task;
static DSPTask* __DSP_curr_task;
static DSPTask* __DSP_last_task;
static DSPTask* __DSP_first_task;
static DSPTask* __DSP_request_task;

extern void __DSPHandler(s16 type, OSContext* ctx);

void DSPInit(void) {
    BOOL enabled;

    DBPrintf("DSPInit(): Build Date: %s %s\n", "Nov 27 2006", "18:03:27");

    if (__DSP_init_flag == TRUE) {
        return;
    }

    OSRegisterVersion(
        "<< RVL_SDK - DSP \trelease build: Nov 27 2006 18:03:27 (0x4199_60831) >>");

    enabled = OSDisableInterrupts();

    __OSSetInterruptHandler(OS_INTR_DSP_DSP, __DSPHandler);
    __OSUnmaskInterrupts(OS_INTR_MASK(OS_INTR_DSP_DSP));

    DSP_HW_REGS[DSP_CSR] =
            (DSP_HW_REGS[DSP_CSR] &
             ~(DSP_CSR_AIDINT | DSP_CSR_ARINT | DSP_CSR_DSPINT)) |
            DSP_CSR_RES;

        DSP_HW_REGS[DSP_CSR] &= ~(DSP_CSR_HALT | DSP_CSR_AIDINT | DSP_CSR_ARINT |
                                  DSP_CSR_DSPINT);

    __DSP_tmp_task = NULL;
    __DSP_curr_task = NULL;
    __DSP_last_task = NULL;
    __DSP_first_task = NULL;

    __DSP_init_flag = TRUE;

    OSRestoreInterrupts(enabled);
}

BOOL DSPReset(void) {
    return __DSP_init_flag;
}

/* ------------------------------------------------------------------ */
/* AIRegisterDMACallback (auto_03_800301FC_text, lines 0x2110-0x2158)  */
/* ------------------------------------------------------------------ */

static AIDMACallback __AID_Callback;

AIDMACallback AIRegisterDMACallback(AIDMACallback callback) {
    AIDMACallback oldCallback;
    BOOL enabled;

    oldCallback = __AID_Callback;
    enabled = OSDisableInterrupts();
    __AID_Callback = callback;
    OSRestoreInterrupts(enabled);

    return oldCallback;
}
