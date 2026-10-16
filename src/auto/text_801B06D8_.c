#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_801B2EC0(void);
extern s32 fn_80128668(void);
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
extern void *lbl_8055E694;
extern f32 lbl_805625F0;
extern void *lbl_8055E68C;
extern u8 lbl_8055E690;
extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
extern void fn_801B18B8(s32, s32);

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

s32 fn_801B0DE0(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x3C);
}

s32 fn_801B0DE8(s32 arg0) { return arg0 + 4; }

s32 fn_801B0DF0(s32 arg0) {
    void *base = lbl_8055E684;
    void **obj = (void **)((u8 *)base + (arg0 << 7));
    void **vtable = *(void ***)obj;
    void *result = ((void *(*)(void *, void *))vtable[8])(obj, base);
    return *(u32 *)((u8 *)result + 0x10) == 0x50434152;
}

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
s32 fn_801B1130(s32 arg0) {
    s32 var_r30;
    s32 var_r31;
    s32 var_r3;
    var_r31 = 1;
    var_r30 = 0;
    if (lbl_8055E68C != NULL) {
        void **obj = (void **)lbl_8055E68C;
        void **vtable = *(void ***)obj;
        s32 (*method)(void *, s32, s32) = (s32 (*)(void *, s32, s32))vtable[5];
        if (method(obj, arg0, *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x7C)) != 0) var_r30 = 1;
    }
    if (var_r30 == 0) {
        var_r3 = 0;
        if (lbl_8055E68C == NULL && lbl_8055E690 != 0) var_r3 = 1;
        if (var_r3 == 0) var_r31 = 0;
    }
    return var_r31;
}

s32 fn_801B1310(s32 arg0) { return arg0 + 4; }

void fn_801B157C(void *arg0,s32 arg1) {
    *(u8*)((u8*)arg0+0x2C)=1;*(f32*)((u8*)arg0+0x30)=lbl_8055E3C8;
    if(lbl_8055E690)fn_801CB6B4(*(s32*)((u8*)arg0+0x60),arg1,2);
}

void fn_801B18B8(s32 arg1, s32 arg2) {
    f32 p0[4]; f32 p1[2];
    void *obj = lbl_8055E684;
    f32 scale=*(f32*)((u8*)obj+0x5BC);
    f32 x=*(f32*)((u8*)obj+0x94)+*(f32*)((u8*)obj+0x54)*scale;
    f32 y=*(f32*)((u8*)obj+0x9C)+*(f32*)((u8*)obj+0x5C)*scale;
    f32 z=*(f32*)((u8*)obj+0x98)+*(f32*)((u8*)obj+0x58)*scale;
    p0[0]=x;p0[1]=y;p0[2]=x;p0[3]=z;p1[0]=*(f32*)((u8*)obj+0x54);p1[1]=*(f32*)((u8*)obj+0x5C);
    fn_80135F64(*(s32*)((u8*)obj+0x58),p0,p1,arg1,arg2,obj,y,z,*(f32*)((u8*)obj+0x58),x,scale);
    fn_801353C8(*(s32*)((u8*)obj+0x3C),p0,p1,0);
}

void fn_801B1FB4(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    void **vtable;
    *arg3 = 0;
    if (lbl_8055E68C == 0) return;
    vtable = *(void ***)lbl_8055E68C;
    ((void (*)(void *, f32, f32, s32, void *))vtable[3])(
        lbl_8055E68C, 0.0f, 0.0f,
        *(s32 *)((u8 *)arg0 + 0x60), (u8 *)arg0 + 0x7C);
}

void fn_801B1FEC(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    void **vtable;
    *arg3 = 0;
    if (lbl_8055E68C == 0) return;
    vtable = *(void ***)lbl_8055E68C;
    ((void (*)(void *, s32, void *))vtable[4])(lbl_8055E68C,
        *(s32 *)((u8 *)arg0 + 0x60), (u8 *)arg0 + 0x7C);
}

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

s32 fn_801B25B0(s32 *arg0, s32 *arg1) {
    f32 var_f31;
    f32 var_f1;
    s32 index0 = *arg0;
    s32 index1 = *arg1;
    void *base = lbl_8055E684;
    void *obj0 = (u8 *)base + (index0 << 7);
    void *obj1 = (u8 *)base + (index1 << 7);
    void **vtable0 = *(void ***)obj0;
    void *result0 = ((void *(*)(void *, s32, void *))vtable0[4])(obj0, index1, base);
    void **vtable1 = *(void ***)obj1;
    ((void (*)(void *))vtable1[4])(obj1);
    var_f31 = *(f32 *)((u8 *)result0 + 0x20);
    var_f1 = *(f32 *)((u8 *)obj1 + 0x20);
    if (var_f31 < lbl_80562604) var_f31 = lbl_80562610;
    if (var_f1 < lbl_80562604) var_f1 = lbl_80562610;
    if (var_f31 < var_f1) return -1;
    return var_f31 > var_f1;
}

void fn_801B2C6C(void) {

}

void fn_801B2ED0(void) {
    fn_801B2EC0();
}

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
    void **obj = (void **)((u8 *)lbl_8055E684 + (arg0 << 7));
    void **vtable = *(void ***)obj;
    ((void (*)(void *))vtable[4])(obj);
    return *(s32 *)(obj + 4);
}

s32 fn_801B3050(s32 arg0) {
    return *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x6C);
}

extern f32 lbl_8055E3C8;
extern f32 lbl_8055E6AC;
f32 fn_801B306C(void) {
    register f32 a = lbl_8055E3C8;
    register f32 b = lbl_8055E6AC;
    return b - a;
}

void* fn_801B307C(void) {
    return lbl_8055E694;
}

void fn_801B3084(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    void *obj = lbl_8055E68C;
    s32 a = *(s32 *)((u8 *)arg0 + 0x1EC);
    s32 b = *(s32 *)((u8 *)arg1 + 0x1EC);
    if (obj != NULL) {
        void **vtable = *(void ***)obj;
        ((void (*)(void *, s32, s32, s32, s32))vtable[6])(obj, a, b, arg2, arg3);
    }
}

extern void fn_802E317C(const char *, s32, s32);
extern char lbl_80335BD8[];
extern void fn_801B196C(s32, s32);
extern void fn_801B18B8(s32, s32);
void fn_801B30C0(s32 arg0) {
    register void *base = lbl_8055E684;
    fn_801B18B8((s32)((u8 *)base + (arg0 << 7)), (s32)base);
}

void fn_801B30D0(s32 arg0) {
    fn_801B196C((s32)((u8 *)lbl_8055E684 + (arg0 << 7)), (s32)lbl_8055E684);
}

void fn_801B3208(s32 arg0, s32 arg1, f32 farg0) {
    fn_802E317C(lbl_80335BD8, arg0, arg1);
    *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x6C) = arg1;
    *(f32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x24) = farg0;
}

s32 fn_801B327C(void) { return 0; }

void fn_801B3284(void) {

}

u8 fn_801B3288(void *arg0) { return *(u8 *)((u8 *)arg0 + 0x2C); }

u32 fn_801B3290(void) { return 1; }

void fn_801B3298(void) {

}

