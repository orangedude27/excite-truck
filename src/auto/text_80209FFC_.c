// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055EDDC;
void fn_8020A634(void) {
    lbl_8055EDDC = 0;
}

char fn_8020A640(void) {
    return lbl_8055EDDC;
}

extern void *lbl_8055EDE0;
void* fn_8020A69C(void) {
    return lbl_8055EDE0;
}

#include "types.h"

extern f32 lbl_8055EDD8;
void fn_8020A5F8(f32 arg0) {
    lbl_8055EDD8 = arg0;
}

s32 fn_802E2C20(void);
extern void fn_802E30C8(const char*, ...);
extern const char lbl_8033C318[];
extern s32 lbl_8055EDE4;
extern s32 lbl_8055EDE8;

void fn_8020A648(s32 arg0) {
    if (arg0 != lbl_8055EDE4) {
        fn_802E30C8(lbl_8033C318, arg0);
        lbl_8055EDE4 = arg0;
        lbl_8055EDE8 = fn_802E2C20();
    }
}

s32 fn_80127D58(void*);
s32 fn_8012E498(void*);
s32 fn_80207924(void);
int sprintf(char*, const char*, ...);
extern u8 fn_8020A100[];
extern s8 lbl_8055EDD0;
extern s8 lbl_8055EDD4;
extern s32 lbl_804892C0[];
extern s32 lbl_8055B560[];
extern char lbl_8055B568[];

void fn_8020A550(void) {
    char buf[80];
    s32* var_r29;
    s32* var_r30;
    s32 var_r27;
    s8* var_r28;

    fn_80127D58(&fn_8020A100);
    lbl_8055EDD0 = 0;
    var_r30 = lbl_804892C0;
    var_r27 = 0;
    var_r29 = lbl_8055B560;
    var_r28 = &lbl_8055EDD4;
    do {
        if (*var_r30 != 0) {
            fn_80207924();
            *var_r30 = 0;
        }
        sprintf(buf, lbl_8055B568, *var_r29);
        fn_8012E498(buf);
        var_r27++;
        *var_r28 = 0;
        var_r30++;
        var_r29++;
        var_r28++;
    } while (var_r27 < 2);
}

s32 fn_80128670(s32);
s32 fn_801336E0(s32, void*);
void fn_8020A634(void);
extern u8 fn_80209FFC[];
extern s32 lbl_8055B550;

void fn_8020A400(void) {
    s32* var_r30;
    s32 var_r29;

    fn_8020A634();
    fn_801336E0(lbl_8055B550, fn_80209FFC);
    lbl_8055B550 = -1;
    var_r30 = lbl_804892C0;
    var_r29 = 0;
    do {
        fn_80128670(var_r30[1]);
        var_r29++;
        var_r30[1] = 0;
        var_r30 = (s32*)((s8*)var_r30 + 8);
    } while (var_r29 < 2);
}

