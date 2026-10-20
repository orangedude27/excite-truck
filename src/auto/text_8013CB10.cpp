#include "types.h"
extern "C" void fn_8001DAE0(void *, f32);
extern "C" f32 lbl_805614FC;
extern "C" f32 lbl_80561500;
extern "C" f32 lbl_80558DC4;
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805614AC;
extern "C" f32 lbl_805614BC;
extern "C" s32 fn_80128670(s32);
extern "C" void fn_80128668(void);
extern "C" f32 fn_8001DAE8(void *);
extern "C" s32 lbl_802F9398[6];
struct S6_8013D18C { s32 v[6]; };
extern "C" void **fn_801284F8(s32, void *);
extern "C" f32 lbl_80561498;
extern "C" s32 fn_80176A1C(void);
extern "C" int strcmp(const char *, const char *);

extern "C" u8 lbl_8032CAC0;
extern "C" s32 fn_8013D224(f32, f32);
extern "C" u8 *fn_801B2EC0(s32);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

struct S28_80142118 { s32 v[7]; };

struct TVec2 { f32 x; f32 y; };

extern "C" void fn_801E9DC4(s16 *);

extern "C" char lbl_80559D40[4];
extern "C" char lbl_80559D58[7];
extern "C" char lbl_80559D60[7];

extern "C" void fn_80140A6C(void);
extern "C" s32 fn_801B8514(void);
extern "C" u8 *fn_8017960C(s32);
extern "C" u32 fn_8013D148(u8 *, f32);
extern "C" void *fn_802C6C34(s32);

// user virtuals start at vtable offset 0x8 (two destructor slots first)
class TObj4C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16();
    virtual void v4C(); // 0x4C
};

class TObj24 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual u8 v24(); // 0x24
};

class TObj8 {
public:
    virtual void d0();
    virtual u8 *v8();
};

class TObj10 {
public:
    virtual u8 *v10(); // 0x8
};

class TObj18 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual u8 *v18();
};

class TObjC {
public:
    virtual void d0();
    virtual s32 vC(s32); // 0xC
};

class TObj20b {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual s32 v20();
};

class TObj20 {
public:
    virtual void d0(); virtual void d1(); virtual void d2();
    virtual void d3(); virtual void d4(); virtual void d5();
    virtual s32 v20(s32);
};

class TObjCPlus {
public:
    virtual void d0();
    virtual s32 vC(s32);
};

extern "C" s32 fn_8013D1F0(s32);

extern "C" s32 fn_8013CB10(void) {
    return fn_80176A1C() == 2;
}

extern f32 lbl_8055E3C8;
#pragma dont_inline on
extern "C" f32 fn_8013CB3C(void) {
    return lbl_8055E3C8;
}
#pragma dont_inline off

extern "C" s32 fn_8013CB44(const char *arg0, TObj10 *arg1) {
    return strcmp((const char *)arg1->v10(), arg0) == 0;
}

extern "C" void fn_8013CB90(void *arg0) {
    f32 x;
    f32 scale;
    f32 y;
    x = *(f32 *)((u8 *)arg0 + 0x10);
    scale = lbl_80561498;
    y = *(f32 *)((u8 *)arg0 + 0x14);
    *(f32 *)((u8 *)arg0 + 4) -= x * scale;
    *(f32 *)((u8 *)arg0 + 8) -= y * scale;
}

extern "C" f32 lbl_805614B4;
extern "C" f32 lbl_805614B8;
extern "C" f32 PSVECDotProduct(const f32 *, const f32 *);
extern "C" s32 fn_8013CFF0(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 dx, dy, dz;
    f32 vx, vy, vz;
    f32 dot;
    f32 sp10, spC, sp8;
    f32 sp18, sp14, sp1C;
    dx = arg0[5] - arg0[2];
    dy = arg0[4] - arg0[1];
    dz = arg0[3] - arg0[0];
    vx = arg0[2] + lbl_80561498 * dx;
    vy = arg0[1] + lbl_80561498 * dy;
    vz = arg0[0] + lbl_80561498 * dz;
    sp8 = vy - arg1[10];
    spC = vz - arg1[9];
    sp10 = vx - arg1[11];
    sp18 = vy;
    sp14 = vz;
    sp1C = vx;
    dot = PSVECDotProduct(&sp8, &sp18);
    if (dot < lbl_805614B4) {
        if (PSVECDotProduct(&sp8, arg1 + 6) < lbl_805614B8) {
            sp8 = arg0[3] - arg1[9];
            spC = arg0[4] - arg1[10];
            sp10 = arg0[5] - arg1[11];
            if (PSVECDotProduct(&sp8, arg1 + 6) > lbl_805614B8) {
                if (arg2) *arg2 = dot;
            }
        }
    }
    return 0;
}

extern "C" u32 fn_8013D148(u8 *arg0, f32 arg1) {
    s32 i = 0;
    s32 count = *(s32 *)arg0;
    u8 *items = *(u8 **)(arg0 + 4);
    u8 *result = items + count * 0x24 - 0x24;
    while (count > 0) {
        u8 *item = items + i;
        if (*(f32 *)(item + 0x18) > arg1) return (u32)result;
        result = item;
        i += 0x24;
        count--;
    }
    return (u32)result;
}

extern "C" u32 fn_8013D18C(u32 arg0) {
    S6_8013D18C values;
    values = *(S6_8013D18C *)&lbl_802F9398;
    return values.v[arg0 % 6];
}

extern "C" s32 fn_8013D1F0(s32 arg0) {
    u8 *obj = ((u8 *(*)(void))fn_801B2EC0)();
    u8 *(*fn)(u8 *) = (u8 *(*)(u8 *))(*(void ***)obj)[4];
    obj = fn(obj);
    return *(s32 *)(obj + 0x10);
}

extern "C" void fn_8013D27C(void *a, void *b) {
    fn_8013D224(*(f32 *)((u8 *)a + 0x18), *(f32 *)((u8 *)b + 0x18));
}

extern "C" u8 lbl_8032CAC0_vt[48];
extern "C" void **fn_801284F8(s32, void *);
extern "C" char lbl_80559D18[5];
#pragma dont_inline on
extern "C" void fn_8013D288(void) {
    void **slot = fn_801284F8(4, (void *)"zstm");
    if (slot != 0) {
        *slot = (void *)lbl_8032CAC0_vt;
    }
}

extern "C" s32 fn_8013D890(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma dont_inline off

#pragma dont_inline on
extern "C" s32 fn_8013DDD4(TObjC *arg0, const char *arg1) {
    s32 count = 0;
    s32 i = 0;
    void *item;
    while ((item = (void *)arg0->vC(i)) != 0) {
        if (fn_8013CB44(arg1, (TObj10 *)item)) count++;
        i++;
    }
    return count;
}

extern "C" void fn_8013E054(void *outPtr, void *objPtr, f32 angle) {
    u8 *out = (u8 *)outPtr;
    TVec2 center = ((TVec2 (*)(void *, const char *))(*(void ***)objPtr)[0x3C / 4])(objPtr, lbl_80559D58);
    TVec2 tanv = ((TVec2 (*)(void *, const char *))(*(void ***)objPtr)[0x3C / 4])(objPtr, lbl_80559D40);
    f32 a = center.x;
    f32 b = center.y;
    f32 c = tanv.x;
    f32 d = tanv.y;
    f32 negAngle = -angle;
    f32 nc = -c;
    *(f32 *)(out + 0x10) = lbl_805614A4;
    *(f32 *)(out + 4) = lbl_805614A4;
    *(f32 *)(out + 0xC) = a + d * angle;
    *(f32 *)(out + 0x0) = a + d * negAngle;
    *(f32 *)(out + 0x8) = b + nc * negAngle;
    *(f32 *)(out + 0x14) = b + nc * angle;
    fn_801E9DC4((s16 *)(out + 0x1C));
    u8 flag = ((u8 (*)(void *, const char *))(*(void ***)objPtr)[0xC / 4])(objPtr, lbl_80559D60);
    *(u8 *)(out + 0x1E) = flag;
    if (flag) {
        *(f32 *)(out + 0x20) = ((f32 (*)(void *, const char *))(*(void ***)objPtr)[0x24 / 4])(objPtr, lbl_80559D60);
    }
}

#pragma dont_inline off
extern "C" f64 fn_8002F234(f32);
extern "C" f32 fn_8013E300(void *arg0) {
    f32 y = *(f32 *)((u8 *)arg0 + 4);
    f32 x = *(f32 *)arg0;
    return (f32)fn_8002F234(x * x + y * y);
}

extern "C" void fn_8013E338(void) {

}

extern "C" void *fn_8013E6E4(void *arg0) {
    volatile f32 scale = lbl_805614AC;
    fn_8001DAE0((u8 *)arg0 + 0x98, scale);
    fn_8001DAE0((u8 *)arg0 + 0xA0, lbl_805614FC);
    fn_8001DAE0((u8 *)arg0 + 0xA8, lbl_805614FC);
    fn_8001DAE0((u8 *)arg0 + 0xB0, lbl_805614FC);
    fn_8001DAE0((u8 *)arg0 + 0xB8, lbl_80561500);
    fn_8001DAE0((u8 *)arg0 + 0xC0, lbl_805614AC);
    fn_8001DAE0((u8 *)arg0 + 0xC8, lbl_80561498);
    fn_8001DAE0((u8 *)arg0 + 0xD0, lbl_80561498);
    fn_8001DAE0((u8 *)arg0 + 0xD8, lbl_80561498);
    return arg0;
}

extern "C" void fn_8013EB0C(void *arg0, s32 arg1) {
    u8 *entry = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    if (*(u8 *)(entry + 0x118))
        *(s32 *)entry = 1;
}

extern "C" f32 lbl_80561510;
extern "C" f32 lbl_80561514;
extern "C" void fn_802AE220(int);
extern "C" int fn_8001DFCC(void);
extern "C" f32 fn_8013EFB0(f32 arg0) {
    return arg0 - lbl_80561510;
}

extern f32 lbl_80561514;
extern f32 lbl_80561510;
extern f32 lbl_80558DC4;
extern void fn_802AE220(int);
extern int fn_8001DFCC(void);
extern f32 lbl_805614A4;
extern f32 lbl_805614AC;
extern f32 lbl_80561530;
extern f32 lbl_80561538;
extern f32 lbl_8056153C;
extern f32 lbl_80561540;
extern f32 lbl_80561498;
extern f32 lbl_805614FC;
extern f32 lbl_80561500;
extern "C" void fn_8001DAE0(void *, f32);
extern "C" f32 fn_8013EFBC(f32 arg0) { return lbl_80561514 - arg0; }

unsigned int fn_8013EFC8(void *arg0) {
 unsigned int result;
 if (__fabsf(*(f32 *)((u8 *)arg0 + 0x250)) <= lbl_80558DC4) {
  if (*((u8 *)arg0 + 0x13c)) ((TObj4C *)arg0)->v4C();
  if (*(int *)((u8 *)arg0 + 0x140)) fn_802AE220(0);
 } else ((TObj4C *)arg0)->v4C();
 if (((int (*)(void *))(*(void ***)arg0)[0x68 / 4])(arg0)) fn_8001DFCC();
 result = *(int *)((u8 *)arg0 + 0x134);
 return result == 4;
}

int fn_8013F088(void *arg0) { return (*(s32 *)((u8 *)arg0 + 0x134) - 2) == 0; }

extern "C" void fn_8013F09C(void) {
    ((void(*)())fn_80140A6C)();
}

extern "C" void fn_8013F434(void) {

}

extern "C" f32 lbl_80561530;
extern "C" f32 lbl_80561538;
extern "C" f32 lbl_8056153C;
extern "C" f32 lbl_80561540;
extern "C" f32 lbl_805614A4, lbl_805614AC, lbl_80561530, lbl_80561538, lbl_8056153C, lbl_80561540;
extern "C" s32 fn_8013F438(f32 x) {
    f32 t = (x - lbl_80561530) / lbl_80561538;
    f32 v = (lbl_805614AC < t) ? lbl_805614AC : t;
    v = (v > lbl_805614A4) ? lbl_805614A4 : v;
    return (s32)(lbl_8056153C + v * lbl_80561540);
}

#pragma push
#pragma scheduling off
extern "C" int fn_8013FC6C(void* arg0) {
    struct V {
        virtual int a0(int); virtual int a1(int); virtual int a2(int);
        virtual int a3(int); virtual int a4(int); virtual int a5(int);
        virtual int a6(int);
    };
    int a = 0, b = 0, c = 0;
    V* obj = (V*)arg0;
    while (c < *(int*)((char*)arg0 + 0xBC)) {
        if (*(unsigned char*)(*(char**)((char*)arg0 + 0xB8) + a + 0x118)) {
            if (obj->a6(c) == 0) {
                b++;
                if (b >= *(int*)((char*)arg0 + 0x130)) return 1;
            }
        }
        a += 0x12C;
        c++;
    }
    return 0;
}
#pragma pop
extern "C" int fn_8013FD20(void* arg0, int arg1) {
    int result = 1;
    if (*(int*)(*(char**)((char*)arg0 + 0xB8) + arg1 * 0x12C + 0x11C) != 0) {
        float f = fn_8001DAE8((char*)arg0 + 0x74) - *(float*)((char*)arg0 + 0x78);
        if (!(f <= lbl_805614A4) && f < *(float*)((char*)arg0 + 0x74)) result = 0;
    }
    return result;
}

extern "C" f32 fn_8001DAF0(f32 *);
extern "C" s32 fn_801E866C(s32);
extern "C" void fn_8001DF08(s32, s32);
extern "C" f64 lbl_805614D8;
extern "C" void fn_8014052C(s32 arg0, u8 *arg1) {
    s32 v = *(s32 *)(arg1 + 0x114) - *(s32 *)(arg1 + 0x10C);
    f32 f = fn_8001DAE8((void *)(arg1 + 0x98)) - *(f32 *)(arg1 + 0x9C);
    s32 flag = 0;
    if (f >= lbl_805614A4 && f < *(f32 *)(arg1 + 0x98))
        flag = 1;
    if (flag != 0 && *(s32 *)(arg1 + 0x80) > 0x32) {
        f32 a = fn_8001DAF0((f32 *)(arg1 + 0x98));
        f32 b = (f32)(*(s32 *)(arg1 + 0x80) * (lbl_805614AC - a));
        v = *(s32 *)(arg1 + 0x10C) - (s32)(b * lbl_805614D8);
    }
    fn_801E866C(arg0);
    fn_8001DF08(arg0, v);
}

extern "C" void fn_80147ABC(void *, void *, s32, f32);
extern "C" void *lbl_8032CA48;
extern "C" void *lbl_8032CA58;
extern "C" void fn_80140614(void *arg0, void *arg2) {
    void *obj = arg0;
    void *src = arg2;
    s32 flag = 0;
    {
        f32 d1 = fn_8001DAE8((char *)src + 0xA8) - *(f32 *)((char *)src + 0xAC);
        if (d1 > lbl_805614A4 && d1 < *(f32 *)((char *)src + 0xA8))
            flag = 1;
    }
    if (flag == 0) {
        f32 d2 = fn_8001DAE8((char *)src + 0xA0) - *(f32 *)((char *)src + 0xA4);
        if (d2 > lbl_805614A4 && d2 < *(f32 *)((char *)src + 0xA0))
            flag = 1;
    }
    if (flag != 0) {
        void *item = *(void **)((char *)obj + 0x54);
        void *r1 = ((void *(*)(void *, void *))(*(void ***)item)[0xC / 4])(item, (void *)0x8032CA48);
        void *r2 = ((void *(*)(void *, void *))(*(void ***)item)[0xC / 4])(item, (void *)0x8032CA58);
        f32 d = fn_8001DAF0((f32 *)((char *)src + 0xA0));
        fn_80147ABC(r1, r2, *(s32 *)((char *)r1 + 0x1C), d * d);
    }
}

extern "C" void fn_80141454(void) {

}

extern "C" void fn_80141458(void) {

}

extern "C" void fn_802A96E8(s32, s32, s32, s32, s32, void *);
extern "C" void fn_80141558(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_802A96E8(arg1, arg2, arg3, *(s32 *)((char *)arg0 + 0), *(s32 *)((char *)arg0 + 4), arg0);
}

extern "C" void fn_80141C84(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    *(s32 *)(p + 0x88) = *(s32 *)(p + 0x10C);
}

extern "C" double floor(double);
extern "C" f32 lbl_805614AC;
extern "C" f32 fn_80141C9C(f32 arg0) {
    return floor(arg0);
}

extern "C" s32 fn_80141E90(f32 *arg0, f32 arg1) {
    return arg1 - *arg0 >= lbl_805614AC;
}

extern "C" void *fn_80141EB0(s32 *arg0) {
    s32 count = arg0[1];
    void *result;
    if ((count + (arg0[2] - arg0[3])) % count <= 0) {
        result = 0;
    } else {
        result = (void *)(arg0[0] + ((count + ((volatile s32 *)arg0)[3]) % count) * 12);
    }
    if (result != 0) {
        arg0[3] = (((volatile s32 *)arg0)[3] + 1) % ((volatile s32 *)arg0)[1];
    }
    return result;
}

extern "C" s32 fn_80141F28(void *arg0, s32 arg1) {
    s32 head = ((s32 *)arg0)[3];
    s32 capacity = ((s32 *)arg0)[1];
    s32 count = capacity + (((s32 *)arg0)[2] - head);
    if (arg1 >= count % capacity)
        return 0;
    s32 *base = (s32 *)((s32 *)arg0)[0];
    s32 index = (arg1 + (capacity + head)) % capacity;
    return (s32)base + index * 12;
}

#pragma small_data off
extern "C" s32 fn_80141F7C(f32 arg0) {
    return (f32)__fabs((f64)arg0) <= *(volatile f32 *)0x80558DC4;
}
#pragma small_data on
extern "C" u8 fn_80141FA0(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x19);
}

extern "C" u8 lbl_8055E1BC;
extern "C" f32 lbl_8056149C;
#pragma small_data off
extern "C" s32 fn_80141FA8(void *arg0, f32 arg1) {
    s32 result = 1;
    if (lbl_8055E1BC != 0) {
        f32 old = *(f32 *)((u8 *)arg0 + 0x94);
        f32 v = old + arg1 / lbl_8056149C;
        if (v < lbl_805614AC) v = lbl_805614AC;
        if (v > lbl_805614A4) v = lbl_805614A4;
        f32 r = v;
        *(f32 *)((u8 *)arg0 + 0x94) = v;
        if (old < r) {
            *(f32 *)((u8 *)arg0 + 0xEC) = r - old;
        } else if ((f32)__fabs((f64)r) <= (f32)lbl_80558DC4 && (f32)__fabs((f64)old) <= (f32)lbl_80558DC4) {
            s32 n = *(s32 *)((u8 *)arg0 + 0xE4);
            if (n > 0) {
                *(s32 *)((u8 *)arg0 + 0xF4) = n;
                fn_8013CB3C();
            }
            *(s32 *)((u8 *)arg0 + 0xE4) = 0;
            n = *(s32 *)((u8 *)arg0 + 0x100);
            if (n > 0) {
                *(f32 *)((u8 *)arg0 + 0xD4) = fn_8001DAE8((u8 *)arg0 + 0xD0);
            }
            *(s32 *)((u8 *)arg0 + 0x100) = 0;
            *(f32 *)((u8 *)arg0 + 0xAC) = fn_8001DAE8((u8 *)arg0 + 0xA8);
            if (lbl_8055E1BC == 0) *(u8 *)((u8 *)arg0 + 0xF8) = 1;
            result = 0;
        }
    }
    return result;
}
#pragma small_data on
extern "C" f32 lbl_80558DC4_arr[2];
extern "C" s32 fn_801420D4(void *arg0) {
    return (f32)__fabs((f64)*(f32 *)((u8 *)arg0 + 0x2690)) <= *(volatile f32 *)0x80558DC4;
}

extern "C" void fn_80142104(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0xE8) = 0;
    *(s32 *)((u8 *)arg0 + 0x104) = 0;
    *(s32 *)((u8 *)arg0 + 0x100) = 0;
}

extern "C" S28_80142118 fn_80142118(S28_80142118 arg0) {
    return arg0;
}

extern "C" s32 fn_80142154(void *arg0) {
    s32 result = 0;
    if (*(s32 *)((u8 *)arg0 + 0x68) < *(s32 *)(*(s32 **)((u8 *)arg0 + 0x64)) - 1) {
        *(s32 *)((u8 *)arg0 + 0x68) += 1;
        *(f32 *)((u8 *)arg0 + 0x70) = fn_8001DAE8((u8 *)arg0 + 0x6C);
        *(s32 *)((u8 *)arg0 + 0x288) = fn_8013D18C(*(s32 *)((u8 *)arg0 + 0x68));
        result = 1;
    }
    return result;
}
#pragma dont_inline off
extern "C" u8 *fn_801421C0(u8 *arg0) {
    s32 index = *(s32 *)(arg0 + 0x68);
    u8 *items = *(u8 **)(arg0 + 0x64);
    return *(u8 **)(items + 4) + index * 0x14;
}

extern "C" f32 fn_8013CB3C(void);
extern "C" u8 lbl_8042FB3C[];
extern "C" void fn_801421D8(void *arg0, void *arg1) {
    u8 *a = (u8 *)arg0;
    u8 *b = (u8 *)arg1;
    f32 t, x, f;
    s32 n, m;
    u8 *row;
    *(f32 *)(b + 0xB4) = fn_8001DAE8(b + 0xB0);
    t = fn_8013CB3C() - *(f32 *)(b + 0x84);
    t = t - *(f32 *)(lbl_8042FB3C + 0x24);
    t = t - lbl_805614A4;
    t = t / (*(f32 *)(lbl_8042FB3C + 0x20) - lbl_805614A4);
    f = lbl_805614AC;
    if (f < t) f = t;
    if (f > lbl_805614A4) f = lbl_805614A4;
    x = *(f32 *)(lbl_8042FB3C + 0x1C);
    t = x + f * (lbl_805614A4 - x);
    n = 0;
    if (t > lbl_805614A4) {
        if (x < lbl_805614A4) t = x - lbl_80561498;
        else t = lbl_80561498 + x;
        n = (s32)t;
    }
    row = *(u8 **)(*(u8 **)(a + 0x64) + 4) + *(s32 *)(a + 0x68) * 0x14;
    f = *(f32 *)(lbl_8042FB3C + 0x1C) * (f32)*(s32 *)(row + 0x10) * (f32)*(s32 *)(row + 0xC);
    if (f < lbl_805614A4) t = f - lbl_80561498;
    else t = lbl_80561498 + f;
    m = (s32)t;
    if (n == m) *(s32 *)b = 3;
    else if (n > 0) *(s32 *)b = 2;
    else *(s32 *)b = 1;
    *(s32 *)(b + 0x5C) = *(s32 *)(row + 0x10);
    *(s32 *)(b + 0x48) = *(s32 *)(row + 0xC);
    *(s32 *)(b + 0x4C) = 1;
    if (*(s32 *)(b + 0x100) == *(s32 *)(lbl_8042FB3C + 4))
        *(s32 *)(b + 0x58) = (*(s32 *)(a + 0x68) + 1) * *(s32 *)(lbl_8042FB3C + 0x2C);
    else *(s32 *)(b + 0x58) = 0;
    *(s32 *)(b + 0x50) = 1;
    *(s32 *)(b + 0x54) = *(s32 *)b;
    t = fn_8013CB3C() - *(f32 *)(b + 0x84);
    t = t - *(f32 *)(lbl_8042FB3C + 0x24);
    t = t - lbl_805614A4;
    t = t / (*(f32 *)(lbl_8042FB3C + 0x20) - lbl_805614A4);
    f = lbl_805614AC;
    if (f < t) f = t;
    if (f > lbl_805614A4) f = lbl_805614A4;
    x = *(f32 *)(lbl_8042FB3C + 0x1C);
    t = x + f * (lbl_805614A4 - x);
    n = 0;
    if (t > lbl_805614A4) {
        if (x < lbl_805614A4) t = x - lbl_80561498;
        else t = lbl_80561498 + x;
        n = (s32)t;
    }
    *(s32 *)(b + 0x60) = n;
    *(s32 *)(b + 0x80) = *(s32 *)(b + 0x48) * *(s32 *)(b + 0x4C) * (*(s32 *)(b + 0x5C) * *(s32 *)(b + 0x50)) + n + *(s32 *)(b + 0x58);
    *(f32 *)(b + 0x84) = fn_8013CB3C();
    *(f32 *)(b + 0xDC) = fn_8001DAE8(b + 0xD8);
    *(f32 *)(b + 0xCC) = fn_8001DAE8(b + 0xC8);
    *(s32 *)(b + 0x10C) += *(s32 *)(b + 0x80);
    *(f32 *)(b + 0x9C) = fn_8001DAE8(b + 0x98);
    row = *(u8 **)(*(u8 **)(a + 0x64) + 4) + *(s32 *)(a + 0x68) * 0x14;
    if (lbl_8055E1BC) {
        x = *(f32 *)(b + 0x94);
        f = x + *(f32 *)(row + 8) / lbl_8056149C;
        if (f < lbl_805614AC) f = lbl_805614AC;
        if (f > lbl_805614A4) f = lbl_805614A4;
        *(f32 *)(b + 0x94) = f;
        if (x < f) *(f32 *)(b + 0xEC) = f - x;
    } else {
        x = *(f32 *)(b + 0x94);
        f = *(f32 *)(row + 8);
        if (f < 0.0f) f = -f;
        if (f > lbl_80558DC4) {
            if (x < 0.0f) x = -x;
            if (x > lbl_80558DC4) {
                n = *(s32 *)(b + 0xE4);
                if (n > 0) {
                    *(s32 *)(b + 0xF4) = n;
                    *(f32 *)(b + 0xF0) = fn_8013CB3C();
                    *(s32 *)(b + 0xE4) = 0;
                }
                if (*(s32 *)(b + 0x100) > 0) {
                    *(f32 *)(b + 0xD4) = fn_8001DAE8(b + 0xD0);
                    *(s32 *)(b + 0x100) = 0;
                }
                *(f32 *)(b + 0xAC) = fn_8001DAE8(b + 0xA8);
                if (!lbl_8055E1BC) b[0xF8] = 1;
            }
        }
    }
    row = b + *(s32 *)(b + 0x54) * 4;
    ++*(s32 *)(row + 0xC);
}

extern "C" f32 lbl_8042FB3C_arr[8];
extern "C" s32 fn_801427DC(void *arg0, s32 arg1) {
    u8 *items = *(u8 **)((u8 *)arg0 + 0x64) + 4;
    u8 *item = items + arg1 * 0x14;
    f32 scale = *(f32 *)&lbl_8042FB3C_arr[0x1C];
    f32 v = (f32)(*(s32 *)(item + 0x10) ^ 0x8000) * scale * (f32)(*(s32 *)(item + 0xC) ^ 0x8000);
    if (v < lbl_805614A4) {
        v -= lbl_80561498;
    } else {
        v += lbl_80561498;
    }
    return (s32)v;
}

extern "C" void fn_80142948(void *arg0) {
    *(f32 *)((u8 *)arg0 + 4) = fn_8001DAE8(arg0);
}

extern "C" s32 fn_80142978(void *arg0) {
    f32 diff = fn_8001DAE8(arg0) - *(f32 *)((u8 *)arg0 + 4);
    return diff >= lbl_805614A4 && diff < *(f32 *)arg0;
}

extern "C" f32 fn_801429D0(f32 arg0, f32 arg1) {
    if (!(arg0 > arg1)) return arg1;
    return arg0;
}

extern "C" f32 fn_801429E0(f32 arg0, f32 arg1) {
    if (!(arg0 < arg1)) return arg1;
    return arg0;
}

extern "C" f32 fabs(f32);
extern "C" void fn_801429F0(void *arg0) {
    u8 *p = (u8 *)arg0;
    f32 old, value, limit;
    *(f32 *)(p + 0xA4) = fn_8001DAE8(p + 0xA0);
    if (*(s32 *)(p + 0xE4) > 0) {
        *(s32 *)(p + 0xF4) = *(s32 *)(p + 0xE4);
        *(f32 *)(p + 0xF0) = fn_8013CB3C();
        *(s32 *)(p + 0xE4) = 0;
    }
    if (*(s32 *)(p + 0x100) > 0) *(f32 *)(p + 0xD4) = fn_8001DAE8(p + 0xD0);
    *(s32 *)(p + 0x100) = 0;
    if (lbl_8055E1BC) return;
    old = *(f32 *)(p + 0x94);
    value = old + lbl_8056149C / lbl_8056149C;
    limit = lbl_805614AC;
    if (limit < value) limit = value;
    if (limit > lbl_805614A4) limit = lbl_805614A4;
    *(f32 *)(p + 0x94) = limit;
    if (old < limit) { *(f32 *)(p + 0xEC) = limit - old; return; }
    if (fabs(value) < lbl_80558DC4 && fabs(old) < lbl_80558DC4) {
        if (*(s32 *)(p + 0xE4) > 0) {
            *(s32 *)(p + 0xF4) = *(s32 *)(p + 0xE4);
            *(f32 *)(p + 0xF0) = fn_8013CB3C();
            *(s32 *)(p + 0xE4) = 0;
        }
        if (*(s32 *)(p + 0x100) > 0) *(f32 *)(p + 0xD4) = fn_8001DAE8(p + 0xD0);
        *(s32 *)(p + 0x100) = 0;
        *(f32 *)(p + 0xAC) = fn_8001DAE8(p + 0xA8);
        if (!lbl_8055E1BC) *(u8 *)(p + 0xF8) = 1;
    }
}

extern "C" void fn_80142B60(void *arg0) {
    u8 *p = (u8 *)arg0;
    p[0x49] = 1;
    p[0x4B] = 0;
    p[0x4A] = 0;
}

extern "C" void fn_80142B78(void *arg0, f32 arg1) {
    if (arg1 != *(f32 *)((u8 *)arg0 + 4)) {
        *(f32 *)((u8 *)arg0 + 4) = arg1;
        *(u8 *)((u8 *)arg0 + 0x4E) = 1;
    }
}

extern "C" s32 fn_80142B94(s32 arg0, s32 arg1, s32 arg2) {
    s32 v = arg1;
    if (arg0 > v) v = arg0;
    if (v < arg2) arg2 = v;
    return arg2;
}

extern "C" s32 fn_80142BB4(void *arg0) {
    s32 count = *(s32 *)((u8 *)arg0 + 4);
    return (count + (*(s32 *)((u8 *)arg0 + 8) - *(s32 *)((u8 *)arg0 + 0xC))) % count;
}

extern "C" void *fn_80142BD8(void *arg0) {
 s32 write=*(s32 *)((u8 *)arg0+8);
 s32 count=*(s32 *)((u8 *)arg0+4);
 s32 read=*(s32 *)((u8 *)arg0+0xC);
 s32 next;
 u8 *base;
 next=(write+1)%count;
 base=*(u8 **)arg0;
 *(s32 *)((u8 *)arg0+8)=next;
 if(next==read) *(s32 *)((u8 *)arg0+0xC)=(read+1)%count;
 return base+write*12;
}

extern "C" void *fn_80142C28(void *arg0, void *arg1) {
 u8 *p=(u8 *)*(void **)((u8 *)arg0+0x64);
 s32 index=*(s32 *)((u8 *)arg0+0x68);
 u8 *entry=*(u8 **)(p+4)+index*0x14;
 u8 *items=*(u8 **)(entry+4);
 u8 *end=items+*(s32 *)entry*0x24;
 if(arg1==end-0x24) return items;
 return (u8 *)arg1+0x24;
}

#pragma dont_inline off
extern "C" void fn_80142C5C(void *arg0, u8 *arg1) {
    void *obj = fn_802C6C34(*(s32 *)(arg1 + 0x59C));
    *(f32 *)((u8 *)arg0 + 0x128) = *(f32 *)((u8 *)obj + 0x30) - *(f32 *)((u8 *)obj + 0x2C);
}

extern "C" u8 *fn_8017960C(s32);
extern "C" u32 fn_8013D148(u8 *, f32);
extern "C" void *fn_802C6C34(s32);
extern "C" u8 *fn_80142C9C(u8 *arg0, s32 arg1) {
    u8 *self = arg0;
    u8 *manager = fn_8017960C(arg1);
    u8 *base = *(u8 **)(manager + 0x270);
    u8 *object = ((TObj18 *)base)->v18();
    s32 index = *(s32 *)(self + 0x68);
    f32 value = *(f32 *)(object + 0x48);
    u8 *items = *(u8 **)(self + 0x64);
    u8 *item = *(u8 **)(items + 4) + index * 0x14;
    u32 result = fn_8013D148(item, value);
    u8 *current = *(u8 **)(items + 4);
    s32 offset = *(s32 *)(current + index * 0x14);
    u8 *end = *(u8 **)(current + 4) + offset * 0x24;
    if (result == (u32)(end - 0x24)) {
        return end;
    }
    return (u8 *)result + 0x24;
}

extern "C" s32 fn_80142D34(void) { return 0; }

extern "C" u8 *fn_80142D3C(void *arg0, s32 arg1) { return *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C; }

extern "C" u8 *fn_801B2EC0(s32);

extern "C" void fn_80143128(u8 *arg0) {
    ((TObj4C *)arg0)->v4C();
}

#pragma use_lmw_stmw off

extern "C" void fn_80143138(u8 *self, u8 *out) {
    *(s32 *)out = *(s32 *)(self + 0xBC);
    *(s32 *)(out + 4) = *(s32 *)(self + 0x130);
    *(u8 *)(out + 0xD) = ((TObj24 *)self)->v24();
    u8 *p = out + 0x10;
    *(u8 *)(out + 0xC) = 0;
    s32 off = 0;
    s32 i = 0;
    while (i < *(s32 *)(self + 0xBC)) {
        *(u8 *)(p + 0x10) = 0;
        u8 *q = ((TObj10 *)fn_801B2EC0(i))->v10();
        i++;
        *(s32 *)(p + 4) = *(s32 *)(q + 4);
        *(s32 *)(p + 8) = *(s32 *)(*(u8 **)(self + 0xB8) + off + 0x10C);
        off += 0x12C;
        p += 0x14;
    }
}

extern "C" void fn_801431F4(u8 *arg0) {
    *(u8 *)(arg0 + 0x26C) = 1;
}

extern "C" void fn_80143200(u8 *arg0) {
    *(u8 *)(arg0 + 0x26C) = 0;
}

extern "C" s32 fn_8014320C(void) {
    return 0x1008;
}

extern "C" void fn_8013D288(void);

extern "C" void fn_80143214(void) {
    fn_8013D288();
}

extern "C" void fn_801352B8(void *);
extern "C" void fn_80135D60(void *, s32);
extern "C" s32 fn_80156A40(void);
extern "C" void fn_801B8048(void *, void *, void *, f32, f32);
extern "C" void fn_8013530C(void *, s32, f32, f32, f32);
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805615A0;
extern "C" f32 lbl_805615A4;
extern "C" f32 lbl_805615A8;
extern "C" s32 fn_80143218(s32 arg0, u8 *arg1) {
    u8 obj[0x38];
    fn_801352B8(obj);
    fn_80135D60(obj, ((TObjC *)fn_80156A40())->vC(0));
    u8 *v = *(u8 **)(obj + 0x2C);
    fn_801B8048(arg1, obj, v, lbl_805614A4,
                (*(f32 *)(v + 8) - lbl_805615A0) - lbl_805615A4);
    f32 fx = *(f32 *)(arg1 + 0x18) * lbl_805615A8;
    f32 fy = *(f32 *)(arg1 + 0x1C) * lbl_805615A8;
    f32 fz = *(f32 *)(arg1 + 0x20) * lbl_805615A8;
    *(f32 *)(arg1 + 0x30) = fx;
    *(f32 *)(arg1 + 0x34) = fy;
    *(s32 *)(arg1 + 0x44) = 1;
    *(f32 *)(arg1 + 0x38) = fz;
    fn_8013530C(obj, -1, fy, fx, lbl_805615A8);
    return 1;
}

extern "C" void fn_801B8A68(void *, s32);
extern "C" void fn_801432D4(TObj20b *arg0, s32 arg1) {
    u8 *obj = *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C;
    s32 zero = 0;
    if (obj[0x118] != 0 && arg0->v20() != 0) {
        *(s32 *)(obj + 0x104) = zero;
        if (*(s32 *)(obj + 0xE4) > 0) {
            *(s32 *)(obj + 0xF4) = *(s32 *)(obj + 0xE4);
            *(f32 *)(obj + 0xF0) = fn_8013CB3C();
            *(s32 *)(obj + 0xE4) = zero;
        }
        if (*(s32 *)(obj + 0x100) > 0) {
            *(f32 *)(obj + 0xD4) = fn_8001DAE8(obj + 0xD0);
        }
        *(s32 *)(obj + 0x100) = zero;
    }
    fn_801B8A68(arg0, arg1);
}

class VTable43398 { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); }; extern "C" void fn_80143398(void *arg0) { ((VTable43398 *)arg0)->f41(); }

extern f32 lbl_805615B0;
extern "C" f32 fn_80143C44(void) {
    return lbl_805615B0;
}

extern "C" u32 fn_80143C4C(void) { return 1; }

extern "C" s32 fn_802ADDD8(s32);
extern "C" void fn_80143DC8(void *);
extern "C" void fn_80143CB0(void *);
extern "C" char lbl_8032CD54[];
extern "C" void fn_80143C54(void *arg0) {
    s32 value;
    void **check = fn_801284F8(8, lbl_8032CD54);
    if (check != 0) {
        value = ((s32 (*)(void *, s32))fn_802ADDD8)(check, 1);
        *(s32 *)((u8 *)arg0 + 0x140) = value;
    }
    volatile u8 *p = (volatile u8 *)arg0;
    fn_80143DC8((void *)(p + 0x134));
    fn_80143CB0((void *)(p + 0x134));
}

extern "C" void fn_801442D4(void) {

}

extern "C" void fn_801442D8(void) {

}

extern "C" void fn_801442DC(void *arg0) {
    class TObj20 {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
    };
    ((TObj20 *)arg0)->f6();
}

extern "C" s32 fn_801442EC(void) { return 0; }

extern "C" s32 fn_801442F4(void) { return 0; }

extern "C" void fn_801442FC(void) {
}

extern "C" void fn_80144300(void) {
}

extern "C" void fn_80144308(void) {
}

extern "C" void fn_80144304(void) {
}

extern "C" void fn_8014430C(void) {
}

extern "C" void fn_80144310(void) {
}

extern "C" s32 fn_80144314(void) { return 0; }

extern "C" s32 fn_8014431C(void) { return 0; }

extern "C" s32 fn_80144324(void) { return 0; }

extern "C" s32 fn_8014432C(void) { return 0; }

extern "C" void fn_80144334(void) {
}

extern "C" void fn_80144338(void) {
}

extern "C" void fn_8014433C(void) {
}

extern "C" void fn_80144340(void) {
}

extern "C" s32 fn_80144344(void) { return 0; }

extern "C" void fn_8014434C(void) {
}

extern "C" s32 fn_80144350(void) { return 0; }

extern "C" void fn_80144358(void) {
}

extern "C" u32 fn_8014435C(void) { return 1; }

extern "C" s32 fn_80144364(void) { return 0; }

extern "C" s32 fn_8014436C(TObj20 *arg0, s32 arg1) {
    s32 result = 0;
    if (fn_801B8514() != 0 && arg0->v20(arg1) == 0)
        result = 1;
    return result;
}

extern "C" s32 fn_801B8514(void);
extern "C" s32 fn_801443E0(void) { return 0; }

extern "C" u32 fn_801443E8(void) { return 1; }

extern "C" s32 fn_801443F0(void) { return 0; }

extern "C" s32 fn_801443F8(void) { return 0; }

extern "C" s32 fn_80144400(void) { return 0; }

extern "C" void fn_80144408(void) {

}

extern "C" void fn_80128668(void);
extern "C" s32 fn_8014440C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern "C" s32 fn_8014444C(void) { return 0; }

extern "C" s32 fn_80144454(void) { return 0; }

extern "C" s32 fn_8013D1F0(s32);
#pragma dont_inline on
extern "C" s32 fn_8014445C(s32 arg0, s32 arg1) {
    s32 v = fn_8013D1F0(arg1) ^ 0xA;
    return ((v >> 1) - (v & 0xA)) < 0;
}
#pragma dont_inline reset
extern "C" s32 fn_80144494(s32 arg0, s32 arg1) { return arg1; }
struct Fn8013FC6CDispatch {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual int test(int);
};
class TObj10DispatchA6C { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void v10(const char *); };
struct TObj24A { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void *v24(); };
struct S3FAC4 { s32 a, b, c, d; f32 e, f, g, h, i, j; };
struct S32_80140728 { s32 v[8]; f32 f[6]; };
extern "C" f32 lbl_805614C4;
extern "C" u8 lbl_8032C530[0x500];
extern "C" void fn_80147BD0(s32, s32, s32, s32, s32, f32);
