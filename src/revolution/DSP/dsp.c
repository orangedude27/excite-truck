#include <revolution/DSP.h>

BOOL DSPCheckMailToDSP(void) {
    return (DSP_HW_REGS[DSP_DSPMBOX_H] & DSP_DSPMBOX_H_STATUS) != 0;
}

BOOL DSPCheckMailFromDSP(void) {
    return (DSP_HW_REGS[DSP_CPUMBOX_H] & DSP_CPUMBOX_H_STATUS) != 0;
}

// Read the 32-bit mail sent from the DSP by combining the CPU mail box's high and low 16-bit halves.
DSPMail DSPReadMailFromDSP(void) {
    return (DSPMail)(DSP_HW_REGS[DSP_CPUMBOX_H] << 16 |
                     DSP_HW_REGS[DSP_CPUMBOX_L]);
}

// Send a 32-bit mail to the DSP by splitting it into the DSP mail box's high and low 16-bit halves.
void DSPSendMailToDSP(DSPMail mail) {
    DSP_HW_REGS[DSP_DSPMBOX_H] = ((uintptr_t)mail) >> 16 & 0xFFFF;
    DSP_HW_REGS[DSP_DSPMBOX_L] = ((uintptr_t)mail) & 0xFFFF;
}
