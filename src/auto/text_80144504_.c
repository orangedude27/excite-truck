// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

// This file's float constants, all in .sdata2 (read_data shows their values).
extern f32 lbl_805615B8;  //  1.0f
extern f32 lbl_805615BC;  //  0.0f
extern f32 lbl_805615C0;  //  0.5f
extern f32 lbl_805615C4;  //  3.0f
extern f32 lbl_805615C8;  // -1.0f
extern f32 lbl_805615CC;  // -2.0f

extern double cos(double);
extern double sin(double);
extern float fn_80144514(float, float, float, float, float, float);
#define D6(a, b, c, d, e, f) fn_80144514(a, b, c, d, e, f)
static f32 *volatile g_alias_probe;
#define M33CAT(a, b, ab)                                                   \
    { g_alias_probe = (ab);                                                \
    if (g_alias_probe == (b) || g_alias_probe == (a)) {                    \
        f32 t0 = D6((a)[0], (b)[0], (a)[3], (b)[1], (a)[6], (b)[2]);       \
        f32 t3 = D6((a)[0], (b)[3], (a)[3], (b)[4], (a)[6], (b)[5]);       \
        f32 t6 = D6((a)[0], (b)[6], (a)[3], (b)[7], (a)[6], (b)[8]);       \
        f32 t1 = D6((a)[1], (b)[0], (a)[4], (b)[1], (a)[7], (b)[2]);       \
        f32 t4 = D6((a)[1], (b)[3], (a)[4], (b)[4], (a)[7], (b)[5]);       \
        f32 t7 = D6((a)[1], (b)[6], (a)[4], (b)[7], (a)[7], (b)[8]);       \
        f32 t2 = D6((a)[2], (b)[0], (a)[5], (b)[1], (a)[8], (b)[2]);       \
        f32 t5 = D6((a)[2], (b)[3], (a)[5], (b)[4], (a)[8], (b)[5]);       \
        f32 t8 = D6((a)[2], (b)[6], (a)[5], (b)[7], (a)[8], (b)[8]);       \
        (ab)[0] = t0; (ab)[3] = t3; (ab)[6] = t6;                          \
        (ab)[1] = t1; (ab)[4] = t4; (ab)[7] = t7;                          \
        (ab)[2] = t2; (ab)[5] = t5; (ab)[8] = t8;                          \
    } else {                                                               \
        (ab)[0] = D6((a)[0], (b)[0], (a)[3], (b)[1], (a)[6], (b)[2]);      \
        (ab)[3] = D6((ab)[0], (b)[3], (a)[3], (b)[4], (a)[6], (b)[5]);     \
        (ab)[6] = D6((ab)[0], (b)[6], (ab)[3], (b)[7], (a)[6], (b)[8]);    \
        (ab)[1] = D6((a)[1], (b)[0], (a)[4], (b)[1], (a)[7], (b)[2]);      \
        (ab)[4] = D6((ab)[1], (b)[3], (a)[4], (b)[4], (a)[7], (b)[5]);     \
        (ab)[7] = D6((ab)[1], (b)[6], (ab)[4], (b)[7], (a)[7], (b)[8]);    \
        (ab)[2] = D6((a)[2], (b)[0], (a)[5], (b)[1], (a)[8], (b)[2]);      \
        (ab)[5] = D6((ab)[2], (b)[3], (a)[5], (b)[4], (a)[8], (b)[5]);     \
        (ab)[8] = D6((ab)[2], (b)[6], (ab)[5], (b)[7], (a)[8], (b)[8]);    \
    } }

static inline void M33Cat(f32 *a, f32 *b, f32 *ab) {
    M33CAT(a, b, ab)
}

extern void lbl_80336890(void);
void fn_80144504(void **object) {
    /* Install the base-class vtable at the head of an object during construction. */
    #define sBaseVtable lbl_80336890
    *object = (void *)&sBaseVtable;
    #undef sBaseVtable
}

/* Dot product of two 3D vectors: (ax,ay,az) . (bx,by,bz). */
float fn_80144514(float ax, float bx, float ay, float by, float az, float bz) {
    return (az * bz) + ((ax * bx) + (ay * by));
}

#pragma push
#pragma processor 750
void fn_8014452C(f32 *m, f32 ax, f32 ay, f32 az) {
    f32 b[9];
    f32 c, s;
    c = cos(ax);
    s = sin(ax);
    m[0] = c;
    m[1] = lbl_805615BC;
    m[3] = lbl_805615BC;
    m[2] = -s;
    m[4] = lbl_805615B8;
    m[5] = lbl_805615BC;
    m[6] = s;
    m[7] = lbl_805615BC;
    m[8] = c;
    c = cos(ay);
    s = sin(ay);
    b[1] = lbl_805615BC;
    b[0] = lbl_805615B8;
    b[2] = lbl_805615BC;
    b[3] = lbl_805615BC;
    b[4] = c;
    b[5] = s;
    b[6] = lbl_805615BC;
    b[7] = -s;
    b[8] = c;
    M33Cat(m, b, m);
    c = cos(az);
    s = sin(az);
    b[0] = c;
    b[1] = s;
    b[2] = lbl_805615BC;
    b[3] = -s;
    b[4] = c;
    b[5] = lbl_805615BC;
    b[6] = lbl_805615BC;
    b[7] = lbl_805615BC;
    b[8] = lbl_805615B8;
    M33Cat(m, b, m);
}
#pragma pop

void GXInitLightAttnA_80144B44(void *attn, f32 aa, f32 ab, f32 ac) {
    /* Store the three light distance-attenuation coefficients into a 12-byte
     * attenuation triple. */
    struct Attn {
        f32 aa;
        f32 ab;
        f32 ac;
    };
    ((struct Attn *)attn)->aa = aa;
    ((struct Attn *)attn)->ab = ab;
    ((struct Attn *)attn)->ac = ac;
}

#pragma push
#pragma scheduling full
void fn_80144B54(s32 *dst, s32 *src) {
    s32 l, k, j, i, h, g, f, e, d, c, b, a;
    volatile s32 *vs = src;
    d = vs[3]; c = vs[2]; b = vs[1]; a = vs[0];
    e = vs[4]; f = vs[5]; g = vs[6]; h = vs[7];
    i = vs[8]; j = vs[9]; k = vs[10]; l = vs[11];
    dst[0] = a; dst[1] = b; dst[2] = c; dst[3] = d;
    dst[4] = e; dst[5] = f; dst[6] = g; dst[7] = h;
    dst[8] = i; dst[9] = j; dst[10] = k; dst[11] = l;
}
#pragma pop
/* Odd smoothstep: clamps x to [-1,1] and returns sign(x) * (3x^2 - 2x^3), the
 * S-curve that eases a signed blend factor between -1 and 1.  Callers hand the
 * result to fn_80144C80(), which lerps between two values by it.
 * (The curve is built as x*(-2x^2) +/- 3x^2 so both halves share one shape.) */
f32 fn_80144BD8(f32 x) {
#define SM_MINUS_ONE lbl_805615C8 /* -1.0f: lower clamp */
#define SM_ONE       lbl_805615B8 /*  1.0f: upper clamp */
#define SM_ZERO      lbl_805615BC /*  0.0f: which half of the curve */
#define SM_THREE     lbl_805615C4 /*  3.0f */
#define SM_MINUS_TWO lbl_805615CC /* -2.0f */
    f32 sq, cu; /* 3x^2 and -2x^2, built up below */
    if (x < SM_MINUS_ONE) return SM_MINUS_ONE;
    if (x > SM_ONE) return SM_ONE;
    if (x > SM_ZERO) {
        sq = SM_THREE;
        cu = SM_MINUS_TWO;
        cu *= x;
        sq *= x;
        cu *= x;
        sq *= x;
        x *= cu;
        return x + sq;
    }
    sq = SM_THREE;
    cu = SM_MINUS_TWO;
    cu *= x;
    sq *= x;
    cu *= x;
    sq *= x;
    x *= cu;
    return x - sq;
#undef SM_MINUS_ONE
#undef SM_ONE
#undef SM_ZERO
#undef SM_THREE
#undef SM_MINUS_TWO
}

void fn_80144C54(void *voice) {
    // Set the sound voice's flag at +0x4A and clear the one at +0x4C.
    ((u8 *)voice)[0x4A] = 1;
    ((u8 *)voice)[0x4C] = 0;
}

unsigned int fn_80144C68(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha) {
    /* Pack four byte components into a 32-bit RGBA color word (red in the high byte, alpha in the low byte). */
    unsigned int low = (alpha & 0xFF) | ((blue << 8) & 0xFF00);
    unsigned int high = (red << 24) | ((green << 16) & 0xFF0000);
    return low | high;
}
#pragma scheduling invalid_target
#pragma scheduling on
/* Linear interpolation: blend from a to b by factor t (a + t*(b-a)). */
float fn_80144C80(float a, float b, float t) {
    return a + (t * (b - a));
}

extern f32 lbl_805615C0;
#pragma push
#pragma scheduling on
/* Round a float to the nearest integer, halves away from zero: bias by 0.5 in
 * the sign's direction, then truncate toward zero. */
s32 fn_80144C90(f32 value) {
    f32 rounded;
    if (value < 0.0f) {
        rounded = value - 0.5f;
    } else {
        rounded = 0.5f + value;
    }
    return (s32)rounded;
}
#pragma pop
/* Return the square of value. */
f32 fn_80144CC8(f32 value) {
    return value * value;
}

#pragma push
#pragma scheduling invalid_target
void fn_80144CD0(float *out, float *vec, float (*m)[4]) {
    float x = vec[0] - m[2][1];
    float y = vec[1] - m[2][2];
    float a0 = x * m[0][0];
    float b0 = y * m[0][1];
    float a1 = x * m[0][3];
    float b1 = y * m[1][0];
    float a2 = x * m[1][2];
    float b2 = y * m[1][3];
    float o0 = a0 + b0;
    float o1 = a1 + b1;
    float o2 = a2 + b2;
    float m5v = m[1][1];
    float z = vec[2] - m[2][3];
    float c1 = z * m5v;
    float c0 = z * m[0][2];
    float c2 = z * m[2][0];
    o1 += c1;
    o0 += c0;
    o2 += c2;
    out[1] = o1;
    out[0] = o0;
    out[2] = o2;
}
#pragma pop
/* Copy three consecutive s32 words from src to dst.  The source is read through
 * a volatile pointer into staged locals so all three loads precede any store. */
void fn_80144D64(s32 *dst, s32 *src) {
 s32 w2, w1, w0;
 volatile s32 *volatileSrc = src;
 w0 = volatileSrc[0]; w1 = volatileSrc[1]; w2 = volatileSrc[2];
 dst[0] = w0; dst[1] = w1; dst[2] = w2;
}

void fn_80144D80(f32 *out, f32 sx, f32 sy, f32 sz) {
    /* Build a 3x3 diagonal (scale) matrix: sx, sy, sz on the diagonal, zero elsewhere. */
    f32 zero = lbl_805615BC;
    out[0] = sx;
    out[1] = zero;
    out[2] = zero;
    out[3] = zero;
    out[4] = sy;
    out[5] = zero;
    out[6] = zero;
    out[7] = zero;
    out[8] = sz;
}

void fn_80144DAC(f32 *dst, f32 *src) {
    /* Copy a 3-component (12-byte) float vector from src into dst. */
    f32 z, y, x;
    x = src[0];
    y = src[1];
    z = src[2];
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

void fn_80144DC8(void) {
}

s32 fn_80144DCC(void) {
    /* Default no-op predicate: unconditionally returns FALSE (0). */
    return 0;
}

void fn_80144DD4(void) {
}

s32 fn_80144DD8(void) {
    /* Default no-op predicate: unconditionally returns FALSE (0). */
    return 0;
}

