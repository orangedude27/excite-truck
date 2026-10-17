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
    s32 unk_30;
} Unk_80135278;

void fn_80135390(Unk_80135278 *);
void fn_801355C0(void *, s32, s32, void *, s32);
void fn_801357A4();

extern void *fn_80156A40(void);

typedef struct {
    float unk_0;
    float unk_4;
} Diffs2_80135278;

static float fn_80135278_dot(float *a, Diffs2_80135278 d) {
    return a[0] * d.unk_0 + a[1] * d.unk_4;
}

float fn_80135278(float *a, float *b, float *c) {
    return fn_80135278_dot(a, (Diffs2_80135278){b[0] - c[0], b[1] - c[1]});
}

void *fn_801352B8(Unk_80135278 *arg0) {
    arg0->unk_0 = (s32)&lbl_8032BE80;
    arg0->unk_4 = 0;
    arg0->unk_c = 0x2710;
    arg0->unk_8 = lbl_80561320;
    fn_80135390(arg0);
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
    float g = lbl_80561324;
    float f = lbl_80561320;
    arg0->unk_8 = f;
    arg0->unk_4 = 0;
    arg0->unk_c = 0;
    arg0->unk_20 = f;
    arg0->unk_24 = f;
    arg0->unk_10 = g;
    arg0->unk_14 = f;
    arg0->unk_18 = f;
    arg0->unk_1c = f;
    arg0->unk_28 = 0;
    arg0->unk_2c = 0;
}

#pragma dont_inline on
void fn_80135390(Unk_80135278 *arg0) {
    fn_80135354(arg0);
    arg0->unk_30 = 0;
}
#pragma dont_inline off

void fn_801353C8(Unk_80135278 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    float f = lbl_80561320;
    arg0->unk_8 = f;
    arg0->unk_4 = arg3;
    fn_801355C0(arg0, arg1, arg2, &arg0->unk_4, 0);
    fn_801357A4(arg0, arg1);
}

void fn_801353C4(void) {
    fn_801357A4();
}

s32 fn_801355B8(void *arg0, void *arg1) {
    return 0;
}

void fn_80135EF0(void *arg0) {
    if (fn_80135D60() == 1) {
        *(int *)((char *)arg0 + 0x34) = 0;
        *(int *)((char *)arg0 + 0x5C) = 0;
        if (*(int *)((char *)arg0 + 0x50) != 0)
            *(int *)((char *)arg0 + 0x54) = *(int *)(*(char **)((char *)arg0 + 0x2C) + 0x18) >> 16;
    }
}

void fn_80135F4C(void *arg0) {
    int x = *(int *)(*(char **)((char *)arg0 + 0x2C) + 0x1C);
    fn_80135F64((int)arg0, x, x + 8, 1, 0);
}

void fn_8013605C(void *arg0) {
    *(signed char *)((char *)arg0 + 0x64) = 0;
}

int fn_801363A0(void *arg0, void *arg1) {
    int temp_r31 = *(int *)((char *)*(void **)arg1 + 0x10);
    int var = *(int *)((char *)*((void **)*(void **)arg1 + 0x14) + 0x10);
    if (var == 0) var = *(int *)((char *)*(void **)((char *)arg0 + 0x2C) + 0x18);
    return temp_r31 + (unsigned int)(*(float *)((char *)arg1 + 4) * (float)(var - temp_r31));
}

s32 fn_801366C0(void *arg0, void *arg1, float farg0) {
    if (*(s32 *)((char *)arg0 + 4) != 0) {
        if (*(s32 *)(*(s32 *)((char *)arg0 + 0x2C) + 0x1C) == 0) {
            return 0;
        }
    }
    return ((*(float *)((char *)arg1 + 0)) * (*(float *)((char *)arg0 + 0x10))
          + (*(float *)((char *)arg1 + 8)) * (*(float *)((char *)arg0 + 0x14))) < -farg0;
}

void fn_80136714(void *arg0) {
    float a = *(float *)((char *)arg0 + 0x10);
    float b = *(float *)((char *)arg0 + 0x14);
    *(float *)((char *)arg0 + 0x38) = b;
    *(float *)((char *)arg0 + 0x3C) = -a;
}

extern void *fn_80156A40(void);

typedef struct {
    void *unk_0;
    void *unk_4;
    void *(*unk_8)(void *, s32);
} Vt_8013672C;

typedef struct {
    Vt_8013672C *vtbl;
} Unk_8013672C_vt;

float fn_8013672C(void) {
    Unk_8013672C_vt *obj = fn_80156A40();
    return *(float *)((char *)obj->vtbl->unk_8(obj, 0) + 8);
}

void fn_80136764(void) {
    fn_801564B0();
}

void fn_80136768(void) {
    fn_801569FC();
}

void fn_801367E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 r;
    void ***vtbl = (void ***)arg0;
    r = ((s32 (*)(void))vtbl[0][3])();
    if (r == 1) {
        fn_801353C8((Unk_80135278 *)arg0, arg2, arg3, 0);
    }
}

void fn_80136854(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 r;
    void ***vtbl = (void ***)arg0;
    r = ((s32 (*)(void))vtbl[0][3])();
    if (r == 1) {
        fn_80135F64((int)arg0, arg2, arg3, 1, 0);
    }
}

