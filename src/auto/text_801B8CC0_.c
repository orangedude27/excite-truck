#include <revolution/MTX/mtxtypes.h>
void fn_801836E0(void *, int);
void fn_80128668(void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80562754;
extern float lbl_80562758;
extern float lbl_8056275C;
extern float lbl_80562760;
extern float PSVECDotProduct(const float *, const float *);
extern void fn_8018381C(void *);
extern void fn_80189C64(void *, void **);
extern void fn_8018A08C(void *);
extern void fn_801AD148(void *, float *, void *, float, float, float);
extern void fn_801AD28C(void *, float *, void *, void *, float, float, float);
// split_file divides it into the game's real files (file_status shows its range).

extern void* __AXFXGetLfoSinTable_801769CC(void);
extern int lbl_8055E774;
extern float lbl_80562764;
extern void* lbl_80436D28[];

static inline void transform_vec(float *out, const float *m, volatile float *in) {
    if (out == in) {
        register float x = in[0];
        register float y = in[1];
        register float z = in[2];
        float x0 = x * m[0] + y * m[3] + z * m[6];
        float x1 = x * m[1] + y * m[4] + z * m[7];
        float x2 = x * m[2] + y * m[5] + z * m[8];
        out[0] = x0;
        out[1] = x1;
        out[2] = x2;
    } else {
        out[0] = in[1] * m[3] + in[0] * m[0] + in[2] * m[6];
        out[1] = in[1] * m[4] + in[0] * m[1] + in[2] * m[7];
        out[2] = in[1] * m[5] + in[0] * m[2] + in[2] * m[8];
    }
}
#pragma cplusplus on
extern "C" static inline void transform_vec_struct(Vec *out, const float *m, volatile Vec *in) {
    if (out == in) {
        float x = in->x;
        float y = in->y;
        float z = in->z;
        float x0 = x * m[0] + y * m[3] + z * m[6];
        float x1 = x * m[1] + y * m[4] + z * m[7];
        float x2 = x * m[2] + y * m[5] + z * m[8];
        out->x = x0;
        out->y = x1;
        out->z = x2;
    } else {
        out->x = in->y * m[3] + in->x * m[0] + in->z * m[6];
        out->y = in->y * m[4] + in->x * m[1] + in->z * m[7];
        out->z = in->y * m[5] + in->x * m[2] + in->z * m[8];
    }
}
static inline void transform_vec_scheduled(float *out, const float *m, float *in) {
if (out == in) {
float m3 = m[3];
float y = in[1];
float m4 = m[4];
float m5 = m[5];
float m0 = m[0];
float x = in[0];
float m1 = m[1];
float m2 = m[2];
float m6 = m[6];
float z = in[2];
float m7 = m[7];
float m8 = m[8];
out[0] = z * m6 + (x * m0 + y * m3);
out[1] = z * m7 + (x * m1 + y * m4);
out[2] = z * m8 + (x * m2 + y * m5);
} else {
float m3 = m[3];
float m0 = m[0];
float m6 = m[6];
out[0] = in[2] * m6 + (in[0] * m0 + in[1] * m3);
float m4 = m[4];
float m1 = m[1];
float m7 = m[7];
out[1] = in[2] * m7 + (in[0] * m1 + in[1] * m4);
float m5 = m[5];
float m2 = m[2];
float m8 = m[8];
out[2] = in[2] * m8 + (in[0] * m2 + in[1] * m5);
}

}
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma cplusplus on
extern "C" int fn_801E320C(int, int);
extern "C" void *fn_801E3004(int, int, int);
extern "C" void fn_801E3488(void *, void *);
extern "C" void fn_801E323C(void *);
extern "C" int fn_802C7A10(int);
extern "C" void fn_802E30C8(const char *, ...);
extern "C" char lbl_803369A0[];
#pragma scheduling invalid_target
extern "C" void fn_801B8CC0(float *arg0, int arg1, int *arg2, float *arg3, float arg4, float arg5) {
    unsigned int a = ((unsigned int *)arg3)[0];
    unsigned int b = ((unsigned int *)arg3)[1];
    unsigned int c = ((unsigned int *)arg3)[2];
    unsigned int *dst;
    void *p;
    int result;

    dst = (unsigned int *)arg0;
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    result = fn_801E320C(arg1, (int)arg2);
    if (result != 0) {
        p = fn_801E3004(arg1, (int)arg2, -1);
        if (p != 0) {
            fn_801E3488(arg0, p);
            fn_801E323C(p);
        }
    } else {
        result = fn_802C7A10(arg1);
        fn_802E30C8(lbl_803369A0, (int)arg2, result);
    }
}
#pragma scheduling on
#pragma cplusplus reset
extern "C" void *fn_801B8D80(void) {
    extern void *fn_801284F8(unsigned int, void *);
    extern void fn_80182010(void *);
    extern int fn_8017960C(int);
    extern char lbl_803369C0[];
    extern char lbl_803369D0[];
    extern void *lbl_80436D28[];
    extern float lbl_80562750;
    void *obj;
    void *vtable;
    float value;
    int zero;
    int index;

    obj = fn_801284F8(0x2760, lbl_803369C0);
    if (obj != 0) {
        fn_80182010(obj);
        vtable = lbl_803369D0;
        value = lbl_80562750;
        *(void **)obj = vtable;
        zero = 0;
        *(int *)((char *)obj + 0x2738) = zero;
        *(int *)((char *)obj + 0x2710) = zero;
        *(float *)((char *)obj + 0x272C) = value;
        *(float *)((char *)obj + 0x2730) = value;
        index = lbl_8055E774;
        *(int *)((char *)obj + 0x2700) = index;
        lbl_8055E774 = index + 1;
        lbl_80436D28[*(int *)((char *)obj + 0x2700)] = obj;
        *(int *)((char *)obj + 0x2754) =
            fn_8017960C(*(int *)((char *)obj + 0x2700));
        *(unsigned char *)((char *)obj + 0x275C) = zero;
    }
    return obj;
}
#pragma cplusplus reset
#pragma scheduling on
#pragma pop
extern "C" void fn_801B8E28(int arg0) {
    struct Dummy {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18();
        virtual void v19(unsigned int *, void *);
    };
    struct ObjectLayout {
        char pad[0x2748];
        Vec position;
    };
    void *obj = lbl_80436D28[arg0];
    struct Work {
        volatile float input[3];
        float sp14[3];
        float sp20[3];
        Vec copy[3];
        float output[3];
        volatile float fx, fy, fz;
        volatile int zero;
        volatile short h;
    } w;
    register float temp_f2, temp_f3, temp_f1, temp_f1_2;
    float dot;

    fn_80189C64(obj, lbl_80436D28);
    temp_f3 = *(float *)((char *)obj + 0x2748) - *(float *)((char *)obj + 0x273c);
    w.input[0] = temp_f3;
    temp_f2 = *(float *)((char *)obj + 0x274c) - *(float *)((char *)obj + 0x2740);
    w.input[1] = temp_f2;
    temp_f1 = *(float *)((char *)obj + 0x2750) - *(float *)((char *)obj + 0x2744);
    w.input[2] = temp_f1;
    w.input[0] = temp_f3 - *(float *)((char *)obj + 0x30);
    w.input[1] = temp_f2 - *(float *)((char *)obj + 0x34);
    temp_f1_2 = temp_f1 - *(float *)((char *)obj + 0x38);
    w.input[2] = temp_f1_2;
    if (*(unsigned char *)((char *)obj + 0x275d) != 0) {
        w.input[2] = temp_f1_2 - lbl_80562754;
    }
    w.h = -1;
    {
        char *matrix = *(char **)((char *)obj + 0x2754);
        transform_vec_scheduled(w.output, (const float *)(matrix + 0x70), (float *)w.input);
        w.output[0] += *(float *)(matrix + 0x94);
        w.output[1] += *(float *)(matrix + 0x98);
        w.output[2] += *(float *)(matrix + 0x9c);
    }
    {
        Vec *matrix = (Vec *)((char *)*(void **)((char *)obj + 0x2754) + 0x70);
        w.copy[0] = matrix[0];
        w.copy[1] = matrix[1];
        w.copy[2] = matrix[2];
    }
    dot = PSVECDotProduct((float *)((char *)*(void **)((char *)obj + 0x2754) + 0x118), (float *)((char *)obj + 0x54));
    w.fx = w.copy[2].x * dot;
    w.zero = 0;
    w.fy = w.copy[2].y * dot;
    w.fz = w.copy[2].z * dot;
    {
        void *matrix = *(void **)((char *)obj + 0x2754);
        w.h = *(short *)((char *)matrix + 0x6c);
        ((struct Dummy *)obj)->v19((unsigned int *)w.copy, matrix);
    }
    *(void **)((char *)obj + 0x2738) = obj;
    if (*(unsigned char *)((char *)obj + 0x275d) == 0) {
        w.sp14[0] = *(float *)((char *)obj + 0x273c) + *(float *)((char *)obj + 0x30);
        w.sp14[1] = *(float *)((char *)obj + 0x2740) + *(float *)((char *)obj + 0x34);
        temp_f3 = *(float *)((char *)obj + 0x2744);
        w.sp14[2] = temp_f3 + *(float *)((char *)obj + 0x38);
        fn_801AD148((char *)obj + 0x2704, w.sp14, *(void **)((char *)obj + 0x2754), lbl_80562758, lbl_8056275C, temp_f3);
    } else {
        w.sp20[0] = *(float *)((char *)obj + 0x273c) + *(float *)((char *)obj + 0x30);
        w.sp20[1] = *(float *)((char *)obj + 0x2740) + *(float *)((char *)obj + 0x34);
        temp_f3 = *(float *)((char *)obj + 0x2744);
        w.sp20[2] = temp_f3 + *(float *)((char *)obj + 0x38);
        fn_801AD28C((char *)obj + 0x2704, w.sp20, *(void **)((char *)obj + 0x2754), &((struct ObjectLayout *)obj)->position, lbl_80562758, lbl_80562760, temp_f3);
    }
    fn_8018A08C((void *)obj);
}
#pragma cplusplus reset
void fn_801B916C(void *arg0) {
    void **table;
    int *p;
    int i;
    int sentinel;
    float frequency;
    if (((int *)__AXFXGetLfoSinTable_801769CC())[1] & 0x400) {
        table = lbl_80436D28;
        frequency = lbl_80562764;
        p = (int *)arg0 + 1;
        i = 0;
        sentinel = -1;
        while (i < *(int *)((char *)arg0 + 0x394)) {
            int index = p[0x60 / 4];
            void *obj;
            if (index < 0) goto no_object;
            if (index >= lbl_8055E774) goto no_object;
            obj = table[index];
            goto have_object;
        no_object:
            obj = 0;
        have_object:
            if (obj != 0) {
                int id = *(int *)((char *)obj + 0x1EC);
                if (p[0x74 / 4] == id)
                    p[0x74 / 4] = sentinel;
                {
                    volatile int *slots = p + 0x8C / 4;
                    if (slots[0] == id) slots[0] = sentinel;
                    if (slots[6] == id) slots[6] = sentinel;
                    if (slots[12] == id) slots[12] = sentinel;
                }
                p[0x74 / 4] = id;
                *(float *)(p + 0x78 / 4) = frequency;
                {
                    float value0;
                    float value1;
                    value0 = *(float *)((char *)obj + 0x2690);
                    *(float *)(p + 0x7C / 4) = value0;
                    value1 = *(float *)((char *)obj + 0x2694);
                    *(float *)(p + 0x80 / 4) = value1;
                    *(float *)(p + 0x84 / 4) = value0 - value1;
                }
                p[0x88 / 4] = *(int *)((char *)obj + 0x268C);
            }
            p += 0xE0 / 4;
            i++;
        }
    }
}

#pragma scheduling invalid_target
#pragma cplusplus off
void *fn_801B9274(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        s32 index = *(s32 *)((char *)arg0 + 0x2700);
        lbl_8055E774--;
        lbl_80436D28[index] = 0;
        fn_801836E0(arg0, 0);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma cplusplus reset
#pragma scheduling on
extern float lbl_80562750;
extern float lbl_80562768;
extern float lbl_8056276C;
extern float lbl_80562770;
extern float lbl_80562774;
extern float lbl_80562778;
extern int lbl_8055A918;
extern void fn_80182074(void *, int);
extern void fn_801B8CC0(float *, int, int *, float *, float, float);
extern void fn_802C77F0(int, float *);
#pragma scheduling invalid_target
void fn_801B92F0(void *arg0, int arg1) {
    struct Work {
        float sp8[3]; float sp14[3]; float sp20[3]; float sp2c[3];
        float sp38[3]; float sp44[3]; float sp50[3]; float sp5c[3];
        float sp68[3]; char pad74[4]; float sp78[6]; float sp90[6];
    };
    union { double align; struct Work work; } frame;
    unsigned int bits = ((unsigned int *)__AXFXGetLfoSinTable_801769CC())[1];
    float *copySrc;
    unsigned int word2, word1, word0;
    float result, top, zero, param1, out0, out1, out2;

    *((unsigned char *)arg0 + 0x275d) = (bits >> 12) & 1;
    fn_80182074(arg0, arg1);
    frame.work.sp44[0] = lbl_80562750;
    frame.work.sp44[1] = lbl_80562750;
    frame.work.sp44[2] = lbl_80562768;
    ((unsigned int *)frame.work.sp50)[0] = ((unsigned int *)frame.work.sp44)[0];
    ((unsigned int *)frame.work.sp50)[1] = ((unsigned int *)frame.work.sp44)[1];
    ((unsigned int *)frame.work.sp50)[2] = ((unsigned int *)frame.work.sp44)[2];
    fn_801B8CC0(frame.work.sp5c, *(int *)((unsigned char *)arg0 + 0x59c),
        &lbl_8055A918, frame.work.sp50, lbl_80562750, lbl_80562750);
    *(float *)((unsigned char *)arg0 + 0x273c) = frame.work.sp5c[0];
    *(float *)((unsigned char *)arg0 + 0x2740) = frame.work.sp5c[1];
    *(float *)((unsigned char *)arg0 + 0x2744) = frame.work.sp5c[2];

    fn_802C77F0(*(int *)((unsigned char *)arg0 + 0x59c), frame.work.sp90);
    if (*((unsigned char *)arg0 + 0x275d)) {
        top = frame.work.sp90[5];
        result = top - lbl_8056276C;
        zero = lbl_80562750;
        frame.work.sp38[0] = zero;
        frame.work.sp38[1] = zero;
        frame.work.sp38[2] = result;
        *(float *)((unsigned char *)arg0 + 0x273c) = zero;
        *(float *)((unsigned char *)arg0 + 0x2740) = zero;
        *(float *)((unsigned char *)arg0 + 0x2744) = result;
    }

    fn_802C77F0(*(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x2754) + 0x59c),
        frame.work.sp78);
    if (*((unsigned char *)arg0 + 0x275d)) {
        top = frame.work.sp78[4];
        param1 = lbl_80562750;
        result = top - lbl_80562770;
        frame.work.sp2c[0] = param1;
        frame.work.sp2c[1] = param1;
        frame.work.sp2c[2] = result;
        copySrc = frame.work.sp2c;
    } else {
        top = frame.work.sp78[4];
        param1 = lbl_80562774;
        result = top - lbl_8056276C;
        frame.work.sp20[0] = lbl_80562750;
        frame.work.sp20[1] = param1;
        frame.work.sp20[2] = result;
        copySrc = frame.work.sp20;
    }
    word0 = ((unsigned int *)copySrc)[0];
    word1 = ((unsigned int *)copySrc)[1];
    word2 = ((unsigned int *)copySrc)[2];
    ((unsigned int *)frame.work.sp68)[0] = word0;
    ((unsigned int *)frame.work.sp8)[0] = word0;
    ((unsigned int *)frame.work.sp68)[1] = word1;
    ((unsigned int *)frame.work.sp8)[1] = word1;
    ((unsigned int *)frame.work.sp68)[2] = word2;
    ((unsigned int *)frame.work.sp8)[2] = word2;
    fn_801B8CC0(frame.work.sp14,
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x2754) + 0x59c),
        &lbl_8055A918, frame.work.sp8, param1, result);
    out0 = frame.work.sp14[0];
    out1 = frame.work.sp14[1];
    out2 = frame.work.sp14[2];
    *(float *)((unsigned char *)arg0 + 0x2748) = out0;
    *(float *)((unsigned char *)arg0 + 0x274c) = out1;
    *(float *)((unsigned char *)arg0 + 0x2750) = out2;
    *(float *)((unsigned char *)arg0 + 0x274c) = out1 + lbl_80562778;
}
#pragma scheduling on
void fn_801B949C(void *arg0) {
    short sp6c;
    int sp68;
    float sp64;
    float sp60;
    float sp5c;
    unsigned int sp2c[9];
    float sp8[3];
    float sp50[3];
    float sp14[3];
    float sp20[3];
    float dot;
    float factorX;
    float factorY;
    float factorZ;
    float *matrix;
    float *dst;
    float *src;
    float x, y, z;
    unsigned char flag;

    *(unsigned char *)((char *)arg0 + 0x275c) = 0;
    *(float *)((char *)arg0 + 0x2758) = lbl_80562750;
    fn_8018381C(arg0);

    sp8[0] = *(float *)((char *)arg0 + 0x2748) - *(float *)((char *)arg0 + 0x273c);
    sp8[1] = *(float *)((char *)arg0 + 0x274c) - *(float *)((char *)arg0 + 0x2740);
    sp8[2] = *(float *)((char *)arg0 + 0x2750) - *(float *)((char *)arg0 + 0x2744);
    sp8[0] -= *(float *)((char *)arg0 + 0x30);
    sp8[1] -= *(float *)((char *)arg0 + 0x34);
    sp8[2] -= *(float *)((char *)arg0 + 0x38);
    flag = *(unsigned char *)((char *)arg0 + 0x275d);
    if (flag != 0) {
        sp8[2] -= lbl_80562754;
    }

    sp6c = -1;
    matrix = *(float **)((char *)arg0 + 0x2754);
    dst = sp50;
    src = sp8;
    if (dst == src) {
        x = sp8[0] * matrix[0x70 / 4] + sp8[1] * matrix[0x7c / 4];
        y = sp8[0] * matrix[0x74 / 4] + sp8[1] * matrix[0x80 / 4];
        z = sp8[0] * matrix[0x78 / 4] + sp8[1] * matrix[0x84 / 4];
        x += sp8[2] * matrix[0x88 / 4];
        y += sp8[2] * matrix[0x8c / 4];
        z += sp8[2] * matrix[0x90 / 4];
        dst[0] = x; dst[1] = y; dst[2] = z;
    } else {
        dst[0] = sp8[0] * matrix[0x70 / 4] + sp8[1] * matrix[0x7c / 4] + sp8[2] * matrix[0x88 / 4];
        dst[1] = sp8[0] * matrix[0x74 / 4] + sp8[1] * matrix[0x80 / 4] + sp8[2] * matrix[0x8c / 4];
        dst[2] = sp8[0] * matrix[0x78 / 4] + sp8[1] * matrix[0x84 / 4] + sp8[2] * matrix[0x90 / 4];
    }

    sp50[0] += matrix[0x94 / 4];
    sp50[1] += matrix[0x98 / 4];
    sp50[2] += matrix[0x9c / 4];

    sp2c[0] = ((unsigned int *)matrix)[0x70 / 4];
    sp2c[1] = ((unsigned int *)matrix)[0x74 / 4];
    sp2c[2] = ((unsigned int *)matrix)[0x78 / 4];
    sp2c[3] = ((unsigned int *)matrix)[0x7c / 4];
    sp2c[4] = ((unsigned int *)matrix)[0x80 / 4];
    sp2c[5] = ((unsigned int *)matrix)[0x84 / 4];
    sp2c[6] = ((unsigned int *)matrix)[0x88 / 4];
    sp2c[7] = ((unsigned int *)matrix)[0x8c / 4];
    sp2c[8] = ((unsigned int *)matrix)[0x90 / 4];
    dot = PSVECDotProduct((float *)((char *)matrix + 0x118), (float *)((char *)arg0 + 0x54));
    factorX = ((float *)((char *)matrix + 0x88))[0] * dot;
    sp68 = 0;
    factorY = ((float *)((char *)matrix + 0x8c))[0] * dot;
    sp5c = factorX;
    sp60 = factorY;
    factorZ = ((float *)((char *)matrix + 0x90))[0] * dot;
    sp64 = factorZ;
    sp6c = *(short *)((char *)matrix + 0x6c);
    {
        typedef void (*VFunc)(void *, float *, void *, float, float);
        void **vtable = *(void ***)arg0;
        VFunc method = (VFunc)*(void **)((char *)vtable + 0x54);
        method(arg0, (float *)sp2c, matrix, factorY, factorX);
    }

    *(void **)((char *)arg0 + 0x2738) = arg0;
    if (*(unsigned char *)((char *)arg0 + 0x275d) == 0) {
        sp14[0] = *(float *)((char *)arg0 + 0x273c) + *(float *)((char *)arg0 + 0x30);
        sp14[1] = *(float *)((char *)arg0 + 0x2740) + *(float *)((char *)arg0 + 0x34);
        sp14[2] = *(float *)((char *)arg0 + 0x2744) + *(float *)((char *)arg0 + 0x38);
        fn_801AD148((char *)arg0 + 0x2704, sp14, matrix, lbl_80562758, lbl_8056275C, *(float *)((char *)arg0 + 0x2744));
    } else {
        sp20[0] = *(float *)((char *)arg0 + 0x273c) + *(float *)((char *)arg0 + 0x30);
        sp20[1] = *(float *)((char *)arg0 + 0x2740) + *(float *)((char *)arg0 + 0x34);
        sp20[2] = *(float *)((char *)arg0 + 0x2744) + *(float *)((char *)arg0 + 0x38);
        fn_801AD28C((char *)arg0 + 0x2704, sp20, matrix, (char *)arg0 + 0x2748, lbl_80562758, lbl_80562760, *(float *)((char *)arg0 + 0x2744));
    }
}

