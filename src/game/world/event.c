// world/event.cpp — event handler registry and dispatcher.
// Recovered TU window 0x801EEFC8..0x801EF190 (see docs/attribution_analysis.md):
// assert string "world/event.cpp: No handler for evt type %d".
// The TU's static-init thunk fn_801EF188 (+ .ctors slot 0x802ED33C) remains in
// auto/text_801EF188_.c pending a promotion pass.

/* Event-handler registry: 18 event types, each a row of 4 handler function
 * pointers (int handler(char *payload)), 0x120 bytes in all. */
extern unsigned char lbl_80488678[];
void *memset(void *, int, unsigned int);
#pragma scheduling off
/* Clears the whole event-handler registry (18 event types x 4 handler slots). */
void fn_801EEFC8(void) {
    memset(lbl_80488678, 0, 0x120);
}
#pragma scheduling invalid_target
/* Registers handler arg0 for event type arg1 & 0xFF: first free slot of that
 * type's 4-slot row; does nothing when the row is full. */
void fn_801EEFDC(int arg0, unsigned int arg1) {
    unsigned int *p;
    unsigned int *base;
    int i;
    base = (unsigned int *)(lbl_80488678 + ((arg1 & 0xFF) << 4));
    p = base;
    for (i = 0; i < 4; p++, i++) {
        if (*p == 0) {
            base[i] = arg0;
            return;
        }
    }
}
#pragma scheduling reset
void fn_802E317C(const char *, ...);
extern char lbl_8033A328[];
#pragma scheduling invalid_target
/* Removes a handler from the event registry (18 event types x 4 slots); reports an error if not found. */
void fn_801EF024(unsigned int handler) {
    unsigned int *row = (unsigned int *)lbl_80488678;
    unsigned int *slot;
    int found = 0;
    int i;
    int j;

    for (i = 0; i < 18; i++, row += 4) {
        slot = row;
        for (j = 0; j < 4; slot++, j++) {
            if (*slot == handler) {
                *(volatile unsigned int *)((char *)lbl_80488678 + (i << 4) + (j << 2)) = 0;
                found = 1;
                goto done;
            }
        }
    }
done:
    if (!found) {
        fn_802E317C(lbl_8033A328);
    }
}

extern char lbl_8033A354[];
#pragma scheduling invalid_target
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw off
void fn_801EF0AC(unsigned char *script) {
    char payloadCopy[0x400];
    unsigned int *slot;
    unsigned char *payload;
    int offset = 0;
    int consumed;
    signed char evtType;
    unsigned int slotIdx;

    /* Runs one event script: a u32 byte count followed by records laid out as
     *   signed char evtType | payload bytes ...
     * Each record's payload is copied into a private 0x400-byte buffer and handed
     * to every handler registered for its type in lbl_80488678 (18 event types x
     * 4 handler slots, see fn_801EEFDC / fn_801EF024); the last handler run
     * returns how many payload bytes it consumed, and the walk advances past
     * those plus the type byte. A type with no handler is reported
     * ("No handler for evt type %d") and aborts the script. */
    while (offset < (int)*(unsigned int *)script) {
        evtType = (signed char)script[offset + 4];
        payload = script + offset + 5;
        consumed = -1;
        slot = (unsigned int *)(lbl_80488678 + evtType * 16);
        for (slotIdx = 0; slotIdx < 4; slotIdx++, slot++) {
            if (*slot != 0) {
                memcpy(payloadCopy, payload, 0x400);
                consumed = ((int (*)(char *))*slot)(payloadCopy);
            }
        }
        if (consumed != -1) {
            offset = offset + consumed + 1;
        } else {
            fn_802E317C(lbl_8033A354, *((volatile unsigned char *)script + offset + 4));
            return;
        }
    }
}
#pragma pop
#pragma scheduling on
void fn_801EF184(void) {

}
