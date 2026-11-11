// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
extern void fn_802E317C(const char *, const char *);
extern void *fn_8001285C(void);
extern void fn_80131818(int);
extern void fn_80128668(void *);
#pragma dont_inline fn_80204B2C
int fn_80204B2C(const char *);
int *fn_80204AA4(void) {
    int value = *(int *)((char *)fn_8001285C() + 8);
    switch (value) {
    case 0x180302: return &lbl_8055B468;
    case 0x180201: return &lbl_8055B470;
    case 0x180303: return &lbl_8055B478;
    default: return 0;
    }
}

void *fn_80204B18(int arg0) {
    return lbl_802F9D68 + arg0 * 0xC;
}

int fn_80204BB4(const char *arg0) {
    return fn_80204B2C(arg0);
}

#pragma dont_inline on
void fn_80204BB8(void) {
    void *r31;
    void *alloc;
    int r28;
    int r31b;
    volatile void *r31c;
    void *cur;
    void *stage;
    int v;
    lbl_8055ED58 = 1;
    lbl_8055ED5C = 0;
    r31 = fn_801E87A8();
    alloc = fn_801284F8(0x14, lbl_8033BBD8);
    if (alloc == 0) goto done;
    r28 = *(int *)((char *)r31 + 0);
    r31b = *(int *)((char *)r31 + 8);
    *(void **)alloc = (void *)r31b;
    *(int *)((char *)alloc + 4) = 0;
    *(int *)((char *)alloc + 8) = 0;
    *(int *)((char *)alloc + 0xC) = 0;
    *(int *)((char *)alloc + 0x10) = 0;
    *(void **)((char *)alloc + 4) = fn_80131808(lbl_8033BBE4);
    r31c = fn_80204B18(r31b);
    cur = (*(void *(**)(void *, int))(*(void ***)(*(void **)((char *)alloc + 4)) + 2))(*(void **)((char *)alloc + 4), *(int *)((char *)r31c + 8));
    *(void **)((char *)alloc + 8) = cur;
    if (r28 >= 0 && r28 < fn_80012854()) {
        stage = *(void **)((char *)((void *(*)(int))fn_8001285C)(r28) + 0x20);
        v = (*(int (**)(void *, int))(*(void ***)stage + 23))(stage, *(int *)((char *)r31c + 8));
        if (((unsigned int)(-v | v) >> 31) != 0) {
            *(int *)((char *)alloc + 0xC) = (*(int (**)(void *, int))(*(void ***)stage + 23))(stage, *(int *)((char *)r31c + 8));
        }
        *(void **)((char *)alloc + 0x10) = ((void *(*)(int))fn_80204AA4)(r28);
    }
done:
    lbl_8055ED5C = (int *)alloc;
}
#pragma dont_inline reset

extern int *lbl_8055ED5C;
int fn_80204CF0(void) {
    return *lbl_8055ED5C;
}

extern double atof(const char *);
__declspec(section ".sdata") extern const char lbl_8055B4AC[];
extern const char lbl_8033BBF4[];
float fn_80204CFC(const char *arg0) {
    char buf[0x64];
    int result = 0;
    int value;
    int r;
    void *temp;
    void *obj;
    void **vt;
    int (*method)(void *);
    int (*method2)(void *, void *);
    int (*method3)(void *, const char *);

    temp = lbl_8055ED5C;
    if (*(int *)((char *)temp + 0x10) != 0) {
        fn_801345D8(buf, 0x64, &lbl_8055B4AC, arg0);
        obj = *(void **)((char *)temp + 0xC);
        if (obj != 0 && (*(int (**)(void *))(*(void ***)obj + 3))(buf) != 0) {
            obj = *(void **)((char *)temp + 0xC);
            result = (*(int (**)(void *, void *))(*(void ***)obj + 5))(obj, buf);
        } else {
            obj = *(void **)((char *)temp + 8);
            if ((*(int (**)(void *))(*(void ***)obj + 3))(buf) != 0) {
                result = (*(int (**)(void *, void *))(*(void ***)obj + 5))(obj, buf);
            } else result = 0;
        }
    }
    if (result == 0) {
        obj = *(void **)((char *)temp + 0xC);
        if (obj != 0 && (*(int (**)(const char *))(*(void ***)obj + 3))(arg0) != 0) {
            result = (*(int (**)(void *, const char *))(*(void ***)obj + 5))(obj, arg0);
        } else {
            obj = *(void **)((char *)temp + 8);
            if ((*(int (**)(void *, const char *))(*(void ***)obj + 3))(obj, arg0) != 0) {
                result = (*(int (**)(void *, const char *))(*(void ***)obj + 5))(obj, arg0);
            } else result = 0;
        }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    value = result;
    return (float)atof((const char *)value);
}

int fn_80204EA0(const char *arg0) {
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

extern int fn_801345D8(void *, int, const char *, const char *);
__declspec(section ".sdata") extern const char lbl_8055B4B4[];
__declspec(section ".sdata") extern const char lbl_8055B4B8[];
int fn_8020503C(const char *arg0) {
    char buf[0x64];
    int *p;
    int result = 0;
    int value;
    void **vt;
    int (*method)(void *, const char *);
    p = lbl_8055ED5C;
    if (p[4] != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
        if (p[3] != 0) {
            vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], buf) != 0) { vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[3], buf); }
            else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], buf) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], buf); } else result = 0; }
        } else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], buf) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], buf); } else result = 0; }
    }
    if (result == 0) {
        if (p[3] != 0) {
            vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[3];
            if (method((void *)p[3], arg0) != 0) { vt = *(void ***)p[3]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[3], arg0); }
            else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], arg0) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], arg0); } else result = 0; }
        } else { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[3]; if (method((void *)p[2], arg0) != 0) { vt = *(void ***)p[2]; method = (int (*)(void *, const char *))vt[5]; result = method((void *)p[2], arg0); } else result = 0; }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    value = result;
    return stricmp((const char *)value, lbl_8055B4B4) == 0 || stricmp((const char *)value, lbl_8055B4B8) == 0;
}

void fn_80205208(void) {
    int *p = lbl_8055ED5C;
    lbl_8055ED58 = 0;
    if (p != 0) {
        p[4] = 0;
        p[2] = 0;
        p[3] = 0;
        fn_80131818(p[1]);
        p[1] = 0;
        fn_80128668(p);
    }
}

extern const char lbl_8033BBE4[];
extern void *fn_80131808(const char *);
extern int fn_80012854(void);
#pragma dont_inline on
int fn_80205268(const char *arg0, int arg1, int arg2) {
    volatile struct { int arg1; void *mgr; void *cur; void *val; void *sel; } s;
    char buf[0x64];
    char *entry;
    int result;
    void *o;
    s.arg1 = arg1;
    s.mgr = 0;
    s.cur = 0;
    s.val = 0;
    s.sel = 0;
    s.mgr = fn_80131808(lbl_8033BBE4);
    entry = (char *)fn_80204B18(arg1);
    o = s.mgr;
    s.cur = (*(void *(**)(void *, int))(*(void ***)o + 2))(o, *(int *)(entry + 8));
    if (arg2 >= 0 && arg2 < fn_80012854()) {
        void *stage = *(void **)((char *)((void *(*)(int))fn_8001285C)(arg2) + 0x20);
        int ok = (*(int (**)(void *, int))(*(void ***)stage + 23))(stage, *(int *)(entry + 8)) != 0;
        if (ok) {
            s.val = (*(void *(**)(void *, int))(*(void ***)stage + 23))(stage, *(int *)(entry + 8));
        }
        s.sel = ((void *(*)(int))fn_80204AA4)(arg2);
    }
    result = 0;
    if (s.sel != 0) {
        fn_801345D8(buf, 0x64, lbl_8055B4AC, arg0);
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
    char *entry;
    const char *result;
    void *o;
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
    result = 0;
    if (s.sel != 0) {
        ((int (*)(void *, int, const char *, ...))fn_801345D8)(buf, 0x64, lbl_8055B4AC, s.sel, arg0);
        o = s.val;
        if (o != 0 && ((Resource *)o)->has(buf) != 0) {
            o = s.val;
            result = ((Resource *)o)->get(buf);
        } else {
            o = s.cur;
            if (((Resource *)o)->has(buf) != 0) {
                o = s.cur;
                result = ((Resource *)o)->get(buf);
            } else {
                result = 0;
            }
        }
    }
    if (result == 0) {
        o = s.val;
        if (o != 0 && ((Resource *)o)->has(arg0) != 0) {
            o = s.val;
            result = ((Resource *)o)->get(arg0);
        } else {
            o = s.cur;
            if (((Resource *)o)->has(arg0) != 0) {
                o = s.cur;
                result = ((Resource *)o)->get(arg0);
            } else {
                result = 0;
            }
        }
    }
    if (result == 0) fn_802E317C(lbl_8033BBF4, arg0);
    { int answer = 1;
    if (stricmp(result, lbl_8055B4B4) != 0 && stricmp((const char *)result, lbl_8055B4B8) != 0) answer = 0;
    s.sel = 0;
    s.cur = 0;
    s.val = 0;
    fn_80131818((int)s.mgr);
    s.mgr = 0;
    return answer; }
}
#pragma pop
