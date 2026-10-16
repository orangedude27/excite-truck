#include <types.h>

extern s32 fn_80128668(void);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80134994(void) {

}

void fn_80134A88(void) {

}

s32 fn_80135038(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern void *lbl_8055E0B0;
void* fn_80135108(void) {
    return lbl_8055E0B0;
}

s32 fn_80135110(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

s32 fn_80135150(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

void fn_80135190(void) {

}

void fn_80135194(void) {

}

void fn_80135198(void) {

}

extern const char lbl_8032BD98[];
extern s32 fn_802E317C(void *, void *);
s32 fn_801351AC(void) {
    return 0;
}

void fn_801351B4(void *param) {
    void *vtable = *(void **)param;
    void (*fn)(void) = *(void **)((u8 *)vtable + 0x10);
    fn();
}

void fn_801351C4(void *arg0, s32 arg1) {
    ((s32 *)arg0)[2] = arg1;
}

void fn_801351CC(void *arg0) {
    extern void fn_8018ADBC(void *, f32);
    extern void fn_8018ADB4(void *, f32);
    extern void fn_8018ADA4(void *, f32);
    extern f32 lbl_805612F4;
    extern f32 lbl_80561318;
    fn_8018ADBC(*(void **)((u8 *)arg0 + 8), lbl_80561318);
    fn_8018ADB4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
    fn_8018ADA4(*(void **)((u8 *)arg0 + 8), lbl_805612F4);
}

void fn_80135218(void) {

}

void fn_80135254(void) {

}

void fn_80135258(void) {

}

void fn_8013525C(void) {

}

void fn_80135260(void) {

}

void fn_80135264(void) {

}

void fn_80135268(void) {

}

void fn_8013526C(void) {

}

