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

/* The handle block the UI stun-part effect keeps: an 8-byte block allocated
 * under the name "uistuntpart", holding the two "partman" particle systems
 * fn_8028E2F8 made for it (global lbl_8055F924). */
typedef struct {
    int spark;     /* "invcblespark", drawn with spark.tex */
    int entryPuff; /* the entry puff, drawn with entrypuff.tex */
} UiStunParts;

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
extern void Event_RegisterHandler(void *, int);
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

s32 fn_802A9F90(s32 *args) {
    extern int lbl_8055F928;
    /* Mark the trail-state record for entry args[0] active (byte 0xDC). */
    ((UnkAA9D4 *)(lbl_8055F928 + (*args * 0x108)))->active = 1;
    return 4;
}

#pragma opt_propagation off
/* Trail-state callback (registered with id 0x11): args[0] selects a 0x108-byte
 * per-entry record in lbl_8055F928; set that record's flag byte at 0xEC and copy
 * the low byte of args[1] into its byte at 0xF4. Returns 8 bytes of args consumed. */
s32 fn_802A9FB0(void *args) {
    extern int lbl_8055F928;
    unsigned char value = *((unsigned char *)args + 4);
    int blockOffset = *(int *)args * 0x108;
    register unsigned char one = 1;
    *(unsigned char *)(lbl_8055F928 + blockOffset + (s32)0xEC) = one;
    *(unsigned char *)(lbl_8055F928 + blockOffset + (unsigned)0xF4) = value;
    return 8;
}
#pragma opt_propagation reset
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
/* Reset the trail-state block (0xDC..0xE8) of a per-object effect entry: clear
 * the active byte at 0xDC, zero the amount at 0xE0, seed the phase at 0xE4 with
 * 0.5, and set the color word at 0xE8 to -1. */
void fn_802AA0C8(void *entry) {
    extern float lbl_805649F0;
    extern float lbl_805649F4;
    float initialPhase;
    float initialAmount;
    initialAmount = lbl_805649F0;
    initialPhase = lbl_805649F4;
    *(unsigned char *)((char *)entry + 0xDC) = 0;
    *(float *)((char *)entry + 0xE0) = initialAmount;
    *(float *)((char *)entry + 0xE4) = initialPhase;
    *(int *)((char *)entry + 0xE8) = -1;
}
#pragma scheduling on
void fn_802AA0EC(void *entry) {
    extern float lbl_805649F0;
    float value = lbl_805649F0;
    /* Reset the stun-part entry: clear the flag at +0xEC and zero its
     * accumulated value at +0xF0 (lbl_805649F0 is 0.0f). */
    *(unsigned char *)((char *)entry + 0xEC) = 0;
    *(float *)((char *)entry + 0xF0) = value;
}

extern float PSVECDotProduct(const void *, const void *);
#pragma push
#pragma processor 750
#pragma opt_propagation off
/* Reconstruct a vector from its projections onto two basis vectors: out = basis0*(vec·basis0) + basis1*(vec·basis1). */ void fn_802AA100(void *out, void *vec, void *basis0, void *basis1) {
    float term0[3];
    float term1[3];
    float dot0;
    float dot1;

    dot0 = PSVECDotProduct(vec, basis0);
    dot1 = PSVECDotProduct(vec, basis1);
    term0[0] = ((float *)basis0)[0] * dot0;
    term0[1] = ((float *)basis0)[1] * dot0;
    term0[2] = ((float *)basis0)[2] * dot0;
    term1[0] = ((float *)basis1)[0] * dot1;
    term1[1] = ((float *)basis1)[1] * dot1;
    term1[2] = ((float *)basis1)[2] * dot1;
    ((float *)out)[0] = term0[0] + term1[0];
    ((float *)out)[1] = term0[1] + term1[1];
    ((float *)out)[2] = term0[2] + term1[2];
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
    float temp_f26, temp_f27, temp_f31;
    long var_r25, var_r28, var_r31;
    float *var_r26, *var_r27;
    void *temp_r25;
    float var_f29;
    *(float *)((char *)arg0 + 0xC0) = (float)fn_8002EFB4(*(float *)((char *)arg0 + 0xC0) + (lbl_80564A08 * farg0), lbl_80564A10);
    if (*(float *)((char *)arg0 + 0xD4) >= lbl_80564A18 && *(float *)((char *)arg0 + 0xD8) == lbl_805649F0 && *(unsigned char *)((char *)arg0 + 0xC4) != 0) {
        float var_f4;
        float var_f3;
        *(unsigned char *)((char *)arg0 + 0xC4) = 0;
        var_f4 = *(float *)((char *)arg0 + 0xC8) + (lbl_80564A04 * farg0);
        if (var_f4 >= lbl_805649FC) var_f4 = lbl_805649FC;
        var_f3 = lbl_805649FC;
        *(float *)((char *)arg0 + 0xC8) = var_f4;
        if (var_f3 >= (*(float *)((char *)arg0 + 0xD4) - lbl_80564A18) / lbl_80564A1C) var_f3 = (*(float *)((char *)arg0 + 0xD4) - lbl_80564A18) / lbl_80564A1C;
        if (var_f3 <= lbl_805649F0) var_f3 = lbl_805649F0;
        *(float *)((char *)arg0 + 0xCC) = lbl_805649F0 + (var_f3 * (var_f4 - lbl_805649F0));
    } else {
        float var_f3_2;
        float var_f1;
        var_f3_2 = *(float *)((char *)arg0 + 0xC8) - (lbl_80564A20 * farg0);
        if (var_f3_2 <= lbl_805649F0) var_f3_2 = lbl_805649F0;
        *(float *)((char *)arg0 + 0xC8) = var_f3_2;
        var_f1 = *(float *)((char *)arg0 + 0xCC) - (lbl_80564A20 * farg0);
        if (var_f1 <= lbl_805649F0) var_f1 = lbl_805649F0;
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
        sp80 = bx;
        sp84 = by;
        sp88 = bz;
        sp8C = *(float *)((char *)arg1 + 0x124);
        sp90 = by;
        sp94 = *(float *)((char *)arg1 + 0x12C);
        if (&sp80 == &sp80) {
            float rx = sp88 * m[6] + (sp80 * m[0] + sp84 * m[3]);
            float ry = sp88 * m[7] + (sp80 * m[1] + sp84 * m[4]);
            float rz = sp88 * m[8] + (sp80 * m[2] + sp84 * m[5]);
            sp80 = rx;
            sp84 = ry;
            sp88 = rz;
        } else {
            sp80 = m[6] * sp88 + (m[0] * sp80 + m[3] * sp84);
            sp84 = m[7] * sp88 + (m[4] * sp80 + m[5] * sp84);
            sp88 = m[8] * sp88 + (m[2] * sp80 + m[5] * sp84);
        }
        if (&sp8C == &sp8C) {
            float rx = sp94 * m[6] + (sp8C * m[0] + sp90 * m[3]);
            float ry = sp94 * m[7] + (sp8C * m[1] + sp90 * m[4]);
            float rz = sp94 * m[8] + (sp8C * m[2] + sp90 * m[5]);
            sp8C = rx;
            sp90 = ry;
            sp94 = rz;
        } else {
            sp8C = m[6] * sp94 + (m[0] * sp8C + m[3] * sp90);
            sp90 = m[7] * sp94 + (m[1] * sp8C + m[4] * sp90);
            sp94 = m[8] * sp94 + (m[2] * sp8C + m[5] * sp90);
        }
        fn_802AA100(&v5C, (char *)arg1 + 0x40, arg1, (char *)arg1 + 0x18);
        if (PSVECDotProduct(&v5C, &v5C) > lbl_80564A28) {
            float dot;
            float var_f0;
            PSVECNormalize(&v5C, &v5C);
            dot = PSVECDotProduct(&v5C, (char *)arg1 + 0x18);
            var_f0 = lbl_805649F0;
            if (var_f0 <= dot) var_f0 = dot;
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
                float temp_f29 = (float)fabs(farg0);
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
                        sp8 = *(long *)((char *)arg1 + 0x34);
                        spC = *(long *)((char *)arg1 + 0x38);
                        sp10 = *(long *)((char *)arg1 + 0x3C);
                        sp14 = sp20;
                        sp18 = sp24;
                        sp1C = sp28;
                        fn_8028E584(*(long *)((char *)lbl_8055F924 + 4), &sp14, &sp8, sp24, sp20, *(long *)((char *)arg1 + 0x3C), *(long *)((char *)arg1 + 0x38), *(long *)((char *)arg1 + 0x34), c4, c6, *(float *)((char *)arg1 + 0xC) * temp_f26, c4, c5, c6, b4, b8);
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
#pragma pop

#pragma push
#pragma processor 750
void fn_802AA9D4(UnkAA9D4 *arg0, void *arg1, float delta) {
    extern float lbl_805649F4, lbl_80564A08, lbl_80564A04, lbl_80564A48, lbl_80564A4C, lbl_80564A50;
    extern float fn_80287BC8(float, float);
    extern void fn_8028E590(int, Vec *, Vec *, float);
    /* Per-frame emitter update: ramp the emission amount toward 0 or 1 at
     * 8.0/sec (clamped), then, while the amount is above a random threshold,
     * place the emitter in the object's local space (forward*halfWidth,
     * side*halfDepth, up*randomHeight) and dispatch an emission at that point. */
    Vec pos, dir, callpos, calldir, side, forward;
    float width = lbl_805649F4 * arg0->width;
    float depth = lbl_805649F4 * arg0->depth;
    float height = lbl_805649F4 * arg0->height;
    float v, angle, scale;

    if (arg0->active) {
        float stp;
        v = arg0->amount;
        stp = lbl_80564A08 * delta;
        arg0->active = 0;
        arg0->amount = (v += stp) < 1.0f ? v : 1.0f;
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
#pragma fp_relaxed on
void fn_802AAD5C(int arg0, int arg1, int arg2) {
    extern void fn_802C8BD0(int);
    extern void fn_801E866C(int);
    extern void fn_802C8DBC(int);
    extern void fn_802C8E00(unsigned int, int, float, float, float, float, float);
    extern void fn_802C8E48(void);
    extern void fn_802C8D74(void);
    extern int lbl_8055CC60, lbl_8055CC70, lbl_8055CC74, lbl_8055CC78;
    extern const double lbl_80564A40;
    extern float lbl_8055CC6C, lbl_805649F0, lbl_805649F4, lbl_805649FC, lbl_80564A24, lbl_80564A30, lbl_80564A54;
    union { double value; unsigned int words[2]; } conv;
    float *arg;
    volatile float sp10, spC, sp8;
    float temp_f2, temp_f0, temp_f4;
    float temp_f31, temp_f30, temp_f29, temp_f28, temp_f27;
    double temp_f26;
    int i, n, alpha, color;
    fn_802C8BD0(lbl_8055CC60);
    fn_801E866C(-1);
    if (*(float *)((char *)arg1 + 0xCC) > lbl_80564A24) {
        fn_802C8DBC(0x10);
        temp_f31 = *(float *)((char *)arg1 + 0xC0);
        temp_f26 = lbl_80564A40;
        temp_f27 = lbl_80564A30;
        temp_f28 = lbl_80564A54;
        temp_f29 = lbl_805649F0;
        temp_f30 = lbl_805649F4;
        arg = (float *)arg1;
        for (i = 0; i < 0x10; i++, arg += 3) {
            const float *position = arg;
            float x = position[0];
            float y = position[1];
            float z = position[2];
            n = 0;
            sp8 = x;
            spC = y;
            sp10 = z;
            if (i > 1) n = (0x10 - (i + 1)) / 2;
            conv.words[0] = 0x43300000;
            conv.words[1] = (unsigned int)n ^ 0x80000000;
            temp_f2 = (float)(conv.value - temp_f26) * temp_f27;
            temp_f0 = lbl_8055CC6C * (temp_f2 * (temp_f28 * (*(float *)((char *)arg1 + 0xCC) * *(float *)((char *)arg1 + 0xD0))));
            if (temp_f0 < temp_f29) temp_f0 -= temp_f30;
            else temp_f0 = temp_f30 + temp_f0;
            alpha = (int)temp_f0;
            color = ((unsigned char)lbl_8055CC74 << 24) | ((unsigned char)lbl_8055CC70 << 16) | ((unsigned char)lbl_8055CC78 << 8) | ((unsigned char)alpha);
            temp_f4 = (i % 2) ? lbl_805649F0 : lbl_805649FC;
            fn_802C8E00(color, 1, sp8, spC, sp10, temp_f4, temp_f31 - temp_f2);
        }
        fn_802C8E48();
    }
    fn_802C8D74();
}
#pragma pop
/* Reserved draw step in the stunt-car effect pass: receives the draw list, a
   per-object effect entry and the source object, but does nothing in this build. */
void fn_802AAF00(int drawList, int entry, int object) {}

extern int lbl_8055CC64;
extern float lbl_805649F0, lbl_805649F4, lbl_805649F8, lbl_805649FC;
extern float lbl_80564A20, lbl_80564A34, lbl_80564A4C, lbl_80564A54;
extern float lbl_80564A58, lbl_80564A5C, lbl_80564A60, lbl_80564A64;
extern __declspec(section ".sdata2") const double lbl_80564A40;
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
    unsigned int color;
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
                var_f1 = lbl_805649F0;
            } else {
                var_f1 = lbl_80564A4C;
            }
            var_f21 = var_f1 + (temp_f18 + (temp_f17 * ((temp_f14 - temp_f31) / temp_f16)));
            if (*(unsigned char *)(obj + 0xF4) != 0) {
                var_f21 *= temp_f19;
            }
            temp_f2 = (float)cos(var_f21);
            temp_f21 = *(float *)(obj + 0xFC) * temp_f2 * temp_f24;
            temp_f6 = *(float *)(obj + 0xFC) * (float)sin(var_f21) * temp_f24;
            var_r29 = frame.sp8;
            temp_f21_2 = (float)sp58 + (temp_f20 * temp_f21) + ((float)sp80 * temp_f6);
            temp_f22 = (float)sp68 + ((float)sp60 * temp_f21) + ((float)sp88 * temp_f6);
            temp_f23 = (float)sp78 + ((float)sp70 * temp_f21) + ((float)sp90 * temp_f6);
            temp_f14 *= (float)sp98;
            var_r26 = 0;
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
            color = ((int)var_f0 << 0x18) | 0xFF0000 | 0xFFFF;
            if (var_r26 != 0) {
                var_f4 = lbl_805649FC;
            } else {
                var_f4 = lbl_805649F0;
            }
            fn_802C8E00(color, 1, var_r29[0], var_r29[1], var_r29[2], var_f4, temp_f31 - temp_f14);
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
    const StuntStrings * const base = (const StuntStrings *)lbl_80349DC8;
    void *buffer;
    int *r29;
    register int two;
    register int five;
    float t13;
    float t31;
    buffer = fn_8012850C(0x850, (const char *)base);
    lbl_8055F928 = (int)fn_8002F37C(buffer, fn_802AB500, 0, 0x108, 8);
    r29 = (int *)fn_801284F8(8, base->name2);
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
        t31 = frame.s1.field_08 * frame.s1.field_08;
        t13 = lbl_80564A80 * (frame.s1.vC.y / t31);
        frame.s1.field_4C = t13;
        t13 = frame.s1.field_48 * t13;
        frame.s1.field_50 = (lbl_80564A84 - t13 * t31) / frame.s1.field_08;
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
    Event_RegisterHandler(fn_802A9F30, 0xF);
    Event_RegisterHandler(fn_802A9F90, 0x10);
    Event_RegisterHandler(fn_802A9FB0, 0x11);
    *(char *)&lbl_8055F92C = (*(int *)((char *)fn_801E87A8() + 4) == 0x180304);
}
#pragma pop

#pragma scheduling on
#pragma pop
/* No-op element constructor passed to fn_8002F37C when building the array of 8
 * per-object effect-state entries at lbl_8055F928 (0x108 bytes each). */
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
/* Initialize all 8 entries in the per-object effect state table (0x108 bytes each). */
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
void fn_802AB6D0(void) {
    /* Intentionally empty reset callback in the stunt-car effect system: does no work. */
}

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

#pragma opt_lifetimes off
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
    int obj;
    unsigned char green;
    unsigned char red;
    unsigned char blue;
    float delta;
    float angle;
    float wave;
    float angleValue;
    float result;
    int angleBelowLimit;
    int angleWithinLimit;
    int active;
    obj = fn_80287B24(arg0);
    delta = fn_801E7E24();
    if (!((float)__fabs(delta) <= *(float *)(void *)&lbl_80558DC4)) {
        red = (unsigned char)((int (*)(int, int, int))fn_80129D90)(0, 0x8C, 0xFF);
        green = (unsigned char)((int (*)(int, int, int))fn_80129D90)(0, 0xFA, 0xFF);
        blue = (unsigned char)((int (*)(int, int, int))fn_80129D90)(0, 0xF0, 0xFF);
        *(int *)(state + 0xE8) = (int)(0xFF000000u | ((unsigned int)blue << 16) | ((unsigned int)green << 8) | (unsigned int)red);
    }
    angle = *(float *)((char *)obj + 0x4C);
    if (lbl_8055F92C != 0) angle = lbl_80564A98;
    if (*(float *)(state + 0xE4) > lbl_805649F4)
        *(float *)(state + 0xE4) = fn_80287BC8(lbl_80564A8C, lbl_80564A68);
    else
        *(float *)(state + 0xE4) += lbl_80564A34 * delta;
    wave = lbl_805649F0;
    if (!((float)__fabs(delta) <= *(float *)(void *)&lbl_80558DC4))
        wave = lbl_80564A9C * (float)(int)fn_80287BC8(wave, lbl_805649FC);
    angleBelowLimit = angle < lbl_80564A00;
    active = 1;
    if (angleBelowLimit != 0) {
        angleValue = (float)fn_8002EFB4(angle, lbl_80564AA0);
        angleWithinLimit = angleValue > lbl_80564A34;
        if (angleWithinLimit == 0)
            active = 0;
    }
    result = lbl_805649F0;
    if (active != 0) result = lbl_80564AA8 * *(float *)(state + 0xE4) - wave;
    obj = *(int *)(state + 0xE8);
    lbl_8055F92D = fn_802C2C00(1);
    lbl_804BD7B0[0] = fn_802C990C(obj);
    fn_802C2BB8(&lbl_804BD7B0[1], &lbl_804BD7B0[2], &lbl_804BD7B0[3]);
    fn_802C2B78(result, lbl_80564AAC + result, lbl_805649FC);
}
#pragma opt_lifetimes reset
// Restore the draw state saved by fn_802AB770: model colour,
// global scale parameters, and the global-scale-on flag.
void fn_802AB994(void) {
    fn_802C990C(lbl_804BD7B0[0]);
    ((void (*)(void *, float, float, float))fn_802C2B78)((void *)lbl_804BD7B0, *(float *)&lbl_804BD7B0[1], *(float *)&lbl_804BD7B0[2], *(float *)&lbl_804BD7B0[3]);
    fn_802C2C00(lbl_8055F92D);
}

/* Alias of fn_8028E070: record the given particle time in lbl_8055F738 and set
   the particle-add flag lbl_8055F73C (called by fn_80255D3C). */
void fn_802AB9E0(float time) { fn_8028E070(time); }

/* End a particle/effect update pass: advance every effect in the primary list
 * by the frame time and disallow further adds (delegates to fn_8028E080). */
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
/* Build the two "partman" particle emitters for the UI stun-part effect (the invincible-car
 * spark and the entry puff) from their tuning constants, register each with fn_8028E2F8,
 * and store the resulting handle pair in lbl_8055F924. */
void fn_802AB9E8(void) {
    struct {
        Vec v[4];
        InitStruct puffDef;
        InitStruct sparkDef;
    } defs;
    UiStunParts *parts;
    register int two;
    register int five;
    float t13;
    register float t31;
    float t3, t2;
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
    parts = (UiStunParts *)fn_801284F8(8, lbl_80349DFC);
    if (parts != NULL) {
        fn_8028E61C(&defs.sparkDef);
        two = 2;
        five = 5;
        defs.sparkDef.field_04 = 0x12C;
        defs.sparkDef.field_08 = lbl_80564A68;
        defs.sparkDef.field_0C = lbl_805649FC;
        defs.sparkDef.field_00 = two;
        defs.sparkDef.field_48 = lbl_805649F4;
        defs.sparkDef.field_44 = five;
        defs.v[2].x = lbl_805649F0;
        defs.v[2].y = lbl_805649FC;
        defs.v[2].z = lbl_805649F0;
        defs.sparkDef.vA.x = lbl_805649F0;
        defs.sparkDef.vA.y = lbl_805649FC;
        defs.sparkDef.vA.z = lbl_805649F0;
        defs.v[3].x = lbl_80564A6C;
        defs.v[3].y = lbl_805649FC;
        defs.v[3].z = lbl_80564A6C;
        defs.sparkDef.vB.x = lbl_80564A6C;
        defs.sparkDef.vB.y = lbl_805649FC;
        defs.sparkDef.vB.z = lbl_80564A6C;
        defs.sparkDef.vC.x = lbl_805649F0;
        defs.sparkDef.vC.y = lbl_80564A70;
        defs.sparkDef.vC.z = lbl_805649F0;
        defs.sparkDef.field_34 = lbl_80564A74;
        defs.sparkDef.field_60 = lbl_80564A78;
        defs.sparkDef.field_68 = lbl_80564A78;
        defs.sparkDef.field_70 = lbl_80564A78;
        defs.sparkDef.field_64 = lbl_805649FC;
        defs.sparkDef.field_6C = lbl_805649FC;
        defs.sparkDef.field_74 = lbl_805649FC;
        defs.sparkDef.field_58 = lbl_805649F0;
        defs.sparkDef.field_5C = lbl_80564A7C;
        t31 = lbl_80564A68 * lbl_80564A68;
        t13 = lbl_80564A80 * (lbl_80564A70 / t31);
        t3 = lbl_805649F4 * t13 * (lbl_80564A68 * lbl_80564A68);
        t2 = lbl_80564A84 - t3;
        t2 = t2 / lbl_80564A68;
        defs.sparkDef.field_4C = t13;
        defs.sparkDef.field_50 = t2;
        defs.sparkDef.field_54 = lbl_80564A58;
        defs.sparkDef.field_78 = lbl_805649F0;
        defs.sparkDef.field_7C = lbl_80564A04;
        parts->spark = ((int (*)(void *, const void *, const void *))fn_8028E2F8)(&defs.sparkDef, lbl_80349E24, lbl_80349E18);
        fn_8028E61C(&defs.puffDef);
        defs.puffDef.field_04 = 0x60;
        defs.puffDef.field_08 = lbl_805649F4;
        defs.puffDef.field_0C = lbl_805649FC;
        defs.puffDef.field_00 = two;
        defs.puffDef.field_48 = lbl_805649F4;
        defs.puffDef.field_44 = five;
        defs.v[0].x = lbl_805649F0;
        defs.v[0].y = lbl_805649F0;
        defs.v[0].z = lbl_805649F0;
        defs.puffDef.vA.x = lbl_805649F0;
        defs.puffDef.vA.y = lbl_805649F0;
        defs.puffDef.vA.z = lbl_805649F0;
        defs.v[1].x = lbl_805649FC;
        defs.v[1].y = lbl_805649FC;
        defs.v[1].z = lbl_805649FC;
        defs.puffDef.vB.x = lbl_805649FC;
        defs.puffDef.vB.y = lbl_805649FC;
        defs.puffDef.vB.z = lbl_805649FC;
        defs.puffDef.vC.x = lbl_805649F0;
        defs.puffDef.vC.y = lbl_80564A00;
        defs.puffDef.vC.z = lbl_805649F0;
        defs.puffDef.field_34 = lbl_80564A74;
        defs.puffDef.field_70 = lbl_80564A78;
        defs.puffDef.field_68 = lbl_80564A78;
        defs.puffDef.field_60 = lbl_80564A78;
        defs.puffDef.field_74 = lbl_80564A88;
        defs.puffDef.field_6C = lbl_80564A88;
        defs.puffDef.field_64 = lbl_80564A88;
        defs.puffDef.field_58 = lbl_80564A78;
        defs.puffDef.field_5C = lbl_80564A8C;
        defs.puffDef.field_50 = lbl_80564A8C;
        defs.puffDef.field_54 = lbl_80564A90;
        defs.puffDef.field_78 = lbl_80564A94;
        defs.puffDef.field_7C = lbl_805649FC;
        parts->entryPuff = ((int (*)(void *, const void *, const void *))fn_8028E2F8)(&defs.puffDef, &lbl_8055CC80, lbl_80349E08);
    }
    lbl_8055F924 = parts;
    fn_8028E024();
}
#pragma pop
/* Shutdown of the UI stun-part effect: destroy the two particle systems this
 * module created -- the invisible spark and the entry puff -- take them out of
 * the partman registries (fn_8028E398), free the handle block they were kept in
 * (fn_80128668) and clear the global.  The original tests the handle twice, so
 * both null checks stay. */
void fn_802ABC2C(void) {
    UiStunParts *parts = (UiStunParts *)lbl_8055F924;
    if (parts == 0) return;
    if (parts != 0) {
        fn_8028E398(parts->spark);
        fn_8028E398(parts->entryPuff);
        fn_80128668(parts);
    }
    lbl_8055F924 = 0;
}

#pragma processor 750
void fn_802ABC80(const void *object, const void *direction, float halfWidth, float halfDepth, float halfHeight) {
    extern float fn_80287BC8(float, float);
    extern void fn_8028E590(int, Vec *, Vec *, float);
    extern float lbl_80564A04, lbl_80564A48, lbl_80564A4C, lbl_805649F0, lbl_805649FC;
    extern void *lbl_8055F924;
    extern double cos(double), sin(double);
    Vec pos, callPos, dirVec, sideVec, forwardVec;
    float angle, scale;
    /* Emit one particle at a random point inside the object's local box
     * (forward*halfWidth, side*halfDepth, up*halfHeight) in the given direction. */
    angle = fn_80287BC8(lbl_80564A48, lbl_80564A4C);
    forwardVec = *(Vec *)object;
    sideVec = *(Vec *)((char *)object + 0x18);
    pos = *(Vec *)((char *)object + 0x24);
    scale = halfWidth * (float)cos(angle);
    pos.x += forwardVec.x * scale;
    pos.y += forwardVec.y * scale;
    pos.z += forwardVec.z * scale;
    scale = halfDepth * (float)sin(angle);
    pos.x += sideVec.x * scale;
    pos.y += sideVec.y * scale;
    pos.z += sideVec.z * scale;
    scale = fn_80287BC8(lbl_805649F0, lbl_80564A04 * halfHeight);
    pos.x += ((float *)((char *)object + 0xC))[0] * scale;
    pos.y += ((float *)((char *)object + 0xC))[1] * scale;
    pos.z += ((float *)((char *)object + 0xC))[2] * scale;
    dirVec = *(Vec *)direction;
    callPos = pos;
    fn_8028E590(*(int *)lbl_8055F924, &callPos, &dirVec, lbl_805649FC);
}

/* Draw the primary particle-emitter list (mode 0) via the particle draw routine. */
void fn_802ABE50(void) { fn_8028E240(0); }

#pragma scheduling invalid_target
void fn_802ABE58(volatile float *arg0, volatile float *arg1, int *arg2, float delta) {
    unsigned char green;
    unsigned char red;
    unsigned char blue;
    float angle;
    float dummy;
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
    angle = lbl_80564A98;
    *arg2 = (int)(0xFF000000u | ((unsigned int)blue << 16) | ((unsigned int)green << 8) | (unsigned int)red);

    if (*(volatile unsigned char *)&lbl_8055F92C == 0)
        dummy = angle;
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
/* Begin a tinted draw of the vehicle: stash the state fn_802AC070 has to put
 * back, then tint the model with `tint` (0xRRGGBB) and switch the global scale
 * on, ramping it from `scale` up to `scale` + 1000.0 at rate 1.0.
 *   savedDrawState[0]    model colour that was in effect
 *   savedDrawState[1..3] global scale (start, end, rate) in effect
 * The same slot is used by fn_802AB770 (the wave draw) and restored by
 * fn_802AC070, so only one tinted draw may be open at a time. */
void fn_802ABFF8(int tint, float scale) {
#define savedDrawState lbl_804BD7B0   /* the single restore slot, see fn_802AC070 */
#define savedScaleOn lbl_8055F92D     /* global-scale on/off flag that was set */
#define Scale_SetOn fn_802C2C00       /* turn the global scale on/off, old state */
#define Color_Set fn_802C990C         /* model colour, old colour */
#define Scale_Get fn_802C2BB8         /* reads back (start, end, rate) */
#define Scale_Set fn_802C2B78         /* sets (start, end, rate) */
#define TINT_SCALE_RANGE lbl_80564AAC /* 1000.0f: how far above scale it ramps */
#define TINT_SCALE_RATE lbl_805649FC  /* 1.0f */

    savedScaleOn = Scale_SetOn(1);
    savedDrawState[0] = Color_Set(tint);
    Scale_Get(&savedDrawState[1], &savedDrawState[2], &savedDrawState[3]);
    Scale_Set(scale, TINT_SCALE_RANGE + scale, TINT_SCALE_RATE);

#undef savedDrawState
#undef savedScaleOn
#undef Scale_SetOn
#undef Color_Set
#undef Scale_Get
#undef Scale_Set
#undef TINT_SCALE_RANGE
#undef TINT_SCALE_RATE
}

/* Restore the draw state saved by fn_802ABFF8/fn_802AB770: model colour,
 * global scale parameters, and the global-scale-on flag. */
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
