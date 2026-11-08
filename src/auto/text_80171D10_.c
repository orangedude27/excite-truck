#include <stdarg.h>
typedef struct { float pos[3]; int w; float a, b; } Elem_801720FC;
typedef struct { float m[12]; float v[3]; } Fn8017431CCam;
typedef union { unsigned long long ull; float f[2]; } Fn8017431CPair;
typedef struct { float a[9]; } Fn8017431CM9;
typedef struct { float a[3]; } Fn8017431CV3;
typedef struct { Fn8017431CM9 m; Fn8017431CV3 pos; Fn8017431CV3 v; } Fn8017431CFrame;
typedef struct { int zero; short mark; } Fn8017431CMark;
typedef struct { float a, b; } Fn8017431CV2;
typedef struct { void *pad[8]; int (*m20)(void *, int); void *pad2[3]; void (*m30)(void *, int); } Fn80176040VT;
typedef struct { Fn80176040VT *vt; } Fn80176040Obj;
typedef struct { Fn8017431CM9 m; Fn8017431CV3 pos; Fn8017431CV3 v; int zero; short mark; } Fn8017431CFrame2;
extern float PSQUATMultiply(void *, void *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_8017960C();
extern void fn_802AE0E0();
extern float lbl_80561A50;
typedef struct { char pad[0x4A]; unsigned char f4A; char pad4B; unsigned char f4C; } Fn80173424Child;
typedef struct {
    int f0; float f4; unsigned char f8; unsigned char f9; char padA[2];
    int fC; unsigned char f10; char pad11[3];
    Fn80173424Child *f14; Fn80173424Child *f18; Fn80173424Child *f1C;
    unsigned char f20; char pad21[3];
    Fn80173424Child *f24; Fn80173424Child *f28; Fn80173424Child *f2C;
    char pad30[0xF8 - 0x30];
    int fF8; int fFC; int f100; int f104;
} Fn80173424Obj;
extern double fn_8002F234(float), cos(double), sin(double);
extern float fn_80129DC4(int,float,float);
extern unsigned long long fn_80171FF0(void *,int,float,float);
extern int fn_80171EF8(void *,void *);
extern float lbl_80558DC4[];
#pragma push
#pragma small_data off
extern char lbl_80330F54[];
extern char lbl_804303B8[];
#pragma pop
extern float lbl_8055E3C8,lbl_80561A38,lbl_80561A78,lbl_80561A80,lbl_80561AB4,lbl_80561ABC,lbl_80561AC8,lbl_80561AF8,lbl_80561AFC,lbl_80561B00,lbl_80561B04,lbl_80561B08,lbl_80561B0C;

#pragma cplusplus on
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16();
    virtual void v4C();
};
#pragma cplusplus reset

void fn_80171D10(int arg0) { fn_80171930(arg0 - 4); }

void fn_80171D18(int arg0) { fn_80171934(arg0 - 4); }

void fn_80171D20(int arg0) { fn_80171A4C(arg0 - 4); }

void fn_80171D28(int arg0) { fn_80171A80(arg0 - 4); }

void fn_80171D30(int arg0) { fn_80171CE0(arg0 - 4); }

int fn_80171D38(int arg0) {
    unsigned char sp[0x68];
    int index;
    int result = 0;
    if (fn_801298E8(sp, arg0) != 0) {
        index = *(int *)(__AXFXGetLfoSinTable_801297F4() + 0x30);
        if (*(sp + 0x20 + index) != 0)
            result = 1;
    }
    return result;
}

void fn_80171D94(int unused) {
    void *r = fn_8017960C();
    int i = 0;
    do {
        fn_8018F76C((int)r, i);
        i++;
    } while (i < 4);
}

#pragma dont_inline on
int fn_80171DE4(void *arg0) {
    extern int fn_80139EC4(int, float, float);
    extern int lbl_8055E3A4;
    int result = 0;
    if (lbl_8055E3A4 != 0 && fn_80139EC4(lbl_8055E3A4, *(float *)arg0, *(float *)((char *)arg0 + 4)) != 0) result = 1;
    return result;
}

#pragma push
#pragma processor 750
#pragma dont_inline on
int fn_80171E3C(void *arg0) {
    extern int fn_802B04D4(float *);
    extern int fn_80139EC4(int, float, float);
    extern int lbl_8055E3A4;
    extern float lbl_80561A38;
    float last = *(float *)((char *)arg0 + 4);
    float position[3];

    position[0] = *(float *)arg0;
    position[1] = lbl_80561A38;
    position[2] = last;
    if (fn_802B04D4(position)) return 0;
    if (lbl_8055E3A4 && fn_80139EC4(lbl_8055E3A4, *(float *)arg0, *(float *)((char *)arg0 + 4))) return 0;
    return 1;
}
#pragma pop

int fn_80171EC0(int unused) {
    return *(int *)((char *)fn_8017960C() + 0x10) == 0x50434152;
}

extern float lbl_80561A3C, lbl_80561A40;
#pragma dont_inline on
int fn_80171EF8(void *arg0, void *arg1) {
    float *start = (float *)arg0;
    float *endPoint = (float *)arg1;
    float dy;
    float dx;
    float sum;
    volatile float savedY;
    volatile float savedX;
    float distance;
    float step;
    float limit;
    float t;
    dy = start[1] - endPoint[1];
    dx = start[0] - endPoint[0];
    sum = dy * dy + dx * dx;
    savedY = dy;
    savedX = dx;
    distance = (float)fn_8002F234(sum);
    step = lbl_80561A3C / distance;
    limit = lbl_80561A40 - step;
    t = step;
    while (t < limit) {
        float coords[2];
        double point;
        float y0 = start[1];
        float y1 = endPoint[1];
        float x0 = start[0];
        float x1 = endPoint[0];
        coords[0] = x0 + (x1 - x0) * t;
        coords[1] = y0 + (y1 - y0) * t;
        point = *(double *)coords;
        if (fn_80171E3C(&point) == 0)
            return 0;
        t += step;
    }
    return 1;
}
#pragma dont_inline reset

unsigned long long fn_80171FF0(void *arg0, int arg1, float angle, float step) {
    extern float lbl_80561A44, lbl_80561A48;
    float zero = lbl_80561A44;
    float off[2];
    float pos[2];
    float rad, c, s;
    while (arg1-- > 0) {
        off[0] = angle;
        off[1] = zero;
        rad = fn_80129DC4(3, zero, lbl_80561A48);
        c = (float)cos(rad);
        s = (float)sin(rad);
        off[1] = off[0] * s + off[1] * c;
        off[0] = angle * c - zero * s;
        pos[1] = *((float *)arg0 + 1) + off[1];
        pos[0] = *(float *)arg0 + off[0];
        if (fn_80171E3C(pos) != 0)
            break;
        angle += step;
    }
    return *(unsigned long long *)pos;
}

#pragma dont_inline on
unsigned int fn_801720E0(unsigned int arg0) {
    return (arg0 & 0xFF000000) | ((arg0 & 0xFEFEFE) >> 1);
}
#pragma dont_inline reset

#pragma push
#pragma processor 750
void fn_801720FC(float *arg0, int arg1, float arg2) {
    extern float PSVECMag(float *);
    extern float lbl_8055E3A8;
    extern float lbl_80561A40, lbl_80561A44, lbl_80561A4C, lbl_80561A50, lbl_80561A54, lbl_80561A58;
    extern double lbl_80561A60;
    extern unsigned short lbl_802F9520[];
    extern void fn_802C8BD0(int);
    extern void fn_802C8DB8(void *, int, void *, int);
    extern void fn_802C8D74(void);
    struct {
        unsigned short s[6];
        float v2[3];
        float v3[3];
        float v1[3];
        Elem_801720FC e[5];
    } L;
    float scale;
    float mag;
    float k;
    int r;
    int i;

    L.v1[0] = lbl_80561A44;
    L.v1[1] = lbl_80561A50;
    L.v1[2] = lbl_80561A44;
    L.v2[0] = lbl_80561A40;
    L.v2[1] = lbl_80561A44;
    L.v2[2] = lbl_80561A44;
    L.v3[0] = lbl_80561A44;
    L.v3[1] = lbl_80561A44;
    L.v3[2] = lbl_80561A40;
    scale = lbl_80561A4C * arg2;
    mag = PSVECMag(L.v1);
    if (!((float)__fabs(mag) <= lbl_80558DC4[0])) {
        k = -arg2 / mag;
        L.v1[0] *= k;
        L.v1[1] *= k;
        L.v1[2] *= k;
    }
    mag = PSVECMag(L.v2);
    if (!((float)__fabs(mag) <= lbl_80558DC4[0])) {
        k = scale * lbl_80561A54 / mag;
        L.v2[0] *= k;
        L.v2[1] *= k;
        L.v2[2] *= k;
    }
    mag = PSVECMag(L.v3);
    if (!((float)__fabs(mag) <= lbl_80558DC4[0])) {
        k = scale * lbl_80561A54 / mag;
        L.v3[0] *= k;
        L.v3[1] *= k;
        L.v3[2] *= k;
    }
    L.e[0].pos[0] = lbl_80561A44;
    L.e[0].pos[1] = lbl_80561A44;
    L.e[0].pos[2] = lbl_80561A44;
    L.e[1].pos[0] = L.v1[0] + L.v2[0] * lbl_80561A50;
    L.e[1].pos[1] = L.v1[1] + L.v2[1] * lbl_80561A50;
    L.e[1].pos[2] = L.v1[2] + L.v2[2] * lbl_80561A50;
    L.e[2].pos[0] = L.v1[0] + L.v2[0] * lbl_80561A40;
    L.e[2].pos[1] = L.v1[1] + L.v2[1] * lbl_80561A40;
    L.e[2].pos[2] = L.v1[2] + L.v2[2] * lbl_80561A40;
    L.e[3].pos[0] = L.v1[0] + L.v3[0] * lbl_80561A50;
    L.e[3].pos[1] = L.v1[1] + L.v3[1] * lbl_80561A50;
    L.e[3].pos[2] = L.v1[2] + L.v3[2] * lbl_80561A50;
    L.e[4].pos[0] = L.v1[0] + L.v3[0] * lbl_80561A40;
    L.e[4].pos[1] = L.v1[1] + L.v3[1] * lbl_80561A40;
    L.e[4].pos[2] = L.v1[2] + L.v3[2] * lbl_80561A40;
    r = fn_801720E0(arg1);
    for (i = 0; i < 5; i++) {
        L.e[i].w = arg1;
        L.e[i].a = lbl_80561A58 * (float)i;
        L.e[i].b = lbl_80561A58 * (float)i;
        L.e[i].pos[0] += arg0[0];
        L.e[i].pos[1] += arg0[1];
        L.e[i].pos[2] += arg0[2];
    }
    L.e[0].w = r;
    L.s[0] = lbl_802F9520[0];
    L.s[1] = lbl_802F9520[1];
    L.s[2] = lbl_802F9520[2];
    L.s[3] = lbl_802F9520[3];
    L.s[4] = lbl_802F9520[4];
    L.s[5] = lbl_802F9520[5];
    fn_802C8BD0(lbl_8055E3A8);
    fn_802C8DB8(L.e, 5, L.s, 6);
    fn_802C8D74();
    L.e[0].w &= 0x3FFFFFFF;
    L.e[1].w &= 0x3FFFFFFF;
    L.e[2].w &= 0x3FFFFFFF;
    L.e[3].w &= 0x3FFFFFFF;
    L.e[4].w &= 0x3FFFFFFF;
    fn_802C8BD0(-1);
    fn_802C8DB8(L.e, 5, L.s, 6);
    fn_802C8D74();
}
#pragma pop
extern void *fn_802C86DC(void);
extern double fn_8002EFB4(float, double);
extern float lbl_80561A44, lbl_80561A68, lbl_80561A6C;
extern float lbl_80561A70, lbl_80561A74, lbl_80561A7C;
extern double lbl_80561A88;
extern float lbl_80561A70, lbl_80561A74;
#pragma optimization_level 3
#pragma scheduling invalid_target
void fn_8017248C(int arg0) {
    float sp[3];
    void *state;
    void *camera;
    float value;
    float clamp;
    float temp_f31;
    float temp_f30;
    float temp_f29;
    float wave;
    float offset;

    state = fn_8017960C(arg0);
    camera = fn_802C86DC();
    value = (PSQUATMultiply((char *)state + 0x60,
                            (char *)camera + 0x24) - lbl_80561A68) /
            lbl_80561A6C;
    clamp = lbl_80561A40;
    if (clamp < value) {
        clamp = value;
    } else {
        clamp = clamp;
    }
    if (clamp > lbl_80561A44) {
        clamp = lbl_80561A44;
    } else {
        clamp = clamp;
    }

    temp_f31 = lbl_80561A70 + (clamp * lbl_80561A70);
    sp[0] = *(float *)((char *)state + 0x60);
    temp_f30 = lbl_80561A74;
    sp[1] = *(float *)((char *)state + 0x64);
    temp_f29 = lbl_80561A78;
    sp[2] = *(float *)((char *)state + 0x68);

    wave = (float)fn_8002EFB4(
        (lbl_80561A7C * (lbl_80561A80 * (float)arg0)) + lbl_8055E3C8,
        lbl_80561A88) - lbl_80561A40;
    offset = temp_f30 + (temp_f29 * (lbl_80561A40 - ((wave * wave) / lbl_80561A40)));
    sp[1] += offset;
    fn_801720FC(sp, -0x100, temp_f31);
}
#pragma scheduling on
#pragma optimization_level reset
#pragma dont_inline on
float fn_801725C8(float arg0) {
    extern float lbl_8043038C[];
    extern float lbl_80561A40;
    extern float lbl_80561A44;
    float f0 = lbl_8043038C[2];
    float f2 = lbl_8043038C[3];
    float f3 = lbl_8043038C[0];
    float f4 = lbl_8043038C[1];
    float value = (arg0 - f0) / (f2 - f0);
    float t = lbl_80561A40;
    if (t < value) { t = value; } else { t = t; }
    if (t > lbl_80561A44) { t = lbl_80561A44; } else { t = t; }
    return f3 + t * (f4 - f3);
}
#pragma dont_inline reset

int fn_80172624(void *arg0, int arg1) {
      extern void *fn_8017960C();
  extern float PSQUATMultiply(void *, void *);
    extern float lbl_8043038C[];
    void *a = fn_8017960C((int)arg0);
    void *b = fn_8017960C(arg1);
    float dot = PSQUATMultiply((char *)a + 0x118, (char *)b + 0x118);
    float threshold = *(float *)((char *)a + 0x25D4);
    float upper = lbl_8043038C[9];
    int result;
    float value = upper * dot + lbl_8043038C[10] * threshold;
    result = 0;
    if (value >= lbl_8043038C[8])
        return 2;
    if (value >= lbl_8043038C[7])
        result = 1;
    return result;
}

void *fn_801726C4(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_80330F48[];
    extern char lbl_80330FE8[];
    void *result = fn_801284F8(0x12C, lbl_80330F48);
    if (result != 0) {
        *(void **)result = lbl_80330FE8;
        *(int *)((char *)result + 0x124) = fn_801EA994();
        *(void **)((char *)result + 0x128) = arg0;
    }
    return result;
}

unsigned char *__AXGetStackHead();                             /* extern */
void fn_801308F4(void *, int, int);          /* extern */
void fn_80130980(void *, int, int, float); /* extern */
void fn_801312EC(void *, void *);      /* extern */
int fn_80131318();                              /* extern */
void fn_801345D8(void *, int, void *, float); /* extern */
void fn_80175080(void **, int, int, char *, double, ...);
void fn_80147230(void *, const char *, ...);
int fn_801609C4(int);                               /* extern */
void fn_802ADFF4(void *, void *);                      /* extern */
void fn_802AE02C(void *, void *);                      /* extern */
void fn_802AE0B8(void *, void *);                      /* extern */
void fn_802AE168(void *);                           /* extern */
unsigned int strlen(const char *); /* extern */
#define COPY_STR20(dst, src) do { \
    unsigned char *d_ = (unsigned char *)(dst); \
    const unsigned char *s_ = (const unsigned char *)(src); \
    int n_ = 0x14; int c_; \
    for (;;) { \
        if (--n_ <= 0) { *(signed char *)(d_ - 1) = 0; } \
        c_ = *s_++; \
        *d_++ = c_; \
        if ((signed char)c_ == 0) break; \
    } } while (0)
extern void *fn_80131234(const char *);
extern float fn_8001DAE8(void *);
extern float fn_801B306C(void);
extern int fn_80161C38(void);
extern int fn_80179630(int);
extern int fn_80179650(void);
extern int fn_80009C84(void);
extern void fn_801CB5DC(int, int, int);
extern void fn_801CB648(int, int, float);
#pragma scheduling invalid_target
void fn_8017272C(void *arg0, int arg1, int arg2, int arg3, int arg4) {
extern int lbl_8055A2A0;
extern unsigned char lbl_8055A2A4;
extern unsigned char lbl_8055A2A8;
extern unsigned int lbl_8055E044;
extern unsigned char lbl_8055E3AC;
extern float lbl_8055E3C8;
extern float lbl_80561A40;
extern float lbl_80561A44;
extern float lbl_80561A54;

    float temp_f0;
    float temp_f1;
    float temp_f2;
    float var_f4;
    int temp_r0;
    int var_r28;
    int var_r6;
    int var_r5;
    unsigned char *var_r6_2;
    unsigned char *var_r4;
    long var_r5_2;
    unsigned char *var_r6_3;
    unsigned char *var_r4_2;
    long var_r5_3;
    unsigned char *var_r6_4;
    unsigned char *var_r4_3;
    unsigned char *var_r3;
    void *temp_r3_9;
    unsigned char *var_r6_5;
    int var_r5_5;
    unsigned char *var_r6_6;
    unsigned char *var_r4_4;
    int temp_r3;
    int temp_r3_2;
    int temp_r3_3;
    int temp_r3_4;
    int temp_r4;
    void *temp_r3_10;
    void *temp_r3_5;
    void *temp_r3_6;
    void *temp_r3_7;
    void *temp_r3_8;
    int var_r5_4;

    if ((int) (*(void **)((char *)(arg0) + (0xC))) != 0) {
        fn_801308F4((char *)(unsigned char *)arg0 + 0x30, 0x14, arg2);
        var_r28 = arg3;
        var_r6 = 0;
        if (arg3 != 0) {
            temp_f1 = (*(float *)((char *)(arg0) + (4)));
            if ((*(float *)((char *)(arg0) + (4))) > lbl_80561A44) {
                temp_f2 = lbl_8055E3C8;
                var_f4 = lbl_80561A40;
                temp_f1 = temp_f2 - temp_f1;
                temp_f0 = temp_f1 - lbl_80561A44;
                temp_f0 = temp_f0 / var_f4;
                var_f4 = (var_f4 < temp_f0) ? var_f4 : temp_f0;
                var_f4 = (var_f4 > lbl_80561A44) ? var_f4 : lbl_80561A44;
                var_r6 = (int) (lbl_80561A44 + (var_f4 * ((lbl_80561A54 + (float) arg3) - lbl_80561A44)));
                var_r28 = arg3 - var_r6;
            }
        }
        ((void (*)(void *, int, const void *, ...))fn_801345D8)((unsigned char *)arg0 + 0x44, 0x14, &lbl_8055A2A0, var_r6);
        if ((int) (*(unsigned char *)((char *)(arg0) + (0x10))) != 0) {
            var_r6_2 = (unsigned char *)arg0 + 0x9E;
            var_r4 = &lbl_8055A2A4;
            var_r5 = 0x14;
            for (;;) {
                if (--var_r5 <= 0) {
                    (*(signed char *)((char *)var_r6_2 - 1)) = 0;
                }
                temp_r3 = *var_r4++;
                *var_r6_2++ = temp_r3;
                if ((signed char)temp_r3 == 0) break;
            }
            var_r6_3 = (unsigned char *)arg0 + 0x58;
            var_r4_2 = &lbl_8055A2A4;
            var_r5_2 = 0x14;
            for (;;) {
                if (--var_r5_2 <= 0) {
                    (*(signed char *)((char *)var_r6_3 - 1)) = 0;
                }
                temp_r3_2 = *var_r4_2++;
                *var_r6_3++ = temp_r3_2;
                if ((signed char)temp_r3_2 == 0) break;
            }
        } else {
            if ((signed char) lbl_8055E3AC == 0) {
                fn_801312EC(&lbl_804303B8, &lbl_80330F54);
                lbl_8055E3AC = 1;
            }
            fn_80130980((unsigned char *)arg0 + 0x9E, 0x14, 2, (float) var_r28);
            if ((unsigned int) (*(unsigned int *)((char *)(&lbl_804303B8) + (8))) != (unsigned int) lbl_8055E044) {
                fn_80131318();
            }
            var_r4_3 = (*(unsigned char **)((char *)(&lbl_804303B8) + (4)));
            var_r6_4 = (unsigned char *)arg0 + 0x58;
            var_r5_3 = 0x14;
            for (;;) {
                if (--var_r5_3 <= 0) {
                    (*(signed char *)((char *)var_r6_4 - 1)) = 0;
                }
                temp_r3_3 = *var_r4_3++;
                *var_r6_4++ = temp_r3_3;
                if ((signed char)temp_r3_3 == 0) break;
            }
        }
        fn_801308F4((unsigned char *)arg0 + 0x6C, 0x14, arg1);
        fn_801308F4((unsigned char *)arg0 + 0x8A, 0x14, arg1 - arg3);
        if (fn_801609C4(arg1) != -1) {
            var_r3 = __AXGetStackHead();
            var_r6_5 = (unsigned char *)arg0 + 0x80;
            var_r5_4 = 0xA;
            for (;;) {
                if (--var_r5_4 <= 0) {
                    (*(signed char *)((char *)var_r6_5 - 1)) = 0;
                }
                temp_r4 = *var_r3++;
                *var_r6_5++ = temp_r4;
                if ((signed char)temp_r4 == 0) break;
            }
        } else {
            var_r6_6 = (unsigned char *)arg0 + 0x80;
            var_r4_4 = &lbl_8055A2A8;
            var_r5_5 = 0xA;
            for (;;) {
                if (--var_r5_5 <= 0) {
                    (*(signed char *)((char *)var_r6_6 - 1)) = 0;
                }
                temp_r3_4 = *var_r4_4++;
                *var_r6_6++ = temp_r3_4;
                if ((signed char)temp_r3_4 == 0) break;
            }
        }
        if ((int) (*(int *)((char *)(arg0) + (0xF8))) != 0) {
            (*(signed char *)((char *)(arg0) + (8))) = 0;
        }
        temp_r0 = (*(int *)((char *)(arg0) + (0)));
        switch (temp_r0) {                          /* irregular */
        case 4:
            break;
        case 0:
            fn_802ADFF4((*(void **)((char *)(arg0) + (0xC))), (*(void **)((char *)(arg0) + (0xF4))));
            if (strlen((char *)arg0 + 0xDA) != 0) {
                temp_r3_5 = (*(void **)((char *)(arg0) + (0x2C)));
                if ((temp_r3_5 != 0) && ((int) (*(unsigned char *)((char *)(temp_r3_5) + (0x19))) == 0)) {
                    (*(signed char *)((char *)(temp_r3_5) + (0x49))) = 1;
                    (*(signed char *)((char *)(temp_r3_5) + (0x4B))) = 0;
                    (*(signed char *)((char *)(temp_r3_5) + (0x4A))) = 0;
                }
            } else {
                temp_r3_6 = (*(void **)((char *)(arg0) + (0x28)));
                if ((temp_r3_6 != 0) && ((int) (*(unsigned char *)((char *)(temp_r3_6) + (0x19))) == 0)) {
                    (*(signed char *)((char *)(temp_r3_6) + (0x49))) = 1;
                    (*(signed char *)((char *)(temp_r3_6) + (0x4B))) = 0;
                    (*(signed char *)((char *)(temp_r3_6) + (0x4A))) = 0;
                }
            }
            if (arg3 > 0) {
                temp_r3_7 = (*(void **)((char *)(arg0) + (0x14)));
                if (temp_r3_7 != 0) {
                    (*(signed char *)((char *)(temp_r3_7) + (0x49))) = 1;
                    (*(signed char *)((char *)(temp_r3_7) + (0x4B))) = 0;
                    (*(signed char *)((char *)(temp_r3_7) + (0x4A))) = 0;
                }
            } else {
                temp_r3_8 = (*(void **)((char *)(arg0) + (0x18)));
                if (temp_r3_8 != 0) {
                    (*(signed char *)((char *)(temp_r3_8) + (0x49))) = 1;
                    (*(signed char *)((char *)(temp_r3_8) + (0x4B))) = 0;
                    (*(signed char *)((char *)(temp_r3_8) + (0x4A))) = 0;
                }
            }
            (*(int *)((char *)(arg0) + (0))) = 1;
            break;
        case 1:
            if (((int) (*(int *)((char *)(arg0) + (0xFC))) != 0) && ((*(float *)((char *)(arg0) + (4))) < lbl_80561A44)) {
                (*(float *)((char *)(arg0) + (4))) = (float) lbl_8055E3C8;
            }
            if (((int) (*(int *)((char *)(arg0) + (0xFC))) == 2) && ((int) (*(unsigned char *)((char *)(arg0) + (0x20))) == 0)) {
                temp_r3_9 = (*(void **)((char *)(arg0) + (0x1C)));
                (*(unsigned char *)((char *)(arg0) + (0x20))) = 1U;
                if (temp_r3_9 != 0) {
                    (*(signed char *)((char *)(temp_r3_9) + (0x49))) = 1;
                    (*(signed char *)((char *)(temp_r3_9) + (0x4B))) = 0;
                    (*(signed char *)((char *)(temp_r3_9) + (0x4A))) = 0;
                }
            }
            if ((int) (*(int *)((char *)(arg0) + (0x100))) != 0) {
                fn_802AE02C((*(void **)((char *)(arg0) + (0xC))), (*(void **)((char *)(arg0) + (0xF4))));
                (*(int *)((char *)(arg0) + (0))) = 2;
            }
            break;
        case 2:
            if ((int) (*(unsigned char *)((char *)(arg0) + (9))) != 0) {
                fn_802AE0B8((*(void **)((char *)(arg0) + (0xC))), (*(void **)((char *)(arg0) + (0xF4))));
                temp_r3_10 = (*(void **)((char *)(arg0) + (0x24)));
                if (temp_r3_10 != 0) {
                    (*(signed char *)((char *)(temp_r3_10) + (0x49))) = 1;
                    (*(signed char *)((char *)(temp_r3_10) + (0x4B))) = 0;
                    (*(signed char *)((char *)(temp_r3_10) + (0x4A))) = 0;
                }
                (*(int *)((char *)(arg0) + (0))) = 3;
            }
            break;
        case 3:
            if ((int) (*(int *)((char *)(arg0) + (0x104))) != 0) {
                fn_802AE02C((*(void **)((char *)(arg0) + (0xC))), (*(void **)((char *)(arg0) + (0xF4))));
                (*(int *)((char *)(arg0) + (0))) = 4;
            }
            break;
        }
        fn_802AE168((*(void **)((char *)(arg0) + (0xC))));
    }
}

#pragma push
#pragma scheduling invalid_target
void *fn_80172C28(void) {
    extern void *fn_801284F8(unsigned int, void *);
    extern void fn_8001DAE0(void *, float);
    extern int fn_80139D4C(void *);
    extern int fn_80207848(void *, int);
    extern int fn_802CAC28(void *, int);
    extern void fn_802E30C8(void *, ...);
    extern void *memset(void *, int, unsigned long);
    extern char lbl_80330F48[];
    extern char lbl_80331018[];
    extern float lbl_80561A44, lbl_80561A90, lbl_8055E3A8;
    extern int lbl_8055E3A4;
    char *base = lbl_80330F48;
    unsigned int zero = 0;
    void *object = fn_801284F8(0x2BC, base + 0x2C);
    if (object != 0) {
        unsigned char *p = (unsigned char *)object;
        void *data = p + 0x10;
        void *vtable = lbl_80331018;
        float firstValue = lbl_80561A44;
        *(void **)p = vtable;
        *(void **)(p + 4) = data;
        *(int *)(p + 0xC) = 0x10;
        *(int *)(p + 8) = zero;
        fn_8001DAE0(p + 0x174, firstValue);
        fn_8001DAE0(p + 0x17C, lbl_80561A80);
        fn_8001DAE0(p + 0x184, lbl_80561A90);
        fn_8001DAE0(p + 0x18C, lbl_80561A90);
        *(int *)(p + 0x1B8) = zero;
        *(int *)(p + 0x1C0) = zero;
        *(int *)(p + 0x1C4) = zero;
        *(int *)(p + 0x1C8) = zero;
        *(int *)(p + 0x1D0) = zero;
        *(int *)(p + 0x1D4) = zero;
        *(int *)(p + 0x1D8) = zero;
        memset(p + 0x1DC, 0x30, 3);
        p[0x1DF] = (unsigned char)zero;
        memset(p + 0x1F0, 0x30, 3);
        p[0x1F3] = (unsigned char)zero;
        memset(p + 0x204, 0x30, 3);
        p[0x207] = (unsigned char)zero;
        memset(p + 0x218, 0x30, 3);
        p[0x21B] = (unsigned char)zero;
        memset(p + 0x22C, 0x30, 3);
        p[0x22F] = (unsigned char)zero;
        memset(p + 0x236, 0x30, 3);
        p[0x239] = (unsigned char)zero;
        memset(p + 0x24A, 0x30, 3);
        p[0x24D] = (unsigned char)zero;
        memset(p + 0x25E, 0x30, 3);
        p[0x261] = (unsigned char)zero;
        memset(p + 0x272, 0x30, 3);
        p[0x275] = (unsigned char)zero;
        memset(p + 0x286, 0x30, 3);
        {
            void *name = base + 0x38;
            p[0x289] = (unsigned char)zero;
            lbl_8055E3A4 = fn_80139D4C(name);
            *(int *)&lbl_8055E3A8 = fn_802CAC28(base + 0x48, 0);
            *(int *)(p + 0x198) = fn_802CAC28(base + 0x58, 0);
            if (lbl_8055E3A4 != 0)
                fn_802E30C8(base + 0x64, name);
            *(int *)(p + 0x2B4) = fn_80207848(base + 0x8C, 1);
            p[0x2B8] = (unsigned char)zero;
        }
    }
    return object;
}
#pragma scheduling on
#pragma pop
int fn_80172E24(int arg0, int arg1) {
    extern int fn_80128668(void);
    if (arg0 != 0 && arg1 > 0)
        fn_80128668();
    return arg0;
}

#pragma cplusplus on
extern "C" void *fn_80172E64(void *arg0, int arg1) {
    class VObj { public: virtual void destroy(int); };
    extern char lbl_80331018[];
    extern int lbl_8055E3A4;
    extern float lbl_8055E3A8;
    extern void fn_80139E18(void *);
    extern void fn_802CAC54(int);
    extern void fn_802ADE60(int, int);
    extern int fn_80128668(void);
    VObj *first;
    if (arg0 != 0) {
        first = *(VObj **)((char *)arg0 + 0x2B4);
        *(void **)arg0 = lbl_80331018;
        if (first != 0) {
            if (first != 0) first->destroy(1);
        }
        if (lbl_8055E3A4 != 0) {
            fn_80139E18((void *)lbl_8055E3A4);
            lbl_8055E3A4 = 0;
        }
        fn_802CAC54(*(int *)&lbl_8055E3A8);
        fn_802CAC54(*(int *)((char *)arg0 + 0x198));
        if ((char *)arg0 + 0x1AC != 0) {
            if (*(int *)((char *)arg0 + 0x1B8) != 0) {
                fn_802ADE60(*(int *)((char *)arg0 + 0x1B8), 1);
                *(int *)((char *)arg0 + 0x1B8) = 0;
            }
            if (*(VObj **)((char *)arg0 + 0x1C0) != 0) {
                if (*(VObj **)((char *)arg0 + 0x1C0) != 0)
                    (*(VObj **)((char *)arg0 + 0x1C0))->destroy(1);
                *(VObj **)((char *)arg0 + 0x1C0) = 0;
            }
            if (*(VObj **)((char *)arg0 + 0x1C4) != 0) {
                if (*(VObj **)((char *)arg0 + 0x1C4) != 0)
                    (*(VObj **)((char *)arg0 + 0x1C4))->destroy(1);
                *(VObj **)((char *)arg0 + 0x1C4) = 0;
            }
            if (*(VObj **)((char *)arg0 + 0x1C8) != 0) {
                if (*(VObj **)((char *)arg0 + 0x1C8) != 0)
                    (*(VObj **)((char *)arg0 + 0x1C8))->destroy(1);
                *(VObj **)((char *)arg0 + 0x1C8) = 0;
            }
            if (*(VObj **)((char *)arg0 + 0x1D0) != 0) {
                if (*(VObj **)((char *)arg0 + 0x1D0) != 0)
                    (*(VObj **)((char *)arg0 + 0x1D0))->destroy(1);
                *(VObj **)((char *)arg0 + 0x1D0) = 0;
            }
            if (*(VObj **)((char *)arg0 + 0x1D4) != 0) {
                if (*(VObj **)((char *)arg0 + 0x1D4) != 0)
                    (*(VObj **)((char *)arg0 + 0x1D4))->destroy(1);
                *(VObj **)((char *)arg0 + 0x1D4) = 0;
            }
            if (*(VObj **)((char *)arg0 + 0x1D8) != 0) {
                if (*(VObj **)((char *)arg0 + 0x1D8) != 0)
                    (*(VObj **)((char *)arg0 + 0x1D8))->destroy(1);
                *(VObj **)((char *)arg0 + 0x1D8) = 0;
            }
        }
        if ((int *)arg0 + 1 != 0) {
            if ((int *)arg0 + 1 != 0) {
                ((volatile int *)arg0)[1] = 0;
                ((volatile int *)arg0)[2] = 0;
                ((volatile int *)arg0)[3] = 0;
            }
        }
        if (arg1 > 0) {
            ((void *(*)(void *))fn_80128668)(arg0);
            return arg0;
        }
    }
}

extern "C" void fn_80173424(Fn80173424Obj *o) {
    Fn80173424Child *q;
    float one = lbl_80561A50;
    o->f0 = 0;
    o->f4 = one;
    o->f8 = 1;
    o->f9 = 0;
    o->f10 = 0;
    o->fF8 = 0;
    o->fFC = 0;
    o->f100 = 0;
    o->f104 = 0;
    if (o->fC != 0)
        ((void (*)(int))fn_802AE0E0)(o->fC);
    q = o->f14;
    if (q != 0) {
        q->f4A = 1;
        q->f4C = 0;
    }
    q = o->f18;
    if (q != 0) {
        q->f4A = 1;
        q->f4C = 0;
    }
    q = o->f1C;
    if (q != 0) {
        q->f4A = 1;
        q->f4C = 0;
    }
    q = o->f24;
    o->f20 = 0;
    if (q != 0) {
        q->f4A = 1;
        q->f4C = 0;
    }
    q = o->f28;
    if (q != 0) {
        q->f4A = 1;
        q->f4C = 0;
    }
    q = o->f2C;
    if (q != 0) {
        q->f4A = 1;
        q->f4C = 0;
    }
}

#pragma cplusplus reset

extern void fn_80130980(void *, int, int, float);    /* extern */
extern int fn_80204CF0(void);                                  /* extern */
extern int fn_80207848(void *, int);                   /* extern */
extern int fn_802ADF34(void *, char *, int *);                /* extern */
extern int lbl_802FAA40[3];
extern int lbl_8055A2C8;
extern unsigned char lbl_8055A2D0;
extern unsigned char lbl_8055A2D4;
extern unsigned char lbl_8055A2D8;
extern float lbl_80561AB4;
void fn_8017353C(unsigned char *arg0, void *arg_sp0) {
    union Word { int i; void *p; } stack[94];
    extern char lbl_80330F48[];






























































































    char *var_r4;
    int temp_r0;
    int temp_r0_2;
    int temp_r10;
    int temp_r10_2;
    int temp_r11;
    int temp_r11_2;
    int temp_r12;
    int temp_r4;
    int temp_r5;
    int temp_r6;
    int temp_r7;
    int temp_r7_2;
    int temp_r8;
    int temp_r9;
    int var_ctr;
    int var_r24;
    int var_r6;
    int var_r6_2;
    unsigned char *var_r22;
    unsigned char *var_r4_2;
    unsigned char *var_r5;
    unsigned char *var_r5_2;
    unsigned char *var_r7;
    unsigned char *var_r7_2;
    unsigned char temp_r4_2;
    unsigned char temp_r4_3;
    unsigned char temp_r5_2;
    void *temp_r23;
    void *temp_r24;
    void *temp_r24_2;
    void *temp_r25;
    void *temp_r25_2;
    void *temp_r26;
    void *temp_r26_2;
    void *temp_r27;
    void *temp_r28;
    void *temp_r29;

    var_ctr = 0x18;
    var_r4 = (char *)&stack[45].i;
    do {
        *(int *)((char *)(var_r4) + (4)) = 0;
        var_r4 += 8;
        *(int *)((char *)(var_r4) + (8)) = 0;
        var_ctr -= 1;
    } while (var_ctr != 0);
    temp_r0 = (int)(arg0 + 0xF8);
    stack[44].i = temp_r0;
    temp_r29 = lbl_80330F48 + 0x32C;
    stack[48].i = temp_r0;
    temp_r26 = lbl_80330F48 + 0x338;
    temp_r28 = lbl_80330F48 + 0x320;
    stack[30].i = 1;
    temp_r11 = (int)(arg0 + 0xFC);
    temp_r10 = (int)(arg0 + 0x100);
    stack[42].i = 3;
    temp_r7 = (int)(arg0 + 0x104);
    temp_r25 = lbl_80330F48 + 0x344;
    stack[43].p = temp_r28;
    temp_r6 = (int)(arg0 + 0x30);
    temp_r5 = (int)(arg0 + 0x44);
    stack[46].i = 3;
    temp_r24 = lbl_80330F48 + 0x350;
    temp_r4 = (int)(arg0 + 0x58);
    stack[47].p = temp_r28;
    temp_r0_2 = (int)(arg0 + 0x6C);
    stack[39].i = 3;
    temp_r8 = (int)(arg0 + 0x80);
    stack[40].p = temp_r29;
    stack[41].i = temp_r11;
    stack[49].i = 3;
    stack[50].p = temp_r29;
    stack[51].i = temp_r11;
    stack[36].i = 3;
    stack[37].p = &lbl_8055A2C8;
    stack[38].i = temp_r10;
    stack[52].i = 3;
    stack[53].p = &lbl_8055A2C8;
    stack[54].i = temp_r10;
    stack[33].i = 3;
    stack[34].p = temp_r26;
    stack[35].i = temp_r7;
    stack[55].i = 3;
    stack[56].p = temp_r26;
    stack[57].i = temp_r7;
    stack[31].p = temp_r25;
    stack[32].i = temp_r6;
    stack[58].i = 1;
    stack[59].p = temp_r25;
    stack[60].i = temp_r6;
    stack[27].i = 1;
    stack[28].p = temp_r29;
    stack[29].i = temp_r5;
    stack[61].i = 1;
    stack[62].p = temp_r29;
    stack[63].i = temp_r5;
    stack[24].i = 1;
    stack[25].p = temp_r24;
    stack[26].i = temp_r4;
    stack[64].i = 1;
    stack[65].p = temp_r24;
    stack[66].i = temp_r4;
    stack[21].i = 1;
    stack[22].p = temp_r26;
    stack[23].i = temp_r0_2;
    stack[67].i = 1;
    stack[68].p = temp_r26;
    stack[69].i = temp_r0_2;
    stack[18].i = 1;
    stack[19].p = &lbl_8055A2C8;
    stack[20].i = temp_r8;
    stack[70].i = 1;
    var_r4_2 = arg0 + 0x8A;
    temp_r24_2 = lbl_80330F48 + 0x368;
    temp_r12 = (int)(arg0 + 0x9E);
    temp_r25_2 = lbl_80330F48 + 0x384;
    stack[71].p = &lbl_8055A2C8;
    temp_r11_2 = (int)(arg0 + 0xB2);
    temp_r23 = lbl_80330F48 + 0x39C;
    stack[72].i = temp_r8;
    temp_r10_2 = (int)(arg0 + 0xC6);
    temp_r26_2 = lbl_80330F48 + 0x3B4;
    stack[15].i = 1;
    temp_r9 = (int)(arg0 + 0xDA);
    temp_r27 = lbl_80330F48 + 0x3C8;
    stack[16].p = temp_r24_2;
    temp_r7_2 = (int)(arg0 + 0xF0);
    stack[74].p = temp_r24_2;
    var_r22 = &lbl_8055A2D0;
    stack[17].p = var_r4_2;
    var_r24 = 0x14;
    stack[73].i = 1;
    stack[75].p = var_r4_2;
    stack[12].i = 1;
    stack[13].p = temp_r28;
    stack[14].i = temp_r12;
    stack[76].i = 1;
    stack[77].p = temp_r28;
    stack[78].i = temp_r12;
    stack[9].i = 1;
    stack[10].p = temp_r25_2;
    stack[11].i = temp_r11_2;
    stack[79].i = 1;
    stack[80].p = temp_r25_2;
    stack[81].i = temp_r11_2;
    stack[6].i = 1;
    stack[7].p = temp_r23;
    stack[8].i = temp_r10_2;
    stack[82].i = 1;
    stack[83].p = temp_r23;
    stack[84].i = temp_r10_2;
    stack[3].i = 1;
    stack[4].p = temp_r26_2;
    stack[5].i = temp_r9;
    stack[85].i = 1;
    stack[86].p = temp_r26_2;
    stack[87].i = temp_r9;
    stack[0].i = 2;
    stack[1].p = temp_r27;
    stack[2].i = temp_r7_2;
    stack[88].i = 2;
    stack[89].p = temp_r27;
    stack[90].i = temp_r7_2;
    stack[91].i = *(int *)((char *)(&lbl_802FAA40) + (0));
    stack[92].i = *(int *)((char *)(&lbl_802FAA40) + (4));
    stack[93].i = *(int *)((char *)(&lbl_802FAA40) + (8));
loop_5:
    temp_r5_2 = *var_r22;
    var_r22 += 1;
    *var_r4_2 = temp_r5_2;
    var_r4_2 += 1;
    if ((signed char) temp_r5_2 != 0) {
        var_r24 -= 1;
        if (var_r24 <= 0) {
            *(signed char *)((char *)(var_r4_2) + (-1)) = 0;
        } else {
            goto loop_5;
        }
    }
    var_r7 = arg0 + 0x44;
    var_r5 = &lbl_8055A2D4;
    var_r6 = 0x14;
loop_9:
    temp_r4_2 = *var_r5;
    var_r5 += 1;
    *var_r7 = temp_r4_2;
    var_r7 += 1;
    if ((signed char) temp_r4_2 != 0) {
        var_r6 -= 1;
        if (var_r6 <= 0) {
            *(signed char *)((char *)(var_r7) + (-1)) = 0;
        } else {
            goto loop_9;
        }
    }
    var_r7_2 = arg0 + 0x6C;
    var_r5_2 = &lbl_8055A2D8;
    var_r6_2 = 0x14;
loop_13:
    temp_r4_3 = *var_r5_2;
    var_r5_2 += 1;
    *var_r7_2 = temp_r4_3;
    var_r7_2 += 1;
    if ((signed char) temp_r4_3 != 0) {
        var_r6_2 -= 1;
        if (var_r6_2 <= 0) {
            *(signed char *)((char *)(var_r7_2) + (-1)) = 0;
        } else {
            goto loop_13;
        }
    }
    fn_80130980(arg0 + 0x9E, 0x14, 2, lbl_80561AB4);
    *(int *)((char *)(arg0) + (0xF0)) = (int) (fn_80204CF0() + 1);
    *(int *)((char *)(arg0) + (0xF4)) = fn_802ADF34((void *)*(int *)((char *)(arg0) + (0xC)), lbl_80330F48 + 0x3DC, &stack[46].i);
    *(int *)((char *)(arg0) + (0x14)) = fn_80207848(lbl_80330F48 + 0x3F0, 1);
    *(int *)((char *)(arg0) + (0x18)) = fn_80207848(lbl_80330F48 + 0x404, 1);
    *(int *)((char *)(arg0) + (0x1C)) = fn_80207848(lbl_80330F48 + 0x420, 1);
    *(int *)((char *)(arg0) + (0x24)) = fn_80207848(lbl_80330F48 + 0x434, 1);
    *(int *)((char *)(arg0) + (0x28)) = fn_80207848(lbl_80330F48 + 0x448, 1);
    *(int *)((char *)(arg0) + (0x2C)) = fn_80207848(lbl_80330F48 + 0x454, 1);
}

extern void fn_802ADE60(int, int);
extern void deleteThreads__6SystemFv_80173A2C(void *);
#pragma cplusplus on
extern "C" void fn_801738D4(void *arg0) {
    class VObj { public: virtual void destroy(int); };
    VObj *p;
    int value;
    value = *(int *)((char *)arg0 + 0x1B8);
    if (value != 0) {
        fn_802ADE60(value, 1);
        *(int *)((char *)arg0 + 0x1B8) = 0;
    }
    p = *(VObj **)((char *)arg0 + 0x1C0);
    if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((char *)arg0 + 0x1C0) = 0; }
    p = *(VObj **)((char *)arg0 + 0x1C4);
    if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((char *)arg0 + 0x1C4) = 0; }
    p = *(VObj **)((char *)arg0 + 0x1C8);
    if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((char *)arg0 + 0x1C8) = 0; }
    p = *(VObj **)((char *)arg0 + 0x1D0);
    if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((char *)arg0 + 0x1D0) = 0; }
    p = *(VObj **)((char *)arg0 + 0x1D4);
    if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((char *)arg0 + 0x1D4) = 0; }
    p = *(VObj **)((char *)arg0 + 0x1D8);
    if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)((char *)arg0 + 0x1D8) = 0; }
    deleteThreads__6SystemFv_80173A2C((char *)arg0 + 0x1A8);
}
#pragma cplusplus reset

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void deleteThreads__6SystemFv_80173A2C(void *arg0) {
    class ThreadObject80173A2C {
    public:
        virtual void destroy(int);
    };
    ThreadObject80173A2C *p = *(ThreadObject80173A2C **)arg0;
    if (p) {
        if (p)
            p->destroy(1);
        *(ThreadObject80173A2C **)arg0 = 0;
    }
}
#pragma cplusplus reset
#pragma pop

int fn_80173A84(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x170);
    int result = 0;
    int i;
    if (count > 0) {
        for (i = 0; i < count; i++) {
            if (*(unsigned char *)((char *)arg0 + 0x91) == 0 &&
                *(unsigned char *)((char *)arg0 + 0x90) != 0)
                result++;
            arg0 = (char *)arg0 + 0x1C;
        }
    }
    return result != 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80173ACC(void *arg0) {
    extern float lbl_8043038C[];
    extern char lbl_80330F48[];
    extern unsigned char lbl_8055A2A4;
    extern float lbl_80561A44, lbl_80561AB8, lbl_80561ABC, lbl_8055E3C8;
    extern float lbl_80558DC4[];
    int i, n;
    char *e;
    char *base = lbl_80330F48;
    char *tbl;
    float one = lbl_8055E3C8;
    float zero, big;
    float x;
    char *p = (char *)arg0;

    if (*(unsigned char *)(p + 0x2B8) == 0 && fn_801B306C() < lbl_80561AB8) {
        *(unsigned char *)(p + 0x2B8) = 1;
        if (*(int *)(p + 0x2B4) != 0 && fn_80161C38() == 0 && fn_80179650() == 1 && fn_80009C84() == 0) {
            char *q = *(char **)(p + 0x2B4);
            *(unsigned char *)(q + 0x49) = 1;
            *(unsigned char *)(q + 0x4B) = 0;
            *(unsigned char *)(q + 0x4A) = 0;
        }
    }
    if (fn_801B306C() >= lbl_80561A44) {
        *(float *)(p + 0x19C) = one + *(float *)(p + 0x1A4);
    }
    tbl = (char *)lbl_8043038C;
    zero = lbl_80561A44;
    big = lbl_80561ABC;
    e = p;
    for (i = 0; i < *(int *)(p + 0x170); i++, e += 0x1C) {
        if (*(unsigned char *)(e + 0x91) != 0 && *(unsigned char *)(tbl + 0x11) != 0) {
            *(float *)((char *)fn_8017960C(i) + 0x25A0) = zero;
        }
        if (*(unsigned char *)(e + 0x91) == 0 && *(unsigned char *)(e + 0x90) == 0) {
            *(float *)((char *)fn_8017960C(i) + 0x25A0) = big;
        }
    }
    if ((*(int (**)(void *))(*(char **)p + 0x24))(p) == 0) {
        n = 0;
        e = p;
        for (i = 0; i < *(int *)(p + 0x170); i++, e += 0x1C) {
            if (*(unsigned char *)(e + 0x91) == 0 && *(unsigned char *)(e + 0x90) != 0) n++;
        }
        if (n == 0) {
            int ok = 0;
            x = fn_8001DAE8(p + 0x174) - *(float *)(p + 0x178);
            if (x >= zero && x < *(float *)(p + 0x174)) ok = 1;
            if (ok == 0) {
                if (*(unsigned char *)(p + 0x194) != 0) {
                    e = p + 0x90;
                    for (i = 0; i < *(int *)(p + 0x170); i++, e += 0x1C) {
                        if (*(unsigned char *)e != 0) {
                            *(unsigned char *)e = 0;
                            *(float *)(e + 0x18) = one;
                        }
                        if (*(unsigned char *)(e + 1) != 0) {
                            fn_801CB5DC(i, *(int *)(e + 4) + *(int *)(tbl + 0x14) * (*(int *)(e + 0xC) + *(int *)(e + 8)),
                                        fn_801609C4(*(int *)(e + 4) + *(int *)(tbl + 0x14) * (*(int *)(e + 0xC) + *(int *)(e + 8))));
                            fn_801CB648(i, 1, (float)*(int *)(e + 4));
                        }
                    }
                    *(float *)(p + 0x1A0) = one;
                } else {
                    *(float *)(p + 0x178) = fn_8001DAE8(p + 0x174);
                }
                *(unsigned char *)(p + 0x194) = 1;
                COPY_STR20(p + 0x25E, fn_80131234(base + 0x460));
                COPY_STR20(p + 0x272, fn_80131234(base + 0x484));
                COPY_STR20(p + 0x286, &lbl_8055A2A4);
            }
        }
        x = *(float *)(p + 0x19C) - one;
        if (zero > x) x = zero;
        if ((float)__fabs(x) <= lbl_80558DC4[0]) {
            n = 0;
            e = p;
            for (i = 0; i < *(int *)(p + 0x170); i++, e += 0x1C) {
                if (*(unsigned char *)(e + 0x91) == 0 && *(unsigned char *)(e + 0x90) != 0) n++;
            }
            if (n > 0) {
                COPY_STR20(p + 0x286, fn_80131234(base + 0x4A8));
                COPY_STR20(p + 0x25E, &lbl_8055A2A4);
                COPY_STR20(p + 0x272, &lbl_8055A2A4);
                e = p + 0x90;
                for (i = 0; i < *(int *)(p + 0x170); i++, e += 0x1C) {
                    if (*(unsigned char *)e != 0) {
                        *(unsigned char *)e = 0;
                        *(float *)(e + 0x18) = one;
                    }
                    if (*(unsigned char *)(e + 1) != 0) {
                        fn_801CB5DC(i, *(int *)(e + 4) + *(int *)(tbl + 0x14) * (*(int *)(e + 0xC) + *(int *)(e + 8)),
                                    fn_801609C4(*(int *)(e + 4) + *(int *)(tbl + 0x14) * (*(int *)(e + 0xC) + *(int *)(e + 8))));
                        fn_801CB648(i, 1, (float)*(int *)(e + 4));
                    }
                }
                *(float *)(p + 0x1A0) = one;
            }
        }
    } else {
        int ok = 0;
        x = fn_8001DAE8(p + 0x17C) - *(float *)(p + 0x180);
        if (x >= zero && x < *(float *)(p + 0x17C)) ok = 1;
        if (ok == 0) {
            char *r = p + fn_80179630(0) * 0x1C;
            int a = *(int *)(r + 0x94);
            int b = *(int *)(tbl + 0x14) * (*(int *)(r + 0x98) + *(int *)(r + 0x9C));
            fn_8017272C(p + 0x1AC, a + b, b, a, *(int *)(tbl + 0x14));
        }
    }
}
#pragma use_lmw_stmw reset
#pragma processor reset
#pragma pop
extern float lbl_80561A50, lbl_80561AC0;
extern void *memset(void *, int, unsigned long);
extern void fn_802AE0E0(void);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_801740D4(void *arg0) {
    unsigned char *self = (unsigned char *)arg0;
    float copied = *(volatile float *)(self + 0x1A4);
    int zero = 0;
    float one = lbl_80561A50;
    unsigned char *cursor = self;
    unsigned char *entry = self + 0x90;
    int i = 0;
    int enabled = 1;
    *(unsigned char *)(self + 0x194) = zero;
    *(float *)(self + 0x19C) = copied;
    *(float *)(self + 0x1A0) = one;
    while (i < *(int *)(self + 0x170)) {
        *(unsigned char *)(cursor + 0x90) = enabled;
        *(float *)(cursor + 0xA8) = one;
        *(int *)(cursor + 0x9C) = zero;
        *(int *)(cursor + 0x98) = zero;
        *(int *)(cursor + 0x94) = zero;
        memset(entry + 0x10, zero, 8);
        cursor += 0x1C;
        entry += 0x1C;
        i++;
    }
    {
        int handle;
        int reset;
        float high;
        int enabled2;
        float low;
        handle = *(int *)(self + 0x1B8);
        reset = 0;
        low = lbl_80561AC0;
        enabled2 = 1;
        high = lbl_80561A50;
        *(float *)(self + 0x180) = low;
        *(float *)(self + 0x188) = low;
        *(float *)(self + 0x190) = low;
        *(float *)(self + 0x178) = low;
        *(int *)(self + 0x1AC) = reset;
        *(float *)(self + 0x1B0) = high;
        *(unsigned char *)(self + 0x1B4) = enabled2;
        *(unsigned char *)(self + 0x1B5) = reset;
        *(unsigned char *)(self + 0x1BC) = reset;
        *(int *)(self + 0x2A4) = reset;
        *(int *)(self + 0x2A8) = reset;
        *(int *)(self + 0x2AC) = reset;
        *(int *)(self + 0x2B0) = reset;
        if (handle != 0)
            fn_802AE0E0();
    }
    {
        void *obj = *(void **)(self + 0x1C0);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = 0; }
    }
    {
        void *obj = *(void **)(self + 0x1C4);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = 0; }
    }
    {
        void *obj = *(void **)(self + 0x1C8);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = 0; }
    }
    zero = 0;
    *(unsigned char *)(self + 0x1CC) = zero;
    {
        void *obj = *(void **)(self + 0x1D0);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = zero; }
    }
    {
        void *obj = *(void **)(self + 0x1D4);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = 0; }
    }
    {
        void *obj = *(void **)(self + 0x1D8);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = 0; }
    }
    {
        void *obj = *(void **)(self + 0x2B4);
        if (obj) { ((unsigned char *)obj)[0x4A] = 1; ((unsigned char *)obj)[0x4C] = 0; }
    }
    *(unsigned char *)(self + 0x2B8) = 0;
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma processor reset
#pragma pop
int fn_80174298(void *arg0, int arg1) {
    extern float lbl_80558DC4[];
    extern float lbl_8055E3C8;
    extern float lbl_80561A44;
    int result = *((unsigned char *)arg0 + arg1 * 0x1C + 0x90);
    if (result != 0) {
        float one = lbl_8055E3C8;
        float value = *(float *)((char *)arg0 + 0x19C) - one;
        float limit = lbl_80561A44;
        limit = limit > value ? limit : value;
        result = !((float)__fabs(limit) <= lbl_80558DC4[0]);
    }
    return result;
}

int fn_801742FC(void *arg0) {
    extern float lbl_80561A44;
    return *(float *)((char *)arg0 + 0x1A0) > lbl_80561A44;
}

int fn_80174314(void) {
    return 8;
}

void fn_8017431C(int arg0, int arg1) {
    extern int fn_802B04D4(float *);
    extern float fn_801DCF48(void *, float, float);
    extern void fn_8018AF04();
    extern void fn_801E9DC4(short *);
    extern void fn_801B7C8C(void *, void *, float *);
    extern void PSVECNormalize(float *, float *);
    extern float lbl_80561A44, lbl_80561A74, lbl_80561AB0, lbl_80561AC4, lbl_80561ACC, lbl_80561AD0, lbl_80561AD4;
    Fn8017431CFrame2 cam;
    float tgt[3];
    float dir[3];
    float sp38[2];
    float sp30[2];
    float sp28[2];
    float sp20[2];
    unsigned long long ret;
    Fn8017431CV2 pv;
    float sp8[2];
    char *obj;
    float *p;
    int inside;
    float dx, dz, dist;
    if (*(unsigned char *)(arg0 + arg1 * 0x1C + 0x90) != 0) {
        obj = (char *)fn_8017960C(arg1);
        fn_8018AF04();
        cam.mark = -1;
        fn_801E9DC4(&cam.mark);
        cam.zero = 0;
        p = (float *)(obj + 0x60);
        cam.m = *(Fn8017431CM9 *)(obj + 0x3C);
        cam.pos = *(Fn8017431CV3 *)(obj + 0x60);
        cam.v.a[0] = lbl_80561A44;
        cam.v.a[1] = lbl_80561A44;
        cam.v.a[2] = lbl_80561A44;
        sp38[0] = p[0];
        sp38[1] = p[2];
        if (fn_802B04D4(p) != 0 || fn_80171E3C(sp38) == 0) {
            sp8[0] = p[0];
            sp8[1] = p[2];
            ret = fn_80171FF0(sp8, 99, lbl_80561AC4, lbl_80561AC8);
            *(double *)&pv = *(double *)&ret;
            tgt[1] = lbl_80561A44;
            tgt[0] = pv.a;
            tgt[2] = pv.b;
            tgt[1] = fn_801DCF48(0, tgt[0], tgt[2]);
            inside = 0;
            if (fn_802B04D4(p) != 0 && fn_80171DE4(sp38) == 0) inside = 1;
            if (inside != 0) {
                float s = lbl_80561A74;
                float k = lbl_80561A40 / s;
                dir[1] = (tgt[1] - p[1]) * k + lbl_80561ACC * s;
                dir[0] = (tgt[0] - p[0]) * k;
                dir[2] = (tgt[2] - p[2]) * k;
                cam.pos.a[0] = p[0];
                cam.pos.a[1] = p[1];
                cam.pos.a[2] = p[2];
                cam.m.a[3] = lbl_80561A44; cam.m.a[4] = lbl_80561A40; cam.m.a[5] = lbl_80561A44;
                cam.m.a[6] = dir[0]; cam.m.a[7] = lbl_80561A44; cam.m.a[8] = dir[2];
                PSVECNormalize(&cam.m.a[6], &cam.m.a[6]);
                cam.m.a[0] = cam.m.a[8];
                cam.m.a[1] = lbl_80561A44;
                cam.m.a[2] = -cam.m.a[6];
                cam.v.a[0] = dir[0];
                cam.v.a[1] = dir[1];
                cam.v.a[2] = dir[2];
            } else {
                dx = tgt[0] - sp38[0];
                dz = tgt[2] - sp38[1];
                sp30[0] = tgt[0]; sp30[1] = tgt[2];
                sp28[0] = dx; sp28[1] = dz;
                dist = (float)fn_8002F234(dx * dx + dz * dz);
                if (lbl_80561AD0 > dist) dist = lbl_80561AD0;
                dist = lbl_80561A40 / dist;
                sp28[0] = sp28[0] * dist;
                sp28[1] = sp28[1] * dist;
                fn_801B7C8C(&cam, sp30, sp28);
                cam.pos.a[2] = cam.pos.a[2] + lbl_80561A3C;
                cam.v.a[0] = cam.m.a[6] * lbl_80561AD4;
                cam.v.a[1] = cam.m.a[7] * lbl_80561AD4;
                cam.v.a[2] = cam.m.a[8] * lbl_80561AD4;
            }
        } else if (*(float *)(obj + 0x4C) < lbl_80561AB0) {
            sp20[0] = *(float *)(obj + 0x54);
            sp20[1] = *(float *)(obj + 0x5C);
            dist = (float)fn_8002F234(sp20[0] * sp20[0] + sp20[1] * sp20[1]);
            if (lbl_80561AD0 > dist) dist = lbl_80561AD0;
            dist = lbl_80561A40 / dist;
            sp20[0] = sp20[0] * dist;
            sp20[1] = sp20[1] * dist;
            fn_801B7C8C(&cam, sp38, sp20);
        }
        (*(void (**)(void *, void *))(*(char **)obj + 0x54))(obj, &cam);
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_801746D0(int *arg0, int *arg1, int arg2) {
    extern float lbl_8043038C[];
    int i;
    int is_zero;
    int *src;
    int *row;
    int *table;

    arg1[0] = arg0[0x170 / 4];
    arg1[1] = 1;
    *(unsigned char *)((unsigned char *)arg1 + 0xD) =
        (unsigned char)((int (*)(void *))(*(void ***)arg0)[9])(arg0);
    *(unsigned char *)((unsigned char *)arg1 + 0xC) = 0;
    src = arg0;
    row = (int *)((unsigned char *)arg1 + 0x10);
    table = (int *)lbl_8043038C;
    i = 0;
    while (i < arg1[0]) {
        is_zero = !((int (*)(int))fn_80171EC0)(i);
        *(unsigned char *)((unsigned char *)row + 0x10) = (unsigned char)is_zero;
        row[1] = i;
        i += 1;
        row[2] = src[0x94 / 4] +
            ((src[0x9C / 4] + src[0x98 / 4]) * table[5]);
        row = (int *)((unsigned char *)row + 0x14);
        src += 0x1C / 4;
    }
}
#pragma scheduling on
#pragma pop
void fn_80174794(void **arg0) {
    extern float fn_801B306C(void);
    extern int fn_800216D0(void);
    extern int fn_801EA994(void);
    extern int fn_801E866C(int);
    extern void fn_8017248C(int);
    extern float lbl_80561A44;
    int count;
    int i;
    if (fn_801B306C() < lbl_80561A44 && fn_800216D0() == 0) {
        count = fn_801EA994();
        for (i = 0; i < count; i++) {
            if (i != fn_801E866C(-1) &&
                (*(int (**)(void **, int))((char *)*arg0 + 0x20))(arg0, i) != 0) {
                fn_8017248C(i);
            }
        }
    }
}
#pragma push
#pragma scheduling invalid_target
int fn_8017483C(void *arg0, void *arg1, int arg2) {
    extern double fn_8002F234(float);
    extern void fn_801B7C8C(void *, void *, float *);
    extern float lbl_80561A40, lbl_80561A50, lbl_80561AD0;
    float xy[2], length, minimum, scale;
    void *entry;
    if (arg2 < *(int *)((char *)arg0 + 8)) {
        entry = (char *)*(void **)((char *)arg0 + 4) + arg2 * 8;
        xy[0] = *(float *)entry * lbl_80561A50;
        xy[1] = *(float *)((char *)entry + 4) * lbl_80561A50;
        length = (float)fn_8002F234(xy[0] * xy[0] + xy[1] * xy[1]);
        minimum = lbl_80561AD0;
        minimum = (minimum > length) ? minimum : length;
        scale = lbl_80561A40 / minimum;
        xy[0] = xy[0] * scale;
        xy[1] = xy[1] * scale;
        fn_801B7C8C(arg1, entry, xy);
        *(int *)((char *)arg1 + 0x44) = 2;
        *(int *)((char *)arg1 + 0x48) = 0;
        *(int *)((char *)arg1 + 0x4C) = 0;
        return 1;
    }
    return 0;
}
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
#pragma push
#pragma small_data on
extern "C" const char lbl_8055A2EC[];
#pragma pop
extern "C" void fn_80175080(void **arg0, int arg1, int arg2, char *fmt, double farg0, ...) {
    struct Dummy {
        virtual void *unused();
        virtual void *get(int);
    };
    extern void *fn_80147CEC(void *, void *, void *, double);
    extern void fn_80147230(void *, const char *, ...);
    extern void fn_801476C4(void *);
    extern void fn_802E317C(const char *, ...);
    extern int vsprintf(char *, const char *, void *);
    extern unsigned int strlen(const char *);
    extern const char lbl_803314F8[];
    char result[0x20];
    char text[0x80];
    void *v;
    void *p;
    va_list args;
    v = ((Dummy *)arg0)->get(arg1);
    p = ((Dummy *)arg0)->get(arg2);
    if (v != 0) {
        fn_80147CEC(result, v, p, farg0);
    } else {
        int *dst = (int *)result;
        int *src = (int *)p;
        int w4, w8;
        dst[0] = src[0];
        w4 = src[1];
        w8 = src[2];
        dst[1] = w4;
        dst[2] = w8;
        dst[3] = src[3];
        *(float *)(result + 0x10) = *(float *)((char *)p + 0x10);
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
    }
    if (fmt != 0) {
        va_start(args, farg0);
        vsprintf(text, fmt, args);
        if (strlen(text) >= 0x80) {
            fn_802E317C(lbl_803314F8, strlen(text), fmt);
        }
        fn_80147230(result, lbl_8055A2EC, text);
    } else {
        fn_801476C4(result);
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma processor reset
#pragma cplusplus reset
typedef void (*Fn_80175228)(void *);
#pragma cplusplus on
extern "C" void fn_80175228(void *arg0) {
    ((TObj4C *)arg0)->v4C();
}

#pragma cplusplus reset
extern float lbl_80561A44, lbl_80561A50, lbl_80561A54, lbl_80561AB8, lbl_80561ADC, lbl_80561AE0, lbl_80561AE4, lbl_80561AE8;
extern char lbl_80330F48[];
__declspec(section ".sdata") extern char lbl_8055A2E4[];
extern void *fn_801E7E3C(void);
extern int fn_80161C38(void), fn_80160998(void), fn_801E866C(int);
extern float fn_801E7E18(void);
extern void fn_8000FBE4(void), fn_80160A74(void), fn_8001DF08(int, int);
extern void *fn_80131234(const char *);
extern void fn_80130978(void *, int, float);
extern float fn_80147204(void *, void *);
extern void fn_8014784C(void *, const char *, const char *, int);
extern void fn_801479A8(void *, void *, void *, ...);
#pragma cplusplus on
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern "C" int fn_80175238(void *arg0, int arg1) {
 struct Rect { int a; float b; int c,d; float e; int f,g,h; };
 struct Manager { virtual void *unused(); virtual void *get(const char *); };
 struct Frame { Rect rect2; char text2[24]; Rect rect1; char text1[20]; } frame;
 struct Manager *mgr; void *one, *two; void *panel, *detail;
 float a, time, limit,b,c,d,e, t, blend, value;
 char *base = lbl_80330F48;
 time = *(float *)((char *)fn_801E7E3C()+0x10);
 limit=lbl_80561AB8; a=limit-lbl_80561AE0; b=a-lbl_80561AE4;
 c=b-lbl_80561AE8; d=c-lbl_80561AE0; e=d-lbl_80561AE4;
 mgr=*(struct Manager **)((char *)arg0+0x1a8);
 one=mgr->get(base+0x5d8);
 mgr=*(struct Manager **)((char *)arg0+0x1a8);
 two=mgr->get(base+0x5e8);
 if (time < e) fn_8000FBE4();
 if (!fn_80161C38()) {
   if (time < limit) {
     t=(time-a)/(b-a); blend=lbl_80561A40;
     blend = blend < t ? blend : t;
     blend = blend > lbl_80561A44 ? blend : lbl_80561A44;
     blend=lbl_80561A44+blend*lbl_80561A40;
     mgr=*(struct Manager **)((char *)arg0+0x1a8);
     panel=mgr->get(base+0x5f8);
     mgr=*(struct Manager **)((char *)arg0+0x1a8);
     detail=mgr->get(base+0x604);
     ((void (*)(int, int))fn_8001DF08)(fn_801E866C(arg1),0);
     if (one && two && panel && detail) {
       value=lbl_80561A50;
if (blend < value) {} else {
 value=lbl_80561A40;
 if (blend > value) {} else {
  if (blend > lbl_80561A44) value=(blend*(lbl_80561ADC*blend*blend))+(lbl_80561A3C*blend*blend);
  else value=(blend*(lbl_80561ADC*blend*blend))-(lbl_80561A3C*blend*blend);
 }
}
       fn_801479A8(one,two,fn_80131234(base+0x610),value);
       fn_80160A74(); fn_801308F4(frame.text1,0x14,fn_80160998());
       frame.rect1.a=*(int *)panel;
       { int bword=*(int *)((char *)panel+4), cword=*(int *)((char *)panel+8); *(int *)&frame.rect1.b=bword; frame.rect1.c=cword; } frame.rect1.d=*(int *)((char *)panel+12); frame.rect1.e=*(float *)((char *)panel+16); frame.rect1.f=*(int *)((char *)panel+20); frame.rect1.g=*(int *)((char *)panel+24); frame.rect1.h=*(int *)((char *)panel+28);
       frame.rect1.b-=lbl_80561A54*fn_80147204(&frame.rect1,frame.text1);
       value=lbl_80561A50;
if (blend < value) {} else {
 value=lbl_80561A40;
 if (blend > value) {} else {
  if (blend > lbl_80561A44) value=(blend*(lbl_80561ADC*blend*blend))+(lbl_80561A3C*blend*blend);
  else value=(blend*(lbl_80561ADC*blend*blend))-(lbl_80561A3C*blend*blend);
 }
}
       fn_801479A8(&frame.rect1,detail,frame.text1,value);
     }
   }
   if (time < c) {
     fn_8014784C(*(void **)((char *)arg0+0x1a8),base+0x500,base+0x510,0);
     t=(time-d)/(e-d); blend=lbl_80561A40;
     blend = blend < t ? blend : t;
     blend = blend > lbl_80561A44 ? blend : lbl_80561A44;
     blend=lbl_80561A44+blend*lbl_80561A40;
     mgr=*(struct Manager **)((char *)arg0+0x1a8);
     panel=mgr->get(base+0x62c);
     mgr=*(struct Manager **)((char *)arg0+0x1a8);
     detail=mgr->get(lbl_8055A2E4);
     if (one && two && panel && detail) {
       value=lbl_80561A50;
if (blend < value) {} else {
 value=lbl_80561A40;
 if (blend > value) {} else {
  if (blend > lbl_80561A44) value=(blend*(lbl_80561ADC*blend*blend))+(lbl_80561A3C*blend*blend);
  else value=(blend*(lbl_80561ADC*blend*blend))-(lbl_80561A3C*blend*blend);
 }
}
       fn_801479A8(one,two,fn_80131234(base+0x638),value);
       t=*(float *)((char *)arg0+0x19c)-fn_801E7E18();
       value=lbl_80561A44; value = value > t ? value : t;
       fn_80130978(frame.text2,0x14,value);
       frame.rect2.a=*(int *)panel;
       { int bword=*(int *)((char *)panel+4), cword=*(int *)((char *)panel+8); *(int *)&frame.rect2.b=bword; frame.rect2.c=cword; } frame.rect2.d=*(int *)((char *)panel+12); frame.rect2.e=*(float *)((char *)panel+16); frame.rect2.f=*(int *)((char *)panel+20); frame.rect2.g=*(int *)((char *)panel+24); frame.rect2.h=*(int *)((char *)panel+28);
       frame.rect2.b+=lbl_80561A54*fn_80147204(&frame.rect2,frame.text2);
       value=lbl_80561A50;
if (blend < value) {} else {
 value=lbl_80561A40;
 if (blend > value) {} else {
  if (blend > lbl_80561A44) value=(blend*(lbl_80561ADC*blend*blend))+(lbl_80561A3C*blend*blend);
  else value=(blend*(lbl_80561ADC*blend*blend))-(lbl_80561A3C*blend*blend);
 }
}
       fn_801479A8(&frame.rect2,detail,frame.text2,value);
     }
   }
 }
 return 1;
}
#pragma pop

#pragma cplusplus reset
extern float lbl_80561AEC;
float fn_801757A8(void) { return lbl_80561AEC; }

int fn_801757B0(void) { return 1; }

#pragma push
#pragma cplusplus on
extern "C" int fn_801757B8(void *arg0, int arg1) {
    class Query {
    public:
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void d16(); virtual void callback(int);
        virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21();
        virtual void d22(); virtual void d23(); virtual int query();
    };
    struct State { char pad[0x17C]; volatile float upper; };
    extern int fn_801E866C(int);
    extern float fn_8001DAE8(void *);
    extern int fn_802AE220(int, int);
    extern void fn_8001DFCC(void);
    extern float lbl_80561A44;
    float value;
    int result;
    fn_801E866C(arg1);
    value = fn_8001DAE8((char *)arg0 + 0x17C) - *(float *)((char *)arg0 + 0x180);
    result = value >= lbl_80561A44 &&
             value < ((State *)arg0)->upper;
    if (result != 0) {
        ((Query *)arg0)->callback(arg1);
    } else {
        if (*(unsigned char *)((char *)arg0 + 0x1B4) != 0)
            ((Query *)arg0)->callback(arg1);
        if (*(int *)((char *)arg0 + 0x1B8) != 0)
            fn_802AE220(*(int *)((char *)arg0 + 0x1B8), 0);
    }
    if (((Query *)arg0)->query() != 0)
        fn_8001DFCC();
    {
        int field = *(int *)((char *)arg0 + 0x1AC);
        return (unsigned int)((4 - field) | (field - 4)) >> 31;
    }
}
#pragma cplusplus reset
#pragma pop
int fn_801758B8(void *arg0) { return *(int *)((char *)arg0 + 0x1AC) == 2; }

extern void fn_802AE118(void);
extern float lbl_8055E3C8, lbl_80561A40, lbl_80561A44;
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" int fn_801758CC(void *arg0, int arg1, int arg2) {
    class Query {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
        virtual int query();
    };
    int result = 0;
    if (((Query *)arg0)->query() != 0 && arg2 == 0x58) {
        if (*(volatile int *)((char *)arg0 + 0x1AC) == 2)
            *((unsigned char *)arg0 + 0x1B5) = 1;
        result = 1;
    } else if (*(volatile int *)((char *)arg0 + 0x1AC) != 0) {
        float total = lbl_8055E3C8;
        if (*(volatile int *)((char *)arg0 + 0x1AC) == 1 &&
            *((unsigned char *)arg0 + 0x1BC) == 0) {
            if (*(float *)((char *)arg0 + 0x1B0) > lbl_80561A44 &&
                total - *(float *)((char *)arg0 + 0x1B0) < lbl_80561A40) {
                void *p;
                int handle = *(int *)((char *)arg0 + 0x1B8);
                *((unsigned char *)arg0 + 0x1BC) = 1;
                if (handle != 0) fn_802AE118();
                p = *(void **)((char *)arg0 + 0x1C0);
                if (p) { *((unsigned char *)p + 0x4A) = 1; *((unsigned char *)p + 0x4C) = 0; }
                p = *(void **)((char *)arg0 + 0x1C4);
                if (p) { *((unsigned char *)p + 0x4A) = 1; *((unsigned char *)p + 0x4C) = 0; }
                p = *(void **)((char *)arg0 + 0x1D4);
                if (p) { *((unsigned char *)p + 0x4A) = 1; *((unsigned char *)p + 0x4C) = 0; }
                p = *(void **)((char *)arg0 + 0x1D8);
                if (p) { *((unsigned char *)p + 0x4A) = 1; *((unsigned char *)p + 0x4C) = 0; }
                {
                    float finalFloor;
                    float finalTotal;
                    int zero;
                    finalTotal = lbl_8055E3C8;
                    zero = 0;
                    finalFloor = lbl_80561A40;
                    if ((*((volatile unsigned char *)arg0 + 0x1B4) = zero) == 0)
                        *(float *)((char *)arg0 + 0x1B0) = finalTotal - finalFloor;
                }
            }
        }
        result = 1;
    }
    return result;
}
#pragma scheduling on
#pragma cplusplus reset
#pragma pop

int fn_80175A38(void *arg0, float *arg1, float *arg2, int arg3, int arg4, int *arg5) {
    char *p = (char *)arg0 + arg3 * 0x24;
    *arg5 = 0x21F;
    arg1[0] = *(float *)(p + 0x18);
    arg1[1] = *(float *)(p + 0x1C);
    *arg2 = *(float *)(p + 0x20);
    return 1;
}

extern void *fn_8017960C();
extern float lbl_80561AF0;
extern float lbl_80561AF4;
int fn_80175A68(void *unused, float *arg0, float *arg1, int arg2, void *unused2, int *arg3) {
    float *p = (float *)fn_8017960C(arg2);
    float first = p[0x54 / 4];
    float scale = lbl_80561AF0;
    float outValue = lbl_80561AF4;
    float x = first * scale + p[0x60 / 4];
    float z = p[0x58 / 4] * scale + p[0x64 / 4];
    float y = p[0x5C / 4] * scale + p[0x68 / 4];
    volatile float stack[3];
    arg0[0] = x;
    arg0[1] = y;
    *arg3 = 0x21F;
    *arg1 = outValue;
    stack[0] = x;
    stack[1] = z;
    stack[2] = y;
    return 1;
}

extern int fn_801B3050(int);
extern float fn_801725C8(float);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80175B0C(char *arg0) {
    float k = lbl_80561B04;
    float min24 = lbl_80561A78;
    float shrink24 = lbl_80561ABC;
    float min25 = lbl_80561B0C;
    float min26 = lbl_80561A80;
    float shrink = lbl_80561B08;
    float step = lbl_80561A38;
    char *out = arg0;
    int i = 0;
    for (; i < *(int *)(arg0 + 0x124); i++, out += 0x24) {
        float a, b, f24, f25, f26;
        float d[2], v[2], w[2];
        int n;
        char *obj;
        if (fn_801B3050(i) & 1) {
            a = lbl_80561AF8;
            b = lbl_80561A44;
        } else {
            a = lbl_80561A44;
            b = lbl_80561AFC;
        }
        f25 = fn_801725C8(lbl_8055E3C8);
        f26 = lbl_80561A38;
        f24 = lbl_80561B00;
        n = 0x13;
        do {
            float len, rad, c, s, dx, dy;
            obj = (char *)fn_8017960C(i);
            v[0] = *(float *)(obj + 0x60);
            v[1] = *(float *)(obj + 0x68);
            d[0] = *(float *)(obj + 0x54);
            d[1] = *(float *)(obj + 0x5C);
            len = (float)fn_8002F234(d[0] * d[0] + d[1] * d[1]);
            if (!((float)__fabs(len) <= lbl_80558DC4[0])) {
                float inv = f24 / len;
                d[0] *= inv;
                d[1] *= inv;
            }
            rad = fn_80129DC4(3, k * a, k * b);
            dx = d[0];
            c = (float)cos(rad);
            s = (float)sin(rad);
            w[0] = *(float *)(obj + 0x60);
            dy = d[1];
            d[0] = dx * c - dy * s;
            d[1] = dx * s + dy * c;
            w[0] = w[0] + d[0];
            w[1] = *(float *)(obj + 0x68) + d[1];
            if (fn_80171EF8(v, w) != 0)
                break;
            f26 = shrink * f26;
            a -= step;
            b += step;
            if (f26 > min26) {} else f26 = min26;
            f25 = shrink * f25;
            if (f25 > min25) {} else f25 = min25;
            f24 = shrink24 * f24;
            if (f24 > min24) {} else f24 = min24;
        } while (n-- > 0);
        *(float *)(out + 0x18) = w[0];
        *(float *)(out + 0x1C) = w[1];
        *(float *)(out + 0x20) = f25;
        *(float *)(out + 0x24) = f26 + lbl_8055E3C8;
        *(char *)(out + 4) = 0;
        *(int *)(out + 0x14) = -1;
    }
}
#pragma pop

#pragma push
#pragma processor 750
#pragma dont_inline on
void fn_80175D40(void *arg0) {
 float old[2],delta[2],base[2],velocity[2],pos[2],candidate[2];
 union {unsigned long long bits;float v[2];} result;
 float angle,cs,sn,len,scale,x,y;
 float factor=lbl_80561B04, step=lbl_80561A38;
 float decay=lbl_80561B08, minTime=lbl_80561A80,minValue=lbl_80561B0C;
 float grow=lbl_80561ABC,minScale=lbl_80561A78,radius=lbl_80561AB4,fallback=lbl_80561AC8;
 float left,right,value,time,distance;
 int i,tries;void *p,*obj;char *entry=(char *)arg0+4;
 for(i=0;i<(*(int *)((char *)(arg0)+(0x124)));i++,entry+=0x24) {
 obj=(*(void * *)((char *)(arg0)+(0x128)));
 if(((int (*)(void *,int))(*(void ***)obj)[8])(obj,i)==0)continue;
 p=fn_8017960C(i);
 old[0]=(*(float *)((char *)(p)+(0x60)));old[1]=(*(float *)((char *)(p)+(0x68)));
 delta[0]=old[0]-(*(float *)((char *)(entry)+(0x14)));delta[1]=old[1]-(*(float *)((char *)(entry)+(0x18)));
 if(delta[0]*delta[0]+delta[1]*delta[1]<radius*radius || lbl_8055E3C8>(*(float *)((char *)(entry)+(0x20)))){
 p=fn_8017960C(i);
 base[0]=(*(float *)((char *)(p)+(0x60)));base[1]=(*(float *)((char *)(p)+(0x68)));
 if(fn_80171E3C(base)) {
 left=lbl_80561AF8;right=lbl_80561AFC;
 value=fn_801725C8(lbl_8055E3C8);
 time=lbl_80561A38;distance=lbl_80561B00;
 tries=19;
 do{
 p=fn_8017960C(i);
 pos[0]=(*(float *)((char *)(p)+(0x60)));pos[1]=(*(float *)((char *)(p)+(0x68)));
 velocity[0]=(*(float *)((char *)(p)+(0x54)));velocity[1]=(*(float *)((char *)(p)+(0x5c)));
 len=(float)fn_8002F234(velocity[0]*velocity[0]+velocity[1]*velocity[1]);
 if(!((float)__fabs(len)<=lbl_80558DC4[0])){
 scale=distance/len;velocity[0]*=scale;velocity[1]*=scale;
 }
 angle=fn_80129DC4(3,factor*left,factor*right);
 x=velocity[0];cs=(float)cos(angle);sn=(float)sin(angle);
 candidate[0]=(*(float *)((char *)(p)+(0x60)));
 y=velocity[1];
 velocity[0]=x*cs-y*sn;
 velocity[1]=x*sn+y*cs;
 candidate[0]+=velocity[0];candidate[1]=(*(float *)((char *)(p)+(0x68)))+velocity[1];
 if(fn_80171EF8(pos,candidate))break;
 time*=decay;left-=step;right+=step;
 time=time>minTime?time:minTime;
 value*=decay;value=value>minValue?value:minValue;
 distance*=grow;distance=distance>minScale?distance:minScale;
 }while(tries-->0);
 (*(float *)((char *)(entry)+(0x14)))=candidate[0];(*(float *)((char *)(entry)+(0x18)))=candidate[1];
 (*(float *)((char *)(entry)+(0x1c)))=value;(*(float *)((char *)(entry)+(0x20)))=time+lbl_8055E3C8;
 }else{
 result.bits=fn_80171FF0(base,10,lbl_80561AC8,lbl_80561AC8);
 (*(float *)((char *)(entry)+(0x14)))=result.v[0];(*(float *)((char *)(entry)+(0x18)))=result.v[1];
 (*(float *)((char *)(entry)+(0x1c)))=minValue;(*(float *)((char *)(entry)+(0x20)))=fallback+lbl_8055E3C8;
 }
 }
 }
}
#pragma pop

int fn_80176030(void) { return 0; }

int fn_80176038(void) { return 0; }

void fn_80176040(char *self, int a, int b) {
    extern float fn_8001DAE8();
    extern void *fn_801B2EC0();
    extern void fn_8017B3A8(void *, float *, float *);
    extern void fn_8018F9B4(void *);
    extern float PSVECMag(float *);
    extern float lbl_80561AC0, lbl_80561A44, lbl_80561A54, lbl_80561AF0, lbl_80561AD0, lbl_80561A40, lbl_80561B10;
    Fn8017431CV3 sp20;
    float sp14[3];
    float sp8[3];
    int c;
    int n;
    char *o;
    char *ent;
    char *ent2;
    char *p;
    char *q;
    float f31;
    float f;
    float g;
    float zero;
    int k;
    int i;
    int cnt;
    Fn80176040Obj *ob;
    ob = *(Fn80176040Obj **)(self + 0x128);
    if (ob->vt->m20(ob, a) == 0) return;
    ob = *(Fn80176040Obj **)(self + 0x128);
    if (ob->vt->m20(ob, b) == 0) return;
    c = -1;
    if (fn_80171EC0(a) != 0) c = b;
    else if (fn_80171EC0(b) != 0) c = a;
    if (c == -1) return;
    if (a == c) a = b;
    n = fn_80172624((void *)a, c);
    o = *(char **)(self + 0x128);
    zero = lbl_80561AC0;
    *(float *)(o + 0x180) = zero;
    *(float *)(o + 0x190) = zero;
    if (n >= 1) {
        *(float *)(o + 0x188) = zero;
        p = (char *)fn_801B2EC0(c);
        ((Fn80176040Obj *)p)->vt->m30(p, a);
        fn_80171D94(c);
        f31 = lbl_8055E3C8;
        ent = o + c * 0x1C;
        *(unsigned char *)(ent + 0x90) = 0;
        *(float *)(ent + 0xA8) = f31;
        *(float *)(o + 0x180) = fn_8001DAE8(o + 0x17C, ent);
        ent2 = o + a * 0x1C;
        k = *(int *)(ent2 + 0x98);
        *(unsigned char *)(ent2 + k + 0xA0) = (n == 2);
        *(int *)(ent2 + 0x98) = k + 1;
        if (n == 2) *(int *)(ent2 + 0x9C) = *(int *)(ent2 + 0x9C) + 1;
        cnt = 0;
        q = o;
        for (i = 0; i < *(int *)(o + 0x170); i++) {
            if (*(unsigned char *)(q + 0x91) == 0 && *(unsigned char *)(q + 0x90) != 0) cnt++;
            q += 0x1C;
        }
        if (cnt == 0) {
            f = lbl_80561A44;
            g = *(float *)(o + 0x19C) - f31;
            if (!(f > g)) f = g;
            f = lbl_80561A54 + f;
            if (f < lbl_80561A44) g = f - lbl_80561A54;
            else g = lbl_80561A54 + f;
            *(int *)(o + a * 0x1C + 0x94) = (int)g;
        }
        if (n == 2) {
            *(float *)(o + 0x190) = fn_8001DAE8(o + 0x18C);
            p = (char *)fn_8017960C(a);
            sp8[0] = *(float *)(p + 0x60) + *(float *)(p + 0x54) * lbl_80561AF0;
            sp8[1] = *(float *)(p + 0x64) + *(float *)(p + 0x58) * lbl_80561AF0;
            sp8[2] = *(float *)(p + 0x68) + *(float *)(p + 0x5C) * lbl_80561AF0;
            q = (char *)fn_8017960C(c);
            sp14[0] = sp8[0] - *(float *)(q + 0x60);
            sp14[1] = sp8[1] - *(float *)(q + 0x64);
            sp14[2] = sp8[2] - *(float *)(q + 0x68);
            f = PSVECMag(sp14);
            if (lbl_80561AD0 > f) f = lbl_80561AD0;
            f = lbl_80561A40 / f;
            sp14[0] = sp14[0] * f;
            sp14[1] = sp14[1] * f;
            sp14[2] = sp14[2] * f;
            f = (lbl_80561A78 * *(float *)(q + 0xD4)) / lbl_80561B10;
            sp14[0] = sp14[0] * f;
            sp14[1] = sp14[1] * f;
            sp14[2] = sp14[2] * f;
            sp14[1] = (lbl_80561B0C * *(float *)(q + 0xD4)) / lbl_80561B10;
            sp20 = *(Fn8017431CV3 *)(q + 0x60);
            sp20.a[1] = sp20.a[1] + lbl_80561A54;
            fn_8017B3A8(q, sp14, sp20.a);
            fn_8018F9B4(q);
        }
    } else {
        f = fn_8001DAE8(o + 0x184) - *(float *)(o + 0x188);
        i = 0;
        if (f >= lbl_80561A44 && f < *(float *)(o + 0x184)) i = 1;
        if (i == 0) *(float *)(o + 0x188) = fn_8001DAE8(o + 0x184);
    }
}

void fn_80176400(void) {
}
