#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80235380(void *);
extern s32 lbl_8055F8BC;
extern s32 lbl_8055F8C0;
extern void fn_802328D4(s32);
extern long fn_80232578(void *);
extern long fn_8023512C(void *);
extern long lbl_80349CF0[];
extern long lbl_80349CFC[];
void fn_802A7BE8(void) {
    lbl_8055F8BC = fn_80232578(&lbl_80349CF0);
    lbl_8055F8C0 = fn_8023512C(&lbl_80349CFC);
}

void fn_802A7C24(void) {
    fn_802328D4(lbl_8055F8BC);
    lbl_8055F8BC = 0;
    fn_80235380((void *)lbl_8055F8C0);
    lbl_8055F8C0 = 0;
}

void fn_802A7C64(void) {
}

void fn_802A7EEC(void);
void fn_802A7C68(void) {
    if ((fn_801C5B60() == 0) &&
        ((u32)(*(u32 *)((u8 *)fn_801E87A8() + 4) + 0xFFE80000) != 0x304U)) {
        fn_802A7EEC();
    }
}

extern float lbl_8042F8A8[];
extern float lbl_8042F8B8[];
extern int lbl_8055E170;
extern float lbl_80561474, lbl_80561478, lbl_8056147C;
extern void *fn_801EA9A0(void);
extern void fn_8013B7B4(void*, int);
extern void fn_8013B6C0(int*, float*, int);
void fn_802A7CA8(float farg0, int arg1) {
    int sp14, sp1c;
    float sp18, sp8;
    int *base;
    int i, n;
    float t, x, v;
    *((unsigned char*)lbl_8042F8A8 + 4) = 0;
    fn_8013B7B4(&sp14, arg1);
    fn_8013B6C0(&sp14, &sp8, *(int*)((char*)fn_801EA9A0() + 0xC));
    base = (int*)((char*)&sp14 + sp14 * 16);
    x = sp8;
    lbl_8042F8B8[0] = *(float*)&base[0] + x * (*(float*)&base[4] - *(float*)&base[0]);
    lbl_8042F8B8[1] = *(float*)&base[1] + x * (*(float*)&base[5] - *(float*)&base[1]);
    lbl_8042F8B8[2] = *(float*)&base[2] + x * (*(float*)&base[6] - *(float*)&base[2]);
    v = *(float*)&base[3] + x * (*(float*)&base[7] - *(float*)&base[3]);
    lbl_8042F8B8[3] = v;
    t = farg0 - lbl_80561474;
    t = t / lbl_80561478;
    if (t < lbl_80561474) t = lbl_80561474;
    if (t > lbl_8056147C) t = lbl_8056147C;
    i = (int)(lbl_80561474 + t * lbl_80561478) * 0; 
    i = (int)(lbl_80561474 + t * lbl_80561478);
    n = 1;
    if (i > 1) n = i;
    i = arg1 - 1;
    if (n < i) i = n;
    lbl_8055E170 = i;
    if (lbl_8042F8B8[2] >= lbl_80561474) lbl_8042F8B8[2] = lbl_80561474;
}

