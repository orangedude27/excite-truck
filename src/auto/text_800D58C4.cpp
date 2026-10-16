// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/GX/GXTypes.h"

void GetLayoutRect__Q34nw4r3lyt6LayoutCFv(void *arg0, void *arg1) {
    f32 *dst = (f32 *)arg0;
    u8 *src = (u8 *)arg1;
    if (src[0x20] == 1) {
        f32 height = *(f32 *)(src + 0x1C);
        f32 width = *(f32 *)(src + 0x18);
        f32 scale = 0.5f;
        dst[2] = width * scale;
        dst[1] = height * scale;
        dst[0] = -width * scale;
        dst[3] = -height * scale;
    } else {
        f32 zero = 0.0f;
        dst[0] = zero;
        dst[1] = zero;
        dst[2] = *(f32 *)(src + 0x18);
        dst[3] = *(f32 *)(src + 0x1C);
    }
}

extern "C" void fn_800D7F58(void *arg0, void *arg1) {
    volatile f32 *src = (volatile f32 *)arg1;
    f32 v1 = src[1];
    f32 v0 = src[0];
    ((f32 *)arg0)[0] = v0;
    ((f32 *)arg0)[1] = v1;
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

extern "C" void fn_800D86F0(void *arg0, void *arg1) {
    s16 v0, v1, v2, v3;
    v0 = ((s16 *)arg1)[0];
    v1 = ((s16 *)arg1)[1];
    v2 = ((s16 *)arg1)[2];
    v3 = ((s16 *)arg1)[3];
    ((s16 *)arg0)[0] = v0;
    ((s16 *)arg0)[1] = v1;
    ((s16 *)arg0)[2] = v2;
    ((s16 *)arg0)[3] = v3;
}

extern "C" void GXInitLightColor_800D8714(u32 *arg0, u32 *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D8720(s32 *arg0) {
    return *arg0 & 0xF;
}

extern "C" s32 fn_800D872C(u32 *arg0) {
    return (*arg0 >> 4) & 0xF;
}

extern "C" s32 fn_800D8738(u32 *arg0) {
    return (*arg0 >> 8) & 0xF;
}

extern "C" s32 fn_800D8744(u32 *arg0) {
    return (*arg0 >> 25) & 1;
}

extern "C" s32 fn_800D8780(u32 *arg0) {
    return (*arg0 >> 13U) & 3;
}

extern "C" s32 fn_800D878C(u32 *arg0) {
    return (*arg0 >> 15U) & 7;
}

extern "C" s32 fn_800D8798(u32 *arg0) {
    return (*arg0 >> 18U) & 0x1F;
}

extern "C" void fn_800D87A4(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" void fn_800D87D4(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" void fn_800D8804(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" void fn_800D886C(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D893C(void *arg0) {
    return ((u32)*(u32*)((u8*)arg0 + 0x4C) >> 6U) & 1;
}

extern "C" void fn_800D8948(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
}

extern "C" s32 fn_800D896C(void *arg0) {
    return ((u32)*(u32*)((u8*)arg0 + 0x4C) >> 5U) & 1;
}

extern "C" void fn_800D8978(GXColor *arg0, const GXColor *arg1) {
    *arg0 = *arg1;
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

extern "C" s32 fn_800D9328(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x58);
}

extern "C" s32 fn_800D9330(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x58) + ((*(u32 *)((u8 *)arg0 + 0x4C) >> 0x17) & 0x1E0);
}

extern "C" s32 fn_800D9344(void *arg0) {
    volatile u32 *p = (volatile u32 *)((u8 *)arg0 + 0x4C);
    u32 x = *p;
    s32 y = *(volatile s32 *)((u8 *)arg0 + 0x58);
    return (((x >> 0x17) & 0x1E0) + y) + (((x >> 0x18) & 0xF) * 0x14);
}

extern "C" s32 fn_800D9364(void *arg0) {
    volatile u32 *p = (volatile u32 *)((u8 *)arg0 + 0x4C);
    u32 x = *p;
    s32 y = *(volatile s32 *)((u8 *)arg0 + 0x58);
    return ((x >> 0x12) & 0x3C) + ((x >> 0x17) & 0x1E0) + y + (((x >> 0x18) & 0xF) * 0x14);
}

extern "C" void fn_800DB830(s32 *arg0) {
    *arg0 = -1;
}

extern "C" void fn_800DB83C(void) {

}

extern "C" void fn_800DB960(void) {

}

extern "C" s32 fn_800DC6DC(void *arg0) {
    return *(s32 *)((u8 *)arg0 + 0x28);
}

