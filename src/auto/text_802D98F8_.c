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
    /* Power-button callback: log the press and set the flag that drives the shutdown sequence. */
    OSReport(lbl_8034C828);
    lbl_8055FE41 = 1;
}
#pragma scheduling on

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802D992C(void) {
    s32 count = (u32)__cntlzw((u32)(lbl_8055FE3C - 1)) >> 5;
    s32 driveStatus = DVDGetDriveStatus();
    switch (driveStatus) {
    case 0: lbl_8055FE3C = 0; break;
    case -1: lbl_8055FE3C = 2; break;
    case 5: lbl_8055FE3C = 4; break;
    case 6: lbl_8055FE3C = 5; break;
    case 4: lbl_8055FE3C = 3; break;
    case 11: lbl_8055FE3C = 6;
    case 1: case 2: case 3: case 7: case 8: case 9: case 10:
        if (OSGetResetButtonState()) {
            lbl_8055FE40 = 1;
        } else if (lbl_8055FE40) {
            lbl_8055FE40 = 0;
            lbl_8055FE3C = 1;
        }
        break;
    default: break;
    }
    if (count != 0 && lbl_8055FE3C != 2)
        lbl_8055FE3C = 1;
    if (lbl_8055FE3C != lbl_8055FE44) {
        char *msg = lbl_8034C838;
        lbl_8055FE44 = lbl_8055FE3C;
        OSReport(msg);
    }
    if (GXGetCurrentGXThread())
        fn_802D3DAC();
}

extern void KERNEL_Reset(int);
extern void fn_802E30C8(const char *, ...);
extern void fn_80129AFC(void);
extern void fn_802E6264(void);
extern void fn_802E7FD0(void);
extern int OSDisableInterrupts(void);
extern int OSEnableInterrupts(void);
extern int GX_IsXFBSet(void);
extern void fn_802C2AA8(int);
extern void gxResetFrameCopyState(int);
extern void fn_802DB03C(void *);
extern void fn_802C2B18(void);
#pragma opt_propagation off
void fn_802D9A50(void) {
    extern unsigned char lbl_8055FFB4;
    extern unsigned char lbl_8055FE38;
    extern unsigned char lbl_8055FE39;
    extern unsigned char lbl_8055FE48;
    extern s32 lbl_8055FE4C;
    extern char lbl_8034C680[];

    register char *msgBase;
    register void **stateMessages;
    register u8 flagOn;
    register s32 noFramebuffer;
    register s32 driveState;

    /* DVD-drive / power-button monitor: while the drive state is nonzero, react
       to the power button and reset requests by logging status messages and
       calling the kernel reset (KERNEL_Reset) or the state's message screen, then
       finalize once the drive returns to idle. */
    msgBase = lbl_8034C680;
    if (lbl_8055FFB4 != 0)
        return;

    if (lbl_8055FE38 != 0) {
        KERNEL_Reset(0);
        lbl_8055FE38 = 0;
    }
    if ((u8)lbl_8055FE41 != 0)
        KERNEL_Reset(2);
    if (*(volatile s32 *)&lbl_8055FE3C != 1)
        lbl_8055FE4C = 0;

    stateMessages = (void **)(msgBase + 0x18C);
    flagOn = 1;
    for (;;) {
        driveState = *(volatile s32 *)&lbl_8055FE3C;
        if (driveState == 0)
            break;
        if ((u8)lbl_8055FE41 != 0)
            KERNEL_Reset(2);
        if (driveState == 1) {
            register subsystemClear = (u32)__cntlzw((u32)lbl_8055FE39) >> 5;
            lbl_8055FE4C++;
            if ((unsigned)subsystemClear != 0) {
                fn_802E30C8(msgBase + 0x1FC);
                KERNEL_Reset(0);
            } else {
                fn_802E30C8(msgBase + 0x210);
                lbl_8055FE38 = 1;
            }
            break;
        }

        fn_80129AFC();
        fn_802E6264();
        fn_802E7FD0();
        OSDisableInterrupts();
        noFramebuffer = GX_IsXFBSet() == 0;
        OSEnableInterrupts();
        if (noFramebuffer != 0 && lbl_8055FE48 == 0) {
            lbl_8055FE48 = flagOn;
            fn_802E30C8(msgBase + 0x224);
            fn_802C2AA8(2);
        }
        gxResetFrameCopyState(0);
        fn_802DB03C(stateMessages[driveState]);
        OSEnableInterrupts();
    }

    OSDisableInterrupts();
    if (lbl_8055FE48 != 0 && lbl_8055FE3C == 0) {
        fn_802E30C8(msgBase + 0x240);
        lbl_8055FE48 = 0;
        fn_802C2B18();
    }
    OSEnableInterrupts();
}
#pragma opt_propagation reset

#pragma scheduling on
#pragma pop
BOOL fn_802D9BF0(void) {
    /* Return TRUE when the DVD drive state is non-zero (a disc is present / the drive is not idle). */
    return lbl_8055FE3C != 0;
}

/* Return TRUE when the DVD-drive state variable (lbl_8055FE3C) is 1 (ready). */
BOOL fn_802D9C04(void) {
    return (lbl_8055FE3C - 1) == 0;
}

/* Registers the AI DMA callback (the DVD state poller) and the power/reset callback. */
void fn_802D9C18(void) {
    AIRegisterDMACallback_800591F0((s32)fn_802D992C);
    OSSetPowerCallback((OSStateCallback)fn_802D98F8);
}

void fn_802D9C4C(void) {
    /* Unregister the AI DMA callback (the DVD state poller fn_802D992C) by clearing it to NULL. */
    AIRegisterDMACallback_800591F0(0);
}
