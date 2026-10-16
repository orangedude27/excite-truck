#include <types.h>
#include <revolution/MTX/vec.h>

extern char lbl_8055E839;
  
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E7E2;
extern s32 lbl_8055E804;
extern f32 lbl_805629CC;
extern u8* fn_8017960C(s32);
extern Vec lbl_80438268;
extern char lbl_804380F0[256];
extern f32 lbl_8055E834;
extern f32 lbl_8055F47C;
extern s32 lbl_80499050[12];
extern s32 lbl_804381F0[12];
char fn_801C5B60(void) {
    return lbl_8055E7E2;
}

s32 fn_801C6C28(Vec* arg0) {
    f32 var_f31 = lbl_805629CC;
    s32 var_r31 = -1;
    s32 var_r30 = 0;
    Vec* var_r29 = arg0;
    
loop_top:
    if (PSVECSquareDistance((Vec*)(fn_8017960C(var_r30) + 0x60), var_r29) >= var_f31) {
        var_r30++;
        if (var_r30 < lbl_8055E804) {
            goto loop_top;
        }
    } else {
        var_r31 = var_r30;
    }
    return var_r31;
}

void fn_801C6CB0(void) {
    return;
}

void fn_801C6CB4(void) {
    fn_801C957C(1);
}

void fn_801C6CBC(void) {
    sprintf(lbl_804380F0, "%s %d", lbl_804380F0, fn_801C6C28(&lbl_80438268));
}

void fn_801C6D00(void) {
    s32* src = lbl_80499050;
    s32* dst = lbl_804381F0;
    s32 i;
    for (i = 0; i < 12; i++) {
        dst[i] = src[i];
    }
    lbl_8055E834 = lbl_8055F47C;
}

void fn_801C7288(void);
void fn_801C7288(void) {
    fn_801C957C(0);
}

void fn_801C7374(void);
void fn_801C7374(void) {
    fn_801C957C(0);
}

void fn_801C737C(void) {
    lbl_8055E839 = 1;
}

extern char lbl_8055E839;
void fn_801C7388(void) {
    lbl_8055E839 = 0;
}

void fn_801C94B8(void) {
    fn_80238A74();
}

void fn_801C94BC(void) {
    fn_80238B44();
}

void fn_801C9830(void) {
    return;
}

void fn_801C98F0(void) {
    fn_801C9444();
}

