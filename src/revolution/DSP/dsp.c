#include <revolution/DSP.h>
#include <revolution/OS.h>
#include <revolution/DB.h>

static BOOL __DSP_init_flag;
static BOOL __DSP_rude_task_pending;
static DSPTask* __DSP_rude_task;
static DSPTask* __DSP_tmp_task;
static DSPTask* __DSP_curr_task;
static DSPTask* __DSP_last_task;
static DSPTask* __DSP_first_task;
static DSPTask* __DSP_request_task;

BOOL DSPCheckMailToDSP(void) {
    return (DSP_HW_REGS[DSP_DSPMBOX_H] & DSP_DSPMBOX_H_STATUS) != 0;
}

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

BOOL DSPCheckMailFromDSP(void) {
    return (DSP_HW_REGS[DSP_CPUMBOX_H] & DSP_CPUMBOX_H_STATUS) != 0;
}

DSPMail DSPReadMailFromDSP(void) {
    return (DSPMail)(DSP_HW_REGS[DSP_CPUMBOX_H] << 16 |
                     DSP_HW_REGS[DSP_CPUMBOX_L]);
}

void DSPSendMailToDSP(DSPMail mail) {
    DSP_HW_REGS[DSP_DSPMBOX_H] = ((uintptr_t)mail) >> 16 & 0xFFFF;
    DSP_HW_REGS[DSP_DSPMBOX_L] = ((uintptr_t)mail) & 0xFFFF;
}