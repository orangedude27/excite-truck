// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int size_t;

// The one progress/loading message the game shows (its own name string is
// "ProgressUpdate", lbl_802FC600). fn_80012478/fn_80012628 clear it,
// fn_800124DC starts one, fn_8001255C advances it and fn_800125D4 drops it.
typedef struct {
    unsigned char active;     // +0x00: a message is set
    char message[0x80];       // +0x01: text, strncpy'd 0x7f chars with the last byte forced to NUL
    float progress;           // +0x84: accumulated progress (fn_8001255C adds to it)
    float target;             // +0x88: value the message was started with
    unsigned int startTime;   // +0x8C: ms (fn_802E2C20) when the message was started
    unsigned int elapsed;     // +0x90: ms between the last update and startTime
} ProgressMessage;
extern char lbl_80351790[];   // the ProgressMessage record
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
extern void fn_80235380(void *);
extern void fn_80128668(void *);
#pragma scheduling invalid_target
void *fn_80012384(void *arg0, int arg1) {
    if (arg0 != 0) {
        void *resource = *(void **)((char *)arg0 + 0x50);
        if (resource != 0) {
            fn_80235380(resource);
        }
        *(void **)((char *)arg0 + 0x50) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma push
#pragma processor 750
void fn_800123EC(float arg0) {
    float f;
    int value;
    int color;
    fn_802C92D0();
    f = lbl_80560348 * arg0;
    value = (int)f;
    color = 0;
    if (value > 0)
        color = (int)f;
    color = (color >= 0xff ? 0xff : color);
    fn_802C92DC(-0x14, -0x14, lbl_8055FB9C + 0x14, lbl_8055FBA0 + 0x14, color << 24);
    fn_802C92D8();
}
#pragma pop

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

extern char lbl_80558AD0;
#pragma push
#pragma processor 750
void fn_800124DC(const char *arg0, float farg0) {
    register char *p = lbl_80351790;
    register int one = 1;
    register int zero = 0;
    lbl_80558AD0 = one;
    strncpy(p + 1, arg0, 0x7f);
    p[0x80] = zero;
    *(float *)(p + 0x88) = farg0;
    *(float *)(p + 0x84) = lbl_8056034C;
    *(int *)(p + 0x8c) = fn_802E2C20();
    p[0] = one;
}
#pragma pop

#pragma pop
#pragma push
#pragma processor 750
void fn_8001255C(const char *arg0, float farg0) {
    register char *p = lbl_80351790;
    float f = *(float *)(p + 0x84) + farg0;
    strncpy(p + 1, arg0, 0x7f);
    *(float *)(p + 0x84) = f;
    p[0x80] = 0;
    *(int *)(p + 0x90) = fn_802E2C20() - *(int *)(p + 0x8c);
}
#pragma pop

void fn_800125C4(void) {
    ((void(*)(const char *, float))fn_8001255C)(lbl_802FC600, lbl_80560350);
}

void fn_800125D4(const char *arg0) {
    register char *dst = lbl_80351790 + 1;
    strncpy(dst, arg0, 0x7f);
    lbl_80351790[0x80] = 0;
    lbl_80351790[0] = 0;
}

extern void fn_800123EC(float);
void fn_80012624(void) {
    ((void(*)(void))fn_800123EC)();
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
