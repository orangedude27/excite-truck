#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8015474C(void);
extern s32 fn_80128668(void);

extern "C" {
void fn_80156188(s32 arg0) {
    fn_8015474C();
}

s32 fn_801568E0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80156920(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern f32 fn_80129DC4(s32, s32, s32, f32, f32);
extern f32 lbl_8055E3C8;

void fn_80156960(void *arg0) {
    s32 var_r29 = 0;
    void *var_r30 = arg0;
    f32 temp_f31 = lbl_8055E3C8;
    s32 r4 = ((s32 *)arg0)[2];  // offset 0x8
    f32 f1 = ((f32 *)arg0)[0xDC / 4];
    f32 f2 = ((f32 *)arg0)[0xE0 / 4];
    s32 r5 = ((s32 *)arg0)[1];  // offset 0x4
    
    do {
        s32 div_result = var_r29 / r4;
        s32 remainder = var_r29 - (div_result * r4);
        s32 offset = remainder * 8;
        s32 temp_r31 = ((s32 *)*((s32 *)r5 + offset / 4))[0];
        
        f32 call_result = fn_80129DC4(4, r4, r5, f1, f2);
        f32 result = temp_f31 + call_result;
        
        ((f32 *)var_r30)[0xE4 / 4] = result;
        ((s32 *)var_r30)[0xE8 / 4] = temp_r31;
        var_r30 = (void *)((u8 *)var_r30 + 8);
        var_r29++;
    } while (var_r29 < 8);
}
}

void fn_80156AC0(void) {

}

void fn_80156B48(void) {

}

void fn_80156B4C(void) {
    return;
}

void fn_80156B50(void) {
    return;
}

