// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern "C" void fn_800D7F58(void *arg0, void *arg1) {
    ((f32 *)arg0)[0] = ((f32 *)arg1)[0];
    ((f32 *)arg0)[1] = ((f32 *)arg1)[1];
}

extern "C" void fn_800D7F6C(s32 *arg0) {
    *arg0 = -1;
}

extern "C" void fn_800D7F78(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

void fn_800D86F0(void *arg0, void *arg1) {
    ((s16 *)arg0)[0] = ((s16 *)arg1)[0];
    ((s16 *)arg0)[1] = ((s16 *)arg1)[1];
    ((s16 *)arg0)[2] = ((s16 *)arg1)[2];
    ((s16 *)arg0)[3] = ((s16 *)arg1)[3];
}

extern "C" s32 fn_800D893C(void *arg0) {
    return ((u32)*(u32*)((u8*)arg0 + 0x4C) >> 6U) & 1;
}

extern "C" s32 fn_800D896C(void *arg0) {
    return ((u32)*(u32*)((u8*)arg0 + 0x4C) >> 5U) & 1;
}

extern "C" s32 fn_800D899C(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89A4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89AC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89B4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89BC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89C4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89CC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89D4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89DC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" u32 fn_800D89E4(u32 arg0, u32 arg1) {
    if (arg0 > arg1) {
        return arg1;
    }
    return arg0;
}

extern "C" s32 fn_800D89F4(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D89FC(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" s32 fn_800D8A04(s32 arg0, s32 arg1) {
    return arg0 + arg1;
}

extern "C" void fn_800DB83C(void) {

}

extern "C" void fn_800DB960(void) {

}

extern "C" s32 fn_800DC6DC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

