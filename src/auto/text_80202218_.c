// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "revolution/MTX/vec.h"
extern int lbl_8055ECC0;
extern int lbl_8055ECC4;
extern float lbl_805630A0;
extern unsigned char lbl_80488964[];
extern void fn_802C6CF8(int);

void fn_802022A0(int *arg0) {
    int temp_r0 = *arg0;
    if (temp_r0 != -1) {
        fn_802C6CF8(temp_r0);
        *arg0 = -1;
    }
}

int fn_802022E4(const void *arg0) {
    float temp_f1;
    float var_f31;
    int var_r29;
    int var_r30;
    int var_r31;
    var_f31 = lbl_805630A0;
    var_r31 = 0;
    var_r30 = 0;
    var_r29 = 0;
loop_4:
    if (var_r29 < lbl_8055ECC0) {
        temp_f1 = PSVECSquareDistance(arg0, (const void *)(lbl_8055ECC4 + var_r31));
        if (temp_f1 < var_f31) {
            var_f31 = temp_f1;
            var_r30 = var_r29;
        }
        var_r31 += 0x10;
        var_r29 += 1;
        goto loop_4;
    }
    return var_r30;
}

int fn_80202378(int arg0, int arg1, int arg2, int arg3) {
    if (arg3 >= lbl_8055ECC0) return -1;
    if (arg3 >= (arg1 * 2) + 1) return -1;
    return ((arg2 * (arg3 - arg1)) + ((lbl_8055ECC0 * 0x64) + arg0)) % lbl_8055ECC0;
}

void *fn_802023C8(void) { return lbl_80488964; }

void fn_802025D4(void) {

}
