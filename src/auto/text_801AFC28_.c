// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <stddef.h>

extern void *lbl_8055E650;
extern void *lbl_8055E654;
extern u8 lbl_80335A00[];
extern void fn_8017B0B0(void);
extern void fn_8017A57C(void *);
extern void fn_80179EE8(void *, u32);
extern void fn_80128668(void *);
extern f32 lbl_80562578;
extern f32 lbl_8055E3C8;
extern f32 lbl_8056258C;
extern f32 lbl_80562590;
extern f32 lbl_80562594;
extern f32 lbl_80562598;
extern f32 lbl_80562588;
extern void fn_8017B164(void);
extern void fn_8017A580(void *, f32);
extern s32 fn_8017D274(u8 *);
extern f32 lbl_8056257C, lbl_80562580, lbl_80562584;
extern char lbl_803359F0[], lbl_80333B48[];
extern void *fn_801284F8(s32, char *);
extern void fn_8019EECC(void *, void *);
extern void fn_80179F94(void *, void *);
extern void *lbl_80435BA8[];

void fn_801AFC28(void) {
    lbl_8055E650 = 0;
    lbl_8055E654 = 0;
}

#pragma scheduling invalid_target
void *fn_801AFD20(void *this_) {
    f32 value;
    void *vtable;
    fn_8017B0B0();
    value = lbl_80562578;
    vtable = lbl_80335A00;
    *(s32 *)((u8 *)this_ + 0x1F4) = 0;
    *(void **)this_ = vtable;
    *(s32 *)((u8 *)this_ + 0x1F0) = 0;
    *(f32 *)((u8 *)this_ + 0x1EC) = value;
    return this_;
}
#pragma scheduling on
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_801AFD70(void *this_, s32 flag) {
    if (this_ != NULL) {
        if (this_ != NULL) {
            fn_80179EE8(this_, 0);
        }

        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

#pragma push
#pragma processor 750
#pragma scheduling off
void fn_801AFDCC(void *arg0, void *arg1) {
    // Fix note: reverse stack-local declarations so each temporary lands at its target frame offset.
    struct Object {
        void *vtable; void *owner; s32 field8; void *fieldC;
        f32 field10; f32 field14; s32 field18; s32 field1C; s32 field20;
        f32 field24; f32 field28; f32 field2C; f32 field30;
        f32 field34; f32 field38; f32 field3C; f32 field40;
        f32 field44; f32 field48; u8 field4C; u8 pad4D[3]; f32 field50;
    };
    volatile f32 stack1C;
    volatile f32 stack18;
    volatile f32 stack14;
    volatile f32 stack10;
    volatile f32 stackC;
    volatile f32 stack8;
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 zero;
    f32 special;
    struct Object *allocated;
    s32 index;

    fn_8017B0F8();
    temp_f2 = *(volatile f32 *)&lbl_80562580;
    temp_f0 = *(volatile f32 *)((u8 *)arg1 + 0x1C);
    zero = *(volatile f32 *)&lbl_80562578;
    temp_f0 = temp_f2 * temp_f0;
    temp_f3 = *(volatile f32 *)&lbl_8056257C;
    temp_f4 = *(volatile f32 *)((u8 *)arg1 + 0x20);
    temp_f2 = *(volatile f32 *)((u8 *)arg1 + 0x18);
    temp_f5 = temp_f0 / temp_f3;
    temp_f29 = *(volatile f32 *)((u8 *)arg1 + 0x24);
    special = *(volatile f32 *)&lbl_80562584;

    stack14 = zero;
    stack18 = zero;
    stack1C = zero;
    stack8 = zero;
    stackC = special;
    stack10 = zero;

    temp_f4 = temp_f4 * temp_f4;
    temp_f31 = temp_f3 * temp_f2;
    temp_f30 = temp_f5 * temp_f4;

    *(f32 *)((u8 *)arg0 + 0x60) = zero;
    *(f32 *)((u8 *)arg0 + 0x64) = special;
    *(f32 *)((u8 *)arg0 + 0x68) = zero;
    ((void (*)(void *, f32, f32, f32, f32, f32))fn_8017A580)(
        arg0, zero, temp_f2, temp_f3, temp_f4, temp_f5);

    allocated = (struct Object *)fn_801284F8(0x54, lbl_803359F0);
    if (allocated != NULL) {
        special = *(volatile f32 *)&lbl_80562578;
        allocated->fieldC = (u8 *)arg0 + 0x3C;
        allocated->owner = arg0;
        allocated->field8 = 0;
        allocated->field18 = 0x53504852;
        allocated->field10 = temp_f30;
        allocated->field14 = temp_f29;
        allocated->field20 = 0x64;
        allocated->field1C = 0;
        allocated->vtable = lbl_80333B48;
        allocated->field24 = temp_f31;
        allocated->field34 = special;
        allocated->field38 = special;
        allocated->field3C = special;
        allocated->field40 = special;
        allocated->field44 = special;
        allocated->field48 = special;
        allocated->field4C = 0;
        allocated->field50 = special;
        allocated->field28 = stack14;
        allocated->field2C = stack18;
        allocated->field30 = stack1C;

        if (arg0 != NULL) {
            fn_8019EECC(arg0, &allocated->field28);
            fn_80179F94(arg0, allocated);
            special = *(volatile f32 *)&lbl_80562578;
            *(u8 *)((u8 *)arg0 + 0x1E8) = 1;
            *(f32 *)((u8 *)arg0 + 0x1EC) = special;
            index = *(s32 *)(void *)&lbl_8055E650;
            ((void **)lbl_80435BA8)[index] = arg0;
            *(s32 *)(void *)&lbl_8055E650 = index + 1;
        }
    }
}
#pragma pop

void fn_801B0174(void *this_) {
    u8 var0;
    f32 temp;
    s32 var3;

    fn_8017A57C(this_);
    var0 = 0;
    temp = *(f32 *)((u8 *)this_ + 0x1EC);
    if ((lbl_8055E3C8 > temp) && (lbl_8055E3C8 < lbl_8056258C + temp)) {
        var0 = 1;
    }
    *(u8 *)((u8 *)this_ + 0x1F8) = var0;
    var3 = 0;
    if (*(f32 *)((u8 *)this_ + 0x64) <= lbl_80562590) {
        *(u8 *)((u8 *)this_ + 0x1F8) = 0;
    }
    if (*(u8 *)((u8 *)this_ + 0x1F8) != 0) {
        if (lbl_8055E3C8 >= lbl_80562594 + temp) {
            var3 = 1;
        }
    }
    if (var3 != 0) {
        *(s32 *)((u8 *)this_ + 0x24) = *(s32 *)((u8 *)this_ + 0x28);
    } else {
        *(s32 *)((u8 *)this_ + 0x24) = 0;
    }
}

extern s32 fn_8017D274(u8 *);
extern void fn_8017B164(void);
extern void fn_8017A580(void *, f32);
extern f32 lbl_80562598;
extern f32 lbl_80562588;
#pragma cplusplus on
extern "C" void fn_801B022C(void *arg0) {
    class Callback {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
    };
    s32 temp_r0;
    void *var_r31;
    f32 temp_f0;
    f32 temp_f1;
    volatile f32 stack_temp[3];

    fn_8017B164();
    temp_f1 = lbl_80562578;
    temp_f0 = lbl_80562598;
    *(volatile f32 *)((u8 *)arg0 + 0x1EC) = temp_f1;
    *(volatile u8 *)((u8 *)arg0 + 0x1F8) = 0;
    stack_temp[0] = temp_f1;
    stack_temp[1] = temp_f0;
    stack_temp[2] = temp_f1;
    *(volatile f32 *)((u8 *)arg0 + 0x60) = temp_f1;
    *(volatile f32 *)((u8 *)arg0 + 0x64) = temp_f0;
    *(volatile f32 *)((u8 *)arg0 + 0x68) = temp_f1;
    ((void (*)(void *))fn_8017A580)(arg0);
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x28);
    *(s32 *)((u8 *)arg0 + 0x24) = temp_r0;
    if (temp_r0 > 0) {
        var_r31 = *(void **)((u8 *)arg0 + 0x14);
    } else {
        var_r31 = NULL;
    }
    if (var_r31 != NULL) {
        ((Callback *)var_r31)->f8();
        *(f32 *)((u8 *)var_r31 + 0x24) = lbl_80562588;
    }
    lbl_8055E654 = 0;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
}
#pragma cplusplus reset
extern f32 PSVECMag(void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern f32 PSVECDotProduct(void *, void *);
extern void fn_8017B81C(void);
extern void fn_8017B4AC(void *, void *);
extern s32 fn_801E9E30(void *, void *);
extern f32 lbl_80562578, lbl_80562588, lbl_80562598, lbl_8056259C;
extern f32 lbl_805625A0, lbl_805625A4, lbl_805625A8, lbl_805625AC;
void fn_801B02E0(void *arg0) {
    u8 *self = (u8 *)arg0;
    f32 velocityMag;
    f32 speed;
    f32 scale;
    f32 vec[3];
    f32 axis[3];
    s32 result[3];
    s32 active;

    if (*(u8 *)(self + 0x1F8) != 0) {
        fn_8017B81C();
        if (*(f32 *)(self + 0x64) < lbl_80562598)
            *(f32 *)(self + 0x64) = lbl_80562598;

        *(f32 *)(self + 0x124) *= lbl_8056259C;
        *(f32 *)(self + 0x128) *= lbl_8056259C;
        *(f32 *)(self + 0x12C) *= lbl_8056259C;
        *(f32 *)(self + 0x118) *= lbl_805625A0;
        *(f32 *)(self + 0x11C) *= lbl_805625A0;
        *(f32 *)(self + 0x120) *= lbl_805625A0;
        velocityMag = PSVECMag(self + 0x124);
        active = 1;
        if (velocityMag > lbl_805625A4) {
            speed = *(f32 *)(self + 0x40);
            axis[0] = lbl_80562578;
            axis[1] = lbl_80562588;
            axis[2] = lbl_80562578;
            PSVECCrossProduct(self + 0x3C, axis, vec);
            scale = lbl_805625A8 * speed;
            speed = PSVECMag(vec);
            if (lbl_80562588 > speed)
                speed = lbl_80562588;
            scale /= speed;
            vec[0] *= scale;
            vec[1] *= scale;
            vec[2] *= scale;
            fn_8017B4AC(arg0, vec);
            scale = PSVECDotProduct(self + 0x3C, self + 0x118) / velocityMag;
            axis[0] = lbl_80562578;
            axis[1] = lbl_805625AC * scale;
            axis[2] = lbl_80562578;
            fn_8017B4AC(arg0, axis);
            result[0] = *(s32 *)(self + 0x60);
            result[1] = *(s32 *)(self + 0x64);
            result[2] = *(s32 *)(self + 0x68);
            if (fn_801E9E30(self + 0x6C, result) != 0)
                active = 0;
        }
        if (active != 0)
            *(f32 *)(self + 0x64) = lbl_80562598;
    } else {
        *(s32 *)(self + 0x1E4) = 0;
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_801B04B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    volatile s32 *src = (volatile s32 *)arg1;
    f32 *vec1 = (f32 *)arg2;
    f32 *vec2 = (f32 *)arg3;
    s16 *value_ptr = (s16 *)arg4;
    s32 t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1, t0;
    f32 f0, f1, f2, f3, f4, f5;
    s16 value;
    t0 = src[0];
    t1 = src[1];
    t2 = src[2];
    t3 = src[3];
    t4 = src[4];
    t5 = src[5];
    t6 = src[6];
    t7 = src[7];
    t8 = src[8];
    t9 = src[9];
    t10 = src[10];
    t11 = src[11];

    *(s32 *)((u8 *)arg0 + 0x3C) = t0;
    *(s32 *)((u8 *)arg0 + 0x40) = t1;
    *(s32 *)((u8 *)arg0 + 0x44) = t2;
    *(s32 *)((u8 *)arg0 + 0x48) = t3;
    *(s32 *)((u8 *)arg0 + 0x4C) = t4;
    *(s32 *)((u8 *)arg0 + 0x50) = t5;
    *(s32 *)((u8 *)arg0 + 0x54) = t6;
    *(s32 *)((u8 *)arg0 + 0x58) = t7;
    *(s32 *)((u8 *)arg0 + 0x5C) = t8;
    *(s32 *)((u8 *)arg0 + 0x60) = t9;
    *(s32 *)((u8 *)arg0 + 0x64) = t10;
    *(s32 *)((u8 *)arg0 + 0x68) = t11;
    ((void (*)(void *))fn_8017A580)(arg0);
    f5 = vec1[0];
    f4 = vec1[1];
    f3 = vec1[2];
    f2 = vec2[0];
    f1 = vec2[1];
    f0 = vec2[2];
    value = *value_ptr;
    *(f32 *)((u8 *)arg0 + 0x118) = f5;
    *(f32 *)((u8 *)arg0 + 0x11C) = f4;
    *(f32 *)((u8 *)arg0 + 0x120) = f3;
    *(f32 *)((u8 *)arg0 + 0x124) = f2;
    *(f32 *)((u8 *)arg0 + 0x128) = f1;
    *(f32 *)((u8 *)arg0 + 0x12C) = f0;
    *(s16 *)((u8 *)arg0 + 0x6C) = value;
}
#pragma pop
s32 fn_801B0588(void *arg0, u8 *arg1) {
    if (*arg1 != 0) return 0x21;
    return 1;
}

s32 fn_801B05A0(void *arg0, u8 *arg1) {
    *arg1 = *(u8 *)((u8 *)arg0 + 0x1F8);
    if (*(u8 *)((u8 *)arg0 + 0x1F8) != 0)
        return (s32)(((u8 *(*)(void *, u8 *))fn_8017D274)(arg0, arg1 + 1) + 1);
    return 1;
}

extern void fn_8017D160(void *, u8 *, u8 *, s32 *, s32 *, f32);
extern f32 lbl_805625B0;
#pragma cplusplus on
extern "C" void fn_801B05E4(void *arg0, u8 *arg1, u8 *arg2, s32 *arg3, s32 *arg4, f32 arg5) {
    class Callback0 {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8();
        virtual s32 get();
    };
    class Callback1 {
    public:
        virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
        virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
        virtual void f8();
        virtual s32 get(u8 *);
    };
    s32 spC;
    s32 sp8;
    s32 result;
    u8 firstFlag;
    f32 zeroValue;
    f32 resetValue;

    *arg3 = ((Callback0 *)arg0)->get();
    result = ((Callback1 *)arg0)->get(arg2);
    firstFlag = *arg1;
    *arg4 = result;
    if (firstFlag != 0 && *arg2 != 0) {
        *(volatile u8 *)((u8 *)arg0 + 0x1F8) = 1;
        fn_8017D160(arg0, arg1 + 1, arg2 + 1, &spC, &sp8, arg5);
    } else {
        zeroValue = *(volatile f32 *)&lbl_80562578;
        resetValue = *(volatile f32 *)&lbl_805625B0;
        *(volatile u8 *)((u8 *)arg0 + 0x1F8) = 0;
        *(volatile f32 *)((u8 *)arg0 + 0x64) = resetValue;
        *(volatile f32 *)((u8 *)arg0 + 0x118) = zeroValue;
        *(volatile f32 *)((u8 *)arg0 + 0x11C) = zeroValue;
        *(volatile f32 *)((u8 *)arg0 + 0x120) = zeroValue;
    }
}
#pragma cplusplus reset
void __AXDSPInitCallback_801AFC38(void) {
    lbl_8055E650 = 0;
}

extern void *lbl_80435BA8[];
extern void *fn_8017960C(void *);
extern void fn_801B04B0(void *, s32, s32, s32, void *);
#pragma scheduling invalid_target
void fn_801AFC44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *obj;
    void *base;
    s32 n;
    void *p;
    f32 value;

    if ((s32)lbl_8055E650 < 1) return;
    obj = lbl_80435BA8[(s32)lbl_8055E654];
    base = fn_8017960C((void *)arg0);
    fn_801B04B0(obj, arg2, arg3, arg4, (u8 *)base + 0x6C);
    value = lbl_8055E3C8;
    *(s32 *)((u8 *)obj + 0x1F0) = arg0;
    *(s32 *)((u8 *)obj + 0x1F4) = arg1;
    *(f32 *)((u8 *)obj + 0x1EC) = value;
    n = *(s32 *)((u8 *)obj + 0x28);
    *(s32 *)((u8 *)obj + 0x24) = n;
    if (n > 0) p = *(void **)((u8 *)obj + 0x14);
    else p = 0;
    value = *(f32 *)((u8 *)base + arg1 * 0x74 + 0x23E8);
    *(f32 *)((u8 *)p + 0x24) = value;
    n = (s32)lbl_8055E654 + 1;
    lbl_8055E654 = (void *)n;
    if (n < (s32)lbl_8055E650) return;
    lbl_8055E654 = 0;
}
#pragma scheduling on
