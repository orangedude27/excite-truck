#include <revolution/BASE.h>
#include <revolution/DVD.h>
#include <revolution/OS.h>

BOOL OnReset(BOOL final, u32 event);
extern OSShutdownFunctionInfo ShutdownFunctionInfo;
static void DecrementerExceptionHandler(u8 type, OSContext* ctx);

static OSAlarmQueue AlarmQueue;

static void SetTimer(const OSAlarm* alarm) {
    s64 timeLeft = alarm->end - __OSGetSystemTime();

    if (timeLeft < 0) {
        PPCMtdec(0);
    } else if (timeLeft < 0x80000000) {
        PPCMtdec(timeLeft);
    } else {
        PPCMtdec(0x7FFFFFFF);
    }
}

void __OSInitAlarm(void) {
    if (__OSGetExceptionHandler(OS_ERR_DECREMENTER) !=
        DecrementerExceptionHandler) {
        AlarmQueue.head = AlarmQueue.tail = NULL;
        __OSSetExceptionHandler(OS_ERR_DECREMENTER,
                                DecrementerExceptionHandler);
        OSRegisterShutdownFunction(&ShutdownFunctionInfo);
    }
}

void OSCreateAlarm(OSAlarm* alarm) {
    alarm->handler = NULL;
    alarm->tag = 0;
}

static void InsertAlarm(OSAlarm* alarm, s64 end, OSAlarmHandler handler) {
    // AlarmQueue is sorted by ascending end time, so this walks it to the first
    // alarm that ends later and links the new one in front of it.  Only an insert
    // at the front can change what the decrementer is counting down to, so that is
    // the only place SetTimer is called.  Callers hold interrupts disabled.
    OSAlarm* later;
    OSAlarm* prev;

    // A periodic alarm (OSSetPeriodicAlarm passes end as 0) fires on its own
    // schedule: its start, moved up to the first period that has not passed yet.
    if (alarm->period > 0) {
        s64 time = __OSGetSystemTime();
        end = alarm->start;

        if (alarm->start < time) {
            s64 periodsElapsed = ((time - alarm->start) / alarm->period);
            end += alarm->period * (periodsElapsed + 1);
        }
    }

    alarm->handler = handler;
    alarm->end = end;

    for (later = AlarmQueue.head; later != NULL; later = later->next) {
        if (later->end <= end) {
            continue;
        }

        // link in front of 'later'
        alarm->prev = later->prev;
        later->prev = alarm;
        alarm->next = later;

        prev = alarm->prev;
        if (prev != NULL) {
            prev->next = alarm;
        } else {
            AlarmQueue.head = alarm;
            SetTimer(alarm);
        }

        return;
    }

    // nothing ends later: hang it off the tail
    alarm->next = NULL;
    prev = AlarmQueue.tail;
    AlarmQueue.tail = alarm;
    alarm->prev = prev;

    if (prev != NULL) {
        prev->next = alarm;
    } else {
        // the queue was empty
        AlarmQueue.tail = alarm;
        AlarmQueue.head = alarm;
        SetTimer(alarm);
    }
}

void OSSetAlarm(OSAlarm* alarm, s64 tick, OSAlarmHandler handler) {
    BOOL enabled = OSDisableInterrupts();

    alarm->period = 0;
    InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);

    OSRestoreInterrupts(enabled);
}

/* Schedule a periodic alarm to first fire at `tick`, then repeat every `period` system ticks. */
void OSSetPeriodicAlarm(OSAlarm* alarm, s64 tick, s64 period,
                        OSAlarmHandler handler) {
    BOOL enabled = OSDisableInterrupts();

    alarm->period = period;
    alarm->start = __OSTimeToSystemTime(tick);
    InsertAlarm(alarm, 0, handler);

    OSRestoreInterrupts(enabled);
}

// Cancels a queued alarm, removing it from AlarmQueue and updating the decrementer if needed.
void OSCancelAlarm(OSAlarm* alarm) {
    OSAlarm* next;

    BOOL enabled = OSDisableInterrupts();

    if (alarm->handler == NULL) {
        OSRestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;
    if (next == NULL) {
        AlarmQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }

    if (alarm->prev != NULL) {
        alarm->prev->next = next;
    } else {
        AlarmQueue.head = next;
        if (next != NULL) {
            SetTimer(next);
        }
    }

    alarm->handler = NULL;

    OSRestoreInterrupts(enabled);
}

// The C half of the decrementer exception handler: DecrementerExceptionHandler
// saves the registers the exception dispatcher leaves alone and jumps here.
// The decrementer is the countdown SetTimer() armed with the head of AlarmQueue,
// so an exception means either "the earliest alarm is due now" or, because that
// counter saturates at 0x7FFFFFFF ticks, "come back later".  Whatever alarms run
// here, the exception always goes back to the context it interrupted.
static void DecrementerExceptionCallback(u8 type, OSContext* ctx) {
#pragma unused(type) // always OS_ERR_DECREMENTER, the handler is fixed to it

    OSAlarmHandler handler;
    OSContext tempCtx;
    OSAlarm* alarm;
    OSAlarm* next;

    s64 time = __OSGetSystemTime();
    alarm = AlarmQueue.head;

    // Nothing queued, so this decrementer exception was not ours.  Both
    // OSLoadContext()s below leave the exception for good, so code past them
    // only runs for an alarm that is due.
    if (alarm == NULL) {
        OSLoadContext(ctx);
    }

    // The countdown saturated before the head came due: re-arm it and return.
    if (time < alarm->end) {
        SetTimer(alarm);
        OSLoadContext(ctx);
    }

    // it is due: take it off the queue
    next = alarm->next;
    AlarmQueue.head = next;
    if (next == NULL) {
        AlarmQueue.tail = NULL;
    } else {
        next->prev = NULL;
    }

    // An unqueued alarm has no handler, so clear it before running it: one that
    // re-arms or cancels itself inside its callback must not still look queued.
    handler = alarm->handler;
    alarm->handler = NULL;

    // Periodic alarms go back in by themselves: InsertAlarm() works out the
    // first end time after now from start and period and re-sorts it in.
    if (alarm->period > 0) {
        InsertAlarm(alarm, 0, handler);
    }

    // whatever is at the head now is the next alarm due: arm the countdown
    if (AlarmQueue.head != NULL) {
        SetTimer(AlarmQueue.head);
    }

    // Run the callback against a scratch current context, as the other hardware
    // interrupt handlers do, so a nested exception saves itself there and not
    // over the context being restored here.  The thread scheduler is off for the
    // same reason: this exception returns to ctx no matter what the callback
    // does to the run queue.
    OSDisableScheduler();
    OSClearContext(&tempCtx);
    OSSetCurrentContext(&tempCtx);
    handler(alarm, ctx);
    OSClearContext(&tempCtx);
    OSSetCurrentContext(ctx);
    OSEnableScheduler();

    // the callback may have made a higher priority thread runnable
    __OSReschedule();
    OSLoadContext(ctx);
}

static asm void DecrementerExceptionHandler(register u8 type,
                                            register OSContext* ctx) {
    // clang-format off
    nofralloc

    stw r0, ctx->gprs[0]
    stw r1, ctx->gprs[1]
    stw r2, ctx->gprs[2]
    stmw r6, ctx->gprs[6]

    mfspr r0, GQR1
    stw r0, ctx->gqrs[1]
    mfspr r0, GQR2
    stw r0, ctx->gqrs[2]
    mfspr r0, GQR3
    stw r0, ctx->gqrs[3]
    mfspr r0, GQR4
    stw r0, ctx->gqrs[4]
    mfspr r0, GQR5
    stw r0, ctx->gqrs[5]
    mfspr r0, GQR6
    stw r0, ctx->gqrs[6]
    mfspr r0, GQR7
    stw r0, ctx->gqrs[7]

    stwu r1, -8(r1)
    b DecrementerExceptionCallback
    // clang-format on
}

void OSSetAlarmTag(OSAlarm* alarm, u32 tag) {
    alarm->tag = tag;
}

BOOL OnReset(BOOL final, u32 event) {
    /* On final reset, cancel all non-DVD alarms still queued in AlarmQueue. */
    OSAlarm* iter;
    OSAlarm* next;

    if (final) {
        iter = AlarmQueue.head;
        next = (iter != NULL) ? iter->next : NULL;

        while (iter != NULL) {
            if (!__DVDTestAlarm(iter)) {
                OSCancelAlarm(iter);
            }

            iter = next;
            next = (next != NULL) ? next->next : NULL;
        }
    }

    return TRUE;
}

void OSSetAlarmUserData(OSAlarm* alarm, void* userData) {
    alarm->userData = userData;
}

void* OSGetAlarmUserData(const OSAlarm* alarm) {
    return alarm->userData;
}
