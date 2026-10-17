// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "revolution/MTX/vec.h"
extern int lbl_8055ECC0;
extern int lbl_8055ECC4;
extern int lbl_8055ECC8;
extern int lbl_8055ECCC;
extern int lbl_8055ECD0;
extern unsigned char lbl_8055ECE0;
extern void fn_802CE6C0(int);
extern int fn_802CE49C(int);
extern int fn_802CE850(int);
extern int fn_80128670(int);
extern void *fn_801E87A8(void);
extern int fn_802C9C58(int);
extern void fn_802C7A44(void);
extern int fn_802C7040(int);
extern void fn_802C7A50(void);
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

int fn_802022E4(const Vec *arg0) {
    f32 temp_f1;
    f32 var_f31;
    s32 var_r29;
    s32 var_r30;
    s32 var_r31;
    var_f31 = lbl_805630A0;
    var_r31 = 0;
    var_r30 = 0;
    var_r29 = 0;
    do {
        temp_f1 = PSVECSquareDistance(arg0, (const Vec *)(lbl_8055ECC4 + var_r31));
        if (temp_f1 < var_f31) {
            var_f31 = temp_f1;
            var_r30 = var_r29;
        }
        var_r31 += 0x10;
        var_r29 += 1;
    } while (var_r29 < lbl_8055ECC0);
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

extern unsigned char lbl_8055ECE0;
extern int lbl_8055ECC8, lbl_8055ECCC, lbl_8055ECD0;
extern int lbl_804888E0[];
int fn_802CE850(int);
void fn_802CE6C0(int);
int fn_802CE49C(int);
int fn_80128670(int);
void fn_802022A0(int *);
void *fn_801E87A8(void);
int fn_802C9C58(int);
void fn_802C7A44(void);
int fn_802C7040(int);
void fn_802C7A50(void);
void fn_80202AD4(float *arg0) {
    ((float *)lbl_80488964)[0] = arg0[0];
    ((float *)lbl_80488964)[1] = arg0[1];
    ((float *)lbl_80488964)[2] = arg0[2];
    lbl_8055ECE0 = 1;
}

int fn_80202B00(void) {
    int count, index, offset;
    if (lbl_8055ECC0 <= 0) return 0;
    count = index = offset = 0;
    do {
        if (fn_802CE850(*(int *)(lbl_8055ECC4 + offset + 12)) == 1) count++;
        offset += 16;
        index++;
    } while (index < lbl_8055ECC0);
    return count;
}

