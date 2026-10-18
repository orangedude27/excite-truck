// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80129C60(void) {

}

extern void *lbl_804223F8;
extern int fn_80129E34(void *, int, int);
extern int fn_80019B3C(void);
extern int fn_802E30C8(const char *, int, int, int);
extern char lbl_8032A5C0[];
extern void fn_80129C64(int);
extern float fn_8012A080(void *);
void fn_80129C64(int arg0) {
    fn_80129E34((char *)lbl_804223F8 + arg0 * 0x19C, 0x5AC2, 0x43DB);
}

void fn_80129C80(int arg0, int arg1, int arg2) {
    int value0 = arg1;
    int value1 = arg2;
    if (fn_80019B3C() != 0) {
        value0 = 0x29885B;
        value1 = 0x1A5A7D;
    } else {
        fn_802E30C8(lbl_8032A5C0, arg0, value0, value1);
    }
    fn_80129E34((char *)lbl_804223F8 + arg0 * 0x19C, value0, value1);
}

int fn_80129D18(int arg0, int arg1) {
    int result = arg1 - 1;
    int value = (int)((float)arg1 * fn_8012A080((char *)lbl_804223F8 + arg0 * 0x19C));
    if (value < result)
        result = value;
    return result;
}

#pragma dont_inline on
int fn_80129D90(int unused, int arg0, int arg1) {
    return arg0 + fn_80129D18(unused, arg1 - arg0);
}
#pragma dont_inline off
int fn_80129D18(int, int);
extern float lbl_80561258;
float fn_80129DC4(float arg0, float arg1) {
    return arg0 + (arg1 - arg0) * ((float)fn_80129D18(0, 100000) / lbl_80561258);
}

extern float lbl_8056125C;
extern float lbl_80561298;
float fn_8012A080(void *arg0) {
    int index0 = *(int *)((char *)arg0 + 0x194);
    int index1 = *(int *)((char *)arg0 + 0x198);
    float *value0 = (float *)((char *)arg0 + index0 * 4 + 4);
    float *value1 = (float *)((char *)arg0 + index1 * 4 + 4);
    float var_f3 = *value0 - *value1;
    float temp_f1;
    float temp_f2;
    if (var_f3 < lbl_8056125C)
        var_f3 += lbl_80561298;
    *value0 = var_f3;
    index0 = *(int *)((char *)arg0 + 0x194) - 1;
    *(int *)((char *)arg0 + 0x194) = index0;
    if (index0 < 0)
        *(int *)((char *)arg0 + 0x194) = 0x60;
    index1 = *(int *)((char *)arg0 + 0x198) - 1;
    *(int *)((char *)arg0 + 0x198) = index1;
    if (index1 < 0)
        *(int *)((char *)arg0 + 0x198) = 0x60;
    temp_f2 = *(float *)((char *)arg0 + 0x188);
    temp_f1 = *(float *)((char *)arg0 + 0x18C);
    temp_f1 = temp_f2 - temp_f1;
    *(float *)((char *)arg0 + 0x188) = temp_f1;
    if (temp_f1 < lbl_8056125C)
        *(float *)((char *)arg0 + 0x188) = temp_f1 + *(float *)((char *)arg0 + 0x190);
    temp_f1 = var_f3 - *(float *)((char *)arg0 + 0x188);
    if (temp_f1 < lbl_8056125C)
        return lbl_80561298 + temp_f1;
    return temp_f1;
}

