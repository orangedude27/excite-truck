// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/MTX/mtxtypes.h"

#define FIELD(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define VFIELD(p, off) (*(u8 *)((u8 *)(p) + (off)))

extern f64 fn_8002F234(f64);

extern double lbl_80560C10;
extern f32 lbl_80560C18;
extern f32 lbl_80560C1C;
extern f32 lbl_80560C20;

void select_1obj_continue_head(void *arg0, void *arg1) {
    register u8 *input = (u8 *)arg1 + 0x20;
    register u8 *output = (u8 *)arg0 + 0xEC;
    register u8 *end = (u8 *)arg0 + 0xC8;
    double scale = lbl_80560C10;
    f32 mul = lbl_80560C18;
    f32 sub0 = lbl_80560C1C;
    f32 sub1 = lbl_80560C20;
    s32 invalid = -1;
    s32 zero = 0;
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

extern f32 lbl_80558EB8;
extern f32 lbl_80558EC0;
extern f32 lbl_8055D990;
extern f32 lbl_8055D9B0;
extern f32 lbl_80560BD8;
extern f32 lbl_80560BE4;
s32 select_2obj_first(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *a;
    u8 *b;
    u8 *bestA = 0;
    u8 *bestB = 0;
    f32 best = lbl_80558EC0;
    f32 threshold = lbl_80560BD8;
    f32 length = lbl_80560BE4;
    u8 *aEnd = obj + 0xEC;
    u8 *bEnd = obj + 0xEC;

    for (a = obj + 0xC8; a < aEnd; a += 0xC) {
        if (*(s8 *)(a + 8) != 0) continue;
        for (b = a + 0xC; b <= bEnd; b += 0xC) {
            f32 dx, dy, mag, nx, ny, v, score;
            if (*(s8 *)(b + 8) != 0) continue;
            dx = *(f32 *)(b + 0) - *(f32 *)(a + 0);
            dy = *(f32 *)(b + 4) - *(f32 *)(a + 4);
            mag = (f32)fn_8002F234((f64)(dx * dx + dy * dy));
            nx = dx * (length / mag);
            ny = dy * (length / mag);
            v = lbl_8055D990 * (length / mag);
            score = *(f32 *)(obj + 0x3C8) * (*(f32 *)(obj + 0xB4) * nx + *(f32 *)(obj + 0xB8) * ny)
                 + *(f32 *)(obj + 0x3CC) * (*(f32 *)(obj + 0xB8) * nx - *(f32 *)(obj + 0xB4) * ny);
            if (v <= lbl_8055D9B0 || v >= lbl_80558EB8) continue;
            if (score < threshold) {
                score = -score;
                if (score > best) { best = score; bestA = b; bestB = a; }
            } else if (score > best) { best = score; bestA = a; bestB = b; }
        }
    }
    if (best == lbl_80558EC0) return 0;
    *(u32 *)(obj + 0xF8) = *(u32 *)(bestA + 0);
    *(u32 *)(obj + 0xFC) = *(u32 *)(bestA + 4);
    *(u32 *)(obj + 0x100) = *(u32 *)(bestA + 8);
    *(u32 *)(obj + 0x104) = *(u32 *)(bestB + 0);
    *(u32 *)(obj + 0x108) = *(u32 *)(bestB + 4);
    *(u32 *)(obj + 0x10C) = *(u32 *)(bestB + 8);
    return 2;
}

extern f32 lbl_80558EC4;
extern f32 lbl_8055D998;
extern f32 lbl_8055D99C;
extern f32 lbl_80560BF0;
s32 select_2obj_continue(void *arg0) {
    register u8 *obj = (u8 *)arg0;
    register u8 *a = obj + 0xC8;
    register u8 *b;
    register u8 *bestA;
    register u8 *bestB;
    register u8 *aEnd = obj + 0xEC;
    register u8 *bEnd;
    f32 best = lbl_80560BF0;
    f32 threshold = lbl_80560BD8;
    f32 length = lbl_80560BE4;
    do {
        if (*(s8 *)(a + 8) == 0) {
            b = a + 0xC;
            bEnd = obj + 0xEC;
            do {
                if (*(s8 *)(b + 8) == 0) {
                    f32 dx = *(f32 *)(b + 0) - *(f32 *)(a + 0);
                    f32 dy = *(f32 *)(b + 4) - *(f32 *)(a + 4);
                    f32 mag = (f32)fn_8002F234((f64)(dx * dx + dy * dy));
                    f32 scale = length / mag;
                    f32 nx = dx * scale;
                    f32 ny = dy * scale;
                    f32 v = scale * lbl_8055D990;
                    if (v > lbl_8055D9B0 && v < lbl_80558EB8) {
                        f32 angle = v - *(f32 *)(obj + 0x3AC);
                        f32 dot;
                        s32 reverse;
                        if (angle < threshold) angle *= lbl_8055D998;
                        else angle *= lbl_8055D99C;
                        if (angle < length) {
                            dot = *(f32 *)(obj + 0x3A4) * nx + *(f32 *)(obj + 0x3A8) * ny;
                            reverse = dot < threshold;
                            if (reverse) dot = -dot;
                            if (dot > lbl_80558EC4) {
                                f32 candidate = angle + (length - dot) / (length - lbl_80558EC4);
                                if (candidate < best) {
                                    best = candidate;
                                    if (reverse) { bestA = b; bestB = a; }
                                    else { bestA = a; bestB = b; }
                                }
                            }
                        }
                    }
                }
                b += 0xC;
            } while (b <= bEnd);
        }
        a += 0xC;
    } while (a < aEnd);
    if (best == lbl_80560BF0) return 0;
    *(u32 *)(obj + 0xF8) = *(u32 *)(bestA + 0);
    *(u32 *)(obj + 0xFC) = *(u32 *)(bestA + 4);
    *(u32 *)(obj + 0x100) = *(u32 *)(bestA + 8);
    *(u32 *)(obj + 0x104) = *(u32 *)(bestB + 0);
    *(u32 *)(obj + 0x108) = *(u32 *)(bestB + 4);
    *(u32 *)(obj + 0x10C) = *(u32 *)(bestB + 8);
    return 2;
}

extern f32 lbl_8055D9A0[2];
extern f32 lbl_8055D9A8[2];
s32 select_1obj_first(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *entry = obj + 0xC8;
    u8 *end = obj + 0xF8;
    f32 sx = *(f32 *)(obj + 0xB4);
    f32 cx = *(f32 *)(obj + 0x3C8);
    f32 sy = *(f32 *)(obj + 0xB8);
    f32 cy = *(f32 *)(obj + 0x3CC);
    f32 scale = *(f32 *)(obj + 0x3B0);
    f32 dx = (sx * cx + sy * cy) * scale;
    f32 dy = (sy * cx - sx * cy) * scale;

    do {
        if (*(s8 *)(entry + 8) == 0) {
            f32 x = *(f32 *)(entry + 0);
            f32 y = *(f32 *)(entry + 4);
            f32 left = x - dx;
            f32 bottom = y - dy;
            f32 right = x + dx;
            f32 top = y + dy;
            if (left >= lbl_8055D9A8[0] && left <= lbl_8055D9A0[0] &&
                bottom >= lbl_8055D9A8[1] && bottom <= lbl_8055D9A0[1]) {
                if (right > lbl_8055D9A8[0] && right < lbl_8055D9A0[0] &&
                    top > lbl_8055D9A8[1] && top < lbl_8055D9A0[1]) {
                    *(u32 *)(obj + 0x104) = *(u32 *)(entry + 0);
                    *(u32 *)(obj + 0x108) = *(u32 *)(entry + 4);
                    *(u32 *)(obj + 0x10C) = *(u32 *)(entry + 8);
                    *(f32 *)(obj + 0xF8) = left;
                    *(f32 *)(obj + 0xFC) = bottom;
                    *(u8 *)(obj + 0x100) = 0;
                    *(u8 *)(obj + 0x101) = 0xFF;
                    return -1;
                }
                if (right >= lbl_8055D9A8[0] && right <= lbl_8055D9A0[0] &&
                    top >= lbl_8055D9A8[1] && top <= lbl_8055D9A0[1]) {
                    *(u32 *)(obj + 0xF8) = *(u32 *)(entry + 0);
                    *(u32 *)(obj + 0xFC) = *(u32 *)(entry + 4);
                    *(u32 *)(obj + 0x100) = *(u32 *)(entry + 8);
                    *(f32 *)(obj + 0x104) = right;
                    *(f32 *)(obj + 0x108) = top;
                    *(u8 *)(obj + 0x10C) = 0;
                    *(u8 *)(obj + 0x10D) = 0xFF;
                    return -1;
                }
            }
        }
        entry += 0xC;
    } while (entry < end);
    return 0;
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

