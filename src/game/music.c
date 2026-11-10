// music — music playback ("music: play!", player_music_vol).
// Recovered TU window 0x80209FFC..0x8020A6A4+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_8020A6A4 (+ .ctors slot 0x802ED38C) remains in
// auto/text_8020A6A4_.c pending a promotion pass.
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

#pragma scheduling invalid_target
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
void fn_8020A100(void);
extern void fn_8012E81C(void*);
extern void *fn_802078CC(char*, s32, s32, s32);
extern s32 fn_8012E938(char*);
extern char lbl_8055B570;
extern char lbl_8055B574;
extern const char lbl_8033C2A8[];
extern const char lbl_8033C2B4[];
extern f32 lbl_80563294;
extern f32 lbl_80563298;
extern f32 lbl_8056329C;
extern f32 lbl_805632A0;
extern f32 lbl_80563290;
extern u8 lbl_8055EDD0;
extern s8 lbl_8055EDD4;
extern s32 lbl_804892C0[];
extern s32 lbl_8055B560;
extern char lbl_8055B568;

void fn_8020A550(void) {
    char buf[64];
    s32 var_r31;
    s32 *var_r30;
    s32 *var_r29;
    s8 *var_r28;
    s32 var_r27;

    fn_80127D58(fn_8020A100);
    var_r31 = 0;
    lbl_8055EDD0 = var_r31;
    var_r30 = lbl_804892C0;
    var_r27 = 0;
    var_r29 = &lbl_8055B560;
    var_r28 = &lbl_8055EDD4;
    do {
        if (*var_r30 != 0) {
            fn_80207924((void *)*var_r30);
            *var_r30 = var_r31;
        }
        sprintf(buf, (char *)&lbl_8055B568, *var_r29);
        fn_8012E498(buf);
        var_r27 += 1;
        *var_r28 = var_r31;
        var_r30 = (s32 *)((s32)var_r30 + 8);
        var_r29 = (s32 *)((s32)var_r29 + 4);
        var_r28 = (s8 *)((s32)var_r28 + 1);
    } while (var_r27 < 2);
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

#pragma opt_propagation off
void fn_8020A100(void) {
    char buf[0x40];
    u8 *obj;
    s32 *name;
    u8 *flag;
    s32 *slot;
    s32 i;
    s32 diff;
    s32 zero;
    f32 scale;
    f32 one;
    f32 t;
    if (lbl_8055EDD0 != 0) {
        scale = lbl_80563294;
        diff = fn_802E2C20() - lbl_8055EDE8;
        if ((s32)lbl_8055EDE0 != lbl_8055EDE4) {
            if (diff >= 0x190 || diff < 0 || (s32)lbl_8055EDE0 == -1) {
                lbl_8055EDE0 = (void *)lbl_8055EDE4;
            } else {
                t = lbl_80563294 < ((f32)diff / lbl_80563298 - lbl_8056329C) / lbl_80563290 ? lbl_80563294 : ((f32)diff / lbl_80563298 - lbl_8056329C) / lbl_80563290;
                t = t > lbl_8056329C ? t : lbl_8056329C;
                scale = lbl_80563294 + t * lbl_805632A0;
            }
        }
        one = lbl_8056329C;
        slot = lbl_804892C0;
        i = 0;
        flag = (u8 *)&lbl_8055EDD4;
        name = &lbl_8055B560;
        zero = 0;
        do {
            if (*flag == 0) {
                sprintf(buf, &lbl_8055B568, *name);
                if (fn_8012E938(buf) != 0) {
                    fn_8012E81C(buf);
                    sprintf(buf, lbl_8033C2A8, *name, zero == 1 ? &lbl_8055B570 : &lbl_8055B574);
                    slot[0] = (s32)fn_802078CC(buf, 0, slot[1], 0x70);
                    fn_802E30C8(lbl_8033C2B4, i, 0, buf, slot[0]);
                    *flag = 1;
                }
            }
            obj = (u8 *)slot[0];
            if (obj != 0) {
                f32 v = lbl_8055EDD8 * scale;
                if (v != *(f32 *)(obj + 8)) {
                    obj[0x4D] = 1;
                    *(f32 *)(obj + 8) = v;
                }
                if (one != *(f32 *)(obj + 0x64)) {
                    obj[0x6C] = 1;
                    *(f32 *)(obj + 0x64) = one;
                }
                if (one != *(f32 *)(obj + 0x68)) {
                    obj[0x6D] = 1;
                    *(f32 *)(obj + 0x68) = one;
                }
                if (i == (s32)lbl_8055EDE0 && lbl_8055EDDC != 0) {
                    obj[0x4A] = 0;
                    obj[0x4B] = 1;
                    obj[0x49] = 1;
                } else {
                    obj[0x4A] = 1;
                    obj[0x4C] = 0;
                }
            }
            i++;
            slot += 2;
            flag++;
            name++;
        } while (i < 2);
    }
}
#pragma opt_propagation reset
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
extern const char lbl_8055B588;
void fn_8020A47C(void) {
    struct {
        char name[8];
        char pad[0x38];
        char buf[0x38];
    } local;
    s32 *value;
    s8 *flag;
    s32 i;
    s32 zero;

    fn_802E30C8(lbl_8033C2DC);
    zero = 0;
    lbl_8055EDE0 = (void *)zero;
    i = zero;
    lbl_8055EDD0 = 1;
    value = &lbl_8055B560;
    flag = &lbl_8055EDD4;
    lbl_8055EDE4 = zero;
    lbl_8055EDE8 = zero;
    do {
        sprintf(local.buf, &lbl_8055B568, *value);
        *flag = zero;
        fn_802E30C8(lbl_8033C2F0, local.buf);
        fn_8012DDA8(local.buf);
        i += 1;
        value++;
        flag++;
    } while (i < 2);
    fn_80127C90(fn_8020A100, &lbl_8055B588);
    sprintf(local.name, &lbl_8055B568, lbl_8055B560);
    fn_8012E81C(local.name);
}

