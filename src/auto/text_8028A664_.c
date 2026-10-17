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
extern void fn_8028C938(s32);

extern void fn_80288A70(void *, f32 *);
extern void fn_8028AA6C(void *, s32, f32);
extern s32 lbl_8055F700;
extern f32 lbl_8056434C;

extern s32 fn_80128668(void);
s32 fn_8028A85C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8028A92C(void) {
    s32 i;
    fn_8028BD5C(lbl_8055F6F0);
    fn_8028BD5C(lbl_8055F6F4);
    fn_8028C938(lbl_8055F6F8);
    ((void (*)(void *))(*(void ***)lbl_8055F6FC)[4])(lbl_8055F6FC);
    for (i = 0; i < 8; i++) {
        struct Obj8028 *p = *(struct Obj8028 **)((u8 *)lbl_804B3238 + i * 0x10);
        if (p) ((void (*)(void *))p->vtable[4])(p);
    }
}

void fn_8028A9BC(void) {
    fn_8028BD60(lbl_8055F6F0);
    fn_8028BD60(lbl_8055F6F4);
    fn_8028CA70(lbl_8055F6F8);
    fn_8028AB14();
}

void fn_8028A9F4(void) {
    s32 i;
    ((void (*)(void *))(*(void ***)lbl_8055F6FC)[5])(lbl_8055F6FC);
    for (i = 0; i < 8; i++) {
        struct Obj8028 *p = *(struct Obj8028 **)((u8 *)lbl_804B3238 + i * 0x10);
        if (p) ((void (*)(void *))p->vtable[5])(p);
    }
}

extern s32 lbl_8055F704;
extern void fn_8028E398();
void fn_8028B4CC(void) {
    if (lbl_8055F704 != 0) {
        fn_8028E398(lbl_8055F704);
        lbl_8055F704 = 0;
    }
}

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

extern f32 fn_801E7E18(void);
extern s32 lbl_804B32B8[];
extern f32 lbl_805643A0;
extern f32 lbl_80564394;
extern s32 fn_80287B94(s32, s32, f32, f32, f32);
extern s32 fn_8028CD80(s32, s32, void *, f32 *, f32);
s32 fn_8028BA9C(void *arg0) {
    f32 values[3];
    s32 temp;
    values[0] = *(f32 *)((u8 *)arg0 + 0xC) * lbl_805643A0;
    values[1] = *(f32 *)((u8 *)arg0 + 0x10) * lbl_805643A0;
    values[2] = *(f32 *)((u8 *)arg0 + 0x14) * lbl_805643A0;
    temp = fn_80287B94(0x18, 0x30, values[0], values[1], values[2]);
    fn_8028CD80(lbl_8055F6F8, temp, arg0, values, lbl_80564394);
    return 0x1C;
}

void fn_8028BC18(void) {
}

void fn_8028C8BC(void) {}

extern void fn_802CAC54(s32);
extern void fn_80128670(s32);
extern s32 fn_8028BFEC(void);
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

