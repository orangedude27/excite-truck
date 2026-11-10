// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055E890;
int fn_80128670(int);
int fn_8012850C(int, const void *);
void fn_801CECE0(void);
extern const char lbl_80338050[];
#pragma scheduling invalid_target
void fn_801CEC80(void) {
    lbl_8055E890 = fn_8012850C(0x180, lbl_80338050);
    fn_801CECE0();
}
#pragma scheduling on
void fn_801CECB4(void) {
    fn_80128670(lbl_8055E890);
    lbl_8055E890 = 0;
}

void fn_801CECE0(void) {
    extern int lbl_8055E890;
    extern float lbl_80562A20;
    register float zero = lbl_80562A20;
    register char *p;
    register int offset = 0;
    register int neg = -1;
    register int i;
    for (i = 0; i < 8; i++) {
        p = (char *)lbl_8055E890;
        p += offset;
        *(int *)p = neg;
        offset += 0x30;
        *(float *)(p + 8) = zero;
        *(float *)(p + 4) = zero;
        *(int *)(p + 0xC) = neg;
        *(float *)(p + 0x14) = zero;
        *(float *)(p + 0x10) = zero;
        *(int *)(p + 0x18) = neg;
        *(float *)(p + 0x20) = zero;
        *(float *)(p + 0x1C) = zero;
        *(int *)(p + 0x24) = neg;
        *(float *)(p + 0x2C) = zero;
        *(float *)(p + 0x28) = zero;
    }
}

void fn_801CEDDC(void) {
    extern int lbl_8055E890;
    extern float lbl_80562A20, lbl_80562A24, lbl_80562A28, lbl_80562A2C, lbl_80562A30;
    register float decay = lbl_80562A30;
    register float min = lbl_80562A20;
    register float threshold = lbl_80562A2C;
    register float max = lbl_80562A28;
    register float step = lbl_80562A24;
    register char *p;
    register int i;
    register int j;
    for (i = 0; i < 8; ++i) {
        p = (char *)lbl_8055E890 + i * 0x30;
        for (j = 0; j < 4; ++j) {
            if (*(int *)p >= 0) {
                register float v = *(float *)(p + 4) + step;
                *(float *)(p + 4) = v;
                if (v > max) {
                    *(int *)p = -1;
                } else if (*(float *)(p + 4) > threshold) {
                    register float speed = *(float *)(p + 8) - decay;
                    if (min > speed)
                        speed = min;
                    *(float *)(p + 8) = speed;
                }
            }
            p += 0xc;
        }
    }
}

extern float lbl_80562A20;
extern void *fn_8017960C(void);
extern void fn_801B916C(void *);
extern void *fn_8017960C();
extern void fn_801B916C();
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801CEEC8(void *arg0) {
    register float temp_f31;
    register char *var_r30;
    register int var_r31;
    register char *var_r29;
    register char *var_r28;
    register int var_r27;
    register int var_r26;
    temp_f31 = lbl_80562A20;
    var_r30 = (char *)arg0 + 4;
    var_r27 = 0;
    var_r31 = 0;
    goto outer_check;
outer_body:
    var_r28 = var_r30 + 0x74;
    var_r26 = 0;
    var_r29 = (char *)lbl_8055E890 + *(int *)(var_r30 + 0x60) * 0x30;
    do {
        register int temp_r3;
        temp_r3 = *(int *)var_r29;
        *(int *)var_r28 = temp_r3;
        *(float *)(var_r28 + 4) = *(float *)(var_r29 + 4);
        *(float *)(var_r28 + 0x10) = *(float *)(var_r29 + 8);
        if (temp_r3 >= 0) {
            temp_r3 = (int)fn_8017960C();
            *(float *)(var_r28 + 8) = *(float *)((char *)temp_r3 + 0x2690);
            *(float *)(var_r28 + 0xc) = *(float *)((char *)temp_r3 + 0x2694);
            *(int *)(var_r28 + 0x14) = *(int *)((char *)temp_r3 + 0x268c);
        } else {
            *(float *)(var_r28 + 8) = temp_f31;
            *(int *)(var_r28 + 0x14) = var_r31;
        }
        var_r26++;
        var_r29 += 0xc;
        var_r28 += 0x18;
    } while (var_r26 < 4);
    var_r30 += 0xe0;
    var_r27++;
outer_check:
    if (var_r27 < *(int *)((char *)arg0 + 0x394))
        goto outer_body;
    fn_801B916C(arg0);
}
#pragma pop
