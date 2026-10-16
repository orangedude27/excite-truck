// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u32 lbl_80559900;

extern "C" void Panic__Q26nw4hbm2dbFPCciPCce(const char *, s32, const char *) __attribute__((noreturn));
extern double __ieee754_pow(double, double);

#pragma push
#pragma small_data off
extern u8 lbl_80327010[];
extern u8 lbl_80327020[];
extern f32 lbl_805610C8; // 1.0
extern f32 lbl_805610CC; // 2.0
extern f32 lbl_805610D0; // 0.5
extern f32 lbl_805610E4; // 256.0
extern f32 lbl_805610E8; // 0.0
extern double lbl_805610F0; // 32000.0
extern double lbl_805610F8; // 2.0
extern double lbl_80561100; // 10.0
extern double lbl_80561108; // 1.0
extern f32 lbl_802F6124[]; // pan table
#pragma pop

extern "C" u32 fn_800FEB9C(void);

extern "C" void fn_800FDFF8(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 4);
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)arg0 = 0;
    *(s32 *)((u8 *)arg0 + 4) = (s32)p;
    *(s32 *)((u8 *)arg0 + 8) = (s32)p;
}

u32 fn_800FEB9C(void) {
    u32 val = lbl_80559900 * 0x19660D;
    val += 0x3C6F0000;
    u32 out = val;
    out -= 0x0CA1;
    lbl_80559900 = out;
    return out >> 16;
}

extern "C" void fn_800FEC1C(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
}

extern "C" s32 fn_80128668(void);
extern "C" s32 fn_800FF940(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

