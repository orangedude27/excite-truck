#include <types.h>
typedef s32 M2C_UNK;
typedef struct StackArg_801B07B4 { void *node; f32 angle; s32 word; } StackArg_801B07B4;
extern void *fn_801B83A0(void);
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern void *fn_80156A40(void);
extern void *fn_801284F8(s32, const char *);
extern void *fn_80135DC4(void *, s32, void *);
extern void *fn_801352B8(void);
extern char lbl_80335B28[], lbl_80335B3C[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern u8 lbl_8055E674;
extern s32 lbl_8055E67C;
extern s32 lbl_8055E6A8;
extern u8 lbl_8055E691;
extern u8 lbl_8055E692;
extern void *fn_801B2EC0(s32);
extern s32 fn_80128668(void);
extern void fn_801B2118(void);
extern void *fn_801B21B8(void *);
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern char lbl_80335BFC[];
extern f32 lbl_805625BC;
extern f32 lbl_80562604;
extern f32 lbl_80562610;
extern void *memset(void *, int, unsigned long);
extern void *lbl_8055E678;
extern u8 lbl_8055E6A0;
extern f32 lbl_8055E6A4;
extern s32 lbl_8055E688;
extern s32 lbl_8055E66C;
extern s32 lbl_8055E670;
extern void *lbl_8055E680;
extern void *lbl_8055E684;
extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
extern s32 lbl_80435C30[];
extern s32 lbl_80435BE8[];
extern void *lbl_8055E694;
extern f32 lbl_805625F0;
extern void *lbl_8055E68C;
extern u8 lbl_8055E690;
extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
extern void fn_801B18B8();
extern void fn_801E89F4(s32);
extern f32 lbl_805625B8;
extern f32 lbl_80562618;

#pragma cplusplus on
struct Dummy_801B30E0 {
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void *d5();
    virtual void *d6(); virtual void *d7(); virtual void *d8();
};
struct Dummy_801B0DF0 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void *d8(void *, void *);
};
#pragma cplusplus off
extern s32 fn_80139EC4(f32, f32);
extern s32 fn_802B04D4(f32 *, f32, f32, f32);
extern f32 lbl_805625BC, lbl_805625C0, lbl_805625C4;
extern f32 lbl_80562600;
extern char lbl_80335AD8[], lbl_80335B04[];
extern f32 lbl_80558DC4;
#pragma push
#pragma processor 750
s32 fn_801B06D8(void *arg0, void *arg1, s32 arg2) {
    volatile f32 sp18, sp14, sp10, spC, sp8;
    register f32 limit;
    register f32 increment;
    register f32 start;
    register f32 step;
    register s32 enabled asm("r3");
    step = lbl_805625BC;
    increment = lbl_805625C0;
    start = step;
    limit = lbl_805625C4;
    while (step < limit) {
        f32 dx = *(f32 *)arg1 * step;
        f32 dy = *(f32 *)((u8 *)arg1 + 4) * step;
        f32 x = *(f32 *)arg0 + dx;
        f32 y = *(f32 *)((u8 *)arg0 + 4) + dy;
        sp14 = start;
        sp8 = x;
        spC = y;
        sp10 = x;
        sp18 = y;
        if (fn_802B04D4((f32 *)&sp10, dy, x, dx)) return 1;
        enabled = lbl_8055E66C;
        if (enabled && fn_80139EC4(sp8, spC)) return 1;
        step += increment;
    }
    return 0;
}

extern s32 fn_801784DC(f32 *, f32 *, s32, s32, s32, f32);
extern void fn_801B8040(void *, void *, f32);
extern f32 lbl_805625BC, lbl_805625C8, lbl_805625CC, lbl_805625D0, lbl_805625D4, lbl_805625D8;
#pragma scheduling invalid_target
void fn_801B07B4(void *arg0, void *arg1) {
    register s32 first = *(s32 *)arg1;
    f32 argAngle = *(f32 *)((u8 *)arg1 + 4);
    s32 argWord = *(s32 *)((u8 *)arg1 + 8);
    volatile s32 sp20;
    volatile f32 sp1C;
    void * volatile sp18;
    volatile s32 sp14, sp10, spC;
    volatile f32 sp8;
    f32 x, scale, angle, finalPos, finalScale;

    sp18 = (void *)first;
    sp1C = argAngle;
    sp20 = argWord;
    while (fn_801B06D8(sp18, (u8 *)sp18 + 8, first))
        sp18 = *(void **)((u8 *)sp18 + 0x14);
    fn_801B8040(arg0, (void *)&sp18, lbl_805625BC);
    x = *(f32 *)((u8 *)arg0 + 0x18);
    scale = lbl_805625C8;
    *(f32 *)((u8 *)arg0 + 0x30) = x * scale;
    *(f32 *)((u8 *)arg0 + 0x34) = *(f32 *)((u8 *)arg0 + 0x1C) * scale;
    *(volatile s32 *)((u8 *)arg0 + 0x3C) = 0;
    *(f32 *)((u8 *)arg0 + 0x38) = *(f32 *)((u8 *)arg0 + 0x20) * scale;
    spC = *(s32 *)((u8 *)arg0 + 0x24);
    sp10 = *(s32 *)((u8 *)arg0 + 0x28);
    sp14 = *(s32 *)((u8 *)arg0 + 0x2C);
    if (*(volatile s32 *)&lbl_8055E670 &&
        fn_80139EC4(*(f32 *)(void *)&spC, *(f32 *)(void *)&sp14)) {
        angle = *(f32 *)(void *)&sp10;
        *(f32 *)(void *)&sp10 = angle + lbl_805625CC;
        if (fn_801784DC((f32 *)(void *)&spC, (f32 *)(void *)&sp8, 0, 0, 0,
                        angle))
            *(f32 *)((u8 *)arg0 + 0x28) = lbl_805625D0 + *(f32 *)(void *)&sp8;
    }
    finalPos = *(f32 *)((u8 *)arg0 + 0x28) + lbl_805625D4;
    finalScale = lbl_805625D8;
    *(f32 *)((u8 *)arg0 + 0x34) = finalScale;
    *(f32 *)((u8 *)arg0 + 0x28) = finalPos;
}
#pragma scheduling on
u32 fn_801B08E8(u32 arg0, u32 arg1, s32 arg2) {
    u32 var_r4;
    var_r4 = arg1;
    if (var_r4 < arg0) var_r4 += arg2;
    return var_r4 - arg0;
}

void fn_801B0B8C(void *arg0) {
    register f32 value = lbl_805625F0;
    *(u8 *)((u8 *)arg0 + 0x2C) = 0;
    *(f32 *)((u8 *)arg0 + 0x30) = value;
}

s32 fn_801B0BA0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x5C);
}

s32 fn_801B0BA8(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x58); }

extern f32 lbl_805625F4;
extern char lbl_80335A58[];
extern void fn_802E30C8(const char *, ...);
#pragma push
#pragma processor 750
void fn_801B0BB0(void *arg0, void *arg1) {
    void *temp_r5;
    void *var_r3;
    void *var_r0;
    s32 var_r4;
    f32 threshold = lbl_805625F4;
    f32 value;
    f32 temp_f31;

    temp_r5 = *(void **)((u8 *)arg1 + 4);
    *(void **)arg0 = temp_r5;
    *(f32 *)((u8 *)arg0 + 4) = *(f32 *)((u8 *)arg1 + 8);
    *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)arg1 + 0xC);
    value = *(f32 *)((u8 *)*(void **)((u8 *)arg1 + 0x2C) + 8);
    temp_f31 = value - threshold;
    if (*(f32 *)((u8 *)temp_r5 + 0x1C) > temp_f31) {
        fn_802E30C8(lbl_80335A58);
        var_r3 = *(void **)((u8 *)*(void **)((u8 *)arg1 + 0x2C) + 0x1C);
        var_r0 = 0;
        var_r4 = 0;
        do {
            var_r0 = var_r3;
            var_r4++;
            if (var_r4 > 0xBB8) {
                var_r0 = 0;
                break;
            }
            var_r3 = *(void **)((u8 *)var_r3 + 0x14);
        } while (*(f32 *)((u8 *)var_r3 + 0x1C) < temp_f31);
        if (var_r0 != 0) *(void **)arg0 = var_r0;
    }
}

extern void fn_801B30D0(s32);
extern void fn_801B30E0(s32);
extern s32 fn_801B8928(s32, void *, s32);
extern void fn_801B0BB0(void *, void *);
extern void fn_801B07B4(void *, void *);
extern void fn_801B08FC(void *, void *);
#pragma cplusplus on
extern "C" void fn_801B0C78(s32 arg0) {
    struct Item {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void *getPayload(); virtual void *getMetadata();
    };
    struct Context {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual s32 check(void *, s32, s32, s32);
    };
    struct Scratch {
        u32 raw[3]; s32 value; f32 weight; s32 limit;
        u8 request[0x20]; u8 pad[0x20]; s16 marker;
    } scratch;
    void *base = lbl_8055E684;
    Item *obj = (Item *)((u8 *)base + (arg0 << 7));
    void *meta;
    bool isResource;

    scratch.marker = -1;
    meta = obj->getMetadata();
    isResource = *(u32 *)((u8 *)meta + 0x10) == 0x50434152;
    if (isResource) {
        fn_801B30D0(arg0);
        fn_801B30E0(arg0);
    }
    if (fn_801B8928(arg0, scratch.request, 0) != 0) goto done;
    if (lbl_8055E68C != 0 &&
        ((Context *)lbl_8055E68C)->check(scratch.request, arg0,
            *(s32 *)((u8 *)*(void * volatile *)&lbl_8055E684 + 0x7C), 0) != 0) goto done;
    scratch.value = 0;
    scratch.limit = 0x2710;
    scratch.weight = lbl_805625BC;
    if (isResource) {
        fn_801B0BB0(scratch.raw, obj->getPayload());
        scratch.value = scratch.raw[0];
        scratch.weight = *(f32 *)&scratch.raw[1];
        scratch.limit = scratch.raw[2];
    } else {
        scratch.value = *(s32 *)((u8 *)obj + 0x4C);
        scratch.weight = *(f32 *)((u8 *)obj + 0x50);
        scratch.limit = *(s32 *)((u8 *)obj + 0x54);
    }
    fn_801B07B4(scratch.request, &scratch.value);
done:
    fn_801B08FC(obj, scratch.request);
}
#pragma cplusplus off
s32 fn_801B0DE0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

s32 fn_801B0DE8(s32 arg0) { return arg0 + 4; }

#pragma cplusplus on
extern "C" s32 fn_801B0DF0(s32 arg0) {
    struct Dummy {
        virtual void *d0(void *);
        virtual void *d1(void *);
        virtual void *d2(void *);
        virtual void *d3(void *);
        virtual void *d4(void *);
        virtual void *d5(void *);
        virtual void *d6(void *);
    };
    Dummy *obj = (Dummy *)((u8 *)lbl_8055E684 + (arg0 << 7));
    void *result = obj->d6(lbl_8055E684);
    return *(u32 *)((u8 *)result + 0x10) == 0x50434152;
}
#pragma cplusplus reset
extern s32 fn_801B2F40(s32);
extern s32 fn_801B0DF0(s32);
#pragma cplusplus on
extern "C" s32 fn_801B0E40(s32 arg0, s32 *arg1) {
    struct Dummy {
        virtual void *d0();
        virtual void *d1();
        virtual void *d2();
    };
    s32 temp_r31;
    s32 var_r30;
    s32 var_r31;
    s32 temp_r0;
    void *base = lbl_8055E684;
    Dummy *obj = (Dummy *)((u8 *)base + (arg0 << 7));

    base = obj->d2();
    temp_r31 = *(s32 *)((u8 *)base + 4);
    var_r30 = temp_r31;
    while (var_r30 <= (s32)lbl_8055E678) {
        fn_801B2F40(var_r30 - 1);
        if (((s32 (*)(void))fn_801B0DF0)() != 0) return 0;
        var_r30++;
    }
    temp_r0 = *arg1;
    var_r30 = temp_r31 - 1;
    var_r31 = 1;
    if (temp_r0 > 1)
        var_r31 = temp_r0;
    while (var_r30 >= var_r31) {
        fn_801B2F40(var_r30 - 1);
        if (((s32 (*)(void))fn_801B0DF0)() != 0) {
            *arg1 = var_r30 + 1;
            break;
        }
        var_r30--;
    }
    return 1;
}
#pragma cplusplus reset
s32 fn_801B0F18(void) {
    return *(s32 *)((u8 *)lbl_8055E684 + (fn_80179630() << 7) + 0x4C);
}

u32 fn_801B0F48(u32 arg0, u32 arg1) {
    u32 diff = arg1 - arg0;
    if (arg0 > arg1) diff = arg0 - arg1;
    return (0x20000U << __cntlzw(diff ^ 0x20000)) >> 31;
}

extern f32 lbl_805625F0;
extern void *lbl_8055E68C;
extern u8 lbl_8055E690;
#pragma cplusplus on
extern "C" s32 fn_801B1130(s32 arg0) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual s32 f3(s32, s32);
    };
    s32 var_r31;
    s32 var_r30;
    s32 var_r3;

    var_r31 = 1;
    var_r30 = 0;
    if (lbl_8055E68C != 0) {
        Dummy *obj = (Dummy *)lbl_8055E68C;
        if (obj->f3(arg0, *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x7C)) != 0)
            var_r30 = 1;
    }
    if (var_r30 == 0) {
        var_r3 = 0;
        if (lbl_8055E68C == 0 && lbl_8055E690 != 0)
            var_r3 = 1;
        if (var_r3 == 0)
            var_r31 = 0;
    }
    return var_r31;
}
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma push
#pragma use_lmw_stmw off
extern "C" s32 fn_801B11DC(const void *arg0, const void *arg1) {
    extern int __cntlzw(unsigned int);
    struct Item {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void *get();
    };
    u32 idx0 = *(volatile const u32 *)arg0;
    u32 offset0;
    u32 cutoff = *(volatile u32 *)&lbl_8055E680;
    u32 offset1;
    void *base = *(void * volatile *)&lbl_8055E684;
    u32 idx1 = *(volatile const u32 *)arg1;
    Item *obj0;
    Item *obj1;
    u32 flag0;
    u32 flag1;
    s32 key0;
    s32 key1;
    s32 tie0;
    s32 tie1;
    offset0 = idx0 << 7;
    offset1 = idx1 << 7;
    obj0 = (Item *)((u8 *)base + offset0);
    obj1 = (Item *)((u8 *)base + offset1);
    cutoff += 1;
    flag0 = (u32)__cntlzw(*(u32 *)((u8 *)obj0 + 0x68) - cutoff) >> 5;
    flag1 = (u32)__cntlzw(*(u32 *)((u8 *)obj1 + 0x68) - cutoff) >> 5;
    key0 = *(s32 *)((u8 *)obj0->get() + 0x10);
    key1 = *(s32 *)((u8 *)obj1->get() + 0x10);
    tie0 = *(s32 *)((u8 *)obj0 + 0x74);
    tie1 = *(s32 *)((u8 *)obj1 + 0x74);
    if (flag0 != 0 && flag1 != 0) {
        f32 a = *(f32 *)((u8 *)obj0 + 0x70);
        f32 b = *(f32 *)((u8 *)obj1 + 0x70);
        f32 difference = (f32)(double)__fabsf(a - b);
        if (difference <= lbl_80558DC4) return 0;
        if (b < a) return 1;
        return -1;
    }
    if (flag0 != 0) goto compare_keys;
    if (flag1 == 0) goto compare_keys;
    if (flag0 == 0) return 1;
    return -1;
compare_keys:
    if (key0 == key1) return tie1 - tie0;
    return key1 - key0;
}
#pragma pop
#pragma scheduling on
#pragma cplusplus off
s32 fn_801B1310(s32 arg0) { return arg0 + 4; }

extern s32 fn_801B11DC(const void *, const void *);
extern void qsort(void *, unsigned long, unsigned long, s32 (*)(const void *, const void *));
#pragma dont_inline on
void fn_801B1318(void) {
    s32 i;
    s32 *p;
    qsort(lbl_80435C30, (unsigned long)lbl_8055E678, 4, fn_801B11DC);
    i = 0;
    p = lbl_80435C30;
    while (i < (s32)lbl_8055E678) {
        s32 value = *p;
        i++;
        *(s32 *)((u8 *)lbl_8055E684 + (value << 7) + 8) = i;
        p++;
    }
}
#pragma dont_inline reset

extern s32 fn_801B526C(void);
extern s32 fn_8026A344(void);
extern void fn_8026A248(s32, s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801B1390(s32 arg0, s32 arg1) {
    struct Dummy {
        virtual void d0();
        virtual void d1();
        virtual void *d2();
    };
    s32 count = fn_8026A344();
    if (fn_801B526C() != 0) {
        s32 index = ((s32)lbl_8055E678 + arg1 + count) % (s32)lbl_8055E678;
        fn_8026A248(index, arg0);
    } else {
        s32 index = 0;
        if (count >= 0 && count < (s32)lbl_8055E678) {
            Dummy *obj = (Dummy *)((u8 *)lbl_8055E684 + (count << 7));
            void *result = obj->d2();
            index = *(s32 *)((u8 *)result + 4) - 1;
        }
        index = ((s32)lbl_8055E678 + arg1 + index) % (s32)lbl_8055E678;
        fn_8026A248(lbl_80435C30[index], arg0);
    }
}
#pragma scheduling on
#pragma cplusplus off
void fn_801B14BC(s32 *arg0,s32 arg1,s32 arg2) {
    if(arg2){*arg0 |= arg1;return;}
    *arg0 &= ~arg1;
}

extern f32 lbl_805625F8;
extern double lbl_805625E8;
extern f32 lbl_805625FC;
extern s32 fn_801366C0(s32,s32,f32);
extern void fn_801B14BC(s32*,s32,s32);
extern s32 fn_8026A27C(s32);
extern void fn_801B1390(s32, s32);
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_801B14E4(void *arg0) {
    struct {
        u8 unk0[0x58];
        s32 field58;
        s32 field5C;
        u8 unk60[4];
        s32 count;
    } *base = (void *)arg0;
    register f32 threshold = lbl_805625F8;
    s32 passed;

    if (((s32 (*)(f32, s32, s32))fn_801366C0)(
            threshold,
            *(s32 *)((u8 *)arg0 + 0x58),
            base->field5C + 0x118)) {
        base->count += 1;
    } else {
        base->count = 0;
    }
    passed = (f32)base->count > lbl_805625FC;
    fn_801B14BC((s32 *)((u8 *)base + 4), 4, passed);
}
#pragma dont_inline reset
#pragma scheduling on
void fn_801B157C(void *arg0,s32 arg1) {
    *(u8*)((u8*)arg0+0x2C)=1;*(f32*)((u8*)arg0+0x30)=lbl_8055E3C8;
    if(lbl_8055E690)fn_801CB6B4(*(s32*)((u8*)arg0+0x60),arg1,2);
}

#pragma cplusplus on
#pragma use_lmw_stmw off
extern "C" void fn_801B179C(void *arg0, s32 arg1, s32 arg2) {
    struct Manager {
        virtual void d0();
        virtual void d1();
        virtual void *getFirst(s32);
        virtual void *getSecond(s32);
    };
    struct Target {
        virtual void d0();
        virtual void set(void *);
    };
    void *first;
    void *obj;
    void *second;
    void *value;
    s32 size = arg1 + 1;
    *(s32*)((u8*)arg0 + 0x60) = arg1;
    *(s32*)((u8*)arg0 + 0x5C) = arg2;
    *(s32*)((u8*)arg0 + 0x6C) = arg1;
    *(s32*)((u8*)arg0 + 8) = size;
    obj = fn_80156A40();
    first = fn_801284F8(0x68, lbl_80335B28);
    if (first != 0) {
        value = ((Manager *)obj)->getFirst(arg1);
        first = fn_80135DC4(first, 1, value);
    }
    *(void**)((u8*)arg0 + 0x58) = first;
    second = fn_801284F8(0x34, lbl_80335B3C);
    if (second != 0) second = fn_801352B8();
    *(void**)((u8*)arg0 + 0x3C) = second;
    *(void**)((u8*)second + 0x30) = *(void**)((u8*)arg0 + 0x58);
    value = ((Manager *)obj)->getSecond(arg1);
    ((Target *)*(void**)((u8*)arg0 + 0x3C))->set(value);
    if ((u32)(*(u32*)((u8*)arg2 + 0x10) + 0xAFBD0000U) == 0x4152U) {
        lbl_8055E67C += 1;
    }
}
#pragma use_lmw_stmw reset
#pragma cplusplus reset
extern void fn_80135F64(s32, f32 *, f32 *, s32, s32, void *, f32, f32, f32, f32, f32);
extern void fn_801353C8(s32, f32 *, f32 *, s32);
void fn_801B18B8(void *arg0, s32 arg1, s32 arg2) {
    f32 p0[5];
    f32 p1[2];
    f32 yBase;
    f32 scale;
    f32 secondY;
    f32 y;
    f32 xBase;
    void *obj;
    f32 originalZ;
    f32 zBase;
    f32 z;
    f32 secondX;
    f32 x;

    obj = *(void **)((u8 *)arg0 + 0x5C);
    scale = *(f32 *)((u8 *)obj + 0x5BC);
    x = *(f32 *)((u8 *)obj + 0x54) * scale;
    y = *(f32 *)((u8 *)obj + 0x5C) * scale;
    xBase = *(f32 *)((u8 *)obj + 0x94);
    yBase = *(f32 *)((u8 *)obj + 0x9C);
    originalZ = *(f32 *)((u8 *)obj + 0x58);
    x = xBase + x;
    zBase = *(f32 *)((u8 *)obj + 0x98);
    y = yBase + y;
    z = originalZ * scale;
    p0[0] = x;
    p0[1] = y;
    z = zBase + z;
    obj = *(void **)((u8 *)arg0 + 0x5C);
    p0[2] = x;
    secondX = *(f32 *)((u8 *)obj + 0x54);
    p0[3] = z;
    p1[0] = secondX;
    secondY = *(f32 *)((u8 *)obj + 0x5C);
    p0[4] = y;
    p1[1] = secondY;
    fn_80135F64(*(s32 *)((u8 *)arg0 + 0x58), p0, p1, arg1, arg2, obj, y, z, originalZ, x, scale);
    fn_801353C8(*(s32 *)((u8 *)arg0 + 0x3C), p0, p1, 0);
}

#pragma cplusplus on
extern "C" void fn_801B196C(s32 arg0, s32 arg1) {
    struct Manager {
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void *d3(s32);
        virtual void d4(s32, void *);
    };
    struct Object {
        virtual void d0();
        virtual void d1();
        virtual void d2(void *, f32 *, s32);
    };
    void *self = (void *)arg0;
    void *entity = *(void **)((u8 *)self + 0x5C);
    Manager *manager;
    Object *object;
    f32 *data;
    f32 scale, dx, dy, x, dz, y, z;
    f32 points[5];
    void *result;

    manager = (Manager *)fn_80156A40();
    manager->d4(*(s32 *)((u8 *)entity + 0x1EC), (u8 *)entity + 0x60);

    data = *(f32 **)((u8 *)self + 0x5C);
    scale = *(f32 *)((u8 *)data + 0x5BC);
    dx = *(f32 *)((u8 *)data + 0x54) * scale;
    dy = *(f32 *)((u8 *)data + 0x58) * scale;
    x = *(f32 *)((u8 *)data + 0x94) + dx;
    dz = *(f32 *)((u8 *)data + 0x5C) * scale;
    y = *(f32 *)((u8 *)data + 0x98) + dy;
    points[2] = x;
    z = *(f32 *)((u8 *)data + 0x9C) + dz;
    points[0] = x;
    points[3] = y;
    points[4] = z;
    points[1] = z;

    manager = (Manager *)fn_80156A40();
    result = manager->d3(*(s32 *)((u8 *)self + 0x60));
    object = *(Object **)((u8 *)self + 0x3C);
    object->d2(result, points, 0);

    object = *(Object **)((u8 *)self + 0x3C);
    *(s32 *)((u8 *)self + 0x4C) = *(s32 *)((u8 *)object + 4);
    *(f32 *)((u8 *)self + 0x50) = *(f32 *)((u8 *)object + 8);
    *(s32 *)((u8 *)self + 0x54) = *(s32 *)((u8 *)object + 0xC);
}
#pragma cplusplus reset

#pragma dont_inline reset

extern void *fn_80156A40(void);
extern void *fn_801284F8(s32, const char *);
extern void *fn_80135DC4(void *, s32, void *);
extern void *fn_801352B8(void);
extern char lbl_80335B28[], lbl_80335B3C[];
extern void fn_80135F4C(void *);
#pragma push
#pragma cplusplus on
extern "C" void fn_801B1A5C(void *arg0) {
    struct Manager {
        virtual void v0();
        virtual void v1();
        virtual void *getFirst(void *);
        virtual void *getSecond(void *);
    };
    struct Target {
        virtual void v0();
        virtual void set(void *);
    };
    Manager *manager = (Manager *)fn_80156A40();
    void *first = manager->getFirst(*(void **)((u8 *)arg0 + 0x60));
    Target *targetA = *(Target **)((u8 *)arg0 + 0x58);
    targetA->set(first);
    void *second = manager->getSecond(*(void **)((u8 *)arg0 + 0x60));
    Target *targetB = *(Target **)((u8 *)arg0 + 0x3C);
    targetB->set(second);

    fn_80135F4C(*(void **)((u8 *)arg0 + 0x58));
    *(s32 *)((u8 *)arg0 + 0x40) = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x58) + 4);
    *(f32 *)((u8 *)arg0 + 0x44) = *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x58) + 8);
    *(s32 *)((u8 *)arg0 + 0x48) = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0xC);
    *(s32 *)((u8 *)arg0 + 0x4C) = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x3C) + 4);
    *(f32 *)((u8 *)arg0 + 0x50) = *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x3C) + 8);
    *(s32 *)((u8 *)arg0 + 0x54) = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x3C) + 0xC);
}
#pragma cplusplus off
#pragma pop
M2C_UNK fn_801353C4(void *, f32 *);                 /* extern */
s32 fn_80136068(void *, f32 *, f32 *);              /* extern */
s32 fn_801363A0(void *);                            /* extern */
s32 fn_801B1130(s32);                               /* extern */
f32 fn_801B2F90(s32, s32);                          /* extern */
M2C_UNK memmove(void *, void *, s32);               /* extern */
extern s32 lbl_8055E3C4;
extern f32 lbl_80562608;
extern f32 lbl_8056260C;
#pragma push
#pragma scheduling invalid_target
void fn_801B1B30(void *arg0) {
    struct Stack {
        f32 sp8;
        u32 sp10;
        f32 sp14;
        s32 pad;
        f32 points[5];
    } stack;
    u8 *var_r4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f2;
    f32 temp_f31;
    f32 temp_f31_2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 temp_f6;
    f32 var_f2;
    f32 var_f31;
    s32 temp_r31;
    s32 temp_r3_4;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 var_r27;
    s32 var_r29;
    s32 var_r29_2;
    s32 var_r31;
    s32 var_r3;
    s32 var_r4;
    u32 var_ctr;
    void **temp_r28;
    void **temp_r3;
    u8 *temp_r27;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_5;
    void *temp_r3_6;
    void *temp_r3_9;
    void *temp_r4;
    void *temp_r4_2;
    void *object;
    void **vtable;

    temp_f31 = lbl_8055E3C8;
    temp_r4 = M2C_FIELD(arg0, void **, 0x5C);
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (temp_f31 - M2C_FIELD(arg0, f32 *, 0x70));
    temp_f6 = M2C_FIELD(temp_r4, f32 *, 0x5BC);
    temp_f2 = M2C_FIELD(temp_r4, f32 *, 0x54);
    temp_f0 = M2C_FIELD(temp_r4, f32 *, 0x58);
    temp_f1 = M2C_FIELD(temp_r4, f32 *, 0x5C);
    temp_f5 = temp_f2 * temp_f6;
    temp_f3 = temp_f0 * temp_f6;
    temp_f4 = M2C_FIELD(temp_r4, f32 *, 0x94);
    temp_f2 = M2C_FIELD(temp_r4, f32 *, 0x98);
    temp_f4 = temp_f4 + temp_f5;
    temp_f0 = M2C_FIELD(temp_r4, f32 *, 0x9C);
    temp_f1 = temp_f1 * temp_f6;
    temp_f2 = temp_f2 + temp_f3;
    temp_f0 = temp_f0 + temp_f1;
    stack.points[2] = temp_f4;
    stack.points[0] = temp_f4;
    stack.points[3] = temp_f2;
    stack.points[4] = temp_f0;
    stack.points[1] = temp_f0;
    temp_r3 = ((void *(*)(void *, f32, f32, f32, f32, f32, f32))fn_80156A40)(arg0, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5, temp_f6);
    vtable = *(void ***)temp_r3;
    temp_r3_2 = ((void *(*)(void *, s32))vtable[4])(temp_r3, M2C_FIELD(arg0, s32 *, 0x60));
    temp_r3_3 = M2C_FIELD(arg0, void **, 0x58);
    vtable = *(void ***)temp_r3_3;
    ((void (*)(void *, void *, f32 *, s32))vtable[4])(temp_r3_3, temp_r3_2, stack.points, 0);
    vtable = *(void ***)temp_r3;
    temp_r3_2 = ((void *(*)(void *, s32))vtable[5])(temp_r3, M2C_FIELD(arg0, s32 *, 0x60));
    temp_r3_3 = M2C_FIELD(arg0, void **, 0x3C);
    vtable = *(void ***)temp_r3_3;
    ((void (*)(void *, void *, f32 *, s32))vtable[4])(temp_r3_3, temp_r3_2, stack.points, 0);
    var_r29 = 0;
    if ((fn_801B1130(M2C_FIELD(arg0, s32 *, 0x60)) != 0) && ((s32) lbl_8055E692 == 0)) {
        var_r29 = 1;
    }
    stack.sp8 = lbl_805625BC;
    temp_r3_4 = fn_80136068(M2C_FIELD(arg0, void **, 0x58), stack.points, &stack.sp8);
    var_r31 = temp_r3_4;
    if ((var_r29 == 0) || ((s32) lbl_8055E692 != 0)) {
        if (temp_r3_4 == 0) {
            var_r31 = 2;
        } else if (temp_r3_4 == 1) {
            var_r31 = 3;
        }
    }
    if ((var_r31 == 2) || (var_r31 == 0)) {
        temp_r4_2 = M2C_FIELD(arg0, void **, 0x58);
        temp_r3_5 = M2C_FIELD(arg0, void **, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_r4_2, s32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) M2C_FIELD(temp_r4_2, f32 *, 8);
        M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(temp_r4_2, s32 *, 0xC);
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_r3_5, s32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(temp_r3_5, f32 *, 8);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(temp_r3_5, s32 *, 0xC);
    }
    fn_801353C4(M2C_FIELD(arg0, void **, 0x3C), stack.points);
    temp_r3_6 = M2C_FIELD(arg0, void **, 0x58);
    if ((s32) M2C_FIELD(temp_r3_6, u8 *, 0x64) != 0) {
        if ((s32) M2C_FIELD(arg0, u8 *, 0x78) == 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x60);
        }
    } else {
        temp_r3_7 = fn_801363A0((u8 *)temp_r3_6 + 4);
        if ((s32) M2C_FIELD(arg0, u8 *, 0x78) == 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = temp_r3_7;
        }
    }
    var_r4 = var_r31 == 0;
    if (((s32) lbl_8055E674 != 0) && ((u32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0x10) + 0xAFBD0000) == 0x4152U) && ((s32) lbl_8055E6A8 == 0) && !(lbl_8055E3C4 & 0x3F)) {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        var_r4_2 = (u8 *)lbl_80435BE8;
        temp_f1_2 = temp_f31 - stack.sp8;
        if ((u32) M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) < 8U) {
            stack.sp10 = M2C_FIELD(arg0, s32 *, 0x60);
            var_ctr = M2C_FIELD(&lbl_80435BE8, u32 *, 0x40);
            var_r3 = 0;
            stack.sp14 = temp_f1_2;
            if ((s32) M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) > 0) {
loop_25:
                if (!(M2C_FIELD(var_r4_2, f32 *, 4) > temp_f1_2)) {
                    var_r4_2 += 8;
                    var_r3 += 1;
                    var_ctr -= 1;
                    if (var_ctr != 0U) {
                        goto loop_25;
                    }
                }
            }
            temp_r27 = (u8 *)lbl_80435BE8 + (var_r3 * 8);
            memmove(temp_r27 + 8, temp_r27, (M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) - var_r3) * 8);
            M2C_FIELD(temp_r27, s32 *, 0) = stack.sp10;
            M2C_FIELD(temp_r27, f32 *, 4) = stack.sp14;
            M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) = (u32) (M2C_FIELD(&lbl_80435BE8, u32 *, 0x40) + 1);
        }
        if ((s32) M2C_FIELD(arg0, u8 *, 0x78) == 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = (s32) lbl_8055E688;
        }
    }
    if (var_r31 == 1) {
        temp_r3_8 = M2C_FIELD(arg0, s32 *, 0x14) - 1;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) (temp_r3_8 & ((s32) (-temp_r3_8 & ~temp_r3_8) >> 0x1F));
    }
    object = (void *)fn_801B83A0();
    vtable = *(void ***)object;
    if (((s32 (*)(void *))vtable[55])(object) != 0) {
        fn_801B14E4(arg0);
    }
    if (((s32) lbl_8055E67C > 1) && ((u32) (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void *(**)(void *), 0x20)(arg0), s32 *, 0x10) + 0xAFBD0000) == 0x4152U)) {
        var_f31 = lbl_805625BC;
        var_r27 = 0;
        var_r29_2 = 0;
        for (; var_r27 < (s32) lbl_8055E678; var_r29_2 += 0x80, var_r27++) {
        temp_r28 = (void **)((u8 *)lbl_8055E684 + var_r29_2);
        temp_r3_9 = M2C_FIELD(*temp_r28, void *(**)(void **), 0x20)(temp_r28);
        if ((var_r27 != (s32) M2C_FIELD(arg0, s32 *, 0x60)) && ((u32) (M2C_FIELD(temp_r3_9, s32 *, 0x10) + 0xAFBD0000) == 0x4152U)) {
            temp_r31 = M2C_FIELD(M2C_FIELD(*temp_r28, void *(**)(void **), 0x10)(temp_r28), s32 *, 4);
            if ((s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void *(**)(void *), 0x10)(arg0), s32 *, 4) > temp_r31) {
                temp_f1_3 = fn_801B2F90(var_r27, M2C_FIELD(arg0, s32 *, 0x60));
                if (var_f31 > temp_f1_3) {

                } else {
                    var_f31 = temp_f1_3;
                }
            }
        }
        }
        var_f2 = lbl_80562604;
        temp_f0_2 = (var_f31 - lbl_80562608) * lbl_8056260C;
        var_f2 = var_f2 < temp_f0_2 ? var_f2 : temp_f0_2;
        var_f2 = var_f2 > lbl_805625BC ? var_f2 : lbl_805625BC;
        temp_f1_4 = var_f2 * lbl_80562604;
        temp_f31_2 = lbl_805625BC + temp_f1_4;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void *(**)(void *), 0x20)(arg0), f32 *, 0x5EC) = temp_f31_2;
    }
}
#pragma pop
void fn_801B1FB4(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    *arg3 = 0;
    if (lbl_8055E68C == 0) {
        return;
    }
    ((void (*)(void *, s32, s32, s32, void *, s32 *))
        (*(void ***)lbl_8055E68C)[3])(
            lbl_8055E68C, arg1, arg2,
            *(s32 *)((u8 *)arg0 + 0x60), (u8 *)arg0 + 0x7C, arg3);
}

void fn_801B1FEC(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    void **vtable;
    *arg3 = 0;
    if (lbl_8055E68C == 0) return;
    vtable = *(void ***)lbl_8055E68C;
    ((void (*)(void *, s32, s32, s32, void *, s32 *))vtable[4])(
        lbl_8055E68C, arg1, arg2,
        *(s32 *)((u8 *)arg0 + 0x60), (u8 *)arg0 + 0x7C, arg3);
}

extern s32 fn_80139D4C(const char *);
extern void fn_80204A1C(const char *, u8 *);
extern s32 *fn_801769D8(u8);
extern s32 fn_8012850C(s32, void *);
extern void *fn_8002F37C(void *, void *, s32, s32);
extern void *fn_800081F0(void);
extern void *fn_801B83A0(void);
extern void *fn_8013C9F4(s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801B2024(void *arg0) {
    class InitObject {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
        virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
        virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
        virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
        virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
        virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
        virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
        virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
        virtual void *initialize();
    };
    register char *base = lbl_80335A58;
    u32 flags;
    u8 index;
    s32 count;
    s32 pool;
    void *result;
    lbl_8055E66C = fn_80139D4C(base + 0xF8);
    lbl_8055E670 = fn_80139D4C(base + 0x10C);
    fn_80204A1C(base + 0x120, &lbl_8055E692);
    flags = *(u32 *)((u8 *)arg0 + 4);
    index = (flags >> 8) & 1;
    lbl_8055E690 = index;
    lbl_8055E691 = (flags >> 9) & 1;
    count = *fn_801769D8(index);
    lbl_8055E678 = (void *)count;
    lbl_8055E67C = 0;
    pool = fn_8012850C((count << 7) + 0x10, base + 0x130);
    lbl_8055E684 =
        ((void *(*)(s32, void *(*)(void *), void (*)(void), s32, s32))fn_8002F37C)(
            pool, fn_801B21B8, fn_801B2118, 0x80, count);
    __AXFXGetLfoSinTable_801769CC();
    lbl_8055E680 = fn_800081F0();
    result = ((InitObject *)fn_801B83A0())->initialize();
    lbl_8055E68C = result;
    if (result == 0) {
        result = fn_8013C9F4(0);
        lbl_8055E68C = result;
    }
    lbl_8055E674 = 0;
}
#pragma scheduling on
#pragma cplusplus reset

void fn_801B2118(void) {}

void *fn_801B21B8(void *arg0) {
    register f32 value = lbl_805625BC;
    register s32 zero = 0;
    *(void **)arg0 = lbl_80335BFC;
    *(s32 *)((u8 *)arg0 + 0x40) = zero;
    *(s32 *)((u8 *)arg0 + 0x48) = 0x2710;
    *(f32 *)((u8 *)arg0 + 0x44) = value;
    *(s32 *)((u8 *)arg0 + 0x4C) = zero;
    *(s32 *)((u8 *)arg0 + 0x54) = 0x2710;
    *(f32 *)((u8 *)arg0 + 0x50) = value;
    memset((u8 *)arg0 + 4, zero, 0x38);
    *(s32 *)((u8 *)arg0 + 0x5C) = zero;
    *(f32 *)((u8 *)arg0 + 0x70) = lbl_805625BC;
    *(s32 *)((u8 *)arg0 + 0x60) = -1;
    *(s32 *)((u8 *)arg0 + 0x6C) = -1;
    *(s32 *)((u8 *)arg0 + 0x58) = zero;
    *(s32 *)((u8 *)arg0 + 0x3C) = zero;
    return arg0;
}

s32 fn_801B224C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern void fn_801B2118(void);
void fn_801B228C(void) {
    fn_8002F6AC(lbl_8055E684, fn_801B2118);
    lbl_8055E684 = 0;
    lbl_8055E678 = 0;
    if (lbl_8055E68C != 0) {
        if (lbl_8055E68C != 0) {
            ((void (*)(void *, s32))(*(void ***)lbl_8055E68C)[2])(lbl_8055E68C, 1);
        }
        lbl_8055E68C = 0;
    }
    if (lbl_8055E66C != 0) {
        fn_80139E18();
        lbl_8055E66C = 0;
    }
    if (lbl_8055E670 != 0) {
        fn_80139E18();
        lbl_8055E670 = 0;
    }
}

void fn_801B2320(void) {
    lbl_8055E688 = *(s32 *)((u8 *)*(void **)((u8 *)fn_80178C9C() + 0x2C) + 0x18);
}

void fn_801B234C(f32 farg0) {
    lbl_8055E6A4 = farg0;
    lbl_8055E6A0 = 1;
}

void fn_801B235C(void) {
    fn_801E89F4(3);
}

extern s32 lbl_8055E6A8;
extern f32 lbl_805625DC;
extern char lbl_80335B94[];
#pragma push
#pragma processor 750
void fn_801B2364(void) {
 f32 time;
 void *obj;
 s32 offset, i, state;
 s32 off, j;
 fn_801B146C();
 if(fn_801769F8()!=0) return;
 state=fn_801E89EC();
 time=lbl_8055E3C8;
 if(lbl_8055E6A0 && time>=lbl_8055E6A4) {
  if(state==0) {
   fn_801E89F4(1);
   for(i=0,offset=0;i<(s32)lbl_8055E678;offset+=0x80,i++) {
    obj=(u8*)lbl_8055E684+offset;
    fn_8018B0D0(*(s32*)((u8*)obj+0x5C),2);
    fn_801CB3AC(*(s32*)((u8*)obj+0x60));
   }
  }
  if(lbl_8055E6A8==1 && fn_800216D0()!=0) lbl_8055E6AC+=lbl_805625DC;
  if(lbl_8055E6A8==1 && time>lbl_8055E6AC) {
   fn_802E30C8(lbl_80335B94);
   lbl_8055E6A8=0;
   j=0; off=0;
   while(j<(s32)lbl_8055E678) {
    *(s32*)((u8*)lbl_8055E684+off+0x28)=lbl_8055E6A8;
    off+=0x80; j++;
   }
   if(lbl_8055E691) fn_801B84F8();
  }
 }
}
#pragma pop
extern void fn_801B15A8(s32, f32);
void fn_801B24B8(void) {
    struct Table {
        s32 entries[16];
        volatile s32 count;
    };
    register struct Table *table;
    register s32 value;
    register void *obj;
    register s32 *entry;
    register s32 i;
    register s32 newValue;
    register s32 index;
    register s32 *table2;
    register s32 j;

    if (fn_801769F8() != 0)
        return;
    entry = (s32 *)&lbl_80435BE8;
    table = (struct Table *)entry;
    i = 0;
    goto check_first;
first_loop:
    index = entry[0];
    value = *(volatile s32 *)&lbl_8055E688;
    obj = (u8 *)lbl_8055E684 + (index << 7);
    newValue = value - i + 9;
    if (*(u8 *)((u8 *)obj + 0x78) == 0)
        *(s32 *)((u8 *)obj + 0x74) = newValue;
    entry = (s32 *)((u8 *)entry + 8);
    i++;
check_first:
    if (i < table->count)
        goto first_loop;

    fn_801B1318();

    table2 = (s32 *)&lbl_80435BE8;
    j = 0;
    goto check_second;
second_loop:
    {
        s32 index2 = table->entries[0];
        f32 amount = *(f32 *)((u8 *)table + 4);
        obj = (u8 *)lbl_8055E684 + (index2 << 7);
        fn_801B15A8((s32)obj, amount);
    }
    table = (struct Table *)((u8 *)table + 8);
    j++;
check_second:
    if (j < *(volatile s32 *)((u8 *)table2 + 0x40))
        goto second_loop;

    *(volatile s32 *)((u8 *)table2 + 0x40) = 0;
    obj = lbl_8055E68C;
    if (obj != 0) {
#pragma cplusplus on
        struct Dummy {
            virtual void d0();
            virtual void d1();
            virtual void d2();
            virtual void d3();
            virtual void d4();
            virtual void d5();
            virtual void call();
        };
        ((Dummy *)obj)->call();
#pragma cplusplus reset
    }
}

#pragma push
#pragma processor 750
#pragma cplusplus on
extern "C" s32 fn_801B25B0(s32 *arg0, s32 *arg1) {
    struct First {
        virtual void v0();
        virtual void v1();
        virtual void *get(s32, void *);
    };
    struct Second {
        virtual void v0();
        virtual void v1();
        virtual void *get();
    };
    void *base = lbl_8055E684;
    Second *obj1 = (Second *)((u8 *)base + (*arg1 << 7));
    First *obj0 = (First *)((u8 *)base + (*arg0 << 7));
    void *result0 = obj0->get(*arg1, base);
    register f32 var_f31 = *(f32 *)((u8 *)result0 + 0x20);
    void *result1 = obj1->get();
    f32 var_f1 = *(f32 *)((u8 *)result1 + 0x20);

    if (var_f31 < lbl_80562604) var_f31 = lbl_80562610;
    if (var_f1 < lbl_80562604) var_f1 = lbl_80562610;
    if (var_f31 < var_f1) return -1;
    return var_f31 > var_f1;
}
#pragma cplusplus off
#pragma pop
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_80019B3C(void);
extern f32 fn_8013B650(int);
extern void fn_801B1A5C(void *);
extern f32 fn_801B88BC(void);
extern u8 lbl_8055E698;
extern s32 lbl_8055E69C;
extern u8 lbl_8055E6B0;
extern char lbl_80335BA8[];
extern void *lbl_8055A8C0;
extern f32 lbl_80562614;
extern s32 fn_801B25B0(s32 *, s32 *);
#pragma push
#pragma processor 750
void fn_801B265C(void) {
    s32 *stack;
    s32 i, j, k;
    s32 count = (s32)lbl_8055E678;
    void *base = lbl_8055E684;
    register f32 temp_f31;

    lbl_8055E6A8 = 1;
    if ((*(s32 *)((u8 *)__AXFXGetLfoSinTable_801769CC() + 0x10) & 1) || fn_80019B3C() != 0) {
        if (lbl_8055E6B0 == 0) {
            lbl_8055E6B0 = 1;
            fn_802E30C8(lbl_80335BA8, lbl_8055A8C0);
        }
        lbl_8055E6AC = lbl_8055E3C8 + lbl_80562614;
    } else {
        temp_f31 = lbl_8055E3C8;
        lbl_8055E6AC = fn_801B88BC() + temp_f31;
    }
    lbl_8055E698 = 0;
    lbl_8055E694 = 0;
    lbl_8055E6A4 = lbl_805625BC;
    lbl_8055E69C = 0;
    lbl_8055E6A0 = 0;
    memset(lbl_80435C30, -1, 0x20);
    {
        void *obj = fn_80156A40();
        void **vtable = *(void ***)obj;
        ((void (*)(void *))vtable[8])(obj);
    }
    i = 0;
    j = 0;
    while (i < count) {
        fn_801B1A5C((u8 *)base + j);
        j += 0x80;
        i++;
    }
    i = 0;
    j = 0;
    while (i < count) {
        void *obj = (u8 *)base + j;
        f32 value = lbl_805625F0;
        if (*(s32 *)((u8 *)obj + 0x5C + 0x1F0) == 0x51) {
            value = fn_8013B650(*(s32 *)((u8 *)obj + 0x60));
        }
        if (__fabsf(*(f32 *)((u8 *)obj + 0x5C + 0x254)) > lbl_80558DC4) {
            value = *(f32 *)((u8 *)obj + 0x5C + 0x254);
        }
        *(f32 *)((u8 *)obj + 0x24) = value;
        j += 0x80;
        i++;
    }
    stack = (s32 *)0;
    k = 0;
    if (count > 0) {
        s32 n = count - 8;
        if (count > 8) {
            if ((count & 7) == 0 && count <= 0x7FFFFFFE) {
                s32 m = (n + 7) >> 3;
                if (n > 0) {
                    do {
                        stack[k] = k;
                        stack[k + 1] = k + 1;
                        stack[k + 2] = k + 2;
                        stack[k + 3] = k + 3;
                        stack[k + 4] = k + 4;
                        stack[k + 5] = k + 5;
                        stack[k + 6] = k + 6;
                        stack[k + 7] = k + 7;
                        k += 8;
                        m--;
                    } while (m != 0);
                }
            }
        }
        if (k < count) {
            do {
                stack[k] = k;
                k++;
            } while (k < count);
        }
    }
    qsort(stack, (unsigned long)count, 4, (s32 (*)(const void *, const void *))fn_801B25B0);
    i = 0;
    j = 0;
    while (j < count) {
        *(s32 *)((u8 *)base + (stack[i] << 7) + 0x6C) = j;
        i++;
        j++;
    }
}
#pragma pop
void fn_801B2910(void) {
    register s32 var_r30;
    register s32 var_r31;
    register s32 var_r4;
    register s32 var_r6;
    register s32 var_r27;
    register s32 var_r28;
    register s32 var_r29;
    s32 i;
    s32 n;
    s32 *p;
    f32 f30;
    f32 f31;
    void *obj;
    void **vtable;

    lbl_8055E6A0 = 0;
    fn_801E89F4(0);
    *(s32 *)((u8 *)&lbl_80435BE8 + 0x40) = 0;
    var_r30 = 0;
    var_r31 = 0;
    while (var_r30 < (s32)lbl_8055E678) {
        obj = (u8 *)lbl_8055E684 + var_r31;
        vtable = *(void ***)obj;
        ((void (*)(void *))vtable[2])(obj);
        var_r31 += 0x80;
        var_r30++;
    }
    var_r4 = 0;
    if ((s32)lbl_8055E678 > 0) {
        n = (s32)lbl_8055E678 - 8;
        if ((s32)lbl_8055E678 > 8) {
            var_r6 = 0;
            if (((s32)lbl_8055E678 & 7) == 0 && (s32)lbl_8055E678 <= 0x7FFFFFFE) var_r6 = 1;
            if (var_r6 != 0) {
                s32 *src = (s32 *)lbl_8055E684;
                i = (n + 7) >> 3;
                if (n > 0) {
                    do {
                        lbl_80435C30[*(s32 *)((u8 *)src + 8) - 1] = var_r4;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x88) - 1] = var_r4 + 1;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x108) - 1] = var_r4 + 2;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x188) - 1] = var_r4 + 3;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x208) - 1] = var_r4 + 4;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x288) - 1] = var_r4 + 5;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x308) - 1] = var_r4 + 6;
                        lbl_80435C30[*(s32 *)((u8 *)src + 0x388) - 1] = var_r4 + 7;
                        src = (s32 *)((u8 *)src + 0x400);
                        var_r4 += 8;
                        i--;
                    } while (i != 0);
                }
            }
        }
        if (var_r4 < (s32)lbl_8055E678) {
            i = (s32)lbl_8055E678 - var_r4;
            do {
                obj = (u8 *)lbl_8055E684 + (var_r4 << 7);
                lbl_80435C30[*(s32 *)((u8 *)obj + 8) - 1] = var_r4;
                var_r4++;
                i--;
            } while (i != 0);
        }
    }
    if (lbl_8055E68C != 0) {
        vtable = *(void ***)lbl_8055E68C;
        ((void (*)(void *))vtable[8])(lbl_8055E68C);
    }
    fn_801B234C(lbl_80562618 + lbl_8055E3C8);
    if (__cntlzw(((s32)lbl_8055E678 - 1) << 27) != 31) {
        f31 = lbl_805625BC;
        f30 = lbl_805625BC;
    } else {
        f31 = -lbl_805625B8;
        f30 = lbl_805625B8;
    }
    p = lbl_80435C30;
    var_r29 = 0;
    var_r28 = 0;
    var_r27 = 0;
    while (var_r27 < (s32)lbl_8055E678) {
        obj = (u8 *)lbl_8055E684 + (*p << 7);
        vtable = *(void ***)obj;
        if (var_r27 & 1) {
            *(s32 *)((u8 *)obj + 0x34) = var_r29;
            *(f32 *)((u8 *)obj + 0x38) = f30;
            var_r29 = (s32)((void *(*)(void *))vtable[7])(obj);
        } else {
            *(s32 *)((u8 *)obj + 0x34) = var_r28;
            *(f32 *)((u8 *)obj + 0x38) = f31;
            var_r28 = (s32)((void *(*)(void *))vtable[7])(obj);
        }
        p++;
        var_r27++;
    }
    obj = fn_80156A40();
    vtable = *(void ***)obj;
    ((void (*)(void *))vtable[8])(obj);
}

#pragma scheduling invalid_target
void fn_801B2BE8(void *arg0) {
    s32 increment;
    f32 initial;
    s32 resource;

    memset((char *)arg0 + 4, 0, 0x38);
    increment = *(s32 *)((char *)arg0 + 0x6C);
    initial = lbl_805625BC;
    *(s32 *)((char *)arg0 + 8) = increment + 1;
    resource = *(s32 *)((char *)arg0 + 0x5C);
    *(s32 *)((char *)arg0 + 0x68) = 0;
    *(f32 *)((char *)arg0 + 0x70) = initial;
    *(s32 *)((char *)arg0 + 0x74) = 0;
    *(u8 *)((char *)arg0 + 0x78) = 0;
    *(u8 *)((char *)arg0 + 0x79) = 0;
    *(s32 *)((char *)arg0 + 0x7C) = 0;
    *(s32 *)((char *)arg0 + 0x64) = 0;
    fn_8018B0D0(resource, 0);
    fn_801CB360(*(s32 *)((char *)arg0 + 0x60));
    *(s32 *)((char *)arg0 + 0x28) = 1;
}
#pragma scheduling on
void fn_801B2C6C(void) {

}

#pragma scheduling invalid_target
s32 fn_801B2C70(void *arg0) {
    struct Entry {
        s32 unknown0;
        s32 value;
        s32 unknown8;
        u8 unknownC[4];
        u8 flag;
        u8 unknown11[3];
    } *entry;
    s32 i;
    s32 offset;
    s32 zero;
    s32 x;
    s32 y;
    s32 shifted;
    s32 mask;

    memset(arg0, 0, 0xB0);
    *(s32 *)arg0 = (s32)lbl_8055E678;
    *(s32 *)((u8 *)arg0 + 4) = lbl_8055E67C;
    zero = 0;
    *(u8 *)((u8 *)arg0 + 0xC) = zero;
    *(u8 *)((u8 *)arg0 + 0xD) = lbl_8055E698;

    x = lbl_8055E69C;
    y = lbl_8055E67C;
    x = x ^ y;
    shifted = x >> 1;
    mask = x & y;
    shifted = shifted - mask;
    *(u8 *)((u8 *)arg0 + 0xE) = (u32)shifted >> 31;

    entry = (struct Entry *)((u8 *)arg0 + 0x10);
    i = 0;
    offset = 0;
    while (i < (s32)lbl_8055E678) {
        i = i + 1;
        entry->value = *(s32 *)((u8 *)lbl_8055E684 + offset + 8);
        offset = offset + 0x80;
        entry->unknown8 = zero;
        entry->flag = zero;
        entry++;
    }
    return 1;
}
#pragma scheduling on
void *fn_801B2EC0(s32 arg0) {
    return (void *)((u8 *)lbl_8055E684 + (arg0 << 7));
}
#pragma dont_inline reset

#pragma dont_inline on
void *fn_801B2ED0(s32 arg0) {
    return fn_801B2EC0(arg0);
}
#pragma dont_inline reset

void* fn_801B2ED4(void) {
    return lbl_8055E680;
}

s32 fn_801B2EDC(s32 arg0, s32 arg1) {
    void *var_r31;
    
    var_r31 = (void *)((u8 *)lbl_8055E684 + (arg0 << 7));
    fn_801B179C(var_r31, arg0, arg1);
    return (s32)var_r31;
}

void* fn_801B2F24(void) {
    return lbl_8055E678;
}

u8 fn_801B2F2C(s32 arg0) {
    return ((u8 *)lbl_8055E684)[(arg0 << 7) + 0x79];
}

s32 fn_801B2F40(s32 arg0) {
    return lbl_80435C30[arg0];
}

typedef void (*VFnPtr)(void *);
s32 fn_801B2F54(s32 arg0) {
    register void **base = (void **)lbl_8055E684;
    void *obj = &base[arg0 * 32];
    void *result = ((void *(*)(void *))((void ***)base)[arg0 * 32][4])(obj);
    return *(s32 *)((u8 *)result + 0x10);
}

extern f32 lbl_8056261C;
extern f32 fn_801365C4(void *, void *);
extern double __fabs(double);
#pragma scheduling invalid_target
f32 fn_801B2F90(s32 arg0, s32 arg1) {
    void *base = lbl_8055E684;
    void *obj0 = (u8 *)base + (arg0 << 7);
    void *obj1 = (u8 *)base + (arg1 << 7);
    void *first;
    void *second;
    s32 difference;

    if (*(s32 *)((u8 *)obj0 + 8) - 1 < *(s32 *)((u8 *)obj1 + 8) - 1) {
        first = obj0;
        second = obj1;
    } else {
        first = obj1;
        second = obj0;
    }
    difference = (*(s32 *)((u8 *)first + 0x14) -
                  *(s32 *)((u8 *)second + 0x14)) -
                 ((u32)*(u32 *)((u8 *)first + 0x74) <
                  (u32)*(u32 *)((u8 *)second + 0x74));
    if (difference != 0)
        return lbl_8056261C * (f32)difference;
    {
        double magnitude = __fabs((f64)fn_801365C4(*(void **)((u8 *)second + 0x58),
                                                  *(void **)((u8 *)first + 0x58)));
        return (f32)magnitude;
    }
}
#pragma scheduling on
s32 fn_801B3050(s32 arg0) {
    return *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x6C);
}

extern f32 fn_801B3064(void);
f32 fn_801B3064(void) {
    return lbl_8055E6A4;
}

extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
f32 fn_801B306C(void) {
    register f32 a = lbl_8055E3C8;
    return lbl_8055E6AC - a;
}

void* fn_801B307C(void) {
    return lbl_8055E694;
}

#pragma push
#pragma scheduling invalid_target
void fn_801B3084(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    void *obj = lbl_8055E68C;
    if (obj != NULL) {
        s32 a = *(s32 *)((u8 *)arg0 + 0x1EC);
        s32 b = *(s32 *)((u8 *)arg1 + 0x1EC);
        void **vtable = *(void ***)obj;
        ((void (*)(void *, s32, s32, s32, s32))vtable[6])(obj, a, b, arg2, arg3);
    }
}
#pragma pop
extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
#pragma dont_inline on
void fn_801B30C0(s32 arg0, s32 arg1, s32 arg2) {
    fn_801B18B8((void *)((u8 *)lbl_8055E684 + (arg0 << 7)), arg1, arg2);
}
#pragma dont_inline reset
void fn_801B30D0(s32 arg0) {
    fn_801B196C((s32)((u8 *)lbl_8055E684 + (arg0 << 7)), (s32)lbl_8055E684);
}

#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801B30E0(s32 index) {
    void *record = (u8 *)lbl_8055E684 + (index << 7);
    void *header = ((Dummy_801B30E0 *)record)->d5();
    void *reference = *(void **)((u8 *)record + 0x40);
    void *bestNode;
    if (reference != 0) {
        s32 bestDiff = 0x7FFFFFFF;
        s32 referenceValue = *(s32 *)((u8 *)reference + 0x10);
        void *parent = *(void **)((u8 *)header + 0x2C);
        void *first = *(void **)((u8 *)parent + 0x1C);
        void *node = first;
        bestNode = 0;
        do {
            s32 difference = *(s32 *)((u8 *)node + 0x10) - referenceValue;
            s32 sign = difference >> 31;
            difference = (difference ^ sign) - sign;
            if (difference < bestDiff) {
                bestDiff = difference;
                bestNode = node;
            }
            node = *(void **)((u8 *)node + 0x14);
        } while (node != first);
    } else {
        bestNode = 0;
    }
    {
        void *data = ((Dummy_801B30E0 *)record)->d6();
        f32 scale = *(f32 *)((u8 *)data + 0x5BC);
        f32 scaleX = *(f32 *)((u8 *)data + 0x54) * scale;
        f32 scaleZ = *(f32 *)((u8 *)data + 0x5C) * scale;
        f32 scaleY = *(f32 *)((u8 *)data + 0x58) * scale;
        f32 x = *(f32 *)((u8 *)data + 0x94) + scaleX;
        f32 y = *(f32 *)((u8 *)data + 0x98) + scaleY;
        f32 z = *(f32 *)((u8 *)data + 0x9C) + scaleZ;
        f32 slots[5];
        slots[2] = x;
        slots[3] = y;
        slots[4] = z;
        slots[0] = x;
        slots[1] = z;
        ((void (*)(void *, f32 *, s32, void *, f32, f32, f32, f32, f32, f32))fn_801353C8)(
            header, slots, 0, bestNode, scaleZ, y, scaleY, x, scaleX, scale);
    }
}
#pragma cplusplus off
#pragma scheduling on

#pragma push
#pragma processor 750
void fn_801B3208(s32 arg0, s32 arg1, f32 farg0) {
    fn_802E317C(lbl_80335BD8, arg0, arg1);
    *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x6C) = arg1;
    *(f32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x24) = farg0;
}
#pragma pop
s32 fn_801B327C(void) { return 0; }

void fn_801B3284(void) {

}

u8 fn_801B3288(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

u32 fn_801B3290(void) { return 1; }

void fn_801B3298(void) {

}
#pragma cplusplus on
struct D801B0C78 { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void *h(); virtual void *i(); };
#pragma cplusplus off
