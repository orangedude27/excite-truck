// roadsnd — road surface sound (roadsnd.val, "roadsnd: can't find %s").
// Recovered TU window 0x8020CA30..0x8020CF60+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020CF60 (+ .ctors slot 0x802ED39C) remains in
// auto/text_8020CF60_.c pending a promotion pass.
extern char lbl_8033C650[];
typedef float f32;
extern f32 lbl_80563304;
extern f32 lbl_80563308;
extern f32 lbl_8056330C;
extern void* fn_801D04A8(int);
extern char lbl_8033C660[];
extern char lbl_8033C66C[];
extern char lbl_8033C678[];
extern const char lbl_8055B5E0[4];
extern const char lbl_8055B5E8[4];
extern const char lbl_8055B5F0[4];
extern const char lbl_8055B5F8[4];
extern const char lbl_8055B600[4];
extern const char lbl_8055B608[4];
extern const char lbl_8055B610[4];
extern const char lbl_8055B618[4];
extern const char lbl_8055B620[4];
extern const char lbl_8055B628[4];
extern f32 lbl_80563300;
extern void* fn_801284F8(int, const char*);
extern void* fn_80131808(const char*);
extern void fn_80131818(void*);
extern void* fn_802077A4(int, int, void*, void*);
extern int fn_802E30C8(const char*, ...);
extern int strcmp(const char*, const char*);
#pragma cplusplus on
struct Item_8020CA3C {
    virtual const char* getName();
    virtual void slot1();
    virtual void slot2();
    virtual int getA(const char*);
    virtual void slot4();
    virtual int getB(const char*);
    virtual void slot6();
    virtual f32 getF(const char*);
};
struct Dir_8020CA3C {
    virtual void slot0();
    virtual Item_8020CA3C* getAt(int);
};
#pragma cplusplus reset

void fn_8020CA30(void) {

}

void fn_8020CA34(void) {

}

void fn_8020CA38(void) {

}

#pragma cplusplus on
extern "C" void* fn_8020CA3C(void* arg0) {
    char* p;
    char* obj;
    int idx;
    Item_8020CA3C* item;
    Dir_8020CA3C* dir;
    char* ctx;
    f32 scale;
    int name;
    void* r;
    int n;

    obj = (char*)fn_801284F8(0x12C, lbl_8055B5E0);
    if (obj != 0) {
        *(char**)obj = lbl_8033C650;
        *(void**)(obj + 4) = arg0;
        *(int*)(obj + 8) = 0;
        dir = (Dir_8020CA3C*)fn_80131808(lbl_8033C660);
        scale = lbl_80563300;
        idx = 0;
        while ((item = dir->getAt(idx)) != 0) {
            if (strcmp(item->getName(), lbl_8055B5E8) == 0) {
                n = *(int*)(obj + 8);
                ctx = *(char**)(obj + 4);
                *(int*)(obj + 8) = n + 1;
                p = obj + n * 0x24;
                name = item->getA(lbl_8055B628);
                r = fn_802077A4(name, 4, ctx + 0x118, ctx + 0x60);
                *(void**)(p + 0xC) = r;
                if (r == 0 && *(int*)(ctx + 0x1EC) == 0) {
                    fn_802E30C8(lbl_8033C678, name);
                }
                *(int*)(p + 0x10) = item->getB(lbl_8033C66C);
                *(f32*)(p + 0x14) = scale * item->getF(lbl_8055B620);
                *(f32*)(p + 0x18) = scale * item->getF(lbl_8055B618);
                *(f32*)(p + 0x1C) = scale * item->getF(lbl_8055B610);
                *(f32*)(p + 0x20) = item->getF(lbl_8055B608);
                *(f32*)(p + 0x24) = item->getF(lbl_8055B600);
                *(f32*)(p + 0x28) = item->getF(lbl_8055B5F8);
                *(f32*)(p + 0x2C) = item->getF(lbl_8055B5F0);
            }
            idx++;
        }
        fn_80131818(dir);
    }
    return obj;
}
#pragma cplusplus reset

#pragma cplusplus on
struct CC78_Item { virtual void s0(int); };
static inline void CC78_call(void *p, int v) { ((CC78_Item *)p)->s0(v); }
#pragma cplusplus reset
#pragma scheduling invalid_target
/* Destroys a road-sound container: installs its vtable, calls slot 0(v=1) on each active 0x24-byte entry's object, and optionally frees the container. */
void *fn_8020CC78(void *obj, int freeFlag) {
    void *cur;
    int i;
    if (obj != 0) {
        *(void **)obj = lbl_8033C650;
        cur = obj;
        i = 0;
        while (i < *(int *)((char *)obj + 8)) {
            void *item = *(void **)((char *)cur + 0xC);
            if (item == 0) {
                goto next;
            }
            if (item == 0) {
                goto next;
            }
            CC78_call(item, 1);
        next:
            cur = (char *)cur + 0x24;
            i++;
        }
        if (freeFlag > 0) {
            fn_80128668(obj);
        }
    }
    return obj;
}

void fn_8020CD28(char *arg0) {
    char *ctx = *(char **)(arg0 + 4);
    char *e;
    int i;
    int max = 0;
    int v;
    f32 hi, lo, cur, scale;

    v = *(int *)(ctx + 0x2410);
    if (v > max) max = v;
    v = *(int *)(ctx + 0x2484);
    if (v > max) max = v;
    v = *(int *)(ctx + 0x24F8);
    if (v > max) max = v;
    v = *(int *)(ctx + 0x256C);
    if (v > max) max = v;

    e = arg0;
    hi = lbl_80563308;
    lo = lbl_8056330C;
    cur = *(f32 *)(ctx + 0x25D4);
    scale = lbl_80563304 * (f32)*(int *)(ctx + 0x2620);
    for (i = 0; i < *(int *)(arg0 + 8); i++, e += 0x24) {
        if (*(int *)((char *)fn_801D04A8(max) + 0x10) == *(int *)(e + 0x10)) {
            char *obj = *(char **)(e + 0xC);
            if (obj != 0) {
                f32 a, b, t, t2;
                f32 s = *(f32 *)(e + 0x18);
                if (cur < s) {
                    f32 base = *(f32 *)(e + 0x14);
                    f32 d = *(f32 *)(e + 0x20);
                    t = (cur - base) / (s - base);
                    if (hi < t) t = hi;
                    if (t > lo) { } else t = lo;
                    a = lo + t * (d - lo);
                } else {
                    f32 base2 = *(f32 *)(e + 0x18);
                    f32 d2 = *(f32 *)(e + 0x20);
                    t = (cur - base2) / (*(f32 *)(e + 0x1C) - base2);
                    if (hi < t) t = hi;
                    if (t > lo) { } else t = lo;
                    a = d2 + t * (*(f32 *)(e + 0x24) - d2);
                }
                {
                    f32 base3 = *(f32 *)(e + 0x14);
                    f32 d3 = *(f32 *)(e + 0x28);
                    t2 = (cur - base3) / (*(f32 *)(e + 0x1C) - base3);
                    if (hi < t2) t2 = hi;
                    if (t2 > lo) { } else t2 = lo;
                    b = d3 + t2 * (*(f32 *)(e + 0x2C) - d3);
                }
                *(char *)(obj + 0x4A) = 0;
                *(char *)(obj + 0x4B) = 1;
                *(char *)(obj + 0x49) = 1;
                {
                    f32 x = scale * a;
                    obj = *(char **)(e + 0xC);
                    if (x != *(f32 *)(obj + 8)) {
                        *(char *)(obj + 0x4D) = 1;
                        *(f32 *)(obj + 8) = x;
                    }
                    obj = *(char **)(e + 0xC);
                    if (b != *(f32 *)(obj + 4)) {
                        *(char *)(obj + 0x4E) = 1;
                        *(f32 *)(obj + 4) = b;
                    }
                }
            }
        } else {
            char *obj = *(char **)(e + 0xC);
            if (obj != 0) {
                *(char *)(obj + 0x4A) = 1;
                *(char *)(obj + 0x4C) = 0;
            }
        }
    }
}



