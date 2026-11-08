#ifndef RVL_SDK_DSP_TASK_TYPES_H
#define RVL_SDK_DSP_TASK_TYPES_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

// Forward declarations
typedef struct DSPTask DSPTask;

typedef enum {
    DSP_TASK_ACTIVE = (1 << 0),
    DSP_TASK_CANCELED = (1 << 1),
} DSPTaskFlags;

typedef enum {
    DSP_TASK_STATE_0,
    DSP_TASK_STATE_1,
    DSP_TASK_STATE_2,
    DSP_TASK_STATE_3,
} DSPTaskState;

typedef void (*DSPTaskCallback)(DSPTask* task);

/**
 * Commands to the DSP sent via the mailbox.
 */
typedef enum {
    MAIL_SET_IRAM_MMEM_ADDR = 0x80F3A001,
    MAIL_SET_IRAM_DSP_ADDR = 0x80F3C002,
    MAIL_SET_IRAM_LENGTH = 0x80F3A002,
    MAIL_SET_ARAM_MMEM_ADDR = 0x80F3B002,
    MAIL_SET_START_VECTOR = 0x80F3D001
} DSPMailCmd;

/**
 * DSP microcode (from Dolphin Emulator).
 */
typedef enum {
    TASK_MAIL_MASK = 0xFFFF0000,
    TASK_MAIL_TO_CPU = 0xDCD10000,
    TASK_MAIL_TO_DSP = 0xCDD10000,

    DSP_INIT = (TASK_MAIL_TO_CPU | 0x0000),
    DSP_RESUME = (TASK_MAIL_TO_CPU | 0x0001),
    DSP_YIELD = (TASK_MAIL_TO_CPU | 0x0002),
    DSP_DONE = (TASK_MAIL_TO_CPU | 0x0003),
    DSP_SYNC = (TASK_MAIL_TO_CPU | 0x0004),
    DSP_FRAME_END = (TASK_MAIL_TO_CPU | 0x0005),

    MAIL_RESUME = (TASK_MAIL_TO_DSP | 0x0000),
    MAIL_NEW_UCODE = (TASK_MAIL_TO_DSP | 0x0001),
    MAIL_RESET = (TASK_MAIL_TO_DSP | 0x0002),
    MAIL_CONTINUE = (TASK_MAIL_TO_DSP | 0x0003)
} DSPUCode;

typedef struct DSPTask {
    u32 state;                       // at 0x0
    volatile u32 prio;               // at 0x4
    u32 flags;                       // at 0x8
    void* iramMmemAddr;              // at 0xC
    u32 iramMmemLen;                 // at 0x10
    uintptr_t iramDspAddr;           // at 0x14
    void* dramMmemAddr;              // at 0x18
    u32 dramMmemLen;                 // at 0x1C
    uintptr_t dramDspAddr;           // at 0x20
    u16 startVector;                 // at 0x24
    u16 resumeVector;                // at 0x26
    DSPTaskCallback initCallback;    // at 0x28
    DSPTaskCallback resumeCallback;  // at 0x2C
    DSPTaskCallback doneCallback;    // at 0x30
    DSPTaskCallback requestCallback; // at 0x34
    DSPTask* next;                   // at 0x38
    DSPTask* prev;                   // at 0x3C
    char UNK_0x40[0x50 - 0x40];
} DSPTask;

#ifdef __cplusplus
}
#endif
#endif
