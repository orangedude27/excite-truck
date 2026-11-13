// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E160;
extern int lbl_802F9350[3];
extern char lbl_8042F858[];
extern int lbl_802F9360[];
extern char lbl_8032C374[];
extern char lbl_8032C364[];
extern float lbl_80561434;
extern float lbl_80561440;
extern float lbl_80561448;
extern float lbl_80561460;
extern float lbl_80559C98;
extern char lbl_8055E161;
extern float fn_80134B58(float *, float);
extern float fn_8013B5DC(int, int);
extern int fn_80028E00(char *, int);
extern int fn_8013A6D4(int);
extern int fn_802E317C(char *, ...);
extern char lbl_8032C1A0[];
extern char lbl_8032C1E8[];
extern char lbl_8032C1F8[];
extern void *fn_8001285C(int);
extern void *fn_80012820(int);
extern float lbl_80561438;
extern float lbl_8056143C;
extern char lbl_80559CB8;
extern char lbl_80559CBC;
extern int fn_8013A9C0(void *, void *, void *, void *);
extern int fn_8027AA48(void);
extern void fn_802E30C8(char *, ...);
extern float fn_8013AA68(void *, void *, void *, void *);
extern int *fn_801E87A8(void);
extern int fn_80135108(void);
extern void fn_801E879C(void);
extern void *fn_80016464(int);
extern int fn_80016508(void *);
extern int fn_80129D90(int, int, int);
extern void qsort(void *, int, int, int (*)(void *, void *));
typedef struct { int pad[3]; int (*m_fn)(void); } unkVtable;
typedef struct { int pad[7]; int (*m_fn)(void); } unkVtable7;
typedef struct { int pad[9]; float (*m_float)(char *); } unkVtableFloat;
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8013A660(void *arg0, char *arg1, char *arg2) {
    struct Dummy {
        virtual int f0();
        virtual int f1();
    };
    if (((Dummy *)arg0)->f1() == 0) {
        fn_802E317C(lbl_8032C1A0, arg2, arg1);
    }
}
#pragma cplusplus reset
#pragma scheduling on
int fn_8013A6C4(void *arg0, void *arg1) {
    return *(int *)((char *)arg0 + 8) - *(int *)((char *)arg1 + 8);
}

int fn_8013A6D4(int arg0) {
    int values[3];
    int *p = lbl_802F9350;
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p;
    return values[arg0];
}

#pragma push
#pragma inline_depth(0)
char *fn_8013A708(char *arg0, int arg1, int arg2) {
    strcpy(arg0, (char *)fn_8013A6D4(arg1));
    fn_80028E00(arg0, arg2);
    return arg0;
}
#pragma pop

#pragma dont_inline fn_8013A708
#pragma cplusplus on
int fn_8013A760(unkVtable **arg0, int arg1) {
    char buffer[0x20];
    int i = 0;
    do {
        char *name = ((char *(*)(char *, int, int))fn_8013A708)(buffer, i, arg1);
        void *tbl = *(void **)arg0;
        int (*slot)(unkVtable **, char *) = *(int (**)(unkVtable **, char *))((char *)tbl + 0xc);
        if (slot(arg0, name) != 0)
            return 1;
        i++;
    } while (i < 3);
    return 0;
}
#pragma cplusplus reset
#pragma push
#pragma scheduling invalid_target
void fn_8013A7E8(unkVtable **arg0, char *arg1, char *arg2) {
    char buffer[0x20];
    int i = 0;
    do {
        char *name = ((char *(*)(char *, int, int))fn_8013A708)(buffer, i, (int)arg1);
        ((void (*)(unkVtable **, char *, char *))fn_8013A660)(arg0, name, arg2);
        i++;
    } while (i < 3);
}
#pragma pop
extern char lbl_8032C1E8[];
extern char lbl_8032C1F8[];
#pragma cplusplus on
extern "C" int fn_8013A860(float *outValues, void *reader) {
    class LocalVtable {
    public:
        virtual void v1();
        virtual int check(char *);
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual float get(char *);
    };
    /* Read "speed_factor"/"skill_range" from reader into outValues[0..1] (skill_range, speed_factor); return nonzero if present. */
    int hasValue = ((LocalVtable *)reader)->check(lbl_8032C1E8);
    if (hasValue != 0) {
        outValues[0] = ((LocalVtable *)reader)->get(lbl_8032C1F8);
        outValues[1] = ((LocalVtable *)reader)->get(lbl_8032C1E8);
    }
    return hasValue;
}

#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" float fn_8013A90C(void *arg0, int arg1, int arg2, float arg3) {
    /* Interpolate a table float between row arg2 and arg2+1 for column arg1.
     * Builds the element name for each row via fn_8013A708 and reads it through
     * vtable slot 0x24 (get float by name), then lerps: value2 + arg3*(value1-value2). */
    class LocalVtable {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual float get(char *);
    };
    char nameNext[0x20];
    char nameCur[0x20];
    float temp_f1;
    float temp_f31;
    temp_f31 = ((LocalVtable *)arg0)->get(
        ((char *(*)(char *, int, int))fn_8013A708)(nameCur, arg2 + 1, arg1));
    temp_f1 = ((LocalVtable *)arg0)->get(
        ((char *(*)(char *, int, int))fn_8013A708)(nameNext, arg2, arg1));
    return temp_f1 + arg3 * (temp_f31 - temp_f1);
}
#pragma pop

/* Offsets of the strings in the block at lbl_8032C1A0 (the first one is the
   warning fn_8013A660 prints when a table has no element). */
#define AI_STR_NO_ELEMENT 0x00 /* "AI: Warning: table \"%s\" has no element \"%s\"" */
#define AI_STR_NO_GHOST 0x40   /* "AI: Warning: No ghost data." */
#define AI_STR_SPEED_FACTOR 0x48 /* "speed_factor" */
#define AI_STR_SKILL_RANGE 0x58  /* "skill_range" */
#define AI_STR_EASY_SKILL_RANGE 0x64 /* "easy_skill_range" */
#define AI_STR_CONTEST_TABLE 0x78 /* "Contest Table" */
#define AI_STR_EVE_TABLE 0x88     /* "Eve Table" */
#define AI_STR_NO_SKILL 0x94 /* "skill: !! !! no skill for this contest !! !!" */
/* The three difficulty prefixes fn_8013A708 puts in front of an element name:
   lbl_802F9350 = {"easy_", "medium_", "hard_"}. */
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_8013AB08(float *skill_speed, int *entry) {
    /* AI skill and speed for one opponent: skill_speed[0] = skill_range and
     * skill_speed[1] = speed_factor, read from the contest/event tables.
     *
     * entry[0] indexes the scene records (fn_8001285C, 0x28 bytes each); the id
     * at +4 of that record picks an event record (fn_80012820, 0x84 or 0x88
     * bytes each).  The contest table is the scene record's +0x20 and the event
     * table the event record's +0x80.  Each can supply the pair two ways:
     * fn_8013A860 reads the plain "speed_factor"/"skill_range" elements, and
     * fn_8013A9C0 interpolates them when the table has "easy_skill_range"
     * (fn_8013B6C0 turns entry[3], the race stage, into the row/fraction pair
     * that lerps between the "easy_"/"medium_"/"hard_" elements - fn_8013A90C).
     * If none of the four lookups finds anything, fall back to the defaults
     * (skill_range 0.05, speed_factor 1.5) and print the "no skill for this
     * contest" warning.  Then, unless the fn_8027AA48 mode flag is set, the
     * stage-scaled "srd" and "sfd" adjustments (skill-range and speed-factor
     * deltas, 0.0 when the contest table has none) are added on. */
    char *strings = lbl_8032C1A0;
    void *contest_rec = fn_8001285C(*entry);
    void *event_rec = fn_80012820(*(int *)((char *)contest_rec + 4));

    if (((int (*)(float *, void *, void *))fn_8013A860)(skill_speed, *(void **)((char *)contest_rec + 0x20), strings + AI_STR_CONTEST_TABLE) == 0 &&
        ((int (*)(float *, void *, void *))fn_8013A860)(skill_speed, *(void **)((char *)event_rec + 0x80), strings + AI_STR_EVE_TABLE) == 0 &&
        fn_8013A9C0(skill_speed, *(void **)((char *)contest_rec + 0x20), entry, strings + AI_STR_CONTEST_TABLE) == 0 &&
        fn_8013A9C0(skill_speed, *(void **)((char *)event_rec + 0x80), entry, strings + AI_STR_EVE_TABLE) == 0) {
        float factor;
        float range;
        range = lbl_80561438;
        factor = lbl_8056143C;
        skill_speed[0] = range;
        skill_speed[1] = factor;
        fn_802E30C8(strings + AI_STR_NO_SKILL);
    }

    if (fn_8027AA48() == 0) {
        skill_speed[0] += fn_8013AA68(*(void **)((char *)contest_rec + 0x20), &lbl_80559CB8, strings + AI_STR_CONTEST_TABLE, entry);
        skill_speed[1] += fn_8013AA68(*(void **)((char *)contest_rec + 0x20), &lbl_80559CBC, strings + AI_STR_CONTEST_TABLE, entry);
    }
}
#pragma pop

#pragma cplusplus off
extern void *fn_8001285C(int);
extern void *fn_80012820(int);
extern int fn_8013A760(unkVtable **, int);
extern void fn_8013A7E8(unkVtable **, char *, char *);
extern float fn_8013A90C(void *, int, int, float);
extern void fn_8013B6C0(int *, float *, int);
extern char lbl_8032C264[];
float fn_8013AA68(void *, void *, void *, void *);
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_8013AC2C(int *arg0) {
    struct Target {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8(char *, float);
    };
    void *tmp = fn_8001285C(*arg0);
    void *parent = fn_80012820(*(int *)((char *)tmp + 4));
    Target *object = *(Target **)((char *)parent + 0x80);
    object->f8(lbl_8032C264, lbl_80561440);
}

extern int *fn_801E87A8(void);
extern int fn_80135108(void);
extern void fn_801E879C(void);
extern void *fn_80016464(int);
extern int fn_80016508(void *);
extern int fn_80129D90(int, int, int);
extern void qsort(void *, int, int, int (*)(void *, void *));
extern int fn_8013A6C4(void *, void *);
extern "C" int *fn_801E87A8(void);
extern "C" int fn_80135108(void);
extern "C" void fn_801E879C(void);
extern "C" void *fn_80016464(int);
extern "C" int fn_80016508(void *);
extern "C" int fn_80129D90(int, int, int);
extern "C" void qsort(void *, int, int, int (*)(void *, void *));
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_8013AC78(int arg0, int *arg1) {
    char *base = lbl_8032C1A0;
    struct Entry { int idx; int key; int score; } es[8];
    int pr[100];
    float sp8[2];
    float f31, t;
    int *a;
    int count, n, i, j, k, pairs;
    int *q;
    a = fn_801E87A8();
    count = fn_80135108();
    fn_801E879C();
    if (arg0 == 0) {
        fn_8013AB08(sp8, a);
    } else {
        fn_802E30C8(base + 0xD8, ((float *)arg0)[1], ((float *)arg0)[0]);
        sp8[0] = ((float *)arg0)[0];
        sp8[1] = ((float *)arg0)[1];
    }
    *(float *)(lbl_8042F858 + 0x48) = ((float (*)(int *))fn_8013AC2C)(a);
    *(float *)lbl_8042F858 = sp8[1];
    n = fn_80016508(lbl_8042F858);
    q = pr;
    for (i = 0; i < n; i++) {
        int *p = (int *)fn_80016464(i);
        q[0] = p[1];
        q[1] = p[0x12];
        q += 2;
    }
    pairs = i;
    q = (int *)es;
    for (k = 0; k < count; k++) {
        int *pp;
        q[0] = k;
        q[1] = *arg1;
        q[2] = fn_80129D90(3, -2, 2);
        for (j = 0, pp = pr; j < pairs; j++, pp += 2) {
            if (q[1] == *pp) {
                q[2] += pr[j * 2 + 1];
                break;
            }
        }
        q += 3;
        arg1++;
    }
    qsort(es, count, 12, fn_8013A6C4);
    f31 = lbl_80561440;
    t = (float)(count - 1);
    if (t > f31) f31 = t;
    for (k = 0; k < count; k++)
        *(float *)(lbl_8042F858 + es[k].idx * 8 + 8) = *(float *)lbl_8042F858 - ((float)k / f31) * sp8[0];
    q = (int *)es;
    for (k = 0; k < count; k++) {
        q[2] += fn_80129D90(3, -2, 2);
        q += 3;
    }
    qsort(es, count, 12, fn_8013A6C4);
    for (k = 0; k < count; k++)
        *(float *)(lbl_8042F858 + es[k].idx * 8 + 0xC) = *(float *)lbl_8042F858 - ((float)k / f31) * sp8[0];
    q = (int *)es;
    for (k = 0; k < count; k++) {
        void *vobj, *obj;
        int idx, has;
        int *pp;
        obj = 0;
        for (j = 0, pp = pr; j < pairs; j++, pp += 2) {
            if (*pp == q[1])
                obj = fn_80016464(j);
        }
        vobj = *(void **)((char *)obj + 0x58);
        idx = q[0];
        has = ((int (*)(void *, char *))(*(void ***)vobj)[3])(vobj, base + 0xF4);
        if (has != 0) {
            vobj = *(void **)((char *)obj + 0x58);
            *(float *)(lbl_8042F858 + idx * 8 + 8) = sp8[1] * ((float (*)(void *, char *))(*(void ***)vobj)[9])(vobj, base + 0xF4);
        }
        vobj = *(void **)((char *)obj + 0x58);
        if (((int (*)(void *, char *))(*(void ***)vobj)[3])(vobj, base + 0x10C) != 0) {
            char *r;
            vobj = *(void **)((char *)obj + 0x58);
            r = lbl_8042F858 + idx * 8;
            *(float *)(r + 0xC) = sp8[1] * ((float (*)(void *, char *))(*(void ***)vobj)[9])(vobj, base + 0x10C);
            if (has == 0)
                *(float *)(r + 8) = *(float *)(r + 0xC);
        }
        q += 3;
    }
}

#pragma pop
#pragma cplusplus off
#pragma scheduling on
void DBPrintf_8013B490(const char *fmt, ...) {
#pragma unused(fmt)
}

extern void fn_8013AC78(int, int *);
extern void fn_802049DC(int, int, float, float, float);
extern char lbl_8032C358[];
extern float lbl_80561450;
extern float lbl_80561454;
extern float lbl_80561438;
/* Collects per-entry values from the source data, applies them, then initializes
 * the drone-speed state/parameters. */
void fn_8013B4E0(void *arg0) {
    int entry_values[10];
    char *entry = (char *)arg0;
    int *dst = entry_values;
    int i = 0;
    int value;
    while (i < *(int *)((char *)arg0 + 0x3C0)) {
        value = *(int *)(entry + 0x68);
        entry += 0x78;
        i++;
        *dst = value;
        dst++;
    }
    fn_8013AC78(0, entry_values);
    lbl_80559C98 = lbl_80561440;
    fn_802049DC((int)(void *)lbl_8032C358, (int)(void *)&lbl_80559C98,
                lbl_80561450, lbl_80561454, lbl_80561438);
    lbl_8055E160 = 1;
    lbl_8055E161 = 0;
}

void fn_8013B56C(void) {
    lbl_8055E160 = 0;
}

#pragma scheduling invalid_target
void *fn_8013B578(int arg0) {
    return lbl_8042F858 + 8 + arg0 * 8;
}
#pragma scheduling on
extern void **fn_801B2ED0(void);
extern void *fn_80138B1C(int);
extern float lbl_80561430;
#pragma cplusplus on
extern "C" float fn_8013B590(void) {
    void *object = *fn_801B2ED0();
    int value = ((int (*)(void *))((void **)object)[7])(object);
    void *result = fn_80138B1C(*(int *)((char *)value + 0x2C));
    if (result != 0)
        return *(float *)((char *)result + 0xC);
    return lbl_80561430;
}

extern "C" float fn_80129DC4(int, float, float);
extern float lbl_80561458;
extern float lbl_8056145C;
#pragma dont_inline fn_8013B578
#pragma push
#pragma processor 750
float fn_8013B5DC(int arg0, int arg1) {
 void *p = ((void *(*)(int))fn_8013B578)(arg0);
 float t = ((float (*)(int))fn_8013B590)(arg0) / *(float *)((char *)p + 4);
 return t + t * fn_80129DC4(arg1, lbl_80561458, lbl_8056145C);
}
#pragma pop

#pragma cplusplus off
float fn_8013B650(int arg0) {
    float temp = fn_80134B58((float *)lbl_8032C364, lbl_80561434);
    return fn_8013B5DC(arg0, 3) + temp;
}

void fn_8013B6A4(int arg0, float arg1) {
    char *p = lbl_8042F858 + arg0 * 8;
    *(float *)(p + 0xC) = arg1;
    *(float *)(p + 8) = arg1;
}

extern int lbl_802F9360[];
extern char lbl_8032C374[];
extern char lbl_8032C364[];
extern float lbl_80561434;
extern float lbl_80561440;
extern float lbl_80561460;
extern float lbl_80559C98;
extern char lbl_8055E161;
extern float fn_80134B58(float *, float);
extern float fn_8013B5DC(int, int);
extern void *fn_8013B578(int);
void fn_8013B6C0(int *arg0, float *arg1, int arg2) {
    if (arg2 <= 4) {
        *arg0 = lbl_802F9360[arg2 * 2];
        *arg1 = *(float *)((char *)lbl_802F9360 + arg2 * 8 + 4);
    } else {
        fn_802E317C(lbl_8032C374, arg2);
        {
            float fallback = lbl_80561434;
            *arg0 = 0;
            *arg1 = fallback;
        }
    }
}

#pragma dont_inline on
float fn_8013B744(int arg0) {
    float v;
    if ((unsigned char)lbl_8055E161 != 0) {
        return lbl_80561440 - lbl_80561460 * (float)arg0;
    }
    v = *(float *)((char *)fn_8013B578(arg0) + 4);
    return v * lbl_80559C98;
}
#pragma dont_inline reset

#pragma push
#pragma processor 750
float fn_8013AA68(void *arg0, void *arg1, void *arg2, void *arg3) {
    int spC;
    float sp8;
    float result = *(volatile float *)&lbl_80561434;
    if (((int (*)(unkVtable **, int))fn_8013A760)((unkVtable **)arg0, (int)arg1) != 0) {
        ((void (*)(int *, float *, int))fn_8013B6C0)(&spC, &sp8, *(int *)((char *)arg3 + 0xC));
        ((void (*)(unkVtable **, char *, char *))fn_8013A7E8)((unkVtable **)arg0, (char *)arg1, (char *)arg2);
        result = ((float (*)(void *, int, int, float))fn_8013A90C)(arg0, (int)arg1, spC, sp8);
    }
    return result;
}
#pragma pop
