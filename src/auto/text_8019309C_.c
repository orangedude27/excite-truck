// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

                      extern void fn_801958D8(void);
extern void fn_8018A174(void *);
extern void fn_801961F8(void);
extern void fn_80195B28(void *, float);
extern void fn_8019416C(void);
extern void fn_801945F8(void *);
extern void fn_80196DC4(void *);
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern void fn_80195654(void *, void *);
extern void fn_801933FC(void *, void *);
    extern double fn_8002F234(float);
    extern float lbl_8055E584, lbl_8055E588;
    extern float fn_80129DC4(int, float, float);
    extern void fn_8013530C(void *, int);
    extern int lbl_8055E550;
    extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204, lbl_805621E4;

      extern void fn_80194FD0(unsigned char *, float *, float);
typedef struct { void *a; float b; int c; } Samp80194FD0;
extern void *fn_8017960C();
extern int fn_80137788(void *, int, float *);
extern float lbl_805621C0, lbl_805621F0, lbl_805621F4, lbl_805621F8, lbl_805621FC, lbl_80562200, lbl_80562160, lbl_8056216C;
extern unsigned int lbl_8055D430;
extern int lbl_8055E0D0;
typedef float (*Fn931AC)(void *, void *, void *, float, float, float, float);
typedef float (*Fn948B0)(void *, int, float);
typedef float (*Fn94FC8)(void *);
extern void fn_80135B9C(void *, void *, void *, void *, void *, float);
#define F80194FD0(p, o) (*(float *)((unsigned char *)(p) + (o)))
#define P80194FD0(p, o) (*(void **)((unsigned char *)(p) + (o)))
#pragma cplusplus on
class Vt_80194C4C {
public:
    virtual void *v0();
    virtual void *v1();
    virtual void *v2();
    virtual void *v3();
    virtual void *v4();
    virtual void *v5();
    virtual void *v6();
    virtual void *v7();
    virtual void *v8();
};
class Vt_80194C4CController {
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
    virtual void v9(float *, float *, int *);
    virtual void v10();
    virtual void v11();
};
class Vt_80194324 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(void *);
};
#pragma cplusplus reset
typedef unsigned char u8;
extern void *lbl_804349C0[];
extern float lbl_8056223C, lbl_8055E57C;
extern int lbl_804348E8[];
extern void *lbl_804349E0[];
extern char lbl_80333390[0x10000];
  void fn_801964D0(void *);
  void fn_80128668(void *);
  void fn_80193138(int);
  void fn_80193CE0(void *);

#pragma cplusplus on
class DummyVt_80193CE0 {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
};
#pragma cplusplus reset
  
  extern unsigned char lbl_8055A4B8[8];
extern float lbl_80562178, lbl_8056217C, lbl_8055E558;
extern float lbl_80562264, lbl_8056224C;
extern void fn_8017B4E0(void *, float *, float *, float);
extern void fn_80193D30(void *);
extern int fn_802E30C8(const char *, ...);
extern char lbl_80333198[];

extern char lbl_80333158[];
extern float lbl_8055A488, lbl_8055A48C;
extern unsigned char lbl_8055E580;
extern unsigned int lbl_8055E540;
extern float lbl_8055E554, lbl_8055E56C, lbl_8055E568, lbl_8055E564;
extern float lbl_8055E544, lbl_8055E548, lbl_8055E54C, lbl_8055E55C;
extern float lbl_8055E560, lbl_8055E570;
extern int lbl_8055E578;
extern float lbl_80562184, lbl_80562188, lbl_8056218C, lbl_80562190;
extern float lbl_80562194, lbl_80562198, lbl_8056219C;
extern void *__AXFXGetLfoSinTable_801769CC(void);
extern void *fn_80137C54(int);
extern void fn_80134CD4(int, void *);
extern float fn_80134B58(void *, float);

#define __HI(x) *(int *)&x
extern float lbl_80562168, lbl_80562174, lbl_805621A4, lbl_805621B0, lbl_805621B4;
extern float lbl_80333308[];
extern float lbl_8056220C;
extern float lbl_8055A488, lbl_8056215C;

int fn_8019309C(void *arg0, int index, signed char arg2) {
    void *entry = lbl_804349C0[index];
    int result = 0;
    if (entry != 0 && *((u8 *)entry + 0x2A4) != 0) {
        result = 1;
        *((u8 *)entry + 0x2FC) = *((unsigned int *)((char *)arg0 + 0x290));
        *((u8 *)arg0 + 0x2FD) = arg2;
    }
    return result;
}

u8 fn_801930DC(void *unused, int index) {
    void *entry;
    entry = lbl_804349C0[index];
    if (entry != 0 && *((u8 *)entry + 0x2A4) != 0)
        return *((u8 *)entry + 0x2FD);
    return 0;
}

int fn_80193110(void *arg0, int arg1) {
    u8 value = arg1;
    if (*((u8 *)arg0 + 0x2FC) == value) {
        *((u8 *)arg0 + 0x2FC) = 0xFF;
        return 1;
    }
    return 0;
}

void fn_80193138(int index) {
    void *entry;
    entry = lbl_804349C0[index];
    if (entry) *((u8 *)entry + 0x304) = 0x14;
}

#pragma dont_inline on
void fn_8019315C(void *unused, int index) {
      void *entry = lbl_804349C0[index];
      if (entry) ++*(int *)((char *)entry + 0x300);
  }
#pragma dont_inline reset

#pragma dont_inline on


u8 fn_80193184(void *unused, int index) {
      void *entry;
      entry = lbl_804349C0[index];
      if (entry != 0) return *((u8 *)entry + 0x2FE);
      return 0;
  }
#pragma dont_inline reset

float fn_801931AC(float a, float b, float c, float d) {
    float quotient = a / d;
    float value = lbl_80562140 - quotient;
    if (value < lbl_80562140)
        value = lbl_80562140;
    if (value > lbl_80562144)
        value = lbl_80562144;
    return b + value * (c - b);
}

float fn_801931EC(float a, float b) {
    float value;
    float floor;
    value = lbl_80562140;
    floor = lbl_8055E558;
    if (value < value - a / b) {
        value = value - a / b;
    }
    if (value > floor) return value;
    return floor;
}

#pragma processor 750
void fn_8019321C(void *arg0, void *arg1, void *arg2) {
    float stack[10];
    float x = *(float *)((char *)arg2 + 0x18);
    float y = *(float *)((char *)arg2 + 0x20);
    float magnitude = x * x + y * y;
    float length;
    float scale;
    float dx;
    float dy;
    double neg;
    float c;
    float d;
    float term0;
    float term1;
    float term2;
    float term3;
    float ox;
    float oy;
    stack[2] = x;
    stack[3] = y;
    length = (float)fn_8002F234(magnitude);
    if (lbl_80562148 > length)
        length = lbl_80562148;
    scale = lbl_80562140 / length;
    dx = stack[2] * scale;
    dy = stack[3] * scale;
    stack[6] = *(float *)((char *)arg2 + 0x24);
    c = *(float *)arg1;
    d = *(float *)((char *)arg1 + 4);
    stack[7] = *(float *)((char *)arg2 + 0x2C);
    neg = -(double)dx;
    stack[2] = dx;
    stack[3] = dy;
    stack[4] = dy;
    stack[5] = (float)neg;
    term0 = dy * c;
    term1 = dx * d;
    term2 = (float)neg * c;
    term3 = dy * d;
    ox = term0 + term1;
    oy = term2 + term3;
    ox += stack[6];
    oy += stack[7];
    *(float *)arg0 = ox;
    *(float *)((char *)arg0 + 4) = oy;
}
#pragma processor reset
extern float lbl_80562140, lbl_80562148;
#pragma dont_inline on
void fn_8019330C(void *out, void *in, int arg2) {
    volatile float work[8];
    float x = *(float *)((char *)arg2 + 0x18);
    float y = *(float *)((char *)arg2 + 0x20);
    float sq = y * y + x * x;
    float length;
    float denom;
    float scale;
    float sx, sy, dx, dy;
    work[2] = x;
    work[3] = y;
    length = (float)fn_8002F234(sq);
    denom = lbl_80562148;
    if (denom <= length)
        denom = length;
    scale = lbl_80562140 / denom;
    sy = work[3] * scale;
    sx = work[2] * scale;
    work[6] = *(float *)((char *)arg2 + 0x24);
    work[7] = *(float *)((char *)arg2 + 0x2C);
    dx = *(float *)in - work[6];
    dy = *(float *)((char *)in + 4) - work[7];
    work[0] = dx;
    work[1] = dy;
    work[2] = sx;
    work[3] = sy;
    work[4] = sy;
    work[5] = -sx;
    *(float *)((char *)out + 4) = dx * sx + dy * sy;
    *(float *)out = dx * sy + dy * -sx;
}
#pragma dont_inline reset

#pragma scheduling off
void fn_801933FC(void *arg0, void *arg1) {
    fn_8019330C(arg1, arg1, (arg0 = *(void **)((char *)arg0 + 0x294), (int)((char *)arg0 + 0x70)));
}
#pragma scheduling reset
int fn_80193524(void *arg0, void *arg1) {
    extern float PSVECDotProduct(const void *, const void *);
    extern float lbl_8056215C;
    float delta[3];
    float dot = __fabs(PSVECDotProduct((char *)arg0 + 0x54, (char *)arg1 + 0x54));
    int result = 0;

    if (dot < lbl_8056215C) {
        delta[0] = *(float *)((char *)arg1 + 0x60) - *(float *)((char *)arg0 + 0x60);
        delta[1] = *(float *)((char *)arg1 + 0x64) - *(float *)((char *)arg0 + 0x64);
        delta[2] = *(float *)((char *)arg1 + 0x68) - *(float *)((char *)arg0 + 0x68);
        dot = PSVECDotProduct(delta, (char *)arg0 + 0x54);
        result = dot > -PSVECDotProduct(delta, (char *)arg1 + 0x54);
    }
    return result;
}
#pragma processor gekko
void fn_801935EC(void *arg0) {
    float value = lbl_80562144;
    *(float *)((unsigned char *)arg0 + 0x224) = value;
    *(float *)((unsigned char *)arg0 + 0x228) = value;
    *(float *)((unsigned char *)arg0 + 0x22C) = lbl_8055E3C8;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_80193604(void *arg0, void *arg1, void *unused, int arg2, void *arg3) {
    extern float PSVECDotProduct(const void *, const void *);
    extern float PSVECMag(const void *);
    extern float lbl_80562140, lbl_80562144, lbl_80562148, lbl_8056215C;
    extern float lbl_80562160, lbl_80562164, lbl_80562168, lbl_8056216C;
    extern float lbl_80562170, lbl_80562174;
    struct Vec { float x, y, z; };
    char *other = (char *)arg3, *obj = (char *)arg0;
    int code = arg2;
    float value, scale, delta[3];
    struct Vec normal;
    if (other != 0) {
        if (*(unsigned int *)(other + 0x10) == 0x50434152) {
            char *vehicle = *(char **)(obj + 0x294);
            delta[0] = *(float *)(other + 0x60) - *(float *)(vehicle + 0x60);
            delta[1] = *(float *)(other + 0x64) - *(float *)(vehicle + 0x64);
            delta[2] = *(float *)(other + 0x68) - *(float *)(vehicle + 0x68);
            if (PSVECDotProduct(delta, *(char **)(obj + 0x294) + 0x54) > lbl_80562144) {
                value = PSVECDotProduct(other + 0x118, other + 0x54);
                if (value > lbl_80562160 && (float)__fabs(PSVECDotProduct(other + 0x118, other + 0x3C) / value) > lbl_80562164)
                    *(float *)(obj + 0x2A8) += lbl_80562168;
            }
        }
        if ((*(unsigned int *)(other + 0x10) == 0x41434152 || *(unsigned int *)(other + 0x10) == 0x50434152) &&
            fn_80193524(*(void **)(obj + 0x294), other))
            *(float *)(obj + 0x2A8) += lbl_80562168;
    }
    if (code < 0x3E8 && PSVECDotProduct(arg1, *(char **)(obj + 0x294) + 0x88) < lbl_80562144) {
        { unsigned int y = ((unsigned int *)arg1)[1], x = ((unsigned int *)arg1)[0], z = ((unsigned int *)arg1)[2];
          ((unsigned int *)&normal)[0] = x; ((unsigned int *)&normal)[1] = y; ((unsigned int *)&normal)[2] = z; }
        value = PSVECMag(&normal);
        scale = lbl_80562148 > value ? lbl_80562148 : value;
        scale = lbl_80562140 / scale;
        normal.x *= scale; normal.y *= scale; normal.z *= scale;
        if ((float)__fabs(PSVECDotProduct(&normal, *(char **)(obj + 0x294) + 0x88)) > lbl_8056215C) {
            value = *(float *)(obj + 0x270);
            if (value < lbl_8056216C && (code != 0x6D || value < lbl_80562170) &&
                (*(int *)(obj + 0x268) != 1 || code != 0x6D))
                *(float *)(obj + 0x2A0) += lbl_80562174;
        }
    }
    if (code == 0x3EA) *(float *)(obj + 0x2A0) += lbl_80562174;
    if (code == 0x6D) *(u8 *)(obj + 0x2FE) = 0;
}
#pragma pop
void fn_8019386C(void *arg0) {
    fn_80193CE0(arg0);
}

void fn_80193870(void *arg0) {
    ((void (*)(void *, void *))fn_801945F8)(arg0, lbl_8055A4B8);
}

void fn_80193878(void *arg0) {
    float a[3], b[3], low[3];
    void *obj;
    low[0] = lbl_8056217C;
    low[1] = lbl_80562144;
    low[2] = lbl_80562144;
    a[0] = lbl_80562144;
    a[1] = lbl_80562144;
    a[2] = lbl_80562178;
    obj = *(void **)((unsigned char *)arg0 + 0x294);
    b[0] = *(float *)((unsigned char *)obj + 0x94) + low[0];
    b[1] = *(float *)((unsigned char *)obj + 0x98) + a[0];
    b[2] = *(float *)((unsigned char *)obj + 0x9C) + a[0];
    fn_8017B4E0(*(void **)((unsigned char *)arg0 + 0x294), a, b, lbl_80562140);
}

extern void fn_801352B8(void *);
extern float lbl_80562144, lbl_80562180;
extern const char lbl_80333348[];
void *fn_801938F4(void *arg0) {
    int minusOne = -1;
    int zero = 0;
    int limit = 0x2710;
    float initial = lbl_80562144;
    char *obj = (char *)arg0 + 0x168;
    *(int *)((char *)arg0 + 0x68) = zero;
    *(const char **)arg0 = lbl_80333348;
    *(int *)((char *)arg0 + 0x70) = limit;
    *(float *)((char *)arg0 + 0x6C) = initial;
    *(int *)((char *)arg0 + 0x78) = zero;
    *(int *)((char *)arg0 + 0x90) = minusOne;
    *((char *)arg0 + 0x8C) = zero;
    *(int *)((char *)arg0 + 0xA0) = zero;
    *(int *)((char *)arg0 + 0xB8) = minusOne;
    *((char *)arg0 + 0xB4) = zero;
    fn_801352B8(obj);
    fn_801352B8(obj + 0x34);
    *(float *)(obj + 0x68) = lbl_80562180;
    (*(void (**)(void *, int))(*(char **)(obj + 0x34) + 0xC))(obj + 0x34, 0);
    (*(void (**)(void *, int))(*(char **)obj + 0xC))(obj, 0);
    *(int *)((char *)arg0 + 0x294) = zero;
    *(int *)((char *)arg0 + 0x290) = -1000;
    return arg0;
}

extern void fn_801945F8(void *);
extern float lbl_80562140, lbl_80562144, lbl_80562178, lbl_8056217C;
extern void fn_8017B4E0(void *, float *, float *, float);
extern void fn_80193D30(void *);
extern void fn_801942F0(void *, int);
extern int fn_802E30C8(const char *, ...);
extern char lbl_80333198[];
void fn_801939C8(void *arg0) {
    void *obj;
    if (*(unsigned char *)((unsigned char *)arg0 + 0x2A4)) {
        fn_802E30C8(lbl_80333198, *(int *)((unsigned char *)arg0 + 0x290));
    } else {
        obj = *(void **)((unsigned char *)arg0 + 0x294);
        *(unsigned char *)((unsigned char *)arg0 + 0x2A4) = 1;
        *(float *)((unsigned char *)arg0 + 0x24C) = *(float *)((unsigned char *)obj + 0x5B0);
        fn_801942F0(arg0, 1);
        fn_80193D30(arg0);
    }
}

void fn_80193A38(void *arg0) {
    void *obj = *(void **)((unsigned char *)arg0 + 0x294);
    *(unsigned char *)((unsigned char *)arg0 + 0x2A4) = 0;
    *(int *)((unsigned char *)obj + 0x24) = *(int *)((unsigned char *)obj + 0x28);
}

void *fn_80193A50(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 0x290);
        if (temp_r0 != -1000) {
            ((int *)lbl_804349C0)[temp_r0] = 0;
        }
        lbl_8055E550 -= 1;
        if ((char *)arg0 + 0x168 != 0) {
            fn_8013530C((char *)arg0 + 0x19C, -1);
            fn_8013530C((char *)arg0 + 0x168, -1);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma cplusplus on
class DummyClass_80193AEC {
public:
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void *vfunc4();
    virtual void *vfunc5();
    virtual void *vfunc6();
};
#pragma cplusplus reset

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_80193AEC(void *arg0, void *arg1) {
    char *table = lbl_80333158;
    int zero = 0;
    int id;
    DummyClass_80193AEC *obj;

    *(void **)((char *)arg0 + 0x294) = arg1;
    *(int *)((char *)arg0 + 0x214) = 2;
    *(unsigned char *)((char *)arg0 + 0x2A4) = zero;
    id = *(int *)((char *)arg1 + 0x1EC);
    *(int *)((char *)arg0 + 0x290) = id;
    fn_80134CD4(id, (char *)arg0 + 0x2AC);

    *(void **)((char *)arg0 + 0x298) = (char *)*(void **)((char *)arg0 + 0x294) + 0x23AC;
    lbl_804349C0[*(int *)((char *)arg0 + 0x290)] = arg0;
    obj = *(DummyClass_80193AEC **)((char *)*(void **)((char *)arg0 + 0x294) + 0x270);
    *(DummyClass_80193AEC **)((char *)arg0 + 0x28C) = obj;
    *(void **)((char *)arg0 + 0x164) = obj->vfunc4();

    if (lbl_8055E550++ == 0) {
        lbl_8055A488 = *(float *)fn_80137C54(-1);
        lbl_8055A48C = *(float *)((char *)fn_80137C54(-1) + 4);
        lbl_8055E580 = 1;
        lbl_8055E540 = ((int *)__AXFXGetLfoSinTable_801769CC())[1] != 0x180304;
        lbl_8055E554 = *(float *)((char *)*(void **)((char *)*(void **)((char *)arg0 + 0x164) + 0x2C) + 8);
        lbl_8055E56C = fn_80134B58(table + 0x70, lbl_80562140);
        lbl_8055E568 = fn_80134B58(table + 0x80, lbl_80562140);
        lbl_8055E564 = fn_80134B58(table + 0x94, lbl_80562140);
        lbl_8055E558 = fn_80134B58(table + 0xA4, lbl_8056215C);
        fn_80134B58(table + 0xB4, lbl_80562140);
        lbl_8055E544 = lbl_80562140;
        lbl_8055E548 = fn_80134B58(table + 0xC4, lbl_80562184);
        lbl_8055E54C = fn_80134B58(table + 0xD4, lbl_80562188);
        lbl_8055E55C = fn_80134B58(table + 0xE4, lbl_8056218C);
        lbl_8055E560 = fn_80134B58(table + 0xF0, lbl_80562190);
        lbl_8055E570 = fn_80134B58(table + 0xFC, lbl_80562194);
        lbl_8055E584 = fn_80134B58(table + 0x10C, lbl_80562198);
        lbl_8055E588 = fn_80134B58(table + 0x11C, lbl_8056219C);
        lbl_8055E578 = zero;
    }
    fn_80193D30(arg0);
}
#pragma scheduling reset
#pragma cplusplus reset
void fn_80193CD4(void *arg0) {
    *(signed char *)((char *)arg0 + 0x2A5) = 1;
}

#pragma cplusplus on
extern "C" void fn_80193CE0(void *arg0) {
    ((DummyVt_80193CE0 *)arg0)->d10();
    *(u8 *)((char *)arg0 + 0x2A5) = 0;
}
#pragma cplusplus reset

void fn_80193D20(void) {
    fn_80129DC4(3, lbl_8055E584, lbl_8055E588);
}

extern void *memset(void *, int, unsigned int);
extern int fn_801769B8(void);
extern void fn_8013B6A4();
extern int fn_8013B578(int);
extern int fn_801667F0(void);
extern int fn_801B8570(int);
extern float fn_801B306C(void);
extern void fn_801B30D0(int);
extern void fn_801B30E0(int);
extern void fn_80195D80(void *, float);
extern float lbl_8055E3C8, lbl_80562140, lbl_80562144, lbl_8056215C, lbl_80562160, lbl_80562180;
extern float lbl_805621A0, lbl_805621A4, lbl_805621A8, lbl_805621AC;
extern int lbl_8055E3C4;
extern unsigned char lbl_8055E574;
extern float lbl_8055E57C;
extern char lbl_80333284[], lbl_80333294[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma cplusplus off
extern int fn_801769A8(void);
void fn_80193D30(void *arg0) {
    char *p = (char *)arg0;
    int temp2;
    int flag = 0;
    int temp;
    float limit;

    lbl_8055E57C = lbl_80562144;
    limit = lbl_8055E3C8;
    lbl_8055E574 = fn_801769B8() == 2;

    memset(p + 8, 0, 0x10);
    memset(p + 0x20, 0, 0x54);
    memset(p + 0x74, 0, 0x78);
    memset(p + 0xEC, 0, 0x30);
    memset(p + 0x11C, 0, 0x48);
    memset(p + 0x1D4, 0, 0x34);
    memset(p + 0x21C, 0, 4);
    memset(p + 0x220, 0, 0x1C);
    memset(p + 0x23C, 0, 0xC);
    memset(p + 0x2D4, 0, 0x28);

    {
        float zero = lbl_80562144;
        *(int *)(p + 0x260) = 0;
        *(int *)(p + 0x2C4) = -1;
        *(float *)(p + 0x2B8) = zero;
        *(float *)(p + 0x2C0) = zero;
        *(float *)(p + 0x264) = zero;
        *(int *)(p + 0x2D0) = 0;
        *(unsigned char *)(p + 0x2A7) = 0;
        memset(p + 0x218, 0, 4);
        *(int *)(p + 0x210) = 0;
    }

    {
        float unit = lbl_805621A0;
        int ident = lbl_8055E3C4;
        float factor = lbl_805621A4;
        *(int *)(p + 0x2B4) = ident;
        *(float *)(p + 0x1D4) = unit;
        *(float *)(p + 0x1F0) = unit;
        *(float *)(p + 0x1E8) = unit;
        *(float *)(p + 0x1E0) = unit;
        *(float *)(p + 0x1E4) = unit;
        *(float *)(p + 0x1EC) = factor;
        *(float *)(p + 0x1F4) = unit;
        *(float *)(p + 0x1F8) = unit;
        *(float *)(p + 0x1FC) = unit;
        *(float *)(p + 0x204) = unit;
        {
            float value = ((float (*)(float))fn_80193D20)(unit);
            float zero = lbl_80562144;
            *(float *)(p + 0x200) = value;
            *(float *)(p + 0x20C) = zero;
        }
    }

    if (fn_801769A8() & 0x800) {
        void *vehicle = *(void **)(p + 0x294);
        if (*(int *)((char *)vehicle + 0x1F0) != 0x50) {
            flag = 1;
            temp2 = 0;
            *(unsigned char *)(p + 0x2A5) = flag;
            *(unsigned char *)(p + 0x208) = temp2;
            memset(p + 0x26C, 0, 0x20);
        }
    }

    {
        void *sub = *(void **)(p + 0x28C);
        *(int *)(p + 0x288) = ((int (**)(void *))*(void **)sub)[4](sub);
    }

    {
        float zero = lbl_80562144;
        float minimum = lbl_80562140;
        float speed = lbl_80562160;
        float scale = lbl_805621A8;
        *(float *)(p + 0x25C) = zero;
        *(float *)(p + 0x144) = zero;
        *(float *)(p + 0x148) = zero;
        *(float *)(p + 0x14C) = minimum;
        *(float *)(p + 0x150) = zero;
        *(int *)(p + 0x140) = temp2;
        *(float *)(p + 0x1C) = speed;
        *(float *)(p + 0x2BC) = scale;
    }

    {
        void *vehicle = *(void **)(p + 0x294);
        void *callback = *(void **)((char *)vehicle + 0x2C0);
        if (callback != 0) {
            ((void (**)(void *, const char *))*(void **)callback)[10](callback, lbl_80333284);
            ((void (*)(int))fn_8013B6A4)(*(int *)(p + 0x290));
        }
    }

    *(int *)(p + 0x29C) = fn_8013B578(*(int *)(p + 0x290));
    if (fn_801667F0() != 0)
        fn_8013B6A4(*(int *)(p + 0x290), lbl_80562140);

    {
        float zero = lbl_80562144;
        float maximum = lbl_8056215C;
        *(float *)(p + 0x254) = zero;
        *(float *)(p + 0x258) = maximum;
        *(float *)(p + 0x2A8) = zero;
        *(float *)(p + 0x2A0) = zero;
    }
    memset(p + 0x2FC, 0, 0xC);

    *(unsigned char *)(p + 0x74) = 0;
    *(unsigned char *)(p + 0x250) = 0;
    {
        float zero = lbl_80562144;
        float unit = lbl_805621A0;
        float extra = lbl_805621AC;
        *(float *)(p + 0xE8) = zero;
        *(float *)(p + 0xE0) = zero;
        *(float *)(p + 0xF0) = zero;
        *(float *)(p + 0xF4) = zero;
        *(int *)(p + 0x118) = -1;
        *(int *)(p + 0x114) = -1;
        *(float *)(p + 0x248) = zero;
        *(float *)(p + 0x234) = unit;
        *(float *)(p + 0x22C) = unit;
        *(float *)(p + 0x224) = zero;
        *(float *)(p + 0x228) = zero;
        *(float *)(p + 0x220) = zero;
        *(float *)(p + 0x244) = zero;
        *(float *)(p + 0x240) = zero;
        *(float *)(p + 0x23C) = zero;
        *(int *)(p + 0x13C) = -1;
        *(unsigned char *)(p + 0x11C) = 0;
        *(float *)(p + 0x120) = zero;
        *(int *)(p + 0x98) = 0;
        *(float *)(p + 0x94) = unit;
        *(int *)(p + 0xC0) = 0;
        *(float *)(p + 0xBC) = extra;
        *(unsigned char *)(p + 0x9C) = 0;
        *(unsigned char *)(p + 0x74) = 0;
        *(float *)(p + 0xC4) = zero;
        *(float *)(p + 0xD0) = zero;
        *(float *)(p + 0xC8) = zero;
        *(float *)(p + 0xD4) = zero;
        *(unsigned char *)(p + 0xFC) = 0;
        *(int *)(p + 0x100) = 0;
        *(int *)((char *)*(void **)(p + 0x164) + 0xC) = 0;
    }

    if (*(int *)((char *)*(void **)(p + 0x294) + 0x1F0) == 0x50) {
        int index = *(int *)(p + 0x290);
        fn_801B30D0(index);
        temp = 0;
        if (fn_801B8570(index) == 0) {
            float threshold = lbl_8055E3C8;
            if (fn_801B306C() < threshold)
                temp = 1;
        }
        if (temp != 0) {
            fn_802E30C8(lbl_80333294);
            fn_801B30E0(index);
        }
    }

    *(float *)(p + 0x1D0) = lbl_80562180;
    {
        void *sub = p + 0x19C;
        ((void (**)(void *, int))*(void **)sub)[3](sub, 0);
    }
    {
        void *sub = p + 0x168;
        ((void (**)(void *, int))*(void **)sub)[3](sub, 0);
    }
    fn_80195D80(arg0, limit);

    *(int *)(p + 0x268) = 6;
    *(unsigned char *)(p + 0x2A6) = 0;
    *(float *)(p + 0x21C) = lbl_80562140;
    {
        float *src = (float *)*(void **)(p + 0x2C8);
        *(float *)(p + 0x2E0) = src[0x44 / 4];
        *(float *)(p + 0x2E4) = src[0x48 / 4];
        *(float *)(p + 0x2E8) = src[0x4C / 4];
        *(float *)(p + 0x2EC) = src[0x50 / 4];
        *(float *)(p + 0x2F0) = src[0x54 / 4];
        *(float *)(p + 0x2F4) = src[0x58 / 4];
        *(float *)(p + 0x2F8) = src[0x5C / 4];
    }
    *(void **)(p + 0x2D4) = p + 0x2E0;
    *(void **)(p + 0x2D8) = p + 0x2E0;
    *(float *)(p + 0x2DC) = limit;
    *(int *)(p + 4) = *(int *)(p + 0x290) * 4;
}
#pragma pop
void fn_8019416C(void) {

}

typedef unsigned int u32;
extern float lbl_80562140, lbl_80562144;
  extern void fn_8018ADB4(int, float);
  extern void fn_8018ADBC(int, float);
  extern void fn_8018ADAC(void *, float);
#pragma scheduling invalid_target
void fn_80194170(void *arg0, float arg1) {
    double value = lbl_80562140;
    value = value < arg1 ? arg1 : value;
    value = value > lbl_80562144 ? lbl_80562144 : value;
    *(float *)((char *)arg0 + 0x240) = value;
    fn_8018ADB4(*(int *)((char *)arg0 + 0x294), (float)value);
}
#pragma scheduling invalid_target
void fn_801941A8(void *arg0, float arg1) {
    union FloatWord {
        float f;
        u32 u;
    } otherBits, newBits;
    volatile float *posField = (volatile float *)((char *)arg0 + 0x23C);
    volatile float *velField = (volatile float *)((char *)arg0 + 0x248);
    float change = lbl_805621B0;
    float delta = arg1 - posField[0];
    float pos;
    float velocity;
    int adjust;
    float product;
    double finalPos;
    float callPos;

    change = change < delta ? delta : change;
    change = change > lbl_805621B4 ? lbl_805621B4 : change;
    pos = posField[0];
    velocity = velField[0];
    pos += change;
    adjust = velocity < lbl_80562174;
    posField[0] = pos;
    if (adjust) {
        void *obj = *(void **)((char *)arg0 + 0x294);
        newBits.f = pos;
        otherBits.f = *(float *)((char *)obj + 0x25F0);
        if ((int)(newBits.u & 0x80000000) != (int)(otherBits.u & 0x80000000)) {
            velocity += lbl_80562168;
            velField[0] = velocity;
        }
    }
    velocity = velField[0];
    {
        float minimum = lbl_80562140;
        minimum = minimum < velocity ? velocity : minimum;
        minimum = minimum > lbl_80562144 ? lbl_80562144 : minimum;
        product = posField[0] * (lbl_80562140 - minimum);
    }
    product = product < lbl_80562140 ? lbl_80562140 : product;
    product = product > lbl_805621A4 ? lbl_805621A4 : product;
    finalPos = product;
    callPos = (float)finalPos;
    posField[0] = finalPos;
    fn_8018ADAC(*(void **)((char *)arg0 + 0x294), callPos);
}
#pragma scheduling on
void fn_801942B8(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80562140) value = arg1;
    else value = lbl_80562140;
    if (value > lbl_80562144) value = lbl_80562144;
    *(float *)((char *)arg0 + 0x244) = value;
    fn_8018ADBC(*(int *)((char *)arg0 + 0x294), value);
}

void fn_801942F0(void *arg0, int arg1) {
    if ((*(int *)((unsigned char *)arg0 + 0x2D0) & 0x20) || arg1 != 0) {
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x267C) = 1;
    } else {
        *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x267C) = 0;
    }
}

extern int fn_801B2F24(void);
extern float lbl_80562198, lbl_805621B8, lbl_805621BC, lbl_805621C0, lbl_805621C4;
static inline float Cross2D_80194324(float ax, float ay, float bx, float by) {
    float n = -ay;
    return ax * bx + by * n;
}
#pragma cplusplus on
extern "C" int fn_800216D0(void);
extern "C" void *fn_801B83A0(void);
extern "C" void fn_80194324(void *arg0) {
    char *p = (char *)arg0;
    int flag;
    float thresh;
    float limit;
    if (fn_800216D0()) {
        *(int *)(p + 0x2D0) |= 0x10;
    }
    flag = 1;
    thresh = lbl_80562198;
    limit = lbl_805621B8;
    if (!(*(int *)(p + 0x2D0) & 0x10)) {
        flag = *(float *)(*(char **)(p + 0x294) + 0x25D4) > lbl_805621BC;
        if (flag) {
            float v;
            float t = *(float *)(p + 0x26C) - *(float *)(p + 0x1D0);
            int lt = t < lbl_805621C0;
            if (lt) {
                float k = t / lbl_805621C0;
                float a = Cross2D_80194324(*(float *)(p + 0x1B0), *(float *)(p + 0x1AC), *(float *)(p + 0x1B4), *(float *)(p + 0x1B8));
                float b = Cross2D_80194324(*(float *)(p + 0x17C), *(float *)(p + 0x178), *(float *)(p + 0x180), *(float *)(p + 0x184));
                v = b + k * (a - b);
            } else {
                v = Cross2D_80194324(*(float *)(p + 0x1B0), *(float *)(p + 0x1AC), *(float *)(p + 0x1B4), *(float *)(p + 0x1B8));
            }
            flag = (float)__fabs(v) < thresh;
        }
        if (!flag) {
            if (*(float *)(p + 0x1D8) >= limit) {
                ((Vt_80194324 *)fn_801B83A0())->v41(*(void **)(p + 0x290));
                *(float *)(p + 0x1D8) = lbl_80562144;
            }
        }
    }
    if (!flag) {
        *(float *)(p + 0x1D8) = *(float *)(p + 0x1D8) + lbl_805621C4;
    } else {
        float x = *(float *)(p + 0x1D8) - lbl_805621C4;
        *(float *)(p + 0x1D8) = (x > lbl_80562144) ? x : lbl_80562144;
    }
}
#pragma cplusplus reset
extern void fn_8018AF04(void *);
extern void fn_80193CD4(void *);
extern unsigned int lbl_8055E540;
extern float lbl_805621A4;
extern char lbl_803332CC[];
void fn_801944C0(void *arg0) {
    void *obj;
    obj = *(void **)((char *)arg0 + 0x288);
    *(u8 *)((char *)arg0 + 0x2A6) = *(u8 *)((char *)obj + 0x28);
    if (*(u8 *)((char *)arg0 + 0x2A6)) {
        if (*(float *)((char *)arg0 + 0x1EC) < lbl_80562144)
            *(float *)((char *)arg0 + 0x1EC) = *(float *)((char *)arg0 + 0x26C);
        switch (lbl_8055E540) {
        case 1:
            if ((*(int *)((char *)arg0 + 0x2D0) & 0x200) == 0)
                ((void (*)(void *, const char *))fn_801945F8)(arg0, lbl_803332CC);
            break;
        case 0:
            fn_80193CD4(arg0);
            break;
        case 2:
            fn_8018AF04(*(void **)((char *)arg0 + 0x294));
            break;
        }
        obj = *(void **)((char *)arg0 + 0x28C);
        ((void (*)(void *, int))(*(void ***)obj)[12])(obj, -1);
    } else {
        *(float *)((char *)arg0 + 0x1EC) = lbl_805621A4;
    }
}

void fn_80194590(void *arg0) {
    int var_r4;
    float product;
    if (*(int *)((char *)arg0 + 0x260) == 0) {
        var_r4 = 1;
        *(int *)((char *)arg0 + 0x260) = 1;
        if (*(int *)((char *)arg0 + 0x18) == 1) {
            var_r4 = -1;
        }
        product = lbl_8055A488 * lbl_8056215C;
        *(float *)((char *)arg0 + 0x264) = (float)var_r4 * (*(float *)((char *)arg0 + 0x284) + product);
    }
}

extern float lbl_8055A488;
extern float lbl_8056215C;
#pragma dont_inline on
void fn_801945F8(void *arg0) {
    if (*(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x1F0) == 0x50) {
        if (*(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x288) + 0x24) != 3) {
            return;
        }
        fn_80194590(arg0);
        return;
    }
    fn_80194590(arg0);
}

extern void *fn_8013A604(void **, float);
void fn_80194624(void *arg0) {
    char *p = (char *)arg0;
    void *r = fn_8013A604((void **)(*(char **)(p + 0x2C8) + 0x40), *(float *)(p + 0x280));
    float q, b, a, c, t;
    if (r != *(void **)(p + 0x2D8)) {
        *(void **)(p + 0x2D4) = *(void **)(p + 0x2D8);
        *(void **)(p + 0x2D8) = r;
        *(float *)(p + 0x2DC) = *(float *)(p + 0x26C);
    }
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    c = lbl_80562140;
    b = ((float *)*(void **)(p + 0x2D8))[2];
    a = ((float *)*(void **)(p + 0x2D4))[2];
    c = (c < q) ? c : q;
    c = (c > lbl_80562144) ? c : lbl_80562144;
    t = a + c * (b - a);
    c = lbl_80562140;
    *(float *)(p + 0x2E8) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[1];
    a = ((float *)*(void **)(p + 0x2D4))[1];
    c = (c < q) ? c : q;
    c = (c > lbl_80562144) ? c : lbl_80562144;
    t = a + c * (b - a);
    c = lbl_80562140;
    *(float *)(p + 0x2E4) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[3];
    a = ((float *)*(void **)(p + 0x2D4))[3];
    c = (c < q) ? c : q;
    c = (c > lbl_80562144) ? c : lbl_80562144;
    t = a + c * (b - a);
    c = lbl_80562140;
    *(float *)(p + 0x2EC) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[4];
    a = ((float *)*(void **)(p + 0x2D4))[4];
    c = (c < q) ? c : q;
    c = (c > lbl_80562144) ? c : lbl_80562144;
    t = a + c * (b - a);
    c = lbl_80562140;
    *(float *)(p + 0x2F0) = t;
    q = (*(float *)(p + 0x26C) - *(float *)(p + 0x2DC)) / **(float **)(p + 0x2D8);
    b = ((float *)*(void **)(p + 0x2D8))[5];
    a = ((float *)*(void **)(p + 0x2D4))[5];
    c = (c < q) ? c : q;
    c = (c > lbl_80562144) ? c : lbl_80562144;
    *(float *)(p + 0x2F4) = a + c * (b - a);
}

extern float fn_801673A4(int, float *);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma dont_inline on
float fn_801948B0(void *arg0, int arg1, float arg2) {
    float *f = (float *)arg0;
    float t, current, out = lbl_80562144, value, adjust, scale, alt, weight, sample, a, b, factor, high;
    float upper, lower;
    int mode;
    factor = lbl_80562140;
    high = f[0x224/4];
    current = f[0x228/4];
    t = (f[0x26C/4] - f[0x22C/4]) / f[0x230/4];
    t = factor < t ? factor : t;
    factor = t > lbl_80562144 ? t : lbl_80562144;
    f[0x220/4] = current + factor * (high - current);
    weight = fn_801673A4(*(int *)((char *)arg0 + 0x290), &sample);
    current = f[0x220/4];
    f[0x220/4] = current + weight * (sample - current);
    scale = lbl_8055E544 * ((lbl_80562184 * lbl_8055A488) * f[0x2E4/4]);
    alt = (lbl_805621C0 * lbl_8055A488) * lbl_8055E568;
    weight = fn_801931EC(arg2, f[0x2CC/4]);
    mode = *(int *)((char *)arg0 + 0x268);
    mode = (mode == 0 || mode == 3) ? 1 : 0;
    if (mode) weight *= scale; else weight *= alt;
    adjust = lbl_80562144;
    if (arg1 && *((unsigned char *)arg0 + 0x14)) {
        value = f[2];
        t = weight * lbl_8056215C + (float)__fabs(value) - f[0x274/4];
        t = t > adjust ? t : adjust;
        if (value > lbl_80562144) t *= lbl_80562140; else t *= -lbl_805621A4;
        adjust = t;
    }
    lower = 0.0f;
    upper = 0.0f;
    out += adjust + f[0x220/4] * weight;
    out += f[0x144/4] * f[0x2E8/4];
    if (arg1) {
        if ((float)__fabs(f[0x278/4]) < lbl_80562174 + f[0x284/4]) {
            a = f[0x274/4];
            b = f[2];
            upper = a - b;
            lower = -a - b;
            out = upper < out ? upper : out;
            out = out > lower ? out : lower;
        } else {
            out = lbl_80562144;
        }
    }
    f[0x238/4] = out;
    return out;
}
#pragma pop

#pragma scheduling invalid_target
void fn_80194AF4(void *unused, float *out, float *a, float *b, float t) {
    volatile double pair;
    union { double d; float f[2]; } temp;
    temp.f[1] = a[1] + t * (b[1] - a[1]);
    temp.f[0] = a[0] + t * (b[0] - a[0]);
    pair = temp.d;
    out[0] = ((float *)&pair)[0];
    out[1] = ((float *)&pair)[1];
    out[2] = a[2] + t * (b[2] - a[2]);
}
#pragma scheduling on
extern double fn_8002EFB4(float, float);
extern float lbl_80562140, lbl_80562144, lbl_8056215C, lbl_805621A4, lbl_805621D0, lbl_805621D4;
#pragma processor 750
float fn_80194B60(float a, float b, float c, float d) {
    float ratio;
    float curve;
    d = (float)fn_8002EFB4(d, c);
    if (d > c * lbl_8056215C) {
        d = c - d;
    }
    ratio = d / (c * lbl_8056215C);
    if (ratio < lbl_805621A4) {
        curve = lbl_805621A4;
    } else if (ratio > lbl_80562140) {
        curve = lbl_80562140;
    } else if (ratio > lbl_80562144) {
        curve = ratio * ((lbl_805621D0 * ratio) * ratio) + ((lbl_805621D4 * ratio) * ratio);
    } else {
        curve = ratio * ((lbl_805621D0 * ratio) * ratio) - ((lbl_805621D4 * ratio) * ratio);
    }
    return a + curve * (b - a);
}

extern float fn_80134C1C(void);
extern int fn_801769A8(void);
extern float fn_801B3064(void);
extern void *fn_801B2EC0(int);
extern float fn_80139048(void);
extern float PSQUATMultiply(void *, void *);
extern void fn_80194F70(void *, float *, float *);
extern float lbl_8055A48C, lbl_80562140, lbl_80562144, lbl_80562160;
extern float lbl_80562174, lbl_80562184, lbl_805621D8, lbl_805621DC;
extern double lbl_805621C8;
extern float lbl_805621E0, lbl_805621E4, lbl_805621E8, lbl_805621EC;
#pragma dont_inline on
void fn_80194C4C(void *arg0, float *arg1) {
    void *work;
    float value;
    int i;

    ((void (*)(void *, float *))fn_80194FD0)(arg0, arg1);
    work = *(void **)((char *)arg0 + 0x288);
    value = *(float *)((char *)work + 0x34);
    arg1[0] += *(float *)((char *)arg0 + 0x58) * value;
    arg1[1] += *(float *)((char *)arg0 + 0x5C) * value;
    value = fn_80134C1C();

    if (fn_801769A8() & 0x400) {
        float endValue = lbl_8055E3C8;
        float elapsed = fn_801B3064();
        float ratio = (endValue - elapsed - lbl_80562144) / lbl_805621D8;
        float amount = lbl_80562140;
        if (amount < ratio)
            amount = ratio;
        if (amount > lbl_80562144)
            amount = lbl_80562144;
        value = lbl_80562144 + amount * (value - lbl_80562144);
    }

    if (*(int *)((char *)work + 0x30) == 0) {
        arg1[2] = value;
        i = 0;
        while (i < fn_801B2F24()) {
            void *other = fn_801B2EC0(i);
            if (i != *(int *)((char *)arg0 + 0x290)) {
                void *state = ((void *(*)(void *))(*(void ***)other)[4])(other);
                if (*(int *)((char *)state + 0x30) == 0) {
                    void *owner = *(void **)((char *)arg0 + 0x294);
                    void *track =
                        ((void *(*)(void *))(*(void ***)other)[8])(other);
                    void *ownerAgain =
                        *(void * volatile *)((char *)arg0 + 0x294);
                    float (*distance)(void *, float *, float *) =
                        (float (*)(void *, float *, float *))fn_80194F70;
                    arg1[2] += distance((char *)ownerAgain + 0x54,
                                        (float *)((char *)track + 0x60),
                                        (float *)((char *)owner + 0x60));
                    break;
                }
            }
            ++i;
        }
    } else {
        float threshold = lbl_805621DC + (lbl_8055A48C + fn_80139048());
        float dot = PSQUATMultiply(
            (char *)*(void **)((char *)work + 0x30) + 0x60,
            (char *)*(void **)((char *)arg0 + 0x294) + 0x60);
        if (dot > threshold) {
            float ratio = (dot - threshold) /
                          (lbl_80562174 * threshold - threshold);
            float amount = ratio > lbl_80562140 ? ratio : lbl_80562140;
            amount = amount > lbl_80562144 ? lbl_80562144 : amount;
            arg1[2] = value + amount * ((lbl_80562160 + value) - value);
        } else {
            float base = value - lbl_80562160;
            float ratio;
            float amount = lbl_80562140;
            base = lbl_80562144 < base ? lbl_80562144 : base;
            ratio = (dot - (lbl_805621DC + lbl_8055A48C)) /
                    (threshold - (lbl_805621DC + lbl_8055A48C));
            if (amount < ratio)
                amount = ratio;
            if (amount > lbl_80562144)
                amount = lbl_80562144;
            arg1[2] = base + amount * (value - base);
        }
    }

    {
        int index = *(int *)((char *)arg0 + 0x290);
        float frame = arg1[2] + fn_80194B60(
            lbl_805621E0, lbl_805621E4, lbl_80562184,
            *(float *)((char *)arg0 + 0x26C) +
                lbl_805621E8 * (float)index);
        arg1[3] = lbl_805621EC;
        arg1[2] = frame;
    }
    if (*(int *)((char *)*(void **)((char *)arg0 + 0x294) + 0x2610) == 0) {
        arg1[2] = lbl_80562144;
        *(int *)((char *)arg0 + 0x2D0) |= 0x10;
    }
    {
        void *controller = *(void **)((char *)arg0 + 0x28C);
        ((void (*)(void *, float *, float *, int *))(*(void ***)controller)[11])(
            controller, arg1, arg1 + 2, (int *)((char *)arg0 + 0x2D0));
    }
    *(int *)((char *)arg0 + 0x2D0) |= 0x826;
}
#pragma dont_inline reset
extern float lbl_8055A488, lbl_8056215C;
extern float PSVECDotProduct(const void *, const void *);
extern void fn_8013B744(int);
void fn_80194F70(void * __restrict arg0, float * __restrict a, float * __restrict b) {
    float diff[3];
    diff[0] = a[0] - b[0];
    diff[1] = a[1] - b[1];
    diff[2] = a[2] - b[2];
    PSVECDotProduct(arg0, diff);
}

void fn_80194FC4(void) {

}

void fn_80194FC8(void *arg0) {
    fn_8013B744(*(int *)((unsigned char *)arg0 + 0x290));
}

void fn_80194FD0(unsigned char *self, float *out, float dt) {
    unsigned char *cfg = P80194FD0(self, 0x2C8);
    Samp80194FD0 b2, a2, b3, a3, s0, sc;
    float q1_2[2], q0_2[2], p1_2[2], p0_2[2];
    float q1_3[2], q0_3[2], p1_3[2], p0_3[2];
    struct V2 { float x, y; } v28;
    float r_2[2], r_3[2];
    float info[2];
    struct V2 v8;
    float f31, f30, t, ret, k;
    int ok, lt, idx;
    s0.a = 0; s0.c = 0x2710; s0.b = lbl_80562144;
    fn_80135B9C(P80194FD0(self, 0x164), 0, 0, 0, &s0, F80194FD0(cfg, 0x70) + F80194FD0(cfg, 0x6C) * F80194FD0(self, 0x270));
    {
        void *e = s0.a;
        void *n = P80194FD0(e, 0x14);
        float v = F80194FD0(e, 0x24);
        void *x = P80194FD0(P80194FD0(self, 0x164), 0x2C);
        ret = ((Fn931AC)fn_801931AC)(x, e, n, v + s0.b * (F80194FD0(n, 0x24) - v), F80194FD0(cfg, 0x60), F80194FD0(cfg, 0x64), F80194FD0(x, 0x14));
    }
    out[3] = F80194FD0(self, 0x2F0) * ret;
    t = out[3] * F80194FD0(self, 0x270);
    f30 = F80194FD0(P80194FD0(self, 0x2C8), 0x68);
    f30 = (f30 > t) ? f30 : t;
    f31 = F80194FD0(self, 0x26C);
    lt = (f31 - F80194FD0(self, 0x1D0)) < lbl_805621C0;
    if (lt) {
        a2.a = 0; a2.c = 0x2710; a2.b = lbl_80562144;
        b2.a = 0; b2.c = 0x2710; b2.b = lbl_80562144;
        fn_80135B9C(self + 0x168, p0_2, q0_2, &r_2[0], &a2, f30);
        fn_80135B9C(self + 0x19C, p1_2, q1_2, &r_2[1], &b2, f30);
        if (out + 2 != 0) {
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            out[2] = r_2[0] + k * (r_2[1] - r_2[0]);
        }
        if (out != 0) {
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            v8.y = p0_2[1] + k * (p1_2[1] - p0_2[1]);
            v8.x = p0_2[0] + k * (p1_2[0] - p0_2[0]);
            *(double *)&v28 = *(double *)&v8;
            out[0] = v28.x;
            out[1] = v28.y;
        }
        if (self + 8 != 0) {
            void *ea = a2.a, *eb = b2.a;
            float va, vb;
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            va = F80194FD0(ea, 0x2C) + a2.b * (F80194FD0(P80194FD0(ea, 0x14), 0x2C) - F80194FD0(ea, 0x2C));
            vb = F80194FD0(eb, 0x2C) + b2.b * (F80194FD0(P80194FD0(eb, 0x14), 0x2C) - F80194FD0(eb, 0x2C));
            F80194FD0(self, 8) = va + k * (vb - va);
        }
    } else if (self + 8 != 0) {
        sc.a = 0; sc.c = 0x2710; sc.b = lbl_80562144;
        fn_80135B9C(self + 0x19C, out, 0, out + 2, &sc, f30);
        F80194FD0(self, 8) = F80194FD0(sc.a, 0x2C) + sc.b * (F80194FD0(P80194FD0(sc.a, 0x14), 0x2C) - F80194FD0(sc.a, 0x2C));
    } else {
        fn_80135B9C(self + 0x19C, out, 0, out + 2, 0, f30);
    }
    f31 = F80194FD0(self, 0x26C);
    F80194FD0(self, 0xC) = out[0];
    F80194FD0(self, 0x10) = out[1];
    *(unsigned char *)(self + 0x14) = 1;
    lt = (f31 - F80194FD0(self, 0x1D0)) < lbl_805621C0;
    if (lt) {
        a3.a = 0; a3.c = 0x2710; a3.b = lbl_80562144;
        b3.a = 0; b3.c = 0x2710; b3.b = lbl_80562144;
        fn_80135B9C(self + 0x168, p0_3, q0_3, &r_3[0], &a3, lbl_805621F0 * f30);
        fn_80135B9C(self + 0x19C, p1_3, q1_3, &r_3[1], &b3, lbl_805621F0 * f30);
        if (out + 2 != 0) {
            k = (f31 - F80194FD0(self, 0x1D0)) / lbl_805621C0;
            out[2] = r_3[0] + k * (r_3[1] - r_3[0]);
        }
    } else {
        fn_80135B9C(self + 0x19C, 0, 0, out + 2, 0, lbl_805621F0 * f30);
    }
    out[2] = out[2] * ((Fn94FC8)fn_80194FC8)(self);
    if (*(unsigned char *)(self + 0x2A6) != 0) {
        float top = lbl_8056217C + F80194FD0(self, 0x1EC);
        float u = (F80194FD0(self, 0x26C) - F80194FD0(self, 0x1EC)) / (top - F80194FD0(self, 0x1EC));
        float w = lbl_80562140;
        w = (w < u) ? w : u;
        w = (w > lbl_80562144) ? w : lbl_80562144;
        out[2] = out[2] * (lbl_80562140 + lbl_805621F4 * (lbl_80562144 + w * lbl_80562140));
    }
    ret = ((Fn948B0)fn_801948B0)(self, 0, dt);
    out[0] = out[0] + F80194FD0(self, 0x58) * ret;
    out[1] = out[1] + F80194FD0(self, 0x5C) * ret;
    if (*(int *)(self + 0x268) == 3) {
        float top = lbl_805621F8 + F80194FD0(self, 0x1DC);
        float u = (F80194FD0(self, 0x26C) - F80194FD0(self, 0x1DC)) / (top - F80194FD0(self, 0x1DC));
        float w = lbl_80562140;
        w = (w < u) ? w : u;
        w = (w > lbl_80562144) ? w : lbl_80562144;
        out[2] = out[2] * (lbl_80562140 + w * lbl_805621FC);
    }
    ok = 0;
    if ((lbl_8055D430 & 1) && (lbl_8055D430 & 0x20)) ok = 1;
    idx = *(int *)(self + 0x2C4);
    if (ok != 0 && idx != -1) {
        unsigned char *tbl = (unsigned char *)lbl_8055E0D0;
        void *ent = *(void **)(*(unsigned char **)(tbl + 0x10) + *(int *)(self + 0x290) * *(int *)(tbl + 0xC) + idx * 4 + 0x18);
        if (F80194FD0(ent, 0x18) < lbl_80562200) {
            unsigned char *o = fn_8017960C();
            fn_80137788(ent, *(int *)(self + 0x290), info);
            if (info[1] > lbl_80562144) {
                out[0] = F80194FD0(o, 0x60);
                out[1] = F80194FD0(o, 0x68);
                out[2] = lbl_8056216C + F80194FD0(o, 0x25CC);
            } else {
                float z = F80194FD0(o, 0x25CC) - lbl_80562160;
                z = (z > lbl_80562160) ? z : lbl_80562160;
                out[2] = z;
            }
        }
    }
    {
        void ***ctl = (void ***)P80194FD0(self, 0x28C);
        ((void (*)(void *, float *, float *, void *))(*ctl)[10])(ctl, out, out + 2, self + 0x2D0);
    }
}

void fn_801955F0(void *arg0, float *arg1) {
    float scale;
    ((void (*)(void *, float *))fn_80194FD0)(arg0, arg1);
    scale = *(float *)((unsigned char *)arg0 + 0x2B8);
    arg1[0] += *(float *)((unsigned char *)arg0 + 0x58) * scale;
    arg1[1] += *(float *)((unsigned char *)arg0 + 0x5C) * scale;
}

extern void fn_801971AC(void *, void *);
extern void fn_801981A0(void *, void *);
extern void fn_8019743C(void *, void *);
extern void fn_80197BD0(void *, void *);
extern void fn_8019724C(void *, float *);
extern unsigned char fn_80167544(int);
void fn_80195654(void *arg0, void *arg1) {
    struct Scratch { int word0, word1; float value0, value1; } scratch;
    float threshold = *(volatile float *)&lbl_805621C0;
    float previous = *(volatile float *)((char *)arg0 + 0x1D0);
    float current = *(volatile float *)((char *)arg0 + 0x26C);
    float difference;
    float interpolated;
    float value;
    int doInterpolate;
    void *first;
    void *second;
    void *left;
    void *right;
    int firstWord;
    int secondWord;
    int flags;

    *(volatile int *)((char *)arg0 + 0x2D0) = 0;
    difference = current - previous;
    doInterpolate = difference < threshold;
    if (doInterpolate != 0) {
        first = *(void **)((char *)arg0 + 0x1A0);
        second = *(void **)((char *)arg0 + 0x16C);
        left = *(void **)((char *)first + 0x14);
        right = *(void **)((char *)second + 0x14);
        {
            float nextA = *(float *)((char *)left + 0x24);
            float baseA = *(float *)((char *)first + 0x24);
            float nextB = *(float *)((char *)right + 0x24);
            float baseB = *(float *)((char *)second + 0x24);
            float deltaA = nextA - baseA;
            float scaleA = *(float *)((char *)arg0 + 0x1A4);
            float deltaB = nextB - baseB;
            float scaleB = *(float *)((char *)arg0 + 0x170);
            float valueA = baseA + scaleA * deltaA;
            float valueB = baseB + scaleB * deltaB;
            float fraction = difference / threshold;
            interpolated = valueB + fraction * (valueA - valueB);
        }
    } else {
        first = *(void **)((char *)arg0 + 0x1A0);
        value = *(float *)((char *)arg0 + 0x1A4);
        left = *(void **)((char *)first + 0x14);
        {
            float base = *(float *)((char *)first + 0x24);
            float next = *(float *)((char *)left + 0x24);
            float delta = next - base;
            interpolated = base + delta * value;
        }
    }
    if (*(int *)((char *)arg0 + 0x268) == 1) {
        ((void (*)(void *, void *, float))fn_80194C4C)(arg0, arg1, interpolated);
    } else {
        ((void (*)(void *, void *, float))fn_80194FD0)(arg0, arg1, interpolated);
        if (*(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x1E4) <
            *(float *)((char *)arg0 + 0x2BC)) {
            firstWord = ((int *)arg1)[0];
            secondWord = ((int *)arg1)[1];
            scratch.word0 = firstWord;
            scratch.word1 = secondWord;
            scratch.value0 = ((float *)arg1)[2];
            scratch.value1 = ((float *)arg1)[3];
            ((void (*)(void *, float *, float))fn_801955F0)(arg0, (float *)&scratch, interpolated);
            {
                float from = *(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x1E4);
                float to = *(float *)((char *)arg0 + 0x2BC);
                float t = from / to;
                t = t * t;
                fn_80194AF4(arg0, (float *)arg1, (float *)&scratch, (float *)arg1, t);
            }
        }
    }
    fn_801971AC(arg0, arg1);
    *(float *)((char *)arg0 + 0x1C) = ((float *)arg1)[2];
    fn_801981A0(arg0, arg1);
    fn_8019743C(arg0, arg1);
    fn_80197BD0(arg0, arg1);
    fn_8019724C(arg0, arg1);
    flags = ((int (*)(int))fn_80167544)(*(int *)((char *)arg0 + 0x290));
    if (flags != 0) {
        *(int *)((char *)arg0 + 0x2D0) |= 0x50;
    }
}

void fn_80195830(void *arg0) {
    struct Fields { unsigned char pad[0x20]; float x; float y; unsigned char mid[0x18]; float outX; float outY; };
    struct Fields* obj = (struct Fields*)arg0;
    float length, denominator, scale;
    ((void (*)(void*, void*))fn_80195654)(arg0, (void*)((unsigned long)arg0 + 0x20));
    fn_801933FC(obj, &obj->x);
    obj->outX = obj->x;
    obj->outY = obj->y;
    length = (float)fn_8002F234(obj->x * obj->x + obj->y * obj->y);
    denominator = lbl_80562148;
    denominator = denominator > length ? denominator : length;
    scale = lbl_80562140 / denominator;
    obj->outX *= scale;
    obj->outY *= scale;
}

extern void fn_801958D8(void);
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern float lbl_8055E3C8;
extern float lbl_80562144;
extern void fn_80195654(void *, void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_80562140;
extern float lbl_80562148;
extern float lbl_80562204;
void fn_801958C4(void *arg0) { *(float *)((unsigned char *)arg0+0x248) *= lbl_80562204; }

void fn_801959AC(void *arg0) {
    extern double __fabs(double);
    extern char lbl_80558DC4[];
    extern float lbl_80562140, lbl_80562144, lbl_805621DC, lbl_80562208;
    extern char lbl_803332F8[];
    extern char lbl_8055A4B0;
    unsigned char *p = (unsigned char *)arg0;
    void *obj;
    float value;
    float stateDifference;
    int state;
    int idle;

    if (p[0x2A7]) {
        obj = *(void **)(p + 0x294);
        if (*(int *)((char *)obj + 0x2620) > 0) {
            p[0x2A7] = 0;
            fn_8018A174(obj);
        }
    }

    obj = *(void **)(p + 0x294);
    if (!((float)__fabs((double)*(float *)((char *)obj + 0x2690)) <= *(float *)lbl_80558DC4))
        ((void (*)(void *, const char *))fn_801961F8)(arg0, lbl_803332F8);

    fn_80195B28(arg0, lbl_80562144);
    value = *(float *)(p + 0x26C) - *(float *)(p + 0x1F4);
    fn_801942F0(arg0, value > lbl_80562140);

    state = *(int *)(p + 0x260);
    switch (state) {
    case 1:
        stateDifference = *(float *)(p + 0x264);
        stateDifference = *(float *)(p + 0x278) - stateDifference;
        if ((float)__fabs((double)stateDifference) < lbl_805621DC)
            *(int *)(p + 0x260) = 2;
        break;
    case 2:
        if (*(float *)(p + 0x270) < lbl_80562208)
            fn_80193CD4(arg0);
        break;
    }

    if ((float)__fabs((double)*(float *)(p + 0x278)) >
            lbl_80562140 + *(float *)(p + 0x284) &&
        !(*(int *)(p + 0x2D0) & 8))
        ((void (*)(void *, const char *))fn_8019416C)(arg0, &lbl_8055A4B0);

    obj = *(void **)(p + 0x294);
    idle = *(int *)((char *)obj + 0x2620) == 0;
    if (idle && !p[0x208])
        *(float *)(p + 0x204) = *(float *)(p + 0x26C);
    p[0x208] = idle;
}

void fn_80195B28(void *arg0, float arg1) {
    float *p = (float *)arg0;
    float *table;
    float value;
    float scale;
    unsigned int tableValue;
    int index;
    unsigned int selected;

    if (p[0x234 / 4] < p[0x26C / 4] || lbl_80562144 != arg1) {
        table = (float *)__AXFXGetLfoSinTable_801769CC();
        {
            unsigned int expected = 0x180201;
            tableValue = *(unsigned int *)((char *)table + 4);
            if (((expected - tableValue) | (tableValue - expected)) >> 31) {
                index = *(int *)((char *)arg0 + 0x268);
                selected = (unsigned int)__cntlzw(index - 1) >> 5;
                table = lbl_80333308;
                if (selected)
                    table += 3;
                {
                    volatile float *vp = (volatile float *)arg0;
                    float base = vp[0x26C / 4];
                    float first = table[0];
                    p[0x22C / 4] = base;
                    p[0x234 / 4] = fn_80129DC4(3, first, table[1]);
                }
                if (!selected)
                    p[0x234 / 4] *= lbl_8055E56C;
                p[0x228 / 4] = p[0x220 / 4];
                p[0x234 / 4] += p[0x26C / 4];
                p[0x230 / 4] = table[2];
                if (selected)
                    p[0x224 / 4] = fn_80129DC4(3, lbl_8056220C, lbl_8056215C);
                else
                    p[0x224 / 4] = fn_80129DC4(3, lbl_805621A4, lbl_80562140);
                if (lbl_80562144 != arg1) {
                    value = (float)__fabs((double)p[0x224 / 4]);
                    if (arg1 > lbl_80562144)
                        scale = lbl_80562140;
                    else
                        scale = lbl_805621A4;
                    p[0x224 / 4] = scale * value;
                }
            } else {
                p[0x234 / 4] = p[0x26C / 4];
                p[0x228 / 4] = lbl_80562144;
                p[0x224 / 4] = lbl_80562144;
                p[0x22C / 4] = p[0x26C / 4];
                p[0x230 / 4] = p[0x26C / 4];
            }
        }
    }
}

extern void fn_80194324();
extern void fn_801944C0(void *);
extern float lbl_805621BC, lbl_80562210, lbl_80562214, lbl_80562218;
void fn_80195CA8(void *arg0) {
    int temp_r3;
    if (!(*(int *)((char *)arg0 + 4) & 0x7F)) {
        fn_80194324();
        fn_801944C0(arg0);
    }
    if (*(float *)((char *)arg0 + 0x270) < lbl_805621BC &&
        *(float *)((char *)arg0 + 0x2A0) > lbl_80562210) {
        *(float *)((char *)arg0 + 0x2A0) = lbl_80562214;
        if (*(int *)((char *)arg0 + 0x260) == 0) {
            temp_r3 = *(int *)((char *)arg0 + 0x210);
            if (temp_r3 != 1) {
                if (*(int *)((char *)arg0 + 0x214) == 2) {
                    *(int *)((char *)arg0 + 0x214) = temp_r3;
                    *(int *)((char *)arg0 + 0x210) = 1;
                } else {
                    *(int *)((char *)arg0 + 0x210) = 1;
                }
                *(float *)((char *)arg0 + 0x218) = *(float *)((char *)arg0 + 0x26C);
            }
        } else {
            *(int *)((char *)arg0 + 0x260) = 2;
        }
    } else {
        *(float *)((char *)arg0 + 0x2A0) *= lbl_80562218;
    }
    ++*(int *)((char *)arg0 + 4);
}

extern int fn_801388F4(void *);
extern void fn_801353C4(void *, float *);
extern float lbl_805621C0;
struct Shape_80195D80 {
    unsigned char pad0[0x14];
    float f14;
    unsigned char pad1[0x10];
    int f28;
};
struct Snap_80195D80 {
    void *w0;
    unsigned int w[8];
    unsigned char b;
    struct Shape_80195D80 *shape;
    unsigned int w2;
};
struct Obj_80195D80 {
    unsigned int pad;
    struct Snap_80195D80 snap;
};
static inline void CopySnap_80195D80(struct Snap_80195D80 *dst, struct Snap_80195D80 *src) {
    *dst = *src;
}
#pragma cplusplus on
class Vt_80195D80 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4();
    virtual Obj_80195D80 *v5();
};
static inline Obj_80195D80 *GetObj_80195D80(void *p) {
    return ((Vt_80195D80 *)p)->v5();
}
struct VtObj_80195D80;
struct VtTbl_80195D80 {
    void *slots0[7];
    struct Obj_80195D80 *(*get)(struct VtObj_80195D80 *);
};
struct VtObj_80195D80 {
    struct VtTbl_80195D80 *vt;
};
struct Other_80195D80 {
    unsigned char p0[0x54];
    float a54, a58, a5c;
    unsigned char p1[0x94 - 0x60];
    float a94, a98, a9c;
    unsigned char p2[0x5BC - 0xA0];
    float a5bc;
};
struct Self_80195D80 {
    unsigned char p0[0x18];
    int f18;
    unsigned char p1[0x168 - 0x1C];
    unsigned char f168[4];
    struct Snap_80195D80 prev;
    unsigned char p2[4];
    struct Snap_80195D80 cur;
    float f1d0;
    unsigned char p3[0x28C - 0x1D4];
    void *src;
    unsigned char p4[4];
    struct Other_80195D80 *other;
    unsigned char p5[0x2C8 - 0x298];
    int f2c8;
    float f2cc;
};
extern "C" void fn_80195D80(void *arg0, float arg1) {
    Self_80195D80 *self = (Self_80195D80 *)arg0;
    Obj_80195D80 *obj = ((Vt_80195D80 *)self->src)->v5();
    int changed;
    float vec[5];
    Other_80195D80 *o;
    self->f2cc = obj->snap.shape->f14;
    self->f2c8 = obj->snap.shape->f28;
    self->f18 = fn_801388F4(obj->snap.w0);
    changed = 0;
    o = self->other;
    if (self->cur.shape != 0 && (unsigned int)self->cur.shape != (unsigned int)obj->snap.shape) {
        changed = 1;
    }
    if (changed) {
        self->prev.w0 = self->cur.w0;
        self->prev.w[0] = self->cur.w[0];
        self->prev.w[1] = self->cur.w[1];
        self->prev.w[2] = self->cur.w[2];
        self->prev.w[3] = self->cur.w[3];
        self->prev.w[4] = self->cur.w[4];
        self->prev.w[5] = self->cur.w[5];
        self->prev.w[6] = self->cur.w[6];
        self->prev.w[7] = self->cur.w[7];
        self->prev.b = self->cur.b;
        self->prev.shape = self->cur.shape;
        self->prev.w2 = self->cur.w2;
        self->f1d0 = lbl_8055E3C8;
    }
    CopySnap_80195D80(&self->cur, &obj->snap);
    if (arg1 - self->f1d0 < lbl_805621C0) {
        float s = o->a5bc;
        float x = o->a94 + o->a54 * s;
        float y = o->a98 + o->a58 * s;
        float z = o->a9c + o->a5c * s;
        vec[0] = x;
        vec[1] = z;
        vec[2] = x;
        vec[3] = y;
        vec[4] = z;
        fn_801353C4(self->f168, vec);
    }
}

extern "C" void fn_80135B9C(void *, void *, void *, void *, void *, float);
extern "C" int fn_802E30C8(const char *, ...);
void fn_80195F6C(void *arg0, void *arg1) {
    extern float lbl_8055A488, lbl_8055A48C, lbl_8056215C, lbl_805621DC, lbl_80562210, lbl_8056221C;
    extern double lbl_80562220;
    extern float lbl_80562228, lbl_8056222C;
    extern char lbl_8033332C[];
    struct Trio { void *p; float f; int i; };
    char *self = (char *)arg0;
    Trio sp24;
    Trio sp18;
    double u1, u2;
    float f2;
    float keep;
    float m, t;
    int flag;
    char *obj;

    if (*(unsigned char *)(self + 0x2A5) == 0) {
        obj = *(char **)(self + 0x164);
        sp24.p = *(void **)(obj + 4);
        sp24.f = *(float *)(obj + 8);
        sp24.i = *(int *)(obj + 0xC);
        fn_80195D80(arg0, *(float *)(self + 0x26C));
        *(int *)(*(char **)(self + 0x164) + 0xC) = 0;
        f2 = *(float *)(*(char **)(*(char **)(self + 0x164) + 4) + 0x28);
        if (!(*((unsigned char *)sp24.p + 0x35) & 1)) {
            f2 = f2 * lbl_80562210;
        }
        flag = 1;
        *(float *)(self + 0x284) = lbl_8056215C * f2;
        *(float *)(self + 0x274) = lbl_8056215C * (f2 - lbl_8055A488) - lbl_8056221C;
        if (*(int *)(self + 0x268) != 0 && *(int *)(self + 0x268) != 3) {
            flag = 0;
        }
        if (flag == 0) {
            *(float *)(self + 0x274) = *(float *)(self + 0x274) - lbl_805621DC;
        }
        if (*(float *)(self + 0x274) <= lbl_80562144) {
            fn_802E30C8(lbl_8033332C, u1, u2, (double)lbl_8055A488, lbl_80562220);
        }
        obj = *(char **)(self + 0x164);
        *(float *)(self + 0x278) = *(float *)(obj + 0x40);
        t = lbl_80562228 * *(float *)(self + 0x270);
        keep = lbl_8056215C;
        *(float *)(self + 0x280) = *(float *)(obj + 0x48);
        *(float *)(self + 0x27C) = *(float *)(obj + 0x44);
        *(unsigned char *)(self + 0x2FE) = 0;
        m = lbl_8055A48C;
        if (m <= t) m = t;
        sp18.p = 0;
        sp18.i = 0x2710;
        sp18.f = lbl_80562144;
        fn_80135B9C(*(void **)(self + 0x164), 0, 0, self + 0x50, &sp18, m);
        *(float *)(self + 0x54) = keep;
        *(void **)(self + 0x68) = sp18.p;
        *(float *)(self + 0x6C) = sp18.f;
        *(int *)(self + 0x70) = sp18.i;
        if (*((unsigned char *)sp18.p + 0x34) == 3) {
            *(float *)(self + 0x50) = lbl_8056222C;
        }
        if (sp18.p != 0) {
            char *a = (char *)sp18.p;
            char *b = *(char **)(a + 0x14);
            float v[4];
            float inv;
            v[0] = *(float *)(a + 8) + sp18.f * (*(float *)(b + 8) - *(float *)(a + 8));
            v[1] = *(float *)(a + 0xC) + sp18.f * (*(float *)(b + 0xC) - *(float *)(a + 0xC));
            v[2] = *(float *)(a + 0) + sp18.f * (*(float *)(b + 0) - *(float *)(a + 0));
            v[3] = *(float *)(a + 4) + sp18.f * (*(float *)(b + 4) - *(float *)(a + 4));
            inv = lbl_80562140 / (float)fn_8002F234(v[0] * v[0] + v[1] * v[1]);
            *(float *)(self + 0x48) = v[2];
            *(float *)(self + 0x4C) = v[3];
            v[0] = v[0] * inv;
            v[1] = v[1] * inv;
            *(float *)(self + 0x58) = v[1];
            *(float *)(self + 0x5C) = -v[0];
            *(float *)(self + 0x60) = v[0];
            *(float *)(self + 0x64) = v[1];
        }
    }
}

#pragma cplusplus reset

  void fn_801961F8(void) {

}

extern float lbl_80562140, lbl_80562144, lbl_80562168;
extern float lbl_80562208, lbl_80562230, lbl_80562234, lbl_80562238;
extern float __fabsf(float);
void fn_80196250(float *arg0, float *arg1, int *arg2, float farg0, float farg1, float farg2) {
    float temp_f5;
    double mag0;
    float abs0;
    float sp8;
    float spC;
    float value1;
    float value0;
    float out1;
    float out0;
    int var_r0;
    temp_f5 = farg0 - farg1;
    temp_f5 += lbl_80562230;
    temp_f5 /= farg2;
    mag0 = __fabs((double)farg0);
    abs0 = (float)mag0;
    if (abs0 < lbl_80562168) {
        value0 = lbl_80562140;
        value1 = lbl_80562144;
        *arg1 = value0;
        *arg0 = value1;
        *arg2 = 0;
        return;
    }
    if ((float)__fabs((double)farg1) < lbl_80562208)
        goto direct_case;
    spC = farg1;
    sp8 = temp_f5;
    if ((int)(*(unsigned int *)&spC & 0x80000000U) != (int)(*(unsigned int *)&sp8 & 0x80000000U))
        goto different_sign;
direct_case:
    out1 = lbl_80562144;
    out0 = (float)__fabs((double)temp_f5) / lbl_80562234;
    *arg0 = out0;
    *arg1 = out1;
    goto finish;
different_sign:
    out0 = lbl_80562144;
    out1 = (float)__fabs((double)temp_f5) / lbl_80562238;
    *arg0 = out0;
    *arg1 = out1;
finish:
    if (farg0 > lbl_80562144)
        var_r0 = 1;
    else
        var_r0 = -1;
    *arg2 = var_r0;
}

  extern float fn_801671FC(int);
  extern int fn_801B89F8(void);
  extern int lbl_8055E0D0;
  extern void fn_8018ADAC(void *, float);
  extern void fn_8018AE24(int, int);
  extern void fn_80136EA4(int, int);
  extern void fn_80136E8C(int, int, int);
void fn_80196328(void *arg0) {
    float value = lbl_80562140;
    fn_8018ADBC(*(int *)((char *)arg0 + 0x294), value);
    fn_8018ADB4(*(int *)((char *)arg0 + 0x294), lbl_80562144);
    fn_8018ADAC(*(void **)((char *)arg0 + 0x294), lbl_80562144);
    fn_8018AE24(*(int *)((char *)arg0 + 0x294), 0);
    fn_80136EA4(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290));
    fn_80136E8C(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290), 0);
}

      extern int fn_801B2F24(void);
    extern void fn_801B2F40(int);
    extern int fn_8019643C();

    void fn_8019639C(void) {
      fn_80194844();
  }

#pragma dont_inline on
void fn_801963A0(void *arg0) {
    void *obj;
    float value;
    float delta;
    ((void (*)(void *, int))fn_801961F8)(arg0, 0);
    obj = *(void **)((char *)arg0 + 0x294);
    value = *(float *)((char *)obj + 0x25D4);
    delta = lbl_8056223C * value;
    lbl_8055E57C += delta;
    ((void (*)(int, int, int, float, float))fn_80136E8C)(lbl_8055E0D0, *(int *)((char *)arg0 + 0x290), 1, delta, value);
    fn_801958C4(arg0);
    fn_801959AC(arg0);
    fn_80195CA8(arg0);
}
#pragma dont_inline reset
  void fn_80196414(void *arg0) {
      fn_80196DC4(arg0);
  }

#pragma dont_inline on
void fn_80196418(void *arg0) {
    int value = *(int *)((char *)arg0 + 0x210);
    if (value == 1) {
        return;
    }
    if (value > 1) {
        return;
    }
    if (value >= 0) {
        return;
    }
    fn_80195830(arg0);
}

int fn_8019643C(int arg0) {
    return *(int *)(lbl_804348E8[arg0] + 0x10) == 0x50434152;
}

#pragma dont_inline reset
      extern int fn_801B2F24(void);
    extern void fn_801B2F40(int);
    extern int fn_8019643C();
    int fn_80196468(int arg0) {
      int end = fn_801B2F24();
      int i = arg0;
      while (i <= end) {
          fn_801B2F40(i - 1);
          if (fn_8019643C() != 0) return 1;
          i++;
      }
      return 0;
  }

extern int fn_80129D18(int, int);
extern void fn_8018A174(void *);
extern void fn_8017B4AC(void *, float *, float, float);
extern float lbl_80562240;
#pragma cplusplus on
extern "C" void fn_801964D0(void *arg0) {
    float vector[3];
    float scale;
    float temp_f1;
    float temp_f2;
    float var_f3;
    Vt_80194C4C *controller;
    controller = (Vt_80194C4C *)*(void **)((char *)arg0 + 0x28C);
    if (fn_80196468(*(int *)((char *)controller->v2() + 4)) != 0) {
        *((unsigned char *)arg0 + 0x2A7) = 1;
        if (fn_80129D18(3, 10) < 5) {
            fn_8018A174(*(void **)((char *)arg0 + 0x294));
            if (fn_80129D18(3, 2) != 0)
                var_f3 = lbl_805621A4;
            else
                var_f3 = lbl_80562140;
            controller = (Vt_80194C4C *)*(void **)((char *)arg0 + 0x294);
            scale = *(float *)((char *)controller + 0xD4);
            temp_f2 = lbl_805621AC * scale;
            temp_f1 = lbl_80562240 * temp_f2;
            temp_f1 *= var_f3;
            vector[0] = *(float *)((char *)controller + 0x3C) * temp_f1;
            vector[1] = *(float *)((char *)controller + 0x40) * temp_f1;
            vector[2] = *(float *)((char *)controller + 0x44) * temp_f1;
            fn_8017B4AC(*(void **)((char *)arg0 + 0x294), vector, temp_f1, temp_f2);
        }
    }
}
#pragma cplusplus reset
extern float lbl_80562140, lbl_80562144, lbl_80562184, lbl_805621A4;
extern float lbl_805621EC, lbl_80562244, lbl_80562248;
extern void fn_801EA18C(void *, void *, int, int, void *, float);
extern void fn_8018AE2C(void *, float);
extern void fn_8018AE34(void *, float);
void fn_801965AC(void *arg0) {
    float position[3];
    int transform[3];
    float delta;
    float diff;
    float depth;
    float value;
    float range;
    float scalar;
    float adjusted;
    float product;
    int doEffect;
    int first;
    int second;
    void *obj;

    if (*(int *)((char *)*(void **)((char *)arg0 + 0x294) + 0x2620) != 0)
        return;

    position[0] = lbl_80562144;
    position[1] = lbl_80562140;
    position[2] = lbl_80562144;
    obj = *(void **)((char *)arg0 + 0x294);
    first = *(int *)((char *)obj + 0x60);
    second = *(int *)((char *)obj + 0x64);
    transform[0] = first;
    transform[1] = second;
    transform[2] = *(int *)((char *)obj + 0x68);
    fn_801EA18C(transform, position, 0, transform[0], obj, lbl_80562144);

    obj = *(void **)((char *)arg0 + 0x294);
    delta = lbl_80562144;
    diff = *(float *)((char *)obj + 0x64) - *(float *)((char *)transform + 4);
    delta = delta > diff ? delta : diff;
    depth = *(float *)((char *)obj + 0x11C);
    depth = depth < lbl_80562244 ? lbl_80562244 : depth;
    range = lbl_80562140;
    doEffect = (-delta / depth) < range;
    scalar = lbl_80562184;
    if (doEffect) {
        float output;
        product = scalar * PSVECDotProduct(position, (char *)obj + 0x54);
        output = lbl_80562140;
        output = output < product ? output : product;
        output = output > lbl_805621A4 ? output : lbl_805621A4;
        fn_8018AE2C(*(void **)((char *)arg0 + 0x294), output);

        product = scalar * PSVECDotProduct(position, (char *)*(void **)((char *)arg0 + 0x294) + 0x3C);
        output = lbl_80562140;
        output = output < product ? output : product;
        output = output > lbl_805621A4 ? output : lbl_805621A4;
        fn_8018AE34(*(void **)((char *)arg0 + 0x294), output);
        return;
    }

    value = __fabs(*(float *)((char *)arg0 + 0x23C));
    value = (value - lbl_80562144) / range;
    range = range < value ? value : range;
    range = range > lbl_80562144 ? lbl_80562144 : range;
    adjusted = *(float *)((char *)obj + 0x58) - (lbl_805621EC + range * lbl_80562248);
    product = scalar * adjusted;
    value = lbl_80562140;
    value = value < product ? value : product;
    value = value > lbl_805621A4 ? value : lbl_805621A4;
    fn_8018AE2C(obj, value);
    fn_8018AE34(*(void **)((char *)arg0 + 0x294), lbl_80562144);
}

extern void fn_80196AA0(void *);
extern void fn_80198530(void *);
  void fn_801967A4(void *arg0) {
      int value = *(int *)((char *)arg0 + 0x210);
      switch (value) {
      case 0:
                     fn_80198530(arg0);
           fn_801965AC(arg0);
          return;
      case 1:
          fn_80196AA0(arg0);
          return;
      }
  }

void fn_801967FC(void *arg0) {
    float temp_f0;
    float var_f2;
    *(int *)((char *)arg0 + 0x300) = 0;
    if ((int)*(u8 *)((char *)arg0 + 0x250) != 0) {
        *(float *)((char *)arg0 + 0x254) *= lbl_8056224C;
        return;
    }
    var_f2 = lbl_80562140;
    temp_f0 = lbl_80562148 + *(float *)((char *)arg0 + 0x254);
    if (var_f2 < temp_f0) {
        var_f2 = var_f2;
    } else {
        var_f2 = temp_f0;
    }
    *(float *)((char *)arg0 + 0x254) = var_f2;
}

extern int fn_801796B4(void);
extern int fn_80134A44(int);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
#pragma dont_inline on
#pragma cplusplus on
extern "C" void fn_8019684C(void) {
    struct List { int count; void *entry[8]; };
    struct Controller {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
        virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
        virtual void update();
    };
    List active, inactive;
    void **entry;
    int mode, i, count;
    active.count = 0;
    inactive.count = 0;
    mode = fn_801796B4();
    entry = lbl_804349C0;
    for (i = 0; i < 8; i++, entry++) {
        void *obj = *entry;
        if (obj && fn_80134A44(i) && *((unsigned char *)obj + 0x2A4)) {
            if (mode || *((unsigned char *)obj + 0x2A5)) inactive.entry[inactive.count++] = obj;
            else active.entry[active.count++] = obj;
        }
    }
    count = inactive.count;
    for (i = 0; i < count; i++) ((void (*)(void *))fn_8019639C)(inactive.entry[i]);
    count = active.count;
    for (i = 0; i < count; i++) ((void (*)(void *))fn_8019639C)(active.entry[i]);
    count = inactive.count;
    for (i = 0; i < count; i++) fn_80196328(inactive.entry[i]);
    count = active.count;
    for (i = 0; i < count; i++) fn_801963A0(active.entry[i]);
    count = active.count;
    for (i = 0; i < count; i++) fn_80196414(active.entry[i]);
    count = active.count;
    for (i = 0; i < count; i++) fn_80196418(active.entry[i]);
    count = active.count;
    for (i = 0; i < count; i++) fn_801967A4(active.entry[i]);
    count = active.count;
    for (i = 0; i < count; i++) fn_801967FC(active.entry[i]);
    {
        struct Controllers { Controller *entries[8]; int count; };
        Controllers *controllers = (Controllers *)lbl_804349E0;
        Controller **iter = controllers->entries;
        for (i = 0; i < controllers->count; i++, iter++) (*iter)->update();
    }
}
#pragma cplusplus reset
#pragma pop

  void fn_80196A9C(void) {
      fn_8019684C();
  }

extern float lbl_80562160, lbl_805621A4, lbl_80562258, lbl_8056225C;
extern float lbl_80562250[2];
extern void fn_8017B3A8(void *, float *, void *, float);
extern void fn_8018ADD4(void *, int);
extern void fn_8018ADC4(int, float);
void fn_80196AA0(void *arg0) {
    float *limits = lbl_80562250;
    volatile float slots[2];
    int state = 0;
    float difference;
    float vecA[3];
    float vecB[3];

    difference = *(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x218);
    if (!(difference < limits[0])) {
        state = 1;
        if (!(difference < limits[1])) state = 2;
    }
    {
        void *flags = *(void **)((char *)arg0 + 0x298);
        if (*(unsigned char *)((char *)flags + 0x17C) != 0 &&
            *(unsigned char *)((char *)flags + 0x108) == 0) state = -1;
    }
    if (state == 0) goto case0;
    if (state >= 0) goto nonnegative;
    if (state >= -1) goto transition;
    goto transition;
nonnegative:
    if (state >= 2) goto transition;
    goto case1;
case0: {
        void *object = *(void **)((char *)arg0 + 0x294);
        void *outputBase;
        void *inputBase;
        float factor = lbl_80562258;
        vecA[0] = *(float *)((char *)object + 0x88) * factor;
        vecA[1] = *(float *)((char *)object + 0x8C) * factor;
        vecA[2] = *(float *)((char *)object + 0x90) * factor;
        outputBase = (void *)*(void * volatile *)((char *)arg0 + 0x294);
        inputBase = (void *)*(void * volatile *)((char *)arg0 + 0x294);
        fn_8017B3A8(inputBase, vecA, (char *)outputBase + 0x94, factor);
    }
case1: {
        float high = lbl_80562144;
        float low = lbl_80562140;
        float value = low;
        float result = -((low * *(float *)((char *)arg0 + 0x40)) +
                         (-high * *(float *)((char *)arg0 + 0x44)));
        slots[0] = high;
        slots[1] = low;
        value = result > value ? result : value;
        value = value > lbl_805621A4 ? lbl_805621A4 : value;
        fn_8018ADAC(*(void **)((char *)arg0 + 0x294), value);
        fn_8018ADD4(*(void **)((char *)arg0 + 0x294), -1);
        fn_8018ADBC(*(int *)((char *)arg0 + 0x294), lbl_80562144);
        fn_8018ADC4(*(int *)((char *)arg0 + 0x294), lbl_80562140);
        if ((float)__fabs(*(float *)((char *)arg0 + 0x270)) < lbl_80562160)
            fn_8018ADB4(*(int *)((char *)arg0 + 0x294), lbl_80562140);
        if (*(float *)((char *)arg0 + 0x270) < lbl_80562160) {
            fn_8018ADC4(*(int *)((char *)arg0 + 0x294), lbl_80562144);
            {
                void *object = *(void **)((char *)arg0 + 0x294);
                float factor = lbl_8056225C;
                vecB[0] = *(float *)((char *)object + 0x88) * factor;
                vecB[1] = *(float *)((char *)object + 0x8C) * factor;
                vecB[2] = *(float *)((char *)object + 0x90) * factor;
                fn_8017B3A8(object, vecB, (char *)object + 0x94, factor);
            }
        }
        goto done;
    }
transition:
    *(int *)((char *)arg0 + 0x210) = *(int *)((char *)arg0 + 0x214);
    *(int *)((char *)arg0 + 0x214) = 2;
done:
    ;
}

#pragma push
#pragma use_lmw_stmw off
void fn_80196C90(void *arg0) {
    extern float lbl_80562260;
    extern float lbl_8055E548, lbl_8055E54C;
    extern int __fpclassifyf(float);
    extern int __cntlzw(unsigned int);
    char *obj = (char *)arg0;
    int flag = 0;
    float f1;
    float f0;
    float f148;
    float f144;
    int r4;
    int r0;
    int r31;
    *(float *)(obj + 0x144) = *(float *)(obj + 0x144) * *(float *)(obj + 0x14C);
    if (*(unsigned char *)(obj + 0x9C) != 0 || *(unsigned char *)(obj + 0x74) != 0) {
        flag = 1;
    }
    if (flag != 0) {
        f1 = *(float *)(obj + 0x144);
        f0 = *(float *)(obj + 0xCC);
        r4 = *(int *)&f1;
        r0 = *(int *)&f0;
        if ((r4 & 0x80000000) == (r0 & 0x80000000)) {
            *(float *)(obj + 0x144) = f1 * lbl_80562260;
        }
    }
    f148 = __fabs(*(float *)(obj + 0x148));
    f144 = __fabs(*(float *)(obj + 0x144));
    if (f144 < f148) {
        float f31 = *(float *)(obj + 0x150);
        r31 = 0;
        if (__fpclassifyf(f31) != 1) {
            int r = __fpclassifyf(f31);
            if (((u32)__cntlzw((u32)r - 1) >> 5) != 0) {
                r31 = 1;
            } else {
                int x = r ^ 2;
                if (((x & r) - (x >> 1)) >> 31) {
                    r31 = 1;
                }
            }
        }
        if (r31 == 0) {
            *(float *)(obj + 0x150) = *(float *)(obj + 0x26C) + fn_80129DC4(3, lbl_8055E548, lbl_8055E54C);
        }
    }
    *(float *)(obj + 0x148) = *(float *)(obj + 0x144);
}

extern int fn_8019703C(void *, void *);
extern int fn_8019799C(void *, void *);
extern int fn_80197FE4(void *, void *);
extern int fn_80137788(void *, int, float *);
extern int fn_801377EC(void *, int, float *);
extern int lbl_802F9578[3];
void fn_80196DC4(void *arg0) {
    struct Cnt { int a, b, c; };
    struct Entry { u8 pad0[8]; u8 b8; u8 pad9[3]; int w0C; u8 b10; u8 pad11[3]; int w14; };
    struct Info { struct Entry *e; float f[4]; u8 b; int w; };
    struct Table { int count; int pad4[2]; int stride; char *base; };
    struct Local { struct Cnt cnt; struct Info info; } L;
    char *obj = (char *)arg0;
    float negx, x, u, v, w;
    int s, n, i;
    float zero;
    fn_80196C90(arg0);
    x = *(float *)(obj + 0x274);
    *(u8 *)(obj + 0x74) = 0;
    negx = -x;
    u = lbl_805621A0;
    v = lbl_805621AC;
    w = lbl_80562144;
    *(u8 *)(obj + 0x9C) = 0;
    *(u8 *)(obj + 0xFC) = 0;
    *(int *)(obj + 0x100) = 0;
    *(int *)(obj + 0x98) = 0;
    *(float *)(obj + 0x94) = u;
    *(int *)(obj + 0xC0) = 0;
    *(float *)(obj + 0xBC) = v;
    *(u8 *)(obj + 0x9C) = 0;
    *(u8 *)(obj + 0x74) = 0;
    *(float *)(obj + 0xC4) = negx;
    *(float *)(obj + 0xD0) = negx;
    *(float *)(obj + 0xC8) = x;
    *(float *)(obj + 0xD4) = x;
    *(u8 *)(obj + 0x11C) = 0;
    *(float *)(obj + 0x120) = w;
    ((void (*)(int, int, float, float, float, float))fn_80136EA4)(lbl_8055E0D0, *(int *)(obj + 0x290), v, u, x, negx);
    L.cnt = *(struct Cnt *)lbl_802F9578;
    zero = lbl_80562144;
    n = (*(struct Table **)&lbl_8055E0D0)->count - 1;
    for (i = 0; i < n; i++) {
        struct Table *t = *(struct Table **)&lbl_8055E0D0;
        struct Entry *e;
        s = *(int *)(obj + 0x290);
        e = *(struct Entry **)(((i + t->count * 2) * 4) + (t->base + s * t->stride) + 0x18);
        if (e == 0) break;
        if ((s == e->w0C ? e->b8 : e->b10) == 0) break;
        L.info.e = e;
        if (e != 0) {
            fn_80137788(e, s, &L.info.f[0]);
            fn_801377EC(e, s, &L.info.f[2]);
            L.info.b = (s == e->w0C) ? e->b8 : e->b10;
            L.info.w = (s == e->w0C) ? e->w14 : e->w0C;
        } else {
            L.info.f[0] = zero; L.info.f[1] = zero; L.info.f[2] = zero; L.info.f[3] = zero;
            L.info.b = 0; L.info.w = 0;
        }
        if (*(u8 *)L.info.e != 0) {
            if (L.cnt.a > 0 && fn_8019703C(arg0, &L.info) != 0) L.cnt.a--;
        } else {
            if (L.cnt.c > 0 && fn_80197FE4(arg0, &L.info) != 0) L.cnt.c--;
            if (L.cnt.b > 0 && fn_8019799C(arg0, &L.info) != 0) L.cnt.b--;
        }
    }
}

#pragma pop
int fn_8019700C(int index) {
    void *entry = lbl_804349C0[index];
    int result = 1;
    if (!entry)
        goto done;
    if (*((u8 *)entry + 0x2A4) == 0)
        goto done;
    result = 0;
done:
    return result;
}

extern float lbl_80562144, lbl_80562170, lbl_80562194, lbl_8055A488;
#pragma scheduling invalid_target
int fn_8019703C(void *arg0, void *arg1) {
    float xLimit;
    float x;
    float z;
    float y;
    float coefficient;
    float base;
    float absoluteY;
    float threshold;
    float score;
    unsigned int word6;
    unsigned int byte5;
    unsigned int word4, word3, word2, word1, word0;
    unsigned int positionWord;
    int update;
    int xValid;
    int yValid;
    int flags;

    x = *(float *)((char *)arg0 + 0x270);
    update = 0;
    xLimit = lbl_80562170;
    z = *(float *)((char *)arg1 + 8);
    xValid = x > xLimit;
    y = *(float *)((char *)arg1 + 4);
    coefficient = lbl_80562194;
    base = lbl_8055A488;
    absoluteY = (float)__fabs((double)y);
    threshold = base + coefficient * base;
    yValid = absoluteY < threshold;
    flags = *(unsigned int *)((char *)arg0 + 0x2D0);

    if ((flags & 1) == 0 && xValid != 0 && yValid != 0) {
        if (y > lbl_80562144) {
            score = *(float *)((char *)arg0 + 0x278) + y;
            if (score < *(float *)((char *)arg0 + 0xBC)) {
                word0 = *(unsigned int *)((char *)arg1 + 0);
                word1 = *(unsigned int *)((char *)arg1 + 4);
                word2 = *(unsigned int *)((char *)arg1 + 8);
                word3 = *(unsigned int *)((char *)arg1 + 0xC);
                word4 = *(unsigned int *)((char *)arg1 + 0x10);
                byte5 = *(unsigned char *)((char *)arg1 + 0x14);
                word6 = *(unsigned int *)((char *)arg1 + 0x18);
                *(float *)((char *)arg0 + 0xBC) = score;
                *(unsigned int *)((char *)arg0 + 0xA0) = word0;
                *(unsigned int *)((char *)arg0 + 0xA4) = word1;
                *(unsigned int *)((char *)arg0 + 0xA8) = word2;
                *(unsigned int *)((char *)arg0 + 0xAC) = word3;
                *(unsigned int *)((char *)arg0 + 0xB0) = word4;
                *(unsigned char *)((char *)arg0 + 0xB4) = byte5;
                *(unsigned int *)((char *)arg0 + 0xB8) = word6;
                *(unsigned char *)((char *)arg0 + 0x9C) = 1;
                update = 1;
            }
        } else {
            score = *(float *)((char *)arg0 + 0x278) + y;
            if (score > *(float *)((char *)arg0 + 0x94)) {
                word6 = *(unsigned int *)((char *)arg1 + 0);
                byte5 = *(unsigned int *)((char *)arg1 + 4);
                word4 = *(unsigned int *)((char *)arg1 + 8);
                word3 = *(unsigned int *)((char *)arg1 + 0xC);
                word2 = *(unsigned int *)((char *)arg1 + 0x10);
                word1 = *(unsigned char *)((char *)arg1 + 0x14);
                word0 = *(unsigned int *)((char *)arg1 + 0x18);
                *(float *)((char *)arg0 + 0x94) = score;
                *(unsigned int *)((char *)arg0 + 0x78) = word6;
                *(unsigned int *)((char *)arg0 + 0x7C) = byte5;
                *(unsigned int *)((char *)arg0 + 0x80) = word4;
                *(unsigned int *)((char *)arg0 + 0x84) = word3;
                *(unsigned int *)((char *)arg0 + 0x88) = word2;
                *(unsigned char *)((char *)arg0 + 0x8C) = word1;
                *(unsigned int *)((char *)arg0 + 0x90) = word0;
                *(unsigned char *)((char *)arg0 + 0x74) = 1;
                update = 1;
            }
        }
    }
    if (update) {
        positionWord = *(unsigned int *)((char *)arg1 + 0x18);
        *(float *)((char *)arg0 + 0xCC) = y;
        *(float *)((char *)arg0 + 0xD8) = z;
        *(unsigned int *)((char *)arg0 + 0xDC) = positionWord;
    }
    if (y > lbl_80562144)
        ++*(int *)((char *)arg0 + 0xC0);
    else
        ++*(int *)((char *)arg0 + 0x98);
    return 0;
}
#pragma scheduling on
void fn_801971AC(void *arg0, void *arg1) {
    extern float lbl_80562264;
    float sp18[2];
    double sp10;
    float sp8[2];
    float factor;
    float speed;
    float old0;
    float old1;
    register float result0;
    register float result1;
    float *point;
    char *base;
    point = (float *)arg1;
    base = (char *)arg0;
    if (*(int *)(base + 0x260) == 0) return;
    if (*(int *)(base + 0x268) == 1) return;
    speed = *(float *)(base + 0x264);
    factor = *(float *)(base + 0x25C) + lbl_80562264;
    *(float *)(base + 0x25C) = factor;
    sp18[0] = *(float *)(base + 0x48) + (*(float *)(base + 0x58) * speed);
    old0 = point[0];
    sp18[1] = *(float *)(base + 0x4C) + (*(float *)(base + 0x5C) * speed);
    old1 = point[1];
    result1 = old1 + (factor * (sp18[1] - old1));
    result0 = old0 + (factor * (sp18[0] - old0));
    sp8[0] = result0;
    sp8[1] = result1;
    sp10 = *(double *)sp8;
    point[0] = *(float *)&sp10;
    point[1] = *((float *)&sp10 + 1);
}

extern int fn_801671AC(int);
extern int fn_8015FBCC(void *, float *, int, int, float, float);
extern float fn_801973FC(float *, float *, void *);
extern float lbl_80562160, lbl_8056222C, lbl_80562268, lbl_8056226C;
#pragma processor 750
void fn_8019724C(void *arg0, float *arg1) {
    float projected[2];
    float direction[2];
    float norm;
    float length;
    float scale;
    float current;
    float upper;
    float lower;
    float diff;
    float weight;
    float factor;
    float flagThreshold;
    int index;
    void *obj;

    if (*(float *)((char *)arg0 + 0x270) > lbl_80562160) {
        index = fn_801671AC(*(int *)((char *)arg0 + 0x290));
        obj = *(void **)((char *)arg0 + 0x294);
        direction[0] = *(float *)((char *)obj + 0x70);
        direction[1] = *(float *)((char *)obj + 0x78);
        norm = (float)fn_8002F234(direction[0] * direction[0] + direction[1] * direction[1]);
        length = lbl_80562148;
        if (length > norm) {
            length = lbl_80562148;
        } else {
            length = norm;
        }
        scale = lbl_80562140 / length;
        direction[0] = direction[0] * scale;
        direction[1] = direction[1] * scale;
        if (((int (*)(void *, float *, int, int))fn_8015FBCC)(*(void **)((char *)arg0 + 0x294), projected, 0, index)) {
            current = *(float *)((char *)arg0 + 0x26C);
            upper = lbl_8056226C + *(float *)((char *)arg0 + 0x1F8);
            lower = current - lbl_80562268;
            current = current < upper ? current : upper;
            current = current > lower ? current : lower;
            *(float *)((char *)arg0 + 0x1F8) = current;
            *(float *)((char *)arg0 + 0x20C) = fn_801973FC(direction, projected, arg1);
            flagThreshold = *(volatile float *)&lbl_8056222C;
            arg1[0] = projected[0];
            arg1[1] = projected[1];
            if (flagThreshold < *(float *)((char *)arg0 + 0x270)) {
                *(volatile int *)((char *)arg0 + 0x2D0) |= 0x40;
                *(volatile int *)((char *)arg0 + 0x2D0) |= 0x800;
            }
        } else {
            diff = *(float *)((char *)arg0 + 0x26C) - *(float *)((char *)arg0 + 0x1F8);
            if (diff < lbl_80562268) {
                weight = lbl_80562140 - diff / lbl_80562268;
                factor = *(float *)((char *)arg0 + 0x20C) * weight;
                arg1[0] = arg1[0] + direction[0] * factor;
                arg1[1] = arg1[1] + direction[1] * factor;
            }
        }
    }
}

float fn_801973FC(float *arg0, float *arg1, void *arg2) {
    float spC;
    float sp8;
    float temp_f2;
    float temp_f3;

    temp_f3 = arg1[0] - *(float *)((char *)arg2 + 0);
    temp_f2 = arg1[1] - *(float *)((char *)arg2 + 4);
    sp8 = temp_f3;
    spC = temp_f2;
    return (arg0[0] * temp_f3) + (arg0[1] * temp_f2);
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
extern float lbl_80562270,lbl_80562274,lbl_80562278;
extern void fn_80198488(void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_8019743C(void *p, void *arg1) {
    float *out = (float *)arg1;
    float diff=lbl_80562144, scale, limit, f, t, v, x, y;
    int decay=1, index,bits,mode,failed,selected,active=0;
    unsigned char *side;
    if(((u8 *)p)[0x9c] || ((u8 *)p)[0x74]) active=1;
    if(active) {
        fn_80198488(p);
        if(((u8 *)p)[0x74]) {
            { float a=*(float *)((u8 *)p+0x84); float m=lbl_8056215C*a; float pos=*(float *)((u8 *)p+0x7c)+m; float margin=lbl_805621DC+lbl_8055A488; limit=margin+(*(float *)((u8 *)p+0x278)+pos); }
            f=*(float *)((u8 *)p+0xc4);
            f = f>limit ? f : limit;
            *(float *)((u8 *)p+0xc4)=f;
        }
        if(((u8 *)p)[0x9c]) {
            { float a=*(float *)((u8 *)p+0xac); float m=lbl_8056215C*a; float pos=*(float *)((u8 *)p+0xa4)+m; float margin=lbl_805621DC+lbl_8055A488; limit=(*(float *)((u8 *)p+0x278)+pos)-margin; }
            f=*(float *)((u8 *)p+0xc8);
            f = f<limit ? f : limit;
            *(float *)((u8 *)p+0xc8)=f;
        }
        t=*(float *)((u8 *)p+0xe8);
        if(t>lbl_80562144) {
            limit=*(float *)((u8 *)p+0x278)+t; f=*(float *)((u8 *)p+0xc4);
            f = f>limit ? f : limit;
            *(float *)((u8 *)p+0xc4)=f;
        } else if(t<lbl_80562144) {
            limit=*(float *)((u8 *)p+0x278)+t; f=*(float *)((u8 *)p+0xc8);
            f = f<limit ? f : limit;
            *(float *)((u8 *)p+0xc8)=f;
        }
        failed=0; side=0;
        scale=lbl_80562174;
        if(*(float *)((u8 *)p+0xc8)<*(float *)((u8 *)p+0xc4)) {
            if(((u8 *)p)[0x74] && ((u8 *)p)[0x9c]) {
                index=*(int *)((u8 *)p+0x90);
                bits=(unsigned char)fn_80193110(p,*(int *)((u8 *)p+0xb8));
                bits|=((unsigned char)fn_80193110(p,index))<<1;
                if(bits && bits!=3) {
                    selected=(bits>>1)&1;
                    if(selected) side=(u8 *)p+0xa0; else side=(u8 *)p+0x78;
                    index=*(int *)(side+0x18);
                    mode=((int (*)(void *, int))fn_801930DC)(p,index);
                    failed=((int (*)(void *, int, int))fn_8019309C)(p,index,mode)==0;
                } else {
                    if((bits&2) && ((int (*)(void *, int))fn_801930DC)(p,*(int *)((u8 *)p+0x90))) { selected=1; mode=1; }
                    else if((bits&1) && ((int (*)(void *, int))fn_801930DC)(p,*(int *)((u8 *)p+0xb8))) {selected=0; mode=1;}
                    else {selected=1;mode=0;}
                    if(selected) side=(u8 *)p+0xa0; else side=(u8 *)p+0x78;
                    failed=((int (*)(void *, int, int))fn_8019309C)(p,*(int *)(side+0x18),mode)==0;
                }
            } else {
                selected=!((u8 *)p)[0x74];
                if(((u8 *)p)[0x74]) side=(u8 *)p+0x78; else side=(u8 *)p+0xa0;
                failed=((int (*)(void *, int, int))fn_8019309C)(p,*(int *)(side+0x18),1)==0;
            }
            if(selected) *(float *)((u8 *)p+0xc8)=*(float *)((u8 *)p+0xc4);
            else *(float *)((u8 *)p+0xc4)=*(float *)((u8 *)p+0xc8);
        } else {
            if(((u8 *)p)[0x74] && (unsigned char)fn_80193110(p,*(int *)((u8 *)p+0x90))) scale*=lbl_80562174;
            if(((u8 *)p)[0x9c] && fn_80193110(p,*(int *)((u8 *)p+0xb8))) scale*=lbl_80562174;
        }
        if(failed) { t=*(float *)(side+8); if(((u8 *)p)[0x2fd] || t<lbl_805621DC) *(int *)((u8 *)p+0x2d0)|=0x40; }
        t=*(float *)((u8 *)p+0x278)+lbl_8056215C**(float *)((u8 *)p+0x27c);
        f=*(float *)((u8 *)p+0xc4);
        if(t<f) diff=f-t;
        else { f=*(float *)((u8 *)p+0xc8); if(t>f) diff=f-t; }
        if((float)__fabs(diff)>lbl_80562148) {
            if(fn_8019700C(*(int *)((u8 *)p+0xdc))) {
                *(int *)((u8 *)p+0x2d0)|=0x40;
                out[2]-=lbl_80562170;
            }
            *(float *)((u8 *)p+0xe4)=*(float *)((u8 *)p+0x278)+diff;
            *(float *)((u8 *)p+0xe8)=lbl_80562144;
            t=(float)__fabs(diff)/lbl_805621DC;
            f=lbl_80562140; f=f<t?f:t;
            f=f>lbl_80562144?f:lbl_80562144;
            v=*(float *)((u8 *)p+0xe0);
            if(v<f) {t=lbl_80562140-lbl_80562148*scale; *(float *)((u8 *)p+0xe0)=f+t*t*(v-f);}
            else *(float *)((u8 *)p+0xe0)=f+lbl_80562270*(v-f);
            decay=0;
        } else *(float *)((u8 *)p+0xe8)=lbl_80562144;
    } else *(float *)((u8 *)p+0xe8)=lbl_80562144;
    if(*(float *)((u8 *)p+0xe0)>lbl_80562274) {
        f=*(float *)((u8 *)p+0xe4);
        ((u8 *)p)[0x250]=1;
        x=*(float *)((u8 *)p+0x48)+*(float *)((u8 *)p+0x58)*f;
        y=*(float *)((u8 *)p+0x4c)+*(float *)((u8 *)p+0x5c)*f;
        t=*(float *)((u8 *)p+0xe0);
        out[0]+=t*(x-out[0]);
        out[1]+=t*(y-out[1]);
    }
    if(decay) *(float *)((u8 *)p+0xe0)*=lbl_80562278;
}
#pragma pop

#pragma processor reset
int fn_8019799C(void *arg0, void *arg1) {
    int id;
    int result = 0;
    int valid;
    int allow;
    double absolute;
    float angle;
    float distance;
    float bound;
    float limit;
    extern float lbl_80562160, lbl_80562170, lbl_80562184;
    extern float fn_80137850(void *);
    extern double __fabs(double);
    extern void fn_80197AB8(void *, int, float, float, float);

    if (*(int *)((char *)arg0 + 0x2D0) & 2) return 0;
    allow = 1;
    angle = -*(float *)((char *)arg1 + 0x10);
    id = *(int *)((char *)arg1 + 0x18);
    if (!(angle > lbl_80562160)) {
        valid = 0;
        if (id == *(int *)((char *)arg0 + 0x114) && angle > lbl_80562170)
            valid = 1;
        if (!valid) allow = 0;
    }
    if (allow && id != *(int *)((char *)arg0 + 0x2C4)) {
        angle = fn_80137850(arg1);
        absolute = __fabs((double)angle);
        bound = *(float *)((char *)arg0 + 0x278) + *(float *)((char *)arg1 + 4);
        distance = (float)absolute;
        limit = lbl_80562184 + *(float *)((char *)arg0 + 0x274);
        distance = distance < bound ? distance : bound;
        if (distance < limit) {
            fn_80197AB8(arg0, id, *(float *)((char *)(*(void **)arg1) + 4), angle,
                *(float *)((char *)arg1 + 0x10));
            result = 1;
        }
    }
    return result;
}

typedef struct Obj Obj;
extern void *fn_8017960C(int);
extern Obj *fn_801B2ED0(int);
extern float lbl_80562194;
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80197AB8(void *arg0, int arg1, float farg0, float farg1, float farg2) {
    class VObj {
    public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
        virtual void *call();
    };
    unsigned char *p = (unsigned char *)arg0;
    float vals[2];
    float rate;
    float motion;
    float field3C;
    float field38;
    float term1;
    float term2;
    float height;
    float sum;
    float output;
    int update;
    void *obj;
    void *result;
    *(int *)(p + 0x100) += 1;
    update = 1;
    if (p[0xFC] != 0)
        update = *(float *)(p + 0xEC) > farg0;
    if (update) {
        *(float *)(p + 0xEC) = farg0;
        obj = fn_8017960C(arg1);
        vals[0] = *(float *)((char *)obj + 0x88);
        vals[1] = *(float *)((char *)obj + 0x90);
        obj = fn_801B2ED0(arg1);
        result = ((VObj *)obj)->call();
        if (result) {
            p[0xFC] = 1;
            rate = *(float *)(p + 0x27C);
            motion = rate * farg0;
            field3C = *(float *)((char *)result + 0x3C);
            field38 = *(float *)((char *)result + 0x38);
            term1 = field3C * vals[1];
            term2 = field38 * vals[0];
            height = *(float *)(p + 0x278) + motion;
            sum = term2 + term1;
            *(float *)(p + 0xF8) = farg1;
            *(int *)(p + 0x114) = arg1;
            output = lbl_80562194 * sum;
            *(float *)(p + 0x108) = height;
            *(float *)(p + 0x110) = farg2;
            *(float *)(p + 0x104) = output;
        }
    }
}
#pragma cplusplus reset
#pragma scheduling on
extern float lbl_8055A48C, lbl_80562194, lbl_8056227C, lbl_80562280, lbl_80562140, lbl_80562144, lbl_805621A4, lbl_8056215C, lbl_80562284, lbl_80562288, lbl_80562268, lbl_80562274, lbl_8056228C;
extern void fn_8019315C(void *, int);
extern int fn_8019309C(void *, int, signed char);
void fn_80197BD0(void *arg0, void *arg1) {
 void *a0,*a1; float f31=lbl_8055A488,f30,f5,f6,f4,f3,f2,f1; int done,i,special; void *p;
 a0=arg0; a1=arg1; done=1;
 f30=lbl_80562194*lbl_8055A48C;
 if (*(u8*)((char*)a0+0xfc)) {
  if (*(float*)((char*)a0+0xec)<lbl_8056227C || *(int*)((char*)a0+0x100)>1) {
   fn_8019315C(a0,*(int*)((char*)a0+0x114)); i=*(int*)((char*)a0+0x114); p=lbl_804349C0[i];
   f5=f31+__fabs(*(float*)((char*)a0+0x104))*(f30-f31);
   special=p && *(int*)((char*)a0+0x290)==*(int*)((char*)p+0x114);
   f4=*(float*)((char*)a0+0xf8); f6=f4-*(float*)((char*)a0+0x108);
   if (__HI(f4)!=__HI(f6)&&!special) f6=f4>lbl_80562144?lbl_80562140:lbl_805621A4;
   if (*(int*)((char*)a0+0x114)!=*(int*)((char*)a0+0x118)||*(float*)((char*)a0+0xec)>lbl_80562194) {
    *(float*)((char*)a0+0x10c)=f6; f3=__fabs(f6); f30=lbl_80562284+lbl_8056215C*(f5+f31);
    if (f3<f30) {
     if ((*(u8*)((char*)a0+0x9c)||*(u8*)((char*)a0+0x74))&&__HI(f6)!=__HI(*(float*)((char*)a0+0xcc))) fn_8019309C(a0,*(int*)((char*)a0+0xdc),0);
     f1=*(float*)((char*)a0+0x10c)>lbl_80562144?lbl_80562140:lbl_805621A4;
     f2=( *(float*)((char*)a0+0x54)-lbl_80562144)/(*(float*)((char*)a0+0xec)-lbl_80562144); if(f2>lbl_80562140) f2=lbl_80562140; if(f2<lbl_80562144) f2=lbl_80562144;
     f3=*(float*)((char*)a0+0x278); f4=(*(float*)((char*)a0+0xec)-lbl_8056227C)/lbl_80562288;
     *(float*)((char*)a0+0xf4)=f3+f2*(*(float*)((char*)a0+0xf8)-f30*f1-f3);
     if(f4>lbl_80562140) f4=lbl_80562140; if(f4<lbl_80562144) f4=lbl_80562144;
     f2=f4*lbl_80562140; f3=*(float*)((char*)a0+0xf0); f1=lbl_80562144+f2-f3; *(float*)((char*)a0+0xf0)=f3+lbl_8056215C*f1;
     if(!fn_80193184(a0,*(int*)((char*)a0+0x114))) { f4=*(float*)((char*)a1+8); f3=*(float*)((char*)a0+0x270)+*(float*)((char*)a0+0x110); *(float*)((char*)a1+8)=f4+*(float*)((char*)a0+0xf0)*(f3+lbl_80562268/(*(int*)((char*)a0+0x100))*(f4-f3)-f4); }
     done=0;
    }
   }
  }
 } else { *(int*)((char*)a0+0x114)=-1; *(int*)((char*)a0+0x118)=-1; }
 f4=*(float*)((char*)a0+0xf0);
 if(f4>lbl_80562274) { f5=*(float*)((char*)a0+0xf4); *(u8*)((char*)a0+0x250)=1; f3=*(float*)((char*)a0+0x48)+*(float*)((char*)a0+0x58)*f5; f2=*(float*)((char*)a0+0x4c)+*(float*)((char*)a0+0x5c)*f5; f1=*(float*)a1; f6=*(float*)((char*)a1+4); *(float*)a1=f1+f4*(f3-f1); *(float*)((char*)a1+4)=f6+f4*(f2-f6); }
 if(done) *(float*)((char*)a0+0xf0)*=lbl_8056228C;
}

extern float lbl_80562184, lbl_80562290, lbl_80562294;
extern float lbl_8055A48C;
extern void fn_8019813C(void *, void *, float, float);
#pragma scheduling invalid_target
int fn_80197FE4(void *arg0, void *arg1) {
    int special;
    int mode;
    int between;
    int x_ok;
    int in_range;
    int angle_ok;
    int allowed;
    int result = 0;
    float z_limit;
    float upper;
    float speed;
    float projected_x;
    float projected_z;
    float lower;
    void *entry;
    extern float lbl_8055A48C, lbl_8055A488;
    extern float lbl_80562184, lbl_8056215C, lbl_80562140;
    extern float lbl_80562290, lbl_80562294;
    extern void *lbl_804349C0[];

    if (!(*(int *)((char *)arg0 + 0x2D0) & 4)) {
        special = 1;
        z_limit = lbl_80562290 * lbl_8055A488;
        upper = lbl_8055A48C + lbl_80562184 * lbl_8055A48C;
        mode = *(int *)((char *)arg0 + 0x268);
        if (mode != 0 && mode != 3)
            special = 0;
        if (special)
            speed = lbl_8056215C;
        else
            speed = lbl_80562140;
        *(float *)((char *)arg0 + 0x134) = speed;

        projected_x = speed * *(float *)((char *)arg1 + 0x10);
        projected_x += *(float *)((char *)arg1 + 8);
        projected_z = speed * *(float *)((char *)arg1 + 0x0C);
        projected_z += *(float *)((char *)arg1 + 4);
        x_ok = *(float *)((char *)arg1 + 8) < lbl_8056215C * lbl_8055A48C;
        in_range = 0;
        between = 0;
        if (projected_x < upper) {
            lower = lbl_80562294 * lbl_8055A48C;
            if (projected_x > lower)
                between = 1;
        }
        if (between && x_ok)
            in_range = 1;
        angle_ok = (float)__fabs((double)projected_z) < z_limit;

        entry = lbl_804349C0[*(int *)((char *)arg1 + 0x18)];
        allowed = 1;
        if (entry && *((unsigned char *)entry + 0x2A5))
            allowed = 0;
        if (allowed && in_range && angle_ok) {
            fn_8019813C(arg0, arg1, *(float *)((char *)arg1 + 8), projected_x);
            result = 1;
        }
    }
    return result;
}
#pragma scheduling on
void fn_8019813C(void *arg0, void *arg1, float arg2, float arg3) {
    int should_update = 1;
    float event_time;
    float value;
    float adjustment;
    float weight;
    int index;

    if (*((u8 *)arg0 + 0x11C) != 0 && arg2 > *((float *)((char *)arg0 + 0x124))) {
        should_update = 0;
    }
    if (should_update == 0) {
        return;
    }
    event_time = *((float *)((char *)arg1 + 0x10));
    weight = *((volatile float *)((char *)arg1 + 4));
    value = *((float *)((char *)arg0 + 0x270)) + event_time;
    adjustment = *((volatile float *)&lbl_805621E4);
    index = *((int *)((char *)arg1 + 0x18));

    *((u8 *)arg0 + 0x11C) = 1;
    *((float *)((char *)arg0 + 0x128)) = arg3;
    *((float *)((char *)arg0 + 0x124)) = arg2;
    *((float *)((char *)arg0 + 0x12C)) = weight;
    *((float *)((char *)arg0 + 0x130)) = value - adjustment;
    *((int *)((char *)arg0 + 0x138)) = index;
}

extern float lbl_80562298, lbl_8056229C, lbl_805622A0, lbl_805622A4, lbl_8056227C, lbl_8056221C;
void fn_801981A0(void *arg0, void *arg1) {
#define o ((char *)arg0)
#define p ((char *)arg1)
    float c, temp_f3, var_f4, var_f5, temp_f6, temp_f7, temp_f2, temp_f0, temp_f0_2, temp_f0_3, temp_f1, temp_f4;
    float var_f0, var_f1, var_f5_2;
    int temp_r5, var_r0, var_r4;

    temp_r5 = *(int *)(o + 0x140);
    if (temp_r5 > 0) {
        *(int *)(o + 0x140) = temp_r5 - 1;
    }
    if (*(u8 *)(o + 0x11C) != 0) {
        if (*(int *)(o + 0x138) != *(int *)(o + 0x13C)) {
            *(float *)(o + 0x14C) = fn_80129DC4(3, lbl_8055E55C, lbl_8055E560);
            *(int *)(o + 0x13C) = *(int *)(o + 0x138);
        }
        var_r4 = 1;
        c = lbl_8055A48C;
        temp_f6 = c + (lbl_80562298 * *(float *)(o + 0x2EC) * c);
        if (*(u8 *)(o + 0xFC) != 0 && *(int *)(o + 0x114) == *(int *)(o + 0x138)) {
            var_r4 = 0;
        }
        if (*(int *)(o + 0x138) != *(int *)(o + 0x2C4) && var_r4 != 0 &&
            (float)__fabs(*(float *)(o + 0x12C)) < lbl_8055E570 * lbl_8055A488) {
            var_f4 = lbl_80562140;
            temp_f7 = *(float *)(p + 8);
            temp_f3 = *(float *)(o + 0x130);
            temp_f0 = (*(float *)(o + 0x128) - c) / (temp_f6 - c);
            var_f4 = (var_f4 < temp_f0) ? var_f4 : temp_f0;
            var_f4 = (var_f4 > lbl_80562144) ? var_f4 : lbl_80562144;
            var_f5 = lbl_80562140;
            temp_f3 = temp_f3 + var_f4 * (temp_f7 - temp_f3);
            *(float *)(p + 8) = temp_f3;
            *(float *)(o + 0x120) = temp_f3;
            temp_f2 = *(float *)(o + 0x134);
            temp_f3 = *(float *)(p + 0xC);
            temp_f0_2 = (*(float *)(o + 0x128) - c) / (temp_f6 - c);
            var_f5 = (var_f5 < temp_f0_2) ? var_f5 : temp_f0_2;
            var_f5 = (var_f5 > lbl_80562144) ? var_f5 : lbl_80562144;
            *(float *)(p + 0xC) = temp_f2 + var_f5 * (temp_f3 - temp_f2);
            if (*(u8 *)(o + 0x9C) != 0) {
                *(int *)(o + 0x140) = 0x1E;
            }
            if (*(int *)(o + 0x140) == 0 && *(int *)(o + 0x268) != 3) {
                var_f5_2 = lbl_8056217C - lbl_80562140;
                temp_f0_3 = (var_f5_2 * ((temp_f7 - *(float *)(o + 0x130)) - lbl_8056229C)) / lbl_805622A0;
                temp_f4 = lbl_8056227C * lbl_8055A488 * lbl_8055E564;
                var_f5_2 = (var_f5_2 < temp_f0_3) ? var_f5_2 : temp_f0_3;
                var_f5_2 = (var_f5_2 > lbl_80562144) ? var_f5_2 : lbl_80562144;
                temp_f1 = *(float *)(o + 0x150);
                var_r0 = 0;
                if (temp_f1 < lbl_80562144 || *(float *)(o + 0x26C) > temp_f1) {
                    var_r0 = 1;
                }
                if (var_r0 != 0) {
                    *(float *)(o + 0x150) = lbl_805621A4;
                    var_f1 = (*(int *)(o + 0x18) == 1) ? lbl_805621A4 : lbl_80562140;
                    var_f0 = ((*(float *)(o + 0x12C) - (lbl_8056221C * (lbl_80562174 * var_f1))) > lbl_80562144) ? lbl_80562140 : lbl_805621A4;
                    var_f1 = *(float *)(o + 0x144) + (lbl_805622A4 * (lbl_80562140 + var_f5_2) * -var_f0);
                    var_f1 = (temp_f4 < var_f1) ? temp_f4 : var_f1;
                    temp_f0_3 = -temp_f4;
                    var_f1 = (var_f1 > temp_f0_3) ? var_f1 : temp_f0_3;
                    *(float *)(o + 0x144) = var_f1;
                }
            }
        }
    }
    *(u8 *)(o + 0x154) = 0;
#undef o
#undef p
}

#pragma scheduling on
void fn_80198488(void *arg0) {
    int temp_r0;
    int var_r4;
    int var_r4_2;
    unsigned char temp_r5, temp_r6;
    volatile unsigned char *p74 = (volatile unsigned char *)arg0 + 0x74;
    volatile unsigned char *p9c = (volatile unsigned char *)arg0 + 0x9C;
    temp_r6 = *p9c;
    temp_r5 = *p74;
    if ((int)(temp_r5 + temp_r6 + 1) > (int)*(float *)((char *)arg0 + 0x2F4)) {
        temp_r0 = *(int *)((char *)arg0 + 0x18) == 0;
        if ((temp_r0 != 0) && ((int)temp_r5 != 0)) {
            if ((int)*p74 != 0) var_r4 = *(int *)((char *)arg0 + 0x90);
            else var_r4 = -1;
            ((void (*)(void *, int))fn_80193138)(arg0, var_r4);
            return;
        }
        if ((temp_r0 == 0) && ((int)temp_r6 != 0)) {
            if ((int)*p9c != 0) var_r4_2 = *(int *)((char *)arg0 + 0xB8);
            else var_r4_2 = -1;
            ((void (*)(void *, int))fn_80193138)(arg0, var_r4_2);
        }
    }
}

void fn_80198530(void *arg0) {
    float a = lbl_80562140;
    float b = lbl_80562144;
    (void)a; (void)b;
    fn_801961FC(arg0);
}

#pragma dont_inline reset
void *fn_80198DD0(void *arg0, int arg1) {
    struct Table {
        void *items[8];
        int count;
    } *table;
    void **scan;
    unsigned char i;
    int loopCount;
    int count;
    if (arg0 != 0) {
        *(void **)arg0 = &lbl_80333390;
        table = (struct Table *)lbl_804349E0;
        scan = table->items;
        i = 0;
        loopCount = table->count;
        for (; loopCount > 0; loopCount--) {
            if (*scan == arg0) {
                count = table->count - 1;
                table->count = count;
                table->items[i] = table->items[count];
            } else {
                scan++;
                i++;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_80198E7C(int index) {
    void *entry = lbl_804349C0[index];
    if (*((u8 *)entry + 0x2A4) != 0)
        fn_801964D0(entry);
}
#pragma dont_inline reset

  void fn_80198E7C(int index);
    void fn_80198EA0(int index) {
        fn_80198E7C(index);
    }

  
    typedef unsigned char u8;
    extern void *lbl_804349C0[];
    extern void *lbl_804349E0[];
      void fn_801964D0(void *);
  void fn_80128668(void *);
  void fn_80193138(int);
    void fn_801964D0(void *);
    void fn_80128668(void *);
  void fn_80193138(int);
  extern float fn_801671FC(int);
  extern int fn_801B89F8(void);
  extern int lbl_8055E0D0;
  extern void fn_8018ADBC(int, float);
  extern void fn_8018ADB4(int, float);
  extern void fn_8018AE24(int, int);
  extern void fn_80136EA4(int, int);
  extern void fn_80136E8C(int, int, int);
  int fn_80198EA4(void) { return 0; }
extern void fn_801958D8(void);
extern void fn_80195F6C(void *, void *);
extern void fn_80194624(void *);
extern void fn_80195654(void *, void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204;
#pragma cplusplus on
struct Dummy_8019684C {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17();
};
#pragma cplusplus reset
