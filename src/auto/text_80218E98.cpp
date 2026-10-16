// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

void fn_802192A0(void) {

}

extern "C" s32 fn_80229C9C(s32 arg0) {
    return arg0 + 0x264;
}

extern "C" s32 fn_80229CA4(s32 arg0) {
    return arg0 + 0x254;
}

extern "C" void fn_80229CB4(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 1;
    (*(f32 *)((u8 *)arg0 + 0x248)) = 0.0f;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" void fn_80229CD8(void *arg0) {
    (*(u8 *)((u8 *)arg0 + 0x244)) = 0;
    if ((*(u8 *)((u8 *)arg0 + 0x1A)) != 0) {
        (*(u8 *)((u8 *)arg0 + 0x234)) = 1;
    }
}

extern "C" s32 fn_80229CA4(s32);
extern "C" s32 fn_80229C9C(s32);
extern "C" void fn_80229CB4(void *);
extern "C" void fn_80229CD8(void *);
extern void fn_80219044(void *);
