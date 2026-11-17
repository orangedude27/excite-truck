#include <types.h>

extern u32 lbl_8055D6E0;

u32 fn_800300F4(void) {
    return 1;
}

u32 fn_800300FC(void) {
    /* No-op MetroTRK console-write handler stub; its caller __write_console ignores the result. */
    return 1;
}

void InitMetroTRK(void) {
}

void EnableMetroTRKInterrupts(void) {
}

/* Atomically replace the MetroTRK callback handler and return the previous one. */
u32 fn_8003010C(u32 value) {
    u32 old = lbl_8055D6E0;
    BOOL enabled = OSDisableInterrupts();
    lbl_8055D6E0 = value;
    OSRestoreInterrupts(enabled);
    return old;
}
