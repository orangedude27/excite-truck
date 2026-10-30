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

void read_kpad_stick(s32 chan, void *arg1) {
    u32 probe;
    s32 ret;
    s32 irq;
    u8 *obj = (u8 *)arg1;
    u8 *state;
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
        if (*(s16 *)(obj + 0x114) < 0) return;
        WPADSetAutoSamplingBuf(chan, 0, 0);
        *(s16 *)(obj + 0x114) = chan - 4;
        *(u32 *)(obj + 0x5C) = 0xFD;
        state = lbl_8037C808 + (chan << 10);
        irq = OSDisableInterrupts();
        if (*(u32 *)(state + 0x3F0) != 0) {
            *(u32 *)(state + 0x3F0) = 0;
            if (*(u32 *)(state + 0x3F8) != 0) ((void (*)(s32, s32))(*(u32 *)(state + 0x3F8)))(chan, 1);
        }
        OSRestoreInterrupts(irq);
        return;
    }
    if (ret != 0) return;
    if (probe == *(u32 *)(obj + 0x5C)) {
        if (*(u32 *)(obj + 0x3F4) != 0) { reset_kpad(obj); return; }
        ret = fn_80062460(chan);
        if (*(u32 *)(obj + 0x3EC) != 0 && ret == 0) { KPADiControlDpdCallback(chan, probe); reset_kpad(obj); return; }
        if (*(u32 *)(obj + 0x3EC) == 0 && ret != 0) { KPADiSamplingCallback(chan, probe); reset_kpad(obj); return; }
        if (*(u32 *)(obj + 0x3FC) != 0) {
            if (*(u32 *)(obj + 0x3EC) != 0) KPADiControlDpdCallback(chan, probe);
            else KPADiSamplingCallback(chan, probe);
            reset_kpad(obj); return;
        }
        return;
    }
    if (probe != 0xFD) {
        if (*(u32 *)(obj + 0x3EC) != 0) KPADiControlDpdCallback(chan, probe);
        else KPADiSamplingCallback(chan, probe);
        *(s16 *)(obj + 0x114) = chan;
        *(u32 *)(obj + 0x5C) = probe;
        reset_kpad(obj); return;
    }
    *(s16 *)(obj + 0x114) = chan - 4;
}

#pragma scheduling invalid_target
s32 KPADRead(s32 arg0, KPADStatus *arg1, s32 arg2) {
    extern f32 lbl_80558EB8;
    extern f32 lbl_80560BE4;
    extern f64 lbl_80560C28;
    extern u8 fn_80062458(void);
    extern void read_kpad_acc(void *, void *, s32, s32);
    extern void read_kpad_dpd(void *, void *, s32);
    extern void calc_acc_horizon(void *, void *, s32);
    extern s32 fn_800609E0(s32);
    union { u32 word[2]; f64 value; } conversion;
    register s32 var_r21;
    register s32 var_r22=arg0;
    register KPADReadPrivate *temp_r29=(KPADReadPrivate *)(lbl_8037C808+(arg0<<10));
    register u8 *var_r28;
    register u8 *var_r27;
    register KPADReadStatus *var_r26=(KPADReadStatus *)arg1;
    register s32 var_r25;
    register s32 var_r24;
    register u32 var_r23=arg2;
    register s32 var_r31;
    register KPADReadStatus *var_r30;
    s32 normalized;
    u32 devType;
    u8 *temp_r4;

    conversion.word[1]=fn_80062458(); conversion.word[0]=0x43300000;
    {
        f32 delta=(f32)conversion.value-(f32)lbl_80560C28;
        lbl_80558EB8=lbl_80560BE4+delta;
    }
    var_r30=var_r26+(var_r23-1);
init_samples:
    *(u32 *)&var_r30->status.dev_type=*(u32 *)&temp_r29->status.status.dev_type;
    var_r30--;
    if(var_r30>=var_r26) goto init_samples;
    if (((s32 (*)(s32,void *))read_kpad_stick)(var_r22,temp_r29)!=0) return 0;
    if(*(u32 *)&temp_r29->status.status.dev_type==0xFD) return 0;
    if(temp_r29->active_chan>=0) normalized=fn_800609E0(temp_r29->active_chan);
    else normalized=fn_800609E0(temp_r29->active_chan+4);
    var_r25=temp_r29->last_index;
    if(var_r25<0) { var_r25=normalized-1; if(var_r25<0) var_r25=0xB; }
    var_r24=normalized-var_r25;
    temp_r29->last_index=normalized;
    if(var_r24==0) return 0;
    if(var_r24<0) var_r24+=0xC;
    if(var_r24<var_r23) var_r23=var_r24;
    temp_r29->repeat_count=0;
    devType=*(u32 *)&temp_r29->status.status.dev_type;
    var_r30=var_r26+var_r23;
    if(devType==0 || devType==0xFB || devType==0xFF || devType==0xFC) {
        var_r31=var_r24-var_r23;
        do {
            var_r25++; if(var_r25==0xC) var_r25=0;
            temp_r4=(u8 *)temp_r29+var_r25*0x2A; var_r28=temp_r4+0x118;
            *((u8 *)temp_r29+0x85)=temp_r4[0x141];
            read_kpad_acc(temp_r29,var_r28,0,var_r22); read_kpad_dpd(temp_r29,var_r28,0);
            if(temp_r29->repeat_count>=var_r31) {
                var_r30--;
                *var_r30=temp_r29->status;
            }
        } while(++temp_r29->repeat_count<var_r24);
    } else if(devType==1) {
        var_r31=var_r24-var_r23;
        do {
            var_r25++; if(var_r25==0xC) var_r25=0;
            temp_r4=(u8 *)temp_r29+var_r25*0x32; var_r27=temp_r4+0x118;
            *((u8 *)temp_r29+0x85)=temp_r4[0x141];
            read_kpad_acc(temp_r29,var_r27,1,var_r22); read_kpad_dpd(temp_r29,var_r27,1); clamp_stick_cross(temp_r29,var_r27);
            if(temp_r29->repeat_count>=var_r31) {
                var_r30--;
                *var_r30=temp_r29->status;
            }
        } while(++temp_r29->repeat_count<var_r24);
    } else if(devType==2) {
        var_r31=var_r24-var_r23;
        do {
            var_r25++; if(var_r25==0xC) var_r25=0;
            temp_r4=(u8 *)temp_r29+var_r25*0x36; var_r26=(KPADReadStatus *)(temp_r4+0x118);
            *((u8 *)temp_r29+0x85)=temp_r4[0x141];
            read_kpad_acc(temp_r29,var_r26,2,var_r22); read_kpad_dpd(temp_r29,var_r26,2); clamp_stick_cross(temp_r29,var_r26);
            if(temp_r29->repeat_count>=var_r31) {
                var_r30--;
                *var_r30=temp_r29->status;
            }
        } while(++temp_r29->repeat_count<var_r24);
    }
    devType=*(u32 *)&temp_r29->status.status.dev_type;
    if(devType==0 || devType==0xFB || devType==0xFC || devType==0xFF) calc_acc_horizon(temp_r29,var_r28,0);
    else if(devType==1) calc_acc_horizon(temp_r29,var_r27,1);
    else if(devType==2) calc_acc_horizon(temp_r29,var_r26,2);
    var_r31=var_r23;
    do {
        var_r30->status.hold=temp_r29->status.status.hold;
        var_r30->status.trig=temp_r29->status.status.trig;
        var_r30->status.release=temp_r29->status.status.release;
        var_r30++;
        if(*(u32 *)&temp_r29->status.status.dev_type==2) {
            var_r30->status.ex_status.cl.hold=temp_r29->status.status.ex_status.cl.hold;
            var_r30->status.ex_status.cl.trig=temp_r29->status.status.ex_status.cl.trig;
            var_r30->status.ex_status.cl.release=temp_r29->status.status.ex_status.cl.release;
        }
        var_r31--;
    } while(var_r31!=0);
    return var_r23;
}
#pragma scheduling on
#pragma push
#pragma scheduling invalid_target
extern void fn_8005EB44(void);
extern s32 fn_8005EE7C(void);
extern void read_kpad_stick(s32, void *);
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
#pragma pop

