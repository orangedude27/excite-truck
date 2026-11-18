// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stddef.h>
#include <math.h>

typedef struct { f32 v[12]; } Blend12;
extern f32 lbl_8055E460, lbl_80558DC4[];
extern f32 PSVECDotProduct(void *, void *);

extern void *lbl_8055E650;
extern void *lbl_8055E654;
extern u8 lbl_80335A00[];
extern void fn_8017B0B0(void);
extern void fn_8017A57C(void *);
extern void fn_80179EE8(void *, u32);
extern void fn_80128668(void *);
extern f32 lbl_80562578;
extern f32 lbl_8055E3C8;
extern f32 lbl_8056258C;
extern f32 lbl_80562590;
extern f32 lbl_80562594;
extern f32 lbl_80562598;
extern f32 lbl_80562588;
extern void fn_8017B164(void);
extern void fn_8017A580(void *, f32);
extern s32 fn_8017D274(u8 *);
extern f32 lbl_8056257C, lbl_80562580, lbl_80562584;
extern char lbl_803359F0[], lbl_80333B48[];
extern void *fn_801284F8(s32, char *);
extern void fn_8019EECC(void *, void *);
extern void fn_80179F94(void *, void *);
extern void *lbl_80435BA8[];

/* Registry of active sound/effect objects: lbl_80435BA8 holds the pointers,
 * sEffectCount how many are registered, sEffectCursor the current round-robin
 * slot that fn_801AFC44 advances through. */
#define sEffectCount  lbl_8055E650
#define sEffectCursor lbl_8055E654

void fn_801AFC28(void) {
    // Clear the sound/effect object registry: reset both the entry count and the round-robin cursor.
    sEffectCount = 0;
    sEffectCursor = 0;
}

#pragma scheduling invalid_target
/* Initializes nw4hbm::snd::detail::DisposeCallbackManager subobject:
 * calls base init, installs vtable, and clears callback/time fields. */
void *fn_801AFD20(void *self) {
#define kZeroFloat lbl_80562578
#define sDisposeCallbackManagerVTable lbl_80335A00
    f32 initValue;
    void *vtable;

    fn_8017B0B0();
    initValue = kZeroFloat;
    vtable = sDisposeCallbackManagerVTable;
    *(s32 *)((u8 *)self + 0x1F4) = 0;
    *(void **)self = vtable;
    *(s32 *)((u8 *)self + 0x1F0) = 0;
    *(f32 *)((u8 *)self + 0x1EC) = initValue;
#undef kZeroFloat
#undef sDisposeCallbackManagerVTable
    return self;
}
#pragma scheduling on
/* nw4hbm::snd::detail::DisposeCallbackManager destructor helper:
 * destroys the base/subobject when non-null, then optionally frees storage. */
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801AFD70(void *this_, s32 flag) {
    if (this_ != NULL) {
        if (this_ != NULL) {
            fn_80179EE8(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801AFDCC(void *arg0, void *arg1) {
    #pragma scheduling on
    struct Object {
        void *vtable; void *owner; s32 field8; void *fieldC;
        f32 field10; f32 field14; s32 field18; s32 field1C; s32 field20;
        f32 field24; f32 field28; f32 field2C; f32 field30;
        f32 field34; f32 field38; f32 field3C; f32 field40;
        f32 field44; f32 field48; u8 field4C; u8 pad4D[3]; f32 field50;
    };
    volatile f32 stack1C;
    volatile f32 stack18;
    volatile f32 stack14;
    volatile f32 stack10;
    volatile f32 stackC;
    volatile f32 stack8;
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 zero;
    struct Object *allocated;

    fn_8017B0F8();
    temp_f2 = *(volatile f32 *)&lbl_80562580;
    temp_f0 = *(volatile f32 *)((u8 *)arg1 + 0x1C);
    zero = *(volatile f32 *)&lbl_80562578;
    temp_f0 = temp_f2 * temp_f0;
    temp_f3 = lbl_8056257C;
    temp_f4 = *(volatile f32 *)((u8 *)arg1 + 0x20);
    temp_f2 = *(volatile f32 *)((u8 *)arg1 + 0x18);
    temp_f5 = temp_f0 / temp_f3;
    temp_f29 = *(volatile f32 *)((u8 *)arg1 + 0x24);
    temp_f0 = *(volatile f32 *)&lbl_80562584;

    stack14 = zero;
    stack18 = zero;
    stack1C = zero;
    stack8 = zero;
    stackC = temp_f0;
    stack10 = zero;

    temp_f4 = temp_f4 * temp_f4;
    temp_f31 = temp_f3 * temp_f2;
    temp_f30 = temp_f5 * temp_f4;

    *(f32 *)((u8 *)arg0 + 0x60) = zero;
    *(f32 *)((u8 *)arg0 + 0x64) = temp_f0;
    *(f32 *)((u8 *)arg0 + 0x68) = zero;
    ((void (*)(void *, f32, f32, f32, f32, f32))fn_8017A580)(
        arg0, zero, temp_f2, temp_f3, temp_f4, temp_f5);

    allocated = (struct Object *)fn_801284F8(0x54, lbl_803359F0);
    if (allocated != NULL) {
        temp_f0 = *(volatile f32 *)&lbl_80562578;
        allocated->fieldC = (u8 *)arg0 + 0x3C;
        allocated->owner = arg0;
        allocated->field8 = 0;
        allocated->field18 = 0x53504852;
        allocated->field10 = temp_f30;
        allocated->field14 = temp_f29;
        allocated->field20 = 0x64;
        allocated->field1C = 0;
        allocated->vtable = lbl_80333B48;
        allocated->field24 = temp_f31;
        allocated->field34 = temp_f0;
        allocated->field38 = temp_f0;
        allocated->field3C = temp_f0;
        allocated->field40 = temp_f0;
        allocated->field44 = temp_f0;
        allocated->field48 = temp_f0;
        allocated->field4C = 0;
        allocated->field50 = temp_f0;
        allocated->field28 = stack14;
        allocated->field2C = stack18;
        allocated->field30 = stack1C;

        if (arg0 != NULL) {
            fn_8019EECC(arg0, &allocated->field28);
            fn_80179F94(arg0, allocated);
            temp_f0 = *(volatile f32 *)&lbl_80562578;
            *(u8 *)((u8 *)arg0 + 0x1E8) = 1;
            *(f32 *)((u8 *)arg0 + 0x1EC) = temp_f0;
            ((void **)lbl_80435BA8)[*(s32 *)(void *)&lbl_8055E650] = arg0;
            ++*(s32 *)(void *)&lbl_8055E650;
        }
    }
}

void fn_801AFF64(void *arg0, int arg1) {
    struct WordPair { unsigned int a, b; };
    unsigned char *src = (unsigned char *)arg0;
    unsigned char *dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    float c = lbl_80562588;
    float t = lbl_8055E460;
    float delta = t - c;
    if ((float)fabs(delta) <= lbl_80558DC4[0]) {
        struct WordPair *s = (struct WordPair *)(src + 0x70);
        struct WordPair *d = (struct WordPair *)dst;
        d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
        ((unsigned int *)dst)[8] = ((unsigned int *)(src + 0x70))[8];
        ((struct WordPair *)(dst + 0x24))[0] = ((struct WordPair *)(src + 0x94))[0];
        ((unsigned int *)dst)[11] = ((unsigned int *)(src + 0x70))[11];
    } else {
        float temp[12];
        float *a = (float *)(src + 0x70);
        float *b = (float *)(src + 0xA0);
        float *out = temp;
        int i;
        for (i = 0; i < 2; i++) {
            float a0 = a[0], b0 = b[0];
            float a1 = a[1], b1 = b[1];
            float a2 = a[2], b2 = b[2];
            float a3 = a[3], b3 = b[3];
            float a4 = a[4], b4 = b[4];
            float a5 = a[5], b5 = b[5];
            out[0] = b0 + t * (a0 - b0);
            out[1] = b1 + t * (a1 - b1);
            out[2] = b2 + t * (a2 - b2);
            out[3] = b3 + t * (a3 - b3);
            out[4] = b4 + t * (a4 - b4);
            out[5] = b5 + t * (a5 - b5);
            a += 6; b += 6; out += 6;
        }
        {
            unsigned int *s = (unsigned int *)temp;
            unsigned int *d = (unsigned int *)dst;
            d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3];
            d[4] = s[4]; d[5] = s[5]; d[6] = s[6]; d[7] = s[7];
            d[8] = s[8]; d[9] = s[9]; d[10] = s[10]; d[11] = s[11];
        }
    }
    *(short *)(dst + 0x30) = *(short *)(src + 0x6C);
    dst = (unsigned char *)arg1 + *(unsigned int *)(src + 8);
    *(unsigned int *)(dst + 0x34) = *(unsigned int *)(src + 0x1F0);
    *(unsigned int *)(dst + 0x38) = *(unsigned int *)(src + 0x1F4);
    *(float *)(dst + 0x3C) = PSVECDotProduct(src + 0x124, src + 0x3C);
    *(unsigned char *)(dst + 0x40) = *(unsigned char *)(src + 0x1F8);
}

#pragma pop

void fn_801B0174(void *this_) {
    f32 k2590;
    f32 threshold;
    f32 temp;
    f32 t64;
    u8 var0;
    u8 flagval;
    long var3;
    s32 v;

    fn_8017A57C(this_);
    threshold = lbl_8055E3C8;
    var0 = 0;
    temp = *(f32 *)((u8 *)this_ + 0x1EC);
    if (threshold > temp && threshold < lbl_8056258C + temp) {
        var0 = 1;
    }
    t64 = *(f32 *)((u8 *)this_ + 0x64);
    k2590 = -499.5f;
    *(u8 *)((u8 *)this_ + 0x1F8) = var0;
    if (t64 <= k2590) {
        *(u8 *)((u8 *)this_ + 0x1F8) = 0;
    }
    flagval = *(u8 *)((u8 *)this_ + 0x1F8);
    var3 = 0;
    if (flagval != 0 && threshold >= lbl_80562594 + *(f32 *)((u8 *)this_ + 0x1EC)) {
        var3 = 1;
    }
    if (var3) {
        v = *(s32 *)((u8 *)this_ + 0x28);
    } else {
        v = 0;
    }
    *(s32 *)((u8 *)this_ + 0x24) = v;
}

extern s32 fn_8017D274(u8 *);
extern void fn_8017B164(void);
extern void fn_8017A580(void *, f32);
extern f32 lbl_80562598;
extern f32 lbl_80562588;
#pragma cplusplus on
extern "C" void fn_801B022C(void *self) {
    /* Resets this audio/mix object: clears position/flags, sets +0x60..0x68 to
       (0, -500, 0), copies +0x28 into +0x24, invokes virtual callback slot f8 on
       the selected child (+0x14 when +0x28 > 0) setting its +0x24 to 1.0f, then
       clears lbl_8055E654 and +0x24. */
    class Callback {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    s32 selectedId;
    void *callback;
    f32 neg500;
    f32 zero;
    volatile f32 stackPos[3];

    fn_8017B164();
    zero = lbl_80562578;    /* 0.0f */
    neg500 = lbl_80562598;  /* -500.0f */
    *(volatile f32 *)((u8 *)self + 0x1EC) = zero;
    *(volatile u8 *)((u8 *)self + 0x1F8) = 0;
    stackPos[0] = zero;
    stackPos[1] = neg500;
    stackPos[2] = zero;
    *(volatile f32 *)((u8 *)self + 0x60) = zero;
    *(volatile f32 *)((u8 *)self + 0x64) = neg500;
    *(volatile f32 *)((u8 *)self + 0x68) = zero;
    ((void (*)(void *))fn_8017A580)(self);
    selectedId = *(s32 *)((u8 *)self + 0x28);
    *(s32 *)((u8 *)self + 0x24) = selectedId;
    if (selectedId > 0) {
        callback = *(void **)((u8 *)self + 0x14);
    } else {
        callback = NULL;
    }
    if (callback != NULL) {
        ((Callback *)callback)->f8();
        *(f32 *)((u8 *)callback + 0x24) = lbl_80562588; /* 1.0f */
    }
    lbl_8055E654 = 0;
    *(s32 *)((u8 *)self + 0x24) = 0;
}
#pragma cplusplus reset
extern f32 PSVECMag(void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern f32 PSVECDotProduct(void *, void *);
extern void fn_8017B81C(void);
extern void fn_8017B4AC(void *, void *);
extern s32 fn_801E9E30(void *, void *);
extern f32 lbl_80562578, lbl_80562588, lbl_80562598, lbl_8056259C;
extern f32 lbl_805625A0, lbl_805625A4, lbl_805625A8, lbl_805625AC;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801B02E0(void *arg0) {
    u8 *self = (u8 *)arg0;
    f32 velocityMag, speed, scale, factor;
    f32 vec[3];
    s32 result[3];
    f32 crossAxis[3];
    f32 axis[3];
    f32 v124, v128, v12c, v118, v11c, v120;
    f32 out124, out128, out12c, out118, out11c, out120;
    s32 active;
    if (*(u8 *)(self + 0x1F8) != 0) {
        fn_8017B81C();
        if (*(f32 *)(self + 0x64) < lbl_80562598)
            *(f32 *)(self + 0x64) = lbl_80562598;
        v124 = *(f32 *)(self + 0x124);
        v128 = *(f32 *)(self + 0x128);
        out124 = v124 * lbl_8056259C;
        v12c = *(f32 *)(self + 0x12C);
        out128 = v128 * lbl_8056259C;
        v118 = *(f32 *)(self + 0x118);
        out12c = v12c * lbl_8056259C;
        v11c = *(f32 *)(self + 0x11C);
        out118 = v118 * lbl_805625A0;
        v120 = *(f32 *)(self + 0x120);
        out11c = v11c * lbl_805625A0;
        out120 = v120 * lbl_805625A0;
        *(f32 *)(self + 0x124) = out124;
        *(f32 *)(self + 0x128) = out128;
        *(f32 *)(self + 0x12C) = out12c;
        *(f32 *)(self + 0x118) = out118;
        *(f32 *)(self + 0x11C) = out11c;
        *(f32 *)(self + 0x120) = out120;
        velocityMag = PSVECMag(self + 0x124);
        active = 1;
        if (velocityMag > lbl_805625A4) {
            speed = *(f32 *)(self + 0x40);
            crossAxis[0] = lbl_80562578;
            crossAxis[1] = lbl_80562588;
            crossAxis[2] = lbl_80562578;
            PSVECCrossProduct(self + 0x3C, crossAxis, vec);
            scale = lbl_805625A8 * speed;
            speed = PSVECMag(vec);
            {
                f32 denominator = (lbl_80562588 > speed) ? lbl_80562588 : speed;
                factor = scale / denominator;
            }
            vec[0] *= factor;
            vec[1] *= factor;
            vec[2] *= factor;
            fn_8017B4AC(arg0, vec);
            scale = PSVECDotProduct(self + 0x3C, self + 0x118) / velocityMag;
            axis[1] = lbl_805625AC * scale;
            axis[0] = lbl_80562578;
            axis[2] = lbl_80562578;
            fn_8017B4AC(arg0, axis);
            {
                s32 x;
                s32 y;
                y = *(volatile s32 *)(self + 0x60);
                x = *(volatile s32 *)(self + 0x64);
                result[0] = y;
                result[1] = x;
                result[2] = *(volatile s32 *)(self + 0x68);
            }
            if (fn_801E9E30(self + 0x6C, result) != 0)
                active = 0;
        }
        if (active != 0)
            *(f32 *)(self + 0x64) = lbl_80562598;
    } else {
        *(s32 *)(self + 0x1E4) = 0;
    }
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
/* Initializes an object from a 12-word matrix block, applies fn_8017A580, then copies
   two 3-float vectors and a 16-bit id into the object's fields. */
void fn_801B04B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    volatile s32 *matrixWords = (volatile s32 *)arg1;
    f32 *vecA = (f32 *)arg2;
    f32 *vecB = (f32 *)arg3;
    s16 *idSrc = (s16 *)arg4;
    s32 w11, w10, w9, w8, w7, w6, w5, w4, w3, w2, w1, w0;
    f32 vB2, vB1, vB0, vA2, vA1, vA0;
    s16 idValue;
    w0 = matrixWords[0];
    w1 = matrixWords[1];
    w2 = matrixWords[2];
    w3 = matrixWords[3];
    w4 = matrixWords[4];
    w5 = matrixWords[5];
    w6 = matrixWords[6];
    w7 = matrixWords[7];
    w8 = matrixWords[8];
    w9 = matrixWords[9];
    w10 = matrixWords[10];
    w11 = matrixWords[11];

    *(s32 *)((u8 *)arg0 + 0x3C) = w0;
    *(s32 *)((u8 *)arg0 + 0x40) = w1;
    *(s32 *)((u8 *)arg0 + 0x44) = w2;
    *(s32 *)((u8 *)arg0 + 0x48) = w3;
    *(s32 *)((u8 *)arg0 + 0x4C) = w4;
    *(s32 *)((u8 *)arg0 + 0x50) = w5;
    *(s32 *)((u8 *)arg0 + 0x54) = w6;
    *(s32 *)((u8 *)arg0 + 0x58) = w7;
    *(s32 *)((u8 *)arg0 + 0x5C) = w8;
    *(s32 *)((u8 *)arg0 + 0x60) = w9;
    *(s32 *)((u8 *)arg0 + 0x64) = w10;
    *(s32 *)((u8 *)arg0 + 0x68) = w11;
    ((void (*)(void *))fn_8017A580)(arg0);
    vA0 = vecA[0];
    vA1 = vecA[1];
    vA2 = vecA[2];
    vB0 = vecB[0];
    vB1 = vecB[1];
    vB2 = vecB[2];
    idValue = *idSrc;
    *(f32 *)((u8 *)arg0 + 0x118) = vA0;
    *(f32 *)((u8 *)arg0 + 0x11C) = vA1;
    *(f32 *)((u8 *)arg0 + 0x120) = vA2;
    *(f32 *)((u8 *)arg0 + 0x124) = vB0;
    *(f32 *)((u8 *)arg0 + 0x128) = vB1;
    *(f32 *)((u8 *)arg0 + 0x12C) = vB2;
    *(s16 *)((u8 *)arg0 + 0x6C) = idValue;
}
#pragma pop
/* Returns the serialized byte count: 0x21 when the caller's flag says the
 * extra payload follows the flag byte, otherwise just the single flag byte (1).
 * The object pointer is unused. */
s32 fn_801B0588(void *self, u8 *flag) {
    if (*flag != 0) return 0x21;
    return 1;
}

/* Serialize the optional extra payload: write the presence flag at +0x1F8 and, if set, append fn_8017D274's data. Returns bytes written. */
s32 fn_801B05A0(void *object, u8 *outBuffer) {
    *outBuffer = *(u8 *)((u8 *)object + 0x1F8);
    if (*(u8 *)((u8 *)object + 0x1F8) != 0)
        return (s32)(((u8 *(*)(void *, u8 *))fn_8017D274)(object, outBuffer + 1) + 1);
    return 1;
}

extern void fn_8017D160(void *, u8 *, u8 *, s32 *, s32 *, f32);
extern f32 lbl_805625B0;
#pragma push
#pragma cplusplus on
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" void fn_801B05E4(void *arg0, u8 *arg1, u8 *arg2, s32 *arg3, s32 *arg4, f32 arg5) {
    class Callback0 {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8();
        virtual s32 get();
    };
    class Callback1 {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8();
        virtual s32 get(u8 *);
    };
    s32 spC;
    s32 sp8;
    u8 firstFlag;
    s32 result;
    f32 zeroValue;
    f32 resetValue;
    *arg3 = ((Callback0 *)arg0)->get();
    result = ((Callback1 *)arg0)->get(arg2);
    firstFlag = *arg1;
    *arg4 = result;
    if (firstFlag == 0) goto fallback;
    if (*arg2 == 0) goto fallback;
    *(u8 *)((u8 *)arg0 + 0x1F8) = 1;
    fn_8017D160(arg0, arg1 + 1, arg2 + 1, &spC, &sp8, arg5);
    return;
fallback:
    zeroValue = lbl_80562578;
    resetValue = lbl_805625B0;
    *(u8 *)((u8 *)arg0 + 0x1F8) = 0;
    *(f32 *)((u8 *)arg0 + 0x64) = resetValue;
    *(f32 *)((u8 *)arg0 + 0x118) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x11C) = zeroValue;
    *(f32 *)((u8 *)arg0 + 0x120) = zeroValue;
}
#pragma pop
void __AXDSPInitCallback_801AFC38(void) {
    /* AX DSP init callback: reset the count of registered sound/effect objects. */
    sEffectCount = 0;
}

extern void *lbl_80435BA8[];
extern void *fn_8017960C(void *);
extern void fn_801B04B0(void *, s32, s32, s32, void *);
#pragma scheduling invalid_target
void fn_801AFC44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    /* Update the current lbl_80435BA8 effect object for arg0/arg1 with params from base+0x6C,
       copy a per-arg1 float from base into its selected subobject, and advance/wrap lbl_8055E654. */
    void *effectObject;
    void *baseData;
    s32 count;
    void *subObject;
    f32 value;

    if ((s32)lbl_8055E650 < 1) return;
    effectObject = lbl_80435BA8[(s32)lbl_8055E654];
    baseData = fn_8017960C((void *)arg0);
    fn_801B04B0(effectObject, arg2, arg3, arg4, (u8 *)baseData + 0x6C);
    value = lbl_8055E3C8;
    *(s32 *)((u8 *)effectObject + 0x1F0) = arg0;
    *(s32 *)((u8 *)effectObject + 0x1F4) = arg1;
    *(f32 *)((u8 *)effectObject + 0x1EC) = value;
    count = *(s32 *)((u8 *)effectObject + 0x28);
    *(s32 *)((u8 *)effectObject + 0x24) = count;
    if (count > 0) subObject = *(void **)((u8 *)effectObject + 0x14);
    else subObject = 0;
    value = *(f32 *)((u8 *)baseData + arg1 * 0x74 + 0x23E8);
    *(f32 *)((u8 *)subObject + 0x24) = value;
    count = (s32)lbl_8055E654 + 1;
    lbl_8055E654 = (void *)count;
    if (count < (s32)lbl_8055E650) return;
    lbl_8055E654 = 0;
}
#pragma scheduling on
