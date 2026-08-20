#include <types.h>

extern u32 lbl_8055D6E0;

u32 fn_800300F4(void) {
    return 1;
}

u32 fn_800300FC(void) {
    return 1;
}

void InitMetroTRK(void) {
}

void EnableMetroTRKInterrupts(void) {
}

u32 fn_8003010C(u32 value) {
    u32 old = lbl_8055D6E0;
    BOOL enabled = OSDisableInterrupts();
    lbl_8055D6E0 = value;
    OSRestoreInterrupts(enabled);
    return old;
}
