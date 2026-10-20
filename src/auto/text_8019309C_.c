// Code of main that had no source file yet: decomp.wtf gave it this one.
    // split_file divides it into the game's real files (file_status shows its range).

    extern void fn_801958D8(void);
    extern void fn_801945F8(void *);
    extern void fn_80195F6C(void *, void *);
    extern void fn_80194624(void *);
    extern void fn_80195654(void *);
    extern void fn_801933FC(void *, void *);
    extern double fn_8002F234(float);
    extern float lbl_8055E584, lbl_8055E588;
    extern float fn_80129DC4(int, float, float);
    extern void fn_8013530C(void *, int);
    extern int lbl_8055E550;
    extern float lbl_8055E3C8, lbl_80562144, lbl_80562140, lbl_80562148, lbl_80562204;

    typedef unsigned char u8;
extern void *lbl_804349C0[];
extern float lbl_8056223C, lbl_8055E57C;
extern int lbl_804348E8[];
extern void *lbl_804349E0[];
extern int lbl_80333390;
void fn_801964D0(void);
void fn_80128668(void *);
void fn_80193138(int);

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

void fn_801933FC(void *arg0, void *arg1) {
    fn_8019330C(arg1, arg0, *(int *)((char *)arg0 + 0x294) + 0x70);
}

#pragma processor 750
int fn_80193524(void *arg0, void *arg1) {
    extern float PSVECDotProduct(const void *, const void *);
    extern float lbl_8056215C;
    float delta[3];
    float dot;
    if (__fabs(PSVECDotProduct((char *)arg0 + 0x54, (char *)arg1 + 0x54)) >= lbl_8056215C)
        return 0;
    delta[0] = *(float *)((char *)arg1 + 0x60) - *(float *)((char *)arg0 + 0x60);
    delta[1] = *(float *)((char *)arg1 + 0x64) - *(float *)((char *)arg0 + 0x64);
    delta[2] = *(float *)((char *)arg1 + 0x68) - *(float *)((char *)arg0 + 0x68);
    dot = PSVECDotProduct(delta, (char *)arg0 + 0x54);
    return dot > -PSVECDotProduct(delta, (char *)arg1 + 0x54);
}
#pragma processor gekko
void fn_801935EC(void *arg0) {
    float value = lbl_80562144;
    *(float *)((unsigned char *)arg0 + 0x224) = value;
    *(float *)((unsigned char *)arg0 + 0x228) = value;
    *(float *)((unsigned char *)arg0 + 0x22C) = lbl_8055E3C8;
}

void fn_8019386C(void) {
    fn_80193CE0();
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
#pragma dont_inline reset

void fn_80193D20(void) {
    fn_80129DC4(3, lbl_8055E584, lbl_8055E588);
}

void fn_8019416C(void) {

}

typedef unsigned int u32;
extern float lbl_80562140, lbl_80562144;
  extern void fn_8018ADB4(int, float);
  extern void fn_8018ADBC(int, float);
  extern void fn_8018ADAC(void *, float);
  void fn_80194170(void *arg0, float arg1) {
    float value;
    if (arg1 > lbl_80562140) value = arg1;
    else value = lbl_80562140;
    if (value > lbl_80562144) value = lbl_80562144;
    *(float *)((char *)arg0 + 0x240) = value;
          fn_8018ADB4(*(int *)((char *)arg0 + 0x294), value);
  }

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
void fn_801945F8(void *arg0) {
    int first = *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x294) + 0x1F0);
    if (first == 0x50) {
        int second = *(int *)((unsigned char *)*(void **)((unsigned char *)arg0 + 0x288) + 0x24);
        if (second != 3)
            return;
    }
    fn_80194590(arg0);
}

void fn_80194AF4(void *unused, float *out, float *a, float *b, float t) {
    float x, y;
    double pair;
    x = a[1] + t * (b[1] - a[1]);
    y = a[0] + t * (b[0] - a[0]);
    pair = (double)y;
    out[0] = (float)pair;
    out[1] = x;
    out[2] = a[2] + t * (b[2] - a[2]);
}

extern double fn_8002EFB4(float, float);
extern float lbl_80562140, lbl_80562144, lbl_8056215C, lbl_805621A4, lbl_805621D0, lbl_805621D4;
#pragma processor 750
float fn_80194B60(float a, float b, float c, float d) {
    float ratio;
    float curve;
    float distance;
    distance = (float)fn_8002EFB4(d, c);
    if (distance > c * lbl_8056215C) {
        distance = c - distance;
    }
    ratio = distance / (c * lbl_8056215C);
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
#pragma processor gekko
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
    float x, y, scale;
    fn_80195654((unsigned char *)arg0 + 0x20);
    fn_801933FC(arg0, (unsigned char *)arg0 + 0x20);
    x=*(float *)((unsigned char *)arg0+0x20); y=*(float *)((unsigned char *)arg0+0x24);
    *(float *)((unsigned char *)arg0+0x40)=x; *(float *)((unsigned char *)arg0+0x44)=y;
    scale=(float)fn_8002F234(x*x+y*y);
    if (lbl_80562148 > scale) {} else { scale=lbl_80562148; }
    scale=lbl_80562140/scale;
    *(float *)((unsigned char *)arg0+0x40)*=scale;
    *(float *)((unsigned char *)arg0+0x44)*=scale;
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
    float sp8;
    float spC;
    int var_r0;
    temp_f5 = (lbl_80562230 + (farg0 - farg1)) / farg2;
    if (__fabs(farg0) < lbl_80562168) {
        *arg1 = lbl_80562140;
        *arg0 = lbl_80562144;
        *arg2 = 0;
        return;
    }
    if (__fabs(farg1) < lbl_80562208) {
        *arg0 = __fabs(temp_f5) / lbl_80562234;
        *arg1 = lbl_80562144;
    } else {
        sp8 = farg1;
        spC = temp_f5;
        if ((*(unsigned int *)&spC & 0x80000000) == (*(unsigned int *)&sp8 & 0x80000000)) {
            *arg0 = __fabs(temp_f5) / lbl_80562234;
            *arg1 = lbl_80562144;
        } else {
            *arg0 = lbl_80562144;
            *arg1 = __fabs(temp_f5) / lbl_80562238;
        }
    }
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

  void fn_80196418(void *arg0) {
      int value = *(int *)((char *)arg0 + 0x210);
      if (value == 0) fn_80195830(arg0);
  }

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
      if (entry == 0) return 1;
      if (*((u8 *)entry + 0x2A4) != 0) return 1;
      return 0;
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
extern int fn_8019813C(float);
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
        fn_8019813C(*(float *)((char *)arg1 + 8));
        result = 1;
    }
    return result;
}

#pragma dont_inline on
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
      int i;
      int count;
      void **items;
      if (arg0 == 0) return arg0;
      *(void **)arg0 = &lbl_80333390;
      count = *(int *)((unsigned char *)lbl_804349E0 + 0x20);
      items = (void **)lbl_804349E0;
      for (i = 0; i < count; i++) {
          if (items[i] == arg0) {
              count--;
              *(int *)((unsigned char *)lbl_804349E0 + 0x20) = count;
              items[i] = items[count];
          }
      }
      if (arg1 > 0) fn_80128668(arg0);
      return arg0;
  }

  void fn_80198EA0(void) {
      fn_80198E7C();
  }

  typedef unsigned char u8;
  extern void *lbl_804349C0[];
  extern void *lbl_804349E0[];
  extern int lbl_80333390;
  void fn_801964D0(void);
  void fn_80128668(void *);
  void fn_80193138(int);
  void fn_801964D0(void);
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
