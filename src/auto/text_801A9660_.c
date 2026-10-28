#include "revolution/MTX/vec.h"
struct FnTable_801ADA9C { char pad[0x18]; void (*call)(void *, void *, void *); };
struct Obj_801ADA9C { struct FnTable_801ADA9C *vtable; };
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#pragma opt_tail_call on

extern void fn_8017A57C(void) __attribute__((noreturn));
extern void fn_801AC240(void *);
extern void fn_801AC254(void *);
extern void fn_801ABFF8(void *, int **);
extern char lbl_80335940[];
extern float lbl_805624D0;

extern void fn_8017B0B0(void *);
extern int lbl_8033585C[64];
extern float lbl_8055E3C8;
extern void fn_80179EE8(void *, unsigned int);
extern void fn_80128668(void *);
extern void *fn_801792F8(void);
extern void *fn_801284F8(int, ...);
extern int lbl_8055E5E4;
extern int lbl_8055E5EC;
extern int lbl_8055E5F0;
extern char lbl_80335718[];
extern char lbl_80335744[];
extern char lbl_80335808[];
extern void *lbl_80435628[];
extern void fn_802E317C(const char *, ...);
extern void **fn_801A9700(void **);
extern int lbl_8055E3C4;
extern int lbl_8055A858;
extern int jumptable_80335578[];
extern void *fn_801AC330(void *);
extern void *fn_801AC26C(void);
extern void fn_8017AB84(void *, Vec *, void *);
#pragma scheduling invalid_target
void *fn_801A9660(void) {
    extern char lbl_80335528[];
    extern char lbl_80335538[];
    unsigned int index = *(unsigned int *)((char *)fn_801792F8() + 0x50) - 6;
    void *obj;

    switch (index) {
    case 6:
        obj = ((void *(*)(int, const char *))fn_801284F8)(0x258, lbl_80335528);
        if (obj != 0)
            return fn_801AC330(obj);
        return obj;
    case 11:
    case 12:
    case 15:
        return fn_801AC26C();
    case 0:
    case 3:
    case 8:
    case 9:
    case 13:
    case 16:
        fn_802E317C(lbl_80335538);
        return 0;
    default:
        obj = ((void *(*)(int, int *))fn_801284F8)(0x23c, &lbl_8055A858);
        if (obj != 0)
            return fn_801A9700(obj);
        return obj;
    }
}
#pragma scheduling on
void** fn_801A9700(void** arg0) {
    fn_8017B0B0(arg0);
    *arg0 = &lbl_8033585C;
    return arg0;
}
#pragma scheduling on
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801A973C(void *this_, int flag) {
    if (this_) {
        if (this_ != 0) fn_80179EE8(this_, 0);
        if (flag > 0) fn_80128668(this_);
    }
    return this_;
}

extern void *fn_801AE180(void);
extern f32 lbl_80562478, lbl_8056247C;
#pragma scheduling invalid_target
void fn_801A9798(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    struct Node_801A9798 { void *next; f32 values[9]; };
    register struct Node_801A9798 *node;
    volatile f32 sp64, sp60, sp5c, sp58, sp54, sp50, sp4c, sp48, sp44;
    volatile f32 sp40, sp3c, sp38, sp34, sp30, sp2c, sp28, sp24, sp20;
    volatile f32 sp1c, sp18, sp14, sp10, spC, sp8;
    register f32 constA, constB;
    sp60 = farg1; sp5c = -farg0; sp64 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp5c; node->values[1] = sp60; node->values[2] = sp64; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp50 = farg0; sp54 = farg1; sp58 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp50; node->values[1] = sp54; node->values[2] = sp58; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp48 = farg1; sp44 = -farg0; sp4c = farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp44; node->values[1] = sp48; node->values[2] = sp4c; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp38 = farg0; sp3c = farg1; sp40 = farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp38; node->values[1] = sp3c; node->values[2] = sp40; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp2c = -farg0; sp30 = -farg1; sp34 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp2c; node->values[1] = sp30; node->values[2] = sp34; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp20 = farg0; sp24 = -farg1; sp28 = -farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp20; node->values[1] = sp24; node->values[2] = sp28; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp1c = farg2; sp14 = -farg0; sp18 = -farg1;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp14; node->values[1] = sp18; node->values[2] = sp1c; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
    sp8 = farg0; spC = -farg1; sp10 = farg2;
    node = (struct Node_801A9798 *)fn_801AE180();
    node->values[0] = sp8; node->values[1] = spC; node->values[2] = sp10; node->values[3] = farg3;
    constA = lbl_80562478; node->values[4] = constA;
    constB = lbl_8056247C; node->values[6] = constB; node->values[7] = constB; node->values[8] = constB; node->values[5] = constB;
    node->next = *(void **)((u8 *)arg0 + 0xD0); *(void **)((u8 *)arg0 + 0xD0) = node;
}

#pragma scheduling invalid_target
void fn_801A9AB0(void *self, void *cfg) {
    extern void fn_8017B0F8(void *, void *);
    extern void fn_8017A580(void *, int, int, int, int, int, int, int);
    extern void fn_8019EECC(void *, void *);
    extern double fn_8002F234(float);
    extern double lbl_805624B8;
    extern double cos(double), sin(double);
    extern void *fn_802C6B44(void *);
    extern void fn_802C6C20(void *);
    extern double __fabs(double);
    extern float lbl_80558DC4;
    extern void *fn_801A2354(void *, void *, void *, void *, float, float, float, float, float);
    extern void *fn_801A3DAC(void *, void *, void *, void *);
    extern void *fn_8019FFD8(void *, void *, void *);
    extern void fn_801A0258(void *, void *, void *);
    extern void fn_801A0444(void *, void *);
    extern void *fn_80131808(void *);
    extern void *fn_80131818(void *);
    extern int strcmp(const char *, const char *);
    extern void fn_80179F94(void *, void *);
    extern void *fn_801A3190(void *, void *, void *, int, void *, void *, float, float);
    extern char lbl_80335528[];
    extern char lbl_80333B48[], lbl_803338C0[], lbl_80333B98[], lbl_80333918[], lbl_80333AF8[];
    extern char lbl_8055A888[];
    extern float lbl_80562478, lbl_8056247C, lbl_80562480, lbl_80562484;
    extern float lbl_80562488, lbl_8056248C, lbl_80562490, lbl_80562494;
    extern float lbl_80562498, lbl_8056249C, lbl_805624A0;
    extern float lbl_805624A4, lbl_805624A8, lbl_805624AC, lbl_805624B0;
    volatile unsigned char pad[0x200];
    struct StackSpace {
        char pad[0x144];
        float v14c[3];
        char gap[0x60];
        float v1b8[3];
    };
    volatile struct StackSpace stack;
    float f28, f29, f30, f25, f26, f27;
    float x, y, z, scale, halfY;
    unsigned int cfgValue, type, temp0, temp1, mode = 1, i;
    void *object = 0, *object2, *scan;
    char *names = lbl_80335528;
    unsigned char *p = (unsigned char *)self;
    unsigned char *c = (unsigned char *)cfg;

    fn_8017B0F8(self, cfg);
    *(unsigned char *)(p + 0x221) = 0;
    *(unsigned char *)(p + 0x220) = 1;
    *(unsigned char *)(p + 0x222) = 0;
    *(float *)(p + 0x21C) = lbl_8056247C;
    *(unsigned char *)(p + 0x223) = 1;
    *(unsigned int *)(p + 0x224) = 0;
    *(float *)(p + 0x228) = lbl_8056247C;
    *(float *)(p + 0x22C) = lbl_8056247C;
    *(float *)(p + 0x230) = lbl_8056247C;
    *(unsigned char *)(p + 0x235) = 0;
    *(unsigned char *)(p + 0x234) = 0;
    *(float *)(p + 0x238) = lbl_8056247C;
    fn_801AC240(self);
    temp1 = *(unsigned int *)(c + 0x18);
    temp0 = *(unsigned int *)(c + 0x1C);
    *(unsigned int *)(p + 0x3C) = temp1;
    *(unsigned int *)(p + 0x40) = temp0;
    temp1 = *(unsigned int *)(c + 0x20);
    temp0 = *(unsigned int *)(c + 0x24);
    *(unsigned int *)(p + 0x44) = temp1;
    *(unsigned int *)(p + 0x48) = temp0;
    temp1 = *(unsigned int *)(c + 0x28);
    temp0 = *(unsigned int *)(c + 0x2C);
    *(unsigned int *)(p + 0x4C) = temp1;
    *(unsigned int *)(p + 0x50) = temp0;
    temp1 = *(unsigned int *)(c + 0x30);
    temp0 = *(unsigned int *)(c + 0x34);
    *(unsigned int *)(p + 0x54) = temp1;
    *(unsigned int *)(p + 0x58) = temp0;
    temp1 = *(unsigned int *)(c + 0x38);
    temp0 = *(unsigned int *)(c + 0x3C);
    *(unsigned int *)(p + 0x5C) = temp1;
    *(unsigned int *)(p + 0x60) = temp0;
    temp1 = *(unsigned int *)(c + 0x40);
    temp0 = *(unsigned int *)(c + 0x44);
    *(unsigned int *)(p + 0x64) = temp1;
    *(unsigned int *)(p + 0x68) = temp0;
    ((void (*)(void *))fn_8017A580)(self);
    stack.v1b8[0] = lbl_8056247C;
    stack.v1b8[1] = lbl_8056247C;
    stack.v1b8[2] = lbl_8056247C;
    *(float *)(p + 0x30) = lbl_8056247C;
    *(float *)(p + 0x34) = lbl_8056247C;
    *(float *)(p + 0x38) = lbl_8056247C;
    ((void (*)(void *))fn_8017A57C)(self);

    scale = lbl_80562484 * *(float *)(c + 8);
    scale = scale / lbl_80562488;
    f30 = lbl_80562480 * scale;
    f29 = lbl_8056248C * f30;
    f28 = *(float *)(c + 0x4C);
    cfgValue = *(unsigned int *)(c + 0x48);
    type = *(unsigned int *)(c + 0x50);
    stack.v1b8[0] = lbl_8056247C;
    stack.v1b8[1] = lbl_8056247C;
    stack.v1b8[2] = lbl_8056247C;

    switch (type) {
    case 0:
    case 17:
        object = fn_801284F8(0x54, names + 0x94);
        if (object != 0) {
            unsigned char *o = (unsigned char *)object;
            x = *(float *)(c + 0x58);
            *(void **)(o + 0x0) = lbl_80333B48;
            *(void **)(o + 0x4) = self;
            *(void **)(o + 0x8) = 0;
            *(void **)(o + 0xC) = p + 0x3C;
            *(float *)(o + 0x10) = f30;
            *(float *)(o + 0x14) = f28;
            *(unsigned int *)(o + 0x18) = 0x53504852;
            *(unsigned int *)(o + 0x1C) = 0;
            *(unsigned int *)(o + 0x20) = 100;
            *(float *)(o + 0x24) = x;
            *(float *)(o + 0x28) = stack.v1b8[0];
            *(float *)(o + 0x2C) = stack.v1b8[1];
            *(float *)(o + 0x30) = stack.v1b8[2];
            *(float *)(o + 0x34) = lbl_8056247C;
            *(float *)(o + 0x38) = lbl_8056247C;
            *(float *)(o + 0x3C) = lbl_8056247C;
            *(float *)(o + 0x40) = lbl_8056247C;
            *(float *)(o + 0x44) = lbl_8056247C;
            *(float *)(o + 0x48) = lbl_8056247C;
            *(unsigned char *)(o + 0x4C) = 0;
            *(float *)(o + 0x50) = lbl_8056247C;
            *(float *)(o + 0x28) = stack.v1b8[0];
            *(float *)(o + 0x2C) = stack.v1b8[1];
            *(float *)(o + 0x30) = stack.v1b8[2];
            if (self != 0) fn_8019EECC(self, o + 0x28);
        }
        break;
    case 1:
    case 2:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        f25 = x * lbl_80562478;
        f26 = y * lbl_80562478;
        f27 = z * lbl_80562478;
        fn_801A9798(self, f25, f26, f27, f29);
        if (type == 1) {
            object = fn_801284F8(0x38, names + 0xA8);
            if (object != 0) {
                unsigned char *o = (unsigned char *)object;
                float xx2 = f25 * f25;
                float yy2 = f26 * f26;
                float zz2 = f27 * f27;
                float norm = (xx2 + yy2) + zz2;
                *(void **)(o + 0xC) = p + 0x3C;
                *(void **)(o + 0x4) = self;
                *(void **)(o + 0x8) = 0;
                *(unsigned int *)(o + 0x18) = 0x424F5820;
                *(float *)(o + 0x10) = f30;
                *(float *)(o + 0x14) = f28;
                *(unsigned int *)(o + 0x20) = 100;
                *(unsigned int *)(o + 0x1C) = 0;
                *(float *)(o + 0x24) = f25;
                *(float *)(o + 0x28) = f26;
                *(float *)(o + 0x2C) = f27;
                *(float *)(o + 0x30) = (float)fn_8002F234(norm) + lbl_80562490;
                *(unsigned int *)(o + 0x34) = 0;
                *(void **)(o + 0x0) = lbl_803338C0;
            }
        } else {
            f25 = f26 + f25;
            f25 = f27 + f25;
            f25 = f25 / lbl_80562494;
            f25 = f25 * lbl_80562478;
            object = fn_801284F8(0x54, names + 0xB8);
            if (object != 0) {
                unsigned char *o = (unsigned char *)object;
                *(void **)(o + 0xC) = p + 0x3C;
                *(void **)(o + 0x4) = self;
                *(void **)(o + 0x8) = 0;
                *(unsigned int *)(o + 0x18) = 0x53504852;
                *(float *)(o + 0x10) = f30;
                *(float *)(o + 0x14) = f28;
                *(unsigned int *)(o + 0x20) = 100;
                *(unsigned int *)(o + 0x1C) = 0;
                *(float *)(o + 0x24) = f25;
                *(float *)(o + 0x28) = stack.v1b8[0];
                *(float *)(o + 0x2C) = stack.v1b8[1];
                *(float *)(o + 0x30) = stack.v1b8[2];
                *(float *)(o + 0x34) = lbl_8056247C;
                *(float *)(o + 0x38) = lbl_8056247C;
                *(float *)(o + 0x3C) = lbl_8056247C;
                *(float *)(o + 0x40) = lbl_8056247C;
                *(float *)(o + 0x44) = lbl_8056247C;
                *(float *)(o + 0x48) = lbl_8056247C;
                *(unsigned char *)(o + 0x4C) = 0;
                *(float *)(o + 0x50) = lbl_8056247C;
                *(void **)(o + 0x0) = lbl_80333B48;
                if (self != 0) fn_8019EECC(self, o + 0x28);
            }
        }
        break;
    case 3:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        {
            struct PushNode { void *next; float values[9]; };
            struct PushNode *node;
            float nx = -x * lbl_80562478;
            float ny = y * lbl_80562478;
            float nz = z * lbl_80562478;
            stack.v14c[0] = y * lbl_80562478;
            stack.v14c[1] = -x * lbl_80562478;
            stack.v14c[2] = z * lbl_80562478;
            stack.v1b8[0] = nx;
            stack.v1b8[1] = ny;
            stack.v1b8[2] = nz;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
        }
        break;
    case 4:
        {
            struct PushNode { void *next; float values[9]; };
            struct PushNode *node;
            float vx, vy, vz, c0, s0, q0;
            x = *(float *)(c + 0x58);
            y = *(float *)(c + 0x5C);
            z = *(float *)(c + 0x60);
            f25 = x * lbl_80562478;
            f26 = z;
            f27 = y;
            vx = x;
            vy = -z * lbl_80562478;
            vz = x;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            c0 = (float)cos(lbl_805624B8);
            s0 = (float)sin(lbl_805624B8);
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * lbl_805624AC;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = lbl_80562478;
            node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
        }
        object = fn_801284F8(0x54, names + 0x110);
        if (object != 0) {
            unsigned char *o = (unsigned char *)object;
            *(void **)(o + 0xC) = p + 0x3C;
            *(void **)(o + 0x4) = self;
            *(void **)(o + 0x8) = 0;
            *(unsigned int *)(o + 0x18) = 0x53504852;
            *(float *)(o + 0x10) = f30;
            *(float *)(o + 0x14) = f28;
            *(unsigned int *)(o + 0x20) = 100;
            *(unsigned int *)(o + 0x1C) = 0;
            *(void **)(o + 0x0) = lbl_80333B48;
            *(float *)(o + 0x24) = f25;
            *(float *)(o + 0x28) = stack.v1b8[0];
            *(float *)(o + 0x2C) = stack.v1b8[1];
            *(float *)(o + 0x30) = stack.v1b8[2];
            *(float *)(o + 0x34) = lbl_8056247C;
            *(float *)(o + 0x38) = lbl_8056247C;
            *(float *)(o + 0x3C) = lbl_8056247C;
            *(float *)(o + 0x40) = lbl_8056247C;
            *(float *)(o + 0x44) = lbl_8056247C;
            *(float *)(o + 0x48) = lbl_8056247C;
            *(unsigned char *)(o + 0x4C) = 0;
            *(float *)(o + 0x50) = lbl_8056247C;
            if (self != 0) fn_8019EECC(self, o + 0x28);
        }
        mode = 0;
        break;
    case 5:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        halfY = y * lbl_80562478;
        fn_801A9798(self, x, halfY, x, f29);
        object = fn_801284F8(0x5C, names + 0x124);
        if (object != 0) {
            unsigned char *o = (unsigned char *)object;
            float maximum = x > halfY ? x : halfY;
            *(void **)(o + 0xC) = p + 0x3C;
            *(void **)(o + 0x4) = self;
            *(void **)(o + 0x8) = 0;
            *(unsigned int *)(o + 0x18) = 0x53504852;
            *(float *)(o + 0x10) = f30;
            *(float *)(o + 0x14) = f28;
            *(unsigned int *)(o + 0x20) = 100;
            *(unsigned int *)(o + 0x1C) = 0;
            *(void **)(o + 0x0) = lbl_80333B48;
            *(float *)(o + 0x24) = maximum;
            *(float *)(o + 0x28) = lbl_8056247C;
            *(float *)(o + 0x2C) = lbl_8056247C;
            *(float *)(o + 0x30) = lbl_8056247C;
            *(float *)(o + 0x34) = lbl_8056247C;
            *(float *)(o + 0x38) = lbl_8056247C;
            *(float *)(o + 0x3C) = lbl_8056247C;
            *(float *)(o + 0x40) = lbl_8056247C;
            *(float *)(o + 0x44) = lbl_8056247C;
            *(float *)(o + 0x48) = lbl_8056247C;
            *(unsigned char *)(o + 0x4C) = 0;
            *(float *)(o + 0x50) = lbl_8056247C;
            if (self != 0) fn_8019EECC(self, o + 0x28);
            *(void **)(o + 0x0) = lbl_80333AF8;
            *(float *)(o + 0x54) = x;
            *(float *)(o + 0x58) = halfY;
            *(unsigned int *)(o + 0x18) = 0x464C5352;
        }
        mode = 0;
        break;

    case 8:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        {
            struct PushNode { void *next; float values[9]; };
            struct PushNode *node;
            float nx = x * lbl_80562478;
            float ny = y * lbl_80562478;
            float nz = z * lbl_80562478;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
        }
        object = fn_801284F8(0x184, names + 0x110);
        if (object != 0) {
            object = fn_8019FFD8(object, p + 0x3C, self);
            fn_801A0258(object, p + 0x3C, p);
            fn_801A0258(object, p + 0x3C, p);
            object = fn_801A2354(object, p + 0x3C, (void *)stack.v14c, self, x, y, z, f30, f28);
            fn_801A0444(self, object);
        }
        break;
    case 7:
        object = fn_801284F8(0x2C, names + 0xCC);
        if (object != 0) {
            unsigned char *o = (unsigned char *)object;
            *(void **)(o + 0x0) = lbl_80333918;
            *(void **)(o + 0x4) = self;
            *(void **)(o + 0xC) = p + 0x3C;
            *(unsigned int *)(o + 0x18) = 0x54554245;
            *(unsigned char *)(p + 0x221) = 1;
        }
        break;

    case 10:
        scan = fn_80131808(c + 0x58);
        while (scan != 0 && strcmp((const char *)scan, "MRJT") != 0) {
            scan = fn_80131818(scan);
        }
        object = fn_801284F8(0xE0, names + 0x104);
        if (object != 0) {
            object = fn_801A3190(object, p + 0x3C, (void *)stack.v14c,
                                 scan != 0, (void *)stack.v14c,
                                 (void *)stack.v14c, f30, f28);
            *(unsigned char *)(p + 0x221) = 1;
        }
        break;
    case 11:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        object = fn_801284F8(0x54, names + 0x124);
        if (object != 0) {
            fn_80179F94(self, object);
            object2 = fn_801284F8(0x74, names + 0x138);
            if (object2 != 0) {
                object2 = fn_801A2354(object2, p + 0x3C,
                                      (void *)stack.v14c, self,
                                      x, y, z, f30, f28);
            }
            {
                struct PushNode { void *next; float values[9]; };
                struct PushNode *node = (struct PushNode *)fn_801AE180();
                node->values[0] = x; node->values[1] = y; node->values[2] = z; node->values[3] = f29;
                node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
                node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
                node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
                node = (struct PushNode *)fn_801AE180();
                node->values[0] = -x; node->values[1] = y; node->values[2] = z; node->values[3] = f29;
                node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
                node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
                node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
                node = (struct PushNode *)fn_801AE180();
                node->values[0] = x; node->values[1] = -y; node->values[2] = z; node->values[3] = f29;
                node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
                node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
                node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            }
        }
        break;
    case 12:
        object = fn_801284F8(0x74, names + 0xE0);
        if (object != 0) {
            stack.v14c[0] = lbl_8056247C;
            stack.v14c[1] = *(float *)(c + 0x5C) * lbl_80562478;
            stack.v14c[2] = lbl_8056247C;
            x = *(float *)(c + 0x58);
            y = *(float *)(c + 0x5C);
            object = fn_801A2354(object, p + 0x3C, (void *)stack.v14c, self,
                                 lbl_805624A0, lbl_80562490, x, stack.v14c[1], x);
        }
        cfgValue = 0x6E;
        mode = 0;
        break;
    case 13:
    case 18:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        object = fn_801284F8(0x2C, names + 0xCC);
        if (object != 0) {
            unsigned char *o = (unsigned char *)object;
            *(void **)(o + 0x0) = lbl_80333918;
            *(void **)(o + 0x4) = self;
            *(void **)(o + 0xC) = p + 0x3C;
            *(unsigned int *)(o + 0x18) = 0x54554245;
            *(float *)(p + 0x238) = f30;
        }
        {
            struct PushNode { void *next; float values[9]; };
            struct PushNode *node = (struct PushNode *)fn_801AE180();
            node->values[0] = x; node->values[1] = y; node->values[2] = z; node->values[3] = f29;
            node->values[4] = lbl_80562478; node->values[5] = lbl_8056247C; node->values[6] = lbl_8056247C;
            node->values[7] = lbl_8056247C; node->values[8] = lbl_8056247C;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
        }
        break;
    case 16:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        f25 = x * lbl_80562478;
        f26 = y * lbl_80562478;
        f27 = z * lbl_80562478;
        fn_801A9798(self, f25, f26, f27, f29);
        object = fn_801284F8(0x38, names + 0xA8);
        if (object != 0) {
            unsigned char *o = (unsigned char *)object;
            *(void **)(o + 0x0) = lbl_803338C0;
            *(void **)(o + 0x4) = self;
            *(void **)(o + 0xC) = p + 0x3C;
            *(unsigned int *)(o + 0x18) = 0x4F465350;
            *(float *)(p + 0x228) = f25;
            *(float *)(p + 0x22C) = f26;
            *(float *)(p + 0x230) = f27;
            *(unsigned char *)(p + 0x234) = 1;
            *(unsigned char *)(p + 0x235) = 1;
        }
        break;
    case 20:
        object = fn_801284F8(0x40, lbl_8055A888);
        if (object != 0) {
            fn_801A3DAC(object, p + 0x3C, c + 0x58, self);
            *(unsigned char *)(p + 0x221) = 1;
        }
        break;
    case 21:
        {
            struct Collection { unsigned char pad[0x10]; unsigned int count; void **items; };
            struct Record { unsigned int tag; unsigned int unk; unsigned int count; unsigned char pad[0x44]; float point[3]; };
            struct PushNode { void *next; float values[9]; };
            struct Collection *collection = (struct Collection *)fn_802C6B44(c + 0x6C);
            unsigned int outer = 0;
            mode = 0;
            while (outer < collection->count) {
                struct Record *record = (struct Record *)collection->items[outer];
                if (record->tag == 0x4D524A54) {
                    unsigned int inner = 0;
                    struct Record *point = record;
                    while (inner < record->count) {
                        struct PushNode *node = (struct PushNode *)fn_801AE180();
                        node->values[0] = point->point[0];
                        node->values[1] = point->point[1];
                        node->values[2] = point->point[2];
                        node->values[3] = f29;
                        node->values[4] = lbl_80562478;
                        node->values[5] = lbl_8056247C;
                        node->values[6] = lbl_8056247C;
                        node->values[7] = lbl_8056247C;
                        node->values[8] = lbl_8056247C;
                        node->next = *(void **)(p + 0xD0);
                        *(void **)(p + 0xD0) = node;
                        point = (struct Record *)((unsigned char *)point + 0x50);
                        inner++;
                    }
                }
                outer++;
            }
            fn_802C6C20(collection);
            x = *(float *)(c + 0x58);
            y = *(float *)(c + 0x5C);
            {
                float difference = y - x;
                difference = (float)__fabs((double)difference);
                if (difference > lbl_80558DC4) {
                    float maximum = x > y ? x : y;
                    object = fn_801284F8(0x5C, names + 0x17C);
                    if (object != 0) {
                        unsigned char *o = (unsigned char *)object;
                        *(void **)(o + 0xC) = p + 0x3C;
                        *(void **)(o + 0x4) = self;
                        *(void **)(o + 0x8) = 0;
                        *(unsigned int *)(o + 0x18) = 0x53504852;
                        *(float *)(o + 0x10) = f30;
                        *(float *)(o + 0x14) = f28;
                        *(unsigned int *)(o + 0x20) = 100;
                        *(unsigned int *)(o + 0x1C) = 0;
                        *(void **)(o + 0x0) = lbl_80333B48;
                        *(float *)(o + 0x24) = maximum;
                        *(float *)(o + 0x28) = lbl_8056247C;
                        *(float *)(o + 0x2C) = lbl_8056247C;
                        *(float *)(o + 0x30) = lbl_8056247C;
                        *(float *)(o + 0x34) = lbl_8056247C;
                        *(float *)(o + 0x38) = lbl_8056247C;
                        *(float *)(o + 0x3C) = lbl_8056247C;
                        *(float *)(o + 0x40) = lbl_8056247C;
                        *(float *)(o + 0x44) = lbl_8056247C;
                        *(float *)(o + 0x48) = lbl_8056247C;
                        *(unsigned char *)(o + 0x4C) = 0;
                        *(float *)(o + 0x50) = lbl_8056247C;
                        if (self != 0) fn_8019EECC(self, o + 0x28);
                        *(void **)(o + 0x0) = lbl_80333AF8;
                        *(float *)(o + 0x54) = x;
                        *(float *)(o + 0x58) = y;
                        *(unsigned int *)(o + 0x18) = 0x464C5352;
                    }
                } else {
                    object = fn_801284F8(0x54, names + 0x17C);
                    if (object != 0) {
                        unsigned char *o = (unsigned char *)object;
                        *(void **)(o + 0xC) = p + 0x3C;
                        *(void **)(o + 0x4) = self;
                        *(void **)(o + 0x8) = 0;
                        *(unsigned int *)(o + 0x18) = 0x53504852;
                        *(float *)(o + 0x10) = f30;
                        *(float *)(o + 0x14) = f28;
                        *(unsigned int *)(o + 0x20) = 100;
                        *(unsigned int *)(o + 0x1C) = 0;
                        *(void **)(o + 0x0) = lbl_80333B48;
                        *(float *)(o + 0x24) = x;
                        *(float *)(o + 0x28) = lbl_8056247C;
                        *(float *)(o + 0x2C) = lbl_8056247C;
                        *(float *)(o + 0x30) = lbl_8056247C;
                        *(float *)(o + 0x34) = lbl_8056247C;
                        *(float *)(o + 0x38) = lbl_8056247C;
                        *(float *)(o + 0x3C) = lbl_8056247C;
                        *(float *)(o + 0x40) = lbl_8056247C;
                        *(float *)(o + 0x44) = lbl_8056247C;
                        *(float *)(o + 0x48) = lbl_8056247C;
                        *(unsigned char *)(o + 0x4C) = 0;
                        *(float *)(o + 0x50) = lbl_8056247C;
                        if (self != 0) fn_8019EECC(self, o + 0x28);
                    }
                }
            }
        }
        break;
    case 23:
        mode = 0;
        break;
    default:
        break;
    }
    {
        extern float lbl_805624D4;
        extern int lbl_8055E5E8;
        extern char lbl_8055A890[], lbl_8055A898[], lbl_8055A8A8[];
        extern unsigned char lbl_8055A8A0;
        extern void fn_801DA758(int, unsigned char *, int);
        struct ObjectVTable { unsigned int pad[16]; void (*method)(void *, int); };
        unsigned int flags = *(unsigned int *)(c + 0x54);
        void *node;
        if (flags & 4) mode = 1;
        if (flags & 8) mode = 0;
        if (object != 0) {
            ((struct ObjectVTable *)*(void **)object)->method(object, cfgValue);
            fn_80179F94(self, object);
            *(unsigned char *)(p + 0x1E8) = (unsigned char)mode;
        }
        node = *(void **)(p + 0xD0);
        while (node != 0) {
            *(float *)((unsigned char *)node + 0x14) = lbl_805624D4;
            node = *(void **)node;
        }
        temp0 = *(unsigned int *)(p + 0x3C); temp1 = *(unsigned int *)(p + 0x40);
        *(unsigned int *)(p + 0x1EC) = temp0; *(unsigned int *)(p + 0x1F0) = temp1;
        temp0 = *(unsigned int *)(p + 0x44); temp1 = *(unsigned int *)(p + 0x48);
        *(unsigned int *)(p + 0x1F4) = temp0; *(unsigned int *)(p + 0x1F8) = temp1;
        temp0 = *(unsigned int *)(p + 0x4C); temp1 = *(unsigned int *)(p + 0x50);
        *(unsigned int *)(p + 0x1FC) = temp0; *(unsigned int *)(p + 0x200) = temp1;
        temp0 = *(unsigned int *)(p + 0x54); temp1 = *(unsigned int *)(p + 0x58);
        *(unsigned int *)(p + 0x204) = temp0; *(unsigned int *)(p + 0x208) = temp1;
        temp0 = *(unsigned int *)(p + 0x5C); temp1 = *(unsigned int *)(p + 0x60);
        *(unsigned int *)(p + 0x20C) = temp0; *(unsigned int *)(p + 0x210) = temp1;
        temp0 = *(unsigned int *)(p + 0x64); temp1 = *(unsigned int *)(p + 0x68);
        *(unsigned int *)(p + 0x214) = temp0; *(unsigned int *)(p + 0x218) = temp1;
        *(unsigned int *)(p + 0x224) = 0;
        if (flags & 1) {
            unsigned int bit = flags & 2;
            void *head = (void *)lbl_8055E5E4;
            if (head != 0 && bit == (unsigned int)lbl_8055E5E8) {
                *(void **)(p + 0x224) = head;
                node = head;
                while (*(void **)((unsigned char *)node + 0x224) != head)
                    node = *(void **)((unsigned char *)node + 0x224);
                *(void **)((unsigned char *)node + 0x224) = self;
            } else {
                *(void **)(p + 0x224) = self;
            }
            lbl_8055E5E8 = (int)bit;
            lbl_8055E5E4 = (int)self;
        } else {
            lbl_8055E5E4 = 0;
        }
        if (*(void **)(c + 0x80) != 0) {
            void *iface = *(void **)(c + 0x80);
            struct IfaceVTable {
                void *pad0[3];
                int (*has)(void *, const char *);
                void *pad1;
                void *(*get)(void *, const char *);
                void *(*get2)(void *, const char *, const char *);
            };
            struct IfaceVTable *vt = (struct IfaceVTable *)*(void **)iface;
            if (vt->has(iface, lbl_8055A890)) {
                void *a = vt->get(iface, lbl_8055A890);
                void *b = vt->get2(iface, (const char *)&lbl_8055A8A0, lbl_8055A8A8);
                void *d = vt->get2(iface, lbl_8055A898, (const char *)b);
                fn_801DA758((int)self, (unsigned char *)d, (int)a);
                *(unsigned char *)(p + 0x222) = 1;
                for (i = 0; i < *(unsigned int *)(p + 0x24); i++) {
                    void *entry = i < *(int *)(p + 0x24) ?
                        *(void **)((unsigned char *)self + 0x14 + i * 4) : 0;
                    struct EntryVTable { unsigned int pad[16]; void (*call)(void *, int); };
                    ((struct EntryVTable *)*(void **)entry)->call(entry, 0x72);
                }
            }
        }
    }
}
#pragma scheduling on
void fn_801ABB54(void *arg0) {
    extern float lbl_80562478, lbl_8056247C, lbl_805624A4, lbl_805624AC, lbl_805624D8;
    float dot, magnitude, sign, limit;
    float unused, scale;
    double absolute;
    float z, y, x;
    char *p = arg0;
    dot = PSVECDotProduct((Vec *)(p + 0x124), (Vec *)(p + 0x54));
    limit = *(float *)(p + 0x238);
    scale = lbl_8056247C;
    absolute = __fabs(dot);
    magnitude = (float)absolute;
    if (magnitude > limit) {
        limit = limit < magnitude ? limit : magnitude;
        if (dot > lbl_8056247C) sign = lbl_805624AC;
        else sign = lbl_805624A4;
        scale = -sign * limit;
    } else if (magnitude > lbl_805624D8) {
        scale = -dot * lbl_80562478;
    }
    x = *(float *)(p + 0x54) * scale;
    y = *(float *)(p + 0x58) * scale;
    z = *(float *)(p + 0x5C) * scale;
    y = *(float *)(p + 0x128) + y;
    x = *(float *)(p + 0x124) + x;
    z = *(float *)(p + 0x12C) + z;
    *(float *)(p + 0x128) = y;
    *(float *)(p + 0x124) = x;
    *(float *)(p + 0x12C) = z;
}

extern void fn_8017B81C(void *);
extern void fn_8017C7C8(void *, float *, float *);
extern float lbl_805624AC, lbl_805624DC, lbl_805624E0, lbl_805624E4;
#pragma cplusplus on
extern "C" void fn_801ABC28(void *arg0) {
    extern void fn_8017A580(void *, int, int, int, int, int, int, int);
    extern void fn_801796CC(int, void *, int);
    struct Work {
        float first[3];
        float second[3];
        Vec output;
        void *object;
        unsigned char flag;
    } work;
    char *p = (char *)arg0;
    register int t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    int flag;
    float first, scale;

    if (*(unsigned char *)(p + 0x222) != 0) {
        *(unsigned char *)(p + 0x1e9) = 0;
        fn_8017C7C8(arg0, work.second, work.first);
        return;
    }
    if (PSVECDotProduct((Vec *)(p + 0x118), (Vec *)(p + 0x118)) > lbl_805624DC ||
        PSVECDotProduct((Vec *)(p + 0x124), (Vec *)(p + 0x124)) > lbl_805624DC) {
        if (*(float *)(p + 0x64) > lbl_805624E0)
            fn_801AC240(arg0);
    }
    if (*(unsigned char *)(p + 0x220) != 0) {
        if (lbl_8055E3C4 == 1 ||
            lbl_8055E3C8 > lbl_805624AC + *(float *)(p + 0x21c)) {
            fn_801AC254(arg0);
            scale = lbl_8056247C;
            *(float *)(p + 0x124) = scale;
            *(float *)(p + 0x128) = scale;
            *(float *)(p + 0x12c) = scale;
            *(float *)(p + 0x118) = scale;
            *(float *)(p + 0x11c) = scale;
            *(float *)(p + 0x120) = scale;
        } else if (*(unsigned char *)(p + 0x221) == 0) {
            fn_8017B81C(arg0);
            #pragma scheduling off
            {
                float a, b, c, d, e, f;
                float r0, r1, r2, r3, r4, r5, check;
                a = *(volatile float *)(p + 0x118);
                scale = *(volatile float *)&lbl_805624E4;
                b = *(volatile float *)(p + 0x11c);
                r0 = a * scale;
                c = *(volatile float *)(p + 0x120);
                r1 = b * scale;
                d = *(volatile float *)(p + 0x124);
                r2 = c * scale;
                e = *(volatile float *)(p + 0x128);
                r3 = d * scale;
                f = *(volatile float *)(p + 0x12c);
                r4 = e * scale;
                r5 = f * scale;
                check = *(volatile float *)(p + 0x238);
                *(float *)(p + 0x118) = r0;
                *(float *)(p + 0x11c) = r1;
                *(float *)(p + 0x120) = r2;
                *(float *)(p + 0x124) = r3;
                *(float *)(p + 0x128) = r4;
                *(float *)(p + 0x12c) = r5;
                if (check > lbl_8056247C)
                    fn_801ABB54(arg0);
            }
            #pragma scheduling on
            flag = 0;
            if (*(unsigned char *)(p + 0x234) != 0 &&
                *(float *)(p + 0x4c) > lbl_80562478)
                flag = 1;
            *(unsigned char *)(p + 0x234) = (unsigned char)flag;
        } else {
            fn_8017B81C(arg0);
            t0 = *(int *)(p + 0x1ec);
            t1 = *(int *)(p + 0x1f0);
            t2 = *(int *)(p + 0x1f4);
            t3 = *(int *)(p + 0x1f8);
            t4 = *(int *)(p + 0x1fc);
            t5 = *(int *)(p + 0x200);
            t6 = *(int *)(p + 0x204);
            t7 = *(int *)(p + 0x208);
            t8 = *(int *)(p + 0x20c);
            t9 = *(int *)(p + 0x210);
            t10 = *(int *)(p + 0x214);
            t11 = *(int *)(p + 0x218);
            scale = lbl_8056247C;
            *(float *)(p + 0x124) = scale;
            *(float *)(p + 0x128) = scale;
            *(float *)(p + 0x12c) = scale;
            *(float *)(p + 0x118) = scale;
            *(float *)(p + 0x11c) = scale;
            *(float *)(p + 0x120) = scale;
            *(int *)(p + 0x3c) = t0;
            *(int *)(p + 0x40) = t1;
            *(int *)(p + 0x44) = t2;
            *(int *)(p + 0x48) = t3;
            *(int *)(p + 0x4c) = t4;
            *(int *)(p + 0x50) = t5;
            *(int *)(p + 0x54) = t6;
            *(int *)(p + 0x58) = t7;
            *(int *)(p + 0x5c) = t8;
            *(int *)(p + 0x60) = t9;
            *(int *)(p + 0x64) = t10;
            *(int *)(p + 0x68) = t11;
            ((void (*)(void *))fn_8017A580)(arg0);
        }
        if (*(float *)(p + 0x64) < lbl_805624E0) {
            struct Dummy { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); };
            ((Dummy *)arg0)->d2();
        }
    }
    if (*(unsigned char *)(p + 0x235) != 0) {
        #pragma scheduling off
        if ((char *)&work.output == p + 0x228) {
            register float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;
            f0 = *(volatile float *)(p + 0x7c);
            f6 = *(volatile float *)(p + 0x22c);
            f2 = *(volatile float *)(p + 0x80);
            f4 = f6 * f0;
            f11 = *(volatile float *)(p + 0x84);
            f1 = *(volatile float *)(p + 0x70);
            f2 = f6 * f2;
            f0 = *(volatile float *)(p + 0x228);
            f3 = *(volatile float *)(p + 0x74);
            f5 = f0 * f1;
            f10 = *(volatile float *)(p + 0x78);
            f3 = f0 * f3;
            f8 = *(volatile float *)(p + 0x88);
            f1 = f0 * f10;
            f0 = f6 * f11;
            f7 = *(volatile float *)(p + 0x230);
            f9 = *(volatile float *)(p + 0x8c);
            f5 = f5 + f4;
            f6 = f7 * f8;
            f12 = *(volatile float *)(p + 0x90);
            f3 = f3 + f2;
            f4 = f7 * f9;
            f0 = f1 + f0;
            f2 = f7 * f12;
            f5 = f6 + f5;
            f1 = f4 + f3;
            f0 = f2 + f0;
            work.output.x = f5;
            work.output.y = f1;
            work.output.z = f0;
        } else {
            work.output.x = *(float *)(p + 0x230) * *(float *)(p + 0x88) +
                (*(float *)(p + 0x228) * *(float *)(p + 0x70) +
                *(float *)(p + 0x22c) * *(float *)(p + 0x7c));
            work.output.y = *(float *)(p + 0x230) * *(float *)(p + 0x8c) +
                (*(float *)(p + 0x228) * *(float *)(p + 0x74) +
                *(float *)(p + 0x22c) * *(float *)(p + 0x80));
            work.output.z = *(float *)(p + 0x230) * *(float *)(p + 0x90) +
                (*(float *)(p + 0x228) * *(float *)(p + 0x78) +
                *(float *)(p + 0x22c) * *(float *)(p + 0x84));
        }
        #pragma scheduling invalid_target
        work.output.x += *(float *)(p + 0x94);
        work.output.y += *(float *)(p + 0x98);
        work.output.z += *(float *)(p + 0x9c);
        work.object = arg0;
        work.flag = *(unsigned char *)(p + 0x234);
        fn_801796CC(9, &work.output, 0x14);
    }
    *(int *)(p + 0x1e4) = 0;
}
#pragma cplusplus reset

#pragma scheduling on
void fn_801ABFF4(void) {
    fn_8017A57C();
}

void fn_801ABFF8(void *self, int **manager) {
    struct CallbackTable {
        void *unk[2];
        void (*call)(void *, void *);
    };
    struct CallbackObject {
        struct CallbackTable *vtable;
    };
    void *node;
    register struct CallbackTable *table;

    node = *(void **)((char *)self + 0x224);
    if (node != 0 &&
        *(unsigned char *)((char *)self + 0x223) != 0 &&
        lbl_8055E3C4 > 1) {
        while (node != self) {
            *(unsigned char *)((char *)node + 0x223) = 0;
            table = ((struct CallbackObject *)manager)->vtable;
            table->call(manager, node);
            node = *(void **)((char *)node + 0x224);
        }
        *(unsigned char *)((char *)self + 0x223) = 0;
    }
    fn_801AC240(self);
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
void fn_801AC0A0(void *arg0, float *arg1, float *arg2, int arg3, int arg4) {
 extern float lbl_805624E8;
 extern int lbl_803357F0[];
 extern void fn_8017D2C8(void *, void *, void *, int, int);
 struct { void *v; float a[3], b[3]; int c,d; } event;
 float value, scale, squared;
 float z2,y2,x2,z,y,x;
 if(arg3>=100 && *((unsigned char *)arg0+0x220)==0) {
 value=*(float *)((char *)arg0+0xD4);
 scale=lbl_805624E8 * value;
 squared=scale*scale;
 if(PSVECDotProduct((Vec *)arg1,(Vec *)arg1)>squared) {
 x=arg1[0]; y=arg1[1]; z=arg1[2];
 x2=arg2[0]; y2=arg2[1]; z2=arg2[2];
 event.v=lbl_803357F0;
 event.a[0]=x; event.a[1]=y; event.a[2]=z;
 event.b[0]=x2; event.b[1]=y2; event.b[2]=z2;
 event.c=arg3; event.d=arg4;
 ((void (*)(void *, void *))fn_801ABFF8)(arg0,&event);
 }
 }
 fn_8017D2C8(arg0,arg1,arg2,arg3,0);
}
#pragma pop

extern void fn_8017A580(void *, int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
void fn_801AC184(void *arg0) {
    int t11, t3, t2, t1, t0, t4, t5, t6, t7, t8, t9, t10;
    fn_801AC240(arg0);
    t0 = *(volatile int *)((char *)arg0 + 0x1EC);
    t1 = *(volatile int *)((char *)arg0 + 0x1F0);
    t2 = *(volatile int *)((char *)arg0 + 0x1F4);
    t3 = *(volatile int *)((char *)arg0 + 0x1F8);
    t4 = *(volatile int *)((char *)arg0 + 0x1FC);
    t5 = *(volatile int *)((char *)arg0 + 0x200);
    t6 = *(volatile int *)((char *)arg0 + 0x204);
    t7 = *(volatile int *)((char *)arg0 + 0x208);
    t8 = *(volatile int *)((char *)arg0 + 0x20C);
    t9 = *(volatile int *)((char *)arg0 + 0x210);
    t10 = *(volatile int *)((char *)arg0 + 0x214);
    t11 = *(volatile int *)((char *)arg0 + 0x218);
    *(int *)((char *)arg0 + 0x3C) = t0;
    *(int *)((char *)arg0 + 0x40) = t1;
    *(int *)((char *)arg0 + 0x44) = t2;
    *(int *)((char *)arg0 + 0x48) = t3;
    *(int *)((char *)arg0 + 0x4C) = t4;
    *(int *)((char *)arg0 + 0x50) = t5;
    *(int *)((char *)arg0 + 0x54) = t6;
    *(int *)((char *)arg0 + 0x58) = t7;
    *(int *)((char *)arg0 + 0x5C) = t8;
    *(int *)((char *)arg0 + 0x60) = t9;
    *(int *)((char *)arg0 + 0x64) = t10;
    *(int *)((char *)arg0 + 0x68) = t11;
    fn_8017A580(arg0, t10, t9, t8, t7, t6, t5, t4);
    fn_8017B164(arg0);
    *(unsigned char *)((char *)arg0 + 0x223) = 1;
    *(unsigned char *)((char *)arg0 + 0x234) = *(unsigned char *)((char *)arg0 + 0x235);
}

#pragma dont_inline on
void fn_801AC240(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x220) = 1;
    *(float *)((char *)arg0 + 0x21C) = lbl_8055E3C8;
}
#pragma dont_inline off

void fn_801AC254(void *arg0) {
    if (*(unsigned char *)((char *)arg0 + 0x220) != 0) {
        *(unsigned char *)((char *)arg0 + 0x220) = 0;
    }
}

void *fn_801AC26C(void) {
    const char *name = lbl_80335718;
    void *obj = ((void *(*)(int, const char *))fn_801284F8)(0x244, name);
    if (obj != 0) {
        fn_801A9700(obj);
        *(void **)obj = &lbl_80335744;
        *(void **)((char *)obj + 0x23C) = (char *)&lbl_80335744 + 0x54;
    }
    return obj;
}

void *fn_801AC2C8(void *arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055E5E4 = 0;
        if (arg0 != 0 && arg0 != 0) fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_801AC330(void *arg0) {
    fn_801A9700(arg0);
    *(void **)arg0 = &lbl_80335808;
    if (*(volatile int *)&lbl_8055E5EC == 0) {
        lbl_8055E5F0 = 0;
    }
    {
        int count = *(volatile int *)&lbl_8055E5EC;
        *(int *)((char *)arg0 + 0x250) = count;
        *(volatile int *)&lbl_8055E5EC = count + 1;
    }
    lbl_80435628[*(int *)((char *)arg0 + 0x250)] = arg0;
    *(int *)((char *)arg0 + 0x254) = -1;
    return arg0;
}

extern void fn_801C1C7C(void);
void **fn_801AC3AC(void **arg0, int arg1) {
    if (arg0 != 0) {
        *arg0 = lbl_80335808;
        lbl_8055E5EC = lbl_8055E5EC - 1;
        if (lbl_8055E5EC == 0) {
            int ptr = lbl_8055E5F0;
            if (ptr != 0) {
                ((void (*)(int))fn_801C1C7C)(ptr);
                lbl_8055E5F0 = 0;
            }
        }
        if (arg0 != 0) {
            lbl_8055E5E4 = 0;
            if (arg0 != 0 && arg0 != 0) fn_80179EE8(arg0, 0);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void fn_802E30C8(const char *, ...);
#pragma scheduling invalid_target
void fn_801AC454(void *arg0, void *arg1) {
    extern float lbl_805624EC;
    extern char lbl_80335728[];
    int count;
    int hasEntries;
    float defaultValue;
    float configValue;
    void *candidate;

    *(void **)((char *)arg0 + 0x23C) = 0;
    *(void **)((char *)arg0 + 0x240) = 0;
    fn_801A9AB0(arg0, arg1);
    count = *(int *)((char *)arg0 + 0x250);
    configValue = *(float *)((char *)arg1 + 0x5C);
    defaultValue = lbl_8056247C;
    hasEntries = count > 0;
    *(float *)((char *)arg0 + 0x248) = configValue;
    *(float *)((char *)arg0 + 0x244) = defaultValue;
    *(float *)((char *)arg0 + 0x24C) = defaultValue;
    *(void **)((char *)arg0 + 0x23C) = 0;
    if (hasEntries) {
        candidate = lbl_80435628[count - 1];
        if (PSVECSquareDistance((const Vec *)((char *)candidate + 0x60),
                                (const Vec *)((char *)arg0 + 0x60)) < lbl_805624EC) {
            *(void **)((char *)arg0 + 0x23C) = candidate;
            fn_802E30C8(lbl_80335728, candidate);
        }
    }
}
#pragma scheduling on
void fn_801AC508(void) {
    s32 value = lbl_8055E5EC;
    if (value > 0) {
        lbl_8055E5F0 = fn_801C1BA4(value * 5, value * 5 - 1);
    }
}
#pragma scheduling on
#pragma dont_inline reset

#pragma push
#pragma scheduling 750
void fn_801ACA48(void *arg0) {
    extern void fn_801ABC28(void *);
    extern float lbl_8056247C, lbl_805624CC, lbl_80562508, lbl_8056250C;
    Vec cross;
    float x, y, z;
    float scale, zero, input;
    float copyZ, copyY, copyX;
    char *p = arg0;
    fn_801ABC28(arg0);
    if (*(unsigned char *)(p + 0x220)) {
        input = *(float *)(p + 0x124);
        scale = lbl_805624CC;
        x = input * scale;
        y = *(float *)(p + 0x128) * scale;
        z = *(float *)(p + 0x12C) * scale;
        zero = lbl_8056247C;
        *(float *)(p + 0x118) = zero;
        *(float *)(p + 0x11C) = zero;
        *(float *)(p + 0x120) = zero;
        *(float *)(p + 0x124) = x;
        *(float *)(p + 0x128) = y;
        *(float *)(p + 0x12C) = z;
        PSVECCrossProduct((Vec *)(p + 0x48), (Vec *)(p + 0x1F8), &cross);
        if (*(float *)(p + 0x4C) < lbl_80562508) {
            float vz, vy, vx, factor, product;
            product = cross.x;
            factor = lbl_8056250C;
            vx = *(float *)(p + 0x124);
            vy = *(float *)(p + 0x128);
            vz = *(float *)(p + 0x12C);
            vx += product * factor;
            *(float *)(p + 0x124) = vx;
            vy += cross.y * factor;
            *(float *)(p + 0x128) = vy;
            vz += cross.z * factor;
            *(float *)(p + 0x12C) = vz;
        }
        copyX = *(float *)(p + 0x210);
        copyY = *(float *)(p + 0x214);
        copyZ = *(float *)(p + 0x218);
        *(float *)(p + 0x60) = copyX;
        *(float *)(p + 0x64) = copyY;
        *(float *)(p + 0x68) = copyZ;
    }
}

extern float lbl_80558DC4, lbl_8055E460, lbl_805624AC;
void fn_801ACB30(void *arg0, int arg1) {
    char *p = (char *)arg0;
    char *out = (char *)(arg1 + *(int *)(p + 8));
    float t = lbl_8055E460 - lbl_805624AC;
    int i;
    if (__fabsf(t) <= lbl_80558DC4) {
        for (i = 0; i < 12; i++) *(int *)(out + i*4) = *(int *)(p + 0x70 + i*4);
    } else {
        for (i = 0; i < 12; i++) {
            float a = *(float *)(p + 0x70 + i*4);
            float b = *(float *)(p + 0xA0 + i*4);
            *(float *)(out + i*4) = b + t * (a - b);
        }
    }
    *(short *)(out + 0x30) = *(short *)(p + 0x6C);
    if (*(void **)(p + 0x23C)) {
        float *v = (float *)(p + 0x244);
        float *q = (float *)(p + 0x244);
        for (i = 0; i < 3; i++) {
            float x = v[0] * *(float *)(p + 0x3C + i*4) +
                      v[1] * *(float *)(p + 0x48 + i*4) +
                      v[2] * *(float *)(p + 0x54 + i*4) +
                      *(float *)(p + 0x60 + i*4);
            *(float *)((char *)&t + i*4) = x;
        }
        for (i = 0; i < 3; i++) {
            float x = q[0] * *(float *)((char *)*(void **)(p + 0x23C) + 0x3C + i*4) +
                      q[1] * *(float *)((char *)*(void **)(p + 0x23C) + 0x48 + i*4) +
                      q[2] * *(float *)((char *)*(void **)(p + 0x23C) + 0x54 + i*4) +
                      *(float *)((char *)*(void **)(p + 0x23C) + 0x60 + i*4);
            *(float *)(p + 0x8 + i*4) = x;
        }
    }
}

typedef struct { u8 pad[0x23C]; void *unk_0x23C; u8 pad2[0x14]; s32 unk_0x254; } Obj_801ACF94;
typedef struct { u8 pad[0x254]; s32 unk_0x254; } Mesh_801ACF94;
extern int lbl_8055E5EC, lbl_8055E5F0;
extern float lbl_8056247C, lbl_805624AC, lbl_80562510;
extern void fn_801C2694(void *, int *, float *, float *, float *, float *, float *, float, float);
extern void fn_801796CC(int, void *, int);
#pragma scheduling invalid_target
void fn_801ACF94(void) {
    char sp8[0x34];
    char sp3c[0x54];
    char sp90[0xED0];
    Obj_801ACF94 **obj;
    int i, j, zero, first;
    Obj_801ACF94 *o;
    Mesh_801ACF94 *a;
    void *root;
    float *src, *dst;
    float fill, special, tail, x, y, z;

    root = (void *)lbl_8055E5F0;
    if (root != 0) {
        fill = lbl_8056247C;
        special = lbl_805624AC;
        tail = lbl_80562510;
        *(int *)sp8 = 0x13C;
        ((float *)sp8)[1] = fill; ((float *)sp8)[2] = fill;
        ((float *)sp8)[3] = fill; ((float *)sp8)[4] = fill;
        ((float *)sp8)[5] = fill; ((float *)sp8)[6] = fill;
        ((float *)sp8)[7] = fill; ((float *)sp8)[8] = special;
        ((float *)sp8)[9] = fill; ((float *)sp8)[10] = fill;
        ((float *)sp8)[11] = tail; ((float *)sp8)[12] = fill;
        fn_801C2694(root, (int *)sp90, (float *)sp8,
                    (float *)(sp8 + 0x28), (float *)(sp8 + 0x1C),
                    (float *)(sp8 + 0x10), (float *)(sp8 + 4),
                    special, fill);
        obj = (Obj_801ACF94 **)lbl_80435628;
        j = 0;
        zero = 0;
        while (j < lbl_8055E5EC) {
            o = *obj;
            a = (Mesh_801ACF94 *)o->unk_0x23C;
            if (a != 0) {
                first = a->unk_0x254;
                src = (float *)(sp90 + first * 12);
                dst = (float *)sp3c;
                *(int *)sp3c = zero;
                *(int *)(sp3c + 8) = o->unk_0x254 - first + 1;
                *(int *)(sp3c + 4) = j;
                i = 0;
                while (i < *(int *)(sp3c + 8)) {
                    x = src[0];
                    i++;
                    y = src[1];
                    dst[3] = x;
                    z = src[2];
                    src += 3;
                    dst[4] = y;
                    dst[5] = z;
                    dst += 3;
                }
                fn_801796CC(6, sp3c, 0x54);
            }
            obj++;
            j++;
        }
    }
}
#pragma scheduling 750

extern float lbl_8056250C;
extern float lbl_80562514;
#pragma scheduling off
void fn_801AD0E0(void *arg0, void *arg1, void *arg2, void *arg3, float farg0, float farg1) {
    float a, b, c, d, x, e, y, z, p, q, r;
    a = lbl_80562514;
    *(volatile int *)((char *)arg0 + 0x0C) = 0;
    b = lbl_8056247C;
    c = a * farg0;
    d = lbl_8056250C;
    x = *(float *)((char *)arg1 + 0x00);
    e = d * c;
    y = *(float *)((char *)arg1 + 0x04);
    z = *(float *)((char *)arg1 + 0x08);
    p = *(float *)((char *)arg3 + 0x00);
    q = *(float *)((char *)arg3 + 0x04);
    r = *(float *)((char *)arg3 + 0x08);
    *(float *)((char *)arg0 + 0x28) = b;
    *(float *)((char *)arg0 + 0x2C) = b;
    *(float *)((char *)arg0 + 0x00) = x;
    *(float *)((char *)arg0 + 0x04) = y;
    *(float *)((char *)arg0 + 0x08) = z;
    *(int *)((char *)arg0 + 0x0C) = (int)arg2;
    *(float *)((char *)arg0 + 0x10) = p;
    *(float *)((char *)arg0 + 0x14) = q;
    *(float *)((char *)arg0 + 0x18) = r;
    *(float *)((char *)arg0 + 0x1C) = farg0;
    *(float *)((char *)arg0 + 0x24) = farg1;
    *(float *)((char *)arg0 + 0x20) = e;
}

#pragma processor 750
#pragma scheduling invalid_target
void fn_801AD148(void *arg0, void *arg1, void *arg2, f32 farg0, f32 farg1) {
    Vec sp14;
    Vec sp8;
    f32 diffX, diffY, diffZ;
    f32 outX, outY, outZ;

    fn_8017AB84(*(void **)((char *)arg0 + 0x34), &sp14, arg1);
    if (arg2 != 0) {
        diffX = sp14.x - *(f32 *)((char *)arg2 + 0x60);
        sp8.x = diffX;
        diffY = sp14.y - *(f32 *)((char *)arg2 + 0x64);
        sp8.y = diffY;
        diffZ = sp14.z - *(f32 *)((char *)arg2 + 0x68);
        sp8.z = diffZ;

        outX = ((diffY * *(f32 *)((char *)arg2 + 0x40)) + (diffX * *(f32 *)((char *)arg2 + 0x3C))) + (diffZ * *(f32 *)((char *)arg2 + 0x44));
        outY = ((diffY * *(f32 *)((char *)arg2 + 0x4C)) + (diffX * *(f32 *)((char *)arg2 + 0x48))) + (diffZ * *(f32 *)((char *)arg2 + 0x50));
        outZ = ((diffY * *(f32 *)((char *)arg2 + 0x58)) + (diffX * *(f32 *)((char *)arg2 + 0x54))) + (diffZ * *(f32 *)((char *)arg2 + 0x5C));

        sp8.x = outX;
        sp8.y = outY;
        sp8.z = outZ;
    } else {
        sp8.x = sp14.x;
        sp8.y = sp14.y;
        sp8.z = sp14.z;
    }
    fn_801AD0E0(arg0, &sp8, arg2, arg1, farg0, farg1);
}
#pragma scheduling on
#pragma processor reset
extern void fn_801AD0E0(void *, void *, void *, void *, f32, f32);
#pragma scheduling invalid_target
void fn_801AD28C(void *arg0, void *arg1, void *arg2, Vec *arg3, f32 farg1, f32 farg0) {
    Vec sp20;
    Vec sp14;
    Vec delta;
    f32 x, y, z;
    f32 distance;
    fn_8017AB84(*(void **)((char *)arg0 + 0x34), &sp20, arg1);
    if (arg2 != 0) {
        fn_8017AB84(arg2, &sp14, arg3);
    } else {
        x = arg3->x;
        y = arg3->y;
        z = arg3->z;
        sp14.x = x;
        sp14.y = y;
        sp14.z = z;
    }
    delta.x = sp14.x - sp20.x;
    delta.y = sp14.y - sp20.y;
    delta.z = sp14.z - sp20.z;
    distance = PSVECMag(&delta);
    *(f32 *)((char *)arg0 + 0x28) = distance;
    fn_801AD0E0(arg0, arg3, arg2, arg1, farg1, farg0);
    *(f32 *)((char *)arg0 + 0x28) = distance;
}
#pragma scheduling on
void fn_801AD5EC(void) {
    fn_801AC508();
}

void fn_801AD5F0(void) {
    fn_801ACF94();
}

extern float lbl_8056249C;
extern float lbl_805624F4;
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801AD5F4(void *arg0, void *arg1) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16(float *, float *, int, int, float, float, float, float, float, float);
    };
    register void *object = arg0;
    register void *other = arg1;
    register float scale = lbl_805624F4;
    register float factor = lbl_8056249C;
    float sp14[3];
    float sp8[3];
    register float temp_f6;
    register float temp_f5;
    register float temp_f4;
    register float temp_f2;
    register float temp_f1;
    register float temp_f0;
    float targetZ;
    float targetY;
    float targetX;

    sp14[0] = *(float *)((char *)object + 4) * scale;
    sp14[1] = *(float *)((char *)object + 8) * scale;
    sp14[2] = *(float *)((char *)object + 0xC) * scale;
    targetZ = *(float *)((char *)other + 0x68);
    temp_f6 = *(float *)((char *)object + 0x18);
    temp_f2 = targetZ - temp_f6;
    targetY = *(float *)((char *)other + 0x64);
    temp_f5 = *(float *)((char *)object + 0x14);
    temp_f1 = targetY - temp_f5;
    targetX = *(float *)((char *)other + 0x60);
    temp_f4 = *(float *)((char *)object + 0x10);
    temp_f0 = targetX - temp_f4;
    temp_f2 = factor * temp_f2;
    temp_f1 = factor * temp_f1;
    temp_f0 = factor * temp_f0;
    temp_f2 = temp_f6 + temp_f2;
    temp_f1 = temp_f5 + temp_f1;
    temp_f0 = temp_f4 + temp_f0;
    sp8[2] = temp_f2;
    sp8[0] = temp_f0;
    sp8[1] = temp_f1;
    ((Obj *)other)->v16(sp14, sp8,
                       *(int *)((char *)object + 0x1C),
                       *(int *)((char *)object + 0x20),
                       temp_f1, temp_f2, factor,
                       temp_f4, temp_f5, temp_f6);
}
#pragma scheduling on
#pragma pop

extern void fn_801D0A24(void *, void *);
extern void fn_801AC0A0(void *, float *, float *, int, int);
extern void fn_801D09A8(void *, int);
extern void fn_801A9AB0(void *, void *);
extern void fn_801D08C0(void *);
extern void fn_801D0934(void *);
void *fn_801AD6B0(void *arg0, int arg1) {
    void *initArg;

    if (arg0 == 0) {
        goto done;
    }
    *(void **)arg0 = &lbl_80335744;
    initArg = arg0;
    *(void **)((char *)arg0 + 0x23C) = (char *)&lbl_80335744 + 0x54;
    if (arg0 == 0) {
        goto init_call;
    }
    initArg = (char *)arg0 + 0x23C;
init_call:
    fn_801D0934(initArg);
    *(int *)((char *)arg0 + 0x240) = 0;
    if (arg0 != 0) {
        lbl_8055E5E4 = 0;
        if (arg0 != 0) {
            if (arg0 != 0) {
                fn_80179EE8(arg0, 0);
            }
        }
    }
    if (arg1 > 0) {
        fn_80128668(arg0);
    }
done:
    return arg0;
}

#pragma scheduling invalid_target
void fn_801AD750(void *arg0, void *arg1) {
    void *var_r30 = arg0;
    fn_801A9AB0(arg0, arg1);
    *(int *)((char *)var_r30 + 0x240) = *(int *)((char *)arg1 + 0x80);
    if (var_r30 != 0) {
        var_r30 = (char *)var_r30 + 0x23C;
        fn_801D08C0(var_r30);
    }
}
#pragma scheduling on
void fn_801AD7A4(void *arg0, void *arg1, void *arg2, int arg3) {
    void *obj;
    if (arg3 >= 8) return;
    if (arg0 == 0) return;
    obj = (char *)arg0 + 0x23C;
    fn_801D0A24(obj, arg2);
}
#pragma scheduling on
unsigned char fn_801AD860(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

long fn_801AD868(void) {
    return 0;
}

void fn_801AD870(void *arg0, void *arg1, void *arg2, long *arg3, long *arg4) {
    *arg4 = 0;
    *arg3 = 0;
}

long fn_801AD880(void) {
    return 0;
}

#pragma cplusplus on
struct Dummy_801AD888 {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
};
#pragma cplusplus on
extern "C" void fn_801AD888(void *arg0) {
    ((Dummy_801AD888 *)arg0)->d2();
    ((void (*)(void *))fn_801AC254)(arg0);
}
#pragma cplusplus off

void fn_801AD8C8(void *arg0, int *arg1, float *arg2, float *arg3) {
    int l, k, j, i, h, g, f, e, d, c, b, a;
    float z1, y1, x1, z0, y0, x0;
    a=arg1[0]; b=arg1[1]; c=arg1[2]; d=arg1[3];
    e=arg1[4]; f=arg1[5]; g=arg1[6]; h=arg1[7];
    i=arg1[8]; j=arg1[9]; k=arg1[10]; l=arg1[11];
    *(int *)((char *)arg0+0x3c)=a;
    *(int *)((char *)arg0+0x40)=b;
    *(int *)((char *)arg0+0x44)=c;
    *(int *)((char *)arg0+0x48)=d;
    *(int *)((char *)arg0+0x4c)=e;
    *(int *)((char *)arg0+0x50)=f;
    *(int *)((char *)arg0+0x54)=g;
    *(int *)((char *)arg0+0x58)=h;
    *(int *)((char *)arg0+0x5c)=i;
    *(int *)((char *)arg0+0x60)=j;
    *(int *)((char *)arg0+0x64)=k;
    *(int *)((char *)arg0+0x68)=l;
    ((void (*)(void *))fn_8017A580)(arg0);
    x0=arg2[0]; y0=arg2[1]; z0=arg2[2];
    x1=arg3[0]; y1=arg3[1]; z1=arg3[2];
    *(float *)((char *)arg0+0x118)=x0;
    *(float *)((char *)arg0+0x11c)=y0;
    *(float *)((char *)arg0+0x120)=z0;
    *(float *)((char *)arg0+0x124)=x1;
    *(float *)((char *)arg0+0x128)=y1;
    *(float *)((char *)arg0+0x12c)=z1;
    fn_801AC240(arg0);
}

#pragma push
#pragma cplusplus on
extern "C" void fn_801AD99C(void *arg0, float *arg1, float *arg2) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16(float *, float *, int, int);
    };
    float scale;
    float sp14[3];
    float sp8[3];
    scale = *(float *)((char *)arg0 + 0xD4) / lbl_805624D0;
    sp14[0] = arg1[0] * scale;
    sp14[1] = arg1[1] * scale;
    sp14[2] = arg1[2] * scale;
    sp8[0] = *(float *)((char *)arg0 + 0x60) + arg2[0];
    sp8[1] = *(float *)((char *)arg0 + 0x64) + arg2[1];
    sp8[2] = *(float *)((char *)arg0 + 0x68) + arg2[2];
    ((Obj *)arg0)->v16(sp14, sp8, 100, 0);
}
#pragma pop
void fn_801ADA38(void *arg0, int arg1) {
    int *sp8;
    if (arg1) {
        sp8 = (int *)lbl_80335940;
        ((void (*)(void *, int **))fn_801ABFF8)(arg0, &sp8);
    } else {
        *((char *)arg0 + 0x220) = 0;
    }
}

unsigned char fn_801ADA7C(void *arg0) {
    return ((unsigned char *)arg0)[0x220];
}

short fn_801ADA84(void *arg0) {
    return *(short *)((char *)arg0 + 0x6C);
}

long fn_801ADA8C(long arg0) { return arg0 + 0x118; }

long fn_801ADA94(long arg0) {
    return arg0 + 0x60;
}

extern float lbl_8055E3C8;
typedef void (*Fn801ADA9C)(void *, void *, void *);
extern unsigned char lbl_8055A8A0;
extern unsigned char lbl_8055A8B0;
void fn_801ADA9C(void *arg0) {
    struct Obj_801ADA9C *obj = *(struct Obj_801ADA9C **)((char *)arg0 + 0x240);
    obj->vtable->call(obj, &lbl_8055A8A0, &lbl_8055A8B0);
}

long fn_801ADAB8(void *arg0) {
    return *(long *)((char *)arg0 + 0x240);
}

void fn_801ADAC0(void *arg0, long arg1) {
    fn_801AC240((void *)arg1);
}
