// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B38;
extern float lbl_80562B3C;

void fn_801D9F24(void) {
    fn_8012C4D8();
}

void fn_801D9F28(void *arg0) {
    volatile int *p = (volatile int *)arg0;
    float value = lbl_80562B38;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    *(volatile float *)((char *)arg0 + 0xC) = value;
}

extern int fn_80128668(void);
extern float lbl_80562B38;
extern int strcmp(const char *, const char *);
int fn_801D9F44(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_801D9F84(void *arg0, int *arg1) {
    float value = lbl_80562B38;
    int isNull = (arg1 == 0);
    *(int **)arg0 = arg1;
    *(int *)((char *)arg0 + 8) = 0;
    *(float *)((char *)arg0 + 0xC) = value;
    if (!isNull && *arg1 > 0)
        *(int *)((char *)arg0 + 4) = (int)(arg1 + 1);
    else
        *(int *)((char *)arg0 + 4) = 0;
}
#pragma scheduling on
int fn_801D9FC4(char **arg0, const char *arg1) {
    register int count;
    register char *base;
    register int i;

    base = *arg0;
    count = *(int *)base;
    i = 0;
    while (i < count) {
        if (strcmp(base + i * 0x18 + 4, arg1) == 0)
            return 1;
        i++;
    }
    return 0;
}

void *fn_801DA03C(int **arg0, int arg1) {
    int *base = *arg0;
    if (arg1 < *base) {
        return (char *)base + arg1 * 0x18 + 4;
    }
    return 0;
}

#pragma use_lmw_stmw off
int fn_801DA064(void *arg0, const char *arg1, int arg2) {
    register int offset;
    register int count;
    register char *entries;
    register int index;
    char *base;

    base = *(char **)arg0;
    count = *(int *)base;
    entries = base + 4;
    index = 0;
    offset = 0;
    while (index < count) {
        if (strcmp(entries + offset, arg1) == 0) {
            *(char **)((char *)arg0 + 4) = entries + index * 0x18;
            return 1;
        }
        offset += 0x18;
        index++;
    }
    return 0;
}
#pragma use_lmw_stmw reset

void fn_801DA198(void *arg0, float farg0) {
    int index;
    void *obj;
    float *values;
    *(float *)((char *)arg0 + 0xC) = farg0;
    *(int *)((char *)arg0 + 8) = 0;
    obj = *(void **)((char *)arg0 + 4);
    if (obj == 0) return;
    for (;;) {
        index = *(int *)((char *)arg0 + 8);
        values = *(float **)((char *)obj + 0x14);
        if (values[index * 8 + 8] > *(float *)((char *)arg0 + 0xC)) return;
        *(int *)((char *)arg0 + 8) = index + 1;
        if (index + 2 >= *(int *)((char *)obj + 0x10)) return;
    }
}

extern float lbl_80562B40, lbl_80562B44, lbl_80562B48, lbl_80562B4C, lbl_80558DC4;
extern double fn_8002F234(float);
extern double fn_8002EFA8(double);
extern double sin(double);
extern double __fabs(double);
extern int fn_801DA1F8(void *, void **, void **, float *);
extern float __fabsf(float);
#pragma scheduling invalid_target
int fn_801DA294(void *arg0, void *arg1, void *arg2, void *arg3) {
    volatile float sp6C;
    volatile float sp68;
    volatile float sp64;
    volatile float sp60;
    volatile float sp58;
    volatile float sp54;
    volatile float sp50;
    volatile float sp4C;
    volatile float sp48;
    volatile float sp44;
    volatile float sp40;
    volatile float sp3C;
    volatile float sp38;
    volatile float sp34;
    volatile float sp30;
    volatile float sp28;
    volatile float sp24;
    volatile float sp20;
    volatile float sp1C;
    volatile float sp18;
    volatile float sp14;
    float *sp10;
    float *spC;
    float sp8;
    float temp_f30;
    float temp_f31;
    float temp_f0;
    float temp_f10;
    float temp_f10_2;
    float temp_f10_3;
    float temp_f11;
    float temp_f11_2;
    float temp_f12;
    float temp_f1;
    float temp_f1_2;
    float temp_f1_3;
    float temp_f2;
    float temp_f2_2;
    float temp_f2_3;
    float temp_f2_4;
    float temp_f3;
    float temp_f3_2;
    float temp_f3_3;
    float temp_f3_4;
    float temp_f3_5;
    float temp_f3_6;
    float temp_f4;
    float temp_f4_2;
    float temp_f4_3;
    float temp_f4_4;
    float temp_f4_5;
    float temp_f5;
    float temp_f5_2;
    float temp_f5_3;
    float temp_f5_4;
    float temp_f5_5;
    float temp_f5_6;
    float temp_f5_7;
    float temp_f6;
    float temp_f6_2;
    float temp_f6_3;
    float temp_f7;
    float temp_f7_2;
    float temp_f7_3;
    float temp_f7_4;
    float temp_f8;
    float temp_f8_2;
    float temp_f8_3;
    float temp_f9;
    float temp_f9_2;
    float temp_f9_3;
    float temp_f9_4;
    float var_f0;

    sp10 = 0;
    spC = 0;
    sp8 = lbl_80562B38;
    if (fn_801DA1F8(arg0, (void **)&sp10, (void **)&spC, &sp8) != 0) {
        temp_f0 = (*(float *)((char *)(spC) + (0xC)));
        temp_f8 = (*(float *)((char *)(sp10) + (0xC)));
        temp_f1 = (*(float *)((char *)(spC) + (8)));
        temp_f7 = (*(float *)((char *)(sp10) + (8)));
        temp_f0 = temp_f0 - temp_f8;
        temp_f4 = sp8;
        temp_f1 = temp_f1 - temp_f7;
        temp_f6 = (*(float *)((char *)(spC) + (4)));
        temp_f3 = temp_f4 * temp_f0;
        temp_f5 = (*(float *)((char *)(sp10) + (4)));
        temp_f1 = temp_f4 * temp_f1;
        temp_f0 = temp_f6 - temp_f5;
        temp_f2 = lbl_80562B40;
        temp_f3 = temp_f8 + temp_f3;
        temp_f10 = temp_f7 + temp_f1;
        temp_f0 = temp_f4 * temp_f0;
        (*(float *)((char *)(arg1) + (0x2C))) = temp_f3;
        temp_f11 = temp_f5 + temp_f0;
        (*(float *)((char *)(arg1) + (0x28))) = temp_f10;
        sp1C = temp_f3;
        (*(float *)((char *)(arg1) + (0x24))) = temp_f11;
        temp_f9 = lbl_80562B40 - sp8;
        temp_f7_2 = (*(float *)((char *)(sp10) + (0x10))) * temp_f9;
        temp_f2 = ((*(float *)((char *)(sp10) + (0x18))) * temp_f9) + ((*(float *)((char *)(spC) + (0x18))) * sp8);
        temp_f0 = ((*(float *)((char *)(sp10) + (0x1C))) * temp_f9) + ((*(float *)((char *)(spC) + (0x1C))) * sp8);
        temp_f6 = (*(float *)((char *)(spC) + (0x10)));
        sp6C = temp_f0;
        temp_f5_2 = temp_f6 * sp8;
        sp68 = temp_f2;
        temp_f4 = ((*(float *)((char *)(sp10) + (0x14))) * temp_f9) + ((*(float *)((char *)(spC) + (0x14))) * sp8);
        sp14 = temp_f11;
        temp_f3_2 = temp_f7_2 + temp_f5_2;
        temp_f2_2 = temp_f4 * temp_f4;
        sp18 = temp_f10;
        sp60 = temp_f3_2;
        temp_f3_3 = temp_f3_2 * temp_f3_2;
        sp64 = temp_f4;
        temp_f5_3 = lbl_80562B40 / (float) fn_8002F234(temp_f3_3 + (temp_f2_2 + ((temp_f0 * temp_f0) + (temp_f2 * temp_f2))));
        var_f0 = lbl_80562B44;
        temp_f3_4 = sp64 * temp_f5_3;
        temp_f2_3 = temp_f2 * temp_f5_3;
        temp_f7_3 = sp60 * temp_f5_3;
        temp_f12 = 2.0f * temp_f3_4;
        sp64 = temp_f3_4;
        temp_f11_2 = 2.0f * temp_f2_3;
        temp_f6_2 = sp6C * temp_f5_3;
        temp_f9_2 = 2.0f * temp_f7_3;
        temp_f4_2 = temp_f3_4 * temp_f12;
        sp68 = temp_f2_3;
        temp_f1 = temp_f2_3 * temp_f11_2;
        temp_f5_4 = temp_f7_3 * temp_f9_2;
        temp_f10_2 = temp_f6_2 * temp_f9_2;
        temp_f9_3 = temp_f3_4 * temp_f11_2;
        sp60 = temp_f7_3;
        sp6C = temp_f6_2;
        (*(float *)((char *)(arg1) + (0))) = (float) (lbl_80562B40 - (temp_f4_2 + temp_f1));
        temp_f10_3 = temp_f6_2 * temp_f12;
        temp_f5_5 = temp_f7_3 * temp_f11_2;
        temp_f9_4 = temp_f6_2 * temp_f11_2;
        temp_f8_2 = temp_f7_3 * temp_f12;
        (*(float *)((char *)(arg1) + (0x10))) = (float) (lbl_80562B40 - (temp_f5_4 + temp_f1));
        (*(float *)((char *)(arg1) + (0x18))) = (float) (temp_f5_5 + temp_f10_3);
        (*(float *)((char *)(arg1) + (0xC))) = (float) (temp_f8_2 - temp_f9_4);
        (*(float *)((char *)(arg1) + (4))) = (float) (temp_f8_2 + temp_f9_4);
        (*(float *)((char *)(arg1) + (0x1C))) = (float) (temp_f9_3 - temp_f10_2);
        (*(float *)((char *)(arg1) + (8))) = (float) (temp_f5_5 - temp_f10_3);
        (*(float *)((char *)(arg1) + (0x14))) = (float) (temp_f9_3 + temp_f10_2);
        (*(float *)((char *)(arg1) + (0x20))) = (float) (lbl_80562B40 - (temp_f5_4 + temp_f4_2));
        temp_f1_2 = (*(float *)((char *)(spC) + (0))) - (*(float *)((char *)(sp10) + (0)));
        if (var_f0 <= temp_f1_2) {
            var_f0 = temp_f1_2;
        }
        temp_f31 = lbl_80562B40 / var_f0;
        temp_f5_6 = (*(float *)((char *)(spC) + (4))) - (*(float *)((char *)(sp10) + (4)));
        temp_f4_3 = (*(float *)((char *)(spC) + (8))) - (*(float *)((char *)(sp10) + (8)));
        temp_f8_3 = (*(float *)((char *)(spC) + (0xC))) - (*(float *)((char *)(sp10) + (0xC)));
        sp54 = temp_f4_3;
        sp50 = temp_f5_6;
        (*(float *)((char *)(arg2) + (0))) = (float) (temp_f5_6 * temp_f31);
        (*(float *)((char *)(arg2) + (4))) = (float) (temp_f4_3 * temp_f31);
        (*(float *)((char *)(arg2) + (8))) = (float) (temp_f8_3 * temp_f31);
        temp_f4_4 = (*(float *)((char *)(sp10) + (0x1C))) * lbl_80562B48;
        temp_f7_4 = (*(float *)((char *)(sp10) + (0x10))) * lbl_80562B48;
        temp_f5_7 = (*(float *)((char *)(sp10) + (0x18))) * lbl_80562B48;
        temp_f6_3 = (*(float *)((char *)(sp10) + (0x14))) * lbl_80562B48;
        temp_f1_3 = (*(float *)((char *)(spC) + (0x1C))) + temp_f4_4;
        temp_f3_5 = (*(float *)((char *)(spC) + (0x10))) + temp_f7_4;
        temp_f2_4 = (*(float *)((char *)(spC) + (0x14))) + temp_f6_3;
        sp58 = temp_f8_3;
        sp40 = temp_f7_4;
        sp44 = temp_f6_3;
        sp48 = temp_f5_7;
        sp4C = temp_f4_4;
        sp30 = temp_f3_5;
        sp34 = temp_f2_4;
        sp38 = (*(float *)((char *)(spC) + (0x18))) + temp_f5_7;
        sp3C = temp_f1_3;
        temp_f30 = (float) fn_8002EFA8(temp_f1_3);
        temp_f4_5 = (float) sin(temp_f30);
        if (__fabsf(temp_f4_5) > lbl_80558DC4) {
            temp_f3_6 = (lbl_80562B4C * temp_f30) / temp_f4_5;
            sp20 = sp30 * temp_f3_6;
            sp24 = sp34 * temp_f3_6;
            sp28 = sp38 * temp_f3_6;
        } else {
            sp20 = lbl_80562B38;
            sp24 = lbl_80562B38;
            sp28 = lbl_80562B38;
        }
        (*(float *)((char *)(arg3) + (0))) = (float) (sp20 * temp_f31);
        (*(float *)((char *)(arg3) + (4))) = (float) (sp24 * temp_f31);
        (*(float *)((char *)(arg3) + (8))) = (float) (sp28 * temp_f31);
        return 1;
    }
    return 0;
}
int fn_801DA648(void *arg0) {
    void *obj;
    int count;
    float *values;
    obj = *(void **)((char *)arg0 + 4);
    if (obj != 0) {
        count = *(int *)((char *)obj + 0x10);
        values = *(float **)((char *)obj + 0x14);
        return *(float *)((char *)arg0 + 0xC) >= values[(count - 1) * 8];
    }
    return 0;
}

int fn_801DA688(void *arg0) {
    if (*(void **)((char *)arg0 + 4) != 0)
        return *(float *)((char *)arg0 + 0xC) <= lbl_80562B38;
    return 0;
}

extern float lbl_80562B3C;
float fn_801DA6B8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    if (obj != 0) {
        int count = *(int *)((char *)obj + 0x10);
        float *values = *(float **)((char *)obj + 0x14);
        return values[(count - 1) * 8];
    }
    return lbl_80562B38;
}

