#include "revolution/BTE/stack/include/btm_api.h"
extern void *memset(void *, int, unsigned long);
extern void fn_8001BE70(void *);
extern void fn_802AE0E0(void);
extern unsigned int fn_801CE898(void);
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
#pragma cplusplus on
struct DummyBase_801CCDAC { int pad; };
struct Dummy_801CCDAC : DummyBase_801CCDAC { virtual int v0(); virtual int v1(int); virtual int v2(f32); };
static inline int fn_801CD130_dispatch(void *obj, f32 value) { return ((Dummy_801CCDAC *)obj)->v2(value); }
#pragma cplusplus reset
extern f32 lbl_805629E4;
extern f32 lbl_805629FC;
extern f32 lbl_80562A08;

#define STAT_HANDLER_LAYOUT_MOVED_UP
/* The award stat handler kept in lbl_8055E884 (its heap name strings at
 * lbl_80337AC8 read "StatHandler::Create: ..." and "award_int"/"award_real").
 * fn_801CC470 allocates the 0x618 bytes, resetStatHandler initialises them and
 * resetAwardHandler resets them between races.  Only the fields the functions in this
 * file reach are named; the node pool at 0x44 holds the 0x14-byte stat nodes the
 * free list at 0x29C hands out. */
typedef struct {
    /* 0x00 */ u32 unknown0[4];
    /* 0x10 */ u8 paused;         // fn_801CCBA4 sets it, fn_801CCBB4 clears it
    /* 0x11 */ s8 player[4];      // one byte per player slot
    /* 0x15 */ u8 pad15[3];
    /* 0x18 */ void *entries;     // entryCount stat entries, one pointer each
    /* 0x1C */ s32 entryCount;
    /* 0x20 */ u8 pad20[0x24];
    /* 0x44 */ u8 nodes[0x258];   // stat node pool, cleared by a reset
    /* 0x29C */ void *freeList;   // first free node, null when none
    /* 0x2A0 */ void **freeListTail; // last node's next link, &freeList when empty
    /* 0x2A4 */ s32 unknown2A4;
    /* 0x2A8 */ s32 pendingPlace; // place of the award queued, see fn_801CD4CC
    /* 0x2AC */ s32 newCount;
    /* 0x2B0 */ s32 newEntry;     // -1 while none
    /* 0x2B4 */ s32 unknown2B4;   // -1 while none
    /* 0x2B8 */ f32 value;        // lbl_80562A08 (-999) while unset
    /* 0x2BC */ u8 hasValue;
    /* 0x2BD */ u8 pad2BD[3];
    /* 0x2C0 */ s32 state;        // fn_801CE75C tests it for 3
    /* 0x2C4 */ f32 unknown2C4;
    /* 0x2C8 */ void *pool;       // 0x74-byte records, fn_802AE0E0 clears +0x68
    /* 0x2CC */ void *actor[3];   // a reset sets their +0x4A and clears +0x4C
    /* 0x2D8 */ s32 unknown2D8;
    /* 0x2DC */ u8 pad2DC[0x29C];
    /* 0x578 */ f32 floats[10][4]; // reset to {1,0,0,0}
} StatHandler;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80019BA8(void);
extern int fn_8000DA10(void);
extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_800167F4(void);
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
extern int fn_80128668(void *);
#pragma push
#pragma small_data off
extern char lbl_80338024[];
extern char lbl_80338038[];
#pragma pop
extern int fn_8001BF34(int);
extern void fn_8001BF0C(int, f32);
extern int fn_80161C38(void);
extern void pushAwardsRaceTime(int, int, f32);
extern s32 *lbl_8055E884;
extern unsigned char *fn_801EA9A0();
extern int fn_801EA994(void);
extern void fn_801CCBA4(void);
extern void fn_801CCAEC(int);
extern void fn_801CCB48(int);
extern void fn_801CCCAC(void);
extern int fn_801CE874(int);
extern void fn_801CCDAC(int, int, int);
extern void fn_801CD130(int, int, f32);
extern void fn_801CD4CC(int, int);
extern signed char lbl_8055E880;
extern void fn_801CEA28(void *);
extern void fn_801CEB94(void *);
typedef struct {
    s32 field0;
    s32 field4;
    s32 field8;
} Struct_801CE670;
void fn_801CDE00(s32);
void fn_801CE6CC(void);
void fn_801CE6A0(void);
void fn_801CE69C(void);
void fn_801CE698(void);
void fn_801CE670(Struct_801CE670*, s32, s32);
void fn_801CE6A4(Struct_801CE670*, s32, s32);
void fn_801CE6D0(Struct_801CE670*, s32, s32);
extern void fn_801CB3F8(void);
extern void fn_801CC470(void);
extern void resetAwardHandler(void);
void fn_801CB2D8(void) {
    /* When not blocked and in the default state, mark active and run setup handlers. */
    if (fn_80019BA8() == 0) {
        switch (fn_80161C38()) {
        case 0:
            lbl_8055E880 = 1;
            fn_801CC470();
            fn_801CB3F8();
            break;
        default:
            break;
        }
    }
}

void fn_801CB320(void) {
    /* Unless a global pause/block guard is set, reset the stats handler state
       and refresh the flags of every active participant. */
    if (fn_80019BA8() || fn_80161C38()) return;
    resetAwardHandler();
    fn_801CB3F8();
}

void fn_801CB360(int participantIndex) {
    /* Update one participant if awards/overlays are active and in the default mode. */
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCAEC(participantIndex);
done:
    return;
}

/* If not blocked and in the active mode, triggers the per-player handler fn_801CCB48 for this index. */
void fn_801CB3AC(int playerIndex) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCB48(playerIndex);
done:
    return;
}

void fn_801CB3F8(void) {
    /* Refresh per-participant flags by iterating all active participants,
       unless the relevant global pause/block flag or another guard is set. */
    int participantCount, participantIndex;
    if (fn_80019BA8() || fn_80161C38()) return;
    participantCount = fn_801EA994();
    for (participantIndex = 0; participantIndex < participantCount; participantIndex++) fn_801CCAEC(participantIndex);
}

void fn_801CB464(void) {
#define BootOptionBit_400 fn_80019BA8
#define ChallengeSubTask_Active fn_80161C38
#define StatManager_Pause fn_801CCBA4
    /* Pause the stat manager unless a boot option or an active challenge sub-task blocks it. */
    if (BootOptionBit_400() || ChallengeSubTask_Active()) return;
    StatManager_Pause();
#undef BootOptionBit_400
#undef ChallengeSubTask_Active
#undef StatManager_Pause
}

extern void fn_801CCBB4(void);
/* If not blocked and in the default mode, clear the byte flag at offset 0x10
 * of the game-state object (fn_801CCBB4). */
void fn_801CB4A0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBB4();
}

extern void fn_801CCBC4(void);
void fn_801CB4DC(void) {
    /* Finalize pending awards when no boot option or challenge sub-task is blocking. */
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBC4();
}

/* If not blocked and in the default mode, clears the active flag and runs cleanup. */
void fn_801CB518(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    lbl_8055E880 = 0;
    fn_801CCCAC();
}

/* Queue an award event for a player if awards are active and the player entry is valid. */
void fn_801CB55C(int playerIndex, int param) {
    if (fn_80019BA8() || fn_80161C38()) return;
    if (fn_801CE874(playerIndex)) {
        fn_801CCDAC(0x22205, playerIndex, param);
        fn_801CD4CC(playerIndex, param);
    }
}

extern void resetAwardHandler(void);
extern void fn_801CC470(void);
extern void pushAward(int, int, int);
#pragma scheduling invalid_target
// fn_801CB5DC matches with invalid_target scheduling to preserve argument-copy order.
void fn_801CB5DC(int arg0, int arg1, int arg2) {
    /* If not blocked and in state 0, forward (arg0, arg1, arg2) to pushAward. */
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    pushAward(arg0, arg1, arg2);
done:
    return;
}
#pragma scheduling on
void fn_801CB648(int playerIndex, int arg1, f32 farg0) {
    /* Conditionally forwards to pushAwardsRaceTime when not blocked by fn_80019BA8 and
     * fn_80161C38 indicates case 0. */
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    pushAwardsRaceTime(playerIndex, arg1, farg0);
done:
    return;
}
#pragma scheduling on
void fn_801CB6B4(void) {
    /* Gate check shared by the neighbouring event dispatchers: probe the flag from fn_80019BA8,
       and only when it is clear probe fn_80161C38; no action follows either result. */
    if (fn_80019BA8() == 0) {
        if (fn_80161C38() != 0) return;
    }
}

/* Dispatches an event through fn_801CCDAC when not in a blocked state. */
void fn_801CB6E4(int eventId, int contextId, int param) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCDAC(eventId, contextId, param);
done:
    return;
}

/* If not blocked by fn_80019BA8, forwards the call to fn_801CD130 when fn_80161C38() returns 0. */
void fn_801CB750(int arg0, int arg1, f32 farg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD130(arg0, arg1, farg0);
done:
    return;
}

extern void fn_801CD970(int);
/* If not blocked by fn_80019BA8 and mode fn_80161C38 is 0, perform action fn_801CD970. */
void fn_801CB7BC(int arg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD970(arg0);
done:
    return;
}

extern void fn_801CDDCC(void);
/* Set up the stats/awards manager's stat block at startup, unless a boot option
   (bit 0x400) or an active challenge sub-task is holding the game in another mode. */
void fn_801CB808(void) {
#define BootOptionBit_400 fn_80019BA8 /* lbl_8055D5A0 bit 10, set by a boot option */
#define ChallengeSubTask_Active fn_80161C38 /* the manager's current sub-task, lbl_8055E300 */
#define StatManager_InitBlock fn_801CDDCC /* build the manager's stat block once tables are loaded */
    if (BootOptionBit_400() || ChallengeSubTask_Active()) return;
    StatManager_InitBlock();
#undef BootOptionBit_400
#undef ChallengeSubTask_Active
#undef StatManager_InitBlock
}

extern void fn_801CE6F8(void);
/* Per-frame tick of the awards/stat manager while the awards screen sits in its
   waiting step (fn_800064A8 runs this for state 2): fn_801CE6F8 refreshes the
   results panel hanging off the manager (stat rows, names, times, progress) and
   fires the screen's finish message once that panel reaches its done state.
   Nothing runs while a boot option (bit 0x400) or a live challenge sub-task
   keeps the stat manager off altogether. */
void fn_801CB844(void) {
#define BootOptionBit_400 fn_80019BA8 /* lbl_8055D5A0 bit 10, set by a boot option */
#define ChallengeSubTask_Active fn_80161C38 /* the manager's current sub-task, lbl_8055E300 */
#define StatManager_Update fn_801CE6F8 /* refresh the results panel; idle while the stat tables load */
    if (BootOptionBit_400() || ChallengeSubTask_Active()) return;
    StatManager_Update();
#undef BootOptionBit_400
#undef ChallengeSubTask_Active
#undef StatManager_Update
}

extern int fn_801CE75C(void);
s32 fn_801CB880(void) {
    /* Gate the awards screen asks before letting the confirm button (event 0x58)
     * move it out of its waiting step (fn_80006580, state 1 -> 2 -> 3): 1 when
     * there is nothing left to wait for.  The award stat manager is not running
     * at all while the boot option bit 0x400 is set or the challenge sub-task
     * manager has a sub-task up, and otherwise the wait is over once the stat
     * manager has finished - its block state 3, or nothing loaded (fn_801CE75C). */
#define BootOptionBit_400 fn_80019BA8 /* lbl_8055D5A0 bit 10, set by a boot option */
#define ChallengeSubTask_Active fn_80161C38 /* the manager's current sub-task, lbl_8055E300 */
#define StatManager_IsComplete fn_801CE75C
    if ((BootOptionBit_400() != 0) || (ChallengeSubTask_Active() != 0)) {
        return 1;
    }
    return StatManager_IsComplete();
#undef BootOptionBit_400
#undef ChallengeSubTask_Active
#undef StatManager_IsComplete
}

extern void fn_801CE7A0(void);
/* Run the award stat manager's teardown, unless the boot option bit or an active
 * challenge sub-task means the stats should be left in place. */
void fn_801CB8C0(void) {
#define BootOptionBit_400 fn_80019BA8
#define ChallengeSubTask_Active fn_80161C38
#define StatManager_ReleaseStats fn_801CE7A0
    if (BootOptionBit_400() || ChallengeSubTask_Active()) return;
    StatManager_ReleaseStats();
#undef BootOptionBit_400
#undef ChallengeSubTask_Active
#undef StatManager_ReleaseStats
}

void fn_801CB8FC(void) {
    /* Check whether a stat context/index is currently available (wrapper around stat access check). */
    fn_801CE8CC();
}

#pragma dont_inline on
/* Award_statMatches: 1 when the stat object a slot of the StatHandler's stat
   array points to carries the stat type being looked for (its type word at
   +0x04, e.g. 0x22205 or 0x20507). The Awards code scans the array
   (lbl_8055E884 + 0x18, count at +0x1C) with this and reports
   "Awards: can't find stat info for type %d!" when no slot matches. */
int fn_801CB900(int *statSlot, int statType) {
#define Award_statGetType fn_8001BD28
    int result = 0;
    if (statSlot != 0 && statType == Award_statGetType(*statSlot)) {
        result = 1;
    }
#undef Award_statGetType
    return result;
}
#pragma dont_inline reset

#pragma push
#pragma use_lmw_stmw off
extern char lbl_80337AC8[];
extern char lbl_80338010[];
extern void *fn_801284F8(s32, void *);
extern s32 fn_80012854(void);
extern void *fn_8001C070(void *, s32, s32, s32, s32);
extern void *fn_8001BE94(void *, s32, s32, s32, s32);
extern void fn_8001BC38(void *, s32, s32, s32, s32);
extern s32 fn_8001BCF0(void *);
extern s32 fn_8001BD6C(void *, void *);
extern void Abend_Panic(char *, s32);
#pragma opt_propagation off
void *fn_801CB954(s32 arg0, void *arg1, s32 arg2) {
    struct Ctx {
        void *arg1;
        s32 arg0;
        char *base;
        void *result;
        s32 i;
        s32 j;
        s32 best;
        s32 best2;
    } c;
    s32 mode;
    void *item;

    mode = arg0 & 0x300;
    c.arg1 = arg1;
    c.arg0 = arg0;
    c.base = lbl_80337AC8;

    switch (mode) {
    default:
        ((void (*)(char *, ...))Abend_Panic)(c.base, c.arg0);
    case 0x200: {
        s32 sp2[9], sp[9];
        c.result = fn_801284F8(0x10, c.base + 0x40);
        if (c.result) {
            item = fn_801284F8(0x24, c.base + 0x4C);
            if (item) {
                item = fn_8001C070(item, fn_8000DA10(), c.arg0, *(s32 *)c.arg1, *(s32 *)((char *)c.arg1 + 4));
            }
            *(void **)c.result = item;
            *(void **)((char *)c.result + 4) = lbl_80338024;
            *(void **)((char *)c.result + 8) = 0;
            *(s32 *)((char *)c.result + 0xC) = 0;
            c.i = 0;
            c.j = 0;
            c.best2 = -1;
            c.best = -1;
            for (c.j = 0; c.j < 3; c.j++) {
                for (c.i = 0; c.i < fn_80012854(); c.i++) {
                    if (c.i == *(s32 *)c.arg1 && c.j == *(s32 *)((char *)c.arg1 + 4)) {
                        continue;
                    }
                    fn_8001BC38(sp, fn_8000DA10(), c.arg0, c.i, c.j);
                    if (fn_8001BCF0(sp)) {
                        if (c.best < 0) {
                            c.best = c.i;
                            c.best2 = c.j;
                        } else {
                            fn_8001BC38(sp2, fn_8000DA10(), c.arg0, c.best, c.best2);
                            if (fn_8001BD6C(sp, sp2)) {
                                c.best = c.i;
                                c.best2 = c.j;
                            }
                        }
                    }
                }
            }
            if (c.best >= 0) {
                item = fn_801284F8(0x24, c.base + 0x4C);
                if (item) {
                    item = fn_8001C070(item, fn_8000DA10(), c.arg0, c.best, c.best2);
                }
                *(void **)((char *)c.result + 8) = item;
            }
        }
        return c.result;
    }
    case 0x100: {
        s32 sp2[9], sp[9];
        c.result = fn_801284F8(0x10, c.base + 0x58);
        if (c.result) {
            item = fn_801284F8(0x24, c.base + 0x64);
            if (item) {
                item = fn_8001BE94(item, fn_8000DA10(), c.arg0, *(s32 *)c.arg1, *(s32 *)((char *)c.arg1 + 4));
            }
            *(void **)c.result = item;
            *(void **)((char *)c.result + 4) = lbl_80338010;
            *(void **)((char *)c.result + 8) = 0;
            *(s32 *)((char *)c.result + 0xC) = 0;
            c.i = 0;
            c.j = 0;
            c.best2 = -1;
            c.best = -1;
            for (c.j = 0; c.j < 3; c.j++) {
                for (c.i = 0; c.i < fn_80012854(); c.i++) {
                    if (c.i == *(s32 *)c.arg1 && c.j == *(s32 *)((char *)c.arg1 + 4)) {
                        continue;
                    }
                    fn_8001BC38(sp, fn_8000DA10(), c.arg0, c.i, c.j);
                    if (fn_8001BCF0(sp)) {
                        if (c.best < 0) {
                            c.best = c.i;
                            c.best2 = c.j;
                        } else {
                            fn_8001BC38(sp2, fn_8000DA10(), c.arg0, c.best, c.best2);
                            if (fn_8001BD6C(sp, sp2)) {
                                c.best = c.i;
                                c.best2 = c.j;
                            }
                        }
                    }
                }
            }
            if (c.best >= 0) {
                item = fn_801284F8(0x24, c.base + 0x64);
                if (item) {
                    item = fn_8001BE94(item, fn_8000DA10(), c.arg0, c.best, c.best2);
                }
                *(void **)((char *)c.result + 8) = item;
            }
        }
        return c.result;
    }
    }
}
#pragma opt_propagation reset

void *__dt__Q34nw4r2ef6EffectFv_801CBCA4(void *arg0, int arg1) {
    /* Destructor for nw4r2ef::Effect variant: restore vtable at +4, run cleanup, and optionally free. */
    extern void fn_801CBD04(void *);
    if (arg0) {
        *(void **)((char *)arg0 + 4) = lbl_80338038;
        fn_801CBD04(arg0);
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801CBD04(void *arg0) {
    /* If the object owns a buffer at offset 0, free it and clear the pointer. */
    void *ownedBuffer = *(void **)arg0;
    if (ownedBuffer != NULL) {
        fn_80128668(ownedBuffer);
        *(void **)arg0 = NULL;
    }
}

/* Bounded string copy the game inlines everywhere: copies src into dst including the
   terminator, at most n bytes; when n runs out the last byte written is replaced by 0. */
#define STRNCPY_801CBD48(dst, src, n)                  \
    do {                                               \
        const char *s_ = (const char *)(src);          \
        int n_ = (n);                                  \
        char *d_ = (char *)(dst);                      \
        while ((*d_++ = *s_++) != 0) {                 \
            if (--n_ <= 0) { d_[-1] = 0; break; }      \
        }                                              \
    } while (0)
extern void *fn_8001285C(s32);
extern char *fn_80131234(char *);
extern void fn_80130978(void *, s32, f32);
extern void fn_801308F4(void *, s32, s32);
extern char *__AXGetStackHead(s32);
extern f32 fn_8001BEE8(void *);
extern void fn_8001BB0C(int, s32, s32);
extern char *fn_8000DB34(int);
extern void fn_802ADFF4(s32, s32);
extern void fn_802AE02C(s32, s32);
extern void fn_802AE168(s32);
extern f32 lbl_805629E0;
extern f32 lbl_805629E8;
extern f32 lbl_805629EC;
extern f32 lbl_805629F0;
extern f32 lbl_805629F4;
extern f32 lbl_805629F8;
extern f32 lbl_80562A00;
#pragma push
#pragma processor 750
void fn_801CBD48(void *arg0, void *arg1) {
    extern char lbl_8055AB30[4];
    extern char lbl_8055AB34[4];
    extern f32 lbl_80558DC0[];
    extern f32 lbl_80558DC4[];
    extern void *fn_8001BB58(s32, s32, s32);
    char *strings = lbl_80337AC8;
    u8 *obj = (u8 *)arg0;
    s32 *key = (s32 *)arg1;
    s32 sp8[9];
    int i;
    u8 *slot;
    register char *s1;
    register char *s2;
    int valid;
    s32 idx;
    int isX;

    if (*(s32 *)(obj + 8) == 0 || lbl_8055E884 == 0) {
        return;
    }
    fn_8001BE94(sp8, fn_8000DA10(), 0x20507, key[0], key[1]);
    isX = *(s32 *)((u8 *)fn_8001285C(key[0]) + 8) == 0x180302;
    s1 = isX ? fn_80131234(strings + 0xC4) : fn_80131234(strings + 0xE0);
    s2 = isX ? fn_80131234(strings + 0x108) : fn_80131234(strings + 0x120);
    if (isX) {
        STRNCPY_801CBD48(obj + 0x276, fn_80131234(strings + 0x140), 0x40);
    } else {
        STRNCPY_801CBD48(obj + 0x276, fn_80131234(strings + 0x154), 0x40);
    }
    if (*((u8 *)lbl_8055E884 + 0x2BC) != 0 &&
        ((s32 (*)(void *, f32))fn_8001BF34)(sp8, *(f32 *)((u8 *)lbl_8055E884 + 0x2B8)) != 0) {
        STRNCPY_801CBD48(obj + 0x19C, lbl_8055AB30, 100);
        STRNCPY_801CBD48(obj + 0x200, s1, 100);
        fn_80130978(obj + 0x188, 0x14, *(f32 *)((u8 *)lbl_8055E884 + 0x2B8));
    } else {
        STRNCPY_801CBD48(obj + 0x200, lbl_8055AB30, 100);
        STRNCPY_801CBD48(obj + 0x19C, s2, 100);
        if (fn_8001BCF0(sp8)) {
            fn_80130978(obj + 0x188, 0x14, fn_8001BEE8(sp8));
        } else {
            fn_80130978(obj + 0x188, 0x14, -lbl_80558DC0[0]);
        }
    }
    fn_801308F4(obj + 0x14C, 0x14, *(s32 *)((u8 *)lbl_8055E884 + 0x2AC));
    {
        s32 v = *(s32 *)((u8 *)lbl_8055E884 + 0x2B0);
        STRNCPY_801CBD48(obj + 0x160, v != -1 ? __AXGetStackHead(v) : lbl_8055AB30, 0x14);
    }
    if (*((u8 *)lbl_8055E884 + 0x2BC) != 0) {
        fn_80130978(obj + 0x174, 0x14, *(f32 *)((u8 *)lbl_8055E884 + 0x2B8));
    } else {
        fn_80130978(obj + 0x174, 0x14, -lbl_80558DC0[0]);
    }
    fn_8001BB0C(fn_8000DA10(), key[0], key[1]);
    slot = obj + 0x20;
    for (i = 0; i < 5; i++, slot += 0x3C) {
        s32 *e = (s32 *)((void *(*)(int, s32, s32, s32))fn_8001BB58)(fn_8000DA10(), key[0], key[1], i);
        if (e != 0) {
            fn_801308F4(slot, 0x14, e[1]);
            STRNCPY_801CBD48(slot + 0x14, e[2] != -1 ? __AXGetStackHead(e[2]) : lbl_8055AB30, 0x14);
            fn_80130978(slot + 0x28, 0x14, *(f32 *)&e[3]);
        } else {
            STRNCPY_801CBD48(slot, lbl_8055AB34, 0x14);
            STRNCPY_801CBD48(slot + 0x14, lbl_8055AB34, 0x14);
            fn_80130978(slot + 0x28, 0x14, -lbl_80558DC0[0]);
        }
    }
    STRNCPY_801CBD48(obj + 0x264, fn_8000DB34(fn_8000DA10()), 0x12);
    valid = 0;
    idx = *(s32 *)((u8 *)lbl_8055E884 + 0x2B4);
    if (idx >= 0 && (u32)idx < 5) {
        valid = 1;
    }
    switch (*(s32 *)obj) {
    case 0:
        fn_802ADFF4(*(s32 *)(obj + 8), *(s32 *)(obj + 0x1C));
        *(s32 *)obj = 1;
        break;
    case 1: {
        u8 *o;
        s32 k;
        if (*(s32 *)(obj + 0x18) == 0) {
            break;
        }
        o = *(u8 **)(obj + 0xC);
        if (o != 0) {
            o[0x4A] = 0;
            o[0x4B] = 1;
            o[0x49] = 1;
        }
        k = *(s32 *)((u8 *)lbl_8055E884 + 0x2B4);
        if (k >= 0 && *(s32 *)(obj + 0x18) - 1 > k) {
            break;
        }
        fn_802AE02C(*(s32 *)(obj + 8), *(s32 *)(obj + 0x1C));
        o = *(u8 **)(obj + 0xC);
        if (o != 0) {
            o[0x4A] = 1;
            o[0x4C] = 0;
        }
        if (valid) {
            o = *(u8 **)(obj + 0x10);
            if (o != 0) {
                o[0x49] = 1;
                o[0x4B] = 0;
                o[0x4A] = 0;
            }
        } else {
            o = *(u8 **)(obj + 0x14);
            if (o != 0) {
                o[0x49] = 1;
                o[0x4B] = 0;
                o[0x4A] = 0;
            }
        }
        *(s32 *)obj = 2;
        break;
    }
    case 2: {
        f32 t = lbl_805629E0 + *(f32 *)(obj + 4);
        *(f32 *)(obj + 4) = (lbl_805629E4 < t) ? lbl_805629E4 : t;
        if ((f32)__fabs(*(f32 *)(obj + 4) - lbl_805629E4) <= lbl_80558DC4[0]) {
            *(s32 *)obj = 3;
        }
        break;
    }
    case 3:
        break;
    default:
        ((void (*)(char *, ...))Abend_Panic)(strings + 0x16C, *(s32 *)obj);
        break;
    }
    if (valid) {
        f32 a = lbl_805629E4 + lbl_805629E8 * *(f32 *)(obj + 4);
        f32 b = lbl_805629EC * *(f32 *)(obj + 4);
        f32 c = lbl_805629F0 * *(f32 *)(obj + 4);
        f32 d = lbl_805629F4 * *(f32 *)(obj + 4);
        f32 g = lbl_805629F8;
        *(f32 *)(obj + 0x2CC) = b;
        *(f32 *)(obj + 0x2B8) = a;
        *(f32 *)(obj + 0x2C8) = a;
        *(f32 *)(obj + 0x2D8) = a;
        *(f32 *)(obj + 0x2DC) = c;
        *(f32 *)(obj + 0x2E8) = a;
        *(f32 *)(obj + 0x2EC) = d;
        *(f32 *)(obj + idx * 16 + 0x2F8) = a;
        *(f32 *)(obj + idx * 16 + 0x2FC) = g * *(f32 *)(obj + 4);
    }
    {
        f32 one = lbl_805629FC;
        f32 zero = lbl_805629E4;
        *(f32 *)(obj + 0x34C) = one;
        *(f32 *)(obj + 0x348) = zero;
        *(f32 *)(obj + 0x350) = one;
        *(f32 *)(obj + 0x354) = one;
        if (!valid) {
            *(f32 *)(obj + 0x350) = one + lbl_80562A00 * *(f32 *)(obj + 4);
        }
    }
    fn_802AE168(*(s32 *)(obj + 8));
}
#pragma pop

extern int fn_80145E70(void *);
extern int fn_8001BA74(int);
extern void fn_801CC8FC(void *);
extern void fn_801CC8EC(void *);
extern void *fn_801CC7A0(void *);
extern void **fn_801CC784(void *);
extern void *fn_801CB954();
extern void fn_801CC768(void *, float);
extern void resetStatHandler(void *);
extern void *fn_80207848(void *, int);
extern void *ArtSetGet(void *);
extern float lbl_80562A04;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801CC470(void) {
    register void *object;
    register int i;
    register s32 *table;
    register void *item;
    void **slot;
    void *field;

    object = fn_801284F8(0x618, lbl_80337AC8 + 0x190);
    if (object != 0) {
        fn_801CC8FC((char *)object + 0x18);
        fn_801CC8EC((char *)object + 0x29C);
        fn_801CC7A0((char *)object + 0x2C0);
        *(int *)((char *)object + 0x40) = fn_80145E70(lbl_80337AC8 + 0x19C);
        *(int *)((char *)object + 0x2A4) = fn_80145E70(lbl_80337AC8 + 0x1AC);
        *((unsigned char *)object + 0x10) = 0;
        table = __AXFXGetLfoSinTable_801769CC();
        *(s32 *)object = table[0];
        *((s32 *)object + 1) = table[2];
        *((unsigned char *)object + 0x11) = 1;
        *((unsigned char *)object + 0x12) = 1;
        *((unsigned char *)object + 0x13) = 1;
        *((unsigned char *)object + 0x14) = 1;
        i = 1;
        do {
            int mode = fn_8001BA74(i);
            item = ((void *(*)(int, void *))fn_801CB954)(mode, object);
            slot = fn_801CC784((char *)object + 0x18);
            i++;
            *slot = item;
        } while (i <= 7);
        field = fn_80207848(lbl_80337AC8 + 0x1BC, 1);
        *(void **)((char *)object + 8) = field;
        if (field != 0)
            fn_801CC768(field, lbl_80562A04);
        *(void **)((char *)object + 0xC) = ArtSetGet(lbl_80337AC8 + 0x1C8);
        resetStatHandler(object);
    }
    lbl_8055E884 = (s32 *)object;
}
#pragma pop
/* Prepares a freshly created award stat handler for its first race: hands every
 * entry of the current stat set back to its record, empties the node pool and
 * the free list that hands its nodes out, and returns the handler's counters,
 * its queued award and the ten float groups at the end of it to their starting
 * values.  The record pool the award objects share is cleared and those three
 * objects are told to start over.  fn_801CC470 (StatHandler::Create) calls it on
 * the new handler before lbl_8055E884 points at it; resetAwardHandler is the same
 * reset once the handler is installed.  Nothing happens while it is paused.
 * The reset values are written through volatile pointers, so the compiler keeps
 * every one of them, in this order, in the handler. */
void resetStatHandler(void *object) {
    StatHandler *handler = (StatHandler *)object;
    register s32 byteOffset;
    register s32 index;
    s32 invalidIndex;
    void *statEntry;
    void *actor;
    void *pool;
    f32 one;
    f32 zero;
    f32 unsetValue;
    if (handler->paused != 0) return;
    index = 0;
    byteOffset = 0;
    while (index < handler->entryCount) {
        statEntry = *(void **)((u8 *)handler->entries + byteOffset);
        if (statEntry != 0) fn_8001BE70(*(void **)statEntry);
        byteOffset += 4;
        ++index;
    }
    handler->freeListTail = &handler->freeList;
    index = 0;
    handler->freeList = (void *)index;
    memset(handler->nodes, index, sizeof(handler->nodes));
    zero = lbl_805629FC;
    invalidIndex = -1;
    one = lbl_805629E4;
    unsetValue = lbl_80562A08;
    *(volatile s32 *)&handler->pendingPlace = index;
    *(volatile s32 *)&handler->newCount = index;
    *(volatile s32 *)&handler->newEntry = invalidIndex;
    *(volatile s32 *)&handler->unknown2B4 = invalidIndex;
    *(volatile f32 *)&handler->value = unsetValue;
    *(volatile u8 *)&handler->hasValue = index;
    *(volatile s32 *)&handler->state = index;
    *(volatile f32 *)&handler->unknown2C4 = zero;
    *(volatile s32 *)&handler->unknown2D8 = index;
    *(volatile f32 *)&handler->floats[0][0] = one;
    *(volatile f32 *)&handler->floats[0][1] = zero;
    *(volatile f32 *)&handler->floats[0][2] = zero;
    *(volatile f32 *)&handler->floats[0][3] = zero;
    *(volatile f32 *)&handler->floats[1][0] = one;
    *(volatile f32 *)&handler->floats[1][1] = zero;
    *(volatile f32 *)&handler->floats[1][2] = zero;
    *(volatile f32 *)&handler->floats[1][3] = zero;
    *(volatile f32 *)&handler->floats[2][0] = one;
    *(volatile f32 *)&handler->floats[2][1] = zero;
    *(volatile f32 *)&handler->floats[2][2] = zero;
    *(volatile f32 *)&handler->floats[2][3] = zero;
    *(volatile f32 *)&handler->floats[3][0] = one;
    *(volatile f32 *)&handler->floats[3][1] = zero;
    *(volatile f32 *)&handler->floats[3][2] = zero;
    *(volatile f32 *)&handler->floats[3][3] = zero;
    *(volatile f32 *)&handler->floats[4][0] = one;
    *(volatile f32 *)&handler->floats[4][1] = zero;
    *(volatile f32 *)&handler->floats[4][2] = zero;
    *(volatile f32 *)&handler->floats[4][3] = zero;
    *(volatile f32 *)&handler->floats[5][0] = one;
    *(volatile f32 *)&handler->floats[5][1] = zero;
    *(volatile f32 *)&handler->floats[5][2] = zero;
    *(volatile f32 *)&handler->floats[5][3] = zero;
    *(volatile f32 *)&handler->floats[6][0] = one;
    *(volatile f32 *)&handler->floats[6][1] = zero;
    *(volatile f32 *)&handler->floats[6][2] = zero;
    *(volatile f32 *)&handler->floats[6][3] = zero;
    *(volatile f32 *)&handler->floats[7][0] = one;
    *(volatile f32 *)&handler->floats[7][1] = zero;
    *(volatile f32 *)&handler->floats[7][2] = zero;
    *(volatile f32 *)&handler->floats[7][3] = zero;
    *(volatile f32 *)&handler->floats[8][0] = one;
    *(volatile f32 *)&handler->floats[8][1] = zero;
    *(volatile f32 *)&handler->floats[8][2] = zero;
    *(volatile f32 *)&handler->floats[8][3] = zero;
    pool = *(void * volatile *)&handler->pool;
    *(volatile f32 *)&handler->floats[9][0] = one;
    *(volatile f32 *)&handler->floats[9][1] = zero;
    *(volatile f32 *)&handler->floats[9][2] = zero;
    *(volatile f32 *)&handler->floats[9][3] = zero;
    if (pool != 0) ((void (*)(void *))fn_802AE0E0)(pool);
    actor = handler->actor[0];
    if (actor != 0) { ((u8 *)actor)[0x4A] = 1; ((u8 *)actor)[0x4C] = 0; }
    actor = handler->actor[1];
    if (actor != 0) { ((u8 *)actor)[0x4A] = 1; ((u8 *)actor)[0x4C] = 0; }
    actor = handler->actor[2];
    if (actor != 0) { ((u8 *)actor)[0x4A] = 1; ((u8 *)actor)[0x4C] = 0; }
}
#pragma scheduling on

void fn_801CC768(void *object, f32 value) {
    /* Set this object's float field at +8 to value, flagging +0x4D when it changes. */
    if (value != *(f32 *)((u8 *)object + 8)) {
        *(f32 *)((u8 *)object + 8) = value;
        *(u8 *)((u8 *)object + 0x4D) = 1;
    }
}

/* A growable array of pointers: `data` holds the slots, `count` the number used. */
typedef struct PtrVec { void **data; s32 count; } PtrVec;

void **fn_801CC784(void *vec) {
    /* Reserve the next slot of a pointer vector: return the address of slot `count` and advance the vector's count. */
    s32 index = ((PtrVec *)vec)->count;
    void **data = ((PtrVec *)vec)->data;
    ((PtrVec *)vec)->count = index + 1;
    return (void **)((s32)data + (index << 2));
}

extern void *memset(void *, int, unsigned long);
/* Initialize a sound-name sub-block: clear the four leading int fields, then fill every fixed-size name slot with the placeholder string "zzz". */ void *fn_801CC7A0(void *block) {
    unsigned char *endPtr;
    unsigned char *slot;
    long zero;
    unsigned char *base;
    zero = 0;
    base = (unsigned char *)block;
    endPtr = base + 0x14C;
    slot = base + 0x20;
    *(long *)(base + 8) = zero;
    *(long *)(base + 0xC) = zero;
    *(long *)(base + 0x10) = zero;
    *(long *)(base + 0x14) = zero;
    do {
        memset(slot, 0x7A, 3);
        slot[3] = zero;
        memset(slot + 0x14, 0x7A, 3);
        slot[0x17] = zero;
        memset(slot + 0x28, 0x7A, 3);
        slot[0x2B] = zero;
        slot += 0x3C;
    } while (slot < (base + 0x14C));
    memset((base + 0x14C), 0x7A, 3);
    base[0x14F] = 0;
    memset(base + 0x160, 0x7A, 3);
    base[0x163] = 0;
    memset(base + 0x174, 0x7A, 3);
    base[0x177] = 0;
    memset(base + 0x188, 0x7A, 3);
    base[0x18B] = 0;
    memset(base + 0x19C, 0x7A, 3);
    base[0x19F] = 0;
    memset(base + 0x200, 0x7A, 3);
    base[0x203] = 0;
    memset(base + 0x264, 0x7A, 3);
    base[0x267] = 0;
    memset(base + 0x276, 0x7A, 3);
    base[0x279] = 0;
    return block;
}

void fn_801CC8EC(void *arg0) {
    /* Initialize the stat-node free-list head: empty head at +0 and tail pointing back at the head at +4. */
    typedef struct {
        void *head;
        void **tail;
    } FreeListHead;
    FreeListHead *list = (FreeListHead *)arg0;
    list->tail = &list->head;
    list->head = 0;
}

void fn_801CC8FC(void *object) {
    /* Initialize a collection object: point its items at the inline storage
     * at +0xC, set the element count (+0x4) to 0 and its capacity (+0x8) to 7. */
    *(int *)object = (int)((char *)object + 0xC);
    *(int *)((char *)object + 8) = 7;
    *(int *)((char *)object + 4) = 0;
}

/* The StatHandler layout is at the top of this file, above resetStatHandler. */

#pragma scheduling invalid_target
/* Resets the award stat handler in lbl_8055E884 between races: hands every entry
 * of the current stat set back to its record, empties the node pool and its free
 * list, and returns the handler's counters, its queued award and the ten float
 * groups at the end of it to their starting values.  The three objects it draws
 * the awards with are told to start over, and the record pool they share is
 * cleared.  Nothing happens while the handler is paused. */
/* Reset the award stat handler (lbl_8055E884) between races: release entries, clear the node pool and free list, restore counters/values/floats, and restart the three actors. */ void resetAwardHandler(void) {
    void *entry;
    f32 one;
    f32 zero;
    register s32 index;
    register u32 byteOffset;
    f32 unset;
    register StatHandler *handler;
    void *actor;
    void *pool;

    handler = (StatHandler *)lbl_8055E884;
    if (handler->paused != 0) return;
    index = 0;
    byteOffset = 0;
    for (; index < handler->entryCount; byteOffset += 4, ++index) {
        entry = *(void **)((char *)handler->entries + byteOffset);
        if (entry) fn_8001BE70(*(void **)entry);
    }
    /* index is still zero from here on: the reset values are written from it. */
    index = 0;
    handler->freeList = (void *)index;
    handler->freeListTail = &handler->freeList;
    memset(handler->nodes, index, sizeof(handler->nodes));
    handler->pendingPlace = index;
    unset = lbl_80562A08;
    handler->newCount = index;
    zero = lbl_805629FC;
    handler->newEntry = -1;
    one = lbl_805629E4;
    handler->unknown2B4 = -1;
    handler->value = unset;
    handler->hasValue = index;
    handler->state = index;
    handler->unknown2C4 = zero;
    handler->unknown2D8 = index;
    handler->floats[0][0] = one; handler->floats[0][1] = zero;
    handler->floats[0][2] = zero; handler->floats[0][3] = zero;
    handler->floats[1][0] = one; handler->floats[1][1] = zero;
    handler->floats[1][2] = zero; handler->floats[1][3] = zero;
    handler->floats[2][0] = one; handler->floats[2][1] = zero;
    handler->floats[2][2] = zero; handler->floats[2][3] = zero;
    handler->floats[3][0] = one; handler->floats[3][1] = zero;
    handler->floats[3][2] = zero; handler->floats[3][3] = zero;
    handler->floats[4][0] = one; handler->floats[4][1] = zero;
    handler->floats[4][2] = zero; handler->floats[4][3] = zero;
    handler->floats[5][0] = one; handler->floats[5][1] = zero;
    handler->floats[5][2] = zero; handler->floats[5][3] = zero;
    handler->floats[6][0] = one; handler->floats[6][1] = zero;
    handler->floats[6][2] = zero; handler->floats[6][3] = zero;
    handler->floats[7][0] = one; handler->floats[7][1] = zero;
    handler->floats[7][2] = zero; handler->floats[7][3] = zero;
    handler->floats[8][0] = one; handler->floats[8][1] = zero;
    handler->floats[8][2] = zero; handler->floats[8][3] = zero;
    handler->floats[9][0] = one; handler->floats[9][1] = zero;
    handler->floats[9][2] = zero; handler->floats[9][3] = zero;
    pool = handler->pool;
    if (pool != 0) ((void (*)(void *))fn_802AE0E0)(pool);
    actor = handler->actor[0];
    if (actor) {
        *(unsigned char *)((char *)actor + 0x4A) = 1;
        *(unsigned char *)((char *)actor + 0x4C) = 0;
    }
    actor = handler->actor[1];
    if (actor) {
        *(unsigned char *)((char *)actor + 0x4A) = 1;
        *(unsigned char *)((char *)actor + 0x4C) = 0;
    }
    actor = handler->actor[2];
    if (actor) {
        *(unsigned char *)((char *)actor + 0x4A) = 1;
        *(unsigned char *)((char *)actor + 0x4C) = 0;
    }
}
#pragma scheduling on
// Enables a per-racer flag byte (offset +0x11) in the race UI/state block for the current racer slot.
void fn_801CCAEC(int arg0) {
    int racerIndex;
    unsigned char *raceMgr;
    char *uiStateBase;
    (void)arg0;
    uiStateBase = (char *)lbl_8055E884;
    raceMgr = fn_801EA9A0();
    if (*raceMgr != 0) {
        racerIndex = raceMgr[0xB4] & 3;
    } else {
        racerIndex = -1;
    }
    if (racerIndex >= 0) {
        *(signed char *)(uiStateBase + racerIndex + 0x11) = 1;
    }
}

/* Clears the award handler's flag for the player driving car playerIndex: the byte
 * the handler keeps per player slot, at StatHandler+0x11+slot, where the slot is
 * the low two bits of the car record's +0xB4.  Nothing happens for a car that is
 * not in play.  fn_801CCAEC is the matching set. */
void fn_801CCB48(int playerIndex) {
    int slotIndex;
    u8 *entry;
    StatHandler *handler;
    handler = (StatHandler *)lbl_8055E884;
    entry = ((u8 *(*)(int))fn_801EA9A0)(playerIndex);
    if (entry[0] != 0) {
        slotIndex = entry[0xB4] & 3;
    } else {
        slotIndex = -1;
    }
    if (slotIndex >= 0) {
        handler->player[slotIndex] = 0;
    }
}

void fn_801CCBA4(void) {
    /* Set the paused flag of the award stat handler in lbl_8055E884. */
    ((StatHandler *)lbl_8055E884)->paused = 1;
}

void fn_801CCBB4(void) {
    /* Clear the paused flag of the award stat handler in lbl_8055E884. */
    ((StatHandler *)lbl_8055E884)->paused = 0;
}

extern void fn_8001BDA8(void *);
extern int fn_8001BBB4(s32, s32, void *, s32, s32, f32);
#pragma scheduling invalid_target
void fn_801CCBC4(void) {
    void *awardsState;
    void *entry;
    void *object;
    s32 i;
    s32 offset;

    /* Finalize pending awards: clean up entries, then trigger award playback for the matching object (type 0x50). */
    awardsState = lbl_8055E884;
    if (*(u8 *)((u8 *)awardsState + 0x10) != 0)
        return;

    i = 0;
    offset = 0;
    goto check_first;
first_loop:
    entry = *(void **)(*(u8 **)((u8 *)awardsState + 0x18) + offset);
    if (entry != 0)
        fn_8001BDA8(*(void **)entry);
    offset += 4;
    i += 1;
check_first:
    if (i < *(s32 *)((u8 *)awardsState + 0x1C))
        goto first_loop;

    if (fn_801CE898() != 0)
        return;
    if (*(s32 *)((u8 *)awardsState + 0x2AC) == 0)
        return;

    i = 0;
    goto check_second;
second_loop:
    object = fn_801EA9A0(i);
    if (*(s32 *)((u8 *)object + 0x44) == 0x50) {
        ((int (*)(s32, s32, s32, void *, s32, s32, f32))fn_8001BBB4)(
            fn_8000DA10(), *(s32 *)((u8 *)awardsState + 0), *(s32 *)((u8 *)awardsState + 4), (u8 *)object + 0x48,
            *(s32 *)((u8 *)awardsState + 0x2AC), *(s32 *)((u8 *)awardsState + 0x2B0),
            *(f32 *)((u8 *)awardsState + 0x2B8));
        return;
    }
    i += 1;
check_second:
    if (i < fn_801EA994())
        goto second_loop;
}
#pragma scheduling on
extern void fn_80235380(void);
extern void deleteThreads__6SystemFv(void *);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801CCCAC(void) {
    /* Tear down the global manager state (lbl_8055E884): release active/ref-counted
       handle, destroy owned first/element objects via vtable slot 2, delete embedded
       thread groups at +0x40/+0x2A4, clear the items list, free the state, and null
       the global. */
    struct FirstObject { virtual void destroy(int); };
    struct ElementBase { int pad; };
    struct ElementObject : ElementBase { virtual void destroy(int); };
    struct ManagerState {
        char pad0[8];
        void *firstObject;
        int activeHandle;
        char pad10[8];
        void **items;
        int itemCount;
        int field20;
    };
    int i;
    int offset;
    int activeHandle;
    ElementObject *element;
    FirstObject *firstObject;
    ManagerState *manager;
    int *managerWords;

    manager = (ManagerState *)lbl_8055E884;
    if (manager != 0) {
        activeHandle = manager->activeHandle;
        if (activeHandle != 0) ((void (*)(int))fn_80235380)(activeHandle);
        manager->activeHandle = 0;
        firstObject = (FirstObject *)manager->firstObject;
        if (firstObject != 0) {
            if (firstObject != 0) firstObject->destroy(1);
        }
        deleteThreads__6SystemFv((char *)manager + 0x40);
        deleteThreads__6SystemFv((char *)manager + 0x2A4);
        i = 0;
        offset = 0;
        while (i < manager->itemCount) {
            element = (ElementObject *)((char *)manager->items + offset);
            element = *(ElementObject **)element;
            if (element != 0) element->destroy(1);
            offset += 4;
            i++;
        }
        manager->itemCount = 0;
        managerWords = (int *)manager;
        if (&managerWords[6] != 0) {
            if (&managerWords[6] != 0) {
                manager->items = 0;
                manager->itemCount = 0;
                manager->field20 = 0;
            }
        }
        fn_80128668(manager);
    }
    lbl_8055E884 = 0;
}
#pragma scheduling on
#pragma cplusplus reset
extern char lbl_80337CA0[];
extern f32 lbl_805629F0;
extern f32 lbl_80562A0C;
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801CCDAC(int arg0, int arg1, int arg2) {
s32 *temp_r31;
register s32 var_r29;
register s32 var_r30;
s32 var_r0;
s32 var_r0_2;
register s32 var_ctr;
register s32 var_r3;
s32 temp_r3_2, temp_r3_3, temp_r3_4, temp_r3_5, temp_r3_6;
unsigned char *temp_r30;
void *temp_r3;
unsigned char *temp_r3_7;
unsigned char *temp_r0;
unsigned char *temp_r4;
unsigned char *temp_r7;
unsigned char *temp_r7_2, *temp_r7_3, *temp_r7_4, *temp_r7_5;
register unsigned char *var_r6;
register unsigned char *var_r7;
register unsigned char *var_r4;
register unsigned char *var_r5;

if ((fn_801CE898() == 0) &&
(temp_r31 = lbl_8055E884, (*(unsigned char *)((unsigned char *)temp_r31 + 0x10) == 0))) {
temp_r3 = ((void *(*)(s32))fn_801EA9A0)(arg1);
if (*(unsigned char *)temp_r3 != 0)
var_r0 = *(unsigned char *)((unsigned char *)temp_r3 + 0xB4) & 3;
else
var_r0 = -1;
if (var_r0 >= 0)
var_r0_2 = *(unsigned char *)((unsigned char *)temp_r31 + var_r0 + 0x11);
else
var_r0_2 = 1;
if (var_r0_2 == 0) {
var_r29 = 0;
var_r30 = 0;
for (; var_r29 < *(s32 *)((unsigned char *)temp_r31 + 0x1C); ) {
if (fn_801CB900(*(int **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r30 / 4), arg0) != 0)
goto after_search;
var_r30 += 4;
var_r29 += 1;
}
var_r29 = -1;
after_search:
if (var_r29 < 0)
((void (*)(const char *, ...))Abend_Panic)(lbl_80337CA0, arg0);
temp_r30 = (unsigned char *)*(void **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r29);
if (temp_r30 != 0) {
if (((Dummy_801CCDAC *)temp_r30)->v1(arg2) != 0) {
var_r6 = (unsigned char *)temp_r31;
var_r7 = (unsigned char *)temp_r31 + 0x44;
var_r4 = 0;
var_r5 = 0;
var_r3 = 0;
for (var_ctr = 0; var_ctr < 5; var_ctr++) {
if (*(unsigned char *)(var_r6 + 0x44) == 0) {
var_r5 = var_r7;
goto block_24;
}
if (*(void **)(var_r6 + 0x4C) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + var_r3 * 0x14 + 0x44;
goto scan_done;
} else {
block_24:
temp_r7 = var_r7 + 0x14;
temp_r3_2 = var_r3 + 1;
if (*(unsigned char *)(var_r6 + 0x58) == 0) {
var_r5 = temp_r7;
goto block_28;
}
if (*(void **)(var_r6 + 0x60) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_2 * 0x14 + 0x44;
goto scan_done;
} else {
block_28:
temp_r7_2 = temp_r7 + 0x14;
temp_r3_3 = temp_r3_2 + 1;
if (*(unsigned char *)(var_r6 + 0x6C) == 0) {
var_r5 = temp_r7_2;
goto block_32;
}
if (*(void **)(var_r6 + 0x74) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_3 * 0x14 + 0x44;
goto scan_done;
} else {
block_32:
temp_r7_3 = temp_r7_2 + 0x14;
temp_r3_4 = temp_r3_3 + 1;
if (*(unsigned char *)(var_r6 + 0x80) == 0) {
var_r5 = temp_r7_3;
goto block_36;
}
if (*(void **)(var_r6 + 0x88) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_4 * 0x14 + 0x44;
goto scan_done;
} else {
block_36:
temp_r7_4 = temp_r7_3 + 0x14;
temp_r3_5 = temp_r3_4 + 1;
if (*(unsigned char *)(var_r6 + 0x94) == 0) {
var_r5 = temp_r7_4;
goto block_40;
}
if (*(void **)(var_r6 + 0x9C) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_5 * 0x14 + 0x44;
goto scan_done;
} else {
block_40:
temp_r7_5 = temp_r7_4 + 0x14;
temp_r3_6 = temp_r3_5 + 1;
if (*(unsigned char *)(var_r6 + 0xA8) == 0) {
var_r5 = temp_r7_5;
goto block_44;
}
if (*(void **)(var_r6 + 0xB0) == temp_r30) {
var_r4 = (unsigned char *)temp_r31 + temp_r3_6 * 0x14 + 0x44;
goto scan_done;
} else {
block_44:
var_r6 += 0x78;
var_r7 = temp_r7_5 + 0x14;
var_r3 = temp_r3_6 + 1;

}
}
}
}
}
}
}
scan_done:
if (var_r4 != 0) {
*(f32 *)(var_r4 + 4) = lbl_805629F0;
if (var_r4[1] != 0)
*(f32 *)(var_r4 + 4) = *(f32 *)(var_r4 + 4) - lbl_80562A0C;
} else {
if (var_r5 == 0) {
temp_r3_7 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 0x29C);
var_r5 = 0;
if (temp_r3_7 != 0) {
temp_r0 = (unsigned char *)*(void **)(temp_r3_7 + 0x10);
var_r5 = temp_r3_7;
*(void **)((unsigned char *)temp_r31 + 0x29C) = temp_r0;
if (temp_r0 == 0)
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)((unsigned char *)temp_r31 + 0x29C);
*(void **)((unsigned char *)temp_r3_7 + 0x10) = 0;
}
}
*var_r5 = 1;
var_r5[1] = 0;
*(f32 *)(var_r5 + 4) = lbl_805629F0;
*(void **)(var_r5 + 8) = temp_r30;
temp_r4 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 8);
if (temp_r4 != 0) {
*((unsigned char *)temp_r4 + 0x49) = 1;
*((unsigned char *)temp_r4 + 0x4B) = 0;
*((unsigned char *)temp_r4 + 0x4A) = 0;
}
*(void **)(*(void ***)((unsigned char *)temp_r31 + 0x2A0)) = var_r5;
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)(var_r5 + 0x10);
*(s32 *)(var_r5 + 0x10) = 0;
}
}
}
}
}
}
#pragma cplusplus reset
#pragma pop
extern char lbl_80337CCC[];
#pragma push
#pragma scheduling invalid_target
/* Report a fatal panic ("StatHandler: data type \"int\" is not accepted here!") via Abend_Panic and return 0 (unreachable). */
s32 fn_801CD100(void) {
    ((void (*)(const char*, ...))Abend_Panic)(lbl_80337CCC);
    return 0;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma paired_single off
#pragma cplusplus on
#pragma paired_single off
extern "C" void fn_801CD130(int arg0, int arg1, f32 farg0) {
s32 *temp_r31;
register s32 var_r29;
register s32 var_r30;
register s32 var_r0;
register s32 var_r0_2;
register s32 var_ctr;
register unsigned char *var_r5;
register unsigned char *var_r4;
register unsigned char *var_r6;
register unsigned char *var_r3;
register unsigned char *temp_r30;
void *temp_r3;
register unsigned char *temp_r3_7;
register unsigned char *temp_r0;
register unsigned char *temp_r4;
register unsigned char *temp_r7;
s32 temp_r3_2, temp_r3_3, temp_r3_4, temp_r3_5, temp_r3_6;
unsigned char *temp_r7_2, *temp_r7_3, *temp_r7_4, *temp_r7_5;
register unsigned char *var_r7;

if ((fn_801CE898() == 0) &&
(temp_r31 = lbl_8055E884, (*(unsigned char *)((unsigned char *)temp_r31 + 0x10) == 0))) {
temp_r3 = ((void *(*)(s32))fn_801EA9A0)(arg1);
if (*(unsigned char *)temp_r3 != 0)
var_r0 = *(unsigned char *)((unsigned char *)temp_r3 + 0xB4) & 3;
else
var_r0 = -1;
if (var_r0 >= 0)
var_r0_2 = *(unsigned char *)((unsigned char *)temp_r31 + var_r0 + 0x11);
else
var_r0_2 = 1;
if (var_r0_2 == 0) {
var_r29 = 0;
var_r30 = 0;
while (var_r29 < *(s32 *)((unsigned char *)temp_r31 + 0x1C)) {
switch (fn_801CB900(*(int **)((unsigned char *)(*(s32 **)((unsigned char *)temp_r31 + 0x18)) + var_r30), arg0)) {
case 0:
var_r30 += 4;
var_r29 += 1;
break;
default:
goto found_item;
}
}
var_r29 = -1;
found_item:
var_r30 = var_r29;
if (var_r30 < 0)
((void (*)(const char *, ...))Abend_Panic)(lbl_80337CA0, arg0);
temp_r30 = (unsigned char *)*(void **)(*(s32 **)((unsigned char *)temp_r31 + 0x18) + var_r30);
if (temp_r30 != 0) {
if (((Dummy_801CCDAC *)temp_r30)->v2(farg0) != 0) {
var_r3 = (unsigned char *)temp_r31;
var_r7 = (unsigned char *)temp_r31 + 0x44;
var_r5 = 0;
var_r6 = 0;
var_r4 = 0;
for (var_ctr = 0; var_ctr < 5; var_ctr++) {
if (*(unsigned char *)(var_r3 + 0x44) == 0) {
var_r4 = var_r7;
goto block_24;
}
if (*(void **)(var_r3 + 0x4C) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + (s32)var_r6 * 0x14 + 0x44;
goto scan_done;
} else {
block_24:
temp_r7 = var_r7 + 0x14;
temp_r3_2 = (s32)var_r6 + 1;
if (*(unsigned char *)(var_r3 + 0x58) == 0) {
var_r4 = temp_r7;
goto block_28;
}
if (*(void **)(var_r3 + 0x60) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_2 * 0x14 + 0x44;
goto scan_done;
} else {
block_28:
temp_r7_2 = temp_r7 + 0x14;
temp_r3_3 = temp_r3_2 + 1;
if (*(unsigned char *)(var_r3 + 0x6C) == 0) {
var_r4 = temp_r7_2;
goto block_32;
}
if (*(void **)(var_r3 + 0x74) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_3 * 0x14 + 0x44;
goto scan_done;
} else {
block_32:
temp_r7_3 = temp_r7_2 + 0x14;
temp_r3_4 = temp_r3_3 + 1;
if (*(unsigned char *)(var_r3 + 0x80) == 0) {
var_r4 = temp_r7_3;
goto block_36;
}
if (*(void **)(var_r3 + 0x88) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_4 * 0x14 + 0x44;
goto scan_done;
} else {
block_36:
temp_r7_4 = temp_r7_3 + 0x14;
temp_r3_5 = temp_r3_4 + 1;
if (*(unsigned char *)(var_r3 + 0x94) == 0) {
var_r4 = temp_r7_4;
goto block_40;
}
if (*(void **)(var_r3 + 0x9C) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_5 * 0x14 + 0x44;
goto scan_done;
} else {
block_40:
temp_r7_5 = temp_r7_4 + 0x14;
temp_r3_6 = temp_r3_5 + 1;
if (*(unsigned char *)(var_r3 + 0xA8) == 0) {
var_r4 = temp_r7_5;
goto block_44;
}
if (*(void **)(var_r3 + 0xB0) == temp_r30) {
var_r5 = (unsigned char *)temp_r31 + temp_r3_6 * 0x14 + 0x44;
goto scan_done;
} else {
block_44:
var_r3 += 0x78;
var_r7 = temp_r7_5 + 0x14;
var_r6 = (unsigned char *)(temp_r3_6 + 1);

}
}
}
}
}
}
}
scan_done:
if (var_r5 != 0) {
*(f32 *)(var_r5 + 4) = lbl_805629F0;
if (var_r5[1] != 0)
*(f32 *)(var_r5 + 4) = *(f32 *)(var_r5 + 4) - lbl_80562A0C;
} else {
if (var_r4 == 0) {
temp_r3_7 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 0x29C);
var_r4 = 0;
if (temp_r3_7 != 0) {
temp_r0 = (unsigned char *)*(void **)(temp_r3_7 + 0x10);
var_r4 = temp_r3_7;
*(void **)((unsigned char *)temp_r31 + 0x29C) = temp_r0;
if (temp_r0 == 0)
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)((unsigned char *)temp_r31 + 0x29C);
*(void **)((unsigned char *)temp_r3_7 + 0x10) = 0;
}
}
*var_r4 = 1;
var_r4[1] = 0;
*(f32 *)(var_r4 + 4) = lbl_805629F0;
*(void **)(var_r4 + 8) = temp_r30;
temp_r4 = (unsigned char *)*(void **)((unsigned char *)temp_r31 + 8);
if (temp_r4 != 0) {
*((unsigned char *)temp_r4 + 0x49) = 1;
*((unsigned char *)temp_r4 + 0x4B) = 0;
*((unsigned char *)temp_r4 + 0x4A) = 0;
}
*(void **)(*(void ***)((unsigned char *)temp_r31 + 0x2A0)) = var_r4;
*(void ***)((unsigned char *)temp_r31 + 0x2A0) =
(void **)(var_r4 + 0x10);
*(s32 *)(var_r4 + 0x10) = 0;
}
}
}
}
}
}
#pragma paired_single reset
#pragma cplusplus reset
#pragma paired_single reset
#pragma pop

#pragma pop

extern char lbl_80337D00[];
#pragma push
#pragma scheduling invalid_target
s32 fn_801CD49C(void) {
#define PanicAbort Abend_Panic
#define kRealTypeRejectedMsg lbl_80337D00
    /* Fatal panic: this stat handler cannot accept a "real" data type. */
    ((void (*)(char *, ...))PanicAbort)(kRealTypeRejectedMsg);
    return 0;
#undef kRealTypeRejectedMsg
#undef PanicAbort
}

extern void fn_8001EF5C(int, int);
extern char lbl_80337D34[];
void fn_801CD4CC(int playerIndex, int place) {
    u8 *awardsBase;
    u8 *entry;
    s32 slotIndex;
    u8 slotState;

    /* Queue a pending award place for a player, or abort if one is already pending. */
    if (fn_801CE898() != 0) return;
    awardsBase = (u8 *)lbl_8055E884;
    if (awardsBase[0x10] != 0) return;

    entry = ((u8 *(*)(s32))fn_801EA9A0)(playerIndex);
    if (entry[0] != 0) {
        slotIndex = entry[0xB4] & 3;
    } else {
        slotIndex = -1;
    }

    if (slotIndex >= 0) {
        slotState = awardsBase[slotIndex + 0x11];
    } else {
        slotState = 1;
    }
    if (slotState != 0) return;

    entry = ((u8 *(*)(s32))fn_801EA9A0)(playerIndex);
    if (entry[0] == 0) return;

    if (*(s32 *)(awardsBase + 0x2A8) == 0) {
        *(s32 *)(awardsBase + 0x2A8) = place;
        if (place == 1) fn_8001EF5C(1, 1);
    } else {
        ((void (*)(char *, ...))Abend_Panic)(lbl_80337D34);
    }
}

extern int fn_8001BBB8(int, int, int, float);
extern void fn_8001EFC4(int, void *, int);
extern char lbl_80337D5C[];
extern void fn_8001EFC4();
/* Handles an award/grade push for an object, storing ids/data and starting playback if idle. */
/* Push an award/grade for an object: store newCount/newEntry, start playback if idle, then rank the contest score if the prior entry is stale. */ void pushAward(int playerIndex, int newCount, int newEntry) {
    unsigned char *awardsState;
    unsigned char *entry;
    int entrySlot;
    int entryStatus;
    void *statData;
    int currentSlot;

    if (fn_801CE898() != 0)
        return;
    awardsState = (unsigned char *)lbl_8055E884;
    if (awardsState[0x10] != 0)
        return;

    entry = ((unsigned char *(*)(int))fn_801EA9A0)(playerIndex);
    if (entry[0] != 0)
        entrySlot = entry[0xB4] & 3;
    else
        entrySlot = -1;
    if (entrySlot >= 0)
        entryStatus = (awardsState + entrySlot)[0x11];
    else
        entryStatus = 1;
    if (entryStatus != 0)
        return;

    entry = ((unsigned char *(*)(int))fn_801EA9A0)(playerIndex);
    if (entry[0] == 0)
        return;
    if (*(int *)(awardsState + 0x2AC) != 0)
        goto warning;

    *(int *)(awardsState + 0x2AC) = newCount;
    *(int *)(awardsState + 0x2B0) = newEntry;
    fn_8001EF5C(0, newCount);
    if (*(int *)(awardsState + 0x2B0) == 0)
        fn_8001EF5C(2, 1);

    entry = ((unsigned char *(*)(int))fn_801EA9A0)(playerIndex);
    statData = entry + 0x88;
    ((void (*)(int, void *, int))fn_8001EFC4)(0, statData, 1);
    if (newEntry == 0)
        ((void (*)(int, void *, int))fn_8001EFC4)(1, statData, 1);

    if (*(int *)(awardsState + 0x2B4) < 0 && awardsState[0x2BC] != 0) {
        entrySlot = *(int *)(awardsState + 0x2AC);
        if (entrySlot >= 0) {
            currentSlot = fn_8000DA10();
            *(int *)(awardsState + 0x2B4) =
                ((int (*)(int, int, int, int, float))fn_8001BBB8)(
                    currentSlot, *(int *)awardsState, *((int *)awardsState + 1), entrySlot,
                    *(float *)(awardsState + 0x2B8));
        }
    }
    goto done;

warning:
    ((void (*)(char *, ...))Abend_Panic)(lbl_80337D5C);
done:
    return;
}

/* Outputs two cached state values from lbl_8055E884 (+0x2AC, +0x2B0) into the
 * provided pointers, or 0/-1 when the current context is unavailable. */
void fn_801CD730(s32 *outValue0, s32 *outValue1) {
    if (fn_801CE898() != 0) {
        if (outValue0 != 0) *outValue0 = 0;
        if (outValue1 != 0) *outValue1 = -1;
    } else {
        if (outValue0 != 0) *outValue0 = *(s32 *)((u8 *)lbl_8055E884 + 0x2AC);
        if (outValue1 != 0) *outValue1 = *(s32 *)((u8 *)lbl_8055E884 + 0x2B0);
    }
}

extern char lbl_80337D90[];
extern f32 lbl_805629FC;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus on
/* Awards: push a race time for a player into the stat handler. After the
 * context/per-player status checks, scan the stat array for the slot whose
 * type is 0x20507, forward the time through that stat object's virtual setter
 * v2() (lbl_80337CA0 warns if none is found), cache it at +0x2B8 and start
 * award playback. lbl_80337D90 warns when a time was already cached. */
extern "C" void pushAwardsRaceTime(int playerIndex, int pushEnabled, f32 raceTime) {
    #pragma opt_propagation off
    register StatHandler *awards;
    register s32 statTypeBase;
    register s32 statType;
    register s32 slotIndex;
    register s32 slotOffset;
    s32 playerSlot;
    u8 *carRecord;
    s32 playerStatus;
    s32 score;
    s32 current;

    /* Awards: push a player's race time into the stat handler's race-time stat
     * (type 0x20507), cache it and start award playback; warn if a time is cached
     * already or the stat slot cannot be found. */
    if (fn_801CE898() != 0)
        goto done;
    awards = (StatHandler *)lbl_8055E884;
    if (awards->paused != 0)
        goto done;
    carRecord = ((u8 *(*)(s32))fn_801EA9A0)(playerIndex);
    if (carRecord[0] != 0)
        playerSlot = carRecord[0xB4] & 3;
    else
        playerSlot = -1;
    if (playerSlot >= 0)
        playerStatus = (u8)awards->player[playerSlot];
    else
        playerStatus = 1;
    if (playerStatus != 0)
        goto done;
    carRecord = ((u8 *(*)(s32))fn_801EA9A0)(playerIndex);
    if (carRecord[0] == 0 || pushEnabled == 0)
        goto done;
    if (awards->value < lbl_805629FC) {
        statTypeBase = 0x20000;
        statType = statTypeBase + 0x507;
        slotIndex = 0;
        slotOffset = 0;
        while (slotIndex < awards->entryCount) {
            switch (fn_801CB900(*(int **)((u8 *)awards->entries + slotOffset), statTypeBase + 0x507)) {
            case 0:
                slotOffset += 4;
                slotIndex++;
                break;
            default:
                goto found;
            }
        }
        slotIndex = -1;
found:
        if (slotIndex < 0)
            ((void (*)(const char *, ...))Abend_Panic)(lbl_80337CA0, statType);
        ((Dummy_801CCDAC *)*(void **)((u8 *)awards->entries + slotIndex * 4))->v2(raceTime);
        awards->value = raceTime;
        awards->hasValue = 1;
        if (awards->unknown2B4 < 0 && awards->hasValue != 0) {
            score = awards->newCount;
            if (score >= 0) {
                current = fn_8000DA10();
                awards->unknown2B4 = ((s32 (*)(s32, s32, s32, s32, f32))fn_8001BBB8)(
                    current, awards->unknown0[0], awards->unknown0[1], score, awards->value);
            }
        }
    } else {
        ((void (*)(const char *, f32, ...))Abend_Panic)(
            lbl_80337D90, awards->value, (double)raceTime);
    }
done:
    return;
}
#pragma cplusplus reset
#pragma pop

extern f32 lbl_805629E4, lbl_805629F0, lbl_805629FC, lbl_80562A10, lbl_80562A14, lbl_80562A18;
extern s32 lbl_802F9930[3];
extern char lbl_8055AB38[];
extern f32 fn_801E7E24(void);
extern s32 fn_8026B0C0(s32);
extern s32 fn_80204CF0(s32, s32, s32 *);
extern void fn_80148070(void *, s32, s32, f32);
extern s32 fn_8001BA6C(void);
extern s32 fn_801345D8(char *, s32, const char *, ...);
extern void fn_80147230(void *, const char *, void *, ...);
extern void fn_801476C4(void *, f32, f32);
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801CD970(int arg0) {
#pragma opt_common_subs off
    typedef struct { s32 field0; f32 field4; s32 field8; s32 fieldC; f32 field10; f32 field14; s32 field18; } DataA;
    typedef struct { s32 field0; f32 field4; s32 field8; s32 fieldC; f32 field10; f32 field14; s32 field18; s32 field1C; } DataB;
    typedef struct { u8 field0; u8 active; u8 pad2[2]; f32 timer; void *data; u32 padC; void *next; } Item;
    void *manager; Item *item;
    register f32 delta, threshold;
    f32 temp, ratio, value, blend, clamp;
    char *strings;
    DataA *record0; DataB *recordA, *recordB, *recordC;
    DataB local1; DataA local0;
    char out2[0x10]; s32 choices[3]; char out1[0x40]; char vec[0x14];
    s32 index, zero, active;
    strings = lbl_80337AC8;
    if (fn_801CE898() != 0) return;
    manager = lbl_8055E884;
    if (*(s32 *)((char *)manager + 0x40) == 0) return;
    if (*(s32 *)((char *)manager + 0x29C) == 0) return;
    delta = fn_801E7E24(); threshold = lbl_805629FC; active = 1; zero = 0;
    goto check_head;
process_item:
    if (fn_8026B0C0(arg0) != 0) {
        if (*(u8 *)((char *)item + 1) != 0) {
            if (*(f32 *)((char *)item + 4) < lbl_80562A0C) {
                Item *head = *(Item **)((char *)manager + 0x29C);
                if (head != 0) {
                    Item *next = *(Item **)((char *)head + 0x10);
                    *(Item **)((char *)manager + 0x29C) = next;
                    if (next == 0) *(void **)((char *)manager + 0x2A0) = (char *)manager + 0x29C;
                    *(void **)((char *)head + 0x10) = (void *)zero;
                }
                *(f32 *)((char *)item + 4) = lbl_80562A10;
                *(u8 *)item = (u8)zero;
                goto check_head;
            }
            *(f32 *)((char *)item + 4) = lbl_80562A14;
        }
        item = 0; goto render_item;
    }
    *(u8 *)((char *)item + 1) = (u8)active;
    temp = *(f32 *)((char *)item + 4) - delta;
    *(f32 *)((char *)item + 4) = temp;
    if (temp < threshold) {
        Item *head = *(Item **)((char *)manager + 0x29C);
        if (head != 0) {
            Item *next = *(Item **)((char *)head + 0x10);
            *(Item **)((char *)manager + 0x29C) = next;
            if (next == 0) *(void **)((char *)manager + 0x2A0) = (char *)manager + 0x29C;
            *(void **)((char *)head + 0x10) = (void *)zero;
        }
        *(u8 *)item = (u8)zero;
        goto check_head;
    }
    goto render_item;
check_head:
    item = *(Item **)((char *)manager + 0x29C);
    if (item != 0) goto process_item;
    item = 0;
    if (item == 0) return;
render_item:
    if (item != 0) {
        record0 = ((DataA *(*)(void *, char *))(*(void ***)*(void ****)((char *)manager + 0x40))[5])(*(void **)((char *)manager + 0x40), strings + 0x310);
        if (record0 != 0) {
            value = *(f32 *)((char *)item + 4);
            if (value >= lbl_80562A0C) value = lbl_805629F0 - value;
            temp = record0->field10;
            ratio = (value - lbl_805629FC) / lbl_80562A0C;
            blend = temp + (lbl_80562A18 - (record0->field4 + temp));
            clamp = lbl_805629E4;
            if (clamp >= ratio) clamp = ratio;
            if (clamp > lbl_805629FC) clamp = lbl_805629FC;
            blend = blend + (clamp * (lbl_805629FC - blend));
            if (record0 != 0) {
                local0.field0 = record0->field0;
                *(s32 *)((char *)&local0 + 4) = *(s32 *)((char *)record0 + 4);
                local0.field8 = record0->field8;
                local0.fieldC = record0->fieldC;
                local0.field10 = record0->field10;
                *(s32 *)((char *)&local0 + 0x14) = *(s32 *)((char *)record0 + 0x14);
                local0.field18 = record0->field18;
                local0.field4 += blend;
                fn_80148070(&local0, -1, *(s32 *)((char *)manager + 0xC), *(f32 *)((char *)record0 + 0x14));
            }
            recordA = ((DataB *(*)(void *, char *))(*(void ***)*(void ****)((char *)manager + 0x40))[3])(*(void **)((char *)manager + 0x40), strings + 0x320);
            choices[0] = lbl_802F9930[0]; choices[1] = lbl_802F9930[1]; choices[2] = lbl_802F9930[2];
            index = fn_80204CF0(lbl_802F9930[1], lbl_802F9930[0], lbl_802F9930);
            recordB = ((DataB *(*)(void *, s32))(*(void ***)*(void ****)((char *)manager + 0x40))[3])(*(void **)((char *)manager + 0x40), choices[index]);
            recordC = ((DataB *(*)(void *, char *))(*(void ***)*(void ****)((char *)manager + 0x40))[3])(*(void **)((char *)manager + 0x40), strings + 0x334);
            if (recordA != 0 && recordB != 0 && recordC != 0) {
                local1.field0 = recordA->field0; *(s32 *)((char *)&local1 + 4) = *(s32 *)((char *)recordA + 4); local1.field8 = recordA->field8; local1.fieldC = recordA->fieldC;
                local1.field10 = recordA->field10; *(s32 *)((char *)&local1 + 0x14) = *(s32 *)((char *)recordA + 0x14); local1.field18 = recordA->field18; local1.field1C = recordA->field1C;
                local1.field4 += blend;
                fn_8001BD38(*(s32 *)((char *)item->data), vec, 0x14, recordA->field10);
                fn_8001BD28(*(s32 *)((char *)item->data));
                fn_801345D8(out1, 0x40, lbl_8055AB38, fn_8001BA6C());
                fn_801345D8(out2, 0x10, lbl_8055AB38, vec);
                fn_80147230(&local1, lbl_8055AB38, out1);
                local1.field0 = recordB->field0; *(s32 *)((char *)&local1 + 4) = *(s32 *)((char *)recordB + 4); local1.field8 = recordB->field8; local1.fieldC = recordB->fieldC;
                local1.field10 = recordB->field10; *(s32 *)((char *)&local1 + 0x14) = *(s32 *)((char *)recordB + 0x14); local1.field18 = recordB->field18; local1.field1C = recordB->field1C;
                local1.field4 += blend;
                fn_80147230(&local1, lbl_8055AB38, out2, recordB->field4, recordB->field10);
                local1.field0 = recordC->field0; *(s32 *)((char *)&local1 + 4) = *(s32 *)((char *)recordC + 4); local1.field8 = recordC->field8; local1.fieldC = recordC->fieldC;
                local1.field10 = recordC->field10; *(s32 *)((char *)&local1 + 0x14) = *(s32 *)((char *)recordC + 0x14); local1.field18 = recordC->field18; local1.field1C = recordC->field1C;
                local1.field4 += blend;
                fn_801476C4(&local1, recordC->field4, recordC->field10);
            }
        }
    }
}
/* StatManager_InitBlock: build the stats/awards manager's stat block at
 * lbl_8055E884+0x2C0, but only once the required tables are loaded. */
void fn_801CDDCC(void) {
    if (fn_801CE898() == 0) {
        fn_801CDE00((s32)lbl_8055E884 + 0x2C0);
    }
}

#pragma dont_inline on
void fn_801CDE00(s32 arg0) {
    extern char lbl_80337AC8[];
    extern char lbl_8055AB30[4];
    extern char lbl_8055AB3C[4];
    extern char lbl_8055AB40[4];
    extern char lbl_8055AB44[4];
    extern char lbl_8055AB48[4];
    extern char lbl_8055AB4C[4];
    extern s32 lbl_802FAA40[];
    extern void *fn_802ADDD8(void *, s32);
    extern s32 fn_802ADF34(void *, char *, s32 *);
    void *tmp;
    s32 s31;
    char *base;
    char *obj;
    Struct_801CE670 t5, t4, t3, t2, t1, s30, s29, s28, s27, s26, s25, s24, s23, s22, s21, s20, s19, s18, s17, s16, s15, s14, s13, s12, s11, s10, s9, s8, s7, s6, s5, s4, s3, s2, s1;
    s32 dest[108];
    register s32 i;
    f32 *p;
    f32 one;
    f32 zero;
    base = lbl_80337AC8;
    tmp = fn_801284F8(8, (void *)(base + 0x348));
    if (tmp != 0) tmp = (void *)((void *(*)(void *, s32))fn_802ADDD8)(tmp, 0x10);
    *(void **)((char *)arg0 + 8) = tmp;
    s31 = ((s32 (*)())fn_80204CF0)();
    memset(dest, 0, sizeof(dest));
    fn_801CE6D0(&s1, (s32)(base + 0x358), (s32)((char *)arg0 + 0x18));
    dest[0] = s1.field0; dest[1] = s1.field4; dest[2] = s1.field8;
    fn_801CE6A4(&s2, (s32)(base + 0x368), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x20, s1.field4, s1.field0));
    dest[3] = s2.field0; dest[4] = s2.field4; dest[5] = s2.field8;
    fn_801CE6A4(&s3, (s32)(base + 0x378), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x34, s2.field4, s2.field0));
    dest[6] = s3.field0; dest[7] = s3.field4; dest[8] = s3.field8;
    fn_801CE6A4(&s4, (s32)(base + 0x388), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x48, s3.field4, s3.field0));
    dest[9] = s4.field0; dest[10] = s4.field4; dest[11] = s4.field8;
    fn_801CE6A4(&s5, (s32)(base + 0x398), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x5c, s4.field4, s4.field0));
    dest[12] = s5.field0; dest[13] = s5.field4; dest[14] = s5.field8;
    fn_801CE6A4(&s6, (s32)(base + 0x3a8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x70, s5.field4, s5.field0));
    dest[15] = s6.field0; dest[16] = s6.field4; dest[17] = s6.field8;
    fn_801CE6A4(&s7, (s32)(base + 0x3b8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x84, s6.field4, s6.field0));
    dest[18] = s7.field0; dest[19] = s7.field4; dest[20] = s7.field8;
    fn_801CE6A4(&s8, (s32)(base + 0x3c8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x98, s7.field4, s7.field0));
    dest[21] = s8.field0; dest[22] = s8.field4; dest[23] = s8.field8;
    fn_801CE6A4(&s9, (s32)(base + 0x3d8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xac, s8.field4, s8.field0));
    dest[24] = s9.field0; dest[25] = s9.field4; dest[26] = s9.field8;
    fn_801CE6A4(&s10, (s32)(base + 0x3e8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xc0, s9.field4, s9.field0));
    dest[27] = s10.field0; dest[28] = s10.field4; dest[29] = s10.field8;
    fn_801CE6A4(&s11, (s32)(base + 0x3f8), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xd4, s10.field4, s10.field0));
    dest[30] = s11.field0; dest[31] = s11.field4; dest[32] = s11.field8;
    fn_801CE6A4(&s12, (s32)(base + 0x408), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xe8, s11.field4, s11.field0));
    dest[33] = s12.field0; dest[34] = s12.field4; dest[35] = s12.field8;
    fn_801CE6A4(&s13, (s32)(base + 0x418), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0xfc, s12.field4, s12.field0));
    dest[36] = s13.field0; dest[37] = s13.field4; dest[38] = s13.field8;
    fn_801CE6A4(&s14, (s32)(base + 0x428), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x110, s13.field4, s13.field0));
    dest[39] = s14.field0; dest[40] = s14.field4; dest[41] = s14.field8;
    fn_801CE6A4(&s15, (s32)(base + 0x438), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x124, s14.field4, s14.field0));
    dest[42] = s15.field0; dest[43] = s15.field4; dest[44] = s15.field8;
    fn_801CE6A4(&s16, (s32)(base + 0x448), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x138, s15.field4, s15.field0));
    dest[45] = s16.field0; dest[46] = s16.field4; dest[47] = s16.field8;
    fn_801CE6A4(&s17, (s32)(base + 0x358), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x14c, s16.field4, s16.field0));
    dest[48] = s17.field0; dest[49] = s17.field4; dest[50] = s17.field8;
    fn_801CE6A4(&s18, (s32)(base + 0x458), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x160, s17.field4, s17.field0));
    dest[51] = s18.field0; dest[52] = s18.field4; dest[53] = s18.field8;
    fn_801CE6A4(&s19, (s32)(base + 0x468), (s32)((void *(*)(void*,s32,s32))fn_801CE6CC)((char *)arg0 + 0x174, s18.field4, s18.field0));
    dest[54] = s19.field0; dest[55] = s19.field4; dest[56] = s19.field8;
    fn_801CE6A4(&s20, (s32)(base + 0x474), s31 == 0 ? (s32)((void *(*)(void*))fn_801CE6CC)((char *)arg0 + 0x188) : (s32)lbl_8055AB30);
    dest[57] = s20.field0; dest[58] = s20.field4; dest[59] = s20.field8;
    fn_801CE6A4(&s21, (s32)(base + 0x488), s31 == 1 ? (s32)((void *(*)(void*))fn_801CE6CC)((char *)arg0 + 0x188) : (s32)lbl_8055AB30);
    dest[60] = s21.field0; dest[61] = s21.field4; dest[62] = s21.field8;
    fn_801CE6A4(&s22, (s32)(base + 0x49c), s31 == 2 ? (s32)((void *(*)(void*))fn_801CE6CC)((char *)arg0 + 0x188) : (s32)lbl_8055AB30);
    dest[63] = s22.field0; dest[64] = s22.field4; dest[65] = s22.field8;
    fn_801CE6A4(&s23, (s32)(base + 0x4b0), (s32)((void *(*)(void*,s32,s32))fn_801CE6A0)((char *)arg0 + 0x19c, s22.field4, s22.field0));
    dest[66] = s23.field0; dest[67] = s23.field4; dest[68] = s23.field8;
    fn_801CE6A4(&s24, (s32)(base + 0x4c4), (s32)((void *(*)(void*,s32,s32))fn_801CE6A0)((char *)arg0 + 0x200, s23.field4, s23.field0));
    dest[69] = s24.field0; dest[70] = s24.field4; dest[71] = s24.field8;
    fn_801CE6A4(&s25, (s32)(base + 0x4dc), (s32)((void *(*)(void*,s32,s32))fn_801CE69C)((char *)arg0 + 0x276, s24.field4, s24.field0));
    dest[72] = s25.field0; dest[73] = s25.field4; dest[74] = s25.field8;
    fn_801CE6A4(&s26, (s32)(base + 0x4ec), (s32)((void *(*)(void*,s32,s32))fn_801CE698)((char *)arg0 + 0x264, s25.field4, s25.field0));
    dest[75] = s26.field0; dest[76] = s26.field4; dest[77] = s26.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s27, (s32)(base + 0x4f8), (s32)((char *)arg0 + 0x2b8), s26.field4);
    dest[78] = s27.field0; dest[79] = s27.field4; dest[80] = s27.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s28, (s32)(base + 0x358), (s32)((char *)arg0 + 0x2c8), s27.field4);
    dest[81] = s28.field0; dest[82] = s28.field4; dest[83] = s28.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s29, (s32)(base + 0x458), (s32)((char *)arg0 + 0x2d8), s28.field4);
    dest[84] = s29.field0; dest[85] = s29.field4; dest[86] = s29.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&s30, (s32)(base + 0x468), (s32)((char *)arg0 + 0x2e8), s29.field4);
    dest[87] = s30.field0; dest[88] = s30.field4; dest[89] = s30.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t1, (s32)lbl_8055AB3C, (s32)((char *)arg0 + 0x2f8), s30.field4);
    dest[90] = t1.field0; dest[91] = t1.field4; dest[92] = t1.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t2, (s32)lbl_8055AB40, (s32)((char *)arg0 + 0x308), t1.field4);
    dest[93] = t2.field0; dest[94] = t2.field4; dest[95] = t2.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t3, (s32)lbl_8055AB44, (s32)((char *)arg0 + 0x318), t2.field4);
    dest[96] = t3.field0; dest[97] = t3.field4; dest[98] = t3.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t4, (s32)lbl_8055AB48, (s32)((char *)arg0 + 0x328), t3.field4);
    dest[99] = t4.field0; dest[100] = t4.field4; dest[101] = t4.field8;
    ((void (*)(Struct_801CE670*,s32,s32,s32))fn_801CE670)(&t5, (s32)lbl_8055AB4C, (s32)((char *)arg0 + 0x338), t4.field4);
    dest[102] = t5.field0; dest[103] = t5.field4; dest[104] = t5.field8;
    dest[105] = lbl_802FAA40[0]; dest[106] = lbl_802FAA40[1]; dest[107] = lbl_802FAA40[2];
    *(s32 *)((char *)arg0 + 0x1c) = fn_802ADF34(*(void **)((char *)arg0 + 8), base + 0x504, dest);
    *(void **)((char *)arg0 + 0xc) = fn_80207848((void *)(base + 0x514), 1);
    *(void **)((char *)arg0 + 0x10) = fn_80207848((void *)(base + 0x528), 1);
    *(void **)((char *)arg0 + 0x14) = fn_80207848((void *)(base + 0x53c), 1);
    zero = lbl_805629FC;
    one = lbl_805629E4;
    *(s32 *)arg0 = 0;
    *(f32 *)((char *)arg0 + 4) = zero;
    *(s32 *)((char *)arg0 + 0x18) = 0;
    p = (f32 *)((char *)arg0 + 0x2b8);
    p[0] = one; p[1] = zero; p[2] = zero; p[3] = zero;
    p[4] = one; p[5] = zero; p[6] = zero; p[7] = zero;
    p[8] = one; p[9] = zero; p[10] = zero; p[11] = zero;
    p[12] = one; p[13] = zero; p[14] = zero; p[15] = zero;
    p[16] = one; p[17] = zero; p[18] = zero; p[19] = zero;
    p[20] = one; p[21] = zero; p[22] = zero; p[23] = zero;
    p[24] = one; p[25] = zero; p[26] = zero; p[27] = zero;
    p[28] = one; p[29] = zero; p[30] = zero; p[31] = zero;
    p[32] = one; p[33] = zero; p[34] = zero; p[35] = zero;
    p[36] = one; p[37] = zero; p[38] = zero; p[39] = zero;
    if (*(void **)((char *)arg0 + 8) != 0) fn_802AE0E0();
    obj = *(char **)((char *)arg0 + 0xc);
    if (obj != 0) {
        *(u8 *)(obj + 0x4a) = 1;
        *(u8 *)(obj + 0x4c) = 0;
    }
    obj = *(char **)((char *)arg0 + 0x10);
    if (obj != 0) {
        *(u8 *)(obj + 0x4a) = 1;
        *(u8 *)(obj + 0x4c) = 0;
    }
    obj = *(char **)((char *)arg0 + 0x14);
    if (obj != 0) {
        *(u8 *)(obj + 0x4a) = 1;
        *(u8 *)(obj + 0x4c) = 0;
    }
}
#pragma dont_inline off

#pragma pop
#pragma paired_single off
#pragma scheduling invalid_target
void fn_801CE670(Struct_801CE670 *out, s32 value1, s32 value2) {
    /* Initialize a 3-word descriptor with a fixed kind tag (5) and two caller values. */
    Struct_801CE670 node;
    node.field4 = value1;
    node.field0 = 5;
    node.field8 = value2;
    *out = node;
}

/* No-op stub. */
void fn_801CE698(void) {

}

/* No-op stub. */
void fn_801CE69C(void) {

}

/* No-op stub. */
void fn_801CE6A0(void) {

}

/* Initialize a 3-word descriptor with a fixed kind tag (1) and two caller values. */
void fn_801CE6A4(Struct_801CE670 *out, s32 value1, s32 value2) {
    Struct_801CE670 node;
    node.field4 = value1;
    node.field0 = 1;
    node.field8 = value2;
    *out = node;
}

/* No-op stub. */
void fn_801CE6CC(void) {

}

extern unsigned char *fn_801EA9A0();
extern s32 *lbl_8055E884;
extern void fn_801CBD48(void *, void *);
extern void fn_802AE220(void *);
extern void fn_8001DFCC(void);
// Initializes a 3-word descriptor with a fixed kind tag (3) and two caller values.
void fn_801CE6D0(Struct_801CE670 *out, s32 value1, s32 value2) {
    Struct_801CE670 node;
    node.field4 = value1;
    node.field0 = 3;
    node.field8 = value2;
    *out = node;
}

void fn_801CE6F8(void) {
    /* Update the active race/menu state each frame, skipping when unavailable. */
    s32 *state;
    if (fn_801CE898() != 0) return;
    state = lbl_8055E884;
    fn_801CBD48((void *)(state + 0x2C0 / 4), (void *)state);
    if (state[0x2C8 / 4] != 0)
        ((void (*)(void *, void *))fn_802AE220)((void *)state[0x2C8 / 4], (void *)(state + 0x608 / 4));
    if (state[0x2C0 / 4] == 3)
        fn_8001DFCC();
}

/* RealName: StatManager_IsComplete (stat manager unavailable, or its block state has reached 3). */
int fn_801CE75C(void) {
#define StatManager_IsUnavailable fn_801CE898
#define sStatManager lbl_8055E884
    if (StatManager_IsUnavailable() != 0) {
        return 1;
    }
    return sStatManager[0x2C0 / 4] == 3;
#undef StatManager_IsUnavailable
#undef sStatManager
}

extern unsigned int fn_801CE898(void);
extern void fn_802ADE60(void *, int);
/* The one stat/awards manager (0x618 bytes): made by fn_801CC470, reset by
   resetStatHandler / resetAwardHandler and freed by fn_801CCCAC.  Its stat block starts at
   +0x2C0; the four pointers below the block's state word are the stat objects
   the manager owns. */
#define sStatManager lbl_8055E884
struct StatBlock {
    char pad0[0x2C0];
    s32 state;            /* 0x2C0: block state, 3 once it is done (fn_801CE75C) */
    f32 field2C4;         /* 0x2C4 */
    void *entrySet;       /* 0x2C8: set of 0x74-byte stat entries, freed by fn_802ADE60 */
    void *statObjects[3]; /* 0x2CC, 0x2D0, 0x2D4: stat objects with a virtual destroy */
};
#pragma cplusplus on
extern "C" void fn_801CE7A0(void) {
    /* Give back the four stat objects the manager owns and clear their slots:
       the entry set at +0x2C8 is freed by fn_802ADE60(obj, 1), the three stat
       objects after it through their virtual destroy(1).  Nothing to do while
       the stat info tables are not loaded (fn_801CE898). */
    class StatObject {
    public:
        virtual void destroy(s32);
    };
    StatBlock *block;
    StatObject *stat;

    if (fn_801CE898() != 0) return;
    block = (StatBlock *)sStatManager;
    stat = (StatObject *)block->entrySet;
    if (stat != 0) { fn_802ADE60(stat, 1); block->entrySet = 0; }
    stat = (StatObject *)block->statObjects[0];
    if (stat != 0) { if (stat != 0) stat->destroy(1); block->statObjects[0] = 0; }
    stat = (StatObject *)block->statObjects[1];
    if (stat != 0) { if (stat != 0) stat->destroy(1); block->statObjects[1] = 0; }
    stat = (StatObject *)block->statObjects[2];
    if (stat != 0) { if (stat != 0) stat->destroy(1); block->statObjects[2] = 0; }
}
#pragma cplusplus reset
/* Read a byte from the current entry; index is forwarded to the entry accessor as its argument. */
int fn_801CE874(int index) {
    return *fn_801EA9A0();
}

unsigned int fn_801CE898(void) {
    /* Stat-manager flag (StatManager_IsUnavailable): 1 when the record count from fn_800167F4 is >= 2, else 0. */
    int recordCount = fn_800167F4();
    int flipped = recordCount ^ 1;
    int half = flipped >> 1;
    flipped &= recordCount;
    return (unsigned int)(half - flipped) >> 31;
}

extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_8000DA10(void);
extern void *fn_8001BB58(s32, s32, s32);
extern int fn_80160AB4(void);
extern void fn_801CD730(s32 *, s32 *);
#pragma dont_inline on
int fn_801CE8CC(void) {
    s32 spC;
    s32 sp8;
    s32 *lfoTable2;
    s32 *lfoTable1;
    s32 value;
    s32 limit;
    void *candidate;

    /* Check whether a valid object/index is available (early reject, direct lookup, or fallback query). */
    if (fn_801CE898() != 0) return 1;

    limit = fn_80160AB4();
    lfoTable2 = __AXFXGetLfoSinTable_801769CC();
    lfoTable1 = __AXFXGetLfoSinTable_801769CC();
    candidate = (void *)fn_8000DA10();
    candidate = ((void *(*)(int, s32, s32, s32))fn_8001BB58)((int)candidate, *lfoTable1, lfoTable2[2], 0);
    if (candidate != NULL) {
        value = ((s32 *)candidate)[2];
        if ((value >= 0) && (value <= limit)) return 1;
    }

    spC = -1;
    sp8 = 0;
    fn_801CD730(&sp8, &spC);
    if ((spC >= 0) && (spC <= limit)) return 1;
    return 0;
}
#pragma dont_inline reset
/* Deleting destructor for an effect object: releases subobjects, runs base cleanup, and optionally frees storage. */
void *fn_801CE9A0(void *self, s32 shouldDelete) {
    if (self != 0) {
        *(void **)((char *)self + 4) = &lbl_80338024[0];
        fn_801CEA28((char *)self + 8);
        fn_801CEA28((char *)self + 0xC);
        if (self != 0) {
            void (*cleanup)(void *);
            cleanup = fn_801CBD04;
            *(void **)((char *)self + 4) = &lbl_80338038[0];
            cleanup(self);
        }
        if (shouldDelete > 0)
            fn_80128668(self);
    }
    return self;
}
/* Free the buffer stored at the given slot and clear the slot. */
void fn_801CEA28(void *slot) {
    void *buffer = *(void **)slot;
    if (buffer != NULL) {
        fn_80128668(buffer);
        *(void **)slot = NULL;
    }
}

extern int fn_80128668(void *);
extern void fn_801CBD04(void *);
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
#pragma scheduling on
int fn_801CEA6C(void *obj, int value) {
    /* Integer twin of fn_801CEBD8: `obj` holds up to three stat records, a primary
     * one at +0x0 and two optional ones at +0x8 and +0xC.  `value` has to beat the
     * primary record's current value, and is then stored into that record as its
     * override; every optional record that is set has to accept `value` too.
     * Returns 0 as soon as one of them refuses, 1 when all of them accept. */
#define BeatsRecord fn_8001C0EC /* (record, value): does value beat the record? */
#define SetOverride fn_8001C0E8 /* (record, value): store value in the record */
    int record;
    record = *(int *)obj;
    if (BeatsRecord(record) == 0) goto fail; /* r4 still carries `value` here */
    SetOverride(record, value);
    record = *(int *)((char *)obj + 8);
    if (record != 0) {
        if (((int (*)(int, int))BeatsRecord)(record, value) == 0) goto fail;
    }
    record = *(int *)((char *)obj + 0xC);
    if (record != 0) {
        if (((int (*)(int, int))BeatsRecord)(record, value) == 0) goto fail;
    }
    return 1;
fail:
    return 0;
#undef BeatsRecord
#undef SetOverride
}

#pragma scheduling on
/* Destroys an object: resets its vtable/owned fields and optionally frees it. */
void *fn_801CEB0C(void *object, s32 freeFlag) {
    if (object != 0) {
        *(void **)((char *)object + 4) = &lbl_80338010[0];
        fn_801CEB94((char *)object + 8);
        fn_801CEB94((char *)object + 0xC);
        if (object != 0) {
            void (*cleanup)(void *);
            cleanup = fn_801CBD04;
            *(void **)((char *)object + 4) = &lbl_80338038[0];
            cleanup(object);
        }
        if (freeFlag > 0)
            fn_80128668(object);
    }
    return object;
}
/* RealName: unknown (rename_symbol unavailable). Frees the owned buffer pointer
 * stored at *slot (if non-NULL) via fn_80128668, then clears the slot. */
void fn_801CEB94(void *arg0) {
#define FreeOwnedBuffer fn_80128668
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        FreeOwnedBuffer(buf);
        *(void **)arg0 = NULL;
    }
#undef FreeOwnedBuffer
}

/* Check/apply a float value against up to three handles stored at +0x0, +0x8, +0xC: requires +0x0 to pass fn_8001BF34, applies fn_8001BF0C to it, and optional handles at +0x8/+0xC must also pass fn_8001BF34 when non-null. */
s32 fn_801CEBD8(void *obj, f32 value) {
    s32 primaryHandle = *(s32 *)obj;
    if (((s32 (*)(s32, f32))fn_8001BF34)(primaryHandle, value) == 0) goto fail;
    fn_8001BF0C(primaryHandle, value);
    if (*(s32 *)((char *)obj + 8) != 0 &&
        ((s32 (*)(s32, f32))fn_8001BF34)(*(s32 *)((char *)obj + 8), value) == 0) goto fail;
    if (*(s32 *)((char *)obj + 0xC) != 0 &&
        ((s32 (*)(s32, f32))fn_8001BF34)(*(s32 *)((char *)obj + 0xC), value) == 0) goto fail;
    return 1;
fail:
    return 0;
}

