#include <types.h>
#pragma opt_tail_call on

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_800A6048();
s32 fn_800A61D0(void *);
s32 fn_800B75C4(void);
void fn_800C4BD0(void) __attribute__((noreturn));

extern u32 lbl_8055DDF8;

void fn_800A5954(void) {
    fn_800A6048();
}

void fn_800A5990(void) {
    fn_800A61D0(0);
}

void fn_800B78EC(void) {

}

void fn_800B7C60(void) {
    fn_800B75C4();
}

void fn_800C3D9C(void) {
    fn_800C4BD0();
}

extern "C" void fn_800CF280(void) {

}

extern "C" void fn_800CF288(void) {

}

extern "C" void fn_800CF28C(void) {

}

extern "C" void fn_800CF290(void) {

}

extern "C" void fn_800CF930(void) {

}

extern "C" void fn_800CF968(void) {

}

extern "C" void fn_800CF96C(void) {

}

extern "C" void fn_800D0BA0(void) {

}

extern "C" void fn_800D1200(void) {

}

extern "C" void fn_800D1558(void) {

}

void fn_800C7764(void *arg0, s8 arg1) {
    ((u8 *)arg0)[0x24] = (u8)arg1;
}

void fn_800C776C(void *arg0, s32 arg1) {
    ((u32 *)arg0)[0x24 / 4] = (u32)arg1;
}

void fn_800C790C(void *arg0) {
    u16 **ptr = *(u16 ***)((u8 *)arg0 + 4);
    u16 *var_r7 = ptr;
    s32 var_r9 = 0;
    s32 var_r10 = 0;
    s32 var_r11 = 0;
    s32 var_r8 = 0;
    
    while (*var_r7 != 0) {
        if (*var_r7 == 0x22) {
            *var_r7 = 0;
            if (var_r11 == 0) {
                s32 temp_r4 = var_r10 * 0x18;
                var_r10++;
                var_r11 = 1;
                ((u32 *)((u8 *)arg0 + temp_r4 + var_r8))[0xB0 / 4] = (u32)(ptr + (var_r9 + 1) * 2);
                if (var_r10 == 7) {
                    var_r10 = 0;
                    var_r8 += 4;
                }
            } else {
                var_r11 = 0;
            }
        }
        var_r7 += 2;
        var_r9++;
    }
}

extern "C" void fn_800C7C68(void) {
    r3 = lbl_8055DDF8;
}

