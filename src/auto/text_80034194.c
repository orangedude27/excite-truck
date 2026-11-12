// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern s32 lbl_8055D864;
extern void cbForCancel(void);
extern s32 lbl_8055D8BC;
extern s32 lbl_8055D858;
extern s32 lbl_8055D86C;
extern s32 lbl_8055D8A0;
extern u32 lbl_8055D8A4;
extern u64 __OSGetSystemTime(void);
extern s32 fn_8003BB48(void);
extern char lbl_8030228C[];
extern s32 lbl_80558E14;
#include <revolution/OS/OSContext.h>
#include <revolution/DSP/dsp_task_types.h>
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
#include "revolution/DSP/dsp_task_types.h"
#include "revolution/DSP/dsp_task_types.h"
extern void fn_80038368(void *);
extern void fn_80035A04(u32);
extern s32 fn_8003B81C(void *, s32, s32, s32);
extern s32 lbl_8055D8CC;
extern u8 lbl_80376A80[];
extern char lbl_80302120[];
__declspec(section ".sdata") extern char lbl_80558E0C[];

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
extern void fn_80035E6C();
extern void fn_8003BCC0(void);
extern void fn_80035DA8(s32);
extern void fn_80036370(u32);
extern void fn_8003773C(void);
extern void fn_8003801C(void);
extern void fn_800373E0(u32);
extern s32 lbl_8055D870, lbl_8055D874;
extern void fn_8003B9CC(u32, void *);
extern void fn_8003A1A0(u32, void (*)(void));
extern void fn_8003B218();
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
extern char lbl_80376B00[];
extern u8 lbl_80376AD0[0x30];
extern void fn_80037CEC(void);
extern void fn_80037DBC(u32);
extern void fn_8003A834(void *, void *);
extern void fn_8003B69C(u32, void *);
extern void fn_80037B54(u32);

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

#define DVD_DRIVER_TYPES
// The DVD driver's command block and its status codes. include/revolution/DVD/dvd.h
// describes the same layout, but this unit's own prototypes of
// DVDReadAbsAsyncPrio/DVDGetCommandBlockStatus/DVDCancel & co. don't match that
// header's signatures, so the driver keeps its own view (like DVDNode above).
typedef struct DVDCommandBlock {
    struct DVDCommandBlock *next;        // at 0x0
    struct DVDCommandBlock *prev;        // at 0x4
    u32 command;                         // at 0x8
    volatile s32 state;                  // at 0xC
    u32 offset;                          // at 0x10
    u32 length;                          // at 0x14
    void *addr;                          // at 0x18
    u32 transferSize;                    // at 0x1C
    u32 transferTotal;                   // at 0x20
    struct DVDDiskID *id;                // at 0x24
    void (*callback)(s32 result, struct DVDCommandBlock *block); // at 0x28
    void *userData;                      // at 0x2C
} DVDCommandBlock;

typedef void (*DVDCommandCallback)(s32 result, DVDCommandBlock *block);

typedef enum {
    DVD_RESULT_COVER_CLOSED = -4,
    DVD_RESULT_CANCELED,
    DVD_RESULT_IGNORED,
    DVD_RESULT_FATAL_ERROR,
    DVD_RESULT_GOOD,
} DVDResult;

// DVDCommandBlock.state, as DVDGetCommandBlockStatus/DVDGetDriveStatus report it
typedef enum {
    DVD_STATE_FATAL = -1,
    DVD_STATE_IDLE,
    DVD_STATE_BUSY,
    DVD_STATE_WAITING,
    DVD_STATE_COVER_CLOSED,
    DVD_STATE_NO_DISK,
    DVD_STATE_COVER_OPENED,
    DVD_STATE_WRONG_DISK_ID,
    DVD_STATE_7,
    DVD_STATE_PAUSED,
    DVD_STATE_9,
    DVD_STATE_CANCELED,
    DVD_STATE_DISK_ERROR,
    DVD_STATE_MOTOR_STOPPED,
} DVDAsyncState;

// The DVD cover/motor state machine's statics, shared with the cancel code below.
#define Transferring    lbl_8055D870  // the cover-poll timeout alarm is running
#define AlarmInfo       lbl_8055D874  // waiting on the cover interrupt instead
#define CoverRegPending lbl_8055D880  // a cover-register read is in flight
#define DriveCommand    lbl_8055D8BC  // the drive command being processed
#define DiskChanged     lbl_8055D87C  // cover opened during the disk-ID check
#define StateToChange   lbl_8055D85C  // drive state __DVDIssueCallback moves to next
#define StateAlarm      lbl_80376AD0  // the DVD state timeout alarm
#define ExecutingBlock  executing_8055D8C8 // block the driver is running

// The cancel state machine's own statics (dvdcancel.c).
#define Canceling      lbl_8055D858  // a cancel is waiting for the drive
#define ResetFlag      lbl_8055D86C  // the drive must be reset before the next command
#define CancelCallback lbl_8055D8B8  // called once the cancel has finished
#define DummyBlock     DummyCommandBlock_80376AA0 // "nothing is executing" block

// The __ErrorInfo ring (dvderror.h): the next free entry of its info[] array,
// and how many drive error interrupts have been counted in a row.
#define ErrorInfoEntry  lbl_8055D848
#define DriveErrorCount lbl_8055D860

extern void *lbl_8055D808;
void DSPInit(void) {
    s32 interrupts;

    /* Initialize the DSP subsystem once: register version, install handler, and enable DSP interrupts. */
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

/* Assert (preempt) the current DSP task with a higher-priority task.
 * If `task` is already running, marks it as the rude task and returns it.
 * If `task` has higher priority than the running task, marks it as the rude
 * task; if the running task is active, requests a DSP preempt via CC00500A.
 * Returns `task` when accepted, or NULL if it cannot preempt. */
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

/*
 * DSP interrupt handler. Acknowledges the DSP interrupt, reads the microcode
 * mailbox message and runs the task state machine (init/resume/yield/done/
 * sync), calling into the current task's callbacks.
 *
 * lbl_8055D810 = __DSP_rude_task_pending  lbl_8055D814 = __DSP_rude_task
 * lbl_8055D81C = __DSP_last_task         lbl_8055D820 = __DSP_first_task
 * lbl_8055D824 = __DSP_curr_task
 */
void __DSPHandler_80034418(s16 interrupt, OSContext *oldContext) {
    OSContext context;
    u16 csr;
    u32 mail;

    csr = *(volatile u16 *)0xCC00500A;
    *(volatile u16 *)0xCC00500A = (csr & ~0x28) | 0x80;
    OSClearContext(&context);
    OSSetCurrentContext(&context);
    while (DSPCheckMailFromDSP() == 0) {}
    mail = DSPReadMailFromDSP();

    if ((((DSPTask *)lbl_8055D824)->flags & DSP_TASK_CANCELED) != 0 && mail == 0xDCD10002)
        mail = 0xDCD10003;

    switch (mail) {
    case 0xDCD10000: /* DSP_INIT */
        ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_1;
        if (((DSPTask *)lbl_8055D824)->initCallback != NULL)
            ((DSPTask *)lbl_8055D824)->initCallback((DSPTask *)lbl_8055D824);
        break;
    case 0xDCD10001: /* DSP_RESUME */
        ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_1;
        if (((DSPTask *)lbl_8055D824)->resumeCallback != NULL)
            ((DSPTask *)lbl_8055D824)->resumeCallback((DSPTask *)lbl_8055D824);
        break;
    case 0xDCD10002: /* DSP_YIELD */
        if (lbl_8055D810 != 0) {
            if (lbl_8055D824 == lbl_8055D814) {
                DSPSendMailToDSP(0xCDD10003);
                while (DSPCheckMailToDSP() != 0) {}
                lbl_8055D814 = 0;
                lbl_8055D810 = 0;
                if (((DSPTask *)lbl_8055D824)->resumeCallback != NULL)
                    ((DSPTask *)lbl_8055D824)->resumeCallback((DSPTask *)lbl_8055D824);
            } else {
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0) {}
                __DSP_exec_task(lbl_8055D824, lbl_8055D814);
                {
                    DSPTask *currentTask = (DSPTask *)lbl_8055D824;
                    currentTask->state = DSP_TASK_STATE_2;
                    lbl_8055D824 = lbl_8055D814;
                    lbl_8055D810 = 0;
                    lbl_8055D814 = 0;
                }
            }
        } else {
            if (((DSPTask *)lbl_8055D824)->next == NULL) {
                if (lbl_8055D824 == lbl_8055D820) {
                    DSPSendMailToDSP(0xCDD10003);
                    while (DSPCheckMailToDSP() != 0) {}
                    if (((DSPTask *)lbl_8055D824)->resumeCallback != NULL)
                        ((DSPTask *)lbl_8055D824)->resumeCallback((DSPTask *)lbl_8055D824);
                } else {
                    DSPSendMailToDSP(0xCDD10001);
                    while (DSPCheckMailToDSP() != 0) {}
                    __DSP_exec_task(lbl_8055D824, lbl_8055D820);
                    ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_2;
                    lbl_8055D824 = lbl_8055D820;
                }
            } else {
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0) {}
                __DSP_exec_task(lbl_8055D824, ((DSPTask *)lbl_8055D824)->next);
                ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_2;
                lbl_8055D824 = ((DSPTask *)lbl_8055D824)->next;
            }
        }
        break;
    case 0xDCD10003: /* DSP_DONE */
        if (lbl_8055D810 != 0) {
            if (lbl_8055D824 != lbl_8055D814) {
                if (((DSPTask *)lbl_8055D824)->doneCallback != NULL)
                    ((DSPTask *)lbl_8055D824)->doneCallback((DSPTask *)lbl_8055D824);
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0) {}
                __DSP_exec_task(0, lbl_8055D814);
                __DSP_remove_task(lbl_8055D824);
                lbl_8055D824 = lbl_8055D814;
                lbl_8055D810 = 0;
                lbl_8055D814 = 0;
                break;
            } else {
                lbl_8055D814 = 0;
                lbl_8055D810 = 0;
            }
        }
        if (((DSPTask *)lbl_8055D824)->next == NULL) {
            if (lbl_8055D824 == lbl_8055D820) {
                if (((DSPTask *)lbl_8055D824)->doneCallback != NULL)
                    ((DSPTask *)lbl_8055D824)->doneCallback((DSPTask *)lbl_8055D824);
                DSPSendMailToDSP(0xCDD10002);
                while (DSPCheckMailToDSP() != 0) {}
                ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_3;
                __DSP_remove_task(lbl_8055D824);
            } else {
                if (((DSPTask *)lbl_8055D824)->doneCallback != NULL)
                    ((DSPTask *)lbl_8055D824)->doneCallback((DSPTask *)lbl_8055D824);
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0) {}
                ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_3;
                __DSP_exec_task(0, lbl_8055D820);
                lbl_8055D824 = lbl_8055D820;
                __DSP_remove_task(lbl_8055D81C);
            }
        } else {
            if (((DSPTask *)lbl_8055D824)->doneCallback != NULL)
                ((DSPTask *)lbl_8055D824)->doneCallback((DSPTask *)lbl_8055D824);
            DSPSendMailToDSP(0xCDD10001);
            while (DSPCheckMailToDSP() != 0) {}
            ((DSPTask *)lbl_8055D824)->state = DSP_TASK_STATE_3;
            __DSP_exec_task(0, ((DSPTask *)lbl_8055D824)->next);
            {
                DSPTask *next = ((DSPTask *)lbl_8055D824)->next;
                lbl_8055D824 = next;
                __DSP_remove_task(next->prev);
            }
        }
        break;
    case 0xDCD10004: /* DSP_SYNC */
        if (((DSPTask *)lbl_8055D824)->requestCallback != NULL)
            ((DSPTask *)lbl_8055D824)->requestCallback((DSPTask *)lbl_8055D824);
        break;
    }
    OSClearContext(&context);
    OSSetCurrentContext(oldContext);
}

/* Send DSP task mailboxes: previous task's DRAM region (or zeros), then the
 * current task's IRAM region and either its initial vectors or resume vectors. */
void __DSP_exec_task(void *prevTask, void *currTask) {
    if (prevTask != NULL) {
        DSPSendMailToDSP(*(u32 *)((u8 *)prevTask + 0x18));
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(*(u32 *)((u8 *)prevTask + 0x1C));
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(*(u32 *)((u8 *)prevTask + 0x20));
        while (DSPCheckMailToDSP() != 0) {
        }
    } else {
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
    }
    DSPSendMailToDSP(*(u32 *)((u8 *)currTask + 0xC));
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(*(u32 *)((u8 *)currTask + 0x10));
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(*(u32 *)((u8 *)currTask + 0x14));
    while (DSPCheckMailToDSP() != 0) {
    }
    if (*(s32 *)currTask == 0) {
        DSPSendMailToDSP(*(u16 *)((u8 *)currTask + 0x24));
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0) {
        }
        return;
    }
    DSPSendMailToDSP(*(u16 *)((u8 *)currTask + 0x26));
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(*(u32 *)((u8 *)currTask + 0x18));
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(*(u32 *)((u8 *)currTask + 0x1C));
    while (DSPCheckMailToDSP() != 0) {
    }
    DSPSendMailToDSP(*(u32 *)((u8 *)currTask + 0x20));
    while (DSPCheckMailToDSP() != 0) {
    }
}

extern s32 DSPCheckMailFromDSP(void);
extern s32 DSPCheckMailToDSP(void);
extern s32 DSPReadMailFromDSP(void);
extern void DSPSendMailToDSP(u32);
extern void DBPrintf_800343C8(const char *, ...);
extern char lbl_80301E30[];
void __DSP_boot_task(void *arg0) {
    volatile u32 mail;
    u32 *task = (u32 *)arg0;
    const char *fmt = lbl_80301E30;
    while (DSPCheckMailFromDSP() == 0) {}
    mail = DSPReadMailFromDSP();
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
    DBPrintf_800343C8(((char (*)[0x20])fmt)[0], arg0);
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

#pragma dont_inline on
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
#pragma dont_inline off

#pragma use_lmw_stmw off
s32 DVDConvertPathToEntrynum(const char *path) {
    const DVDNode *nodes;
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
            has_extension = 0;
            illegal_format = 0;
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') {
                if (*name_end == '.') {
                    if (name_end - path > 8 || has_extension != 0) {
                        illegal_format = 1;
                        goto validate_format;
                    }
                    has_extension = 1;
                    extension_start = name_end + 1;
                } else if (*name_end == ' ') illegal_format = 1;
                name_end++;
            }
validate_format:
            if (has_extension != 0 && name_end - extension_start > 3)
                illegal_format = 1;
            if (illegal_format == 0)
                goto skip_panic;
            ((void (*)(const char *, s32, const char *, ...))OSPanic)(
                lbl_80558DF8, 0x1B9, lbl_80301F70, backup_path);
skip_panic:;
        } else {
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') name_end++;
        }
        name_delimited_by_slash = (*name_end == '\0') ? 0 : 1;
        name_length = name_end - path;
        anchor = it + 1;
        nodes = (const DVDNode *)FstStart_8055D840;
        while (anchor < nodes[it].folder.sibling_next) {
            while (TRUE) {
                if ((nodes[anchor].packed_type_name & 0xFF000000) ||
                    name_delimited_by_slash == 0) {
                    item_name = (const char *)FstStringStart_8055D83C +
                                (nodes[anchor].packed_type_name & 0xFFFFFF);
                    if (DVDPathSame(path, item_name) == TRUE)
                        goto descend;
                }
                if (nodes[anchor].packed_type_name & 0xFF000000) {
                    anchor = nodes[anchor].sibling_or_size;
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

#pragma push
#pragma use_lmw_stmw off
extern s32 DVDConvertPathToEntrynum(const char *);
extern u32 DVDConvertEntrynumToPath(s32, char *, u32);
extern void OSReport(const char *, ...);
extern char lbl_80302038[];
/* "/name" appended to path at loc (SDK dvdfs.c entryToPath tail + myStrncpy) */
static inline u32 appendPathPart(char *path, u32 loc, u32 maxlen, const char *name) {
    u32 i;
    if (loc == maxlen) return loc;
    path[loc++] = '/';
    i = maxlen - loc;
    {
        char *dst = path + loc;
        u32 left = i;
        while (left > 0 && *name != 0) {
            *dst++ = *name++;
            left--;
        }
        return loc + (i - left);
    }
}
#pragma push
#pragma use_lmw_stmw off
BOOL DVDGetCurrentDir(const char *path, void *info) {
    char dir[128];
    s32 entry;
    s32 cur;
    u32 loc;
    u8 *fst;
    u8 *parents;
    u8 *strings;
    u32 p1;
    u32 p2;
    u32 p3;
    u8 *name1;
    u8 *name2;
    u8 *name3;
    u32 start;
    u32 left;
    u32 i;
    u8 *dst;
    u32 offset;

    entry = DVDConvertPathToEntrynum(path);
    if (entry < 0) {
        cur = lbl_8055D828;
        if (cur == 0) {
            loc = 0;
        } else {
            fst = FstStart_8055D840;
            strings = FstStringStart_8055D83C;
            parents = fst + 4;
            p1 = *(u32 *)(parents + cur * 12);
            name1 = strings + (*(u32 *)(fst + cur * 12) & 0xFFFFFF);
            if (p1 == 0) {
                loc = 0;
            } else {
                p2 = *(u32 *)(parents + p1 * 12);
                name2 = strings + (*(u32 *)(fst + p1 * 12) & 0xFFFFFF);
                if (p2 == 0) {
                    loc = 0;
                } else {
                    name3 = strings + (*(u32 *)(fst + p2 * 12) & 0xFFFFFF);
                    loc = DVDConvertEntrynumToPath(*(u32 *)(parents + p2 * 12), dir, 0x80);
                    if (loc != 0x80) {
                        start = loc + 1;
                        dir[loc] = '/';
                        left = 0x80 - start;
                        i = left;
                        dst = (u8 *)dir + start;
                        while (i != 0 && (s8)*name3 != 0) {
                            *dst++ = *name3++;
                            i--;
                        }
                        loc = start + (left - i);
                    }
                }
                if (loc != 0x80) {
                    start = loc + 1;
                    dir[loc] = '/';
                    left = 0x80 - start;
                    i = left;
                    dst = (u8 *)dir + start;
                    while (i != 0 && (s8)*name2 != 0) {
                        *dst++ = *name2++;
                        i--;
                    }
                    loc = start + (left - i);
                }
            }
            if (loc != 0x80) {
                start = loc + 1;
                dir[loc] = '/';
                left = 0x80 - start;
                i = left;
                dst = (u8 *)dir + start;
                while (i != 0 && (s8)*name1 != 0) {
                    *dst++ = *name1++;
                    i--;
                }
                loc = start + (left - i);
            }
        }
        if (loc == 0x80) {
            dir[0x7F] = '\0';
        } else {
            if (*(u32 *)(FstStart_8055D840 + cur * 12) & 0xFF000000) {
                if (loc == 0x7F) {
                    dir[loc] = '\0';
                    goto report;
                }
                dir[loc++] = '/';
            }
            dir[loc] = '\0';
        }
report:
        OSReport(lbl_80302038, path, dir);
        return FALSE;
    }

    offset = entry * 12;
    fst = FstStart_8055D840;
    if (*(u32 *)(fst + offset) & 0xFF000000) {
        return FALSE;
    }
    fst += offset;
    *(u32 *)((u8 *)info + 0x30) = *(u32 *)(fst + 4) >> __DVDLayoutFormat;
    *(u32 *)((u8 *)info + 0x34) = *(u32 *)(FstStart_8055D840 + offset + 8);
    *(u32 *)((u8 *)info + 0x38) = 0;
    *(u32 *)((u8 *)info + 0x0C) = 0;
    return TRUE;
}
#pragma use_lmw_stmw reset
#pragma pop

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

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
u32 DVDConvertEntrynumToPath(s32 entry, char *path, u32 max) {
    u8 *parentTable;
    u8 *strings;
    u8 *fst;
    u32 offset;
    u32 parentIndex;
    u32 nextParent;
    u32 pos;
    u32 start;
    u32 left;
    u32 initialLeft;
    char *parentName;
    char *name;
    char *grandparentName;
    char *dst;
    char *src;

    if (entry == 0) return 0;
    fst = (u8 *)FstStart_8055D840;
    offset = entry * 12;
    strings = (u8 *)FstStringStart_8055D83C;
    parentTable = fst + 4;
    parentIndex = *(u32 *)(parentTable + offset);
    name = (char *)(strings + (*(u32 *)(fst + offset) & 0xFFFFFF));
    if (parentIndex == 0) {
        pos = 0;
    } else {
        offset = parentIndex * 12;
        nextParent = *(u32 *)(parentTable + offset);
        parentName = (char *)(strings + (*(u32 *)(fst + offset) & 0xFFFFFF));
        if (nextParent == 0) {
            pos = 0;
        } else {
            offset = nextParent * 12;
            grandparentName = (char *)(strings + (*(u32 *)(fst + offset) & 0xFFFFFF));
            pos = DVDConvertEntrynumToPath(*(u32 *)(parentTable + offset), path, max);
            if (pos != max) {
                start = pos + 1;
                initialLeft = max - start;
                path[pos] = '/';
                dst = path + start;
                left = initialLeft;
                src = grandparentName;
                do {
                    *dst++ = *src++;
                    left--;
                } while (left != 0 && *src != 0);
                pos = start + (initialLeft - left);
            }
        }
        if (pos != max) {
            start = pos + 1;
            initialLeft = max - start;
            path[pos] = '/';
            dst = path + start;
            left = initialLeft;
            src = parentName;
            do {
                *dst++ = *src++;
                left--;
            } while (left != 0 && *src != 0);
            pos = start + (initialLeft - left);
        }
    }
    if (pos != max) {
        start = pos + 1;
        initialLeft = max - start;
        path[pos] = '/';
        dst = path + start;
        left = initialLeft;
        src = name;
        do {
            *dst++ = *src++;
            left--;
        } while (left != 0 && *src != 0);
        pos = start + (initialLeft - left);
    }
    return pos;
}
#pragma scheduling on
#pragma pop
extern void OSPanic(const char *, s32, const char *);
extern s32 DVDReadAbsAsyncPrio(void *, void *, s32, s32, void *, s32);
extern void cbForCancelSync(void);
extern void cbForReadAsync(void *, void *);
extern char lbl_80302070[];
extern char lbl_803020A4[];
extern char lbl_80558DF8[];
#pragma push
#pragma use_lmw_stmw off
/* Starts an asynchronous read from an open DVD file at a byte offset with priority. */
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
void fn_800356F4(s32 error, s32 param1, s32 param2) {
    s32 interrupts;
    u32 tick;
    u8 *info;

    /* Record an error entry in the next __ErrorInfo slot and advance the ring index with interrupts disabled. */
    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 >= 5) {
        *(volatile u32 *)&lbl_8055D848 = 0;
    }
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = error;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = param1;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = param2;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
    OSRestoreInterrupts(interrupts);
}
#pragma pop
void fn_800357A8(void) {

}

void DVDInit(void) {
    s32 bootMagic;
    s32 one = 1;
    s32 ver;
    u32 diskBase;
    u8 *disk;
    if (DVDInitialized_8055D888 == 0) {
        OSRegisterVersion(__DVDVersion);
        DVDInitialized_8055D888 = one;
        DVDLowInit();
        __DVDFSInit();
        __DVDClearWaitingQueue();
        MotorState_8055D8A8 = 0;
        bootInfo_8055D8C0 = (void *)0x80000000;
        IDShouldBe_8055D8C4 = (s32)0x80000000;
        OSInitThreadQueue(__DVDThreadQueue);
        DVDLowUnmaskStatusInterrupts();
        DVDLowMaskCoverInterrupt();
        bootMagic = *(s32 *)((u8 *)bootInfo_8055D8C0 + 0x20);
        if (((u32)(bootMagic + 0x1AE00000) != 0x7C22) && ((u32)(bootMagic - 0x0D150000) != 0xEA5E)) {
            FirstTimeInBootrom_8055D868 = one;
        }
        memset(__ErrorInfo, 0, 0x80);
        memcpy(__ErrorInfo, (void *)0x80000000, 4);
        diskBase = 0x80000000;
        disk = (u8 *)diskBase;
        __ErrorInfo[4] = disk[6];
        ver = disk[7];
        __ErrorInfo[5] = (u8)ver;
        __DVDLayoutFormat = 0;
        DVDSetAutoFatalMessaging(one, (u8)ver, __ErrorInfo, (void *)diskBase);
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Start a DVD read for boot data into the boot info buffer after validating size, and record read metadata in error info. */
void fn_8003588C(void) {
    u32 discOffset;
    u32 readLength;
    s32 interrupts;
    u8 *errorInfoBase;
    u32 tick;

    lbl_8055D8CC = (s32)fn_8003588C;
    if (*(u32 *)((u8 *)bootInfo_8055D8C0 + 0x3C) < *(u32 *)(lbl_80376A80 + 8)) {
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558E0C, 0x3F6, lbl_80302120);
    }
    fn_8003BCDC(0);

    readLength = ((*(u32 *)(lbl_80376A80 + 8) << (~(*(volatile u32 *)&__DVDLayoutFormat) & 2)) + 0x1F) & ~0x1F;
    discOffset = *(u32 *)(lbl_80376A80 + 4) >> *(volatile u32 *)&__DVDLayoutFormat;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 >= 5)
        *(volatile u32 *)&lbl_8055D848 = 0;
    errorInfoBase = (u8 *)__ErrorInfo;
    *(s32 *)(errorInfoBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 1;
    *(s32 *)(errorInfoBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = discOffset;
    *(s32 *)(errorInfoBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = readLength;
    tick = OSGetTick();
    *(s32 *)(errorInfoBase + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
    OSRestoreInterrupts(interrupts);

    fn_8003B81C(*(void **)((u8 *)bootInfo_8055D8C0 + 0x38),
                ((*(u32 *)(lbl_80376A80 + 8) << (~(*(volatile u32 *)&__DVDLayoutFormat) & 2)) + 0x1F) & ~0x1F,
                *(u32 *)(lbl_80376A80 + 4) >> *(volatile u32 *)&__DVDLayoutFormat,
                (s32)fn_80035A04);
}
#pragma dont_inline on
/* Completion callback of the boot read started by fn_8003588C(); `result` is the
 * state the drive finished the read with.
 *
 * The state goes into the driver's error log first (dvderror.h's DVDErrorInfo at
 * __ErrorInfo: the dicr word of the entry the log count lbl_8055D848 points at, or
 * the spare word at 0x78 while no command has been logged), so a dump of that log
 * shows how the read ended. Then, by state:
 *   0x10 / 0x20 - the boot is over and the drive needs no reset: hand the log to
 *     NAND with the reason code 0x1234568 / 0x1234569 (fn_8003A1A0), and let
 *     fn_80035C78() re-arm the drive if NAND cannot take it.
 *   bit 0 set - the read was cancelled rather than failed: clear the drive-error
 *     count, rebuild the file system from the disc's FST, make the dummy block the
 *     executing one again, finish the real block (its state and its own callback,
 *     with the good result 0) and start whatever is queued behind it.
 *   anything else - log a fatal entry (0x27) and queue a drive reset transaction,
 *     which reports back through fn_80035E6C().
 */
void fn_80035A04(u32 result) {
    register s32 interrupts;
    s32 enabled;
    s32 *block;
    void (*callback)(s32);

    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0)
        *(u32 *)(__ErrorInfo + 0x78) = result;
    else
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = result;
    OSRestoreInterrupts(enabled);

    if (result == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78); /* save the error log to NAND */
        return;
    }
    if (result == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78); /* same, other reason */
        return;
    }
    if (result & 1) {
        lbl_8055D860 = 0;   /* no drive errors seen any more */
        __DVDFSInit();
        block = (s32 *)executing_8055D8C8; /* the DVDCommandBlock we were running */
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        block[3] = 0;                       /* block->state = 0 */
        callback = *(void (**)(s32))((u8 *)block + 0x28); /* block->callback */
        if (callback != 0)
            callback(0);                    /* DVD_RESULT_GOOD */
        fn_80038040();                      /* start the next queued command */
        return;
    }

    interrupts = OSDisableInterrupts();
    /* a new log entry: code 0x27, no parameters, taken now */
    if (*(volatile u32 *)&lbl_8055D848 >= 5)
        *(volatile u32 *)&lbl_8055D848 = 0;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x27;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
    *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
    OSRestoreInterrupts(interrupts);
    fn_8003B218(fn_80035E6C); /* queue a drive reset */
}
#pragma dont_inline off
extern void __DVDPrintFatalMessage(void);
extern s32 lbl_8055D858;
void fn_80035B88(u32 dvdStatus) {
    u32 *currentBlock;
    void (*completionCb)(s32, void *);

    /* Fatal DVD command result: mark current block failed, save log for
     * 0x10/0x20 resets, otherwise report fatal and complete callbacks,
     * then continue the waiting queue. */
    *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = -1;
    if (dvdStatus == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (dvdStatus == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }

    __DVDPrintFatalMessage();
    currentBlock = (u32 *)executing_8055D8C8;
    FatalErrorFlag_8055D854 = 1;
    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
    completionCb = *(void (**)(s32, void *))((u8 *)currentBlock + 0x28);
    if (completionCb != 0)
        completionCb(-1, currentBlock);
    if (lbl_8055D858 != 0) {
        completionCb = lbl_8055D8B8;
        lbl_8055D858 = 0;
        if (completionCb != 0)
            completionCb(0, currentBlock);
    }
    fn_80038040();
}

void fn_80035C64(void) {
    fn_8003AF1C(0, 0, fn_80035B88);
}

extern s32 lbl_8055D890;
#pragma small_data off
extern __declspec(section ".data") u8 lbl_8037B580;
#pragma small_data on
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
/* Categorize a DVD drive error/status code (low 24 bits) and return a retry/
 * handling category: 0 = ignore, 1 = clear/recover, 2 = retry, 3 = fatal.
 * Updates lbl_8055D8B0 with the (masked) code and tracks repeats in lbl_8055D860,
 * with special cases for certain codes and the executing command/callback state. */
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
    /* Record a DVD error (command 0x10) in the next __ErrorInfo slot, then invoke fn_8003AF1C with callback fn_80036624. */
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

#pragma push
#pragma dont_inline on
void fn_80035E6C(u32 arg0) {
    register s32 state;
    s32 firstInterrupts;
    s32 taskType;
    u32 status;
    s32 code;
    s32 handled;
    void *block;
    void (*callback)(s32, void *);
    register u32 kind = arg0;
    u8 *info;
    u32 value;
    u32 tick;
    u32 period;

    firstInterrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0)
        *(u32 *)(__ErrorInfo + 0x78) = kind;
    else
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = kind;
    OSRestoreInterrupts(firstInterrupts);

    if (kind == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (kind == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (kind & 2) {
        fn_8003A1A0(0x1234567, fn_80035C64);
        return;
    }

    taskType = ((s32 (*)(void))fn_8003BCC0)();
    kind = taskType & 0xFF000000;
    status = fn_80035CB4(taskType);
    if (status == 1) {
        fn_8003A1A0(taskType, fn_80035C64);
        return;
    }
    if ((u32)(status - 2) <= 1) {
        code = 0;
    } else if (kind == 0x01000000) {
        code = 4;
    } else if (kind == 0x02000000) {
        code = 6;
    } else if (kind == 0x03000000) {
        code = 3;
    } else if (kind == 0) {
        if ((u32)(taskType - 0x00050000) == 0x3000)
            code = 1;
        else
            code = 5;
    } else {
        code = 5;
    }

    if (lbl_8055D858 != 0) {
        block = (void *)executing_8055D8C8;
        lbl_8055D85C = code;
        lbl_8055D858 = 0;
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        *(s32 *)((char *)block + 0xC) = 0xA;
        callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
        if (callback != 0)
            callback(-3, block);
        if (lbl_8055D8B8 != 0)
            lbl_8055D8B8(0, block);
        fn_80038040();
        handled = 1;
    } else {
        handled = 0;
    }
    if (handled != 0)
        return;

    if (status == 2) {
        fn_8003A1A0(taskType, (void (*)(void))fn_80035DA8);
        return;
    }
    if (status == 3) {
        if ((u32)((taskType & 0x00FFFFFF) - 0x00030000) == 0x1100) {
            value = *(u32 *)((char *)executing_8055D8C8 + 0x10);
            state = OSDisableInterrupts();
            if (*(volatile u32 *)&lbl_8055D848 >= 5)
                *(volatile u32 *)&lbl_8055D848 = 0;
            info = (u8 *)__ErrorInfo;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 2;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = value;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
            *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
            OSRestoreInterrupts(state);
            fn_8003B9CC(*(u32 *)((char *)executing_8055D8C8 + 0x10),
                        (void *)fn_80036370);
            return;
        }
        ((void (*)(void *))lbl_8055D8CC)((void *)executing_8055D8C8);
        return;
    }
    if (kind == 0x01000000) {
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 5;
        MotorState_8055D8A8 = 1;
        if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
            lbl_8055D870 = 1;
            OSCreateAlarm(&lbl_80376AD0);
            tick = OSGetTick();
            period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
            OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period,
                               fn_8003801C);
        }
        return;
    }
    if (kind == 0x02000000) {
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 3;
        fn_8003773C();
        return;
    }
    if (kind == 0x03000000) {
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 4;
        MotorState_8055D8A8 = 1;
        if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
            lbl_8055D870 = 1;
            OSCreateAlarm(&lbl_80376AD0);
            tick = OSGetTick();
            period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
            OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period,
                               fn_8003801C);
        }
        return;
    }
    if (kind == 0) {
        if ((u32)(taskType - 0x00050000) == 0x3000) {
            state = OSDisableInterrupts();
            if (*(volatile u32 *)&lbl_8055D848 >= 5)
                *(volatile u32 *)&lbl_8055D848 = 0;
            info = (u8 *)__ErrorInfo;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x10;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
            *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
            *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
            OSRestoreInterrupts(state);
            fn_8003AF1C(0, 0, (void *)fn_800373E0);
            return;
        }
        fn_8003A1A0(0x1234567, fn_80035C64);
        return;
    }
    fn_8003A1A0(0x1234567, fn_80035C64);
}
#pragma pop

extern void fn_80036550(u32);
void fn_80036370(u32 arg0) {
    register u32 errorCode = arg0;
    s32 interrupts;
    u32 tick;
    u8 *info;

    /* Record DVD error info into __ErrorInfo ring and dispatch recovery based on error code. */
    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0)
        *(u32 *)(__ErrorInfo + 0x78) = errorCode;
    else
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = errorCode;
    OSRestoreInterrupts(interrupts);

    if (errorCode == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (errorCode == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }

    if (errorCode & 1) {
        interrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&lbl_8055D848 >= 5)
            *(volatile u32 *)&lbl_8055D848 = 0;
        info = (u8 *)__ErrorInfo;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x10;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
        tick = OSGetTick();
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
        *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
        OSRestoreInterrupts(interrupts);
        fn_8003AF1C(0, 0, fn_80036624);
        return;
    }

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 >= 5)
        *(volatile u32 *)&lbl_8055D848 = 0;
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x27;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
    OSRestoreInterrupts(interrupts);
    fn_8003B218((void (*)(void))fn_80036550);
}

extern void fn_8003A1A0(u32, void (*)(void));
extern void fn_8003BCC0(void);
extern void fn_80035C64(void);
extern void fn_80035C78(void);
#pragma push
#pragma scheduling invalid_target
void fn_80036550(u32 errorCode) {
    register u32 code = errorCode;
    s32 interrupts = OSDisableInterrupts();

    /* Store the error code in the error info record while interrupts are disabled. */
    if (*(volatile u32 *)&lbl_8055D848 == 0) *(u32 *)(__ErrorInfo + 0x78) = code;
    else *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = code;
    OSRestoreInterrupts(interrupts);

    if (code == 0x10) fn_8003A1A0(0x1234568, fn_80035C78);
    else if (code == 0x20) fn_8003A1A0(0x1234569, fn_80035C78);
    else if (code & 2) fn_8003A1A0(0x1234567, fn_80035C64);
    else ((void (*)(void *, void (*)(void)))fn_8003A1A0)(((void *(*)(void))fn_8003BCC0)(), fn_80035C64);
}
#pragma pop

/* Drive error handler run on the DVD thread (queued through fn_8003AF1C with the
 * error code as its argument).  The code goes into the last __ErrorInfo entry;
 * the codes the NAND error report of fn_8003A1A0 deals with end the handling
 * here, and any other code finishes the cancel that is in flight: the command
 * the drive was running is completed with DVD_RESULT_CANCELED.  When nothing
 * was being cancelled the dummy block is marked as needing attention instead
 * and the periodic cover/motor poll is armed. */
void fn_80036624(s32 errorCode) {
    register u32 code = errorCode;
    s32 interrupts;
    s32 complete;
    DVDCommandBlock *block;
    DVDCommandCallback callback;
    u32 tick;
    u32 period;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&ErrorInfoEntry == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = code;
    } else {
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&ErrorInfoEntry * 0x14 + 0x14) = code;
    }
    OSRestoreInterrupts(interrupts);

    if (code == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (code == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (code & 2) {
        fn_8003A1A0(0x1234567, fn_80035C64);
        return;
    }

    *(volatile s32 *)&DriveErrorCount = 0;
    // The commands that do not need the drive reset before they can be retried.
    if (*(volatile u32 *)&DriveCommand == 4 ||
        *(volatile u32 *)&DriveCommand == 5 ||
        *(volatile u32 *)&DriveCommand == 13 ||
        *(volatile u32 *)&DriveCommand == 33 ||
        *(volatile u32 *)&DriveCommand == 34 ||
        *(volatile u32 *)&DriveCommand == 15 ||
        *(volatile u32 *)&DriveCommand == 37) {
        lbl_8055D8AC = 1;
    }

    if (*(volatile s32 *)&Canceling != 0) {
        block = (DVDCommandBlock *)ExecutingBlock;
        *(volatile s32 *)&StateToChange = 2;
        *(volatile s32 *)&Canceling = 0;
        ExecutingBlock = (s32)DummyBlock;
        block->state = DVD_STATE_CANCELED;
        callback = block->callback;
        if (callback != 0)
            callback(DVD_RESULT_CANCELED, block);
        if (CancelCallback != 0)
            CancelCallback(DVD_RESULT_GOOD, block);
        fn_80038040();
        complete = 1;
    } else {
        complete = 0;
    }
    if (complete != 0)
        return;

    ((DVDCommandBlock *)ExecutingBlock)->state = DVD_STATE_DISK_ERROR;
    MotorState_8055D8A8 = DVD_STATE_BUSY;
    if (Transferring == 0 && AlarmInfo == 0) {
        Transferring = 1;
        OSCreateAlarm(&StateAlarm);
        tick = OSGetTick();
        period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100; // 100 ms in timer ticks
        OSSetPeriodicAlarm(&StateAlarm, 0x10624DD3, 0, tick, 0, period,
                           fn_8003801C);
    }
}

extern u8 lbl_80376A80[];
extern s32 lbl_8055D87C, lbl_8055D8BC;
extern s32 IDShouldBe_8055D8C4, executing_8055D8C8, lbl_8055D860;
extern BOOL DVDCompareDiskID(void *, void *);
extern s32 fn_8003AD88(void *, s32, s32, u32);
extern void fn_80036B84(u32);
extern char lbl_80376B20[];
extern char lbl_80376B40[];
extern u32 *lbl_8055D89C;
extern void fn_80036D24(u32);
extern void fn_800373E0(u32);
extern int memcmp(const void *, const void *, u32);
void fn_8003684C(void) {
    register s32 enabled;
    register u8 *idBase = lbl_80376A80;
    register s32 zero = 0;
    switch (lbl_8055D8BC) {
    case 3:
        lbl_8055D87C = zero;
        if (DVDCompareDiskID(idBase + 0x80,
                *(void **)(executing_8055D8C8 + 0x24)) != 0) {
            memcpy((void *)IDShouldBe_8055D8C4, idBase + 0x80, 0x20);
            *(s32 *)(executing_8055D8C8 + 0xC) = 1;
            DCInvalidateRange(idBase, 0x20);
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

#pragma push
#pragma dont_inline on
/* Handles a DVD drive status value: records it in __ErrorInfo, then starts an
 * error-report/reset flow for 0x10, 0x20 or an odd code, else issues a
 * stop-motor/reset command sequence. */
void fn_80036B84(u32 status) {
    s32 interrupts;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 +
                 (*(volatile u32 *)&lbl_8055D848 - 1) * 0x14) = status;
    }
    OSRestoreInterrupts(interrupts);

    if (status == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (status == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (status & 1) {
        u8 *info;
        s32 state;

        lbl_8055D860 = 0;
        lbl_8055D89C = (u32 *)lbl_80376B20;
        fn_8003BCDC(0);

        state = OSDisableInterrupts();
        if (*(volatile u32 *)&lbl_8055D848 >= 5)
            *(volatile u32 *)&lbl_8055D848 = 0;
        info = (u8 *)__ErrorInfo;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x21;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0x10008;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0x20;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
        OSRestoreInterrupts(state);
        fn_8003AD88(lbl_80376B40, 0x20, 0x10008, (u32)fn_80036D24);
        return;
    }

    fn_800356F4(0x27, 0, 0);
    fn_8003B218(fn_80035E6C);
}
#pragma pop

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

extern void fn_800375A8(u32);
/* Record DVD error status into the global error info ring and dispatch the corresponding recovery path. */
void fn_800370F4(u32 errorCode) {
    register u32 status = errorCode;
    s32 interrupts;
    u8 *info;
    u32 tick;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 +
                 (*(volatile u32 *)&lbl_8055D848 - 1) * 0x14) = status;
    }
    OSRestoreInterrupts(interrupts);

    if (status == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (status == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (status & 1) {
        lbl_8055D860 = 0;
        fn_8003BCDC(0);
        interrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&lbl_8055D848 >= 5)
            *(volatile u32 *)&lbl_8055D848 = 0;
        info = (u8 *)__ErrorInfo;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 1;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0x108;
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0x20;
        tick = OSGetTick();
        *(s32 *)(info + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = tick;
        *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
        OSRestoreInterrupts(interrupts);
        fn_8003B81C(lbl_80376A80, 0x20, 0x108, (s32)fn_800375A8);
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}

/* Handles a DVD DI/drive status value: records it in __ErrorInfo, then either starts error-report/reset flows (0x10/0x20/bit0) or issues a stop-motor/reset command sequence. */
void fn_8003727C(u32 status) {
    register u32 diStatus = status;
    s32 interrupts = OSDisableInterrupts();
    s32 resetHandled;
    void *commandBlock;
    void (*callback)(s32, void *);

    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = diStatus;
    } else {
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = diStatus;
    }
    OSRestoreInterrupts(interrupts);

    if (diStatus == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (diStatus == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (diStatus & 1) {
        *(volatile s32 *)&lbl_8055D860 = 0;
        if (*(volatile s32 *)&lbl_8055D858 != 0) {
            commandBlock = (void *)executing_8055D8C8;
            lbl_8055D85C = 0;
            lbl_8055D858 = 0;
            executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
            *(s32 *)((u8 *)commandBlock + 0xC) = 0xA;
            callback = *(void (**)(s32, void *))((u8 *)commandBlock + 0x28);
            if (callback != 0)
                callback(-3, commandBlock);
            if (lbl_8055D8B8 != 0)
                lbl_8055D8B8(0, commandBlock);
            fn_80038040();
            resetHandled = 1;
        } else {
            resetHandled = 0;
        }
        if (resetHandled == 0) {
            *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 1;
            fn_80038368((void *)executing_8055D8C8);
        }
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}

/* DVD motor/error callback: records error state, handles special/reset cases, and either
 * cancels the executing command or schedules periodic motor-off via alarm. */
void fn_800373E0(u32 arg0) {
    register u32 value = arg0;
    s32 interrupts;
    s32 resetDone;
    void *block;
    void (*callback)(s32, void *);
    u32 tick;
    u32 period;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = value;
    } else {
        *(u32 *)(__ErrorInfo +
                 *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = value;
    }
    OSRestoreInterrupts(interrupts);

    if (value == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (value == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (value & 2) {
        fn_8003A1A0(0x1234567, fn_80035C64);
        return;
    }

    *(volatile s32 *)&lbl_8055D860 = 0;
    if (*(volatile s32 *)&lbl_8055D858 != 0) {
        block = (void *)executing_8055D8C8;
        lbl_8055D85C = 1;
        lbl_8055D858 = 0;
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        *(s32 *)((u8 *)block + 0xC) = 0xA;
        callback = *(void (**)(s32, void *))((u8 *)block + 0x28);
        if (callback != 0)
            callback(-3, block);
        if (lbl_8055D8B8 != 0)
            lbl_8055D8B8(0, block);
        fn_80038040();
        resetDone = 1;
    } else {
        resetDone = 0;
    }
    if (resetDone != 0)
        return;

    *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 6;
    MotorState_8055D8A8 = 1;
    if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
        lbl_8055D870 = 1;
        OSCreateAlarm(&lbl_80376AD0);
        tick = OSGetTick();
        period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
        OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period,
                           fn_8003801C);
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_800375A8(u32 arg0) {
    register u32 value = arg0;
    s32 interrupts;
    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = value;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 + (*(volatile u32 *)&lbl_8055D848 - 1) * 0x14) = value;
    }
    OSRestoreInterrupts(interrupts);
    if (value == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (value == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (value & 1) {
        u32 layout;
        register u32 shiftedSize;
        register u32 rawSize;
        lbl_8055D860 = 0;
        lbl_8055D8CC = (s32)fn_8003588C;
        if (*(u32 *)((u8 *)bootInfo_8055D8C0 + 0x3C) < *(u32 *)(lbl_80376A80 + 8)) {
            ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558E0C, 0x3F6, lbl_80302120);
        }
        fn_8003BCDC(0);
        layout = *(volatile u32 *)&__DVDLayoutFormat;
        shiftedSize = *(u32 *)(lbl_80376A80 + 8) << (~*(volatile u32 *)&__DVDLayoutFormat & 2);
        rawSize = *(u32 *)(lbl_80376A80 + 4);
        ((void (*)(s32, s32, s32, u32, u32))fn_800356F4)(1, rawSize >> layout, (shiftedSize + 0x1F) & ~0x1F, layout, rawSize);
        fn_8003B81C(*(void **)((u8 *)bootInfo_8055D8C0 + 0x38),
                    ((*(u32 *)(lbl_80376A80 + 8) << (~*(volatile u32 *)&__DVDLayoutFormat & 2)) + 0x1F) & ~0x1F,
                    *(u32 *)(lbl_80376A80 + 4) >> *(volatile u32 *)&__DVDLayoutFormat,
                    (s32)fn_80035A04);
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}
#pragma pop
extern s32 MotorState_8055D8A8;
extern s32 lbl_8055D8BC;
extern void __DVDClearWaitingQueue(void);
extern void fn_80038368(void *);
extern void fn_800379A8(u32);
extern BOOL __OSInIPL;
/* Handle DVD command completion/error state transitions based on the current executing command. */
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

void fn_80037800(void) {
    /* Initializes a platform-specific error path, logging an error record and starting the corresponding transfer/callback. */
    s32 savedInterrupts;

    if (*(u16 *)0x800030E6 == 0x8003) {
        lbl_8055D8CC = (s32)fn_80037A8C;
        fn_8003BCDC(0);

        savedInterrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&lbl_8055D848 >= 5)
            *(volatile u32 *)&lbl_8055D848 = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 0x25;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&lbl_8055D848 =
            *(volatile u32 *)&lbl_8055D848 + 1;
        OSRestoreInterrupts(savedInterrupts);
        fn_8003B69C(0x20000, fn_80037B54);
    } else {
        DCInvalidateRange(lbl_80376B00, 0x20);
        lbl_8055D8CC = (s32)fn_80037CEC;
        fn_8003BCDC(0);

        savedInterrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&lbl_8055D848 >= 5)
            *(volatile u32 *)&lbl_8055D848 = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 5;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0x20;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&lbl_8055D848 =
            *(volatile u32 *)&lbl_8055D848 + 1;
        OSRestoreInterrupts(savedInterrupts);
        fn_8003A834(lbl_80376B00, fn_80037DBC);
    }
}

extern s32 lbl_8055D8A0;
extern u32 lbl_8055D8A4;

extern void OSSetAlarm(void *, u64, u32, void (*)(void));
extern u64 __OSGetSystemTime(void);
extern void fn_80037800(void);
extern void fn_80035E6C();
#pragma push
#pragma dont_inline on
#pragma small_data off
void fn_800379A8(u32 status) {
    /* Handle DVD drive error/status: dispatch known codes, or on odd status
     * record the current time, reset drive state and arm the timeout alarm;
     * otherwise report a fatal DVD error. */
    u64 now;
    u32 alarmTicks;
    if (status == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (status == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (status & 1) {
        now = __OSGetSystemTime();
        lbl_8055D8A4 = now;
        lbl_8055D8A0 = now >> 32;
        lbl_8055D8AC = 0;
        lbl_8055D85C = 0;
        OSCreateAlarm(&lbl_8037B580);
        alarmTicks = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
        ((void (*)(void *, u32, u32, u32, void (*)(void)))OSSetAlarm)(&lbl_8037B580, 0x10624DD3, 0, alarmTicks, fn_80037800);
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}
#pragma pop
extern s32 fn_8003BCDC(s32);
extern void fn_8003B69C(u32, void*);
extern void fn_80037B54(u32);
void fn_80037A8C(void) {
    /* Request a DVD cover-interrupt clear, log error command 0x25 into the next
     * __ErrorInfo slot, then configure DVD audio buffering and continue via
     * fn_80037B54. */
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

#pragma push
#pragma dont_inline on
/* Record a DVD/error status event and dispatch the matching follow-up action
 * (direct callback, async read request, or generic error path). */
void fn_80037B54(u32 status_code) {
    register s32 saved_interrupts_async;
    s32 saved_interrupts;

    saved_interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status_code;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 +
                 (*(volatile u32 *)&lbl_8055D848 - 1) * 0x14) = status_code;
    }
    OSRestoreInterrupts(saved_interrupts);

    if (status_code == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (status_code == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (status_code & 1) {
        DCInvalidateRange(lbl_80376B00, 0x20);
        lbl_8055D8CC = (s32)fn_80037CEC;
        fn_8003BCDC(0);

        saved_interrupts_async = OSDisableInterrupts();
        if (*(volatile u32 *)&lbl_8055D848 >= 5)
            *(volatile u32 *)&lbl_8055D848 = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x1C) = 5;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x24) = 0x20;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
        OSRestoreInterrupts(saved_interrupts_async);
        fn_8003A834(lbl_80376B00, fn_80037DBC);
        return;
    }

    fn_800356F4(0x27, 0, 0);
    fn_8003B218(fn_80035E6C);
}
#pragma pop

extern void fn_8003A834(void *, void *);
extern char lbl_80376B00[];
extern void fn_80037DBC(u32);
/* Schedules an async DVD error info read by recording an error entry and starting the read callback chain. */
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
// Handle DVD command block callback status and dispatch appropriate action.
void fn_80037DBC(u32 status) {
    register u32 value = status;
    s32 interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&lbl_8055D848 == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = value;
    } else {
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 0x14 + 0x14) = value;
    }
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
// (Transferring, AlarmInfo, CoverRegPending, DriveCommand, DiskChanged,
// StateToChange, StateAlarm and ExecutingBlock are named at the top of the file.)

// Callback for the cover-register read kicked off by fn_8003801C: it reads the
// drive's cover/motor status and advances the state machine. If we were waiting
// on the cover interrupt and the cover is now open it stops that wait and
// re-enters the motor-standby path; if the cover just closed it hands over from
// the timeout alarm to waiting on the cover interrupt.
void fn_80037E94(void) {
    s32 zero = 0;
    *(volatile s32 *)&CoverRegPending = zero;
    if (*(volatile s32 *)&AlarmInfo != 0) {
        if (!(fn_8003BB48() & 1)) {
            OSCancelAlarm(&StateAlarm);
            *(volatile s32 *)&AlarmInfo = zero;
            *(volatile s32 *)&AlarmInfo = zero;
            if ((u32)*(volatile s32 *)&DriveCommand == 3) DiskChanged = 1;
            if ((u32)MotorState_8055D8A8 == 2) {
                if (ExecutingBlock != 0) *(s32 *)((u8 *)ExecutingBlock + 0xC) = 0xC;
            } else {
                DVDLowMaskCoverInterrupt();
                if (ExecutingBlock != 0) {
                    *(s32 *)((u8 *)ExecutingBlock + 0xC) = 3;
                    fn_8003773C();
                    return;
                }
                StateToChange = 7;
            }
        }
    } else {
        if (fn_8003BB48() & 1) {
            Transferring = zero;
            *(volatile s32 *)&AlarmInfo = 1;
            if ((u32)MotorState_8055D8A8 == 2) *(s32 *)((u8 *)ExecutingBlock + 0xC) = 0xC;
            else *(s32 *)((u8 *)ExecutingBlock + 0xC) = 5;
            return;
        }
        if (fn_8003BB48() & 4) {
            OSCancelAlarm(&StateAlarm);
            Transferring = zero;
            fn_8003BCDC(zero);
            *(volatile s32 *)&AlarmInfo = zero;
            if ((u32)*(volatile s32 *)&DriveCommand == 3) DiskChanged = 1;
            if ((u32)MotorState_8055D8A8 == 2) {
                if (ExecutingBlock != 0) *(s32 *)((u8 *)ExecutingBlock + 0xC) = 0xC;
            } else {
                DVDLowMaskCoverInterrupt();
                if (ExecutingBlock != 0) {
                    *(s32 *)((u8 *)ExecutingBlock + 0xC) = 3;
                    fn_8003773C();
                    return;
                }
                StateToChange = 7;
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
    void *temp_r3, *temp_r4, *temp_r5;
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
        *(s32 *)((u8 *)temp_r3 + 0xC) = -1;
        temp_r5 = (void *)DummyCommandBlock_80376AA0;
        temp_r4 = (void *)executing_8055D8C8;
        executing_8055D8C8 = (s32)temp_r5;
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
                lbl_8055D870 = 1;
                OSCreateAlarm(lbl_80376AD0);
                OSSetPeriodicAlarm(lbl_80376AD0, 0x10624DD3, 0, OSGetTick(), 0,
                    ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 0x64, fn_8003801C);
            }
            break;
        case 4:
            *(s32 *)((u8 *)temp_r3 + 0xC) = 5;
            MotorState_8055D8A8 = 1;
            if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
                lbl_8055D870 = 1;
                OSCreateAlarm(lbl_80376AD0);
                OSSetPeriodicAlarm(lbl_80376AD0, 0x10624DD3, 0, OSGetTick(), 0,
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

#pragma push
#pragma use_lmw_stmw off
extern void fn_80038870(void);
extern void fn_8003B9CC(u32, void *);
extern void fn_8003B508(u32, u32, void *);
extern void fn_8003B0B0(void *, void *);
extern void fn_8003AC24(void *);
extern void (*lbl_80558E08)(void *, void *);
#pragma push
#pragma use_lmw_stmw off
void fn_80038368(void *arg0) {
 u8 *p = arg0;
 int command;
 lbl_8055D8CC = (int)fn_80038368;
 command = *(int *)(p+8);
 switch (command) {
 case 2: case 3: case 5: case 13: case 14: case 15: case 16: case 34: case 37: {
   u32 length = *(u32 *)(p+0x14), offset = *(u32 *)(p+0x10);
   {
 int irq = OSDisableInterrupts(); int tick;
 if (*(volatile u32 *)&lbl_8055D848 >= 5) *(volatile u32 *)&lbl_8055D848 = 0;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x1c) = command;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x20) = offset;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x24) = length;
 tick = OSGetTick();
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x2c) = tick;
 *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
 OSRestoreInterrupts(irq);
}
 } break;
 default: break;
 }
 switch (*(u32 *)(p+8)) {
 case 5:
   fn_8003BCDC(0); *(int *)(p+0x1c) = 0x20;
   fn_8003A834(*(void **)(p+0x18),fn_80038870); break;
 case 1: case 4:
   if (*(int *)(p+0x14) == 0) {
     u8 *old = (u8 *)executing_8055D8C8;
     executing_8055D8C8 = (int)DummyCommandBlock_80376AA0;
     *(int *)(old+0xc) = 0;
     if (*(void (**)(int))(old+0x28)) (*(void (**)(int))(old+0x28))(0);
     fn_80038040(); break;
   }
   fn_8003BCDC(0);
   {
     u32 remaining = *(u32 *)(p+0x14) - *(u32 *)(p+0x20);
     u32 n = 0x80000;
     u32 offset; int cmd;
     if (remaining <= n) n = remaining;
     *(u32 *)(p+0x1c) = n;
     cmd = *(int *)(p+8);
     offset = *(u32 *)(p+0x10) + (*(u32 *)(p+0x20) >> 2);
     {
 int irq = OSDisableInterrupts(); int tick;
 if (*(volatile u32 *)&lbl_8055D848 >= 5) *(volatile u32 *)&lbl_8055D848 = 0;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x1c) = cmd;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x20) = offset;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x24) = n;
 tick = OSGetTick();
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x2c) = tick;
 *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
 OSRestoreInterrupts(irq);
}
     ((int (*)(void *, u32, u32, void *))fn_8003B81C)(*(u8 **)(p+0x18)+*(u32 *)(p+0x20), *(u32 *)(p+0x1c), *(u32 *)(p+0x10)+(*(u32 *)(p+0x20)>>2), fn_80038870);
   } break;
 case 2: fn_8003BCDC(0); fn_8003B9CC(*(u32 *)(p+0x10),fn_80038870); break;
 case 3: fn_8003AF1C(0,0,fn_80038870); break;
 case 15: fn_8003AF1C(0,0,fn_80038870); break;
 case 13: fn_8003BCDC(0); fn_8003B508(*(u32 *)(p+0x10),*(u32 *)(p+0x14),fn_80038870); break;
 case 14: fn_8003BCDC(0); *(int *)(p+0x1c)=0x20; fn_8003B0B0(*(void **)(p+0x18),fn_80038870); break;
 case 16: fn_8003BCDC(0); fn_8003AF1C(0,0,fn_80038870); break;
 case 34: fn_8003B380(1); fn_8003B38C(fn_80038870); break;
 case 37:
   if (*(int *)(p+0x14) == 0) {
     u8 *old = (u8 *)executing_8055D8C8;
     executing_8055D8C8 = (int)DummyCommandBlock_80376AA0;
     *(int *)(old+0xc) = 0;
     if (*(void (**)(int))(old+0x28)) (*(void (**)(int))(old+0x28))(0);
     fn_80038040(); break;
   }
   fn_8003BCDC(0);
   {
     u32 remaining = *(u32 *)(p+0x14) - *(u32 *)(p+0x20);
     int cmd; u32 offset; u32 n = 0x80000;
     if (remaining <= n) n = remaining;
     *(u32 *)(p+0x1c) = n;
     cmd = *(int *)(p+8);
     offset = *(u32 *)(p+0x10) + (*(u32 *)(p+0x20) >> 2);
     {
 int irq = OSDisableInterrupts(); int tick;
 if (*(volatile u32 *)&lbl_8055D848 >= 5) *(volatile u32 *)&lbl_8055D848 = 0;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x1c) = cmd;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x20) = offset;
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x24) = n;
 tick = OSGetTick();
 *(int *)(__ErrorInfo + *(volatile u32 *)&lbl_8055D848 * 20 + 0x2c) = tick;
 *(volatile u32 *)&lbl_8055D848 = *(volatile u32 *)&lbl_8055D848 + 1;
 OSRestoreInterrupts(irq);
}
     ((void (*)(void *, u32, u32, void *))fn_8003AD88)(*(u8 **)(p+0x18)+*(u32 *)(p+0x20), *(u32 *)(p+0x1c), *(u32 *)(p+0x10)+(*(u32 *)(p+0x20)>>2), fn_80038870);
   } break;
 case 35: fn_8003BCDC(0); ((void (*)(u32, int, int, int, void *, void *))DVDLowOpenPartition)(*(u32 *)(p+0x10),0,0,0,*(void **)(p+0x18),fn_80038870); break;
 case 36: fn_8003BCDC(0); fn_8003AC24(fn_80038870); break;
 case 32: fn_8003BB58(fn_80038870); break;
 case 33: fn_8003BB58(fn_80038870); break;
 case 38: fn_8003BCDC(0); fn_8003B69C(0x20000,fn_80038870); break;
 default: lbl_80558E08(arg0,fn_80038870); break;
 }
}

void fn_80038870(void) {
    s32 interrupts;
    interrupts = OSDisableInterrupts();
    OSRestoreInterrupts(interrupts);
    fn_80038040();
}

#pragma pop

/* Start an asynchronous absolute DVD read into a command block at the given
 * priority. Sets up the read request, invalidates the destination cache range
 * when needed, queues the block, and kicks the DVD driver if idle. */
s32 DVDReadAbsAsyncPrio(void *block, void *addr, s32 length, s32 offset, void *callback, s32 prio) {
    s32 result;
    s32 savedInterrupts;
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

    savedInterrupts = OSDisableInterrupts();
    *(u32 *)((u8 *)block + 0xC) = 2;
    result = __DVDPushWaitingQueue(prio, block);
    if (executing_8055D8C8 == 0 && lbl_8055D84C == 0) {
        fn_80038040();
    }
    OSRestoreInterrupts(savedInterrupts);
    return result;
}

extern void DCInvalidateRange(void *, u32);
#pragma opt_propagation off
s32 DVDInquiryAsync(void *block, void *addr, void *callback) {
    /* Issue an asynchronous DVD inquiry command, invalidating the 0x20-byte reply buffer when needed and kicking the DVD queue. */
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
    status = *(s32 *)((u8 *)arg0 + 12);
    if (status == 3) {
        status = 1;
    } else if (status == 5) {
        status = 4;
    } else if ((u32)executing_8055D8C8 == (u32)&lbl_8037B5B0) {
        next = __DVDGetNextWaitingQueue();
        if (next != 0) {
            if ((u32)arg0 == (u32)next) status = 1;
            else status = *(s32 *)((u8 *)arg0 + 12);
        } else if ((u32)arg0 == (u32)&lbl_8037B5B0) {
            status = 0;
        } else {
            status = *(s32 *)((u8 *)arg0 + 12);
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
    s32 zero = 0;
    *(volatile s32 *)&lbl_8055D84C = zero;
    if (PausingFlag_8055D850 != 0) {
        PausingFlag_8055D850 = 0;
        fn_80038040();
    }
    OSRestoreInterrupts(enabled);
}
#pragma pop
// The DVDCommandBlock, DVDResult and DVDAsyncState types, and the state-static
// names below, are defined at the top of this file.

// The cancel state machine's own statics (dvdcancel.c); Canceling, ResetFlag,
// CancelCallback and DummyBlock are named at the top of the file, together with
// the cover/motor statics it shares with the state machine.

extern s32 lbl_8055D858, lbl_8055D86C;
extern void (*lbl_8055D8B8)(s32, void *);
extern s32 __DVDDequeueWaitingQueue(void *);
// This is __DVDCancelAsync(block, callback) of the Revolution DVD driver
// (source/os/dvd/dvdcancel.c); DVDCancel, DVDCancelAll and __DVDPrepareReset*
// are built on it.
// Cancel a DVD command without waiting for it. A block that is idle, already
// finished or still only queued is completed here with DVD_RESULT_CANCELED; a
// block the drive is working on makes the state machine stop and re-enter a
// clean state first, and @p callback is then called when that has finished.
// Returns FALSE when a cancel is already in flight (only one at a time).
// (callback is a DVDCommandCallback; the driver's callers all keep it as a
// plain (s32, void *) function pointer, so the parameter does too.)
s32 fn_80039424(DVDCommandBlock *block, void (*callback)(s32, void *)) {
    s32 enabled = OSDisableInterrupts();
    switch (block->state) {
    case DVD_STATE_FATAL: case DVD_STATE_IDLE: case DVD_STATE_CANCELED:
        if (callback) callback(DVD_RESULT_GOOD, block);
        break;
    case DVD_STATE_BUSY:
        if (Canceling) { OSRestoreInterrupts(enabled); return 0; }
        Canceling = 1;
        CancelCallback = callback;
        // A seek or a read leaves the drive mid-transfer: it has to be reset.
        if (block->command == 4 || block->command == 0x21 || block->command == 0x22 || block->command == 1)
            ResetFlag = 1;
        break;
    case DVD_STATE_WAITING:
        __DVDDequeueWaitingQueue(block);
        block->state = DVD_STATE_CANCELED;
        if (block->callback) block->callback(DVD_RESULT_CANCELED, block);
        if (callback) callback(DVD_RESULT_GOOD, block);
        break;
    case DVD_STATE_COVER_CLOSED:
        switch (block->command) {
        case 4: case 5: case 0xD: case 0xF: case 0x21: case 0x22: case 0x25:
            if (callback) callback(DVD_RESULT_GOOD, block);
            break;
        case 1: case 2:
            if (__OSInIPL) {
                ExecutingBlock = (s32)DummyBlock;
                block->state = DVD_STATE_CANCELED;
                if (block->callback) block->callback(DVD_RESULT_CANCELED, block);
                if (callback) callback(DVD_RESULT_GOOD, block);
                fn_80038040();
                break;
            }
            // Otherwise the drive has to stop first, like the states below.
        default:
            if (Canceling) { OSRestoreInterrupts(enabled); return 0; }
            Canceling = 1;
            CancelCallback = callback;
            break;
        }
        break;
    case DVD_STATE_NO_DISK: case DVD_STATE_COVER_OPENED: case DVD_STATE_WRONG_DISK_ID: case DVD_STATE_7: case DVD_STATE_DISK_ERROR:
        if (!AlarmInfo && !Transferring) { OSRestoreInterrupts(enabled); return 0; }
        OSCancelAlarm(&StateAlarm);
        Transferring = 0;
        // The drive state the state machine has to move on to first.
        if (block->state == DVD_STATE_NO_DISK) StateToChange = 3;
        if (block->state == DVD_STATE_COVER_OPENED) StateToChange = 4;
        if (block->state == DVD_STATE_WRONG_DISK_ID) StateToChange = 1;
        if (block->state == DVD_STATE_DISK_ERROR) StateToChange = 2;
        if (block->state == DVD_STATE_7) StateToChange = 7;
        ExecutingBlock = (s32)DummyBlock;
        block->state = DVD_STATE_CANCELED;
        if (block->callback) block->callback(DVD_RESULT_CANCELED, block);
        if (callback) callback(DVD_RESULT_GOOD, block);
        fn_80038040();
        break;
    case DVD_STATE_MOTOR_STOPPED:
        ExecutingBlock = (s32)DummyBlock;
        block->state = DVD_STATE_CANCELED;
        if (block->callback) block->callback(DVD_RESULT_CANCELED, block);
        if (callback) callback(DVD_RESULT_GOOD, block);
        fn_80038040();
        break;
    }
    OSRestoreInterrupts(enabled);
    return 1;
}

extern void OSSleepThread(void *);
extern void fn_80039838(void);

#pragma push
#pragma use_lmw_stmw off
s32 DVDReadPrio(void *fileInfo, void *buffer, s32 length, s32 offset, s32 priority) {
    s32 end;
    s32 enabled;
    s32 state;
    s32 result;

    /* Synchronously read from an open DVD file at a byte offset, with priority. */
    if (offset < 0 || (u32)offset > *(u32 *)((u8 *)fileInfo + 0x34))
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558DF8, 0x36B, lbl_803020A4);
    end = offset + length;
    if (end < 0 || (u32)end >= *(u32 *)((u8 *)fileInfo + 0x34) + 0x20)
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558DF8, 0x371, lbl_803020A4);
    if (DVDReadAbsAsyncPrio(fileInfo, buffer, length,
                            *(s32 *)((u8 *)fileInfo + 0x30) + (offset >> 2),
                            cbForCancelSync, priority) == 0)
        return -1;

    enabled = OSDisableInterrupts();
    for (;;) {
        state = *(s32 *)((u8 *)fileInfo + 0xC);
        if (state == 0) {
            result = *(s32 *)((u8 *)fileInfo + 0x20);
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
    /* Synchronously cancel a DVD command block, waiting for the drive/driver to
     * reach a terminal or safely cancelable state. */
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

s32 fn_80039840(void) {
    s32 result;
    s32 tempInterrupts;
    s32 savedInterrupts;
    void *active;

    savedInterrupts = OSDisableInterrupts();
    lbl_8055D864 = 0;
    tempInterrupts = OSDisableInterrupts();
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
        result = fn_80039424((void *)executing_8055D8C8,
                             (void (*)(s32, void *))cbForCancel);
    } else {
        result = 1;
        if (&cbForCancel != 0) {
            lbl_8055D864 = 1;
            OSWakeupThread(__DVDThreadQueue);
        }
    }
    active = (void *)OSDisableInterrupts();
    *(volatile s32 *)&lbl_8055D84C = 0;
    if (PausingFlag_8055D850 != 0) {
        PausingFlag_8055D850 = 0;
        fn_80038040();
    }
    OSRestoreInterrupts((s32)active);
    OSRestoreInterrupts(tempInterrupts);
    if (result == 0) {
        OSRestoreInterrupts(savedInterrupts);
        return -1;
    }
wait_loop:
    if (lbl_8055D864 != 0)
        goto wait_done;
    OSSleepThread(__DVDThreadQueue);
    goto wait_loop;
wait_done:
    OSRestoreInterrupts(savedInterrupts);
    return 0;
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
    u64 now;
    u32 hi;
    u32 lo;
    lbl_8055D88C = 0;
    fn_8003BB58((void (*)(void))fn_8003998C);
    while (*(volatile u32 *)&lbl_8055D88C == 0) {
    }
    if ((*(volatile u32 *)&lbl_8055D88C & 1) == 0) {
        return 0;
    }
    status = fn_8003BB48();
    now = __OSGetSystemTime();
    hi = lbl_8055D8A0;
    lo = lbl_8055D8A4;
    if ((s64)now - (s64)(((u64)hi << 32) | lo) < (s64)(((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100)) {
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
    s32 tempInterrupts;
    s32 savedInterrupts;
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
