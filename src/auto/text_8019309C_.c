// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

          extern void fn_801958D8(void);
      extern void fn_801945F8(void *);
      extern void fn_80196DC4(void *);
    extern void fn_80195F6C(void *, void *);
    extern void fn_80194624(void *);
    extern void fn_80195654(void *);
    extern void fn_801933FC(void *, void *);
    extern double fn_8002F234(float);
    extern float lbl_8055E584, lbl_8055E588;
    extern float fn_80129DC4(int, float, float);
    extern void fn_8013530C(void *, int);
    extern int lbl_8055E550;
    extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204, lbl_805621E4;

      extern void fn_80194FD0(void);
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
#pragma cplusplus reset
typedef unsigned char u8;
extern void *lbl_804349C0[];
extern float lbl_8056223C, lbl_8055E57C;
extern int lbl_804348E8[];
extern void *lbl_804349E0[];
extern char lbl_80333390[0x10000];
  void fn_801964D0();
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
    float x = *(float *)((char *)arg2 + 0x18);
    float y = *(float *)((char *)arg2 + 0x20);
    float length = (float)fn_8002F234(x * x + y * y);
    float scale;
    float dx, dy, neg;
    float ox, oy;
    float a = *(float *)((char *)arg2 + 0x24);
    float b = *(float *)((char *)arg2 + 0x2C);
    float c = *(float *)arg1;
    float d = *(float *)((char *)arg1 + 4);
    if (lbl_80562148 > length) length = lbl_80562148;
    scale = lbl_80562140 / length;
    dx = x * scale;
    dy = y * scale;
    neg = -dx;
    ox = dy * c + dx * d + a;
    oy = neg * c + dy * d + b;
    *(float *)arg0 = ox;
    *(float *)((char *)arg0 + 4) = oy;
}
#pragma processor gekko
extern float lbl_80562140, lbl_80562148;
#pragma dont_inline on
void fn_8019330C(void *out, void *in, int arg2) {
    volatile float x = *(float *)((char *)arg2 + 0x18);
    volatile float y = *(float *)((char *)arg2 + 0x20);
    float length = (float)fn_8002F234(x * x + y * y);
    float scale;
    float sx, sy, dx, dy;
    if (lbl_80562148 > length) {
    } else {
        length = lbl_80562148;
    }
    scale = lbl_80562140 / length;
    sx = x * scale;
    sy = y * scale;
    dx = *(float *)in - *(float *)((char *)arg2 + 0x24);
    dy = *(float *)((char *)in + 4) - *(float *)((char *)arg2 + 0x2C);
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

void fn_80193604(void *arg0, void *arg1, int arg2, void *arg3) {
    extern float PSVECDotProduct(const void *, const void *);
    extern float PSVECMag(const void *);
    extern float lbl_80562140, lbl_80562144, lbl_80562148, lbl_8056215C;
    extern float lbl_80562160, lbl_80562164, lbl_80562168, lbl_8056216C;
    extern float lbl_80562170, lbl_80562174;
    char *obj = (char *)arg0, *vec = (char *)arg1, *other = (char *)arg3;
    float value, scale, x, y, z;
    if (other != 0) {
        if (*(unsigned int *)(other + 0x10) == 0x50434152) {
            char *vehicle = *(char **)(obj + 0x294);
            x = *(float *)(other + 0x60) - *(float *)(vehicle + 0x60);
            y = *(float *)(other + 0x64) - *(float *)(vehicle + 0x64);
            z = *(float *)(other + 0x68) - *(float *)(vehicle + 0x68);
            if (PSVECDotProduct(&x, vehicle + 0x54) > lbl_80562144) {
                value = PSVECDotProduct(other + 0x118, other + 0x54);
                if (value > lbl_80562160 && __fabsf(PSVECDotProduct(other + 0x118, other + 0x3C) / value) > lbl_80562164)
                    *(float *)(obj + 0x2A8) += lbl_80562168;
            }
        }
        if ((*(unsigned int *)(other + 0x10) == 0x41434152 || *(unsigned int *)(other + 0x10) == 0x50434152) &&
            fn_80193524(*(void **)(obj + 0x294), other))
            *(float *)(obj + 0x2A8) += lbl_80562168;
    }
    if (arg2 < 0x3E8 && PSVECDotProduct(vec, *(char **)(obj + 0x294) + 0x88) < lbl_80562144) {
        x = *(float *)(vec + 0); y = *(float *)(vec + 4); z = *(float *)(vec + 8);
        value = PSVECMag(&x);
        scale = lbl_80562148;
        if (scale <= value) scale = value;
        scale = lbl_80562140 / scale;
        x *= scale; y *= scale; z *= scale;
        if (__fabsf(PSVECDotProduct(&x, *(char **)(obj + 0x294) + 0x88)) > lbl_8056215C) {
            value = *(float *)(obj + 0x270);
            if (value < lbl_8056216C && (arg2 != 0x6D || value < lbl_80562170) &&
                (*(int *)(obj + 0x268) != 1 || arg2 != 0x6D))
                *(float *)(obj + 0x2A0) += lbl_80562174;
        }
    }
    if (arg2 == 0x3EA) *(float *)(obj + 0x2A0) += lbl_80562174;
    if (arg2 == 0x6D) *(u8 *)(obj + 0x2FE) = 0;
}

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
#pragma cplusplus off
extern int fn_801769A8(void);
void fn_80193D30(void *arg0) {
    char *p = (char *)arg0;
    int flag = 0;
    int temp;
    int temp2;
    float limit;

    limit = lbl_8055E3C8;
    lbl_8055E57C = lbl_80562144;
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

    *(int *)(p + 0x260) = 0;
    *(int *)(p + 0x2C4) = -1;
    *(float *)(p + 0x2B8) = lbl_80562144;
    *(float *)(p + 0x2C0) = lbl_80562144;
    *(float *)(p + 0x264) = lbl_80562144;
    *(int *)(p + 0x2D0) = 0;
    *(unsigned char *)(p + 0x2A7) = 0;
    memset(p + 0x218, 0, 4);
    *(int *)(p + 0x210) = 0;

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
#pragma scheduling on
void fn_801941A8(void *arg0, float arg1) {
    float value;
    float pos = *(float *)((char *)arg0 + 0x23C);
    float vel = *(float *)((char *)arg0 + 0x248);
    float limit;
    int other;

    value = arg1 - pos;
    if (value < lbl_805621B0) value = lbl_805621B0;
    if (value > lbl_805621B4) value = lbl_805621B4;
    limit = pos + value;
    if (vel < lbl_80562174) {
        pos = limit;
        other = *(int *)((char *)*(void **)((char *)arg0 + 0x294) + 0x25F0);
        if (other < 0 != limit < 0)
            vel += lbl_80562168;
    }
    *(float *)((char *)arg0 + 0x23C) = pos;
    *(float *)((char *)arg0 + 0x248) = vel;
    vel = *(float *)((char *)arg0 + 0x248);
    if (vel < lbl_80562140) vel = lbl_80562140;
    if (vel > lbl_80562144) vel = lbl_80562144;
    pos = *(float *)((char *)arg0 + 0x23C);
    pos *= lbl_80562140 - vel;
    if (pos < lbl_80562140) pos = lbl_80562140;
    if (pos > lbl_805621A4) pos = lbl_805621A4;
    *(float *)((char *)arg0 + 0x23C) = pos;
    fn_8018ADAC(*(void **)((char *)arg0 + 0x294), pos);
}

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
    curve = lbl_805621A4;
    if (ratio < curve) {
        goto done;
    }
    curve = lbl_80562140;
    if (ratio > curve) {
        goto done;
    }
    if (ratio > lbl_80562144) {
        curve = ((lbl_805621D0 * ratio) * ratio) * ratio + ((lbl_805621D4 * ratio) * ratio);
    } else {
        curve = ((lbl_805621D0 * ratio) * ratio) * ratio - ((lbl_805621D4 * ratio) * ratio);
    }
done:
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

    fn_80194FD0();
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
extern void fn_80194FD0(void);
void fn_80194F70(void *arg0, float *a, float *b) {
    float x, y, z;
    x = a[0] - b[0];
    y = a[1] - b[1];
    z = a[2] - b[2];
    PSVECDotProduct(arg0, &x);
}

void fn_80194FC4(void) {

}

void fn_80194FC8(void *arg0) {
    fn_8013B744(*(int *)((unsigned char *)arg0 + 0x290));
}

void fn_801955F0(void *arg0, float *arg1) {
    float scale;
    fn_80194FD0();
    scale = *(float *)((unsigned char *)arg0 + 0x2B8);
    arg1[0] += *(float *)((unsigned char *)arg0 + 0x58) * scale;
    arg1[1] += *(float *)((unsigned char *)arg0 + 0x5C) * scale;
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
extern void fn_80195654(void *);
extern void fn_801933FC(void *, void *);
extern double fn_8002F234(float);
extern float lbl_80562140;
extern float lbl_80562148;
extern float lbl_80562204;
void fn_801958C4(void *arg0) { *(float *)((unsigned char *)arg0+0x248) *= lbl_80562204; }

void fn_80195B28(void *arg0, float arg1) {
 float *p=(float*)arg0, *table; float value, scale; int index;
 if (p[0x234/4]>=p[0x26C/4] && lbl_80562144==arg1) {
  table=(float*)__AXFXGetLfoSinTable_801769CC();
  if (*(int*)((char*)table+4)!=0x180201) {
   index=*(int*)((char*)arg0+0x268); table=lbl_80333308; if(index==1)table+=3;
   p[0x22C/4]=p[0x26C/4]; p[0x234/4]=fn_80129DC4(3,table[0],table[1]);
   if(index!=1)p[0x234/4]*=lbl_8055E56C;
   p[0x228/4]=p[0x220/4]; p[0x234/4]+=p[0x26C/4]; p[0x230/4]=table[2];
   if(index==1)p[0x224/4]=fn_80129DC4(3,lbl_8056220C,lbl_8056215C);
   else p[0x224/4]=fn_80129DC4(3,lbl_805621A4,lbl_80562140);
   if(lbl_80562144!=arg1){ value=fabsf(p[0x224/4]); if(arg1>lbl_80562144)scale=lbl_80562140;else scale=lbl_805621A4;p[0x224/4]=scale*value;}
  } else { p[0x234/4]=p[0x26C/4];p[0x228/4]=lbl_80562144;p[0x224/4]=lbl_80562144;p[0x22C/4]=p[0x26C/4];p[0x230/4]=p[0x26C/4]; }
 }
}

extern void fn_80194324(void);
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
void fn_80195D80(void *arg0, float arg1) {
    void *base = *(void **)((char *)arg0 + 0x28C);
    void *(*get)(void *) = *(void *(**)(void *))(*(char **)base + 0x1C);
    void *obj = get(base);
    void *shape = *(void **)((char *)obj + 0x2C);
    void *other = *(void **)((char *)arg0 + 0x294);
    int changed;
    float values[8];
    *(float *)((char *)arg0 + 0x2CC) = *(float *)((char *)shape + 0x14);
    *(int *)((char *)arg0 + 0x2C8) = *(int *)((char *)shape + 0x28);
    *(int *)((char *)arg0 + 0x18) = fn_801388F4(*(void **)((char *)obj + 4));
    changed = *(int *)((char *)arg0 + 0x1C8) != 0 && *(int *)((char *)arg0 + 0x1C8) != *(int *)((char *)obj + 0x2C);
    if (changed) {
        *(int *)((char *)arg0 + 0x16C) = *(int *)((char *)arg0 + 0x1A0);
        *(int *)((char *)arg0 + 0x170) = *(int *)((char *)arg0 + 0x1A4);
        *(int *)((char *)arg0 + 0x174) = *(int *)((char *)arg0 + 0x1A8);
        *(int *)((char *)arg0 + 0x178) = *(int *)((char *)arg0 + 0x1AC);
        *(int *)((char *)arg0 + 0x17C) = *(int *)((char *)arg0 + 0x1B0);
        *(int *)((char *)arg0 + 0x180) = *(int *)((char *)arg0 + 0x1B4);
        *(int *)((char *)arg0 + 0x184) = *(int *)((char *)arg0 + 0x1B8);
        *(int *)((char *)arg0 + 0x188) = *(int *)((char *)arg0 + 0x1BC);
        *(int *)((char *)arg0 + 0x18C) = *(int *)((char *)arg0 + 0x1C0);
        *(u8 *)((char *)arg0 + 0x190) = *(u8 *)((char *)arg0 + 0x1C4);
        *(int *)((char *)arg0 + 0x194) = *(int *)((char *)arg0 + 0x1C8);
        *(int *)((char *)arg0 + 0x198) = *(int *)((char *)arg0 + 0x1CC);
        *(float *)((char *)arg0 + 0x1D0) = lbl_8055E3C8;
    }
    *(int *)((char *)arg0 + 0x1A0) = *(int *)((char *)obj + 4);
    *(int *)((char *)arg0 + 0x1A4) = *(int *)((char *)obj + 8);
    *(int *)((char *)arg0 + 0x1A8) = *(int *)((char *)obj + 0xC);
    *(int *)((char *)arg0 + 0x1AC) = *(int *)((char *)obj + 0x10);
    *(int *)((char *)arg0 + 0x1B0) = *(int *)((char *)obj + 0x14);
    *(int *)((char *)arg0 + 0x1B4) = *(int *)((char *)obj + 0x18);
    *(int *)((char *)arg0 + 0x1B8) = *(int *)((char *)obj + 0x1C);
    *(int *)((char *)arg0 + 0x1BC) = *(int *)((char *)obj + 0x20);
    *(int *)((char *)arg0 + 0x1C0) = *(int *)((char *)obj + 0x24);
    *(u8 *)((char *)arg0 + 0x1C4) = *(u8 *)((char *)obj + 0x28);
    *(int *)((char *)arg0 + 0x1C8) = *(int *)((char *)obj + 0x2C);
    *(int *)((char *)arg0 + 0x1CC) = *(int *)((char *)obj + 0x30);
    if (arg1 - *(float *)((char *)arg0 + 0x1D0) < lbl_805621C0) {
        float scale = *(float *)((char *)other + 0x5BC);
        values[0] = *(float *)((char *)other + 0x94) + *(float *)((char *)other + 0x54) * scale;
        values[1] = *(float *)((char *)other + 0x98) + *(float *)((char *)other + 0x58) * scale;
        values[2] = *(float *)((char *)other + 0x9C) + *(float *)((char *)other + 0x5C) * scale;
        values[3] = values[0]; values[4] = values[1]; values[5] = values[2];
        fn_801353C4((char *)arg0 + 0x168, values);
    }
}

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
    int var_r0;
    temp_f5 = farg0 - farg1;
    temp_f5 += lbl_80562230;
    temp_f5 /= farg2;
    mag0 = __fabs((double)farg0);
    abs0 = (float)mag0;
    if (abs0 < lbl_80562168) {
        float value0 = lbl_80562140;
        float value1 = lbl_80562144;
        *arg1 = value0;
        *arg0 = value1;
        *arg2 = 0;
        return;
    }
    if ((float)__fabs((double)farg1) < lbl_80562208)
        goto direct_case;
    sp8 = temp_f5;
    spC = farg1;
    if ((int)(*(unsigned int *)&spC & 0x80000000U) != (int)(*(unsigned int *)&sp8 & 0x80000000U))
        goto different_sign;
direct_case:
    *arg0 = (float)__fabs((double)temp_f5) / lbl_80562234;
    *arg1 = lbl_80562144;
    goto finish;
different_sign:
    *arg0 = lbl_80562144;
    *arg1 = (float)__fabs((double)temp_f5) / lbl_80562238;
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
  extern int fn_8019643C(void);

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
#pragma dont_inline reset
  extern int fn_801B2F24(void);
  extern void fn_801B2F40(int);
  extern int fn_8019643C(void);
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

extern float lbl_80562140, lbl_80562144, lbl_80562184, lbl_805621A4;
extern float lbl_805621EC, lbl_80562244, lbl_80562248;
extern void fn_801EA18C(void *, void *, int, int, void *, float);
extern void fn_8018AE2C(void *, float);
extern void fn_8018AE34(void *, float);
void fn_801965AC(void *arg0) {
    float position[3];
    int transform[3];
    float delta;
    float value;
    float scale;
    float factor;
    void *obj;

    obj = *(void **)((char *)arg0 + 0x294);
    if (*(int *)((char *)obj + 0x2620) != 0)
        return;

    position[0] = lbl_80562144;
    position[1] = lbl_80562140;
    position[2] = lbl_80562144;
    transform[0] = *(int *)((char *)obj + 0x60);
    transform[1] = *(int *)((char *)obj + 0x64);
    transform[2] = *(int *)((char *)obj + 0x68);
    fn_801EA18C(transform, position, 0, transform[0], obj, lbl_80562144);

    obj = *(void **)((char *)arg0 + 0x294);
    delta = *(float *)((char *)obj + 0x64) - *(float *)((char *)transform + 4);
    if (delta < lbl_80562144)
        delta = lbl_80562144;
    value = *(float *)((char *)obj + 0x11C);
    if (value < lbl_80562244)
        value = lbl_80562244;
    scale = -delta / value;
    factor = lbl_80562140;
    if (scale < factor) {
        factor = lbl_80562184;
        value = factor * PSVECDotProduct(position, (char *)obj + 0x54);
        if (value < lbl_80562140)
            value = lbl_80562140;
        if (value > lbl_805621A4)
            value = lbl_805621A4;
        fn_8018AE2C(*(void **)((char *)arg0 + 0x294), value);
        value = factor * PSVECDotProduct(position, (char *)*(void **)((char *)arg0 + 0x294) + 0x3C);
        if (value < lbl_80562140)
            value = lbl_80562140;
        if (value > lbl_805621A4)
            value = lbl_805621A4;
        fn_8018AE34(*(void **)((char *)arg0 + 0x294), value);
        return;
    }

    value = __fabs(*(float *)((char *)arg0 + 0x23C));
    value = (value - lbl_80562144) / scale;
    if (scale < value)
        scale = value;
    if (scale > lbl_80562144)
        scale = lbl_80562144;
    factor = *(float *)((char *)obj + 0x58) - (lbl_805621EC + scale * lbl_80562248);
    value = lbl_80562184 * factor;
    if (value < lbl_80562140)
        value = lbl_80562140;
    if (value > lbl_805621A4)
        value = lbl_805621A4;
    fn_8018AE2C(obj, value);
    fn_8018AE34(*(void **)((char *)arg0 + 0x294), lbl_80562144);
}

  void fn_801967A4(void *arg0) {
      int value = *(int *)((char *)arg0 + 0x210);
      switch (value) {
      case 0:
          fn_80198530();
          fn_801965AC(arg0);
          return;
      case 1:
          fn_80196AA0();
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

  void fn_80196A9C(void) {
      fn_8019684C();
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
int fn_8019703C(void *arg0, void *arg1) {
    float x = *(float *)((char *)arg0 + 0x270);
    float y = *(float *)((char *)arg1 + 4);
    float z = *(float *)((char *)arg1 + 8);
    float threshold = lbl_8055A488 + lbl_80562194 * x;
    int chosen = 0;
    int update = 0;
    if ((*(unsigned int *)((char *)arg0 + 0x2D0) & 1) == 0 &&
        x > lbl_80562170 && __fabsf(y) < threshold) {
        if (y > lbl_80562144) {
            float score = *(float *)((char *)arg0 + 0x278) + y;
            if (score < *(float *)((char *)arg0 + 0xBC)) {
                *(float *)((char *)arg0 + 0xBC) = score;
                *(unsigned int *)((char *)arg0 + 0xA0) = *(unsigned int *)((char *)arg1 + 0);
                *(unsigned int *)((char *)arg0 + 0xA4) = *(unsigned int *)((char *)arg1 + 4);
                *(unsigned int *)((char *)arg0 + 0xA8) = *(unsigned int *)((char *)arg1 + 8);
                *(unsigned int *)((char *)arg0 + 0xAC) = *(unsigned int *)((char *)arg1 + 0xC);
                *(unsigned int *)((char *)arg0 + 0xB0) = *(unsigned int *)((char *)arg1 + 0x10);
                *(unsigned char *)((char *)arg0 + 0xB4) = *(unsigned char *)((char *)arg1 + 0x14);
                *(unsigned int *)((char *)arg0 + 0xB8) = *(unsigned int *)((char *)arg1 + 0x18);
                *(unsigned char *)((char *)arg0 + 0x9C) = 1;
                update = 1;
            }
        } else {
            float score = *(float *)((char *)arg0 + 0x278) + y;
            if (score > *(float *)((char *)arg0 + 0x94)) {
                *(float *)((char *)arg0 + 0x94) = score;
                *(unsigned int *)((char *)arg0 + 0x78) = *(unsigned int *)((char *)arg1 + 0);
                *(unsigned int *)((char *)arg0 + 0x7C) = *(unsigned int *)((char *)arg1 + 4);
                *(unsigned int *)((char *)arg0 + 0x80) = *(unsigned int *)((char *)arg1 + 8);
                *(unsigned int *)((char *)arg0 + 0x84) = *(unsigned int *)((char *)arg1 + 0xC);
                *(unsigned int *)((char *)arg0 + 0x88) = *(unsigned int *)((char *)arg1 + 0x10);
                *(unsigned char *)((char *)arg0 + 0x8C) = *(unsigned char *)((char *)arg1 + 0x14);
                *(unsigned int *)((char *)arg0 + 0x90) = *(unsigned int *)((char *)arg1 + 0x18);
                *(unsigned char *)((char *)arg0 + 0x74) = 1;
                update = 1;
            }
        }
    }
    if (update) {
        *(float *)((char *)arg0 + 0xCC) = y;
        *(float *)((char *)arg0 + 0xD8) = z;
        *(unsigned int *)((char *)arg0 + 0xDC) = *(unsigned int *)((char *)arg1 + 0x18);
    }
    if (y > lbl_80562144)
        ++*(int *)((char *)arg0 + 0xC0);
    else
        ++*(int *)((char *)arg0 + 0x98);
    return 0;
}

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

int fn_8019799C(void *arg0, void *arg1) {
    int result = 0;
    int id;
    int valid;
    int allow;
    float angle;
    float bound;
    float distance;
    extern float lbl_80562160, lbl_80562170, lbl_80562184;
    extern float fn_80137850(void *);
    extern void fn_80197AB8(void *, int, float, float, float);
    extern float __fabsf(float);

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
        distance = __fabsf(angle);
        bound = *(float *)((char *)arg0 + 0x278) + *(float *)((char *)arg1 + 4);
        if (distance >= bound) distance = bound;
        if (distance < lbl_80562184 + *(float *)((char *)arg0 + 0x274)) {
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
void fn_80197AB8(void *arg0, int arg1, float farg0, float farg1, float farg2) {
    unsigned char *p = (unsigned char *)arg0;
    float vals[2];
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
        result = (*(void *(*)(void *))(*(void ***)obj)[6])(obj);
        if (result) {
            p[0xFC] = 1;
            *(float *)(p + 0xF8) = farg1;
            *(int *)(p + 0x114) = arg1;
            *(float *)(p + 0x108) = *(float *)(p + 0x278) + *(float *)(p + 0x27C) * farg0;
            *(float *)(p + 0x110) = farg2;
            *(float *)(p + 0x104) = lbl_80562194 * (*(float *)((char *)result + 0x38) * vals[0] + *(float *)((char *)result + 0x3C) * vals[1]);
        }
    }
}

extern float lbl_8055A48C, lbl_80562194, lbl_8056227C, lbl_80562280, lbl_80562140, lbl_80562144, lbl_805621A4, lbl_8056215C, lbl_80562284, lbl_80562288, lbl_80562268, lbl_80562274, lbl_8056228C;
extern void fn_8019315C(void *, int);
extern int fn_8019309C(void *, int, signed char);
void fn_80197BD0(void *arg0, void *arg1) {
 float f31=lbl_8055A488,f30,f5,f6,f4,f3,f2,f1; int done=1, i, special; void *p;
 f30=lbl_80562194*lbl_8055A48C;
 if (*(u8*)((char*)arg0+0xfc)) {
  if (*(float*)((char*)arg0+0xec)<lbl_8056227C || *(int*)((char*)arg0+0x100)>1) {
   fn_8019315C(arg0,*(int*)((char*)arg0+0x114)); i=*(int*)((char*)arg0+0x114); p=lbl_804349C0[i];
   f5=f31+__fabs(*(float*)((char*)arg0+0x104))*(f30-f31);
   special=p && *(int*)((char*)arg0+0x290)==*(int*)((char*)p+0x114);
   f4=*(float*)((char*)arg0+0xf8); f6=f4-*(float*)((char*)arg0+0x108);
   if (__HI(f4)!=__HI(f6)&&!special) f6=f4>lbl_80562144?lbl_80562140:lbl_805621A4;
   if (*(int*)((char*)arg0+0x114)!=*(int*)((char*)arg0+0x118)||*(float*)((char*)arg0+0xec)>lbl_80562194) {
    *(float*)((char*)arg0+0x10c)=f6; f3=__fabs(f6); f30=lbl_80562284+lbl_8056215C*(f5+f31);
    if (f3<f30) {
     if ((*(u8*)((char*)arg0+0x9c)||*(u8*)((char*)arg0+0x74))&&__HI(f6)!=__HI(*(float*)((char*)arg0+0xcc))) fn_8019309C(arg0,*(int*)((char*)arg0+0xdc),0);
     f1=*(float*)((char*)arg0+0x10c)>lbl_80562144?lbl_80562140:lbl_805621A4;
     f2=( *(float*)((char*)arg0+0x54)-lbl_80562144)/(*(float*)((char*)arg0+0xec)-lbl_80562144); if(f2>lbl_80562140) f2=lbl_80562140; if(f2<lbl_80562144) f2=lbl_80562144;
     f3=*(float*)((char*)arg0+0x278); f4=(*(float*)((char*)arg0+0xec)-lbl_8056227C)/lbl_80562288;
     *(float*)((char*)arg0+0xf4)=f3+f2*(*(float*)((char*)arg0+0xf8)-f30*f1-f3);
     if(f4>lbl_80562140) f4=lbl_80562140; if(f4<lbl_80562144) f4=lbl_80562144;
     f2=f4*lbl_80562140; f3=*(float*)((char*)arg0+0xf0); f1=lbl_80562144+f2-f3; *(float*)((char*)arg0+0xf0)=f3+lbl_8056215C*f1;
     if(!fn_80193184(arg0,*(int*)((char*)arg0+0x114))) { f4=*(float*)((char*)arg1+8); f3=*(float*)((char*)arg0+0x270)+*(float*)((char*)arg0+0x110); *(float*)((char*)arg1+8)=f4+*(float*)((char*)arg0+0xf0)*(f3+lbl_80562268/(*(int*)((char*)arg0+0x100))*(f4-f3)-f4); }
     done=0;
    }
   }
  }
 } else { *(int*)((char*)arg0+0x114)=-1; *(int*)((char*)arg0+0x118)=-1; }
 f4=*(float*)((char*)arg0+0xf0);
 if(f4>lbl_80562274) { f5=*(float*)((char*)arg0+0xf4); *(u8*)((char*)arg0+0x250)=1; f3=*(float*)((char*)arg0+0x48)+*(float*)((char*)arg0+0x58)*f5; f2=*(float*)((char*)arg0+0x4c)+*(float*)((char*)arg0+0x5c)*f5; f1=*(float*)arg1; f6=*(float*)((char*)arg1+4); *(float*)arg1=f1+f4*(f3-f1); *(float*)((char*)arg1+4)=f6+f4*(f2-f6); }
 if(done) *(float*)((char*)arg0+0xf0)*=lbl_8056228C;
}

extern float lbl_80562184, lbl_80562290, lbl_80562294;
extern float lbl_8055A48C;
extern void fn_8019813C(void *, void *, float, float);
int fn_80197FE4(void *arg0, void *arg1) {
    int result = 0;
    float speed;
    float x;
    float y;
    float z;
    float limit;
    float bound;
    void *entry;
    int allowed;
    int in_range;
    int angle_ok;

    if (*((int *)((char *)arg0 + 0x2D0)) & 4)
        return 0;

    speed = (*((int *)((char *)arg0 + 0x268)) == 0 ||
             *((int *)((char *)arg0 + 0x268)) == 3)
                ? lbl_8056215C : lbl_80562140;
    *(float *)((char *)arg0 + 0x134) = speed;

    x = *(float *)((char *)arg1 + 8);
    y = *(float *)((char *)arg1 + 0x10);
    z = *(float *)((char *)arg1 + 0x0C);
    limit = lbl_8055A48C + lbl_80562184 * lbl_8055A48C;
    bound = lbl_80562294 * lbl_8055A48C;
    in_range = (x < lbl_8056215C * lbl_8055A48C) &&
               (x + speed * y < limit) &&
               (x + speed * y > bound);
    angle_ok = __fabs(*(float *)((char *)arg1 + 4) + speed * z) <
               lbl_80562290 * lbl_8055A488;

    entry = lbl_804349C0[*(int *)((char *)arg1 + 0x18)];
    allowed = 1;
    if (entry != 0 && *((u8 *)entry + 0x2A5) != 0)
        allowed = 0;
    if (allowed && in_range && angle_ok) {
        fn_8019813C(arg0, arg1, x, x + speed * y);
        result = 1;
    }
    return result;
}

#pragma scheduling invalid_target
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
      void fn_801964D0();
  void fn_80128668(void *);
  void fn_80193138(int);
    void fn_801964D0();
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
extern void fn_80195654(void *);
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
