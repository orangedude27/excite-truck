// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#define M2F(e, t, o) (*(t)((char *)(e) + (o)))
extern char lbl_8033BBD8[];
extern void *fn_801E87A8(void);
extern void *fn_801284F8(int, void *);
extern const char lbl_8033BBE4[];
extern void *fn_80131808(const char *);
extern int fn_80012854(void);
extern char lbl_802F9D68[];
extern char lbl_8033BBA0[];
extern int *lbl_8055ED5C;
extern int lbl_8055B468;
extern int lbl_8055B470;
extern int lbl_8055B478;
extern signed char lbl_8055ED58;
extern int stricmp(const char *, const char *);
extern void fn_802E317C(const char *, ...);
extern void *fn_8001285C(void);
extern void fn_80131818(int);
extern void fn_80128668(void *);
#pragma dont_inline fn_80204B2C
int fn_80204B2C(const char *);
/* Return the contest-name string for the current scene's type, or 0 if unknown. */
int *fn_80204AA4(void) {
    int value = *(int *)((char *)fn_8001285C() + 8);
    switch (value) {
    case 0x180302: return &lbl_8055B468; /* "excite" */
    case 0x180201: return &lbl_8055B470; /* "zone" */
    case 0x180303: return &lbl_8055B478; /* "fs" */
    default: return 0;
    }
}

void *fn_80204B18(int arg0) {
    return lbl_802F9D68 + arg0 * 0xC;
}

int fn_80204BB4(const char *arg0) {
    return fn_80204B2C(arg0);
}

#pragma cplusplus on
#pragma dont_inline on
/* Build the 0x14-byte "difficulty" info block for the current scene (scene type,
 * property group, current difficulty value, stage value and contest name) and
 * publish it through lbl_8055ED5C. */
extern "C" void fn_80204BB8(void)
{
    #define DIFFICULTY_READY  lbl_8055ED58   /* info block is valid */
    #define DIFFICULTY_INFO   lbl_8055ED5C   /* published info block */
    #define DIFFICULTY_TAG    lbl_8033BBD8   /* "difficulty" allocation tag */
    #define DIFFICULTY_VAL    lbl_8033BBE4   /* "difficulty.val" property group */
    #define INFO_SIZE         0x14

    class PropertyGroup { public: virtual void *get(int) = 0; };
    class Stage { public:
        virtual void unused0() = 0;
        virtual void unused1() = 0;
        virtual void unused2() = 0;
        virtual void unused3() = 0;
        virtual void unused4() = 0;
        virtual void unused5() = 0;
        virtual void unused6() = 0;
        virtual void unused7() = 0;
        virtual void unused8() = 0;
        virtual void unused9() = 0;
        virtual void unused10() = 0;
        virtual void unused11() = 0;
        virtual void unused12() = 0;
        virtual void unused13() = 0;
        virtual void unused14() = 0;
        virtual void unused15() = 0;
        virtual void unused16() = 0;
        virtual void unused17() = 0;
        virtual void unused18() = 0;
        virtual void unused19() = 0;
        virtual void unused20() = 0;
        virtual int get(int) = 0; /* slot 0x17 */
    };
    void *scene;
    void **groupSlot;
    void *info;
    int stageIndex;
    int sceneType;
    void *typeEntry;
    void *groupValue;
    void **nameSlot;
    Stage *stageProps;
    int stageValue;
    DIFFICULTY_READY = 1;
    DIFFICULTY_INFO = 0;
    scene = fn_801E87A8();
    info = fn_801284F8(INFO_SIZE, DIFFICULTY_TAG);
    if (info == 0) goto done;
    stageIndex = *(int *)scene;
    sceneType = *(int *)((char *)scene + 8);
    *(int *)info = sceneType;
    *(int *)((char *)info + 4) = 0;
    groupSlot = (void **)((char *)info + 4);
    *(int *)((char *)info + 8) = 0;
    *(int *)((char *)info + 12) = 0;
    *(int *)((char *)info + 16) = 0;
    *groupSlot = fn_80131808(DIFFICULTY_VAL);
    typeEntry = fn_80204B18(sceneType);
    groupValue = ((PropertyGroup *)*groupSlot)->get(*(int *)((char *)typeEntry + 8));
    *(void **)((char *)info + 8) = groupValue;
    if (stageIndex >= 0 && stageIndex < fn_80012854()) {
        stageProps = *(Stage **)((char *)((void *(*)(int))fn_8001285C)(stageIndex) + 0x20);
        stageValue = stageProps->get(*(int *)((char *)typeEntry + 8));
        if (((unsigned int)(-stageValue | stageValue) >> 31) != 0)
            *(int *)((char *)info + 12) = stageProps->get(*(int *)((char *)typeEntry + 8));
        nameSlot = (void **)((char *)info + 16);
        *nameSlot = ((void *(*)(int))fn_80204AA4)(stageIndex);
    }
done:
    DIFFICULTY_INFO = (int *)info;

    #undef DIFFICULTY_READY
    #undef DIFFICULTY_INFO
    #undef DIFFICULTY_TAG
    #undef DIFFICULTY_VAL
    #undef INFO_SIZE
}
#pragma dont_inline reset
#pragma cplusplus reset

extern int *lbl_8055ED5C;
int fn_80204CF0(void) {
    return *lbl_8055ED5C;
}

extern double atof(const char *);
__declspec(section ".sdata") extern const char lbl_8055B4AC[];
extern const char lbl_8033BBF4[];
#pragma cplusplus on
extern "C" int fn_801345D8(void *, int, const char *, const char *);
extern "C" double atof(const char *);
extern "C" void fn_802E317C(const char *, ...);
extern "C" float fn_80204CFC(const char *arg0) {
    class Res {
    public:
        virtual void unused0();
        virtual int has(void *);
        virtual void unused2();
        virtual int get(void *);
    };
    char buf[0x64];
    int result = 0;
    int value;
    int r;
    int *temp;
    temp = lbl_8055ED5C;
    if (temp[4] != 0) {
        ((int (*)(void *, int, const char *, ...))fn_801345D8)(buf, 0x64, lbl_8055B4AC, temp[4], arg0);
        if (temp[3] != 0 && ((Res *)temp[3])->has(buf)) {
            r = ((Res *)temp[3])->get(buf);
        } else if (((Res *)temp[2])->has(buf)) {
            r = ((Res *)temp[2])->get(buf);
        } else {
            r = 0;
        }
        result = r;
    }
    if (result == 0) {
        if (temp[3] != 0 && ((Res *)temp[3])->has((void *)arg0)) {
            r = ((Res *)temp[3])->get((void *)arg0);
        } else if (((Res *)temp[2])->has((void *)arg0)) {
            r = ((Res *)temp[2])->get((void *)arg0);
        } else {
            r = 0;
        }
        result = r;
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    value = result;
    return (float)atof((const char *)value);
}
#pragma cplusplus reset
#pragma cplusplus on
class Res80204EA0 {
public:
    virtual void unused0();
    virtual int has(void *);
    virtual void unused2();
    virtual int get(void *);
};
extern "C" int fn_80204EA0(const char *arg0) {
    char buf[0x64];
    int *p;
    int result = 0;
    void **vt;
    int (*method)(void *, const char *);

    p = lbl_8055ED5C;
    if (p[4] != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
        if (p[3] != 0) {
            vt = *(void ***)p[3];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], buf) != 0) {
                vt = *(void ***)p[3];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[3], buf);
            }
        } else {
            vt = *(void ***)p[2];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[2], buf) != 0) {
                vt = *(void ***)p[2];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[2], buf);
            } else result = 0;
        }
    }
    if (result == 0) {
        if (p[3] != 0) {
            vt = *(void ***)p[3];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], arg0) != 0) {
                vt = *(void ***)p[3];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[3], arg0);
            } else result = 0;
        } else {
            vt = *(void ***)p[2];
            method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[2], arg0) != 0) {
                vt = *(void ***)p[2];
                method = (int (*)(void *, const char *))vt[5];
                result = method((void *)p[2], arg0);
            } else result = 0;
        }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    return result;
}
#pragma cplusplus reset

extern int fn_801345D8();
__declspec(section ".sdata") extern const char lbl_8055B4B4[];
__declspec(section ".sdata") extern const char lbl_8055B4B8[];
#pragma cplusplus on
extern "C" int fn_8020503C(const char *arg0) {
    class Res {
    public:
        virtual void unused0();
        virtual int has(void *);
        virtual void unused2();
        virtual int get(void *);
    };
    char buf[0x64];
    int *p;
    int result;
    int value;
    int answer;
    p = lbl_8055ED5C;
    result = 0;
    if (p[4] != 0) {
        ((int (*)(void *, int, const char *, ...))fn_801345D8)(buf, 0x64, lbl_8055B4AC, p[4], arg0);
        if (p[3] != 0) {
            if (((Res *)p[3])->has(buf)) {
                value = ((Res *)p[3])->get(buf);
                goto done1;
            }
        }
        if (((Res *)p[2])->has(buf)) {
            value = ((Res *)p[2])->get(buf);
        } else {
            value = 0;
        }
    done1:
        result = value;
    }
    if (result == 0) {
        if (p[3] != 0) {
            if (((Res *)p[3])->has((void *)arg0)) {
                value = ((Res *)p[3])->get((void *)arg0);
                goto done2;
            }
        }
        if (((Res *)p[2])->has((void *)arg0)) {
            value = ((Res *)p[2])->get((void *)arg0);
        } else {
            value = 0;
        }
    done2:
        result = value;
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    value = result;
    answer = 0;
    if (stricmp((const char *)value, lbl_8055B4B4) == 0 ||
        stricmp((const char *)value, lbl_8055B4B8) == 0) answer = 1;
    return answer;
}
#pragma cplusplus reset
/* Clear the active contest configuration and release its resources. */
void fn_80205208(void) {
    int *contestConfig = lbl_8055ED5C;
    lbl_8055ED58 = 0;
    if (contestConfig != 0) {
        contestConfig[4] = 0;
        contestConfig[2] = 0;
        contestConfig[3] = 0;
        fn_80131818(contestConfig[1]);
        contestConfig[1] = 0;
        fn_80128668(contestConfig);
    }
}

extern const char lbl_8033BBE4[];
extern void *fn_80131808(const char *);
extern int fn_80012854(void);
#pragma dont_inline on
int fn_80205268(const char *arg0, int arg1, int arg2) {
    volatile struct { int arg1; void *mgr; void *cur; void *val; void *sel; } s;
    char buf[0x64];
    int *entry;
    int result;
    void *o;
    s.arg1 = arg1;
    s.mgr = 0;
    s.cur = 0;
    s.val = 0;
    s.sel = 0;
    s.mgr = fn_80131808(lbl_8033BBE4);
    entry = (int *)fn_80204B18(arg1);
    s.cur = (*(void *(**)(void *, int))(*(void ***)s.mgr + 2))(s.mgr, entry[2]);
    if (arg2 >= 0 && arg2 < fn_80012854()) {
        void *stage = *(void **)((char *)((void *(*)(int))fn_8001285C)(arg2) + 0x20);
        int ok = (*(int (**)(void *, int))(*(void ***)stage + 23))(stage, entry[2]) != 0;
        if (ok) {
            s.val = (*(void *(**)(void *, int))(*(void ***)stage + 23))(stage, entry[2]);
        }
        s.sel = ((void *(*)(int))fn_80204AA4)(arg2);
    }
    result = 0;
    if (s.sel != 0) {
        ((int (*)(void *, int, const char *, ...))fn_801345D8)(buf, 0x64, lbl_8055B4AC, s.sel, arg0);
        o = s.val;
        if (o != 0 && (*(int (**)(void *, const char *))(*(void ***)o + 3))(o, buf) != 0) {
            o = s.val;
            result = (*(int (**)(void *, const char *))(*(void ***)o + 5))(o, buf);
        } else {
            o = s.cur;
            if ((*(int (**)(void *, const char *))(*(void ***)o + 3))(o, buf) != 0) {
                o = s.cur;
                result = (*(int (**)(void *, const char *))(*(void ***)o + 5))(o, buf);
            } else {
                result = 0;
            }
        }
    }
    if (result == 0) {
        o = s.val;
        if (o != 0 && (*(int (**)(void *, const char *))(*(void ***)o + 3))(o, arg0) != 0) {
            o = s.val;
            result = (*(int (**)(void *, const char *))(*(void ***)o + 5))(o, arg0);
        } else {
            o = s.cur;
            if ((*(int (**)(void *, const char *))(*(void ***)o + 3))(o, arg0) != 0) {
                o = s.cur;
                result = (*(int (**)(void *, const char *))(*(void ***)o + 5))(o, arg0);
            } else {
                result = 0;
            }
        }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    s.sel = 0;
    s.cur = 0;
    s.val = 0;
    fn_80131818((int)s.mgr);
    s.mgr = 0;
    return result;
}
#pragma push
#pragma dont_inline on
#pragma cplusplus on
extern "C" int fn_802054EC(const char *arg0, int arg1, int arg2) {
    class Manager { public: virtual void *get(int); };
    class Stage { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void *get(int); };
    class Resource { public: virtual void f0(); virtual int has(const char *); virtual void f2(); virtual const char *get(const char *); };
    volatile struct { int arg1; void *mgr; void *cur; void *val; void *sel; } s;
    char buf[0x64];
    const char *result;
    char *entry;
    const char *t;
    void *o;
    void *sel;
    void *mgr;
    s.arg1 = arg1;
    s.mgr = 0;
    s.cur = 0;
    s.val = 0;
    s.sel = 0;
    s.mgr = fn_80131808(lbl_8033BBE4);
    entry = (char *)fn_80204B18(arg1);
    s.cur = ((Manager *)s.mgr)->get(*(int *)(entry + 8));
    if (arg2 >= 0 && arg2 < fn_80012854()) {
        void *stage = *(void **)((char *)((void *(*)(int))fn_8001285C)(arg2) + 0x20);
        int ok = ((Stage *)stage)->get(*(int *)(entry + 8)) != 0;
        if (ok) {
            s.val = ((Stage *)stage)->get(*(int *)(entry + 8));
        }
        s.sel = ((void *(*)(int))fn_80204AA4)(arg2);
    }
    sel = s.sel;
    result = 0;
    if (sel != 0) {
        ((int (*)(void *, int, const char *, ...))fn_801345D8)(buf, 0x64, lbl_8055B4AC, sel, arg0);
        o = s.val;
        if (o != 0 && ((Resource *)o)->has(buf) != 0) {
            o = s.val;
            t = ((Resource *)o)->get(buf);
        } else {
            o = s.cur;
            if (((Resource *)o)->has(buf) != 0) {
                o = s.cur;
                t = ((Resource *)o)->get(buf);
            } else {
                t = 0;
            }
        }
        result = t;
    }
    if (result == 0) {
        o = s.val;
        if (o != 0 && ((Resource *)o)->has(arg0) != 0) {
            o = s.val;
            t = ((Resource *)o)->get(arg0);
        } else {
            o = s.cur;
            if (((Resource *)o)->has(arg0) != 0) {
                o = s.cur;
                t = ((Resource *)o)->get(arg0);
            } else {
                t = 0;
            }
        }
        result = t;
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    arg2 = 1;
    if (stricmp(result, lbl_8055B4B4) != 0 && stricmp((const char *)result, lbl_8055B4B8) != 0) arg2 = 0;
    mgr = s.mgr;
    s.sel = 0;
    s.cur = 0;
    s.val = 0;
    fn_80131818((int)mgr);
    s.mgr = 0;
    return arg2;
}
