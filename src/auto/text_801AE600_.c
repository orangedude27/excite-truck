extern int *lbl_80435780;
extern int *lbl_8055E624;
extern unsigned char *fn_801EA9A0(int);
extern int fn_801B8728(void);
extern int fn_801B2C70(void *);
extern float lbl_80558DC4;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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
extern float lbl_80562560;
extern float lbl_8055E630;
extern float lbl_80562558;
extern int lbl_8055E62C;
extern double lbl_80562568;
extern float lbl_8056255C;
extern void fn_801AE874(unsigned short *, int);
extern void fn_801AE894(void *);
extern int fn_801EA994(void);
int fn_801AEA64(float arg0, float arg1) {
    float diff = arg0 - arg1;
    if (__fabsf(diff) <= lbl_80558DC4) return 0;
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
extern float lbl_80558DC4;
