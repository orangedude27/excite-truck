// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma use_lmw_stmw off

extern char lbl_8055EDDC;
extern const char lbl_8033C308[];
extern void fn_802E30C8(const char*, ...);
#pragma dont_inline on
void fn_8020A634(void) {
    lbl_8055EDDC = 0;
}
#pragma dont_inline off

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

#pragma scheduling invalid_target
void fn_8020A600(void) {
    fn_802E30C8(lbl_8033C308);
    lbl_8055EDDC = 1;
}
#pragma scheduling on

s32 fn_802E2C20(void);
extern const char lbl_8033C318[];
extern s32 lbl_8055EDE4;
extern s32 lbl_8055EDE8;

#pragma scheduling off
void fn_8020A648(s32 arg0) {
    if (arg0 != lbl_8055EDE4) {
        fn_802E30C8(lbl_8033C318, arg0);
        lbl_8055EDE4 = arg0;
        lbl_8055EDE8 = fn_802E2C20();
    }
}
#pragma scheduling on
s32 fn_80127D58(void*);
s32 fn_8012E498(void*);
void fn_80207924();
int sprintf(char*, const char*, ...);
extern u8 fn_8020A100[];
extern s8 lbl_8055EDD0;
extern s8 lbl_8055EDD4;
extern s32 lbl_804892C0[];
extern s32 lbl_8055B560;
extern char lbl_8055B568;

void fn_8020A550(void) {
    char buf[64]; s32 var_r31; s32 *var_r30; s32 *var_r29; s8 *var_r28; s32 var_r27;
    fn_80127D58(fn_8020A100);
    var_r31=0; lbl_8055EDD0=var_r31; var_r30=lbl_804892C0; var_r27=0; var_r29=&lbl_8055B560; var_r28=&lbl_8055EDD4;
    do {
        if (*var_r30 != var_r31) { fn_80207924(); *var_r30=var_r31; }
        sprintf(buf,(char*)&lbl_8055B568,*var_r29);
        fn_8012E498(buf); var_r27+=1; *var_r28=var_r31;
        var_r30=(s32*)((s32)var_r30+8); var_r29=(s32*)((s32)var_r29+4); var_r28=(s8*)((s32)var_r28+1);
    } while(var_r27<2);
}

f32 fn_8020A5F0(void) {
    return lbl_8055EDD8;
}

s32 fn_80128670(s32);
s32 fn_801336E0(s32, void*);
void fn_8020A634(void);
void fn_80209FFC(void);
extern s32 lbl_8055B550;

extern char lbl_8055B578;
extern char lbl_8055B580;
extern const char lbl_8033C278[];
extern f32 lbl_80563290;
s32 fn_8012850C(s32, void*);
s32 fn_8013323C(s32, void*, f32);
s32 fn_8013365C(void*, void*);
s32 fn_8000DBC8(void*);
extern u8 fn_8020A03C[];
extern void fn_801331C4(int, void *, f32 *);
#pragma dont_inline on
void fn_80209FFC(void) {
    f32 value;

    value = fn_8020A5F0();
    fn_801331C4(4, (void *)lbl_8033C278, &value);
    fn_8020A5F8(value);
}
#pragma dont_inline off
void fn_8020A368(void) {
    s32* var_r31;
    s32 var_r30;
    f32 temp_f1;
    void *arg1;
    var_r31 = lbl_804892C0;
    var_r30 = 0;
    do {
        var_r31[1] = fn_8012850C(0x70, (void*)&lbl_8055B578);
        var_r30 += 1;
        var_r31 = (s32*)((s32)var_r31 + 8);
    } while (var_r30 < 2);
    temp_f1 = lbl_80563290;
    lbl_8055EDDC = 0;
    lbl_8055EDD8 = temp_f1;
    fn_8013323C(4, (void*)lbl_8033C278, temp_f1);
    arg1 = (void*)fn_80209FFC;
    lbl_8055B550 = fn_8013365C((void*)&lbl_8055B580, arg1);
    fn_8000DBC8((void*)fn_8020A03C);
}

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
        var_r29 += 1;
        var_r30[1] = 0;
        var_r30 = (s32*)((s32)var_r30 + 8);
    } while (var_r29 < 2);
}

extern int sprintf(char*, const char*, ...);
extern void fn_8012DDA8(void*);
extern void fn_8012E81C(void*);
extern void fn_80127C90(void*, const char*);
extern const char lbl_8033C2DC[];
extern const char lbl_8033C2F0[];
extern const char lbl_8055B588[];
void fn_8020A47C(void) {
    char name[8];
    char buf[0x58];
    s8* flag;
    s32* value;
    s32 i;
    s32 zero;

    fn_802E30C8(lbl_8033C2DC);
    zero = 0;
    lbl_8055EDE0 = (void*)zero;
    i = zero;
    lbl_8055EDD0 = 1;
    value = &lbl_8055B560;
    flag = &lbl_8055EDD4;
    lbl_8055EDE4 = zero;
    lbl_8055EDE8 = zero;
    do {
        sprintf(buf, &lbl_8055B568, *value);
        *flag = zero;
        fn_802E30C8(lbl_8033C2F0, buf);
        fn_8012DDA8(buf);
        i += 1;
        value++;
        flag++;
    } while (i < 2);
    fn_80127C90(fn_8020A100, lbl_8055B588);
    sprintf(name, &lbl_8055B568, lbl_8055B560);
    fn_8012E81C(name);
}

