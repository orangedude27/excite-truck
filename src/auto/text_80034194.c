// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_80558E04;
extern s32 lbl_8055D84C;
extern volatile s32 PausingFlag_8055D850;
extern s32 FatalErrorFlag_8055D854;
extern s32 executing_8055D8C8;
extern char __DVDThreadQueue[4];
extern char DummyCommandBlock_80376AA0[32];

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32);
extern void OSWakeupThread(void *queue);
extern void fn_80038040(void);
extern s32 DVDGetCommandBlockStatus(void *block);

extern void *lbl_8055D808;
void* DSPReset(void) {
    return lbl_8055D808;
}

void DBPrintf_800343C8(const char *fmt, ...) {
#pragma unused(fmt)
}

void cbForCancelSync(void) {
    OSWakeupThread(__DVDThreadQueue);
}

void fn_800357A8(void) {

}

s32 DVDGetDriveStatus(void) {
    s32 enabled;
    s32 state;

    enabled = OSDisableInterrupts();

    if (FatalErrorFlag_8055D854 != 0) {
        state = -1;
    } else if (PausingFlag_8055D850 != 0) {
        state = 8;
    } else if (executing_8055D8C8 == 0) {
        state = 0;
    } else if ((u32)executing_8055D8C8 == (u32)DummyCommandBlock_80376AA0) {
        state = 0;
    } else {
        state = DVDGetCommandBlockStatus((void *)executing_8055D8C8);
    }

    OSRestoreInterrupts(enabled);
    return state;
}

s32 fn_800393C4(s32 value) {
    s32 old;

    old = lbl_80558E04;
    lbl_80558E04 = value;
    return old;
}

void fn_800393D4(void) {
    s32 enabled;

    enabled = OSDisableInterrupts();
    lbl_8055D84C = 0;
    if (PausingFlag_8055D850 != 0) {
        PausingFlag_8055D850 = 0;
        fn_80038040();
    }
    OSRestoreInterrupts(enabled);
}

void fn_80039838(void) {
    OSWakeupThread(__DVDThreadQueue);
}

extern s32 lbl_8055D864;
void cbForCancel(void) {
    lbl_8055D864 = 1;
    OSWakeupThread(&__DVDThreadQueue);
}

extern void *lbl_8055D88C;
void fn_8003998C(void* hi) {
    lbl_8055D88C = hi;
}

void fn_80039CE0(void) {

}

