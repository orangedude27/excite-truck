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
  extern void fn_80036624(s32);
  extern void fn_8003AF1C(s32, s32, void *);
  
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
            task = *(void **)((u8 *)task + 0x38);
            *(void **)((u8 *)task + 0x3c) = 0;
            return;
        }
        lbl_8055D824 = 0; lbl_8055D81C = 0; lbl_8055D820 = 0;
        return;
    }
    if (lbl_8055D81C == task) {
        lbl_8055D81C = *(void **)((u8 *)task + 0x3c);
        task = *(void **)((u8 *)task + 0x3c);
        *(void **)((u8 *)task + 0x38) = 0;
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

void fn_80035DA8(s32 arg0) {
    s32 enabled;
    u32 index;
    u8 *info;

    enabled = OSDisableInterrupts();
    if (lbl_8055D848 >= 5) {
        lbl_8055D848 = 0;
    }
    index = lbl_8055D848;
    info = (u8 *)__ErrorInfo + index * 0x14;
    *(s32 *)(info + 0x1C) = 0x10;
    *(s32 *)(info + 0x20) = 0;
    *(s32 *)(info + 0x24) = 0;
    *(s32 *)(info + 0x2C) = OSGetTick();
    lbl_8055D848 = index + 1;
    OSRestoreInterrupts(enabled);
    fn_8003AF1C(0, 0, fn_80036624);
    #pragma unused(arg0)
}

extern s32 MotorState_8055D8A8;
extern s32 lbl_8055D8BC;
extern void __DVDClearWaitingQueue(void);
extern void fn_80038368(void *);
extern void fn_800379A8(void);
extern BOOL __OSInIPL;
void fn_8003773C(void) {
    s32 command = lbl_8055D8BC;
    MotorState_8055D8A8 = 1;
    switch (command) {
    case 4: case 5: case 13: case 15: case 18: case 33: case 34: {
        void *block;
        void (*callback)(s32, void *);
        __DVDClearWaitingQueue();
        block = (void *)executing_8055D8C8;
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        callback = *(void (**)(s32, void *))((char *)block + 0x28);
        if (callback != 0)
            callback(-4, block);
        fn_80038040();
        break;
    }
    case 32:
        MotorState_8055D8A8 = 0;
    case 35: case 36: case 37:
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 1;
        fn_80038368((void *)executing_8055D8C8);
        break;
    case 1: case 2:
        if (__OSInIPL)
            break;
    case 38:
    default:
        MotorState_8055D8A8 = 0;
        fn_8003B380(1);
        fn_8003B38C(fn_800379A8);
        break;
    }
}

extern s32 fn_8003BCDC(s32);
extern void fn_8003B69C(u32, void*);
extern void fn_80037B54(void);
void fn_80037A8C(void) {
    s32 enabled;
    u8 *base;
    fn_8003BCDC(0);
    enabled = OSDisableInterrupts();
    if (lbl_8055D848 >= 5) lbl_8055D848 = 0;
    base = (u8*)__ErrorInfo;
    *(s32*)(base + (*(volatile u32*)&lbl_8055D848) * 0x14 + 0x1C) = 0x25;
    *(s32*)(base + (*(volatile u32*)&lbl_8055D848) * 0x14 + 0x20) = 0;
    *(s32*)(base + (*(volatile u32*)&lbl_8055D848) * 0x14 + 0x24) = 0;
    *(s32*)(base + (*(volatile u32*)&lbl_8055D848) * 0x14 + 0x2C) = OSGetTick();
    lbl_8055D848 = (*(volatile u32*)&lbl_8055D848) + 1;
    OSRestoreInterrupts(enabled);
    fn_8003B69C(0x20000, fn_80037B54);
}

extern void fn_8003A834(void *, void *);
extern char lbl_80376B00[];
extern void fn_80037DBC(void);
void fn_80037CEC(void) {
    s32 enabled;
    u8 *base;
    fn_8003BCDC(0);
    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 >= 5)
        lbl_8055D848 = 0;
    base = (u8 *)__ErrorInfo;
    *(s32 *)(base + (*(volatile u32 *)&lbl_8055D848) * 0x14 + 0x1C) = 5;
    *(s32 *)(base + (*(volatile u32 *)&lbl_8055D848) * 0x14 + 0x20) = 0;
    *(s32 *)(base + (*(volatile u32 *)&lbl_8055D848) * 0x14 + 0x24) = 0x20;
    *(s32 *)(base + (*(volatile u32 *)&lbl_8055D848) * 0x14 + 0x2C) = OSGetTick();
    lbl_8055D848 = (*(volatile u32 *)&lbl_8055D848) + 1;
    OSRestoreInterrupts(enabled);
    fn_8003A834(lbl_80376B00, fn_80037DBC);
}

void fn_8003801C(void) {
    if (lbl_8055D880 != 0) {
        return;
    }
    lbl_8055D880 = 1;
    fn_8003BB58(fn_80037E94);
}

extern u8 lbl_8037B5B0;
extern s32 __DVDGetNextWaitingQueue(void);
extern __declspec(section ".data") u8 lbl_8037B5B0;
s32 DVDGetCommandBlockStatus(void *arg0) {
    s32 status;
    s32 enabled;

    enabled = OSDisableInterrupts();
    if (*(s32 *)((u8 *)arg0 + 0xC) == 3) {
        status = 1;
    } else if (*(s32 *)((u8 *)arg0 + 0xC) == 5) {
        status = 4;
    } else if ((u32)executing_8055D8C8 == (u32)&lbl_8037B5B0) {
        if (__DVDGetNextWaitingQueue() != 0) {
            if ((u32)arg0 == (u32)__DVDGetNextWaitingQueue()) status = 1;
            else status = *(s32 *)((u8 *)arg0 + 0xC);
        } else if ((u32)arg0 == (u32)&lbl_8037B5B0) status = 0;
        else status = *(s32 *)((u8 *)arg0 + 0xC);
    } else {
        status = *(s32 *)((u8 *)arg0 + 0xC);
    }
    OSRestoreInterrupts(enabled);
    return status;
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

