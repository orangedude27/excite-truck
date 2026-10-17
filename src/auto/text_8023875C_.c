// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_8023875C(int, int);
extern int fn_80232B70(int);
extern int fn_802344B0(void);
extern int fn_802346C8(void);
extern int fn_802344C4(int);
extern int fn_802C8BD0(int);
extern int fn_802C8D74(void);
extern int fn_802C92DC(int, int, int, int, int);
extern int lbl_8055F0D4;
extern float lbl_805636F0;
extern unsigned char lbl_8055F0D8;
extern unsigned int lbl_8055CFF0;
extern unsigned int lbl_8055CFF4;
extern int fn_802328D4(void);
extern int fn_80230B5C(void *);
extern int fn_802C974C(float, float, float);
extern int fn_802C8638(void *, unsigned int, float);
extern int fn_8012C33C(int);
extern int fn_80232578(int);
extern unsigned char lbl_8055F0D9;
extern float lbl_8055FC88;
extern float lbl_805636F8;
extern float lbl_80563710;
extern float lbl_80563714;
extern double lbl_80563700;
extern int lbl_80563708;
extern int lbl_8056370C;
void fn_8023889C(void) {
    int sp8;
    int spC;
    int i = 0;
    register int one = 1;
    sp8 = lbl_80563708;
    spC = lbl_8056370C;
    lbl_8055F0D9 = one;
    do {
        if (fn_8012C33C(*(int *)((char *)&sp8 + i * 4)) != 0) {
            lbl_8055F0D4 = fn_80232578(*(int *)((char *)&sp8 + i * 4));
            break;
        }
        i++;
    } while (i < 2);
}

void fn_80238920(void) {
    lbl_8055F0D9 = 0;
    if (lbl_8055F0D4 != 0)
        fn_802328D4();
    lbl_8055F0D4 = 0;
}

void fn_8023895C(void) {
    volatile float sp34;
    int sp8[8];
    fn_802C974C(lbl_805636F8, lbl_80563710, lbl_80563714);
    fn_80230B5C(&sp8[0]);
    sp34 = (float)(-((int)(((lbl_8055CFF0 >> 31) + lbl_8055CFF0)) >> 1)) / lbl_8055FC88;
    fn_802C8638(&sp8[0], lbl_8055CFF0, sp34);
    lbl_8055F0D8 = 1;
    fn_802344C4(1);
}

void fn_802389E4(void) {
    if (fn_802344B0()) fn_802346C8();
    lbl_8055F0D8 = 0;
    fn_802344C4(0);
}

int fn_80238A20(void) {
    return (int)(lbl_805636F0 * (float)fn_80232B70(lbl_8055F0D4));
}

void fn_80238A74(int arg1) { fn_8023875C(arg1 - 3, 9); }
#include <stdarg.h>
