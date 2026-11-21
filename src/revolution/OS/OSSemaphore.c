#include <revolution/OS.h>

/* Counting semaphores built on top of an OS thread queue. */
void OSInitSemaphore(OSSemaphore* sem, s32 count) {
    /* Initialize a semaphore with the given initial count. */
    BOOL enabled;

    enabled = OSDisableInterrupts();
    OSInitThreadQueue(&sem->queue);
    sem->count = count;
    OSRestoreInterrupts(enabled);
}

s32 OSWaitSemaphore(OSSemaphore* sem) {
    /* Decrement the semaphore, sleeping the current thread until its count is positive. */
    BOOL enabled;
    s32 prevCount;

    enabled = OSDisableInterrupts();

    while ((prevCount = sem->count) <= 0) {
        OSSleepThread(&sem->queue);
    }

    sem->count--;
    OSRestoreInterrupts(enabled);

    return prevCount;
}

s32 OSSignalSemaphore(OSSemaphore* sem) {
    /* Increment the semaphore count, wake one waiting thread, and return the previous count. */
    BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();
    count = sem->count;
    sem->count = count + 1;
    OSWakeupThread(&sem->queue);
    OSRestoreInterrupts(enabled);

    return count;
}
