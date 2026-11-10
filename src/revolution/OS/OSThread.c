#include <revolution/BASE.h>
#include <revolution/OS.h>

static void DefaultSwitchThreadCallback(OSThread* currThread,
                                        OSThread* newThread);

static OSSwitchThreadCallback SwitchThreadCallback =
    DefaultSwitchThreadCallback;

static OSThread DefaultThread;
static OSThreadQueue RunQueue[32];
// The original binary has a single 0x5F0-byte BSS object covering the idle
// context, 0x10 bytes of padding, and the idle thread. Model it as one struct.
static struct {
    OSContext ctx;    // at 0x00
    u8 pad[0x10];     // at 0x2C8
    OSThread thread;  // at 0x2D8
} Idle;
#define IdleContext Idle.ctx
#define IdleThread Idle.thread

volatile static s32 Reschedule = 0;
volatile static BOOL RunQueueHint = FALSE;
volatile static u32 RunQueueBits = 0;

static void DefaultSwitchThreadCallback(OSThread* currThread,
                                        OSThread* newThread) {
#pragma unused(currThread)
#pragma unused(newThread)
}

OSSwitchThreadCallback OSSetSwitchThreadCallback(OSSwitchThreadCallback newCb) {
    OSSwitchThreadCallback oldCb;
    BOOL enabled = OSDisableInterrupts();

    oldCb = SwitchThreadCallback;
    SwitchThreadCallback =
        (newCb != NULL) ? newCb : DefaultSwitchThreadCallback;

    OSRestoreInterrupts(enabled);
    return (oldCb == DefaultSwitchThreadCallback) ? NULL : oldCb;
}

void __OSThreadInit(void) {
    // Initialize the thread subsystem: set up the default (main) thread the
    // game runs on, one ready queue per priority, and the idle thread's context.
    int i;
    OSThread* thread = &DefaultThread;
    OSThread* tail;

    // The main thread starts running and detached, at the default priority.
    thread->state = OS_THREAD_STATE_RUNNING;
    thread->flags = OS_THREAD_DETACHED;
    thread->base = 16;
    thread->priority = 16;
    thread->suspend = 0;
    thread->val = (u32)-1; // no OSJoinThread return value yet
    thread->mutex = NULL;

    OSInitThreadQueue(&thread->joinQueue);
    OSInitMutexQueue(&thread->mutexQueue);

    OS_CURRENT_FPU_CONTEXT = &thread->context;
    OSClearContext(&thread->context);
    OSSetCurrentContext(&thread->context);

    // The default thread runs on the static stack.
    thread->stackBegin = (u32*)_stack_addr;
    thread->stackEnd = (u32*)_stack_end;
    *thread->stackEnd = OS_THREAD_STACK_MAGIC;

    OSSetCurrentThread(thread);
    OSClearStack(0x00);

    // One ready queue per priority level; none has a runnable thread yet.
    RunQueueBits = 0;
    RunQueueHint = FALSE;
    for (i = 0; i < OS_PRIORITY_MAX + 1; i++) {
        OSInitThreadQueue(&RunQueue[i]);
    }

    // Append the default thread to the active-thread list.
    OSInitThreadQueue(&OS_THREAD_QUEUE);

    tail = OS_THREAD_QUEUE.tail;
    if (tail == NULL) {
        OS_THREAD_QUEUE.head = thread;
    } else {
        tail->nextActive = thread;
    }

    thread->prevActive = tail;
    thread->nextActive = NULL;
    OS_THREAD_QUEUE.tail = thread;

    OSClearContext(&IdleContext);
    Reschedule = 0;
}

void OSSetCurrentThread(OSThread* thread) {
    SwitchThreadCallback(OSGetCurrentThread(), thread);
    OS_CURRENT_THREAD = thread;
}

void OSInitMutexQueue(OSMutexQueue* queue) {
    queue->tail = NULL;
    queue->head = NULL;
}

void OSInitThreadQueue(OSThreadQueue* queue) {
    queue->tail = NULL;
    queue->head = NULL;
}

OSThread* OSGetCurrentThread(void) {
    return OS_CURRENT_THREAD;
}

static void __OSSwitchThread(OSThread* thread) {
    OSSetCurrentThread(thread);
    OSSetCurrentContext(&thread->context);
    OSLoadContext(&thread->context);
}

BOOL OSIsThreadTerminated(OSThread* thread) {
    return thread->state == OS_THREAD_STATE_MORIBUND ||
                   thread->state == OS_THREAD_STATE_EXITED
               ? TRUE
               : FALSE;
}

static BOOL __OSIsThreadActive(OSThread* thread) {
    OSThread* iter;

    if (thread->state == OS_THREAD_STATE_EXITED) {
        return FALSE;
    }

    for (iter = OS_THREAD_QUEUE.head; iter != NULL; iter = iter->nextActive) {
        if (thread == iter) {
            return TRUE;
        }
    }

    return FALSE;
}

s32 OSDisableScheduler(void) {
    s32 old;
    BOOL enabled = OSDisableInterrupts();

    old = Reschedule++;

    OSRestoreInterrupts(enabled);

    return old;
}

s32 OSEnableScheduler(void) {
    s32 old;
    BOOL enabled = OSDisableInterrupts();

    old = Reschedule--;

    OSRestoreInterrupts(enabled);

    return old;
}

void OSClearStack(u8 val) {
    u32* end;
    u32* begin;
    u32 longVal;

    longVal = val << 24 | val << 16 | val << 8 | val;

    begin = (u32*)OSGetStackPointer();
    end = OSGetCurrentThread()->stackEnd + 1;

    for (; end < (u32*)begin; end++) {
        *end = longVal;
    }
}

static void SetRun(OSThread* thread) {
    OSThreadQueue* queue;
    OSThread* tail;

    queue = &RunQueue[thread->priority];
    thread->queue = queue;
    tail = thread->queue->tail;

    if (tail == NULL) {
        thread->queue->head = thread;
    } else {
        tail->next = thread;
    }

    thread->prev = tail;
    thread->next = NULL;
    thread->queue->tail = thread;

    RunQueueBits |= (1 << (OS_PRIORITY_MAX - thread->priority));
    RunQueueHint = TRUE;
}

static void UnsetRun(OSThread* thread) DECOMP_DONT_INLINE {
    OSThreadQueue* queue;
    OSThread* next;
    OSThread* prev;

    next = thread->next;
    queue = thread->queue;
    prev = thread->prev;

    if (next == NULL) {
        queue->tail = prev;
    } else {
        next->prev = prev;
    }

    if (prev == NULL) {
        queue->head = next;
    } else {
        prev->next = next;
    }

    if (queue->head == NULL) {
        RunQueueBits &= ~(1 << (OS_PRIORITY_MAX - thread->priority));
    }

    thread->queue = NULL;
}

s32 __OSGetEffectivePriority(OSThread* thread) {
    s32 prio = thread->base;

    OSMutex* mutex;
    for (mutex = thread->mutexQueue.head; mutex != NULL; mutex = mutex->next) {
        OSThread* mutexThread = mutex->queue.head;
        if (mutexThread != NULL && mutexThread->priority < prio) {
            prio = mutexThread->priority;
        }
    }

    return prio;
}

/* Update a thread's effective priority and reposition it in run/ready queues,
 * or mark a reschedule hint for the running thread; returns mutex owner to boost.
 */
static OSThread* SetEffectivePriority(OSThread* thread, s32 prio) {
    OSThread* iter;
    OSThread* iterPrev;
    OSThread* next;
    OSThread* prev;

    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        UnsetRun(thread);
        thread->priority = prio;
        thread->queue = &RunQueue[prio];
        SetRun(thread);
        break;
    case OS_THREAD_STATE_SLEEPING:
        next = thread->next;
        prev = thread->prev;
        if (next == NULL) {
            thread->queue->tail = prev;
        } else {
            next->prev = prev;
        }

        if (prev == NULL) {
            thread->queue->head = next;
        } else {
            prev->next = next;
        }

        thread->priority = prio;

        for (iter = thread->queue->head;
             iter != NULL && iter->priority <= thread->priority;
             iter = iter->next) {
        }

        if (iter == NULL) {
            iter = thread->queue->tail;
            if (iter == NULL) {
                thread->queue->head = thread;
            } else {
                iter->next = thread;
            }
            thread->prev = iter;
            thread->next = NULL;
            thread->queue->tail = thread;
        } else {
            thread->next = iter;
            iterPrev = iter->prev;
            iter->prev = thread;
            thread->prev = iterPrev;

            if (iterPrev == NULL) {
                thread->queue->head = thread;
            } else {
                iterPrev->next = thread;
            }
        }

        if (thread->mutex != NULL) {
            return thread->mutex->thread;
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = TRUE;
        thread->priority = prio;
        break;
    default:
        break;
    }

    return NULL;
}

static void UpdatePriority(OSThread* thread) {
    s32 prio = 0;

    while (TRUE) {
        if (thread->suspend > 0) {
            return;
        }

        prio = __OSGetEffectivePriority(thread);
        if (thread->priority == prio) {
            return;
        }

        thread = SetEffectivePriority(thread, prio);
        if (thread == NULL) {
            return;
        }
    }
}

void __OSPromoteThread(OSThread* thread, s32 prio) {
    while (TRUE) {
        if (thread->suspend > 0) {
            return;
        }

        if (thread->priority <= prio) {
            return;
        }

        thread = SetEffectivePriority(thread, prio);
        if (thread == NULL) {
            return;
        }
    }
}

/**
 * Chooses the thread that runs next, switches to it and returns it; NULL means the
 * current thread keeps the CPU.
 *
 * The scheduler is parked while Reschedule is set. Unless `force` is set (OSYieldThread
 * asks for it), a running thread is only taken off the CPU when some ready thread
 * outranks it. A thread that gives up the CPU goes back onto its priority's ready queue
 * and has its registers saved into its context, and the thread at the head of the
 * highest priority ready queue comes off it and is loaded. With nothing ready at all,
 * the idle context runs with interrupts enabled until some thread becomes runnable.
 */
static OSThread* SelectThread(BOOL force) {
    OSThreadQueue* queue;
    OSThread* currThread;
    OSThread* head;
    OSThread* next;
    OSContext* currCtx;
    s32 prio;

    // A reschedule is already on the way (another thread was promoted on this CPU).
    if (Reschedule > 0) {
        return NULL;
    }

    currCtx = OSGetCurrentContext();
    currThread = OSGetCurrentThread();

    // Only the thread the live context belongs to may hand the CPU over.
    if (currCtx != &currThread->context) {
        return NULL;
    }

    if (currThread != NULL) {
        if (currThread->state == OS_THREAD_STATE_RUNNING) {
            // Without force: stay on while no ready thread outranks this one.
            // __cntlzw of the queue bits is the best priority waiting.
            if (!force) {
                prio = __cntlzw(RunQueueBits);
                if (currThread->priority <= prio) {
                    return NULL;
                }
            }

            currThread->state = OS_THREAD_STATE_READY;
            SetRun(currThread);
        }

        // The caller-saved registers are only in the context when that bit says so;
        // otherwise save them now. Coming back to this call later (the thread was
        // loaded again), OSSaveContext returns 1 and the caller gets a NULL.
        if (!(currThread->context.state & OS_CONTEXT_STATE_GPRS_SAVED)) {
            if (OSSaveContext(&currThread->context)) {
                return NULL;
            }
        }
    }

    // Nothing ready: idle with interrupts on until some thread can run again.
    if (RunQueueBits == 0) {
        OSSetCurrentThread(NULL);
        OSSetCurrentContext(&IdleContext);

        do {
            OSEnableInterrupts();

            while (RunQueueBits == 0) {
            }
            OSDisableInterrupts();

        } while (RunQueueBits == 0);

        OSClearContext(&IdleContext);
    }

    RunQueueHint = FALSE;

    // Unlink the head of the highest priority ready queue; that thread runs next.
    prio = __cntlzw(RunQueueBits);
    queue = &RunQueue[prio];
    head = queue->head;
    next = head->next;

    if (next == NULL) {
        queue->tail = NULL;
    } else {
        next->prev = NULL;
    }

    queue->head = next;
    if (next == NULL) {
        RunQueueBits &= ~(1 << (OS_PRIORITY_MAX - prio));
    }

    head->queue = NULL;
    head->state = OS_THREAD_STATE_RUNNING;
    __OSSwitchThread(head);
    return head;
}

void __OSReschedule(void) {
    if (RunQueueHint) {
        SelectThread(FALSE);
    }
}

void OSYieldThread(void) {
    BOOL enabled = OSDisableInterrupts();
    SelectThread(TRUE);
    OSRestoreInterrupts(enabled);
}

/**
 * Sets up a caller-allocated thread to run func(funcArg) on the stack ending at
 * stackBegin, and adds it to the tail of the active thread list. The new thread
 * starts suspended (OSResumeThread lets it run) and leaves through
 * OSExitThread when func returns. Fails only on a priority outside
 * OS_PRIORITY_MIN..OS_PRIORITY_MAX.
 */
BOOL OSCreateThread(OSThread* thread, OSThreadFunc func, void* funcArg,
                    void* stackBegin, u32 stackSize, s32 prio, u16 flags) {
    BOOL enabled;
    int i;
    OSThread* tail;
    void* sp;

    if (prio < OS_PRIORITY_MIN || prio > OS_PRIORITY_MAX) {
        return FALSE;
    }

    // Ready but held: suspend > 0 keeps the scheduler off it until
    // OSResumeThread. base keeps the priority the thread was created with,
    // priority is the one it effectively has (mutexes may raise it).
    thread->state = OS_THREAD_STATE_READY;
    thread->flags = flags & OS_THREAD_DETACHED;
    thread->base = prio;
    thread->priority = prio;
    thread->suspend = 1;
    thread->val = (u32)-1; // no OSJoinThread return value yet
    thread->mutex = NULL;
    OSInitThreadQueue(&thread->joinQueue);
    OSInitMutexQueue(&thread->mutexQueue);

    // The first frame on the new stack: the two words below the initial stack
    // pointer are a null backchain and return address, which end a stack walk.
    sp = ROUND_DOWN_PTR(stackBegin, 8);
    *((u32*)sp - 2) = 0;
    *((u32*)sp - 1) = 0;

    // Start at func with funcArg in r3; lr rather than srr0 carries the thread
    // into OSExitThread once func returns.
    OSInitContext(&thread->context, func, (char*)sp - 8);
    thread->context.lr = (u32)OSExitThread;
    thread->context.gprs[3] = (u32)funcArg;

    // The magic word at the bottom of the stack catches an overflow (OSCheckStack).
    thread->stackBegin = (u32*)stackBegin;
    thread->stackEnd = (u32*)((char*)stackBegin - stackSize);
    *thread->stackEnd = OS_THREAD_STACK_MAGIC;

    thread->error = 0;
    for (i = 0; i < 2; i++) {
        thread->specific[i] = NULL;
    }

    enabled = OSDisableInterrupts();
    // With an FP exception handler installed every thread must report FP
    // exceptions: resume with the FP exception enables on, and own the FP state
    // right away (OS_CONTEXT_STATE_FP_SAVED) so the handler will not overwrite
    // these registers with a first lazy save.
    if (__OSErrorTable[OS_ERR_FP_EXCEPTION] != NULL) {
        thread->context.srr1 |= (MSR_FE0 | MSR_FE1);
        thread->context.state |= OS_CONTEXT_STATE_FP_SAVED;
        thread->context.fpscr = __OSFpscrEnableBits & FPSCR_ENABLE;
        thread->context.fpscr |= FPSCR_NI;

        // All-ones FPRs and PSFs are quiet NaNs: the thread traps on its very
        // first floating-point use.
        for (i = 0; i < 32; i++) {
            *(u64*)&thread->context.fprs[i] = 0xFFFFFFFFFFFFFFFF;
            *(u64*)&thread->context.psfs[i] = 0xFFFFFFFFFFFFFFFF;
        }
    }

    // Append to the active thread list, under interrupt disable so a running
    // thread cannot walk the list half-linked.
    tail = OS_THREAD_QUEUE.tail;
    if (tail == NULL) {
        OS_THREAD_QUEUE.head = thread;
    } else {
        tail->nextActive = thread;
    }

    thread->prevActive = tail;
    thread->nextActive = NULL;
    OS_THREAD_QUEUE.tail = thread;
    tail = thread; // leftover of the SDK's queue code; never read again

    OSRestoreInterrupts(enabled);
    return TRUE;
}

void OSExitThread(OSThread* thread) {
    BOOL enabled;
    OSThread* currThread;
    OSThread* next;
    OSThread* prev;

    enabled = OSDisableInterrupts();
    currThread = OSGetCurrentThread();
    OSClearContext(&currThread->context);

    if ((currThread->flags & OS_THREAD_DETACHED)) {
        next = currThread->nextActive;
        prev = currThread->prevActive;

        if (next == NULL) {
            OS_THREAD_QUEUE.tail = prev;
        } else {
            next->prevActive = prev;
        }

        if (prev == NULL) {
            OS_THREAD_QUEUE.head = next;
        } else {
            prev->nextActive = next;
        }

        currThread->state = OS_THREAD_STATE_EXITED;
    } else {
        currThread->state = OS_THREAD_STATE_MORIBUND;
        currThread->val = (u32)thread;
    }

    __OSUnlockAllMutex(currThread);
    OSWakeupThread(&currThread->joinQueue);
    RunQueueHint = TRUE;
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

/**
 * Stops a thread for good without waiting for it to finish.
 *
 * The thread comes off whichever queue held it - its priority's ready queue, or the
 * sleep queue it was blocked on, in which case the thread owning its mutex also gets
 * its inherited priority recomputed - and its context is cleared so it can never be
 * resumed. A detached thread leaves the active-thread list and is EXITED right away;
 * one that may still be joined stays on the list as MORIBUND until OSJoinThread
 * collects it. Mutexes it held are released, threads waiting on its join queue wake
 * up, and the scheduler picks who runs next.
 */
void OSCancelThread(OSThread* thread) {
    BOOL enabled;
    OSThread* next;
    OSThread* prev;

    enabled = OSDisableInterrupts();

    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        // A suspended ready thread is not on its run queue yet.
        if (thread->suspend <= 0) {
            UnsetRun(thread);
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        // Cancelling the running thread: SelectThread takes the CPU away from it.
        RunQueueHint = TRUE;
        break;
    case OS_THREAD_STATE_SLEEPING:
        // Take it out of the queue it was sleeping on.
        next = thread->next;
        prev = thread->prev;
        if (next == NULL) {
            thread->queue->tail = prev;
        } else {
            next->prev = prev;
        }

        if (prev == NULL) {
            thread->queue->head = next;
        } else {
            prev->next = next;
        }

        thread->queue = NULL;
        // Give back the priority it lent to whoever holds the mutex it waited on.
        if (thread->suspend <= 0 && thread->mutex != NULL) {
            UpdatePriority(thread->mutex->thread);
        }
        break;
    default:
        // Already EXITED or MORIBUND; leave it alone.
        OSRestoreInterrupts(enabled);
        return;
        break;
    }

    OSClearContext(&thread->context);
    if (thread->flags & OS_THREAD_DETACHED) {
        // Nobody can join it, so unlink it from the active-thread list and let go.
        next = thread->nextActive;
        prev = thread->prevActive;

        if (next == NULL) {
            OS_THREAD_QUEUE.tail = prev;
        } else {
            next->prevActive = prev;
        }

        if (prev == NULL) {
            OS_THREAD_QUEUE.head = next;
        } else {
            prev->nextActive = next;
        }

        thread->state = OS_THREAD_STATE_EXITED;
    } else {
        // Kept alive for OSJoinThread, which reads its return value in thread->val.
        thread->state = OS_THREAD_STATE_MORIBUND;
    }

    __OSUnlockAllMutex(thread);
    OSWakeupThread(&thread->joinQueue);
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

BOOL OSJoinThread(OSThread* thread, void* val) {
    BOOL enabled;
    OSThread* next;
    OSThread* prev;

    enabled = OSDisableInterrupts();

    if (!(thread->flags & OS_THREAD_DETACHED) &&
        thread->state != OS_THREAD_STATE_MORIBUND &&
        thread->joinQueue.head == NULL) {
        OSSleepThread(&thread->joinQueue);
        if (!__OSIsThreadActive(thread)) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }
    }

    if (thread->state == OS_THREAD_STATE_MORIBUND) {
        if (val != NULL) {
            *(u32*)val = thread->val;
        }

        next = thread->nextActive;
        prev = thread->prevActive;

        if (next == NULL) {
            OS_THREAD_QUEUE.tail = prev;
        } else {
            next->prevActive = prev;
        }

        if (prev == NULL) {
            OS_THREAD_QUEUE.head = next;
        } else {
            prev->nextActive = next;
        }

        thread->state = OS_THREAD_STATE_EXITED;

        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

void OSDetachThread(OSThread* thread) {
    BOOL enabled;
    OSThread* next;
    OSThread* prev;

    enabled = OSDisableInterrupts();
    thread->flags |= OS_THREAD_DETACHED;

    if (thread->state == OS_THREAD_STATE_MORIBUND) {
        next = thread->nextActive;
        prev = thread->prevActive;

        if (next == NULL) {
            OS_THREAD_QUEUE.tail = prev;
        } else {
            next->prevActive = prev;
        }

        if (prev == NULL) {
            OS_THREAD_QUEUE.head = next;
        } else {
            prev->nextActive = next;
        }

        thread->state = OS_THREAD_STATE_EXITED;
    }

    OSWakeupThread(&thread->joinQueue);
    OSRestoreInterrupts(enabled);
}

/* Undoes one OSSuspendThread() and returns the suspend count from before this
 * call.  The count never goes below zero, so resuming a thread that was not
 * suspended changes nothing.  Only the resume that drops the count to zero
 * makes the thread eligible to run again:
 *   ready    - it is put back on the run queue for its effective priority;
 *   sleeping - it is unlinked from the queue it is sleeping on and re-inserted
 *              there in priority order (a sleeping thread is not on a run
 *              queue, but its priority still decides who is woken first);
 * either way the scheduler is then offered the highest priority thread.
 * A sleeping thread that owns a mutex may have been raising its owner's
 * priority, so that chain is recomputed from the owner. */
s32 OSResumeThread(OSThread* thread) {
    BOOL enabled;
    s32 prevSuspend;
    OSThread* iter;
    OSThread* iterPrev;
    OSThread* next;
    OSThread* prev;

    enabled = OSDisableInterrupts();
    prevSuspend = thread->suspend--;

    if (thread->suspend < 0) {
        thread->suspend = 0;
    } else if (thread->suspend == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_READY:
            thread->priority = __OSGetEffectivePriority(thread);
            SetRun(thread);
            break;
        case OS_THREAD_STATE_SLEEPING:
            /* unlink from the sleep queue */
            next = thread->next;
            prev = thread->prev;
            if (next == NULL) {
                thread->queue->tail = prev;
            } else {
                next->prev = prev;
            }

            if (prev == NULL) {
                thread->queue->head = next;
            } else {
                prev->next = next;
            }

            thread->priority = __OSGetEffectivePriority(thread);

            /* re-insert ahead of the first thread of higher priority */
            for (iter = thread->queue->head;
                 iter != NULL && iter->priority <= thread->priority;
                 iter = iter->next) {
            }

            if (iter == NULL) {
                /* none: go on the end of the queue */
                iter = thread->queue->tail;
                if (iter == NULL) {
                    thread->queue->head = thread;
                } else {
                    iter->next = thread;
                }
                thread->prev = iter;
                thread->next = NULL;
                thread->queue->tail = thread;
            } else {
                thread->next = iter;
                iterPrev = iter->prev;
                iter->prev = thread;
                thread->prev = iterPrev;

                if (iterPrev == NULL) {
                    thread->queue->head = thread;
                } else {
                    iterPrev->next = thread;
                }
            }

            if (thread->mutex != NULL) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        default:
            break;
        }

        __OSReschedule();
    }

    OSRestoreInterrupts(enabled);
    return prevSuspend;
}

/* Increment a thread's suspend count; if newly suspended, remove it from
 * scheduling or its wait queue as appropriate and trigger rescheduling. */
s32 OSSuspendThread(OSThread* thread) {
    BOOL interrupts;
    s32 previousSuspend;
    OSThread* next;
    OSThread* prev;
    OSThread* tail;

    interrupts = OSDisableInterrupts();
    previousSuspend = thread->suspend++;

    if (previousSuspend == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_RUNNING:
            RunQueueHint = TRUE;
            thread->state = OS_THREAD_STATE_READY;
            break;
        case OS_THREAD_STATE_READY:
            UnsetRun(thread);
            break;
        case OS_THREAD_STATE_SLEEPING:
            next = thread->next;
            prev = thread->prev;
            if (next == NULL) {
                thread->queue->tail = prev;
            } else {
                next->prev = prev;
            }

            if (prev == NULL) {
                thread->queue->head = next;
            } else {
                prev->next = next;
            }

            thread->priority = OS_PRIORITY_MAX + 1;

            tail = thread->queue->tail;
            if (tail == NULL) {
                thread->queue->head = thread;
            } else {
                tail->next = thread;
            }

            thread->prev = tail;
            thread->next = NULL;
            thread->queue->tail = thread;
            tail = thread;

            if (thread->mutex != NULL) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        default:
            break;
        }

        __OSReschedule();
    }

    OSRestoreInterrupts(interrupts);
    return previousSuspend;
}

void OSSleepThread(OSThreadQueue* queue) {
    BOOL enabled;
    OSThread* currThread;
    OSThread* iter;
    OSThread* iterPrev;

    enabled = OSDisableInterrupts();
    currThread = OSGetCurrentThread();

    currThread->state = OS_THREAD_STATE_SLEEPING;
    currThread->queue = queue;

    for (iter = queue->head;
         iter != NULL && iter->priority <= currThread->priority;
         iter = iter->next) {
    }

    if (iter == NULL) {
        iter = queue->tail;
        if (iter == NULL) {
            queue->head = currThread;
        } else {
            iter->next = currThread;
        }
        currThread->prev = iter;
        currThread->next = NULL;
        queue->tail = currThread;
    } else {
        currThread->next = iter;
        iterPrev = iter->prev;
        iter->prev = currThread;
        currThread->prev = iterPrev;

        if (iterPrev == NULL) {
            queue->head = currThread;
        } else {
            iterPrev->next = currThread;
        }
    }

    RunQueueHint = TRUE;
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

void OSWakeupThread(OSThreadQueue* queue) {
    BOOL enabled;
    OSThread* head;
    OSThread* next;

    enabled = OSDisableInterrupts();

    while (queue->head != NULL) {
        head = queue->head;
        next = head->next;

        if (next == NULL) {
            queue->tail = NULL;
        } else {
            next->prev = NULL;
        }

        queue->head = next;

        head->state = OS_THREAD_STATE_READY;
        if (head->suspend <= 0) {
            SetRun(head);
        }
    }

    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

BOOL OSSetThreadPriority(OSThread* thread, s32 prio) {
    BOOL enabled;

    if (prio < OS_PRIORITY_MIN || prio > OS_PRIORITY_MAX) {
        return FALSE;
    }

    enabled = OSDisableInterrupts();

    if (thread->base != prio) {
        thread->base = prio;
        UpdatePriority(thread);
        __OSReschedule();
    }

    OSRestoreInterrupts(enabled);
    return TRUE;
}

static void SleepAlarmHandler(OSAlarm* alarm, OSContext* ctx) {
#pragma unused(ctx)

    OSResumeThread((OSThread*)OSGetAlarmUserData(alarm));
}

void OSSleepTicks(s64 ticks) {
    BOOL enabled;
    OSAlarm alarm;
    OSThread* thread;

    enabled = OSDisableInterrupts();

    thread = OS_CURRENT_THREAD;
    if (thread == NULL) {
        OSRestoreInterrupts(enabled);
        return;
    }

    OSCreateAlarm(&alarm);
    OSSetAlarmTag(&alarm, (u32)thread);
    OSSetAlarmUserData(&alarm, thread);
    OSSetAlarm(&alarm, ticks, SleepAlarmHandler);

    OSSuspendThread(thread);
    OSCancelAlarm(&alarm);
    OSRestoreInterrupts(enabled);
}

DECOMP_FORCEACTIVE(OSThread_c, IdleThread);
