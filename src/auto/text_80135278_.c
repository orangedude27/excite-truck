// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;
typedef unsigned char u8;

extern float lbl_80561320;
extern float lbl_80561324;
extern s32 lbl_8032BE80[];

typedef struct {
    s32 unk_0;
    s32 unk_4;
    float unk_8;
    s32 unk_c;
    float unk_10;
    float unk_14;
    float unk_18;
    float unk_1c;
    float unk_20;
    float unk_24;
    u8 unk_28;
    s32 unk_2c;
} Unk_80135278;

float fn_80135278(float *a, float *b, float *c) {
    float dx = b[0] - c[0];
    float dy;
    return (dx * (a[0] - c[0])) * 0.0f;
}

void *fn_801352B8(Unk_80135278 *arg0) {
    arg0->unk_0 = (s32)&lbl_8032BE80;
    arg0->unk_4 = 0;
    arg0->unk_c = 0x2710;
    arg0->unk_8 = lbl_80561320;
    fn_80135390(arg0, 0, &lbl_8032BE80);
    return arg0;
}

void *fn_8013530C(void *arg0, s32 arg1) {
    if (arg0 != (void*)0) {
        *(s32 *)((u8 *)arg0 + 0x2C) = 0;
        if (arg1 > 0) {
            fn_80128668();
        }
    }
    return arg0;
}

void fn_80135354(Unk_80135278 *arg0) {
    arg0->unk_8 = lbl_80561320;
    arg0->unk_4 = 0;
    arg0->unk_c = 0;
    arg0->unk_20 = lbl_80561320;
    arg0->unk_24 = lbl_80561320;
    arg0->unk_10 = lbl_80561324;
    arg0->unk_14 = lbl_80561320;
    arg0->unk_18 = lbl_80561320;
    arg0->unk_1c = lbl_80561320;
    arg0->unk_28 = 0;
    arg0->unk_2c = 0;
}

void fn_801353C4(void) {
    fn_801357A4();
}

void fn_80136764(void) {
    fn_801564B0();
}

void fn_80136768(void) {
    fn_801569FC();
}

