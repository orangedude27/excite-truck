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
