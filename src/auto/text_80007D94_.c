// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <macros.h>

typedef struct {
    u8 unk_0x0[0x1E4];
    void* unk_0x1E4;
} Unk8034EF38;

typedef struct {
    u32 unk_0x0;
    const char* unk_0x4;
    const char* unk_0x8;
} Unk802FB70C;

extern Unk8034EF38 lbl_8034EF38;
extern Unk802FB70C lbl_802FB70C[];
extern const char lbl_802FB77C[];
extern const char lbl_80558998[1];
extern const char lbl_805589A0[1];
extern const char lbl_805589A8[1];
void fn_80007DA0(void);
void fn_80279464(void);
void fn_80012778(void);
void fn_80131818(void*);
void fn_802E317C(const char*, ...);

int stricmp(const char*, const char*);
extern void qsort(void *, u32, u32, int (*)(const void *, const void *));
const char* fn_80008158(s32);
void fn_80012794(void);
void fn_80279488(void);
void fn_802E30C8(const char*, ...);
extern const char lbl_802FB7A4[];
void fn_80007D94(const char** arg0, const char** arg1) {
    stricmp(*arg0, *arg1);
}

extern void *fn_80131808(void *);
extern char lbl_802FB6E0[];
DECL_SECTION(".sdata") extern const char lbl_80558978[];
DECL_SECTION(".sdata") extern const char lbl_80558980[];
DECL_SECTION(".sdata") extern const char lbl_80558988[];
DECL_SECTION(".sdata") extern const char lbl_80558990[];
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80007DA0(void) {
    struct Config {
        virtual void unused();
        virtual void *getEntry(u32);
    };
    struct Item {
        virtual const char *getName();
        virtual void unused1();
        virtual void unused2();
        virtual const char *getValue(const char *);
        virtual void *getString(const char *, const char *);
    };
    volatile u32 *global;
    char *base;
    void *initialConfig;
    u32 index;

    /* Load track entries from the "excite_beta_race" config (base+0x68) into
       gRaceEventTable (lbl_8034EF38): for each "track" item store {name,
       display string (base+0x74 key, default ""), environ (default "")} in
       0xC-byte slots (max 0x28, overflows -> abend base+0x84), then qsort by
       name with fn_80007D94. global[0x78]=count, global[0x79]=config ptr. */
    base = lbl_802FB6E0;
    initialConfig = fn_80131808(base + 0x68);
    global = (volatile u32 *)&lbl_8034EF38;
    global[0x79] = (u32)initialConfig;
    index = 0;
    global[0x78] = 0;

loop:
    {
        void *config;
        Item *entry;
        void *value;
        u32 count;
        u32 entryIndex;

        config = (void *)global[0x79];
        entryIndex = index;
        index++;
        entry = (Item *)((Config *)config)->getEntry(entryIndex);
        if (entry == 0) {
            goto done;
        }
        if (stricmp(entry->getName(), lbl_80558978) != 0) {
            goto loop;
        }

        value = (void *)entry->getValue(lbl_80558980);
        *(void **)((u8 *)global + global[0x78] * 0xC) = value;

        value = entry->getString(base + 0x74, lbl_80558988);
        *(void **)((u8 *)global + global[0x78] * 0xC + 4) = value;

        value = entry->getString(lbl_80558990, lbl_80558988);
        *(void **)((u8 *)global + global[0x78] * 0xC + 8) = value;

        count = global[0x78] + 1;
        global[0x78] = count;
        if (count < 0x28) {
            goto loop;
        }
        fn_802E317C(base + 0x84);
    }

done:
    qsort(&lbl_8034EF38, *(volatile u32 *)((u8 *)&lbl_8034EF38 + 0x1E0), 0xC, (int (*)(const void *, const void *))fn_80007D94);
}
#pragma scheduling on
#pragma cplusplus reset

#pragma dont_inline on
/* Tear down the parsed "excite_beta_race" config: release the config object
 * held at offset 0x1E4 of the global race-event table and clear the pointer. */
void fn_80007F04(void) {
    Unk8034EF38* raceTable = &lbl_8034EF38;
    fn_80131818(raceTable->unk_0x1E4);
    raceTable->unk_0x1E4 = 0;
}
#pragma dont_inline reset

/* Bootstrap init for the race-event subsystem (paired with fn_80007F68's teardown):
 * parse the "excite_beta_race" config into the event table, reset the per-controller
 * state, then load/set up event resource 0x12F. */
void fn_80007F40(void) {
    fn_80007DA0();
    fn_80279464();
    fn_80012778();
}

#pragma dont_inline fn_80007F04
void fn_80007F04(void);
#pragma dont_inline fn_80007F04
void fn_80007F68(void) {
    /* Tear down the race-event subsystem: release the per-controller model
       list, resume the pending alarm thread, then free the parsed config. */
    fn_80012794();
    fn_80279488();
    fn_80007F04();
}
#pragma scheduling invalid_target
const char* fn_80007F90(u32 eventId) {
    /* Look up the name string for an event ID in the event table, or return "?" if not found. */
    Unk802FB70C* entry = lbl_802FB70C;
    while (entry->unk_0x0) {
        if (entry->unk_0x0 == eventId) return entry->unk_0x4;
        entry++;
    }
    fn_802E317C(lbl_802FB77C, eventId);
    return lbl_80558998;
}
#pragma scheduling on
const char* fn_80007FF0(u32 eventType) {
    /* Look up the display name for an event type ID in the event type table, or return "unknown" if not found. */
    Unk802FB70C* entry;
    u32 id;
    for (entry = lbl_802FB70C; (id = entry->unk_0x0) != 0; ++entry) {
        if (id == eventType) return entry->unk_0x8;
    }
    fn_802E317C(lbl_802FB77C, eventType);
    return lbl_805589A0;
}

#pragma scheduling invalid_target
/* Look up the event id (unk_0x0) for an event identifier string by scanning lbl_802FB70C
 * entries and comparing each entry's name (unk_0x4) to eventName. Returns 0 if not found. */
u32 fn_80008050(const char* eventName) {
    register u32 eventId;
    register Unk802FB70C* entry;
    for (entry = lbl_802FB70C; (eventId = entry->unk_0x0) != 0; ++entry) {
        if (strcmp(entry->unk_0x4, eventName) == 0) return eventId;
    }
    fn_802E30C8(lbl_802FB7A4, eventName);
    return 0;
}
#pragma scheduling on
u32 fn_800080D8(void) {
    return *(u32*)((u8*)&lbl_8034EF38 + 0x1E0);
}

#pragma dont_inline on
/* Returns the index of the named entry in the lbl_8034EF38 table, or -1 if not found. */
s32 fn_800080E8(arg0)
const char* arg0;
{
    s32 i = 0;
    goto compare;
body:
    if (stricmp(arg0, fn_80008158(i)) == 0) {
        return i;
    }
    i++;
compare:
    if (i < (s32)fn_800080D8()) {
        goto body;
    }
    return -1;
}
#pragma dont_inline reset

/* Return the name string of the race-event table entry at index (0xC-byte records,
 * count at offset 0x1E0), or "invalid" if the index is out of range. */
const char* fn_80008158(s32 index) {
    if (index < 0) {
        goto done;
    }
    if (index >= *(s32 *)((u8 *)&lbl_8034EF38 + 0x1E0)) {
        goto done;
    }
    return *(const char **)((u8 *)&lbl_8034EF38 + index * 0xC);

done:
    return lbl_805589A8;
}

const char* fn_80008158(s32);
/* Returns the display-string field (offset 4) of the race-event table entry selected by the caller's name lookup. */
const char* fn_80008188(void) {
    return *(const char**)((u8*)&lbl_8034EF38 + fn_800080E8() * 0xC + 4);
}

/* Returns the "environ" field (offset 8) of the race-event table entry whose name
 * matches; the caller's name argument is forwarded in r3 to the lookup fn_800080E8. */
s32 fn_800081BC(void) {
    return *(s32 *)((u8 *)&lbl_8034EF38 + fn_800080E8() * 0xC + 8);
}

#define GetContestLapCount fn_800081F0 /* contest lap count for a reference record */
s32 fn_800081F0(void *arg0) {
    /* Return the lap count of the contest this reference record points at; a set first flag yields 200. */
    typedef struct { s32 contestIndex; u8 pad04[0x0C]; u32 flags; } ContestRef;
    typedef struct { s32 pad00[3]; s32 laps; } ContestLaps;
    s32 laps;
    if (((ContestRef *)arg0)->flags & 1) goto done;
    laps = ((ContestLaps *)fn_8001285C(((ContestRef *)arg0)->contestIndex))->laps;
    return laps;
done:
    return 0xC8;
}

#pragma dont_inline on
/* Reset a 0x14-byte contest reference record to its empty state: index -1 at offset 0, all other fields 0. */
void fn_8000822C(void *record) {
    *(s32 *)((u8 *)record + 0) = -1;
    *(u32 *)((u8 *)record + 4) = 0;
    *(u32 *)((u8 *)record + 0x10) = 0;
    *(u32 *)((u8 *)record + 0xC) = 0;
    *(u32 *)((u8 *)record + 8) = 0;
}
#pragma dont_inline reset

void fn_8000822C(void *);
#pragma dont_inline fn_8000822C
/* Initialize a record from a looked-up source: reset the destination, then copy
 * its first field and the field at offset 8 from the looked-up object. */
void fn_8000824C(void *dest, s32 index) {
    void *source;

    fn_8000822C(dest);
    source = (void *)fn_8001285C(index);
    *(u32 *)((u8 *)dest) = *(u32 *)((u8 *)source);
    *(u32 *)((u8 *)dest + 4) = *(u32 *)((u8 *)source + 8);
}
