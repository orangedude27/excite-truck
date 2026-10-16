// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_80320548;
extern "C" s32 fn_80128668(void);

s32 fn_800DCE10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800DCE50(void **arg0) {
    arg0[0] = &lbl_80320548;
}

extern "C" s32 fn_800DCE60(void) {
    return 0;
}

void fn_800DCE68(void *arg0, void *arg1) {
    s16 v0 = ((s16 *)arg1)[0];
    s16 v1 = ((s16 *)arg1)[1];
    s16 v2 = ((s16 *)arg1)[2];
    s16 v3 = ((s16 *)arg1)[3];
    
    u8 b0 = (v0 < 0) ? 0 : (v0 > 0xFF) ? 0xFF : (u8)v0;
    u8 b1 = (v1 < 0) ? 0 : (v1 > 0xFF) ? 0xFF : (u8)v1;
    u8 b2 = (v2 < 0) ? 0 : (v2 > 0xFF) ? 0xFF : (u8)v2;
    u8 b3 = (v3 < 0) ? 0 : (v3 > 0xFF) ? 0xFF : (u8)v3;
    
    ((u8 *)arg0)[0] = b0;
    ((u8 *)arg0)[1] = b1;
    ((u8 *)arg0)[2] = b2;
    ((u8 *)arg0)[3] = b3;
}

