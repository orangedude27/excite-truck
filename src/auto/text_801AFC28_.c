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

void fn_801AFC28(void) {
    lbl_8055E650 = 0;
    lbl_8055E654 = 0;
}

void *fn_801AFD20(void *this_) {
    fn_8017B0B0();
    *(s32 *)((u8 *)this_ + 0x1F4) = 0;
    *(void **)this_ = lbl_80335A00;
    *(s32 *)((u8 *)this_ + 0x1F0) = 0;
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
    f32 field_1ec = *(f32 *)((u8 *)this_ + 0x1EC);
    f32 field_64;
    u8 var0 = 0;

    fn_8017A57C(this_);
    if ((lbl_8055E3C8 > field_1ec) && (lbl_8055E3C8 < lbl_8056258C + field_1ec)) {
        var0 = 1;
    }
    *(u8 *)((u8 *)this_ + 0x1F8) = var0;
    field_64 = *(f32 *)((u8 *)this_ + 0x64);
    if (field_64 == lbl_80562590) {
        *(u8 *)((u8 *)this_ + 0x1F8) = 0;
    }
    if (*(u8 *)((u8 *)this_ + 0x1F8) != 0) {
        if (lbl_80562594 + *(f32 *)((u8 *)this_ + 0x1EC) >= lbl_8055E3C8) {
            *(s32 *)((u8 *)this_ + 0x24) = *(s32 *)((u8 *)this_ + 0x28);
            return;
        }
    }
    *(s32 *)((u8 *)this_ + 0x24) = 0;
}
void __AXDSPInitCallback_801AFC38(void) {
    lbl_8055E650 = 0;
}
