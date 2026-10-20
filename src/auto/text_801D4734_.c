// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

#pragma cplusplus on
class TObj34 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10();
    virtual void v34();
};
#pragma cplusplus reset

extern void fn_801D59C8(s32, s32);

extern char lbl_803385D0[];
extern char lbl_803388F0[];
extern char lbl_8033890C[];
extern s32 lbl_8055E3C4;
extern f32 lbl_8055E3C8;
extern u8 lbl_804422F0[];
extern f32 lbl_80562B04;
extern f32 lbl_80562AE4;
s32 fn_801E1F78(void);
extern f32 lbl_80562AE0;
extern f32 lbl_80562AEC;
extern char lbl_80338C40[];
extern char lbl_803387A8[];

typedef struct {
    char *name;
    s32 state;
} UnkStruct_801D6618;

extern char lbl_80338F50[];
extern char lbl_80338CB0[];
extern char lbl_80338C78[];
extern char lbl_80338D20[];
extern f32 lbl_80442310[];
void fn_80128658(s32);

extern u8 lbl_80338460[];
extern s8 lbl_8055E954;
extern f32 lbl_80562AD8;
void *fn_802077A4(void *, s32, void *, void *);
void fn_801D5520();
s32 *__AXFXGetLfoSinTable_801769CC(void);
void *fn_8001285C(s32);
void fn_801D56C0(void *);
void fn_801D5730(void);
void fn_801D4734(void) {
    register u8 *base;
    register u8 *config asm("r4");
    void *obj;
    void *manager;
    base = lbl_80338460;
    config = lbl_804422F0;
    lbl_8055E954 = 1;
    obj = fn_802077A4(base, 5, config + 8, config + 0x14);
    *(void **)config = obj;
    if (obj != 0) *(f32 *)((u8 *)obj + 0x6C) = lbl_80562AD8;
    fn_801D5520(base + 0xC);
    manager = fn_8001285C(*__AXFXGetLfoSinTable_801769CC());
    manager = *(void **)((u8 *)manager + 0x20);
    if (((s32 (**)(void *, void *))(*(void ***)manager))[3](manager, base + 0x18) != 0) {
        ((void (**)(void *, void *))(*(void ***)manager))[5](manager, base + 0x18);
        fn_801D5520();
    }
}

extern void *lbl_804423A4[];
s32 fn_801D5650(void *);

void fn_801D47F4(void) {
    fn_801D57F0();
}

void fn_801D47F8(void* alarm) {
    fn_801D5488(fn_801D5650(alarm));
}

void fn_801D483C(void) {
    void *obj;
    lbl_8055E954 = 0;
    obj = *(void **)lbl_804422F0;
    if (obj != 0)
        ((void (**)(void *, s32))*(void ***)obj)[2](obj, 1);
    fn_801D5730();
}

void fn_801D4888(void) {
    fn_801D5860();
}

void fn_801D48F4(void) {
    fn_801D58DC();
}

void fn_801D48F8(void) {
    fn_801D592C();
}

void fn_801D5A14(s32 arg0);
void fn_801D48FC(s32 arg0) {
    fn_801D5A14(arg0);
}

void fn_801D5A14(s32 arg0);
void fn_801D5A1C(s32 arg0);
void fn_801D5A24(s32 arg0);
s32 fn_801D5A2C();
void fn_801D4900(s32 arg0) {
    fn_801D5A1C(arg0);
}

void fn_801D4904(s32 arg0) {
    fn_801D5A24(arg0);
}

s32 fn_801D4908(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return fn_801D5A2C(arg0, arg1, arg2, arg3);
}

s32 fn_801D4CB8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern void fn_801D50B8(s32);
extern f32 lbl_80562B00;
extern char lbl_80338D80[];
#pragma push
#pragma use_lmw_stmw off
void fn_801D4F2C(void *arg0) {
    s32 offset;
    s32 i;
    void *obj;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x34)) {
        obj = *(void **)(*(u8 **)((u8 *)arg0 + 0x30) + offset);
        ((void (**)(void *))*(void **)obj)[4](obj);
        offset += 4;
        i += 1;
    }
}
#pragma pop
void fn_801D4F9C(void) {
}

#pragma scheduling reset
void fn_801D4FA0(void *arg0) {
    s32 offset;
    s32 i;
    void *obj;
    void **vtable;
    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x34)) {
        obj = *(void **)(*(u8 **)((u8 *)arg0 + 0x30) + offset);
        vtable = *(void ***)obj;
        ((void (*)(void *))vtable[10])(obj);
        offset += 4;
        i += 1;
    }
}
void fn_801D5010(void) {
}

#pragma push
#pragma use_lmw_stmw off
s32 fn_801D5014(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 offset;
    s32 i;
    void *obj;

    i = 0;
    offset = 0;
    while (i < *(s32 *)((u8 *)arg0 + 0x34)) {
        obj = *(void **)(*(u8 **)((u8 *)arg0 + 0x30) + offset);
        if (((s32 (**)(void *, s32, s32))*(void **)obj)[8](obj, arg1, arg2) != 0) {
            return 1;
        }
        offset += 4;
        i += 1;
    }
    return 0;
}
#pragma pop
s32 fn_801D50A0(void) { return 0; }

void fn_801D5328(s32, s32);
void fn_801D50A8(s32 arg0) { fn_801D5328(arg0, 1); }

    void fn_801D50B0(s32 arg0) {
    fn_801D5328(arg0, 0);
}

#pragma scheduling on
void fn_801D52A4(void *arg0) {
    s32 offset;
    s32 i;
    void *obj;
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        i = 0;
        offset = 0;
        while (i < *(s32 *)((u8 *)arg0 + 0x34)) {
            obj = *(void **)(*(u8 **)((u8 *)arg0 + 0x30) + offset);
            ((void (**)(void *))*(void **)obj)[13](obj);
            offset += 4;
            i += 1;
        }
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}
#pragma scheduling reset
s32 fn_801D544C(void) { return 0; }

#pragma scheduling reset

extern u8 lbl_804422F0[];
extern f32 lbl_80562B04;
void fn_801D5454(void *arg0) {
    f32 x;
    f32 y;
    f32 z;
    f32 old;

    x = *(f32 *)arg0;
    old = *(f32 *)(lbl_804422F0 + 4);
    y = *(f32 *)((u8 *)arg0 + 4);
    *(f32 *)(lbl_804422F0 + 4) = old + lbl_80562B04;
    z = *(f32 *)((u8 *)arg0 + 8);
    *(f32 *)(lbl_804422F0 + 0x14) = x;
    *(f32 *)(lbl_804422F0 + 0x18) = y;
    *(f32 *)(lbl_804422F0 + 0x1C) = z;
}

s32 fn_801D5650(void *alarm) {
    s32 offset;
    s32 i;
    s32 count;
    offset = 0;
    i = 0;
    while (i < (count = *(s32 *)((u8 *)lbl_804423A4 + 4))) {
        fn_801D50B8(*(s32 *)((u8 *)lbl_804423A4[0] + offset));
        offset += 4;
        i += 1;
    }
}
#pragma scheduling on
extern void *lbl_804423A4[];
extern f32 lbl_80562ADC, lbl_80562AE0, lbl_80562B08;
void fn_801D5730(void) {
    s32 count, index, i; void *p;
    count = *(s32 *)((u8 *)lbl_804423A4 + 4); index = count * 4; i = count;
    while (i > 0) {
        i--; index -= 4; p = *(void **)((u8 *)lbl_804423A4[0] + index); fn_801D4F2C(p);
        if (i >= 0 && i < *(s32 *)((u8 *)lbl_804423A4 + 4)) {
            count = *(s32 *)((u8 *)lbl_804423A4 + 4);
            if (i != count - 1) *(void **)((u8 *)lbl_804423A4[0] + index) = *(void **)((u8 *)lbl_804423A4[0] + count * 4 - 4);
            *(s32 *)((u8 *)lbl_804423A4 + 4) = count - 1;
        }
        if (p != 0) ((void (**)(void *, s32))*(void **)p)[2](p, 1);
    }
}

void fn_801D5A14(s32 arg0) {
    fn_801D59C8(arg0, 2);
}

void fn_801D5A1C(s32 arg0) {
    fn_801D59C8(arg0, 1);
}

void fn_801D5A24(s32 arg0) {
    fn_801D59C8(arg0, 4);
}

#pragma dont_inline on
#pragma scheduling invalid_target
s32 fn_801D5A2C(void *arg0, s32 arg1, s32 arg2) {
    void **entries = (void **)lbl_804423A4[0];
    s32 count = *(s32 *)((u8 *)lbl_804423A4 + 4);
    s32 i;

    for (i = 0; i < count; i++) {
        if (entries[i] == arg0) {
            return ((s32 (*)(void *, s32, s32))fn_801D5014)(arg0, arg1, arg2);
        }
    }
    return 0;
}
#pragma scheduling on
#pragma dont_inline reset
u8 fn_801D5A68(void *arg0) {
    void **entries = lbl_804423A4[0];
    s32 count = *(s32 *)((u8 *)lbl_804423A4 + 4);
    s32 i;
    for (i = 0; i < count; i++) {
        if (entries[i] == arg0) {
            return *((u8 *)arg0 + 0x22);
        }
    }
    return 0;
}

void fn_801D5AA8(void *arg0) {
    *(void **)((u8 *)arg0 + 0) = lbl_80338D20;
    *(void **)((u8 *)arg0 + 4) = lbl_80338D20 + 0x38;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(void **)((u8 *)arg0 + 0x10) = (u8 *)arg0 + 0x1C;
    *(s32 *)((u8 *)arg0 + 0x18) = 4;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(void **)((u8 *)arg0 + 0x70) = (u8 *)arg0 + 0x7C;
    *(s32 *)((u8 *)arg0 + 0x78) = 0x40;
    *(s32 *)((u8 *)arg0 + 0x74) = 0;
}

extern void fn_801D0824(void *);
void fn_801D5AF0(void *arg0, s32 arg1) {
    s32 field8;
    if (arg0 != NULL) {
        field8 = *(s32 *)((u8 *)arg0 + 8);
        *(void **)((u8 *)arg0 + 0) = lbl_80338D20;
        *(void **)((u8 *)arg0 + 4) = lbl_80338D20 + 0x38;
        if (field8 != 0) {
            *(s32 *)((u8 *)arg0 + 8) = 0;
            fn_801D0824((u8 *)arg0 + 4);
            *(s32 *)((u8 *)arg0 + 0xC) = -1;
        }
        *(s32 *)((u8 *)arg0 + 0x70) = 0;
        *(s32 *)((u8 *)arg0 + 0x74) = 0;
        *(s32 *)((u8 *)arg0 + 0x78) = 0;
        *(s32 *)((u8 *)arg0 + 0x10) = 0;
        *(s32 *)((u8 *)arg0 + 0x14) = 0;
        *(s32 *)((u8 *)arg0 + 0x18) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
}

extern f32 lbl_80558DC4;
extern f32 fn_80129DC4(s32, f32, f32);
extern f32 PSVECDotProduct(void *, void *);
extern void PSVECNormalize(void *, void *);
s32 fn_801D5E94(void *arg0) {
    u8 *self = arg0;
    f32 p[3], v[3], t, dy, zero;
    s32 i, offset;
    if (*(s32 *)(self + 8) != 1) return 0;
    zero = lbl_80562ADC; i = 0; offset = 0;
    do {
        f32 scale = fn_80129DC4(4, lbl_80562ADC, lbl_80562AE0);
        f32 amount = fn_80129DC4(4, lbl_80562ADC, lbl_80562AE0);
        p[0] = *(f32 *)(self + 0x3C) + amount * (*(f32 *)(self + 0x48) - *(f32 *)(self + 0x3C));
        p[1] = *(f32 *)(self + 0x40) + amount * (*(f32 *)(self + 0x4C) - *(f32 *)(self + 0x40));
        p[2] = *(f32 *)(self + 0x44) + amount * (*(f32 *)(self + 0x50) - *(f32 *)(self + 0x44));
        v[0] = zero; v[1] = zero; v[2] = zero;
        dy = *(f32 *)(self + 0x64) - *(f32 *)(self + 0x60);
        t = *(f32 *)(self + 0x60) + scale * dy;
        if (fabsf(PSVECDotProduct(p, v)) <= lbl_80558DC4 || fabsf(t) <= lbl_80558DC4) {
            void *obj = *(void **)(*(u8 **)(self + 0x70) + offset);
            ((void (**)(void *, s32))*(void **)obj)[8](obj, 1);
        } else {
            void *obj;
            PSVECNormalize(p, p);
            v[0] = p[0] * t; v[1] = p[1] * t; v[2] = p[2] * t;
            obj = *(void **)(*(u8 **)(self + 0x70) + offset);
            ((void (**)(void *, void *, void *))*(void **)obj)[9](obj, v, self + 0x54);
        }
        offset += 4; i += 1;
    } while (i < *(s32 *)(self + 0x74));
    if (*(s32 *)(self + 0x68) > 0) {
        *(s32 *)(self + 8) = 2;
        *(s32 *)(self + 0x6C) = lbl_8055E3C4;
    } else *(s32 *)(self + 8) = 3;
    return 1;
}

#pragma scheduling off
void fn_801D6080(void *arg0) {
    s32 *p = (s32 *)arg0;
    s32 offset;
    s32 count;
    void *obj;

    if (p[2] == 2 && lbl_8055E3C4 - p[0x1B] >= p[0x1A]) {
        count = 0;
        offset = 0;
        while (count < p[0x1D]) {
            obj = *(void **)((u8 *)p[0x1C] + offset);
            ((void (**)(void *))*(void **)obj)[11](obj);
            offset += 4;
            count++;
        }
        p[2] = 3;
    }
}
#pragma scheduling on
void fn_801D628C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(void **)((u8 *)arg0 + 0) = lbl_80338C78;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
}

#pragma scheduling on
void *fn_801D62A8(void *arg0, s32 arg1) {
    volatile s32 temp_r5;
    if (arg0 != NULL) {
        temp_r5 = *(s32 *)((u8 *)arg0 + 0x14);
        *(volatile void **)arg0 = lbl_80338C78;
        *(volatile s32 *)((u8 *)arg0 + 4) = 0;
        if (temp_r5 != 0) fn_80128658(temp_r5);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling reset
void *__AXFXGetLfoSinTable_801D64F4(void) {
    return lbl_803387A8;
}

s32 fn_801D6500(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D6508(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x1C) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void fn_801D6600(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

extern char lbl_803387A8[];
extern char lbl_803387C8[];
#pragma scheduling invalid_target
void fn_801D6618(UnkStruct_801D6618 *arg0) {
    arg0->name = lbl_80338C40;
    arg0->state = 0;
}
#pragma scheduling on
void *fn_801D6630(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void *fn_801D67D4(void) {
    return lbl_803387C8;
}

s32 fn_801D67E0(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D67E8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void fn_801E9DC4(void *);
void fn_801796CC(s32, void *, s32);
void fn_801D6814(void *arg0) {
    struct { f32 values[6]; s32 unk18; volatile s32 unk1C; } data;
    s32 elapsed = lbl_8055E3C4 - (*(s32 *)((u8 *)arg0 + 0x10) + *(s32 *)((u8 *)arg0 + 0xC));
    if (*(s32 *)((u8 *)arg0 + 4) == 2 && elapsed > 0) {
        data.values[0] = *(f32 *)((u8 *)arg0 + 0x14);
        data.values[1] = *(f32 *)((u8 *)arg0 + 0x18);
        data.values[2] = *(f32 *)((u8 *)arg0 + 0x1C);
        data.values[3] = *(f32 *)((u8 *)arg0 + 0x20);
        data.values[4] = *(f32 *)((u8 *)arg0 + 0x24);
        data.values[5] = *(f32 *)((u8 *)arg0 + 0x28);
        fn_801E9DC4(&data.unk18);
        data.unk1C = *(s32 *)((u8 *)arg0 + 0x2C);
        fn_801796CC(10, data.values, (data.unk1C, 0x20));
        if (elapsed >= *(s32 *)((u8 *)arg0 + 8))
            *(s32 *)((u8 *)arg0 + 4) = 3;
    }
}

void fn_801D68D0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

extern char lbl_80338BD0[];
void fn_801D68E8(UnkStruct_801D6618 *arg0) {
    arg0->name = lbl_80338BD0;
    arg0->state = 0;
}

void *fn_801D6900(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void fn_801D6BD0(void *arg0) {
    if (*(void **)((u8 *)arg0 + 0x30) != NULL) {
        if (*(void **)((u8 *)arg0 + 0x30) != NULL) {
            void *obj = *(void **)((u8 *)arg0 + 0x30);
            ((void (**)(void *, s32))*(void **)obj)[2](obj, 1);
        }
    }
    *(void **)((u8 *)arg0 + 0x30) = NULL;
}

extern u8 lbl_80338868[];
void *fn_801D6C28(void) {
    return lbl_80338868;
}

s32 fn_801D6C34(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D6C3C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void fn_801D6C68(void *arg0) {
    s32 remaining;
    void *obj;
    f32 value;
    remaining = lbl_8055E3C4 - (*(s32 *)((u8 *)arg0 + 0x10) + *(s32 *)((u8 *)arg0 + 0xC));
    if (*(s32 *)((u8 *)arg0 + 4) != 2) return;
    if (remaining <= 0) return;
    if (*(u8 *)((u8 *)arg0 + 0x16) != 0) {
        obj = *(void **)((u8 *)arg0 + 0x30);
        value = lbl_80562AE0;
        if (value != *(f32 *)((u8 *)obj + 8)) {
            *(u8 *)((u8 *)obj + 0x4D) = 1;
            *(f32 *)((u8 *)obj + 8) = value;
        }
    }
    if (*(u8 *)((u8 *)arg0 + 0x15) != 0) {
        obj = *(void **)((u8 *)arg0 + 0x30);
        *(u8 *)((u8 *)obj + 0x4A) = 0;
        *(u8 *)((u8 *)obj + 0x4B) = 1;
        *(u8 *)((u8 *)obj + 0x49) = 1;
        if (remaining >= *(s32 *)((u8 *)arg0 + 8)) {
            obj = *(void **)((u8 *)arg0 + 0x30);
            *(s32 *)((u8 *)arg0 + 4) = 3;
            *(u8 *)((u8 *)obj + 0x4A) = 1;
            *(u8 *)((u8 *)obj + 0x4C) = 0;
        }
    } else {
        obj = *(void **)((u8 *)arg0 + 0x30);
        *(volatile u8 *)((u8 *)obj + 0x49) = 1;
        *(volatile u8 *)((u8 *)obj + 0x4B) = 0;
        *(volatile u8 *)((u8 *)obj + 0x4A) = 0;
        *(s32 *)((u8 *)arg0 + 4) = 3;
    }
}

void fn_801D6D28(void *arg0) {
    register void *obj;
    obj = *(void **)((u8 *)arg0 + 0x30);
    if (obj != NULL && *(u8 *)((u8 *)obj + 0x19) != 0) {
        *(u8 *)((u8 *)obj + 0x4A) = 1;
        *(u8 *)((u8 *)obj + 0x4C) = 0;
    }
    if (*(s32 *)((u8 *)arg0 + 4) != 0) *(s32 *)((u8 *)arg0 + 4) = 1;
}

extern char lbl_80338B98[];
void fn_801D6D68(UnkStruct_801D6618 *arg0) {
    arg0->name = lbl_80338B98;
    arg0->state = 0;
}

void *fn_801D6D80(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern u8 lbl_80338878[];
void *fn_801D6ED0(void) {
    return lbl_80338878;
}

s32 fn_801D6EDC(void *arg0) {
    return ((s32 *)arg0)[1];
}

#pragma no_unroll
s32 fn_801D6EE4(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        u8 *src;
        u8 *dst;
        s32 i;

        *(f32 *)lbl_80442310 = lbl_8055E3C8;
        *(f32 *)((u8 *)lbl_80442310 + 4) = *(f32 *)((u8 *)arg0 + 8);

        src = (u8 *)arg0 + 0xC;
        dst = (u8 *)lbl_80442310 + 0x48;
        for (i = 0x40; i > 0; i--) {
            *dst = *src;
            src += 1;
            dst += 1;
            if (*(s8 *)(dst - 1) == 0) break;
        }
        if (i <= 0) *(u8 *)(dst - 1) = 0;

        src = (u8 *)arg0 + 0x4C;
        dst = (u8 *)lbl_80442310 + 8;
        for (i = 0x40; i > 0; i--) {
            *dst = *src;
            src += 1;
            dst += 1;
            if (*(s8 *)(dst - 1) == 0) break;
        }
        if (i <= 0) *(u8 *)(dst - 1) = 0;

        *(s32 *)((u8 *)arg0 + 4) = 3;
        return 1;
    }
    return 0;
}
#pragma no_unroll off
extern f32 lbl_80442310[];
extern s32 fn_8016A15C(void *);

void fn_801D6FA0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

void fn_801D6FB8(void *arg0) {
    if (*(u8 *)((u8 *)arg0 + 0x34) == 0) {
        if (fn_8016A15C((u8 *)arg0 + 8) != 0) {
            void *p = *(void **)((u8 *)arg0 + 0x38);
            *(u8 *)((u8 *)p + 0x49) = 1;
            *(u8 *)((u8 *)p + 0x4B) = 0;
            *(u8 *)((u8 *)p + 0x4A) = 0;
        }
        *(u8 *)((u8 *)arg0 + 0x34) = 1;
    }
}

extern char lbl_80338B08[];
void fn_801D701C(UnkStruct_801D6618 *arg0) {
    arg0->name = lbl_80338B08;
    arg0->state = 0;
}

void *fn_801D7034(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern f32 lbl_80442310[];
void fn_801D71A8(void *arg0) {
    void *obj = *(void **)((u8 *)arg0 + 0x38);
    if (obj != 0 && obj != 0) {
        void *vptr;
        obj = obj;
        vptr = *(void **)obj;
        ((void (**)(void *, s32))vptr)[2](obj, 1);
    }
    *(void **)((u8 *)arg0 + 0x38) = 0;
}
#pragma scheduling reset
extern u8 lbl_803388D4[];
void *fn_801D7200(void) {
    return lbl_803388D4;
}

s32 fn_801D720C(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D7214(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 4) = 2;
        *(f32 *)((u8 *)arg0 + 0x2C) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

extern f32 lbl_8055E3C8;
extern f32 lbl_80562ADC;
void fn_8016A240(void *);
void fn_801D6FB8(void *);
void fn_801D7240(void *arg0) {
    f32 f2;
    f32 f1;
    if (*(s32 *)((u8 *)arg0 + 4) == 2) {
        f2 = *(f32 *)((u8 *)arg0 + 0x30);
        if (f2 < lbl_80562ADC) {
            fn_801D6FB8(arg0);
            *(s32 *)((u8 *)arg0 + 4) = 3;
        } else {
            f1 = *(f32 *)((u8 *)arg0 + 0x2C);
            f1 += *(f32 *)((u8 *)arg0 + 0x28);
            if (f2 + f1 < lbl_8055E3C8) {
                fn_8016A240((u8 *)arg0 + 8);
                *(s32 *)((u8 *)arg0 + 4) = 3;
            } else if (f1 < lbl_8055E3C8) {
                fn_801D6FB8(arg0);
            }
        }
    }
}

void fn_801D72D0(void *arg0) {
    void *p;
    fn_8016A240((u8 *)arg0 + 8);
    p = *(void **)((u8 *)arg0 + 0x38);
    *(s32 *)((u8 *)arg0 + 4) = 1;
    if (p != 0 && *(u8 *)((u8 *)p + 0x19) != 0) {
        *(u8 *)((u8 *)p + 0x4A) = 1;
        *(u8 *)((u8 *)p + 0x4C) = 0;
    }
    *(u8 *)((u8 *)arg0 + 0x34) = 0;
}

s32 fn_801D76CC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_801D770C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void *fn_801D774C(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 val = ((s32)arg0 + 0x24);
        if (val == 0) {
            goto skip;
        }
        if (val == 0) {
            goto skip;
        }
        *(s32 *)((u8 *)arg0 + 0x24) = 0;
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
skip:
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

char *fn_801D77AC(void) {
    return lbl_803388F0;
}

s32 fn_801D77B8(s32 arg0) {
    return ((s32 *)arg0)[2];
}

s32 fn_801D77C0(s32 arg0) {
    s32 *ptr = (s32 *)arg0;
    if (ptr[2] == 0) {
        return arg0;
    }
    ptr[2] = 1;
    return arg0;
}

s32 fn_801D77B8(s32 arg0);
s32 fn_801D77C0(s32 arg0);
void fn_80116BCC(void *);
void fn_80127464(void *);
#pragma cplusplus on
extern "C" void fn_801D77D8(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void fn_801D77E8(void) {

}

void fn_801D77EC(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)arg0;
    s32 count = ptr[0x1D];
    s32 idx = 0;
    s32 byte_offset = 0;
    
    if (count > 0) {
        s32 *array = (s32 *)ptr[0x1C];
        
        for (; idx < count; idx++) {
            if (array[byte_offset / 4] == arg1) {
                goto post_loop;
            }
            byte_offset += 4;
        }
        
        idx = -1;
    }
    
post_loop:
    if (idx == -1) {
        return;
    }
    if (idx < 0) {
        return;
    }
    if (idx >= count) {
        return;
    }
    if (idx == count - 1) {
        ptr[0x1C] = (s32)((s32 *)ptr[0x1C]);
        ((s32 *)ptr[0x1C])[idx] = ((s32 *)ptr[0x1C])[count - 1];
        ptr[0x1D] = count - 1;
    }
}

void fn_801D7874(void *arg0, void *arg1) {
    s32 result;
    s32 count;
    
    ((void (*)(void *))((void ***)arg1)[2])(arg1);
    
    if (((s32 *)arg0)[3] < 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    
    result = ((s32 (*)(void *, void *, s32))((void ***)arg1)[10])(arg1, &lbl_803385D0, -1);
    if (result != ((s32 *)arg0)[3]) {
        return;
    }
    
    count = ((s32 *)arg0)[0x1D];
    ((s32 *)arg0)[0x1D] = count + 1;
    ((s32 *)((s32 *)arg0)[0x1C])[count] = (s32)arg1;
}

void *fn_801D7924(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 0x28) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma scheduling on
s32 fn_801D796C(void *arg0, s32 *arg1, s32 arg2) {
    s32 *entry;
    s32 idx;

    entry = arg1;
    for (idx = 0; idx < arg2; entry++, idx++) {
        if (((s32 *)arg0)[1] != 0) {
            if (fn_801D9B28(((s32 *)arg0)[1], *entry) != 0) {
                return 1;
            }
        } else if (((s32 *)arg0)[2] == *entry) {
            return 1;
        }
    }
    return 0;
}
char *fn_801D7C6C(void) {
    return lbl_8033890C;
}

s32 fn_801D7C78(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

extern s32 fn_802E317C(const char *, ...);
#pragma push
#pragma scheduling off
s32 fn_801D7C80(void *arg0, s32 arg1) {
    s32 *ptr = (s32 *)arg0;
    f32 *fptr = (f32 *)arg0;
    if (ptr[0xA] == 1) {
        ptr[7] = lbl_8055E3C4;
        switch (arg1) {
        case 0: {
            f32 *d8 = (f32 *)((char *)arg0 + 0x20);
            f32 *d9 = (f32 *)((char *)arg0 + 0x24);
            *d8 = fptr[5]; *d9 = fptr[6]; break;
        }
        case 1: {
            f32 *d8 = (f32 *)((char *)arg0 + 0x20);
            f32 *d9 = (f32 *)((char *)arg0 + 0x24);
            *d8 = fptr[6]; *d9 = fptr[5]; break;
        }
        default: {
            char *fmt = lbl_80338F50;
            fn_802E317C(fmt, arg1);
            break;
        }
        }
        ptr[0xA] = 2;
        return 1;
    }
    return 0;
}

void fn_801D7E3C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x28) != 0) *(s32 *)((u8 *)arg0 + 0x28) = 1;
}

#pragma push
#pragma use_lmw_stmw off
void fn_801D7E54(void *arg0) {
    s32 temp;
    f32 f;
    if (*(s32 *)((u8 *)arg0 + 0x28) == 0) return;
    if (*(s32 *)((u8 *)arg0 + 0x10) != 0) goto done;
    temp = *(s32 *)((u8 *)arg0 + 4);
    f = *(f32 *)((u8 *)arg0 + 0x14);
    if (temp != 0) fn_801D9AB8(temp, f);
    else fn_80178DBC(*(s32 *)((u8 *)arg0 + 8));
done:
    *(s32 *)((u8 *)arg0 + 0x28) = 1;
}
#pragma pop
extern char lbl_80338CB0[];
#pragma push
#pragma scheduling reset
void *fn_801D7EC0(void *arg0, s32 arg1) {
    register void *child;
    s32 value;
    if (arg0 == 0) goto done;
    child = *(void **)((u8 *)arg0 + 0x2C);
    *(void **)arg0 = lbl_80338CB0;
    *(s32 *)((u8 *)arg0 + 0x40) = 0;
    if (child == 0) goto done_child;
    if (child == 0) goto done_child;
    ((void (**)(void *, s32))*(void **)child)[2](child, 1);
done_child:
    value = *(s32 *)((u8 *)arg0 + 0x3C);
    if (value != 0) fn_80128658(value);
    if (arg1 > 0) fn_80128668(arg0);
done:
    return arg0;
}
#pragma pop
s32 fn_801D7F5C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

#pragma scheduling reset

extern u8 lbl_80338928[];
void *fn_801D8148(void) {
    return lbl_80338928;
}

s32 fn_801D8154(void *arg0) { return *(s32 *)((u8 *)arg0 + 0x40); }

s32 fn_801DA8C8(void *, void *);
extern f32 lbl_80562AE0;
extern f32 lbl_80562AEC;
void fn_801D82A0(void *arg0) {
    s32 state, a, b, delta;
    f32 f;
    void **p;
    state = *(s32 *)((u8 *)arg0 + 0x40);
    a = *(s32 *)((u8 *)arg0 + 0x34);
    b = *(s32 *)((u8 *)arg0 + 0x30);
    delta = lbl_8055E3C4 - (a + b);
    if (state == 2 && delta >= 0) {
        p = *(void ***)((u8 *)arg0 + 0x2C);
        if (p != 0) {
            if (*(s32 *)((u8 *)arg0 + 0x38) == 0) f = lbl_80562AE0;
            else f = lbl_80562AEC;
            ((void (*)(f32))(*(void **)((u8 *)*p + 0x14)))(f);
        }
        *(s32 *)((u8 *)arg0 + 0x40) = 3;
    }
}

void fn_801D832C(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x40) != 0) *(s32 *)((u8 *)arg0 + 0x40) = 1;
}

void fn_801D8344(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x40) != 0) {
        void *p = *(void **)((u8 *)arg0 + 0x2C);
        if (p != 0) {
            (*(void (**)(void *))(*(u32 *)p + 0x1C))(p);
        }
        *(s32 *)((u8 *)arg0 + 0x40) = 1;
    }
}

s32 fn_801D839C(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x18) == 0;
}

#pragma cplusplus on
extern "C" void fn_801D83AC(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
s32 fn_801D83BC(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x30) == 0;
}

#pragma cplusplus on
extern "C" void fn_801D83CC(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void *fn_801D83DC(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern u8 lbl_80339038[];
void *fn_801D8504(void) {
    return lbl_80339038;
}

s32 fn_801D8510(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D8518(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C4;
        *(s32 *)((u8 *)arg0 + 4) = 2;
        return 1;
    }
    return 0;
}

void fn_801D8544(void *arg0) {
    s32 sp8;
    s32 elapsed;
    elapsed = lbl_8055E3C4 - (*(s32 *)((u8 *)arg0 + 0x10) + *(s32 *)((u8 *)arg0 + 0xC));
    if (*(s32 *)((u8 *)arg0 + 4) == 2 && elapsed > 0) {
        sp8 = *(s32 *)((u8 *)arg0 + 0x14);
        fn_801796CC(0xB, &sp8, *(volatile const s32 *)&(const s32){4});
        if (elapsed >= *(s32 *)((u8 *)arg0 + 8)) *(s32 *)((u8 *)arg0 + 4) = 3;
    }
}

#pragma cplusplus on
extern "C" void fn_801D85C8(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void fn_801D85D8(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

s32 fn_801D85F0(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x14) == 0;
}

void fn_801D8600(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

s32 fn_801D8618(void) { return 0; }

#pragma pop
void fn_801D8620(void) {

}

#pragma cplusplus on
extern "C" void fn_801D8624(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void fn_801D8710(s32 arg0) {
    if (arg0 != 0) {
        arg0 += 4;
    }
    fn_801D05B4(arg0);
}

extern u8 lbl_8033905C[];
void *fn_801D8720(void) {
    return lbl_8033905C;
}

s32 fn_801D872C(void *arg0) {
    return ((s32 *)arg0)[0x18 / 4];
}

s32 fn_801D8734(void) { return 0; }

s32 fn_801D873C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x18) = 2;
    *(s32 *)((u8 *)arg0 + 0x20) = 0;
    *(f32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C8;
    return 0;
}

#pragma cplusplus on
extern "C" void fn_801D88AC(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void fn_801D88BC(void *arg0) {
    s32 i;
    *(s32 *)((u8 *)arg0 + 0x18) = 1;
    for (i = 0; i < *(s32 *)((u8 *)arg0 + 0x28); i++) {
        void *base = *(void **)((u8 *)arg0 + 0x24);
        void *entry = *(void **)((u8 *)base + i * 0xC);
        (*(void (**)(void *, s32))(*(void ***)entry + 10))(entry, -1);
    }
}

void fn_801D8938(void) {

}

void fn_801D893C(void *arg0, u32 arg1) {
    s32 offset = 0;
    s32 i = 0;
    u8 *base;
    u8 *item;
    for (; i < *(s32 *)((u8 *)arg0 + 0x28); offset += 0xC, i++) {
        base = *(u8 **)((u8 *)arg0 + 0x24);
        item = base + offset;
        if (*(u32 *)item == arg1 && i >= 0 && i < *(s32 *)((u8 *)arg0 + 0x28)) {
            s32 last = *(s32 *)((u8 *)arg0 + 0x28) - 1;
            if (i != last) {
                *(u32 *)item = *(u32 *)(base + last * 0xC);
                *(u32 *)(item + 4) = *(u32 *)(base + last * 0xC + 4);
                *(u32 *)(item + 8) = *(u32 *)(base + last * 0xC + 8);
            }
            *(s32 *)((u8 *)arg0 + 0x28) = *(s32 *)((u8 *)arg0 + 0x28) - 1;
        }
    }
}

s32 fn_801D8AA4(void *arg0) {
    return *(f32 *)((u8 *)arg0 + 0x30) < lbl_80562ADC;
}

#pragma cplusplus on
extern "C" void fn_801D8ABC(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
extern s32 lbl_8055ACB0;
extern s32 lbl_8055ACB8;
extern f32 lbl_80562B14;
extern f32 lbl_80562B20;
extern s32 lbl_80339070;
s32 fn_801D8ACC(void *arg0, void *arg1) {
    extern f32 lbl_80562ADC;
    extern f32 lbl_80562B14;
    extern s32 lbl_8055ACB8;
    extern s32 lbl_8055ACB0;
    f32 value = lbl_80562ADC;
    *(s32 *)((u8 *)arg0 + 4) = 1;
    *(f32 *)((u8 *)arg0 + 0x10) = value;
    *(f32 *)((u8 *)arg0 + 8) = ((f32 (*)(void *, s32 *, f32))(*(void ***)arg1)[10])(arg1, &lbl_8055ACB8, value);
    *(f32 *)((u8 *)arg0 + 0xC) = ((f32 (*)(void *, s32 *, f32))(*(void ***)arg1)[10])(arg1, &lbl_8055ACB0, lbl_80562B14);
    return 1;
}

void fn_801D8B50(void) {

}

void fn_801D8B54(void) {

}

void fn_801D8B58(void) {

}

void fn_801D8B5C(void) {

}

s32 fn_801D8B60(void *arg0, void **arg1) {
    *(f32 *)((u8 *)arg0 + 0x14) = ((f32 (*)(void *, s32 *, f32))(*(void **)(*(u32 *)arg1 + 0x28)))(arg1, &lbl_80339070, lbl_80562B20);
    *(s32 *)((u8 *)arg0 + 4) = 1;
    *(f32 *)((u8 *)arg0 + 0x10) = lbl_80562ADC;
    *(f32 *)((u8 *)arg0 + 8) = ((f32 (*)(void *, s32 *, f32))(*(void **)(*(u32 *)arg1 + 0x28)))(arg1, &lbl_8055ACB8, lbl_80562ADC);
    *(f32 *)((u8 *)arg0 + 0xC) = ((f32 (*)(void *, s32 *, f32))(*(void **)(*(u32 *)arg1 + 0x28)))(arg1, &lbl_8055ACB0, lbl_80562B14);
    return 1;
}

void fn_801D8C0C(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x18) = -1;
}

void fn_801D8C18(void) {

}

extern f32 lbl_80562AE4;
s32 fn_801E1F78(void);
void fn_801D8C1C(void *arg0, f32 arg1) {
    volatile f32 threshold = lbl_80562ADC;
    f32 f1 = arg1 / (*(f32 *)((u8 *)arg0 + 0x14));
    f32 f0;
    s32 value;
    if (f1 < threshold) f0 = f1 - lbl_80562AE4;
    else f0 = lbl_80562AE4 + f1;
    value = (s32)f0;
    if (value != *(s32 *)((u8 *)arg0 + 0x18)) {
        fn_801E1F78();
        *(s32 *)((u8 *)arg0 + 0x18) = value;
    }
}

void fn_801D8C94(void) {

}

extern u8 lbl_8033907C[];
void *fn_801D8C98(void) {
    return lbl_8033907C;
}

s32 fn_801D8CA4(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_801D8CAC(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 4) = 2;
        *(f32 *)((u8 *)arg0 + 0x10) = lbl_8055E3C8;
        ((void (*)(void *))(*(void ***)arg0)[14])(arg0);
        return 1;
    }
    return 0;
}

void fn_801D8D00(void *arg0) {
 f32 f1, f2;
 void **vtable = *(void ***)arg0;
 if (*(s32 *)((u8 *)arg0+4)==2) {
 f1=lbl_8055E3C8-*(f32 *)((u8 *)arg0+0x10); f2=*(f32 *)((u8 *)arg0+8);
 if(f1<f2){((void (**)(void))vtable)[15](); return;}
 if(f1<f2+*(f32 *)((u8 *)arg0+0xC)){((void (**)(void *,f32))vtable)[16](arg0,f1-f2);return;}
 ((void (**)(void))vtable)[17](); *(s32 *)((u8 *)arg0+4)=3;
 }
}

#pragma cplusplus on
extern "C" void fn_801D8DA0(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void fn_801D8DB0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}

void *fn_801D8DC8(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

extern u8 lbl_803389B8[];
void *fn_801D8EF0(void) {
    return lbl_803389B8;
}

s32 fn_801D8EFC(void *arg0) {
    return ((s32 *)arg0)[1];
}

s32 fn_801D8F04(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) == 1) {
        *(s32 *)((u8 *)arg0 + 4) = 2;
        *(f32 *)((u8 *)arg0 + 0x20) = lbl_8055E3C8;
        return 1;
    }
    return 0;
}

extern char lbl_803390C0[];
extern s32 fn_802E30C8(char *, void *);
extern void fn_801D488C(s32, s32, f32 *);
void fn_801D8F30(void *arg0) {
    f32 sp8[3];
    if (*(s32 *)((u8 *)arg0 + 4) == 2 &&
        lbl_8055E3C8 - *(f32 *)((u8 *)arg0 + 0x20) <=
            *(f32 *)((u8 *)arg0 + 0x1C)) {
        if (((s32 (*)(void *))fn_801D4888)((u8 *)arg0 + 8) == 0) {
            fn_802E30C8(lbl_803390C0, (u8 *)arg0 + 8);
        } else {
            sp8[0] = lbl_80562ADC;
            sp8[1] = lbl_80562ADC;
            sp8[2] = lbl_80562ADC;
            fn_801D488C(1, 0, sp8);
        }
        *(s32 *)((u8 *)arg0 + 4) = 3;
    }
}

#pragma cplusplus on
extern "C" void fn_801D8FD0(void *arg0) {
    ((TObj34 *)arg0)->v34();
}
#pragma cplusplus reset
void fn_801D8FE0(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 4) != 0) {
        *(s32 *)((u8 *)arg0 + 4) = 1;
    }
}
typedef struct {
    void (*unk_0)(void);
    void (*unk_4)(void);
    void (*unk_8)(void);
    void (*unk_C)(void);
    void (*unk_10)(void);
    void (*unk_14)(void);
    void (*unk_18)(void);
    void (*unk_1C)(void);
    void (*unk_20)(void);
    void (*unk_24)(void);
    void (*unk_28)(void);
    void (*unk_2C)(void);
    void (*unk_30)(void);
    void (*unk_34)(void);
} Vtbl;
