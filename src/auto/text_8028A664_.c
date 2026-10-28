// Code of main that had no source file yet: decomp.wtf gave it this one.
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern void fn_8028C8BC(void);

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
    extern void fn_8028B500(void);
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
#pragma scheduling on
#pragma pop

void fn_8028AD78(void) {
    u8 *slot = (u8 *)lbl_804B3238;
    s32 i = 0;
loop:
    {
        struct Obj8028 *p = *(struct Obj8028 **)slot;
        if (p == 0) goto next;
        if (p == 0) goto clear;
        ((void (*)(void *, s32))*(void **)((u8 *)*(void **)p + 8))(p, 1);
clear:
        *(struct Obj8028 **)slot = 0;
    }
next:
    i++;
    slot += 0x10;
    if (i < 8) goto loop;
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
#pragma cplusplus on
s32 fn_8028B500(void *arg0) { return arg0 ? 0x38 : 0; }
#pragma cplusplus off

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
void fn_8028BD60(s32 arg0) {
    s32 sp[12];
    f32 temp_f31;
    s32 temp_r30 = fn_801E85B4();
    s32 *src = (s32 *)fn_801E8718();
    int i;
    for (i = 0; i < 12; i++) sp[i] = src[i];
    if (*(s32 *)(arg0 + 4) > 0) {
        temp_f31 = fn_802C9A4C(*(f32 *)(arg0 + 0x18));
        fn_802C8BD0(*(s32 *)(arg0 + 0x14));
        if (fn_801E8758(temp_r30) == 0)
            fn_8028C11C((void *)arg0, sp, (s32 *)(arg0 + temp_r30 * 0x30 + 0x1C));
        else fn_8028C11C((void *)arg0, sp, sp);
        fn_802C8D74();
        fn_802C9A4C(temp_f31);
    }
    for (i = 0; i < 12; i++) *(s32 *)(arg0 + temp_r30 * 0x30 + 0x1C + i * 4) = sp[i];
}

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
    register s32 count;
    register u8 *offset;
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
    for (count = 0, offset = 0; count < list->count; count++, offset += 0x28) {
        in = (struct Entry *)((u32)list->data + (u32)offset);
        if (in->age > elapsed) {
            vx = in->vx * factor;
            vy = (in->vy * factor) - delta;
            vz = in->vz * factor;
            temp_x = vx;
            temp_z = vz;
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
                temp_f3 = temp_f24 * temp_f25;
                temp_f6 = temp_f0 * temp_f23;
                temp_f4_2 = temp_f22 * temp_f6;
                stack.sp2C = temp_f9 + (temp_f0 * (temp_f23 * temp_f23));
                temp_f6_2 = temp_f25 * temp_f6;
                temp_f2 = temp_f24 * temp_f22;
                stack.sp30 = temp_f4_2 + temp_f3;
                temp_f3_2 = temp_f25 * (temp_f0 * temp_f22);
                temp_f0_2 = temp_f24 * temp_f23;
                stack.sp38 = temp_f4_2 - temp_f3;
                stack.sp34 = temp_f6_2 - temp_f2;
                stack.sp3C = temp_f9 + (temp_f0 * (temp_f22 * temp_f22));
                stack.sp40 = temp_f3_2 + temp_f0_2;
                stack.sp44 = temp_f6_2 + temp_f2;
                stack.sp48 = temp_f3_2 - temp_f0_2;
                stack.sp4C = temp_f9 + (temp_f0 * (temp_f25 * temp_f25));
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
