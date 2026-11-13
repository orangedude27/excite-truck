#include "revolution/MTX/mtxtypes.h"
#include "math.h"
extern char lbl_80558DC4[];
extern float lbl_805649F4, lbl_80564A00, lbl_80564A34, lbl_80564A68, lbl_80564A8C, lbl_80564A98, lbl_80564A9C, lbl_80564AA8;
extern const double lbl_80564A40;
extern double lbl_80564AA0;
extern unsigned char lbl_8055F92C;
extern unsigned char fn_80129D90(int, int, int);
extern float fn_80287BC8(float, float);
extern double fn_8002EFB4(float, double);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct UnkAA9D4 { unsigned char pad[0xDC]; unsigned char active; unsigned char padDD[3]; float amount; unsigned char padE4[0x14]; float width, depth, height; } UnkAA9D4;
typedef union UnkAAF04Conversion { unsigned int words[2]; double value; } UnkAAF04Conversion;
typedef struct InitStruct {
    int field_00;
    int field_04;
    float field_08;
    float field_0C;
    Vec vA;
    Vec vB;
    Vec vC;
    float field_34;
    float pad38[3];
    int field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    float field_68;
    float field_6C;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;
    float pad80[3];
} InitStruct;

extern const char lbl_80349DC8[];
extern const char lbl_80349DFC[], lbl_80349E24[], lbl_80349E18[], lbl_80349E08[];
extern float lbl_8055CC80;
extern int lbl_8055CC60, lbl_8055CC64;
extern float lbl_805649F0, lbl_805649F4, lbl_805649FC, lbl_80564A00, lbl_80564A04, lbl_80564A58, lbl_80564A68, lbl_80564A6C, lbl_80564A70, lbl_80564A74, lbl_80564A78, lbl_80564A7C, lbl_80564A80, lbl_80564A84, lbl_80564A88, lbl_80564A8C, lbl_80564A90, lbl_80564A94;
extern void *fn_8012850C(int, const char *);
extern void *fn_801284F8(int, const char *);
extern void fn_8028E61C(void *);
extern void *fn_8002F37C(void *, void (*)(void), void *, int, int);
extern int fn_802CAC28(const char *, int);
extern void fn_802AB500(void);
extern void fn_802AB5B8(void);
extern void fn_801EEFDC(void *, int);
extern void *fn_801E87A8(void);
extern int fn_8028E2F8(void *, const void *, const void *, ...);

void fn_8028E240(int);
int fn_802C2C00(int);
int fn_802C990C(int);
void fn_802C2BB8(int *, int *, int *);
void fn_802C2B78(float, float, float);
extern int lbl_804BD7B0[4];
extern unsigned char lbl_8055F92D;
extern float lbl_805649FC;
extern float lbl_80564AAC;
void fn_8028E398(int);
void fn_80128668(void *);
extern void *lbl_8055F924;
extern int lbl_8055F928;
void fn_8028E080(void);
__declspec(section ".sdata") extern float lbl_805649F0;
s32 fn_802A9F30(void *arg0) {
    extern double lbl_805649E8;
    UnkAAF04Conversion conversion;
    s32 offset = *(s32 *)arg0 * 0x108;
    conversion.words[1] = *(u8 *)((u8 *)arg0 + 8);
    *(u8 *)((u8 *)(lbl_8055F928 + offset) + 0xC4) = 1;
    conversion.words[0] = 0x43300000;
    *(f32 *)((u8 *)(lbl_8055F928 + offset) + 0xD4) = *(f32 *)((u8 *)arg0 + 4);
    *(f32 *)((u8 *)(lbl_8055F928 + offset) + 0xD8) = (f32)(conversion.value - lbl_805649E8);
    return 0xC;
}

s32 fn_802A9F90(s32 *arg0) {
    extern int lbl_8055F928;
    *(u8 *)((u8 *)(lbl_8055F928 + (*arg0 * 0x108)) + 0xDC) = 1;
    return 4;
}

#pragma scheduling invalid_target
s32 fn_802A9FB0(void *arg0) {
    int index = *(int *)arg0;
    extern int lbl_8055F928;
    int offset = index * 0x108;
    unsigned char value = *((unsigned char *)arg0 + 4);
    *(u8 *)((u8 *)(lbl_8055F928 + offset) + 0xEC) = 1;
    *(u8 *)((u8 *)(lbl_8055F928 + offset) + 0xF4) = value;
    return 8;
}
#pragma scheduling on
/* Clears the per-entry state block (0x00..0xD8) to the default float zero value. */
void fn_802A9FE0(void *entry) {
    float zero = lbl_805649F0;
    int offset;
    for (offset = 0; offset <= 0xC0; offset += 4) *(float *)((char *)entry + offset) = zero;
    *(unsigned char *)((char *)entry + 0xC4) = 0;
    *(float *)((char *)entry + 0xCC) = zero;
    *(float *)((char *)entry + 0xC8) = zero;
    *(float *)((char *)entry + 0xD0) = zero;
    *(float *)((char *)entry + 0xD4) = zero;
    *(float *)((char *)entry + 0xD8) = zero;
}

#pragma scheduling invalid_target
void fn_802AA0C8(void *arg0) {
    extern float lbl_805649F0;
    extern float lbl_805649F4;
    float second;
    float first;
    first = lbl_805649F0;
    second = lbl_805649F4;
    *(unsigned char *)((char *)arg0 + 0xDC) = 0;
    *(float *)((char *)arg0 + 0xE0) = first;
    *(float *)((char *)arg0 + 0xE4) = second;
    *(int *)((char *)arg0 + 0xE8) = -1;
}
#pragma scheduling on
void fn_802AA0EC(void *arg0) {
    extern float lbl_805649F0;
    float value = lbl_805649F0;
    *(unsigned char *)((char *)arg0 + 0xEC) = 0;
    *(float *)((char *)arg0 + 0xF0) = value;
}

extern float PSVECDotProduct(const void *, const void *);
#pragma push
#pragma processor 750
#pragma opt_propagation off
void fn_802AA100(void *arg0, void *arg1, void *arg2, void *arg3) {
    float sp1C;
    float sp18;
    float sp14;
    float sp10;
    float spC;
    float sp8;
    float temp_f1;
    float temp_f31;
    float temp_f3;
    float temp_f4;
    float temp_f5;
    float temp_f6;
    float temp_f7;
    float temp_f8;
    temp_f31 = PSVECDotProduct(arg1, arg2);
    temp_f1 = PSVECDotProduct(arg1, arg3);
    temp_f7 = ((float *)arg2)[1] * temp_f31;
    temp_f8 = ((float *)arg2)[0] * temp_f31;
    temp_f4 = ((float *)arg3)[1] * temp_f1;
    temp_f6 = ((float *)arg2)[2] * temp_f31;
    temp_f5 = ((float *)arg3)[0] * temp_f1;
    sp14 = temp_f8;
    temp_f3 = ((float *)arg3)[2] * temp_f1;
    sp18 = temp_f7;
    sp1C = temp_f6;
    ((float *)arg0)[1] = temp_f7 + temp_f4;
    ((float *)arg0)[0] = temp_f8 + temp_f5;
    ((float *)arg0)[2] = temp_f6 + temp_f3;
    sp8 = temp_f5;
    spC = temp_f4;
    sp10 = temp_f3;
}
#pragma opt_propagation reset
#pragma pop
void fn_802AA1D0(unsigned int index) {
    /* Compute and store X/Y/Z extents (max-min) for the object associated with this index. */
    extern int lbl_8055F928;
    extern int lbl_80488648[];
    extern int fn_801EE0C8(int);
    extern void fn_802C77F0(int, float *);
    float bounds[8];
    int *entry = (int *)(lbl_8055F928 + index * 0x108);
    int sourceObject = fn_801EE0C8(index < 8 ? lbl_80488648[index] : 0);
    fn_802C77F0(sourceObject, bounds);
    *(float *)((char *)entry + 0xF8) = bounds[1] - bounds[0];
    *(float *)((char *)entry + 0x100) = bounds[3] - bounds[2];
    *(float *)((char *)entry + 0xFC) = bounds[5] - bounds[4];
}

extern void PSVECNormalize(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern float PSVECMag(float *);
extern void fn_8028E584(long, void *, void *, float, float, long, long, long, float, float, float, float, float, float, float, float);
extern void fn_802AA100(void *, void *, void *, void *);
extern float lbl_805649F8;
extern float lbl_80564A04;
extern float lbl_80564A08;
extern double lbl_80564A10;
extern float lbl_80564A18;
extern float lbl_80564A1C;
extern float lbl_80564A20;
extern float lbl_80564A24;
extern float lbl_80564A28;
extern float lbl_80564A2C;
extern float lbl_80564A30;
extern float lbl_80564A34;
extern float lbl_80564A38;
extern float lbl_8055CC68;
#pragma push
#pragma processor 750
void fn_802AA25C(void *arg0, void *arg1, float farg0) {
    float sp94, sp90, sp8C, sp88, sp84, sp80, sp7C, sp78, sp74, sp70, sp6C, sp68;
    Vec v50;
    Vec v5C;
    float sp4C, sp48, sp44, sp40, sp3C, sp38, sp34, sp30, sp2C, sp28, sp24, sp20;
    float sp1C, sp18, sp14;
    long sp10, spC, sp8;
    float temp_f26, temp_f27, temp_f28, temp_f29, temp_f31;
    float temp_f30;
    long var_r25, var_r28, var_r31;
    float *var_r26, *var_r27;
    void *temp_r25;
    float var_f4, var_f3, var_f3_2, var_f1, var_f0;
    float var_f29;
    *(float *)((char *)arg0 + 0xC0) = (float)fn_8002EFB4(*(float *)((char *)arg0 + 0xC0) + (lbl_80564A08 * farg0), lbl_80564A10);
    if (*(float *)((char *)arg0 + 0xD4) >= lbl_80564A18 && *(float *)((char *)arg0 + 0xD8) == lbl_805649F0 && *(unsigned char *)((char *)arg0 + 0xC4) != 0) {
        *(unsigned char *)((char *)arg0 + 0xC4) = 0;
        var_f4 = *(float *)((char *)arg0 + 0xC8) + (lbl_80564A04 * farg0);
        if (var_f4 < lbl_805649FC) {
        } else {
            var_f4 = lbl_805649FC;
        }
        var_f3 = lbl_805649FC;
        *(float *)((char *)arg0 + 0xC8) = var_f4;
        if (var_f3 < (*(float *)((char *)arg0 + 0xD4) - lbl_80564A18) / lbl_80564A1C) {
        } else {
            var_f3 = (*(float *)((char *)arg0 + 0xD4) - lbl_80564A18) / lbl_80564A1C;
        }
        if (var_f3 > lbl_805649F0) {
        } else {
            var_f3 = lbl_805649F0;
        }
        *(float *)((char *)arg0 + 0xCC) = lbl_805649F0 + (var_f3 * (var_f4 - lbl_805649F0));
    } else {
        var_f3_2 = *(float *)((char *)arg0 + 0xC8) - (lbl_80564A20 * farg0);
        if (var_f3_2 > lbl_805649F0) {
        } else {
            var_f3_2 = lbl_805649F0;
        }
        *(float *)((char *)arg0 + 0xC8) = var_f3_2;
        var_f1 = *(float *)((char *)arg0 + 0xCC) - (lbl_80564A20 * farg0);
        if (var_f1 > lbl_805649F0) {
        } else {
            var_f1 = lbl_805649F0;
        }
        *(float *)((char *)arg0 + 0xCC) = var_f1;
    }
    if (*(unsigned char *)((char *)arg1 + 0x118) != 0) {
        *(float *)((char *)arg0 + 0xCC) = lbl_805649F0;
    }
    if (*(long *)((char *)arg1 + 0x68) & 8) {
        *(float *)((char *)arg0 + 0xCC) = lbl_805649F0;
    }
    if (*(float *)((char *)arg0 + 0xCC) >= lbl_80564A24) {
        float bx = *(float *)((char *)arg1 + 0xAC);
        float by = lbl_805649F0;
        float bz = *(float *)((char *)arg1 + 0xB4);
        float *m = (float *)arg1;
        float x1, y1, z1;
        float x2, y2, z2;
        sp80 = bx;
        sp84 = by;
        sp88 = bz;
        sp8C = *(float *)((char *)arg1 + 0x124);
        sp90 = by;
        sp94 = *(float *)((char *)arg1 + 0x12C);
        x1 = sp80;
        y1 = sp84;
        z1 = sp88;
        if (&sp80 == &sp80) {
            float rx = z1 * m[6] + (x1 * m[0] + y1 * m[3]);
            float ry = z1 * m[7] + (x1 * m[1] + y1 * m[4]);
            float rz = z1 * m[8] + (x1 * m[2] + y1 * m[5]);
            sp80 = rx;
            sp84 = ry;
            sp88 = rz;
        } else {
            sp80 = m[6] * z1 + (m[0] * x1 + m[3] * y1);
            sp84 = m[7] * z1 + (m[4] * sp80 + m[5] * y1);
            sp88 = m[8] * z1 + (m[2] * sp80 + m[5] * sp84);
        }
        x2 = sp8C;
        y2 = sp90;
        z2 = sp94;
        if (&sp8C == &sp8C) {
            float rx = z2 * m[6] + (x2 * m[0] + y2 * m[3]);
            float ry = z2 * m[7] + (x2 * m[1] + y2 * m[4]);
            float rz = z2 * m[8] + (x2 * m[2] + y2 * m[5]);
            sp8C = rx;
            sp90 = ry;
            sp94 = rz;
        } else {
            sp8C = m[6] * z2 + (m[0] * x2 + m[3] * y2);
            sp90 = m[7] * z2 + (m[1] * sp8C + m[4] * y2);
            sp94 = m[8] * z2 + (m[2] * sp8C + m[5] * sp90);
        }
        fn_802AA100(&v5C, (char *)arg1 + 0x40, arg1, (char *)arg1 + 0x18);
        if (PSVECDotProduct(&v5C, &v5C) > lbl_80564A28) {
            float dot;
            PSVECNormalize(&v5C, &v5C);
            dot = PSVECDotProduct(&v5C, (char *)arg1 + 0x18);
            var_f0 = lbl_805649F0;
            if (var_f0 > dot) {
            } else {
                var_f0 = dot;
            }
            *(float *)((char *)arg0 + 0xD0) = var_f0;
            var_f29 = lbl_80564A2C;
            PSVECCrossProduct(&v5C, (char *)arg1 + 0xC, &v50);
            var_r26 = &sp80;
            temp_f26 = lbl_805649F8;
            var_r27 = var_r26;
            var_r25 = 0;
            do {
                float mag = PSVECMag(var_r26);
                float cosv = (float)fabs(PSVECDotProduct(&v50, var_r26) / mag);
                if (cosv > var_f29) {
                    float vx = var_r27[0];
                    var_f29 = cosv;
                    sp68 = vx;
                    sp6C = var_r27[1];
                    sp70 = var_r27[2];
                    sp74 = vx * temp_f26;
                    sp78 = var_r27[1] * temp_f26;
                    sp7C = var_r27[2] * temp_f26;
                }
                var_r25 += 1;
                var_r26 += 3;
                var_r27 += 3;
            } while (var_r25 < 2);
            {
                UnkAAF04Conversion conv;
                float t28;
                float temp_f1;
                long i10 = *(long *)((char *)arg1 + 0x34);
                long i9 = *(long *)((char *)arg1 + 0x38);
                long i8 = *(long *)((char *)arg1 + 0x3C);
                *(float *)((char *)arg0 + 0) = sp68 + *(float *)((char *)arg1 + 0x24);
                *(float *)((char *)arg0 + 4) = sp6C + *(float *)((char *)arg1 + 0x28);
                temp_f31 = lbl_80564A30;
                *(float *)((char *)arg0 + 8) = sp70 + *(float *)((char *)arg1 + 0x2C);
                temp_f27 = lbl_805649FC;
                *(float *)((char *)arg0 + 0xC) = sp74 + *(float *)((char *)arg1 + 0x24);
                *(float *)((char *)arg0 + 0x10) = sp78 + *(float *)((char *)arg1 + 0x28);
                *(float *)((char *)arg0 + 0x14) = sp7C + *(float *)((char *)arg1 + 0x2C);
                var_r31 = 1;
                var_r28 = 0x18;
                do {
                    float a8 = *(float *)((char *)arg1 + 0x40);
                    float aC = *(float *)((char *)arg1 + 0x44);
                    float a10 = *(float *)((char *)arg1 + 0x48);
                    conv.words[0] = 0x43300000;
                    conv.words[1] = (unsigned long)var_r31 ^ 0x8000;
                    t28 = (float)(conv.value - lbl_80564A40) * temp_f31;
                    temp_r25 = (char *)arg0 + var_r28;
                    sp38 = a8;
                    sp3C = aC;
                    sp40 = a10;
                    sp2C = v5C.x;
                    sp30 = v5C.y;
                    sp34 = v5C.z;
                    temp_f1 = -PSVECMag((float *)((char *)arg1 + 0x34)) * lbl_8055CC68;
                    sp28 = a8;
                    sp2C = v5C.x;
                    {
                        float p10 = temp_f27 * (t28 * temp_f1);
                        float p11 = temp_f27 * ((temp_f27 - t28) * temp_f1);
                        float g6 = sp38 * p10;
                        float h9 = sp2C * p11;
                        float g7 = sp3C * p10;
                        float h8;
                        float g63;
                        float h10;
                        float h52;
                        float f34;
                        float h73;
                        float f2;
                        float h43;
                        float f17;
                        sp38 = g6;
                        h8 = sp30 * p11;
                        g63 = h9 + g6;
                        h10 = sp40 * p10;
                        h52 = h8 + g7;
                        sp3C = g7;
                        f34 = g63 * temp_f31;
                        h73 = sp34 * p11;
                        f2 = h52 * temp_f31;
                        sp40 = h10;
                        h43 = h73 + h10;
                        sp2C = h9;
                        *(float *)((char *)temp_r25 + 0) = *(float *)((char *)temp_r25 - 0x18) + f34;
                        f17 = h43 * temp_f31;
                        sp30 = h8;
                        sp34 = h73;
                        *(float *)((char *)temp_r25 + 4) = *(float *)((char *)temp_r25 - 0x14) + f2;
                        sp44 = g63;
                        sp48 = h52;
                        *(float *)((char *)temp_r25 + 8) = *(float *)((char *)temp_r25 - 0x10) + f17;
                        sp4C = h43;
                        *(float *)((char *)temp_r25 + 0xC) = *(float *)((char *)temp_r25 - 0xC) + f34;
                        *(float *)((char *)temp_r25 + 0x10) = *(float *)((char *)temp_r25 - 0x8) + f2;
                        *(float *)((char *)temp_r25 + 0x14) = *(float *)((char *)temp_r25 - 0x4) + f17;
                    }
                    if (!(temp_f29 <= *(float *)lbl_80558DC4) && fn_80287BC8(lbl_805649F0, temp_f27) < (*(float *)((char *)arg0 + 0xCC) * *(float *)((char *)arg0 + 0xD0)) && fn_80287BC8(lbl_805649F0, lbl_805649FC) > t28) {
                        float f18 = fn_80287BC8(lbl_80564A34, lbl_80564A38);
                        float b8 = *(float *)((char *)temp_r25 + 8);
                        float b4 = *(float *)((char *)temp_r25 + 4);
                        float b0 = *(float *)((char *)temp_r25 + 0);
                        float c5 = b8 + (f18 * (*(float *)((char *)temp_r25 + 0x14) - b8));
                        float c4 = b4 + (f18 * (*(float *)((char *)temp_r25 + 0x10) - b4));
                        float c6 = b0 + (f18 * (*(float *)((char *)temp_r25 + 0xC) - b0));
                        sp28 = c5;
                        sp20 = c6 + (*(float *)((char *)arg1 + 0xC) * temp_f26);
                        sp24 = c4 + (*(float *)((char *)arg1 + 0x10) * temp_f26);
                        sp28 = c5 + (*(float *)((char *)arg1 + 0x14) * temp_f26);
                        sp8 = i10;
                        spC = i9;
                        sp10 = i8;
                        sp14 = sp20;
                        sp18 = sp24;
                        sp1C = sp28;
                        fn_8028E584(*(long *)((char *)lbl_8055F924 + 4), &sp14, &sp8, sp24, sp20, i8, i9, i10, c4, c6, *(float *)((char *)arg1 + 0xC) * temp_f26, c4, c5, c6, b4, b8);
                    }
                    var_r31 += 1;
                    var_r28 += 0x18;
                } while (var_r31 < 8);
            }
            return;
        }
        *(float *)((char *)arg0 + 0xD0) = lbl_805649F0;
    }
}

#pragma push
#pragma processor 750
void fn_802AA9D4(UnkAA9D4 *arg0, void *arg1, float delta) {
    extern float lbl_805649F4, lbl_80564A08, lbl_80564A04, lbl_80564A48, lbl_80564A4C, lbl_80564A50;
    extern float fn_80287BC8(float, float);
    extern void fn_8028E590(int, Vec *, Vec *, float);
    Vec pos, dir, callpos, calldir, side, forward;
    float width = lbl_805649F4 * arg0->width;
    float depth = lbl_805649F4 * arg0->depth;
    float height = lbl_805649F4 * arg0->height;
    float v, angle, scale;

    if (arg0->active) {
        float max;
        v = lbl_80564A08 * delta;
        max = lbl_805649FC;
        arg0->active = 0;
        arg0->amount = (v += arg0->amount) < max ? v : max;
    } else {
        v = arg0->amount - lbl_80564A08 * delta;
        arg0->amount = v > lbl_805649F0 ? v : lbl_805649F0;
    }

    if ((float)fabs(delta) <= *(float *)lbl_80558DC4) return;
    if (!(fn_80287BC8(lbl_805649F0, lbl_805649FC) < arg0->amount)) return;

    angle = fn_80287BC8(lbl_80564A48, lbl_80564A4C);
    forward = *(Vec *)arg1;
    side = *(Vec *)((char *)arg1 + 0x18);
    pos = *(Vec *)((char *)arg1 + 0x24);

    scale = width * (float)cos(angle);
    pos.x += forward.x * scale;
    pos.y += forward.y * scale;
    pos.z += forward.z * scale;

    scale = depth * (float)sin(angle);
    pos.x += side.x * scale;
    pos.y += side.y * scale;
    pos.z += side.z * scale;

    scale = fn_80287BC8(lbl_805649F0, lbl_80564A04 * height);
    pos.x += *(float *)((char *)arg1 + 0xC) * scale;
    pos.y += *(float *)((char *)arg1 + 0x10) * scale;
    pos.z += *(float *)((char *)arg1 + 0x14) * scale;

    dir = *(Vec *)((char *)arg1 + 0x34);
    if (*(float *)((char *)arg1 + 0x4C) >= lbl_80564A50 - *(float *)lbl_80558DC4) {
        calldir = dir;
        callpos = pos;
        fn_8028E590(*(int *)lbl_8055F924, &callpos, &calldir, lbl_805649FC);
    }
}
#pragma pop

#pragma push
#pragma processor 750
void fn_802AAC80(void *arg0, void *arg1, float farg0) {
    /* Update object m_value (+0xF0): after fn_801E86F8(0), ramp toward 1.0 (lbl_805649FC)
       when m_flag (+0xEC) is set (and clear it), toward 0.0 (lbl_805649F0) when
       state m_condition (+0x118) is clear, else set to 0.0; force 0.0 if state m_flags & 8. */
    struct Object {
        unsigned char pad0[0xEC];
        unsigned char m_flag;
        unsigned char pad1[3];
        float m_value;
    };
    struct State {
        unsigned char pad0[0x68];
        unsigned int m_flags;
        unsigned char pad1[0xAC];
        unsigned char m_condition;
    };
    extern void fn_801E86F8(int);
    extern float lbl_805649F0, lbl_805649FC, lbl_80564A04;
    struct Object *object = (struct Object *)arg0;
    struct State *state = (struct State *)arg1;
    volatile unsigned char *triggerFlag = &object->m_flag;
    volatile float *currentValue = &object->m_value;
    fn_801E86F8(0);
    if (*triggerFlag) {
        float limit, current, delta, step;
        step = *(volatile float *)&lbl_80564A04;
        current = *currentValue;
        delta = step * farg0;
        limit = *(volatile float *)&lbl_805649FC;
        *triggerFlag = 0;
        current += delta;
        object->m_value = current < limit ? current : limit;
    } else if (state->m_condition) {
        object->m_value = lbl_805649F0;
    } else {
        float limit, current, delta, step;
        step = *(volatile float *)&lbl_80564A04;
        current = *currentValue;
        delta = step * farg0;
        limit = *(volatile float *)&lbl_805649F0;
        current -= delta;
        object->m_value = current > limit ? current : limit;
    }
    if (state->m_flags & 8)
        object->m_value = lbl_805649F0;
}
#pragma push
#pragma processor 750
void fn_802AAD5C(int arg0, int arg1, int arg2) {
    extern void fn_802C8BD0(int);
    extern void fn_801E866C(int);
    extern void fn_802C8DBC(int);
    extern void fn_802C8E00(unsigned int, int, float, float, float, float, float);
    extern void fn_802C8E48(void);
    extern void fn_802C8D74(void);
    extern int lbl_8055CC60, lbl_8055CC70, lbl_8055CC74, lbl_8055CC78;
    extern float lbl_8055CC6C, lbl_805649F0, lbl_805649F4, lbl_805649FC, lbl_80564A24, lbl_80564A30, lbl_80564A54;
    float *arg;
    volatile float sp8, spC, sp10;
    float temp_f2, temp_f0, temp_f4, temp_f31;
    int i, n, color0, color1, color2, alpha;
    union {
        unsigned int word;
        struct { unsigned char a, r, g, b; } bytes;
    } color;
    fn_802C8BD0(lbl_8055CC60);
    fn_801E866C(-1);
    if (*(float *)((char *)arg1 + 0xCC) > lbl_80564A24) {
        fn_802C8DBC(0x10);
        temp_f31 = *(float *)((char *)arg1 + 0xC0);
        arg = (float *)arg1;
        for (i = 0; i < 0x10; i++, arg += 3) {
            sp8 = arg[0];
            spC = arg[1];
            sp10 = arg[2];
            n = 0;
            if (i > 1) n = (0x10 - (i + 1)) / 2;
            temp_f2 = (float)n * lbl_80564A30;
            temp_f0 = lbl_8055CC6C * (temp_f2 * (lbl_80564A54 * (*(float *)((char *)arg1 + 0xCC) * *(float *)((char *)arg1 + 0xD0))));
            if (temp_f0 < lbl_805649F0) temp_f0 -= lbl_805649F4;
            else temp_f0 += lbl_805649F4;
            alpha = (int)temp_f0;
            color0 = (unsigned char)lbl_8055CC70;
            color1 = (unsigned char)lbl_8055CC78;
            color2 = (unsigned char)lbl_8055CC74;
            color.bytes.a = (unsigned char)alpha;
            color.bytes.r = (unsigned char)color0;
            color.bytes.g = (unsigned char)color1;
            color.bytes.b = (unsigned char)color2;
            temp_f4 = (i & 1) ? lbl_805649F0 : lbl_805649FC;
            fn_802C8E00(color.word, 1, sp8, spC, sp10, temp_f4, temp_f31 - temp_f2);
        }
        fn_802C8E48();
    }
    fn_802C8D74();
}
#pragma pop
void fn_802AAF00(int a, int b, int c) {}

extern int lbl_8055CC64;
extern float lbl_805649F0, lbl_805649F4, lbl_805649F8, lbl_805649FC;
extern float lbl_80564A20, lbl_80564A34, lbl_80564A4C, lbl_80564A54;
extern float lbl_80564A58, lbl_80564A5C, lbl_80564A60, lbl_80564A64;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802AAF04(int arg0, int arg1, int arg2) {
    extern void fn_802C8BD0(int);
    extern void fn_802C8DBC(int);
    extern void fn_802C8E00(unsigned int, int, float, float, float, float, float);
    extern void fn_802C8E48(void);
    extern void fn_802C8D74(void);
    extern int lbl_8055CC64;
    extern float lbl_805649F0, lbl_805649F4, lbl_805649F8, lbl_805649FC;
    extern float lbl_80564A20, lbl_80564A34, lbl_80564A4C, lbl_80564A54;
    extern float lbl_80564A58, lbl_80564A5C, lbl_80564A60, lbl_80564A64;
    extern const double lbl_80564A40;
    char *obj = (char *)arg1;
    char *data = (char *)arg2;
    struct { float sp8[6]; unsigned int words[12]; UnkAAF04Conversion conv; } frame;
    double sp98, sp90, sp88, sp80, sp78, sp70, sp68, sp60, sp58;
    double temp_f15;
    float *var_r29;
    float temp_f14, temp_f16, temp_f17, temp_f18, temp_f19, temp_f20, temp_f26, temp_f27, temp_f28;
    float temp_f21, temp_f21_2, temp_f22, temp_f23, temp_f24, temp_f25;
    float temp_f29, temp_f2, temp_f30, temp_f31, temp_f4, temp_f6;
    float var_f0, var_f1, var_f1_2, var_f21, var_f4;
    int var_r28, var_r27, var_r26;
    frame.words[0] = *(unsigned int *)(data + 0);
    frame.words[1] = *(unsigned int *)(data + 4);
    frame.words[2] = *(unsigned int *)(data + 8);
    frame.words[3] = *(unsigned int *)(data + 0xC);
    frame.words[4] = *(unsigned int *)(data + 0x10);
    frame.words[5] = *(unsigned int *)(data + 0x14);
    frame.words[6] = *(unsigned int *)(data + 0x18);
    frame.words[7] = *(unsigned int *)(data + 0x1C);
    frame.words[8] = *(unsigned int *)(data + 0x20);
    frame.words[9] = *(unsigned int *)(data + 0x24);
    frame.words[10] = *(unsigned int *)(data + 0x28);
    frame.words[11] = *(unsigned int *)(data + 0x2C);
    if (*(float *)(obj + 0xF0) > lbl_80564A58) {
        fn_802C8BD0(lbl_8055CC64);
        var_r28 = 0;
        sp58 = (double)(*(float *)&frame.words[9]);
        temp_f20 = (*(float *)&frame.words[0]);
        temp_f24 = lbl_805649F4;
        sp60 = (double)(*(float *)&frame.words[1]);
        temp_f25 = lbl_80564A64;
        temp_f26 = (*(float *)&frame.words[3]);
        temp_f27 = (*(float *)&frame.words[4]);
        temp_f28 = (*(float *)&frame.words[5]);
        sp68 = (double)(*(float *)&frame.words[10]);
        sp70 = (double)(*(float *)&frame.words[2]);
        sp78 = (double)(*(float *)&frame.words[11]);
        sp80 = (double)(*(float *)&frame.words[6]);
        temp_f29 = lbl_80564A54;
        sp88 = (double)(*(float *)&frame.words[7]);
        temp_f30 = lbl_805649F0;
        sp90 = (double)(*(float *)&frame.words[8]);
        temp_f31 = lbl_805649FC;
        sp98 = (double)lbl_80564A34;
        temp_f19 = lbl_805649F8;
        temp_f16 = lbl_80564A20;
        temp_f17 = lbl_80564A60;
        temp_f18 = lbl_80564A5C;
        temp_f15 = lbl_80564A40;
        do {
            fn_802C8DBC(0xA);
            var_r27 = 0;
        loop_3:
            frame.conv.words[0] = 0x43300000;
            frame.conv.words[1] = ((unsigned int)var_r27) ^ 0x80000000;
            temp_f14 = (float)(frame.conv.value - temp_f15);
            if (var_r28 == 0) {
                var_f1 = lbl_80564A4C;
            } else {
                var_f1 = lbl_805649F0;
            }
            var_f21 = temp_f18 + (temp_f17 * ((temp_f14 - temp_f31) / temp_f16)) + var_f1;
            if (*(unsigned char *)(obj + 0xF4) != 0) {
                var_f21 *= temp_f19;
            }
            temp_f2 = (float)cos(var_f21);
            temp_f21 = *(float *)(obj + 0xFC) * temp_f2 * temp_f24;
            temp_f6 = *(float *)(obj + 0xFC) * (float)sin(var_f21) * temp_f24;
            var_r29 = frame.sp8;
            var_r26 = 0;
            temp_f21_2 = (float)sp58 + (temp_f20 * temp_f21) + ((float)sp80 * temp_f6);
            temp_f22 = (float)sp68 + ((float)sp60 * temp_f21) + ((float)sp88 * temp_f6);
            temp_f23 = (float)sp78 + ((float)sp70 * temp_f21) + ((float)sp90 * temp_f6);
        do {
            var_r29[0] = temp_f21_2;
            var_r29[1] = temp_f22;
            var_r29[2] = temp_f23;
            if (var_r26 != 0) {
                var_f1_2 = (*(float *)(obj + 0x100) * temp_f24) - temp_f25;
            } else {
                var_f1_2 = temp_f25 + (*(float *)(obj + 0x100) * temp_f24);
            }
            temp_f4 = temp_f29 * *(float *)(obj + 0xF0);
            var_r29[0] = var_r29[0] + (temp_f26 * var_f1_2);
            var_r29[1] = var_r29[1] + (temp_f27 * var_f1_2);
            var_r29[2] = var_r29[2] + (temp_f28 * var_f1_2);
            if (temp_f4 < temp_f30) {
                var_f0 = temp_f4 - temp_f24;
            } else {
                var_f0 = temp_f24 + temp_f4;
            }
            if (var_r26 != 0) {
                var_f4 = lbl_805649FC;
            } else {
                var_f4 = lbl_805649F0;
            }
            fn_802C8E00(((int)var_f0 << 0x18) | 0xFF0000 | 0xFFFF, 1, var_r29[0], var_r29[1], var_r29[2], var_f4, temp_f31 - (temp_f14 * (float)sp98));
            var_r26 += 1;
            var_r29 += 3;
        } while (var_r26 < 2);
            var_r27 += 1;
            if (var_r27 < 5) {
                goto loop_3;
            }
            fn_802C8E48();
            var_r28 += 1;
        } while (var_r28 < 2);
        fn_802C8D74();
    }
}

#pragma push
#pragma processor 750
void fn_802AB21C(void) {
    typedef struct StuntStrings {
        char name1[12];
        char name2[12];
        char name3[12];
        char name4[16];
    } StuntStrings;
    struct {
        Vec v[4];
        InitStruct s2;
        InitStruct s1;
    } frame;
    const StuntStrings *base;
    void *buffer;
    int *r29;
    register int two;
    register int five;
    register float t31;
    float t13, t3, t2;
    base = (const StuntStrings *)lbl_80349DC8;
    buffer = fn_8012850C(0x850, base->name1);
    lbl_8055F928 = (int)fn_8002F37C(buffer, fn_802AB500, 0, 0x108, 8);
    r29 = (int *)fn_801284F8(8, base->name2);
    if (r29 != NULL) {
        fn_8028E61C(&frame.s1);
        t31 = lbl_80564A68 * lbl_80564A68;
        two = 2;
        five = 5;
        t13 = lbl_80564A80 * (lbl_80564A70 / t31);
        t3 = lbl_805649F4 * t13;
        t3 = t3 * t31;
        frame.s1.field_04 = 0x12C;
        frame.s1.field_08 = lbl_80564A68;
        t2 = lbl_80564A84 - t3;
        t2 = t2 / lbl_80564A68;
        frame.s1.field_0C = lbl_805649FC;
        frame.s1.field_00 = two;
        frame.s1.field_48 = lbl_805649F4;
        frame.s1.field_44 = five;
        frame.v[2].x = lbl_805649F0;
        frame.v[2].y = lbl_805649FC;
        frame.v[2].z = lbl_805649F0;
        frame.s1.vA.x = lbl_805649F0;
        frame.s1.vA.y = lbl_805649FC;
        frame.s1.vA.z = lbl_805649F0;
        frame.v[3].x = lbl_80564A6C;
        frame.v[3].y = lbl_805649FC;
        frame.v[3].z = lbl_80564A6C;
        frame.s1.vB.x = lbl_80564A6C;
        frame.s1.vB.y = lbl_805649FC;
        frame.s1.vB.z = lbl_80564A6C;
        frame.s1.vC.x = lbl_805649F0;
        frame.s1.vC.y = lbl_80564A70;
        frame.s1.vC.z = lbl_805649F0;
        frame.s1.field_34 = lbl_80564A74;
        frame.s1.field_60 = lbl_80564A78;
        frame.s1.field_68 = lbl_80564A78;
        frame.s1.field_70 = lbl_80564A78;
        frame.s1.field_64 = lbl_805649FC;
        frame.s1.field_6C = lbl_805649FC;
        frame.s1.field_74 = lbl_805649FC;
        frame.s1.field_58 = lbl_805649F0;
        frame.s1.field_5C = lbl_80564A7C;
        frame.s1.field_4C = t13;
        frame.s1.field_50 = t2;
        frame.s1.field_54 = lbl_80564A58;
        frame.s1.field_78 = lbl_805649F0;
        frame.s1.field_7C = lbl_80564A04;
        r29[0] = ((int (*)(void *, const void *, const void *))fn_8028E2F8)(&frame.s1, lbl_80349E24, lbl_80349E18);
        fn_8028E61C(&frame.s2);
        frame.s2.field_04 = 0x60;
        frame.s2.field_08 = lbl_805649F4;
        frame.s2.field_0C = lbl_805649FC;
        frame.s2.field_00 = two;
        frame.s2.field_48 = lbl_805649F4;
        frame.s2.field_44 = five;
        frame.v[0].x = lbl_805649F0;
        frame.v[0].y = lbl_805649F0;
        frame.v[0].z = lbl_805649F0;
        frame.s2.vA.x = lbl_805649F0;
        frame.s2.vA.y = lbl_805649F0;
        frame.s2.vA.z = lbl_805649F0;
        frame.v[1].x = lbl_805649FC;
        frame.v[1].y = lbl_805649FC;
        frame.v[1].z = lbl_805649FC;
        frame.s2.vB.x = lbl_805649FC;
        frame.s2.vB.y = lbl_805649FC;
        frame.s2.vB.z = lbl_805649FC;
        frame.s2.vC.x = lbl_805649F0;
        frame.s2.vC.y = lbl_80564A00;
        frame.s2.vC.z = lbl_805649F0;
        frame.s2.field_34 = lbl_80564A74;
        frame.s2.field_70 = lbl_80564A78;
        frame.s2.field_68 = lbl_80564A78;
        frame.s2.field_60 = lbl_80564A78;
        frame.s2.field_74 = lbl_80564A88;
        frame.s2.field_6C = lbl_80564A88;
        frame.s2.field_64 = lbl_80564A88;
        frame.s2.field_58 = lbl_80564A78;
        frame.s2.field_5C = lbl_80564A8C;
        frame.s2.field_50 = lbl_80564A8C;
        frame.s2.field_54 = lbl_80564A90;
        frame.s2.field_78 = lbl_80564A94;
        frame.s2.field_7C = lbl_805649FC;
        r29[1] = ((int (*)(void *, const void *, const void *))fn_8028E2F8)(&frame.s2, &lbl_8055CC80, lbl_80349E08);
    }
    lbl_8055F924 = r29;
    fn_802AB5B8();
    lbl_8055CC60 = fn_802CAC28(base->name3, 0);
    lbl_8055CC64 = fn_802CAC28(base->name4, 0);
    fn_801EEFDC(fn_802A9F30, 0xF);
    fn_801EEFDC(fn_802A9F90, 0x10);
    fn_801EEFDC(fn_802A9FB0, 0x11);
    *(char *)&lbl_8055F92C = (*(int *)((char *)fn_801E87A8() + 4) == 0x180304);
}
#pragma pop

#pragma scheduling on
#pragma pop
void fn_802AB500(void) {}

/* Shutdown: unregister callbacks, destroy owned objects/buffers, and reset handles. */
void fn_802AB504(void) {
    extern void fn_801EF024(void (*)(void));
    extern void fn_80128670(void *);
    extern void fn_802CAC54(int);
    extern s32 fn_802A9F30(void *), fn_802A9F90(s32 *);
    extern s32 fn_802A9FB0(void *);
    extern unsigned char lbl_8055F92C;
    extern void *lbl_8055F924;
    extern int lbl_8055F928, lbl_8055CC60, lbl_8055CC64;
    int *object;
    int *buffer;

    lbl_8055F92C = 0;
    fn_801EF024((void (*)(void))fn_802A9F30);
    fn_801EF024((void (*)(void))fn_802A9F90);
    fn_801EF024((void (*)(void))fn_802A9FB0);

    object = (int *)lbl_8055F924;
    if (object) {
        fn_8028E398(object[0]);
        fn_8028E398(object[1]);
        fn_80128668(object);
    }
    lbl_8055F924 = 0;

    buffer = (int *)lbl_8055F928;
    if (buffer) {
        fn_80128670((char *)buffer - 0x10);
    }
    lbl_8055F928 = 0;

    fn_802CAC54(lbl_8055CC60);
    lbl_8055CC60 = -2;
    fn_802CAC54(lbl_8055CC64);
    lbl_8055CC64 = -2;
}

#pragma dont_inline on
void fn_802AB5B8(void) {
    extern int lbl_8055F928;
    int offset = 0;
    int index = 0;
    do {
        char *entry = (char *)lbl_8055F928 + offset;
        *(int *)(entry + 0x104) = index;
        fn_802A9FE0(entry);
        fn_802AA0C8(entry);
        fn_802AA0EC(entry);
        index++;
        offset += 0x108;
    } while (index < 8);
}

#pragma push
#pragma use_lmw_stmw off
void fn_802AB628(float deltaTime) {
    /* Per-frame update for each active object: for each index, run AA1D0 setup
       (index), then update entry at lbl_8055F928 + i*0x108 via AA25C/AA9D4/AAC80
       with the object returned by fn_80287B24(i). */
    extern int fn_80287B14(void);              /* object count */
    extern int fn_80287B24(int);               /* object pointer/data by index */
    extern void fn_802AA1D0(unsigned int);     /* per-index setup using lbl_80488648 */
    extern void fn_802AA25C(void *, void *, float);
    extern void fn_802AA9D4(UnkAA9D4 *, void *, float);
    extern void fn_802AAC80(void *, void *, float);
    extern int lbl_8055F928;                   /* base of per-object state entries (stride 0x108) */
    int count = fn_80287B14();
    int entryOffset;
    int index;
    int object;
    int entryBase;

    index = 0;
    entryOffset = index;
    goto check;
loop:
    object = fn_80287B24(index);
    entryBase = lbl_8055F928 + entryOffset;
    fn_802AA1D0(index);
    fn_802AA25C((void *)entryBase, (void *)object, deltaTime);
    fn_802AA9D4((UnkAA9D4 *)entryBase, (void *)object, deltaTime);
    fn_802AAC80((void *)entryBase, (void *)object, deltaTime);
    entryOffset += 0x108;
    index += 1;
check:
    if (index < count)
        goto loop;
}
#pragma pop
void fn_802AB6D0(void) {}

#pragma push
#pragma use_lmw_stmw off
void fn_802AB6D4(void) {
    /* Draw pass for the stunt-car effect system: for each active object, render its
       air-stream trail and entry-puff quads into the current draw list. Each object's
       per-frame effect state lives in the entry at lbl_8055F928 + i*0x108. */
    extern int fn_80287B14(void);              /* number of active objects */
    extern int fn_80287B24(int);               /* object pointer by index (stride 0x160) */
    extern int fn_802C86DC(void);              /* current draw list */
    extern void fn_802AAD5C(int, int, int);    /* draw the air-stream trail (airstrm.tex) */
    extern void fn_802AAF00(int, int, int);    /* reserved draw step (empty) */
    extern void fn_802AAF04(int, int, int);    /* draw the entry-puff quads (entrypuff.tex) */
    extern int lbl_8055F928;                   /* base of per-object effect entries (stride 0x108) */
    int count = fn_80287B14();
    int drawList = fn_802C86DC();
    int i;
    for (i = 0; i < count; i++) {
        int object = fn_80287B24(i);
        int entry = lbl_8055F928 + i * 0x108;
        fn_802AAD5C(drawList, entry, object);
        fn_802AAF00(drawList, entry, object);
        fn_802AAF04(drawList, entry, object);
    }
}

#pragma push
#pragma processor 750
void fn_802AB770(int arg0) {
    extern int lbl_8055F928;
    extern unsigned char lbl_8055F92C, lbl_8055F92D;
    extern float lbl_805649F0, lbl_805649F4, lbl_805649FC;
    extern float lbl_80564A00, lbl_80564A34, lbl_80564A68, lbl_80564A8C, lbl_80564A98, lbl_80564A9C;
    extern float lbl_80564AA8, lbl_80564AAC;
    extern double lbl_80564AA0;
    extern int lbl_804BD7B0[4];
    extern double __fabs(double);
    extern float fn_801E7E24(void);
    extern float fn_80287BC8(float, float);
    extern double fn_8002EFB4(float, double);
    extern int fn_802C2C00(int);
    extern int fn_802C990C(int);
    extern void fn_802C2BB8(int *, int *, int *);
    extern void fn_802C2B78(float, float, float);
    char *state = (char *)(lbl_8055F928 + arg0 * 0x108);
    int obj = fn_80287B24(arg0);
    float delta = fn_801E7E24();
    float angle;
    float wave1;
    float wave2;
    int color;
    int lt;
    unsigned char r, g, b;
    if (!((float)__fabs(delta) <= *(float *)(void *)&lbl_80558DC4)) {
        int hi;
        int lo;
        r = fn_80129D90(0, 0x8C, 0xFF) & 0xFF;
        g = fn_80129D90(0, 0xFA, 0xFF) & 0xFF;
        b = fn_80129D90(0, 0xF0, 0xFF);
        hi = (b << 16);
        lo = (g << 8) | r;
        hi |= 0xFF000000;
        *(int *)(state + 0xE8) = lo | hi;
    }
    angle = *(float *)((char *)obj + 0x4C);
    if (lbl_8055F92C != 0) angle = lbl_80564A98;
    if (*(float *)(state + 0xE4) > lbl_805649F4)
        *(float *)(state + 0xE4) = fn_80287BC8(lbl_80564A8C, lbl_80564A68);
    else
        *(float *)(state + 0xE4) += lbl_80564A34 * delta;
    wave1 = lbl_805649F0;
    if (!((float)__fabs(delta) <= *(float *)(void *)&lbl_80558DC4))
        wave1 = lbl_80564A9C * (float)(int)fn_80287BC8(wave1, lbl_805649FC);
    color = 1;
    lt = angle < lbl_80564A00;
    if (lt && !((float)fn_8002EFB4(angle, lbl_80564AA0) > lbl_80564A34)) color = 0;
    wave2 = lbl_805649F0;
    if (color != 0) wave2 = lbl_80564AA8 * *(float *)(state + 0xE4) - wave1;
    {
        int old = *(int *)(state + 0xE8);
        lbl_8055F92D = fn_802C2C00(1);
        lbl_804BD7B0[0] = fn_802C990C(old);
        fn_802C2BB8(&lbl_804BD7B0[1], &lbl_804BD7B0[2], &lbl_804BD7B0[3]);
        fn_802C2B78(wave2, lbl_80564AAC + wave2, lbl_805649FC);
    }
}
#pragma pop
void fn_802AB994(void) {
    fn_802C990C(lbl_804BD7B0[0]);
    ((void (*)(void *, float, float, float))fn_802C2B78)((void *)lbl_804BD7B0, *(float *)&lbl_804BD7B0[1], *(float *)&lbl_804BD7B0[2], *(float *)&lbl_804BD7B0[3]);
    fn_802C2C00(lbl_8055F92D);
}

void fn_802AB9E0(void) { fn_8028E070(); }

void fn_802AB9E4(void) { fn_8028E080(); }

extern void fn_8028DFFC(void);
extern void *fn_801284F8(int, const char *);
extern void fn_8028E61C(void *);
extern void fn_8028E024(void);
extern int fn_8028E2F8(void *, const void *, const void *, ...);
extern const char lbl_80349DFC[], lbl_80349E24[], lbl_80349E18[], lbl_80349E08[];
extern float lbl_805649F0, lbl_805649F4, lbl_805649FC, lbl_80564A00, lbl_80564A04, lbl_80564A58, lbl_80564A68, lbl_80564A6C, lbl_80564A70, lbl_80564A74, lbl_80564A78, lbl_80564A7C, lbl_80564A80, lbl_80564A84, lbl_80564A88, lbl_80564A8C, lbl_80564A90, lbl_80564A94;
extern float lbl_8055CC80;
#pragma push
#pragma processor 750
void fn_802AB9E8(void) {
    struct {
        Vec v[4];
        InitStruct s2;
        InitStruct s1;
    } frame;
    int *r29;
    register int two;
    register int five;
    float t13;
    register float t31;
    register float t3;
    float t2;
    extern void fn_8028DFFC(void);
    extern void *fn_801284F8(int, const char *);
    extern void fn_8028E61C(void *);
    extern void fn_8028E024(void);
    extern int fn_8028E2F8(void *, const void *, const void *, ...);
    extern const char lbl_80349DFC[], lbl_80349E24[], lbl_80349E18[], lbl_80349E08[];
    extern float lbl_8055CC80;
    extern float lbl_805649F0, lbl_805649F4, lbl_805649FC, lbl_80564A00, lbl_80564A04, lbl_80564A58, lbl_80564A68, lbl_80564A6C, lbl_80564A70, lbl_80564A74, lbl_80564A78, lbl_80564A7C, lbl_80564A80, lbl_80564A84, lbl_80564A88, lbl_80564A8C, lbl_80564A90, lbl_80564A94;
    extern void *lbl_8055F924;
    fn_8028DFFC();
    r29 = (int *)fn_801284F8(8, lbl_80349DFC);
    if (r29 != NULL) {
        fn_8028E61C(&frame.s1);
        two = 2;
        five = 5;
        frame.s1.field_04 = 0x12C;
        frame.s1.field_08 = lbl_80564A68;
        frame.s1.field_0C = lbl_805649FC;
        frame.s1.field_00 = two;
        frame.s1.field_48 = lbl_805649F4;
        frame.s1.field_44 = five;
        frame.v[2].x = lbl_805649F0;
        frame.v[2].y = lbl_805649FC;
        frame.v[2].z = lbl_805649F0;
        frame.s1.vA.x = lbl_805649F0;
        frame.s1.vA.y = lbl_805649FC;
        frame.s1.vA.z = lbl_805649F0;
        frame.v[3].x = lbl_80564A6C;
        frame.v[3].y = lbl_805649FC;
        frame.v[3].z = lbl_80564A6C;
        frame.s1.vB.x = lbl_80564A6C;
        frame.s1.vB.y = lbl_805649FC;
        frame.s1.vB.z = lbl_80564A6C;
        frame.s1.vC.x = lbl_805649F0;
        frame.s1.vC.y = lbl_80564A70;
        frame.s1.vC.z = lbl_805649F0;
        frame.s1.field_34 = lbl_80564A74;
        frame.s1.field_60 = lbl_80564A78;
        frame.s1.field_68 = lbl_80564A78;
        frame.s1.field_70 = lbl_80564A78;
        frame.s1.field_64 = lbl_805649FC;
        frame.s1.field_6C = lbl_805649FC;
        frame.s1.field_74 = lbl_805649FC;
        frame.s1.field_58 = lbl_805649F0;
        frame.s1.field_5C = lbl_80564A7C;
        t31 = lbl_80564A68 * lbl_80564A68;
        t13 = lbl_80564A80 * (lbl_80564A70 / t31);
        t3 = lbl_805649F4 * t13 * t31;
        t2 = (lbl_80564A84 - t3) / lbl_80564A68;
        frame.s1.field_4C = t13;
        frame.s1.field_50 = t2;
        frame.s1.field_54 = lbl_80564A58;
        frame.s1.field_78 = lbl_805649F0;
        frame.s1.field_7C = lbl_80564A04;
        r29[0] = ((int (*)(void *, const void *, const void *))fn_8028E2F8)(&frame.s1, lbl_80349E24, lbl_80349E18);
        fn_8028E61C(&frame.s2);
        frame.s2.field_04 = 0x60;
        frame.s2.field_08 = lbl_805649F4;
        frame.s2.field_0C = lbl_805649FC;
        frame.s2.field_00 = two;
        frame.s2.field_48 = lbl_805649F4;
        frame.s2.field_44 = five;
        frame.v[0].x = lbl_805649F0;
        frame.v[0].y = lbl_805649F0;
        frame.v[0].z = lbl_805649F0;
        frame.s2.vA.x = lbl_805649F0;
        frame.s2.vA.y = lbl_805649F0;
        frame.s2.vA.z = lbl_805649F0;
        frame.v[1].x = lbl_805649FC;
        frame.v[1].y = lbl_805649FC;
        frame.v[1].z = lbl_805649FC;
        frame.s2.vB.x = lbl_805649FC;
        frame.s2.vB.y = lbl_805649FC;
        frame.s2.vB.z = lbl_805649FC;
        frame.s2.vC.x = lbl_805649F0;
        frame.s2.vC.y = lbl_80564A00;
        frame.s2.vC.z = lbl_805649F0;
        frame.s2.field_34 = lbl_80564A74;
        frame.s2.field_70 = lbl_80564A78;
        frame.s2.field_68 = lbl_80564A78;
        frame.s2.field_60 = lbl_80564A78;
        frame.s2.field_74 = lbl_80564A88;
        frame.s2.field_6C = lbl_80564A88;
        frame.s2.field_64 = lbl_80564A88;
        frame.s2.field_58 = lbl_80564A78;
        frame.s2.field_5C = lbl_80564A8C;
        frame.s2.field_50 = lbl_80564A8C;
        frame.s2.field_54 = lbl_80564A90;
        frame.s2.field_78 = lbl_80564A94;
        frame.s2.field_7C = lbl_805649FC;
        r29[1] = ((int (*)(void *, const void *, const void *))fn_8028E2F8)(&frame.s2, &lbl_8055CC80, lbl_80349E08);
    }
    lbl_8055F924 = r29;
    fn_8028E024();
}
#pragma pop
void fn_802ABC2C(void) {
    int *p = (int *)lbl_8055F924;
    if (p == 0) return;
    if (p != 0) {
        fn_8028E398(p[0]);
        fn_8028E398(p[1]);
        fn_80128668(p);
    }
    lbl_8055F924 = 0;
}

#pragma processor 750
void fn_802ABC80(void *arg0, void *arg1, float farg0, float farg1, float farg2) {
    extern float fn_80287BC8(float, float);
    extern void fn_8028E590(int, Vec *, Vec *, float);
    extern float lbl_80564A04, lbl_80564A48, lbl_80564A4C, lbl_805649F0, lbl_805649FC;
    extern void *lbl_8055F924;
    extern double cos(double), sin(double);
    Vec pos, callpos, dir, side, forward;
    float angle, scale;
    angle=fn_80287BC8(lbl_80564A48,lbl_80564A4C);
    forward=*(Vec*)arg0; side=*(Vec*)((char*)arg0+0x18); pos=*(Vec*)((char*)arg0+0x24);
    scale=farg0*(float)cos(angle);
    pos.x+=forward.x*scale; pos.y+=forward.y*scale; pos.z+=forward.z*scale;
    scale=farg1*(float)sin(angle);
    pos.x+=side.x*scale; pos.y+=side.y*scale; pos.z+=side.z*scale;
    scale=fn_80287BC8(lbl_805649F0,lbl_80564A04*farg2);
    pos.x+=((float*)((char*)arg0+0xC))[0]*scale;
    pos.y+=((float*)((char*)arg0+0xC))[1]*scale;
    pos.z+=((float*)((char*)arg0+0xC))[2]*scale;
    dir=*(Vec*)arg1;
    callpos=pos;
    fn_8028E590(*(int*)lbl_8055F924,&callpos,&dir,lbl_805649FC);
}

void fn_802ABE50(void) { fn_8028E240(0); }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802ABE58(volatile float *arg0, volatile float *arg1, int *arg2, float delta) {
    unsigned char green;
    unsigned char red;
    unsigned char blue;
    unsigned int color;
    unsigned low;
    float angle;
    float current;
    float magnitude;
    float wave;
    float angleValue;
    float result;
    int withinTolerance;
    int angleBelowLimit;
    int angleWithinLimit;
    int active;

    red = (unsigned char)((int (*)(int, int, int))fn_80129D90)(0, 0x8C, 0xFF);
    green = (unsigned char)((int (*)(int, int, int))fn_80129D90)(0, 0xFA, 0xFF);
    blue = (unsigned char)((int (*)(int, int, int))fn_80129D90)(0, 0xF0, 0xFF);
    color = ((unsigned int)blue & 0xFF) << 16;
    angle = lbl_80564A98;
    low = (((unsigned int)green & 0xFF) << 8) | ((unsigned int)red & 0xFF);
    color |= 0xFF000000;
    *arg2 = color | low;

    (void)*(volatile unsigned char *)&lbl_8055F92C;
    current = *arg0;
    if (current > lbl_805649F4)
        *arg0 = fn_80287BC8(lbl_80564A8C, lbl_80564A68);
    else
        *arg0 = current + lbl_80564A34 * delta;

    magnitude = (float)fabs(delta);
    wave = lbl_805649F0;
    withinTolerance = magnitude <= *(float *)(void *)&lbl_80558DC4;
    if ((unsigned short)withinTolerance == 0)
        wave = lbl_80564A9C * (float)(int)fn_80287BC8(lbl_805649F0, lbl_805649FC);

    angleBelowLimit = angle < lbl_80564A00;
    active = 1;
    if (angleBelowLimit != 0) {
        angleValue = (float)fn_8002EFB4(angle, lbl_80564AA0);
        angleWithinLimit = angleValue > lbl_80564A34;
        if (angleWithinLimit == 0)
            active = 0;
    }

    result = lbl_805649F0;
    if (active != 0)
        result = lbl_80564AA8 * *arg0 - wave;
    *arg1 = result;
}

void fn_802ABFF8(int arg0, float farg0) {
    lbl_8055F92D = fn_802C2C00(1);
    lbl_804BD7B0[0] = fn_802C990C(arg0);
    fn_802C2BB8(&lbl_804BD7B0[1], &lbl_804BD7B0[2], &lbl_804BD7B0[3]);
    fn_802C2B78(farg0, lbl_80564AAC + farg0, lbl_805649FC);
}

void fn_802AC070(void) {
    fn_802C990C(lbl_804BD7B0[0]);
    ((void (*)(void *, float, float, float))fn_802C2B78)((void *)lbl_804BD7B0, *(float *)&lbl_804BD7B0[1], *(float *)&lbl_804BD7B0[2], *(float *)&lbl_804BD7B0[3]);
    fn_802C2C00(lbl_8055F92D);
}
struct Obj802AAC80 { char pad[0xEC]; unsigned char flag; float value; };
struct Ctrl802AAC80 { char pad[0x68]; unsigned int flags; char pad2[0xAC]; unsigned char flag; };
extern float lbl_805649F4, lbl_80564A34, lbl_80564A68, lbl_80564A8C, lbl_80564A98, lbl_80564A9C, lbl_80564AA8;
extern double lbl_80564AA0;
extern unsigned char lbl_8055F92C;
unsigned char fn_80129D90(int, int, int);
float fn_80287BC8(float, float);
double fn_8002EFB4(float, double);
