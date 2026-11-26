#include "revolution/MTX/vec.h"
#pragma cplusplus on
class Dummy_801ADA9C {
public:
    virtual void d0(void *, void *);
    virtual void d1(void *, void *);
    virtual void d2(void *, void *);
    virtual void d3(void *, void *);
    virtual void v4(void *, void *);
};
struct Dummy_801ABFF8 {
    virtual void f0(void *);
};
#pragma cplusplus off
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
extern void Abend_Panic(const char *, ...);
extern void **fn_801A9700(void **);
extern int lbl_8055E3C4;
extern int lbl_8055A858;
extern int jumptable_80335578[];
extern void *fn_801AC330(void *);
extern void *fn_801AC26C(void);
extern void fn_8017AB84(void *, Vec *, void *);
#pragma scheduling invalid_target
/* Create/return an obstacle object for the current mode (mode id at fn_801792F8()+0x50): selects constructor/path by (mode-6), logs fatal error for modes reserved to SOL, and returns NULL or the initialized object. */
void *fn_801A9660(void) {
    extern char lbl_80335528[];
    extern char lbl_80335538[];
    unsigned int modeIndex = *(unsigned int *)((char *)fn_801792F8() + 0x50) - 6;
    void *object;

    switch (modeIndex) {
    case 6:
        object = ((void *(*)(int, const char *))fn_801284F8)(0x258, lbl_80335528);
        if (object != 0)
            return fn_801AC330(object);
        return object;
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
        Abend_Panic(lbl_80335538);
        return 0;
    default:
        object = ((void *(*)(int, int *))fn_801284F8)(0x23c, &lbl_8055A858);
        if (object != 0)
            return fn_801A9700(object);
        return object;
    }
}
#pragma scheduling on
void** fn_801A9700(void** object) {
#define ObstacleBaseCtor fn_8017B0B0
#define ObstacleVtable lbl_8033585C
    /* Construct the base obstacle: run shared base-object setup and install the obstacle vtable. */
    ObstacleBaseCtor(object);
    *object = &ObstacleVtable;
    return object;
#undef ObstacleVtable
#undef ObstacleBaseCtor
}
#pragma scheduling on
/* Deleting destructor for nw4r::snd::detail::DisposeCallbackManager: destroy base
 * state, then optionally free the object. */
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801A973C(void *self, int shouldDelete) {
    if (self) {
        if (self != 0) fn_80179EE8(self, 0);
        if (shouldDelete > 0) fn_80128668(self);
    }
    return self;
}

extern void *fn_801AE180(void);
extern f32 lbl_80562478, lbl_8056247C;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801A9798(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    struct Node_801A9798 { void *next; f32 values[9]; };
    struct Node_801A9798 *node;
    volatile f32 sp64, sp60, sp5c, sp58, sp54, sp50, sp4c, sp48, sp44;
    volatile f32 sp40, sp3c, sp38, sp34, sp30, sp2c, sp28, sp24, sp20;
    volatile f32 sp1c, sp18, sp14, sp10, spC, sp8;
    f32 constA, constB;
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
#pragma pop
void fn_801A9AB0(void *self, void *cfg) {
    extern void fn_8017B0F8(void *, void *);
    extern void fn_8017A580(void *);
    extern void fn_8019EECC(void *, void *);
    extern double fn_8002F234(float);
    extern double lbl_805624B8;
    extern double cos(double), sin(double);
    extern void *fn_802C6B44(void *);
    extern void MRModel_ReleaseResource(void *);
    extern double __fabs(double);
    extern float lbl_80562488;
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
    extern float lbl_80562484;
    struct StackSpace {
        char pad[0x144];
        float v14c[3];
        char gap[0x60];
        float v1b8[3];
    };
    struct Mat3x3 { unsigned int w[9]; };
    struct Vec3u { unsigned int w[3]; };
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
    *(float *)(p + 0x21C) = 0.0f;
    *(unsigned char *)(p + 0x223) = 1;
    *(unsigned int *)(p + 0x224) = 0;
    *(float *)(p + 0x228) = 0.0f;
    *(float *)(p + 0x22C) = 0.0f;
    *(float *)(p + 0x230) = 0.0f;
    *(unsigned char *)(p + 0x235) = 0;
    *(unsigned char *)(p + 0x234) = 0;
    *(float *)(p + 0x238) = 0.0f;
    fn_801AC240(self);
    *(struct Mat3x3 *)(p + 0x3C) = *(struct Mat3x3 *)(c + 0x18);
    *(struct Vec3u *)(p + 0x60) = *(struct Vec3u *)(c + 0x3C);
    ((void (*)(void *))fn_8017A580)(self);
    stack.v1b8[0] = 0.0f;
    stack.v1b8[1] = 0.0f;
    stack.v1b8[2] = 0.0f;
    *(float *)(p + 0x30) = 0.0f;
    *(float *)(p + 0x34) = 0.0f;
    *(float *)(p + 0x38) = 0.0f;
    ((void (*)(void *))fn_8017A57C)(self);

    scale = 9.81f * *(float *)(c + 8);
    scale = scale / lbl_80562488;
    f30 = 1.5f * scale;
    f29 = 0.4f * f30;
    f28 = *(float *)(c + 0x4C);
    cfgValue = *(unsigned int *)(c + 0x48);
    type = *(unsigned int *)(c + 0x50);
    stack.v1b8[0] = 0.0f;
    stack.v1b8[1] = 0.0f;
    stack.v1b8[2] = 0.0f;

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
            *(float *)(o + 0x34) = 0.0f;
            *(float *)(o + 0x38) = 0.0f;
            *(float *)(o + 0x3C) = 0.0f;
            *(float *)(o + 0x40) = 0.0f;
            *(float *)(o + 0x44) = 0.0f;
            *(float *)(o + 0x48) = 0.0f;
            *(unsigned char *)(o + 0x4C) = 0;
            *(float *)(o + 0x50) = 0.0f;
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
        f25 = x * 0.5f;
        f26 = y * 0.5f;
        f27 = z * 0.5f;
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
                *(float *)(o + 0x30) = (float)fn_8002F234(norm) + 0.2f;
                *(unsigned int *)(o + 0x34) = 0;
                *(void **)(o + 0x0) = lbl_803338C0;
            }
        } else {
            f25 = f26 + f25;
            f25 = f27 + f25;
            f25 = f25 / 3.0f;
            f25 = f25 * 0.5f;
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
                *(float *)(o + 0x34) = 0.0f;
                *(float *)(o + 0x38) = 0.0f;
                *(float *)(o + 0x3C) = 0.0f;
                *(float *)(o + 0x40) = 0.0f;
                *(float *)(o + 0x44) = 0.0f;
                *(float *)(o + 0x48) = 0.0f;
                *(unsigned char *)(o + 0x4C) = 0;
                *(float *)(o + 0x50) = 0.0f;
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
            float nx = -x * 0.5f;
            float ny = y * 0.5f;
            float nz = z * 0.5f;
            stack.v14c[0] = y * 0.5f;
            stack.v14c[1] = -x * 0.5f;
            stack.v14c[2] = z * 0.5f;
            stack.v1b8[0] = nx;
            stack.v1b8[1] = ny;
            stack.v1b8[2] = nz;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
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
            f25 = x * 0.5f;
            f26 = z;
            f27 = y;
            vx = x;
            vy = -z * 0.5f;
            vz = x;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            c0 = (float)cos(lbl_805624B8);
            s0 = (float)sin(lbl_805624B8);
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            q0 = vx * c0 + vz * s0;
            vy = vy * 1.0f;
            vz = -vx * s0 + vz * c0;
            vx = q0;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = vx; node->values[1] = vy; node->values[2] = vz;
            node->values[3] = f29; node->values[4] = 0.5f;
            node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
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
            *(float *)(o + 0x34) = 0.0f;
            *(float *)(o + 0x38) = 0.0f;
            *(float *)(o + 0x3C) = 0.0f;
            *(float *)(o + 0x40) = 0.0f;
            *(float *)(o + 0x44) = 0.0f;
            *(float *)(o + 0x48) = 0.0f;
            *(unsigned char *)(o + 0x4C) = 0;
            *(float *)(o + 0x50) = 0.0f;
            if (self != 0) fn_8019EECC(self, o + 0x28);
        }
        mode = 0;
        break;
    case 5:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        halfY = y * 0.5f;
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
            *(float *)(o + 0x28) = 0.0f;
            *(float *)(o + 0x2C) = 0.0f;
            *(float *)(o + 0x30) = 0.0f;
            *(float *)(o + 0x34) = 0.0f;
            *(float *)(o + 0x38) = 0.0f;
            *(float *)(o + 0x3C) = 0.0f;
            *(float *)(o + 0x40) = 0.0f;
            *(float *)(o + 0x44) = 0.0f;
            *(float *)(o + 0x48) = 0.0f;
            *(unsigned char *)(o + 0x4C) = 0;
            *(float *)(o + 0x50) = 0.0f;
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
            float nx = x * 0.5f;
            float ny = y * 0.5f;
            float nz = z * 0.5f;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            node = (struct PushNode *)fn_801AE180();
            node->values[0] = -nx; node->values[1] = -ny; node->values[2] = -nz; node->values[3] = f29;
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
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
                node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
                node->values[7] = 0.0f; node->values[8] = 0.0f;
                node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
                node = (struct PushNode *)fn_801AE180();
                node->values[0] = -x; node->values[1] = y; node->values[2] = z; node->values[3] = f29;
                node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
                node->values[7] = 0.0f; node->values[8] = 0.0f;
                node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
                node = (struct PushNode *)fn_801AE180();
                node->values[0] = x; node->values[1] = -y; node->values[2] = z; node->values[3] = f29;
                node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
                node->values[7] = 0.0f; node->values[8] = 0.0f;
                node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
            }
        }
        break;
    case 12:
        object = fn_801284F8(0x74, names + 0xE0);
        if (object != 0) {
            stack.v14c[0] = 0.0f;
            stack.v14c[1] = *(float *)(c + 0x5C) * 0.5f;
            stack.v14c[2] = 0.0f;
            x = *(float *)(c + 0x58);
            y = *(float *)(c + 0x5C);
            object = fn_801A2354(object, p + 0x3C, (void *)stack.v14c, self,
                                 50000.0f, 0.2f, x, stack.v14c[1], x);
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
            node->values[4] = 0.5f; node->values[5] = 0.0f; node->values[6] = 0.0f;
            node->values[7] = 0.0f; node->values[8] = 0.0f;
            node->next = *(void **)(p + 0xD0); *(void **)(p + 0xD0) = node;
        }
        break;
    case 16:
        x = *(float *)(c + 0x58);
        y = *(float *)(c + 0x5C);
        z = *(float *)(c + 0x60);
        f25 = x * 0.5f;
        f26 = y * 0.5f;
        f27 = z * 0.5f;
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
                        node->values[4] = 0.5f;
                        node->values[5] = 0.0f;
                        node->values[6] = 0.0f;
                        node->values[7] = 0.0f;
                        node->values[8] = 0.0f;
                        node->next = *(void **)(p + 0xD0);
                        *(void **)(p + 0xD0) = node;
                        point = (struct Record *)((unsigned char *)point + 0x50);
                        inner++;
                    }
                }
                outer++;
            }
            MRModel_ReleaseResource(collection);
            x = *(float *)(c + 0x58);
            y = *(float *)(c + 0x5C);
            {
                float difference = y - x;
                difference = (float)__fabs((double)difference);
                if (difference > 1.19209290e-07f) {
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
                        *(float *)(o + 0x28) = 0.0f;
                        *(float *)(o + 0x2C) = 0.0f;
                        *(float *)(o + 0x30) = 0.0f;
                        *(float *)(o + 0x34) = 0.0f;
                        *(float *)(o + 0x38) = 0.0f;
                        *(float *)(o + 0x3C) = 0.0f;
                        *(float *)(o + 0x40) = 0.0f;
                        *(float *)(o + 0x44) = 0.0f;
                        *(float *)(o + 0x48) = 0.0f;
                        *(unsigned char *)(o + 0x4C) = 0;
                        *(float *)(o + 0x50) = 0.0f;
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
                        *(float *)(o + 0x28) = 0.0f;
                        *(float *)(o + 0x2C) = 0.0f;
                        *(float *)(o + 0x30) = 0.0f;
                        *(float *)(o + 0x34) = 0.0f;
                        *(float *)(o + 0x38) = 0.0f;
                        *(float *)(o + 0x3C) = 0.0f;
                        *(float *)(o + 0x40) = 0.0f;
                        *(float *)(o + 0x44) = 0.0f;
                        *(float *)(o + 0x48) = 0.0f;
                        *(unsigned char *)(o + 0x4C) = 0;
                        *(float *)(o + 0x50) = 0.0f;
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
            *(float *)((unsigned char *)node + 0x14) = 2.0f;
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
    /* Clamp/correct a vector at +0x124 against a reference vector at +0x54 using a limit at +0x238. */
    extern float lbl_80562478, lbl_8056247C, lbl_805624A4, lbl_805624AC, lbl_805624D8;
    float dot, magnitude, sign, limit;
    double absolute;
    float x, y, z;
    float unused, scale;
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
    x = *(float *)(p + 0x124) + *(float *)(p + 0x54) * scale;
    y = *(float *)(p + 0x128) + *(float *)(p + 0x58) * scale;
    z = *(float *)(p + 0x12C) + *(float *)(p + 0x5C) * scale;
    *(float *)(p + 0x124) = x;
    *(float *)(p + 0x128) = y;
    *(float *)(p + 0x12C) = z;
}

extern void fn_8017B81C(void *);
extern void fn_8017C7C8(void *, float *, float *);
extern float lbl_805624AC, lbl_805624DC, lbl_805624E0, lbl_805624E4;
#pragma cplusplus on
#pragma scheduling on
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
    float scale, first;
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
            {
                float f, e, d, c, b, a;
                float check, r5, r4, r3, r2, r1, r0;
                float s;
                int needCall;
                a = *(volatile float *)(p + 0x118);
                s = *(volatile float *)&lbl_805624E4;
                b = *(volatile float *)(p + 0x11c);
                r0 = a * s;
                c = *(volatile float *)(p + 0x120);
                r1 = b * s;
                d = *(volatile float *)(p + 0x124);
                r2 = c * s;
                e = *(volatile float *)(p + 0x128);
                r3 = d * s;
                f = *(volatile float *)(p + 0x12c);
                r4 = e * s;
                r5 = f * s;
                check = *(volatile float *)(p + 0x238);
                needCall = check > lbl_8056247C;
                *(float *)(p + 0x118) = r0;
                *(float *)(p + 0x11c) = r1;
                *(float *)(p + 0x120) = r2;
                *(float *)(p + 0x124) = r3;
                *(float *)(p + 0x128) = r4;
                *(float *)(p + 0x12c) = r5;
                if (needCall)
                    fn_801ABB54(arg0);
            }
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
    /* Tail-call wrapper for fn_8017A57C. */
    fn_8017A57C();
}

/* Activates `self` (via fn_801AC240) and, when linked in a circular group ring
   (+0x224) with propagation enabled (+0x223 != 0 and frame > 1), clears +0x223
   and dispatches `event` (f0) to every peer in the ring. */
void fn_801ABFF8(void *self, int **event) {
    void *peer;
    peer = *(void **)((char *)self + 0x224);
    if (peer != 0 &&
        *(unsigned char *)((char *)self + 0x223) != 0 &&
        lbl_8055E3C4 > 1) {
        while (peer != self) {
            *(unsigned char *)((char *)peer + 0x223) = 0;
            ((struct Dummy_801ABFF8 *)event)->f0(peer);
            peer = *(void **)((char *)peer + 0x224);
        }
        *(unsigned char *)((char *)self + 0x223) = 0;
    }
    fn_801AC240(self);
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
void fn_801AC0A0(void *arg0, const float *arg1, const float *arg2, int arg3, int arg4) {
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
 fn_8017D2C8(arg0,(void *)arg1,(void *)arg2,arg3,0);
}
#pragma pop

extern void fn_8017A580(void *, int, int, int, int, int, int, int);
extern void fn_8017B164(void *);
void fn_801AC184(void *arg0) {
    int saved1EC, saved1F8, saved1F4, saved1F0, saved1EC_copy, saved1FC, saved200, saved204, saved208, saved20C, saved210, saved214;
    /* Reinitializes object state: calls setup helpers, copies 12 ints from +0x1EC..+0x218 to +0x3C..+0x68, forwards a subset to fn_8017A580, finalizes, and propagates flags (+0x223, +0x234<-+0x235). */
    fn_801AC240(arg0);
    saved1EC_copy = *(volatile int *)((char *)arg0 + 0x1EC);
    saved1F0 = *(volatile int *)((char *)arg0 + 0x1F0);
    saved1F4 = *(volatile int *)((char *)arg0 + 0x1F4);
    saved1F8 = *(volatile int *)((char *)arg0 + 0x1F8);
    saved1FC = *(volatile int *)((char *)arg0 + 0x1FC);
    saved200 = *(volatile int *)((char *)arg0 + 0x200);
    saved204 = *(volatile int *)((char *)arg0 + 0x204);
    saved208 = *(volatile int *)((char *)arg0 + 0x208);
    saved20C = *(volatile int *)((char *)arg0 + 0x20C);
    saved210 = *(volatile int *)((char *)arg0 + 0x210);
    saved214 = *(volatile int *)((char *)arg0 + 0x214);
    saved1EC = *(volatile int *)((char *)arg0 + 0x218);
    *(int *)((char *)arg0 + 0x3C) = saved1EC_copy;
    *(int *)((char *)arg0 + 0x40) = saved1F0;
    *(int *)((char *)arg0 + 0x44) = saved1F4;
    *(int *)((char *)arg0 + 0x48) = saved1F8;
    *(int *)((char *)arg0 + 0x4C) = saved1FC;
    *(int *)((char *)arg0 + 0x50) = saved200;
    *(int *)((char *)arg0 + 0x54) = saved204;
    *(int *)((char *)arg0 + 0x58) = saved208;
    *(int *)((char *)arg0 + 0x5C) = saved20C;
    *(int *)((char *)arg0 + 0x60) = saved210;
    *(int *)((char *)arg0 + 0x64) = saved214;
    *(int *)((char *)arg0 + 0x68) = saved1EC;
    fn_8017A580(arg0, saved214, saved210, saved20C, saved208, saved204, saved200, saved1FC);
    fn_8017B164(arg0);
    *(unsigned char *)((char *)arg0 + 0x223) = 1;
    *(unsigned char *)((char *)arg0 + 0x234) = *(unsigned char *)((char *)arg0 + 0x235);
}

#pragma dont_inline on
void fn_801AC240(void *obj) {
    /* Set the object's active flag and seed its +0x21C field from the global float. */
    *(unsigned char *)((char *)obj + 0x220) = 1;
    *(float *)((char *)obj + 0x21C) = lbl_8055E3C8;
}
#pragma dont_inline off

void fn_801AC254(void *obj) {
    /* Clear this object's active flag at +0x220, if it is set. */
    if (*(unsigned char *)((char *)obj + 0x220) != 0) {
        *(unsigned char *)((char *)obj + 0x220) = 0;
    }
}

/* Allocates and constructs a 0x244-byte DynamicObstacle instance with its primary and secondary vtables. */
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

void *fn_801AC2C8(void *object, int deleteFlag) {
    /* Deleting-destructor-like helper: clears global state, runs cleanup on the object if present, frees when deleteFlag > 0, and returns the object. */
    if (object != 0) {
        lbl_8055E5E4 = 0;
        if (object != 0 && object != 0) fn_80179EE8(object, 0);
        if (deleteFlag > 0) fn_80128668(object);
    }
    return object;
}

/* FencePost_construct - the "fencepst" fence post's constructor.  Builds the obstacle base it
 * shares with the other obstacles (fn_801A9700), installs this class's vtable, takes the next
 * free slot in the level's post table and clears the post's rope point index; the first post
 * of a level also drops the rope solver the fence is built from (fn_801AC508 makes it). */
void *fn_801AC330(void *object) {
    /* A fence post past the obstacle base every obstacle starts with. */
    struct FencePost {
        void *vtable;   /* 0x000 this class's vtable, lbl_80335808 */
        u8 pad[0x24C];
        s32 index;      /* 0x250 this post's slot in the level's post table */
        s32 pointIndex; /* 0x254 the post's first rope point, -1 until the rope is built */
    };
    struct FencePost *post = (struct FencePost *)object;
    /* The module's globals: the posts placed in the level, how many there are, and the rope
     * solver ("ppsys") the fence strung between them is simulated by. */
#define fencePostTable lbl_80435628
#define fencePostCount lbl_8055E5EC
#define fenceRope lbl_8055E5F0

    fn_801A9700(object);
    post->vtable = &lbl_80335808;
    if (*(volatile int *)&fencePostCount == 0) {
        fenceRope = 0;
    }
    {
        s32 count = *(volatile int *)&fencePostCount;
        post->index = count;
        *(volatile int *)&fencePostCount = count + 1;
    }
    fencePostTable[post->index] = object;
    post->pointIndex = -1;
#undef fencePostTable
#undef fencePostCount
#undef fenceRope
    return object;
}

extern void fn_801C1C7C(void);
/* Destructor-like cleanup: reset vtable, decrement shared instance count and
 * release shared resource when last, run base cleanup, and optionally free. */
void **fn_801AC3AC(void **obj, int shouldFree) {
    if (obj != 0) {
        *obj = lbl_80335808;
        lbl_8055E5EC = lbl_8055E5EC - 1;
        if (lbl_8055E5EC == 0) {
            int sharedResource = lbl_8055E5F0;
            if (sharedResource != 0) {
                ((void (*)(int))fn_801C1C7C)(sharedResource);
                lbl_8055E5F0 = 0;
            }
        }
        if (obj != 0) {
            lbl_8055E5E4 = 0;
            if (obj != 0 && obj != 0) fn_80179EE8(obj, 0);
        }
        if (shouldFree > 0) fn_80128668(obj);
    }
    return obj;
}

extern void fn_802E30C8(const char *, ...);
#pragma scheduling invalid_target
void fn_801AC454(void *self, void *config) {
    extern float lbl_805624EC;
    extern char lbl_80335728[];
    int poleCount;
    int hasPreviousPole;
    float defaultValue;
    float configuredRadius;
    void *candidatePole;

    /* Initialize fence pole state, copy base fields from config, and bind to the previous pole if it is within range. */
    *(void **)((char *)self + 0x23C) = 0;
    *(void **)((char *)self + 0x240) = 0;
    fn_801A9AB0(self, config);
    poleCount = *(int *)((char *)self + 0x250);
    configuredRadius = *(float *)((char *)config + 0x5C);
    defaultValue = lbl_8056247C;
    hasPreviousPole = poleCount > 0;
    *(float *)((char *)self + 0x248) = configuredRadius;
    *(float *)((char *)self + 0x244) = defaultValue;
    *(float *)((char *)self + 0x24C) = defaultValue;
    *(void **)((char *)self + 0x23C) = 0;
    if (hasPreviousPole) {
        candidatePole = lbl_80435628[poleCount - 1];
        if (PSVECSquareDistance((const Vec *)((char *)candidatePole + 0x60),
                                (const Vec *)((char *)self + 0x60)) < lbl_805624EC) {
            *(void **)((char *)self + 0x23C) = candidatePole;
            fn_802E30C8(lbl_80335728, candidatePole);
        }
    }
}
extern int fn_801C1BA4(int, int, int);
#define fencePostCount lbl_8055E5EC  // number of fence posts placed in the level
#define fenceRope      lbl_8055E5F0  // shared rope ("ppsys") solver strung across them
#pragma dont_inline on
// Build the shared rope solver once fence posts exist: 5 rope points per post,
// 4 fewer links, kept for every fence post in the level to share.
void fn_801AC508(void) {
    s32 postCount = fencePostCount;
    if (postCount > 0) {
        fenceRope = fn_801C1BA4(postCount * 5, postCount * 5 - 1, postCount);
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern float PSQUATMultiply(void *, void *);
extern void fn_801A2674(void *, int, int, float);
extern void fn_801C1CBC(int, int, void *, int, void *, int, void *);
extern float lbl_805624AC, lbl_805624F0, lbl_805624F4, lbl_805624F8;
#pragma push
#pragma opt_lifetimes off
void fn_801AC544(void *arg0)
{
int __repair_literal;

  struct Point
  {
    float x;
    float y;
    float z;
    float a;
    float b;
  };
  struct Link
  {
    int a;
    int b;
    float distance;
    float value;
  };
  struct Anchor
  {
    int index;
    void *matrix;
    int unused;
  };
  struct Point points[320];
  struct Link links[320];
  struct Anchor anchors[64];
  Vec a;
  Vec b;
  int npoints;
  int nlinks;
  int nanchors;
  int i;
  int j;
  fn_801AC184(arg0);
  if (((*((int *) (((char *) arg0) + 0x250))) == (lbl_8055E5EC - 1)) && (lbl_8055E5F0 != 0))
  {
    float divisor = lbl_805624F4;
    float one = lbl_805624AC;
    float base = lbl_80562478;
    float factor = lbl_805624F0;
    float val = lbl_805624F8;
    float zero = lbl_8056247C;
    npoints = (nlinks = (nanchors = 0));
    {
      void **iter = lbl_80435628;
      for (i = 0; i < lbl_8055E5EC; i++, iter++)
      {
        char *obj = *iter;
        float *m = (float *) (obj + 0x1ec);
        float *v = (float *) (obj + 0x244);
        char *parent;
        if ((&a) == ((Vec *) v))
        {
          float x = v[0];
          float y = v[1];
          float z = v[2];
          float r2 = z * m[8];
          float p0 = x * m[0];
          float p1 = y * m[3];
          float p2 = z * m[6];
          float xx = p2 + (p0 + p1);
          float q0 = x * m[1];
          float q1 = y * ((0, m[4]));
          float q2 = z * m[7];
          float yy = q2 + (q0 + q1);
          float r0 = x * m[2];
          float r1 = y * m[5];
          float zz = r2 + (r0 + r1);
          a.z = zz;
          a.y = yy;
          a.x = xx;
        }
        else
        {
          a.x = (v[2] * m[6]) + ((v[0] * m[0]) + (v[1] * m[3]));
          a.y = (v[2] * m[7]) + ((v[0] * m[1]) + (v[1] * m[4]));
          a.z = (v[2] * m[8]) + ((v[0] * m[2]) + (v[1] * m[5]));
        }
        a.x += m[9];
        a.y += m[10];
        a.z += m[11];
        parent = *((char **) (obj + 0x23c));
        if (parent)
        {
          float d = base + (factor * PSQUATMultiply(obj + 0x210, parent + 0x210));
          if (*((void **) (obj + 0x240)))
          {
            fn_801A2674(*((void **) (obj + 0x240)), npoints, npoints + 5, d);
          }
          parent = *((char **) (obj + 0x23c));
          m = (float *) (parent + 0x1ec);
          v = (float *) (parent + 0x244);
          if ((&b) == ((Vec *) v))
          {
            float x = v[0];
            float y = v[1];
            float z = v[2];
            float p0 = x * m[0];
            float p1 = y * m[3];
            float p2 = z * m[6];
            float xx = p2 + (p0 + p1);
            float q0 = x * m[1];
            float q1 = y * m[4];
            float q2 = z * m[7];
            float yy = q2 + (q0 + q1);
            float r0 = x * m[2];
            float r1 = y * m[5];
            float r2 = z * m[8];
            float zz = r2 + (r1 + r0);
            b.x = xx;
            b.y = yy;
            b.z = zz;
          }
          else
          {
            b.x = (v[2] * m[6]) + ((v[0] * m[0]) + (v[1] * m[3]));
            b.y = (v[2] * m[7]) + ((v[0] * m[1]) + (v[1] * m[4]));
            b.z = (v[2] * m[8]) + ((v[0] * m[2]) + (v[1] * ((0, m[5]))));
          }
          b.x += m[9];
          b.y += m[10];
          b.z += m[11];
          for (j = 0; j < 5; j++)
          {
__repair_literal = 0;

            if (j > __repair_literal)
            {
              float t = ((float) j) / divisor;
              float s = one - t;
              points[npoints].x = (((0, b.x)) * s) + (a.x * t);
              points[npoints].y = (b.y * s) + (a.y * t);
              points[npoints].z = (b.z * s) + (a.z * t);
              points[npoints].a = one;
              points[npoints].b = one;
              npoints++;
            }
            links[nlinks].a = npoints;
            links[nlinks].b = npoints - 1;
            links[nlinks].distance = zero;
            links[nlinks].value = val;
            nlinks++;
          }
        }
        anchors[nanchors].index = npoints;
        anchors[nanchors].matrix = obj + 0x3c;
        anchors[nanchors].unused = 0;
        nanchors++;
        *((int *) (obj + 0x254)) = npoints;
        points[npoints].x = a.x;
        points[npoints].y = a.y;
        points[npoints].z = a.z;
        points[npoints].a = one;
        points[npoints].b = one;
        npoints++;
      }
    }
    for (i = 0; i < nlinks; i++)
    {
      PSQUATMultiply(&points[links[i].a], &points[links[i].b]);
      links[i].distance = zero;
    }
    fn_801C1CBC(lbl_8055E5F0, npoints, points, nlinks, links, nanchors, anchors);
  }
}
#pragma pop

#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
void fn_801ACA48(void *self) {
    /* Run the base object update, then when the active flag at +0x220 is set:
       scale the vector at +0x124 by lbl_805624CC and clear +0x118, add a cross
       product of +0x48 and +0x1F8 (scaled by lbl_8056250C) into +0x124 when
       +0x4C is below lbl_80562508, and copy the position at +0x210 to +0x60. */
    extern void fn_801ABC28(void *);
    extern float lbl_8056247C, lbl_805624CC, lbl_80562508, lbl_8056250C;
    float scaledX, scaledY, scaledZ;
    float scale, zero, velX;
    float posZ, posY, posX;
    char *p = self;
    fn_801ABC28(self);
    if (*(unsigned char *)(p + 0x220)) {
        Vec cross;
        velX = *(float *)(p + 0x124);
        scale = lbl_805624CC;
        scaledX = velX * scale;
        scaledY = *(float *)(p + 0x128) * scale;
        scaledZ = *(float *)(p + 0x12C) * scale;
        zero = lbl_8056247C;
        *(float *)(p + 0x118) = zero;
        *(float *)(p + 0x11C) = zero;
        *(float *)(p + 0x120) = zero;
        *(float *)(p + 0x124) = scaledX;
        *(float *)(p + 0x128) = scaledY;
        *(float *)(p + 0x12C) = scaledZ;
        PSVECCrossProduct((Vec *)(p + 0x48), (Vec *)(p + 0x1F8), &cross);
        if (*(float *)(p + 0x4C) < lbl_80562508) {
            float crossX = cross.x;
            float nudge = lbl_8056250C;
            *(float *)(p + 0x124) = *(float *)(p + 0x124) + crossX * nudge;
            *(float *)(p + 0x128) = *(float *)(p + 0x128) + cross.y * nudge;
            *(float *)(p + 0x12C) = *(float *)(p + 0x12C) + cross.z * nudge;
        }
        posX = *(float *)(p + 0x210);
        posY = *(float *)(p + 0x214);
        posZ = *(float *)(p + 0x218);
        *(float *)(p + 0x60) = posX;
        *(float *)(p + 0x64) = posY;
        *(float *)(p + 0x68) = posZ;
    }
}
#pragma pop
extern float lbl_80558DC4, lbl_8055E460, lbl_805624AC;
struct Pair_801ACB30 { int a, b; };
static inline void transform_801ACB30(const float *m, const float *src, float *dst) {
    if (dst == src) {
        float x = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        float y = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        float z = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
    dst[0] += m[9]; dst[1] += m[10]; dst[2] += m[11];
}
__declspec(section ".data") extern float lbl_80558DC4;
void fn_801ACB30(void *arg0, int arg1) {
    char *p = (char *)arg0;
    float *out = (float *)(arg1 + *(int *)(p + 8));
    register float t = lbl_8055E460 - lbl_805624AC;
    float tmp[12], st[3], st2[3];
    struct Pair_801ACB30 *sp, *dp;
    int j, k;
    if ((float)__fabs(t) <= lbl_80558DC4) {
        sp = (struct Pair_801ACB30 *)(p + 0x70);
        dp = (struct Pair_801ACB30 *)out;
        for (j = 0; j < 6; j++) dp[j] = sp[j];
    } else {
        float *a = (float *)(p + 0x70);
        float *b = (float *)(p + 0xA0);
        float *o = tmp;
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 6; k++) o[k] = b[k] + t * (a[k] - b[k]);
            a += 6; b += 6; o += 6;
        }
        sp = (struct Pair_801ACB30 *)tmp;
        dp = (struct Pair_801ACB30 *)out;
        for (j = 0; j < 6; j++) dp[j] = sp[j];
    }
    *(short *)(out + 12) = *(short *)(p + 0x6C);
    if (*(void **)(p + 0x23C)) {
        float *q = (float *)(*(char **)(p + 0x23C));
        transform_801ACB30((float *)(p + 0x3C), (float *)(p + 0x244), st);
        transform_801ACB30((float *)((char *)q + 0x3C), (float *)((char *)q + 0x244), st2);
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
    void **obj;
    int i, j, zero, first, last, count, off;
    void *root;
    void *a;
    void *o;
    float *base, *dst, *src;
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
        obj = (void **)lbl_80435628;
        j = 0;
        zero = 0;
        while (j < lbl_8055E5EC) {
            o = *obj;
            a = *(void **)((char *)o + 0x23C);
            if (a != 0) {
                first = *(int *)((char *)a + 0x254);
                base = (float *)(sp90);
                last = *(int *)((char *)o + 0x254);
                dst = (float *)sp3c;
                off = first * 12;
                *(int *)dst = zero;
                count = last - first + 1;
                *(int *)((char *)dst + 4) = j;
                *(int *)(sp3c + 8) = count;
                src = (float *)((char *)base + off);
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
/* A spring between a point of a rigid body (+0x34) and a target point: a fixed
   world point (+0x00) when there is no second body (+0x0C == 0), or that body's
   world position of +0x00.  fn_801AD0E0/fn_801AD148/fn_801AD28C set one up and
   applySpringForce measures it and feeds the force it produces into the bodies. */
typedef struct Spring {
    Vec target;                 /* +0x00: point to pull the anchor towards */
    void *other;                /* +0x0C: the body +0x00 is a point of, 0 for a fixed point */
    Vec anchor;                 /* +0x10: point on `body`, in its own frame */
    float strength;             /* +0x1C: force per unit of stretch */
    float damping;              /* +0x20: force per unit of closing speed */
    float range;                /* +0x24: how far past the rest length the spring still acts */
    float restLength;           /* +0x28 */
    float stretch;              /* +0x2C: out: how far past the rest length it is */
    float flatDistance;         /* +0x30: out: the target-anchor distance ignoring height */
    void *body;                 /* +0x34 */
} Spring;

#pragma scheduling 750

extern float lbl_8056250C;
extern float lbl_80562514;
extern float lbl_8056247C;
#pragma scheduling off
#pragma opt_propagation off
/* Initialize a spring: store the world target and the local anchor, the second
   body (or zero for a fixed point), strength and range; derive damping as a
   fixed fraction of strength; zero the rest length and stretch. */
void fn_801AD0E0(void *spring, void *target, void *other, void *anchor, float strength, float range) {
    float damping, scaledStrength, anchorZ, anchorY, anchorX, targetZ, targetY, targetX, zeroFloat;
    int zeroInt;
    damping = lbl_80562514;
    zeroInt = 0;
    zeroFloat = lbl_8056247C;
    scaledStrength = damping * strength;
    damping = lbl_8056250C;
    *(int *)&((Spring *)spring)->other = zeroInt;
    targetX = ((Vec *)target)->x;
    damping = damping * scaledStrength;
    targetY = ((Vec *)target)->y;
    targetZ = ((Vec *)target)->z;
    anchorX = ((Vec *)anchor)->x;
    anchorY = ((Vec *)anchor)->y;
    anchorZ = ((Vec *)anchor)->z;
    ((Spring *)spring)->restLength = zeroFloat;
    ((Spring *)spring)->stretch = zeroFloat;
    ((Spring *)spring)->target.x = targetX;
    ((Spring *)spring)->target.y = targetY;
    ((Spring *)spring)->target.z = targetZ;
    *(int *)&((Spring *)spring)->other = (int)other;
    ((Spring *)spring)->anchor.x = anchorX;
    ((Spring *)spring)->anchor.y = anchorY;
    ((Spring *)spring)->anchor.z = anchorZ;
    ((Spring *)spring)->strength = strength;
    ((Spring *)spring)->range = range;
    ((Spring *)spring)->damping = damping;
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
extern void fn_801AD0E0(void *, void *, void *, void *, f32, f32);
#pragma scheduling on
void fn_801AD28C(void *arg0, void *arg1, void *arg2, Vec *arg3, f32 farg1, f32 farg0) {
    Vec sp20;
    Vec sp14;
    Vec delta;
    f32 z, y, x;
    f32 distance;
    f32 *out = (f32 *)((char *)arg0 + 0x28);
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
    *out = distance;
    fn_801AD0E0(arg0, arg3, arg2, arg1, farg1, farg0);
    *out = distance;
}

/* Measure a spring and apply it.  Both ends are brought into the world: the
   anchor (+0x10) through the body at +0x34, the target (+0x00) through the
   second body at +0x0C when there is one.  Their separation is written back as
   the stretch past the rest length (+0x2C) and as the distance ignoring height
   (+0x30); while that stretch lies between the epsilon and the spring's range,
   the relative speed of the two ends and the spring's own pull are added into a
   force and pushed into the body at the anchor - and, for a spring between two
   bodies, into the other body the other way round. */
#pragma scheduling invalid_target
void applySpringForce(Spring *spring) {
    extern double fn_8002F234(float);              /* sqrt */
    extern float lbl_8056247C;                     /* 0.0f */
    extern float lbl_805624A4;                     /* -1.0f */
    extern float lbl_805624AC;                     /* 1.0f */
    extern float lbl_80562518;                     /* 0.001f */
    extern void fn_8017B6D4(void *, Vec *, Vec *); /* velocity of a body at a world point */
    extern void fn_8017B3A8(void *, Vec *, Vec *); /* add a force at a world point */
    Vec anchorPos;
    Vec targetPos;
    Vec delta;
    Vec direction;
    Vec force;
    Vec anchorVel;
    Vec targetVel;
    Vec closingVel;
    float length;
    float minLength;
    float flatDistance;
    float factor;
    float dz2;
    float dx2;
    float restLength;
    float stretch;

    /* Where the two ends of the spring are in the world: the anchor goes
       through the body's frame, the target through the second body's when the
       spring hangs off another body rather than off a fixed point. */
    fn_8017AB84(spring->body, &anchorPos, &spring->anchor);
    if (spring->other != 0) {
        fn_8017AB84(spring->other, &targetPos, &spring->target);
    } else {
        targetPos.x = spring->target.x;
        targetPos.y = spring->target.y;
        targetPos.z = spring->target.z;
    }

    delta.x = targetPos.x - anchorPos.x;
    delta.y = targetPos.y - anchorPos.y;
    delta.z = targetPos.z - anchorPos.z;
    length = PSVECMag(&delta);
    dz2 = delta.z * delta.z;
    dx2 = delta.x * delta.x;
    flatDistance = (float) fn_8002F234(dx2 + dz2);
    restLength = spring->restLength;
    minLength = lbl_80562518;
    stretch = length - restLength;
    spring->flatDistance = flatDistance;
    spring->stretch = stretch;

    if (length > minLength && length < restLength + spring->range) {
        float invLength;
        float zero;
        float damping;
        invLength = lbl_805624AC / length;
        zero = lbl_8056247C;
        force.x = zero;
        force.y = zero;
        force.z = zero;
        direction.x = delta.x * invLength;
        direction.y = delta.y * invLength;
        direction.z = delta.z * invLength;
        fn_8017B6D4(spring->body, &anchorVel, &anchorPos);

        if (spring->other != 0) {
            fn_8017B6D4(spring->other, &targetVel, &targetPos);
        } else {
            targetVel.x = lbl_8056247C;
            targetVel.y = lbl_8056247C;
            targetVel.z = lbl_8056247C;
        }

        /* Damping works against the speed the two ends approach each other at,
           the spring itself against the stretch past the rest length. */
        closingVel.x = targetVel.x - anchorVel.x;
        closingVel.y = targetVel.y - anchorVel.y;
        closingVel.z = targetVel.z - anchorVel.z;
        damping = spring->damping;
        force.x = closingVel.x * damping;
        force.y = closingVel.y * damping;
        force.z = closingVel.z * damping;

        if (length > spring->restLength) {
            factor = spring->strength * (length - spring->restLength);
            force.x += direction.x * factor;
            force.y += direction.y * factor;
            force.z += direction.z * factor;
        }

        fn_8017B3A8(spring->body, &force, &anchorPos);
        if (spring->other != 0) {
            /* the second body gets the same force the other way round */
            force.x *= lbl_805624A4;
            force.y *= lbl_805624A4;
            force.z *= lbl_805624A4;
            fn_8017B3A8(spring->other, &force, &anchorPos);
        }
    }
}
#pragma scheduling on
/* Thin forwarding thunk: game init calls this to build the fence rope via fn_801AC508. */
void fn_801AD5EC(void) {
    fn_801AC508();
}

/* Per-frame forwarding thunk: the effect-list update calls this, which (via fn_801ACF94)
   transforms a mesh from the root object and emits each object's vertex slice as an EFX event. */
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
    register char *self = (char *)arg0;
    register float scale = 5.0f;
    register float factor = 0.8f;
    float sp14[3];
    float sp8[3];
    register float temp_f2;
    register float temp_f1;
    register float temp_f0;

    sp14[0] = *(float *)(self + 4) * scale;
    sp14[1] = *(float *)(self + 8) * scale;
    sp14[2] = *(float *)(self + 0xC) * scale;
    temp_f2 = *(float *)(self + 0x18) + (factor * (*(float *)((char *)arg1 + 0x68) - *(float *)(self + 0x18)));
    temp_f1 = *(float *)(self + 0x14) + (factor * (*(float *)((char *)arg1 + 0x64) - *(float *)(self + 0x14)));
    temp_f0 = *(float *)(self + 0x10) + (factor * (*(float *)((char *)arg1 + 0x60) - *(float *)(self + 0x10)));
    sp8[2] = temp_f2;
    sp8[0] = temp_f0;
    sp8[1] = temp_f1;
    ((Obj *)arg1)->v16(sp14, sp8,
                       *(int *)(self + 0x1C),
                       *(int *)(self + 0x20),
                       temp_f1, temp_f2, factor,
                       *(float *)(self + 0x10),
                       *(float *)(self + 0x14),
                       *(float *)(self + 0x18));
}
#pragma scheduling on
#pragma pop

extern void fn_801D0A24(void *, void *);
extern void fn_801AC0A0();
extern void fn_801D09A8(void *, int);
extern void fn_801A9AB0(void *, void *);
extern void fn_801D08C0(void *);
extern void fn_801D0934(void *);
#pragma push
#pragma opt_propagation off
void *fn_801AD6B0(void *self, int shouldDelete) {
    void *notifier;
    /* Destructor: sets the main and +0x23C embedded vtables, notifies listeners
     * for the embedded notifier, clears +0x240 and lbl_8055E5E4, destroys the
     * base, and frees when shouldDelete > 0. */
    if (self != 0) {
        *(void **)self = &lbl_80335744;
        notifier = self;
        *(void **)((u8 *)self + 0x23C) = (char *)&lbl_80335744 + 0x54;
        if (notifier != 0) {
            notifier = (u8 *)notifier + 0x23C;
        }
        fn_801D0934(notifier);
        *(int *)((u8 *)self + 0x240) = 0;
        if (self != 0) {
            lbl_8055E5E4 = 0;
            if (self != 0) {
                if (self != 0) {
                    fn_80179EE8(self, 0);
                }
            }
        }
        if (shouldDelete > 0) {
            ((void (*)(void *))fn_80128668)(self);
        }
    }
    return self;
}
#pragma push
#pragma opt_propagation off
void fn_801AD750(void *arg0, void *arg1) {
    void *notifier;
    fn_801A9AB0(arg0, arg1);
    *(int *)((char *)arg0 + 0x240) = *(int *)((char *)arg1 + 0x80);
    if (arg0 != 0) {
        notifier = arg0;
        if (notifier != 0) {
            notifier = (unsigned char *)notifier + 0x23C;
        }
        fn_801D08C0(notifier);
        return;
    }
}
#pragma pop
extern void fn_801D0A24(void *arg0, void *arg1);
void fn_801AD7A4(void *object, void *unused, void *eventData, int slotIndex) {
    /* Forward an event notification to listeners for slot indices below 8, using the object's subobject at +0x23C when present. */
    if (slotIndex >= 8) return;
    if (object != 0) object = (char *)object + 0x23C;
    fn_801D0A24(object, eventData);
}
/* Forward the event to fn_801AC0A0; if the target is a vehicle object (fourcc CAR/PCAR/ACAR/NCAR),
 * notify the embedded listener at +0x23C with the vehicle's record index at +0x1EC. */
void fn_801AD7C4(void *arg0, float *arg1, float *arg2, int arg3, void *arg4) {
    void *object = arg4;
    fn_801AC0A0(arg0, arg1, arg2, arg3, (int)object);
    if (object != 0) {
        s32 isCar;
        s32 fourcc = *(s32 *)((char *)object + 0x10);
        isCar = 0;
        if ((u32)(fourcc + 0xBCBF0000) == 0x5220U ||
            (u32)(fourcc + 0xAFBD0000) == 0x4152U ||
            (u32)(fourcc + 0xBEBD0000) == 0x4152U ||
            (u32)(fourcc + 0xB1BD0000) == 0x4152U) {
            isCar = 1;
        }
        if (isCar != 0) {
            s32 recordIndex = *(s32 *)((char *)object + 0x1EC);
            if (arg0 != 0) arg0 = (char *)arg0 + 0x23C;
            fn_801D09A8(arg0, recordIndex);
        }
    }
}

#pragma peephole on
/* Return this object's active-flag byte at offset 0x220. */
unsigned char fn_801AD860(void *object) {
    return ((unsigned char *)object)[0x220];
}

/* Default callback stub: reports a zero result (nothing to return). */
long fn_801AD868(void) {
    return 0;
}

/* No-op/default handler: simply clears the two output values. */
void fn_801AD870(void *unused0, void *unused1, void *unused2, long *out0, long *out1) {
    *out1 = 0;
    *out0 = 0;
}

/* Virtual method at vtable slot +0x34 (lbl_80335744): default stub that reports a zero result (nothing to return). */
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
extern "C" void fn_801AD888(void *object) {
    /* Invoke the callback object's d2() virtual method, then clear its flag at +0x220. */
    ((Dummy_801AD888 *)object)->d2();
    ((void (*)(void *))fn_801AC254)(object);
}
#pragma cplusplus off

void fn_801AD8C8(void *arg0, unsigned int *arg1, float *arg2, float *arg3) {
    /* Copy a 12-word matrix and two 3-float vectors into the object, then update its state. */
    volatile unsigned int *src = (volatile unsigned int *)arg1;
    float *vecA = arg2;
    float *vecB = arg3;
    unsigned int t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    float f0, f1, f2, f3, f4, f5;
    t0 = src[0];
    t1 = src[1];
    t2 = src[2];
    t3 = src[3];
    t4 = src[4];
    t5 = src[5];
    t6 = src[6];
    t7 = src[7];
    t8 = src[8];
    t9 = src[9];
    t10 = src[10];
    t11 = src[11];
    *(unsigned int *)((char *)arg0 + 0x3C) = t0;
    *(unsigned int *)((char *)arg0 + 0x40) = t1;
    *(unsigned int *)((char *)arg0 + 0x44) = t2;
    *(unsigned int *)((char *)arg0 + 0x48) = t3;
    *(unsigned int *)((char *)arg0 + 0x4C) = t4;
    *(unsigned int *)((char *)arg0 + 0x50) = t5;
    *(unsigned int *)((char *)arg0 + 0x54) = t6;
    *(unsigned int *)((char *)arg0 + 0x58) = t7;
    *(unsigned int *)((char *)arg0 + 0x5C) = t8;
    *(unsigned int *)((char *)arg0 + 0x60) = t9;
    *(unsigned int *)((char *)arg0 + 0x64) = t10;
    *(unsigned int *)((char *)arg0 + 0x68) = t11;
    ((void (*)(void *))fn_8017A580)(arg0);
    f5 = vecA[0];
    f4 = vecA[1];
    f3 = vecA[2];
    f2 = vecB[0];
    f1 = vecB[1];
    f0 = vecB[2];
    *(float *)((char *)arg0 + 0x118) = f5;
    *(float *)((char *)arg0 + 0x11C) = f4;
    *(float *)((char *)arg0 + 0x120) = f3;
    *(float *)((char *)arg0 + 0x124) = f2;
    *(float *)((char *)arg0 + 0x128) = f1;
    *(float *)((char *)arg0 + 0x12C) = f0;
    fn_801AC240(arg0);
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_801AD99C(void *self, float *velocity, float *positionOffset) {
    /* Scales velocity by this object's +0xD4 factor, offsets positionOffset by
     * this object's position at +0x60, and dispatches virtual slot 0x48. */
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
    float scaledVelocity[3];
    float targetPosition[3];
    scale = *(float *)((char *)self + 0xD4) / 0.016683381f;
    scaledVelocity[0] = velocity[0] * scale;
    scaledVelocity[1] = velocity[1] * scale;
    scaledVelocity[2] = velocity[2] * scale;
    targetPosition[0] = *(float *)((char *)self + 0x60) + positionOffset[0];
    targetPosition[1] = *(float *)((char *)self + 0x64) + positionOffset[1];
    targetPosition[2] = *(float *)((char *)self + 0x68) + positionOffset[2];
    ((Obj *)self)->v16(scaledVelocity, targetPosition, 100, 0);
}
#pragma pop
void fn_801ADA38(void *object, int enable) {
    /* If enabled, dispatch the default event table (lbl_80335940) to this object/its peers via fn_801ABFF8; otherwise clear the active flag at +0x220. */
    int *event;
    if (enable) {
        event = (int *)lbl_80335940;
        ((void (*)(void *, int **))fn_801ABFF8)(object, &event);
    } else {
        *((char *)object + 0x220) = 0;
    }
}

/* Return this object's active-flag byte at offset 0x220. */
unsigned char fn_801ADA7C(void *object) {
    return ((unsigned char *)object)[0x220];
}

/* Return the signed 16-bit field at offset 0x6C of this object. */
short fn_801ADA84(void *object) {
    return *(short *)((char *)object + 0x6C);
}

/* Return the address of the embedded field at offset 0x118 of base. */
long fn_801ADA8C(long base) { return base + 0x118; }

/* Return the address of the embedded field at offset 0x60 of base. */
long fn_801ADA94(long base) { return base + 0x60; }

extern float lbl_8055E3C8;
typedef void (*Fn801ADA9C)(void *, void *, void *);
extern unsigned char lbl_8055A8A0;
extern unsigned char lbl_8055A8B0;
#pragma cplusplus on
extern "C" void fn_801ADA9C(void *owner) {
    /* Invoke the two-string virtual method v4 (vtable slot 0x18) on the interface object held at +0x240, passing "dyno" and "unknown". */
    Dummy_801ADA9C *iface = *(Dummy_801ADA9C **)((char *)owner + 0x240);
    iface->v4(&lbl_8055A8A0, &lbl_8055A8B0);
}
#pragma cplusplus off
/* Return this object's interface pointer (Dummy_801ADA9C *) at offset 0x240, as an integer. */
long fn_801ADAB8(void *owner) {
    return *(long *)((char *)owner + 0x240);
}

/* Activates the object whose handle is passed in arg1 via fn_801AC240; arg0 is the unused interface owner. */
void fn_801ADAC0(void *owner, long obj) {
    fn_801AC240((void *)obj);
}
