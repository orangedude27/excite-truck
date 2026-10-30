#include "revolution/MTX/mtxtypes.h"
#include "math.h"
extern float lbl_80558DC4;
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
    s32 temp_r5 = *(s32 *)arg0 * 0x108;
    conversion.words[0] = 0x43300000;
    conversion.words[1] = *(u8 *)((u8 *)arg0 + 8);
    *(u8 *)((u8 *)(lbl_8055F928 + temp_r5) + 0xC4) = 1;
    *(f32 *)((u8 *)(lbl_8055F928 + temp_r5) + 0xD4) = *(f32 *)((u8 *)arg0 + 4);
    *(f32 *)((u8 *)(lbl_8055F928 + temp_r5) + 0xD8) = (f32)conversion.value - lbl_805649E8;
    return 0xC;
}

s32 fn_802A9F90(s32 *arg0) {
    extern int lbl_8055F928;
    *(u8 *)((u8 *)(lbl_8055F928 + (*arg0 * 0x108)) + 0xDC) = 1;
    return 4;
}

#pragma scheduling invalid_target
s32 fn_802A9FB0(void *arg0) {
    extern int lbl_8055F928;
    int index = *(int *)arg0;
    int offset = index * 0x108;
    unsigned char value = *((unsigned char *)arg0 + 4);
    *(unsigned char *)(lbl_8055F928 + offset + 0xEC) = 1;
    *(unsigned char *)(lbl_8055F928 + offset + 0xF4) = value;
    return 8;
}
#pragma scheduling on
void fn_802A9FE0(void *arg0) {
    float value = lbl_805649F0;
    int i;
    for (i = 0; i <= 0xC0; i += 4) *(float *)((char *)arg0 + i) = value;
    *(unsigned char *)((char *)arg0 + 0xC4) = 0;
    *(float *)((char *)arg0 + 0xCC) = value;
    *(float *)((char *)arg0 + 0xC8) = value;
    *(float *)((char *)arg0 + 0xD0) = value;
    *(float *)((char *)arg0 + 0xD4) = value;
    *(float *)((char *)arg0 + 0xD8) = value;
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
void fn_802AA1D0(unsigned int arg0) {
    extern int lbl_8055F928;
    extern int lbl_80488648[];
    extern int fn_801EE0C8(int);
    extern void fn_802C77F0(int, float *);
    float sp[8];
    int *p = (int *)(lbl_8055F928 + arg0 * 0x108);
    int v = fn_801EE0C8(arg0 < 8 ? lbl_80488648[arg0] : 0);
    fn_802C77F0(v, sp);
    *(float *)((char *)p + 0xF8) = sp[1] - sp[0];
    *(float *)((char *)p + 0x100) = sp[3] - sp[2];
    *(float *)((char *)p + 0xFC) = sp[5] - sp[4];
}

#pragma push
#pragma processor 750
void fn_802AA9D4(void *arg0, void *arg1, float delta) {
 extern float lbl_805649F4, lbl_80564A08, lbl_80564A04, lbl_80564A48, lbl_80564A4C, lbl_80564A50;
 extern float fn_80287BC8(float, float);
 extern void fn_8028E590(int, Vec *, Vec *, float);
 Vec pos, dir, callpos, calldir, side, forward;
 float width = lbl_805649F4 * *(float *)((char *)arg0+0xF8);
 float depth = lbl_805649F4 * *(float *)((char *)arg0+0xFC);
 float height = lbl_805649F4 * *(float *)((char *)arg0+0x100);
 float v, angle, scale;
 if (*(unsigned char *)((char *)arg0+0xDC)) {
   *(unsigned char *)((char *)arg0+0xDC)=0;
   v=*(float *)((char *)arg0+0xE0)+lbl_80564A08*delta;
   *(float *)((char *)arg0+0xE0)=v<lbl_805649FC?v:lbl_805649FC;
 } else {
   v=*(float *)((char *)arg0+0xE0)-lbl_80564A08*delta;
   *(float *)((char *)arg0+0xE0)=v>lbl_805649F0?v:lbl_805649F0;
 }
 if ((float)fabs(delta)<=lbl_80558DC4) return;
 if (fn_80287BC8(lbl_805649F0,lbl_805649FC)>=*(float *)((char *)arg0+0xE0)) return;
 angle=fn_80287BC8(lbl_80564A48,lbl_80564A4C);
 forward=*(Vec *)arg1;
 side=*(Vec *)((char *)arg1+0x18);
 pos=*(Vec *)((char *)arg1+0x24);
 scale=width*(float)cos(angle);
 pos.x+=forward.x*scale; pos.y+=forward.y*scale; pos.z+=forward.z*scale;
 scale=depth*(float)sin(angle);
 pos.x+=side.x*scale; pos.y+=side.y*scale; pos.z+=side.z*scale;
 scale=fn_80287BC8(lbl_805649F0,lbl_80564A04*height);
 pos.x+=*(float *)((char *)arg1+0xC)*scale;
 pos.y+=*(float *)((char *)arg1+0x10)*scale;
 pos.z+=*(float *)((char *)arg1+0x14)*scale;
 dir=*(Vec *)((char *)arg1+0x34);
 if (*(float *)((char *)arg1+0x4C)>=lbl_80564A50-lbl_80558DC4) {
 callpos=pos; calldir=dir;
 fn_8028E590(*(int *)lbl_8055F924,&callpos,&calldir,lbl_805649FC);
 }
}
#pragma pop

#pragma scheduling invalid_target
void fn_802AAC80(void *arg0, void *arg1, float farg0) {
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
    volatile unsigned char *flag = &object->m_flag;
    volatile float *value = &object->m_value;
    fn_801E86F8(0);
    if (*flag) {
        float limit, current, delta, step;
        step = *(volatile float *)&lbl_80564A04;
        current = *value;
        delta = step * farg0;
        limit = *(volatile float *)&lbl_805649FC;
        *flag = 0;
        current += delta;
        object->m_value = current < limit ? current : limit;
    } else if (state->m_condition) {
        object->m_value = lbl_805649F0;
    } else {
        float limit, current, delta, step;
        step = *(volatile float *)&lbl_80564A04;
        current = *value;
        delta = step * farg0;
        limit = *(volatile float *)&lbl_805649F0;
        current -= delta;
        object->m_value = current > limit ? current : limit;
    }
    if (state->m_flags & 8)
        object->m_value = lbl_805649F0;
}
#pragma scheduling on
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
            temp_f0 = lbl_8055CC6C *
                (temp_f2 * (lbl_80564A54 *
                    (*(float *)((char *)arg1 + 0xCC) *
                     *(float *)((char *)arg1 + 0xD0))));
            if (temp_f0 < lbl_805649F0) temp_f0 -= lbl_805649F4;
            else temp_f0 += lbl_805649F4;
            alpha = (int)temp_f0;
            color0 = (unsigned char)lbl_8055CC70;
            color1 = (unsigned char)lbl_8055CC78;
            color2 = (unsigned char)lbl_8055CC74;
            temp_f4 = (i & 1) ? lbl_805649F0 : lbl_805649FC;
            fn_802C8E00((color1 << 8) | color2 | (color0 << 16) | (alpha << 24),
                1, sp8, spC, sp10, temp_f4, temp_f31 - temp_f2);
        }
        fn_802C8E48();
    }
    fn_802C8D74();
}

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
#pragma scheduling on
#pragma pop
void fn_802AB500(void) {}

void fn_802AB504(void) {
    extern void fn_801EF024(void (*)(void));
    extern void fn_80128670(void *);
    extern void fn_802CAC54(int);
    extern s32 fn_802A9F30(void *), fn_802A9F90(s32 *);
    extern s32 fn_802A9FB0(void *);
    extern unsigned char lbl_8055F92C;
    extern void *lbl_8055F924;
    extern int lbl_8055F928, lbl_8055CC60, lbl_8055CC64;
    int *p;
    int *q;
    lbl_8055F92C = 0;
    fn_801EF024((void (*)(void))fn_802A9F30);
    fn_801EF024((void (*)(void))fn_802A9F90);
    fn_801EF024((void (*)(void))fn_802A9FB0);
    p = (int *)lbl_8055F924;
    if (p) {
        fn_8028E398(p[0]);
        fn_8028E398(p[1]);
        fn_80128668(p);
    }
    lbl_8055F924 = 0;
    q = (int *)lbl_8055F928;
    if (q) fn_80128670((char *)q - 0x10);
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
void fn_802AB628(float farg0) {
    extern int fn_80287B14(void);
    extern int fn_80287B24(int);
    extern void fn_802AA25C(void *, void *, float);
    extern int lbl_8055F928;
    int count = fn_80287B14();
    int offset;
    int i;
    int object;
    int base;
    i = 0;
    offset = i;
    goto check;
loop:
    object = fn_80287B24(i);
    base = lbl_8055F928 + offset;
    fn_802AA1D0(i);
    fn_802AA25C((void *)base, (void *)object, farg0);
    fn_802AA9D4((void *)base, (void *)object, farg0);
    fn_802AAC80((void *)base, (void *)object, farg0);
    offset += 0x108;
    i += 1;
check:
    if (i < count)
        goto loop;
}
#pragma pop
void fn_802AB6D0(void) {}

#pragma push
#pragma use_lmw_stmw off
void fn_802AB6D4(void) {
    extern int fn_80287B14(void);
    extern int fn_80287B24(int);
    extern int fn_802C86DC(void);
    extern void fn_802AAD5C(int, int, int);
    extern void fn_802AAF00(int, int, int);
    extern void fn_802AAF04(int, int, int);
    extern int lbl_8055F928;
    int count = fn_80287B14();
    int obj = fn_802C86DC();
    int i;
    for (i = 0; i < count; i++) {
        int item = fn_80287B24(i);
        int data = lbl_8055F928 + i * 0x108;
        fn_802AAD5C(obj, data, item);
        fn_802AAF00(obj, data, item);
        fn_802AAF04(obj, data, item);
    }
}

void fn_802AB770(int arg0) {
    extern int lbl_8055F928;
    extern unsigned char lbl_8055F92C, lbl_8055F92D;
    extern float lbl_805649F0, lbl_805649F4, lbl_805649FC;
    extern float lbl_80564A00, lbl_80564A34, lbl_80564A68, lbl_80564A8C, lbl_80564A98, lbl_80564A9C;
    extern float lbl_80564AA8, lbl_80564AAC;
    extern double lbl_80564AA0;
    extern int lbl_804BD7B0[4];
    extern float fn_801E7E24(void);
    extern unsigned char fn_80129D90(int, int, int);
    extern float fn_80287BC8(float, float);
    extern double fn_8002EFB4(float, double);
    extern int fn_802C2C00(int);
    extern int fn_802C990C(int);
    extern void fn_802C2BB8(int *, int *, int *);
    extern void fn_802C2B78(float, float, float);
    float delta = fn_801E7E24();
    char *state = (char *)(lbl_8055F928 + arg0 * 0x108);
    int obj = fn_80287B24(lbl_8055F928);
    float angle;
    float wave;
    int color;
    if (delta < -*(float *)(void *)&lbl_80558DC4 || delta > *(float *)(void *)&lbl_80558DC4) {
        int r = fn_80129D90(0, 0x8C, 0xFF);
        int g = fn_80129D90(0, 0xFA, 0xFF);
        int b = fn_80129D90(0, 0xF0, 0xFF);
        *(int *)(state + 0xE8) = (b << 16) | (g << 8) | r | 0xFF000000;
    }
    angle = *(float *)((char *)obj + 0x4C);
    if (lbl_8055F92C != 0) angle = lbl_80564A98;
    if (*(float *)(state + 0xE4) > lbl_805649F4)
        *(float *)(state + 0xE4) = fn_80287BC8(lbl_80564A8C, lbl_80564A68);
    else
        *(float *)(state + 0xE4) += lbl_80564A34 * delta;
    wave = lbl_805649F0;
    if (delta < -*(float *)(void *)&lbl_80558DC4 || delta > *(float *)(void *)&lbl_80558DC4)
        wave = lbl_80564A9C * (float)(int)fn_80287BC8(lbl_805649F0, lbl_805649FC);
    color = 1;
    if (angle > lbl_80564A00 && (float)fn_8002EFB4(angle, lbl_80564AA0) <= lbl_80564A34) color = 0;
    wave = lbl_805649F0;
    if (color != 0) wave = lbl_80564AA8 * *(float *)(state + 0xE4) - wave;
    {
        int old = *(int *)(state + 0xE8);
        lbl_8055F92D = fn_802C2C00(1);
        lbl_804BD7B0[0] = fn_802C990C(old);
        fn_802C2BB8(&lbl_804BD7B0[1], &lbl_804BD7B0[2], &lbl_804BD7B0[3]);
        fn_802C2B78(wave, lbl_80564AAC + wave, lbl_805649FC);
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
void fn_802AB9E8(void) {
    unsigned char sp[0x144]; void **p; float t31, t13, t3, t2; int two=2, five=5;
    fn_8028DFFC(); p=(void **)fn_801284F8(8,lbl_80349DFC);
    if(p) {
        fn_8028E61C(&sp[0xC4]); t31=lbl_80564A68*lbl_80564A68; t13=lbl_80564A80*(lbl_80564A70/t31);
        t3=lbl_805649F4*t13; t3=t3*t31; t2=lbl_80564A84-t3; t2=t2/lbl_80564A68;
        *(int *)&sp[0xC4]=two; *(int *)&sp[0xC8]=0x12C; *(float *)&sp[0xCC]=lbl_80564A68; *(float *)&sp[0xD0]=lbl_805649FC;
        *(int *)&sp[0x108]=five; *(float *)&sp[0x10C]=lbl_805649F4;
        *(float *)&sp[0x20]=lbl_805649F0; *(float *)&sp[0x24]=lbl_805649FC; *(float *)&sp[0x28]=lbl_805649F0;
        *(float *)&sp[0xD4]=lbl_805649F0; *(float *)&sp[0xD8]=lbl_805649FC; *(float *)&sp[0xDC]=lbl_805649F0;
        *(float *)&sp[0x2C]=lbl_80564A6C; *(float *)&sp[0x30]=lbl_805649FC; *(float *)&sp[0x34]=lbl_80564A6C;
        *(float *)&sp[0xE0]=lbl_80564A6C; *(float *)&sp[0xE4]=lbl_805649FC; *(float *)&sp[0xE8]=lbl_80564A6C;
        *(float *)&sp[0xEC]=lbl_805649F0; *(float *)&sp[0xF0]=lbl_80564A70; *(float *)&sp[0xF4]=lbl_805649F0; *(float *)&sp[0xF8]=lbl_80564A74;
        *(float *)&sp[0x124]=lbl_80564A78; *(float *)&sp[0x12C]=lbl_80564A78; *(float *)&sp[0x134]=lbl_80564A78;
        *(float *)&sp[0x128]=lbl_805649FC; *(float *)&sp[0x130]=lbl_805649FC; *(float *)&sp[0x138]=lbl_805649FC;
        *(float *)&sp[0x11C]=lbl_805649F0; *(float *)&sp[0x120]=lbl_80564A7C; *(float *)&sp[0x110]=t13; *(float *)&sp[0x114]=t2; *(float *)&sp[0x118]=lbl_80564A58;
        *(float *)&sp[0x13C]=lbl_805649F0; *(float *)&sp[0x140]=lbl_80564A04;
        p[0]=(void *)fn_8028E2F8(&sp[0xC4],lbl_80349E24,lbl_80349E18,lbl_80564A58,t2,t3,lbl_80564A7C,lbl_80564A78,lbl_80564A74,lbl_80564A70,lbl_80564A6C,lbl_805649F0,lbl_805649F4,lbl_805649FC,lbl_80564A68,t13);
        fn_8028E61C(&sp[0x38]); *(int *)&sp[0x38]=two; *(int *)&sp[0x3C]=0x60; *(float *)&sp[0x40]=lbl_805649F4; *(float *)&sp[0x44]=lbl_805649FC;
        *(float *)&sp[0x80]=lbl_805649F4; *(int *)&sp[0x7C]=five; *(float *)&sp[8]=lbl_805649F0; *(float *)&sp[0xC]=lbl_805649F0; *(float *)&sp[0x10]=lbl_805649F0;
        *(float *)&sp[0x48]=lbl_805649F0; *(float *)&sp[0x4C]=lbl_805649F0; *(float *)&sp[0x50]=lbl_805649F0;
        *(float *)&sp[0x14]=lbl_805649FC; *(float *)&sp[0x18]=lbl_805649FC; *(float *)&sp[0x1C]=lbl_805649FC; *(float *)&sp[0x54]=lbl_805649FC; *(float *)&sp[0x58]=lbl_805649FC; *(float *)&sp[0x5C]=lbl_805649FC;
        *(float *)&sp[0x60]=lbl_805649F0; *(float *)&sp[0x64]=lbl_80564A00; *(float *)&sp[0x68]=lbl_805649F0; *(float *)&sp[0x6C]=lbl_80564A74;
        *(float *)&sp[0xA8]=lbl_80564A78; *(float *)&sp[0xA0]=lbl_80564A78; *(float *)&sp[0x98]=lbl_80564A78; *(float *)&sp[0xAC]=lbl_80564A88; *(float *)&sp[0xA4]=lbl_80564A88; *(float *)&sp[0x9C]=lbl_80564A88;
        *(float *)&sp[0x90]=lbl_80564A78; *(float *)&sp[0x94]=lbl_80564A8C; *(float *)&sp[0x88]=lbl_80564A8C; *(float *)&sp[0x8C]=lbl_80564A90; *(float *)&sp[0xB0]=lbl_80564A94; *(float *)&sp[0xB4]=lbl_805649FC;
        p[1]=(void *)fn_8028E2F8(&sp[0x38],&lbl_8055CC80,lbl_80349E08,lbl_80564A90,lbl_80564A8C,lbl_80564A88,lbl_80564A78,lbl_80564A74,lbl_80564A00,lbl_805649F0,lbl_805649FC,lbl_805649F4);
    }
    lbl_8055F924=p; fn_8028E024();
}

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

void fn_802ABC80(void *arg0, void *arg1, float farg0, float farg1, float farg2) {
    extern float fn_80287BC8(float, float);
    extern void fn_8028E590(int, Vec *, Vec *, float);
    extern float lbl_80564A04, lbl_80564A48, lbl_80564A4C, lbl_805649F0, lbl_805649FC;
    extern void *lbl_8055F924;
    extern double cos(double), sin(double);
    Vec forward, side, pos, dir;
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
    fn_8028E590(*(int*)lbl_8055F924,&pos,&dir,lbl_805649FC);
}

void fn_802ABE50(void) { fn_8028E240(0); }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802ABE58(float *arg0, float *arg1, int *arg2, float delta) {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned int color;
    unsigned int low;
    float angle;
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
    color = (unsigned int)blue << 16;
    angle = lbl_80564A98;
    low = (unsigned int)green << 8;
    low |= red;
    color |= 0xFF000000;
    *arg2 = color | low;

    (void)*(volatile unsigned char *)&lbl_8055F92C;
    if (*arg0 > lbl_805649F4)
        *arg0 = fn_80287BC8(lbl_80564A8C, lbl_80564A68);
    else
        *arg0 = *arg0 + lbl_80564A34 * delta;

    magnitude = (float)fabs(delta);
    withinTolerance = magnitude <= *(float *)(void *)&lbl_80558DC4;
    wave = lbl_805649F0;
    if (withinTolerance == 0)
        wave = lbl_80564A9C * (float)(int)fn_80287BC8(lbl_805649F0, lbl_805649FC);

    angleBelowLimit = angle < lbl_80564A00;
    active = 1;
    if (angleBelowLimit != 0) {
        angleValue = (float)fn_8002EFB4(angle, lbl_80564AA0);
        angleWithinLimit = angleValue < lbl_80564A34;
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

