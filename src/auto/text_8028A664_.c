// Code of main that had no source file yet: decomp.wtf gave it this one.
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

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
