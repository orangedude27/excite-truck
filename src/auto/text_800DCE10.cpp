// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 lbl_80320548;
extern "C" s32 fn_80128668(void);

extern "C" s32 fn_800DCE10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_800DCE50(void **arg0) {
    *arg0 = (void *)&lbl_80320548;
}

extern "C" s32 fn_800DCE60(void) {
    return 0;
}

extern "C" void fn_800DCE68(void *arg0, void *arg1) {
    s16 r5 = ((s16 *)arg1)[0];
    s16 r6 = ((s16 *)arg1)[1];
    s16 r7 = ((s16 *)arg1)[2];
    s16 r4 = ((s16 *)arg1)[3];
    
    u8 r0, r0_2, r0_3, r0_4;
    
    if (r5 < 0) {
        r0 = 0;
    } else if (r5 > 0xFF) {
        r0 = 0xFF;
    } else {
        r0 = (u8)r5;
    }
    
    if (r6 < 0) {
        r0_2 = 0;
    } else if (r6 > 0xFF) {
        r0_2 = 0xFF;
    } else {
        r0_2 = (u8)r6;
    }
    
    if (r7 < 0) {
        r0_3 = 0;
    } else if (r7 > 0xFF) {
        r0_3 = 0xFF;
    } else {
        r0_3 = (u8)r7;
    }
    
    if (r4 < 0) {
        r0_4 = 0;
    } else if (r4 > 0xFF) {
        r0_4 = 0xFF;
    } else {
        r0_4 = (u8)r4;
    }
    
    ((u8 *)arg0)[0] = r0;
    ((u8 *)arg0)[1] = r0_2;
    ((u8 *)arg0)[2] = r0_3;
    ((u8 *)arg0)[3] = r0_4;
}

