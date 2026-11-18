#include <types.h>

s32 fn_80019430(void);
s32 fn_80019438(void);
void *fn_80019054(s32);
s32 fn_80019088(void);
s32 fn_80019098(s32);
s32 fn_80019144(s32);
s32 fn_8027DE68(s32);
void fn_80131234(void *);
void fn_80131818(s32);
s32 fn_80018E44(const char *, s32);
s32 fn_802E317C(void *, void *);
void fn_80018BA4(void);
void fn_80018CCC(void);
void *fn_80131808(void *);
extern const char lbl_80558C50[] __attribute__((section(".sdata2")));
extern const char lbl_802FD2F4[];
extern const char lbl_802FD308[];
void fn_80018B74(void);
void fn_8027DEAC(void);
void fn_8001EF60(s32);
s32 stricmp(const char *, const char *);
extern char lbl_8055D588;
extern u8 lbl_80357E0C[12];

#define sUnlockableMaxExcitePointsName lbl_802FD2F4
#define sUnlockableNotFoundFmt lbl_802FD308
#define sUnlockableTable lbl_80357E0C
#define sUnlockManager lbl_8055D58C /* unlock/properties Manager loaded from common.res/unlock.val */
#define sResetRequested lbl_8055D588 /* set when a quit/reset is requested */
#define sUnlockValPath lbl_802FD2DC  /* "common.res/unlock.val" */
#define sCarCategoryName lbl_80558C50 /* "car" unlockable category name */

typedef struct UnlockableEntry {
    const char *name;
    const char *category;
    s32 value;
    u8 flag;
    u8 pad[3];
    s32 sortIndex;
} UnlockableEntry;

typedef struct UnlockableTable {
    UnlockableEntry *entries;
    volatile s32 count;
    s32 unk8;
} UnlockableTable;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80018B70(void) {
#define GetCurrentPlayerMode fn_8027DEAC
    /* GetCurrentPlayerUnlockMode: tail-call thunk forwarding to the per-player
       mode getter whose result gates non-car unlockables in fn_80018E44. */
    GetCurrentPlayerMode();
#undef GetCurrentPlayerMode
}

/* qsort comparator for unlockable records: order by value ascending, using the
 * original collection index as a stable tiebreaker when values are equal. */
s32 fn_80018B7C(void *arg0, void *arg1) {
    s32 diff;

    diff = ((UnlockableEntry *)arg0)->value - ((UnlockableEntry *)arg1)->value;
    if (diff == 0) {
        return ((UnlockableEntry *)arg0)->sortIndex - ((UnlockableEntry *)arg1)->sortIndex;
    }
    return diff;
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Collect entries for manager items whose name matches the target and sort them. */
extern "C" void fn_80018BA4(void) {
    struct Manager { virtual void unused(); virtual void *get(int); };
    struct Item {
        virtual const char *name();
        virtual void unused1();
        virtual void unused2();
        virtual const char *value(const char *);
        virtual void unused4();
        virtual const char *other(const char *);
    };
    extern void *lbl_8055D58C;
    extern unsigned char lbl_80357E0C[12];
    extern void *lbl_802FD2A0 __attribute__((section(".rodata")));
    extern int strcmp(const char *, const char *);
    extern int fn_80265DCC(void *, int, int, void *);
    extern const char lbl_80558C30[] __attribute__((section(".sdata")));
    extern const char lbl_80558C38[] __attribute__((section(".sdata")));
    extern const char lbl_80558C40[] __attribute__((section(".sdata")));
    int *record;
    register int matchCount = 0;
    register int itemIndex = 0;
    register int zeroValue = 0;
    Item *item;

    for (;;) {
        item = (Item *)((Manager *)lbl_8055D58C)->get(itemIndex);
        if (item == 0)
            break;
        if (strcmp(item->name(), (const char *)&lbl_802FD2A0) == 0) {
            record = (int *)((char *)*(void **)lbl_80357E0C +
                            *(int *)(lbl_80357E0C + 4) * 0x14);
            *(int *)(lbl_80357E0C + 4) = *(int *)(lbl_80357E0C + 4) + 1;
            record[0] = (int)item->value(lbl_80558C30);
            record[1] = (int)item->value(lbl_80558C38);
            record[2] = (int)item->other(lbl_80558C40);
            *((char *)record + 0xC) = (char)zeroValue;
            record[4] = matchCount++;
        }
        ++itemIndex;
    }
    fn_80265DCC(*(void **)lbl_80357E0C, *(int *)(lbl_80357E0C + 4), 0x14, fn_80018B7C);
}
#pragma cplusplus reset
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80018CCC(void) {
    struct Manager { virtual void unused(); virtual void *get(int); };
    struct Item {
        virtual const char *name();
        virtual void unused1();
        virtual void unused2();
        virtual const char *value(const char *);
        virtual void unused4();
        virtual const char *property(const char *);
    };
    extern void *lbl_8055D58C;
    extern void *lbl_803580A4 __attribute__((section(".data")));
    extern void *lbl_802FD2A0 __attribute__((section(".rodata")));
    extern const char lbl_80558C48[] __attribute__((section(".sdata")));
    extern s32 stricmp(const char *, const char *);
    register char *name;
    register char *strings = (char *)&lbl_802FD2A0;
    register int row;
    register int offset;
    register Item *object;
    register int outer = 0;

    goto get_next;
check_object:
    if (stricmp(object->name(), strings + 0x10) == 0) {
        name = (char *)object->value(strings + 0x20);
        row = 0;
        offset = 0;
        goto check_count;
search:
        if (stricmp(*(const char **)((char *)*(void **)&lbl_803580A4 + offset), name) != 0)
            goto search_advance;
        goto found;
search_advance:
        offset += 0x10;
        row++;
check_count:
        if (row < *(volatile int *)((char *)&lbl_803580A4 + 4))
            goto search;
        row = -1;
found:
        if (row < 0) {
            int count = *(volatile int *)((char *)&lbl_803580A4 + 4);
            row = *(volatile int *)((char *)&lbl_803580A4 + 4);
            *(volatile int *)((char *)&lbl_803580A4 + 4) = count + 1;
            *(const char **)((char *)*(void **)&lbl_803580A4 + count * 0x10) = name;
        }
        name = (char *)*(void **)&lbl_803580A4 + row * 0x10;
        *(void **)(name + 4) =
            (void *)object->property(strings + 0x30);
        *(void **)(name + 8) =
            (void *)object->property(lbl_80558C48);
        *(void **)(name + 0xC) =
            (void *)object->value(strings + 0x10);
    }
get_next:
    outer++;
    object = (Item *)((Manager *)lbl_8055D58C)->get(outer);
    if (object != 0)
        goto check_object;
}
#pragma cplusplus reset
#pragma pop

#pragma push
#pragma dont_inline on
s32 fn_80018E3C(void) {
#define GetCurrentPlayerScore fn_80018B74
    /* GetCurrentPlayerCarUnlockMode: tail-call thunk forwarding to the current
       player's lifetime "score" achievement read, whose result gates car unlockables. */
    GetCurrentPlayerScore();
#undef GetCurrentPlayerScore
}

s32 fn_80018E40(void) {
#define GetCurrentPlayerUnlockMode fn_80018B70
    /* GetCurrentUnlockModeForOtherCategories: tail-call the shared per-player
       mode getter whose result gates non-car unlockables in fn_80018E44. */
    GetCurrentPlayerUnlockMode();
#undef GetCurrentPlayerUnlockMode
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
s32 fn_80018E44(const char *categoryName, s32 itemName) {
    /* Returns whether the named record is allowed: skips lookup when disabled and rejects a matching entry whose rank is above the current mode and not flagged. */
    register s32 mode;
    register s32 offset;
    register s32 index;

    if ((u8)lbl_8055D588 != 0) {
        return 1;
    }
    if (stricmp(categoryName, lbl_80558C50) == 0) {
        mode = fn_80018E3C();
    } else {
        mode = fn_80018E40();
    }
    index = 0;
    offset = 0;
    goto check;
loop:
    if (stricmp((const char *)itemName,
                *(const char **)((char *)*(void **)lbl_80357E0C + offset + 4)) == 0 &&
        stricmp(categoryName,
                *(const char **)((char *)*(void **)lbl_80357E0C + offset)) == 0) {
        char *entry = (char *)*(void **)lbl_80357E0C + index * 0x14;
        s32 rank = *(s32 *)(entry + 8);
        s32 result = 1;
        if (rank > mode && *(u8 *)(entry + 0xC) == 0) {
            result = 0;
        }
        return result;
    }
    offset += 0x14;
    index++;
check:
    if (index < ((s32 *)lbl_80357E0C)[1]) {
        goto loop;
    }
    return 1;
}
#pragma pop
void fn_80018FA8(s32 itemName) {
    /* Checks whether the named car unlockable is allowed; the result is returned through fn_80018E44. */
    fn_80018E44(sCarCategoryName, itemName);
}

#pragma dont_inline on
s32 fn_80019430(void) {
    /* Stubbed reset check: always reports "no pending reset", so the exit/busy
     * tests that call it (fn_80019604, fn_800194CC) never trigger on it here. */
    return 0;
}

s32 fn_800194C8(void) {
#define CheckCarUnlockStatus fn_80019438
    /* Tail-call thunk forwarding to the CAR-unlockable status check (0 = satisfied, 1 = otherwise). */
    CheckCarUnlockStatus();
#undef CheckCarUnlockStatus
}
#pragma dont_inline off

extern char lbl_8055D588;
extern s32 lbl_8055DDF8;
extern void *lbl_8055D58C;
extern char lbl_802FD404[];
extern char lbl_802FD3CC[];
extern char lbl_802FD3A0[];
extern char lbl_802FD3B4[];
extern char lbl_802FD434[];
extern void *lbl_802FD2DC;
extern const char lbl_80558C54[] __attribute__((section(".sdata")));
extern void *lbl_803580A4;
extern u8 lbl_80357E0C[12];
/* Clear the pending quit/reset request flag (the mirror of fn_800196FC). */
void fn_80019708(void) {
    sResetRequested = 0;
}

/* Return the pending quit/reset request flag. */
char fn_80019714(void) {
    return sResetRequested;
}

void fn_800196FC(void) {
    /* Request a quit/reset by setting the pending-reset flag. */
    sResetRequested = 1;
}

/* Fire the "career completed" car-unlock event path. */
void fn_800196F0(void) {
#define EVENT_CAR_UNLOCK_CAREER_COMPLETED lbl_802FD404
    fn_80131234(EVENT_CAR_UNLOCK_CAREER_COMPLETED);
#undef EVENT_CAR_UNLOCK_CAREER_COMPLETED
}

#pragma dont_inline on
s32 fn_80019604(void) {
    /* True if a quit/reset has been requested, a simple reset was triggered,
     * or the display manager reports a pending fatal/display-reset (kind 2). */
    s32 shouldExit;
    if ((s32)(u8)lbl_8055D588 != 0) {
        shouldExit = 1;
    } else {
        shouldExit = 0;
        if (((volatile s32)fn_80019430() != 0) || (fn_8027DE68(2) != 0)) {
            shouldExit = 1;
        }
    }
    return shouldExit;
}
#pragma dont_inline off

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" s32 fn_80019664(void) {
    /* If a global interface object exists and supports the "other_unlockables" key, fetch
       that subobject and query its "career_completed_chassis" flag/value (arg 0). */
    struct Dummy {
        virtual Dummy *f0(void *);
        virtual void f1();
        virtual s32 f2(void *);
        virtual void f3();
        virtual s32 f4(void *, s32);
    };
    if (lbl_8055D58C != 0) {
        if (((Dummy *)lbl_8055D58C)->f2(lbl_802FD3A0) != 0) {
            return ((Dummy *)lbl_8055D58C)->f0(lbl_802FD3A0)->f4(lbl_802FD434, 0);
        }
    }
    return 0;
}
#pragma scheduling on
#pragma cplusplus off
/* Displays the "all satisfied" or "not all satisfied" unlockable-status message based on fn_80019438. */
void fn_800195C0(void) {
    if (fn_80019438() != 0) {
        fn_80131234(lbl_802FD3CC);
        return;
    }
    fn_80131234(lbl_802FD404);
}

#pragma cplusplus on
struct Dummy_80019534 {
    virtual Dummy_80019534 *f0(void *);
    virtual void f1();
    virtual s32 f2(void *);
    virtual void f3();
    virtual s32 f4(void *, s32);
};
#pragma cplusplus on
#pragma scheduling on
extern "C" s32 fn_80019534(void) {
    /* Return the "all_extremes_chassis" value from the "other_unlockables" group in the
       global unlocks/properties manager (lbl_8055D58C). Keys: lbl_802FD3A0="other_unlockables",
       lbl_802FD3B4="all_extremes_chassis". Returns 0 if unavailable. */
    if (lbl_8055D58C) {
        if (((Dummy_80019534 *)lbl_8055D58C)->f2(lbl_802FD3A0) != 0) {
            return ((Dummy_80019534 *)lbl_8055D58C)->f0(lbl_802FD3A0)->f4(lbl_802FD3B4, 0);
        }
    }
    return 0;
}
#pragma cplusplus off
__declspec(section ".data") extern void *lbl_803580A4;
static inline s32 fn_80019098_find_inl(const char *name) {
    s32 offset;
    s32 i;
    for (i = 0, offset = 0; i < *(volatile s32 *)((char *)&lbl_803580A4 + 4); offset += 0x10, i++) {
        if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name) == 0)
            return i;
    }
    return -1;
}
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
s32 fn_80019098(s32 arg0) {
    register s32 index;
    register s32 offset;
    register const char *name;
    char *entry;
    name = (const char *)arg0;
    index = 0;
    offset = 0;
    goto check;
loop:
    if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name) != 0)
        goto advance;
    goto found;
advance:
    offset += 0x10;
    index++;
check:
    if (index < *(volatile s32 *)((char *)&lbl_803580A4 + 4))
        goto loop;
    index = -1;
found:
    entry = (char *)lbl_803580A4 + index * 0x10 + 4;
    if (index < 0) entry = 0;
    if (entry != 0) return *(s32 *)(entry + 8);
    return 0;
}
#pragma pop

s32 fn_8001EFC0(s32, s32);
static inline s32 fn_80019144_find_inl(const char *name) {
    s32 offset;
    s32 i;
    for (i = 0, offset = 0; i < *(volatile s32 *)((char *)&lbl_803580A4 + 4); offset += 0x10, i++) {
        if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name) == 0)
            return i;
    }
    return -1;
}
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
s32 fn_80019144(s32 arg0) {
    register s32 index;
    register const char *name;
    int value0;
    s32 value1;
    s32 lower;
    s32 upper;
    s32 result;
    char *entry;

    name = (const char *)arg0;
    index = fn_80019144_find_inl(name);
    entry = (char *)lbl_803580A4 + index * 0x10 + 4;
    if (index < 0) entry = 0;
    if (entry) {
        if ((u8)lbl_8055D588 != 0) return 1;
        value0 = fn_8001EFC0(0, arg0);
        lower = *(s32 *)entry <= value0;
        value1 = fn_8001EFC0(1, arg0);
        upper = *(s32 *)(entry + 4) <= value1;
        result = 0;
        if (lower != 0 || upper != 0)
            result = 1;
        return result;
    }
    return 0;
}
#pragma pop
__declspec(section ".data") extern void *lbl_803580A4;
__declspec(section ".data") extern void *lbl_802FD2A0;
static inline s32 fn_80019258_find_inl(const char *name) {
    s32 offset;
    s32 i;
    for (i = 0, offset = 0; i < *(volatile s32 *)((char *)&lbl_803580A4 + 4); offset += 0x10, i++) {
        if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name) == 0)
            return i;
    }
    return -1;
}
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
int fn_80019258(const char *name, int *outValue0, int *outValue1, int unused) {
    /* Find the named record in the global registry and return its two int
     * payload fields; return 0 if no record matches. */
    s32 row;
    char *pRecord;
    row = fn_80019258_find_inl(name);
    pRecord = (char *)lbl_803580A4 + row * 0x10 + 4;
    if (row < 0)
        pRecord = 0;
    if (pRecord != 0) {
        *outValue0 = *(s32 *)pRecord;
        *outValue1 = *(s32 *)(pRecord + 4);
        return 1;
    }
    return 0;
}
#pragma pop
extern s32 fn_8001EFC0(s32, s32);
extern void *lbl_802FD2A0;
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
void fn_8001931C(s32 name) {
    register s32 name_r = name;
    register char *strings = (char *)&lbl_802FD2A0;
    register s32 i;
    register s32 offset;
    char *p;

    for (i = 0, offset = 0; i < *(s32 *)((char *)&lbl_803580A4 + 4); offset += 0x10, i++) {
        if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), (const char *)name_r) == 0)
            goto found;
    }
    i = -1;
found:
    p = (char *)lbl_803580A4 + i * 0x10 + 4;
    if (i < 0)
        p = 0;
    if (p != 0) {
        s32 inRange = *(s32 *)p <= fn_8001EFC0(0, name_r);
        s32 pastEnd = fn_8001EFC0(1, name_r) >= *(s32 *)(p + 4);
        if (pastEnd) {
            fn_80131234(strings + 0x94);
            return;
        }
        if (inRange) {
            fn_80131234(strings + 0xBC);
            return;
        }
    }
    fn_80131234(strings + 0xE4);
}
#pragma pop
/* Returns 1 when no "CAR" unlockable entry is currently blocking; returns 0 if
 * a "CAR" entry exists whose requirement is met and not restricted. */
#pragma push
#pragma dont_inline on
s32 fn_80019438(void) {
    s32 index = 0;
    /* Return 0 if a "CAR" unlockable entry exists, is met, and is unrestricted. */
    while (index < fn_80019088()) {
        void *unlockableEntry = fn_80019054(index);
        if (stricmp(*(const char **)unlockableEntry, lbl_80558C54) == 0) {
            if (fn_80019098(((s32 *)unlockableEntry)[1]) != 0 && fn_80019144(((s32 *)unlockableEntry)[1]) == 0) {
                return 0;
            }
        }
        index++;
    }
    return 1;
}
#pragma pop

s32 fn_800194CC(void) {
    /* Returns nonzero if the subsystem is busy or a pending operation/state requires attention. */
    s32 result;
    if ((s32)(u8)lbl_8055D588 != 0) {
        result = 1;
    } else {
        result = 0;
        if ((fn_80019430() != 0) || (fn_800194C8() != 0) || (fn_80019604() != 0)) {
            result = 1;
        }
    }
    return result;
}

#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
/* Look up the MAX_EXCITE_POINTS unlockable value in the unlockable table. */
int fn_80018FB4(s32 unused) {
    register s32 offset;
    register const char *target;
    register s32 i;
    register const char *entry;

    target = lbl_802FD2F4;
    for (i = 0, offset = 0; i < *(volatile s32 *)(lbl_80357E0C + 4); offset += 0x14, i++) {
        entry = *(const char **)((u8 *)*(void **)lbl_80357E0C + offset);
        if (stricmp(entry, target) == 0) {
            return *(s32 *)((u8 *)*(void **)lbl_80357E0C + i * 0x14 + 8);
        }
    }
    ((s32 (*)(const char *, ...))fn_802E317C)(lbl_802FD308, target);
    return 0;
}
#pragma pop
/* Releases the unlock/properties manager object and clears its global pointer. */
void fn_80018F7C(void) {
    s32 manager = (s32)sUnlockManager;
    fn_80131818(manager);
    sUnlockManager = 0;
}

void *fn_80019054(s32 index) {
    /* Bounds-checked lookup of an unlockable-table entry by index (0x14-byte records); returns 0 when out of range. */
    void *entry;
    if (index < 0) goto done;
    if (index >= *(s32 *)(lbl_80357E0C + 4)) goto done;
    entry = (void *)((u8 *)*(void **)lbl_80357E0C + index * 0x14);
    return entry;
done:
    return 0;
}

/* Return the number of entries in the unlockable table. */
s32 fn_80019088(void) {
    return ((UnlockableTable *)sUnlockableTable)->count;
}

__declspec(section ".data") extern void *lbl_802FD2DC;
/* RealName: InitUnlocks. Load the unlock/properties manager from common.res/unlock.val, build its item tables, and clear the reset-requested flag. */
void fn_80018F40(void) {
    sUnlockManager = fn_80131808(&sUnlockValPath);
    fn_80018BA4();
    fn_80018CCC();
    sResetRequested = 0;
}
void fn_80018B74(void) {
#define ReadCurrentPlayerAchCounter fn_8001EF60
#define ACH_COUNTER_SCORE 0
    /* Alarm callback wrapper: read the current player's stored lifetime "score" (counter 0) achievement value. */
    ReadCurrentPlayerAchCounter(ACH_COUNTER_SCORE);
#undef ACH_COUNTER_SCORE
#undef ReadCurrentPlayerAchCounter
}
