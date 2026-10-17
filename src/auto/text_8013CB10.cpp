#include "types.h"
extern "C" f32 lbl_80558DC4;
extern "C" f32 lbl_805614A4;
extern "C" f32 lbl_805614AC;
extern "C" f32 lbl_805614BC;
extern "C" s32 fn_80128670(s32);
extern "C" f32 fn_8001DAE8(void *);
extern "C" s32 lbl_802F9398[6];
struct S6_8013D18C { s32 v[6]; };
extern "C" void **fn_801284F8(s32, void *);
extern "C" f32 lbl_80561498;
extern "C" s32 fn_80176A1C(void);
extern "C" int strcmp(const char *, const char *);
extern "C" u8 lbl_80559D18;
extern "C" u8 lbl_8032CAC0;
extern "C" s32 fn_8013D224(f32, f32);
extern "C" u8 *fn_801B2EC0(s32);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

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

class TObj10 {
public:
    virtual void d0(); virtual void d1();
    virtual u8 *v10(); // 0x10
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

extern "C" s32 fn_8013D1F0(s32);

extern "C" s32 fn_8013CB10(void) {
    return fn_80176A1C() == 2;
}

extern f32 lbl_8055E3C8;
extern "C" f32 fn_8013CB3C(void) {
    return lbl_8055E3C8;
}

extern "C" s32 fn_8013CB44(const char *arg0, TObj10 *arg1) {
    return strcmp((const char *)arg1->v10(), arg0) == 0;
}

extern "C" void fn_8013CB90(void *arg0) {
    f32 x = *(f32 *)((u8 *)arg0 + 0x10);
    f32 scale = lbl_80561498;
    f32 y = *(f32 *)((u8 *)arg0 + 0x14);
    *(f32 *)((u8 *)arg0 + 4) = *(f32 *)((u8 *)arg0 + 4) - x * scale;
    *(f32 *)((u8 *)arg0 + 8) = *(f32 *)((u8 *)arg0 + 8) - y * scale;
}

extern "C" u32 fn_8013D148(u8 *arg0, f32 arg1) {
    s32 count = *(s32 *)arg0;
    s32 i = 0;
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
    ((void (*)(void))(*(void ***)obj)[4])();
    return *(s32 *)(obj + 0x10);
}

extern "C" void fn_8013D27C(void *a, void *b) {
    fn_8013D224(*(f32 *)((u8 *)a + 0x18), *(f32 *)((u8 *)b + 0x18));
}

extern "C" s32 fn_8013DDD4(TObjC *arg0, const char *arg1) {
    s32 count = 0;
    s32 i = 0;
    void *item;
    while ((item = (void *)arg0->vC(i)) != 0) {
        if (fn_8013CB44(arg1, (TObj10 *)item))
            count++;
        i++;
    }
    return count;
}

extern "C" f64 fn_8002F234(f32);
extern "C" f32 fn_8013E300(void *arg0) {
    f32 y = *(f32 *)((u8 *)arg0 + 4);
    f32 x = *(f32 *)arg0;
    return (f32)fn_8002F234(x * x + y * y);
}

extern "C" void fn_8013E338(void) {

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
f32 fn_8013EFB0(f32 arg0) { return arg0 - lbl_80561510; }

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

extern "C" int fn_8013FC6C(void* arg0) {
    int a = 0, b = 0, c = 0;
    while (c < *(int*)((char*)arg0 + 0xBC)) {
        if (*(unsigned char*)(*(char**)((char*)arg0 + 0xB8) + a + 0x118)) {
            if (((int (*)(void*, int))(*(void***)arg0)[8])(arg0, c) == 0) {
                b++;
                if (b >= *(int*)((char*)arg0 + 0x130)) return 1;
            }
        }
        a += 0x12C;
        c++;
    }
    return 0;
}

extern "C" int fn_8013FD20(void* arg0, int arg1) {
    int result = 1;
    if (*(int*)(*(char**)((char*)arg0 + 0xB8) + arg1 * 0x12C + 0x11C) != 0) {
        float f = fn_8001DAE8((char*)arg0 + 0x74) - *(float*)((char*)arg0 + 0x78);
        if (!(f <= lbl_805614A4) && f < *(float*)((char*)arg0 + 0x74)) result = 0;
    }
    return result;
}

extern "C" void fn_80141454(void) {

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
    s32 head = *(s32 *)((char *)arg0 + 0xC);
    s32 capacity = *(s32 *)((char *)arg0 + 4);
    s32 count = capacity + (*(s32 *)((char *)arg0 + 8) - head);
    s32 result;
    if (arg1 >= count % capacity) {
        result = *(s32 *)arg0 + ((arg1 + (capacity + head)) % capacity) * 12;
    } else {
        result = 0;
    }
    return result;
}

extern "C" s32 fn_80141F7C(f32 arg0) {
    return (f32)__fabs((f64)arg0) <= *(volatile f32 *)0x80558DC4;
}

extern "C" u8 fn_80141FA0(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x19);
}

extern "C" void fn_80142104(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0xE8) = 0;
    *(s32 *)((u8 *)arg0 + 0x104) = 0;
    *(s32 *)((u8 *)arg0 + 0x100) = 0;
}

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

extern f32 lbl_805615B0;
extern "C" f32 fn_80143C44(void) {
    return lbl_805615B0;
}

extern "C" u32 fn_80143C4C(void) { return 1; }

extern "C" void fn_801442DC(void *arg0) {
    void **vtable = *(void ***)arg0;
    void *fn = vtable[8];
    ((void (*)())fn)();
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
extern "C" s32 fn_8014445C(s32 arg0, s32 arg1) {
    s32 v = fn_8013D1F0(arg1) ^ 0xA;
    s32 a = v & 0xA;
    return (v >> 1) - a >> 0x1F;
}

extern "C" s32 fn_80144494(s32 arg0, s32 arg1) { return arg1; }

