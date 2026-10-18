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

void fn_801AFC28(void) {
    lbl_8055E650 = 0;
    lbl_8055E654 = 0;
}

void *fn_801AFD20(void *this_) {
    s32 zero = 0;
    fn_8017B0B0();
    *(s32 *)((u8 *)this_ + 0x1F4) = zero;
    *(void **)this_ = lbl_80335A00;
    *(s32 *)((u8 *)this_ + 0x1F0) = zero;
    *(f32 *)((u8 *)this_ + 0x1EC) = lbl_80562578;
    return this_;
}

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
void fn_801B022C(void *arg0) {
    s32 temp_r0;
    void *var_r31;
    fn_8017B164();
    *(f32 *)((u8 *)arg0 + 0x1EC) = lbl_80562578;
    *(u8 *)((u8 *)arg0 + 0x1F8) = 0;
    fn_8017A580(arg0, lbl_80562578);
    temp_r0 = *(s32 *)((u8 *)arg0 + 0x28);
    *(s32 *)((u8 *)arg0 + 0x24) = temp_r0;
    if (temp_r0 > 0) {
        var_r31 = *(void **)((u8 *)arg0 + 0x14);
    } else {
        var_r31 = NULL;
    }
    if (var_r31 != NULL) {
        (*(void (**)(void *))(*(u32 *)var_r31 + 0x28))(var_r31);
        *(f32 *)((u8 *)var_r31 + 0x24) = lbl_80562588;
    }
    lbl_8055E654 = 0;
    *(s32 *)((u8 *)arg0 + 0x24) = 0;
}

void fn_801B04B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    s32 temp_r10;
    s32 temp_r9;
    s32 temp_r8;
    s32 temp_r7;
    s32 temp_r6;
    s32 temp_r5;
    s32 *src = (s32 *)arg1;
    temp_r10=src[5]; temp_r9=src[6]; temp_r8=src[7]; temp_r7=src[8]; temp_r6=src[9]; temp_r5=src[10];
    *(s32 *)((u8 *)arg0+0x3c)=src[0]; *(s32 *)((u8 *)arg0+0x40)=src[1]; *(s32 *)((u8 *)arg0+0x44)=src[2]; *(s32 *)((u8 *)arg0+0x48)=src[3]; *(s32 *)((u8 *)arg0+0x4c)=src[4];
    *(s32 *)((u8 *)arg0+0x50)=temp_r10; *(s32 *)((u8 *)arg0+0x54)=temp_r9; *(s32 *)((u8 *)arg0+0x58)=temp_r8; *(s32 *)((u8 *)arg0+0x5c)=temp_r7; *(s32 *)((u8 *)arg0+0x60)=temp_r6; *(s32 *)((u8 *)arg0+0x64)=temp_r5; *(s32 *)((u8 *)arg0+0x68)=src[11];
    fn_8017A580((void *)temp_r5, (f32)temp_r6);
    *(f32 *)((u8 *)arg0+0x118)=((f32 *)arg2)[0]; *(f32 *)((u8 *)arg0+0x11c)=((f32 *)arg2)[1]; *(f32 *)((u8 *)arg0+0x120)=((f32 *)arg2)[2];
    *(f32 *)((u8 *)arg0+0x124)=((f32 *)arg3)[0]; *(f32 *)((u8 *)arg0+0x128)=((f32 *)arg3)[1]; *(f32 *)((u8 *)arg0+0x12c)=((f32 *)arg3)[2];
    *(s16 *)((u8 *)arg0+0x6c)=*(s16 *)arg4;
}

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
void fn_801B05E4(void *arg0, u8 *arg1, u8 *arg2, s32 *arg3, s32 *arg4, f32 arg5) {
    s32 spC;
    s32 sp8;
    *arg3 = (*(s32 (**)(void *))(*(u32 *)arg0 + 0x2C))(arg0);
    *arg4 = (*(s32 (**)(void *, u8 *))(*(u32 *)arg0 + 0x2C))(arg0, arg2);
    if (*arg1 != 0 && *arg2 != 0) {
        *(u8 *)((u8 *)arg0 + 0x1F8) = 1;
        fn_8017D160(arg0, arg1 + 1, arg2 + 1, &spC, &sp8, arg5);
    } else {
        *(u8 *)((u8 *)arg0 + 0x1F8) = 0;
        *(f32 *)((u8 *)arg0 + 0x64) = lbl_805625B0;
        *(f32 *)((u8 *)arg0 + 0x118) = lbl_80562578;
        *(f32 *)((u8 *)arg0 + 0x11C) = lbl_80562578;
        *(f32 *)((u8 *)arg0 + 0x120) = lbl_80562578;
    }
}

void __AXDSPInitCallback_801AFC38(void) {
    lbl_8055E650 = 0;
}

extern void *lbl_80435BA8[];
extern void *fn_8017960C(void *);
extern void fn_801B04B0(void *, s32, s32, s32, void *);
void fn_801AFC44(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *obj;
    void *base;
    s32 n;
    void *p;
    f32 value;

    n = (s32)lbl_8055E650;
    if (n < 1) return;
    obj = lbl_80435BA8[(s32)lbl_8055E654];
    base = fn_8017960C(lbl_80435BA8);
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
    if (n >= (s32)lbl_8055E650) lbl_8055E654 = 0;
}

