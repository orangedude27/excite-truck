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
extern void __DVDStateBusy(void *);
extern void onBootDataReadComplete(u32);
extern s32 DVDLowReadAsync(void *, s32, s32, s32);
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

#define DVDNodeIsFolder(node) (((node).packed_type_name & 0xFF000000))
#define DVDNodeGetName(node) ((node).packed_type_name & 0x00FFFFFF)

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
extern void __DVDHandleError(u32);
extern void fn_8003773C(void);
extern void fn_8003801C(void);
extern void __DVDHandleMotorError(u32);
extern s32 lbl_8055D870, lbl_8055D874;
extern void DVDLowSeekAsync(u32, void *);
extern void fn_8003A1A0(u32, void (*)(void));
extern void fn_8003B218();
extern u32 errorLogCount;
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
extern void __DVDStateReady(void);
extern s32 OSGetTick(void);
extern s32 fn_8003BCDC(s32);
extern void DCInvalidateRange(void *, u32);
extern char lbl_80376B00[];
extern u8 lbl_80376AD0[0x30];
extern void fn_80037CEC(void);
extern void fn_80037DBC(u32);
extern void DVDLowAsyncIoctl(void *, void *);
extern void fn_8003B69C(u32, void *);
extern void __DVDRecordStatusEvent(u32);

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
extern void __DVDHandleCoverRegister(void);
extern void fn_8003BB58(void (*callback)(void));
extern void fn_8003B380(s32);
extern void fn_8003B38C(void *);
  extern void fn_80035B88(u32);
  extern void __DVDHandleDriveError(s32);
  extern void DVDLowRawReadAsync(s32, s32, void *);
  
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
extern void __DVDStateReady(void);
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

// The drive commands stateReady starts with no resume point held over.  The
// SDK's dvd.c has the full COMMAND_* list; these are the ones this unit tests.
#define COMMAND_INQUIRY         14
#define COMMAND_RESET           32
#define COMMAND_CLOSE_PARTITION 35

// StateToChange (the SDK's ResumeFromHere): the state the drive picks the
// command back up in once the one in hand is done with.
enum {
    RESUME_POINT_NONE,
    RESUME_POINT_WRONG_DISK_ID,
    RESUME_POINT_DISK_ERROR,
    RESUME_POINT_NO_DISK,
    RESUME_POINT_COVER_OPENED,
    RESUME_POINT_OK,
    RESUME_POINT_DISK_CHANGED,
    RESUME_POINT_7
};

// MotorState_8055D8A8: what the drive's motor is doing.
enum { MOTOR_STATE_WORKING, MOTOR_STATE_PENDING_STOP, MOTOR_STATE_STOPPED };

// The DVD cover/motor state machine's statics, shared with the cancel code below.
#define Transferring    lbl_8055D870  // the cover-poll timeout alarm is running
#define AlarmInfo       lbl_8055D874  // waiting on the cover interrupt instead
#define CoverRegPending lbl_8055D880  // a cover-register read is in flight
#define DriveCommand    lbl_8055D8BC  // the drive command being processed
#define DiskChanged     lbl_8055D87C  // cover opened during the disk-ID check
#define StateToChange   lbl_8055D85C  // drive state __DVDIssueCallback moves to next
#define StateAlarm      lbl_80376AD0  // the DVD state timeout alarm
#define MotorStopped    lbl_8055D878  // the motor is stopped, not just slowing
#define CancelLastError lbl_8055D8B4  // the drive error the cancel reports
#define ExecutingBlock  executing_8055D8C8 // block the driver is running

// The cancel state machine's own statics (dvdcancel.c).
#define Canceling      lbl_8055D858  // a cancel is waiting for the drive
#define ResetFlag      lbl_8055D86C  // the drive must be reset before the next command
#define CancelCallback lbl_8055D8B8  // called once the cancel has finished
#define DummyBlock     DummyCommandBlock_80376AA0 // "nothing is executing" block
#define PauseFlag      lbl_8055D84C  // DVDPause/DVDResume: keep stateReady off the queue
#define isCancelDone   lbl_8055D864  // cbForCancel: the cancel DVDCancelAll asked for landed
#define ResetDone      lbl_8055D890  // set by cbForPrepareReset; __DVDPrepareReset polls it

// The cancel helpers below, under the names the RVL SDK's DVD.cpp gives them.
#define DVDCancelAsync DVDCancelAsyncCore   // cancel one command block, answer when done
#define stateReady     __DVDStateReady   // start the next command on the waiting queue
#define stateCoverClosed     fn_8003773C // the drive's cover-closed state
#define stateBusy            __DVDStateBusy // the drive's busy state: run the block's command
#define CoverAlarmHandler    fn_8003801C // the alarm that polls the cover register
#define __DVDStoreErrorCode  fn_8003A1A0 // write a drive error code, then carry on
 #define cbForStoreErrorCode1 fn_80035C64 // carried on from the code just written

 // Cover-register read helpers used by the poll alarm and its callback.
 #define DVDLowPrepareCoverRegister fn_8003BB58 // queue a cover-register read with the given callback
 #define cbForCoverReg              __DVDHandleCoverRegister // called when that cover-register read lands


// The __ErrorInfo ring (dvderror.h): the next free entry of its info[] array,
// and how many drive error interrupts have been counted in a row.
#define ErrorInfoEntry  errorLogCount
#define DriveErrorCount lbl_8055D860

extern void *lbl_8055D808;
#define DSPInitFlag lbl_8055D808 // set to 1 once the DSP subsystem has been initialized
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

/* Return whether the DSP subsystem has been initialized (the DSP init flag). */
void* DSPReset(void) {
    return DSPInitFlag;
}

/* Insert a DSP task into the queue, clear its state and mark it active,
 * then boot it if it is now the first task. */
void *DSPAssertInt(void *task) {
    s32 interrupts;

    interrupts = OSDisableInterrupts();
    __DSP_insert_task(task);
    *(s32 *)task = 0;
    *(s32 *)((u8 *)task + 8) = 1;
    OSRestoreInterrupts(interrupts);
    if (task == lbl_8055D820) {
        __DSP_boot_task(task);
    }
    return task;
}

/* DSP interrupt handler: with interrupts disabled, mark the DSP task as
 * canceled and return it. */
void *__DSPHandler(DSPTask *task) {
    s32 level;
    level = OSDisableInterrupts();
    task->flags |= DSP_TASK_CANCELED;
    OSRestoreInterrupts(level);
    return task;
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

// Debug printf stub; ignores all arguments and produces no output.
void DBPrintf_800343C8(const char *format, ...) {
#pragma unused(format)
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
#pragma optimization_level 2
void __DSP_boot_task(void *arg0)
{
  volatile u32 mail;
  u32 *task;
  const char *fmt = lbl_80301E30;
  while (DSPCheckMailFromDSP() == 0)
  {
  }

  mail = DSPReadMailFromDSP();
  DSPSendMailToDSP(0x80F3A001);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(((u32 *) arg0)[3]);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(0x80F3C002);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP((u16) ((u32 *) arg0)[5]);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(0x80F3A002);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(((u32 *) arg0)[4]);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(0x80F3B002);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(0);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(0x80F3D001);
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DSPSendMailToDSP(*((u16 *) (((u8 *) arg0) + 0x24)));
  while (DSPCheckMailToDSP() != 0)
  {
  }

  DBPrintf_800343C8(fmt + 0, arg0);
  DBPrintf_800343C8(fmt + 0x20, ((u32 *) arg0)[3]);
  DBPrintf_800343C8(fmt + 0x50, ((u32 *) arg0)[5]);
  DBPrintf_800343C8(fmt + 0x80, ((u32 *) arg0)[4]);
  DBPrintf_800343C8(fmt + 0xB0, ((u32 *) arg0)[7]);
  DBPrintf_800343C8(fmt + 0xE0, *((u16 *) (((u8 *) arg0) + 0x24)));
}
#pragma optimization_level reset
void __DSP_insert_task(void *arg0) {
    /* Insert a DSP task into the global priority-sorted task list
     * (__DSP_first_task/__DSP_last_task/__DSP_curr_task). Priority is at +4;
     * prev at +0x3C, next at +0x38. */
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
/* Remove a task from the DSP task doubly-linked list and mark it done. */
void __DSP_remove_task(void *task) {
    *(u32 *)((u8 *)task + 8) = 0;
    *(u32 *)task = 3;
    if (lbl_8055D820 == task) {
        void *nextTask = *(void **)((u8 *)task + 0x38);
        if (nextTask != 0) {
            lbl_8055D820 = nextTask;
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

/* Low-memory mirror and the boot header's FST pointer slot. */
#define BOOT_INFO_BASE 0x80000000
#define FST_PTR_ADDR   0x80000038
#define FST_ENTRY_SIZE 12

#pragma dont_inline on
/* Initialize the DVD file-system globals from the boot header: record the
 * low-memory base and FST pointer, then derive the string table from the entry count. */
void __DVDFSInit(void) {
    u8 *fst;
    BootInfo_8055D844 = (void *)BOOT_INFO_BASE;
    fst = *(u8 **)FST_PTR_ADDR;
    FstStart_8055D840 = fst;
    if (fst == 0)
        return;
    MaxEntryNum_8055D838 = *(u32 *)(fst + 8);
    FstStringStart_8055D83C = fst + MaxEntryNum_8055D838 * FST_ENTRY_SIZE;
}
#pragma dont_inline off

#pragma use_lmw_stmw off
/* RVL SDK (dvdfs.c): resolve a path - relative to the current directory, or
 * absolute after a leading '/' - into a DVD FST entry number, or -1 when no
 * such file or folder exists. */
s32 DVDConvertPathToEntrynum(const char *path) {
    const DVDNode *fst;
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
    it = lbl_8055D828; /* currentDirectory */
    for (;;) {
        /* End of string -> return what we have */
        if (*path == '\0') return it;
        /* Ignore initial slash: /Path/File vs Path/File */
        if (*path == '/') { it = 0; path++; continue; }
        /* Handle special cases: -../-, -.., -./-, -. */
        if (path[0] == '.') {
            if (path[1] == '.') {
                /* Seek to parent ../ */
                if (path[2] == '/') {
                    it = ((DVDNode *)FstStart_8055D840)[it].folder.parent;
                    path += 3; continue;
                }
                /* Return parent folder immediately */
                if (path[2] == '\0')
                    return ((DVDNode *)FstStart_8055D840)[it].folder.parent;
                /* Malformed: fall through to the name check below */
                goto check_format;
            }
            /* "." directory does nothing */
            if (path[1] == '/') { path += 2; continue; }
            /* Ignore trailing dot */
            if (path[1] == '\0') return it;
        }
check_format:
        if (!__DVDLongFileNameFlag) {
            has_extension = FALSE;
            illegal_format = FALSE;
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') {
                if (*name_end == '.') {
                    /* 8.3 format limits file name to 8 characters. */
                    if (name_end - path > 8 || has_extension == TRUE) {
                        illegal_format = TRUE;
                        goto validate_format;
                    }
                    has_extension = TRUE;
                    extension_start = name_end + 1;
                }
                /* 8.3 format does not allow spaces in file name. */
                else if (*name_end == ' ') illegal_format = TRUE;
                name_end++;
            }
validate_format:
            if (has_extension == TRUE && name_end - extension_start > 3)
                illegal_format = TRUE;
            if (illegal_format == FALSE)
                goto skip_panic;
            /* OS_ASSERT(!illegal_format, "... doesn't match standard 8.3
             * format ...", backup_path) at dvdfs.c line 0x1B9 */
            ((void (*)(const char *, s32, const char *, ...))OSPanic)(
                lbl_80558DF8, 0x1B9, lbl_80301F70, backup_path);
skip_panic:;
        } else {
            /* The name is not special after all: isolate the current item of
             * the path string, up to the next '/' or the terminator. */
            name_end = path;
            while (*name_end != '\0' && *name_end != '/') name_end++;
        }
        /* Whether the name was delimited by a '/' rather than truncated. */
        name_delimited_by_slash = (*name_end == '\0') ? 0 : 1;
        name_length = name_end - path;
        /* Traverse all children of the parent. */
        anchor = it + 1;
        fst = (const DVDNode *)FstStart_8055D840;
        while (anchor < fst[it].folder.sibling_next) {
            while (TRUE) {
                if (DVDNodeIsFolder(fst[anchor]) ||
                    name_delimited_by_slash != TRUE) {
                    item_name = (const char *)FstStringStart_8055D83C +
                                DVDNodeGetName(fst[anchor]);
                    /* Advance to the next item in the path */
                    if (DVDPathSame(path, item_name) == TRUE)
                        goto descend;
                }
                if (DVDNodeIsFolder(fst[anchor])) {
                    anchor = fst[anchor].folder.sibling_next;
                    break;
                }
                anchor++;
                break;
            }
        }
        return -1;
descend:
        /* If the path was truncated, there is nowhere else to go. */
        if (!name_delimited_by_slash) return anchor;
        it = anchor;
        path += name_length + 1;
        continue;
    }
}
BOOL DVDFastOpen(s32 entrynum, void *info) {
    /* Open a DVD file by FST entry number, populating start offset, length, and zeroed state fields. */
    u32 entryOffset;

    if ((entrynum < 0) ||
        ((u32)entrynum >= MaxEntryNum_8055D838) ||
        ((*(u32 *)(FstStart_8055D840 + (entryOffset = (u32)entrynum * 0xC)) & 0xFF000000) != 0)) {
        return FALSE;
    }
    *(u32 *)((u8 *)info + 0x30) = *(u32 *)(FstStart_8055D840 + entryOffset + 4) >> __DVDLayoutFormat;
    *(u32 *)((u8 *)info + 0x34) = *(u32 *)(FstStart_8055D840 + entryOffset + 8);
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
static inline const char *entryName(s32 entry) {
    u32 off = *(u32 *)(FstStart_8055D840 + entry * 12) & 0xFFFFFF;
    return (const char *)FstStringStart_8055D83C + off;
}
static inline u32 entryParent(s32 entry) {
    return *(u32 *)(FstStart_8055D840 + 4 + entry * 12);
}
static inline u32 myStrncpy(char *dest, const char *src, u32 maxlen) {
    u32 i = maxlen;
    while (i > 0 && *src != 0) {
        *dest++ = *src++;
        i--;
    }
    return maxlen - i;
}
static inline u32 entryToPathA(u32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;
    if (entry == 0) return 0;
    name = (char *)FstStringStart_8055D83C + (*(u32 *)(FstStart_8055D840 + entry * 12) & 0xFFFFFF);
    return appendPathPart(path, DVDConvertEntrynumToPath(*(u32 *)(FstStart_8055D840 + 4 + entry * 12), path, maxlen), maxlen, name);
}
static inline u32 entryToPathB(s32 entry, char *path, u32 maxlen) {
    char *name;
    u32 loc;
    if (entry == 0) return 0;
    name = (char *)FstStringStart_8055D83C + (*(u32 *)(FstStart_8055D840 + entry * 12) & 0xFFFFFF);
    loc = entryToPathA(*(u32 *)(FstStart_8055D840 + 4 + entry * 12), path, maxlen);
    if (loc == maxlen) return loc;
    path[loc++] = '/';
    loc += myStrncpy(path + loc, name, maxlen - loc);
    return loc;
}
static inline u32 entryToPathC(u32 entry, char *path, u32 maxlen) {
    u32 loc;
    const char *name;
    if (entry == 0) return 0;
    name = (const char *)FstStringStart_8055D83C + (*(u32 *)(FstStart_8055D840 + entry * 12) & 0xFFFFFF);
    loc = entryToPathB(*(u32 *)(FstStart_8055D840 + 4 + entry * 12), path, maxlen);
    if (loc == maxlen) return loc;
    path[loc++] = '/';
    loc += myStrncpy(path + loc, name, maxlen - loc);
    return loc;
}
static inline BOOL convertEntrynumToPath(s32 entrynum, char *path, u32 maxlen) {
    u32 loc;
    loc = entryToPathC((u32)entrynum, path, maxlen);
    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }
    if (*(u32 *)(FstStart_8055D840 + entrynum * 12) & 0xFF000000) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }
        path[loc++] = '/';
    }
    path[loc] = '\0';
    return TRUE;
}
static inline u32 entryToPath1(u32 entry, char *path, u32 maxlen) {
    const char *name;
    if (entry == 0) return 0;
    name = entryName(entry);
    return appendPathPart(path, DVDConvertEntrynumToPath(entryParent(entry), path, maxlen), maxlen, name);
}
static inline u32 entryToPath2(u32 entry, char *path, u32 maxlen) {
    const char *name;
    u32 loc;
    if (entry == 0) return 0;
    name = entryName(entry);
    loc = entryToPath1(entryParent(entry), path, maxlen);
    return appendPathPart(path, loc, maxlen, name);
}
static inline u32 entryToPath3(u32 entry, char *path, u32 maxlen) {
    const char *name;
    u32 loc;
    if (entry == 0) return 0;
    name = entryName(entry);
    loc = entryToPath2(entryParent(entry), path, maxlen);
    return appendPathPart(path, loc, maxlen, name);
}
static inline void convertEntrynumPath(u32 entrynum, char *path, u32 maxlen) {
    u32 loc;
    u32 p1;
    u32 p2;
    char *name1;
    char *name2;
    char *name3;

    if (entrynum == 0) {
        loc = 0;
    } else {
        name1 = (char *)entryName(entrynum);
        p1 = entryParent(entrynum);
        if (p1 == 0) {
            loc = 0;
        } else {
            name2 = (char *)entryName(p1);
            p2 = entryParent(p1);
            if (p2 == 0) {
                loc = 0;
            } else {
                name3 = (char *)entryName(p2);
                loc = appendPathPart(path, DVDConvertEntrynumToPath(entryParent(p2), path, maxlen), maxlen, name3);
            }
            loc = appendPathPart(path, loc, maxlen, name2);
        }
        loc = appendPathPart(path, loc, maxlen, name1);
    }
    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
    } else {
        if (*(u32 *)(FstStart_8055D840 + entrynum * 12) & 0xFF000000) {
            if (loc == maxlen - 1) {
                path[loc] = '\0';
                return;
            }
            path[loc++] = '/';
        }
        path[loc] = '\0';
    }
}
#pragma push
#pragma use_lmw_stmw off
BOOL DVDGetCurrentDir(const char *path, void *info) {
    char dir[128];
    s32 entry;
    s32 cur;
    u32 offset;
    u8 *fstNode;

    /* Resolve the entry number for path in the DVD file system table; on failure
     * report the current directory instead. */
    entry = DVDConvertPathToEntrynum(path);
    if (entry < 0) {
        cur = lbl_8055D828;
        convertEntrynumPath(cur, dir, 0x80);
        OSReport(lbl_80302038, path, dir);
        return FALSE;
    }

    offset = entry * 12;
    fstNode = FstStart_8055D840;
    if (*(u32 *)(fstNode + offset) & 0xFF000000) {
        return FALSE;
    }
    fstNode += offset;
    *(u32 *)((u8 *)info + 0x30) = *(u32 *)(fstNode + 4) >> __DVDLayoutFormat;
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
extern u32 errorLogCount;
extern char __ErrorInfo[];
extern s32 OSGetTick(void);
s32 DVDClose(void) {
    /* Close the DVD device: cancel any outstanding commands, then report success. */
    DVDCancel();
    return 1;
}

#pragma scheduling reset
u32 DVDConvertEntrynumToPath(s32 entry, char *path, u32 max) {
    u32 pos;
    u8 *parentTable;
    u8 *strings;
    u8 *fst;
    u32 offset;
    u32 parentIndex;
    u32 nextParent;
    u32 n;
    u32 start;
    char *dst;
    u32 left;
    u32 initialLeft;
    char *parentName;
    char *name;
    char *grandparentName;
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
        goto append_name;
    }

    offset = parentIndex * 12;
    nextParent = *(u32 *)(parentTable + offset);
    parentName = (char *)(strings + (*(u32 *)(fst + offset) & 0xFFFFFF));
    if (nextParent == 0) {
        pos = 0;
        goto append_parent;
    }

    offset = nextParent * 12;
    n = *(u32 *)(parentTable + offset);
    grandparentName = (char *)(strings + (*(u32 *)(fst + offset) & 0xFFFFFF));
    n = DVDConvertEntrynumToPath(n, path, max);
    pos = n;
    if (pos != max) goto copy_grandparent;
    goto append_parent;
copy_grandparent:
    start = pos + 1;
    initialLeft = max - start;
    path[pos] = '/';
    dst = path + start;
    left = initialLeft;
    src = grandparentName;
    while (left != 0 && *src != 0) {
        *dst++ = *src++;
        left--;
    }
    pos = start + (initialLeft - left);

append_parent:
    if (pos != max) {
        start = pos + 1;
        initialLeft = max - start;
        path[pos] = '/';
        dst = path + start;
        left = initialLeft;
        src = parentName;
        while (left != 0 && *src != 0) {
            *dst++ = *src++;
            left--;
        }
        pos = start + (initialLeft - left);
    }

append_name:
    if (pos != max) {
        start = pos + 1;
        initialLeft = max - start;
        path[pos] = '/';
        dst = path + start;
        left = initialLeft;
        src = name;
        while (left != 0 && *src != 0) {
            *dst++ = *src++;
            left--;
        }
        pos = start + (initialLeft - left);
    }
    return pos;
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
/* DVD read completion: call the user callback stored in the file info at +0x38. */
void cbForReadAsync(void *result, void *fileInfo) {
    void (*userCallback)(void);
    userCallback = *(void (**)(void))((u8 *)fileInfo + 0x38);
    if (userCallback != 0) {
        userCallback();
    }
}

/* DVD cancel-completion callback: wakes the thread blocked in DVDCancel once the cancel command finishes. */
void cbForCancelSync(void) {
    /* Callback for a synchronous DVD cancel: wake the thread blocked in the cancel so it can observe completion. */
    OSWakeupThread(__DVDThreadQueue);
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline fn_800356F4
void fn_800356F4(s32 error, s32 param1, s32 param2) {
    u8 *info;
    s32 interrupts;
    u32 tick;

    /* Record an error entry in the next __ErrorInfo slot and advance the ring index with interrupts disabled. */
    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount >= 5) {
        *(volatile u32 *)&errorLogCount = 0;
    }
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = error;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = param1;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = param2;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
    OSRestoreInterrupts(interrupts);
}
#pragma pop
void fn_800357A8(void) {
    /* Empty no-op hook in the DVD library: between the DVDPatch error recorder
     * and DVDInit, it has no work to do and simply returns. */
}

/* Initialize the DVD driver and file system once on first use. */
void DVDInit(void) {
    s32 gameCode;
    s32 initialized = 1;
    u8 *bootInfo;

    if (DVDInitialized_8055D888 == 0) {
        OSRegisterVersion(__DVDVersion);
        DVDInitialized_8055D888 = initialized;
        DVDLowInit();
        __DVDFSInit();
        __DVDClearWaitingQueue();
        MotorState_8055D8A8 = 0;
        bootInfo_8055D8C0 = (void *)0x80000000;
        IDShouldBe_8055D8C4 = (s32)0x80000000;
        OSInitThreadQueue(__DVDThreadQueue);
        DVDLowUnmaskStatusInterrupts();
        DVDLowMaskCoverInterrupt();
        gameCode = *(s32 *)((u8 *)bootInfo_8055D8C0 + 0x20);
        if (((u32)(gameCode + 0x1AE00000) != 0x7C22) && ((u32)(gameCode - 0x0D150000) != 0xEA5E)) {
            FirstTimeInBootrom_8055D868 = initialized;
        }
        memset(__ErrorInfo, 0, 0x80);
        bootInfo = (u8 *)0x80000000;
        memcpy(__ErrorInfo, bootInfo, 4);
        __ErrorInfo[4] = bootInfo[6];
        __ErrorInfo[5] = bootInfo[7];
        __DVDLayoutFormat = 0;
        ((BOOL (*)(BOOL))DVDSetAutoFatalMessaging)(1);
    }
}

#pragma push
#pragma use_lmw_stmw off
/* Start a DVD read for boot data into the boot info buffer after validating size, and record read metadata in error info. */
/* Validate the FST boot-data size, then start an async low-level DVD read into the boot info buffer and log the read in the driver's error info. */ void startBootDataReadAsync(void) {
    u32 discOffset;
    u32 readLength;
    s32 interrupts;
    u8 *errorInfoBase;
    u32 tick;

    lbl_8055D8CC = (s32)startBootDataReadAsync;
    if (*(u32 *)((u8 *)bootInfo_8055D8C0 + 0x3C) < *(u32 *)(lbl_80376A80 + 8)) {
        ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558E0C, 0x3F6, lbl_80302120);
    }
    fn_8003BCDC(0);

    readLength = ((*(u32 *)(lbl_80376A80 + 8) << (~(*(volatile u32 *)&__DVDLayoutFormat) & 2)) + 0x1F) & ~0x1F;
    discOffset = *(u32 *)(lbl_80376A80 + 4) >> *(volatile u32 *)&__DVDLayoutFormat;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount >= 5)
        *(volatile u32 *)&errorLogCount = 0;
    errorInfoBase = (u8 *)__ErrorInfo;
    *(s32 *)(errorInfoBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 1;
    *(s32 *)(errorInfoBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = discOffset;
    *(s32 *)(errorInfoBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = readLength;
    tick = OSGetTick();
    *(s32 *)(errorInfoBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
    OSRestoreInterrupts(interrupts);

    DVDLowReadAsync(*(void **)((u8 *)bootInfo_8055D8C0 + 0x38),
                ((*(u32 *)(lbl_80376A80 + 8) << (~(*(volatile u32 *)&__DVDLayoutFormat) & 2)) + 0x1F) & ~0x1F,
                *(u32 *)(lbl_80376A80 + 4) >> *(volatile u32 *)&__DVDLayoutFormat,
                (s32)onBootDataReadComplete);
}
#pragma dont_inline on
/* Completion callback of the boot-data read started by startBootDataRead(); `result` is
 * the state the drive finished the read with.
 *
 * The state goes into the driver's error log first (dvderror.h's DVDErrorInfo at
 * __ErrorInfo: the dicr word of the entry the log count errorLogCount points at, or
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
void onBootDataReadComplete(u32 result) {
    register s32 interrupts;
    s32 savedInterrupts;
    s32 *block;
    void (*callback)(s32);

    savedInterrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0)
        *(u32 *)(__ErrorInfo + 0x78) = result;
    else
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = result;
    OSRestoreInterrupts(savedInterrupts);

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
        __DVDStateReady();                  /* start the next queued command */
        return;
    }

    interrupts = OSDisableInterrupts();
    /* a new log entry: code 0x27, no parameters, taken now */
    if (*(volatile u32 *)&errorLogCount >= 5)
        *(volatile u32 *)&errorLogCount = 0;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x27;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
    *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
    *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
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
    __DVDStateReady();
}

/* After a DVD error code is stored, re-arm the drive with a low-level command,
 * using the fatal-command handler fn_80035B88 as its completion callback. */
void fn_80035C64(void) {
    DVDLowRawReadAsync(0, 0, fn_80035B88);
}

extern s32 lbl_8055D890;
#pragma small_data off
extern __declspec(section ".data") u8 lbl_8037B580;
#pragma small_data on
extern s32 fn_8003BE40(void);
extern s32 lbl_8055D880;
extern void __DVDHandleCoverRegister(void);
extern void fn_8003BB58(void (*callback)(void));
extern void fn_8003B380(s32);
extern void fn_8003B38C(void *);
extern void fn_80035B88(u32);
  extern s32 lbl_8055D8AC;
extern s32 lbl_8055D85C;
#define NoResetRetry lbl_8055D8AC /* set for commands retried without a drive reset */
/* Completion callback for saving a DVD error log to NAND: re-arm the drive by
 * clearing the pending command and queueing a fresh transaction with the fatal
 * handler, then clear the retry and target drive-state flags. */
void fn_80035C78(void) {
    fn_8003B380(0);
    fn_8003B38C(fn_80035B88);
    NoResetRetry = 0;
    StateToChange = 0;
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
    /* Record a DVD error (command 0x10) in the next __ErrorInfo slot, then invoke DVDLowRawReadAsync with callback __DVDHandleDriveError. */
    s32 enabled;
    u32 tick;
    u8 *info;
    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount >= 5) {
        *(volatile u32 *)&errorLogCount = 0;
    }
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x10;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
    OSRestoreInterrupts(enabled);
    DVDLowRawReadAsync(0, 0, __DVDHandleDriveError);
    #pragma unused(arg0)
}

/* Cancel the executing command if a cancel is pending: report it as
 * canceled to its callback and the cancel callback, then go idle. */
static inline BOOL CheckCancel(u32 resume) {
    void *finished;
    void (*callback)(s32, void *);

    if (lbl_8055D858 != 0) {
        lbl_8055D85C = resume;
        lbl_8055D858 = 0;
        finished = (void *)executing_8055D8C8;
        executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
        *(s32 *)((char *)finished + 0xC) = 0xA;
        callback = *(void (**)(s32, void *))((u8 *)finished + 0x28);
        if (callback != 0)
            callback(-3, finished);
        if (lbl_8055D8B8 != 0)
            lbl_8055D8B8(0, finished);
        __DVDStateReady();
        return TRUE;
    }
    return FALSE;
}

/* Start the periodic motor-check alarm (every 100 ms) unless already armed. */
static inline void StartMotorAlarm(void) {
    u32 tick;
    u32 period;

    if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
        lbl_8055D870 = 1;
        OSCreateAlarm(&lbl_80376AD0);
        tick = OSGetTick();
        period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
        OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period,
                           fn_8003801C);
    }
}

/* Handle a drive error by its category byte: motor stopped / cover opened /
 * no disk (start the motor-check alarm), cover closed (re-read the disk ID),
 * anything else is reported as an unrecoverable error. */
static inline void HandleErrorCategory(u32 kind, u32 error) {
    if (kind == 0x01000000) {
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 5;
        MotorState_8055D8A8 = 1;
        StartMotorAlarm();
    } else if (kind == 0x02000000) {
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 3;
        fn_8003773C();
    } else if (kind == 0x03000000) {
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 4;
        MotorState_8055D8A8 = 1;
        StartMotorAlarm();
    } else if (kind == 0) {
        if (error - 0x00050000 == 0x3000) {
            fn_800356F4(0x10, 0, 0);
            DVDLowRawReadAsync(0, 0, (void *)__DVDHandleMotorError);
        } else {
            fn_8003A1A0(0x1234567, fn_80035C64);
        }
    } else {
        fn_8003A1A0(0x1234567, fn_80035C64);
    }
}

/* Log a cover-closed error and re-read the disk ID through __DVDHandleMotorError. */
static inline void StateCoverClosed(void) {
    s32 interrupts;
    u8 *info;
    u32 tick;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount >= 5) {
        *(volatile u32 *)&errorLogCount = 0;
    }
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x10;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
    OSRestoreInterrupts(interrupts);
    DVDLowRawReadAsync(0, 0, (void *)__DVDHandleMotorError);
}

#pragma dont_inline off
void fn_80035E6C(u32 arg0) {
    s32 taskType;
    u32 kind;
    s32 firstInterrupts;
    u32 status;
    s32 code;
    u32 tick;
    u32 period;

    firstInterrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0)
        *(u32 *)(__ErrorInfo + 0x78) = arg0;
    else
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = arg0;
    OSRestoreInterrupts(firstInterrupts);

    if (arg0 == 0x10) { fn_8003A1A0(0x1234568, fn_80035C78); return; }
    if (arg0 == 0x20) { fn_8003A1A0(0x1234569, fn_80035C78); return; }
    if (arg0 & 2) { fn_8003A1A0(0x1234567, fn_80035C64); return; }

    taskType = ((s32 (*)(void))fn_8003BCC0)();
    kind = taskType & 0xFF000000;
    status = ((u32 (*)(u32))fn_80035CB4)(taskType);
    if (status == 1) { fn_8003A1A0(taskType, fn_80035C64); return; }
    if ((u32)(status - 2) <= 1) {
        code = 0;
    } else if (kind == 0x01000000) {
        code = 4;
    } else if (kind == 0x02000000) {
        code = 6;
    } else if (kind == 0x03000000) {
        code = 3;
    } else if (kind == 0) {
        if ((u32)(taskType - 0x00050000) == 0x3000) code = 1; else code = 5;
    } else {
        code = 5;
    }

    if (CheckCancel(code)) return;

    if (status == 2) { fn_8003A1A0(taskType, (void (*)(void))fn_80035DA8); return; }
    if (status == 3) {
        if ((u32)((taskType & 0x00FFFFFF) - 0x00030000) == 0x1100) {
            fn_800356F4(2, *(u32 *)((char *)executing_8055D8C8 + 0x10), 0);
            DVDLowSeekAsync(*(u32 *)((char *)executing_8055D8C8 + 0x10), (void *)__DVDHandleError);
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
            OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period, fn_8003801C);
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
            OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period, fn_8003801C);
        }
        return;
    }
    if (kind == 0) {
        if ((u32)(taskType - 0x00050000) == 0x3000) {
            register s32 localInterrupts;
            u8 *localInfo;
            u32 localTick;
            localInterrupts = OSDisableInterrupts();
            if (*(volatile u32 *)&errorLogCount >= 5)
                *(volatile u32 *)&errorLogCount = 0;
            localInfo = (u8 *)__ErrorInfo;
            *(s32 *)(localInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x10;
            *(s32 *)(localInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
            *(s32 *)(localInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
            localTick = OSGetTick();
            *(s32 *)(localInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = localTick;
            *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
            OSRestoreInterrupts(localInterrupts);
            DVDLowRawReadAsync(0, 0, (void *)__DVDHandleMotorError);
            return;
        }
        fn_8003A1A0(0x1234567, fn_80035C64);
        return;
    }
    fn_8003A1A0(0x1234567, fn_80035C64);
}
extern void fn_80036550(u32);
/* Record a DVD error in the __ErrorInfo ring and dispatch the appropriate drive recovery. */ void __DVDHandleError(u32 arg0) {
    register u32 errorCode = arg0;
    s32 interrupts;
    u32 tick;
    u8 *info;

    /* Record DVD error info into __ErrorInfo ring and dispatch recovery based on error code. */
    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0)
        *(u32 *)(__ErrorInfo + 0x78) = errorCode;
    else
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = errorCode;
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
        if (*(volatile u32 *)&errorLogCount >= 5)
            *(volatile u32 *)&errorLogCount = 0;
        info = (u8 *)__ErrorInfo;
        *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x10;
        *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
        *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
        tick = OSGetTick();
        *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;
        *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
        OSRestoreInterrupts(interrupts);
        DVDLowRawReadAsync(0, 0, __DVDHandleDriveError);
        return;
    }

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount >= 5)
        *(volatile u32 *)&errorLogCount = 0;
    info = (u8 *)__ErrorInfo;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x27;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
    tick = OSGetTick();
    *(s32 *)(info + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;
    *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
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
    if (*(volatile u32 *)&errorLogCount == 0) *(u32 *)(__ErrorInfo + 0x78) = code;
    else *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = code;
    OSRestoreInterrupts(interrupts);

    if (code == 0x10) fn_8003A1A0(0x1234568, fn_80035C78);
    else if (code == 0x20) fn_8003A1A0(0x1234569, fn_80035C78);
    else if (code & 2) fn_8003A1A0(0x1234567, fn_80035C64);
    else ((void (*)(void *, void (*)(void)))fn_8003A1A0)(((void *(*)(void))fn_8003BCC0)(), fn_80035C64);
}
#pragma pop

/* Drive error handler run on the DVD thread (queued through DVDLowRawReadAsync with the
 * error code as its argument).  The code goes into the last __ErrorInfo entry;
 * the codes the NAND error report of fn_8003A1A0 deals with end the handling
 * here, and any other code finishes the cancel that is in flight: the command
 * the drive was running is completed with DVD_RESULT_CANCELED.  When nothing
 * was being cancelled the dummy block is marked as needing attention instead
 * and the periodic cover/motor poll is armed. */
/* Handle a DVD drive error on the DVD thread: record the code, finish any in-flight cancel, or arm the periodic disk-error/cover poll. */ void __DVDHandleDriveError(s32 errorCode) {
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
        __DVDStateReady();
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
extern s32 DVDLowUnencryptedReadAsync(void *, s32, s32, u32);
extern void __DVDHandleCommandStatus(u32);
extern char lbl_80376B20[];
extern char lbl_80376B40[];
extern u32 *lbl_8055D89C;
extern void fn_80036D24(u32);
extern void __DVDHandleMotorError(u32);
extern int memcmp(const void *, const void *, u32);
void fn_8003684C(void) {
    s32 enabled;
    u8 *idBase = lbl_80376A80;
#define LOG_ENTRY(a, b, c)                                                                      \
    {                                                                                           \
        u32 tick;                                                                               \
        enabled = OSDisableInterrupts();                                                        \
        if (*(volatile u32 *)&errorLogCount >= 5) *(volatile u32 *)&errorLogCount = 0;           \
        *(s32 *)((u8 *)__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = (a);      \
        *(s32 *)((u8 *)__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = (b);      \
        *(s32 *)((u8 *)__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = (c);      \
        tick = OSGetTick();                                                                     \
        *(s32 *)((u8 *)__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = tick;     \
        *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;                   \
        OSRestoreInterrupts(enabled);                                                           \
    }
    switch (lbl_8055D8BC) {
    case 3:
        lbl_8055D87C = 0;
        if (DVDCompareDiskID(idBase + 0x80,
                *(void **)(executing_8055D8C8 + 0x24)) != 0) {
            memcpy((void *)IDShouldBe_8055D8C4, idBase + 0x80, 0x20);
            *(s32 *)(executing_8055D8C8 + 0xC) = 1;
            DCInvalidateRange(idBase, 0x20);
            lbl_8055D860 = 0;
            fn_8003BCDC(0);
            LOG_ENTRY(0x21, 0x10000, 0x20);
            DVDLowUnencryptedReadAsync(idBase + 0xA0, 0x20, 0x10000, (u32)__DVDHandleCommandStatus);
        } else {
            LOG_ENTRY(0x10, 0, 0);
            DVDLowRawReadAsync(0, 0, __DVDHandleMotorError);
        }
        break;
    default:
        if (memcmp(idBase + 0x80, (void *)IDShouldBe_8055D8C4, 0x20) != 0) {
            LOG_ENTRY(0x10, 0, 0);
            DVDLowRawReadAsync(0, 0, __DVDHandleMotorError);
        } else {
            lbl_8055D860 = 0;
            fn_8003BCDC(0);
            LOG_ENTRY(0x21, 0x10000, 0x20);
            DVDLowUnencryptedReadAsync(idBase + 0xA0, 0x20, 0x10000, (u32)__DVDHandleCommandStatus);
        }
        break;
    }
#undef LOG_ENTRY
}

#pragma push
#pragma dont_inline on
/* DVD low-level command callback: log the status into the error-info ring, then
 * start the matching NAND error report, recovery command, or motor reset. */
void __DVDHandleCommandStatus(u32 status) {
    s32 enabled;

    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 +
                 (*(volatile u32 *)&errorLogCount - 1) * 0x14) = status;
    }
    OSRestoreInterrupts(enabled);

    if (status == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
        return;
    }
    if (status == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
        return;
    }
    if (status & 1) {
        u8 *errorInfo;
        s32 savedIrq;

        lbl_8055D860 = 0;
        lbl_8055D89C = (u32 *)lbl_80376B20;
        fn_8003BCDC(0);

        savedIrq = OSDisableInterrupts();
        if (*(volatile u32 *)&errorLogCount >= 5)
            *(volatile u32 *)&errorLogCount = 0;
        errorInfo = (u8 *)__ErrorInfo;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x21;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0x10008;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0x20;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
        OSRestoreInterrupts(savedIrq);
        DVDLowUnencryptedReadAsync(lbl_80376B40, 0x20, 0x10008, (u32)fn_80036D24);
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
extern void handleDvdPartitionStatus(u32);
extern void fn_8003727C(u32);
extern void fn_8003801C(void);
extern void DVDLowOpenPartition(u32, u32, u32, u32, void *, void (*)(u32));
#pragma dont_inline on
void fn_80036D24(u32 arg0) {
    register s32 enabled;
    register u8 *base = lbl_80376A80;
    s32 value;
    s32 oldBlock;
    s32 result;

    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0)
        *(u32 *)(__ErrorInfo + 0x78) = arg0;
    else
        *(u32 *)(__ErrorInfo + 0x28 + (*(volatile u32 *)&errorLogCount - 1) * 0x14) = arg0;
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
        s32 idx32;
        u32 *freeEntry = 0;
        s16 index;
        lbl_8055D860 = 0;
        lbl_8055D898 = base + 0xC0;
        lbl_8055D894 = 0;
        for (index = 0; (idx32 = index), ((u32)idx32 < *lbl_8055D89C); index++) {
            if (((u32 *)lbl_8055D898)[1] == 0) {
                freeEntry = (u32 *)lbl_8055D898;
                lbl_8055D894 = (u32 *)lbl_8055D898;
            }
            lbl_8055D898 += 8;
        }

        if (freeEntry != 0) {
            switch (lbl_8055D8BC) {
            case 3:
                {
                    register s32 localEnabled;
                    u8 *logBase;
                    lbl_8055D860 = 0;
                    fn_8003BCDC(0);
                    value = *lbl_8055D894;
                    localEnabled = OSDisableInterrupts();
                    if (*(volatile u32 *)&errorLogCount >= 5)
                        errorLogCount = 0;
                    logBase = (u8 *)__ErrorInfo;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x22;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = value;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
                    errorLogCount = *(volatile u32 *)&errorLogCount + 1;
                    OSRestoreInterrupts(localEnabled);
                    DVDLowOpenPartition(*lbl_8055D894, 0, 0, 0, base + 0x100, handleDvdPartitionStatus);
                }
                return;
            default:
                {
                    u8 *logBase;
                    register s32 localEnabled;
                    lbl_8055D860 = 0;
                    fn_8003BCDC(0);
                    value = *lbl_8055D894;
                    localEnabled = OSDisableInterrupts();
                    if (*(volatile u32 *)&errorLogCount >= 5)
                        errorLogCount = 0;
                    logBase = (u8 *)__ErrorInfo;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x22;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = value;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
                    *(s32 *)(logBase + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
                    errorLogCount = *(volatile u32 *)&errorLogCount + 1;
                    OSRestoreInterrupts(localEnabled);
                    DVDLowOpenPartition(*lbl_8055D894, 0, 0, 0, base + 0x100, fn_8003727C);
                }
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
            __DVDStateReady();
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
            period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
            OSSetPeriodicAlarm(base + 0x50, 0x10624DD3, 0, value, 0, period, fn_8003801C);
        }
        return;
    }

    fn_800356F4(0x27, 0, 0);
    fn_8003B218(fn_80035E6C);
}

extern void onDiscHeaderReadComplete(u32);
/* DVD low-level open-partition status callback: log the status in the error-info ring and dispatch the matching recovery path. */
void handleDvdPartitionStatus(u32 errorCode) {
    register u32 status = errorCode;
    s32 savedInterrupts;
    u8 *errorInfo;
    u32 timestamp;

    savedInterrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 +
                 (*(volatile u32 *)&errorLogCount - 1) * 0x14) = status;
    }
    OSRestoreInterrupts(savedInterrupts);

    if (status == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (status == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (status & 1) {
        lbl_8055D860 = 0;
        fn_8003BCDC(0);
        savedInterrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&errorLogCount >= 5)
            *(volatile u32 *)&errorLogCount = 0;
        errorInfo = (u8 *)__ErrorInfo;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 1;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0x108;
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0x20;
        timestamp = OSGetTick();
        *(s32 *)(errorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = timestamp;
        *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
        OSRestoreInterrupts(savedInterrupts);
        DVDLowReadAsync(lbl_80376A80, 0x20, 0x108, (s32)onDiscHeaderReadComplete);
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

    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = diStatus;
    } else {
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = diStatus;
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
            __DVDStateReady();
            resetHandled = 1;
        } else {
            resetHandled = 0;
        }
        if (resetHandled == 0) {
            *(s32 *)((u8 *)executing_8055D8C8 + 0xC) = 1;
            __DVDStateBusy((void *)executing_8055D8C8);
        }
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}

/* DVD motor/error callback: records error state, handles special/reset cases, and either
 * cancels the executing command or schedules periodic motor-off via alarm. */
/* DVD motor/error callback: record the error state, handle special/reset codes, cancel the executing command with its completion callbacks when resetting, or schedule a periodic alarm to stop the motor when idle. */ void __DVDHandleMotorError(u32 arg0) {
    register u32 value = arg0;
    s32 interrupts;
    s32 resetDone;
    void *block;
    void (*callback)(s32, void *);
    u32 tick;
    u32 period;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = value;
    } else {
        *(u32 *)(__ErrorInfo +
                 *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = value;
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
        __DVDStateReady();
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
/* Completion callback for the disc-header read: log the drive status, then re-issue the boot-data read on cancel/odd status or queue a fatal drive reset otherwise. */ void onDiscHeaderReadComplete(u32 statusCode) {
    register u32 status = statusCode;
    s32 interrupts;

    /* Completion callback for the small disc-header read issued by handleDvdPartitionStatus:
     * log the drive status in the error ring, then on a cancel/odd status re-issue
     * the boot-data read (its offset and length come from the header) and finish
     * through onBootDataReadComplete; otherwise log a fatal error and queue a drive reset. */
    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 + (*(volatile u32 *)&errorLogCount - 1) * 0x14) = status;
    }
    OSRestoreInterrupts(interrupts);

    if (status == 0x10) {
        fn_8003A1A0(0x1234568, fn_80035C78);
    } else if (status == 0x20) {
        fn_8003A1A0(0x1234569, fn_80035C78);
    } else if (status & 1) {
        u32 layoutShift;
        register u32 shiftedLength;
        register u32 readLength;
        register u32 rawLength;
        register u32 discOffset;

        lbl_8055D860 = 0;
        lbl_8055D8CC = (s32)startBootDataReadAsync;
        if (*(u32 *)((u8 *)bootInfo_8055D8C0 + 0x3C) < *(u32 *)(lbl_80376A80 + 8)) {
            ((void (*)(const char *, s32, const char *, ...))OSPanic)(lbl_80558E0C, 0x3F6, lbl_80302120);
        }
        fn_8003BCDC(0);
        layoutShift = *(volatile u32 *)&__DVDLayoutFormat;
        shiftedLength = (*((u32 *) (lbl_80376A80 + 8))) << ((~(*((volatile u32 *) (&__DVDLayoutFormat)))) & 2);
        rawLength = *((u32 *) (lbl_80376A80 + 4));
        discOffset = rawLength >> layoutShift;
        readLength = (shiftedLength + 0x1F) & (~0x1F);
        ((void (*)(s32, s32, s32, u32, u32)) fn_800356F4)(1, (unsigned long long) discOffset, readLength, layoutShift, rawLength);
        DVDLowReadAsync(*((void **) (((u8 *) bootInfo_8055D8C0) + 0x38)), (((*((u32 *) (lbl_80376A80 + 8))) << ((~(*((volatile u32 *) (&__DVDLayoutFormat)))) & 2)) + 0x1F) & (~0x1F), (*((u32 *) (lbl_80376A80 + 4))) >> (*((volatile u32 *) (&__DVDLayoutFormat))), (s32) onBootDataReadComplete);
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}
#pragma pop
extern s32 MotorState_8055D8A8;
extern s32 lbl_8055D8BC;
extern void __DVDClearWaitingQueue(void);
extern void __DVDStateBusy(void *);
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
        __DVDStateReady();
        break;
    }
    case 32:
        MotorState_8055D8A8 = 0;
    case 35: case 36: case 37:
        *(s32 *)((char *)executing_8055D8C8 + 0xC) = 1;
        __DVDStateBusy((void *)executing_8055D8C8);
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

/* Initializes the DVD error path for the current boot code: picks the platform's error callback, records a fresh error entry in __ErrorInfo, then starts the matching error transfer/callback. */ void DVDInitErrorPath(void) {
    /* Initializes a platform-specific error path, logging an error record and starting the corresponding transfer/callback. */
    s32 savedInterrupts;

    if (*(u16 *)0x800030E6 == 0x8003) {
        lbl_8055D8CC = (s32)fn_80037A8C;
        fn_8003BCDC(0);

        savedInterrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&errorLogCount >= 5)
            *(volatile u32 *)&errorLogCount = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 0x25;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&errorLogCount =
            *(volatile u32 *)&errorLogCount + 1;
        OSRestoreInterrupts(savedInterrupts);
        fn_8003B69C(0x20000, __DVDRecordStatusEvent);
    } else {
        DCInvalidateRange(lbl_80376B00, 0x20);
        lbl_8055D8CC = (s32)fn_80037CEC;
        fn_8003BCDC(0);

        savedInterrupts = OSDisableInterrupts();
        if (*(volatile u32 *)&errorLogCount >= 5)
            *(volatile u32 *)&errorLogCount = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 5;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0x20;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&errorLogCount =
            *(volatile u32 *)&errorLogCount + 1;
        OSRestoreInterrupts(savedInterrupts);
        DVDLowAsyncIoctl(lbl_80376B00, fn_80037DBC);
    }
}

extern s32 lbl_8055D8A0;
extern u32 lbl_8055D8A4;

extern void OSSetAlarm(void *, u64, u32, void (*)(void));
extern u64 __OSGetSystemTime(void);
extern void DVDInitErrorPath(void);
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
        ((void (*)(void *, u32, u32, u32, void (*)(void)))OSSetAlarm)(&lbl_8037B580, 0x10624DD3, 0, alarmTicks, DVDInitErrorPath);
    } else {
        fn_800356F4(0x27, 0, 0);
        fn_8003B218(fn_80035E6C);
    }
}
#pragma pop
extern s32 fn_8003BCDC(s32);
extern void fn_8003B69C(u32, void*);
extern void __DVDRecordStatusEvent(u32);
void fn_80037A8C(void) {
    /* Request a DVD cover-interrupt clear, log error command 0x25 into the next
     * __ErrorInfo slot, then configure DVD audio buffering and continue via
     * __DVDRecordStatusEvent. */
    s32 enabled;
    u8 *base;
    fn_8003BCDC(0);
    enabled = OSDisableInterrupts();
    if (errorLogCount >= 5) errorLogCount = 0;
    base = (u8*)__ErrorInfo;
    *(s32*)(base + (*(volatile u32*)&errorLogCount) * 0x14 + 0x1C) = 0x25;
    *(s32*)(base + (*(volatile u32*)&errorLogCount) * 0x14 + 0x20) = 0;
    *(s32*)(base + (*(volatile u32*)&errorLogCount) * 0x14 + 0x24) = 0;
    *(s32*)(base + (*(volatile u32*)&errorLogCount) * 0x14 + 0x2C) = OSGetTick();
    errorLogCount = (*(volatile u32*)&errorLogCount) + 1;
    OSRestoreInterrupts(enabled);
    fn_8003B69C(0x20000, __DVDRecordStatusEvent);
}

#pragma push
#pragma dont_inline on
/* Record a DVD/error status event in the error-info table and dispatch the
 * matching follow-up action: a direct callback for the two special codes, an
 * async error-info read for the low-bit case, or the generic error path. */
void __DVDRecordStatusEvent(u32 status_code) {
    register s32 saved_interrupts_async;
    s32 saved_interrupts;

    saved_interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = status_code;
    } else {
        *(u32 *)(__ErrorInfo + 0x28 +
                 (*(volatile u32 *)&errorLogCount - 1) * 0x14) = status_code;
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
        if (*(volatile u32 *)&errorLogCount >= 5)
            *(volatile u32 *)&errorLogCount = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x1C) = 5;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x20) = 0;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x24) = 0x20;
        *(s32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x2C) = OSGetTick();
        *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
        OSRestoreInterrupts(saved_interrupts_async);
        DVDLowAsyncIoctl(lbl_80376B00, fn_80037DBC);
        return;
    }

    fn_800356F4(0x27, 0, 0);
    fn_8003B218(fn_80035E6C);
}
#pragma pop

extern void DVDLowAsyncIoctl(void *, void *);
extern char lbl_80376B00[];
extern void fn_80037DBC(u32);
/* Schedules an async DVD error info read by recording an error entry and starting the read callback chain. */
void fn_80037CEC(void) {
    s32 enabled;
    u8 *base;
    fn_8003BCDC(0);
    enabled = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount >= 5)
        errorLogCount = 0;
    base = (u8 *)__ErrorInfo;
    *(s32 *)(base + (*(volatile u32 *)&errorLogCount) * 0x14 + 0x1C) = 5;
    *(s32 *)(base + (*(volatile u32 *)&errorLogCount) * 0x14 + 0x20) = 0;
    *(s32 *)(base + (*(volatile u32 *)&errorLogCount) * 0x14 + 0x24) = 0x20;
    *(s32 *)(base + (*(volatile u32 *)&errorLogCount) * 0x14 + 0x2C) = OSGetTick();
    errorLogCount = (*(volatile u32 *)&errorLogCount) + 1;
    OSRestoreInterrupts(enabled);
    DVDLowAsyncIoctl(lbl_80376B00, fn_80037DBC);
}

#pragma push
#pragma scheduling invalid_target
#pragma dont_inline on
// Handle DVD command block callback status and dispatch appropriate action.
void fn_80037DBC(u32 status) {
    register u32 value = status;
    s32 interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = value;
    } else {
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = value;
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
/* Callback for the cover-register read: inspects cover/motor status and moves the DVD state machine between the cover-interrupt wait and the timeout alarm. */ void __DVDHandleCoverRegister(void) {
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

// Cover-poll alarm: if no cover-register read is in flight, mark one pending
// and queue it; its callback advances the drive's cover/motor state machine.
void fn_8003801C(void) {
    if (CoverRegPending != 0) {
        return;
    }
    CoverRegPending = 1;
    DVDLowPrepareCoverRegister(cbForCoverReg);
}

extern s32 __DVDCheckWaitingQueue(void);
extern void *__DVDPopWaitingQueue(void);

extern s32 lbl_8055D8B4, lbl_8055D878;
/* The driver's idle state: start the command at the head of the waiting queue.
 *
 * The block comes off the queue, becomes the one the driver is running, and is
 * handed to the drive state that fits it.  A resume point left over from an
 * earlier command (StateToChange) is finished first - the ones that stop the
 * motor arm the 100 ms cover poll (CoverAlarmHandler) unless something is
 * watching the cover already - and otherwise the motor's state decides between
 * the busy state and the cover-closed one.  Reset, inquiry and closing a
 * partition leave no resume point behind.  While the driver is paused the block
 * stays queued and PausingFlag says so; once the drive has hit a fatal error
 * every block is failed where it stands and the next one is taken in turn.
 * (The file calls this state stateReady.)
 */
/* The DVD driver's ready state: pop the next queued command block and dispatch it according to the pending resume point or the motor state. */ void __DVDStateReady(void) {
    void *block;
    void *failedBlock;
    void (*callback)(s32, void *);
    if (__DVDCheckWaitingQueue() == 0) {
        ExecutingBlock = 0; /* nothing queued: the driver is idle */
        return;
    }
    if (PauseFlag != 0) {
        PausingFlag_8055D850 = 1; /* the queue waits for DVDResume */
        ExecutingBlock = 0;
        return;
    }
    block = __DVDPopWaitingQueue();
    ExecutingBlock = (s32)block;
    if (FatalErrorFlag_8055D854 != 0) {
        /* the drive is done for: fail this block, then take in the next */
        *(s32 *)((u8 *)block + 0xC) = DVD_STATE_FATAL;
        failedBlock = (void *)ExecutingBlock;
        ExecutingBlock = (s32)DummyBlock;
        callback = *(void (**)(s32, void *))((u8 *)failedBlock + 0x28);
        if (callback != 0) callback(DVD_RESULT_FATAL_ERROR, failedBlock);
        stateReady();
        return;
    }
    *(volatile u32 *)&DriveCommand = *(u32 *)((u8 *)block + 8);
    if (((u32)*(volatile s32 *)&DriveCommand == COMMAND_RESET) ||
        ((u32)*(volatile s32 *)&DriveCommand == COMMAND_INQUIRY) ||
        ((u32)*(volatile s32 *)&DriveCommand == COMMAND_CLOSE_PARTITION)) StateToChange = 0;
    if (*(volatile s32 *)&StateToChange != 0) {
        /* an earlier command still owes the drive an answer: finish that */
        switch (*(volatile s32 *)&StateToChange) {
        case RESUME_POINT_DISK_ERROR: {
            s32 tick;
            *(s32 *)((u8 *)block + 0xC) = DVD_STATE_DISK_ERROR;
            MotorState_8055D8A8 = MOTOR_STATE_PENDING_STOP;
            if (Transferring == 0 && AlarmInfo == 0) {
                Transferring = 1;
                OSCreateAlarm(&StateAlarm);
                tick = OSGetTick();
                {
                    u32 timerBase = 0x80000000; /* where the OS keeps its clock */
                    u32 scaleHi = 0x10620000;
                    u32 timerClock = *(volatile u32 *)(timerBase + 0xF8);
                    void (*onExpired)(void) = CoverAlarmHandler;
                    u32 timeScale = scaleHi + 0x4DD3; /* 0x10624DD3 */
                    u32 period = ((timerClock >> 2) / 1000) * 0x64; /* 100 ms in ticks */
                    OSSetPeriodicAlarm(&StateAlarm, timeScale, 0, tick, 0, period, onExpired);
                }
            }
            break;
        }
        case RESUME_POINT_NO_DISK: {
            s32 tick;
            *(s32 *)((u8 *)block + 0xC) = DVD_STATE_NO_DISK;
            MotorState_8055D8A8 = MOTOR_STATE_PENDING_STOP;
            if (Transferring == 0 && AlarmInfo == 0) {
                Transferring = 1;
                OSCreateAlarm(&StateAlarm);
                tick = OSGetTick();
                {
                    u32 timerBase = 0x80000000; /* where the OS keeps its clock */
                    u32 scaleHi = 0x10620000;
                    u32 timerClock = *(volatile u32 *)(timerBase + 0xF8);
                    void (*onExpired)(void) = CoverAlarmHandler;
                    u32 timeScale = scaleHi + 0x4DD3; /* 0x10624DD3 */
                    u32 period = ((timerClock >> 2) / 1000) * 0x64; /* 100 ms in ticks */
                    OSSetPeriodicAlarm(&StateAlarm, timeScale, 0, tick, 0, period, onExpired);
                }
            }
            break;
        }
        case RESUME_POINT_COVER_OPENED: {
            s32 tick;
            *(s32 *)((u8 *)block + 0xC) = DVD_STATE_COVER_OPENED;
            MotorState_8055D8A8 = MOTOR_STATE_PENDING_STOP;
            if (Transferring == 0 && AlarmInfo == 0) {
                Transferring = 1;
                OSCreateAlarm(&StateAlarm);
                tick = OSGetTick();
                {
                    u32 timerBase = 0x80000000; /* where the OS keeps its clock */
                    u32 scaleHi = 0x10620000;
                    u32 timerClock = *(volatile u32 *)(timerBase + 0xF8);
                    void (*onExpired)(void) = CoverAlarmHandler;
                    u32 timeScale = scaleHi + 0x4DD3; /* 0x10624DD3 */
                    u32 period = ((timerClock >> 2) / 1000) * 0x64; /* 100 ms in ticks */
                    OSSetPeriodicAlarm(&StateAlarm, timeScale, 0, tick, 0, period, onExpired);
                }
            }
            break;
        }
        case RESUME_POINT_WRONG_DISK_ID:
        case RESUME_POINT_DISK_CHANGED:
        case RESUME_POINT_7:
            *(s32 *)((u8 *)block + 0xC) = DVD_STATE_COVER_CLOSED;
            stateCoverClosed();
            break;
        case RESUME_POINT_OK:
            __DVDStoreErrorCode(CancelLastError, cbForStoreErrorCode1);
            break;
        }
        StateToChange = 0;
        return;
    }
    switch (MotorState_8055D8A8) {
    case MOTOR_STATE_STOPPED:
        if (MotorStopped != 0) {
            *(s32 *)((u8 *)block + 0xC) = DVD_STATE_MOTOR_STOPPED;
            return;
        }
        *(s32 *)((u8 *)block + 0xC) = DVD_STATE_COVER_CLOSED;
        stateCoverClosed();
        return;
    case MOTOR_STATE_WORKING:
        *(s32 *)((u8 *)block + 0xC) = DVD_STATE_BUSY;
        stateBusy((void *)ExecutingBlock);
        return;
    default:
        stateCoverClosed();
        return;
    }
}

#pragma push
#pragma use_lmw_stmw off
extern void fn_80038870();
extern void DVDLowSeekAsync(u32, void *);
extern void fn_8003B508(u32, u32, void *);
extern void fn_8003B0B0(void *, void *);
extern void fn_8003AC24(void *);
extern void (*lbl_80558E08)(void *, void *);
#pragma push
#pragma use_lmw_stmw off
/* DVD low-level command completion handler (the driver's busy state). Logs
 * selected commands to the error-info ring buffer, then dispatches each one to
 * the matching DVDLow routine; long reads are split into 0x80000-byte chunks. */
/* Complete a DVD command in the driver's busy state: stamp interesting commands into the error-info ring, then issue the matching DVDLow call, splitting long reads into 0x80000-byte chunks. */ void __DVDStateBusy(void *block) {
 u8 *blockBytes = block;
 int offset;
 int length;
 int command;
 u32 transferSize;
 lbl_8055D8CC = (int)__DVDStateBusy;   /* LastState = stateBusy */
 command = *(int *)(blockBytes+8);
 switch (command) {                  /* StampCommand: log the interesting commands */
 case 2: case 3: case 5: case 13: case 14: case 15: case 16: case 34: case 37: {
   length = *(int *)(blockBytes+0x14); offset = *(int *)(blockBytes+0x10);
   {
 int irq = OSDisableInterrupts(); int tick;
 if (*(volatile u32 *)&errorLogCount >= 5) *(volatile u32 *)&errorLogCount = 0;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x1c) = command;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x20) = offset;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x24) = length;
 tick = OSGetTick();
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x2c) = tick;
 *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
 OSRestoreInterrupts(irq);
}
 } break;
 default: break;
 }
 switch (*(u32 *)(blockBytes+8)) {
 case 5:                             /* COMMAND_READID -> DVDLowReadDiskID */
   fn_8003BCDC(0);                   /* DVDLowClearCoverInterrupt(NULL) */
   *(int *)(blockBytes+0x1c) = 0x20; /* transferSize = sizeof(DVDDiskID) */
   DVDLowAsyncIoctl(*(void **)(blockBytes+0x18),fn_80038870); break;
 case 1: case 4:                     /* COMMAND_READ / COMMAND_BSREAD */
   if (*(int *)(blockBytes+0x14) == 0) {
     u8 *previousBlock = (u8 *)executing_8055D8C8;
     executing_8055D8C8 = (int)DummyCommandBlock_80376AA0;
     *(int *)(previousBlock+0xc) = 0; /* state = DVD_STATE_IDLE */
     if (*(void (**)(int))(previousBlock+0x28)) (*(void (**)(int))(previousBlock+0x28))(0);
     __DVDStateReady();                   /* stateReady() */
     break;
   }
   fn_8003BCDC(0);                   /* DVDLowClearCoverInterrupt(NULL) */
   {
     u32 remaining = *(u32 *)(blockBytes+0x14) - *(u32 *)(blockBytes+0x20);
     u32 stampOffset; int stampCommand;
     transferSize = 0x80000;         /* MAX_TRANSFER_SIZE */
     if (remaining <= transferSize) transferSize = remaining;
     *(u32 *)(blockBytes+0x1c) = transferSize;
     stampCommand = *(int *)(blockBytes+8);
     stampOffset = *(u32 *)(blockBytes+0x10) + (*(u32 *)(blockBytes+0x20) >> 2);
     {
 int irq = OSDisableInterrupts(); int tick;
 if (*(volatile u32 *)&errorLogCount >= 5) *(volatile u32 *)&errorLogCount = 0;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x1c) = stampCommand;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x20) = stampOffset;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x24) = transferSize;
 tick = OSGetTick();
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x2c) = tick;
 *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
 OSRestoreInterrupts(irq);
}
     /* DVDLowRead(addr+transferTotal, transferSize, offset+DVD_LOW_OFFSET(transferTotal), cbForStateBusy) */
     ((int (*)(void *, u32, u32, void *))DVDLowReadAsync)(*(u8 **)(blockBytes+0x18)+*(u32 *)(blockBytes+0x20), *(u32 *)(blockBytes+0x1c), *(u32 *)(blockBytes+0x10)+(*(u32 *)(blockBytes+0x20)>>2), fn_80038870);
   } break;
 case 2: fn_8003BCDC(0); DVDLowSeekAsync(*(u32 *)(blockBytes+0x10),fn_80038870); break;                  /* clear cover; DVDLowSeek */
 case 3: DVDLowRawReadAsync(0,0,fn_80038870); break;                                                       /* DVDLowStopMotor */
 case 15: DVDLowRawReadAsync(0,0,fn_80038870); break;                                                      /* DVDLowStopMotor */
 case 13: fn_8003BCDC(0); fn_8003B508(*(u32 *)(blockBytes+0x10),*(u32 *)(blockBytes+0x14),fn_80038870); break; /* DVDLowAudioBufferConfig */
 case 14: fn_8003BCDC(0); *(int *)(blockBytes+0x1c)=0x20; fn_8003B0B0(*(void **)(blockBytes+0x18),fn_80038870); break; /* DVDLowInquiry */
 case 16: fn_8003BCDC(0); DVDLowRawReadAsync(0,0,fn_80038870); break;                                      /* DVDLowStopMotor */
 case 34: fn_8003B380(1); fn_8003B38C(fn_80038870); break;                                          /* spin up; DVDLowReset */
 case 37:                            /* COMMAND_SET_MAX_ROTATION -> DVDLowUnencryptedRead */
   if (*(int *)(blockBytes+0x14) == 0) {
     u8 *previousBlock = (u8 *)executing_8055D8C8;
     executing_8055D8C8 = (int)DummyCommandBlock_80376AA0;
     *(int *)(previousBlock+0xc) = 0;
     if (*(void (**)(int))(previousBlock+0x28)) (*(void (**)(int))(previousBlock+0x28))(0);
     __DVDStateReady(); break;
   }
   fn_8003BCDC(0);
   {
     u32 remaining = *(u32 *)(blockBytes+0x14) - *(u32 *)(blockBytes+0x20);
     int stampCommand; u32 stampOffset;
     transferSize = 0x80000;
     if (remaining <= transferSize) transferSize = remaining;
     *(u32 *)(blockBytes+0x1c) = transferSize;
     stampCommand = *(int *)(blockBytes+8);
     stampOffset = *(u32 *)(blockBytes+0x10) + (*(u32 *)(blockBytes+0x20) >> 2);
     {
 int irq = OSDisableInterrupts(); int tick;
 if (*(volatile u32 *)&errorLogCount >= 5) *(volatile u32 *)&errorLogCount = 0;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x1c) = stampCommand;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x20) = stampOffset;
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x24) = transferSize;
 tick = OSGetTick();
 *(int *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 20 + 0x2c) = tick;
 *(volatile u32 *)&errorLogCount = *(volatile u32 *)&errorLogCount + 1;
 OSRestoreInterrupts(irq);
}
     ((void (*)(void *, u32, u32, void *))DVDLowUnencryptedReadAsync)(*(u8 **)(blockBytes+0x18)+*(u32 *)(blockBytes+0x20), *(u32 *)(blockBytes+0x1c), *(u32 *)(blockBytes+0x10)+(*(u32 *)(blockBytes+0x20)>>2), fn_80038870);
   } break;
 case 35: fn_8003BCDC(0); ((void (*)(u32, int, int, int, void *, void *))DVDLowOpenPartition)(*(u32 *)(blockBytes+0x10),0,0,0,*(void **)(blockBytes+0x18),fn_80038870); break; /* DVDLowClosePartition */
 case 36: fn_8003BCDC(0); fn_8003AC24(fn_80038870); break;
 case 32: fn_8003BB58((void (*)(void))fn_80038870); break;
 case 33: fn_8003BB58((void (*)(void))fn_80038870); break;
 case 38: fn_8003BCDC(0); fn_8003B69C(0x20000,fn_80038870); break;
 default: lbl_80558E08(block,fn_80038870); break;
 }
}

void fn_80038870(u32 arg0) {
#define CMD (*(volatile u32 *)&lbl_8055D8BC)
#define CMDN (*(u32 *)&lbl_8055D8BC)
    char *block;
    void *cbp;
    s32 flag;
    s32 cmd_valid;
    s32 interrupts;
    u32 tlow;
    u64 now, start;
    u32 result;

    interrupts = OSDisableInterrupts();
    if (*(volatile u32 *)&errorLogCount == 0) {
        *(u32 *)(__ErrorInfo + 0x78) = arg0;
    } else {
        *(u32 *)(__ErrorInfo + *(volatile u32 *)&errorLogCount * 0x14 + 0x14) = arg0;
    }
    OSRestoreInterrupts(interrupts);

    if (arg0 == 0x10) {
        fn_8003A1A0(0x01234568, &fn_80035C78);
        return;
    }
    if (arg0 == 0x20) {
        fn_8003A1A0(0x01234569, &fn_80035C78);
        return;
    }
    if (CMD == 3 || CMD == 0xF) {
        if (arg0 & 2) {
            fn_8003A1A0(0x01234567, &fn_80035C64);
            return;
        }
        *(volatile u32 *)&lbl_8055D860 = 0;
        if (CMD == 0xF) lbl_8055D8AC = 1;
        if (lbl_8055D858 != 0) {
            block = (char *)executing_8055D8C8;
            *(volatile u32 *)&lbl_8055D85C = 7;
            *(volatile u32 *)&lbl_8055D858 = 0;
            executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
            *(s32 *)(block + 0xC) = 0xA;
            cbp = *(void **)(block + 0x28);
            if (cbp != 0) ((void (*)(s32, void *))cbp)(-3, block);
            if (lbl_8055D8B8 != 0) lbl_8055D8B8(0, block);
            __DVDStateReady();
            flag = 1;
        } else flag = 0;
        if (flag == 0 && MotorState_8055D8A8 != 2U) {
            *(s32 *)((char *)executing_8055D8C8 + 0xC) = 7;
            MotorState_8055D8A8 = 1;
            if (lbl_8055D870 == 0 && lbl_8055D874 == 0) {
                lbl_8055D870 = 1;
                OSCreateAlarm(&lbl_80376AD0);
                {
                    s32 tick = OSGetTick();
                    u32 period = ((*(volatile u32 *)0x800000F8 >> 2) / 1000) * 100;
                    OSSetPeriodicAlarm(&lbl_80376AD0, 0x10624DD3, 0, tick, 0, period, fn_8003801C);
                }
            }
        }
    } else {
        if (CMDN == 1 || CMDN == 4 || CMDN == 5 || CMDN == 0x21 || CMDN == 0xE) cmd_valid = 1;
        else if (CMDN == lbl_80558E14) cmd_valid = 1;
        else cmd_valid = 0;
        if (cmd_valid) {
            s32 add = (arg0 & 9) ? *(s32 *)((char *)executing_8055D8C8 + 0x1C) : 0;
            *(s32 *)((char *)executing_8055D8C8 + 0x20) += add;
        }
        if (lbl_8055D86C != 0) {
            block = (char *)executing_8055D8C8;
            lbl_8055D86C = 0;
            lbl_8055D858 = 0;
            executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
            *(s32 *)(block + 0xC) = 0xA;
            cbp = *(void **)(block + 0x28);
            if (cbp != 0) ((void (*)(s32, void *))cbp)(-3, block);
            if (lbl_8055D8B8 != 0) lbl_8055D8B8(0, block);
            __DVDStateReady();
            return;
        }
        if (arg0 & 1) {
            *(volatile u32 *)&lbl_8055D860 = 0;
            if (CMD == 0x10) {
                block = (char *)executing_8055D8C8;
                MotorState_8055D8A8 = (*(u32 *)(block + 0x10) != 0) + 1;
                executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                *(s32 *)(block + 0xC) = 0;
                cbp = *(void **)(block + 0x28);
                if (cbp != 0) ((void (*)(s32, void *))cbp)(0, block);
                __DVDStateReady();
                return;
            }
            if (CMD == 0x20) {
                now = __OSGetSystemTime();
                block = (char *)executing_8055D8C8;
                lbl_8055D8A4 = (u32)now;
                lbl_8055D8A0 = (u32)(now >> 32);
                lbl_8055D8AC = 0;
                lbl_8055D85C = 0;
                executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                *(s32 *)(block + 0xC) = 0;
                cbp = *(void **)(block + 0x28);
                if (cbp != 0) ((void (*)(s32, void *))cbp)(0, block);
                __DVDStateReady();
                return;
            }
            if (lbl_8055D858 != 0) {
                block = (char *)executing_8055D8C8;
                lbl_8055D85C = 0;
                lbl_8055D858 = 0;
                executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                *(s32 *)(block + 0xC) = 0xA;
                cbp = *(void **)(block + 0x28);
                if (cbp != 0) ((void (*)(s32, void *))cbp)(-3, block);
                if (lbl_8055D8B8 != 0) lbl_8055D8B8(0, block);
                __DVDStateReady();
                flag = 1;
            } else flag = 0;
            if (flag == 0) {
                if (CMD == 0x26) {
                    result = fn_8003BB48();
                    now = __OSGetSystemTime();
                    start = ((u64)(u32)lbl_8055D8A0 << 32) | (u32)lbl_8055D8A4;
                    tlow = ((*(u32 *)0x800000F8 >> 2) / 1000) * 100;
                    if ((s64)(now - start) >= (s64)tlow) flag = 0;
                    else flag = 2 - (s32)(result & 1);
                    block = (char *)executing_8055D8C8;
                    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                    *(s32 *)(block + 0xC) = 0;
                    *(s32 *)(block + 0x10) = flag;
                    cbp = *(void **)(block + 0x28);
                    if (cbp != 0) ((void (*)(void))cbp)();
                    __DVDStateReady();
                    return;
                }
                if (CMD == 0x24) {
                    result = fn_8003BB48();
                    if (((result >> 2) & 1) || (result & 1)) flag = 0;
                    else flag = (lbl_8055D85C == 0);
                    block = (char *)executing_8055D8C8;
                    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                    *(s32 *)(block + 0xC) = 0;
                    *(s32 *)(block + 0x10) = flag;
                    cbp = *(void **)(block + 0x28);
                    if (cbp != 0) ((void (*)(void))cbp)();
                    __DVDStateReady();
                    return;
                }
                if (CMDN == 1 || CMDN == 4 || CMDN == 5 || CMDN == 0x21 || CMDN == 0xE) cmd_valid = 1;
                else if (CMDN == lbl_80558E14) cmd_valid = 1;
                else cmd_valid = 0;
                if (cmd_valid) {
                    block = (char *)executing_8055D8C8;
                    if (*(u32 *)(block + 0x20) != *(u32 *)(block + 0x14)) {
                        __DVDStateBusy(block);
                        return;
                    }
                    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                    *(s32 *)(block + 0xC) = 0;
                    cbp = *(void **)(block + 0x28);
                    if (cbp != 0) ((void (*)(s32, void *))cbp)(*(s32 *)(block + 0x20), block);
                    __DVDStateReady();
                    return;
                }
                if ((u32)(CMDN - 9) <= 3) cmd_valid = 1;
                else if (CMDN == *(const u32 *)(lbl_8030228C + 0)) cmd_valid = 1;
                else if (CMDN == *(const u32 *)(lbl_8030228C + 4)) cmd_valid = 1;
                else if (CMDN == *(const u32 *)(lbl_8030228C + 8)) cmd_valid = 1;
                else cmd_valid = 0;
                if (cmd_valid) {
                    u32 arg;
                    if ((u32)(CMDN - 0xA) <= 1) arg = ((s32 (*)(void))fn_8003BCC0)() << 2;
                    else arg = ((s32 (*)(void))fn_8003BCC0)();
                    block = (char *)executing_8055D8C8;
                    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                    *(s32 *)(block + 0xC) = 0;
                    cbp = *(void **)(block + 0x28);
                    if (cbp != 0) ((void (*)(u32, void *))cbp)(arg, block);
                    __DVDStateReady();
                    return;
                }
                block = (char *)executing_8055D8C8;
                executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                *(s32 *)(block + 0xC) = 0;
                cbp = *(void **)(block + 0x28);
                if (cbp != 0) ((void (*)(s32, void *))cbp)(0, block);
                __DVDStateReady();
            }
        } else {
            if (CMD == 0xE) {
                fn_8003A1A0(0x01234567, &fn_80035C64);
                return;
            }
            block = (char *)executing_8055D8C8;
            if ((CMD == 1 || CMD == 4 || CMD == 5 || CMD == 0x21 || CMD == 0xE) &&
                *(u32 *)(block + 0x20) == *(u32 *)(block + 0x14)) {
                if (lbl_8055D858 != 0) {
                    lbl_8055D85C = 0;
                    lbl_8055D858 = 0;
                    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                    *(s32 *)(block + 0xC) = 0xA;
                    cbp = *(void **)(block + 0x28);
                    if (cbp != 0) ((void (*)(s32, void *))cbp)(-3, block);
                    if (lbl_8055D8B8 != 0) lbl_8055D8B8(0, block);
                    __DVDStateReady();
                    flag = 1;
                } else flag = 0;
                if (flag == 0) {
                    block = (char *)executing_8055D8C8;
                    executing_8055D8C8 = (s32)DummyCommandBlock_80376AA0;
                    *(s32 *)(block + 0xC) = 0;
                    cbp = *(void **)(block + 0x28);
                    if (cbp != 0) ((void (*)(s32))cbp)(*(s32 *)(block + 0x20));
                    __DVDStateReady();
                }
            } else {
                fn_800356F4(0x27, 0, 0);
                fn_8003B218(fn_80035E6C);
            }
        }
    }
#undef CMD
#undef CMDN
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
        __DVDStateReady();
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
        __DVDStateReady();
    }
    OSRestoreInterrupts(enabled);
    return result;
}
#pragma opt_propagation reset
extern u8 lbl_8037B5B0;
extern s32 __DVDGetNextWaitingQueue(void);
extern __declspec(section ".data") u8 lbl_8037B5B0;
/* Report a DVD command block's state from its volatile field at block+0xC:
 * cover-closed (3) reads as busy (1), cover-open (5) as no-disk (4), and the
 * root block reads busy while it is queued but not yet executing. The whole
 * read runs with interrupts disabled. */
s32 DVDGetCommandBlockStatus(void *block) {
    s32 state;
    s32 enabled = OSDisableInterrupts();
    if (*(volatile s32 *)((u8 *)block + 0xC) == 3) {
        state = 1;
    } else if (*(volatile s32 *)((u8 *)block + 0xC) == 5) {
        state = 4;
    } else if ((u32)executing_8055D8C8 == (u32)&lbl_8037B5B0) {
        s32 next = __DVDGetNextWaitingQueue();
        if (next != 0) {
            if ((u32)block == (u32)next) state = 1;
            else state = *(volatile s32 *)((u8 *)block + 0xC);
        } else if ((u32)block == (u32)&lbl_8037B5B0) {
            state = 0;
        } else {
            state = *(volatile s32 *)((u8 *)block + 0xC);
        }
    } else {
        state = *(volatile s32 *)((u8 *)block + 0xC);
    }
    OSRestoreInterrupts(enabled);
    return state;
}

/* Return the current DVD drive status: fatal error (-1), paused (8), idle (0)
 * when nothing is executing or only the dummy block is active, otherwise the
 * status of the currently executing command block. Checked with interrupts
 * disabled. */
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

/* Set the DVD cache-invalidation flag and return its previous value. */
s32 fn_800393C4(s32 value) {
    s32 old;

    old = lbl_80558E04;
    lbl_80558E04 = value;
    return old;
}

#pragma opt_propagation off
void fn_800393D4(void) {
    /* DVDResume: with interrupts off, clear the drive's pause flags and restart the
       waiting command queue if it was paused. */
    s32 enabled = OSDisableInterrupts();
    s32 zero = enabled ^ enabled;
    *(volatile s32 *)&PauseFlag = zero;
    if (PausingFlag_8055D850 != 0) {
        PausingFlag_8055D850 = zero;
        stateReady();
    }
    OSRestoreInterrupts(enabled);
}
#pragma opt_propagation reset
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
/* Cancel a DVD command block asynchronously, optionally invoking a callback, without waiting for the drive to finish. */ s32 DVDCancelAsyncCore(DVDCommandBlock *block, void (*callback)(s32, void *)) {
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
                __DVDStateReady();
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
        __DVDStateReady();
        break;
    case DVD_STATE_MOTOR_STOPPED:
        ExecutingBlock = (s32)DummyBlock;
        block->state = DVD_STATE_CANCELED;
        if (block->callback) block->callback(DVD_RESULT_CANCELED, block);
        if (callback) callback(DVD_RESULT_GOOD, block);
        __DVDStateReady();
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
    if (((s32 (*)(void *, void *))DVDCancelAsyncCore)(block, (void *)fn_80039838) == 0)
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

/* RVL SDK DVD cbForCancelSync (dvdcancel.c): the cancel-completion callback
 * DVDCancel hands to DVDCancelAsync(DVDCancelAsyncCore).  The driver calls it once the
 * cancel has landed, waking the thread that is sleeping on __DVDThreadQueue
 * waiting for the command block to reach a terminal state. */
void fn_80039838(void) {
    OSWakeupThread(__DVDThreadQueue);
}

s32 fn_80039840(void) {
    /* RealName: DVDCancelAll (RVL SDK DVD.cpp, source/os/dvd/dvdcancel.c).
     * Pause the drive, cancel every command still on the waiting queue and the
     * one the drive is running, then sleep on the DVD thread queue until
     * cbForCancel reports the cancel done.  Returns 0 once everything is
     * cancelled, -1 when the executing command refused to be cancelled. */
    BOOL success;             // DVDCancelAsync's answer for the executing block
    s32 intStatus;            // interrupts kept off for the whole cancel
    s32 enabled;              // interrupts as this function found them
    s32 pauseEnabled;         // the inlined DVDPause()/DVDResume()'s own save
    DVDCommandBlock *block;   // command taken off the waiting queue

    enabled = OSDisableInterrupts();
    isCancelDone = FALSE;

    intStatus = OSDisableInterrupts();

    // DVDPause(), inlined by the compiler
    pauseEnabled = OSDisableInterrupts();
    PauseFlag = TRUE;
    if (ExecutingBlock == 0) {
        PausingFlag_8055D850 = TRUE;
    }
    OSRestoreInterrupts(pauseEnabled);

    // Nothing queued may survive the cancel, so queued blocks get no callback.
    while ((block = __DVDPopWaitingQueue()) != NULL) {
        DVDCancelAsync(block, NULL);
    }

    if (ExecutingBlock != 0) {
        success = DVDCancelAsync((DVDCommandBlock *)ExecutingBlock,
                                 (void (*)(s32, void *))cbForCancel);
    } else {
        // Nothing was running, so the cancel is already over.
        success = TRUE;
        if (&cbForCancel != NULL) { // a function of this file: always true
            isCancelDone = TRUE;
            OSWakeupThread(__DVDThreadQueue);
        }
    }

    // DVDResume(), inlined; stateReady() is left as a call
    pauseEnabled = OSDisableInterrupts();
    *(volatile s32 *)&PauseFlag = FALSE;
    if (PausingFlag_8055D850 != 0) {
        PausingFlag_8055D850 = 0;
        stateReady();
    }
    OSRestoreInterrupts(pauseEnabled);
    OSRestoreInterrupts(intStatus);

    if (!success) {
        OSRestoreInterrupts(enabled);
        return -1;
    }

wait_loop: // the test stays on top: CW must not rotate this into a do-while
    if (isCancelDone != 0)
        goto wait_done;
    OSSleepThread(__DVDThreadQueue); // cbForCancel wakes this thread up
    goto wait_loop;
wait_done:
    OSRestoreInterrupts(enabled);
    return 0;
}

extern s32 lbl_8055D864;
/* DVD cancel callback: mark the requested cancel as done and wake the thread waiting on the DVD queue. */
void cbForCancel(void) {
    isCancelDone = 1;
    OSWakeupThread(&__DVDThreadQueue);
}

extern void *lbl_8055D88C;
/* DVD cover-status callback: store the command's returned status word into
   lbl_8055D88C so __DVDGetCoverStatus, polling it, can read the result. */
void fn_8003998C(void* status) {
    lbl_8055D88C = status;
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
    /* RealName: __DVDCancelAllAsync (RVL SDK DVD.cpp, source/os/dvd/dvdcancel.c),
     * the async twin of DVDCancelAll above.  Pause the drive and cancel what it
     * has: every block still on the waiting queue is cancelled with no callback
     * of its own, the block being executed with @p callback, and @p callback is
     * called straight away when nothing is running.  If a cancel is already on
     * its way to the drive this only takes over the callback it will answer. */
    s32 resumeEnabled;        // DVDResume()'s own save
    s32 intStatus;            // interrupts kept off from DVDPause() to DVDResume()
    DVDCommandBlock *block;   // DVDPause()'s save at first, then each block popped
    s32 enabled;              // interrupts as this function found them

    enabled = OSDisableInterrupts();

    __DVDClearWaitingQueue();

    if (Canceling) {
        CancelCallback = callback;
    } else {
        // The cancel answers through our callback, not the block's own one.
        if (ExecutingBlock != 0)
            ((DVDCommandBlock *)ExecutingBlock)->callback = NULL;

        // DVDPause(), inlined by the compiler
        intStatus = OSDisableInterrupts();
        block = (DVDCommandBlock *)OSDisableInterrupts();
        PauseFlag = TRUE;
        if (ExecutingBlock == 0) {
            PausingFlag_8055D850 = TRUE;
        }
        OSRestoreInterrupts((s32)block);

        // Nothing queued may survive the cancel, so queued blocks get no callback.
        while ((block = __DVDPopWaitingQueue()) != NULL) {
            DVDCancelAsync(block, NULL);
        }

        if (ExecutingBlock != 0) {
            DVDCancelAsync((DVDCommandBlock *)ExecutingBlock, callback);
        } else if (callback != NULL) {
            callback(DVD_RESULT_GOOD, NULL);
        }

        // DVDResume(), inlined; stateReady() is left as a call
        resumeEnabled = OSDisableInterrupts();
        *(volatile s32 *)&PauseFlag = FALSE;
        if (PausingFlag_8055D850 != 0) {
            PausingFlag_8055D850 = 0;
            stateReady();
        }
        OSRestoreInterrupts(resumeEnabled);
        OSRestoreInterrupts(intStatus);
    }
    OSRestoreInterrupts(enabled);
}

/* DVD reset callback: signal that the drive reset/cancel has completed so that
 * __DVDPrepareReset's wait loop can exit. */
void cbForPrepareReset(void) {
    ResetDone = 1;
}

/* __DVDPrepareReset (RVL SDK DVD.cpp): stop the drive and spin until the reset
 * completes.  Pause the drive and cancel each queued block (with no callback)
 * plus the one executing (through cbForPrepareReset), resume the drive, then
 * wait for that callback to set ResetDone.  If a cancel is already in flight,
 * only take over its callback instead. */
void __DVDPrepareReset(void) {
    s32 intStatus;        // interrupts kept off from DVDPause to DVDResume
    s32 resumeEnabled;    // DVDResume()'s own save
    void *block;          // DVDPause()'s save at first, then each block popped
    s32 enabled;          // interrupts as this function found them
    s32 one = 1;

    OSDisableInterrupts();
    ResetDone = 0;
    enabled = OSDisableInterrupts();

    __DVDClearWaitingQueue();

    if (Canceling != 0) {
        CancelCallback = (void (*)(s32, void *))cbForPrepareReset;
    } else {
        if (ExecutingBlock != 0)
            *(s32 *)(ExecutingBlock + 0x28) = 0;

        // DVDPause(), inlined by the compiler
        intStatus = OSDisableInterrupts();
        block = (void *)OSDisableInterrupts();
        *(volatile s32 *)&PauseFlag = one;
        if (ExecutingBlock == 0) {
            PausingFlag_8055D850 = one;
        }
        OSRestoreInterrupts((s32)block);

        // Nothing queued may survive the reset, so queued blocks get no callback.
        while ((block = (void *)__DVDPopWaitingQueue()) != 0)
            DVDCancelAsync(block, 0);
        if (ExecutingBlock != 0)
            DVDCancelAsync((void *)ExecutingBlock, (void (*)(s32, void *))cbForPrepareReset);
        else if ((void *)cbForPrepareReset != 0)
            ResetDone = one;

        // DVDResume(), inlined; stateReady() is left as a call
        resumeEnabled = OSDisableInterrupts();
        *(volatile s32 *)&PauseFlag = 0;
        if (PausingFlag_8055D850 != 0) {
            PausingFlag_8055D850 = 0;
            stateReady();
        }
        OSRestoreInterrupts(resumeEnabled);
        OSRestoreInterrupts(intStatus);
    }
    OSRestoreInterrupts(enabled);
    OSEnableInterrupts();
    while (*(volatile s32 *)&ResetDone != 1) {}
}

#pragma small_data off
extern __declspec(section ".data") u8 lbl_8037B580;
#define DvdTimeoutAlarm lbl_8037B580 /* DVD timeout alarm created and armed in fn_800379A8 */
#define DefaultAlarmTest fn_8003BE40 /* default predicate: returns 0 */
s32 __DVDTestAlarm(void *alarm) {
    /* Return 1 when alarm is the DVD timeout alarm; otherwise fall back to the default test (false). */
    if (alarm == &DvdTimeoutAlarm) {
        return 1;
    }
    return DefaultAlarmTest();
}
#pragma small_data on
/* Constant predicate in the DVD/alarm code (beside __DVDTestAlarm): always returns 1 (true). */
u32 fn_80039CD8(void) { return 1; }

void fn_80039CE0(void) {
    /* Empty no-op hook in the VI force-dim timing path: __OSSetVIForceDimming
     * calls it when a timing counter reaches its limit, but it does nothing. */
}
