#include <types.h>
#include <math.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern f32 lbl_8055E3C8;
extern f32 lbl_80560470;
extern f32 lbl_80560474;

extern s32 fn_80128668(void);
extern void **lbl_80358680;
extern s32 lbl_8055E3C4;
extern f32 lbl_80560460;
extern f32 lbl_80560464;
extern f64 lbl_80560468;
f32 fn_8001DA5C(s32 arg0) {
    f64 var_f3 = lbl_80560468;
    f64 var_f0;
    f64 var_f2;
    f32 var_f1;
    u32 var_r0;
    s32 var_r5;
    
    var_r0 = arg0 ^ 0x8000;
    var_f1 = lbl_80560460;
    var_r5 = lbl_8055E3C4 / arg0;
    
    // Load double from stack: 0x43300000 followed by var_r0 bytes
    union {
        f64 d;
        u32 u[2];
    } u0;
    u0.u[0] = 0x43300000;
    u0.u[1] = var_r0;
    var_f0 = u0.d - var_f3;
    
    union {
        f64 d;
        u32 u[2];
    } u2;
    u2.u[0] = 0x43300000;
    // For u2, the upper word comes from stack+0xC which hasn't been written yet
    // This is tricky - need to figure out what value is there
    
    var_f2 = u2.d - var_f3;
    
    var_f1 = var_f1 * var_f2 / var_f0;
    var_f1 = (f32)sin((f64)var_f1);
    
    return lbl_80560464 + lbl_80560464 * var_f1;
}

f32 fn_8001DAE8(void) {
    return lbl_8055E3C8;
}

extern "C" s32 fn_8001DD2C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_8001DEA8(void) {
    u32 var_r30;
    void ***var_r31;
    
    var_r31 = (void ***)lbl_80358680;
    var_r30 = 0;
    do {
        void **temp = var_r31[0];
        ((void (**)(void *))temp)[4](temp);
        var_r30++;
        var_r31++;
    } while (var_r30 < 6);
}

void fn_8001DF04(void) {

}

extern "C" s32 fn_8001E26C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_8001E974(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" s32 fn_8001ED78(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

