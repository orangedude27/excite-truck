#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
extern "C" void fn_802A3C50(void* arg0, s32 arg1);

extern "C" int lbl_80349B00[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" s32 fn_80128668(void);
extern "C" void fn_8028E398(void*);
extern "C" int lbl_80349B28[];
extern "C" void* lbl_804BCF88[];
extern "C" int fn_801EF024(void*);
extern "C" s32 fn_802A1C30(void*);
extern "C" void fn_802A1DC0(void);
extern "C" f32 lbl_80564728;
extern "C" int lbl_80349B50[];
extern "C" int lbl_80349AD8[];
class DummyReceiver_802A3314 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 v3(const void*);
    virtual void v4();
    virtual s32 v5(const void*);
};
extern "C" int lbl_8055CBB0;
extern "C" void fn_802A3500(void*, s32);
extern "C" void fn_802A30BC(void*, s32);
extern "C" void fn_802A31DC(void*, s32);
extern "C" s32 fn_802A47A8(void*);
extern "C" void fn_802A2AE8(void*, s32);
extern "C" void fn_802A2BF4(void*, s32);
extern "C" void fn_802A2D04(void*, s32);
extern "C" void fn_802A2E08(void*, s32);
extern "C" void fn_802A44B8(void*, s32);
extern "C" int lbl_80349B78[];
extern "C" int lbl_8055F870;
extern "C" float lbl_80564734;
extern "C" float lbl_80564744;
extern "C" void fn_802A4524(void*);
extern "C" s32 fn_80287B14(void*);

namespace ebi {
namespace title {
class TPlaneSub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
          virtual void v5();
              virtual void v6(); // 0x20
        virtual void v7(); // 0x24
};

class LocalCall {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 call(void*);
};

class TBlackPlane {
public:
    TBlackPlane() {}
    void* m_pad; // 0x0
    TPlaneSub* m_a; // 0x4
    TPlaneSub* m_b; // 0x8
    void updateAfterCamera();
};
} // namespace title
} // namespace ebi

extern "C" u8 fn_802A4A20(void);
extern "C" void *memset(void *, int, unsigned long);
extern "C" char lbl_80349928[];
extern "C" char lbl_8055CB70;
extern "C" void *fn_802AE414(void *);
extern "C" void fn_801345D8(void *, s32, const char *, s32);
extern "C" s32 fn_802A194C(void);
extern "C" void fn_80287B38(void *);
extern "C" f32 fn_801E7E24(void);
extern "C" int fn_802BF4F0(void);
extern "C" f32 fn_802BF590(void);
extern "C" float __fabsf(float);
__declspec(section ".data") extern f32 lbl_80558DC4;
extern "C" void fn_802A1B20(void*, s32);
extern "C" void fn_802A1CC4(void);
extern "C" void fn_8028E61C(void*);
extern "C" void fn_801EEFDC(void *, s32);
extern "C" void fn_802A1590(void) {
    void *obj;
    void **entry;
    s32 index;
    char name[0x20];

    memset(lbl_804BCF88, 0, 0x20);
    entry = lbl_804BCF88;
    index = 0;
    do {
        fn_801345D8(name, 0x20, lbl_80349928, index);
        obj = fn_802AE414(name);
        if (obj != 0) {
            if (((s32 (*)(void *, void *))(*(void ***)obj)[0x5c / 4])(obj, &lbl_8055CB70) != 0) {
                *entry = (void *)fn_802A194C();
            }
        }
        index++;
        entry++;
    } while (index < 8);
    fn_80287B38((void *)fn_802A1B20);
    fn_802A1CC4();
    fn_801EEFDC((void *)fn_802A1C30, 5);
}

extern "C" void fn_802A1660(void) {
    int var_r29;
    void** var_r30;
    int var_r31 = 0;
    fn_801EF024((void*)fn_802A1C30);
    fn_802A1DC0();
    var_r30 = lbl_804BCF88;
    var_r29 = 0;
    do {
        void* obj = *var_r30;
        if (obj != 0) {
            ((void (*)(int))(*(void***)obj)[2])(1);
            *var_r30 = (void*)var_r31;
        }
        var_r29++;
        var_r30++;
    } while (var_r29 < 8);
}

extern "C" s32 fn_802A16EC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" void fn_802A172C(void) {
    struct Dispatch { virtual void f0(); virtual void f1(); virtual void f2(); virtual void call(); };
    void **var_r31 = lbl_804BCF88;
    int var_r30;
    for (var_r30 = 0; var_r30 < 8; var_r30++, var_r31++) {
        void *temp_r3 = *var_r31;
        if (temp_r3 != 0)
            ((Dispatch *)temp_r3)->call();
    }
}

extern "C" void fn_802A1790(void) {}

extern "C" void fn_802A1794(void) {
    struct Dispatch { virtual void f0(); virtual void f1(); virtual void f2(); virtual void call(); };
    void **entry = lbl_804BCF88;
    s32 index = 0;
    do {
        void *obj = *entry;
        if (obj != 0) ((Dispatch *)obj)->call();
    } while (++index < 8 && (entry++, index < 8));
}

extern "C" void fn_802A17FC(void) {
    void ***entry = (void ***)&lbl_804BCF88;
    s32 index = 0;
    struct Dispatch {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void call();
    };
    do {
        void **obj = *entry;
        if (obj != 0) ((Dispatch *)obj)->call();
        index++;
    } while (index < 8 && (entry++, index < 8));
}

extern "C" void fn_802A1860(void) {}

extern "C" char* lbl_802FAA10[];
extern "C" char lbl_80349934[];
extern "C" int stricmp(const char*, const char*);
extern "C" void fn_802E317C(const char*, const char*);
extern "C" s32 fn_802A1864(const char* name) {
    s32 entries[12];
    s32 i;
    entries[0] = (s32)lbl_802FAA10[0];
    entries[1] = (s32)lbl_802FAA10[1];
    entries[2] = (s32)lbl_802FAA10[2];
    entries[3] = (s32)lbl_802FAA10[3];
    entries[4] = (s32)lbl_802FAA10[4];
    entries[5] = (s32)lbl_802FAA10[5];
    entries[6] = (s32)lbl_802FAA10[6];
    entries[7] = (s32)lbl_802FAA10[7];
    entries[8] = (s32)lbl_802FAA10[8];
    entries[9] = (s32)lbl_802FAA10[9];
    entries[10] = (s32)lbl_802FAA10[10];
    entries[11] = (s32)lbl_802FAA10[11];
    for (i = 0; i < 6; ++i) {
        if (stricmp(name, (char*)entries[i * 2]) == 0) return entries[i * 2 + 1];
    }
    fn_802E317C(lbl_80349934, name);
    return 0;
}

extern "C" void fn_802A1B20(void* arg0, s32 count) {
    void* p = arg0;
    f32 threshold = fn_801E7E24();
    if (threshold != lbl_80558DC4) {
        void** table = lbl_804BCF88;
        s32 i = 0;
        while (i < count) {
            if (*(u8*)((char*)p + 0xC) != 0) {
                s32 j = 0;
                s32 off = 0;
                void* base = *(void**)p;
                do {
                    void* obj = (char*)base + off;
                    if (*(u8*)((char*)obj + 0xA0) != 0) {
                        s32 index = *(s32*)((char*)obj + 0xA8);
                        if (index >= 0 && index < 8 && table[index] != 0 &&
                            (fn_802BF4F0() == 0 || *(f32*)((char*)obj + 0x80) > fn_802BF590())) {
                            void* target = table[index];
                            ((void (*)(void*, void*, s32))(*(void***)target)[0x1C / 4])(target, p, j);
                        }
                    }
                    j++;
                    off += 0x3C;
                } while (j < 4);
            }
            p = (char*)p + 0x10;
            i++;
        }
    }
}

extern "C" s32 fn_802A1C30(void* arg0) {
    void* saved = arg0;
    s32 index = *(s32*)((char*)arg0 + 0x2C);
    if (index >= 0 && index < 8) {
        void** table = lbl_804BCF88;
        ebi::title::TPlaneSub* obj = (ebi::title::TPlaneSub*)*(table + index);
        if (obj != 0) {
            if (*(f32*)((char*)arg0 + 0x24) > lbl_80564728) obj->v6();
            else obj->v7();
        }
    }
    return (s32)(saved != 0) * 0 + 0x30;
}

extern "C" void fn_802A1CBC(void) {}

extern "C" void fn_802A1CC0(void) {
}

extern "C" void fn_802A1DC0(void) {
    if (lbl_8055F870 != 0) {
        fn_8028E398((void *)lbl_8055F870);
        lbl_8055F870 = 0;
    }
}

extern "C" void* fn_802A1DF4(void* arg0, void* arg1) {
    s32 value;
    *(void**)arg0 = &lbl_80349B78;
    value = (*(s32 (**)(void*, void*))((char*)*(void**)arg1 + 0x14))(arg1, (void*)lbl_8055CBB0);
    fn_802A2AE8(arg0, value);
    fn_802A2BF4(arg0, value);
    fn_802A2D04(arg0, value);
    fn_802A2E08(arg0, value);
    return arg0;
}

extern "C" void* fn_802A1E80(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(volatile void**)arg0 = &lbl_80349B78;
        fn_802A44B8(*(void**)((char*)arg0 + 0x10), 1);
        fn_8028E398(*(void**)((char*)arg0 + 0xC));
        fn_8028E398(*(void**)((char*)arg0 + 8));
        fn_8028E398(*(void**)((char*)arg0 + 4));
        if (arg1 > 0) ((s32 (*)(void*))fn_80128668)(arg0);
    }
    return arg0;
}

#pragma scheduling off
extern "C" void fn_802A1F00(void *arg0) {
    float f31 = lbl_80564734;
    float f30 = lbl_80564744;
    s32 count = 0;
    void* p = arg0;
    while (count < fn_80287B14(p)) {
        *(float*)((char*)p + 0x14) = f30;
        count++;
        *(float*)((char*)p + 0x18) = f31;
        *(float*)((char*)p + 0x1C) = f30;
        *(float*)((char*)p + 0x20) = f30;
        p = (char*)p + 0x10;
    }
    fn_802A4524(*(void**)((char*)arg0 + 0x10));
}

extern "C" void* fn_80287B24(s32);
extern "C" void fn_802A4658(s32);
extern "C" f32 lbl_80564730, lbl_80564748, lbl_8056474C, lbl_80564750;
#pragma scheduling off
extern "C" void fn_802A1F88(void* arg0) {
    f32 step = lbl_80564748 * fn_801E7E24();
    f32 scale = lbl_8056474C;
    f32 max = lbl_80564750;
    f32 bound = lbl_80564730;
    s32 i = 0;
    void* p = arg0;
    do {
        void* obj = fn_80287B24(i);
        if (fn_802BF4F0() != 0) {
            char* wheel = (char*)obj + 0x70;
            s32 active = 4;
            s32 j = 0;
            f32 threshold = fn_802BF590();
            do {
                if (*(f32*)(wheel + 0x10) >= threshold && *(u8*)(wheel + 0x30) == 0)
                    --active;
                ++j;
                wheel += 0x3C;
            } while (j < 4);
            if (active == 0) goto skip;
        }
        {
            f32 a = *(f32*)((char*)obj + 0x110);
            f32 b = *(f32*)((char*)obj + 0x14C);
            if (a > b) b = a;
            f32 amount = scale * b;
            f32 speed = *(f32*)((char*)obj + 0x50) * step;
            if (speed > amount) amount = speed;
            if (amount > max) amount = max;
            if (*(f32*)((char*)p + 0x14) > bound - lbl_80558DC4)
                *(f32*)((char*)p + 0x14) -= bound;
            *(f32*)((char*)p + 0x14) += amount;
            if (*(f32*)((char*)p + 0x18) > bound - lbl_80558DC4)
                *(f32*)((char*)p + 0x18) -= bound;
            *(f32*)((char*)p + 0x18) += amount;
        }
skip:
        p = (char*)p + 0x10;
        ++i;
    } while (i < fn_80287B14(arg0));
    if (__fabsf(fn_801E7E24()) != lbl_80558DC4)
        fn_802A4658(*(s32*)((char*)arg0 + 0x10));
}
#pragma scheduling on
extern "C" void fn_802A2118(void *arg0) {
    fn_802A47A8((void*)*(void**)((char*)arg0 + 0x10));
}

extern "C" float lbl_80564730;
extern "C" float lbl_80564738;
extern "C" float lbl_80564740;
extern "C" float lbl_80564754;
extern "C" float lbl_80564758;
extern "C" float lbl_8056475C;
extern "C" float lbl_80564760;
extern "C" float lbl_80564764;
extern "C" float lbl_80564768;
extern "C" float lbl_8056476C;
extern "C" float lbl_80564770;
extern "C" void fn_8028E58C(void*, void*, void*, f32);
extern "C" void fn_802A4538(void*, void*, void*, f32);
#pragma push
#pragma processor 750
extern "C" void fn_802A2120(void* arg0, void* arg1, s32 arg2) {
    unsigned char* base;
    unsigned char* p;
    f32 sp8, spC, sp10;
    f32 f6, f7, f8;
    f32 var_f1;
    f32 f31;
    f32 fa, fb;
    s32 flag;
    f32* vp;

    if (*(f32*)((char*)arg1 + 8) > lbl_80564754) return;
    p = *(unsigned char**)arg1 + arg2 * 0x3c;
    if (*(f32*)(p + 0x94) * *(f32*)(p + 0x94) < lbl_80564758) return;
    flag = 1;
    if (arg2 != 2 && arg2 != 3) flag = 0;
    var_f1 = lbl_8056475C;
    if (*(f32*)(p + 0x70) > lbl_80564744) var_f1 = lbl_80564730;
    if (*(f32*)(p + 0x94) > lbl_80564744) var_f1 = lbl_80564730;
    else var_f1 = lbl_8056475C;
    f8 = *(f32*)(p + 0x78) - lbl_80564760 * var_f1;
    f6 = *(f32*)(p + 0x70);
    f7 = lbl_80564764 + *(f32*)(p + 0x74);
    base = *(unsigned char**)arg1;
    sp8 = f6;
    spC = f7;
    sp10 = f8;
    vp = &sp8;
    if (vp != &sp8) {
        sp8 = f8 * *(f32*)(base + 0x18) + (f6 * *(f32*)base + f7 * *(f32*)(base + 0x0c));
        spC = f8 * *(f32*)(base + 0x1c) + (sp8 * *(f32*)(base + 4) + f7 * *(f32*)(base + 0x10));
        sp10 = f8 * *(f32*)(base + 0x20) + (sp8 * *(f32*)(base + 8) + spC * *(f32*)(base + 0x14));
    } else {
        sp8 = f8 * *(f32*)(base + 0x18) + (f6 * *(f32*)base + f7 * *(f32*)(base + 0x0c));
        spC = f8 * *(f32*)(base + 0x1c) + (f6 * *(f32*)(base + 4) + f7 * *(f32*)(base + 0x10));
        sp10 = f8 * *(f32*)(base + 0x20) + (f6 * *(f32*)(base + 8) + f7 * *(f32*)(base + 0x14));
    }
    sp8 += *(f32*)(base + 0x24);
    spC += *(f32*)(base + 0x28);
    sp10 += *(f32*)(base + 0x2c);

    fb = *(f32*)(base + 0x14c);
    fa = *(f32*)(base + 0x110);
    if (fa > fb) { } else fa = fb;
    {
        f32 r = (fa - lbl_80564744) / lbl_80564768;
        if (lbl_80564730 < r) { } else fa = r;
        if (fa > lbl_80564744) { } else fa = lbl_80564744;
    }
    f31 = lbl_80564740 + fa * lbl_80564738;

    if (*(f32*)((char*)arg1 + 8) < lbl_8056476C) {
        fn_8028E58C((void*)*(s32*)((char*)arg0 + 4), (void*)&sp8, (void*)(*(unsigned char**)arg1 + 0x34), f31);
        if (flag != 0) {
            fn_8028E58C((void*)*(s32*)((char*)arg0 + 8), (void*)&sp8, (void*)(*(unsigned char**)arg1 + 0x34), f31);
        }
    }
    if (flag != 0) {
        if (*(f32*)(p + 0x94) * *(f32*)(p + 0x94) > lbl_80564770) {
            if (*(f32*)((char*)arg0 + (*(s32*)((char*)arg1 + 4) << 4) + (arg2 - 2) * 4 + 0x14) > lbl_80564730 - lbl_80558DC4) {
                fn_802A4538((void*)*(s32*)((char*)arg0 + 0x10), (void*)&sp8, (void*)(*(unsigned char**)arg1 + 0x34), f31);
            }
        }
    }
}
#pragma pop
extern "C" f32 lbl_80558DC4;
extern "C" f32 lbl_80564730;
extern "C" f32 lbl_80564750;
extern "C" f32 lbl_80564744;
extern "C" int lbl_80349AB0[];
extern "C" void fn_8028E584(void*, void*);
extern "C" s32 fn_80287B14(void*);
extern "C" void fn_802A2A38(void* arg0, void* arg1) {
    s32 index = *(s32*)((char*)arg1 + 0x28);
    f32* value = (f32*)((char*)arg0 + (index << 4) + 0x20);
    if (*value > lbl_80564730 - lbl_80558DC4) {
        fn_8028E584(*(void**)((char*)arg0 + 0xC), (char*)arg1 + 0xC);
    }
    index = *(s32*)((char*)arg1 + 0x28);
    value = (f32*)((char*)arg0 + (index << 4) + 0x20);
    if (*value > lbl_80564730 - lbl_80558DC4) {
        *value -= lbl_80564730;
    }
    *value += lbl_80564750;
}

extern "C" void *fn_801284F8(u32, void *);
extern "C" s32 fn_802A42C8(void *, s32);
extern "C" int lbl_80349A34[];
extern "C" f32 lbl_80564730, lbl_80564734, lbl_80564740, lbl_80564744, lbl_80564780, lbl_805647AC, lbl_805647C0, lbl_805647C4, lbl_805647C8, lbl_805647CC, lbl_805647D0, lbl_805647D4, lbl_805647D8;
extern "C" void fn_802A2E08(void *arg0, s32 arg1) {
    struct Params {
        s32 size;
        f32 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r;
    } params;
    void *obj;
    params.size = 0x834;
    params.a = lbl_805647C0;
    params.b = lbl_805647C4;
    params.c = lbl_805647C8;
    params.d = lbl_805647C8;
    params.e = lbl_805647C8;
    params.f = lbl_80564730;
    params.g = lbl_80564740;
    params.h = lbl_80564730;
    params.i = lbl_805647AC;
    params.j = lbl_805647CC;
    params.k = lbl_80564744;
    params.l = lbl_80564734;
    params.m = lbl_805647D0;
    params.n = lbl_805647D4;
    params.o = lbl_80564780;
    params.p = lbl_80564740;
    params.q = lbl_805647D8;
    params.r = lbl_80564744;
    obj = fn_801284F8(0x68, (void *)lbl_80349A34);
    if (obj != 0) *(s32 *)((u8 *)arg0 + 0x10) = fn_802A42C8(&params, arg1);
}

extern "C" void* fn_802A2EEC(void* arg0, void* arg1) {
    *(void**)arg0 = lbl_80349B50;
    s32 result = (*(s32 (**)(void*, void*))(*(void**)((char*)arg1 + 0x14)))(arg1, &lbl_8055CBB0);
    fn_802A30BC(arg0, result);
    fn_802A31DC(arg0, result);
    return arg0;
}

extern "C" void* __dt__8JUTVideoFv(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80349B50;
        fn_8028E398(*(void**)((char*)arg0 + 8));
        fn_8028E398(*(void**)((char*)arg0 + 4));
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

#pragma scheduling invalid_target
extern "C" void* fn_802A3314(void* arg0, DummyReceiver_802A3314* arg1) {
    *(void**)arg0 = lbl_80349B28;
    s32 result = arg1->v3(&lbl_8055CBB0);
    fn_802A3500(arg0, result);
    return arg0;
}
#pragma scheduling on
extern "C" void fn_8028E398(void*);
extern "C" int lbl_80349B28[];
extern "C" void* __dt__14CollisionSpaceFv_802A3370(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349B28;
        fn_8028E398(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802A37C8(void*, s32);
extern "C" void* fn_802A3610(void* arg0, DummyReceiver_802A3314* arg1) {
    *(void**)arg0 = lbl_80349B00;
    s32 result = arg1->v3(&lbl_8055CBB0);
    fn_802A37C8(arg0, result);
    return arg0;
}

extern "C" int lbl_80349B00[];
extern "C" void* __dt__14CollisionSpaceFv_802A366C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349B00;
        fn_8028E398(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" f32 lbl_80564730, lbl_80564744, lbl_8056475C, lbl_8056476C, lbl_805647C4, lbl_805647DC, lbl_80564818, lbl_8056481C;
extern "C" void fn_8028E590(int, f32*, f32*, f32);
extern "C" void fn_802A36D0(void* arg0, void* arg1, s32 arg2) {
    unsigned char* obj = *(unsigned char**)arg1;
    unsigned char* p = obj + arg2 * 0x3C;
    f32 sp8, spC, sp10, temp_f6, temp_f5, temp_f4, temp_f3, temp_f2, temp_f7;
    if (*(f32*)((char*)arg1 + 8) > lbl_8056476C) return;
    if (*(f32*)(p + 0x98) < lbl_805647DC && *(f32*)(p + 0x94) < lbl_80564818) return;
    if (*(f32*)(p + 0x70) > lbl_80564744) temp_f7 = lbl_80564730;
    else temp_f7 = lbl_8056475C;
    temp_f6 = *(f32*)(obj + 0x34) * lbl_805647C4;
    sp8 = temp_f6;
    temp_f5 = *(f32*)(obj + 0x38) * lbl_805647C4;
    spC = temp_f5;
    temp_f4 = *(f32*)(obj + 0x3C) * lbl_805647C4;
    sp10 = temp_f4;
    temp_f3 = temp_f7 * *(f32*)(obj + 0x50);
    temp_f2 = lbl_8056481C * temp_f3;
    sp8 = temp_f6 + *(f32*)obj * temp_f2;
    spC = temp_f5 + *(f32*)(obj + 4) * temp_f2;
    sp10 = temp_f4 + *(f32*)(obj + 8) * temp_f2;
    fn_8028E590(*(int*)((char*)arg0 + 4), (f32*)(p + 0x7C), &sp8, lbl_805647DC);
}

extern "C" void* fn_802A38D0(void* arg0, DummyReceiver_802A3314* arg1) {
    *(void**)arg0 = lbl_80349AD8;
    s32 result = arg1->v3(&lbl_8055CBB0);
    fn_802A3C50(arg0, result);
    return arg0;
}

extern "C" int lbl_80349B50[];
extern "C" int lbl_80349AD8[];
extern "C" void fn_802A3500(void*, s32);
extern "C" void fn_802A30BC(void*, s32);
extern "C" void fn_802A31DC(void*, s32);
extern "C" void* __dt__14CollisionSpaceFv_802A392C(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80349AD8;
        fn_8028E398(((void**)arg0)[1]);
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" float fn_80287BC8(float, float);
extern "C" void fn_8028E590(int, float *, float *, float);
extern "C" float lbl_80564730, lbl_80564740, lbl_80564744, lbl_80564758, lbl_8056475C, lbl_80564760, lbl_80564764, lbl_8056476C, lbl_8056477C, lbl_805647A4, lbl_8056481C, lbl_8056482C;
extern "C" void fn_802A3990(void *arg0, void *arg1, int arg2) {
    float sp1C, sp18, sp14, sp10, spC, sp8, temp_f1, temp_f1_2, temp_f3, temp_f4, temp_f5, temp_f6, temp_f7, temp_f8, var_f0, var_f31, var_f1;
    unsigned char *obj = *(unsigned char **)arg1, *p = obj + arg2 * 0x3C;
    if (*(float *)((char *)arg1 + 8) > lbl_8056476C) return;
    temp_f1 = *(float *)(p + 0x94); if (temp_f1 * temp_f1 < lbl_80564758) return;
    if (*(float *)(p + 0x70) > lbl_80564744) var_f31 = lbl_80564730; else var_f31 = lbl_8056475C;
    if (*(float *)(p + 0x94) > lbl_80564744) var_f1 = lbl_80564730; else var_f1 = lbl_8056475C;
    temp_f8 = *(float *)(p + 0x78) - lbl_80564760 * var_f1; temp_f6 = *(float *)(p + 0x70); temp_f7 = lbl_80564740 + *(float *)(p + 0x74);
    sp14=temp_f6; sp18=temp_f7; sp1C=temp_f8;
    if (&sp14 == &sp14) {
        sp14=temp_f8 * *(float *)(obj+0x18)+(temp_f6 * *(float *)obj+temp_f7 * *(float *)(obj+0xC));
        sp18=temp_f8 * *(float *)(obj+0x1C)+(temp_f6 * *(float *)(obj+4)+temp_f7 * *(float *)(obj+0x10));
        sp1C=temp_f8 * *(float *)(obj+0x20)+(temp_f6 * *(float *)(obj+8)+temp_f7 * *(float *)(obj+0x14));
    } else {
        temp_f3=temp_f8 * *(float *)(obj+0x18)+(temp_f6 * *(float *)obj+temp_f7 * *(float *)(obj+0xC)); sp14=temp_f3;
        temp_f4=temp_f8 * *(float *)(obj+0x1C)+(temp_f3 * *(float *)(obj+4)+temp_f7 * *(float *)(obj+0x10)); sp18=temp_f4;
        sp1C=temp_f8 * *(float *)(obj+0x20)+(temp_f3 * *(float *)(obj+8)+temp_f4 * *(float *)(obj+0x14));
    }
    sp14+=*(float *)(obj+0x24); sp18+=*(float *)(obj+0x28); sp1C+=*(float *)(obj+0x2C);
    var_f0=lbl_805647A4; temp_f5=lbl_80564764+lbl_8056481C*(var_f31* *(float *)(obj+0x50));
    sp8=*(float *)(obj+0x34)+*(float *)obj*temp_f5; spC=*(float *)(obj+0x38)+*(float *)(obj+4)*temp_f5; sp10=*(float *)(obj+0x3C)+*(float *)(obj+8)*temp_f5;
    temp_f1_2=lbl_80564764+lbl_8056482C* *(float *)(obj+0x50); if(var_f0<temp_f1_2){}else var_f0=temp_f1_2;
    sp8+=*(float *)(obj+0xC)*var_f0; temp_f5=*(float *)(obj+0x10)*var_f0; spC+=temp_f5; temp_f4=*(float *)(obj+0x14); sp10+=temp_f4*var_f0;
    fn_8028E590(*(int *)((char *)arg0+4),&sp14,&sp8,-var_f31*fn_80287BC8(lbl_80564744,lbl_8056477C));
}

extern "C" s32 fn_8028E2F8(void*, void*, s32, s32);
extern "C" void fn_8028E61C(void*);
extern "C" int lbl_80349A80[];
extern "C" f32 lbl_8056472C, lbl_80564730, lbl_80564734, lbl_80564738, lbl_8056475C, lbl_80564764, lbl_80564830;
extern "C" void fn_802A3C50(void* arg0, s32 arg1) {
    f32 sp8[40];
    s32 sp20;
    fn_8028E61C(&sp20);
    sp20 = 2;
    *(s32*)((char*)&sp20 + 4) = 0x100;
    *(f32*)((char*)&sp20 + 8) = lbl_80564734;
    *(f32*)((char*)&sp20 + 0xc) = lbl_80564830;
    *(f32*)((char*)&sp20 - 0xc) = lbl_80564730;
    *(f32*)((char*)&sp20 - 8) = lbl_80564730;
    *(f32*)((char*)&sp20 - 4) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x10) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x14) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x18) = lbl_80564730;
    *(f32*)((char*)&sp20 - 0x18) = lbl_80564730;
    *(f32*)((char*)&sp20 - 0x14) = lbl_80564730;
    *(f32*)((char*)&sp20 - 0x10) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x1c) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x20) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x24) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x30) = lbl_80564738;
    *(f32*)((char*)&sp20 + 0x34) = lbl_8056472C;
    *(s32*)((char*)&sp20 + 0x44) = 5;
    *(f32*)((char*)&sp20 + 0x48) = lbl_80564738;
    *(f32*)((char*)&sp20 + 0x54) = lbl_80564734;
    *(f32*)((char*)&sp20 + 0x50) = lbl_80564764;
    *(f32*)((char*)&sp20 + 0x5c) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x58) = lbl_8056475C;
    *(f32*)((char*)&sp20 + 0x74) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x6c) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x64) = lbl_80564730;
    *(f32*)((char*)&sp20 + 0x7c) = lbl_80564730;
    *(s32*)((char*)arg0 + 4) = fn_8028E2F8(&sp20, lbl_80349A80, arg1, 0x100);
}

extern "C" void* __dt__14CollisionSpaceFv_802A3D98(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = &lbl_80349AB0;
        fn_8028E398(*(void**)((char*)arg0 + 4));
        if (arg1 > 0) {
            ((s32 (*)(void*))fn_80128668)(arg0);
        }
    }
    return arg0;
}

extern "C" void fn_802A3DFC(void* arg0) {
    f32* cursor = (f32*)((char*)arg0 + 8);
    s32 i = 0;
    do {
        *cursor = lbl_80564744;
        cursor++;
        i++;
    } while (i < fn_80287B14(arg0));
}

void fn_802A4118(void *arg0, void *arg1) {
    f32 *p = (f32 *)((char *)arg0 + (*(s32 *)((char *)arg1 + 0x28) * 4));
    f32 f = p[2];
    if (f > (lbl_80564730 - lbl_80558DC4)) {
        p[2] = f - lbl_80564730;
    }
    p[2] += lbl_80564750;
}

extern "C" void fn_8028E61C(void *);
extern "C" f32 lbl_8056472C, lbl_80564730, lbl_80564734, lbl_80564738;
extern "C" f32 lbl_8056475C, lbl_80564760, lbl_805647C8, lbl_80564830;
extern "C" u8 lbl_80349A8C[];
extern "C" void fn_802A41D8(void *arg0, s32 arg1) {
    u8 config[0x80];
    fn_8028E61C(config);
    *(s32 *)(config + 0x00) = 2;
    *(s32 *)(config + 0x04) = 0x100;
    *(f32 *)(config + 0x08) = lbl_80564734;
    *(f32 *)(config + 0x0C) = lbl_80564830;
    *(f32 *)(config + 0x14) = lbl_80564730;
    *(f32 *)(config + 0x18) = lbl_80564730;
    *(f32 *)(config + 0x1C) = lbl_80564730;
    *(f32 *)(config + 0x30) = lbl_80564730;
    *(f32 *)(config + 0x34) = lbl_80564730;
    *(f32 *)(config + 0x38) = lbl_80564730;
    *(f32 *)(config + 0x08 - 0x00) = lbl_80564734;
    *(f32 *)(config + 0x2C) = lbl_80564830;
    *(f32 *)(config + 0x50) = lbl_80564738;
    *(f32 *)(config + 0x54) = lbl_8056472C;
    *(s32 *)(config + 0x64) = 5;
    *(f32 *)(config + 0x68) = lbl_80564738;
    *(f32 *)(config + 0x74) = lbl_805647C8;
    *(f32 *)(config + 0x70) = lbl_80564760;
    *(f32 *)(config + 0x7C) = lbl_80564730;
    *(f32 *)(config + 0x78) = lbl_8056475C;
    *(f32 *)(config + 0x94) = lbl_80564730;
    *(f32 *)(config + 0x8C) = lbl_80564730;
    *(f32 *)(config + 0x84) = lbl_80564730;
    *(f32 *)(config + 0x9C) = lbl_80564730;
    ((s32 (*)(void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32))fn_8028E2F8)(config, lbl_80349A8C, arg1, 0x100, 2, lbl_80564760, lbl_805647C8, lbl_8056472C, lbl_80564738, lbl_80564730, lbl_80564830, lbl_80564734);
}

extern "C" void fn_802A44B4(void) {
}

#pragma scheduling off
extern "C" void fn_802A4524(void *arg0) {
    *(f32*)((char*)arg0 + 0x18) = lbl_80564744;
    *(s32*)((char*)arg0 + 0x4) = 0;
}

extern "C" f32 fn_80287BC8(f32, f32);
extern "C" f32 fn_801E7E18(f32);
extern "C" void fn_802A4538(void* arg0, void* arg1, void* arg2, f32 farg0) {
    s32 index, cap, base;
    f32* dst;
    f32 t;
    index = *(s32*)((char*)arg0 + 4);
    cap = *(s32*)((char*)arg0 + 8);
    if (index >= cap) return;
    if (*(f32*)((char*)arg0 + 0x18) <= lbl_80564730 - lbl_80558DC4) return;
    base = *(s32*)arg0;
    dst = (f32*)(base + (index << 5));
    dst[0] = *(f32*)arg1;
    dst[1] = *(f32*)((char*)arg1 + 4);
    dst[2] = *(f32*)((char*)arg1 + 8);
    t = -*(f32*)((char*)arg0 + 0x28);
    dst[3] = *(f32*)arg2 * *(f32*)((char*)arg0 + 0x1C) + fn_80287BC8(t, t);
    t = -*(f32*)((char*)arg0 + 0x2C);
    dst[4] = *(f32*)((char*)arg2 + 4) * *(f32*)((char*)arg0 + 0x20) + *(f32*)((char*)arg0 + 0x34) + fn_80287BC8(t, t);
    t = -*(f32*)((char*)arg0 + 0x30);
    dst[5] = *(f32*)((char*)arg2 + 8) * *(f32*)((char*)arg0 + 0x24) + fn_80287BC8(t, t);
    dst[6] = fn_801E7E18(*(f32*)((char*)arg2 + 8));
    dst[7] = farg0;
    *(s32*)((char*)arg0 + 4) = index + 1;
}

#pragma scheduling on
extern "C" s32 fn_802A4958(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern "C" u8 fn_802A4998(void) {
    return 0;
}

extern "C" void fn_802A49A0(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v2();
}

extern "C" void fn_802A49B4(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v3();
}

extern "C" void fn_802A49C8(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v4();
}

extern "C" void fn_802A49DC(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v5();
}

extern "C" void fn_802A49F0(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v6();
}

extern "C" void fn_802A4A04(void* arg0) {
    ((ebi::title::TBlackPlane*)arg0)->m_a->v7();
}

extern "C" u32 fn_802A4A18(void) { return 1; }

extern "C" u8 fn_802A4A20(void) {
    return 2;
}

extern "C" u32 fn_802A4A28(void) { return 3; }

extern "C" u32 fn_802A4A30(void) { return 4; }

extern "C" u32 fn_802A4A38(void) { return 5; }

extern "C" u32 fn_802A4A40(void) { return 6; }