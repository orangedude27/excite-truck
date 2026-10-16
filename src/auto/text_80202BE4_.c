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
extern u32 fn_80202BE4(void);
typedef struct { s32 w0; s32 w1; } lbl_8048897C_entry;
struct lbl_8048897C_t { lbl_8048897C_entry* ptr; s32 count; s32 unk_08; s32 unk_0C; };
extern struct lbl_8048897C_t lbl_8048897C;
extern s32 lbl_8055ECFC;
extern s32 lbl_8055ED00;
extern s32 lbl_8055ED04;
extern s32 lbl_8055ED0C;
extern u8 lbl_8055ED10;
extern s32 lbl_8055ED14;
#pragma dont_inline on
extern s8 lbl_8055ED18;
extern s32 lbl_8055ED1C;
extern f32 lbl_80563130;
struct lbl_80488B88_t { s32 w[12]; };
extern struct lbl_80488B88_t lbl_80488B88;
extern void fn_80202BFC(s32);
extern void fn_80203380(void*);
extern void fn_802036E4(void);
extern s32 fn_802BE07C(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 fn_802C8BD0(s32);
extern void fn_802C8D74(void);
extern void fn_802D3050(s32);
extern void fn_802D306C(s32);
typedef struct { u8 pad[0x24]; f32 x; f32 y; f32 z; } unk_80203A88_dest;
void fn_802039CC(s32 arg0, struct lbl_80488B88_t* arg1);

void fn_802039CC(s32 arg0, struct lbl_80488B88_t* arg1) {
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r8;
    s32 temp_r9;
    s32 temp_r10;

    lbl_8055ED1C = -1;
    fn_802C8BD0(-1);
    temp_r10 = arg1->w[5];
    temp_r9 = arg1->w[6];
    temp_r8 = arg1->w[7];
    temp_r7 = arg1->w[8];
    temp_r6 = arg1->w[9];
    temp_r5 = arg1->w[10];
    lbl_80488B88 = *arg1;
    fn_802BE07C(arg0 + 0x24, (s32)fn_802036E4, temp_r5, temp_r6, temp_r7, temp_r8, temp_r9, temp_r10);
    fn_802C8D74();
}

void fn_80203A88(void* arg0, s32 arg1, unk_80203A88_dest* arg2) {
    f32 var_f2;
    f32 var_f3;
    f32 var_f1;

    if (fn_80202BE4() == 0) {
        fn_802D3050(1);
        fn_802D306C(0x5A);
        var_f2 = ((f32*)arg0)[1];
        var_f3 = ((f32*)arg0)[0];
        var_f1 = ((f32*)arg0)[2];
        arg2->x = var_f3;
        arg2->z = var_f1;
        arg2->y = var_f2 + lbl_80563130;
        fn_802039CC(arg1, (struct lbl_80488B88_t*)arg2);
        fn_80203380(arg2);
        fn_802D306C(0);
    }
}

void fn_80203D84(s32* arg0) {
    s32 temp_r0;

    temp_r0 = *arg0;
    if (temp_r0 != -2) {
        fn_802CAC54(temp_r0);
        *arg0 = -2;
    }
}
#pragma dont_inline off

void fn_80203DC8(void) {
    struct lbl_8048897C_t* var_r30;
    struct lbl_8048897C_t* var_r31;
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
    ((void(*)(void*))fn_802D050C)(0);
    fn_802D30DC(0);
    var_r30 = (struct lbl_8048897C_t*)((s32)&lbl_8048897C - 0x8000);
    var_r31 = (struct lbl_8048897C_t*)((s32)var_r30 + 0x8000);
    var_r28 = 0;
    var_r29 = 0;
    while (var_r28 < var_r31->count) {
        fn_80203D84((s32*)((u8*)lbl_8048897C.ptr + var_r29));
        var_r29 += 8;
        var_r28 += 1;
    }
    var_r31->count = 0;
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

void fn_80203EF4(void) {
    if (lbl_8055ED10 == 0) {
        return;
    }
    fn_80202BFC(lbl_8055ECFC);
}

void fn_80203F0C(void) {

}

