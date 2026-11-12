// RVL_SDK DVD waiting queue (dvdqueue.c).  One circular list per request
// priority holds the DVDCommandBlocks that could not start yet; the heads are
// the WaitingQueue array and an empty list is a head that points to itself.
// A block is linked in through its next/prev fields (+0x00/+0x04), which is why
// every function below casts a head to DVDCommandBlock*.  All of the pointer
// surgery runs between OSDisableInterrupts() and OSRestoreInterrupts().
#include <revolution/DVD.h>

typedef struct DVDWaitingQueue {
    struct DVDWaitingQueue* next; // at 0x0
    struct DVDWaitingQueue* prev; // at 0x4
} DVDWaitingQueue;

static DVDWaitingQueue WaitingQueue[DVD_PRIO_MAX];


void __DVDClearWaitingQueue(void) {
    u32 i;

    for (i = 0; i < DVD_PRIO_MAX; i++) {
        DVDCommandBlock* head = (DVDCommandBlock*)&WaitingQueue[i];
        head->next = head;
        head->prev = head;
    }
}

BOOL __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block) {
    BOOL enabled = OSDisableInterrupts();
    DVDCommandBlock* head = (DVDCommandBlock*)&WaitingQueue[prio];

    head->prev->next = block;
    block->prev = head->prev;
    block->next = head;
    head->prev = block;

    OSRestoreInterrupts(enabled);
    return TRUE;
}

/* Unlink and return the first block of one priority's queue, or the head itself
 * when that queue is empty (the caller has checked).  The links of the returned
 * block are cleared so a caller can tell it is not queued. */
static DVDCommandBlock* __DVDPopWaitingQueuePrio(s32 prio) {
    BOOL enabled = OSDisableInterrupts();

    DVDCommandBlock* head = (DVDCommandBlock*)&WaitingQueue[prio];
    DVDCommandBlock* block = head->next;

    head->next = block->next;
    block->next->prev = head;

    OSRestoreInterrupts(enabled);

    block->next = NULL;
    block->prev = NULL;
    return block;
}

/* Take the command block at the head of the highest priority queue that has one
 * (DVD_PRIO_HIGHEST first, DVD_PRIO_LOW last) and unlink it from that queue;
 * NULL when every queue is empty.  The build inlines __DVDPopWaitingQueuePrio
 * here, so the target re-disables interrupts for the unlink, rewires
 * head->next and block->next->prev around the block and clears the block's own
 * links before handing it back (dvd.c starts it as the executing command). */
DVDCommandBlock* __DVDPopWaitingQueue(void) {
    u32 prio;
    BOOL enabled = OSDisableInterrupts();

    for (prio = 0; prio < DVD_PRIO_MAX; prio++) {
        DVDCommandBlock* head = (DVDCommandBlock*)&WaitingQueue[prio];

        if (head->next != head) {
            OSRestoreInterrupts(enabled);
            return __DVDPopWaitingQueuePrio(prio);
        }
    }

    OSRestoreInterrupts(enabled);
    return NULL;
}

BOOL __DVDCheckWaitingQueue(void) {
    u32 i;
    BOOL enabled = OSDisableInterrupts();

    for (i = 0; i < DVD_PRIO_MAX; i++) {
        DVDCommandBlock* head = (DVDCommandBlock*)&WaitingQueue[i];

        if (head->next != head) {
            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

DVDCommandBlock* __DVDGetNextWaitingQueue(void) {
    u32 i;
    BOOL enabled = OSDisableInterrupts();

    for (i = 0; i < DVD_PRIO_MAX; i++) {
        DVDCommandBlock* head = (DVDCommandBlock*)&WaitingQueue[i];
        DVDCommandBlock* block = head->next;

        if (block != head) {
            OSRestoreInterrupts(enabled);
            return block;
        }
    }

    OSRestoreInterrupts(enabled);
    return NULL;
}

BOOL __DVDDequeueWaitingQueue(const DVDCommandBlock* block) {
    BOOL enabled = OSDisableInterrupts();

    DVDCommandBlock* prev = block->prev;
    DVDCommandBlock* next = block->next;

    if (prev == NULL || next == NULL) {
        OSRestoreInterrupts(enabled);
        return FALSE;
    }

    prev->next = next;
    next->prev = prev;

    OSRestoreInterrupts(enabled);
    return TRUE;
}
