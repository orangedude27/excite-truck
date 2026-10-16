#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_801B2EC0(void);
extern void *lbl_8055E678;
extern void *lbl_8055E680;
extern void *lbl_8055E684;
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
    *(u8 *)((u8 *)arg0 + 0x2C) = 0;
    *(f32 *)((u8 *)arg0 + 0x30) = lbl_805625F0;
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
    s32 var_r30 = 0;
    s32 var_r31 = 1;

    if (lbl_8055E68C != NULL) {
        void **obj = (void **)lbl_8055E68C;
        void **vtable = *(void ***)obj;
        s32 (*method)(void *, s32) = (s32 (*)(void *, s32))vtable[5];
        if (method(obj, *(s32 *)((u8 *)lbl_8055E684 + (arg0 << 7) + 0x7C)) != 0) {
            var_r30 = 1;
        }
    }
    if (var_r30 == 0) {
        s32 var_r3 = 0;
        if (lbl_8055E68C == NULL && lbl_8055E690 != 0) {
            var_r3 = 1;
        }
        if (var_r3 == 0) {
            var_r31 = 0;
        }
    }
    return var_r31;
}

s32 fn_801B1310(s32 arg0) { return arg0 + 4; }

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

void* fn_801B307C(void) {
    return lbl_8055E694;
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

u32 fn_801B3290(void) { return 1; }

void fn_801B3298(void) {

}

