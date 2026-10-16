// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include <revolution/MTX/vec.h>
#pragma opt_tail_call on
extern f32 lbl_805622DC;
extern f32 lbl_805622E0;
extern f32 lbl_805622D0;
extern void fn_8019AC44(f32*, f32*, f32);
extern char lbl_803339B8;
extern void fn_8019F03C();
extern void fn_8019DDFC(s32, s32, s32, s32, void*, void*, f32);
extern "C" f64 fn_8002F234(f32);

extern "C" void fn_8019EBC0(void);
extern "C" void fn_8019F3D0(void);
extern "C" void fn_801A49E8(void*);
extern "C" void fn_801A49FC(s32);
extern "C" void fn_801796EC(s32, s32*, s32);
extern "C" s32 fn_8012C4E4(void*, void*, s32);
extern "C" s32 fn_801CFF18(s32, s32);
extern "C" void fn_801D0650(void);
extern "C" void fn_801CFF14(void);
extern "C" s32 fn_801CF828(s32, s32, s32, s32, s32);
extern s32 lbl_8055E5A0;
extern "C" s32 fn_801CFEAC(void*);
#pragma push
#pragma small_data off
extern s32 lbl_803336EC;
#pragma pop

class VTab19 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void slot0x4C();
};

class VTab12C4 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
};
class VTab1250 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
};

class VTab13 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual void slot0x34(s32);
};

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32);
extern "C" void fn_801A44D4(void*);
extern void* lbl_8055A508;
extern void* lbl_8055A510;

void fn_8019F1A4(void) __attribute__((noreturn));

extern "C" s32 fn_80128668(void);
void fn_801A5C4C(void);
void fn_80199870(void* arg0) {
    u32 value = *(u32*)((u8*)arg0 + 0x10);
    if ((u32)(value - 0x50430000) == 0x4152 ||
        (u32)(value - 0x41430000) == 0x4152) {
        fn_801A5C4C();
    }
}

extern "C" s32 fn_8019A780(void *arg0) {
    return *(s32*)((u8*)arg0 + 8);
}

void fn_8019A788(void* arg0, void* arg1, void* arg3, void* arg4, s32 arg5, f32 farg1, f32 farg2) {
    extern s32 fn_80199894(void*, void*, f32*, s32, void*, f32, f32, f32, f32, f32);
    f32 sp10, spC, sp8;
    f32 scale = lbl_805622DC;
    if (*(s32*)((u8*)arg0 + 4) != 0 || arg4 != 0) {
        fn_80199894(arg0, arg4, (f32*)0, arg5, arg4, farg2, farg1, 0.0f, 0.0f, 0.0f);
        return;
    }
    sp8 = *(f32*)arg3 * scale;
    spC = *((f32*)arg3 + 1) * scale;
    sp10 = *((f32*)arg3 + 2) * scale;
    fn_80199894(arg1, arg0, &sp8, arg5, arg4, farg2, farg1, 0.0f, 0.0f, 0.0f);
}

void fn_8019AA18(void* arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern void fn_8019A820(void*, s32, s32, s32, f32);
    fn_8019A820((u8*)arg0 + 0x34, arg1, arg2, arg3, *(f32*)((u8*)arg0 + 0x24));
}

void fn_8019B068(void* arg0, void* arg1, s32 arg2, s32 arg3) {
    extern void fn_8019AA34(void*, void*, void*, s32, s32, void*, f32, f32);
    fn_8019AA34((u8*)arg0 + 0x34, arg1, (u8*)arg1 + 0x34, arg2, arg3, arg1, *(f32*)((u8*)arg0 + 0x24), *(f32*)((u8*)arg1 + 0x24));
}

extern "C" s32 fn_8019BD4C(void *arg0) {
    return ((s32 *)arg0)[0xC / 4];
}

extern void fn_8019CCCC(void*, f32, s32);
extern void fn_8019CCCC(void*, void*, s32, f32);
void fn_8019CE3C(void* arg0, s32 arg1) {
    fn_8019CCCC(arg0, (u8*)arg0 + 0x34, arg1, *(f32*)((u8*)arg0 + 0x24));
}

extern "C" f32 fn_8019DDEC(void *arg0) {
    return *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28);
}

extern "C" s32 fn_8019E834(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_8019E874(void*, void**, void*, f32, f32, f32, f32);
extern void fn_8019AA34(void*, void*, void*, s32, s32, void*, f32, f32);
extern void fn_8019A820(void*, s32, s32, s32, f32);
s32 fn_8019EA7C(void* arg0, void** arg1) {
    void* temp_r3;
    void* temp_r5;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 sp20;
    f32 sp1C;
    f32 spC;

    temp_r3 = ((void* (*)(void*))(*(u32*)(*(u32*)arg1 + 0x50)))(arg1);
    temp_r5 = *(void**)((u8*)arg0 + 0xC);
    temp_f3 = *(f32*)((u8*)temp_r5 + 0x28);
    temp_f4 = *(f32*)((u8*)temp_r5 + 0x24) - *(f32*)((u8*)temp_r3 + 0x24);
    temp_f1 = *(f32*)((u8*)temp_r5 + 0x2C);
    temp_f2 = temp_f3 - *(f32*)((u8*)temp_r3 + 0x28);
    sp20 = temp_f4; spC = temp_f2;
    sp1C = temp_f1 - *(f32*)((u8*)temp_r3 + 0x2C);
    return fn_8019E874(arg0, arg1, temp_r5, temp_f1, temp_f2, temp_f3, temp_f4) != 0;
}

void fn_8019EB14(u8 *arg0, s32 arg1) {
    u32 offset = arg1 * 8;
    u8 *p = arg0 + offset;
    u8 t;
    t = p[0]; p[0] = p[1]; p[1] = t;
    t = p[2]; p[2] = p[3]; p[3] = t;
    t = p[4]; p[4] = p[5]; p[5] = t;
    t = p[6]; p[6] = p[7]; p[7] = t;
    if (*(u16 *)(p + 4) != 0) {
        s32 i;
        for (i = 0; i < 4; i++) {
            fn_8019EB14(arg0, *(u16 *)(p + 4) + i);
        }
    }
}

void fn_8019EBC0(void* arg0) {
    void* obj = *(void**)((u8*)arg0 + 4);
    if (obj != 0) {
        void** vtable = *(void***)obj;
        ((void (*)(void*))(*(u32*)((u8*)vtable + 0x48)))(obj);
    }
}

extern "C" void fn_8019EBE0(void* self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 v1 = (s32)self;
    s32 v2 = a;
    s32 v3 = b;
    s32 v4 = c;
    s32 v5 = d;
    s32 v6 = e;
    s32 v7 = f;
    s32 obj = *(s32*)((u8*)self + 4);

    if (obj != 0) {
        fn_8017B5D4(obj, v1, v2, v3, v4, v5, v6);
        return;
    }

    obj = *(s32*)((u8*)self + 8);
    if (obj != 0) {
        fn_801A4A10(obj, v4, v7);
    }

    return (void)v1, (void)v2, (void)v3, (void)v5, (void)v6;
}

extern "C" void fn_8019EC84(void* this_) {
    VTab19* p = *(VTab19**)((u8*)this_ + 4);
    if (p == NULL) {
        return;
    }
    p->slot0x4C();
}

extern "C" void fn_8019ECA4(VTab13* this_, s32 arg1) {
    *(s32*)((u8*)this_ + 8) = arg1;
    this_->slot0x34(arg1 + 4);
}

extern "C" void fn_8017B5D4(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801A4A10(s32, s32, s32);
extern "C" void fn_8019ECBC(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
}

void fn_8019EECC(void* arg0, Vec* arg1) {
    arg1->x += *(f32*)((u8*)arg0 + 0x30);
    arg1->y += *(f32*)((u8*)arg0 + 0x34);
    arg1->z += *(f32*)((u8*)arg0 + 0x38);
}

void fn_8019F03C(void* arg0) {
    f32 value = lbl_805622D0;
    *(u8*)((u8*)arg0 + 0x4C) = 0;
    *(f32*)((u8*)arg0 + 0x40) = value;
    *(f32*)((u8*)arg0 + 0x44) = value;
    *(f32*)((u8*)arg0 + 0x48) = value;
    *(f32*)((u8*)arg0 + 0x34) = value;
    *(f32*)((u8*)arg0 + 0x38) = value;
    *(f32*)((u8*)arg0 + 0x3C) = value;
}

void fn_8019F1A4(void* arg0) { fn_8019AC44((f32*)((u8*)arg0 + 0x34), (f32*)((u8*)arg0 + 0x40), *(f32*)((u8*)arg0 + 0x24)); }

void fn_8019F1B4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) { fn_8019DDFC(arg1,arg2,arg3,arg4,(u8*)arg0+0x34,arg0,*(f32*)((u8*)arg0+0x24)); }

void fn_8019F1D4(void *arg0, f32 *arg1, f32 *arg2) {
    f32 width = *(f32 *)((u8 *)arg0 + 0x24);
    f32 left = *(f32 *)((u8 *)arg0 + 0x34);
    f32 mid = *(f32 *)((u8 *)arg0 + 0x38);
    f32 right = *(f32 *)((u8 *)arg0 + 0x3C);
    f32 a = width * lbl_805622DC;
    f32 b = width * lbl_805622E0;
    f32 v0[2] = {width, width};
    f32 v1[4] = {width, left, mid, right};
    arg1[0] = left + a;
    arg1[1] = mid + a;
    arg1[2] = right + a;
    arg2[0] = left + b;
    arg2[1] = mid + b;
    arg2[2] = right + b;
}

void fn_8019F248(void *arg0) {
    extern f32 lbl_80562300;
    extern s32 lbl_8055E598;
    extern void fn_801E3FC8(void*, s32, f32);
    f32 var_f1 = *(f32*)((u8*)arg0 + 0x24);
    if (var_f1 <= lbl_80562300) {
        var_f1 = lbl_80562300;
    }
    fn_801E3FC8((u8*)arg0 + 0x34, lbl_8055E598, var_f1);
}

extern "C" void fn_8019F3D0(void) {

}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_8019F3D4(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8019F414(void *arg0) {
    extern f32 lbl_8056237C;
    extern void fn_8019EECC(void*, void*);
    extern void fn_8019EF00(void*);
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r4;
    void *temp_r6;
    temp_r6 = *(void **)((u8*)arg0 + 0x54);
    temp_r4 = *(void **)arg0;
    sp8 = *(f32*)((u8*)temp_r6 + 0x30);
    spC = *(f32*)((u8*)temp_r6 + 0x34);
    sp10 = *(f32*)((u8*)temp_r6 + 0x38);
    sp8 = (sp8 - *(f32*)((u8*)temp_r4 + 0x30)) + *(f32*)((u8*)arg0 + 0x58);
    spC = (spC - *(f32*)((u8*)temp_r4 + 0x34)) + (lbl_8056237C + *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)temp_r6 + 0xC));
    sp10 = sp10 - *(f32*)((u8*)temp_r4 + 0x38);
    *(f32*)((u8*)arg0 + 0x28) = sp8;
    *(f32*)((u8*)arg0 + 0x2C) = spC;
    *(f32*)((u8*)arg0 + 0x30) = sp10;
    if (temp_r4 != 0) fn_8019EECC(temp_r4, (u8*)arg0 + 0x28);
    fn_8019EF00(arg0);
}

void fn_8019F560(void) {
    fn_8019F1A4();
}

void fn_8019F6F0(void *arg0) { fn_8019F03C(arg0); *(f32*)((u8*)arg0+0x64)=lbl_805622D0; *(f32*)((u8*)arg0+0x68)=lbl_805622D0; *(f32*)((u8*)arg0+0x6C)=lbl_805622D0; *(f32*)((u8*)arg0+0x70)=lbl_805622D0; *(f32*)((u8*)arg0+0x74)=lbl_805622D0; *(f32*)((u8*)arg0+0x78)=lbl_805622D0; *(f32*)((u8*)arg0+0x7C)=lbl_805622D0; *(f32*)((u8*)arg0+0x80)=lbl_805622D0; *(f32*)((u8*)arg0+0x84)=lbl_805622D0; *(f32*)((u8*)arg0+0x88)=lbl_805622D0; *(f32*)((u8*)arg0+0x8C)=lbl_805622D0; *(f32*)((u8*)arg0+0x90)=lbl_805622D0; *(f32*)((u8*)arg0+0x94)=lbl_805622D0; *(f32*)((u8*)arg0+0x98)=lbl_805622D0; *(f32*)((u8*)arg0+0x9C)=lbl_805622D0; *(f32*)((u8*)arg0+0xA0)=lbl_805622D0; *(f32*)((u8*)arg0+0xA4)=lbl_805622D0; *(f32*)((u8*)arg0+0xA8)=lbl_805622D0; *(f32*)((u8*)arg0+0xAC)=lbl_805622D0; *(f32*)((u8*)arg0+0xB0)=lbl_805622D0; *(f32*)((u8*)arg0+0xB4)=lbl_805622D0; *(f32*)((u8*)arg0+0xB8)=lbl_805622D0; *(f32*)((u8*)arg0+0xBC)=lbl_805622D0; *(f32*)((u8*)arg0+0xC0)=lbl_805622D0; }

extern "C" void fn_8019FF88(void) {
    fn_8019EBC0();
}

extern "C" void fn_8019FF8C(void* arg0) {
    fn_8019F03C();
    *(f32*)((u8*)arg0 + 0x28) = *(f32*)((u8*)arg0 + 0x54);
    *(f32*)((u8*)arg0 + 0x2C) = *(f32*)((u8*)arg0 + 0x58);
    *(f32*)((u8*)arg0 + 0x30) = *(f32*)((u8*)arg0 + 0x5C);
    *(u8*)((u8*)arg0 + 0x78) = 0;
}

extern "C" void fn_8019FFD8(void* arg0, s32 arg1, s32 arg2) {
    *(s32*)((u8*)arg0 + 0xC) = arg1;
    *(s32*)((u8*)arg0 + 4) = arg2;
    *(s32*)((u8*)arg0 + 8) = 0;
    *(s32*)((u8*)arg0 + 0x18) = 0x47525550;
    *(f32*)((u8*)arg0 + 0x10) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x14) = lbl_805622D0;
    *(s32*)((u8*)arg0 + 0x20) = 0x64;
    *(s32*)((u8*)arg0 + 0x1C) = 0;
    *(void**)((u8*)arg0) = &lbl_803339B8;
    *(f32*)((u8*)arg0 + 0x170) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x178) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x16C) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x168) = lbl_805622D0;
    *(f32*)((u8*)arg0 + 0x164) = lbl_805622D0;
    *(s32*)((u8*)arg0 + 0x174) = 0;
    *(s32*)((u8*)arg0 + 0x17C) = 0;
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" s32 fn_801A010C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_801A014C(void* arg0) {
    void* item = *(void**)((u8*)arg0 + 0x17C);
    ((void (*)(void))((void**) *(void**)item)[3])();
}

extern s32 lbl_8055E3C4;
extern "C" void fn_801A0160(void* arg0) {
    s32 value = lbl_8055E3C4;
    if (value != *(s32*)((u8*)arg0 + 0x180)) {
        *(s32*)((u8*)arg0 + 0x180) = value;
        void** entries = (void**)arg0;
        s32 i = 0;
    loop:
        void* item = *(void**)((u8*)entries + 0x24);
        ((void (*)(void*))((void**) *(void**)item)[3])(item);
        entries++;
        i++;
        if (i < *(s32*)((u8*)arg0 + 0x174))
            goto loop;
    }
}

extern "C" void fn_801A01E0(void* arg0, void* arg1, void* arg2) {
    f32 temp_f8 = *(f32*)((u8*)arg0 + 0x178);
    void* temp_r3 = *(void**)((u8*)arg0 + 0xC);
    f32 temp_f7 = *(f32*)((u8*)temp_r3 + 0x24);
    f32 temp_f2 = temp_f8 * lbl_805622DC;
    f32 temp_f6 = *(f32*)((u8*)temp_r3 + 0x28);
    f32 temp_f0 = temp_f8 * lbl_805622E0;
    f32 temp_f5 = *(f32*)((u8*)temp_r3 + 0x2C);
    f32 sp8 = temp_f8;
    *(f32*)arg1 = temp_f7 + temp_f2;
    *(f32*)((u8*)arg1 + 4) = temp_f6 + temp_f2;
    *(f32*)((u8*)arg1 + 8) = temp_f5 + temp_f2;
    f32 spC = temp_f8;
    f32 sp10 = temp_f8;
    f32 sp14 = temp_f7;
    f32 sp18 = temp_f6;
    f32 sp1C = temp_f5;
    *(f32*)arg2 = temp_f7 + temp_f0;
    *(f32*)((u8*)arg2 + 4) = temp_f6 + temp_f0;
    *(f32*)((u8*)arg2 + 8) = temp_f5 + temp_f0;
}

extern "C" void fn_801A0444(void* arg0, void* arg1) {
    *(void**)((u8*)arg0 + 0x17C) = arg1;
    *(f32*)((u8*)arg0 + 0x164) = *(f32*)((u8*)arg1 + 0x24);
    *(f32*)((u8*)arg0 + 0x168) = *(f32*)((u8*)arg1 + 0x28);
    *(f32*)((u8*)arg0 + 0x16C) = *(f32*)((u8*)arg1 + 0x2C);
}

extern "C" void fn_801A1250(void* arg0) {
    VTab1250** entries = (VTab1250**)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        entries[9]->v10();
        entries++;
        i++;
    }
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

void fn_801A12C4(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x1C) = arg1;
    VTab12C4* first = *(VTab12C4**)((u8*)arg0 + 0x17C);
    first->v17();
    VTab12C4** entries = (VTab12C4**)arg0;
    s32 i = 0;
    while (i < *(s32*)((u8*)arg0 + 0x174)) {
        ((void (*)(VTab12C4*, s32))(*(void***)entries[9])[17])(entries[9], arg1);
        entries++; i++;
    }
}

extern "C" void fn_801A1358(void *arg0, s32 arg1) { *(s32 *)((u8 *)arg0 + 0x1C) = arg1; }

extern "C" void fn_801A1360(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x20) = arg1;
    void* p = *(void**)((u8*)arg0 + 0x17C);
    void** vt = *(void***)p;
    ((void (*)(void*, s32))vt[16])(p, arg1);
    void** entries = (void**)arg0;
    s32 i = 0;
    do {
        void* item = *(void**)((u8*)entries + 0x24);
        void** ivt = *(void***)item;
        ((void (*)(void*, s32))ivt[16])(item, arg1);
        entries++;
        i++;
    } while (i < *(s32*)((u8*)arg0 + 0x174));
}

extern "C" void fn_801A13F4(void* arg0) {
    void* p = *(void**)((u8*)arg0 + 0x17C);
    void** vt = *(void***)p;
    ((void (*)(void*))vt[19])(p);
    void** entries = (void**)arg0;
    s32 i = 0;
    do {
        void* item = *(void**)((u8*)entries + 0x24);
        void** ivt = *(void***)item;
        ((void (*)(void*))ivt[19])(item);
        entries++;
        i++;
    } while (i < *(s32*)((u8*)arg0 + 0x174));
}

extern "C" void fn_801A1474(void* arg0, f32 scale) {
    u8* p = (u8*)arg0;
    f32* src = (f32*)(p + 0x64);
    void* obj = *(void**)(p + 0x24);
    s32 i = 0;
    *(f32*)(p + 0x178) = *(f32*)(p + 0x170) * scale;
    do {
        f32 x = src[0] * scale;
        f32 y = src[1] * scale;
        f32 z = src[2] * scale;
        *(f32*)((u8*)obj + 0x28) = x;
        *(f32*)((u8*)obj + 0x2c) = y;
        *(f32*)((u8*)obj + 0x30) = z;
        *(f32*)((u8*)obj + 0x24) = src[3] * scale;
        src += 4;
        obj = *(void**)(p + 0x28 + i * 4);
        i++;
    } while (i < *(s32*)(p + 0x174));
    obj = *(void**)(p + 0x17c);
    *(f32*)((u8*)obj + 0x24) = *(f32*)(p + 0x164) * scale;
    *(f32*)((u8*)obj + 0x28) = *(f32*)(p + 0x168) * scale;
    *(f32*)((u8*)obj + 0x2c) = *(f32*)(p + 0x16c) * scale;
}

extern void fn_8019ECC4(void);
extern void* lbl_80333968;
extern f32 lbl_80562370;
extern "C" void* fn_801A1520(void* arg0, void* arg1, s32 arg2) {
    fn_8019ECC4();
    *(void**)arg0 = &lbl_80333968;
    if (arg2 != 0) {
        u8 a = *((u8*)arg0 + 0x24);
        u8 b = *((u8*)arg0 + 0x25);
        u8 c = *((u8*)arg0 + 0x28);
        u8 d = *((u8*)arg0 + 0x29);
        *((u8*)arg0 + 0x24) = *((u8*)arg0 + 0x27);
        *((u8*)arg0 + 0x27) = a;
        *((u8*)arg0 + 0x25) = *((u8*)arg0 + 0x26);
        *((u8*)arg0 + 0x26) = b;
        *((u8*)arg0 + 0x28) = *((u8*)arg0 + 0x2b);
        *((u8*)arg0 + 0x2b) = c;
        *((u8*)arg0 + 0x29) = *((u8*)arg0 + 0x2a);
        *((u8*)arg0 + 0x2a) = d;
        if (*(s32*)((u8*)arg0 + 0x20) == 0x3eb)
            *(f32*)((u8*)arg0 + 0x24) += lbl_80562370;
    }
    return arg0;
}

void fn_801A1F44(void* arg0, void* arg1) {
    void* result = ((void* (*)(void*))((void**)*(void**)arg1)[10])(arg1);
    *(s32*)((u8*)arg0) = *(s32*)((u8*)result + 0x24);
    *(s32*)((u8*)arg0 + 4) = *(s32*)((u8*)result + 0x28);
    *(s32*)((u8*)arg0 + 8) = *(s32*)((u8*)result + 0x2C);
}

extern "C" s32 fn_801A2434(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_801A2674(void* arg0, s32 arg1, s32 arg2, f32 arg3) {
    *(f32*)((u8*)arg0 + 0x24) = arg3;
    *(s32*)((u8*)arg0 + 0x28) = arg1;
    *(s32*)((u8*)arg0 + 0x2C) = arg2;
}

extern f32 lbl_805622E0;
void fn_801A2684(void* arg0, f32* arg1, f32* arg2) {
    f32 sp10, spC, sp8;
    f32 temp_f0 = *(f32*)((u8*)arg0 + 0x24);
    void* temp_r3 = *(void**)((u8*)arg0 + 0xC);
    f32 temp_f1 = lbl_805622E0 * temp_f0;
    sp8 = lbl_805622E0;
    f32 temp_f2 = lbl_805622E0 * -temp_f0;
    spC = lbl_805622E0;
    sp10 = lbl_805622E0;
    arg1[0] = *(f32*)((u8*)temp_r3 + 0x24) + temp_f2;
    arg1[1] = *(f32*)((u8*)temp_r3 + 0x28) + temp_f2;
    arg1[2] = *(f32*)((u8*)temp_r3 + 0x2C) + temp_f2;
    arg2[0] = *(f32*)((u8*)temp_r3 + 0x24) + temp_f1;
    arg2[1] = *(f32*)((u8*)temp_r3 + 0x28) + temp_f1;
    arg2[2] = *(f32*)((u8*)temp_r3 + 0x2C) + temp_f1;
}

extern "C" void* fn_801A2C9C(void* arg0) {
    return (u8*)arg0 + 0x44;
}

extern "C" f32 fn_801A2CA4(void* arg0) {
    return *(f32*)((u8*)arg0 + 0x178);
}

extern void fn_8019ECC4();
extern char lbl_803337C8;
extern void fn_801E3FC8(s32, s32, s32, f32);
extern s32 lbl_8055E598;
void* fn_801A2CC0(void* arg0, s32 arg1, s32 arg2) {
    u8 temp_r6;
    u8 temp_r7;
    u8 temp_r8;
    u8 temp_r9;
    fn_8019ECC4();
    *(void**)arg0 = &lbl_803337C8;
    if (arg2 != 0) {
        temp_r6 = *(u8*)((u8*)arg0 + 0x24);
        temp_r8 = *(u8*)((u8*)arg0 + 0x25);
        temp_r7 = *(u8*)((u8*)arg0 + 0x28);
        temp_r9 = *(u8*)((u8*)arg0 + 0x29);
        *(u8*)((u8*)arg0 + 0x24) = *(u8*)((u8*)arg0 + 0x27);
        *(u8*)((u8*)arg0 + 0x27) = temp_r6;
        *(u8*)((u8*)arg0 + 0x25) = *(u8*)((u8*)arg0 + 0x26);
        *(u8*)((u8*)arg0 + 0x26) = temp_r8;
        *(u8*)((u8*)arg0 + 0x28) = *(u8*)((u8*)arg0 + 0x2B);
        *(u8*)((u8*)arg0 + 0x2B) = temp_r7;
        *(u8*)((u8*)arg0 + 0x29) = *(u8*)((u8*)arg0 + 0x2A);
        *(u8*)((u8*)arg0 + 0x2A) = temp_r9;
    }
    return arg0;
}

extern "C" void fn_801A2EC8(void) {

}

extern "C" void fn_801A3174(void *arg0) {
    ((void (*)(s32, s32, f32))fn_801E3FC8)(*(s32*)((u8*)arg0 + 0xC) + 0x24, lbl_8055E598, *(f32*)((u8*)arg0 + 0x24) + *(f32*)((u8*)arg0 + 0x28));
}

extern s32 lbl_80333778;
extern "C" void fn_801A3190(void *arg0, s32 arg1, void *arg2, s32 arg3, void *arg4, void *arg5, f32 farg0, f32 farg1) {
    s32 i;
    u8 *dst = (u8*)arg0;
    u8 *src = (u8*)arg2;
    *(s32*)(dst + 0xC) = arg1;
    *(s32*)(dst + 4) = 0;
    *(s32*)(dst + 0x18) = 0x504F4C59;
    *(s32*)(dst + 8) = 0;
    *(f32*)(dst + 0x10) = farg0;
    *(f32*)(dst + 0x14) = farg1;
    *(s32*)(dst + 0x20) = 100;
    *(s32*)(dst + 0x1C) = 0;
    *(void**)dst = &lbl_80333778;
    *(s32*)(dst + 0xDC) = 0;
    *(s32*)(dst + 0xBC) = arg3;
    for (i = 0; i < arg3; i++) {
        *(s32*)(dst + 0x3C) = *(s32*)src;
        *(s32*)(dst + 0x40) = *(s32*)(src + 4);
        *(s32*)(dst + 0x44) = *(s32*)(src + 8);
        *(f32*)(dst + 0x48) = *(f32*)(src + 0xC);
        src += 0x10;
        dst += 0x10;
    }
    *(f32*)((u8*)arg0 + 0x24) = ((f32*)arg4)[0];
    *(f32*)((u8*)arg0 + 0x28) = ((f32*)arg4)[1];
    *(f32*)((u8*)arg0 + 0x2C) = ((f32*)arg4)[2];
    *(f32*)((u8*)arg0 + 0x30) = ((f32*)arg5)[0];
    *(f32*)((u8*)arg0 + 0x34) = ((f32*)arg5)[1];
    *(f32*)((u8*)arg0 + 0x38) = ((f32*)arg5)[2];
}

f32 fn_801A3880(void* arg0) {
    f32 first;
    f32 second;
    first = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x30), (const Vec *)((u8 *)arg0 + 0x30));
    second = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x24), (const Vec *)((u8 *)arg0 + 0x24));
    if (second > first) {
        first = second;
    }
    return (f32)fn_8002F234(first);
}

extern "C" void fn_8019ECC4(void);
extern "C" void fn_801CFA48(void*);
extern s32 lbl_80333728;
void* fn_801A3F5C(void* arg0, s32 arg1, s32 arg2) {
    fn_8019ECC4();
    *(s32*)arg0 = (s32)&lbl_80333728;
    if (arg2 != 0) {
        *(void**)((u8*)arg0 + 0x24) = (u8*)arg0 + 0x40;
        fn_801CFA48((u8*)arg0 + 0x40);
    }
    return arg0;
}

void *__dt__Q28PSSystem7SeqHeapFv_801A3FB8(void *arg0, s32 arg1) {
    if (arg0) {
        *(void**)arg0 = &lbl_80333728;
        ((void (*)(s32))fn_801CFF14)(*(s32*)((u8*)arg0 + 0x24));
        if (arg1 > 0) {
            ((void (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

void fn_801A442C(void *arg0, void *arg1, void *arg2) {
    *(f32 *)((u8 *)arg1 + 0) = *(f32 *)((u8 *)arg0 + 0x28);
    *(f32 *)((u8 *)arg1 + 4) = *(f32 *)((u8 *)arg0 + 0x2C);
    *(f32 *)((u8 *)arg1 + 8) = *(f32 *)((u8 *)arg0 + 0x30);
    *(f32 *)((u8 *)arg2 + 0) = *(f32 *)((u8 *)arg0 + 0x34);
    *(f32 *)((u8 *)arg2 + 4) = *(f32 *)((u8 *)arg0 + 0x38);
    *(f32 *)((u8 *)arg2 + 8) = *(f32 *)((u8 *)arg0 + 0x3C);
}

f32 fn_801A4460(void *arg0) {
    f32 first;
    f32 second;
    first = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x34), (const Vec *)((u8 *)arg0 + 0x34));
    second = PSVECDotProduct((const Vec *)((u8 *)arg0 + 0x28), (const Vec *)((u8 *)arg0 + 0x28));
    if (second > first) {
        first = second;
    }
    return (f32)fn_8002F234(first);
}

extern "C" void fn_801A44C4(void* arg0) {
    fn_801CFF18(*(s32*)((u8*)arg0 + 0x24), *(s32*)((u8*)arg0 + 0xC));
}

extern "C" void fn_801A44D4(void* arg0) {
    s32* r29;
    s32 r30;
    s32 r31;
    r29 = (s32*)arg0;
    r30 = 0;
    r31 = 0;
    goto check;
loop:
    {
        s32* arr = (s32*)r29[1];
        fn_801A49FC(*(s32*)((u8*)arr + r30));
        r30 += 4;
        r31++;
    }
check:
    {
        s32 limit = r29[0];
        if (r31 < limit) goto loop;
    }
}

extern "C" void fn_801A4538(void* arg0) {
    fn_8012C4E4(arg0, &fn_801A44D4, 0);
}

#pragma opt_tail_call on
extern "C" void fn_801A4768(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

extern "C" void fn_801A4798(s32* arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

#pragma opt_tail_call on
void fn_801A47C8(void* arg0) {
    s32 limit = *(s32*)arg0;
    s32** ptrs = *(s32***)((u8*)arg0 + 4);
    for (s32 i = 0; i < limit; i++) {
        ((u8*)ptrs[i])[0x40] = 1;
    }
}

#pragma opt_tail_call on
void fn_801A47FC(void* arg0) {
    if (arg0) {
        s32 limit = *(s32*)arg0;
        s32** ptrs = *(s32***)((u8*)arg0 + 4);
        for (s32 i = 0; i < limit; i++) {
            fn_801A49E8((void*)ptrs[i]);
        }
    }
}

#pragma opt_tail_call on
void fn_801A4868(void* arg0, u8 arg1) {
    if (*(u8*)((u8*)arg0 + 0x40) != arg1) {
        s32 local38;
        u8 localC;
        local38 = *(s32*)((u8*)arg0 + 0x38);
        localC = arg1;
        fn_801796EC(12, (s32*)&local38, 8);
        *(u8*)((u8*)arg0 + 0x40) = arg1;
    }
}

void fn_801A48C8(void* arg0) {
    void* ptr = *(void**)((u8*)arg0 + 0x48);
    ((void(*)(void*, void*, void**))(*(void***)((u8*)ptr + 0x18)))(ptr, &lbl_8055A508, &lbl_8055A510);
}

void fn_801A49E8(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D0650();
    }
}

extern "C" void fn_801D06C4(void);
extern "C" void fn_8019BD54(void*, void*, s32, s32);
extern "C" void fn_8019D06C(void*, void*, s32, s32);
extern "C" void fn_8019EA7C(void*, void*);
extern f32 lbl_8056237C;
extern f32 lbl_80562300;
extern void fn_8019EECC(void*, void*);
extern void fn_8019EF00(void*);
extern void fn_801E3FC8(void*, s32, f32);
void fn_801A49FC(void* arg0) {
    if (*(s32*)((u8*)arg0 + 0x48) != 0) {
        fn_801D06C4();
    }
}

#pragma push
#pragma small_data off
extern "C" void fn_801A4E28(void) {
    lbl_8055E5A0 = fn_801CFEAC(&lbl_803336EC);
}
#pragma pop
extern "C" void fn_801A4E54(void) {
    if (lbl_8055E5A0 != 0) {
        ((void (*)(s32))fn_801CFF14)(lbl_8055E5A0);
        lbl_8055E5A0 = 0;
    }
}

extern "C" void fn_801D0650(void);
extern s32 lbl_8055E5A0;
extern void fn_801CFF14(void);
extern s32 fn_801CF828(s32, s32, s32, s32, s32);
extern "C" s32 fn_801A4E88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32* arg4) {
    s32 a = arg0;
    s32 b = arg1;
    s32 c = arg2;
    s32 d = arg3;
    s32* out = arg4;
    if (lbl_8055E5A0 != 0 && fn_801CF828(lbl_8055E5A0, a, b, c, d) != 0) {
        *out = 0x6E;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801A4F00(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F40(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4F80(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A4FC0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5000(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5040(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5080(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A50C0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" f32 fn_801A5100(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" void fn_801A5108(void* arg0) {
    *(s32*)((u8*)arg0 + 0x180) = -1;
}

extern "C" f32 fn_801A5114(void *arg0) {
    return ((f32 *)arg0)[0x30 / 4];
}

extern "C" f32 fn_801A511C(void *arg0) {
    return ((f32 *)arg0)[0x24 / 4];
}

extern "C" float fn_801A5124(void* arg0) {
    return *(float*)((char*)arg0 + 0x28);
}

extern "C" s32 fn_801A512C(void) {
    return 0;
}

extern "C" s32 fn_801A5134(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_801A5174(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x48);
}

extern "C" s32 fn_801A517C(s32 arg0) {
    return arg0 + 0x28;
}

extern "C" u8 fn_801A5184(void *arg0) { return *((u8*)arg0 + 0x40); }

extern "C" void fn_801A4868(void);

extern "C" void fn_801A4868(void);
extern "C" void fn_801A4868(void*, u8);

extern "C" void fn_801A518C(void) {
    fn_801A4868();
}

extern "C" void fn_801A5190(void* arg0) {
    VTab19* p = *(VTab19**)((u8*)arg0 + 0x3C);
    if (p == NULL) {
        return;
    }
    p->v14();
}

extern "C" s32 fn_801A51B0(void* arg0) {
    void* obj = *(void**)((u8*)arg0 + 0x3C);
    if (obj != NULL) {
        return *(s32*)((u8*)obj + 0x20);
    }
    return -1;
}

extern "C" s32 fn_801A51CC(void* arg0) {
    return *(s32*)((u8*)arg0 + 0x34);
}

extern "C" void fn_801A51D4(void* arg0, s32 arg1) {
    *(s32*)((u8*)arg0 + 0x34) = arg1;
}
extern void fn_8019ECC4(void);
extern void* lbl_80333968;
extern f32 lbl_80562370;
typedef void (*VFunc)(void*);
typedef void (*VFuncArg)(void*, s32);
extern f32 lbl_805622DC;
