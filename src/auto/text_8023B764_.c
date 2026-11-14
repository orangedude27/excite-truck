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
extern void fn_8000C0E8(void);
extern u8 lbl_803413A8[];
extern s32 atoi(void);
extern void fn_802E317C(const char *);
extern const char lbl_80341354[];
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
s32 fn_8023B764(s32 arg0, s32 arg1) {
    return fn_802054EC((s32)&lbl_80341308, arg0, arg1);
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_8023B77C(void) {
    s32 var_r31;
    s32 var_r30;

    var_r31 = 0x129;
    var_r30 = 0x18D;
    if (fn_802C9A58() == 0) {
        var_r31 = 0x136;
        var_r30 = 0x1BC;
    }
    fn_802CED50((var_r31 * 0x280) / 512, 0x188, ((var_r30 - var_r31) * 0x280) / 512, 0x1F);
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
void fn_8023B8AC(s32 arg0) {
    fn_8000ABE0();
    fn_800126C0(arg0, arg0 + 0x3F8);
    fn_80244738();
    fn_8023B77C();
    fn_80211F44();
    if (fn_80019B3C() == 0) fn_8027B690();
    fn_8020A600();
}

#pragma scheduling invalid_target
void fn_8023B904(void *arg0, void *dest, s32 flag) {
    struct Buffer {
        u8 *data;
        s32 field0;
        s32 field1;
        s32 field2;
        u8 bytes[4];
        s32 tail[40];
    } local;
    s32 *source;
    s32 *target;
    s32 count;
    if (flag == 0) {
        local.data = lbl_803413A8;
        ((void (*)(void *, void *))fn_8000BF20)(arg0, &local);
        if (dest != 0) {
            *(s32 *)dest = local.field0;
            *(s32 *)((u8 *)dest + 4) = local.field1;
            *(s32 *)((u8 *)dest + 8) = local.field2;
            ((u8 *)dest)[0xC] = local.bytes[0];
            ((u8 *)dest)[0xD] = local.bytes[1];
            ((u8 *)dest)[0xE] = local.bytes[2];
            target = (s32 *)((u8 *)dest + 0xC);
            source = (s32 *)local.bytes;
            count = 0x14;
            do {
                target[1] = source[1];
                target[2] = source[2];
                source += 2;
                target += 2;
            } while (--count != 0);
        }
    } else {
        fn_8000C0E8();
    }
}
#pragma scheduling on
s32 fn_8023B9AC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
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
void fn_8023B9EC(s32 c0, s32 c1, s32 c2, s32 c3, s32 c4) {
    struct Context { u8 pad[0x3E4]; s32 value; s32 unk; s32 arg3; s32 zero; s32 flags; u8 trailing[0x50]; };
    struct Frame { const char *resource; s32 resource0; s32 resource1; s32 resource2; struct Context context; } frame;
    s32 active; s32 zero; const char *resource;
    active = fn_802ECEEC();
    if (active != 0) {
        fn_802ECEC0();
        resource = lbl_80341314;
        zero = 0;
        frame.resource = resource;
        frame.resource0 = fn_80128314(zero);
        frame.resource1 = fn_80128314(1);
        frame.resource2 = fn_80265D58();
        if (fn_80204024() != 0) fn_8012BF28();
        do {
            fn_801E952C(&frame.context);
            fn_8023B7EC(&frame.context, c0, c1, c3);
            frame.context.arg3 = c3;
            frame.context.zero = zero;
            if (fn_8023B764(c3, frame.context.value) != 0) { fn_802E30C8(resource + 0x14); frame.context.flags |= 2; }
            fn_8023B904(&frame.context, (void *)c2, c4);
            fn_8023B8AC((s32)&frame.context);
        } while (fn_80204024() != 0);
        fn_80129AEC(0);
        if (active != 0) fn_802ECEC4();
    }
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma scheduling on
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
typedef struct VTbl_8023BC24 { void *slot[2]; void (*fn2)(void *, int); } VTbl_8023BC24;
typedef struct Obj_8023BC24 { VTbl_8023BC24 *vt; } Obj_8023BC24;
int fn_8023BC24(int ignored, int arg1, int arg2) {
    Obj_8023BC24 *obj = (Obj_8023BC24 *)fn_8027DB40(1);
    int result = fn_8024DAE0(arg1, arg2, 0, (int)obj, 0);
    if (obj != 0) {
        void (**tbl)(void *, int) = (void (**)(void *, int))obj->vt;
        tbl[2](obj, 1);
    }
    return result;
}

int fn_8023BCAC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern u8 lbl_8055F291;
#pragma opt_propagation off
void fn_8023BCEC(void) {
    s32 sp20[0x2C];
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 temp_r31;
    fn_80137C78(1);
    fn_80137C84(fn_802E4A10(), 0);
    sp1C = *(s32 *)((u8 *)fn_80016464(0) + 4);
    sp18 = *(s32 *)((u8 *)fn_80016510(*(s32 *)((u8 *)fn_80016464(0) + 0x4C)) + 4);
    sp14 = *(s32 *)((u8 *)fn_80016464(0) + 0x50);
    sp10 = 0;
    spC = 0;
    sp8 = 0;
    do {
        while (((int (*)(s32 *, s32 *, s32 *, s32))fn_8023BC24)(&sp1C, &sp18, &sp14, 0) == 0) { (void)0; }
        temp_r31 = lbl_8055F291;
        fn_8000DA10();
        fn_800169F8(fn_8000DB34(), 0);
        fn_80016970(0, sp1C, sp18, sp14);
        fn_8023B9EC(sp10, spC, (s32)sp20, sp8, temp_r31);
        fn_80137C80(0);
    } while (fn_8024A4C4((s32)&sp10, (s32)&spC, (s32)&sp8) != 0);
}
#pragma opt_propagation reset
extern int fn_80128668(void);
extern void fn_802411C8(void);
extern int fn_8023FF1C(int);
extern void fn_8023BB0C(void);
extern void fn_8023B9EC(int, int, int, int, int);
extern void fn_8001EFC8(void);
extern int fn_8024A4CC(int *, int *, int *);
extern int fn_80137C74(void);
extern void fn_80137C80(int);
extern void fn_80137C78(int);
void fn_8023BDEC(void) {
    int i = 0;
    goto check;
body:
    fn_80137C80(i);
    i++;
check:
    if (i < fn_80137C74()) goto body;
    fn_80137C78(1);
}

#pragma dont_inline on
void fn_8023BE38(int ignored, int flag) {
    fn_80012794();
    fn_80012790(0x130);
    fn_802411C8();
    if (flag != 0) {
        fn_8023BBA8();
    } else {
        while (fn_8023FF1C(flag) != 1) {
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
    fn_8023BE38((int)lbl_80341340, 1);
}
#pragma scheduling reset
extern void *fn_8001285C(void);
extern void *fn_80012820(s32);
extern s32 *fn_80012870(s32, s32);
extern void fn_8023B9EC(s32, s32, s32, s32, s32);
extern void fn_8023BE38(int, int);
extern const char lbl_80341340[];
#pragma dont_inline on
void fn_8023BEB8(s32 arg0, s32 arg1, s32 arg2) {
    fn_8023B9EC(arg0, arg1, arg2, 0, 0);
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
void fn_8023BF4C(void *arg0) {
    fn_8023B9EC(*(s32 *)((u8 *)arg0 + 0),
                *(s32 *)((u8 *)arg0 + 4),
                *(s32 *)((u8 *)arg0 + 0xC),
                *(s32 *)((u8 *)arg0 + 8), 0);
}

extern s32 atoi(void);
extern void fn_802E317C(const char *);
extern const char lbl_80341354[];
extern s32 lbl_8055BB30;
void fn_8023BF68(void) {
    s32 value = atoi();
    lbl_8055BB30 = value;
    if (value == 0 || (((value >> 31) ^ value) - (value >> 31)) > 4) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80341354, value);
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

void fn_8023C20C(void) {}

void fn_8023C210(Dst8023C210 *dst, Src8023C210 *src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->t = src->t;
}

void fn_8023C268(void) {}
#pragma cplusplus on
extern "C" s32 fn_80007FF0(s32);
extern "C" s32 fn_80137C7C(s32, s32);
extern "C" u32 lbl_8055BB34;
extern const char lbl_8034137C[]; /* "GameDoEve: eve [%s] contest [%s] at %s" */

/* lbl_8055BB34: the .sdata string "name", the parameter-table element a
 * contest's own name is read from. */
#define contest_name_key lbl_8055BB34
/* lbl_8055BB30: how many players the debug console asked the next race to run
 * with (fn_8023BF68 rejects 0 and anything past 4).  A negative count gives
 * every player its own index instead of the currently selected player. */
#define player_count lbl_8055BB30
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
