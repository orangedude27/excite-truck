// Code of main that had no source file yet: decomp.wtf gave it this one.
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern void fn_8028C8BC(void);

struct Vec3i { s32 a, b, c; };
extern f32 fn_801E7E24(void);
extern s32 fn_80287B5C(s32);
extern f32 fn_80287BC8(f32, f32);
extern void PSVECNormalize(f32 *, f32 *);
extern f64 fabs(f64);
extern f32 lbl_80558DC4[];
extern f32 lbl_80564328, lbl_8056432C, lbl_80564334, lbl_80564338, lbl_8056433C;
extern f32 lbl_80564340, lbl_80564344, lbl_80564348, lbl_80564350, lbl_80564354;
extern f32 lbl_80564358, lbl_8056435C, lbl_80564360;
extern f32 lbl_80564364, lbl_805643BC, lbl_805643C0, lbl_805643C4;
extern f32 fn_80144514(f32, f32, f32, f32, f32, f32);
extern s32 fn_802C8DBC(s32);
extern void fn_802C8E00();
extern void fn_802C8E48(void);
#define FLD(p, off) (*(f32 *)((u8 *)(p) + (off)))

struct V3 { f32 x, y, z; };
static inline void XfmV3(f32 *m, struct V3 *src, struct V3 *dst) {
    if (src == dst) {
        f32 x = src->x, y = src->y, z = src->z;
        dst->x = z * m[6] + (x * m[0] + y * m[3]);
        dst->y = z * m[7] + (x * m[1] + y * m[4]);
        dst->z = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        dst->x = src->z * m[6] + (src->x * m[0] + src->y * m[3]);
        dst->y = src->z * m[7] + (src->x * m[1] + src->y * m[4]);
        dst->z = src->z * m[8] + (src->x * m[2] + src->y * m[5]);
    }
}
static inline void XfmVec(f32 *m, f32 *src, f32 *dst) {
    if (src == dst) {
        f32 x = src[0], y = src[1], z = src[2];
        dst[0] = z * m[6] + (x * m[0] + y * m[3]);
        dst[1] = z * m[7] + (x * m[1] + y * m[4]);
        dst[2] = z * m[8] + (x * m[2] + y * m[5]);
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}

extern s32 fn_8012850C(s32, void *, s32);
extern s32 fn_8002F37C(void *, s32, s32, s32);
extern s32 fn_802CAC28(void *, s32);
extern f64 fn_8002F208(f64);
extern char lbl_80348C34[], lbl_80348C40[];
extern f64 lbl_805643C8;

extern f32 fn_801E7E18(void);
extern s32 lbl_804B32B8[];
extern void fn_8028BC88(s32);
extern f32 lbl_805643A0;
extern f32 lbl_80564394;
extern s32 fn_80287B94(s32, s32, f32, f32, f32);
extern s32 fn_8028CD80(s32, s32, void *, f32 *, f32);

extern s32 lbl_8055F6F0;
extern s32 lbl_8055F6F4;
extern s32 lbl_8055F6F8;
extern void *lbl_8055F6FC;
extern struct Obj8028 { void **vtable; } *lbl_804B3238[];
extern void fn_8028BD60(s32);
extern void fn_8028CA70(s32);
extern void fn_8028AB14(void);
extern void fn_8028BD5C(s32);
extern void fn_8028BFEC(s32);
extern void fn_8028C938(s32);

extern void fn_80288A70(void *, f32 *);
extern void fn_8028AA6C(void *, s32, f32);
extern s32 lbl_8055F700;
extern f32 lbl_8056434C;

extern s32 fn_80128668(void);
#pragma cplusplus on
#pragma cplusplus off
#pragma push
#pragma optimize_for_size on
#pragma scheduling invalid_target
void fn_8028A664(void) {
    extern char lbl_80348B98[];
    extern char lbl_8055C8A0;
    extern s32 lbl_804B32B8[];
    extern s32 lbl_8055F6F0, lbl_8055F6F4, lbl_8055F6F8, lbl_8055F700;
    extern f32 lbl_80564328, lbl_8056432C;
    extern void *fn_801284F8(s32, void *);
    extern void *fn_8028BB68(void *, s32, f32);
    extern void *fn_8028C824(void *, s32);
    extern void *fn_802929D8(s32, void *, s32, s32);
    extern void *fn_802974CC(void *);
    extern void fn_8028ABE8(void *);
    extern void fn_8028B3CC(void);
    extern void fn_801EEFDC(s32, s32);
    extern s32 fn_8028B93C(f32 *);
    extern s32 fn_8028B500(void *);
    extern s32 fn_8028BA44(void *);
    extern s32 fn_8028BA9C(void *);
    extern s32 fn_8028BB14(s32);
    struct Data { char first; };
    register char *data asm("r31") = lbl_80348B98;
    volatile struct Data *header = (volatile struct Data *)data;
    void *p;

    p = fn_801284F8(0xDC, (void *)&header->first);
    if (p != 0) p = fn_8028BB68(p, 0x80, lbl_80564328);
    lbl_8055F6F0 = (s32)p;
    p = fn_801284F8(0xDC, data + 0x10);
    if (p != 0) p = fn_8028BB68(p, 0x60, lbl_8056432C);
    lbl_8055F6F4 = (s32)p;
    p = fn_801284F8(0x14, data + 0x1C);
    if (p != 0) p = fn_8028C824(p, 0x60);
    lbl_8055F6F8 = (s32)p;
    lbl_8055F6FC = fn_802929D8(1, &lbl_8055C8A0, 0, 0);
    p = fn_802974CC(data + 0x2C);
    *(volatile s32 *)&lbl_8055F700 = (s32)p;
    *(volatile s32 *)&lbl_804B32B8[0x50] = 0;
    fn_8028ABE8(p);
    fn_8028B3CC();
    fn_801EEFDC((s32)fn_8028B93C, 0);
    fn_801EEFDC((s32)fn_8028B500, 1);
    fn_801EEFDC((s32)fn_8028BA44, 2);
    fn_801EEFDC((s32)fn_8028BA9C, 7);
    fn_801EEFDC((s32)fn_8028BB14, 8);
}
#pragma pop
#pragma cplusplus on

extern "C" void fn_8028A784(void) {
    class Obj {
    public:
        virtual void v0(int);
    };
    extern void fn_801EF024(void *);
    extern s32 fn_8028BB14(s32);
    extern s32 fn_8028BA9C(void *);
    extern s32 fn_8028BA44(void *);
    extern s32 fn_8028B500(void *);
extern s32 fn_8028B93C(f32 *);
    extern void fn_8028B4CC(void), fn_8028AD78(void);
    extern void fn_802976DC(s32);
    extern void *fn_8028C8C0(void *, s32);
    extern s32 fn_8028BC1C(s32, s32);
    void *p;
    fn_801EF024((void *)fn_8028BB14);
    fn_801EF024((void *)fn_8028BA9C);
    fn_801EF024((void *)fn_8028BA44);
    fn_801EF024((void *)fn_8028B500);
    fn_801EF024((void *)fn_8028B93C);
    fn_8028B4CC();
    fn_8028AD78();
    if (lbl_8055F700) fn_802976DC(lbl_8055F700);
    lbl_8055F700 = 0;
    p = lbl_8055F6FC;
    if (p) ((Obj *)p)->v0(1);
    lbl_8055F6FC = 0;
    fn_8028C8C0((void *)lbl_8055F6F8, 1);
    lbl_8055F6F8 = 0;
    fn_8028BC1C(lbl_8055F6F0, 1);
    lbl_8055F6F0 = 0;
    fn_8028BC1C(lbl_8055F6F4, 1);
    lbl_8055F6F4 = 0;
}
#pragma cplusplus off
s32 fn_8028A85C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern void fn_8028C92C(void *);
void fn_8028A89C(void) {
    void *obj;
    s32 i;
    void **p;
    fn_8028BC88(lbl_8055F6F0);
    fn_8028BC88(lbl_8055F6F4);
    fn_8028C92C((void *)lbl_8055F6F8);
    ((void (*)(void *))(*(void ***)lbl_8055F6FC)[3])(lbl_8055F6FC);
    p = (void **)lbl_804B3238;
    i = 0;
    do {
        obj = *p;
        if (obj != 0)
            ((void (*)(void *))(*(void ***)obj)[3])(obj);
        i++;
        if (i >= 8) break;
        p = (void **)((u8 *)p + 0x10);
    } while (1);
}

void fn_8028A92C(void) {
    s32 i;
    void **p;
    fn_8028BD5C(lbl_8055F6F0);
    fn_8028BD5C(lbl_8055F6F4);
    fn_8028C938(lbl_8055F6F8);
    ((void (*)(void *))(*(void ***)lbl_8055F6FC)[4])(lbl_8055F6FC);
    p = (void **)lbl_804B3238;
    i = 0;
    do {
        void *obj = *p;
        if (obj) ((void (*)(void *))(*(void ***)obj)[4])(obj);
        i++;
        if (i >= 8) break;
        p = (void **)((u8 *)p + 0x10);
    } while (1);
}

void fn_8028A9BC(void) {
    fn_8028BD60(lbl_8055F6F0);
    fn_8028BD60(lbl_8055F6F4);
    fn_8028CA70(lbl_8055F6F8);
    fn_8028AB14();
}

#pragma cplusplus on
extern "C" void fn_8028A9F4(void) {
    class Dummy { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); };
    ((Dummy *)lbl_8055F6FC)->v3();
    void **p = (void **)lbl_804B3238;
    s32 i = 0;
    do {
        void *obj = *p;
        if (obj) ((Dummy *)obj)->v3();
        i++;
        p = (void **)((u8 *)p + 0x10);
    } while (i < 8);
}
#pragma cplusplus off

#pragma push
#pragma processor 750
extern s32 fn_8029771C(void *, void *, f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028AB14(void) {
    struct Entry { f32 time; struct { s32 x, y, z; } pos; void *obj; };
    f32 now = fn_801E7E18();
    struct Entry *entry = (struct Entry *)lbl_804B32B8;
    s32 i = 0;
    while (i < lbl_804B32B8[0x50]) {
        if (!fn_8029771C(entry->obj, &entry->pos, now - entry->time)) {
            struct Entry *last = (struct Entry *)lbl_804B32B8 + --lbl_804B32B8[0x50];
            entry->time = last->time;
            entry->pos = last->pos;
            entry->obj = last->obj;
        } else {
            entry++;
            i++;
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_8028ABE8(void *arg0) {
    class Obj {
    public:
        virtual void dummy0();
        virtual void dummy1();
        virtual void dummy2();
        virtual void dummy3();
        virtual s32 v4(void *, void *);
        virtual void dummy5();
        virtual s32 v6(void *, s32);
        virtual void dummy7();
        virtual f32 v8(void *, f32);
        virtual void dummy9();
        virtual void dummy10();
        virtual void dummy11();
        virtual void dummy12();
        virtual void dummy13();
        virtual void dummy14();
        virtual void dummy15();
        virtual void dummy16();
        virtual void dummy17();
        virtual void dummy18();
        virtual void dummy19();
        virtual void dummy20();
        virtual Obj *v21(void *);
    };
    extern char lbl_80348B98[];
    extern char lbl_8055C8A8, lbl_8055C8B0, lbl_8055C8B8;
    extern f32 lbl_80564330;
    extern void fn_801345D8(void *, s32, void *, ...);
    extern void *fn_802AE414(void *);
    extern void *fn_802929D8(s32, void *, s32, s32);
    extern void fn_80287B38(void (*)(void));
    extern void fn_8028ADF4(void *, s32);
    u8 sp8[0x20];
    char *data = lbl_80348B98;
    s32 *entry = (s32 *)lbl_804B3238;
    s32 validCount = 0;
    s32 i = 0;
    do {
        void *object;
        fn_801345D8(sp8, 0x20, data + 0x38, i);
        object = fn_802AE414(sp8);
        if (object != 0) {
            object = ((Obj *)object)->v21(&lbl_8055C8A8);
        }
        if (object != 0) {
            entry[0] = (s32)fn_802929D8(2, data + 0x44, validCount,
                                        ((Obj *)object)->v4(&lbl_8055C8B0, &lbl_8055C8B8));
            *(f32 *)&entry[1] = ((Obj *)object)->v8(data + 0x50, lbl_80564330);
            {
                s32 value = ((Obj *)object)->v6(data + 0x5C, 0x14);
                value = value & ((-value & ~value) >> 31);
                entry[2] = value < 0x64 ? value : 0x64;
            }
            {
                s32 value = ((Obj *)object)->v6(data + 0x68, 2);
                value = value & ((-value & ~value) >> 31);
                entry[3] = value < 0x64 ? value : 0x64;
            }
            validCount++;
        } else {
            entry[0] = 0;
        }
        i++;
        entry += 4;
    } while (i < 8);
    fn_80287B38((void (*)(void))fn_8028ADF4);
}
#pragma cplusplus off
#pragma pop

#pragma scheduling on
#pragma pop

void fn_8028AD78(void) {
    register u8 *slot;
    register s32 i;
    register s32 zero = 0;
    slot = (u8 *)lbl_804B3238;
    i = 0;
    goto loop;
loop:
    {
        void *p = *(void **)slot;
        if (p == 0) goto next;
        if (p == 0) goto clear;
        ((void (*)(void *, s32))(*(void ***)p)[2])(p, 1);
clear:
        *(void **)slot = (void *)zero;
next:
        i++;
        slot += 0x10;
        if (i < 8) goto loop;
    }
}

#pragma push
#pragma use_lmw_stmw off
void fn_8028ADF4(void *arg0, s32 arg1) {
    u8 *e;
    s32 i;
    u8 *m;
    s32 j;
    s32 n = arg1;
    u8 *ent = (u8 *)arg0;
    struct V3 *pv;
    u8 *t;
    f32 a1[3], b1[3], c1[3];
    struct V3 a2;
    f32 b2[3];
    f32 k31, k30, k29, k28, k27, k26, k25, k24, k23;
    pv = &a2;
    if ((f32)__fabs(fn_801E7E24()) <= lbl_80558DC4[0]) return;
    k23 = lbl_80564334;
    k24 = lbl_80564344;
    k25 = lbl_80564348;
    k26 = lbl_8056434C;
    k27 = lbl_80564350;
    k29 = lbl_80564338;
    k30 = lbl_80564340;
    k31 = lbl_80564360;
    k28 = lbl_80564354;
    for (i = 0; i < n; i++, ent += 0x10) {
        m = *(u8 **)ent;
        if (ent[0xC] != 0 && !(FLD(ent, 8) > k23)) {
            e = m + 0x70;
            for (j = 0; j < 4; j++, e += 0x3C) {
                s32 type;
                s32 roll;
                f32 f4;
                f32 f22;
                if (e[0x30] == 0) continue;
                type = *(s32 *)(e + 0x38);
                if (type < 0 || type >= 8) continue;
                t = (u8 *)lbl_804B3238 + type * 16;
                if (*(s32 *)t == 0) continue;
                if (*(s32 *)(e + 0x2C) & 8) continue;
                roll = fn_80287B5C(0x64);
                if (FLD(e, 0x28) > FLD(t, 4) && roll < *(s32 *)(t + 8)) {
                    f32 r;
                    *(struct Vec3i *)a1 = *(struct Vec3i *)(e + 0xC);
                    r = fn_80287BC8(lbl_80564338, lbl_8056432C);
                    b1[0] = FLD(m, 0xC) * r;
                    b1[1] = FLD(m, 0x10) * r;
                    b1[2] = FLD(m, 0x14) * r;
                    r = fn_80287BC8(lbl_8056433C, lbl_80564340);
                    b1[0] += FLD(m, 0x18) * r;
                    b1[1] += FLD(m, 0x1C) * r;
                    b1[2] += FLD(m, 0x20) * r;
                    PSVECNormalize(b1, b1);
                    r = FLD(e, 0x34);
                    b1[0] *= r;
                    b1[1] *= r;
                    b1[2] *= r;
                    a1[0] += b1[0];
                    a1[1] += b1[1];
                    a1[2] += b1[2];
                    c1[0] = FLD(m, 0x34) * k24;
                    c1[1] = FLD(m, 0x38) * k24;
                    c1[1] += k25;
                    c1[2] = FLD(m, 0x3C) * k24;
                    f4 = (FLD(e, 0) > k26) ? lbl_8056432C : lbl_80564340;
                    c1[0] += FLD(m, 0) * f4;
                    c1[1] += FLD(m, 4) * f4;
                    c1[2] += FLD(m, 8) * f4;
                    f22 = k27 * FLD(e, 0x24);
                    c1[0] += fn_80287BC8(-f22, f22);
                    c1[2] += fn_80287BC8(-f22, f22);
                    ((void (*)(void *, f32 *, f32 *, s16, s32))(*(void ***)*(void **)t)[6])(
                        *(void **)t, a1, c1, *(s16 *)(m + 0x30), i);
                } else if (FLD(e, 0x24) > k28 && roll < *(s32 *)(t + 0xC)) {
                    f32 r;
                    a2.x = FLD(e, 0);
                    a2.y = FLD(e, 4);
                    a2.z = FLD(e, 8) - k29;
                    XfmV3((f32 *)m, pv, (struct V3 *)&a2.x);
                    a2.x += FLD(m, 0x24);
                    a2.y += FLD(m, 0x28);
                    a2.z += FLD(m, 0x2C);
                    b2[0] = FLD(m, 0x18) * k30;
                    b2[1] = FLD(m, 0x1C) * k30;
                    b2[2] = FLD(m, 0x20) * k30;
                    r = fn_80287BC8(lbl_80564328, lbl_8056432C);
                    b2[0] += FLD(m, 0xC) * r;
                    b2[1] += FLD(m, 0x10) * r;
                    b2[2] += FLD(m, 0x14) * r;
                    r = FLD(e, 0x24) * fn_80287BC8(lbl_80564358, lbl_8056435C);
                    b2[0] *= r;
                    b2[1] *= r;
                    b2[2] *= r;
                    b2[0] += FLD(m, 0x34) * k31;
                    b2[1] += FLD(m, 0x38) * k31;
                    b2[2] += FLD(m, 0x3C) * k31;
                    f4 = (FLD(e, 0) > k26) ? lbl_8056432C : lbl_80564340;
                    b2[0] += FLD(m, 0) * f4;
                    b2[1] += FLD(m, 4) * f4;
                    b2[2] += FLD(m, 8) * f4;
                    f22 = k27 * FLD(e, 0x24);
                    b2[0] += fn_80287BC8(-f22, f22);
                    b2[2] += fn_80287BC8(-f22, f22);
                    ((void (*)(void *, f32 *, f32 *, s16, s32))(*(void ***)*(void **)t)[6])(
                        *(void **)t, (f32 *)&a2, b2, *(s16 *)(m + 0x30), i);
                }
            }
        }
    }
}
#pragma pop

#pragma push
#pragma processor gekko
void fn_8028B3CC(void) {
    extern s32 lbl_8055D430, lbl_8055F704;
    extern char lbl_80348C10[], lbl_80348C1C[];
    extern f32 lbl_8056432C, lbl_80564328, lbl_80564330, lbl_80564364, lbl_80564368, lbl_8056436C, lbl_80564370, lbl_8056434C;
    extern void fn_8028E61C(void *);
    extern s32 fn_8028E2F8(void *, void *, void *);
    union { s32 i[36]; f32 f[36]; } cfg;
    s32 enabled = 0;
    char *name = lbl_80348C10;
    if ((lbl_8055D430 & 1) && (lbl_8055D430 & 8)) enabled = 1;
    if (enabled) {
        fn_8028E61C(&cfg);
        cfg.i[1] = 0x80;
        cfg.f[2] = lbl_80564328;
        cfg.f[3] = lbl_8056432C;
        cfg.i[0] = 0;
        cfg.f[4] = lbl_80564364;
        cfg.f[5] = lbl_80564364;
        cfg.f[6] = lbl_80564364;
        cfg.f[7] = lbl_80564368;
        cfg.f[8] = lbl_80564368;
        cfg.f[9] = lbl_80564368;
        cfg.f[12] = lbl_80564328;
        cfg.i[17] = 5;
        cfg.f[20] = lbl_80564330;
        cfg.f[21] = lbl_8056432C;
        cfg.f[22] = lbl_8056436C;
        cfg.f[23] = lbl_80564370;
        cfg.f[28] = lbl_8056434C;
        cfg.f[26] = lbl_8056434C;
        cfg.f[24] = lbl_8056434C;
        cfg.f[27] = lbl_8056432C;
        cfg.f[25] = lbl_8056432C;
        cfg.f[29] = lbl_8056434C;
        lbl_8055F704 = fn_8028E2F8(&cfg, lbl_80348C1C, name);
    } else lbl_8055F704 = 0;
}
#pragma pop
extern s32 lbl_8055F704;
extern void fn_8028E398();
void fn_8028B4CC(void) {
    if (lbl_8055F704 != 0) {
        fn_8028E398(lbl_8055F704);
        lbl_8055F704 = 0;
    }
}

#pragma cplusplus on
extern "C" f32 lbl_8056432C, lbl_80564330, lbl_80564348, lbl_8056434C, lbl_80564364, lbl_8056436C, lbl_80564370, lbl_80564374, lbl_80564378, lbl_8056437C, lbl_80564380, lbl_80564384, lbl_80564388, lbl_8056438C, lbl_80564390, lbl_80564394, lbl_80564398;
extern "C" s32 lbl_8055F6F0, lbl_8055F6F4;
extern "C" void *lbl_8055F6FC;
extern "C" f32 PSVECMag(f32 *);
extern "C" f32 PSVECDotProduct(f32 *, f32 *);
extern "C" void *fn_80287B24(s32);
extern "C" f32 fn_80287BC8(f32, f32);
extern "C" void fn_8028BED4(void *, s32, void *, void *, f32);
extern void *fn_80287B24(s32);
extern f32 lbl_8056432C, lbl_80564330, lbl_80564348, lbl_8056434C, lbl_80564364, lbl_8056436C, lbl_80564370, lbl_80564374, lbl_80564378, lbl_8056437C, lbl_80564380, lbl_80564384, lbl_80564388, lbl_8056438C, lbl_80564390, lbl_80564394, lbl_80564398;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_8028B500(void *arg0) {
    class Emitter {
    public:
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual void emit(void *, f32 *, s32, s32);
    };
    register f32 *a = (f32 *)arg0;
    s32 kind;
    f32 magnitude = PSVECMag(a + 6);
    f32 raw = lbl_80564374 * magnitude;
    register s32 count;
    s32 clipped;
    s16 param;
        f32 up, amount, spread, limit, dot, factor, scale, zero, x, y, z, p, q, r;
    f32 v[3], dir[3], w[3];
    Emitter *emitter;
    clipped = (s32)raw;
    if (clipped < 0) clipped = 0;
    count = clipped < 0x60 ? clipped : 0x60;
    param = *(s16 *)((u8 *)fn_80287B24(*(s32 *)((u8 *)arg0 + 0x30)) + 0x30);
    if (count > 0) {
        s32 i, n;
        amount = lbl_80564378 * magnitude;
        up = lbl_8056437C;
        up = up < amount ? up : amount;
        up = up > lbl_80564348 ? up : lbl_80564348;
        spread = lbl_80564364;
        if (amount < spread) spread = amount;
        kind = *(s32 *)((u8 *)arg0 + 0x34);
        limit = lbl_8056434C;
        if (kind == 0x6e || kind < 8) limit = lbl_80564380;
        zero = lbl_8056434C;
        for (i = 0; i < count; i++) {
            scale = fn_80287BC8(lbl_80564384, lbl_8056432C);
            x = a[0] * scale; y = a[1] * scale; z = a[2] * scale;
            v[0] = x; v[1] = y; v[2] = z;
            v[0] += fn_80287BC8(-spread, spread);
            v[1] += up + fn_80287BC8(lbl_80564388, lbl_80564330);
            v[2] += fn_80287BC8(-spread, spread);
            dot = PSVECDotProduct(a + 9, v);
            factor = -dot + fn_80287BC8(lbl_8056436C, lbl_80564348);
            if (limit < factor) factor = limit;
            factor = factor > zero ? factor : zero;
            p = a[9] * factor; x = v[0]; q = a[10] * factor; r = a[11] * factor; y = v[1]; z = v[2];
            x += p; y += q; z += r;
            v[0] = x; v[1] = y; v[2] = z;
            ((Emitter *)lbl_8055F6FC)->emit(a + 3, v, param, *(s32 *)((u8 *)arg0 + 0x30));
        }
        n = (s32)(lbl_80564370 * (f32)count);
        amount = amount < lbl_8056438C ? amount : lbl_8056438C;
        x = a[0] * lbl_80564390;
        y = a[1] * lbl_80564390;
        z = a[2] * lbl_80564390;
        dir[0] = x;
        dir[2] = z;
        dir[1] = y + lbl_80564390 * amount;
        fn_8028BED4((void *)lbl_8055F6F0, n, a + 3, dir, amount);
        fn_8028BED4((void *)lbl_8055F6F4, n, a + 3, dir, amount);
    }
    kind = *(s32 *)((u8 *)arg0 + 0x34);
    if (kind >= 0 && kind < 8) {
        emitter = *(Emitter **)((u8 *)lbl_804B3238 + kind * 0x10);
        if (emitter) {
            s32 i, n;
            f32 zero2, spread2;
            spread2 = lbl_80564378 * magnitude;
            n = count / 3;
            spread2 = spread2 < lbl_80564394 ? spread2 : lbl_80564394;
            zero2 = lbl_8056434C;
            for (i = 0; i < n; i++) {
                scale = fn_80287BC8(lbl_80564384, lbl_8056432C);
                x = a[0] * scale; y = a[1] * scale; z = a[2] * scale;
                w[0] = x; w[1] = y; w[2] = z;
                w[0] += fn_80287BC8(-spread2, spread2);
                w[1] += fn_80287BC8(lbl_80564388, lbl_80564330);
                w[2] += fn_80287BC8(-spread2, spread2);
                factor = -PSVECDotProduct(a + 9, w);
                if (zero2 > factor) factor = zero2;
                p = a[9] * factor; x = w[0]; q = a[10] * factor; r = a[11] * factor; y = w[1]; z = w[2];
                x += p; y += q; z += r;
                w[0] = x; w[1] = y; w[2] = z;
                emitter->emit(a + 3, w, param, *(s32 *)((u8 *)arg0 + 0x30));
            }
        }
    }
    return 0x38;
}
#pragma pop

extern f32 PSVECMag(f32 *);
extern f32 fn_80287BC8(f32, f32);
extern f32 lbl_80564328, lbl_805643A4, lbl_805643A8;
extern void fn_8028BED4(void *, s32, void *, void *, f32);
extern s32 lbl_8055F6F0, lbl_8055F6F4;
#pragma scheduling invalid_target
s32 fn_8028B93C(f32 *arg0) {
    f32 dir[3];
    f32 pos[3];
    f32 temp_y, temp_z, temp_x;
    f32 radius;
    register s32 i;
    f32 x, y, z;

    x = arg0[0] * lbl_80564328;
    y = arg0[1] * lbl_80564328;
    z = arg0[2] * lbl_80564328;
    dir[0] = x;
    dir[1] = y;
    dir[2] = z;
    radius = lbl_805643A0 * PSVECMag(arg0);
    for (i = 0; i < 2; i++) {
        temp_z = arg0[5] + fn_80287BC8(lbl_805643A4, lbl_805643A8);
        temp_y = arg0[4] + fn_80287BC8(lbl_805643A4, lbl_805643A8);
        temp_x = arg0[3] + fn_80287BC8(lbl_805643A4, lbl_805643A8);
        pos[1] = temp_y;
        pos[2] = temp_z;
        pos[0] = temp_x;
        fn_8028BED4((void *)*(volatile s32 *)&lbl_8055F6F0, 1, pos, dir, radius);
        fn_8028BED4((void *)*(volatile s32 *)&lbl_8055F6F4, 1, pos, dir, radius);
    }
    return 0x20;
}
#pragma scheduling on
s32 fn_8028BA44(void *arg0) {
    struct {
        f32 sp8;
        f32 spC;
        f32 sp10;
    } locals;
    f32 val;
    s32 gval;
    f32 init = lbl_8056434C;
    locals.sp8 = init;
    locals.spC = init;
    locals.sp10 = init;
    fn_80288A70(arg0, &locals.sp8);
    val = *(f32 *)((u8 *)arg0 + 0xC);
    gval = lbl_8055F700;
    fn_8028AA6C(arg0, gval, val);
    return 0x14;
}
#pragma pop
extern f32 fn_801E7E18(void);
extern s32 lbl_804B32B8[];
extern f32 lbl_805643A0;
extern f32 lbl_80564394;
extern s32 fn_80287B94(s32, s32, f32, f32, f32);
extern s32 fn_8028CD80(s32, s32, void *, f32 *, f32);
s32 fn_8028BA9C(void *arg0) {
    f32 a, b, c, scale;
    f32 values[3];
    s32 temp;
    c = *(f32 *)((u8 *)arg0 + 0x14);
    b = *(f32 *)((u8 *)arg0 + 0x10);
    scale = lbl_805643A0;
    a = *(f32 *)((u8 *)arg0 + 0xC);
    a *= scale;
    b *= scale;
    c *= scale;
    values[0] = a;
    values[1] = b;
    values[2] = c;
    temp = fn_80287B94(0x18, 0x30, a, b, c);
    fn_8028CD80(lbl_8055F6F8, temp, arg0, values, lbl_80564394);
    return 0x1C;
}

s32 fn_8028BB14(s32 arg0) {
    s32 *value = (s32 *)arg0;
    s32 i = 0;
    do {
        fn_8028E584(lbl_8055F704, (s32)value, (s32)(value + 3));
        i++;
    } while (i < 0x14);
    return 0x18;
}

#pragma cplusplus on
extern "C" void fn_8028BC18(void);
void *fn_8028BB68(void *arg0, s32 arg1, f32 farg0) {
    extern char lbl_8055C8BC[];
    extern char lbl_80348C28[];
    extern f32 lbl_8056432C;
    extern f64 lbl_805643B0;
    s32 offset = arg1 * 0x1C;

    fn_8012850C(offset + 0x10, lbl_8055C8BC, offset);
    *(s32 *)arg0 = fn_8002F37C((void *)fn_8028BC18, 0, 0x1C, arg1);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(f32 *)((u8 *)arg0 + 0xC) = farg0;
    *(f32 *)((u8 *)arg0 + 0x10) = lbl_8056432C / farg0;
    *(s32 *)((u8 *)arg0 + 0x14) = fn_802CAC28(lbl_80348C28, 0);
    *(f32 *)((u8 *)arg0 + 0x18) = (f32)fn_8002F208(lbl_805643B0);
    return arg0;
}
#pragma cplusplus off
void fn_8028BC18(void) {
}

s32 fn_8028BC1C(s32 arg0, s32 arg1) {
    extern void fn_802CAC54(s32);
    extern void fn_80128670(s32);
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(((s32 *)arg0)[5]);
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)((void *)arg0);
    }
    return arg0;
}

extern f32 lbl_8056432C;
#pragma push
#pragma scheduling off
void fn_8028BC88(s32 arg0) {
    f32 zero, one;
    one = lbl_8056432C;
    *(s32 *)(arg0 + 4) = 0;
    zero = lbl_8056434C;
    *(f32 *)(arg0 + 0x1c) = one;
    *(f32 *)(arg0 + 0x20) = zero;
    *(f32 *)(arg0 + 0x24) = zero;
    *(f32 *)(arg0 + 0x28) = zero;
    *(f32 *)(arg0 + 0x2c) = one;
    *(f32 *)(arg0 + 0x30) = zero;
    *(f32 *)(arg0 + 0x34) = zero;
    *(f32 *)(arg0 + 0x38) = zero;
    *(f32 *)(arg0 + 0x3c) = one;
    *(f32 *)(arg0 + 0x40) = zero;
    *(f32 *)(arg0 + 0x44) = zero;
    *(f32 *)(arg0 + 0x48) = zero;
    *(f32 *)(arg0 + 0x4c) = one;
    *(f32 *)(arg0 + 0x50) = zero;
    *(f32 *)(arg0 + 0x54) = zero;
    *(f32 *)(arg0 + 0x58) = zero;
    *(f32 *)(arg0 + 0x5c) = one;
    *(f32 *)(arg0 + 0x60) = zero;
    *(f32 *)(arg0 + 0x64) = zero;
    *(f32 *)(arg0 + 0x68) = zero;
    *(f32 *)(arg0 + 0x6c) = one;
    *(f32 *)(arg0 + 0x70) = zero;
    *(f32 *)(arg0 + 0x74) = zero;
    *(f32 *)(arg0 + 0x78) = zero;
    *(f32 *)(arg0 + 0x7c) = one;
    *(f32 *)(arg0 + 0x80) = zero;
    *(f32 *)(arg0 + 0x84) = zero;
    *(f32 *)(arg0 + 0x88) = zero;
    *(f32 *)(arg0 + 0x8c) = one;
    *(f32 *)(arg0 + 0x90) = zero;
    *(f32 *)(arg0 + 0x94) = zero;
    *(f32 *)(arg0 + 0x98) = zero;
    *(f32 *)(arg0 + 0x9c) = one;
    *(f32 *)(arg0 + 0xa0) = zero;
    *(f32 *)(arg0 + 0xa4) = zero;
    *(f32 *)(arg0 + 0xa8) = zero;
    *(f32 *)(arg0 + 0xac) = one;
    *(f32 *)(arg0 + 0xb0) = zero;
    *(f32 *)(arg0 + 0xb4) = zero;
    *(f32 *)(arg0 + 0xb8) = zero;
    *(f32 *)(arg0 + 0xbc) = one;
    *(f32 *)(arg0 + 0xc0) = zero;
    *(f32 *)(arg0 + 0xc4) = zero;
    *(f32 *)(arg0 + 0xc8) = zero;
    *(f32 *)(arg0 + 0xcc) = one;
    *(f32 *)(arg0 + 0xd0) = zero;
    *(f32 *)(arg0 + 0xd4) = zero;
    *(f32 *)(arg0 + 0xd8) = zero;
}

void fn_8028BD5C(s32 arg0) {
    fn_8028BFEC(arg0);
}

extern s32 fn_801E85B4(void);
extern void *fn_801E8718(void);
extern s32 fn_801E8758(s32);
extern void fn_8028C11C(void *, s32 *, s32 *);
extern void fn_802C8BD0(s32);
extern void fn_802C8D74(void);
extern f32 fn_802C9A4C(f32);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_8028BD60(s32 arg0) {
    struct Pair { s32 first, second; };
    struct State {
        struct Pair p0, p1, p2, p3;
        s32 p4;
        struct Pair p5;
        s32 p6;
    };
    s32 index = fn_801E85B4();
    struct State *src = (struct State *)fn_801E8718();
    struct State copy;
    struct Pair *dest;

    copy.p0 = src->p0;
    copy.p1 = src->p1;
    copy.p2 = src->p2;
    copy.p3 = src->p3;
    copy.p4 = src->p4;
    copy.p5 = src->p5;
    copy.p6 = src->p6;

    if (*(s32 *)(arg0 + 4) > 0) {
        f32 saved = fn_802C9A4C(*(f32 *)(arg0 + 0x18));
        fn_802C8BD0(*(s32 *)(arg0 + 0x14));
        if (fn_801E8758(index) == 0)
            fn_8028C11C((void *)arg0, (s32 *)&copy, (s32 *)(arg0 + index * 0x30 + 0x1C));
        else
            fn_8028C11C((void *)arg0, (s32 *)&copy, (s32 *)&copy);
        fn_802C8D74();
        fn_802C9A4C(saved);
    }

    dest = (struct Pair *)(arg0 + index * 0x30 + 0x1C);
    dest[0] = copy.p0;
    dest[1] = copy.p1;
    dest[2] = copy.p2;
    dest[3] = copy.p3;
    ((s32 *)dest)[8] = copy.p4;
    *(struct Pair *)((s32 *)dest + 9) = copy.p5;
    ((s32 *)dest)[11] = copy.p6;
}
#pragma pop

#pragma pop
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028BED4(void *arg0, s32 arg1, void *arg2, void *arg3, f32 farg0) {
    struct Ring {
        void *data;
        s32 head;
        s32 tail;
    } *ring = (struct Ring *)arg0;
    f32 *src = (f32 *)arg2;
    f32 *vel = (f32 *)arg3;
    s32 count;
    s32 limit;
    s32 i;
    f32 now;
    f32 temp_y;
    f32 temp_z;
    f32 temp_x;
    f32 src0;
    f32 src1;
    f32 *dst;
    now = fn_801E7E18();
    count = ring->tail - ring->head;
    limit = arg1 & ((-arg1 & ~arg1) >> 31);
    if (limit < count) count = limit;
    for (i = 0; i < count; i++) {
        dst = (f32 *)((u8 *)ring->data + (ring->head + i) * 0x1C);
        src0 = src[0];
        src1 = src[1];
        dst[0] = src0;
        dst[1] = src1;
        dst[2] = src[2];
        temp_z = vel[2] + fn_80287BC8(-farg0, farg0);
        temp_y = vel[1] + fn_80287BC8(-farg0, farg0);
        temp_x = vel[0] + fn_80287BC8(-farg0, farg0);
        dst[3] = temp_x;
        dst[4] = temp_y;
        dst[5] = temp_z;
        dst[6] = now;
    }
    ring->head += count;
}
#pragma pop

extern f32 fn_801E7E24(void);
extern f32 lbl_80564328, lbl_8056432C, lbl_80564338, lbl_805643B8;
#pragma push
#pragma scheduling invalid_target
void fn_8028BFEC(s32 arg0) {
    struct Entry { f32 x, y, z, vx, vy, vz, age; };
    struct List { struct Entry *data; s32 count; s32 pad; f32 time; };
    struct List *list = (struct List *)arg0;
    register struct Entry *out;
    register struct Entry *in;
    register s32 count;
    register u8 *offset;
    f32 vz;
    f32 vy;
    f32 vx;
    f32 elapsed;
    f32 time;
    f32 f7;
    f32 f8;
    volatile f32 temp[3];

    elapsed = fn_801E7E18() - list->time;
    time = fn_801E7E24();
    f7 = lbl_80564338 * (lbl_805643B8 * time);
    f8 = lbl_8056432C - (lbl_80564328 * time);
    out = list->data;
    for (count = 0, offset = 0; count < list->count; count++, offset += 0x1C) {
        in = (struct Entry *)((u32)list->data + (u32)offset);
        if (in->age > elapsed) {
            vx = in->vx * f8;
            vy = (in->vy * f8) - f7;
            vz = in->vz * f8;
            temp[0] = vx;
            temp[1] = vy;
            temp[2] = vz;
            out->x = in->x + vx * time;
            out->y = in->y + vy * time;
            out->z = in->z + vz * time;
            out->vx = vx;
            out->vy = vy;
            out->vz = vz;
            out->age = in->age;
            out = (struct Entry *)((u8 *)out + 0x1C);
        }
    }
    list->count = ((s32)out - (s32)list->data) / 28;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028C11C(void *arg0, s32 *arg1, s32 *arg2) {
    f32 m[9];
    f32 tmp[9];
    f32 t;
    f32 s;
    f32 scale;
    s32 i;
    s32 off;
    f32 *a1 = (f32 *)arg1;
    f32 *a2 = (f32 *)arg2;
    if (fn_802C8DBC(*(s32 *)((u8 *)arg0 + 4) * 4) == 0)
        return;
    t = fn_801E7E18();
    s = fn_801E7E24();
    for (i = 0; i < 9; i++)
        m[i] = a2[i];
    {
        f32 a = m[1];
        m[1] = m[3];
        m[3] = a;
        a = m[2];
        m[2] = m[6];
        m[6] = a;
        a = m[5];
        m[5] = m[7];
        m[7] = a;
    }
    for (i = 0; i < 3; i++) {
        tmp[i * 3] = fn_80144514(m[0], a1[i * 3], m[3], a1[i * 3 + 1], m[6], a1[i * 3 + 2]);
        tmp[i * 3 + 1] = fn_80144514(m[1], a1[i * 3], m[4], a1[i * 3 + 1], m[7], a1[i * 3 + 2]);
        tmp[i * 3 + 2] = fn_80144514(m[2], a1[i * 3], m[5], a1[i * 3 + 1], m[8], a1[i * 3 + 2]);
    }
    for (i = 0; i < 9; i++)
        m[i] = tmp[i];
    scale = lbl_80564364 * -s;
    (void)scale;
    (void)t;
    if (*(s32 *)((u8 *)arg0 + 4) <= 0) {
        fn_802C8E48();
        return;
    }
    for (i = 0, off = 0; i < *(s32 *)((u8 *)arg0 + 4); i++, off += 0x1C) {
        u8 *ent = (u8 *)(*(s32 *)arg0) + off;
        f32 dx = *(f32 *)(ent + 0) + *(f32 *)(ent + 12) * scale;
        f32 dy = *(f32 *)(ent + 4) + *(f32 *)(ent + 16) * scale;
        f32 dz = *(f32 *)(ent + 8) + *(f32 *)(ent + 20) * scale;
        dx -= a2[9];
        dy -= a2[10];
        dz -= a2[11];
        {
            f32 diff[3];
            diff[0] = dx;
            diff[1] = dy;
            diff[2] = dz;
            XfmVec(m, diff, diff);
            diff[0] += a1[9];
            diff[1] += a1[10];
            diff[2] += a1[11];
            {
                f32 delta[3];
                delta[0] = diff[0] - *(f32 *)(ent + 0);
                delta[1] = diff[1] - *(f32 *)(ent + 4);
                delta[2] = diff[2] - *(f32 *)(ent + 8);
                if (PSVECDotProduct(a1 + 3, delta) > lbl_8056434C)
                    scale = lbl_8056432C;
                else
                    scale = lbl_80564340;
                (void)scale;
            }
        }
        fn_802C8E00(0, 0, *(f32 *)(ent + 0), *(f32 *)(ent + 4), *(f32 *)(ent + 8), lbl_8056434C, lbl_8056432C);
    }
    fn_802C8E48();
}
#pragma pop

#pragma pop
void *fn_8028C824(void *arg0, s32 arg1) {
    s32 size = arg1 * 0x28;
    void *memory;
    void *array;

    memory = ((void *(*)(s32, void *, s32))fn_8012850C)(size + 0x10, lbl_80348C34, size);
    array = ((void *(*)(void *, void *, s32, s32, s32))fn_8002F37C)(memory, fn_8028C8BC, 0, 0x28, arg1);
    ((void **)arg0)[0] = array;
    ((s32 *)arg0)[1] = 0;
    ((s32 *)arg0)[2] = arg1;
    ((s32 *)arg0)[3] = fn_802CAC28(lbl_80348C40, 0);
    ((f32 *)arg0)[4] = (f32)fn_8002F208(lbl_805643C8);
    return arg0;
}
#pragma dont_inline off
void fn_8028C8BC(void) {}

extern void fn_802CAC54(s32);
extern void fn_80128670(s32);
extern s32 fn_8012850C(s32, void *, s32);
extern s32 fn_8002F37C(void *, s32, s32, s32);
extern s32 fn_802CAC28(void *, s32);
extern f64 fn_8002F208(f64);
extern char lbl_80348C34[];
extern char lbl_80348C40[];
extern f64 lbl_805643C8;
extern void fn_8028C8BC(void);
void *fn_8028C8C0(void *arg0, s32 arg1) {
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(((s32 *)arg0)[3]);
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) ((s32 (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
}

void fn_8028C92C(void *arg0) {
    ((s32 *)arg0)[1] = 0;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single off
void fn_8028C938(s32 arg0) {
    extern f32 fn_801E7E24(void);
    extern f32 lbl_8056432C, lbl_805643B8, lbl_805643D0, lbl_805643D4;
    struct Entry { f32 x, y, z, vx, vy, vz, u0, u1, u2, age; };
    struct List { struct Entry *data; s32 count; };
    struct List *list = (struct List *)arg0;
    register struct Entry *out;
    register u8 *offset;
    register s32 count;
    register struct Entry *in;
    f32 vz;
    f32 vy;
    f32 vx;
    f32 elapsed;
    f32 step;
    f32 scale;
    f32 factor;
    f32 delta;
    volatile f32 temp_z;
    volatile f32 temp_y;
    volatile f32 temp_x;

    elapsed = fn_801E7E18() - lbl_805643D0;
    step = fn_801E7E24();
    scale = lbl_805643B8 * step;
    delta = lbl_805643D4 * scale;
    out = list->data;
    factor = lbl_8056432C;
    count = 0;
    offset = 0;
    while (count < list->count) {
        in = (struct Entry *)((u32)list->data + (u32)offset);
        if (in->age > elapsed) {
            vx = in->vx * factor;
            vy = (in->vy * factor) - delta;
            vz = in->vz * factor;
            temp_x = vx;
            temp_z = (vz * step, vz);
            temp_y = vy;
            out->x = in->x + vx * step;
            out->y = in->y + vy * step;
            out->z = in->z + vz * step;
            out->vx = vx;
            out->vy = vy;
            out->vz = vz;
            out->u0 = in->u0;
            out->u1 = in->u1;
            out->u2 = in->u2;
            out->age = in->age;
            out = (struct Entry *)((u8 *)out + 0x28);
        }
        offset += 0x28;
        count++;
    }
    list->count = ((s32)out - (s32)list->data) / 40;
}
#pragma pop

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8028CA70(s32 arg0) {
    extern f32 PSVECDotProduct(f32 *, f32 *);
    extern f32 PSVECMag(f32 *);
    extern f64 cos(f32);
    extern f32 fn_801E7E18(void);
    extern void fn_802C8BD0(s32);
    extern void fn_802C8D74(void);
    extern s32 fn_802C8DBC(s32);
    extern void fn_802C8E00();
    extern void fn_802C8E48(void);
    extern void *fn_802C9A40(void);
    extern f32 fn_802C9A4C(f32);
    extern f64 sin(f32);
    extern f32 lbl_8056432C, lbl_8056434C, lbl_80564358, lbl_805643D8, lbl_805643DC;
    struct Stack { f32 out[3]; f32 diff[3]; s32 axisX, axisY, axisZ; f32 sp2C, sp30, sp34, sp38, sp3C, sp40, sp44, sp48, sp4C; } stack;
    struct Axis { s32 x, y, z; };
    struct Entry { f32 f[10]; };
    f32 alphaScale, zero, one, threshold, time, saved, drawScale;
    f32 temp_f0, temp_f0_2, temp_f1, temp_f1_2, temp_f1_3, temp_f1_4, temp_f1_5;
    f32 temp_f22, temp_f23, temp_f24, temp_f25, temp_f2, temp_f2_2, temp_f2_3;
    f32 temp_f3, temp_f3_2, temp_f3_3, temp_f3_4, temp_f4, temp_f4_2, temp_f6, temp_f6_2, temp_f6_3, temp_f6_4, temp_f9;
    s32 temp_r30, temp_r3, temp_r3_3, temp_r4_2, var_r0, var_r28, var_r29;
    s32 *temp_r27;
    s32 firstCount = *(s32 *)(arg0 + 4);
    if (firstCount >= 1) {
        saved = fn_802C9A4C(*(f32 *)(arg0 + 0x10));
        fn_802C8BD0(*(s32 *)(arg0 + 0xC));
        temp_r3 = *(s32 *)(arg0 + 4);
        if (fn_802C8DBC((temp_r3 * 4) - temp_r3) != 0) {
            *(struct Axis *)&stack.axisX = *(struct Axis *)fn_802C9A40();
            time = fn_801E7E18();
            one = lbl_8056432C;
            threshold = lbl_805643D8;
            zero = lbl_8056434C;
            alphaScale = lbl_805643DC;
            drawScale = lbl_80564358;
            var_r29 = 0;
            var_r28 = 0;
            goto check;
        body:
            temp_r27 = (s32 *)((u8 *)*(s32 *)arg0 + var_r28);
            temp_f1 = time - *(f32 *)((u8 *)temp_r27 + 0x24);
            stack.diff[0] = *(f32 *)((u8 *)temp_r27 + 0x18) * temp_f1;
            stack.diff[1] = *(f32 *)((u8 *)temp_r27 + 0x1C) * temp_f1;
            stack.diff[2] = *(f32 *)((u8 *)temp_r27 + 0x20) * temp_f1;
            temp_f1_2 = PSVECMag(stack.diff);
            if (temp_f1_2 > threshold) {
                temp_f4 = one / temp_f1_2;
                temp_f23 = temp_f4 * stack.diff[0];
                temp_f22 = temp_f4 * stack.diff[1];
                temp_f25 = temp_f4 * stack.diff[2];
                temp_f24 = (f32)sin(temp_f1_2);
                temp_f9 = (f32)cos(temp_f1_2);
                temp_f0 = one - temp_f9;
                temp_f2 = temp_f23 * temp_f23;
                temp_f3 = temp_f22 * temp_f22;
                temp_f4_2 = temp_f25 * temp_f25;
                temp_f6 = temp_f0 * temp_f23;
                temp_f3_2 = temp_f22 * temp_f6;
                temp_f2_2 = temp_f0 * temp_f2;
                temp_f6_2 = temp_f0 * temp_f3;
                stack.sp2C = temp_f9 + temp_f2_2;
                temp_f3_3 = temp_f24 * temp_f25;
                temp_f6_3 = temp_f25 * temp_f6;
                temp_f2_3 = temp_f24 * temp_f22;
                stack.sp30 = temp_f3_2 + temp_f3_3;
                temp_f0_2 = temp_f24 * temp_f23;
                stack.sp38 = temp_f3_2 - temp_f3_3;
                temp_f4_2 = temp_f0 * temp_f4_2;
                temp_f3_4 = temp_f0 * temp_f22;
                stack.sp34 = temp_f6_3 - temp_f2_3;
                temp_f3_2 = temp_f25 * temp_f3_4;
                stack.sp3C = temp_f9 + temp_f6_2;
                stack.sp40 = temp_f3_2 + temp_f0_2;
                stack.sp44 = temp_f6_3 + temp_f2_3;
                stack.sp48 = temp_f3_2 - temp_f0_2;
                stack.sp4C = temp_f9 + temp_f4_2;
            } else {
                stack.sp2C = one;
                stack.sp30 = zero;
                stack.sp34 = zero;
                stack.sp38 = zero;
                stack.sp3C = one;
                stack.sp40 = zero;
                stack.sp44 = zero;
                stack.sp48 = zero;
                stack.sp4C = one;
            }
            temp_f1_3 = PSVECDotProduct(&stack.sp38, (f32 *)&stack.axisX);
            var_r0 = 0xFF;
            temp_r4_2 = (s32)(alphaScale * (temp_f1_3 * temp_f1_3));
            temp_r3_3 = temp_r4_2 & ((-temp_r4_2 & ~temp_r4_2) >> 31);
            if (temp_r3_3 >= 0xFF) goto skip_render;
            var_r0 = temp_r3_3;
            temp_r30 = (var_r0 << 24) | 0x00FFFFFF;
            fn_802C8E00(temp_r30, 0, *(f32 *)temp_r27, *(f32 *)((u8 *)temp_r27 + 4), *(f32 *)((u8 *)temp_r27 + 8), lbl_8056434C, lbl_8056432C);
            temp_f6_3 = stack.sp2C * drawScale;
            temp_f2_2 = *(f32 *)((u8 *)temp_r27 + 4) + (stack.sp30 * drawScale);
            temp_f1_4 = *(f32 *)temp_r27 + temp_f6_3;
            temp_f3_3 = *(f32 *)((u8 *)temp_r27 + 8) + (stack.sp34 * drawScale);
            stack.out[0] = temp_f1_4;
            stack.out[1] = temp_f2_2;
            stack.out[2] = temp_f3_3;
            fn_802C8E00(temp_r30, 0, temp_f1_4, temp_f2_2, temp_f3_3, lbl_8056432C, lbl_8056432C, temp_f6_3);
            temp_f6_4 = stack.sp44 * drawScale;
            temp_f2_3 = *(f32 *)((u8 *)temp_r27 + 4) + (stack.sp48 * drawScale);
            temp_f1_5 = *(f32 *)temp_r27 + temp_f6_4;
            temp_f3_4 = *(f32 *)((u8 *)temp_r27 + 8) + (stack.sp4C * drawScale);
            stack.out[0] = temp_f1_5;
            stack.out[1] = temp_f2_3;
            stack.out[2] = temp_f3_4;
            fn_802C8E00(temp_r30, 1, temp_f1_5, temp_f2_3, temp_f3_4, lbl_8056434C, lbl_8056434C, temp_f6_4);
        skip_render:
            var_r28 += 0x28;
            var_r29 += 1;
        check:
            if (var_r29 < *(s32 *)(arg0 + 4)) goto body;
            fn_802C8E48();
        }
        fn_802C8D74();
        fn_802C9A4C(saved);
    }
}
#pragma scheduling on
#pragma pop
extern f32 lbl_805643E0;
extern f32 lbl_805643E4;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling on
s32 fn_8028CD80(s32 arg0, s32 arg1, void *arg2, f32 *arg3, f32 farg0) {
    struct Ring { void *data; s32 head; s32 tail; } *ring = (struct Ring *)arg0;
    f32 *src = (f32 *)arg2;
    f32 *vel = arg3;
    register s32 count;
    register s32 limit;
    register s32 i;
    f32 now;
    f32 src0;
    f32 src1;
    f32 src2;
    f32 temp_y;
    f32 temp_z;
    f32 temp_x;
    f32 rand0;
    f32 rand1;
    f32 rand2;
    f32 *dst;

    now = fn_801E7E18();
    count = ring->tail - ring->head;
    limit = arg1 & ((-arg1 & ~arg1) >> 31);
    if (limit < count) count = limit;
    for (i = 0; i < count;) {
        dst = (f32 *)((u8 *)ring->data + (ring->head + i) * 0x28);
        src0 = src[0];
        src1 = src[1];
        dst[0] = src0;
        src2 = src[2];
        dst[1] = src1;
        dst[2] = src2;
        temp_z = vel[2] + fn_80287BC8(-farg0, farg0);
        temp_y = vel[1] + fn_80287BC8(-farg0, farg0);
        temp_x = vel[0] + fn_80287BC8(-farg0, farg0);
        dst[3] = temp_x;
        dst[4] = temp_y;
        dst[5] = temp_z;
        rand0 = fn_80287BC8(lbl_805643E0, lbl_805643E4);
        rand1 = fn_80287BC8(lbl_805643E0, lbl_805643E4);
        rand2 = fn_80287BC8(lbl_805643E0, lbl_805643E4);
        dst[6] = rand2;
        i++;
        dst[7] = rand1;
        dst[8] = rand0;
        dst[9] = now;
    }
    ring->head += count;
}
#pragma pop

