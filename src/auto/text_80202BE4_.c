// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

void fn_80203D84(s32* arg0);
void fn_80203DC8(void);
void fn_80203E88(void);
void fn_80203EC4(void);
extern void fn_802CAC54(s32);
extern void fn_802CB228(void);
extern void fn_802CB288(s32);
extern void fn_802CA294(s32);
extern void fn_802D050C(s32);
extern void fn_802D30DC(s32);
extern void fn_802D9230(void);
extern void fn_80203B20(void);
extern void fn_802D050C_var(void);
#define fn_802D050C(...) fn_802D050C_var()
extern s32 fn_80202BE4(void);
extern struct lbl_8048897C_t { s32 ptr; s32 count; } lbl_8048897C;
extern s32 lbl_8055ECFC;
extern s32 lbl_8055ED00;
extern s32 lbl_8055ED04;
extern s32 lbl_8055ED0C;
extern s8 lbl_8055ED18;

void fn_80203D84(s32* arg0) {
    s32 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}

void fn_80203DC8(void) {
    s32 var_r28;
    s32 var_r29;

    lbl_8055ED18 = 0;
    if (lbl_8055ECFC != -2) {
        fn_802CB228();
        lbl_8055ECFC = -2;
    }
    fn_80203D84(&lbl_8055ED00);
    fn_80203D84(&lbl_8055ED04);
    fn_80203D84(&lbl_8055ED0C);
    fn_802D050C(0);
    fn_802D30DC(0);
    var_r28 = 0;
    var_r29 = 0;
    while (var_r28 < lbl_8048897C.count) {
        fn_80203D84((s32*)lbl_8048897C.ptr + var_r29);
        var_r29 += 8;
        var_r28 += 1;
    }
    lbl_8048897C.count = 0;
}

extern void fn_802D050C(void*);
void fn_80203E88(void) {
    fn_80203B20();
    fn_802CA294(lbl_8055ECFC);
    fn_802D9230();
    fn_802CA294(lbl_8055ED04);
    fn_802D050C(0);
}

void fn_80203EC0(void) {

}

void fn_80203EC4(void) {
    if (fn_80202BE4() == 0) {
        fn_802CB288(lbl_8055ECFC);
    }
}

void fn_80203F0C(void) {

}

