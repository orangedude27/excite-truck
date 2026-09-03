#include <revolution/DSP/dsp_task.h>
#include <revolution/OS.h>

/* Review carve for REXE01 DSPAssertInt@0x8003425C (auto_03_80034194_text).
 *
 * Custom REXE01 variant with no direct sibling match: it inserts the task,
 * forces default state/flags, then boots the task if it became the head of
 * the priority list.  Note the public dsp.h prototype (void DSPAssertInt())
 * is a later-SDK shape and does not match this binary, so this TU includes
 * dsp_task.h only.  Not configured; review-only.
 */

void __DSP_insert_task(DSPTask* task);

DSPTask* DSPAssertInt(DSPTask* task) {
    BOOL enabled;

    enabled = OSDisableInterrupts();

    __DSP_insert_task(task);

    task->state = DSP_TASK_STATE_0;
    task->flags = DSP_TASK_ACTIVE;

    OSRestoreInterrupts(enabled);

    if (task == __DSP_first_task) {
        __DSP_boot_task(task);
    }

    return task;
}