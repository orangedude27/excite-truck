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

void __AXDSPInitCallback_801AFC38(void) {
    lbl_8055E650 = 0;
}
