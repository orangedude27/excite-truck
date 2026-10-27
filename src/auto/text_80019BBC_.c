// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma small_data off
extern char lbl_803583C8[];
#pragma small_data on
extern void fn_802C8BD0(int);
extern void fn_802C8DB8(void *, int, unsigned short *, int);
extern void fn_802C8D74(void);
extern float PSVECDotProduct(const void *, const void *);
extern float lbl_80560444, lbl_80560448, lbl_8056044C;
extern float fn_80235EF0(void *, int);
extern void fn_80235AFC(void *, int, unsigned int, float, float, float, float, float, float);
extern void fn_802354A0(void *, int, int, float, float, float, float, float);
extern int fn_8001B478(float);
extern void *fn_80156A40(void);
extern float lbl_80560418;
extern float lbl_8056041C;
#pragma small_data off
extern char lbl_803582C0[];
#pragma small_data on
extern double cos(double);
extern double sin(double);
#pragma scheduling invalid_target
void fn_80019BBC(void) {
    float initial = lbl_80560418;
    float angle = lbl_80560418;
    float step = lbl_8056041C;
    float *p = (float *)lbl_803582C0;
    int i = 0;
    do {
        *p++ = (float)cos(angle);
        p[0] = (float)sin(angle);
        p[1] = initial;
        p += 2;
        angle += step;
        i++;
    } while (i < 20);
    ((float *)lbl_803582C0)[60] = lbl_80560418;
    ((float *)lbl_803582C0)[61] = lbl_80560418;
    ((float *)lbl_803582C0)[62] = lbl_80560418;
}
#pragma scheduling on
void fn_8001A1F0(void) {
}

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
static inline void transformBasis(f32 *dst, const f32 *src,
                                  const f32 *xaxis, const f32 *yaxis, const f32 *zaxis) {
    if (dst == src) {
        f32 x = src[0];
        f32 y = src[1];
        f32 z = src[2];
        dst[0] = x * xaxis[0] + y * yaxis[0] + z * zaxis[0];
        dst[1] = x * xaxis[1] + y * yaxis[1] + z * zaxis[1];
        dst[2] = x * xaxis[2] + y * yaxis[2] + z * zaxis[2];
    } else {
        dst[0] = src[0] * xaxis[0] + src[1] * yaxis[0] + src[2] * zaxis[0];
        dst[1] = src[0] * xaxis[1] + src[1] * yaxis[1] + src[2] * zaxis[1];
        dst[2] = src[0] * xaxis[2] + src[1] * yaxis[2] + src[2] * zaxis[2];
    }
}
extern s32 fn_801E866C(s32);
extern void *fn_801E8718(s32);
extern double fn_8002EFB0(f32, f32);
extern void *fn_801EA9A0(s32);
extern s32 fn_801EA994(void);
extern void *memset(void *, int, unsigned long);
extern void *lbl_8055D5B4;
extern s32 fn_80016474(s32);
extern f32 lbl_80560420;
extern f32 lbl_80560424;
extern f32 lbl_80560418;
extern f32 lbl_8056043C;
extern f32 lbl_80560440;
extern void *fn_80178C9C(void);
extern void fn_80136468(void *, void *, f32);
extern void *fn_8017960C(s32);
extern void *fn_802678E4(s32);
extern f32 lbl_80560418, lbl_80560420, lbl_80560424, lbl_8056043C, lbl_80560440;
extern void *fn_801E87A8(void);
extern s32 fn_80230B9C(s32);
extern void PSVECNormalize(f32 *, f32 *);
extern void PSVECCrossProduct(f32 *, f32 *, f32 *);
extern void fn_80231380(void *, s32, f32, f32, f32, f32, f32);
#pragma scheduling invalid_target
void fn_8001A1F4(void *obj, f32 x, f32 y, f32 width, f32 height) {
    struct Frame {
        u8 prefix[0x78];
        f32 vectors[4];
        u32 matrix2[12];
        u32 matrix[12];
        f32 output[3];
        f32 normal[3];
        f32 axis[3];
        u8 gap0[0x0C];
        unsigned short indices[0x5A];
        u8 gap1[0xB4];
        u8 vertices[0x1F8];
        u8 tail[0x1A8];
    } __attribute__((aligned(16))) frame;
    s32 resource;
    s32 index;
    s32 offset;
    s32 *data;
    volatile u32 *destination;
    volatile u32 *destination2;
    volatile u32 *source;
    void *global;
    void *record;
    void *part;
    f32 angle;
    f32 result;
    f32 f21;
    f32 f25;
    u32 a, b;
    u32 l, k, j, i, h, g, f, e, d, c;
    f32 ratio;
    f32 v;
    void *desc;
    void *state;
    void *actor;
    f32 actorX;
    f32 actorY;
    s32 flag;
    s32 color;
    register u32 *ring;
    f32 u, w, z, sx, sy, sz, px, py, pz;

    if (obj == 0) return;
    resource = fn_801E866C(*(s32 *)((u8 *)obj + 0x44));
    global = lbl_8055D5B4;
    source = (u32 *)fn_801E8718(*(s32 *)((u8 *)obj + 0x44));
    destination = frame.matrix;
    b = source[6]; a = source[8]; destination[6] = b;
    c = source[0]; destination[8] = a;
    d = source[1]; e = source[2]; f = source[3]; g = source[4];
    h = source[5]; i = source[7]; j = source[9]; k = source[10]; l = source[11];
    angle = *(volatile f32 *)&destination[6];
    result = *(volatile f32 *)&destination[8];
    destination[0] = c; destination[1] = d; destination[2] = e; destination[3] = f;
    destination[4] = g; destination[5] = h; destination[7] = i; destination[9] = j;
    destination[10] = k; destination[11] = l;
    result = (f32)fn_8002EFB0(angle, result);
    *(f32 *)((u8 *)global + 0x10) = result;
    record = fn_801EA9A0(resource);
    *(u32 *)((u8 *)global + 4) = *(u32 *)((u8 *)record + 0x1C);
    data = *(s32 **)((u8 *)obj + 0x10);
    memset((u8 *)data + 4, 0, 0x40);
    *(s32 *)((u8 *)data + 0x44) = fn_801EA994();
    index = 0;
    offset = 0;
    goto recordCheck;
recordLoop:
    record = fn_801EA9A0(index);
    part = (void *)fn_80016474(*(s32 *)((u8 *)record + 0xAC));
    *(u32 *)((u8 *)data + offset + 4) = *(u32 *)((u8 *)part + 0x50);
    part = *(void **)((u8 *)record + 8);
    if (part != 0) {
        angle = (f32)fn_8002EFB0(*(f32 *)((u8 *)part + 0x20), *(f32 *)((u8 *)part + 0x18));
        *(f32 *)((u8 *)data + offset + 8) = -angle;
    }
    index++;
    offset += 8;
recordCheck:
    if (index < *(s32 *)((u8 *)data + 0x44)) goto recordLoop;

    source = (u32 *)fn_801E8718(*(s32 *)((u8 *)obj + 0x44));
    destination2 = frame.matrix2;
    b = source[6]; a = source[8]; destination2[6] = b;
    c = source[0]; destination2[8] = a;
    d = source[1]; e = source[2]; f = source[3]; g = source[4];
    h = source[5]; i = source[7]; j = source[9]; k = source[10]; l = source[11];
    angle = *(volatile f32 *)&destination2[6];
    result = *(volatile f32 *)&destination2[8];
    destination2[0] = c; destination2[1] = d; destination2[2] = e; destination2[3] = f;
    destination2[4] = g; destination2[5] = h; destination2[7] = i; destination2[9] = j;
    destination2[10] = k; destination2[11] = l;
    result = (f32)fn_8002EFB0(angle, result);
    angle = -result;
    index = 0;
    offset = 0;
    goto subtractCheck;
subtractLoop:
    *(f32 *)((u8 *)data + offset + 8) -= angle;
    index++;
    offset += 8;
subtractCheck:
    if (index < *(s32 *)((u8 *)data + 0x44)) goto subtractLoop;
    *(s32 *)((u8 *)data + 0x48) = resource;
    record = fn_801EA9A0(resource);
    desc = *(void **)((u8 *)record + 8);
    f21 = *(f32 *)((u8 *)desc + 0x2C8);
    f25 = lbl_80560424 / (*(f32 *)((u8 *)obj + 0x28) * lbl_80560420);
    record = fn_801EA9A0(resource);
    part = *(void **)((u8 *)record + 8);
    ratio = ((*(f32 *)((u8 *)part + 0x4C) / lbl_8056043C) - *(f32 *)((u8 *)obj + 0x2C)) /
            (*(f32 *)((u8 *)obj + 0x30) - *(f32 *)((u8 *)obj + 0x2C));
    if (lbl_80560424 < ratio) f25 = ratio;
    else f25 = lbl_80560424;
    if (f25 > lbl_80560418) f25 = lbl_80560418;
    state = fn_80178C9C();
    fn_80136468(frame.vectors, state, f21);
    actor = fn_8017960C(resource);
    state = fn_802678E4(*(s32 *)((u8 *)obj + 0x44));
    desc = *(void **)((u8 *)state + 0x140);
    v = *(f32 *)((u8 *)state + 0x70);
    ratio = *(f32 *)((u8 *)state + 0x78);
    flag = *(u8 *)((u8 *)desc + 0x260C);
    if (flag != 0) {
        v *= lbl_80560440;
        ratio *= lbl_80560440;
    }
    actorX = *(f32 *)((u8 *)actor + 0x60);
    actorY = *(f32 *)((u8 *)actor + 0x68);
    frame.output[0] = lbl_80560424;
    frame.output[1] = lbl_80560418;
    frame.output[2] = lbl_80560418;
    frame.normal[0] = v;
    frame.normal[1] = ratio;
    frame.normal[2] = lbl_80560418;
    frame.axis[0] = actorX;
    frame.axis[1] = actorY;
    frame.axis[2] = lbl_80560418;
    PSVECNormalize(frame.normal, frame.normal);
    PSVECCrossProduct(frame.normal, frame.axis, frame.output);
    state = fn_801E87A8();
    if ((*(s32 *)((u8 *)state + 0x10) & 2) != 0) {
        frame.output[0] *= lbl_80560440;
        frame.output[1] *= lbl_80560440;
        frame.output[2] *= lbl_80560440;
        color = fn_80230B9C(-1);
    }
    ring = (u32 *)&lbl_803582C0;
    flag = 0;
    color = -1;
    offset = 0;
    for (index = 0; index < 21; index++) {
        a = *(u32 *)((u8 *)ring + offset);
        b = *(u32 *)((u8 *)ring + offset + 4);
        c = *(u32 *)((u8 *)ring + offset + 8);
        *(volatile u32 *)((u8 *)&frame + 0x6C) = a;
        *(volatile u32 *)((u8 *)&frame + 0x70) = b;
        *(volatile u32 *)((u8 *)&frame + 0x74) = c;
        u = *(volatile f32 *)((u8 *)&frame + 0x6C);
        w = *(volatile f32 *)((u8 *)&frame + 0x70);
        z = *(volatile f32 *)((u8 *)&frame + 0x74);
        sx = u * f25;
        sy = w * f25;
        sz = z * f25;
        *(f32 *)((u8 *)&frame + 0x60) = sx;
        *(f32 *)((u8 *)&frame + 0x64) = sy;
        *(f32 *)((u8 *)&frame + 0x68) = sz;
        transformBasis((f32 *)((u8 *)&frame + 0x60),
                       (f32 *)((u8 *)&frame + 0x60),
                       frame.output, frame.normal, frame.axis);
        px = *(f32 *)((u8 *)&frame + 0x60);
        py = *(f32 *)((u8 *)&frame + 0x64);
        pz = *(f32 *)((u8 *)&frame + 0x68);
        fn_80231380((u8 *)&frame + 0x280 + flag, color,
                    x + px + *(f32 *)((u8 *)&frame + 0x10C),
                    y + py + *(f32 *)((u8 *)&frame + 0x110),
                    pz + *(f32 *)((u8 *)&frame + 0x114),
                    lbl_80560420 + lbl_80560420 *
                        (px + *(f32 *)((u8 *)&frame + 0x10C)) +
                        *(f32 *)((u8 *)record + 0x20) / *(f32 *)((u8 *)record + 0x1C),
                    lbl_80560424 - (lbl_80560420 + lbl_80560420 *
                        (py + *(f32 *)((u8 *)&frame + 0x110))) +
                        *(f32 *)((u8 *)record + 0x24) / *(f32 *)((u8 *)record + 0x1C));
        if (index < 20) {
            sx = u * f21;
            sy = w * f21;
            sz = z * f21;
            *(f32 *)((u8 *)&frame + 0x60) = sx;
            *(f32 *)((u8 *)&frame + 0x64) = sy;
            *(f32 *)((u8 *)&frame + 0x68) = sz;
            transformBasis((f32 *)((u8 *)&frame + 0x60),
                           (f32 *)((u8 *)&frame + 0x60),
                           frame.output, frame.normal, frame.axis);
            px = *(f32 *)((u8 *)&frame + 0x60);
            py = *(f32 *)((u8 *)&frame + 0x64);
            pz = *(f32 *)((u8 *)&frame + 0x68);
            fn_80231380((u8 *)&frame + 0x280 + (index + 21) * 0x18, color & 0x00FFFFFF,
                        x + px + *(f32 *)((u8 *)&frame + 0x10C),
                        y + py + *(f32 *)((u8 *)&frame + 0x110),
                        pz + *(f32 *)((u8 *)&frame + 0x114),
                        lbl_80560420 + lbl_80560420 *
                            (px + *(f32 *)((u8 *)&frame + 0x10C)) +
                            *(f32 *)((u8 *)record + 0x20) / *(f32 *)((u8 *)record + 0x1C),
                        lbl_80560424 - (lbl_80560420 + lbl_80560420 *
                            (py + *(f32 *)((u8 *)&frame + 0x110))) +
                            *(f32 *)((u8 *)record + 0x24) / *(f32 *)((u8 *)record + 0x1C));
        }
        offset += 12;
        flag += 0x18;
    }
    index = 0; offset = 0;
    do {
        flag = (index + 1) % 20;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = 20; offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)index; offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)flag; offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)index; offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)flag; offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)(index + 21); offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)flag; offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)(index + 21); offset += 2;
        *(unsigned short *)((u8 *)&frame + 0x118 + offset) = (unsigned short)(flag + 21); offset += 2;
    } while (++index < 20);
    if (*(s32 *)((u8 *)obj + 4) != -2)
        fn_802C8BD0(*(s32 *)((u8 *)obj + 4));
    else
        fn_802C8BD0(*(s32 *)obj);
    fn_802C8DB8((u8 *)&frame + 0x280, 0x29, (unsigned short *)((u8 *)&frame + 0x118), 0xB4);
    fn_802C8D74();
    record = fn_801EA9A0(resource);
    index = 0;
    do {
        if (index == fn_801E866C(*(s32 *)((u8 *)obj + 0x44))) break;
        record = fn_801EA9A0(index);
        actor = fn_8017960C(index);
        px = *(f32 *)((u8 *)actor + 0x60) - *(f32 *)((u8 *)global + 8);
        py = *(f32 *)((u8 *)actor + 0x64) - *(f32 *)((u8 *)global + 0xC);
        pz = *(f32 *)((u8 *)actor + 0x68) - *(f32 *)((u8 *)global + 0x10);
        *(f32 *)((u8 *)&frame + 0x54) = px;
        *(f32 *)((u8 *)&frame + 0x58) = py;
        *(f32 *)((u8 *)&frame + 0x5C) = pz;
        transformBasis((f32 *)((u8 *)&frame + 0x54),
                       (f32 *)((u8 *)&frame + 0x54),
                       frame.output, frame.normal, frame.axis);
        ratio = width * lbl_80560420 / f21;
        *(f32 *)((u8 *)&frame + 0x54) *= ratio;
        *(f32 *)((u8 *)&frame + 0x58) *= ratio;
        *(f32 *)((u8 *)&frame + 0x5C) *= ratio;
        result = PSVECDotProduct((u8 *)&frame + 0x54, (u8 *)&frame + 0x54);
        if (result < (width * lbl_80560420) * (width * lbl_80560420)) {
            color = index == *(s32 *)((u8 *)data + 0x48) ? 1 : 3;
            angle = (f32)fn_80235EF0(*(void **)data, color);
            ratio = 1.0f - result / ((width * lbl_80560420) * (width * lbl_80560420));
            if (ratio >= lbl_80560440) {
                if (ratio > lbl_80560424) ratio = lbl_80560424;
                if (ratio > lbl_80560418)
                    v = lbl_80560444 * ratio * ratio * ratio + lbl_80560448 * ratio * ratio;
                else
                    v = lbl_80560444 * ratio * ratio * ratio - lbl_80560448 * ratio * ratio;
            }
            v *= lbl_8056044C;
            if (v < lbl_80560418) v -= lbl_80560420;
            else v += lbl_80560420;
            fn_80235AFC(*(void **)data, color, 0xFFFFFFFF,
                        x + *(f32 *)((u8 *)&frame + 0x54), y + *(f32 *)((u8 *)&frame + 0x58), 0.0f,
                        v * width * lbl_80560420, angle,
                        *(f32 *)((u8 *)record + 8));
        }
        index++;
    } while (index < fn_801EA994());
    index = 0;
    offset = 0;
    while (index < 16) {
        record = (void *)((u8 *)lbl_803583C8 + offset);
        if (*(u8 *)((u8 *)record + 0x10) != 0) {
            px = *(f32 *)((u8 *)record + 8) - *(f32 *)((u8 *)&frame + 0x10C);
            py = *(f32 *)((u8 *)record + 0xC) - *(f32 *)((u8 *)&frame + 0x110);
            pz = lbl_80560418 - *(f32 *)((u8 *)&frame + 0x114);
            *(f32 *)((u8 *)&frame + 0x3C) = px;
            *(f32 *)((u8 *)&frame + 0x40) = py;
            *(f32 *)((u8 *)&frame + 0x44) = pz;
            transformBasis((f32 *)((u8 *)&frame + 0x3C),
                           (f32 *)((u8 *)&frame + 0x3C),
                           frame.output, frame.normal, frame.axis);
            ratio = width * lbl_80560420;
            result = PSVECDotProduct((u8 *)&frame + 0x3C, (u8 *)&frame + 0x3C);
            if (result > ratio * ratio) {
                PSVECNormalize((f32 *)((u8 *)&frame + 0x3C), (f32 *)((u8 *)&frame + 0x3C));
                *(f32 *)((u8 *)&frame + 0x3C) *= ratio;
                *(f32 *)((u8 *)&frame + 0x40) *= ratio;
                *(f32 *)((u8 *)&frame + 0x44) *= ratio;
                angle = (f32)fn_80235EF0(record, 0);
                result = angle * lbl_80560420;
                fn_802354A0(record, *(s32 *)((u8 *)record + 4), -1,
                            x + width * lbl_80560420 + *(f32 *)((u8 *)&frame + 0x3C) - result,
                            result + y - height * lbl_80560420 + *(f32 *)((u8 *)&frame + 0x40),
                            lbl_80560418, angle, angle);
            }
        }
        index++;
        offset += 0x14;
    }
    data = *(s32 **)((u8 *)obj + 0x10);
    color = resource == *(s32 *)((u8 *)data + 0x48) ? 1 : 3;
    angle = (f32)fn_80235EF0(*(void **)data, color);
    result = angle * lbl_80560424;
    fn_80235AFC(*(void **)data, color, 0xFFFFFFFF,
                x + width * lbl_80560420, y - height * lbl_80560420,
                lbl_80560418, result, result,
                *(f32 *)((u8 *)data + resource * 8 + 8));
    actor = fn_8017960C(fn_801E866C(*(s32 *)((u8 *)obj + 0x44)));
    px = *(f32 *)((u8 *)global + 8) - *(f32 *)((u8 *)&frame + 0x10C);
    py = *(f32 *)((u8 *)global + 0xC) - *(f32 *)((u8 *)&frame + 0x110);
    pz = lbl_80560418 - *(f32 *)((u8 *)&frame + 0x114);
    *(f32 *)((u8 *)&frame + 0x30) = px;
    *(f32 *)((u8 *)&frame + 0x34) = py;
    *(f32 *)((u8 *)&frame + 0x38) = pz;
    transformBasis((f32 *)((u8 *)&frame + 0x30),
                   (f32 *)((u8 *)&frame + 0x30),
                   frame.output, frame.normal, frame.axis);
    ratio = width * lbl_80560420 / f21;
    *(f32 *)((u8 *)&frame + 0x30) *= ratio;
    *(f32 *)((u8 *)&frame + 0x34) *= ratio;
    *(f32 *)((u8 *)&frame + 0x38) *= ratio;
    result = PSVECDotProduct((u8 *)&frame + 0x30, (u8 *)&frame + 0x30);
    if (result < (width * lbl_80560420) * (width * lbl_80560420)) {
        angle = (f32)fn_80235EF0(*(void **)data, 0);
        ratio = 1.0f - PSVECDotProduct((u8 *)&frame + 0x30, (u8 *)&frame + 0x30) /
                ((width * lbl_80560420) * (width * lbl_80560420));
        if (ratio >= lbl_80560440) {
            if (ratio > lbl_80560424) ratio = lbl_80560424;
            if (ratio > lbl_80560418)
                v = lbl_80560444 * ratio * ratio * ratio + lbl_80560448 * ratio * ratio;
            else
                v = lbl_80560444 * ratio * ratio * ratio - lbl_80560448 * ratio * ratio;
        }
        v *= lbl_8056044C;
        if (v < lbl_80560418) v -= lbl_80560420;
        else v += lbl_80560420;
        color = ((s32)v << 24) | 0x00FFFFFF;
        fn_80235AFC(*(void **)data, 0, (u32)color,
                    x + *(f32 *)((u8 *)&frame + 0x30), y + *(f32 *)((u8 *)&frame + 0x34), lbl_80560418,
                    angle, angle, *(f32 *)((u8 *)actor + 0x68));
    }
}
#pragma scheduling on
struct EntryData {
    int first;
    int second;
    float x;
    float y;
    unsigned char occupied;
};
int fn_8001B308(void *arg0, int arg1, int arg2) {
    int group;
    int one;
    int status;
    unsigned char *base;
    int index;

    one = 1;
    status = 0;
    base = (unsigned char *)&lbl_803583C8;
    index = 0;
    for (group = 0; group < 4; group++) {
        if (base[0x10] == 0) {
            *(int *)(base + 0) = arg1;
            status = one;
            {
                float first = *(float *)arg0;
                *(int *)(base + 4) = arg2;
                {
                    float second = *((float *)arg0 + 1);
                    *(float *)(base + 8) = first;
                    *(float *)(base + 0xC) = second;
                }
            }
            base[0x10] = (unsigned char)one;
        } else {
            status = 0;
        }
        if (status != 0) return index;
        index++;

        if (base[0x24] == 0) {
            *(int *)(base + 0x14) = arg1;
            status = one;
            {
                float first = *(float *)arg0;
                *(int *)(base + 0x18) = arg2;
                {
                    float second = *((float *)arg0 + 1);
                    *(float *)(base + 0x1C) = first;
                    *(float *)(base + 0x20) = second;
                }
            }
            base[0x24] = (unsigned char)one;
        } else {
            status = 0;
        }
        if (status != 0) return index;
        index++;

        if (base[0x38] == 0) {
            *(int *)(base + 0x28) = arg1;
            status = one;
            {
                float first = *(float *)arg0;
                *(int *)(base + 0x2C) = arg2;
                {
                    float second = *((float *)arg0 + 1);
                    *(float *)(base + 0x30) = first;
                    *(float *)(base + 0x34) = second;
                }
            }
            base[0x38] = (unsigned char)one;
        } else {
            status = 0;
        }
        if (status != 0) return index;
        index++;

        if (base[0x4C] == 0) {
            *(int *)(base + 0x3C) = arg1;
            status = one;
            {
                float first = *(float *)arg0;
                *(int *)(base + 0x40) = arg2;
                {
                    float second = *((float *)arg0 + 1);
                    *(float *)(base + 0x44) = first;
                    *(float *)(base + 0x48) = second;
                }
            }
            base[0x4C] = (unsigned char)one;
        } else {
            status = 0;
        }
        if (status != 0) return index;
        index++;
        base += 0x50;
    }
    return -1;
}

extern void fn_801352B8(void *);
extern int fn_80135D60(void *, int);
extern void fn_8013530C(void *, int);
extern void fn_802C8DBC(int);
extern void fn_802C8E00(int, int, float, float, float, float, float, float, float, float);
extern void fn_802C8E48(void);
extern float fn_8002F234(float, float, float, float, float);
extern float lbl_80560418, lbl_80560420, lbl_80560424, lbl_80560440;
int fn_8001B478(float farg0) {
    unsigned char sp20[0x30];
    int i, count, result;
    float step, ratio, angle, x, y, z, w, nx, ny, norm, inv, dx, dy, t;
    float a[4];
    void *node;
    void *head;
    fn_801352B8(sp20);
    if (fn_80135D60(sp20, 0) == 0) {
        fn_8013530C(sp20, -1);
        return 0;
    }
    step = *(float *)(sp20 + 0x2c);
    ratio = step / farg0;
    count = (int)ratio;
    if (ratio - count > lbl_80560420) count++;
    head = *(void **)(sp20 + 0x1c);
    node = *(void **)((char *)head + 0x14);
    i = 1;
    while (node != head) {
        node = *(void **)((char *)node + 0x14);
        i++;
    }
    if ((i & 3) != 0) i += 4 - (i & 3);
    fn_802C8DBC((i / 4) * 2 + 2);
    angle = lbl_80560440;
    t = lbl_80560418;
    result = 0;
    x = lbl_80560424;
    y = lbl_80560420;
    count++;
    node = head;
    for (i = 0; i < count; i++, node = *(void **)((char *)node + 0x14)) {
        if ((i & 3) == 0) {
            void *next = *(void **)((char *)node + 0x14);
            float x0 = *(float *)((char *)node + 8);
            float y0 = *(float *)((char *)node + 0xc);
            float z0 = *(float *)node;
            float w0 = *(float *)((char *)node + 4);
            float x1 = x0 + t * (*(float *)((char *)next + 8) - x0);
            float y1 = y0 + t * (*(float *)((char *)next + 0xc) - y0);
            float z1 = z0 + t * (*(float *)next - z0);
            float w1 = w0 + t * (*(float *)((char *)next + 4) - w0);
            a[0] = x1; a[1] = y1; a[2] = z1; a[3] = w1;
            norm = fn_8002F234(x1*x1 + y1*y1, 0, 0, 0, 0);
            inv = x / norm;
            dx = -(x1 * inv);
            dy = y1 * inv;
            a[0] = dx; a[1] = dy;
            if (*(float *)((char *)node + 0x1c) < angle)
                ratio = (float)count * (*(float *)((char *)node + 0x1c) + step);
            else ratio = *(float *)((char *)node + 0x1c) * (float)count;
            angle = *(float *)((char *)node + 0x1c);
            nx = -farg0 * y;
            x0 = z1 + dx * nx;
            y0 = w1 + dy * nx;
            fn_802C8E00(-1, result, x0, lbl_80560418, y0, lbl_80560418, ratio, z1, dx*nx, nx);
            nx = farg0 * y;
            fn_802C8E00(-1, result, z1 + dx * nx, lbl_80560418, w1 + dy * nx,
                        lbl_80560424, ratio, z1, dx*nx, nx);
            result = 1;
        }
    }
    fn_802C8E48();
    fn_8013530C(sp20, -1);
    return result;
}

#pragma push
#pragma cplusplus on
extern "C" int fn_8001B754(float arg0) {
    class Callback {
    public:
        virtual void f0();
        virtual int invoke(int);
    };
    int i = 0;
    int result;

    for (;;) {
        fn_8001B478(arg0);
        i++;
        result = ((Callback *)fn_80156A40())->invoke(i);
        if (result == 0)
            break;
    }
    return result;
}
#pragma cplusplus reset
#pragma pop

void fn_8001B7B8(void) {
    fn_802D3050();
}

extern void fn_802CB274(int);
extern void fn_802C9294(int, int);
extern double fn_8002EF30(float);
extern void fn_802C9694(float *, float, float, float, float);
extern void fn_802C86F0(int *, int, int, int, int);
extern void fn_802C88CC(int);
extern int fn_802C2C00(int);
extern void fn_802C8638(float *, float, float);
extern void fn_802C8BD0(int);
extern int fn_8001B754(float);
extern void fn_802C8D74(void);
extern void fn_802C8750(int *, int);
extern void fn_802C96DC(float *, int);
extern float lbl_80560418, lbl_80560420, lbl_80560424, lbl_80560440, lbl_80560458;
void fn_8001B7BC(void *arg0) {
    float sp78[4];
    int sp58[2];
    float sp28[12];
    float temp_f31;
    float temp_f4;
    int temp_r31;
    fn_802CB274(*(int *)((char *)arg0 + 4));
    fn_802C9294(*(int *)((char *)arg0 + 4), 0);
    temp_f31 = lbl_80560458;
    temp_f4 = (float)fn_8002EF30(temp_f31 * lbl_80560420);
    temp_f31 = (lbl_80560420 * *(float *)((char *)arg0 + 0x28)) / temp_f4;
    fn_802C9694(sp78, temp_f31 - lbl_80560424, lbl_80560424 + temp_f31, lbl_80560458, temp_f4);
    temp_f4 = *(float *)((char *)arg0 + 0x1C);
    fn_802C86F0(sp58, 0, 0, (int)temp_f4, (int)temp_f4);
    fn_802C88CC(0xFFFFFF);
    temp_r31 = fn_802C2C00(0);
    sp28[9] = lbl_80560418; sp28[10] = temp_f31; sp28[11] = lbl_80560418;
    sp28[0] = lbl_80560424; sp28[1] = lbl_80560418; sp28[2] = lbl_80560418;
    sp28[3] = lbl_80560418; sp28[4] = lbl_80560418; sp28[5] = lbl_80560424;
    sp28[6] = lbl_80560418; sp28[7] = lbl_80560440; sp28[8] = lbl_80560418;
    fn_802C8638(sp28, lbl_80560424, lbl_80560418);
    fn_802C8BD0(*(int *)((char *)arg0 + 0xC));
    fn_8001B754(*(float *)((char *)arg0 + 0x3C)); fn_802C8D74();
    ((void (*)(int))fn_8001B7B8)(0);
    fn_802C8BD0(*(int *)((char *)arg0 + 8));
    fn_8001B754(*(float *)((char *)arg0 + 0x3C)); fn_802C8D74();
    ((void (*)(int))fn_8001B7B8)(1);
    fn_802C2C00(temp_r31); fn_802C9294(-2, 0);
    fn_802C8750(sp58, -1); fn_802C96DC(sp78, -1);
}

#pragma small_data on
extern float lbl_80560418;
extern float lbl_8056041C;
extern int fn_8001B478(float);
extern void *fn_80156A40(void);
extern double cos(double);
extern double sin(double);
