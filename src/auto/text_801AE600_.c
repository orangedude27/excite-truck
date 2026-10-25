extern int *lbl_80435780;
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
#pragma small_data off
extern float lbl_80558DC4;
#pragma small_data on
extern float lbl_8055E630;
extern float lbl_8056255C;
extern float lbl_80562560;
extern int lbl_8055E62C;
extern double lbl_80562568;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80435740[];

int fn_801AE618(int arg0);
int fn_801AE600(int arg0) {
    return arg0 == 0x50;
}

int fn_801AE610(void) {
    return 0;
}

#pragma dont_inline on
int fn_801AE618(int arg0) {
    return arg0 & 1;
}
#pragma dont_inline reset

void fn_801AE620(void *arg0) {
    fn_801AE618(*(unsigned short *)((char *)arg0 + 0xE));
}

int fn_801AE790(void *arg0) {
    return *((unsigned char *)arg0 + 0x70) & 3;
}

extern int lbl_8055E62C;
extern float lbl_8056255C;
extern double lbl_80562568;
void fn_801AE874(unsigned short *arg0, int arg1) {
    unsigned short value = *arg0 | 1;
    *arg0 = value;
    if (arg1) *arg0 = value | 4;
}

#pragma small_data off
extern float lbl_80558DC4;
extern float lbl_80562560;
extern float lbl_8055E630;
extern float lbl_80562558;
extern int lbl_8055E62C;
extern double lbl_80562568;
extern float lbl_8056255C;
extern void fn_801AE874(unsigned short *, int);
extern void fn_801AE894(void *);
extern int fn_801EA994(void);
extern double __fabs(double);
int fn_801AEA64(float arg0, float arg1) {
    float diff = arg0 - arg1;
    float magnitude = (float)__fabs((double)diff);
    if (magnitude <= lbl_80558DC4) return 0;
    if (arg1 < arg0) return 1;
    return -1;
}
#pragma small_data on
void fn_801AED54(void) {

}

void fn_801AED58(void) {

}

extern signed char lbl_8055E634;
extern void fn_801B8778(void);
extern void fn_801B878C(void);
extern float fn_801AF9EC(int, float *);
extern int fn_801AEA64(float, float);
extern void *fn_801AF8D0(int);
void fn_801AED5C(void) {
    lbl_8055E634 = 1;
    fn_801B8778();
}

void fn_801AED68(void) {
    lbl_8055E634 = 0;
    fn_801B878C();
}

extern void *lbl_8055E620;
extern int fn_801B2F24(void);
extern int fn_801B3050(int);
extern int fn_801B2ED4(void);
extern void *memset(void *, int, unsigned int);
void fn_801AED74(void) {
    int i;
    int offset;
    float value;
    void *base;
    void **table;
    int j;
    int k;
    void *entry;
    void *data;

    if (lbl_8055E634 == 0) {
        base = (void *)lbl_8055E624[0];
        value = lbl_80562558;
        offset = 0;
        for (i = 0; i < lbl_8055E624[1]; i++) {
            data = (char *)base + offset;
            memset(data, 0, 0x1C);
            *(float *)((char *)data + 8) = value;
            *(short *)((char *)data + 0xC) = -100;
            if (i < fn_801B2F24())
                *(short *)((char *)data + 0x1A) = fn_801B3050(i);
            else
                *(short *)((char *)data + 0x1A) = -1;
            offset += 0x1C;
        }
        table = (void **)lbl_8055E620;
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                entry = table[k];
                if (entry != 0) {
                    for (i = 0; i < *(int *)((char *)entry + 4); i++)
                        *(short *)((char *)*(int *)entry + i * 8 + 6) = 0;
                }
            }
            table += 4;
        }
    }
    lbl_8055E62C = fn_801B2ED4();
}

void *fn_801AF8D0(int arg0) {
    void *result = 0;
    if (arg0 < lbl_8055E624[1]) {
        result = (char *)lbl_8055E624[0] + arg0 * 0x1C;
        fn_801AE620(result);
        if (fn_801AE618(*(unsigned short *)((char *)result + 0xE))) {
            result = 0;
        }
    }
    return result;
}

void fn_801AF92C(void *arg0) {
    int count;
    int i;
    char *entry;
    if (fn_801B8728() != 0 || fn_801B2C70(arg0) != 0) return;
    count = lbl_80435780[0x3C0 / 4];
    *(int *)arg0 = count;
    *(int *)((char *)arg0 + 4) = 0;
    *((signed char *)arg0 + 0xC) = 0;
    *((signed char *)arg0 + 0xD) = 1;
    entry = (char *)arg0 + 0x10;
    for (i = 0; i < count; i++, entry += 0x14) {
        void *item = fn_801AF8D0(i);
        if (item != 0) {
            *(int *)(entry + 4) = *(short *)((char *)item + 0xC);
            *(int *)(entry + 8) = 0;
            entry[0x10] = 0;
        } else {
            *(int *)(entry + 4) = -1;
            *(int *)(entry + 8) = 0;
            entry[0x10] = 0;
        }
    }
}

float fn_801AF9EC(int arg0, float *arg1) {
    if (arg1 != 0) *arg1 = lbl_80435740[arg0 * 2 + 1];
    return lbl_80435740[arg0 * 2];
}

#pragma scheduling invalid_target
void fn_801AFA20(void) {
    /* Pass the check result through and set its failure value to minus one. */
    int result = fn_801284F8(4, lbl_803359A0);
    if (result != 0) {
        ((void (*)(int *, int))fn_801AFA64)((int *)result, -1);
    }
}
#pragma scheduling on
void fn_801AFA5C(int arg0) { fn_801AFA70(arg0, 1); }

extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];

void fn_801AFA64(int *arg0) { *arg0 = 0; }

int fn_801AFA70(int arg0, int arg1) { if (arg0 != 0 && arg1 > 0) fn_80128668(); return arg0; }

void fn_801AFAB4(void) {

}

void fn_801AFABC(void) {

}

void fn_801AFAB8(void) {

}

void fn_801AFAB0(void) {

}
extern int fn_801284F8(int, const char *);
extern void fn_801AFA64(int *);
extern const char lbl_803359A0[];
extern float lbl_80435740[];
extern int *lbl_80435780;
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
