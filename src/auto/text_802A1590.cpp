#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/gki/common/gki.h"
extern "C" void fn_802A41D8(void *arg0, s32 arg1);
extern "C" f32 fn_802C9A4C(f32);
extern "C" void fn_802C8BD0(void*);
extern "C" void fn_802C8D74(void);
extern "C" int fn_802CE860(void*);
extern "C" void fn_802CE868(void);
extern "C" void fn_802CE86C(unsigned int, int, f32, f32, f32, f32);
extern "C" f32 lbl_8056483C;
extern "C" void fn_8028E590(int, f32 *, f32 *, f32);
extern "C" f32 fn_80129DC4(s32, f32, f32);
extern "C" f32 lbl_80564750, lbl_8056476C, lbl_805647C4, lbl_805647DC, lbl_80564804;
extern "C" f32 lbl_805647D4, lbl_805647F4, lbl_80564798, lbl_8056479C, lbl_80564760, lbl_805647BC, lbl_805647EC, lbl_805647AC, lbl_805647F8, lbl_805647FC, lbl_80564800, lbl_805647B4;
extern "C" char lbl_80349A54[];
extern "C" s32 fn_8028E2F8(void *, void *, s32, s32);

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
extern "C" f32 lbl_80564728; extern "C" f32 lbl_8056472C, lbl_80564750, lbl_80564788, lbl_805647E8, lbl_805647EC, lbl_805647F0, lbl_805647C4; extern "C" int lbl_80349A40[]; 
extern "C" const char lbl_80349A28[];
extern "C" const char lbl_80349A68[];
extern "C" f32 lbl_80564808, lbl_8056480C, lbl_80564810, lbl_80564814;
extern "C" f32 lbl_80564798, lbl_8056479C, lbl_805647A8, lbl_805647B4, lbl_805647B8, lbl_805647BC;
extern "C" f32 lbl_80564730, lbl_80564734, lbl_80564740, lbl_80564744, lbl_8056475C, lbl_80564760, lbl_80564764, lbl_805647A0, lbl_805647A4;
extern "C" int lbl_80349A00[], lbl_80349A14[];
extern "C" f32 lbl_805647AC, lbl_805647B0;
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
extern "C" void *fn_802A44B8(void*, s32);
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
extern "C" char lbl_80349BA0[];
extern "C" char lbl_8055CBA4;
class Receiver802A194C { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(void*); };
class Item802A194C { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual unsigned int getType(); };
extern "C" char lbl_8055CB70;
extern "C" void *fn_802AE414(void *);
extern "C" void fn_801345D8(void *, s32, const char *, s32);
extern "C" void *fn_802A194C(void *);
extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_802A1DF4(void *, DummyReceiver_802A3314 *);
extern "C" void *fn_802A2EEC(void *, DummyReceiver_802A3314 *);
extern "C" void *fn_802A3314(void *, DummyReceiver_802A3314 *);
extern "C" void *fn_802A3610(void *, DummyReceiver_802A3314 *);
extern "C" void *fn_802A38D0(void *, DummyReceiver_802A3314 *);
extern "C" void *fn_802A3D3C(void *, DummyReceiver_802A3314 *);
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
#pragma scheduling invalid_target
extern "C" void fn_802A1590(void) {
    class Item {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual s32 v21(void *);
    };
    register void **entry;
    register s32 index;
    char name[0x20];
    memset(lbl_804BCF88, 0, 0x20);
    entry = lbl_804BCF88;
    index = 0;
loop:
    ((void (*)(void *, s32, const char *, ...))fn_801345D8)(name, 0x20, lbl_80349928, index);
    {
        void *obj = fn_802AE414(name);
        if (obj != 0)
            obj = (void *)((Item *)obj)->v21(&lbl_8055CB70);
        if (obj != 0)
            *entry = fn_802A194C(obj);
    }
    index++;
    entry++;
    if (index < 8)
        goto loop;
    fn_80287B38((void *)fn_802A1B20);
    fn_802A1CC4();
    {
        register void *cb = (void *)fn_802A1C30;
        fn_801EEFDC(cb, 5);
    }
}
#pragma scheduling on
extern "C" void fn_802A1660(void) {
    class Dummy {
    public:
        virtual void reset(int);
    };
    register void **entries;
    register int i;
    register int zero = 0;
    fn_801EF024((void *)fn_802A1C30);
    fn_802A1DC0();
    entries = lbl_804BCF88;
    i = 0;
    goto loop;
loop:
    {
        void *obj = *entries;
        if (obj == 0)
            goto next;
        if (obj == 0)
            goto clear;
        ((Dummy *)obj)->reset(1);
clear:
        *entries = (void *)zero;
next:
        i++;
        entries++;
        if (i < 8)
            goto loop;
    }
}
#pragma scheduling on
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

extern "C" void fn_802A17F8(void) {
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
#pragma use_lmw_stmw off
extern "C" s32 fn_802A1864(const char *name) {
    register s32 table[12];
    register s32 *src = (s32 *)lbl_802FAA10;
    register s32 *dst = table;
    register s32 *p = table;
    register unsigned int i = 0;
    *dst++ = *src++; *dst++ = *src++; *dst++ = *src++; *dst++ = *src++;
    *dst++ = *src++; *dst++ = *src++; *dst++ = *src++; *dst++ = *src++;
    *dst++ = *src++; *dst++ = *src++; *dst++ = *src++; *dst = *src;
    do {
        if (stricmp(name, (const char *)p[0]) == 0)
            return ((s32 *)((char *)table + 4))[i * 2];
        ++i;
        p += 2;
    } while (i < 6);
    ((void (*)(const char *, ...))fn_802E317C)(lbl_80349934, name);
    return 0;
}

extern "C" void *fn_802A194C(void *arg0) {
    class Receiver {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual s32 findType(const char *);
    };
    class Item {
    public:
        virtual void v0();
        virtual u32 getType();
    };
    struct Entry {
        void *vtable;
        void *item;
    };
    Receiver *receiver = (Receiver *)arg0;
    char *strings = lbl_80349928;
    void **entries;
    s32 type;
    s32 i;
    void *result;

    receiver->findType((const char *)&lbl_8055CBA4);
    type = ((s32 (*)())fn_802A1864)();
    entries = lbl_804BCF88;
    i = 0;

    while (i < 8) {
        void *item = *entries;
        if (item != 0 && ((Item *)item)->getType() == (u32)type) {
            result = fn_801284F8(8, strings + 0x2C);
            if (result != 0) {
                void *matched = ((void **)lbl_804BCF88)[i];
                ((Entry *)result)->vtable = lbl_80349BA0;
                ((Entry *)result)->item = matched;
            }
            return result;
        }
        i++;
        entries++;
    }

    switch (type) {
    case 1:
        result = fn_801284F8(0x94, strings + 0x40);
        if (result != 0)
            return fn_802A1DF4(result, (DummyReceiver_802A3314 *)arg0);
        return result;
    case 2:
        result = fn_801284F8(0x0C, strings + 0x50);
        if (result != 0)
            return fn_802A2EEC(result, (DummyReceiver_802A3314 *)arg0);
        return result;
    case 3:
        result = fn_801284F8(8, strings + 0x68);
        if (result != 0)
            return fn_802A3314(result, (DummyReceiver_802A3314 *)arg0);
        return result;
    case 4:
        result = fn_801284F8(8, strings + 0x78);
        if (result != 0)
            return fn_802A3610(result, (DummyReceiver_802A3314 *)arg0);
        return result;
    case 5:
        result = fn_801284F8(8, strings + 0x88);
        if (result != 0)
            return fn_802A38D0(result, (DummyReceiver_802A3314 *)arg0);
        return result;
    case 6:
        result = fn_801284F8(0x28, strings + 0x98);
        if (result != 0)
            return fn_802A3D3C(result, (DummyReceiver_802A3314 *)arg0);
        return result;
    default:
        ((void (*)(const char *, ...))fn_802E317C)(strings + 0xA8, type);
        return 0;
    }
}

#pragma use_lmw_stmw on
extern "C" void fn_802A1B20(void* arg0, s32 count) {
    struct Dummy {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void invoke(void*, s32);
    };
    f32 value;
    void* obj;
    s32 off;
    s32 i;
    s32 j;
    value = __fabs(fn_801E7E24());
    if (!(value <= lbl_80558DC4)) {
        i = 0;
        while (i < count) {
            if (*(u8*)((char*)arg0 + 0xC) != 0) {
                j = 0;
                off = 0;
                do {
                    obj = (char*)*(void**)arg0 + off;
                    if (*(u8*)((char*)obj + 0xA0) != 0) {
                        s32 item = *(s32*)((char*)obj + 0xA8);
                        if (item >= 0 && item < 8 &&
                            ((void**)&lbl_804BCF88)[item] != 0 &&
                            (fn_802BF4F0() == 0 || *(f32*)((char*)obj + 0x80) > fn_802BF590())) {
                            ((Dummy*)((void**)&lbl_804BCF88)[*(s32*)((char*)obj + 0xA8)])->invoke(arg0, j);
                        }
                    }
                    j++;
                    off += 0x3C;
                } while (j < 4);
            }
            arg0 = (char*)arg0 + 0x10;
            i++;
        }
    }
}

extern "C" s32 fn_802A1C30(void* arg0) {
    struct TPlaneSubCall {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6(void*);
        virtual void v7(void*);
    };
    s32 index = *(s32*)((char*)arg0 + 0x2C);
    if (index >= 0 && index < 8) {
        TPlaneSubCall* obj = (TPlaneSubCall*)lbl_804BCF88[index];
        if (obj != 0) {
            if (*(f32*)((char*)arg0 + 0x24) > lbl_80564728) obj->v6(arg0);
            else obj->v7(arg0);
        }
    }
    return 0x30;
}

extern "C" void fn_802A1CBC(void) {}

extern "C" void fn_802A1CC0(void) {
}

extern "C" int lbl_803499E8[];
extern "C" int lbl_803499F4[];
extern "C" s32 lbl_8055D430;
extern "C" f32 lbl_80564738, lbl_8056473C;
extern "C" void fn_802A1CC4(void) {
    s32 enabled = 0;
    register int *name = lbl_803499E8;
    u8 config[0x90];
    if ((lbl_8055D430 & 1) != 0) {
        if ((lbl_8055D430 & 8) != 0)
            enabled = 1;
    }
    if (enabled != 0) {
        fn_8028E61C(config);
        *(s32 *)(config + 0x04) = 0x80;
        *(f32 *)(config + 0x08) = lbl_8056472C;
        *(f32 *)(config + 0x0C) = lbl_80564730;
        *(s32 *)(config + 0x00) = 0;
        *(f32 *)(config + 0x10) = lbl_80564730;
        *(f32 *)(config + 0x14) = lbl_80564730;
        *(f32 *)(config + 0x18) = lbl_80564730;
        *(f32 *)(config + 0x1C) = lbl_80564730;
        *(f32 *)(config + 0x20) = lbl_80564730;
        *(f32 *)(config + 0x24) = lbl_80564730;
        *(f32 *)(config + 0x30) = lbl_80564734;
        *(s32 *)(config + 0x44) = 5;
        *(f32 *)(config + 0x50) = lbl_80564730;
        *(f32 *)(config + 0x54) = lbl_80564738;
        *(f32 *)(config + 0x58) = lbl_8056473C;
        *(f32 *)(config + 0x5C) = lbl_80564740;
        *(f32 *)(config + 0x70) = lbl_80564744;
        *(f32 *)(config + 0x68) = lbl_80564744;
        *(f32 *)(config + 0x60) = lbl_80564744;
        *(f32 *)(config + 0x6C) = lbl_80564730;
        *(f32 *)(config + 0x64) = lbl_80564730;
        *(f32 *)(config + 0x74) = lbl_80564744;
        lbl_8055F870 = ((s32 (*)(void *, void *, void *, s32, f32, f32, f32, f32, f32, f32))fn_8028E2F8)(
            config, lbl_803499F4, name, 0,
            lbl_80564740, lbl_8056473C, lbl_80564738,
            lbl_80564734, lbl_80564730, lbl_8056472C);
    } else {
        lbl_8055F870 = 0;
    }
}

extern "C" void fn_802A1DC0(void) {
    if (lbl_8055F870 != 0) {
        fn_8028E398((void *)lbl_8055F870);
        lbl_8055F870 = 0;
    }
}

#pragma scheduling invalid_target
extern "C" void *fn_802A1DF4(void *arg0, DummyReceiver_802A3314 *arg1) {
    register void *self = arg0;
    *(void **)self = lbl_80349B78;
    s32 value = arg1->v3(&lbl_8055CBB0);
    fn_802A2AE8(self, value);
    fn_802A2BF4(self, value);
    fn_802A2D04(self, value);
    fn_802A2E08(self, value);
    return self;
}
#pragma scheduling on
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

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
extern "C" void fn_802A1F00(void *arg0) {
    register double f31 = (double)lbl_80564734;
    register double f30 = (double)lbl_80564744;
    register void *p = arg0;
    register s32 count = 0;
    while (count < ((s32 (*)(void))fn_80287B14)()) {
        *(float *)((char *)p + 0x14) = f30;
        count++;
        *(float *)((char *)p + 0x18) = f31;
        *(float *)((char *)p + 0x1C) = f30;
        *(float *)((char *)p + 0x20) = f30;
        p = (char *)p + 0x10;
    }
    fn_802A4524(*(void **)((char *)arg0 + 0x10));
}
#pragma pop
extern "C" void* fn_80287B24(s32);
extern "C" void fn_802A4658(s32);
extern "C" f32 lbl_80564730, lbl_80564748, lbl_8056474C, lbl_80564750;
#pragma cplusplus on
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling off
extern "C" void fn_802A1F88(void *arg0) {
    register f32 step;
    f32 bound;
    register f32 max;
    register f32 scale;
    register void *p;
    register char *wheel;
    register s32 i;
    f32 rawStep;
    f32 stepScale;

    rawStep = fn_801E7E24();
    stepScale = lbl_80564748;
    p = arg0;
    scale = lbl_8056474C;
    i = 0;
    step = stepScale * rawStep;
    max = lbl_80564750;
    bound = lbl_80564730;

    goto loop_test;
loop_body:
    {
        void *obj = fn_80287B24(i);
        if (fn_802BF4F0() != 0) {
            register s32 active;
            register s32 j;
            f32 threshold;
            wheel = (char *)obj + 0x70;
            active = 4;
            j = 0;
            threshold = fn_802BF590();
            do {
                if (*(f32 *)(wheel + 0x10) < threshold) goto wheel_next;
                if (*(u8 *)(wheel + 0x30) != 0) goto wheel_next;
                --active;
wheel_next:
                ++j;
                wheel += 0x3C;
            } while (j < 4);
            if (active == 0) goto skip;
        }
        {
            f32 b = *(f32 *)((char *)obj + 0x14C);
            f32 a = *(f32 *)((char *)obj + 0x110);
            b = (b > a) ? a : b;
            f32 speed = *(f32 *)((char *)obj + 0x50);
            f32 amount = scale * b;
            speed = speed * step;
            speed = (speed > amount) ? amount : speed;
            if (max < speed) speed = max;
            if (*(f32 *)((char *)p + 0x14) > bound - lbl_80558DC4)
                *(f32 *)((char *)p + 0x14) -= bound;
            *(f32 *)((char *)p + 0x14) += speed;
            if (*(f32 *)((char *)p + 0x18) > bound - lbl_80558DC4)
                *(f32 *)((char *)p + 0x18) -= bound;
            *(f32 *)((char *)p + 0x18) += speed;
        }
skip:
        p = (char *)p + 0x10;
        ++i;
loop_test:
        if (i < ((s32 (*)(void))fn_80287B14)()) goto loop_body;
    }

    {
        f64 rawRate = fn_801E7E24();
        f64 finalRate = __fabs(rawRate);
        f32 finalLimit = lbl_80558DC4;
        if (finalLimit >= (f32)finalRate) return;
    }
    fn_802A4658(*(s32 *)((char *)arg0 + 0x10));
}
#pragma pop
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
#pragma scheduling invalid_target
extern "C" void fn_802A2A38(void* arg0, void* arg1) {
    s32 index = *(s32*)((char*)arg1 + 0x28);
    f32* value = (f32*)((char*)arg0 + (index << 4) + 0x20);
    f32 current = *value;
    f32 limit = lbl_80564730 - lbl_80558DC4;
    int shouldCall = current > limit;
    if (shouldCall) {
        ((void (*)(void*, void*, void*))fn_8028E584)(
            *(void**)((char*)arg0 + 0xC), arg1, (char*)arg1 + 0xC);
    }
    index = *(s32*)((char*)arg1 + 0x28);
    value = (f32*)((char*)arg0 + (index << 4) + 0x20);
    if (*value > lbl_80564730 - lbl_80558DC4) {
        *value -= lbl_80564730;
    }
    *value += lbl_80564750;
}
#pragma scheduling on
extern "C" void fn_802A2AE8(void* arg0, s32 arg1) {
    u8 space[0xA8];
    u8* cfg = space;
    fn_8028E61C(cfg + 0x18);
    *(s32*)(cfg + 0x1C) = 0x200;
    *(f32*)(cfg + 0x20) = lbl_80564740;
    *(f32*)(cfg + 0x24) = lbl_80564730;
    *(s32*)(cfg + 0x18) = 0;
    *(f32*)(cfg + 0x60) = lbl_80564798;
    *(s32*)(cfg + 0x5C) = 4;
    *(f32*)(cfg + 0x0C) = lbl_8056479C;
    *(f32*)(cfg + 0x10) = lbl_80564760;
    *(f32*)(cfg + 0x14) = lbl_8056479C;
    *(f32*)(cfg + 0x28) = lbl_8056479C;
    *(f32*)(cfg + 0x2C) = lbl_80564760;
    *(f32*)(cfg + 0x30) = lbl_8056479C;
    *(f32*)(cfg + 0x00) = lbl_80564798;
    *(f32*)(cfg + 0x04) = lbl_80564734;
    *(f32*)(cfg + 0x08) = lbl_80564798;
    *(f32*)(cfg + 0x34) = lbl_80564798;
    *(f32*)(cfg + 0x38) = lbl_80564734;
    *(f32*)(cfg + 0x3C) = lbl_80564798;
    *(f32*)(cfg + 0x40) = lbl_80564730;
    *(f32*)(cfg + 0x44) = lbl_805647A0;
    *(f32*)(cfg + 0x48) = lbl_80564744;
    *(f32*)(cfg + 0x4C) = lbl_80564740;
    *(f32*)(cfg + 0x8C) = lbl_80564730;
    *(f32*)(cfg + 0x84) = lbl_80564730;
    *(f32*)(cfg + 0x7C) = lbl_80564730;
    *(f32*)(cfg + 0x70) = lbl_8056475C;
    *(f32*)(cfg + 0x74) = lbl_80564730;
    *(f32*)(cfg + 0x68) = lbl_805647A4;
    *(f32*)(cfg + 0x6C) = lbl_80564734;
    *(f32*)(cfg + 0x90) = lbl_805647A8;
    *(f32*)(cfg + 0x94) = lbl_80564764;
    *(s32*)((char*)arg0 + 4) = ((s32 (*)(void*, void*, s32))fn_8028E2F8)(cfg + 0x18, lbl_80349A00, arg1);
}

extern "C" void fn_802A2BF4(void* arg0, s32 arg1) {
    u8 space[0xA8];
    u8* cfg = space;
    fn_8028E61C(cfg + 0x18);
    *(s32*)(cfg + 0x1C) = 0x200;
    *(f32*)(cfg + 0x20) = lbl_80564730;
    *(f32*)(cfg + 0x24) = lbl_80564740;
    *(s32*)(cfg + 0x18) = 0;
    *(f32*)(cfg + 0x60) = lbl_80564798;
    *(s32*)(cfg + 0x5C) = 4;
    *(f32*)(cfg + 0x0C) = lbl_8056479C;
    *(f32*)(cfg + 0x10) = lbl_80564760;
    *(f32*)(cfg + 0x14) = lbl_8056479C;
    *(f32*)(cfg + 0x28) = lbl_8056479C;
    *(f32*)(cfg + 0x2C) = lbl_80564760;
    *(f32*)(cfg + 0x30) = lbl_8056479C;
    *(f32*)(cfg + 0x00) = lbl_80564798;
    *(f32*)(cfg + 0x04) = lbl_80564734;
    *(f32*)(cfg + 0x08) = lbl_80564798;
    *(f32*)(cfg + 0x34) = lbl_80564798;
    *(f32*)(cfg + 0x38) = lbl_80564734;
    *(f32*)(cfg + 0x3C) = lbl_80564798;
    *(f32*)(cfg + 0x40) = lbl_805647AC;
    *(f32*)(cfg + 0x44) = lbl_805647A0;
    *(f32*)(cfg + 0x48) = lbl_80564744;
    *(f32*)(cfg + 0x4C) = lbl_80564734;
    *(f32*)(cfg + 0x8C) = lbl_80564730;
    *(f32*)(cfg + 0x84) = lbl_80564730;
    *(f32*)(cfg + 0x7C) = lbl_80564730;
    *(f32*)(cfg + 0x70) = lbl_8056475C;
    *(f32*)(cfg + 0x74) = lbl_80564730;
    *(f32*)(cfg + 0x68) = lbl_805647B0;
    *(f32*)(cfg + 0x6C) = lbl_80564734;
    *(f32*)(cfg + 0x90) = lbl_805647A8;
    *(f32*)(cfg + 0x94) = lbl_80564764;
    *(s32*)((char*)arg0 + 8) = ((s32 (*)(void*, void*, s32))fn_8028E2F8)(cfg + 0x18, lbl_80349A14, arg1);
}

void fn_802A2D04(void *arg0, s32 arg1) {
    char stack[0xA8];
    fn_8028E61C(&stack[0x18]);
    *(s32 *)(stack+0x1c)=0x100;
    *(f32 *)(stack+0x20)=lbl_80564730;
    *(f32 *)(stack+0x24)=lbl_80564730;
    *(s32 *)(stack+0x18)=0;
    *(f32 *)(stack+0x60)=lbl_80564798;
    *(s32 *)(stack+0x5c)=4;
    *(f32 *)(stack+0x0c)=lbl_8056479C;
    *(f32 *)(stack+0x10)=lbl_80564760;
    *(f32 *)(stack+0x14)=lbl_8056479C;
    *(f32 *)(stack+0x28)=lbl_8056479C;
    *(f32 *)(stack+0x2c)=lbl_80564760;
    *(f32 *)(stack+0x30)=lbl_8056479C;
    *(f32 *)(stack+0x00)=lbl_80564730;
    *(f32 *)(stack+0x04)=lbl_80564730;
    *(f32 *)(stack+0x08)=lbl_80564730;
    *(f32 *)(stack+0x34)=lbl_80564730;
    *(f32 *)(stack+0x38)=lbl_80564730;
    *(f32 *)(stack+0x3c)=lbl_80564730;
    *(f32 *)(stack+0x40)=lbl_805647B4;
    *(f32 *)(stack+0x48)=lbl_80564744;
    *(f32 *)(stack+0x4c)=lbl_80564738;
    *(f32 *)(stack+0x8c)=lbl_80564730;
    *(f32 *)(stack+0x84)=lbl_80564730;
    *(f32 *)(stack+0x7c)=lbl_80564730;
    *(f32 *)(stack+0x70)=lbl_805647B8;
    *(f32 *)(stack+0x74)=lbl_80564738;
    *(f32 *)(stack+0x68)=lbl_805647BC;
    *(f32 *)(stack+0x6c)=lbl_80564738;
    *(f32 *)(stack+0x90)=lbl_805647A8;
    *(f32 *)(stack+0x94)=lbl_80564764;
    *(s32 *)((char *)arg0+0xc)=((s32 (*)(void *, void *, s32))fn_8028E2F8)(&stack[0x18],(void *)lbl_80349A28,arg1);
}

extern "C" void fn_802A44B4(void);
extern "C" void *fn_801284F8(u32, void *);
extern "C" void *fn_802A42C8(void *, void *, s32);
extern "C" int lbl_80349A34[];
extern "C" f32 lbl_80564730, lbl_80564734, lbl_80564740, lbl_80564744, lbl_80564780, lbl_805647AC, lbl_805647C0, lbl_805647C4, lbl_805647C8, lbl_805647CC, lbl_805647D0, lbl_805647D4, lbl_805647D8;
extern "C" char lbl_80349A98[];
extern "C" f32 lbl_80564838;
extern "C" void *fn_8012850C(u32, void *);
extern "C" void *fn_8002F37C(void *, void (*)(void), s32, s32, s32);
extern "C" void *fn_802CAC28(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" f64 fn_8002F208(f32, f32, f32);
extern "C" void fn_802A2E08(void *arg0, s32 arg1) {
    struct Params {
        s32 size;
        f32 a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s;
    } params;
    params.size = 0x834;
    params.a = lbl_805647C0;
    params.b = lbl_805647C4;
    params.c = lbl_805647C8;
    params.d = lbl_805647C8;
    params.e = lbl_805647C8;
    params.f = lbl_80564730;
    params.g = lbl_80564740;
    params.h = lbl_80564730;
    params.j = lbl_805647CC;
    params.i = lbl_805647AC;
    params.k = lbl_80564744;
    params.l = lbl_80564734;
    params.m = lbl_805647D0;
    params.n = lbl_805647D4;
    params.o = lbl_80564780;
    params.p = lbl_80564740;
    params.q = lbl_805647D8;
    params.r = lbl_80564744;
    params.s = lbl_805647C8;
    void *obj = fn_801284F8(0x68, (void *)lbl_80349A34);
    if (obj == 0) return;
    *(s32 *)((u8 *)arg0 + 0x10) =
        ((s32 (*)(void *, Params *, s32))fn_802A42C8)(obj, &params, arg1);
}

#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_802A2EEC(void *arg0, DummyReceiver_802A3314 *arg1) {
    *(void **)arg0 = lbl_80349B50;
    s32 result = arg1->v3(&lbl_8055CBB0);
    fn_802A30BC(arg0, result);
    fn_802A31DC(arg0, result);
    return arg0;
}
#pragma pop
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

extern "C" f32 lbl_805647E0, lbl_805647E4;
extern "C" void fn_802A2FCC(void *arg0, void *arg1, s32 arg2) {
    struct Vec {
        u32 x;
        f32 y;
        u32 z;
    } vec;
    unsigned char *base;
    unsigned char *entry;
    s32 sign;
    f32 factor;
    f64 converted;
    f32 adjustment;
    if (*(f32 *)((char *)arg1 + 8) > lbl_8056476C)
        return;
    base = *(unsigned char **)arg1;
    entry = base + arg2 * 0x3C;
    if (*(f32 *)(entry + 0x98) < lbl_805647DC)
        return;
    if (*(f32 *)(entry + 0x70) < lbl_80564744)
        sign = -1;
    else
        sign = 1;
    vec.x = *(u32 *)(entry + 0x7C);
    vec.y = *(f32 *)(entry + 0x80) + lbl_80564740;
    vec.z = *(u32 *)(entry + 0x84);
    factor = lbl_805647E0 * *(f32 *)(entry + 0x94);
    converted = (f64)sign;
    adjustment = factor * (f32)(converted - 1.0);
    if (*(f32 *)(entry + 0x98) > lbl_805647E4)
        fn_8028E590(*(s32 *)((char *)arg0 + 8), (f32 *)&vec, (f32 *)(base + 0x34), adjustment);
    else
        fn_8028E590(*(s32 *)((char *)arg0 + 4), (f32 *)&vec, (f32 *)(base + 0x34), adjustment);
}

extern "C" void fn_802A30BC(void* arg0, s32 arg1) {
    char stack[0xA8];
    fn_8028E61C(&stack[0x18]);
    *(s32*)(stack + 0x1C) = 0x80;
    *(f32*)(stack + 0x20) = lbl_80564730;
    *(f32*)(stack + 0x24) = lbl_80564734;
    *(s32*)(stack + 0x18) = 2;
    *(f32*)(stack + 0x60) = lbl_80564734;
    *(s32*)(stack + 0x5C) = 4;
    *(f32*)(stack + 0x0C) = lbl_80564798;
    *(f32*)(stack + 0x10) = lbl_80564760;
    *(f32*)(stack + 0x14) = lbl_80564798;
    *(f32*)(stack + 0x28) = lbl_80564798;
    *(f32*)(stack + 0x2C) = lbl_80564760;
    *(f32*)(stack + 0x30) = lbl_80564798;
    *(f32*)(stack + 0x00) = lbl_8056479C;
    *(f32*)(stack + 0x04) = lbl_8056479C;
    *(f32*)(stack + 0x08) = lbl_8056479C;
    *(f32*)(stack + 0x34) = lbl_8056479C;
    *(f32*)(stack + 0x38) = lbl_8056479C;
    *(f32*)(stack + 0x3C) = lbl_8056479C;
    *(f32*)(stack + 0x40) = lbl_8056472C;
    *(f32*)(stack + 0x44) = lbl_805647E8;
    *(f32*)(stack + 0x48) = lbl_805647EC;
    *(f32*)(stack + 0x4C) = lbl_805647AC;
    *(f32*)(stack + 0x88) = lbl_80564750;
    *(f32*)(stack + 0x80) = lbl_80564750;
    *(f32*)(stack + 0x78) = lbl_80564750;
    *(f32*)(stack + 0x8C) = lbl_80564798;
    *(f32*)(stack + 0x84) = lbl_80564798;
    *(f32*)(stack + 0x7C) = lbl_80564798;
    *(f32*)(stack + 0x70) = lbl_805647F0;
    *(f32*)(stack + 0x74) = lbl_805647C4;
    *(f32*)(stack + 0x68) = lbl_805647A4;
    *(f32*)(stack + 0x6C) = lbl_80564734;
    *(f32*)(stack + 0x90) = lbl_80564788;
    *(f32*)(stack + 0x94) = lbl_80564730;
    *(s32*)((char*)arg0 + 4) = ((s32 (*)(void*, void*, s32))fn_8028E2F8)(&stack[0x18], (void*)lbl_80349A40, arg1);
}

#pragma push
#pragma processor 750
#pragma paired off
#pragma paired_single off
#pragma scheduling invalid_target
struct Fn802A31DCConfig {
    f32 f00, f04, f08, f0c, f10, f14;
    s32 f18, f1c;
    f32 f20, f24, f28, f2c, f30, f34, f38, f3c;
    f32 f40, f44, f48, f4c, f50, f54, f58;
    s32 f5c;
    f32 f60, f64, f68, f6c, f70, f74, f78, f7c;
    f32 f80, f84, f88, f8c, f90, f94, f98, f9c, fa0, fa4;
};

extern "C" void fn_802A31DC(void *arg0, s32 arg1) {
    Fn802A31DCConfig cfg;
    fn_8028E61C(&cfg.f18);
    cfg.f1c = 0x40;
    cfg.f20 = lbl_805647D4;
    cfg.f24 = lbl_805647F4;
    cfg.f18 = 2;
    cfg.f60 = lbl_80564734;
    cfg.f0c = lbl_80564798;
    cfg.f10 = lbl_80564760;
    cfg.f14 = lbl_80564798;
    cfg.f28 = lbl_80564798;
    cfg.f2c = lbl_80564760;
    cfg.f30 = lbl_80564798;
    cfg.f00 = lbl_8056479C;
    cfg.f04 = lbl_8056479C;
    cfg.f08 = lbl_8056479C;
    cfg.f34 = lbl_8056479C;
    cfg.f38 = lbl_8056479C;
    cfg.f3c = lbl_8056479C;
    cfg.f40 = lbl_8056479C;
    cfg.f44 = lbl_805647BC;
    cfg.f48 = lbl_805647EC;
    cfg.f4c = lbl_805647AC;
    cfg.f5c = 4;
    cfg.f88 = lbl_80564750;
    cfg.f80 = lbl_80564750;
    cfg.f78 = lbl_80564750;
    cfg.f8c = lbl_80564798;
    cfg.f84 = lbl_80564798;
    cfg.f7c = lbl_80564798;
    cfg.f70 = lbl_805647F8;
    cfg.f74 = lbl_805647FC;
    cfg.f68 = lbl_80564800;
    cfg.f6c = lbl_805647B4;
    cfg.f90 = lbl_8056475C;
    cfg.f94 = lbl_80564730;
    *(s32 *)((char *)arg0 + 8) =
        ((s32 (*)(void *, void *, s32))fn_8028E2F8)(
            &cfg.f18, lbl_80349A54, arg1);
}
#pragma paired_single reset
#pragma paired reset
#pragma scheduling on

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

extern "C" void fn_802A33D4(void* arg0, void* arg1, s32 arg2) {
    f32 value = *(f32*)((char*)arg1 + 8);
    s32 offset = arg2 * 0x3C;
    f32 limit = lbl_8056476C;
    unsigned char* base = *(unsigned char**)arg1;
    unsigned char* item = base + offset;
    s32 a[3];
    f32 p[3];
    f32 angle;
    if (value > limit) goto done;
    if (*(f32*)(item + 0x98) >= lbl_805647DC) goto calculate;
    goto done;
calculate:
    a[0] = *(s32*)(item + 0x7C);
    a[1] = *(s32*)(item + 0x80);
    a[2] = *(s32*)(item + 0x84);
    p[0] = *(f32*)(base + 0x0C) * lbl_80564804;
    p[1] = *(f32*)(base + 0x10) * lbl_80564804;
    p[2] = *(f32*)(base + 0x14) * lbl_80564804;
    p[0] = p[0] + *(f32*)(base + 0x34) * lbl_805647C4;
    p[1] = p[1] + *(f32*)(base + 0x38) * lbl_805647C4;
    p[2] = p[2] + *(f32*)(base + 0x3C) * lbl_805647C4;
    angle = lbl_80564750 * *(f32*)(base + 0x50);
    p[0] = p[0] + fn_80129DC4(0, -angle, angle);
    p[2] = p[2] + fn_80129DC4(0, -angle, angle);
    fn_8028E590(*(s32*)((char*)arg0 + 4), (f32*)a, p, lbl_805647DC);
done:
    ;
}

extern "C" void fn_802A3500(void *arg0, s32 arg1) {
    char stack[0xA8];
    fn_8028E61C(&stack[0x18]);
    *(s32 *)(stack + 0x1c) = 0x12c;
    *(f32 *)(stack + 0x20) = lbl_805647C4;
    *(f32 *)(stack + 0x24) = lbl_80564734;
    *(s32 *)(stack + 0x18) = 2;
    *(f32 *)(stack + 0x60) = lbl_8056479C;
    *(s32 *)(stack + 0x5c) = 4;
    *(f32 *)(stack + 0x0c) = lbl_805647A4;
    *(f32 *)(stack + 0x10) = lbl_80564808;
    *(f32 *)(stack + 0x14) = lbl_805647A4;
    *(f32 *)(stack + 0x28) = lbl_805647A4;
    *(f32 *)(stack + 0x2c) = lbl_80564808;
    *(f32 *)(stack + 0x30) = lbl_805647A4;
    *(f32 *)(stack + 0x00) = lbl_80564730;
    *(f32 *)(stack + 0x04) = lbl_805647B4;
    *(f32 *)(stack + 0x08) = lbl_80564730;
    *(f32 *)(stack + 0x34) = lbl_80564730;
    *(f32 *)(stack + 0x38) = lbl_805647B4;
    *(f32 *)(stack + 0x3c) = lbl_80564730;
    *(f32 *)(stack + 0x40) = lbl_80564730;
    *(f32 *)(stack + 0x44) = lbl_8056480C;
    *(f32 *)(stack + 0x48) = lbl_80564810;
    *(f32 *)(stack + 0x4c) = lbl_80564730;
    *(f32 *)(stack + 0x8c) = lbl_80564730;
    *(f32 *)(stack + 0x84) = lbl_80564730;
    *(f32 *)(stack + 0x7c) = lbl_80564730;
    *(f32 *)(stack + 0x70) = lbl_80564814;
    *(f32 *)(stack + 0x74) = lbl_805647D8;
    *(f32 *)(stack + 0x68) = lbl_8056479C;
    *(f32 *)(stack + 0x6c) = lbl_80564760;
    *(f32 *)(stack + 0x90) = lbl_80564744;
    *(f32 *)(stack + 0x94) = lbl_80564730;
    *(s32 *)((char *)arg0 + 4) = ((s32 (*)(void *, void *, s32))fn_8028E2F8)(&stack[0x18], (void *)lbl_80349A68, arg1);
}

extern "C" { extern f32 lbl_80564730, lbl_80564734, lbl_80564738, lbl_8056479C, lbl_805647A0, lbl_805647B8, lbl_805647C4, lbl_805647F0; extern f32 lbl_80564820, lbl_80564824, lbl_80564828; extern int lbl_80349A74[]; void fn_802A37C8(void*, s32); }
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
extern "C" void fn_802A36D0(void *arg0, void *arg1, s32 arg2) {
    if (*(f32 *)((char *)arg1 + 8) > lbl_8056476C)
        return;
    {
        unsigned char *base = *(unsigned char **)arg1;
        unsigned char *p = base + arg2 * 0x3C;
        if (*(f32 *)(p + 0x98) < lbl_805647DC) {
            if (*(f32 *)(p + 0x94) < lbl_80564818)
                return;
        }
        {
            f32 sp[6];
            f32 temp_f6;
            f32 temp_f5;
            f32 temp_f4;
            f32 temp_f3;
            f32 temp_f2;
            f32 temp_f7;
            if (*(f32 *)(p + 0x70) > lbl_80564744)
                temp_f7 = lbl_80564730;
            else
                temp_f7 = lbl_8056475C;
            temp_f6 = *(f32 *)(base + 0x34) * lbl_805647C4;
            sp[0] = temp_f6;
            temp_f5 = *(f32 *)(base + 0x38) * lbl_805647C4;
            sp[1] = temp_f5;
            temp_f4 = *(f32 *)(base + 0x3C) * lbl_805647C4;
            sp[2] = temp_f4;
            temp_f3 = temp_f7 * *(f32 *)(base + 0x50);
            temp_f2 = lbl_8056481C * temp_f3;
            sp[0] = temp_f6 + *(f32 *)base * temp_f2;
            sp[1] = temp_f5 + *(f32 *)(base + 4) * temp_f2;
            sp[2] = temp_f4 + *(f32 *)(base + 8) * temp_f2;
            fn_8028E590(*(s32 *)((char *)arg0 + 4), (f32 *)(p + 0x7C), sp, lbl_805647DC);
        }
    }
}

extern "C" void fn_802A37C8(void* arg0, s32 arg1) {
    u8 space[0xA8];
    u8* cfg = space;
    fn_8028E61C(cfg + 0x18);
    *(s32*)(cfg + 0x1C) = 0xC0;
    *(f32*)(cfg + 0x20) = lbl_80564820;
    *(f32*)(cfg + 0x24) = lbl_8056479C;
    *(s32*)(cfg + 0x18) = 2;
    *(f32*)(cfg + 0x60) = lbl_80564734;
    *(s32*)(cfg + 0x5C) = 4;
    *(f32*)(cfg + 0x0C) = lbl_80564824;
    *(f32*)(cfg + 0x10) = lbl_80564738;
    *(f32*)(cfg + 0x14) = lbl_80564824;
    *(f32*)(cfg + 0x28) = lbl_80564824;
    *(f32*)(cfg + 0x2C) = lbl_80564738;
    *(f32*)(cfg + 0x30) = lbl_80564824;
    *(f32*)(cfg + 0x00) = lbl_80564730;
    *(f32*)(cfg + 0x04) = lbl_80564730;
    *(f32*)(cfg + 0x08) = lbl_80564730;
    *(f32*)(cfg + 0x34) = lbl_80564730;
    *(f32*)(cfg + 0x38) = lbl_80564730;
    *(f32*)(cfg + 0x3C) = lbl_80564730;
    *(f32*)(cfg + 0x40) = lbl_80564828;
    *(f32*)(cfg + 0x44) = lbl_805647A0;
    *(f32*)(cfg + 0x48) = lbl_80564734;
    *(f32*)(cfg + 0x4C) = lbl_80564734;
    *(f32*)(cfg + 0x8C) = lbl_80564730;
    *(f32*)(cfg + 0x84) = lbl_80564730;
    *(f32*)(cfg + 0x7C) = lbl_80564730;
    *(f32*)(cfg + 0x70) = lbl_805647F0;
    *(f32*)(cfg + 0x74) = lbl_805647C4;
    *(f32*)(cfg + 0x68) = lbl_80564828;
    *(f32*)(cfg + 0x6C) = lbl_80564730;
    *(f32*)(cfg + 0x90) = lbl_805647B8;
    *(f32*)(cfg + 0x94) = lbl_80564730;
    *(s32*)((char*)arg0 + 4) = ((s32 (*)(void*, void*, s32))fn_8028E2F8)(cfg + 0x18, lbl_80349A74, arg1);
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
#pragma scheduling invalid_target
extern "C" void fn_802A3C50(void *arg0, s32 arg1) {
    struct Settings { f32 values[42]; } settings;
    s32 *words = (s32 *)settings.values;
    fn_8028E61C(&settings.values[6]);
    words[6] = 2;
    words[7] = 0x100;
    settings.values[8] = lbl_80564734;
    settings.values[9] = lbl_80564830;
    settings.values[3] = lbl_80564730;
    settings.values[4] = lbl_80564730;
    settings.values[5] = lbl_80564730;
    settings.values[10] = lbl_80564730;
    settings.values[11] = lbl_80564730;
    settings.values[12] = lbl_80564730;
    settings.values[0] = lbl_80564730;
    settings.values[1] = lbl_80564730;
    settings.values[2] = lbl_80564730;
    settings.values[13] = lbl_80564730;
    settings.values[14] = lbl_80564730;
    settings.values[15] = lbl_80564730;
    settings.values[18] = lbl_80564738;
    settings.values[19] = lbl_8056472C;
    words[23] = 5;
    settings.values[24] = lbl_80564738;
    settings.values[27] = lbl_80564734;
    settings.values[26] = lbl_80564764;
    settings.values[29] = lbl_80564730;
    settings.values[28] = lbl_8056475C;
    settings.values[35] = lbl_80564730;
    settings.values[33] = lbl_80564730;
    settings.values[31] = lbl_80564730;
    settings.values[37] = lbl_80564730;
    *(s32 *)((char *)arg0 + 4) = fn_8028E2F8(&settings.values[6], lbl_80349A80, arg1, words[7]);
}
#pragma scheduling on
extern "C" void* fn_802A3D3C(void* arg0, DummyReceiver_802A3314* arg1) {
    *(void**)arg0 = lbl_80349AB0;
    s32 result = arg1->v3(&lbl_8055CBB0);
    fn_802A41D8(arg0, result);
    return arg0;
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

extern "C" void fn_802A3DFC(void *arg0) {
    f32 value = lbl_80564744;
    u8 *cursor = (u8 *)arg0;
    s32 i = 0;
    do {
        *(f32 *)(cursor + 8) = value;
        cursor += 4;
        ++i;
    } while (i < ((s32 (*)(void))fn_80287B14)());
}

extern "C" f32 lbl_80564834;
#pragma scheduling invalid_target
extern "C" void fn_802A4118(void *arg0, void *arg1) {
    s32 index = *(s32 *)((char *)arg1 + 0x28);
    f32 *p = (f32 *)((char *)arg0 + (index << 2));
    s32 shouldCall = p[2] > (lbl_80564730 - lbl_80558DC4);
    if (shouldCall != 0) {
        f32 scale = fn_80287BC8(lbl_80564834, lbl_8056477C);
        fn_8028E590(*(s32 *)((char *)arg0 + 4), (f32 *)arg1,
                     (f32 *)((char *)arg1 + 0xC), scale);
    }

    index = *(s32 *)((char *)arg1 + 0x28);
    p = (f32 *)((char *)arg0 + (index << 2));
    if (p[2] > (lbl_80564730 - lbl_80558DC4))
        p[2] = p[2] - lbl_80564730;
    p[2] += lbl_80564750;
}
#pragma scheduling on
extern "C" void fn_8028E61C(void *);
extern "C" f32 lbl_8056472C, lbl_80564730, lbl_80564734, lbl_80564738;
extern "C" f32 lbl_8056475C, lbl_80564760, lbl_805647C8, lbl_80564830;
extern "C" u8 lbl_80349A8C[];
extern "C" void fn_802A41D8(void *arg0, s32 arg1) {
    u8 config[0xB0];
    fn_8028E61C(config + 0x18);
    register s32 mode = 2;
    register s32 size = 0x100;
    *(s32 *)(config + 0x18) = mode;
    *(s32 *)(config + 0x1C) = size;
    *(f32 *)(config + 0x20) = lbl_80564734;
    *(f32 *)(config + 0x24) = lbl_80564830;
    *(f32 *)(config + 0x0C) = lbl_80564730;
    *(f32 *)(config + 0x10) = lbl_80564730;
    *(f32 *)(config + 0x14) = lbl_80564730;
    *(f32 *)(config + 0x28) = lbl_80564730;
    *(f32 *)(config + 0x2C) = lbl_80564730;
    *(f32 *)(config + 0x30) = lbl_80564730;
    *(f32 *)(config + 0x00) = lbl_80564730;
    *(f32 *)(config + 0x04) = lbl_80564730;
    *(f32 *)(config + 0x08) = lbl_80564730;
    *(f32 *)(config + 0x34) = lbl_80564730;
    *(f32 *)(config + 0x38) = lbl_80564730;
    *(f32 *)(config + 0x3C) = lbl_80564730;
    *(f32 *)(config + 0x48) = lbl_80564738;
    *(f32 *)(config + 0x4C) = lbl_8056472C;
    *(s32 *)(config + 0x5C) = 5;
    *(f32 *)(config + 0x60) = lbl_80564738;
    *(f32 *)(config + 0x6C) = lbl_805647C8;
    *(f32 *)(config + 0x68) = lbl_80564760;
    *(f32 *)(config + 0x74) = lbl_80564730;
    *(f32 *)(config + 0x70) = lbl_8056475C;
    *(f32 *)(config + 0x8C) = lbl_80564730;
    *(f32 *)(config + 0x84) = lbl_80564730;
    *(f32 *)(config + 0x7C) = lbl_80564730;
    *(f32 *)(config + 0x94) = lbl_80564730;
    *(s32 *)((u8 *)arg0 + 4) =
        ((s32 (*)(void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32))fn_8028E2F8)(
            config + 0x18, lbl_80349A8C, arg1, size, mode,
            lbl_80564760, lbl_805647C8, lbl_8056472C,
            lbl_80564738, lbl_80564730, lbl_80564830, lbl_80564734);
}

#pragma push
#pragma scheduling invalid_target
extern "C" void *fn_802A42C8(void *arg0, void *arg1, s32 arg2) {
    struct Params {
        s32 count;
        f32 p4, p8, pC, p10, p14, p18, p1C, p20, p24, p28;
        f32 p2C, p30, p34, p38, p3C, p40, p44, p48, p4C;
    };
    register s32 count = ((volatile struct Params *)arg1)->count;
    register volatile struct Params *params = (volatile struct Params *)arg1;
    register char *object = (char *)arg0;
    register s32 extra = arg2;
    void *entries = fn_8012850C((count << 5) + 0x10, lbl_80349A98);
    entries = fn_8002F37C(entries, fn_802A44B4, 0, 0x20, count);

    register f32 p30 = params->p30;
    s32 copyCount = count;
    register f32 p34 = params->p34;
    s32 zero = 0;
    register f32 p3C = params->p3C;
    register f32 limit = lbl_80564730;
    register f32 slope44 = p34 - p30;
    register f32 p38 = params->p38;
    register f32 p40 = params->p40;
    register f32 remaining = limit - p3C;
    p34 = p38 - p34;
    register f32 p44 = params->p44;
    register f32 p4 = params->p4;
    register f32 p4C = params->p4C;
    register f32 p48 = params->p48;
    register f32 scale = lbl_80564838;
    slope44 /= p3C;
    register f32 p8 = params->p8;
    register f32 pC = params->pC;
    register f32 p10 = params->p10;
    register f32 p14 = params->p14;
    p34 /= remaining;
    register f32 slope54 = p44 - p40;
    register f32 p18 = params->p18;
    register f32 ratio = limit / p4;
    register f32 p1C = params->p1C;
    register f32 p20 = params->p20;
    register f32 p24 = params->p24;
    register f32 p28 = params->p28;
    slope54 /= p4C;
    register f32 p2C = params->p2C;
    scale *= p2C;
    register f32 difference = p48 - p44;
    register f32 slope58 = difference / (limit - p4C);

    *(void **)((char *)object + 0x00) = entries;
    *(s32 *)((char *)object + 0x08) = copyCount;
    *(f32 *)((char *)object + 0x0c) = p4;
    *(f32 *)((char *)object + 0x10) = ratio;
    *(f32 *)((char *)object + 0x14) = p8;
    *(f32 *)((char *)object + 0x1c) = pC;
    *(f32 *)((char *)object + 0x20) = p10;
    *(f32 *)((char *)object + 0x24) = p14;
    *(f32 *)((char *)object + 0x28) = p18;
    *(f32 *)((char *)object + 0x2c) = p1C;
    *(f32 *)((char *)object + 0x30) = p20;
    *(f32 *)((char *)object + 0x34) = p24;
    *(f32 *)((char *)object + 0x38) = scale;
    *(f32 *)((char *)object + 0x3c) = p28;
    *(f32 *)((char *)object + 0x40) = p30;
    *(f32 *)((char *)object + 0x44) = slope44;
    *(f32 *)((char *)object + 0x48) = p34;
    *(f32 *)((char *)object + 0x4c) = p3C;
    *(f32 *)((char *)object + 0x50) = p40;
    *(f32 *)((char *)object + 0x54) = slope54;
    *(f32 *)((char *)object + 0x58) = slope58;
    *(f32 *)((char *)object + 0x5c) = p4C;
    *(void **)((char *)object + 0x60) =
        ((void *(*)(void *, s32))fn_802CAC28)((void *)extra, zero);

    f32 upper = lbl_80564734 - *(f32 *)((char *)object + 0x4c);
    f32 clampUpper = lbl_80564744;
    if (clampUpper > upper) {
    } else {
        clampUpper = upper;
    }
    f32 clampLower = *(f32 *)((char *)object + 0x4c);
    if (clampLower < lbl_80564734) {
    } else {
        clampLower = lbl_80564734;
    }
    f32 product = *(f32 *)((char *)object + 0x44) * clampLower;
    f32 base = *(f32 *)((char *)object + 0x40) + product;
    *(f32 *)((char *)object + 0x64) = (f32)fn_8002F208(
        lbl_805647AC / (base + *(f32 *)((char *)object + 0x48) * clampUpper),
        base, product);
    fn_802A4524(object);
    return object;
}
#pragma pop
  
  extern "C" void fn_802A44B4(void) {
}

extern "C" void fn_802CAC54(s32);
extern "C" void fn_80128670(s32);
extern "C" void *fn_802A44B8(void *arg0, s32 arg1) {
    s32 value;
    if (arg0 != 0) {
        ((void (*)(s32))fn_802CAC54)(*(s32 *)((u8 *)arg0 + 0x60));
        value = *(s32 *)arg0;
        if (value != 0) {
            ((void (*)(s32))fn_80128670)(value - 0x10);
        }
        if (arg1 > 0) {
            ((void (*)(void *))fn_80128668)(arg0);
        }
    }
    return arg0;
}

#pragma scheduling off
extern "C" void fn_802A4524(void *arg0) {
    f32 value = lbl_80564744;
    *(volatile s32 *)((char *)arg0 + 0x4) = 0;
    *(volatile f32 *)((char *)arg0 + 0x18) = value;
}

extern "C" f32 fn_80287BC8(f32, f32);
extern "C" f32 fn_801E7E18(void);
#pragma scheduling invalid_target
extern "C" void fn_802A4538(void* arg0, void* arg1, void* arg2, f32 farg0) {
    f32 saved = farg0;
    long index = *(s32*)((char*)arg0 + 4);
    if (index >= *(s32*)((char*)arg0 + 8))
        return;
    s32 valid = *(f32*)((char*)arg0 + 0x18) >
        lbl_80564730 - lbl_80558DC4;
    if (!valid)
        return;
    f32 first = *(f32*)arg1;
    f32 second = *(f32*)((char*)arg1 + 4);
    f32* dst = (f32*)(*(s32*)arg0 + (index << 5));
    dst[0] = first;
    f32 third = *(f32*)((char*)arg1 + 8);
    dst[1] = second;
    dst[2] = third;
    dst[3] = *(f32*)arg2 * *(f32*)((char*)arg0 + 0x1c) +
        fn_80287BC8(-*(f32*)((char*)arg0 + 0x28), *(f32*)((char*)arg0 + 0x28));
    dst[4] = *(f32*)((char*)arg0 + 0x34) +
        (*(f32*)((char*)arg2 + 4) * *(f32*)((char*)arg0 + 0x20) +
         fn_80287BC8(-*(f32*)((char*)arg0 + 0x2c), *(f32*)((char*)arg0 + 0x2c)));
    dst[5] = *(f32*)((char*)arg2 + 8) * *(f32*)((char*)arg0 + 0x24) +
        fn_80287BC8(-*(f32*)((char*)arg0 + 0x30), *(f32*)((char*)arg0 + 0x30));
    dst[6] = ((f32 (*)(void))fn_801E7E18)();
    dst[7] = saved;
    *(s32*)((char*)arg0 + 4) = *(s32*)((char*)arg0 + 4) + 1;
}

extern "C" void fn_802A4658(s32 arg0) {
    struct Entry { f32 x, y, z, vx, vy, vz, age, pad; };
    struct List {
        struct Entry *data;
        s32 count;
        f32 unk8, elapsed, unk10, advance, phase;
        f32 reserved[7];
        f32 scale, factor;
    };
    struct List *list = (struct List *)arg0;
    register struct Entry *out;
    register u8 *offset;
    register s32 count;
    register struct Entry *in;
    f32 vz;
    f32 vy;
    f32 vx;
    f32 elapsed;
    f32 step;
    f32 scale;
    f32 factor;
    volatile f32 temp_z;
    volatile f32 temp_y;
    volatile f32 temp_x;

    elapsed = fn_801E7E18() - list->elapsed;
    step = fn_801E7E24();
    scale = step * list->scale;
    factor = lbl_80564730 - (list->factor * step);
    out = list->data;
    count = 0;
    offset = 0;
    while (count < list->count) {
        in = (struct Entry *)((u32)list->data + (u32)offset);
        if (in->age > elapsed) {
            vx = in->vx * factor;
            vy = (in->vy * factor) - scale;
            vz = in->vz * factor;
            temp_x = vx;
            temp_y = vy;
            temp_z = (vz * step, vz);
            out->x = in->x + vx * step;
            out->y = in->y + vy * step;
            out->z = in->z + vz * step;
            out->vx = vx;
            out->vy = vy;
            out->vz = vz;
            out->age = in->age;
            out->pad = in->pad;
            out = (struct Entry *)((u8 *)out + 0x20);
        }
        offset += 0x20;
        count++;
    }
    f32 one = lbl_80564730;
    f32 phase = list->phase;
    f32 advance = list->advance;
    list->count = ((s32)out - (s32)list->data) / 32;
    if (phase > one - lbl_80558DC4)
        list->phase = phase - one;
    list->phase = list->phase + advance;
}

extern "C" s32 fn_802A47A8(void *arg0) {
    char *obj = (char *)arg0;
    s32 offset, i, alphaInt, alpha;
    register f32 now;
    register f32 limit;
    f32 saved, v, high, t, low;

    if (*(s32 *)(obj + 4) >= 1) {
        saved = fn_802C9A4C(*(f32 *)(obj + 0x64));
        fn_802C8BD0((void *)*(s32 *)(obj + 0x60));
        if (fn_802CE860((void *)*(s32 *)(obj + 4))) {
            now = ((f32 (*)())fn_801E7E18)();
            limit = lbl_80564744;
            v = lbl_8056483C;
            for (i = 0, offset = 0; i < *(s32 *)(obj + 4); offset += 0x20, i++) {
                char *p = *(char **)obj + offset;
                t = *(f32 *)(obj + 0x10) * (now - *(f32 *)(p + 0x18));
                high = t - *(f32 *)(obj + 0x5C);
                if (limit > high)
                    high = limit;
                low = *(f32 *)(obj + 0x5C);
                low = low < t ? low : t;
                alphaInt = (s32)(v * (*(f32 *)(p + 0x1C) *
                    (*(f32 *)(obj + 0x50) + *(f32 *)(obj + 0x54) * low +
                     *(f32 *)(obj + 0x58) * high)));
                alpha = alphaInt & ((-alphaInt & ~alphaInt) >> 31);
                if (alpha < 0xFF)
                    alphaInt = alpha;
                else
                    alphaInt = 0xFF;
                unsigned int color = (alphaInt << 24) | 0xFFFFFF;
                high = t - *(f32 *)(obj + 0x4C);
                if (limit > high)
                    high = limit;
                low = *(f32 *)(obj + 0x4C);
                low = low < t ? low : t;
                fn_802CE86C(color, 0,
                    *(f32 *)(obj + 0x40) + *(f32 *)(obj + 0x44) * low +
                    *(f32 *)(obj + 0x48) * high,
                    *(f32 *)p, *(f32 *)(p + 4), *(f32 *)(p + 8));
            }
            fn_802CE868();
        }
        fn_802C8D74();
        fn_802C9A4C(saved);
    }
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
