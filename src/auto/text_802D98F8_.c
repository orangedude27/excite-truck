#include "revolution/OS/OSStateTM.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void AIRegisterDMACallback_800591F0(s32);
void fn_802D992C(void);
void fn_802D98F8(void);
extern s32 lbl_8055FE3C;
extern u8 lbl_8055FE40;
extern s32 lbl_8055FE44;
extern char lbl_8034C838[];
extern void *jumptable_8034C848[];
extern s32 DVDGetDriveStatus(void);
extern BOOL OSGetResetButtonState(void);
extern void OSReport(const char *, ...);
extern void *GXGetCurrentGXThread(void);
extern void fn_802D3DAC(void);
extern int __cntlzw(unsigned int);
extern char lbl_8034C828[];
extern char lbl_8055FE41;
#pragma scheduling invalid_target
void fn_802D98F8(void) {
    OSReport(lbl_8034C828);
    lbl_8055FE41 = 1;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D992C(void) {
    s32 count = (u32)__cntlzw((u32)(lbl_8055FE3C - 1)) >> 5;
    s32 state = DVDGetDriveStatus();
    switch (state) {
    case -1:
        lbl_8055FE3C = 0;
        goto done;
    case 0:
        lbl_8055FE3C = 2;
        goto done;
    case 1:
        lbl_8055FE3C = 4;
        goto done;
    case 2:
        lbl_8055FE3C = 5;
        goto done;
    case 3:
        lbl_8055FE3C = 3;
        goto done;
    case 4:
        lbl_8055FE3C = 6;
        goto done;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        goto reset;
    default:
        goto done;
    }
reset:
    if (OSGetResetButtonState()) {
        lbl_8055FE40 = 1;
    } else if (lbl_8055FE40) {
        lbl_8055FE40 = 0;
        lbl_8055FE3C = 1;
    }
done:
    if (count != 0 && lbl_8055FE3C != 2) {
        lbl_8055FE3C = 1;
    }
    if (lbl_8055FE3C != lbl_8055FE44) {
        lbl_8055FE44 = lbl_8055FE3C;
        OSReport(lbl_8034C838);
    }
    if (GXGetCurrentGXThread()) {
        fn_802D3DAC();
    }
}

#pragma scheduling on
#pragma pop
BOOL fn_802D9BF0(void) {
    return lbl_8055FE3C != 0;
}

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
