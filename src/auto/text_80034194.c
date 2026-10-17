// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern s32 lbl_8055D890;
extern s32 lbl_8055D880;
extern s32 lbl_8055D8AC;
extern s32 lbl_8055D85C;
extern u8 lbl_8037B580;
extern s32 fn_8003BE40(void);
extern void fn_80037E94(void);
extern void fn_8003BB58(void (*callback)(void));
extern void fn_8003B380(s32);
extern void fn_8003B38C(void *);
extern void fn_80035B88(void);

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

extern void *BootInfo_8055D844;
extern u8 *FstStringStart_8055D83C;
extern void *lbl_8055D81C;
extern void *lbl_8055D820;
extern void *lbl_8055D824;
void __DSP_remove_task(void *task) {
    *(u32 *)((u8 *)task + 8) = 0;
    *(u32 *)task = 3;
    if (lbl_8055D820 == task) {
        void *next = *(void **)((u8 *)task + 0x38);
        if (next != 0) {
            lbl_8055D820 = next;
            *(void **)((u8 *)next + 0x3c) = 0;
            return;
        }
        lbl_8055D824 = 0; lbl_8055D81C = 0; lbl_8055D820 = 0;
        return;
    }
    if (lbl_8055D81C == task) {
        lbl_8055D81C = *(void **)((u8 *)task + 0x3c);
        *(void **)((u8 *)lbl_8055D81C + 0x38) = 0;
        lbl_8055D824 = lbl_8055D820;
        return;
    }
    lbl_8055D824 = *(void **)((u8 *)task + 0x38);
    *(void **)((u8 *)*(void **)((u8 *)task + 0x3c) + 0x38) = *(void **)((u8 *)task + 0x38);
    *(void **)((u8 *)*(void **)((u8 *)task + 0x38) + 0x3c) = *(void **)((u8 *)task + 0x3c);
}

extern void DVDCancel(void);
extern u32 MaxEntryNum_8055D838;
extern void *BootInfo_8055D844;
extern u8 *FstStringStart_8055D83C;
extern void *lbl_8055D81C;
extern void *lbl_8055D820;
extern void *lbl_8055D824;
extern u8 *FstStart_8055D840;
extern u32 __DVDLayoutFormat;
extern u32 lbl_8055D848;
extern char __ErrorInfo[];
extern s32 OSGetTick(void);
s32 DVDClose(void) {
    DVDCancel();
    return 1;
}

void cbForReadAsync(void *arg0, void *arg1) {
    void (*callback)(void);
    callback = *(void (**)(void))((u8 *)arg1 + 0x38);
    if (callback != 0) {
        callback();
    }
}

void cbForCancelSync(void) {
    OSWakeupThread(__DVDThreadQueue);
}

void fn_800356F4(s32 arg0, s32 arg1, s32 arg2) {
    s32 enabled;
    u32 index;
    u8 *info;
    enabled = OSDisableInterrupts();
    if (lbl_8055D848 >= 5) {
        lbl_8055D848 = 0;
    }
    index = lbl_8055D848;
    info = (u8 *)__ErrorInfo + index * 0x14;
    *(s32 *)(info + 0x1C) = arg0;
    *(s32 *)(info + 0x20) = arg1;
    *(s32 *)(info + 0x24) = arg2;
    *(s32 *)(info + 0x2C) = OSGetTick();
    lbl_8055D848 = index + 1;
    OSRestoreInterrupts(enabled);
}

void fn_800357A8(void) {

}

void fn_80035C64(void) {
    fn_8003AF1C(0, 0, fn_80035B88);
}

extern s32 lbl_8055D890;
extern u8 lbl_8037B580;
extern s32 fn_8003BE40(void);
extern s32 lbl_8055D880;
extern void fn_80037E94(void);
extern void fn_8003BB58(void (*callback)(void));
extern void fn_8003B380(s32);
extern void fn_8003B38C(void *);
extern void fn_80035B88(void);
extern s32 lbl_8055D8AC;
extern s32 lbl_8055D85C;
void fn_80035C78(void) {
    fn_8003B380(0);
    fn_8003B38C(fn_80035B88);
    lbl_8055D8AC = 0;
    lbl_8055D85C = 0;
}

void fn_8003801C(void) {
    if (lbl_8055D880 != 0) {
        return;
    }
    lbl_8055D880 = 1;
    fn_8003BB58(fn_80037E94);
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

void cbForPrepareReset(void) {
    lbl_8055D890 = 1;
}

s32 __DVDTestAlarm(void *alarm) {
    if (alarm == &lbl_8037B580) {
        return 1;
    }
    return fn_8003BE40();
}

u32 fn_80039CD8(void) { return 1; }

void fn_80039CE0(void) {

}

