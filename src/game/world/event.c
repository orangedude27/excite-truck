// world/event.cpp — event handler registry and dispatcher.
// Recovered TU window 0x801EEFC8..0x801EF190 (see docs/attribution_analysis.md):
// assert string "world/event.cpp: No handler for evt type %d".
// The TU's static-init thunk fn_801EF188 (+ .ctors slot 0x802ED33C) remains in
// auto/text_801EF188_.c pending a promotion pass.

/* Event-handler registry: 18 event types, each a row of 4 handler function
 * pointers (int handler(char *payload)), 0x120 bytes in all. */
typedef int (*EventHandler)(char *payload);
typedef struct {
    EventHandler handlers[4];
} EventHandlerRow;
extern unsigned char gEventHandlers[];
void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
#pragma scheduling off
/* Clears the whole event-handler registry (all 18 event-type rows of handlers). */
void fn_801EEFC8(void) {
    memset(gEventHandlers, 0, 18 * sizeof(EventHandlerRow));
}
#pragma scheduling invalid_target
/* Registers a handler for event type (eventType & 0xFF): stores it in the first
   free slot of that type's 4-slot row, or does nothing when the row is full. */
void Event_RegisterHandler(int handler, unsigned int eventType) {
    unsigned int *p;
    unsigned int *base;
    int i;
    base = (unsigned int *)(gEventHandlers + ((eventType & 0xFF) << 4));
    p = base;
    for (i = 0; i < 4; p++, i++) {
        if (*p == 0) {
            base[i] = handler;
            return;
        }
    }
}
#pragma scheduling reset
void Abend_Panic(const char *, ...);
extern char lbl_8033A328[];
#pragma scheduling invalid_target
/* Removes a handler from the event registry (18 event types x 4 slots);
   reports an error if not found. */
/* Unregisters a handler from the 18-type x 4-slot event-handler registry; panics ("EventUnInstallHandler: Can't find handler!") if the handler was not registered. */ void fn_801EF024(unsigned int handler) {
    unsigned int *row = (unsigned int *)gEventHandlers;
    unsigned int *slot;
    int found = 0;
    int eventType;
    int slotIndex;

    for (eventType = 0; eventType < 18; eventType++, row += 4) {
        slot = row;
        for (slotIndex = 0; slotIndex < 4; slot++, slotIndex++) {
            if (*slot == handler) {
                *(volatile unsigned int *)((char *)gEventHandlers + (eventType << 4) + (slotIndex << 2)) = 0;
                found = 1;
                goto done;
            }
        }
    }
done:
    if (!found) {
        Abend_Panic(lbl_8033A328);
    }
}

extern char lbl_8033A354[];
#pragma scheduling invalid_target
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
/* Runs one event script: a u32 byte count followed by records laid out as
 *   signed char evtType | payload bytes ...
 * Each record's payload is copied into a private 0x400-byte buffer and handed
 * to every handler registered for its type in gEventHandlers (18 event types x
 * 4 handler slots, see Event_RegisterHandler / fn_801EF024); the last handler run
 * returns how many payload bytes it consumed, and the walk advances past
 * those plus the type byte. A type with no handler is reported
 * ("No handler for evt type %d") and aborts the script. */
/* Walks one event script: for each record, copies its payload to a scratch buffer, calls all registered handlers for its type, and advances by the bytes the last handler consumed; aborts with a panic if the type has no handler. */ void fn_801EF0AC(unsigned char *script) {
    char payloadCopy[0x400];
    unsigned int *handlerSlot;
    unsigned char *payload;
    int offset = 0;
    int bytesConsumed;
    signed char evtType;
    unsigned int slotIndex;

    while (offset < (int)*(unsigned int *)script) {
        evtType = (signed char)script[offset + 4];
        payload = script + offset + 5;
        bytesConsumed = -1;
        handlerSlot = (unsigned int *)(gEventHandlers + evtType * 16);
        for (slotIndex = 0; slotIndex < 4; slotIndex++, handlerSlot++) {
            if (*handlerSlot != 0) {
                memcpy(payloadCopy, payload, 0x400);
                bytesConsumed = ((EventHandler)*handlerSlot)(payloadCopy);
            }
        }
        if (bytesConsumed != -1) {
            offset = offset + bytesConsumed + 1;
        } else {
            Abend_Panic(lbl_8033A354, *((volatile unsigned char *)script + offset + 4));
            return;
        }
    }
}
#pragma pop
#pragma scheduling on
/* Empty stub (returns immediately). */
void fn_801EF184(void) {
}
