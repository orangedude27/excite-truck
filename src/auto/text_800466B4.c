// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/MTX/mtxtypes.h"

extern f64 fn_8002F234(f64);

extern double lbl_80560C10;
extern f32 lbl_80560C18;
extern f32 lbl_80560C1C;
extern f32 lbl_80560C20;

void select_1obj_continue_head(void *arg0, void *arg1) {
    register u8 *input = (u8 *)arg1 + 0x20;
    register u8 *output = (u8 *)arg0 + 0xEC;
    register u8 *end = (u8 *)arg0 + 0xC8;
    f32 sub1 = lbl_80560C20;
    f32 sub0 = lbl_80560C1C;
    f32 mul = lbl_80560C18;
    double scale = lbl_80560C10;
    s32 zero = 0;
    s32 invalid = -1;
    do {
        if (*(u16 *)(input + 4) != 0) {
            *(f32 *)(output + 0) = mul * ((f32)*(s16 *)(input + 0)) - sub0;
            *(f32 *)(output + 4) = mul * ((f32)*(s16 *)(input + 2)) - sub1;
            output[8] = zero;
            output[9] = zero;
        } else {
            output[8] = invalid;
        }
        output -= 0xC;
        input -= 8;
    } while (output >= end);
}

static void clamp_stick_circle(Vec2* stick, s32 sx, s32 sy, s32 min, s32 max) {
    f32 length;
    f32 fx = (f32)sx;
    f32 fy = (f32)sy;
    f32 fmin = (f32)min;
    f32 fmax = (f32)max;

    length = (f32)fn_8002F234(fx * fx + fy * fy);

    if (length <= fmin) {
        stick->x = stick->y = 0.0f;

    } else if (length >= fmax) {
        stick->x = fx / length;
        stick->y = fy / length;

    } else {
        length = (length - fmin) / (fmax - fmin) / length;
        stick->x = fx * length;
        stick->y = fy * length;
    }
}

