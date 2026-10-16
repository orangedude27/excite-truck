#include "revolution/OS/OSStateTM.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void AIRegisterDMACallback_800591F0(s32);
void fn_802D992C(void);
void fn_802D98F8(void);
extern s32 lbl_8055FE3C;
BOOL fn_802D9C04(void) {
    return (lbl_8055FE3C - 1) == 0;
}

void fn_802D9C18(void) {
    AIRegisterDMACallback_800591F0((s32)fn_802D992C);
    OSSetPowerCallback((OSStateCallback)fn_802D98F8);
}

void fn_802D9C4C(void) {
    AIRegisterDMACallback_800591F0(0);
}
