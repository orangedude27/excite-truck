// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct { s32 w[40]; } Tail8023C210;
typedef struct { s32 pad; s32 a, b, c; u8 d, e, f, g; Tail8023C210 t; } Dst8023C210;
typedef struct { s32 a, b, c; u8 d, e, f, g; Tail8023C210 t; } Src8023C210;
extern s32 fn_80016464(s32);
extern s32 fn_802E4A10(void);
extern s32 fn_80137C84(s32, s32);
extern void fn_80137C80(s32);
extern void fn_80137C78(s32);

extern void fn_802411C8(void);
extern int fn_8023FF1C(int);
extern void fn_8023BB0C(void);
extern void fn_8023B9EC(int, int, int, int, int);
extern void fn_8001EFC8(void);
extern int fn_8024A4CC(int *, int *, int *);
extern s32 fn_80128668(void);
extern void fn_8000BF20(void *);
extern void restartGameFromContext(void);
extern u8 lbl_803413A8[];
extern s32 atoi();
extern void Abend_Panic(const char *, ...);
extern const char lbl_80341354[]; /* "Can't set %d players.  That's crazy." */
extern s32 lbl_8055BB30;
extern s32 fn_802054EC(s32, s32, s32);
extern void fn_802ECC18(s32);
extern void fn_802445FC(s32, s32, s32);
extern void fn_8020A634(void);
extern void fn_8027B77C(void);
extern void fn_80211F4C(void);
extern void fn_8023C0EC(void *, s32, s32);
extern void fn_80018318(void *, s32);
extern void fn_800126B4(void *, void *, s32, s32);
extern void fn_80018440(s32 *, s32, void *);
extern void fn_8000AB48(void *, s32 *);
extern s32 fn_802C9A58(void);
extern void fn_802CED50(s32, s32, s32, s32);
extern const char lbl_80341308[];
/* Queries the "mirror_mode" setting for the given key/index through the
 * resource lookup in fn_802054EC; returns nonzero when it is enabled. */
s32 fn_8023B764(s32 key, s32 index) {
    return fn_802054EC((s32)&lbl_80341308, key, index);
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_8023B77C(void) {
    /* Compute a horizontal scissor/rect region and submit it; values depend on fn_802C9A58(). */
    s32 left;
    s32 right;

    left = 0x129;
    right = 0x18D;
    if (fn_802C9A58() == 0) {
        left = 0x136;
        right = 0x1BC;
    }
    fn_802CED50((left * 0x280) / 512, 0x188, ((right - left) * 0x280) / 512, 0x1F);
}
#pragma scheduling on
#pragma dont_inline reset

#pragma push
#pragma opt_common_subs off
/* Initialize and run one game context frame sequence, preparing buffers/state used by subsequent systems. */
void fn_8023B7EC(void *context, s32 arg1, s32 arg2, s32 arg3) {
    s32 tempBuf[16];
    fn_802ECC18(0);
    fn_802445FC(arg1, arg2, arg3);
    fn_8023B77C();
    fn_8020A634();
    fn_8027B77C();
    fn_80211F4C();
    fn_8023C0EC(context, arg1, arg2);
    fn_80018318((u8 *)context + 0x3F8, arg1);
    fn_800126B4(context, (u8 *)context + 0x3F8, 0, 1);
    fn_80018440(tempBuf, *(s32 *)((u8 *)context + 0x3E4), (u8 *)context + 0x3F8);
    fn_8000AB48(context, tempBuf);
}
#pragma pop
/* Run one context/frame update: initialize per-frame state, run subsystems, then post-update steps. */
void fn_8023B8AC(s32 context) {
    fn_8000ABE0();
    fn_800126C0(context, context + 0x3F8);
    fn_80244738();
    fn_8023B77C();
    fn_80211F44();
    if (fn_80019B3C() == 0) {
        fn_8027B690();
    }
    fn_8020A600();
}

#pragma scheduling invalid_target
/* Run one game-loop frame with a result callback and copy the submitted race
 * results into `result`; when `reset` is nonzero, restart the frame context
 * through restartGameFromContext instead. */
void fn_8023B904(void *context, void *result, s32 reset) {
    struct Local8023B904 {
        u8 *data;                    /* callback vtable (lbl_803413A8) */
        s32 a, b, c;                 /* result fields filled by submit() */
        u8 d, e, f, g;
        Tail8023C210 t;
    } local;
    Src8023C210 *out;
    if (reset == 0) {
        local.data = lbl_803413A8;
        ((void (*)(void *, void *))fn_8000BF20)(context, &local);
        if (result != 0) {
            out = (Src8023C210 *)result;
            out->a = local.a;
            out->b = local.b;
            out->c = local.c;
            out->d = local.d;
            out->e = local.e;
            out->f = local.f;
            out->t = local.t;
        }
    } else {
        restartGameFromContext();
    }
}
#pragma scheduling on
s32 fn_8023B9AC(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

extern s32 fn_80128314(s32);
extern s32 fn_80265D58(void);
extern s32 fn_80204024(void);
extern void fn_8012BF28(void);
extern void fn_801E952C(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_80129AEC(s32);
extern s32 fn_802ECEEC(void);
extern void fn_802ECEC0(void);
extern void fn_802ECEC4(void);
extern char lbl_80341314[];
extern char lbl_80341328[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_8023B9EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    /* Run the single-player event loop ("msingle:do_event()"): initialize a frame context each iteration, enable mirror mode when requested, process/update it, and repeat while active. */
    struct Context {
        u8 pad[0x3E4];
        s32 value;
        s32 unk;
        s32 arg3;
        s32 zero;
        s32 flags;
        u8 trailing[0x40];
    };
    struct Frame {
        const char *resource;
        s32 resource0;
        s32 resource1;
        s32 resource2;
        struct Context context;
    } frame;
    const char *eventResource;
    s32 wasActive = fn_802ECEEC();
    if (wasActive != 0)
        fn_802ECEC0();
    eventResource = lbl_80341314;
    do {
        frame.resource = eventResource;
        frame.resource0 = fn_80128314(0);
        frame.resource1 = fn_80128314(1);
        frame.resource2 = fn_80265D58();
        if (fn_80204024() != 0)
            fn_8012BF28();
        fn_801E952C(&frame.context);
        fn_8023B7EC(&frame.context, arg0, arg1, arg3);
        frame.context.zero = 0;
        frame.context.arg3 = arg3;
        if (fn_8023B764(arg3, frame.context.value) != 0) {
            fn_802E30C8(lbl_80341328);
            frame.context.flags |= 2;
        }
        fn_8023B904(&frame.context, (void *)arg2, arg4);
        fn_8023B8AC((s32)&frame.context);
    } while (fn_80204024() != 0);
    fn_80129AEC(0);
    if (wasActive != 0)
        fn_802ECEC4();
}
void fn_8023BB0C(void) {
    /* Refresh the cached per-driver state for every active driver slot. */
    s32 outA, outC, outB;
    s32 driverCount = fn_802411CC();
    s32 driverIndex;
    s32 driverId;
    fn_800167FC();
    for (driverIndex = 0; driverIndex < driverCount; driverIndex++) {
        driverId = *(s32 *)((u8 *)fn_80016464(driverIndex) + 4);
        fn_802411D0(driverIndex, &outA, &outB, &outC);
        fn_80137C84(outC, driverIndex);
        fn_80016A44(driverIndex);
        fn_80016970(driverIndex, driverId, outA, outB);
    }
}

#pragma dont_inline on
/* Runs the multiplayer event selection and race loop: repeatedly prompts for an event (fn_8024A4CC), runs truck selection (fn_8023FF1C), and if not canceled refreshes driver slots and executes the event (fn_8023B9EC). */
void fn_8023BBA8(void) {
#define MRoll_Reset fn_802411C8
#define MRoll_SelectTrucks fn_8023FF1C
#define MSingle_RefreshDriverSlots fn_8023BB0C
#define MSingle_DoEvent fn_8023B9EC
#define MSingle_PostEvent fn_8001EFC8
#define MEvent_SelectMultiplayer fn_8024A4CC
    s32 cupIndex;
    s32 eventIndex;
    s32 mirrorMode;

    cupIndex = 0;
    eventIndex = 0;
    mirrorMode = 0;
    goto select_event;
run_event:
    MRoll_Reset();
    if (MRoll_SelectTrucks(1) != 1) {
        MSingle_RefreshDriverSlots();
        MSingle_DoEvent(cupIndex, eventIndex, 0, mirrorMode, 0);
        MSingle_PostEvent();
    }
select_event:
    if (MEvent_SelectMultiplayer(&cupIndex, &eventIndex, &mirrorMode) != 0) goto run_event;
#undef MEvent_SelectMultiplayer
#undef MSingle_PostEvent
#undef MSingle_DoEvent
#undef MSingle_RefreshDriverSlots
#undef MRoll_SelectTrucks
#undef MRoll_Reset
}
#pragma dont_inline reset

#pragma dont_inline reset
#pragma scheduling on
extern int fn_8027DB40(int);
extern int fn_8024DAE0(int, int, int, int, int);
#pragma push
#pragma cplusplus on
extern "C" int fn_8023BC24(int ignored, int paramA, int paramB) {
    struct Object { virtual void destroy(int); };
    /* Allocate a temporary effect object, run the fn_8024DAE0 state machine with it
     * and the caller's two parameters, then release the object and return the result. */
    Object *effect = (Object *)fn_8027DB40(1);
    int result = fn_8024DAE0(paramA, paramB, 0, (int)effect, 0);
    if (effect != 0) {
        effect->destroy(1);
    }
    return result;
}
#pragma pop
int fn_8023BCAC(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) fn_80128668();
    return object;
}

extern u8 lbl_8055F291;
#pragma opt_propagation off
void fn_8023BCEC(void) {
    /* Run the single-player menu/event selection loop for player 0 and execute the chosen event. */
    s32 eventParamBuf[0x2C];
    s32 driverId;
    s32 vehicleParam;
    s32 trackParam;
    s32 selA;
    s32 selB;
    s32 selC;
    u8 savedFlag;
    fn_80137C78(1);
    fn_80137C84(fn_802E4A10(), 0);
    driverId = *(s32 *)((u8 *)fn_80016464(0) + 4);
    vehicleParam = *(s32 *)((u8 *)fn_80016510(*(s32 *)((u8 *)fn_80016464(0) + 0x4C)) + 4);
    trackParam = *(s32 *)((u8 *)fn_80016464(0) + 0x50);
    selA = 0;
    selB = 0;
    selC = 0;
    while (fn_8024A4C4((s32)&selA, (s32)&selB, (s32)&selC) != 0) {
        if (((int (*)(s32 *, s32 *, s32 *, s32))fn_8023BC24)(&driverId, &vehicleParam, &trackParam, 0) != 0) {
            savedFlag = lbl_8055F291;
            fn_8000DA10();
            fn_800169F8(fn_8000DB34(), 0);
            fn_80016970(0, driverId, vehicleParam, trackParam);
            fn_8023B9EC(selA, selB, (s32)eventParamBuf, selC, savedFlag);
            fn_80137C80(0);
        }
    }
}
#pragma opt_propagation reset
extern int fn_80137C74(void);
/* Call fn_80137C80 for each index from 0 up to (but not including) fn_80137C74(), then call fn_80137C78(1). */
void fn_8023BDEC(void) {
    int index = 0;
    goto check;
body:
    fn_80137C80(index);
    index++;
check:
    if (index < fn_80137C74()) goto body;
    fn_80137C78(1);
}

#pragma dont_inline on
void fn_8023BE38(int unused, int runMultiplayerLoop) {
    /* Run the truck-selection flow, then either the multiplayer event loop or a polling loop until selection completes. */
    fn_80012794();
    fn_80012790(0x130);
    fn_802411C8();
    if (runMultiplayerLoop != 0) {
        fn_8023BBA8();
    } else {
        while (fn_8023FF1C(runMultiplayerLoop) != 1) {
            fn_8023BB0C();
            fn_8023B5E0();
        }
    }
    fn_8023BDEC();
    fn_80012794();
    fn_80012778();
}
#pragma dont_inline reset

#pragma scheduling off
void fn_8023BEA8(void) {
    extern const char lbl_80341340[];
    /* Launch head-to-head (two-player versus) mode: run the truck-selection
     * flow with the multiplayer event loop, tagged with the "GameDoHeadToHead"
     * mode name. */
    fn_8023BE38((int)lbl_80341340, 1);
}
#pragma scheduling reset
extern void *fn_8001285C(void);
extern void *fn_80012820(s32);
extern s32 *fn_80012870(s32, s32);
extern void fn_8023BE38(int, int);
#pragma dont_inline on
/* Run the context/frame sequence with the given context id, index and parameter,
 * leaving the two extra options of fn_8023B9EC at their zero defaults. */
void fn_8023BEB8(s32 contextId, s32 index, s32 param) {
    fn_8023B9EC(contextId, index, param, 0, 0);
}
#pragma dont_inline reset

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
/* Find the index whose entry (via fn_80012870) matches targetId by scanning downward from the count at offset 0x70, then pass context id, found index (-1 if none), and param to fn_8023BEB8. */
void fn_8023BEC4(s32 targetId, s32 param) {
    s32 contextId;
    s32 foundIndex;
    s32 index;

    contextId = *(s32 *)((u8 *)fn_8001285C() + 4);
    foundIndex = -1;
    index = *(s32 *)((u8 *)fn_80012820(contextId) + 0x70);
    goto check;
body:
    if (targetId == *fn_80012870(contextId, index)) {
        foundIndex = index;
    }
check:
    if (index-- > 0) {
        goto body;
    }
    fn_8023BEB8(contextId, foundIndex, param);
}
#pragma scheduling on
#pragma use_lmw_stmw reset
void fn_8023BF4C(void *args) {
    /* Unpack a debug-command Args block (list, found at +4, arg2 at +8, arg0 at +0xC) and forward it to the command runner. */
    fn_8023B9EC(*(s32 *)((u8 *)args + 0),
                *(s32 *)((u8 *)args + 4),
                *(s32 *)((u8 *)args + 0xC),
                *(s32 *)((u8 *)args + 8), 0);
}

/* lbl_8055BB30: how many players the debug console asked the next race to run
 * with (fn_8023BF68 rejects 0 and anything past 4).  A negative count gives
 * every player its own index instead of the currently selected player. */
#define player_count lbl_8055BB30
/* Debug_SetPlayerCount: the debug console's player-count command.  The command
 * text its caller hands over is parsed with atoi() and kept for fn_8023BFBC to
 * run the next race with; 0 players or more than 4 of them (in absolute value,
 * a negative count being the "one index per player" form) is reported -- and
 * stays set all the same. */
void fn_8023BF68(const char *countText) {
    s32 playerCount = atoi(countText);
    player_count = playerCount;
    if (playerCount == 0 || (((playerCount >> 31) ^ playerCount) - (playerCount >> 31)) > 4) {
        Abend_Panic(lbl_80341354, playerCount);
    }
}

extern void fn_8000824C(void *, s32);
extern u32 lbl_8055BB3C; /* the string "track": the table element a contest's track is read from */

/* One event (a cup) of the event table at lbl_803518C0, 0x84 bytes each;
 * fn_80012B50 fills a record from the event's parameter table object.  Only
 * the fields this unit reads are named. */
struct EventRecord {
    s32 index;        /* +0x00: its index in the table */
    s32 league;       /* +0x04: the table's "league" element */
    char track[0x20]; /* +0x08: the table's "track" element */
    char name[0x40];  /* +0x28: "name2", or "name" when the table has none */
    u8 unk_68[0x18];
    void *table;      /* +0x80: the event's parameter table object */
};

/* One contest (a course of an event) of the table at lbl_80352AD0, 0x28 bytes
 * each, count lbl_8055D508; fn_80012B50 appends one per contest of an event. */
struct ContestEntry {
    s32 index;    /* +0x00: its index in the table */
    s32 eventId;  /* +0x04: the event the contest belongs to */
    s32 type;     /* +0x08: contest type word; fn_80007FF0 turns it into a name */
    s32 unk_0C[5];
    void *table;  /* +0x20: the contest's parameter table object */
    s32 inUse;    /* +0x24: the entry holds a contest */
};

#pragma cplusplus on
void fn_8023C0EC(void *setup, s32 eventId, s32 contestIdx) {
    /* A contest's parameter table object (ContestEntry+0x20): slot 0xC asks
     * whether the table holds an element, slot 0x14 reads one as a string. */
    struct TableObject {
        virtual void f0();
        virtual s32 hasElement(const char *elementName);
        virtual void f2();
        virtual const char *getString(const char *elementName);
    };
    struct EventRecord *event = (struct EventRecord *)fn_80012820(eventId);
    struct ContestEntry *contest = (struct ContestEntry *)fn_80012870(eventId, contestIdx);
    const char *source;
    s32 count;
    char *dest;

    /* The contest's own "track" element when its table has one, otherwise the
     * track its event was defined with. */
    if (((struct TableObject *)contest->table)->hasElement((const char *)&lbl_8055BB3C) != 0) {
        source = ((struct TableObject *)contest->table)->getString((const char *)&lbl_8055BB3C);
        count = 0x20;
        dest = (char *)setup;
        while ((s8)(*dest++ = *source++) != 0) {
            if (--count <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    } else {
        source = event->track;
        count = 0x20;
        dest = (char *)setup;
        while ((s8)(*dest++ = *source++) != 0) {
            if (--count <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    /* which contest of which event this setup was built for */
    fn_8000824C((char *)setup + 0x3e4, contest->index);
}
#pragma cplusplus reset

/* No-op virtual slot +0x8 of the race-result callback vtable lbl_803413A8
 * (installed by fn_8023B904): this callback does nothing. */
void fn_8023C20C(void) {}

/* Copies a source record (three s32 header fields, three bytes, and a 0xA0-byte tail)
 * into a destination record that has a 4-byte leading pad, field-by-field so the
 * compiler emits the same bytewise tail copy as the original. */
void fn_8023C210(Dst8023C210 *dst, Src8023C210 *src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->t = src->t;
}

/* Intentionally empty placeholder callback: does nothing and returns immediately. */
void fn_8023C268(void) {}
#pragma cplusplus on
extern "C" s32 fn_80007FF0(s32);
extern "C" s32 fn_80137C7C(s32, s32);
extern "C" u32 lbl_8055BB34;
extern const char lbl_8034137C[]; /* "GameDoEve: eve [%s] contest [%s] at %s" */

/* lbl_8055BB34: the .sdata string "name", the parameter-table element a
 * contest's own name is read from. */
#define contest_name_key lbl_8055BB34
extern "C" void fn_8023BFBC(s32 eventId, s32 contestIdx) {
    /* The contest's parameter table object (ContestEntry+0x20).  Slot 0x18
     * reads an element of the table as a string, falling back on the name it
     * is handed when the table has no such element. */
    struct ParamTable {
        virtual void f0();
        virtual s32 hasElement(const char *elementName);
        virtual void f2();
        virtual const char *getString(const char *elementName);
        virtual const char *getName(const char *elementName, const char *fallback);
    };
    struct EventRecord *event;
    struct ContestEntry *contest;
    const char *typeName;
    s32 players;
    s32 sign;
    s32 channelCount;
    const char *contestName;

    /* Log which event, contest and track this (event, contest) pair picked,
     * then run it with as many players as the debug console asked for: every
     * player channel is set up first and released again once the race ends. */
    event = (struct EventRecord *)fn_80012820(eventId);
    contest = (struct ContestEntry *)fn_80012870(eventId, contestIdx);
    typeName = (const char *)fn_80007FF0(contest->type);
    contestName = ((struct ParamTable *)contest->table)->getName((const char *)&contest_name_key, typeName);
    fn_802E30C8(lbl_8034137C, event->name, contestName, event->track);
    players = player_count;
    sign = players >> 31;
    channelCount = (sign ^ players) - sign;
    fn_80137C78(channelCount);
    {
        s32 i;
        for (i = 0; i < channelCount; i++) {
            if (player_count >= 0) {
                fn_80137C84(fn_802E4A10(), i);
            } else {
                fn_80137C84(i, i);
            }
            fn_80137C7C(*(s32 *)((u8 *)fn_80016464(i) + 4), i);
        }
    }
    fn_8023BEB8(eventId, contestIdx, 0);
    {
        s32 i;
        for (i = 0; i < channelCount; i++) {
            fn_80137C80(i);
        }
    }
}
#pragma cplusplus reset
