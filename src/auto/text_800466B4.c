// Code of main that had no source file yet: decomp.wtf gave it this one.
extern float lbl_80558ED0;
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
#include "revolution/MTX/mtxtypes.h"
#include "revolution/KPAD/KPAD.h"

typedef struct KPADReadStatus {
    KPADStatus status;
    u32 status_pad;
} KPADReadStatus;

typedef struct KPADReadPrivate {
    KPADReadStatus status;
    u8 pad0[0x8A];
    u16 repeat_count;
    s16 active_chan;
    s16 last_index;
    u8 ring[0x2E8];
} KPADReadPrivate;

extern u8 lbl_8037C808[];
extern f32 lbl_80558EB8;
extern f32 lbl_80560BE4;
extern f64 lbl_80560C28;

#define FIELD(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define VFIELD(p, off) (*(u8 *)((u8 *)(p) + (off)))

extern f64 fn_8002F234(f64);
extern s32 WPADProbe(s32, s32 *);
extern void reset_kpad(void *);
extern f32 lbl_80558EC8, lbl_80558ECC;

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
    struct Pair { u32 x, y; };
    u8 *obj = (u8 *)arg0;
    u8 *aEnd;
    u8 *bEnd;
    u8 *a;
    u8 *b;
    u8 *bestA;
    u8 *bestB;
    f32 length;
    f32 best;
    f32 threshold;
    volatile f32 temp[2];

    best = lbl_80558EC0;
    threshold = lbl_80560BD8;
    a = obj + 0xC8;
    length = lbl_80560BE4;
    aEnd = obj + 0xEC;
    do {
        if (*(s8 *)(a + 8) == 0) {
            b = a + 0xC;
            bEnd = obj + 0xEC;
            do {
                if (*(s8 *)(b + 8) == 0) {
                    register f32 dy, dx;
                    f32 q, p;
                    f32 mag;
                    f32 v;
                    f32 scale;
                    f32 c0, c1, score;
                    dx = *(f32 *)(b + 0) - *(f32 *)(a + 0);
                    dy = *(f32 *)(b + 4) - *(f32 *)(a + 4);
                    mag = (f32)fn_8002F234((f64)(dx * dx + dy * dy));
                    p = *(f32 *)(obj + 0xB4);
                    q = *(f32 *)(obj + 0xB8);
                    scale = length / mag;
                    dx *= scale;
                    dy *= scale;
                    v = lbl_8055D990 * scale;
                    c0 = p * dx + q * dy;
                    c1 = q * dx - p * dy;
                    temp[0] = c0;
                    temp[1] = c1;
                    if (v <= lbl_8055D9B0 || v >= lbl_80558EB8)
                        goto skip_score;
                    score = *(f32 *)(obj + 0x3C8) * c0 + *(f32 *)(obj + 0x3CC) * c1;
                    if (score < threshold) {
                        score = -score;
                        if (score > best) {
                            best = score;
                            bestA = b;
                            bestB = a;
                        }
                    } else if (score > best) {
                        best = score;
                        bestA = a;
                        bestB = b;
                    }
                }
            skip_score:
                b += 0xC;
            } while (b <= bEnd);
        }
        a += 0xC;
    } while (a < aEnd);
    if (best == lbl_80558EC0)
        return 0;
    *(struct Pair *)(obj + 0xF8) = *(struct Pair *)bestA;
    *(u32 *)(obj + 0x100) = *(u32 *)(bestA + 8);
    *(struct Pair *)(obj + 0x104) = *(struct Pair *)bestB;
    *(u32 *)(obj + 0x10C) = *(u32 *)(bestB + 8);
    return 2;
}

extern f32 lbl_80558EC4;
extern f32 lbl_8055D998;
extern f32 lbl_8055D99C;
extern f32 lbl_80560BF0;
s32 select_2obj_continue(void *arg0) {
    struct Pair { u32 x, y; };
    u8 *obj = (u8 *)arg0;
    u8 *aEnd;
    u8 *bEnd;
    u8 *a;
    u8 *b;
    u8 *bestA;
    u8 *bestB;
    f32 best;
    f32 length;
    f32 threshold;
    volatile f32 temp[2];

    best = lbl_80560BF0;
    threshold = lbl_80560BD8;
    a = obj + 0xC8;
    length = lbl_80560BE4;
    aEnd = obj + 0xEC;
    do {
        if (*(s8 *)(a + 8) == 0) {
            b = a + 0xC;
            bEnd = obj + 0xEC;
            do {
                if (*(s8 *)(b + 8) == 0) {
                    f32 dx, dy, mag, scale, angle, dot;
                    s32 reverse;
                    dx = *(f32 *)(b + 0) - *(f32 *)(a + 0);
                    dy = *(f32 *)(b + 4) - *(f32 *)(a + 4);
                    mag = (f32)fn_8002F234((f64)(dx * dx + dy * dy));
                    scale = length / mag;
                    temp[0] = dx * scale;
                    temp[1] = dy * scale;
                    angle = scale * lbl_8055D990;
                    if (angle <= lbl_8055D9B0 || angle >= lbl_80558EB8) goto skip;
                    angle = angle - *(f32 *)(obj + 0x3AC);
                    if (angle < threshold) angle *= lbl_8055D998;
                    else angle *= lbl_8055D99C;
                    if (angle >= length) goto skip;
                    dot = *(f32 *)(obj + 0x3A4) * temp[0] + *(f32 *)(obj + 0x3A8) * temp[1];
                    if (dot < threshold) {
                        dot = -dot;
                        reverse = 1;
                    } else {
                        reverse = 0;
                    }
                    if (dot <= lbl_80558EC4) goto skip;
                    angle += (length - dot) / (length - lbl_80558EC4);
                    if (angle < best) {
                        best = angle;
                        if (reverse) { bestA = b; bestB = a; }
                        else { bestA = a; bestB = b; }
                    }
                }
            skip:
                b += 0xC;
            } while (b <= bEnd);
        }
        a += 0xC;
    } while (a < aEnd);
    if (lbl_80560BF0 == best) return 0;
    *(struct Pair *)(obj + 0xF8) = *(struct Pair *)bestA;
    *(u32 *)(obj + 0x100) = *(u32 *)(bestA + 8);
    *(struct Pair *)(obj + 0x104) = *(struct Pair *)bestB;
    *(u32 *)(obj + 0x10C) = *(u32 *)(bestB + 8);
    return 2;
}

extern f32 lbl_8055D9A0[2];
extern f32 lbl_8055D9A8[2];
#pragma push
#pragma scheduling on
s32 select_1obj_first(void *arg0) {
    u8 *obj = (u8 *)arg0;
    register u8 *entry = obj + 0xC8;
    register u8 *end = obj + 0xF8;
    register f32 *min = lbl_8055D9A8;
    register f32 *max = lbl_8055D9A0;
    f32 sx = *(f32 *)(obj + 0xB4);
    f32 cx = *(f32 *)(obj + 0x3C8);
    f32 sy = *(f32 *)(obj + 0xB8);
    f32 cy = *(f32 *)(obj + 0x3CC);
    f32 xCos = sx * cx;
    f32 yCos = sy * cx;
    f32 scale = *(f32 *)(obj + 0x3B0);
    f32 ySin = sy * cy;
    f32 xSin = sx * cy;
    f32 dx = (xCos + ySin) * scale;
    f32 dy = (yCos - xSin) * scale;

    do {
        if (*(s8 *)(entry + 8) == 0) {
            f32 x = *(f32 *)(entry + 0);
            f32 y = *(f32 *)(entry + 4);
            volatile f32 left = x - dx;
            volatile f32 bottom = y - dy;
            volatile f32 right = x + dx;
            volatile f32 top = y + dy;

            if (left <= min[0] || left >= max[0] || bottom <= min[1] || bottom >= max[1]) {
                if (right > min[0] && right < max[0] && top > min[1] && top < max[1]) {
                    *(u32 *)(obj + 0x104) = *(u32 *)(entry + 0);
                    *(u32 *)(obj + 0x108) = *(u32 *)(entry + 4);
                    *(u32 *)(obj + 0x10C) = *(u32 *)(entry + 8);
                    *(f32 *)(obj + 0xF8) = left;
                    *(f32 *)(obj + 0xFC) = bottom;
                    *(u8 *)(obj + 0x100) = 0;
                    *(u8 *)(obj + 0x101) = 0xFF;
                    return -1;
                }
            } else if (right <= min[0] || right >= max[0] || top <= min[1] || top >= max[1]) {
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
        entry += 0xC;
    } while (entry < end);
    return 0;
}
#pragma pop

int select_1obj_continue(void *obj) {
    unsigned char *candidate;
    unsigned char *other;
    unsigned char *bestCandidate;
    unsigned char *bestOther;
    unsigned char *outerEnd = (unsigned char *)obj + 0x110;
    unsigned char *innerEnd;
    float limit = lbl_80558ED0 * lbl_80558ED0;
    float distance;
    float dx;
    float dy;
    float qx;
    float qy;
    float cosine;
    float sine;
    float scale;
    float xCos;
    float yCos;
    float ySin;
    float xSin;
    float scaledX;
    float scaledY;
    volatile float *rotated;
    volatile u32 *copyFrom;
    u32 firstWord;
    u32 secondWord;
    u32 thirdWord;
    unsigned char *firstCandidate;

    candidate = (unsigned char *)obj + 0xF8;
outer_loop:
    if ((signed char)candidate[8] != 0) goto next_outer;
    if ((signed char)candidate[9] != 0) goto next_outer;
    other = (unsigned char *)obj + 0xC8;
    innerEnd = outerEnd - 0x18;
inner_loop:
    if ((signed char)other[8] == 0) {
        dx = *(float *)(candidate + 0) - *(float *)(other + 0);
        dy = *(float *)(candidate + 4) - *(float *)(other + 4);
        distance = dx * dx + dy * dy;
        if (distance < limit) {
            limit = distance;
            bestCandidate = candidate;
            bestOther = other;
        }
    }
    other += 0xC;
    if (other < innerEnd) goto inner_loop;
next_outer:
    candidate += 0xC;
    if (candidate < outerEnd) goto outer_loop;

    if (limit == lbl_80558ED0 * lbl_80558ED0) return 0;
    copyFrom = (volatile u32 *)bestOther;
    firstWord = copyFrom[0];
    firstCandidate = (unsigned char *)obj + 0xF8;
    secondWord = copyFrom[1];
    *(u32 *)(bestCandidate + 0) = firstWord;
    *(u32 *)(bestCandidate + 4) = secondWord;
    thirdWord = copyFrom[2];
    *(u32 *)(bestCandidate + 8) = thirdWord;

    qx = *(volatile float *)((char *)obj + 0xB4);
    cosine = *(volatile float *)((char *)obj + 0x3C8);
    qy = *(volatile float *)((char *)obj + 0xB8);
    sine = *(volatile float *)((char *)obj + 0x3CC);
    xCos = qx * cosine;
    yCos = qy * cosine;
    scale = *(volatile float *)((char *)obj + 0x3A0);
    ySin = qy * sine;
    xSin = qx * sine;
    dx = xCos + ySin;
    dy = yCos - xSin;
    rotated = (volatile float *)((char *)obj + 0x3A4);
    scaledX = scale * dx;
    rotated[0] = dx;
    scaledY = scale * dy;
    rotated[1] = dy;

    if (bestCandidate == firstCandidate) {
        *(float *)((char *)obj + 0x104) = *(float *)bestCandidate + scaledX;
        *(float *)((char *)obj + 0x108) = *(float *)(bestCandidate + 4) + scaledY;
        *((unsigned char *)obj + 0x10C) = 0;
        *((signed char *)obj + 0x10D) = -1;
    } else {
        *(float *)((char *)obj + 0xF8) = *(float *)bestCandidate - scaledX;
        *(float *)((char *)obj + 0xFC) = *(float *)(bestCandidate + 4) - scaledY;
        *((unsigned char *)obj + 0x100) = 0;
        *((signed char *)obj + 0x101) = -1;
    }
    if ((signed char)*((unsigned char *)obj + 0x84) < 0) return -1;
    return 1;
}

extern f32 lbl_8055D988, lbl_8055D98C, lbl_80560BDC;
void calc_dpd_variable(void *arg0, s8 arg1) {
    struct Pair { f32 x, y; }; u8 *p=(u8*)arg0; struct Pair pos, delta; f32 mag,scale,t,k;
    if(arg1==0){VFIELD(p,0x84)=0;return;}
    pos.x=FIELD(p,0xB4)*FIELD(p,0x3A4)+FIELD(p,0xB8)*FIELD(p,0x3A8);
    pos.y=FIELD(p,0xB8)*FIELD(p,0x3A4)-FIELD(p,0xB4)*FIELD(p,0x3A8);
    if((s8)VFIELD(p,0x84)==0){f32 zero=lbl_80560BD8;*(struct Pair *)(p+0x34)=pos;*(struct Pair *)(p+0x3C)=*(struct Pair *)&lbl_8055D988;FIELD(p,0x44)=zero;}
    else {delta.x=pos.x-FIELD(p,0x34);delta.y=pos.y-FIELD(p,0x38);mag=(f32)fn_8002F234((f64)(delta.x*delta.x+delta.y*delta.y));if(mag>=FIELD(p,0x90)){scale=lbl_80560BE4;}else {scale=mag/FIELD(p,0x90);scale*=scale;scale*=scale;}scale*=FIELD(p,0x94);delta.x=FIELD(p,0x34)+scale*delta.x;delta.y=FIELD(p,0x38)+scale*delta.y;mag=(f32)fn_8002F234((f64)(delta.x*delta.x+delta.y*delta.y));delta.x/=mag;delta.y/=mag;FIELD(p,0x3C)=delta.x-FIELD(p,0x34);FIELD(p,0x40)=delta.y-FIELD(p,0x38);FIELD(p,0x44)=(f32)fn_8002F234((f64)(FIELD(p,0x3C)*FIELD(p,0x3C)+FIELD(p,0x40)*FIELD(p,0x40)));*(struct Pair *)(p+0x34)=delta;}
    {
        f32 value = lbl_8055D990/FIELD(p,0x3A0);
        if ((s8)VFIELD(p,0x84)==0) {
            f32 zero = lbl_80560BD8;
            FIELD(p,0x48)=value; FIELD(p,0x4C)=zero; FIELD(p,0x50)=zero;
        } else {
            f32 zero = lbl_80560BD8; f32 diff = value-FIELD(p,0x48);
            f32 absdiff = diff < zero ? -diff : diff;
            f32 factor;
            if (absdiff >= FIELD(p,0x98)) factor = lbl_80560BE4;
            else { factor=absdiff/FIELD(p,0x98); factor*=factor; factor*=factor; }
            value=factor*FIELD(p,0x9C)*diff;
            FIELD(p,0x4C)=value;
            if (value < zero) FIELD(p,0x50)=-value; else FIELD(p,0x50)=value;
            FIELD(p,0x48)+=FIELD(p,0x4C);
        }
    }
    {
        f32 c = FIELD(p,0x3A4), sn = FIELD(p,0x3A8);
        f32 bx = FIELD(p,0xB4), by = FIELD(p,0xB8);
        f32 rx = c * bx + sn * by;
        f32 ry = -sn * bx + c * by;
        f32 mx = (FIELD(p,0xF8) + FIELD(p,0x104)) * lbl_80560BDC;
        f32 my = (FIELD(p,0xFC) + FIELD(p,0x108)) * lbl_80560BDC;
        f32 xx = rx * mx - ry * my;
        f32 yy = ry * mx + rx * my;
        delta.x = FIELD(p,0xC4) * (FIELD(p,0xBC) - xx);
        delta.y = FIELD(p,0xC4) * (FIELD(p,0xC0) - yy);
        pos.x = -FIELD(p,0xB0)*delta.x + FIELD(p,0xAC)*delta.y;
        pos.y = -FIELD(p,0xAC)*delta.x - FIELD(p,0xB0)*delta.y;
    }
    if((s8)VFIELD(p,0x84)==0){f32 zero=lbl_80560BD8;*(struct Pair *)(p+0x20)=pos;*(struct Pair *)(p+0x28)=*(struct Pair *)&lbl_8055D988;FIELD(p,0x30)=zero;}else{delta.x=pos.x-FIELD(p,0x20);delta.y=pos.y-FIELD(p,0x24);mag=(f32)fn_8002F234((f64)(delta.x*delta.x+delta.y*delta.y));if(mag>=FIELD(p,0x88)){t=lbl_80560BE4;}else {t=mag/FIELD(p,0x88);t*=t;t*=t;}scale=t*FIELD(p,0x8C);FIELD(p,0x28)=scale*delta.x;FIELD(p,0x2C)=scale*delta.y;FIELD(p,0x30)=(f32)fn_8002F234((f64)(FIELD(p,0x28)*FIELD(p,0x28)+FIELD(p,0x2C)*FIELD(p,0x2C)));FIELD(p,0x20)+=FIELD(p,0x28);FIELD(p,0x24)+=FIELD(p,0x2C);}
    VFIELD(p,0x84)=(u8)arg1;
}

void read_kpad_dpd(void *arg0, void *arg1, s32 mode) {
    u8 *p = (u8 *)arg0;
    register u8 *last, *first, *a, *b;
    s32 probe, type;
    s8 selected;
    register f32 dy, dx; f32 scale, x, y, c, d; f64 mag;
    if (*(s16 *)(p + 0x114) < 0) return;
    probe = WPADProbe(*(s16 *)(p + 0x114), &type);
    if ((u32)mode == 1) {
        if (probe != 0) { if (probe == -1) { *(s16 *)(p+0x114) -= 4; reset_kpad(arg0); return; } }
        else ((void (*)(void *, void *, int))select_1obj_continue_head)(arg0,arg1,1);
    } else if ((u32)mode == 2) {
        if (probe != 0) { if (probe == -1) { *(s16 *)(p+0x114) -= 4; reset_kpad(arg0); return; } }
        else ((void (*)(void *, void *, int))select_1obj_continue_head)(arg0,arg1,2);
    } else {
        if (probe != 0) { if (probe == -1) { *(s16 *)(p+0x114) -= 4; reset_kpad(arg0); return; } }
        else ((void (*)(void *, void *, int))select_1obj_continue_head)(arg0,arg1,0);
    }
    first = p + 0xc8; last = p + 0xec;
    a = last;
    do {
        if (*(s8 *)(a+8) >= 0 && (*(f32 *)a <= lbl_8055D9A8[0] || *(f32 *)a >= lbl_8055D9A0[0] || *(f32 *)(a+4) <= lbl_8055D9A8[1] || *(f32 *)(a+4) >= lbl_8055D9A0[1]))
            a[8] |= 1;
        a -= 12;
    } while (a >= first);
    a = first;
    do {
        if (*(s8 *)(a+8) == 0) {
            b = a + 12;
            do {
                if (*(s8 *)(b+8) == 0 && *(f32 *)a == *(f32 *)b && *(f32 *)(a+4) == *(f32 *)(b+4)) b[8] |= 2;
                b += 12;
            } while (b <= last);
        }
        a += 12;
    } while (a < last);
    *(s16 *)(p+0x110) = 0;
    a = p + 0xec; first = p + 0xc8;
    do {
        if (*(s8 *)(a+8) == 0) ++*(s16 *)(p+0x110);
        a -= 12;
    } while (a >= first);
    selected = 0;
    if (!(*(f32 *)(p+0x54) <= lbl_80558ECC)) {
        if (*(s8 *)(p+0x84) == 2 || *(s8 *)(p+0x84) == -2) {
            if (*(s16 *)(p+0x110) >= 2) selected = select_2obj_continue(arg0);
            if (!selected && *(s16 *)(p+0x110) >= 1) selected = select_1obj_continue(arg0);
        } else if (*(s8 *)(p+0x84) == 1 || *(s8 *)(p+0x84) == -1) {
            if (*(s16 *)(p+0x110) >= 2) selected = select_2obj_first(arg0);
            if (!selected && *(s16 *)(p+0x110) >= 1) selected = select_1obj_continue(arg0);
        } else {
            if (*(s16 *)(p+0x110) >= 2) selected = select_2obj_first(arg0);
            if (!selected && *(s16 *)(p+0x110) == 1) selected = select_1obj_first(arg0);
        }
    }
    if (selected) {
        dx = *(f32 *)(p+0x104) - *(f32 *)(p+0xf8);
        dy = *(f32 *)(p+0x108) - *(f32 *)(p+0xfc);
        mag = (f32)fn_8002F234(dx*dx+dy*dy);
        scale = lbl_80560BE4 / mag;
        *(f32 *)(p+0x3a0) = mag;
        x = *(f32 *)(p+0xb4); y = *(f32 *)(p+0xb8);
        dx *= scale; dy *= scale;
        *(f32 *)(p+0x3a4) = dx;
        *(f32 *)(p+0x3ac) = lbl_8055D990 * scale;
        c = x*dx+y*dy; d = y*dx-x*dy;
        *(f32 *)(p+0x3a8) = dy;
        *(f32 *)(p+0x3c0) = c; *(f32 *)(p+0x3c4) = d;
        if (*(u16 *)(p+0x3d8) == 0 && c * *(f32 *)(p+0x3c8) + d * *(f32 *)(p+0x3cc) <= lbl_80558EC8) {
            selected = 0; p[0x10c] = 1; p[0x100] = 1;
        }
        if ((s32)p[0x84] == 2 && selected == 2) {
            if (p[0x3da] == 0xc8) *(f32 *)(p+0x3b0) = *(f32 *)(p+0x3a0);
            else ++p[0x3da];
        } else p[0x3da] = 0;
    } else p[0x3da] = 0;
    calc_dpd_variable(arg0, selected);
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

extern s32 WPADProbe(s32, s32 *);
extern void reset_kpad(void *);
extern s32 lbl_80558ED4, lbl_80558ED8, lbl_80558EDC, lbl_80558EE0;
extern s32 lbl_80558EE4, lbl_80558EE8;
extern f64 lbl_80560C10;
extern f32 lbl_80560BD8, lbl_80560BE4;
static void clamp_stick_circle(Vec2*, s32, s32, s32, s32);
void clamp_stick_cross(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *input = (u8 *)arg1;
    register s16 chan = *(s16 *)(obj + 0x114);
    s32 devType;
    s32 ret;
    double bias = lbl_80560C10;
    if (chan < 0) return;
    ret = WPADProbe(chan, &devType);
    if (*(u32 *)(obj + 0x5C) == 1) {
        if (ret != 0 && ret == -1) {
            *(s16 *)(obj + 0x114) -= 4;
            reset_kpad(obj);
            return;
        }
        {
            volatile s8 *stick = (volatile s8 *)(input + 0x30);
            clamp_stick_circle((Vec2 *)(obj + 0x60), stick[0], stick[1], lbl_80558ED4, lbl_80558ED8);
        }
        return;
    }
    if (*(u32 *)(obj + 0x5C) != 2) return;
    if (ret != 0 && ret == -1) {
        *(s16 *)(obj + 0x114) -= 4;
        reset_kpad(obj);
        return;
    }
    clamp_stick_circle((Vec2 *)(obj + 0x6C), *(s16 *)(input + 0x2C), *(s16 *)(input + 0x2E), lbl_80558EDC, lbl_80558EE0);
    clamp_stick_circle((Vec2 *)(obj + 0x74), *(s16 *)(input + 0x30), *(s16 *)(input + 0x32), lbl_80558EDC, lbl_80558EE0);
    {
        register s32 value;
        register s32 high;
        register s32 low;
        low = *(volatile s32 *)&lbl_80558EE4;
        value = input[0x34];
        high = *(volatile s32 *)&lbl_80558EE8;
        if (value <= low) *(f32 *)(obj + 0x7C) = lbl_80560BD8;
        else if (value >= high) *(f32 *)(obj + 0x7C) = lbl_80560BE4;
        else *(f32 *)(obj + 0x7C) = (f32)(value - low) / (f32)(high - low);
    }
    {
        register s32 value;
        register s32 high;
        register s32 low;
        low = *(volatile s32 *)&lbl_80558EE4;
        value = input[0x35];
        high = *(volatile s32 *)&lbl_80558EE8;
        if (value <= low) *(f32 *)(obj + 0x80) = lbl_80560BD8;
        else if (value >= high) *(f32 *)(obj + 0x80) = lbl_80560BE4;
        else *(f32 *)(obj + 0x80) = (f32)(value - low) / (f32)(high - low);
    }
}

s32 read_kpad_stick(s32 chan, void *arg1) {
    u32 probe;
    s32 ret;
    s32 irq;
    u8 *obj = (u8 *)arg1;
    extern s32 WPADProbe(s32, s32 *);
    extern void WPADSetAutoSamplingBuf(s32, void *, u32);
    extern s32 OSDisableInterrupts(void);
    extern void OSRestoreInterrupts(s32);
    extern void reset_kpad(void *);
    extern s32 fn_80062460(s32);
    extern void KPADiControlDpdCallback(s32, u32);
    extern void KPADiSamplingCallback(s32, u32);
    extern u8 lbl_8037C808[];
    ret = WPADProbe(chan, (s32 *)&probe);
    if (ret == -1) {
        if (*(s16 *)(obj + 0x114) >= 0) {
            WPADSetAutoSamplingBuf(chan, 0, 0);
            *(s16 *)(obj + 0x114) = chan - 4;
            *(u32 *)(obj + 0x5C) = 0xFD;
            obj = lbl_8037C808 + (chan << 10);
            irq = OSDisableInterrupts();
            if (*(u32 *)(obj + 0x3F0) != 0) {
                *(u32 *)(obj + 0x3F0) = 0;
                if (*(u32 *)(obj + 0x3F8) != 0) {
                    ((void (*)(s32, s32))(*(u32 *)(obj + 0x3F8)))(chan, 1);
                }
            }
            OSRestoreInterrupts(irq);
        }
        return -1;
    }
    if (ret != 0) return 0;
    if (probe == *(u32 *)(obj + 0x5C)) {
        if (*(u32 *)(obj + 0x3F4) != 0) { reset_kpad(obj); return 1; }
        ret = fn_80062460(chan);
        if (*(u32 *)(obj + 0x3EC) != 0 && ret == 0) { KPADiControlDpdCallback(chan, probe); reset_kpad(obj); return 1; }
        if (*(u32 *)(obj + 0x3EC) == 0 && ret != 0) { KPADiSamplingCallback(chan, probe); reset_kpad(obj); return 1; }
        if (*(u32 *)(obj + 0x3FC) != 0) {
            if (*(u32 *)(obj + 0x3EC) != 0) KPADiControlDpdCallback(chan, probe);
            else KPADiSamplingCallback(chan, probe);
            reset_kpad(obj); return 1;
        }
        return 0;
    }
    if (*(volatile u32 *)&probe != 0xFD) {
        if (*(u32 *)(obj + 0x3EC) != 0) KPADiControlDpdCallback(chan, probe);
        else KPADiSamplingCallback(chan, probe);
    } else {
        *(s16 *)(obj + 0x114) = chan - 4;
        return -1;
    }
    *(s16 *)(obj + 0x114) = chan;
    *(u32 *)(obj + 0x5C) = probe;
    reset_kpad(obj);
    return 1;
}

#pragma push
#pragma fp_contract on
// Read up to numSamples controller status samples for chan from the KPAD ring buffer,
// replaying the new entries and repeating the last one to fill the requested count.
s32 KPADRead(s32 chan, KPADStatus *pSamples, s32 numSamples) {
    extern f32 lbl_80558EB8;                  /* kp_err_dist_max */
    extern f32 lbl_80560BE4;                  /* 1.0f */
    extern u8 fn_80062458(void);              /* WPADGetDpdSensitivity */
    extern void read_kpad_acc(void *, void *, s32, s32);
    extern void read_kpad_dpd(void *, void *, s32);
    extern void calc_acc_horizon(void *, void *, s32);
    extern s32 fn_800609E0(s32);              /* WPADGetLatestIndexInBuf */
    register s32 chanCopy=chan;
    register KPADReadPrivate *kp=(KPADReadPrivate *)(lbl_8037C808+(chan<<10));
    register u8 *coreStatus;
    register u8 *fsStatus;
    register KPADReadStatus *sampleBuf=(KPADReadStatus *)pSamples;
    register s32 ringIndex;
    register s32 available;
    register u32 count=numSamples;
    register s32 remaining;
    register KPADReadStatus *out;
    s32 latestIndex;
    u32 devType;
    u8 *ringEntry;
    f32 sensitivity;

    sensitivity=(f32)fn_80062458();
    lbl_80558EB8=lbl_80560BE4+sensitivity;
    out=sampleBuf+(count-1);
init_samples:
    *(u32 *)&out->status.dev_type=*(u32 *)&kp->status.status.dev_type;
    out--;
    if(out>=sampleBuf) goto init_samples;
    if (((s32 (*)(s32,void *))read_kpad_stick)(chanCopy,kp)!=0) return 0;
    if(*(u32 *)&kp->status.status.dev_type==0xFD) return 0;  /* WPAD_DEV_NOT_FOUND */
    if(kp->active_chan>=0) latestIndex=fn_800609E0(kp->active_chan);
    else latestIndex=fn_800609E0(kp->active_chan+4);
    ringIndex=kp->last_index;
    if(ringIndex<0) { ringIndex=latestIndex-1; if(ringIndex<0) ringIndex=0xB; }
    available=latestIndex-ringIndex;
    kp->last_index=latestIndex;
    if(available==0) return 0;
    if(available<0) available+=0xC;
    if(available<count) count=available;
    kp->repeat_count=0;
    devType=*(u32 *)&kp->status.status.dev_type;
    out=sampleBuf+count;
    if(devType==0 || devType==0xFB || devType==0xFF || devType==0xFC) {
        /* WPAD_DEV_CORE / WPAD_DEV_FUTURE / WPAD_DEV_UNKNOWN / WPAD_DEV_NOT_SUPPORTED */
        do {
            ringIndex++; if(ringIndex==0xC) ringIndex=0;
            ringEntry=(u8 *)kp+ringIndex*0x2A; coreStatus=ringEntry+0x118;
            *((u8 *)kp+0x85)=ringEntry[0x141];
            read_kpad_acc(kp,coreStatus,0,chanCopy); read_kpad_dpd(kp,coreStatus,0);
            if(kp->repeat_count>=(s32)(available-count)) {
                out--;
                *out=kp->status;
            }
        } while(++kp->repeat_count<available);
    } else if(devType==1) {
        /* WPAD_DEV_FREESTYLE */
        do {
            ringIndex++; if(ringIndex==0xC) ringIndex=0;
            ringEntry=(u8 *)kp+ringIndex*0x32; fsStatus=ringEntry+0x118;
            *((u8 *)kp+0x85)=ringEntry[0x141];
            read_kpad_acc(kp,fsStatus,1,chanCopy); read_kpad_dpd(kp,fsStatus,1); clamp_stick_cross(kp,fsStatus);
            if(kp->repeat_count>=(s32)(available-count)) {
                out--;
                *out=kp->status;
            }
        } while(++kp->repeat_count<available);
    } else if(devType==2) {
        /* WPAD_DEV_CLASSIC: sampleBuf is reused as the classic ring entry */
        do {
            ringIndex++; if(ringIndex==0xC) ringIndex=0;
            ringEntry=(u8 *)kp+ringIndex*0x36; sampleBuf=(KPADReadStatus *)(ringEntry+0x118);
            *((u8 *)kp+0x85)=ringEntry[0x141];
            read_kpad_acc(kp,sampleBuf,2,chanCopy); read_kpad_dpd(kp,sampleBuf,2); clamp_stick_cross(kp,sampleBuf);
            if(kp->repeat_count>=(s32)(available-count)) {
                out--;
                *out=kp->status;
            }
        } while(++kp->repeat_count<available);
    }
    devType=*(u32 *)&kp->status.status.dev_type;
    if(devType==0 || devType==0xFB || devType==0xFC || devType==0xFF) calc_acc_horizon(kp,coreStatus,0);
    else if(devType==1) calc_acc_horizon(kp,fsStatus,1);
    else if(devType==2) calc_acc_horizon(kp,sampleBuf,2);
    remaining=count;
    do {
        out->status.hold=kp->status.status.hold;
        out->status.trig=kp->status.status.trig;
        out->status.release=kp->status.status.release;
        out++;
        if(*(u32 *)&kp->status.status.dev_type==2) {
            out->status.ex_status.cl.hold=kp->status.status.ex_status.cl.hold;
            out->status.ex_status.cl.trig=kp->status.status.ex_status.cl.trig;
            out->status.ex_status.cl.release=kp->status.status.ex_status.cl.release;
        }
        remaining--;
    } while(remaining!=0);
    return count;
}
#pragma pop
extern void fn_8005EB44(void);
extern s32 fn_8005EE7C(void);
extern void KPADSetSensorHeight(void *, s32);
extern u8 fn_80062458(void);
extern void OSRegisterVersion(const char *);
extern f32 lbl_80558E8C;
extern u32 lbl_80558E90, lbl_80558E94, lbl_80558E98, lbl_80558E9C;
extern s32 lbl_8055D980, lbl_8055D984;
extern f32 lbl_80558EA0, lbl_80558EA8, lbl_80558EB4, lbl_80558EB8, lbl_80558EBC;
extern f32 lbl_8055D990, lbl_8055D994, lbl_8055D998, lbl_8055D99C, lbl_8055D9B0;
extern f32 lbl_80560BD8, lbl_80560BE0, lbl_80560BE4, lbl_80560BE8, lbl_80560BEC, lbl_80560C30;
extern const char *lbl_80558E88;
extern f64 lbl_80560C28;
extern u8 lbl_8037C808[];
void KPADInit(void) {
    f32 f29, f30;
    f64 bias;
    union { u32 word[2]; f64 value; } conversion;
    u8 *p;
    s32 i;
    fn_8005EB44();
    if (fn_8005EE7C() != 3) return;
    p = lbl_8037C808;
    f29 = lbl_80560BD8;
    f30 = lbl_80560BE4;
    bias = lbl_80560C28;
    for (i = 0; i < 4; i++, p += 0x400) {
        *(s32 *)(p + 0x3EC) = 1;
        *(s32 *)(p + 0x3FC) = 0;
        *(s32 *)(p + 0x3F0) = 0;
        *(s32 *)(p + 0x3F4) = 0;
        *(s32 *)(p + 0x3F8) = 0;
        *(s32 *)(p + 0x5C) = 0xFD;
        *(s16 *)(p + 0x114) = i - 4;
        read_kpad_stick(i, p);
        *(f32 *)(p + 0xA8) = lbl_80558E8C;
        *(u32 *)(p + 0xAC) = lbl_80558E90;
        *(u32 *)(p + 0xB0) = lbl_80558E94;
        *(u32 *)(p + 0xB4) = lbl_80558E98;
        *(u32 *)(p + 0xB8) = lbl_80558E9C;
        *(s32 *)(p + 0xBC) = lbl_8055D980;
        *(s32 *)(p + 0xC0) = lbl_8055D984;
        KPADSetSensorHeight(p, lbl_8055D980);
        *(f32 *)(p + 0xA0) = f29;
        *(f32 *)(p + 0x98) = f29;
        *(f32 *)(p + 0x90) = f29;
        *(f32 *)(p + 0x88) = f29;
        *(f32 *)(p + 0xA4) = f30;
        *(f32 *)(p + 0x9C) = f30;
        *(f32 *)(p + 0x94) = f30;
        *(f32 *)(p + 0x8C) = f30;
        conversion.word[1] = fn_80062458();
        conversion.word[0] = 0x43300000;
        *(s16 *)(p + 0x3E0) = -0x63C0;
        *(s16 *)(p + 0x3E2) = 0;
        *(s16 *)(p + 0x3E8) = -0x63C0;
        *(s16 *)(p + 0x3EA) = 0;
        {
            f32 delta = (f32)(conversion.value - bias);
            lbl_80558EB8 = f30 + delta;
        }
    }
    lbl_8055D99C = f30 / lbl_80558EBC;
    lbl_8055D9B0 = lbl_80558EA0 / lbl_80560BE0;
    lbl_8055D990 = lbl_80558EA0 / lbl_80560BE0;
    lbl_8055D998 = lbl_80560BEC / lbl_80558EBC;
    lbl_8055D9A8[0] = lbl_80560BEC + lbl_80558EB4;
    lbl_8055D9A0[0] = f30 - lbl_80558EB4;
    lbl_8055D9A8[1] = lbl_80560C30 + lbl_80558EB4;
    lbl_8055D9A0[1] = lbl_80560BE8 - lbl_80558EB4;
    lbl_8055D994 = lbl_80558EA8 * lbl_80558EA8;
    for (p = lbl_8037C808 + 0xC00; p >= lbl_8037C808; p -= 0x400) reset_kpad(p);
    OSRegisterVersion(lbl_80558E88);
}

