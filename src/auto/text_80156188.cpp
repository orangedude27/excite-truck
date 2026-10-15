#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8015474C(void);
extern s32 fn_80128668(void);

extern "C" {
void fn_80156188(s32 arg0) {
    volatile s32 temp = arg0 - 4;
    (void)temp;
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
}

void fn_80156A48(void) {
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

