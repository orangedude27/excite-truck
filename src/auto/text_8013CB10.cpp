#include "types.h"
extern "C" s32 fn_801E9E30(void *, f32 *);
extern "C" s32 fn_80136594(void **, s32, f32 *, f32);
extern "C" s32 fn_80178C9C(void);
extern "C" void qsort(void *, u32, u32, int (*)(const void *, const void *));
extern "C" void *memset(void *, s32, u32);
extern "C" void fn_802AE0E0(int);
extern "C" f32 lbl_80561594;
extern "C" f32 lbl_80561598;
extern "C" f32 lbl_8056159C;
extern "C" f32 fn_8001DAF0(f32 *);
extern "C" u8 lbl_8042FB3C[];
extern "C" void fn_802ADE60(int, int);
extern "C" void fn_8001DAE0(void *, f32);
extern "C" f32 lbl_805614FC;
extern "C" f32 lbl_80561500;
#pragma small_data off
extern "C" f32 lbl_80558DC4;
#pragma small_data on
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
    virtual void d18(); virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22(); virtual void d23();
    virtual s32 v68(); // 0x68
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

class TObj60 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21();
    virtual s32 v60(s32);
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

class TDispatchStringInt20 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual s32 v20(const char *, s32);
};

class TDispatchStringFloat28 {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual f32 v28(const char *, f32);
};

extern "C" u8 lbl_8032C530[0x500];
extern "C" f32 lbl_805614E0;
extern "C" f32 lbl_805614E4;
extern "C" f32 lbl_805614E8;
extern "C" f32 lbl_805614EC;
extern "C" f32 lbl_805614F0;
extern "C" f32 lbl_805614F4;
extern "C" f32 lbl_805614F8;
extern "C" f64 lbl_805614D8;
extern "C" f32 fn_80204CFC(const char *);

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

#pragma dont_inline on
extern "C" void fn_8013CB90(void *arg0) {
    f32 x = *(f32 *)((u8 *)arg0 + 0x10);
    f32 scale = lbl_80561498;
    f32 y = *(f32 *)((u8 *)arg0 + 0x14);
    *(f32 *)((u8 *)arg0 + 4) = *(f32 *)((u8 *)arg0 + 4) - x * scale;
    *(f32 *)((u8 *)arg0 + 8) = *(f32 *)((u8 *)arg0 + 8) - y * scale;
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
    struct {
        s32 v[6];
    } values = {{
        lbl_802F9398[0], lbl_802F9398[1], lbl_802F9398[2],
        lbl_802F9398[3], lbl_802F9398[4], lbl_802F9398[5]
    }};
    return values.v[arg0 % 6];
}

extern "C" s32 fn_8013D1F0(s32 arg0) {
    u8 *obj = ((u8 *(*)(void))fn_801B2EC0)();
    u8 *(*fn)(u8 *) = (u8 *(*)(u8 *))(*(void ***)obj)[4];
    obj = fn(obj);
    return *(s32 *)(obj + 0x10);
}

extern "C" s32 fn_8013D224(f32 farg0, f32 farg1) {
    f32 diff = farg0 - farg1;
    f32 result;
    if ((f32)__fabs((f64)diff) <= lbl_80558DC4) {
        return 0;
    }
    if (diff > lbl_805614A4) {
        result = lbl_805614AC;
    } else {
        result = lbl_805614BC;
    }
    return (s32)result;
}

extern "C" void fn_8013D27C(void *a, void *b) {
    fn_8013D224(*(f32 *)((u8 *)a + 0x18), *(f32 *)((u8 *)b + 0x18));
}

extern "C" u8 lbl_8032CAC0_vt[48];
extern "C" void **fn_801284F8(s32, void *);
extern "C" char lbl_80559D18[5];
#pragma dont_inline on
#pragma scheduling invalid_target
extern "C" void fn_8013D288(void) {
    void **slot = fn_801284F8(4, (void *)lbl_80559D18);
    if (slot != 0) {
        *slot = (void *)lbl_8032CAC0_vt;
    }
}
#pragma scheduling on
#pragma dont_inline off

extern "C" s32 fn_8013D890(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

#pragma dont_inline off

#pragma dont_inline on
extern "C" s32 fn_8013DDD4(TObjC *arg0, const char *arg1) {
    s32 count = 0;
    s32 i = 0;

    while (arg0->vC(i) != 0) {
        if (fn_8013CB44(arg1, (TObj10 *)arg0->vC(i))) {
            count++;
        }
        i++;
    }
    return count;
}

#pragma dont_inline on
extern "C" s32 fn_8013DE7C(TObj60 *arg0, const char *arg1) {
    s32 count = 0;
    s32 i = 0;

    while (arg0->v60(i) != 0) {
        if (fn_8013CB44(arg1, (TObj10 *)arg0->v60(i))) {
            count++;
        }
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

extern "C" f32 PSQUATMultiply(void *, void *);
extern "C" f32 lbl_80561498, lbl_805614A4;
extern "C" void fn_8013E19C(void *arg0, f32 arg1) {
 f32 *p=(f32*)arg0;
 p[4]=lbl_805614A4; p[1]=lbl_805614A4;
 f32 t=arg1/PSQUATMultiply(arg0,(char*)arg0+0xC);
 f32 a=p[5]; f32 b=p[2]; f32 c=p[4]; f32 d=p[1]; f32 e=p[3]; f32 g=p[0];
 f32 x=b+lbl_80561498*(a-b);
 f32 y=d+lbl_80561498*(c-d);
 f32 z=g+lbl_80561498*(e-g);
 f32 bx=b-x, by=d-y, bz=g-z;
 f32 ax=a-x, ay=c-y, az=e-z;
 f32 qx=x+t*bx, qy=y+t*by, qz=z+t*bz;
 f32 rx=x+t*ax, ry=y+t*ay, rz=z+t*az;
 p[2]=qx; p[0]=qz; p[1]=qy; p[3]=rz; p[4]=ry; p[5]=rx;
}

extern "C" void fn_8013E2AC(void *arg0, void *arg1) {
    volatile u32 *src = (volatile u32 *)arg1;
    u32 word5, word4, word3, word2, word1, word0;
    f32 value3, value2, value1, value0;
    s16 half;
    u8 byte;

    word0 = src[0];
    word1 = src[1];
    word2 = src[2];
    word3 = src[3];
    word4 = src[4];
    word5 = src[5];
    value0 = *(volatile f32 *)((u8 *)arg1 + 0x18);
    half = *(volatile s16 *)((u8 *)arg1 + 0x1C);
    byte = *((volatile u8 *)arg1 + 0x1E);
    value3 = *(volatile f32 *)((u8 *)arg1 + 0x20);

    ((u32 *)arg0)[0] = word0;
    ((u32 *)arg0)[1] = word1;
    ((u32 *)arg0)[2] = word2;
    ((u32 *)arg0)[3] = word3;
    ((u32 *)arg0)[4] = word4;
    ((u32 *)arg0)[5] = word5;
    *(f32 *)((u8 *)arg0 + 0x18) = value0;
    *(s16 *)((u8 *)arg0 + 0x1C) = half;
    *((u8 *)arg0 + 0x1E) = byte;
    *(f32 *)((u8 *)arg0 + 0x20) = value3;
}

#pragma dont_inline off
extern "C" f64 fn_8002F234(f32);
#pragma processor 750
extern "C" f32 fn_8013E300(void *arg0) {
    f32 y = *(f32 *)((u8 *)arg0 + 4);
    f32 x = *(f32 *)arg0;
    return (f32)fn_8002F234(x * x + y * y);
}
extern "C" void fn_8013E338(void) {

}

extern "C" void *fn_8013E33C(void *arg0, s32 arg1) {
    void *field;
    if (arg0 != 0) {
        field = *(void **)((u8 *)arg0 + 4);
        if (field != 0) {
            fn_80128670((s32)field - 0x10);
        }
        *(void **)((u8 *)arg0 + 4) = 0;
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}

#pragma scheduling invalid_target
extern "C" void fn_8013E3A8(void *arg0, void *arg1) {
    u8 *dst = (u8 *)arg0;
    u8 *base = lbl_8032C530;
    s32 value;
    f32 fvalue;
    f32 scale;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x210), 0x19);
    else value = 0x19;
    *(s32 *)(dst + 0xC) = value;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x220), 0xA);
    else value = 0xA;
    *(s32 *)(dst + 4) = value;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x230), lbl_805614E0);
    else fvalue = lbl_805614E0;
    *(f32 *)(dst + 0) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x248), lbl_805614E4);
    else fvalue = lbl_805614E4;
    *(f32 *)(dst + 8) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x258), lbl_805614E8);
    else fvalue = lbl_805614E8;
    *(f32 *)(dst + 0x10) = fvalue;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x270), 0xA);
    else value = 0xA;
    *(s32 *)(dst + 0x14) = value;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x280), lbl_805614EC);
    else fvalue = lbl_805614EC;
    *(f32 *)(dst + 0x18) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x290), lbl_805614AC);
    else fvalue = lbl_805614AC;
    *(f32 *)(dst + 0x1C) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x29C), lbl_805614F0);
    else fvalue = lbl_805614F0;
    *(f32 *)(dst + 0x24) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x2B0), lbl_805614AC);
    else fvalue = lbl_805614AC;
    *(f32 *)(dst + 0x20) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x2C0), lbl_805614F4);
    else fvalue = lbl_805614F4;
    *(f32 *)(dst + 0x28) = fvalue;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x2D4), lbl_805614E8);
    else fvalue = lbl_805614E8;
    *(f32 *)(dst + 0x30) = fvalue;

    if (arg1) value = ((TDispatchStringInt20 *)arg1)->v20((const char *)(base + 0x2E8), 0x186A0);
    else value = 0x186A0;
    *(s32 *)(dst + 0x2C) = value;

    if (arg1) fvalue = ((TDispatchStringFloat28 *)arg1)->v28((const char *)(base + 0x300), lbl_805614AC);
    else fvalue = lbl_805614AC;
    *(f32 *)(dst + 0x38) = fvalue;

    *(f32 *)(dst + 0x34) = fn_80204CFC((const char *)(base + 0x310));
    scale = fn_80204CFC((const char *)(base + 0x200));
    *(f32 *)(dst + 0x24) = lbl_805614F8;
    *(s32 *)(dst + 0x2C) = (s32)((f32)*(s32 *)(dst + 0x2C) * scale);
}
#pragma scheduling invalid_target
extern "C" void *fn_8013E6E4(void *arg0) {
    register f32 first;
    void *field;

    first = *(volatile f32 *)&lbl_805614AC;
    field = (u8 *)arg0 + 0x98;
    fn_8001DAE0(field, first);
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
#pragma scheduling on
extern "C" void fn_802C6CF8(s32);
extern "C" void fn_802CAC54(s32);
extern "C" void fn_8002F6AC(s32, void *);
extern "C" void *fn_8013E33C(void *, s32);
extern "C" void *__dt__Q210JASDrumSet5TPercFv(void *, s32);
extern "C" u8 lbl_8032CAF0[];
extern "C" s32 lbl_8055E1C0;
extern "C" void *fn_8013E77C(void *arg0, s32 arg1) {
    class VObj { public: virtual void destroy(int); };
    u8 *self=(u8 *)arg0;
    VObj *p;
    VObj *child;
    s32 i,offset;
    if (self != 0) {
        child=*(VObj **)(self+0x254);
        *(void **)self=lbl_8032CAF0;
        if (child != 0) { if (child != 0) child->destroy(1); }
        fn_802C6CF8(*(s32 *)(self+0xB4));
        i=0; offset=0;
        while (i<*(s32 *)(self+0xC)) {
            p=*(VObj **)(*(u8 **)(self+8)+offset);
            if (p != 0) p->destroy(1);
            offset+=4; i++;
        }
        fn_802CAC54(*(s32 *)(self+0xA0));
        fn_802CAC54(*(s32 *)(self+0xA4));
        fn_802CAC54(*(s32 *)(self+0xA8));
        fn_802CAC54(*(s32 *)(self+0xAC));
        fn_802CAC54(*(s32 *)(self+0xB0));
        p=*(VObj **)(self+0x64);
        if (p != 0) {
            fn_8002F6AC(*(s32 *)((u8 *)p+4),(void *)fn_8013E33C);
            *(s32 *)((u8 *)p+4)=0;
            ((void (*)(void *))fn_80128668)(p);
        }
        p=*(VObj **)(self+0x27C);
        *(VObj **)(self+0x64)=0;
        if (p != 0) p->destroy(1);
        p=*(VObj **)(self+0x278);
        *(VObj **)(self+0x27C)=0;
        if (p != 0) p->destroy(1);
        p=*(VObj **)(self+0x270);
        *(VObj **)(self+0x278)=0;
        if (p != 0) p->destroy(1);
        p=*(VObj **)(self+0x274);
        *(VObj **)(self+0x270)=0;
        if (p != 0) p->destroy(1);
        p=*(VObj **)(self+0x60);
        *(VObj **)(self+0x274)=0;
        if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x60)=0; }
        p=*(VObj **)(self+0xB8);
        if (p != 0) fn_80128670((s32)p-0x10);
        *(VObj **)(self+0xB8)=0;
        lbl_8055E1C0=0;
        __dt__Q210JASDrumSet5TPercFv(self+0x280,-1);
        if ((u32)self+0x134 != 0) {
            p=*(VObj **)(self+0x140);
            if (p != 0) { fn_802ADE60((s32)p,1); *(VObj **)(self+0x140)=0; }
            p=*(VObj **)(self+0x148);
            if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x148)=0; }
            p=*(VObj **)(self+0x14C);
            if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x14C)=0; }
            p=*(VObj **)(self+0x150);
            if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x150)=0; }
            p=*(VObj **)(self+0x158);
            if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x158)=0; }
            p=*(VObj **)(self+0x15C);
            if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x15C)=0; }
            p=*(VObj **)(self+0x160);
            if (p != 0) { if (p != 0) p->destroy(1); *(VObj **)(self+0x160)=0; }
        }
        if ((u32)self+0xC0 != 0) { if ((u32)self+0xC0 != 0) *(s32 *)(self+0xC0)=0; }
        if ((u32)self+8 != 0) {
            if ((u32)self+8 != 0) {
                if ((u32)self+8 != 0) {
                    *(s32 *)(self+8)=0; *(s32 *)(self+0xC)=0; *(s32 *)(self+0x10)=0;
                }
            }
        }
        if (arg1>0) ((void (*)(void *))fn_80128668)(arg0);
    }
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

#pragma scheduling invalid_target
extern "C" unsigned int fn_8013EFC8(void *arg0) {
    f32 magnitude = __fabsf(*(f32 *)((u8 *)arg0 + 0x250));
    if (magnitude <= lbl_80558DC4) {
        if (*(u8 *)((u8 *)arg0 + 0x13C) != 0)
            ((TObj4C *)arg0)->v4C();
        s32 object = *(s32 *)((u8 *)arg0 + 0x140);
        if (object != 0)
            ((void (*)(s32, s32))fn_802AE220)(object, 0);
    } else {
        ((TObj4C *)arg0)->v4C();
    }
    if (((TObj4C *)arg0)->v68())
        fn_8001DFCC();
    return *(s32 *)((u8 *)arg0 + 0x134) != 4;
}
#pragma scheduling on
extern "C" s32 fn_8013F088(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x134) - 2) == 0;
}

extern "C" void fn_8013F09C(void) {
    ((void(*)())fn_80140A6C)();
}

extern "C" f32 lbl_80561520;
extern "C" f32 lbl_80561524;
extern "C" f32 lbl_80561528;
extern "C" f32 lbl_8056152C;
extern "C" f32 lbl_80561534;
extern "C" void fn_80147F30(unsigned long, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void *fn_80147C50(u32, s32, f32);
extern "C" void fn_801476D8(void *, void *, s32);
extern "C" void fn_80147EE0(void *, f32);
#pragma scheduling invalid_target
extern "C" void fn_8013F0A0(void *arg0, void *arg1, void *arg2) {
    struct VStringFloat { virtual void d0(); virtual void d1(); virtual u8 *v10(const char *, f32); };
    struct RenderData { u32 f0; f32 f4; f32 f8; u32 fC; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; };
    f32 delta, progress, normalized, scale, factor, f27, f29, f28;
    register u8 *dataObj;
    register char *labels;
    s32 drawCount, active = 0;
    s32 enabled;
    void *result;
    void *firstResult;
    RenderData data;
    enabled = *(s32 *)((u8 *)arg2 + 0x104);
    dataObj = (u8 *)arg2;
    labels = (char *)lbl_8032C530;
    if (enabled != 0) {
        delta = fn_8001DAE8(dataObj + 0xC8) - *(f32 *)(dataObj + 0xCC);
        scale = lbl_805614A4;
        active = 0;
        if (delta >= scale) {
            if (delta < *(f32 *)(dataObj + 0xC8)) active = 1;
        }
        if (active != 0) {
            delta = (fn_8001DAF0((f32 *)(dataObj + 0xC8)) - lbl_80561498) / lbl_80561498;
            factor = lbl_805614AC;
            if (factor < delta) factor = delta;
            if (factor > lbl_805614A4) factor = lbl_805614A4;
            scale = lbl_805614A4 + factor * lbl_805614AC;
        } else scale = lbl_805614AC;
        delta = fn_8013CB3C() - *(f32 *)(dataObj + 0x84);
        delta -= *(f32 *)(lbl_8042FB3C + 0x24);
        delta -= lbl_805614A4;
        delta /= *(f32 *)(lbl_8042FB3C + 0x20) - lbl_805614A4;
        normalized = lbl_805614AC;
        if (normalized < delta) normalized = delta;
        if (normalized > lbl_805614A4) normalized = lbl_805614A4;
        factor = normalized * lbl_805614BC;
        progress = lbl_805614AC + factor;
        firstResult = ((VStringFloat *)*(void **)((u8 *)arg0 + 0x54))->v10(labels + 0x394, factor);
        f28 = *(f32 *)((u8 *)firstResult + 0x10) * scale;
        f27 = *(f32 *)((u8 *)firstResult + 4);
        f29 = *(f32 *)((u8 *)firstResult + 8);
        drawCount = (s32)(lbl_80561520 * progress);
        if (drawCount > 0) {
            fn_80147F30((unsigned long)0xFF00FF00, drawCount, *(s32 *)((u8 *)arg0 + 0xB0), f27, f29, f28, lbl_805614A4, lbl_80561524, lbl_80561528, lbl_805614A4, lbl_805614A4);
            fn_80147F30((unsigned long)0xFF000000, 1, *(s32 *)((u8 *)arg0 + 0xB0), f27, f29, f28, lbl_805614A4, lbl_80561524, lbl_8056152C, lbl_805614A4, lbl_805614A4);
            fn_80147F30((unsigned long)0xFF000000, 1, *(s32 *)((u8 *)arg0 + 0xB0), f27, f29, f28, lbl_805614A4, lbl_80561524 + lbl_80561528 * (f32)drawCount, lbl_8056152C, lbl_805614A4, lbl_805614A4);
        }
        ((VStringFloat *)*(void **)((u8 *)arg0 + 0x54))->v10(labels + 0x3A0, 0.0f);
        result = ((VStringFloat *)*(void **)((u8 *)arg0 + 0x54))->v10(labels + 0x3B0, 0.0f);
        data = *(RenderData *)result;
        data.f4 = *(f32 *)((u8 *)firstResult + 4);
        data.f8 = *(f32 *)((u8 *)firstResult + 8);
        fn_8013CB90(&data);
        fn_80147EE0(&data, scale);
        delta = (progress - lbl_80561530) / lbl_80561534;
        factor = lbl_805614AC;
        if (factor < delta) factor = delta;
        if (factor > lbl_805614A4) factor = lbl_805614A4;
        fn_801476D8(&data, fn_80147C50(0xFFFFFF, -1, lbl_805614AC + factor * lbl_805614BC), *(s32 *)((u8 *)arg0 + 0xAC));
    }
}
#pragma scheduling on
extern "C" void fn_8013F434(void) {

}

extern "C" f32 lbl_80561530;
extern "C" f32 lbl_80561538;
extern "C" f32 lbl_8056153C;
extern "C" f32 lbl_80561540;
extern "C" f32 lbl_805614A4, lbl_805614AC, lbl_80561530, lbl_80561538, lbl_8056153C, lbl_80561540;
#pragma scheduling invalid_target
extern "C" s32 fn_8013F438(f32 x) {
    f32 t = (x - lbl_80561530) / lbl_80561538;
    f32 v = (lbl_805614AC < t) ? lbl_805614AC : t;
    v = (v > lbl_805614A4) ? lbl_805614A4 : v;
    return (s32)(lbl_8056153C + v * lbl_80561540);
}
#pragma scheduling on
extern float lbl_805614A4, lbl_805614AC, lbl_805614F8, lbl_80561518, lbl_80561544, lbl_80561548;
extern "C" void fn_8013F498(void *arg0, void *arg1, f32 farg0) {
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 var_f3;
    f32 var_f4;
    f64 temp_f2;
    f64 temp_f5;

    var_f3 = lbl_805614AC;
    temp_f0 = (farg0 - lbl_805614A4) / var_f3;
    if (var_f3 < temp_f0) {
    } else {
        var_f3 = temp_f0;
    }
    if (var_f3 > lbl_805614A4) {
    } else {
        var_f3 = lbl_805614A4;
    }
    var_f4 = lbl_805614AC;
    temp_f0_2 = ((farg0 * farg0) - lbl_805614A4) / var_f4;
    temp_f6 = lbl_80561544 + (var_f3 * lbl_805614F8);
    temp_f8 = temp_f6 * lbl_80561518;
    if (var_f4 < temp_f0_2) {
    } else {
        var_f4 = temp_f0_2;
    }
    if (var_f4 > lbl_805614A4) {
    } else {
        var_f4 = lbl_805614A4;
    }
    temp_f5 = -temp_f6;
    temp_f2 = -temp_f8;
    sp18 = lbl_805614A4;
    temp_f7 = lbl_805614A4 + (var_f4 * lbl_80561548);
    sp1C = temp_f7;
    *(f32 *)arg0 = lbl_805614A4 + (f32)temp_f5;
    *(f32 *)((u8 *)arg0 + 4) = temp_f7 + temp_f8;
    sp10 = (f32)temp_f5;
    sp14 = temp_f8;
    sp8 = temp_f6;
    spC = (f32)temp_f2;
    *(f32 *)arg1 = lbl_805614A4 + temp_f6;
    *(f32 *)((u8 *)arg1 + 4) = temp_f7 + (f32)temp_f2;
}

#pragma scheduling invalid_target
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
#pragma scheduling on
extern "C" int fn_8013FD20(void *arg0, int arg1) {
    int result = 1;
    int valid = 0;
    if (*(int *)(*(char **)((char *)arg0 + 0xB8) + arg1 * 0x12C + 0x11C) != 0) {
        float diff = fn_8001DAE8((char *)arg0 + 0x74) -
                     *(float *)((char *)arg0 + 0x78);
        if (diff >= lbl_805614A4 && diff < *(float *)((char *)arg0 + 0x74)) {
            valid = 1;
        }
        if (valid == 0) {
            result = 0;
        }
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

extern "C" void fn_8013EB30(void);
extern "C" void fn_80140B98(void *, void *, s32);
extern "C" void fn_80141558(void *, s32, s32, s32);
extern "C" void fn_80140D1C(void *arg0, void *arg1, void *arg2) {
 f32 buffer[16]; f32 *dst=buffer; s32 count=*(s32 *)((u8 *)arg1+4)-1, idx=0, i, cap, head, end; u8 *item;
 fn_8013EB30();
 while(count>=0){ item=*(u8 **)(*(u8 **)arg1+count*8);
 if(item[0x1E]){ if(idx>0){fn_80141558((u8 *)arg0+0x280,(s32)dst,idx,*(s32 *)((u8 *)arg0+0x288));idx=0;} fn_80140B98(arg0,*(void **)(*(u8 **)arg1+count*8),2);}
 else {dst[idx*3]=*(f32 *)item;dst[idx*3+1]=*(f32 *)(item+4);dst[idx*3+2]=*(f32 *)(item+8);idx++;dst[idx*3]=*(f32 *)(item+0xC);dst[idx*3+1]=*(f32 *)(item+0x10);dst[idx*3+2]=*(f32 *)(item+0x14);idx++;} count--;}
 if(idx>0){fn_80141558((u8 *)arg0+0x280,(s32)dst,idx,*(s32 *)((u8 *)arg0+0x288));idx=0;}
 i=0; do {cap=*(s32 *)((u8 *)arg0+0xC4);head=*(s32 *)((u8 *)arg0+0xCC);end=(cap+(*(s32 *)((u8 *)arg0+0xC8)-head))%cap;if(i>=end)break;item=*(u8 **)((u8 *)arg0+0xC0);fn_80140B98(arg0,*(void **)(item+((i+cap+head)%cap)*12+8),4);i++;}while(1);
}

extern "C" void fn_80141454(void) {

}

extern "C" void fn_80141458(void) {

}

extern "C" char lbl_8032CA94[];
extern "C" void fn_8013D2C4(void *, void *);
extern "C" void fn_8014145C(void *arg0) {
    void **object = fn_801284F8(0x298, lbl_8032CA94);
    if (object != 0) {
        fn_8013D2C4(object, arg0);
    }
}

extern "C" char lbl_8032CAA0[];
extern "C" char lbl_8032CAB0[];
extern "C" void *fn_802CAC28(const char *, s32);
extern "C" void *fn_801414A4(void *arg0) {
    void **fields = (void **)arg0;
    fields[0] = fn_802CAC28(lbl_8032CAA0, 0);
    fields[1] = fn_802CAC28(lbl_8032CAB0, 0);
    return arg0;
}

extern "C" void *__dt__Q210JASDrumSet5TPercFv(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802CAC54(*(s32 *)arg0);
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 4));
        if (arg1 > 0) ((void (*)(void *))fn_80128668)(arg0);
    }
    return arg0;
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

extern "C" u8 *fn_80131234(const char *);
extern "C" char lbl_80559D80[1];
extern "C" char lbl_8032CC64[];
#pragma push
#pragma scheduling invalid_target
extern "C" void fn_80141DAC(char *arg0) {
    {
        char *src = (char *)fn_80131234(lbl_8032CC64);
        char c;
        long len = 20;
        char *dst = arg0 + 0xEE;

        goto copy_a;
    check_a:
        if (--len > 0)
            goto copy_a;
        dst[-1] = 0;
        goto done_a;
    copy_a:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_a;
        goto check_a;
    done_a:
        ;
    }

    {
        char c;
        char *src = lbl_80559D80;
        long len = 20;
        char *dst = arg0 + 0xC6;

        goto copy_b;
    check_b:
        if (--len > 0)
            goto copy_b;
        dst[-1] = 0;
        goto done_b;
    copy_b:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_b;
        goto check_b;
    done_b:
        ;
    }

    {
        char c;
        char *src = lbl_80559D80;
        long len = 20;
        char *dst = arg0 + 0xDA;

        goto copy_c;
    check_c:
        if (--len > 0)
            goto copy_c;
        dst[-1] = 0;
        goto done_c;
    copy_c:
        c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            goto done_c;
        goto check_c;
    done_c:
        ;
    }
}
#pragma pop
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
    return !((f32)__fabs((f64)*(f32 *)((u8 *)arg0 + 0x2690)) <= *(volatile f32 *)0x80558DC4);
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
#pragma scheduling invalid_target
extern "C" s32 fn_801427DC(void *arg0, s32 arg1) {
    u8 *table = *(u8 **)((u8 *)arg0 + 0x64);
    u8 *items = *(u8 **)(table + 4);
    u8 *item = items + arg1 * 0x14;
    f32 first = (f32)*(s32 *)(item + 0x10);
    f32 scale = *(f32 *)(lbl_8042FB3C + 0x1C);
    f32 second = (f32)*(s32 *)(item + 0xC);
    f32 value = first * scale * second;
    if (value < lbl_805614A4) {
        value -= lbl_80561498;
    } else {
        value += lbl_80561498;
    }
    return (s32)value;
}
#pragma scheduling on
extern "C" s32 fn_80142870(void *arg0, void *arg1) {
    f32 time = fn_8013CB3C() - *(f32 *)((u8 *)arg1 + 0x84);
    time -= *(f32 *)(lbl_8042FB3C + 0x24);
    f32 one = lbl_805614A4;
    f32 span = *(f32 *)(lbl_8042FB3C + 0x20);
    f32 value = lbl_805614AC;
    f32 position = *(f32 *)(lbl_8042FB3C + 0x1C);
    time -= one;
    f32 ratio = time / (span - one);

    value = value < ratio ? ratio : value;
    value = value > lbl_805614A4 ? lbl_805614A4 : value;

    f32 result = position + value * (lbl_805614A4 - position);
    if (result > lbl_805614A4) {
        f32 current = *(f32 *)(lbl_8042FB3C + 0x1C);
        f32 rounded;
        if (!(current < lbl_805614A4)) {
            rounded = lbl_80561498 + current;
        } else {
            rounded = current - lbl_80561498;
        }
        return (s32)rounded;
    }
    return 0;
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

#pragma push
#pragma scheduling invalid_target
#pragma opt_propagation off
extern "C" void *fn_80142BD8(void *arg0) {
    s32 *ring = (s32 *)arg0;
    s32 write = ring[2];
    s32 count = ring[1];
    s32 next;
    s32 read = ring[3];
    u8 *base;
    void *result;

    next = (write + 1) % count;
    base = (u8 *)ring[0];
    result = base + write * 12;
    ring[2] = next;
    if (next == read)
        ring[3] = (read + 1) % count;
    return result;
}
#pragma pop
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
    struct Object {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual u8 *get();
    };
    register u8 *self = arg0;
    u8 *manager = (u8 *)fn_8017960C(arg1);
    u8 *base = *(u8 **)(manager + 0x270);
    u8 *object = ((Object *)base)->get();
    s32 index = *(s32 *)(self + 0x68);
    f32 value = *(f32 *)(object + 0x48);
    u8 *items = *(u8 **)(self + 0x64);
    u8 *item = *(u8 **)(items + 4) + index * 0x14;
    u8 *result = (u8 *)fn_8013D148(item, value);

    index = *(s32 *)(self + 0x68);
    items = *(u8 **)(self + 0x64);
    base = *(u8 **)(items + 4);
    s32 offset = *(s32 *)(base += index * 0x14);
    u8 *array = *(u8 **)(base + 4);
    u8 *end = array + offset * 0x24;
    u8 *out = array;
    if (result != end - 0x24) {
        out = result + 0x24;
    }
    return out;
}

extern "C" s32 fn_80142D34(void) { return 0; }

extern "C" u8 *fn_80142D3C(void *arg0, s32 arg1) { return *(u8 **)((u8 *)arg0 + 0xB8) + arg1 * 0x12C; }

#pragma scheduling invalid_target
extern "C" void fn_80142D4C(void *arg0) {
    u8 *self = (u8 *)arg0;
    {
        register f32 spread = lbl_80561498;
        s32 groupIndex, groupOffset;

    lbl_8055E1BC = 0;
    *(u8 *)(self + 0x294) = 0;
    *(s32 *)(self + 0x28C) = 0;
    groupIndex = 0;
    groupOffset = 0;
    for (; groupIndex < *(s32 *)(*(u8 **)(self + 0x64)); groupOffset += 0x14, groupIndex++) {
        s32 itemOffset, itemIndex;
        u8 *group;
        u8 *groupBase = *(u8 **)(*(u8 **)(self + 0x64) + 4);
        group = groupBase + groupOffset;
        itemIndex = 0;
        itemOffset = 0;
        for (; itemIndex < *(s32 *)group; itemOffset += 0x24, itemIndex++) {
            u8 *item = *(u8 **)(group + 4) + itemOffset;
            {
                u8 *point;
                u32 vertex;
                vertex = 0;
                point = item;
                do {
                    fn_801E9E30(point + 0x1C, (f32 *)point);
                    *(f32 *)(point + 4) += spread;
                    point += 0xC;
                    vertex++;
                } while (vertex < 2);
            }
            {
                f32 x0, x1, y0, y1, z0, z1;
                z1 = *(f32 *)(item + 0x14);
                z0 = *(f32 *)(item + 8);
                y1 = *(f32 *)(item + 0x10);
                y0 = *(f32 *)(item + 4);
                x1 = *(f32 *)(item + 0xC);
                x0 = *(f32 *)(item + 0);
                f32 z = z0 + spread * (z1 - z0);
                f32 y = y0 + spread * (y1 - y0);
                f32 x = x0 + spread * (x1 - x0);
                volatile f32 coords[4];
                volatile f32 padding;
                struct Out { void *ptr; f32 weight; } out;
                f32 pair[2];
                coords[3] = z;
                coords[2] = y;
                coords[1] = x;
                s32 handle = fn_80178C9C();
                pair[0] = coords[1];
                pair[1] = coords[3];
                fn_80136594((void **)&out, handle, pair, coords[3]);
                *(f32 *)(item + 0x18) =
                    *(f32 *)((u8 *)out.ptr + 0x1C) +
                    *(f32 *)((u8 *)out.ptr + 0x18) * out.weight;
            }
        }
        qsort(*(u8 **)(group + 4), *(u32 *)group, 0x24,
              (int (*)(const void *, const void *))fn_8013D27C);
    }

    }

    *(s32 *)(self + 0x68) = 0;
    *(f32 *)(self + 0x70) = lbl_80561594;
    *(f32 *)(self + 0x78) = lbl_80561594;
    *(f32 *)(self + 0x80) = lbl_80561594;
    *(f32 *)(self + 0x88) = lbl_80561594;
    *(f32 *)(self + 0x90) = lbl_80561594;
    *(s32 *)(self + 0x288) = fn_8013D18C(0);
    {
        register f32 negative = lbl_805614AC;
        register f32 defaultValue = lbl_80561598;
        register f32 one = lbl_805614A4;
        register f32 zero = lbl_80561594;
        s32 index = 0;
        s32 offset = 0;
        for (; index < *(s32 *)(self + 0xBC); offset += 0x12C, index++) {
            u8 *p = *(u8 **)(self + 0xB8) + offset;
            memset(p + 0xC, 0, 0x10);
            *(f32 *)(p + 0xC4) = zero;
            *(s32 *)(p + 0x0) = 1;
            *(s32 *)(p + 0x4) = 1;
            *(f32 *)(p + 0x8) = one;
            *(s32 *)(p + 0x1C) = 0;
            *(u8 *)(p + 0xF8) = 0;
            *(s32 *)(p + 0x80) = 0;
            *(f32 *)(p + 0x84) = defaultValue;
            *(s32 *)(p + 0x20) = 4;
            *(s32 *)(p + 0x24) = 4;
            *(s32 *)(p + 0x28) = 4;
            *(s32 *)(p + 0x2C) = 4;
            *(s32 *)(p + 0x30) = 4;
            *(s32 *)(p + 0x34) = 4;
            *(s32 *)(p + 0x38) = 4;
            *(s32 *)(p + 0x3C) = 4;
            *(s32 *)(p + 0x40) = 4;
            *(s32 *)(p + 0x44) = 4;
            *(f32 *)(p + 0xA4) = zero;
            *(f32 *)(p + 0xAC) = zero;
            *(f32 *)(p + 0xB4) = zero;
            *(f32 *)(p + 0xBC) = zero;
            *(f32 *)(p + 0x9C) = zero;
            *(f32 *)(p + 0xCC) = zero;
            *(f32 *)(p + 0xDC) = zero;
            *(f32 *)(p + 0xEC) = one;
            *(s32 *)(p + 0x88) = -1;
            *(s32 *)(p + 0x8C) = -1;
            *(f32 *)(p + 0x94) = negative;
            *(s32 *)(p + 0xE4) = 0;
            *(s32 *)(p + 0xE0) = 0;
            *(s32 *)(p + 0xE8) = 0;
            *(s32 *)(p + 0x104) = 0;
            *(f32 *)(p + 0xF0) = defaultValue;
            *(s32 *)(p + 0x100) = 0;
            *(s32 *)(p + 0xFC) = 0;
            *(f32 *)(p + 0x108) = *(f32 *)(lbl_8042FB3C + 0x18);
            *(u8 *)(p + 0x92) = 0;
            *(u8 *)(p + 0x91) = 0;
            *(u8 *)(p + 0x90) = 0;
            *(s32 *)(p + 0x11C) = 0;
            *(s32 *)(p + 0x10C) = 0;
            *(s32 *)(p + 0x110) = 0;
            *(s32 *)(p + 0x114) = 0;
            *(s32 *)(p + 0x124) = 3;
            *(f32 *)(p + 0x120) = defaultValue;
        }
    }

    {
        s32 handle = *(s32 *)(self + 0x140);
        s32 zero = 0;
        f32 reset = lbl_805614BC;
        *(s32 *)(self + 0xC8) = zero;
        *(s32 *)(self + 0xCC) = zero;
        *(s32 *)(self + 0x134) = zero;
        *(f32 *)(self + 0x138) = reset;
        *(u8 *)(self + 0x13C) = 1;
        *(u8 *)(self + 0x13D) = 0;
        *(u8 *)(self + 0x144) = 0;
        *(s32 *)(self + 0x240) = zero;
        *(s32 *)(self + 0x244) = zero;
        *(s32 *)(self + 0x248) = zero;
        *(s32 *)(self + 0x24C) = zero;
        if (handle != 0) fn_802AE0E0(handle);
    }
    {
        u8 *resource = *(u8 **)(self + 0x148);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x14C);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x150);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x158);
        *(u8 *)(self + 0x154) = 0;
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x15C);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x160);
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    {
        u8 *resource = *(u8 **)(self + 0x254);
        *(f32 *)(self + 0x250) = lbl_8056159C;
        if (resource != 0) {
            resource[0x4A] = 1;
            resource[0x4C] = 0;
        }
    }
    *(u8 *)(self + 0x258) = 0;
}
#pragma scheduling on
extern "C" u8 *fn_801B2EC0(s32);

extern "C" void fn_80143128(u8 *arg0) {
    ((TObj4C *)arg0)->v4C();
}

#pragma use_lmw_stmw off

#pragma scheduling invalid_target
extern "C" void fn_80143138(u8 *self, u8 *out) {
    class TObj10Local {
    public:
        virtual void d0();
        virtual void d1();
        virtual u8 *v10();
    };
    *(s32 *)out = *(s32 *)(self + 0xBC);
    *(s32 *)(out + 4) = *(s32 *)(self + 0x130);
    *(u8 *)(out + 0xD) = ((TObj24 *)self)->v24();
    s32 z = 0;
    u8 *p = out + 0x10;
    *(u8 *)(out + 0xC) = z;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (i < *(s32 *)(self + 0xBC)) {
        *(u8 *)(p + 0x10) = z;
        u8 *q = ((TObj10Local *)fn_801B2EC0(i))->v10();
        i++;
        *(s32 *)(p + 4) = *(s32 *)(q + 4);
        *(s32 *)(p + 8) = *(s32 *)(*(u8 **)(self + 0xB8) + off + 0x10C);
        off += 0x12C;
        p += 0x14;
    }
}
#pragma scheduling on
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
#pragma scheduling invalid_target
extern "C" s32 fn_80143218(s32 arg0, u8 *arg1) {
    u8 obj[0x38];
    volatile f32 *input = (volatile f32 *)(arg1 + 0x18);
    f32 *output = (f32 *)(arg1 + 0x30);
    f32 fx, fy, fz;

    fn_801352B8(obj);
    fn_80135D60(obj, ((TObjC *)fn_80156A40())->vC(0));
    u8 *v = *(u8 **)(obj + 0x2C);
    fn_801B8048(arg1, obj, v, lbl_805614A4,
                (*(f32 *)(v + 8) - lbl_805615A0) - lbl_805615A4);

    fx = input[0];
    register f32 scale = *(volatile f32 *)&lbl_805615A8;
    fy = input[1];
    fz = input[2];
    fx *= scale;
    fy *= scale;
    fz *= scale;
    output[0] = fx;
    output[1] = fy;
    *(s32 *)(arg1 + 0x44) = 1;
    output[2] = fz;
    fn_8013530C(obj, -1, fy, fx, scale);
    return 1;
}
#pragma scheduling on
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
    void *check = fn_801284F8(8, lbl_8032CD54);
    if (check != 0) {
        check = (void *)((s32 (*)(void *, s32))fn_802ADDD8)(check, 1);
    }
    *(void **)((u8 *)arg0 + 0x140) = check;
    volatile u8 *p = (volatile u8 *)arg0;
    fn_80143DC8((void *)(p + 0x134));
    fn_80143CB0((void *)(p + 0x134));
}

extern "C" void fn_802AE0E0(int);
extern "C" void fn_80143CB0(void *arg0) {
 int ref=*(int*)((char*)arg0+0xC);
 *(int*)((char*)arg0)=0;
 *(f32*)((char*)arg0+4)=lbl_805614BC;
 *((u8*)arg0+8)=1; *((u8*)arg0+9)=0; *((u8*)arg0+0x10)=0;
 *(int*)((char*)arg0+0x10C)=0; *(int*)((char*)arg0+0x110)=0; *(int*)((char*)arg0+0x114)=0; *(int*)((char*)arg0+0x118)=0;
 if(ref!=0) fn_802AE0E0(ref);
 void *item=*(void**)((char*)arg0+0x14);
 if(item!=0){*((u8*)item+0x4A)=1;*((u8*)item+0x4C)=0;}
 item=*(void**)((char*)arg0+0x18);
 if(item!=0){*((u8*)item+0x4A)=1;*((u8*)item+0x4C)=0;}
 item=*(void**)((char*)arg0+0x1C);
 if(item!=0){*((u8*)item+0x4A)=1;*((u8*)item+0x4C)=0;}
 item=*(void**)((char*)arg0+0x24);
 *((u8*)arg0+0x20)=0;
 if(item!=0){*((u8*)item+0x4A)=1;*((u8*)item+0x4C)=0;}
 item=*(void**)((char*)arg0+0x28);
 if(item!=0){*((u8*)item+0x4A)=1;*((u8*)item+0x4C)=0;}
 item=*(void**)((char*)arg0+0x2C);
 if(item!=0){*((u8*)item+0x4A)=1;*((u8*)item+0x4C)=0;}
}

extern "C" void fn_80130980(void *, s32, s32, f32);
extern "C" s32 fn_80204CF0(void);
extern "C" s32 fn_80207848(void *, s32);
extern "C" s32 fn_802ADF34(void *, char *, s32 *);
extern "C" s32 lbl_802FAA40[3];
extern "C" u8 lbl_80559D8C, lbl_80559D94, lbl_80559D98, lbl_80559D9C;
extern "C" f32 lbl_805615B4;
#pragma push
#pragma optimize_for_size on
#pragma scheduling invalid_target
extern "C" void fn_80143DC8(void *arg0) {
    union Word { s32 i; void *p; } stack[95];
    register u8 *obj;
    register char *base;
    register volatile s32 *var_r4;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 temp_r12_2;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 temp_r8;
    s32 temp_r9;
    register u32 var_ctr;
    s32 var_r20;
    s32 var_r6;
    s32 var_r6_2;
    u8 *var_r24;
    u8 *var_r4_2;
    u8 *var_r5;
    u8 *var_r5_2;
    u8 *var_r7;
    u8 *var_r7_2;
    u8 temp_r4_2;
    u8 temp_r4_3;
    u8 temp_r5_2;
    s32 one;
    s32 three;
    s32 sp188;
    s32 sp18c;
    s32 sp190;
    void *temp_r12;
    void *temp_r21;
    void *temp_r22;
    void *temp_r23;
    void *temp_r24;
    void *temp_r25;
    void *temp_r25_2;
    void *temp_r26;
    void *temp_r26_2;
    void *temp_r27;
    void *temp_r29;

    obj = (u8 *)arg0;
    base = (char *)lbl_8032C530;
    var_r4 = (volatile s32 *)&stack[47].i;
    for (var_ctr = 0; var_ctr < 0x19; var_ctr++) {
        var_r4[1] = 0;
        var_r4 += 2;
        var_r4[0] = 0;
    }
    var_r4[1] = 0;

    one = 1;
    temp_r0 = (s32)(obj + 0x10C);
    stack[47].i = temp_r0;
    temp_r12 = base + 0x290;
    temp_r26 = base + 0x840;
    stack[50].i = temp_r0;
    temp_r27 = base + 0x834;
    temp_r10 = (s32)(obj + 0x110);
    three = 3;
    stack[45].i = three;
    temp_r9 = (s32)(obj + 0x114);
    temp_r7 = (s32)(obj + 0x118);
    stack[48].i = three;
    temp_r29 = base + 0x84C;
    temp_r6 = (s32)(obj + 0x30);
    stack[46].p = temp_r27;
    temp_r5 = (s32)(obj + 0x44);
    temp_r25 = base + 0x858;
    stack[49].p = temp_r27;
    temp_r4 = (s32)(obj + 0x58);
    temp_r24 = base + 0x870;
    stack[42].i = three;
    temp_r0_2 = (s32)(obj + 0x6C);
    stack[43].p = temp_r12;
    stack[44].i = temp_r10;
    stack[51].i = three;
    stack[52].p = temp_r12;
    stack[53].i = temp_r10;
    stack[39].i = three;
    stack[40].p = &lbl_80559D8C;
    stack[41].i = temp_r9;
    stack[54].i = three;
    stack[55].p = &lbl_80559D8C;
    stack[56].i = temp_r9;
    stack[36].i = three;
    stack[37].p = temp_r26;
    stack[38].i = temp_r7;
    stack[57].i = three;
    stack[58].p = temp_r26;
    stack[59].i = temp_r7;
    stack[33].i = one;
    stack[34].p = temp_r29;
    stack[35].i = temp_r6;
    stack[60].i = one;
    stack[61].p = temp_r29;
    stack[62].i = temp_r6;
    stack[30].i = one;
    stack[31].p = temp_r12;
    stack[32].i = temp_r5;
    stack[63].i = one;
    stack[64].p = temp_r12;
    stack[65].i = temp_r5;
    stack[27].i = one;
    stack[28].p = temp_r25;
    stack[29].i = temp_r4;
    stack[66].i = one;
    stack[67].p = temp_r25;
    stack[68].i = temp_r4;
    stack[24].i = one;
    stack[25].p = temp_r24;
    stack[26].i = temp_r0_2;
    stack[69].i = one;
    stack[70].p = temp_r24;
    stack[71].i = temp_r0_2;
    stack[21].i = one;

    sp188 = lbl_802FAA40[0];
    temp_r8 = (s32)(obj + 0x80);
    sp18c = lbl_802FAA40[1];
    temp_r4 = (s32)(obj + 0x9E);
    sp190 = lbl_802FAA40[2];
    temp_r29 = obj + 0x94;
    stack[72].i = one;
    temp_r26_2 = base + 0x840;
    temp_r12_2 = (s32)(obj + 0xB2);
    stack[23].i = temp_r8;
    temp_r25_2 = base + 0x87C;
    temp_r11_2 = (s32)(obj + 0xC6);
    stack[73].p = temp_r26_2;
    temp_r23 = base + 0x898;
    temp_r10_2 = (s32)(obj + 0xDA);
    stack[74].i = temp_r8;
    temp_r22 = base + 0x8B0;
    stack[18].i = one;
    temp_r9 = (s32)(obj + 0xEE);
    temp_r21 = base + 0x8DC;
    stack[20].i = (s32)temp_r29;
    temp_r7_2 = (s32)(obj + 0x104);
    stack[75].i = one;
    var_r24 = &lbl_80559D8C;
    temp_r8 = 2;
    stack[19].p = var_r24;
    var_r20 = 0x14;
    stack[76].p = var_r24;
    var_r24 = &lbl_80559D94;
    stack[77].i = (s32)temp_r29;
    stack[15].i = one;
    stack[16].p = temp_r25_2;
    stack[17].i = temp_r4;
    stack[78].i = one;
    stack[79].p = temp_r25_2;
    stack[80].i = temp_r4;
    stack[12].i = one;
    stack[13].p = temp_r27;
    stack[14].i = temp_r12_2;
    stack[81].i = one;
    stack[82].p = temp_r27;
    stack[83].i = temp_r12_2;
    stack[9].i = one;
    stack[10].p = temp_r23;
    stack[11].i = temp_r11_2;
    stack[84].i = one;
    stack[85].p = temp_r23;
    stack[86].i = temp_r11_2;
    stack[6].i = one;
    stack[7].p = temp_r22;
    stack[8].i = temp_r10_2;
    stack[87].i = one;
    stack[88].p = temp_r22;
    stack[89].i = temp_r10_2;
    stack[3].i = one;
    stack[4].p = temp_r21;
    stack[5].i = temp_r9;
    stack[90].i = one;
    stack[91].p = temp_r21;
    stack[92].i = temp_r9;
    stack[0].i = 2;
    stack[1].p = temp_r21;
    stack[2].i = temp_r7_2;
    stack[93].i = 2;
    stack[94].p = temp_r21;
    stack[95].i = temp_r7_2;
    stack[96].i = sp188;
    stack[97].i = sp18c;
    stack[98].i = sp190;

    var_r4_2 = obj + 0x9E;
    var_r24 = &lbl_80559D94;
    var_r20 = 0x14;
    goto loop_5_copy;
loop_5_count:
    var_r20 -= 1;
    if (var_r20 > 0) goto loop_5_copy;
    *(signed char *)(var_r4_2 - 1) = 0;
    goto loop_5_done;
loop_5_copy:
    temp_r5_2 = *var_r24;
    var_r24 += 1;
    *var_r4_2 = temp_r5_2;
    var_r4_2 += 1;
    if ((signed char)temp_r5_2 != 0) goto loop_5_count;
loop_5_done:
    var_r7 = obj + 0x44;
    var_r5 = &lbl_80559D98;
    var_r6 = 0x14;
    goto loop_9_copy;
loop_9_count:
    var_r6 -= 1;
    if (var_r6 > 0) goto loop_9_copy;
    *(signed char *)(var_r7 - 1) = 0;
    goto loop_9_done;
loop_9_copy:
    temp_r4_2 = *var_r5;
    var_r5 += 1;
    *var_r7 = temp_r4_2;
    var_r7 += 1;
    if ((signed char)temp_r4_2 != 0) goto loop_9_count;
loop_9_done:
    var_r7_2 = obj + 0x80;
    var_r5_2 = &lbl_80559D9C;
    var_r6_2 = 0x14;
    goto loop_13_copy;
loop_13_count:
    var_r6_2 -= 1;
    if (var_r6_2 > 0) goto loop_13_copy;
    *(signed char *)(var_r7_2 - 1) = 0;
    goto loop_13_done;
loop_13_copy:
    temp_r4_3 = *var_r5_2;
    var_r5_2 += 1;
    *var_r7_2 = temp_r4_3;
    var_r7_2 += 1;
    if ((signed char)temp_r4_3 != 0) goto loop_13_count;
loop_13_done:
    fn_80130980(obj + 0xB2, 0x14, 2, lbl_805615B4);
    *(s32 *)(obj + 0x104) = fn_80204CF0() + 1;
    *(s32 *)(obj + 0x108) = fn_802ADF34(*(void **)(obj + 0xC), base + 0x8F0, &stack[48].i);
    *(s32 *)(obj + 0x14) = fn_80207848(base + 0x904, 1);
    *(s32 *)(obj + 0x18) = fn_80207848(base + 0x918, 1);
    *(s32 *)(obj + 0x1C) = fn_80207848(base + 0x934, 1);
    *(s32 *)(obj + 0x24) = fn_80207848(base + 0x948, 1);
    *(s32 *)(obj + 0x28) = fn_80207848(base + 0x15C, 1);
    *(s32 *)(obj + 0x2C) = fn_80207848(base + 0x95C, 1);
}
#pragma scheduling on
#pragma optimize_for_size reset
#pragma pop

extern "C" void fn_802ADE60(int, int);
extern "C" void fn_80144184(void *arg0) {
 class VObj { public: virtual void destroy(int); };
 int value=*(int*)((char*)arg0+0x140);
 if(value){fn_802ADE60(value,1);*(int*)((char*)arg0+0x140)=0;}
 VObj *p;
 p=*(VObj**)((char*)arg0+0x148);
 if(p){if(p)p->destroy(1);*(VObj**)((char*)arg0+0x148)=0;}
 p=*(VObj**)((char*)arg0+0x14C);
 if(p){if(p)p->destroy(1);*(VObj**)((char*)arg0+0x14C)=0;}
 p=*(VObj**)((char*)arg0+0x150);
 if(p){if(p)p->destroy(1);*(VObj**)((char*)arg0+0x150)=0;}
 p=*(VObj**)((char*)arg0+0x158);
 if(p){if(p)p->destroy(1);*(VObj**)((char*)arg0+0x158)=0;}
 p=*(VObj**)((char*)arg0+0x15C);
 if(p){if(p)p->destroy(1);*(VObj**)((char*)arg0+0x15C)=0;}
 p=*(VObj**)((char*)arg0+0x160);
 if(p){if(p)p->destroy(1);*(VObj**)((char*)arg0+0x160)=0;}
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
    s32 value = fn_8013D1F0(arg1);
    value ^= 0xA;
    s32 half = value >> 1;
    s32 mask = value & 0xA;
    if (half - mask < 0) {
        return 1;
    }
    return 0;
}
#pragma dont_inline off
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