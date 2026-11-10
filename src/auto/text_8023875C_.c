#include <stdarg.h>
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8023875C(int, int, const char *, int, int);
extern int fn_80232B70(int);
extern int fn_802344B0(void);
extern int fn_802346C8(void);
extern int fn_802344C4(int);
extern int fn_802C8BD0(int);
extern int fn_802C8D74(void);
extern int fn_802C92DC(int, int, int, int, int);
extern int lbl_8055F0D4;
extern float lbl_805636F0;
extern float lbl_805636F4;
extern unsigned char lbl_8055F0D8;
__declspec(section ".sdata") extern unsigned int lbl_8055CFF0;
__declspec(section ".sdata") extern unsigned int lbl_8055CFF4;
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
extern int fn_80232BA4(int, int, int, int, int, float, float, float, float, float);
extern int fn_802344CC(int, int, int, int, float, float, float);
void fn_8023875C(int x, int y, const char *text, int arg3, int arg4) {
    int halfWidth;
    int halfHeight;

    if ((fn_802344B0() != 0) &&
        ((unsigned int)(strlen(text) + 1) < 0x40U)) {
        halfHeight = (int)(((unsigned int)lbl_8055CFF4 >> 31) +
                           lbl_8055CFF4) >> 1;
        halfWidth = (int)(((unsigned int)lbl_8055CFF0 >> 31) +
                          lbl_8055CFF0) >> 1;
        fn_802344CC((int)text, arg3, arg4, 0,
                    (float)(x - halfWidth),
                    (float)(halfHeight - y), lbl_805636F0);
        return;
    }

    halfHeight = (int)(((unsigned int)lbl_8055CFF4 >> 31) +
                       lbl_8055CFF4) >> 1;
    halfWidth = (int)(((unsigned int)lbl_8055CFF0 >> 31) +
                      lbl_8055CFF0) >> 1;
    fn_80232BA4((int)text, lbl_8055F0D4, arg3, arg4, halfWidth,
                (float)(x - halfWidth), (float)(halfHeight - y),
                lbl_805636F0, lbl_805636F4, lbl_805636F8);
}

#pragma scheduling invalid_target
void fn_8023889C(void) {
    int values[2];
    int *var_r31;
    unsigned int var_r30;
    var_r31 = values;
    var_r30 = 0U;
    lbl_8055F0D9 = 1;
    values[0] = lbl_80563708;
    values[1] = lbl_8056370C;
    do {
        if (fn_8012C33C(*var_r31) != 0) {
            lbl_8055F0D4 = fn_80232578(values[var_r30]);
            return;
        }
        var_r30 += 1;
        var_r31++;
    } while (var_r30 < 2U);
}
#pragma scheduling on
void fn_80238920(void) {
    int value = *(volatile int *)&lbl_8055F0D4;
    lbl_8055F0D9 = 0;
    if (value != 0)
        fn_802328D4();
    lbl_8055F0D4 = 0;
}
#pragma scheduling invalid_target
void fn_8023895C(void) {
    float sp8[12];

    fn_802C974C(lbl_805636F8, lbl_80563710, lbl_80563714);
    fn_80230B5C(&sp8[0]);
    sp8[11] = (float)(-((int)(((lbl_8055CFF0 >> 31) + lbl_8055CFF0)) >> 1)) / lbl_8055FC88;
    ((void (*)(void *))fn_802C8638)(&sp8[0]);
    lbl_8055F0D8 = 1;
    fn_802344C4(1);
}
#pragma scheduling on
void fn_802389E4(void) {
    if (fn_802344B0())
        fn_802346C8();
    lbl_8055F0D8 = 0;
    fn_802344C4(0);
}
#pragma scheduling on
int fn_80238A20(void) {
    return (int)(lbl_805636F0 * (float)fn_80232B70(lbl_8055F0D4));
}

void fn_80238A74(int arg0, int arg1, int arg2, int arg3) { ((int (*)(int, int, int, int, int))fn_8023875C)(arg0, arg1 - 3, arg2, arg3, 9); }

void fn_80238A80(int arg0, int arg1, int arg2, const char *fmt, ...) {
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    ((void (*)(int, int, int, int))fn_80238A74)(arg0, arg1, (int)buffer, arg2);
}

#pragma use_lmw_stmw off
void fn_80238B44(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int halfX = 0;
    int halfY = 0;
    fn_802C8BD0(-1);
    halfY = (int)(((unsigned int)lbl_8055CFF4 >> 31) + lbl_8055CFF4) >> 1;
    halfX = (int)(((unsigned int)lbl_8055CFF0 >> 31) + lbl_8055CFF0) >> 1;
    fn_802C92DC(arg0 - halfX, halfY - arg1, arg2 - halfX, halfY - arg3, arg4);
    fn_802C8D74();
}
#pragma use_lmw_stmw on

#include <stdarg.h>
