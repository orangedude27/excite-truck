// Code of main that had no source file yet: decomp.wtf gave it this one.
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

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
extern "C" void fn_8028A784(void) {
    class Obj {
    public:
        virtual void v0(int);
    };
    extern void fn_801EF024(void *);
    extern s32 fn_8028BB14(s32);
    extern s32 fn_8028BA9C(void *);
    extern s32 fn_8028BA44(void *);
    extern void fn_8028B500(void), fn_8028B93C(void);
    extern void fn_8028B4CC(void), fn_8028AD78(void);
    extern void fn_802976DC(s32);
    extern void *fn_8028C8C0(void *, s32);
    extern void fn_8028BC1C(s32, s32);
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

void fn_8028A9F4(void) {
    s32 i;
    void **p;
    ((void (*)(void *))(*(void ***)lbl_8055F6FC)[5])(lbl_8055F6FC);
    p = (void **)lbl_804B3238;
    i = 0;
    do {
        void *obj = *p;
        if (obj) ((void (*)(void *))(*(void ***)obj)[5])(obj);
        i++;
        if (i >= 8) break;
        p = (void **)((u8 *)p + 0x10);
    } while (1);
}

#pragma push
#pragma processor 750
extern s32 fn_8029771C(void *, void *, f32);
#pragma push
#pragma processor 750
#pragma scheduling off
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
#pragma pop

void fn_8028AD78(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        struct Obj8028 *p = *(struct Obj8028 **)((u8 *)lbl_804B3238 + i * 0x10);
        if (p) {
            ((void (*)(void *, s32))p->vtable[2])(p, 1);
            *(struct Obj8028 **)((u8 *)lbl_804B3238 + i * 0x10) = 0;
        }
    }
}

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

#pragma push
#pragma scheduling off
s32 fn_8028BA44(void *arg0) {
    struct {
        f32 sp8;
        f32 spC;
        f32 sp10;
    } locals;
    
    f32 val;
    s32 gval;
    
    locals.sp8 = lbl_8056434C;
    locals.spC = lbl_8056434C;
    locals.sp10 = lbl_8056434C;
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
    f32 x = *(f32 *)((u8 *)arg0 + 0xC);
    f32 y = *(f32 *)((u8 *)arg0 + 0x10);
    f32 z = *(f32 *)((u8 *)arg0 + 0x14);
    f32 scale = lbl_805643A0;
    f32 a = x * scale;
    f32 b = y * scale;
    f32 c = z * scale;
    f32 values[3];
    s32 temp;
    values[0] = a; values[1] = b; values[2] = c;
    temp = fn_80287B94(0x18, 0x30, a, b, c);
    fn_8028CD80(lbl_8055F6F8, temp, arg0, values, lbl_80564394);
    return 0x1C;
}

s32 fn_8028BB14(s32 arg0) {
    s32 i;
    i = 0;
    do {
        fn_8028E584(lbl_8055F704, arg0, arg0 + 0xC);
        i++;
    } while (i < 0x14);
    return 0x18;
}

void fn_8028BC18(void) {
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

#pragma pop
void fn_8028BED4(void *arg0, s32 arg1, void *arg2, void *arg3, f32 farg0) {
    struct Entry { f32 f[7]; } *dst;
    f32 *src = (f32 *)arg2;
    f32 *vel = (f32 *)arg3;
    s32 *arr = (s32 *)arg0;
    s32 count = arr[2] - arr[1];
    s32 max = arg1 & (-arg1 & ~arg1) >> 31;
    f32 now = fn_801E7E18();
    f32 t;
    s32 i;
    if (max < count) count = max;
    for (i = 0; i < count; i++) {
        dst = (struct Entry *)(arr[0] + (arr[1] + i) * 0x1C);
        dst->f[0] = src[0];
        dst->f[1] = src[1];
        dst->f[2] = src[2];
        t = vel[2] + fn_80287BC8(now, -farg0);
        dst->f[3] = vel[1] + fn_80287BC8(now, -farg0);
        dst->f[4] = i;
        dst->f[5] = vel[0] + fn_80287BC8(now, -farg0);
        dst->f[6] = now;
    }
    arr[1] += count;
}

#pragma pop
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

extern f32 lbl_805643E0;
extern f32 lbl_805643E4;
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling off
s32 fn_8028CD80(s32 arg0, s32 arg1, void *arg2, f32 *arg3, f32 farg0) {
    struct Entry { f32 f[10]; } *dst;
    f32 *src = (f32 *)arg2;
    f32 *vel = (f32 *)arg3;
    s32 *arr = (s32 *)arg0;
    s32 count = arr[2] - arr[1];
    s32 max = arg1 & (-arg1 & ~arg1) >> 31;
    f32 now = fn_801E7E18();
    f32 t;
    f32 a;
    f32 b;
    f32 c;
    s32 i;
    if (max < count) count = max;
    for (i = 0; i < count; i++) {
        dst = (struct Entry *)(arr[0] + (arr[1] + i) * 0x28);
        dst->f[0] = src[0];
        dst->f[1] = src[1];
        dst->f[2] = src[2];
        t = vel[2] + fn_80287BC8(now, -farg0);
        dst->f[3] = vel[1] + fn_80287BC8(now, -farg0);
        dst->f[4] = vel[0] + fn_80287BC8(now, -farg0);
        a = fn_80287BC8(lbl_805643E0, lbl_805643E4);
        b = fn_80287BC8(lbl_805643E0, lbl_805643E4);
        c = fn_80287BC8(lbl_805643E0, lbl_805643E4);
        dst->f[5] = i;
        dst->f[6] = c;
        dst->f[7] = b;
        dst->f[8] = now;
    }
    arr[1] += count;
    return 0;
}
#pragma pop
