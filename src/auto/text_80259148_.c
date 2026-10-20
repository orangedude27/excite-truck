// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_80258354(void);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80345158;
extern float lbl_80563AE0;
extern float lbl_80563B14;
extern double fn_8002F234(double);
extern float PSVECDotProduct();
void fn_80259148(void) {
    int *base = lbl_80344DE0;
    void *obj = fn_80258354();
    void **vtable;
    lbl_8055F394 = obj;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, base, (char *)base + 0x10, 0);
    obj = lbl_8055F394;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, (char *)base + 0x20, (char *)base + 0x30, 0);
    obj = lbl_8055F394;
    vtable = *(void ***)obj;
    ((void (*)(void *, void *, void *, int))vtable[5])(obj, (char *)base + 0x40, (char *)base + 0x50, 1);
}

#pragma push
#pragma cplusplus on
extern "C" void fn_802591D8(void) {
    class Obj {
    public:
        virtual void destroy(int);
    };
    if (lbl_8055F394 != 0) {
        ((Obj*)lbl_8055F394)->destroy(1);
    }
    lbl_8055F394 = 0;
}
#pragma cplusplus reset
#pragma pop
struct Loc_8025AA90 {
    float v8[3];
    float v14[3];
    float v20[3];
    float v2C[3];
    float v38[3];
    float v44[3];
    float v50[3];
    float rot[9];
    unsigned char info[0x60];
};

int fn_8025921C(void) { return 0; }

void *fn_80259680(void *arg0, int arg1) {
    int value;
    if (arg0 != 0) {
        value = *(int *)((char *)arg0 + 0x50);
        *(void **)arg0 = &lbl_80345158;
        if (value != -1) {
            fn_802C6CF8(value);
            *(int *)((char *)arg0 + 0x50) = -1;
        }
        fn_802CAC54(*(int *)((char *)arg0 + 0xA8));
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int fn_80259700(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

extern float lbl_80563AE4;
extern float lbl_8055F3A4;
extern signed char lbl_8055F3A0;
extern int fn_80236914(void);
void fn_80259740(int arg0, float farg0) {
    fn_80236914();
    lbl_8055F3A4 = farg0;
    lbl_8055F3A0 = (arg0 - 2) == 0;
}

int fn_8025A1C4(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

int fn_8025A4CC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0)
        fn_80128668((void *)arg0);
    return arg0;
}

void fn_8025A83C(void *arg0) {
    float a = lbl_80563AE4;
    float b = lbl_80563AE0;
    float *p = (float *)((char *)arg0 + 0x84);
    p[1] = a;
    p[0] = b;
    p[2] = a;
    p[3] = a;
    p[4] = b;
    p[5] = a;
    p[6] = a;
    p[7] = a;
    p[8] = b;
    ((void (*)(void *, void *))(*(void ***)arg0)[3])(arg0, (char *)arg0 + 4);
}

void fn_8025A87C(void *arg0) {
    float a = lbl_80563AE4;
    char zero = 0;
    float b = lbl_80563AE0;
    float *p = (float *)((char *)arg0 + 0x84);
    p[1] = a;
    p[0] = b;
    p[2] = a;
    p[3] = a;
    p[4] = b;
    p[5] = a;
    p[6] = a;
    p[7] = a;
    p[8] = b;
    ((char *)arg0)[4] = zero;
    ((char *)arg0)[0x36] = zero;
}

extern int fn_801298E8(void *, int);
extern void fn_8001BA68();
extern void fn_8025AD88(void);
extern void fn_80144DAC(void *, void *);
extern float fn_80144CC8(float);
extern float fn_801429D0(float, float);
extern void fn_8025AD8C(void *, float *, float *, float *, float);
extern float fn_8025ADF4(float);
extern void GXInitLightAttnA_801BFEBC(void *, float, float, float);
extern float fn_8017F70C(float);
extern void fn_801F3198(void *);
extern void GXInitLightAttnA_80144B44(void *, float, float, float);
extern void fn_801C0E4C(void *, void *, void *);
extern float fn_8014C8B4(float, float, float, float, float);
extern void fn_8025AD3C(float *, float *, float *, float);
extern void fn_80015EB0(void *, float);
extern void fn_80015B20(void *, void *, void *);
extern void *fn_802C86DC(void);
extern float lbl_8055F398;
extern float lbl_80563AEC, lbl_80563B08, lbl_80563B0C, lbl_80563B10;
extern float lbl_80498EAC[3];
#pragma push
#pragma processor 750
void fn_8025AA90(void *arg0, float farg0) {
    unsigned char info[0x60];
    float rot[9];
    float v50[3];
    float v44[3];
    float v38[3];
    float v2C[3];
    float v20[3];
    float v14[3];
    float v8[3];
    unsigned int flags40, flags50;
    float color0, color1, sum, d1;
    if (*(int *)((char *)arg0 + 0x50) != -1) {
        if (((unsigned char *)arg0)[0x4A] != 0) {
            if (fn_801298E8(info, 0) != 0) {
                flags40 = *(int *)(info + 0x40);
                color0 = (flags40 & 2) ? lbl_80563AE0 : lbl_80563AE4;
                color1 = (flags40 & 8) ? lbl_80563AEC : lbl_80563AE4;
                sum = color1 + color0;
                lbl_8055F398 += farg0 * (lbl_80563B08 * sum);
                fn_8001BA68(v8);
                flags50 = *(int *)(info + 0x50);
                if (flags50 & 0x20) {
                    fn_80144DAC(v8, (float *)(info + 0x54));
                } else {
                    GXInitLightAttnA_801BFEBC(v8,
                        *(float *)(info + 0),
                        -fn_8025ADF4(fn_801429D0(lbl_80563AE4,
                            (lbl_80563AE0 - fn_80144CC8(*(float *)(info + 0))) + fn_80144CC8(*(float *)(info + 4)))),
                        *(float *)(info + 4));
                }
                fn_8025AD8C((char *)arg0 + 0x84, lbl_80498EAC, lbl_80498EAC, v8, farg0);
                GXInitLightAttnA_801BFEBC((char *)arg0 + 0x90, lbl_80498EAC[0], -lbl_80498EAC[1], lbl_80498EAC[2]);
                fn_801F3198((char *)arg0 + 0x90);
            }
            GXInitLightAttnA_80144B44(v14, lbl_80563AE0, lbl_80563AE4, lbl_80563AE4);
            GXInitLightAttnA_80144B44(v20, lbl_80563AE4, lbl_80563AE4, lbl_80563AE0);
            d1 = fn_8017F70C(((float (*)(void *, void *))fn_8025AD88)(v14, (char *)arg0 + 0x90));
            fn_8017F70C(((float (*)(void *, void *))fn_8025AD88)((char *)arg0 + 0x90, v20));
            if (d1 > lbl_80563B0C) {
                fn_8001BA68(v2C);
                fn_8001BA68(v38);
                fn_8001BA68(v44);
                fn_801C0E4C(v44, v14, (char *)arg0 + 0x90);
                fn_801C0E4C(v2C, (char *)arg0 + 0x90, v44);
                fn_801C0E4C(v38, (char *)arg0 + 0x90, v20);
                d1 = fn_8014C8B4(lbl_80563B0C, lbl_80563B10, lbl_80563AE4, lbl_80563AE0, d1);
                fn_8025AD3C(v50, v2C, v38, d1);
                fn_801C0E4C((char *)arg0 + 0x9C, v50, (char *)arg0 + 0x90);
                fn_801F3198((char *)arg0 + 0x9C);
                fn_801C0E4C((char *)arg0 + 0x84, (char *)arg0 + 0x90, (char *)arg0 + 0x9C);
            } else {
                fn_801C0E4C((char *)arg0 + 0x9C, v14, (char *)arg0 + 0x90);
                fn_801F3198((char *)arg0 + 0x9C);
                fn_801C0E4C((char *)arg0 + 0x84, (char *)arg0 + 0x90, (char *)arg0 + 0x9C);
            }
            fn_80015EB0(rot, lbl_8055F398);
            fn_80015B20((char *)arg0 + 0x84, rot, (char *)arg0 + 0x84);
            fn_80015B20((char *)arg0 + 0x84, (char *)arg0 + 0x84, fn_802C86DC());
        }
    }
}
#pragma pop
void fn_8025AD3C(float *out, float *a, float *b, float t) {
    float dz = b[2] - a[2];
    float dy = b[1] - a[1];
    float dx = b[0] - a[0];
    float rz = a[2] + t * dz;
    float ry = a[1] + t * dy;
    float rx = a[0] + t * dx;
    out[2] = rz;
    out[1] = ry;
    out[0] = rx;
}

void fn_8025AD88(void) { PSVECDotProduct(); }

void fn_8025AD8C(void *unused, float *out, float *a, float *b, float t) {
 float scale=lbl_80563B14*t;
 float max=lbl_80563AE0;
 float dx,dy,dz,x,y,z;
 if (max < scale) max=scale;
 dx=b[0]-a[0]; dy=b[1]-a[1]; dz=b[2]-a[2];
 x=a[0]+max*dx; y=a[1]+max*dy; z=a[2]+max*dz;
 out[0]=x; out[1]=y; out[2]=z;
}

float fn_8025ADF4(float arg0) { return (float)fn_8002F234(arg0); }

extern double sin(double);
typedef unsigned int u32;
typedef float f32;
extern f32 lbl_80563B1C;
f32 fn_8025B0A8(void *arg0) {
    f32 *p = (f32 *)arg0;
    f32 d = p[1] - p[0];
    f32 out = p[0];
    out += d * lbl_80563B1C;
    return out;
}

f32 fn_8025B0C4(f32 arg0) {
    return (f32)sin(arg0);
}

void fn_8025B0E8(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_8025B134(void) {
}

extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
void fn_8025B22C(void *arg0) {
    int i;
    for (i = 1; i <= 5; i++) {
        if (*(int *)((char *)arg0 + 0x74) == i)
            fn_80214AF0(i + 5);
        else
            fn_80214A9C(i + 5);
        if (i <= *(int *)((char *)arg0 + 0x1C)) {
            fn_80214AF0(i);
            fn_80214A9C(i + 10);
        } else {
            fn_80214AF0(i + 10);
            fn_80214A9C(i);
        }
    }
}

void fn_8025B784(void) {
}

extern unsigned char *fn_8001EFAC(int, int);
extern int fn_801345D8(char *, int, const char *, int);
extern const char lbl_80344F08[];
void fn_8025BE0C(void *arg0) {
    void *arg1;
    int size;
    void *obj;
    unsigned char *src;
    unsigned char *dst;
    int count;
    arg1 = arg0;
    size = *(int *)((char *)arg0 + 0x24);
    obj = *(void **)((char *)arg1 + 0x18);
    *(int *)((char *)obj + 0x4C) = size;
    src = fn_8001EFAC(*(int *)((char *)arg0 + 0x20), size);
    if (src != 0) {
        dst = (unsigned char *)obj + 4;
        count = 0x32;
        do { count--; } while (count > 0);
        dst[-1] = 0;
        do {
            unsigned char c = *src++;
            *dst++ = c;
            if ((signed char)c == 0) break;
        } while (1);
    } else *((unsigned char *)obj + 4) = 0;
    if (size > 0)
        fn_801345D8((char *)obj + 0x36, 0x14, lbl_80344F08, size);
    else *((unsigned char *)obj + 0x36) = 0;
}

void fn_8025BED0(void *arg0) {
    void *data = *(void **)((char *)arg0 + 0x1C);
    void *obj;
    int size;
    unsigned char *src;
    unsigned char *dst;
    int count;
    if (*(unsigned char *)((char *)data + 0xC5) == 0) return;
    if (*(unsigned char *)((char *)data + 0x58) != 0) return;
    size = *(int *)((char *)data + 0xC8);
    obj = *(void **)((char *)arg0 + 0x18);
    *(int *)((char *)arg0 + 0x24) = size;
    *(int *)((char *)data + 0x18);
    *(int *)((char *)arg0 + 0x20) = *(int *)((char *)data + 0x18);
    *(int *)((char *)obj + 0x4C) = size;
    src = fn_8001EFAC(*(int *)((char *)arg0 + 0x20), size);
    if (src != 0) {
        dst = (unsigned char *)obj + 4;
        count = 0x32;
        while (--count > 0) {}
        dst[-1] = 0;
        do {
            unsigned char c = *src++;
            *dst++ = c;
            if ((signed char)c == 0) break;
        } while (1);
    } else {
        *((unsigned char *)obj + 4) = 0;
    }
    if (size > 0)
        fn_801345D8((char *)obj + 0x36, 0x14, lbl_80344F08, size);
    else
        *((unsigned char *)obj + 0x36) = 0;
    obj = *(void **)((char *)arg0 + 0x18);
    *(unsigned char *)((char *)obj + 0x4A) = 1;
}

extern void *fn_80258354(void);
extern int fn_802C6CF8(int);
extern int fn_802CAC54(int);
extern int fn_80128668(void *);
extern int lbl_80344DE0[];
extern void *lbl_8055F394;
extern int lbl_80345158;
extern float lbl_80563AE4;
extern float lbl_8055F3A4;
extern signed char lbl_8055F3A0;
extern int fn_80236914(void);
