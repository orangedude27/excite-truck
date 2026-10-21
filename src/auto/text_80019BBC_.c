// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma small_data off
extern int lbl_803583C8;
#pragma small_data on
extern int fn_8001B478(float);
extern void *fn_80156A40(void);
extern float lbl_80560418;
extern float lbl_8056041C;
extern float lbl_803582C0;
extern double cos(double);
extern double sin(double);
void fn_80019BBC(void) {
    float angle = lbl_80560418;
    float step = lbl_8056041C;
    float initial = angle;
    float *p = &lbl_803582C0;
    int i = 0;
    do {
        *p++ = (float)cos(angle);
        p[0] = (float)sin(angle);
        p[1] = initial;
        p += 2;
        angle += step;
        i++;
    } while (i < 20);
    ((float *)&lbl_803582C0)[60] = lbl_80560418;
    ((float *)&lbl_803582C0)[61] = lbl_80560418;
    ((float *)&lbl_803582C0)[62] = lbl_80560418;
}

void fn_8001A1F0(void) {
}

#pragma small_data off
int fn_8001B308(void *arg0, int arg1, int arg2) {
    unsigned char *var_r7;
    int temp_r8;
    int temp_r8_2;
    int temp_r8_3;
    int var_ctr;
    int var_r6;
    int var_r6_2;
    int var_r6_3;
    int var_r6_4;
    int var_r8;

    var_ctr = 4;
    var_r7 = (unsigned char *)&lbl_803583C8;
    var_r8 = 0;
loop_1:
    if (var_r7[0x10] == 0) {
        *(int *)(var_r7 + 0) = arg1;
        var_r6 = 1;
        *(int *)(var_r7 + 4) = arg2;
        *(float *)(var_r7 + 8) = *(float *)arg0;
        *(float *)(var_r7 + 0xC) = *((float *)arg0 + 1);
        var_r7[0x10] = 1;
    } else {
        var_r6 = 0;
    }
    if (var_r6 != 0) {
        return var_r8;
    }
    temp_r8_3 = var_r8 + 1;
    if (var_r7[0x24] == 0) {
        *(int *)(var_r7 + 0x14) = arg1;
        var_r6_2 = 1;
        *(int *)(var_r7 + 0x18) = arg2;
        *(float *)(var_r7 + 0x1C) = *(float *)arg0;
        *(float *)(var_r7 + 0x20) = *((float *)arg0 + 1);
        var_r7[0x24] = 1;
    } else {
        var_r6_2 = 0;
    }
    if (var_r6_2 != 0) return temp_r8_3;
    temp_r8_2 = temp_r8_3 + 1;
    if (var_r7[0x38] == 0) {
        *(int *)(var_r7 + 0x28) = arg1;
        var_r6_3 = 1;
        *(int *)(var_r7 + 0x2C) = arg2;
        *(float *)(var_r7 + 0x30) = *(float *)arg0;
        *(float *)(var_r7 + 0x34) = *((float *)arg0 + 1);
        var_r7[0x38] = 1;
    } else {
        var_r6_3 = 0;
    }
    if (var_r6_3 != 0) return temp_r8_2;
    temp_r8 = temp_r8_2 + 1;
    if (var_r7[0x4C] == 0) {
        *(int *)(var_r7 + 0x3C) = arg1;
        var_r6_4 = 1;
        *(int *)(var_r7 + 0x40) = arg2;
        *(float *)(var_r7 + 0x44) = *(float *)arg0;
        *(float *)(var_r7 + 0x48) = *((float *)arg0 + 1);
        var_r7[0x4C] = 1;
    } else {
        var_r6_4 = 0;
    }
    if (var_r6_4 != 0) return temp_r8;
    var_r7 += 0x50;
    var_r8 = temp_r8 + 1;
    var_ctr -= 1;
    if (var_ctr == 0) return -1;
    goto loop_1;
}
#pragma small_data on
void fn_8001B7B8(void) {
    fn_802D3050();
}
extern int lbl_803583C8;
extern float lbl_80560418;
extern float lbl_8056041C;
extern float lbl_803582C0;
extern int fn_8001B478(float);
extern void *fn_80156A40(void);
extern double cos(double);
extern double sin(double);
