#include <types.h>

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8015474C(void);
extern s32 fn_80128668(void);
extern void fn_80128668(void*);
extern void fn_80138AD8(void* this_, u32 a);
extern u8 lbl_8032E46C[];
extern void **lbl_8055E27C;

extern "C" {
void fn_80156188(s32 arg0) {
    fn_8015474C();
}

s32 fn_801568E0(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80156920(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern f32 fn_80129DC4(s32, s32, s32, f32, f32);
extern f32 lbl_8055E3C8;

void fn_80156960(void *arg0) {
    s32 r29 = 0;
    void *r30 = arg0;
    f32 f31 = lbl_8055E3C8;
    s32 r4 = ((s32 *)arg0)[2];
    s32 r5 = ((s32 *)arg0)[1];
    f32 f1 = ((f32 *)arg0)[0xDC / 4];
    f32 f2 = ((f32 *)arg0)[0xE0 / 4];
    
    do {
        s32 temp_r0 = r29 / r4;
        temp_r0 = temp_r0 * r4;
        temp_r0 = r29 - temp_r0;
        temp_r0 = temp_r0 * 8;
        s32 temp_r31 = ((s32 *)*(s32 *)(r5 + temp_r0))[0];
        
        f32 result = fn_80129DC4(4, r4, r5, f1, f2);
        result = f31 + result;
        
        ((f32 *)r30)[0xE4 / 4] = result;
        ((s32 *)r30)[0xE8 / 4] = temp_r31;
        r30 = (void *)((u8 *)r30 + 8);
        r29++;
    } while (r29 < 8);
}

void fn_801569FC(void) {
    void *ptr = lbl_8055E27C;
    if (ptr != NULL) {
        void **table = *(void***)ptr;
        void (*fn)(s32) = (void (*)(s32))*(void**)((u8*)table + 0x28);
        fn(1);
    }
    lbl_8055E27C = NULL;
}

s32 fn_80156A40(void) {
    return (s32)lbl_8055E27C;
}

extern void fn_80128668(void*);
extern void **lbl_8055E27C;
extern u8 lbl_8032E46C[];
extern void fn_80138AD8(void* this_, u32 a);
void* __dt__Q28PSSystem7SeqHeapFv_80156A4C(void* this_, s32 flag) {
    if (this_) {
        *(u32*)this_ = (u32)lbl_8032E46C;
        fn_80138AD8((u8*)this_ + 4, (u32)lbl_8032E46C);
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

}

void fn_80156AC0(void) {

}

void fn_80156B48(void) {

}

void fn_80156B4C(void) {
    return;
}

void fn_80156B50(void) {
    return;
}

