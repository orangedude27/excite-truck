// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int size_t;
extern char lbl_80351790[];
extern char lbl_802FC600[];
extern float lbl_80560350;
extern float lbl_8056034C;
extern char lbl_8055D4EC;
extern char *strncpy(char *, const char *, size_t);
extern void *memset(void *, int, size_t);
extern int fn_802E2C20(void);
void fn_8001255C(const char *, float);
extern float lbl_80560348;
extern int lbl_8055FB9C;
extern int lbl_8055FBA0;
extern void fn_802C92D0(void);
extern void fn_802C92D8(void);
extern void fn_802C92DC(int, int, int, int, int);
extern void fn_80235380(void);
extern void fn_80128668(void *);
void *fn_80012384(void *arg0, int arg1) {
    if (arg0 != 0) {
        if (!(*(int *)((char *)arg0 + 0x50) == 0)) fn_80235380();
        *(int *)((char *)arg0 + 0x50) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_800123EC(float arg0) {
    float f;
    int value;
    int color;
    fn_802C92D0();
    f = lbl_80560348 * arg0;
    value = (int)f;
    if (value <= 0) value = 0;
    color = value;
    if (color >= 0xff) color = 0xff;
    fn_802C92DC(-0x14, -0x14, lbl_8055FB9C + 0x14, lbl_8055FBA0 + 0x14, color << 24);
    fn_802C92D8();
}

#pragma push
#pragma scheduling on
void fn_80012478(void) {
    register char *p = lbl_80351790;
    register int zero = 0;
    p[0] = zero;
    memset(p + 1, zero, 0x80);
    *(int *)(p + 0x8c) = zero;
    *(float *)(p + 0x88) = lbl_8056034C;
    *(float *)(p + 0x84) = lbl_8056034C;
    lbl_8055D4EC = 1;
}
#pragma pop
void fn_800125C4(void) {
    fn_8001255C(lbl_802FC600, lbl_80560350);
}

void fn_800125D4(const char *arg0) {
    register char *dst = lbl_80351790 + 1;
    strncpy(dst, arg0, 0x7f);
    lbl_80351790[0x80] = 0;
    lbl_80351790[0] = 0;
}

extern void fn_800123EC(float);
void fn_80012624(void) {
    fn_800123EC(0.0f);
}

#pragma push
#pragma scheduling on
void fn_80012628(void) {
    register char *p = lbl_80351790;
    register int zero = 0;
    p[0] = zero;
    memset(p + 1, zero, 0x80);
    *(int *)(p + 0x8c) = zero;
    *(float *)(p + 0x88) = lbl_8056034C;
    *(float *)(p + 0x84) = lbl_8056034C;
    lbl_8055D4EC = zero;
}
#pragma pop
