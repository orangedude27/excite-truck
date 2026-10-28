// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern s32 lbl_8055D864;
#include <revolution/OS/OSContext.h>
extern s32 lbl_8055D810;
extern void *lbl_8055D814;
extern void *lbl_8055D81C;
extern void *lbl_8055D820;
extern void *lbl_8055D824;
extern void __DSP_exec_task(void *, void *);
extern void __DSP_remove_task(void *);
extern s32 DSPCheckMailFromDSP(void);
extern s32 DSPCheckMailToDSP(void);
extern s32 DSPReadMailFromDSP(void);
extern void DSPSendMailToDSP(u32);
#include <ctype.h>

extern s32 __DVDPushWaitingQueue(s32, void *);

extern char lbl_80301DB0[];
extern s32 lbl_80558DE8;
extern s32 lbl_8055D818;
extern s32 __OSSetInterruptHandler(s32, void *);
extern s32 __OSUnmaskInterrupts(s32);
extern void __DSPHandler_80034418(s16, OSContext *);
extern void DBPrintf_800343C8(const char *, ...);

extern u8 *FstStart_8055D840;
extern u8 *FstStringStart_8055D83C;
extern u32 MaxEntryNum_8055D838;
extern __Locale lbl_802FE850;
extern s32 lbl_8055D828;
extern BOOL __DVDLongFileNameFlag;
__declspec(section ".sdata") extern char lbl_80558DF8[];
extern void OSPanic(const char *, s32, const char *);
extern char lbl_80558DF8[];
extern char lbl_80301F70[];

typedef struct DVDNode {
    union {
        struct {
            u32 is_folder : 8;
            u32 name : 24;
        };
        u32 packed_type_name;
    };
    union {
        struct {
            u32 parent_or_offset;
            u32 sibling_or_size;
        };
        struct {
            u32 offset;
            u32 size;
        };
        struct {
            u32 parent;
            u32 sibling_next;
        } folder;
    };
} DVDNode;

static inline int DVDPathLower(int c) {
    return (c < 0 || c >= 256) ? c :
           (int)lbl_802FE850.cmap->to_lower_table[c];
}

static inline BOOL DVDPathSame(const char *lhs, const char *rhs) {
    while (*rhs != '\0') {
        if (DVDPathLower(*lhs++) != DVDPathLower(*rhs++))
            return FALSE;
    }
    if (*lhs == '/' || *lhs == '\0')
        return TRUE;
    return FALSE;
}

extern void fn_80035C78(void);
extern void fn_80035E6C(void);
extern void fn_8003A1A0(u32, void (*)(void));
extern void fn_8003B218(void (*)(void));
extern u32 lbl_8055D848;
extern s32 lbl_8055D860;
extern char __ErrorInfo[];
extern void (*lbl_8055D8B8)(s32, void *);
extern void OSCreateAlarm(void *);
extern void OSSetPeriodicAlarm(void *, u32, u32, s32, u32, u32, void (*)(void));
extern s32 executing_8055D8C8;
extern char DummyCommandBlock_80376AA0[];
extern void __DVDFSInit(void);
extern void __DSP_boot_task(void *);
extern void __DSP_insert_task(void *);
extern void fn_80038040(void);
extern s32 OSGetTick(void);
extern s32 fn_8003BCDC(s32);
extern void DCInvalidateRange(void *, u32);

extern s32 DVDInitialized_8055D888;
extern s32 FirstTimeInBootrom_8055D868;
extern s32 IDShouldBe_8055D8C4;
extern s32 MotorState_8055D8A8;
extern u32 __DVDLayoutFormat;
extern char __DVDThreadQueue[4];
extern s32 __DVDVersion;
extern char __ErrorInfo[];
extern void *bootInfo_8055D8C0;
extern void OSRegisterVersion(s32);
extern void DVDLowInit(void);
extern void __DVDFSInit(void);
extern void __DVDClearWaitingQueue(void);
extern void OSInitThreadQueue(void *);
extern void DVDLowUnmaskStatusInterrupts(void);
extern void DVDLowMaskCoverInterrupt(void);
extern void *memset(void *, int, u32);
extern void *memcpy(void *, const void *, u32);
extern void DVDSetAutoFatalMessaging(s32, u8, void *, void *);

extern s32 lbl_8055D890;
extern s32 lbl_8055D880;
extern s32 lbl_8055D8AC;
extern s32 lbl_8055D85C;
#pragma small_data off
extern u8 lbl_8037B580;
#pragma small_data on
extern s32 fn_8003BE40(void);
extern void fn_80037E94(void);
extern void fn_8003BB58(void (*callback)(void));
extern void fn_8003B380(s32);
extern void fn_8003B38C(void *);
  extern void fn_80035B88(u32);
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
void DSPInit(void) {
    s32 interrupts;

    DBPrintf_800343C8(lbl_80301DB0 + 0x48,
                      lbl_80301DB0 + 0x68,
                      lbl_80301DB0 + 0x74);
    if ((s32)lbl_8055D808 != 1) {
        OSRegisterVersion(lbl_80558DE8);
        interrupts = OSDisableInterrupts();
        __OSSetInterruptHandler(7, __DSPHandler_80034418);
        __OSUnmaskInterrupts(0x01000000);
        *(volatile u16 *)0xCC00500A =
            (*(volatile u16 *)0xCC00500A & ~0xA8) | 0x800;
        *(volatile u16 *)0xCC00500A &= ~0xAC;
        lbl_8055D818 = 0;
        lbl_8055D824 = 0;
        lbl_8055D81C = 0;
        lbl_8055D820 = 0;
        lbl_8055D808 = (void *)1;
        OSRestoreInterrupts(interrupts);
    }
}

void* DSPReset(void) {
    return lbl_8055D808;
}

void *DSPAssertInt(void *arg0) {
    s32 enabled;

    enabled = OSDisableInterrupts();
    __DSP_insert_task(arg0);
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 8) = 1;
    OSRestoreInterrupts(enabled);
    if (arg0 == lbl_8055D820) {
        __DSP_boot_task(arg0);
    }
    return arg0;
}

void *__DSPHandler(void *arg0) {
    s32 interrupts;
    interrupts = OSDisableInterrupts();
    *(u32 *)((u8 *)arg0 + 8) |= 2;
    OSRestoreInterrupts(interrupts);
    return arg0;
}

void *DSPAssertTask(void *arg0) {
    s32 interrupts;
    s32 irq;
    void *current;

    interrupts = OSDisableInterrupts();
    current = lbl_8055D824;
    if (current == arg0) {
        lbl_8055D814 = arg0;
        lbl_8055D810 = 1;
        OSRestoreInterrupts(interrupts);
        return arg0;
    }
    if (*(u32 *)((u8 *)arg0 + 4) < *(u32 *)((u8 *)current + 4)) {
        lbl_8055D814 = arg0;
        lbl_8055D810 = 1;
        if (*(u32 *)current == 1) {
            irq = OSDisableInterrupts();
            *(volatile u16 *)0xCC00500A =
                (*(volatile u16 *)0xCC00500A & ~0xA8) | 2;
            OSRestoreInterrupts(irq);
        }
        OSRestoreInterrupts(interrupts);
        return arg0;
    }
    OSRestoreInterrupts(interrupts);
    return 0;
}

void DBPrintf_800343C8(const char *fmt, ...) {
#pragma unused(fmt)
}

void __DSPHandler_80034418(s16 interrupt, OSContext *oldContext) {
OSContext context;
u16 dspControl;
u32 mail;
dspControl = *(volatile u16 *)0xCC00500A;
*(volatile u16 *)0xCC00500A = (dspControl & ~0x28) | 0x80;
OSClearContext(&context);
OSSetCurrentContext(&context);
while (DSPCheckMailFromDSP() == 0) {}
mail = DSPReadMailFromDSP();
if ((*(u32 *)((u8 *)lbl_8055D824 + 8) & 2) != 0 && mail == 0xDCD10002) mail = 0xDCD10003;
switch (mail) {
case 0xDCD10000:
*(s32 *)lbl_8055D824 = 1;
if (*(void **)((u8 *)lbl_8055D824 + 0x28) != 0) ((void (*)(void))*(void **)((u8 *)lbl_8055D824 + 0x28))();
break;
case 0xDCD10001:
*(s32 *)lbl_8055D824 = 1;
if (*(void **)((u8 *)lbl_8055D824 + 0x2C) != 0) ((void (*)(void))*(void **)((u8 *)lbl_8055D824 + 0x2C))();
break;
case 0xDCD10002:
if (lbl_8055D810 != 0) {
if (lbl_8055D824 == lbl_8055D814) {
DSPSendMailToDSP(0xCDD10003);
while (DSPCheckMailToDSP() != 0) {}
lbl_8055D814 = 0;
lbl_8055D810 = 0;
if (*(void **)((u8 *)lbl_8055D824 + 0x2C) != 0) ((void (*)(void))*(void **)((u8 *)lbl_8055D824 + 0x2C))();
} else {
DSPSendMailToDSP(0xCDD10001);
while (DSPCheckMailToDSP() != 0) {}
__DSP_exec_task(lbl_8055D824, lbl_8055D814);
{
void *currentTask = lbl_8055D824;
s32 taskState = 2;
s32 zero = 0;
*(s32 *)currentTask = taskState;
lbl_8055D810 = zero;
lbl_8055D824 = lbl_8055D814;
lbl_8055D814 = (void *)zero;
}
}
} else {
if (*(void **)((u8 *)lbl_8055D824 + 0x38) == 0) {
if (lbl_8055D824 == lbl_8055D820) {
DSPSendMailToDSP(0xCDD10003);
while (DSPCheckMailToDSP() != 0) {}
if (*(void **)((u8 *)lbl_8055D824 + 0x2C) != 0) ((void (*)(void))*(void **)((u8 *)lbl_8055D824 + 0x2C))();
} else {
DSPSendMailToDSP(0xCDD10001);
while (DSPCheckMailToDSP() != 0) {}
__DSP_exec_task(lbl_8055D824, lbl_8055D820);
*(s32 *)lbl_8055D824 = 2;
lbl_8055D824 = lbl_8055D820;
}
} else {
DSPSendMailToDSP(0xCDD10001);
while (DSPCheckMailToDSP() != 0) {}
__DSP_exec_task(lbl_8055D824, *(void **)((u8 *)lbl_8055D824 + 0x38));
*(s32 *)lbl_8055D824 = 2;
lbl_8055D824 = *(void **)((u8 *)lbl_8055D824 + 0x38);
}
}
break;
case 0xDCD10003:
if (lbl_8055D810 != 0) {
if (lbl_8055D824 != lbl_8055D814) {
if (*(void **)((u8 *)lbl_8055D824 + 0x30) != 0) ((void (*)(void *))*(void **)((u8 *)lbl_8055D824 + 0x30))(lbl_8055D824);
DSPSendMailToDSP(0xCDD10001);
while (DSPCheckMailToDSP() != 0) {}
__DSP_exec_task(0, lbl_8055D814);
__DSP_remove_task(lbl_8055D824);
{
void *pendingTask = lbl_8055D814;
s32 zero = 0;
lbl_8055D810 = zero;
lbl_8055D824 = pendingTask;
lbl_8055D814 = (void *)zero;
}
} else {
lbl_8055D814 = 0;
lbl_8055D810 = 0;
goto case_done;
}
}
case_done: {
register void *task = lbl_8055D824;
if (*(void **)((u8 *)task + 0x38) == 0) {
if (task == lbl_8055D820) {
if (*(void **)((u8 *)lbl_8055D824 + 0x30) != 0) ((void (*)(void *))*(void **)((u8 *)task + 0x30))(task);
DSPSendMailToDSP(0xCDD10002);
while (DSPCheckMailToDSP() != 0) {}
*(s32 *)lbl_8055D824 = 3;
__DSP_remove_task(lbl_8055D824);
} else {
if (*(void **)((u8 *)lbl_8055D824 + 0x30) != 0) ((void (*)(void *))*(void **)((u8 *)task + 0x30))(task);
DSPSendMailToDSP(0xCDD10001);
while (DSPCheckMailToDSP() != 0) {}
*(s32 *)lbl_8055D824 = 3;
__DSP_exec_task(0, lbl_8055D820);
lbl_8055D824 = lbl_8055D820;
__DSP_remove_task(lbl_8055D81C);
}
} else {
if (*(void **)((u8 *)lbl_8055D824 + 0x30) != 0) ((void (*)(void *))*(void **)((u8 *)task + 0x30))(task);
DSPSendMailToDSP(0xCDD10001);
while (DSPCheckMailToDSP() != 0) {}
*(s32 *)lbl_8055D824 = 3;
__DSP_exec_task(0, *(void **)((u8 *)lbl_8055D824 + 0x38));
{
void *next = *(void **)((u8 *)lbl_8055D824 + 0x38);
lbl_8055D824 = next;
__DSP_remove_task(*(void **)((u8 *)next + 0x3C));
}
}
break;
}
case 0xDCD10004:
if (*(void **)((u8 *)lbl_8055D824 + 0x34) != 0) ((void (*)(void *))*(void **)((u8 *)lbl_8055D824 + 0x34))(lbl_8055D824);
break;
}
OSClearContext(&context);
OSSetCurrentContext(oldContext);
}

extern s32 DSPCheckMailFromDSP(void);
extern s32 DSPCheckMailToDSP(void);
extern s32 DSPReadMailFromDSP(void);
extern void DSPSendMailToDSP(u32);
extern void DBPrintf_800343C8(const char *, ...);
extern char lbl_80301E30[];
void __DSP_boot_task(void *arg0) {
    volatile u32 frame[5];
    u32 *task = (u32 *)arg0;
    const char *fmt = lbl_80301E30;
    while (DSPCheckMailFromDSP() == 0) {}
    frame[2] = DSPReadMailFromDSP();
    DSPSendMailToDSP(0x80F3A001);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(task[3]);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(0x80F3C002);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP((u16)task[5]);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(0x80F3A002);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(task[4]);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(0x80F3B002);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(0);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(0x80F3D001);
    while (DSPCheckMailToDSP() != 0) {}
    DSPSendMailToDSP(*(u16 *)((u8 *)arg0 + 0x24));
    while (DSPCheckMailToDSP() != 0) {}
    DBPrintf_800343C8(fmt, arg0);
    DBPrintf_800343C8(fmt + 0x20, task[3]);
    DBPrintf_800343C8(fmt + 0x50, task[5]);
    DBPrintf_800343C8(fmt + 0x80, task[4]);
    DBPrintf_800343C8(fmt + 0xB0, task[7]);
    DBPrintf_800343C8(fmt + 0xE0, *(u16 *)((u8 *)arg0 + 0x24));
}

void __DSP_insert_task(void *arg0) {
    extern void *lbl_8055D81C;
    extern void *lbl_8055D820;
    extern void *lbl_8055D824;
    void *temp_r4;
    void *var_r5 = lbl_8055D820;
    if (var_r5 == 0) {
        lbl_8055D824 = arg0; lbl_8055D81C = arg0; lbl_8055D820 = arg0;
        *(void **)((u8 *)arg0 + 0x3C) = 0; *(void **)((u8 *)arg0 + 0x38) = 0;
        return;
    }
    while (var_r5 != 0) {
        if (*(u32 *)((u8 *)arg0 + 4) < *(u32 *)((u8 *)var_r5 + 4)) {
            *(void **)((u8 *)arg0 + 0x3C) = *(void **)((u8 *)var_r5 + 0x3C);
            *(void **)((u8 *)var_r5 + 0x3C) = arg0;
            temp_r4 = *(void **)((u8 *)arg0 + 0x3C);
            *(void **)((u8 *)arg0 + 0x38) = var_r5;
            if (temp_r4 == 0) lbl_8055D820 = arg0;
            else *(void **)((u8 *)temp_r4 + 0x38) = arg0;
            break;
        }
        var_r5 = *(void **)((u8 *)var_r5 + 0x38);
    }
    if (var_r5 == 0) {
        *(void **)((u8 *)lbl_8055D81C + 0x38) = arg0;
        *(void **)((u8 *)arg0 + 0x38) = 0;
        *(void **)((u8 *)arg0 + 0x3C) = lbl_8055D81C;
        lbl_8055D81C = arg0;
    }
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

void __DVDFSInit(void) {
    u8 *fst;
    BootInfo_8055D844 = (void *)0x80000000;
    fst = *(u8 **)0x80000038;
    FstStart_8055D840 = fst;
    if (fst == 0)
        return;
    MaxEntryNum_8055D838 = *(u32 *)(fst + 8);
    FstStringStart_8055D83C = fst + MaxEntryNum_8055D838 * 12;
}

#pragma use_lmw_stmw off
s32 DVDConvertPathToEntrynum(const char *path) {
    const DVDNode *new_var;
    const char *name_end;
    u32 it;
    u32 anchor;
    const char *item_name;
    BOOL name_delimited_by_slash;
    s32 name_length;
    const char *backup_path;
    const char *extension_start;
    BOOL illegal_format;
    BOOL has_extension;

    backup_path = path;
    it = lbl_8055D828;
    for (;;) {
        if (*path == '\0') return it;
        if (*path == '/') { it = 0; path++; continue; }
        if (path[0] == '.') {
            if (path[1] == '.') {
                if (path[2] == '/') {
                    it = ((DVDNode *)FstStart_8055D840)[it].folder.parent;
                    path += 3; continue;
                }
                if (path[2] == '\0')
                    return ((DVDNode *)FstStart_8055D840)[it].parent_or_offset;
                goto check_format;
            }
            if (path[1] == '/') { path += 2; continue; }
            if (path[1] == '\0') return it;
        }
check_format:
        if (!__DVDLongFileNameFlag) {
            has_extension = FALSE;
            illegal_format = FALSE;
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') {
                if (*name_end == '.') {
                    if (name_end - path > 8 || has_extension == TRUE) {
                        illegal_format = TRUE;
                        goto validate_format;
                    }
                    has_extension = TRUE;
                    extension_start = name_end + 1;
                } else if (*name_end == ' ') illegal_format = TRUE;
                name_end++;
            }
validate_format:
            if (has_extension == TRUE && name_end - extension_start > 3)
                illegal_format = TRUE;
            if (illegal_format == FALSE)
                goto skip_panic;
            ((void (*)(const char *, s32, const char *, ...))OSPanic)(
                lbl_80558DF8, 0x1B9, lbl_80301F70, backup_path);
skip_panic:;
        } else {
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') name_end++;
        }
        name_delimited_by_slash = (*name_end == '\0') ? FALSE : TRUE;
        name_length = name_end - path;
        anchor = it + 1;
        new_var = (const DVDNode *)FstStart_8055D840;
        while (anchor < new_var[it].folder.sibling_next) {
            while (TRUE) {
                if ((new_var[anchor].packed_type_name & 0xFF000000) ||
                    name_delimited_by_slash != TRUE) {
                    item_name = (const char *)FstStringStart_8055D83C +
                                (new_var[anchor].packed_type_name & 0xFFFFFF);
                    if (DVDPathSame(path, item_name) == TRUE)
                        goto descend;
                }
                if (new_var[anchor].packed_type_name & 0xFF000000) {
                    anchor = new_var[anchor].sibling_or_size;
                    break;
                }
                anchor++;
                break;
            }
        }
        return -1;
descend:
        if (!name_delimited_by_slash) return anchor;
        it = anchor;
        path += name_length + 1;
        continue;
    }
}

BOOL DVDFastOpen(s32 entrynum, void *info) {
    u32 temp_r7;

    if ((entrynum < 0) ||
        ((u32)entrynum >= MaxEntryNum_8055D838) ||
        ((*(u32 *)(FstStart_8055D840 + (temp_r7 = (u32)entrynum * 0xC)) & 0xFF000000) != 0)) {
        return FALSE;
    }
    *(u32 *)((u8 *)info + 0x30) = *(u32 *)(FstStart_8055D840 + temp_r7 + 4) >> __DVDLayoutFormat;
    *(u32 *)((u8 *)info + 0x34) = *(u32 *)(FstStart_8055D840 + temp_r7 + 8);
    *(u32 *)((u8 *)info + 0x38) = 0;
    *(u32 *)((u8 *)info + 0x0C) = 0;
    return TRUE;
}

#pragma use_lmw_stmw reset
extern s32 DVDCancel();
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

u32 DVDConvertEntrynumToPath(s32 entry, char *path, u32 max) {
    u8 *fst = (u8 *)FstStart_8055D840;
    u8 *strings = (u8 *)FstStringStart_8055D83C;
    u32 pos;
    u32 child;
    u32 sibling;
    u32 grandchild;
    u32 n;
    u32 left;
    char *name;
    char *parent;
    char *ancestor;
    if (entry == 0) return 0;
    child = *(u32 *)(fst + entry * 12 + 4);
    name = (char *)(strings + (*(u32 *)(fst + entry * 12) & 0xFFFFFF));
    pos = 0;
    if (child != 0) {
        sibling = *(u32 *)(fst + child * 12 + 4);
        parent = (char *)(strings + (*(u32 *)(fst + child * 12) & 0xFFFFFF));
        if (sibling != 0) {
            grandchild = *(u32 *)(fst + sibling * 12 + 4);
            ancestor = (char *)(strings + (*(u32 *)(fst + sibling * 12) & 0xFFFFFF));
            n = DVDConvertEntrynumToPath(grandchild, path, max);
            pos = n;
            if (n != max) {
                left = max - n - 1;
                path[n] = '/';
                while (left != 0 && *ancestor != 0) {
                    path[n + 1 + (max - n - 1 - left)] = *ancestor++;
                    --left;
                }
                pos = n + 1 + (max - n - 1 - left);
            }
        }
        if (pos != max) {
            left = max - pos - 1;
            path[pos] = '/';
            while (left != 0 && *parent != 0) {
                path[pos + 1 + (max - pos - 1 - left)] = *parent++;
                --left;
            }
            pos = pos + 1 + (max - pos - 1 - left);
        }
    }
    if (pos == max) return pos;
    left = max - pos - 1;
    path[pos] = '/';
    while (left != 0 && *name != 0) {
        path[pos + 1 + (max - pos - 1 - left)] = *name++;
        --left;
    }
    return pos + 1 + (max - pos - 1 - left);
}

extern void OSPanic(const char *, s32, const char *);
extern s32 DVDReadAbsAsyncPrio(void *, void *, s32, s32, void *, s32);
extern void cbForCancelSync(void);
extern void cbForReadAsync(void *, void *);
extern char lbl_80302070[];
extern char lbl_803020A4[];
extern char lbl_80558DF8[];
#pragma push
#pragma use_lmw_stmw off
s32 DVDReadAsyncPrio(void *block, void *addr, s32 length, s32 offset, void *callback, s32 prio) {
    s32 end;
    if (offset < 0 || (u32)offset > *(u32 *)((u8 *)block + 0x34))
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558DF8, 0x325, lbl_80302070);
    end = offset + length;
    if (end < 0 || (u32)end >= *(u32 *)((u8 *)block + 0x34) + 0x20)
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558DF8, 0x32B, lbl_80302070);
    *(void **)((u8 *)block + 0x38) = callback;
    DVDReadAbsAsyncPrio(block, addr, length, *(s32 *)((u8 *)block + 0x30) + (offset >> 2), cbForReadAsync, prio);
    return 1;
}
#pragma use_lmw_stmw reset
#pragma pop
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

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline fn_800356F4
void fn_800356F4(s32 arg0, s32 arg1, s32 arg2) {
    s32 enabled;
    u32 tick;
    u8 *info;
    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 >= 5) {
        *(volatile u32 *)&lbl_8055D848 = 0;
    }
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = arg0;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = arg1;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = arg2;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
    OSRestoreInterrupts(enabled);
}
#pragma pop
void fn_800357A8(void) {

}

void DVDInit(void) {
    s32 temp_r3;
    u8 temp_r4;
    if (DVDInitialized_8055D888 == 0) {
        OSRegisterVersion(__DVDVersion);
        DVDInitialized_8055D888 = 1;
        DVDLowInit();
        __DVDFSInit();
        __DVDClearWaitingQueue();
        MotorState_8055D8A8 = 0;
        bootInfo_8055D8C0 = (void *)0x80000000;
        IDShouldBe_8055D8C4 = 0x80000000;
        OSInitThreadQueue(__DVDThreadQueue);
        DVDLowUnmaskStatusInterrupts();
        DVDLowMaskCoverInterrupt();
        temp_r3 = *(s32 *)((u8 *)bootInfo_8055D8C0 + 0x20);
        if (((u32)temp_r3 + 0x1AE00000U != 0x7C22U) &&
            ((u32)(temp_r3 - (s32)0xD1500000U) != 0xEA5EU)) {
            FirstTimeInBootrom_8055D868 = 1;
        }
        memset(__ErrorInfo, 0, 0x80);
        memcpy(__ErrorInfo, (void *)0x80000000, 4);
        __ErrorInfo[4] = *(u8 *)0x80000006;
        temp_r4 = *(u8 *)0x80000007;
        __ErrorInfo[5] = temp_r4;
        __DVDLayoutFormat = 0;
        DVDSetAutoFatalMessaging(1, temp_r4, __ErrorInfo, (void *)0x80000000);
    }
}

void fn_80035A04(u32 arg0) {
    s32 state;
    s32 *block;
    void (*callback)(s32);

    OSDisableInterrupts();
    if (lbl_8055D848 == 0)
        *(u32 *)(__ErrorInfo + 0x78) = arg0;
    else
        *(u32 *)(__ErrorInfo + lbl_8055D848 * 0x14 + 0x14) = arg0;
    ((void (*)(void))OSRestoreInterrupts)();

    if (arg0 == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (arg0 == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (arg0 & 1) {
        lbl_8055D860 = 0;
        __DVDFSInit();
        block = (s32 *)executing_8055D8C8;
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        block[3] = 0;
        callback = *(void (**)(s32))((u8 *)block + 0x28);
        if (callback != 0)
            callback(0);
        fn_80038040();
        return;
    }

    state = OSDisableInterrupts();
    if ((u32)lbl_8055D848 >= 5)
        lbl_8055D848 = 0;
    *(s32 *)(__ErrorInfo + lbl_8055D848 * 0x14 + 0x1C) = 0x27;
    *(s32 *)(__ErrorInfo + lbl_8055D848 * 0x14 + 0x20) = 0;
    *(s32 *)(__ErrorInfo + lbl_8055D848 * 0x14 + 0x24) = 0;
    *(s32 *)(__ErrorInfo + lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
    lbl_8055D848++;
    OSRestoreInterrupts(state);
    fn_8003B218(fn_80035E6C);
}

extern void __DVDPrintFatalMessage(void);
extern s32 lbl_8055D858;
void fn_80035B88(u32 arg0) {
    u32 *task;
    void (*callback)(s32, void *);

    *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = -1;
    if (arg0 == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (arg0 == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }

    __DVDPrintFatalMessage();
    task = (u32 *)executing_8055D8C8;
    FatalErrorFlag_8055D854 = 1;
    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
    callback = *(void (**)(s32, void *))((u8 *)task + 0x28);
    if (callback != 0)
        callback(-1, task);
    if (lbl_8055D858 != 0) {
        callback = lbl_8055D8B8;
        lbl_8055D858 = 0;
        if (callback != 0)
            callback(0, task);
    }
    fn_80038040();
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
extern void fn_80035B88(u32);
  extern s32 lbl_8055D8AC;
extern s32 lbl_8055D85C;
void fn_80035C78(void) {
    fn_8003B380(0);
    fn_8003B38C(fn_80035B88);
    lbl_8055D8AC = 0;
    lbl_8055D85C = 0;
}

extern u32 lbl_8055D8B0;
extern s32 lbl_8055D860;
extern s32 lbl_8055D8CC;
extern void fn_80037A8C(void);
s32 fn_80035CB4(u32 arg0) {
    u32 diimmval;

    if (arg0 == 0x20400) {
        lbl_8055D8B0 = arg0;
        return 1;
    }

    diimmval = arg0 & 0x00FFFFFF;

    if (diimmval == 0x62800 ||
        diimmval == 0x23A00 ||
        diimmval == 0x53000 ||
        diimmval == 0xB5A01) {
        return 0;
    }

    if (diimmval == 0x52000 &&
        (*(u32 *)(executing_8055D8C8 + 8) == 0x25 ||
         (void *)lbl_8055D8CC == (void *)fn_80037A8C)) {
        return 0;
    }

    (*(volatile s32 *)&lbl_8055D860)++;

    if (*(volatile s32 *)&lbl_8055D860 == 2) {
        if (diimmval == lbl_8055D8B0) {
            lbl_8055D8B0 = diimmval;
            return 1;
        }
        lbl_8055D8B0 = diimmval;
        return 2;
    }

    lbl_8055D8B0 = diimmval;

    if (diimmval == 0x31100 ||
        *(u32 *)(executing_8055D8C8 + 8) == 5) {
        return 2;
    }

    return 3;
}

void fn_80035DA8(s32 arg0) {
    s32 enabled;
    u32 tick;
    u8 *info;
    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 >= 5) {
        *(volatile u32 *)&lbl_8055D848 = 0;
    }
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x10;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
    OSRestoreInterrupts(enabled);
    fn_8003AF1C(0, 0, fn_80036624);
    #pragma unused(arg0)
}

extern void fn_8003A1A0(u32, void (*)(void));
extern void fn_8003BCC0(void);
extern void fn_80035C64(void);
extern void fn_80035C78(void);
#pragma push
#pragma scheduling invalid_target
void fn_80036550(u32 arg0) {
    register u32 value = arg0;
    s32 interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) *(u32 *)(__ErrorInfo + 0x78) = value;
    else *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = value;
    OSRestoreInterrupts(interrupts);
    if (value == 0x10) fn_8003A1A0(0x1234568, fn_80035C78);
    else if (value == 0x20) fn_8003A1A0(0x1234569, fn_80035C78);
    else if (value & 2) fn_8003A1A0(0x1234567, fn_80035C64);
    else ((void (*)(void *, void (*)(void)))fn_8003A1A0)(((void *(*)(void))fn_8003BCC0)(), fn_80035C64);
}
#pragma pop
extern u8 lbl_80376A80[];
extern s32 lbl_8055D87C, lbl_8055D8BC;
extern s32 IDShouldBe_8055D8C4, executing_8055D8C8, lbl_8055D860;
extern BOOL DVDCompareDiskID(void *, void *);
extern s32 fn_8003AD88(void *, s32, s32, u32);
extern void fn_80036B84(void);
extern void fn_800373E0(void);
extern int memcmp(const void *, const void *, u32);
void fn_8003684C(void) {
    register s32 zero = 0;
    register u8 *idBase = lbl_80376A80;
    register s32 enabled;
    switch (lbl_8055D8BC) {
    case 3:
        lbl_8055D87C = zero;
        if (DVDCompareDiskID(idBase + 0x80,
                *(void **)(executing_8055D8C8 + 0x24)) != 0) {
            memcpy((void *)IDShouldBe_8055D8C4, idBase + 0x80, 0x20);
            *(s32 *)(executing_8055D8C8 + 0xC) = 1;
            DCInvalidateRange((void *)&lbl_80376A80, 0x20);
            lbl_8055D860 = zero;
            fn_8003BCDC(0);
            {
        u32 tick, offset, next;
        enabled = OSDisableInterrupts();
        if ((u32)lbl_8055D848 >= 5U) lbl_8055D848 = zero;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x21;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0x10000;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0x20;
        tick = OSGetTick();
        offset = *(volatile u32 *)&lbl_8055D848 * 0x14;
        next = *(volatile u32 *)&lbl_8055D848 + 1;
        lbl_8055D848 = next;
        *(s32 *)(__ErrorInfo + offset + 0x2C) = tick;
        OSRestoreInterrupts(enabled);
        fn_8003AD88(idBase + 0xA0, 0x20, 0x10000, (u32)fn_80036B84);
    }
        } else {
            {
        u32 tick, offset, next;
        enabled = OSDisableInterrupts();
        if ((u32)lbl_8055D848 >= 5U) lbl_8055D848 = zero;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x10;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
        tick = OSGetTick();
        offset = *(volatile u32 *)&lbl_8055D848 * 0x14;
        next = *(volatile u32 *)&lbl_8055D848 + 1;
        lbl_8055D848 = next;
        *(s32 *)(__ErrorInfo + offset + 0x2C) = tick;
        OSRestoreInterrupts(enabled);
        fn_8003AF1C(0, 0, fn_800373E0);
    }
        }
        break;
    default:
        if (memcmp(idBase + 0x80, (void *)IDShouldBe_8055D8C4, 0x20) != 0) {
            {
        u32 tick, offset, next;
        enabled = OSDisableInterrupts();
        if ((u32)lbl_8055D848 >= 5U) lbl_8055D848 = zero;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x10;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
        tick = OSGetTick();
        offset = *(volatile u32 *)&lbl_8055D848 * 0x14;
        next = *(volatile u32 *)&lbl_8055D848 + 1;
        lbl_8055D848 = next;
        *(s32 *)(__ErrorInfo + offset + 0x2C) = tick;
        OSRestoreInterrupts(enabled);
        fn_8003AF1C(0, 0, fn_800373E0);
    }
        } else {
            lbl_8055D860 = zero;
            fn_8003BCDC(0);
            {
        u32 tick, offset, next;
        enabled = OSDisableInterrupts();
        if ((u32)lbl_8055D848 >= 5U) lbl_8055D848 = zero;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x21;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0x10000;
        *(s32 *)(__ErrorInfo + (u32)*(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0x20;
        tick = OSGetTick();
        offset = *(volatile u32 *)&lbl_8055D848 * 0x14;
        next = *(volatile u32 *)&lbl_8055D848 + 1;
        lbl_8055D848 = next;
        *(s32 *)(__ErrorInfo + offset + 0x2C) = tick;
        OSRestoreInterrupts(enabled);
        fn_8003AD88(idBase + 0xA0, 0x20, 0x10000, (u32)fn_80036B84);
    }
        }
        break;
    }
}

extern s32 lbl_8055D858, lbl_8055D870, lbl_8055D874;
extern u32 *lbl_8055D894;
extern u8 *lbl_8055D898;
extern u32 *lbl_8055D89C;
extern void fn_800370F4(u32);
extern void fn_8003727C(u32);
extern void fn_8003801C(void);
extern void DVDLowOpenPartition(u32, u32, u32, u32, void *, void (*)(u32));
#pragma dont_inline on
void fn_80036D24(u32 arg0) {
    u8 *base = lbl_80376A80;
    register u8 *logBase;
    register u32 *limit;
    register u8 *entry;
    register u32 *freeEntry;
    s32 enabled;
    s16 index;
    register s32 signedIndex;
    s32 value;
    s32 oldBlock;
    s32 result;

    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0)
        *(u32 *)(__ErrorInfo + 0x78) = arg0;
    else
        *(u32 *)(__ErrorInfo + 0x28 + (*(volatile u32 *)&lbl_8055D848 - 1) * 0x14) = arg0;
    OSRestoreInterrupts(enabled);

    if (arg0 == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (arg0 == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }

    if (arg0 & 1) {
        entry = base + 0xC0;
        *(volatile s32 *)&lbl_8055D860 = 0;
        index = 0;
        freeEntry = 0;
        limit = *(u32 * volatile *)&lbl_8055D89C;
        *(volatile u8 **)&lbl_8055D898 = entry;
        *(u32 * volatile *)&lbl_8055D894 = 0;
        while ((u32)(s16)index < *limit) {
            if (*(u32 *)(entry + 4) == 0) {
                freeEntry = (u32 *)entry;
                *(u32 * volatile *)&lbl_8055D894 = (u32 *)entry;
            }
            entry += 8;
            index++;
            *(volatile u8 **)&lbl_8055D898 = (u8 *)entry;
        }

        if (freeEntry != 0) {
            if (lbl_8055D8BC != 3) {
                register s32 localEnabled;
                lbl_8055D860 = 0;
                fn_8003BCDC(0);
                value = *lbl_8055D894;
                localEnabled = OSDisableInterrupts();
                if (*(volatile u32 *)&lbl_8055D848 >= 5)
                    lbl_8055D848 = 0;
                logBase = (u8 *)__ErrorInfo;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x22;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = value;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
                lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
                OSRestoreInterrupts(localEnabled);
                DVDLowOpenPartition(*lbl_8055D894, 0, 0, 0, base + 0x100, fn_8003727C);
                return;
            }
            {
                register s32 localEnabled;
                lbl_8055D860 = 0;
                fn_8003BCDC(0);
                value = *lbl_8055D894;
                localEnabled = OSDisableInterrupts();
                if (*(volatile u32 *)&lbl_8055D848 >= 5)
                    lbl_8055D848 = 0;
                logBase = (u8 *)__ErrorInfo;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x22;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = value;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
                *(s32 *)(logBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
                lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
                OSRestoreInterrupts(localEnabled);
                DVDLowOpenPartition(*lbl_8055D894, 0, 0, 0, base + 0x100, fn_800370F4);
                return;
            }
        }

        if (lbl_8055D858 != 0) {
            oldBlock = executing_8055D8C8;
            lbl_8055D85C = 1;
            lbl_8055D858 = 0;
            executing_8055D8C8 = (s32)(base + 0x20);
            *(s32 *)((u8 *)oldBlock + 0xC) = 0xA;
            {
                void (*cb)(s32, void *) = *(void (**)(s32, void *))((u8 *)oldBlock + 0x28);
                if (cb != 0)
                    cb(-3, (void *)oldBlock);
            }
            if (lbl_8055D8B8 != 0)
                lbl_8055D8B8(0, (void *)oldBlock);
            fn_80038040();
            result = 1;
        } else {
            result = 0;
        }
        if (result != 0)
            return;

        *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 6;
        MotorState_8055D8A8 = 1;
        if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
            u32 period;
            lbl_8055D870 = 1;
            OSCreateAlarm(base + 0x50);
            value = OSGetTick();
            period = (u32)(((u64)(*(volatile u32 *)0x800000F8 >> 2) * (u32)0x10624DD3U) >> 32);
            period = (period >> 6) * 100;
            OSSetPeriodicAlarm(base + 0x50, 0x10624DD3, 0, value, 0, period, fn_8003801C);
        }
        return;
    }

    fn_800356F4(0x27, 0, 0);
    fn_8003B218(fn_80035E6C);
}
#pragma dont_inline reset
extern s32 MotorState_8055D8A8;
extern s32 lbl_8055D8BC;
extern void __DVDClearWaitingQueue(void);
extern void fn_80038368(void *);
extern void fn_800379A8(u32);
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

extern s32 lbl_8055D8A0;
extern u32 lbl_8055D8A4;

extern void OSSetAlarm(void *, u64, u32, void (*)(void));
extern u64 __OSGetSystemTime(void);
extern void fn_80037800(void);
extern void fn_80035E6C(void);
#pragma push
#pragma dont_inline on
void fn_800379A8(u32 arg0) {
    u64 time;
    u32 ticks;
    register void *alarm;
    if (arg0 == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (arg0 == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (arg0 & 1) {
        time = __OSGetSystemTime();
        lbl_8055D8A4 = time;
        alarm = (void *)((u32)&lbl_8037B580 + 0x10000U - 0x10000U);
        lbl_8055D8A0 = time >> 32;
        lbl_8055D8AC = 0;
        lbl_8055D85C = 0;
        OSCreateAlarm(alarm);
        ticks = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
        ((void (*)(void *, u32, u32, u32, void (*)(void)))OSSetAlarm)(
            alarm, 0x10624DD3, 0, ticks, fn_80037800);
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}
#pragma pop
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
extern void fn_80037DBC(u32);
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

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80037DBC(u32 arg0) {
    register u32 value = arg0;
    s32 interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) *(u32 *)(__ErrorInfo + 0x78) = value;
    else *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = value;
    OSRestoreInterrupts(interrupts);
    if (value == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (value == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (value & 1) {
        lbl_8055D860 = 0;
        fn_8003684C();
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}
#pragma pop

extern s32 lbl_8055D874, lbl_8055D870, lbl_8055D880, lbl_8055D8BC, lbl_8055D87C, lbl_8055D85C;
extern s32 executing_8055D8C8, MotorState_8055D8A8;
extern u8 lbl_80376AD0[0x30];
extern s32 fn_8003BB48(void);
extern void OSCancelAlarm(void *);
extern void fn_8003773C(void);
void fn_80037E94(void) {
    s32 zero = 0;
    lbl_8055D880 = zero;
    if (lbl_8055D874 != 0) {
        if (!(fn_8003BB48() & 1)) {
            OSCancelAlarm(&lbl_80376AD0);
            lbl_8055D874 = zero;
            lbl_8055D874 = zero;
            if ((u32)lbl_8055D8BC == 3) lbl_8055D87C = 1;
            if ((u32)MotorState_8055D8A8 == 2) {
                if (executing_8055D8C8 != 0) *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 0xC;
            } else {
                DVDLowMaskCoverInterrupt();
                if (executing_8055D8C8 != 0) {
                    *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 3;
                    fn_8003773C();
                    return;
                }
                lbl_8055D85C = 7;
            }
        }
    } else {
        if (fn_8003BB48() & 1) {
            lbl_8055D870 = zero;
            lbl_8055D874 = 1;
            if ((u32)MotorState_8055D8A8 == 2) *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 0xC;
            else *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 5;
            return;
        }
        if (fn_8003BB48() & 4) {
            OSCancelAlarm(&lbl_80376AD0);
            lbl_8055D870 = zero;
            fn_8003BCDC(zero);
            lbl_8055D874 = zero;
            if ((u32)lbl_8055D8BC == 3) lbl_8055D87C = 1;
            if ((u32)MotorState_8055D8A8 == 2) {
                if (executing_8055D8C8 != 0) *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 0xC;
            } else {
                DVDLowMaskCoverInterrupt();
                if (executing_8055D8C8 != 0) {
                    *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 3;
                    fn_8003773C();
                    return;
                }
                lbl_8055D85C = 7;
            }
        }
    }
}

void fn_8003801C(void) {
    if (lbl_8055D880 != 0) {
        return;
    }
    lbl_8055D880 = 1;
    fn_8003BB58(fn_80037E94);
}

extern s32 __DVDCheckWaitingQueue(void);
extern void *__DVDPopWaitingQueue(void);

extern s32 lbl_8055D8B4, lbl_8055D878;
void fn_80038040(void) {
    void (*callback)(s32);
    void *temp_r3, *temp_r4;
    if (__DVDCheckWaitingQueue() == 0) {
        executing_8055D8C8 = 0;
        return;
    }
    if (lbl_8055D84C != 0) {
        PausingFlag_8055D850 = 1;
        executing_8055D8C8 = 0;
        return;
    }
    temp_r3 = __DVDPopWaitingQueue();
    executing_8055D8C8 = (s32)temp_r3;
    if (FatalErrorFlag_8055D854 != 0) {
        void *dummy_command;
        *(s32 *)((u8 *)temp_r3 + 0xC) = -1;
        temp_r4 = (void *)executing_8055D8C8;
        dummy_command = (void *)DummyCommandBlock_80376AA0;
        executing_8055D8C8 = (s32)dummy_command;
        callback = *(void (**)(s32))((u8 *)temp_r4 + 0x28);
        if (callback != 0) callback(-1);
        fn_80038040();
        return;
    }
    *(volatile u32 *)&lbl_8055D8BC = *(u32 *)((u8 *)temp_r3 + 8);
    if (((u32)*(volatile s32 *)&lbl_8055D8BC == 0x20U) ||
        ((u32)*(volatile s32 *)&lbl_8055D8BC == 0xEU) ||
        ((u32)*(volatile s32 *)&lbl_8055D8BC == 0x23U)) lbl_8055D85C = 0;
    if (*(volatile s32 *)&lbl_8055D85C != 0) {
        switch (*(volatile s32 *)&lbl_8055D85C) {
        case 2:
            *(s32 *)((u8 *)temp_r3 + 0xC) = 0xB;
            MotorState_8055D8A8 = 1;
            if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
                s32 tick;
                lbl_8055D870 = 1;
                OSCreateAlarm(lbl_80376AD0);
                tick = OSGetTick();
                OSSetPeriodicAlarm(lbl_80376AD0, 0x10624DD3, 0, tick, 0,
                    ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 0x64, fn_8003801C);
            }
            break;
        case 3:
            *(s32 *)((u8 *)temp_r3 + 0xC) = 4;
            MotorState_8055D8A8 = 1;
            if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
                s32 tick;
                lbl_8055D870 = 1;
                OSCreateAlarm(lbl_80376AD0);
                tick = OSGetTick();
                OSSetPeriodicAlarm(lbl_80376AD0, 0x10624DD3, 0, tick, 0,
                    ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 0x64, fn_8003801C);
            }
            break;
        case 4:
            *(s32 *)((u8 *)temp_r3 + 0xC) = 5;
            MotorState_8055D8A8 = 1;
            if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
                s32 tick;
                lbl_8055D870 = 1;
                OSCreateAlarm(lbl_80376AD0);
                tick = OSGetTick();
                OSSetPeriodicAlarm(lbl_80376AD0, 0x10624DD3, 0, tick, 0,
                    ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 0x64, fn_8003801C);
            }
            break;
        case 5:
            *(s32 *)((u8 *)temp_r3 + 0xC) = 3;
            fn_8003773C();
            break;
        case 1:
        case 6:
        case 7:
            fn_8003A1A0(lbl_8055D8B4, fn_80035C64);
            break;
        default:
            break;
        }
        lbl_8055D85C = 0;
        return;
    }
    switch (MotorState_8055D8A8) {
    case 2:
        if (lbl_8055D878 != 0) {
            *(s32 *)((u8 *)temp_r3 + 0xC) = 0xC;
            return;
        }
        *(s32 *)((u8 *)temp_r3 + 0xC) = 3;
        fn_8003773C();
        return;
    case 0:
        *(s32 *)((u8 *)temp_r3 + 0xC) = 1;
        fn_80038368((void *)executing_8055D8C8);
        return;
    default:
        fn_8003773C();
        return;
    }
}

s32 DVDReadAbsAsyncPrio(void *block, void *addr, s32 length, s32 offset, void *callback, s32 prio) {
    s32 result;
    s32 interrupts;
    u32 command;

    *(u32 *)((u8 *)block + 8) = 1;
    *(void **)((u8 *)block + 0x18) = addr;
    *(u32 *)((u8 *)block + 0x14) = length;
    *(u32 *)((u8 *)block + 0x10) = offset;
    *(u32 *)((u8 *)block + 0x20) = 0;
    *(void **)((u8 *)block + 0x28) = callback;

    if (lbl_80558E04 != 0) {
        command = *(u32 *)((u8 *)block + 8);
        if (command == 1 || command == 4 || command == 5 ||
            command == 0x21 || command == 0xE) {
            DCInvalidateRange(*(void **)((u8 *)block + 0x18),
                              *(u32 *)((u8 *)block + 0x14));
        }
    }

    interrupts = OSDisableInterrupts();
    *(u32 *)((u8 *)block + 0xC) = 2;
    result = __DVDPushWaitingQueue(prio, block);
    if (executing_8055D8C8 == 0 && lbl_8055D84C == 0) {
        fn_80038040();
    }
    OSRestoreInterrupts(interrupts);
    return result;
}

extern void DCInvalidateRange(void *, u32);
#pragma opt_propagation off
s32 DVDInquiryAsync(void *block, void *addr, void *callback) {
    s32 result;
    s32 enabled;
    u32 cmd = 0xE;
    *(u32 *)((u8 *)block + 8) = cmd;
    *(void **)((u8 *)block + 0x18) = addr;
    *(u32 *)((u8 *)block + 0x14) = 0x20;
    *(u32 *)((u8 *)block + 0x20) = 0;
    *(void **)((u8 *)block + 0x28) = callback;
    if (lbl_80558E04 != 0 &&
        (cmd == 1 || cmd == 4 || cmd == 5 || cmd == 0x21 || cmd == 0xE)) {
        DCInvalidateRange(*(void **)((u8 *)block + 0x18), *(u32 *)((u8 *)block + 0x14));
    }
    enabled = OSDisableInterrupts();
    *(u32 *)((u8 *)block + 0xC) = 2;
    result = __DVDPushWaitingQueue(2, block);
    if (executing_8055D8C8 == 0 && lbl_8055D84C == 0) {
        fn_80038040();
    }
    OSRestoreInterrupts(enabled);
    return result;
}
#pragma opt_propagation reset
extern u8 lbl_8037B5B0;
extern s32 __DVDGetNextWaitingQueue(void);
extern __declspec(section ".data") u8 lbl_8037B5B0;
s32 DVDGetCommandBlockStatus(void *arg0) {
    s32 status;
    s32 enabled;
    s32 next;

    enabled = OSDisableInterrupts();
    status = *(s32 *)((u8 *)arg0 + 0xC);
    if (status == 3) {
        status = 1;
    } else if (status == 5) {
        status = 4;
    } else if ((u32)executing_8055D8C8 == (u32)&lbl_8037B5B0) {
        next = __DVDGetNextWaitingQueue();
        if (next != 0) {
            if ((u32)arg0 == (u32)next) status = 1;
            else status = *(s32 *)((u8 *)arg0 + 0xC);
        } else if ((u32)arg0 == (u32)&lbl_8037B5B0) {
            status = 0;
        } else {
            status = *(s32 *)((u8 *)arg0 + 0xC);
        }
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

#pragma push
#pragma scheduling invalid_target
void fn_800393D4(void) {
    s32 enabled = OSDisableInterrupts();

    lbl_8055D84C = 0;
    if (PausingFlag_8055D850 != 0) {
        PausingFlag_8055D850 = 0;
        fn_80038040();
    }
    OSRestoreInterrupts(enabled);
}
#pragma pop
extern s32 lbl_8055D858, lbl_8055D86C;
extern void (*lbl_8055D8B8)(s32, void *);
extern s32 __DVDDequeueWaitingQueue(void *);
s32 fn_80039424(void *block, void (*callback)(s32, void *)) {
    s32 enabled = OSDisableInterrupts();
    switch (*(volatile s32 *)((u8 *)block + 0xC)) {
    case -1: case 0: case 10:
        if (callback) callback(0, block);
        break;
    case 1:
        if (lbl_8055D858) { OSRestoreInterrupts(enabled); return 0; }
        lbl_8055D858 = 1;
        lbl_8055D8B8 = callback;
        if (*(u32 *)((u8 *)block + 8) == 4 || *(u32 *)((u8 *)block + 8) == 33 || *(u32 *)((u8 *)block + 8) == 34 || *(u32 *)((u8 *)block + 8) == 1)
            lbl_8055D86C = 1;
        break;
    case 2:
        __DVDDequeueWaitingQueue(block);
        *(volatile s32 *)((u8 *)block + 0xC) = 10;
        if (*(void (**)(s32, void *))((u8 *)block + 0x28)) (*(void (**)(s32, void *))((u8 *)block + 0x28))(-3, block);
        if (callback) callback(0, block);
        break;
    case 3:
        switch (*(u32 *)((u8 *)block + 8)) {
        case 4: case 5: case 13: case 15: case 33: case 34: case 37:
            if (callback) callback(0, block);
            break;
        case 1: case 2:
            if (__OSInIPL) {
                executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                *(volatile s32 *)((u8 *)block + 0xC) = 10;
                if (*(void (**)(s32, void *))((u8 *)block + 0x28)) (*(void (**)(s32, void *))((u8 *)block + 0x28))(-3, block);
                if (callback) callback(0, block);
                fn_80038040();
                break;
            }
        default:
            if (lbl_8055D858) { OSRestoreInterrupts(enabled); return 0; }
            lbl_8055D858 = 1;
            lbl_8055D8B8 = callback;
            break;
        }
        break;
    case 4: case 5: case 6: case 7: case 11:
        if (!lbl_8055D874 && !lbl_8055D870) { OSRestoreInterrupts(enabled); return 0; }
        OSCancelAlarm(&lbl_80376AD0);
        lbl_8055D870 = 0;
        if (*(volatile s32 *)((u8 *)block + 0xC) == 4) lbl_8055D85C = 3;
        if (*(volatile s32 *)((u8 *)block + 0xC) == 5) lbl_8055D85C = 4;
        if (*(volatile s32 *)((u8 *)block + 0xC) == 6) lbl_8055D85C = 1;
        if (*(volatile s32 *)((u8 *)block + 0xC) == 11) lbl_8055D85C = 2;
        if (*(volatile s32 *)((u8 *)block + 0xC) == 7) lbl_8055D85C = 7;
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        *(volatile s32 *)((u8 *)block + 0xC) = 10;
        if (*(void (**)(s32, void *))((u8 *)block + 0x28)) (*(void (**)(s32, void *))((u8 *)block + 0x28))(-3, block);
        if (callback) callback(0, block);
        fn_80038040();
        break;
    case 12:
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        *(volatile s32 *)((u8 *)block + 0xC) = 10;
        if (*(void (**)(s32, void *))((u8 *)block + 0x28)) (*(void (**)(s32, void *))((u8 *)block + 0x28))(-3, block);
        if (callback) callback(0, block);
        fn_80038040();
        break;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

extern s32 fn_80039424(void *, void (*)(s32, void *));
extern void OSSleepThread(void *);
extern void fn_80039838(void);

#pragma push
#pragma use_lmw_stmw off
s32 DVDReadPrio(void *block, void *addr, s32 length, s32 offset, s32 prio) {
    s32 end;
    s32 enabled;
    s32 state;
    s32 result;

    if (offset < 0 || (u32)offset > *(u32 *)((u8 *)block + 0x34))
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558DF8, 0x36B, lbl_803020A4);
    end = offset + length;
    if (end < 0 || (u32)end >= *(u32 *)((u8 *)block + 0x34) + 0x20)
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558DF8, 0x371, lbl_803020A4);
    if (DVDReadAbsAsyncPrio(block, addr, length,
                            *(s32 *)((u8 *)block + 0x30) + (offset >> 2),
                            cbForCancelSync, prio) == 0)
        return -1;

    enabled = OSDisableInterrupts();
    for (;;) {
        state = *(s32 *)((u8 *)block + 0xC);
        if (state == 0) {
            result = *(s32 *)((u8 *)block + 0x20);
            break;
        }
        if (state == -1) {
            result = -1;
            break;
        }
        if (state == 10) {
            result = -3;
            break;
        }
        OSSleepThread(__DVDThreadQueue);
    }
    OSRestoreInterrupts(enabled);
    return result;
}
#pragma use_lmw_stmw reset
#pragma pop
s32 DVDCancel(void *block) {
    s32 enabled;
    s32 state;
    u32 command;
    if (((s32 (*)(void *, void *))fn_80039424)(block, (void *)fn_80039838) == 0)
        return -1;
    enabled = OSDisableInterrupts();
    for (;;) {
        state = *(s32 *)((u8 *)block + 0xC);
        if (state == 0 || state == -1 || state == 10)
            break;
        if (state == 3) {
            command = *(u32 *)((u8 *)block + 8);
            if (command == 4 || command == 5 || command == 0xD ||
                command == 0x21 || command == 0x22 || command == 0xF ||
                command == 0x25)
                break;
        }
        OSSleepThread(__DVDThreadQueue);
    }
    OSRestoreInterrupts(enabled);
    return 0;
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

u32 __DVDGetCoverStatus(void) {
    u32 status;
    u32 frequency;
    u32 threshold;
    u64 now;
    s64 elapsed;
    u64 stamp;
    lbl_8055D88C = 0;
    fn_8003BB58((void (*)(void))fn_8003998C);
    while (*(volatile u32 *)&lbl_8055D88C == 0) {
    }
    if ((*(volatile u32 *)&lbl_8055D88C & 1) == 0) {
        return 0;
    }
    status = fn_8003BB48();
    now = __OSGetSystemTime();
    frequency = *(volatile u32 *)0x800000F8;
    threshold = ((frequency >> 2) / 1000) * 100;
    stamp = *(u64 *)(void *)&lbl_8055D8A0;
    elapsed = (s64)now - (s64)stamp;
    if (elapsed < (s64)threshold) {
        return 0;
    }
    status &= 1;
    status = -status;
    return status + 2;
}

void fn_80039A5C(void (*callback)(s32, void *)) {
    s32 saved;
    s32 temp;
    void *active;
    s32 enabled;

    enabled = OSDisableInterrupts();
    __DVDClearWaitingQueue();
    if (lbl_8055D858) {
        lbl_8055D8B8 = callback;
    } else {
        if (executing_8055D8C8)
            *(s32 *)((u8 *)executing_8055D8C8 + 0x28) = 0;
        temp = OSDisableInterrupts();
        active = (void *)OSDisableInterrupts();
        lbl_8055D84C = 1;
        if (executing_8055D8C8 == 0) {
            PausingFlag_8055D850 = 1;
            OSRestoreInterrupts((s32)active);
            goto queue_check;
        }
queue_call:
        fn_80039424(active, 0);
queue_check:
        active = __DVDPopWaitingQueue();
        if (active != 0)
            goto queue_call;
        if (executing_8055D8C8 != 0) {
            fn_80039424((void *)executing_8055D8C8, callback);
        } else if (callback != 0) {
            callback(0, 0);
        }
        saved = OSDisableInterrupts();
        *(volatile s32 *)&lbl_8055D84C = 0;
        if (PausingFlag_8055D850 != 0) {
            PausingFlag_8055D850 = 0;
            fn_80038040();
        }
        OSRestoreInterrupts(saved);
        OSRestoreInterrupts(temp);
    }
    OSRestoreInterrupts(enabled);
}

void cbForPrepareReset(void) {
    lbl_8055D890 = 1;
}

void __DVDPrepareReset(void) {
    s32 savedInterrupts;
    s32 tempInterrupts;
    void *active;
    s32 oldInterrupts;
    s32 one = 1;

    OSDisableInterrupts();
    lbl_8055D890 = 0;
    oldInterrupts = OSDisableInterrupts();
    __DVDClearWaitingQueue();
    if (lbl_8055D858 != 0) {
        lbl_8055D8B8 = (void (*)(s32, void *))cbForPrepareReset;
    } else {
        if (executing_8055D8C8 != 0)
            *(s32 *)(executing_8055D8C8 + 0x28) = 0;
        tempInterrupts = OSDisableInterrupts();
        active = (void *)OSDisableInterrupts();
        *(volatile s32 *)&lbl_8055D84C = one;
        if (executing_8055D8C8 == 0) {
            PausingFlag_8055D850 = one;
            OSRestoreInterrupts((s32)active);
            goto queue_check;
        }
queue_call:
        fn_80039424(active, 0);
queue_check:
        active = (void *)__DVDPopWaitingQueue();
        if (active != 0)
            goto queue_call;
        if (executing_8055D8C8 != 0)
            fn_80039424((void *)executing_8055D8C8, (void (*)(s32, void *))cbForPrepareReset);
        else if ((void *)cbForPrepareReset != 0)
            lbl_8055D890 = one;
        savedInterrupts = OSDisableInterrupts();
        *(volatile s32 *)&lbl_8055D84C = 0;
        if (PausingFlag_8055D850 != 0) {
            PausingFlag_8055D850 = 0;
            fn_80038040();
        }
        OSRestoreInterrupts(savedInterrupts);
        OSRestoreInterrupts(tempInterrupts);
    }
    OSRestoreInterrupts(oldInterrupts);
    while (1) {
        OSEnableInterrupts();
        if (lbl_8055D890 == 1)
            break;
    }
}

#pragma small_data off
extern __declspec(section ".data") u8 lbl_8037B580;
s32 __DVDTestAlarm(void *alarm) {
    if (alarm == &lbl_8037B580) {
        return 1;
    }
    return fn_8003BE40();
}
#pragma small_data on
u32 fn_80039CD8(void) { return 1; }

void fn_80039CE0(void) {

}
