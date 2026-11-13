// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long s32;
typedef float f32;
typedef struct V3A70E4 { f32 x, y, z; } V3A70E4;
extern f32 PSQUATMultiply(void *, void *);
extern f32 PSVECDotProduct(f32 *, f32 *);
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern f32 PSVECMag(f32 *);
extern s32 fn_80287B5C(s32);
extern f32 fn_80287BC8(f32, f32);
extern s32 fn_8028E584(s32, f32 *, f32 *, f32, f32);
extern void fn_802C8BD0(s32);
extern s32 fn_802CE860(s32);
extern void fn_802CE868(void);
extern void fn_802CE86C(void *, s32, f32, double, double, double);
extern f32 lbl_805648D8;
extern f32 lbl_80564860;
extern s32 fn_801E85B4(void);
extern int fn_802C86DC(void);
extern void fn_802C744C(s32, f32 *);
extern void fn_802C9900(f32);
extern void fn_802C9904(void);
extern double cos(double), sin(double);
extern double fn_8002F234(double);
extern f32 lbl_80564858, lbl_8056485C, lbl_80564878;
extern f32 lbl_8056487C, lbl_80564880, lbl_80564884, lbl_80564864;
extern s32 lbl_8055F88C;
extern char lbl_80349C88[];
extern s32 fn_801284F8(s32, char *);
extern s32 fn_802A6944(s32, s32, s32);
extern s32 fn_8012850C();
extern s32 fn_8002F37C(s32, void *, s32, s32, s32);
extern void fn_8001BA68(void);
extern char lbl_80349CAC[];
extern s32 lbl_8055CBC0;
extern char lbl_80349CA0[];
extern s32 lbl_8055CBB8, lbl_8055CBBC;
typedef union { double d; struct { f32 x, z; }; } Vec2_802A775C;
typedef struct {
    void *points;
    s32 count;
    s32 unk8;
    f32 posX;
    f32 posY;
    f32 posZ;
    f32 radius;
    f32 unk1C;
    f32 dirX;
    f32 dirY;
    f32 dirZ;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    f32 unk38;
    f32 unk3C;
} Obj802A775C;
void fn_802C2C00(s32);
void *fn_801E1F44(void);
void fn_802C2C00(s32);
s32 fn_802C990C(s32);
s32 fn_802C2B78(f32, f32, f32);
f32 fn_802A4A50(void);
void fn_802A6A7C();
void fn_802A6E34(void *);
void fn_802A6F70(void *, void *);
void fn_802A71C4(void *);
s32 fn_802A711C(void *, f32, f32, f32);
void fn_802A5CA4();
void fn_802A5A38(void);
void fn_802A6790(void *);
extern s32 lbl_8055F888;
extern s32 lbl_8055F88C;
extern f32 lbl_8055F8A0;
s32 fn_802A6A44(s32 *);
void fn_802A5C1C();
void fn_802A59E0(void);
extern s32 lbl_804BCFA8[];
extern s32 lbl_8055F890;
s32 fn_802A7680(s32);
extern s32 lbl_8055F894, lbl_8055F898, lbl_8055F89C;
extern u8 lbl_80349BF0[], lbl_8055CBC8;
s32 fn_802C6CF8(void);
s32 fn_802CAC54(s32);
extern s32 fn_80128670(s32);
extern s32 fn_80128668(void *);
s32 fn_802A597C(void);
s32 fn_8028E398(void);
s32 fn_802A5B8C();
void *fn_802A69D8(void *, s32);
s32 fn_800167F4(void);
s32 fn_802A5384(s32);
void fn_802A53B0(void *, s32);
s32 fn_80287B38(void *);
s32 fn_802A5878(void);
s32 fn_802CAC28(void *, s32);
void *fn_802AE414(void *);
s32 fn_802C6FC0(void *, s32, s32);
s32 fn_800216F4(void);
f32 fn_801E7E24(void);
s32 fn_802E2C20(void);
extern s32 lbl_8055F8A4;
extern f32 lbl_80564840, lbl_80564844;
extern f32 lbl_80564850, lbl_80564858, lbl_8056485C, lbl_80564888;
void fn_802A6234();
void fn_802A70E4(void *, f32 *);
f32 fn_80129DC4(s32, f32, f32);
extern f32 lbl_80564894, lbl_80564898, lbl_805648AC, lbl_805648B0;
extern void fn_801E8C84(f32 *);
extern float fn_802C9A50(void);
static inline void Mtx33MultVec_802A6470(const f32 *m, const f32 *src, f32 *dst) {
    if (src == dst) {
        f32 x = src[0], y = src[1], z = src[2];
        f32 o0 = z * m[2] + (x * m[0] + y * m[1]);
        f32 o1 = z * m[5] + (x * m[3] + y * m[4]);
        f32 o2 = z * m[8] + (x * m[6] + y * m[7]);
        dst[0] = o0; dst[1] = o1; dst[2] = o2;
    } else {
        f32 x = src[0], y = src[1], z = src[2];
        x = z * m[2] + (x * m[0] + y * m[1]);
        dst[0] = x;
        y = z * m[5] + (x * m[3] + y * m[4]);
        dst[1] = y;
        dst[2] = z * m[8] + (x * m[6] + y * m[7]);
    }
}
static inline void VecMtxMult_802A53B0(const f32 *m, const f32 *src, f32 *dst) {
    if (src == dst) {
        f32 x = src[0], y = src[1], z = src[2];
        f32 y3 = y * m[3];
        f32 y4 = y * m[4];
        f32 x0 = x * m[0];
        f32 x1 = x * m[1];
        f32 x2 = x * m[2];
        f32 y5 = y * m[5];
        f32 s0 = x0 + y3;
        f32 s1 = x1 + y4;
        f32 s2 = x2 + y5;
        f32 o0 = z * m[6] + s0;
        f32 o1 = z * m[7] + s1;
        f32 o2 = z * m[8] + s2;
        dst[0] = o0; dst[1] = o1; dst[2] = o2;
    } else {
        dst[0] = src[2] * m[6] + (src[0] * m[0] + src[1] * m[3]);
        dst[1] = src[2] * m[7] + (src[0] * m[1] + src[1] * m[4]);
        dst[2] = src[2] * m[8] + (src[0] * m[2] + src[1] * m[5]);
    }
}
extern f32 __fabsf(f32);
extern char lbl_80558DC4[];
extern f32 lbl_80564854;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
void fn_802A5A90(void);
void fn_802A6D68(void *);
void fn_802D3D50(void);
void fn_802A5FE4(void *);
void *fn_801E7E34(void);
extern float fn_802C9A4C(float);
extern void fn_802C8B98(int, int);
extern int fn_801E501C(int, void *, float, int);
extern void fn_801E5174(void *, float, float, float);
extern void fn_801E5348(void);
extern void fn_802C8D74(void);
extern f32 lbl_8055F880;
extern f32 lbl_80564884;
extern f32 lbl_80564890;
extern double lbl_80564848;
typedef struct { f32 *pts; s32 count; s32 pad8; s32 unkC; s32 unk10; f32 x14; f32 y18; char pad1C[0x28]; f32 vec[3]; } Obj802A5FE4;
s32 fn_802C90F0(s32);
void fn_802C9118(void);
void fn_802C9124(s32, s32, f32, f32, u32, f32, f32, f32, f32);

/* Return frame delta time in seconds: when the timer mode flag is set, use the millisecond timer delta capped at 0.05s, otherwise return the fixed timestep. */
f32 fn_802A4A50(void) {
    f32 clampedDelta;
    s32 nowMs;
    s32 deltaMs;
    if (fn_800216F4() != 0) {
        nowMs = fn_802E2C20();
        deltaMs = nowMs - lbl_8055F8A4;
        clampedDelta = lbl_80564844;
        lbl_8055F8A4 = nowMs;
        if ((f32)deltaMs / lbl_80564840 < clampedDelta)
            return (f32)deltaMs / lbl_80564840;
        return clampedDelta;
    }
    return fn_801E7E24();
}

f32 fn_802A4AD4(void) {
    return lbl_8055F8A0;
}

#pragma cplusplus on
extern "C" void fn_802A4ADC(void) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual s32 f4(void *, void *);
    };
    u8 *base = lbl_80349BF0;
    {
        s32 result = (s32)fn_801E1F44();
        if (fn_800167F4() == 1) fn_802A5384(result);
        fn_80287B38((void *)fn_802A53B0);
        fn_802A5878();
        lbl_8055F89C = fn_802CAC28((char *)base + 0x28, 0);
        result = (s32)((char *)base + 0x38);
        {
            struct Dummy *p = (struct Dummy *)fn_802AE414(&lbl_8055CBC8);
            if (p != 0) result = p->f4((void *)((char *)base + 0x48), (void *)result);
        }
        lbl_8055F898 = fn_802C6FC0((void *)result, 0, 0);
    }
}
#pragma cplusplus reset
void fn_802A4B90(void) {
    /* Release tracked resources/handles and reset their globals to inactive sentinels. */
    s32 resource;
    resource = lbl_8055F898;
    if (resource != -1) { ((s32 (*)(s32))fn_802C6CF8)(resource); lbl_8055F898 = -1; }
    fn_802CAC54(lbl_8055F89C);
    fn_802A597C();
    resource = lbl_8055F894;
    if (resource != 0) { ((s32 (*)(s32))fn_8028E398)(resource); lbl_8055F894 = 0; }
    resource = lbl_8055F888;
    if (resource != 0) { ((void (*)(s32, s32))fn_802A5B8C)(resource, 1); lbl_8055F888 = 0; }
    resource = lbl_8055F88C;
    if (resource != 0) { fn_802A69D8((void *)resource, 1); lbl_8055F88C = 0; }
}

void fn_802A4C20(void) {
    if (lbl_8055F88C != 0) fn_802A6A44((s32 *)lbl_8055F88C);
    if (lbl_8055F888 != 0) ((void (*)(void *))fn_802A5C1C)((void *)lbl_8055F888);
    fn_802A59E0();
}

#pragma dont_inline on
void fn_802A4C60(void) {
    lbl_8055F8A0 = fn_802A4A50();
    if (lbl_8055F88C != 0) fn_802A6A7C(lbl_8055F88C);
    if (lbl_8055F888 != 0) fn_802A5CA4(lbl_8055F888);
    fn_802A5A38();
}
#pragma dont_inline reset
void fn_802A4CA8(void) {
    u8 *p = (u8 *)fn_801E1F44();
    if (p[0x18] != 0) {
        fn_802C2C00(1);
        fn_802C990C(*(s32 *)(p + 8));
        fn_802C2B78(*(f32 *)(p + 0xC), *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    }
}

void fn_802A4D00(void) { fn_802C2C00(0); }

#pragma scheduling invalid_target
/* Draws the active overlay/hint UI each frame, using state flags and fade amount. */
void fn_802A4D08(void) {
    u8 *state = (u8 *)fn_801E1F44();
    s32 selectedFlag;
    f32 fadeValue;
    s32 scaledAlpha;
    s32 nonnegativeAlpha;
    s32 alpha;

    fn_802A5A90();
    if (state[0x18] != 0)
        fn_802D3D50();

    selectedFlag = lbl_8055F88C;
    if (selectedFlag != 0) {
        fn_802A6D68((void *)selectedFlag);
    } else {
        selectedFlag = lbl_8055F888;
        if (selectedFlag != 0)
            ((void (*)(s32))fn_802A5FE4)(selectedFlag);
    }

    fadeValue = *(f32 *)((u8 *)fn_801E7E34() + 0xDC);
    if (!((f32)__fabs((double)fadeValue) <= *(f32 *)(void *)&lbl_80558DC4)) {
        scaledAlpha = (s32)(lbl_80564850 * (lbl_80564854 * fadeValue));
        nonnegativeAlpha = scaledAlpha & ((-scaledAlpha & ~scaledAlpha) >> 31);
        alpha = 0xFF;
        if (nonnegativeAlpha < 0xFF)
            alpha = nonnegativeAlpha;

        fn_802C90F0(lbl_8055F89C);
        ((void (*)(f32, f32, f32, f32, s32, s32, s32, s32, s32))fn_802C9124)(
            lbl_80564858, lbl_80564858, lbl_8056485C, lbl_8056485C,
            0, 0, lbl_8055CFF0, lbl_8055CFF4,
            (alpha << 24) | 0x00FFFFFF);
        fn_802C9118();
    }
}

/* One 0xE0-byte weather entry in the array owned by the weather object
 * (fn_801E7E34() = the object, fn_801E85B4() = the entry being drawn).
 * Only the snow fields this file reads are named. */
typedef struct SnowLayer {
    u8 pad_00[0xD8];
    f32 modelFade; /* +0xD8 snow model fade-in, 0..1 */
    f32 quadAlpha; /* +0xDC screen snow quad opacity, 0..1 */
    f32 spinAngle; /* +0xE0 yaw of the snow model, radians (one float past the entry) */
} SnowLayer;

/* Constants of the snow pass; the game keeps the floats in the small-data pool. */
#define SNOW_LAYER_SIZE 0xE0                   /* bytes per weather entry */
#define FLOAT_EPSILON (*(f32 *)lbl_80558DC4)   /* 2^-15: |x| at or below this counts as zero */
#define FADE_TO_ALPHA lbl_80564854             /* 255.0f: 0..1 fade -> 8-bit alpha */
#define FLOAT_ZERO lbl_80564858                /* 0.0f */
#define FLOAT_ONE lbl_8056485C                 /* 1.0f */
#define FADE_TO_BRIGHTNESS lbl_80564860        /* 2.0f: snow fade -> model brightness */
#define SNOW_TINT_RGB 0x00E6F0FF               /* pale blue snow tint; alpha is OR'd on top */
#define RENDER_WIDTH lbl_8055CFF0              /* 640 */
#define RENDER_HEIGHT lbl_8055CFF4             /* 480 */
/* fn_802C9124 really takes UVs, then the screen rectangle and a packed RGBA colour. */
typedef void DrawTexturedQuad(f32, f32, f32, f32, s32, s32, s32, s32, s32);

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802A4E08(void) {
    /* Draw the snow weather pass for the entry being rendered: a full-screen
     * snowquad.tex quad tinted pale blue with the entry's +0xDC alpha, then the
     * snow model (lbl_8055F898) centred on the camera, spun about Y by the +0xE0
     * angle and lit by min(1, 2 * the +0xD8 fade). */
    register s32 alpha;
    SnowLayer *layer;
    s32 layerOff;
    f32 quadAlpha;
    f32 magnitude;
    s32 scaledAlpha;
    s32 clampedAlpha;
    const f32 *viewMtx;
    f32 modelMtx[12];
    f32 angle;
    f32 cosine;
    f32 sine;
    f32 brightness;
    f32 fadeBrightness;
    layerOff = fn_801E85B4() * SNOW_LAYER_SIZE;
    layer = (SnowLayer *)((u8 *)fn_801E7E34() + layerOff);
    quadAlpha = layer->quadAlpha;
    magnitude = (f32)__fabs((double)quadAlpha);
    if (!(magnitude <= FLOAT_EPSILON)) {
        alpha = 0xFF;
        scaledAlpha = (s32)(FADE_TO_ALPHA * quadAlpha);
        clampedAlpha = scaledAlpha & ((-scaledAlpha & ~scaledAlpha) >> 31);
        if (clampedAlpha < 0xFF)
            alpha = clampedAlpha;
        fn_802C90F0(lbl_8055F89C); /* start a 2D batch on the snowquad.tex texture */
        ((DrawTexturedQuad *)fn_802C9124)(
            FLOAT_ZERO, FLOAT_ZERO, FLOAT_ONE, FLOAT_ONE,
            0, 0, RENDER_WIDTH, RENDER_HEIGHT,
            (alpha << 24) | SNOW_TINT_RGB);
        fn_802C9118();
    }
    magnitude = (f32)__fabs((double)layer->modelFade);
    if (!(magnitude <= FLOAT_EPSILON) && lbl_8055F898 != -1) {
        viewMtx = (const f32 *)fn_802C86DC();
        modelMtx[9] = viewMtx[9];
        modelMtx[10] = viewMtx[10];
        modelMtx[11] = viewMtx[11];
        angle = layer->spinAngle;
        cosine = (f32)cos((double)angle);
        sine = (f32)sin((double)angle);
        modelMtx[0] = cosine;
        modelMtx[1] = FLOAT_ZERO;
        modelMtx[2] = -sine;
        modelMtx[3] = FLOAT_ZERO;
        modelMtx[4] = FLOAT_ONE;
        modelMtx[5] = FLOAT_ZERO;
        modelMtx[6] = sine;
        modelMtx[7] = FLOAT_ZERO;
        modelMtx[8] = cosine;
        brightness = FLOAT_ONE;
        fadeBrightness = FADE_TO_BRIGHTNESS * layer->modelFade;
        brightness = (brightness < fadeBrightness) ? brightness : fadeBrightness;
        fn_802C9900(brightness); /* model brightness */
        fn_802C744C(lbl_8055F898, modelMtx);
        fn_802C9904();
    }
}
#pragma scheduling on
#pragma pop
extern void PSVECCrossProduct(float *, float *, float *);
extern float PSVECMag(float *);
extern void fn_802E317C(const char *, ...);
extern const char lbl_80349C48[];
extern const char lbl_8055CBD0, lbl_8055CBD4, lbl_8055CBDC, lbl_8055CBE0;
extern float lbl_80564860, lbl_80564864;
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_802A4FA8(float *out, void *object) {
    struct Vec3 {
        float x, y, z;
    };
    struct Dummy {
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
        virtual Vec3 get(const char *);
    };
    /* Fetches four named vectors from an object and validates the cross-product magnitude. */
    if (object != 0) {
        const Vec3 &v0 = ((Dummy *)object)->get(&lbl_8055CBD0);
        out[0] = v0.x; out[1] = v0.y; out[2] = v0.z;
        const Vec3 &v1 = ((Dummy *)object)->get(&lbl_8055CBD4);
        out[3] = v1.x; out[4] = v1.y; out[5] = v1.z;
        const Vec3 &v2 = ((Dummy *)object)->get(&lbl_8055CBDC);
        out[6] = v2.x; out[7] = v2.y; out[8] = v2.z;
        const Vec3 &v3 = ((Dummy *)object)->get(&lbl_8055CBE0);
        out[9] = v3.x; out[10] = v3.y; out[11] = v3.z;
        Vec3 cross;
        PSVECCrossProduct(out + 6, out + 9, &cross.x);
        if (lbl_80564864 * PSVECMag(&cross.x) < lbl_80564860)
            fn_802E317C(lbl_80349C48);
        return 1;
    }
    return 0;
}
#pragma cplusplus reset
#pragma scheduling on

extern f32 lbl_8056485C, lbl_80564868, lbl_8056486C, lbl_80564870, lbl_80564874;
extern s32 lbl_8055F894;
extern unsigned char lbl_80349BF0[];
extern unsigned char lbl_804BCFB8[];
extern s32 lbl_8055CBE8;
s32 fn_80287B14(void);
void *fn_80288208(s32);
s32 fn_80287E20(void *, s32);
void *fn_80287E80(void *, s32);
void fn_8028E61C(void *);
s32 fn_8028E2F8(void *, void *, void *, f32, f32, f32, f32);
int sprintf(char *, const char *, ...);
#pragma scheduling on
#pragma cplusplus on
extern "C" void fn_802A50F8(void) {
    struct Init { s32 a, b; f32 c[28]; };
    struct Frame { u8 pad[0x18]; struct Init init; u8 unkTail[0x10]; };
    struct Lookup {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual void *get(const char *);
    };
    struct Frame frame;
    char name[4];
    void *obj;
    s32 i;
    u8 *entry;
    u8 *base;
    base = lbl_80349BF0;
    fn_8028E61C(&frame.init);
    frame.init.a = 0;
    frame.init.b = 0x100;
    frame.init.c[0] = lbl_80564868;
    frame.init.c[1] = lbl_8056485C;
    frame.init.c[2] = lbl_8056486C;
    frame.init.c[3] = lbl_8056486C;
    frame.init.c[4] = lbl_8056486C;
    frame.init.c[5] = lbl_8056485C;
    frame.init.c[6] = lbl_8056485C;
    frame.init.c[7] = lbl_8056485C;
    frame.init.c[10] = lbl_8056485C;
    ((s32 *)&frame.init)[17] = 5;
    frame.init.c[19] = lbl_80564870;
    frame.init.c[18] = lbl_80564870;
    frame.init.c[21] = lbl_8056485C;
    frame.init.c[20] = lbl_80564874;
    frame.init.c[27] = lbl_8056485C;
    frame.init.c[25] = lbl_8056485C;
    frame.init.c[23] = lbl_8056485C;
    lbl_8055F894 = fn_8028E2F8(&frame.init, base + 0x80, base + 0x1c, lbl_80564870, lbl_8056486C, lbl_8056485C, lbl_80564868);
    entry = lbl_804BCFB8;
    for (i = 0; i < fn_80287B14(); ++i, entry += 0xC4) {
        obj = fn_80288208(i);
        *(s32 *)(entry + 0xC0) = 0;
        if (((s32 (*)(void *, s32))fn_80287E20)(obj, (s32)&lbl_8055CBE8)) {
            obj = fn_80287E80(obj, (s32)&lbl_8055CBE8);
            *(s32 *)(entry + 0xC0) = 0;
            while (*(s32 *)(entry + 0xC0) < 4) {
                void *value;
                sprintf(name, (char *)(base + 0x8c), *(s32 *)(entry + 0xC0) + 1);
                value = ((Lookup *)obj)->get(name);
                if (!fn_802A4FA8((float *)(entry + *(s32 *)(entry + 0xC0) * 0x30), value)) break;
                *(s32 *)(entry + 0xC0) = *(s32 *)(entry + 0xC0) + 1;
            }
        }
    }
}
#pragma cplusplus reset
#pragma scheduling on
void fn_802A5270(f32 arg0) {
    f32 value = lbl_8056485C;
    s32 amount;
    s32 result;
    value = (value < arg0) ? value : arg0;
    value = (value > lbl_80564858) ? value : lbl_80564858;
    amount = (s32)(lbl_80564878 * value);
    result = fn_801284F8(0x44, lbl_80349C88);
    if (result != 0) {
        result = fn_802A6944(result, amount, 0);
    }
    lbl_8055F88C = result;
    fn_802A50F8();
}
#pragma scheduling on
extern f32 lbl_80564858, lbl_8056485C, lbl_80564878;
extern char lbl_80349C94[];
s32 fn_801284F8(s32, char *);
void *fn_802A5AE8(void *, s32, s32);
#pragma scheduling on
void fn_802A52FC(f32 arg0) {
    register f32 value = lbl_8056485C;
    s32 result;
    s32 amount;
    value = (value < arg0) ? value : arg0;
    value = (value > lbl_80564858) ? value : lbl_80564858;
    amount = (s32)(lbl_80564878 * value);
    result = fn_801284F8(0xBC, lbl_80349C94);
    if (result != 0) result = (s32)fn_802A5AE8((void *)result, amount, 0);
    lbl_8055F888 = result;
}
void fn_802A5270(f32);
s32 fn_802A5384(s32 arg0) {
    s32 value = *(s32 *)arg0;

    if (value == 2) {
        goto special;
    }
    if (value >= 2) {
        return;
    }
    if (value < 1) {
        return;
    }
    return ((s32 (*)(f32))fn_802A5270)(lbl_8056485C);
special:
    return ((s32 (*)(f32))fn_802A52FC)(lbl_8056485C);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802A53B0(void *arg0, s32 arg1) {
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp14[3];
    f32 sp8[3];
    s32 i;
    s32 j;
    s32 k;
    f32 dot;
    f32 mag;
    f32 f27;
    f32 f29;
    f32 f30;
    f32 f28;
    f32 f1;
    u8 *base;
    u8 *item;
    u8 *entry;
    s32 *mat;
    if ((f32)__fabs((double)((f32 (*)(void))fn_802A4AD4)()) <= *(f32 *)(void *)&lbl_80558DC4) {
        return;
    }
    if (lbl_8055F894 == 0) {
        return;
    }
    base = (u8 *)lbl_8055F88C;
    f27 = lbl_8056487C;
    f1 = -(lbl_8056485C / (f32)fn_8002F234(PSVECDotProduct((f32 *)(base + 0x2C), (f32 *)(base + 0x2C))));
    f30 = lbl_80564880;
    f29 = lbl_80564884;
    f28 = lbl_80564864;
    sp38[0] = *(f32 *)(base + 0x2C) * f1;
    sp38[1] = *(f32 *)(base + 0x30) * f1;
    sp38[2] = *(f32 *)(base + 0x34) * f1;
    for (i = 0; i < arg1; i++) {
        item = (u8 *)arg0 + i * 0x10;
        entry = lbl_804BCFB8 + (*(s32 *)(item + 4) * 0xC4);
        if (*(f32 *)(item + 8) > f27) {
            continue;
        }
        if (((u8 *)(item + 0xC))[0] == 0) {
            continue;
        }
        if (*(s32 *)(entry + 0xC0) < 1) {
            continue;
        }
        mat = *(s32 **)item;
        for (j = 0; j < *(s32 *)(entry + 0xC0); j++) {
            VecMtxMult_802A53B0((f32 *)mat, (f32 *)(entry + j * 0x30), sp2C);
            dot = PSVECDotProduct(sp38, sp2C);
            PSVECCrossProduct((f32 *)(entry + j * 0x30 + 0x18), (f32 *)(entry + j * 0x30 + 0x24), sp14);
            mag = PSVECMag(sp14);
            {
                f32 t1 = f28 * mag;
                f32 t2 = -dot * t1;
                if ((s32)t2 < 1) {
                    continue;
                }
            }
            {
                f32 t = f30 * dot;
                f32 a0 = sp38[0] + sp2C[0] * t;
                f32 a1 = sp38[1] + sp2C[1] * t;
                f32 a2 = sp38[2] + sp2C[2] * t;
                sp20[0] = a0;
                sp20[1] = a1;
                sp20[2] = a2;
                {
                    f32 s0 = a0 * f29;
                    f32 s1 = a1 * f29;
                    f32 s2 = a2 * f29;
                    f32 *mp = (f32 *)mat;
                    sp20[0] = mp[13] + s0;
                    sp20[1] = mp[14] + s1;
                    sp20[2] = mp[15] + s2;
                }
            }
            {
                f32 t1 = f28 * mag;
                f32 t2 = -dot * t1;
                s32 cnt2 = fn_80287B5C((s32)t2) + 1;
                for (k = 0; k < cnt2; k++) {
                    f32 r = fn_80287BC8(lbl_80564858, lbl_8056485C);
                    f32 r2 = fn_80287BC8(lbl_80564858, lbl_8056485C);
                    sp8[0] = *(f32 *)(entry + j * 0x30 + 0xC) + *(f32 *)(entry + j * 0x30 + 0x18) * r + *(f32 *)(entry + j * 0x30 + 0x24) * r2;
                    sp8[1] = *(f32 *)(entry + j * 0x30 + 0x10) + *(f32 *)(entry + j * 0x30 + 0x1C) * r + *(f32 *)(entry + j * 0x30 + 0x28) * r2;
                    sp8[2] = *(f32 *)(entry + j * 0x30 + 0x14) + *(f32 *)(entry + j * 0x30 + 0x20) * r + *(f32 *)(entry + j * 0x30 + 0x2C) * r2;
                    VecMtxMult_802A53B0((f32 *)mat, sp8, sp8);
                    sp8[0] += ((f32 *)mat)[9];
                    sp8[1] += ((f32 *)mat)[10];
                    sp8[2] += ((f32 *)mat)[11];
                    {
                        f32 a1 = sp8[2];
                        f32 a2 = sp8[1];
                        fn_8028E584(lbl_8055F894, sp8, sp20, a1, a2);
                    }
                }
            }
        }
    }
}
#pragma scheduling on
#pragma pop
extern void *fn_802AE4C8(s32);
extern s32 fn_802A7370(s32, void *);
extern int strncmp(const char *, const char *, unsigned long);
extern char lbl_8055CBF0;
#pragma push
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" s32 fn_802A5878(void) {
    /* Collect "spar" child items from each list: allocate/init an entry per match and append its handle to lbl_804BCFA8, tracking count in lbl_8055F890. */
    struct Item {
        virtual const char *name();
        virtual void *child(s32);
    };
    s32 *handleTable;
    Item *listItem;
    s32 listIndex;
    s32 childIndex;
    Item *childItem;
    s32 entry;
    s32 entryCount;

    lbl_8055F890 = 0;
    if (fn_800167F4() > 1) {
        goto done;
    }
    handleTable = lbl_804BCFA8;
    listIndex = 0;
    while ((listItem = (Item *)fn_802AE4C8(listIndex)) != 0) {
        childIndex = 0;
        while (listItem->child(childIndex) != 0) {
            childItem = (Item *)listItem->child(childIndex);
            if (strncmp(childItem->name(), &lbl_8055CBF0, 4) == 0) {
                entry = fn_801284F8(0x40, &lbl_8055CBF0);
                if (entry != 0) {
                    entry = fn_802A7370(entry, childItem);
                }
                entryCount = lbl_8055F890;
                handleTable[entryCount] = entry;
                lbl_8055F890 = entryCount + 1;
            }
            childIndex++;
        }
        listIndex++;
    }
done:
    ;
}
#pragma cplusplus off
#pragma pop

void *fn_802A7614(void *, s32);
s32 fn_802A597C(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A7614((void *)*ptr, 1);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
    lbl_8055F890 = 0;
}

void fn_802A59E0(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A7680(*ptr);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
}

void fn_802A775C(void *);
void fn_802A5A38(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A775C((void *)*ptr);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
}

void fn_802A5A90(void);
s32 fn_802A79CC(s32);
void fn_802A5A90(void) {
    s32 *ptr = lbl_804BCFA8;
    s32 i = 0;
    goto check;
loop:
    fn_802A79CC(*ptr);
    ptr++;
    i++;
check:
    if (i < lbl_8055F890) goto loop;
}

#pragma scheduling invalid_target
void *fn_802A5AE8(void *arg0, s32 arg1, s32 arg2) {
    s32 size = arg1 * 0xC;
    s32 buffer = ((s32 (*)(s32, void *, s32))fn_8012850C)(size + 0x10, lbl_80349CA0, size);
    *(s32 *)arg0 = fn_8002F37C(buffer, (void *)fn_8001BA68, 0, 0xC, arg1);
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC) = fn_802CAC28((void *)lbl_8055CBBC, 0);
    *(s32 *)((u8 *)arg0 + 0x10) = fn_802CAC28((void *)lbl_8055CBB8, 0);
    *(s32 *)((u8 *)arg0 + 0x1C) = arg2;
    fn_802A5C1C(arg0);
    return arg0;
}
#pragma scheduling on
extern s32 lbl_804BCFA8[];
extern s32 lbl_8055F890;
s32 fn_802A7680(s32);
#pragma scheduling invalid_target
s32 fn_802A5B8C(s32 arg0, s32 arg1) {
    s32 temp;
    s32 *p = (s32 *)arg0;
    if (arg0 != 0) {
        fn_802CAC54(p[4]);
        p[4] = -1;
        fn_802CAC54(p[3]);
        temp = p[0];
        p[3] = -1;
        if (temp != 0) fn_80128670(temp - 0x10);
        p[0] = 0;
        if (arg1 > 0) fn_80128668((void *)arg0);
    }
    return arg0;
}
#pragma scheduling on
void fn_802A5C1C(void *arg0) {
    f32 zero = lbl_80564858;
    f32 a = lbl_8056485C;
    f32 b = lbl_80564850;
    f32 c = lbl_80564888;
    *(f32 *)((u8 *)arg0 + 0x20) = a;
    *(f32 *)((u8 *)arg0 + 0x24) = b;
    *(f32 *)((u8 *)arg0 + 0x28) = c;
    *(f32 *)((u8 *)arg0 + 0x2C) = zero;
    *(f32 *)((u8 *)arg0 + 0x30) = zero;
    *(f32 *)((u8 *)arg0 + 0x34) = zero;
    *(f32 *)((u8 *)arg0 + 0x38) = zero;
    *(f32 *)((u8 *)arg0 + 0x3C) = zero;
    *(f32 *)((u8 *)arg0 + 0x40) = zero;
    *(f32 *)((u8 *)arg0 + 0x44) = zero;
    *(f32 *)((u8 *)arg0 + 0x48) = zero;
    *(f32 *)((u8 *)arg0 + 0x4C) = zero;
    *(f32 *)((u8 *)arg0 + 0x50) = zero;
    *(f32 *)((u8 *)arg0 + 0x54) = a;
    *(f32 *)((u8 *)arg0 + 0x58) = zero;
    *(f32 *)((u8 *)arg0 + 0x18) = zero;
    *(f32 *)((u8 *)arg0 + 0x14) = zero;
    fn_802A6234(c, b, a);
    fn_802A6790(arg0);
}
#pragma scheduling on
extern f32 lbl_8056488C;
extern void *fn_801E8718();
extern void fn_802A62CC(void *, s32);
extern s32 fn_801E8758(s32);
extern f32 PSVECDotProduct(f32 *, f32 *);
extern void fn_802A6470(void *, f32 *, f32 *, f32);
extern void fn_802A6838(void *);
extern void fn_802A6408(void *);
extern void fn_802A6790(void *);
#pragma scheduling invalid_target
void fn_802A5CA4(void *arg0) {
    struct Obj { u8 pad0[0x1C]; s32 model; u8 pad20[0x0C]; f32 pos[3]; f32 axis[3]; f32 scaled[3]; f32 base[3]; };
    struct Work { f32 input[3]; f32 cross[3]; f32 transformed[3]; s32 pad; s32 matrix[12]; } w;
    register f32 *m = (f32 *)w.matrix;
    struct Obj *obj = (struct Obj *)arg0;
    s32 *source = (s32 *)fn_801E8718(obj->model);
    s32 a, b;
    b=source[0]; a=source[1]; w.matrix[0]=b; w.matrix[1]=a;
    a=source[2]; b=source[3]; w.matrix[2]=a; w.matrix[3]=b;
    a=source[4]; b=source[5]; w.matrix[4]=a; w.matrix[5]=b;
    a=source[6]; b=source[7]; w.matrix[6]=a; w.matrix[7]=b;
    a=source[8]; w.matrix[8]=a;
    a=source[9]; b=source[10]; w.matrix[9]=a; w.matrix[10]=b;
    a=source[11]; w.matrix[11]=a;
    fn_802A62CC(obj, w.matrix[9]);
    {
        f32 y=lbl_80564874, x=lbl_80564858, z=lbl_80564858;
        w.input[0]=x; w.input[1]=y; w.input[2]=z;
        if (obj->base==&w.input[0]) {
            f32 xy1=y*m[1];
            f32 xx0=x*m[0];
            f32 xx1=x*m[3];
            f32 yy4=y*m[4];
            f32 xx2=x*m[6];
            f32 yy5=y*m[7];
            f32 s0=xx0+xy1;
            f32 s1=xx1+yy4;
            f32 s2=xx2+yy5;
            f32 o0=z*m[2]+s0;
            f32 o1=z*m[5]+s1;
            f32 o2=z*m[8]+s2;
            obj->base[0]=o0; obj->base[1]=o1; obj->base[2]=o2;
        } else {
            obj->base[0]=w.input[2]*m[2]+(w.input[0]*m[0]+w.input[1]*m[1]);
            obj->base[1]=w.input[2]*m[5]+(w.input[0]*m[3]+w.input[1]*m[4]);
            obj->base[2]=w.input[2]*m[8]+(w.input[0]*m[6]+w.input[1]*m[7]);
        }
    }
    {
        f32 scale=lbl_80564844;
        obj->scaled[0]=obj->base[0]*scale;
        obj->scaled[1]=obj->base[1]*scale;
        obj->scaled[2]=obj->base[2]*scale;
    }
    if (fn_801E8758(obj->model)==0) {
        w.transformed[0]=obj->pos[0]-m[9];
        w.transformed[1]=obj->pos[1]-m[10];
        w.transformed[2]=obj->pos[2]-m[11];
        {
            f32 x=w.transformed[0], y=w.transformed[1], z=w.transformed[2];
            f32 out0=x*m[0]+y*m[1]+z*m[2];
            f32 out1=x*m[3]+y*m[4]+z*m[5];
            f32 out2=x*m[6]+y*m[7]+z*m[8];
            w.transformed[0]=out0; w.transformed[1]=out1; w.transformed[2]=out2;
        }
        {
            f32 posScale=lbl_8056488C;
            obj->scaled[0]+=w.transformed[0]*posScale;
            obj->scaled[1]+=w.transformed[1]*posScale;
            obj->scaled[2]+=w.transformed[2]*posScale;
        }
        PSVECCrossProduct((f32 *)&w.matrix[6],obj->axis,w.cross);
        fn_802A6470(obj,m,w.transformed,PSVECDotProduct((f32 *)&w.matrix[3],w.cross));
        fn_802A6838(obj); fn_802A6408(obj);
    } else fn_802A6790(obj);
    obj->pos[0]=m[9]; obj->pos[1]=m[10]; obj->pos[2]=m[11];
    obj->axis[0]=m[6]; obj->axis[1]=m[7]; obj->axis[2]=m[8];
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802A5FE4(void *arg0) {
    Obj802A5FE4 *o = (Obj802A5FE4 *)arg0;
    f32 saved;
    s32 scaled, t;
    f32 c884, c888, one;
    s32 j, i;
    if (o->count >= 1) {
        saved = fn_802C9A4C(lbl_8055F880);
        fn_802C8B98(o->unkC, fn_802C86DC());
        scaled = (s32)(lbl_80564854 * (lbl_8056485C / (lbl_80564890 * PSVECMag(o->vec))));
        t = scaled & ~(scaled >> 31);
        if (fn_801E501C(o->count, o->vec, lbl_80564844, (u8)(t < 0xff ? t : 0xff)) != 0) {
            s32 off = 0;
            s32 k = 0;
            while (k < o->count) {
                f32 *e = (f32 *)((char *)o->pts + off);
                fn_801E5174(e, e[0], e[1], e[2]);
                off += 0xC;
                k++;
            }
            fn_801E5348();
        }
        fn_802C8D74();
        fn_802C9A4C(saved);
        fn_802C90F0(o->unk10);
        one = lbl_8056485C;
        c884 = lbl_80564884;
        c888 = lbl_80564888;
        i = 0;
        while (i < lbl_8055CFF0 / 64 + 1) {
            j = 0;
            while (j < lbl_8055CFF4 / 64 + 1) {
                s32 y1 = (j + 1) << 6;
                s32 x1 = (i + 1) << 6;
                if (lbl_8055CFF4 < y1) y1 = lbl_8055CFF4;
                if (lbl_8055CFF0 < x1) x1 = lbl_8055CFF0;
                ((void (*)(s32, s32, s32, s32, u32, f32, f32, f32, f32))fn_802C9124)(
                    i << 6, j << 6, x1, y1, 0x6EFFFFFF,
                    o->x14 + (f32)(i * 7) / c884,
                    o->y18 + (f32)(j * 7) / c888,
                    (one + o->x14) + (f32)(i * 7) / c884,
                    (one + o->y18) + (f32)(j * 7) / c888);
                j++;
            }
            i++;
        }
        fn_802C9118();
    }
}
#pragma pop

#pragma push
#pragma processor 750
void fn_802A6234(void *arg0) {
    /* Initialize 8 XYZ float triplets at offsets 0x5C.. with random values in [-0.1, 0.1]. */
    f32 randomZ;
    f32 randomY;
    s32 entryPtr = (s32)arg0;
    s32 index = 0;
    do {
        randomZ = fn_80129DC4(0, lbl_80564894, lbl_80564898);
        randomY = fn_80129DC4(0, lbl_80564894, lbl_80564898);
        *(f32 *)(entryPtr + 0x5C) = fn_80129DC4(0, lbl_80564894, lbl_80564898);
        index += 1;
        *(f32 *)(entryPtr + 0x60) = randomY;
        *(f32 *)(entryPtr + 0x64) = randomZ;
        entryPtr += 0xC;
    } while (index < 8);
}
extern double fn_8002EF30(f32);
extern f32 fn_801E8738(s32);
extern f32 fn_801E8874(s32);
extern f32 fn_801E8894(s32);
extern void fn_801E88B4(f32 *, f32 *, s32 *, f32 *, s32);
extern f32 lbl_80564860;
extern f32 lbl_80564890;
extern f32 lbl_80564894;
extern f32 lbl_8056489C;
extern f32 lbl_805648A0;
extern double lbl_80564848;
#pragma push
#pragma optimization_level 2
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_802A62CC(void *arg0, s32 arg1) {
    union IntToDouble {
        double value;
        struct { u32 high, low; } words;
    } conversion;
    f32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    f32 temp_f10;
    f32 temp_f29;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f30;
    f32 temp_f30_2;
    f32 temp_f31;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    temp_f30 = lbl_80564850 * fn_801E8738(*(s32 *)((u8 *)arg0 + 0x1C));
    temp_f31 = fn_801E8874(*(s32 *)((u8 *)arg0 + 0x1C));
    temp_f29 = fn_801E8894(*(s32 *)((u8 *)arg0 + 0x1C));
    fn_801E88B4(&sp14, &sp10, &spC, &sp8, *(s32 *)((u8 *)arg0 + 0x1C));
    temp_f10 = (f32)fn_8002EF30(temp_f30);
    *(f32 *)((u8 *)arg0 + 0x20) = temp_f10;
    temp_f30_2 = temp_f29 + temp_f31;
    temp_f7 = temp_f29 * lbl_8056489C;
    *(f32 *)((u8 *)arg0 + 0x24) = lbl_805648A0 + temp_f31;
    temp_f9 = lbl_80564894 * temp_f30_2;
    temp_f8 = lbl_80564860 * temp_f29 * temp_f31;
    temp_f6 = temp_f31 * temp_f7;
    temp_f29_2 = temp_f9 - temp_f8;
    conversion.words.high = 0x43300000;
    conversion.words.low = (u32)spC ^ 0x80000000;
    temp_f3 = lbl_80564844 * ((f32)(conversion.value - lbl_80564848) * (lbl_80564890 * temp_f31));
    temp_f4 = temp_f29_2 * temp_f29_2;
    temp_f2 = temp_f3 * (temp_f29 - temp_f31);
    *(f32 *)((u8 *)arg0 + 0x28) = (f32)((-temp_f29_2 +
        (f32)fn_8002F234(temp_f4 -
            (lbl_80564890 * temp_f30_2 * (temp_f6 - (temp_f2 / (lbl_80564860 * temp_f10)))))) /
        (lbl_80564860 * temp_f30_2));
}
#pragma scheduling on
#pragma pop
#pragma pop
f32 fn_80129DC4(s32, f32, f32);
extern f32 lbl_80564894, lbl_80564898;
f32 fn_802A4AD4(void);
f32 fn_80287BC8(f32, f32);
extern f32 lbl_805648A4, lbl_805648A8;
void fn_802A6408(void *arg0) {
    f32 value = ((f32 (*)(void))fn_802A4AD4)();
    f32 abs = (f32)__fabs((double)value);
    if (!(abs <= *(f32 *)(void *)&lbl_80558DC4)) {
        *(f32 *)((u8 *)arg0 + 0x14) = fn_80287BC8(lbl_805648A4, lbl_805648A8);
        *(f32 *)((u8 *)arg0 + 0x18) = fn_80287BC8(lbl_805648A4, lbl_805648A8);
    }
}

#pragma push
#pragma processor 750
void fn_802A6470(void *arg0, f32 *arg1, f32 *arg2, f32 farg0) {
    typedef struct { f32 x, y, z; } V3;
    f32 v[3];
    f32 p[3];
    f32 ratioY, ratioX, scale, d;
    V3 *out;
    int i;

    d = fn_802C9A50();
    ratioY = *(f32 *)((u8 *)arg0 + 0x20);
    ratioX = ratioY / d;
    scale = ((f32 (*)(void))fn_802A4AD4)();
    fn_801E8C84(v);
    {
        f32 t = lbl_80564898 * scale;
        v[0] = v[0] * t;
        v[2] = v[2] * t;
        v[1] = v[1] * t - lbl_805648AC * scale;
    }
    Mtx33MultVec_802A6470(arg1, v, v);
    v[0] += arg2[0] * lbl_805648B0;
    v[1] += arg2[1] * lbl_805648B0;
    v[2] += arg2[2] * lbl_805648B0;
    out = *(V3 **)arg0;
    for (i = 0; i < *(s32 *)((u8 *)arg0 + 4); i++) {
        V3 *in = (V3 *)((u8 *)(*(V3 **)arg0) + i * 0xC);
        u8 *rec = (u8 *)arg0 + (i % 8) * 0xC;
        f32 z = in->z + v[2] + *(f32 *)(rec + 0x64) * scale;
        f32 y = in->y + v[1] + *(f32 *)(rec + 0x60) * scale;
        f32 x = in->x + v[0] + *(f32 *)(rec + 0x5C) * scale + farg0 * z;
        p[2] = z;
        p[1] = y;
        p[0] = x;
        if (z > *(f32 *)((u8 *)arg0 + 0x24) && z < *(f32 *)((u8 *)arg0 + 0x28)) {
            f32 a = z * ratioX;
            if (x * x < a * a) {
                f32 b = z * ratioY;
                if (y * y < b * b) {
                    out->x = x;
                    out->y = y;
                    out->z = z;
                    out++;
                }
            }
        }
    }
    *(s32 *)((u8 *)arg0 + 4) = out - *(V3 **)arg0;
}
#pragma pop

#pragma scheduling push
#pragma scheduling on
#pragma dont_inline on
void fn_802A6758(void *arg0, f32 *arg1) {
    s32 i = *(s32 *)((u8 *)arg0 + 4);
    f32 *base = *(f32 **)arg0;
    f32 z;
    f32 y;
    f32 x;
    x = arg1[0];
    y = arg1[1];
    z = arg1[2];
    base[i * 3] = x;
    base += i * 3;
    base[1] = y;
    base[2] = z;
    *(s32 *)((u8 *)arg0 + 4) += 1;
}
#pragma push
#pragma processor 750
void fn_802A6790(void *arg0) {
    f32 values[3];
    f32 first;
    f32 scaled;
    f32 second;
    f32 third;

    /* Fill entries [count@+4, limit@+8) with random 3-float samples derived from ranges at +0x20/+0x24/+0x28. */
    *(s32 *)((u8 *)arg0 + 4) = 0;
    while (*(s32 *)((u8 *)arg0 + 4) < *(s32 *)((u8 *)arg0 + 8)) {
        first = fn_80287BC8(*(f32 *)((u8 *)arg0 + 0x24), *(f32 *)((u8 *)arg0 + 0x28));
        scaled = *(f32 *)((u8 *)arg0 + 0x20) * first;
        second = fn_80287BC8(-scaled, scaled);
        third = fn_80287BC8(-scaled, scaled);
        values[0] = second;
        values[1] = third;
        values[2] = first;
        fn_802A6758(arg0, values);
    }
}

extern float fn_802C9A50(void);
extern void fn_802A6758(void *, float *);
extern double __fabs(double);
extern float lbl_80564850, lbl_80564858, lbl_8056485C;
void fn_802A6838(void *arg0) {
    unsigned char *p = (unsigned char *)arg0;
    float samples[2];
    float values[3];
    float divisor;
    float dt;
    float speed;
    float scale;
    float one;
    float curve;
    float product;
    double absX;
    double absY;
    float ax;
    float ay;
    float rx;
    float ry;
    float end;
    float start;
    float next;

    divisor = fn_802C9A50();
    dt = *(float *)(p + 0x20);
    speed = dt / divisor;
    scale = lbl_80564850;
    one = lbl_8056485C;
    while (*(int *)(p + 4) < *(int *)(p + 8)) {
        curve = fn_80287BC8(lbl_80564858, lbl_8056485C);
        product = scale * curve;
        samples[1] = *(float *)(p + 0x54) * (scale - product);
        samples[0] = *(float *)(p + 0x50) * (scale - product);
        absX = __fabs((double)samples[0]);
        absY = __fabs((double)samples[1]);
        ax = one - (float)absX;
        ay = one - (float)absY;
        rx = fn_80287BC8(-ax, ax);
        ry = fn_80287BC8(-ay, ay);
        end = *(float *)(p + 0x28);
        start = *(float *)(p + 0x24);
        next = start + curve * (end - start);
        values[2] = next;
        values[1] = dt * next * (samples[1] + ry);
        values[0] = speed * next * (samples[0] + rx);
        fn_802A6758(arg0, values);
    }
}

#pragma pop
s32 fn_802A6944(s32 arg0, s32 arg1, s32 arg2) {
    s32 *object = (s32 *)arg0;
    void *base = (void *)lbl_80349CAC;
    s32 size = arg1 * 0xC + 0x10;
    object[0] = fn_8002F37C(fn_8012850C(size, base), (void *)fn_8001BA68, 0, 0xC, arg1);
    object[2] = arg1;
    object[3] = fn_802CAC28((void *)lbl_8055CBC0, 0);
    object[4] = arg2;
    fn_802A6A44(object);
    return arg0;
}
#pragma scheduling on
void *fn_802A69D8(void *arg0, s32 arg1) {
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(((s32 *)arg0)[3]);
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern f32 lbl_80564850;
extern f32 lbl_80564858;
extern f32 lbl_8056485C;
extern f32 lbl_80564888;
s32 fn_802A711C(void *, f32, f32, f32);
#pragma scheduling invalid_target
s32 fn_802A6A44(s32 *arg0) {
    f32 d;
    f32 b = lbl_80564888;
    f32 c;
    f32 a = lbl_8056485C;
    f32 *p = (f32 *)arg0;

    c = lbl_80564850;
    d = lbl_80564858;
    p[5] = a;
    p[6] = c;
    p[7] = b;
    p[8] = d;
    p[9] = d;
    p[10] = d;
    p[14] = d;
    p[15] = a;
    p[16] = d;
    return fn_802A711C(arg0, b, c, a);
}

extern f32 lbl_805648A4;
#pragma scheduling invalid_target
void fn_802A6A7C(void *arg0) {
    struct Obj { u8 pad0[0x10]; s32 model; u8 pad14[0xC]; f32 pos[3]; f32 vel[3]; f32 axis[3]; } *obj = (struct Obj *)arg0;
    f32 *m = (f32 *)fn_801E8718(obj->model);
    f32 disp[3];
    f32 in[3];
    fn_802A6E34(obj);
    {
        f32 y = lbl_8056485C, x = lbl_80564858, z = lbl_80564858;
        in[0] = x; in[1] = y; in[2] = z;
        if (obj->axis == &in[0]) {
            f32 xy1 = y * m[1];
            f32 xx0 = x * m[0];
            f32 xx1 = x * m[3];
            f32 yy4 = y * m[4];
            f32 xx2 = x * m[6];
            f32 yy5 = y * m[7];
            f32 s0 = xx0 + xy1;
            f32 s1 = xx1 + yy4;
            f32 s2 = xx2 + yy5;
            f32 o0 = z * m[2] + s0;
            f32 o1 = z * m[5] + s1;
            f32 o2 = z * m[8] + s2;
            obj->axis[0] = o0; obj->axis[1] = o1; obj->axis[2] = o2;
        } else {
            obj->axis[0] = in[2] * m[2] + (in[0] * m[0] + in[1] * m[1]);
            obj->axis[1] = in[2] * m[5] + (in[0] * m[3] + in[1] * m[4]);
            obj->axis[2] = in[2] * m[8] + (in[0] * m[6] + in[1] * m[7]);
        }
    }
    if (fn_801E8758(obj->model) == 0) {
        f32 s;
        f32 dx = obj->pos[0] - m[9];
        f32 dy;
        f32 dz;
        disp[0] = dx;
        dy = obj->pos[1] - m[10];
        disp[1] = dy;
        dz = obj->pos[2] - m[11];
        disp[2] = dz;
        {
            f32 p1 = dy * m[1];
            f32 p0 = dx * m[0];
            f32 p4 = dy * m[4];
            f32 p3 = dx * m[3];
            f32 p7 = dy * m[7];
            f32 p6 = dx * m[6];
            f32 o0 = dz * m[2] + (p0 + p1);
            f32 o1 = dz * m[5] + (p3 + p4);
            f32 o2 = dz * m[8] + (p6 + p7);
            disp[0] = o0; disp[1] = o1; disp[2] = o2;
        }
        s = lbl_805648A4;
        obj->vel[0] = obj->axis[0] + disp[0] * s;
        obj->vel[1] = obj->axis[1] + disp[1] * s;
        obj->vel[2] = obj->axis[2] + disp[2] * s;
        s = lbl_805648B0 * (lbl_8056485C / (f32)fn_8002F234(PSVECDotProduct(obj->vel, obj->vel)));
        obj->vel[0] = obj->vel[0] * s;
        obj->vel[1] = obj->vel[1] * s;
        obj->vel[2] = obj->vel[2] * s;
        fn_802A6F70(obj, disp);
        fn_802A71C4(obj);
    } else {
        f32 s = lbl_805648B0;
        f32 vx = obj->axis[0] * s;
        f32 vy = obj->axis[1] * s;
        obj->vel[0] = vx;
        obj->vel[1] = vy;
        obj->vel[2] = obj->axis[2] * s;
        fn_802A711C(obj, vy, vx, s);
    }
    obj->pos[0] = m[9];
    obj->pos[1] = m[10];
    obj->pos[2] = m[11];
}
extern float lbl_8055F884;
extern float lbl_805648B4;
extern float fn_802C9A4C(float);
extern int fn_802C86DC(void);
extern void fn_802C8B98(int, int);
extern int fn_801E501C(int, void *, float, int);
extern void fn_801E5174(void *, float, float, float);
extern void fn_801E5348(void);
extern void fn_802C8D74(void);
#pragma push
#pragma processor 750
void fn_802A6D68(void *arg0) {
    float savedScale;
    /* Update particles for arg0 and draw them if setup succeeds. */
    if (*(int *)((char *)arg0 + 4) >= 1) {
        savedScale = fn_802C9A4C(lbl_8055F884);
        fn_802C8B98(*(int *)((char *)arg0 + 0xC), fn_802C86DC());
        if (fn_801E501C(*(int *)((char *)arg0 + 4), (char *)arg0 + 0x2C, lbl_805648B4, 0xFF) != 0) {
            int offset;
            int i;
            i = 0;
            offset = 0;
            while (i < *(int *)((char *)arg0 + 4)) {
                float *position = (float *)((char *)*(float **)arg0 + offset);
                fn_801E5174(position, *(float *)((char *)*(float **)arg0 + offset), position[1], position[2]);
                offset += 0xC;
                i++;
            }
            fn_801E5348();
        }
        fn_802C8D74();
        fn_802C9A4C(savedScale);
    }
}

extern float lbl_80564850, lbl_8056485C, lbl_80564860, lbl_80564890, lbl_805648B4, lbl_805648B8, lbl_805648BC;
#pragma push
#pragma optimization_level 4
#pragma processor 750
void fn_802A6E34(void *arg0) {
    f32 sp14;
    f32 sp10;
    s32 spC;
    f32 sp8;
    volatile union { double value; struct { u32 high, low; } words; } conversion;
    f32 temp_f30;
    f32 temp_f31;
    f32 temp_f29;
    f32 temp_f10;
    f32 temp_f29_2;
    f32 temp_f2;
    f32 temp_f30_2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 temp_f9;
    f32 disc;
    temp_f30 = lbl_80564850 * fn_801E8738(*(s32 *)((u8 *)arg0 + 0x10));
    temp_f31 = fn_801E8874(*(s32 *)((u8 *)arg0 + 0x10));
    temp_f29 = fn_801E8894(*(s32 *)((u8 *)arg0 + 0x10));
    fn_801E88B4(&sp14, &sp10, &spC, &sp8, *(s32 *)((u8 *)arg0 + 0x10));
    temp_f10 = (f32)fn_8002EF30(temp_f30);
    *(f32 *)((u8 *)arg0 + 0x14) = temp_f10;
    temp_f30_2 = temp_f29 + temp_f31;
    temp_f7 = temp_f29 * lbl_805648BC;
    *(f32 *)((u8 *)arg0 + 0x18) = lbl_8056485C + temp_f31;
    temp_f9 = lbl_805648B8 * temp_f30_2;
    temp_f8 = lbl_80564860 * temp_f29 * temp_f31;
    temp_f6 = temp_f31 * temp_f7;
    temp_f29_2 = temp_f9 - temp_f8;
    conversion.words.high = 0x43300000;
    conversion.words.low = (u32)spC ^ 0x80000000;
    temp_f3 = lbl_805648B4 * ((f32)(conversion.value - lbl_80564848) *
        (lbl_80564890 * temp_f31));
    temp_f4 = temp_f29_2 * temp_f29_2;
    temp_f2 = temp_f3 * (temp_f29 - temp_f31);
    disc = temp_f4 - (lbl_80564890 * temp_f30_2 *
        (temp_f6 - (temp_f2 / (lbl_80564860 * temp_f10))));
    *(f32 *)((u8 *)arg0 + 0x1C) =
        (f32)((-temp_f29_2 + (f32)fn_8002F234(disc)) /
            (lbl_80564860 * temp_f30_2));
}
#pragma pop
extern f32 fn_802A4AD4(void);
extern f32 fn_802C9A50(void);
extern f32 lbl_805648B0;
extern f32 lbl_805648C0;
#pragma scheduling invalid_target
void fn_802A6F70(void *arg0, void *arg1) {
    volatile f32 sp1C;
    volatile f32 sp18;
    volatile f32 sp14;
    volatile f32 sp10;
    volatile f32 spC;
    volatile f32 sp8;
    f32 divisor;
    f32 dt;
    f32 speed;
    f32 scale;
    f32 xVelocity;
    f32 yVelocity;
    f32 zVelocity;
    f32 xBase;
    f32 yBase;
    f32 zBase;
    f32 xOffset;
    f32 yOffset;
    f32 zOffset;
    f32 pointX;
    f32 pointY;
    f32 pointZ;
    f32 radiusBase;
    s32 offset;
    s32 count;
    u8 *out;
    double ddx;
    double ddy;
    double ddz;
    f32 rx;
    f32 ry;
    f32 rz;
    divisor = fn_802C9A50();
    dt = *(f32 *)((u8 *)arg0 + 0x14);
    speed = dt / divisor;
    scale = lbl_805648C0 * fn_802A4AD4();
    count = 0;
    xVelocity = *(f32 *)((u8 *)arg0 + 0x38) * scale;
    offset = 0;
    xBase = *(f32 *)((u8 *)arg1 + 0);
    yVelocity = *(f32 *)((u8 *)arg0 + 0x3C) * scale;
    yBase = *(f32 *)((u8 *)arg1 + 4);
    zVelocity = *(f32 *)((u8 *)arg0 + 0x40) * scale;
    xOffset = xBase + xVelocity;
    zBase = *(f32 *)((u8 *)arg1 + 8);
    yOffset = yBase + yVelocity;
    out = *(u8 **)arg0;
    zOffset = zBase + zVelocity;
    ddx = xOffset;
    ddy = yOffset;
    ddz = zOffset;
    rx = (f32)ddx;
    ry = (f32)ddy;
    rz = (f32)ddz;
    sp14 = xOffset;
    sp18 = yOffset;
    sp1C = zOffset;
    radiusBase = lbl_805648B0;
    goto check;
loop:
    {
        u8 *pointBase = *(u8 **)arg0;
        pointX = *(f32 *)(pointBase + offset);
        pointZ = *(f32 *)(pointBase + offset + 8);
        pointY = *(f32 *)(pointBase + offset + 4);
        pointX += rx;
        pointZ += rz;
        pointY += ry;
    }
    sp8 = pointX;
    spC = pointY;
    sp10 = pointZ;
    if (pointZ > *(f32 *)((u8 *)arg0 + 0x18) &&
        pointZ < *(f32 *)((u8 *)arg0 + 0x1C) &&
        pointX * pointX < (radiusBase + pointZ * speed) *
            (radiusBase + pointZ * speed) &&
        pointY * pointY < (radiusBase + pointZ * dt) *
            (radiusBase + pointZ * dt)) {
        *(f32 *)(out + 0) = pointX;
        *(f32 *)(out + 4) = pointY;
        *(f32 *)(out + 8) = pointZ;
        out += 0xC;
    }
    offset += 0xC;
    count++;
check:
    if (count < *(s32 *)((u8 *)arg0 + 4)) goto loop;
    *(s32 *)((u8 *)arg0 + 4) =
        ((s32)(out - *(u8 **)arg0)) / 12;
}
#pragma scheduling on
s32 fn_802A711C(void *object, f32 arg1, f32 arg2, f32 arg3) {
    /* Fill object entries while count (+4) < limit (+8): pick a random primary
       value in [field18, field1C] via fn_80287BC8, scale by +0x14, then build a
       3-float vector {rand(-scaled,scaled), rand(-scaled,scaled), primary} and
       pass it to fn_802A70E4; returns final count (+4). arg1/arg2/arg3 unused. */
    f32 values[3];
    f32 first;
    f32 scaled;
    f32 second;
    f32 third;
    *(s32 *)((u8 *)object + 4) = 0;
    while (*(s32 *)((u8 *)object + 4) < *(s32 *)((u8 *)object + 8)) {
        first = fn_80287BC8(*(f32 *)((u8 *)object + 0x18), *(f32 *)((u8 *)object + 0x1C));
        scaled = *(f32 *)((u8 *)object + 0x14) * first;
        second = fn_80287BC8(-scaled, scaled);
        third = fn_80287BC8(-scaled, scaled);
        values[0] = second;
        values[1] = third;
        values[2] = first;
        fn_802A70E4(object, values);
    }
    return *(s32 *)((u8 *)object + 4);
}

extern f32 lbl_80564850, lbl_80564858, lbl_8056485C, lbl_805648C4;
f32 fn_802C9A50(void);
void fn_802A70E4(void *, f32 *);
#pragma scheduling invalid_target
void fn_802A71C4(void *arg0) {
    volatile u8 *p = (volatile u8 *)arg0;
    f32 divisor;
    f32 dt;
    f32 threshold;
    f32 speed;
    f32 scale;
    f32 one;
    f32 curve;
    f32 a;
    f32 factor;
    f32 x;
    f32 y;
    f32 ax;
    f32 ay;
    volatile f32 yStack;
    volatile f32 xStack;
    f32 rx;
    f32 ry;
    f32 start;
    f32 end;
    f32 newx;
    divisor = fn_802C9A50();
    dt = *(volatile f32 *)(p + 0x14);
    threshold = *(volatile f32 *)(p + 0x34);
    speed = dt / divisor;
    if (threshold >= lbl_805648C4) {
        scale = lbl_80564850;
        one = lbl_8056485C;
        do {
            curve = fn_80287BC8(lbl_80564858, lbl_8056485C);
            a = scale * curve;
            factor = scale - a;
            x = *(volatile f32 *)(p + 0x38) * factor;
            y = *(volatile f32 *)(p + 0x3C) * factor;
            xStack = x;
            yStack = y;
            ax = (f32)__fabs((double)x);
            ay = (f32)__fabs((double)y);
            ax = one - ax;
            ay = one - ay;
            rx = fn_80287BC8(-ax, ax);
            ry = fn_80287BC8(-ay, ay);
            end = *(volatile f32 *)(p + 0x1C);
            start = *(volatile f32 *)(p + 0x18);
            newx = start + curve * (end - start);
            {
                f32 v[3];
                v[2] = newx;
                v[1] = dt * newx * (yStack + ry);
                v[0] = speed * newx * (xStack + rx);
                fn_802A70E4(arg0, v);
            }
        } while (*(volatile s32 *)(p + 4) < *(volatile s32 *)(p + 8));
    } else {
        do {
            curve = fn_80287BC8(lbl_80564858, lbl_8056485C);
            {
                f32 squared = curve * curve;
                f32 localThreshold = *(volatile f32 *)(p + 0x34);
                f32 localEnd = *(volatile f32 *)(p + 0x1C);
                f32 negativeThreshold = -localThreshold;
                f32 localStart = *(volatile f32 *)(p + 0x18);
                f32 curveDelta = squared - curve;
                f32 endDelta = localEnd - localStart;
                f32 bend = negativeThreshold * curveDelta;
                f32 factor2 = curve + bend;
                f32 distance = factor2 * endDelta;
                newx = localStart + distance;
            }
            rx = fn_80287BC8(-newx, newx);
            ry = fn_80287BC8(-newx, newx);
            {
                f32 v[3];
                v[2] = newx;
                v[0] = speed * rx;
                v[1] = dt * ry;
                fn_802A70E4(arg0, v);
            }
        } while (*(volatile s32 *)(p + 4) < *(volatile s32 *)(p + 8));
    }
}

extern char lbl_80349CB8[];
extern char lbl_80349CC8[];
extern char lbl_8055CBF8, lbl_8055CBFC, lbl_8055CC04, lbl_8055CC0C, lbl_8055CC10, lbl_8055CC14, lbl_8055CC18, lbl_8055CC20, lbl_8055CC28;
extern double fn_8002F208(float);
extern s32 fn_801EA140(void *);
#pragma cplusplus on
extern "C" s32 fn_802A7370(s32 arg0, void *arg1) {
    struct Vec3 {
        float x, y, z;
    };
    struct Dummy {
        virtual const char *v0();
        virtual void v1();
        virtual void v2();
        virtual void *v3(const char *);
        virtual void v4();
        virtual s32 v5(const char *);
        virtual void v6();
        virtual float v7(const char *);
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual Vec3 get(const char *);
    };
    Dummy *obj = (Dummy *)arg1;
    s32 count = obj->v5(&lbl_8055CBF8);
    s32 size = count * 0xC;
    *(s32 *)(arg0 + 4) = count;
    {
        s32 buffer = ((s32 (*)(s32, void *, s32))fn_8012850C)(size + 0x10, lbl_80349CB8, size);
        *(s32 *)arg0 = fn_8002F37C(buffer, (void *)fn_8001BA68, 0, 0xC, count);
    }
    *(f32 *)(arg0 + 8) = obj->v7(&lbl_8055CBFC);
    {
        const Vec3 &v = obj->get(&lbl_8055CC04);
        *(f32 *)(arg0 + 0xC) = v.x;
        *(f32 *)(arg0 + 0x10) = v.y;
        *(f32 *)(arg0 + 0x14) = v.z;
    }
    *(f32 *)(arg0 + 0x18) = obj->v7(&lbl_8055CC0C);
    *(f32 *)(arg0 + 0x1C) = obj->v7(&lbl_8055CC10);
    {
        const Vec3 &v = obj->get(&lbl_8055CC14);
        *(f32 *)(arg0 + 0x20) = v.x;
        *(f32 *)(arg0 + 0x24) = v.y;
        *(f32 *)(arg0 + 0x28) = v.z;
    }
    {
        s32 h = fn_802CAC28(obj->v3(&lbl_8055CC18), 0);
        *(f32 *)(arg0 + 0x30) = (f32)fn_8002F208((*(s32 *)(arg0 + 0x2C) = h, lbl_80564850 / *(f32 *)(arg0 + 8)));
    }
    {
        const Vec3 &c = obj->get(&lbl_8055CC20);
        s32 t0, t1, t2;
        u8 r, g, b;
        t0 = (s32)c.z;
        t0 = t0 > 0 ? t0 : 0;
        r = t0 < 0xFF ? t0 : 0xFF;
        t1 = (s32)c.y;
        t1 = t1 > 0 ? t1 : 0;
        g = t1 < 0xFF ? t1 : 0xFF;
        t2 = (s32)c.x;
        t2 = t2 > 0 ? t2 : 0;
        b = t2 < 0xFF ? t2 : 0xFF;
        *(s32 *)(arg0 + 0x34) = r | ((g << 8) | ((b << 16) | 0xFF000000));
    }
    *(f32 *)(arg0 + 0x38) = obj->v7(&lbl_8055CC28);
    if (fn_801EA140((void *)(arg0 + 0xC)) == 0) {
        fn_802E317C(lbl_80349CC8, obj->v0());
    }
    return arg0;
}
#pragma cplusplus reset

#pragma scheduling on
extern float fn_80287BC8(float, float);
extern void fn_802A70E4(void *, float *);
extern s32 fn_802CAC54(s32);
extern s32 fn_80128670(s32);
extern s32 fn_80128668(void *);
void *fn_802A7614(void *arg0, s32 arg1) {
    s32 temp;
    if (arg0 != 0) {
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x2C));
        temp = *(s32 *)arg0;
        if (temp != 0) fn_80128670(temp - 0x10);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern f32 lbl_80564858, lbl_805648C8;
#pragma push
#pragma processor 750
s32 fn_802A7680(s32 arg0) {
    u8 *object = (u8 *)arg0;
    f32 amplitude = lbl_805648C8;
    s32 offset = 0;
    s32 i = 0;
    while (i < *(s32 *)(object + 4)) {
        f32 angle;
        f32 y;
        f32 z;
        f32 x;
        f32 angle2;
        u32 addr;
        angle = *(f32 *)(object + 0x18);
        z = *(f32 *)(object + 0x14) + fn_80287BC8(amplitude * -angle, amplitude * angle);
        y = *(f32 *)(object + 0x10) + fn_80287BC8(lbl_80564858, *(f32 *)(object + 0x1C));
        angle2 = *(f32 *)(object + 0x18);
        x = *(f32 *)(object + 0xC) + fn_80287BC8(amplitude * -angle2, amplitude * angle2);
        addr = *(u32 *)object + offset;
        i++;
        offset += 0xC;
        *(f32 *)(addr + 0) = x;
        *(f32 *)(addr + 4) = y;
        *(f32 *)(addr + 8) = z;
    }
    *(f32 *)(object + 0x3C) = lbl_80564858;
}
#pragma pop
extern f32 PSVECSquareDistance(const void *, const void *);
extern double fn_8002F234(double);
extern void *fn_801E8718(s32);
extern f32 lbl_805648CC;
extern f32 lbl_805648D0;
extern f32 lbl_805648D4;
#pragma push
#pragma optimization_level 2
#pragma processor 750
#pragma dont_inline on
void fn_802A775C(void *arg0) {
    s32 offset;
    s32 i;
    Vec2_802A775C sp10;
    Vec2_802A775C sp8;
    f32 sp18[3];
    f32 f29;
    f32 distSq;
    f32 one;
    void *cam2;
    cam2 = (u8 *)fn_801E8718(0) + 0x24;
    distSq = PSVECSquareDistance(cam2, (u8 *)arg0 + 0xC);
    if (distSq > *(f32 *)((u8 *)arg0 + 0x18) * *(f32 *)((u8 *)arg0 + 0x18)) {
        f32 t = fn_802A4AD4();
        f32 x = *(f32 *)((u8 *)arg0 + 0x20);
        f32 z = *(f32 *)((u8 *)arg0 + 0x28);
        f32 y = *(f32 *)((u8 *)arg0 + 0x24);
        f32 xx = x * x;
        f32 tx;
        f32 ty;
        f32 zz;
        f32 tz;
        f32 sum;
        f32 len;
        f32 inv;
        sp10.x = x;
        tx = x * t;
        ty = y * t;
        zz = z * z;
        sp10.z = z;
        tz = z * t;
        sum = xx + zz;
        sp18[0] = tx;
        sp18[1] = ty;
        sp18[2] = tz;
        len = (f32)fn_8002F234(sum);
        one = lbl_8056485C;
        offset = 0;
        i = 0;
        inv = -*(f32 *)((u8 *)arg0 + 0x18) * (one / len);
        sp10.x *= inv;
        sp10.z *= inv;
        sp8.d = sp10.d;
        {
            f32 neg_x = -sp8.x;
            sp8.x = sp8.z;
            sp8.z = neg_x;
        }
        while (i < *(s32 *)((u8 *)arg0 + 4)) {
            f32 *pt = (f32 *)(*(u8 **)arg0 + offset);
            if (PSVECSquareDistance(pt, (u8 *)arg0 + 0xC) < *(f32 *)((u8 *)arg0 + 0x18) * *(f32 *)((u8 *)arg0 + 0x18)) {
                pt[0] += sp18[0];
                pt[1] += sp18[1];
                pt[2] += sp18[2];
            } else {
                f32 r = fn_80287BC8(lbl_805648CC, lbl_805648D0);
                f32 f28 = one - r * r;
                f32 ptz = *(f32 *)((u8 *)arg0 + 0x14) + sp8.z * r + sp10.z * f28;
                f32 ry = fn_80287BC8(lbl_80564858, *(f32 *)((u8 *)arg0 + 0x1C));
                pt[0] = *(f32 *)((u8 *)arg0 + 0xC) + sp8.x * r + sp10.x * f28;
                pt[1] = *(f32 *)((u8 *)arg0 + 0x10) + ry;
                pt[2] = ptz;
            }
            offset += 0xC;
            i++;
        }
        f29 = lbl_80564858;
    } else {
        f29 = *(f32 *)((u8 *)arg0 + 0x38) * (lbl_8056485C - (f32)fn_8002F234(distSq) / *(f32 *)((u8 *)arg0 + 0x18));
    }
    if (((f32)__fabs(f29) <= *(f32 *)(void *)&lbl_80558DC4) != ((f32)__fabs(*(f32 *)((u8 *)arg0 + 0x3C)) <= *(f32 *)(void *)&lbl_80558DC4)) {
        fn_802C990C(*(s32 *)((u8 *)arg0 + 0x34));
    }
    fn_802C2B78(lbl_80564850, lbl_805648D4, f29);
    *(f32 *)((u8 *)arg0 + 0x3C) = f29;
}

#pragma scheduling invalid_target
s32 fn_802A79CC(s32 arg0) {
    u8 *object = (u8 *)arg0;
    f32 pointScaleFactor;
    double intBias;
    f32 rate;
    f32 alphaScale;
    f32 distance;
    f32 radius;
    f32 radiusScale;
    f32 delta;
    f32 scaled;
    f32 radiusSquared;
    s32 raw;
    s32 magnitude;
    s32 alpha;
    s32 offset;
    s32 i;
    distance = PSQUATMultiply((u8 *)fn_802C86DC() + 36, object + 12);
    radiusScale = lbl_80564850;
    alpha = 255;
    radius = *(f32 *)(object + 24);
    delta = distance - (radiusScale * radius);
    scaled = lbl_805648D8 * (lbl_80564854 * delta);
    raw = (s32)scaled;
    magnitude = raw & ((-raw & ~raw) >> 31);
    if (magnitude < 255)
        alpha = magnitude;
    if (alpha > 0) {
        rate = fn_802C9A4C(*(f32 *)(object + 48));
        fn_802C8BD0(*(s32 *)(object + 44));
        if (fn_802CE860(*(s32 *)(object + 4)) != 0) {
            u32 alphaWord = (u32)alpha ^ 0x80000000;
            u32 highWord = 0x43300000;
            volatile union {
                double value;
                struct { u32 high; u32 low; } words;
            } conversion;
            intBias = lbl_80564848;
            radius = *(f32 *)(object + 24);
            radiusSquared = radius * radius;
            conversion.words.low = alphaWord;
            conversion.words.high = highWord;
            alphaScale = (f32)(conversion.value - intBias) / radiusSquared;
            pointScaleFactor = lbl_80564850;
            i = 0;
            offset = 0;
            goto check;
        loop:
            {
                u8 *point = *(u8 **)object + offset;
                f32 distSq = PSVECSquareDistance(point, object + 12);
                f32 pointScale = pointScaleFactor * *(f32 *)(object + 8);
                f32 pointX = *(f32 *)(point + 0);
                f32 pointY = *(f32 *)(point + 4);
                f32 pointZ = *(f32 *)(point + 8);
                conversion.words.low = alphaWord;
                conversion.words.high = highWord;
                raw = (s32)((f32)(conversion.value - intBias) - alphaScale * distSq);
                magnitude = raw & ((-raw & ~raw) >> 31);
                if (magnitude < alpha)
                    raw = magnitude;
                else
                    raw = alpha;
                fn_802CE86C((void *)((raw << 24) | 0x00FFFFFF), i, pointScale, pointX, pointY, pointZ);
                offset += 12;
                i++;
            }
        check:
            if (i < *(s32 *)(object + 4))
                goto loop;
            fn_802CE868();
        }
        fn_802C8D74();
        fn_802C9A4C(rate);
    }
    fn_802D3D50();
}
#pragma scheduling on
extern f32 lbl_80564850, lbl_80564854, lbl_80564858, lbl_8056485C;
extern s32 lbl_8055CFF0, lbl_8055CFF4;
extern s32 fn_802C90F0(s32);
extern void fn_802C9118(void);
extern void fn_802C9124(s32, s32, f32, f32, u32, f32, f32, f32, f32);
extern void fn_802D3D50(void);
extern void fn_802A5FE4();
extern void *fn_801E7E34(void);
#pragma cplusplus on
struct Obj802A5878 {
    virtual void *v0();
    virtual void *v1();
    virtual const char *name();
    virtual Obj802A5878 *child(s32);
};
#pragma cplusplus reset

/* Append a three-float value; read the entire input before writing its slot. */
#pragma push
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_802A70E4(void *object, float *input) {
f32 *data = *(f32 **)object;
s32 idx = ((s32 *)object)[1];
float z;
float y;
float x;
x = input[0];
y = input[1];
z = input[2];
data[idx * 3] = x;
data[idx * 3 + 1] = y;
data[idx * 3 + 2] = z;
((s32 *)object)[1] = ((s32 *)object)[1] + 1;
}
#pragma pop

#pragma cplusplus reset
