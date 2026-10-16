// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

extern s32 lbl_803582B0[];
s32 fn_802E6BD8(s32, s32, void*, s32, s32);
void *fn_80128668(void *);
void *fn_800197B0(void *arg0, s32 arg1) {
    if (arg0 != (void*)0) {
        *(s32*)arg0 = 0;
        *(s32*)((s8*)arg0 + 4) = 0;
        *(s32*)((s8*)arg0 + 8) = 0;
        if (arg1 > 0) {
            arg0 = fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_80019864(void) {
    fn_802E6BD8(0x52657030, 0, &lbl_803582B0, 0xC, 0);
}

void fn_80019884(void) {
    return;
}

s32 fn_80019888(void) {
    return 0;
}

