// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <math.h>
#include "types.h"

typedef struct {
    f32 x[9];
} Mat3x3;

extern f32 lbl_80562CE8;
extern f32 lbl_80562CEC;
extern void fn_801E35D4(void *dst, void *src);
extern void fn_801E3284(void *out, void *in, s32 arg2);
extern void fn_802C744C(s32 arg0, void *out);

void fn_8012A260(void*, unsigned int);
void fn_80128668(void*);
extern s32 lbl_803398D8;
extern s32 lbl_80339904;
extern void *lbl_8055EA50;
extern void *fn_801284F8(s32, void *);
extern void fn_8012A13C(void *, s32, s32);
#pragma push
#pragma small_data off
#pragma pop
void fn_801E2F00(void) {
    void *p = fn_801284F8(0x20, &lbl_803398D8);
    if (p != 0) {
        fn_8012A13C(&lbl_803398D8, 0x128, 0x68);
        *(void **)p = &lbl_80339904;
    }
    lbl_8055EA50 = p;
}
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801E2FAC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_8012A260((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma small_data off
void fn_801E31D8(s32 *arg0) {
    *(s32 **)((u8 *)fn_801E3004(*arg0) + 4) = arg0;
}

s32 fn_801E320C(void) {
    return fn_801E2DEC(0, 0, 0) != 0;
}

void fn_801E33E4(void) {
    f32 sp[12];
    sp[0] = lbl_80562CE8;
    sp[1] = lbl_80562CEC;
    sp[2] = lbl_80562CEC;
    sp[3] = lbl_80562CEC;
    sp[4] = lbl_80562CE8;
    sp[5] = lbl_80562CEC;
    sp[6] = lbl_80562CEC;
    sp[7] = lbl_80562CEC;
    sp[8] = lbl_80562CE8;
    sp[9] = lbl_80562CEC;
    sp[10] = lbl_80562CEC;
    sp[11] = lbl_80562CEC;
    fn_801E3284(0, sp, 0);
}

void fn_801E3440(void* arg0) {
    f32 sp[12];
    fn_801E3284(sp, 0, 0);
    *(f32*)((u8*)arg0 + 0) = sp[9];
    *(f32*)((u8*)arg0 + 4) = sp[10];
    *(f32*)((u8*)arg0 + 8) = sp[11];
}

void fn_801E34E4(s32 *arg0, s32 arg1) {
    s32 sp8[12];
    s32 val = *arg0;

    if (val != -1) {
        fn_801E3284(&sp8[0], arg0, arg1);
        fn_802C744C(*arg0, &sp8[0]);
    }
}

s32 fn_801E3534(s32 *arg0) {
    return *arg0;
}

void fn_801E353C(s32 arg0, f32 angle) {
    Mat3x3 m;
    f32 c;
    f32 s;

    c = (f32)cos(angle);
    s = (f32)sin(angle);
    m.x[0] = c;
    m.x[1] = s;
    m.x[2] = lbl_80562CEC;
    m.x[3] = -s;
    m.x[4] = c;
    m.x[5] = lbl_80562CEC;
    m.x[6] = lbl_80562CEC;
    m.x[7] = lbl_80562CEC;
    m.x[8] = lbl_80562CE8;
    fn_801E35D4((void *)arg0, &m);
}

void fn_801E35D4(void *arg0, void *arg1) {
    f32 val = lbl_80562CEC;
    s32 i = ((s32 *)arg1)[8];
    s32 h = ((s32 *)arg1)[7];
    s32 g = ((s32 *)arg1)[6];
    s32 f = ((s32 *)arg1)[5];
    s32 e = ((s32 *)arg1)[4];
    s32 d = ((s32 *)arg1)[3];
    s32 c = ((s32 *)arg1)[2];
    s32 b = ((s32 *)arg1)[1];
    s32 a = ((s32 *)arg1)[0];
    s32 *dst = (s32 *)arg0;
    f32 *fdst = (f32 *)((u8 *)arg0 + 0x2C);

    fdst[0] = val;
    fdst[1] = val;
    fdst[2] = val;
    dst[2] = a;
    dst[3] = b;
    dst[4] = c;
    dst[5] = d;
    dst[6] = e;
    dst[7] = f;
    dst[8] = g;
    dst[9] = h;
    dst[10] = i;
}

