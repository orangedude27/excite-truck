#ifndef RVL_SDK_DSP_TASK_H
#define RVL_SDK_DSP_TASK_H
#include <types.h>
#ifdef __cplusplus
extern "C" {
#endif

#define DSP_SEND_MAIL_SYNC(x)                                                  \
    do {                                                                       \
        DSPSendMailToDSP((DSPMail)(x));                                        \
        while (DSPCheckMailToDSP()) {                                          \
            ;                                                                  \
        }                                                                      \
    } while (0)

// Forward declarations
typedef struct OSContext OSContext;

#include <revolution/DSP/dsp_task_types.h>

extern BOOL __DSP_rude_task_pending;
extern DSPTask* __DSP_rude_task;
extern DSPTask* __DSP_tmp_task;
extern DSPTask* __DSP_last_task;
extern DSPTask* __DSP_first_task;
extern DSPTask* __DSP_curr_task;

void __DSPHandler(s16 intr, OSContext* ctx);
void __DSP_exec_task(DSPTask* task1, DSPTask* task2);
void __DSP_boot_task(DSPTask* task);
void __DSP_insert_task(DSPTask* task);
void __DSP_remove_task(DSPTask* task);

#ifdef __cplusplus
}
#endif
#endif
