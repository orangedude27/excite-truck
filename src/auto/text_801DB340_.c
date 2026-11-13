#include "math.h"

extern void fn_802E30C8(const char *, ...);
extern void fn_801D02B0(void);
extern void fn_801DCD28(int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B70;
extern float lbl_80562BB8;
extern int lbl_80446F08[];
extern int lbl_8055E990;
extern void (*lbl_8055E994)(int);
extern char lbl_8055E9A4;
extern int lbl_8055E998;
extern char lbl_80339468[];
extern unsigned char lbl_80446F18[];
extern int fn_801DC258(void *, void *, void *, void *, float, float);
extern int fn_80128670(void);
extern int fn_801D049C(void);
extern int lbl_8055E99C;
extern int lbl_8055E9A0;
extern unsigned short lbl_80442708[];
extern float lbl_804424B0[];
extern int fn_801DB348();
extern float fn_801DB398(float grid[4][4], float, float);
extern void *memset(void *, int, unsigned int);
extern char lbl_803393B8[];
extern char lbl_803393E0[];
extern void fn_802E317C(const char *, ...);

/* The ground descriptor block lbl_8055E990 points at (0x34 bytes).  It comes
 * from the "track.gnd" resource, byte-swapped and rebased by fn_801DC32C, or
 * is built procedurally by fn_801DCA60 (which leaves the tile tables empty,
 * so only the flat heightmap at lbl_80446F08 is used). */
typedef struct GroundDesc {
    /* 0x00 */ float offsetX;   /* world X added before scaling to grid cells */
    /* 0x04 */ float offsetZ;   /* world Z added before scaling to grid cells */
    /* 0x08 */ float scaleX;    /* grid cells per world unit, X */
    /* 0x0C */ float scaleZ;    /* grid cells per world unit, Z */
    /* 0x10 */ int tiled;       /* 0: flat heightmap only, see fn_801DB348 */
    /* 0x14 */ int nodeCount;   /* height tiles at nodes, 0x894 bytes each */
    /* 0x18 */ void *nodes;
    /* 0x1C */ int layerCount;  /* overlay layers at layers, 0x810 bytes each */
    /* 0x20 */ void *layers;
    /* 0x24 */ int recordCount; /* 16-byte records at records */
    /* 0x28 */ void *records;
    /* 0x30 */ unsigned char *typeRuns; /* per tile: (type, X length) runs */
} GroundDesc;

static inline void swap32(unsigned char *p) {
    unsigned char t;
    t = p[0]; p[0] = p[3]; p[3] = t;
    t = p[1]; p[1] = p[2]; p[2] = t;
}

static inline void swap16(unsigned char *p) {
    unsigned char t = p[0];
    p[0] = p[1];
    p[1] = t;
}
extern float fn_801DB514(float grid[4][4], void *, float, float);

static inline int sample_tile(int x, int y, float *out_h, int *out_type, void *arg4) {
    int divX, divY, tileX, tileZ, remX, remZ;
    char *node;
    char *layer;
    unsigned char *type_p;
    unsigned short tile;
    int next, sum;
    float h;

    if (x < 0 || y < 0) {
        return 0;
    }
    if (*(int *)((char *)lbl_8055E990 + 0x10) == 0) {
        return fn_801DB348(x, y, out_h, out_type, arg4);
    }
    divX = x / 32;
    divY = y / 32;
    tileX = divX - lbl_8055E99C;
    tileZ = divY - lbl_8055E9A0;
    remX = x - divX * 32;
    remZ = y - divY * 32;
    if (tileX < 0 || tileZ < 0) {
        node = 0;
    } else if (tileX >= 0x60 || tileZ >= 0x60) {
        node = 0;
    } else {
        tile = ((unsigned short (*)[0x60])lbl_80442708)[tileX][tileZ];
        if (tile == 0xFFFF) {
            node = 0;
        } else {
            node = *(char **)((char *)lbl_8055E990 + 0x18) + tile * 0x894;
        }
    }
    if (node == 0) {
        return 0;
    }
    h = *(float *)(node + 0) + *(float *)(node + 4) * (float)*(unsigned short *)(node + (remX * 64 + remZ * 2) + 8);
    next = *(int *)(node + 0x890);
    if (next >= 0) {
        do {
            layer = *(char **)((char *)lbl_8055E990 + 0x20) + next * 0x810;
            h += lbl_804424B0[*(int *)(layer + 0x808)] * (*(float *)(layer + 0) + *(float *)(layer + 4) * (float)*(unsigned short *)(layer + (remX * 64 + remZ * 2) + 8));
            next = *(int *)(layer + 0x80C);
        } while (next >= 0);
    }
    type_p = *(unsigned char **)((char *)lbl_8055E990 + 0x30) + *(int *)(node + 0x810 + remZ * 4);
    sum = 0;
    while (sum + type_p[1] <= remX) {
        sum += type_p[1];
        type_p += 2;
    }
    if (type_p[0] != 0xFF) {
        *out_h = h;
        if (out_type != 0) {
            *out_type = type_p[0];
        }
        return 1;
    }
    return 0;
}

void fn_801DB340(int arg0) { fn_801DB13C(arg0 - 4); }

#pragma auto_inline off
#pragma dont_inline on
int fn_801DB348(int arg0, int arg1, float *arg2, int *arg3) {
    int width, height;
    float *data;
    if (arg3 != 0) {
        *arg3 = 0;
    }
    width = lbl_80446F08[0];
    height = lbl_80446F08[1];
    data = (float *)lbl_80446F08[2];
    arg0 &= width - 1;
    arg1 = (arg1 & (height - 1)) * width;
    *arg2 = data[arg0 + arg1];
    return 1;
}
#pragma dont_inline reset
#pragma auto_inline reset

extern float lbl_80562B64;
extern float lbl_80562B68;
extern float lbl_80562B6C;
#pragma push
#pragma processor 750
#pragma opt_common_subs off
#pragma scheduling invalid_target
float fn_801DB398(float grid[4][4], float t, float u) {
    float values[4];
    float *src = (float *)grid;
    int qq;
    for (qq = 0; qq < 4; qq++) {
        float p2 = src[8];
        float p0 = src[0];
        float p1 = src[4];
        float dp20 = p2 - p0;
        float p3 = src[12];
        float dp21 = p2 - p1;
        float dp31 = p3 - p1;
        float half20 = lbl_80562B64 * dp20;
        float twice20 = lbl_80562B68 * half20;
        float half31 = lbl_80562B64 * dp31;
        float c3t = lbl_80562B6C * dp21;
        float sum = half20 + half31;
        float twice21 = lbl_80562B68 * dp21;
        float coeff3 = c3t - twice20;
        float coeff2 = sum - twice21;
        float t2 = t * t;
        float t3 = t2 * t;
        coeff3 = coeff3 - half31;
        values[qq] = (coeff2 * t3 + coeff3 * t2) + half20 * t + p1;
        src++;
    }
    {
        float p2 = values[2];
        float u2 = u * u;
        float p0 = values[0];
        float p1 = values[1];
        float dp20 = p2 - p0;
        float half20 = lbl_80562B64 * dp20;
        float dp21 = p2 - p1;
        float p3 = values[3];
        float u3 = u2 * u;
        float dp31 = p3 - p1;
        float twice20 = lbl_80562B68 * half20;
        float half31 = lbl_80562B64 * dp31;
        float c3t = lbl_80562B6C * dp21;
        float sum = half20 + half31;
        float twice21 = lbl_80562B68 * dp21;
        float coeff3 = c3t - twice20;
        float coeff2 = sum - twice21;
        coeff3 = coeff3 - half31;
        return (coeff2 * u3 + coeff3 * u2) + half20 * u + p1;
    }
}
#pragma pop

static inline float eval_spline(const float *p, int stride, float t, float *out_deriv) {
    float p2 = p[stride * 2];
    float p0 = p[0];
    float p1 = p[stride];
    float dp20 = p2 - p0;
    float p3 = p[stride * 3];
    float dp21 = p2 - p1;
    float dp31 = p3 - p1;
    float half20 = lbl_80562B64 * dp20;
    float twice20 = lbl_80562B68 * half20;
    float c3_term = lbl_80562B6C * dp21;
    float half31 = lbl_80562B64 * dp31;
    float twice21 = lbl_80562B68 * dp21;
    float sum = half20 + half31;
    float coeff3 = c3_term - twice20;
    float coeff2 = sum - twice21;
    float t2 = t * t;
    float t3 = t2 * t;
    coeff3 = coeff3 - half31;
    if (out_deriv != 0) {
        *out_deriv = (lbl_80562B6C * coeff2 * t2 + lbl_80562B68 * coeff3 * t) + half20;
    }
    return (coeff2 * t3 + coeff3 * t2) + half20 * t + p1;
}

#pragma push
#pragma processor 750
#pragma opt_common_subs off
#pragma scheduling invalid_target
float fn_801DB514(float grid[4][4], void *out, float t, float u) {
    float b[4];
    float a[4];
    float normal[3];
    float deriv_u;
    float *pa = a;
    float *pb = b;
    int i;
    float height;
    for (i = 0; i < 4; i++) {
        *pb++ = eval_spline(&grid[0][i], 4, t, pa);
        pa++;
    }
    height = eval_spline(b, 1, u, &deriv_u);
    normal[1] = lbl_80562B70 / *(float *)((char *)lbl_8055E990 + 8);
    normal[2] = -deriv_u;
    normal[0] = -eval_spline(a, 1, u, 0);
    PSVECNormalize(normal, normal);
    ((float *)out)[0] = normal[0];
    ((float *)out)[1] = normal[1];
    ((float *)out)[2] = normal[2];
    return height;
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
int fn_801DB74C(int arg0, int arg1, float *arg2, int *arg3, void *arg4, void *arg5, float farg0, float farg1) {
    int i, j;
    float sp8;
    float grid[4][4];

    if (!sample_tile(arg0, arg1, &sp8, arg3, arg4) &&
        !sample_tile(arg0 + 1, arg1, &sp8, arg3, arg4) &&
        !sample_tile(arg0, arg1 + 1, &sp8, arg3, arg4) &&
        !sample_tile(arg0 + 1, arg1 + 1, &sp8, arg3, arg4)) {
        return 0;
    }

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            if (!sample_tile(arg0 - 1 + i, arg1 - 1 + j, &grid[i][j], 0, 0)) {
                grid[i][j] = sp8;
            }
        }
    }

    if (arg5 != 0) {
        *arg2 = fn_801DB514(grid, arg5, farg0, farg1);
    } else {
        *arg2 = fn_801DB398(grid, farg0, farg1);
    }
    return 1;
}
#pragma pop
int fn_801DC258(void *arg0, void *arg1, void *arg2, void *arg3, float farg0, float farg1) {
    extern int lbl_8055E990;
    float *state = (float *)lbl_8055E990;
    float temp_x, fx, temp_z, fz;
    temp_x = (farg0 + state[0]) * state[2];
    temp_z = (farg1 + state[1]) * state[3];
    fx = floor(temp_x);
    fz = floor(temp_z);
    return fn_801DB74C((int)fx, (int)fz, (float *)arg0, (int *)arg1, arg2, arg3, temp_x - fx, temp_z - fz);
}
#pragma pop

#pragma use_lmw_stmw off
void fn_801DC32C(void *base) {
    unsigned char *arg0 = base;
    int i, j, k;
    int minX, minZ, maxX, maxZ;
    unsigned char *node;
    unsigned char *p;
    unsigned char *q;

    p = arg0;
    i = 13;
    do {
        swap32(p);
        p += 4;
    } while (--i);
    *(int *)(arg0 + 0x18) += (int)arg0;
    *(int *)(arg0 + 0x20) += (int)arg0;
    *(int *)(arg0 + 0x28) += (int)arg0;
    *(int *)(arg0 + 0x30) += (int)arg0;
    memset(lbl_80442708, -1, 0x4800);
    lbl_8055E9A0 = 0;
    lbl_8055E99C = 0;
    minX = 0; minZ = 0; maxX = 0; maxZ = 0;
    for (i = 0; i < *(int *)(arg0 + 0x14); i++) {
        node = *(unsigned char **)(arg0 + 0x18) + i * 0x894;
        swap32(node);
        swap32(node + 4);
        for (j = 0; j < 32; j++) {
            q = node + 8;
            for (k = 0; k < 32; k++) {
                swap16(q + j * 2);
                q += 0x40;
            }
        }
        swap32(node + 0x808);
        swap32(node + 0x80C);
        p = node + 0x810;
        for (k = 0; k < 8; k++) {
            swap32(p);
            swap32(p + 4);
            swap32(p + 8);
            swap32(p + 12);
            p += 16;
        }
        swap32(node + 0x890);
        if (i == 0) {
            lbl_8055E99C = minX = maxX = *(int *)(node + 0x808);
            lbl_8055E9A0 = minZ = maxZ = *(int *)(node + 0x80C);
        } else {
            minX = lbl_8055E99C;
            if (*(int *)(node + 0x808) < minX) minX = *(int *)(node + 0x808);
            lbl_8055E99C = minX;
            minZ = lbl_8055E9A0;
            if (*(int *)(node + 0x80C) < minZ) minZ = *(int *)(node + 0x80C);
            lbl_8055E9A0 = minZ;
            if (*(int *)(node + 0x808) > maxX) maxX = *(int *)(node + 0x808);
            if (*(int *)(node + 0x80C) > maxZ) maxZ = *(int *)(node + 0x80C);
        }
    }
    fn_802E30C8(lbl_803393B8, maxX - minX, maxZ - minZ);
    for (i = 0; i < *(int *)(arg0 + 0x14); i++) {
        node = *(unsigned char **)(arg0 + 0x18) + i * 0x894;
        if (*(int *)(node + 0x808) < lbl_8055E99C || *(int *)(node + 0x80C) < lbl_8055E9A0
            || *(int *)(node + 0x808) - lbl_8055E99C >= 0x60 || *(int *)(node + 0x80C) - lbl_8055E9A0 >= 0x60) {
            fn_802E317C(lbl_803393E0, *(int *)(node + 0x808) - lbl_8055E99C, *(int *)(node + 0x80C) - lbl_8055E9A0, 0x60, 0x60);
        }
        ((unsigned short (*)[0x60])lbl_80442708)[*(int *)(node + 0x808) - lbl_8055E99C][*(int *)(node + 0x80C) - lbl_8055E9A0] = i;
    }
    for (i = 0; i < *(int *)(arg0 + 0x1C); i++) {
        node = *(unsigned char **)(arg0 + 0x20) + i * 0x810;
        swap32(node);
        swap32(node + 4);
        for (j = 0; j < 32; j++) {
            q = node + 8;
            for (k = 0; k < 32; k++) {
                swap16(q + j * 2);
                q += 0x40;
            }
        }
        swap32(node + 0x808);
        swap32(node + 0x80C);
    }
    for (i = 0; i < *(int *)(arg0 + 0x24); i++) {
        p = *(unsigned char **)(arg0 + 0x28) + i * 16;
        swap32(p);
        swap32(p + 4);
        swap32(p + 8);
        swap32(p + 12);
    }
}
extern void *fn_8012E96C(const char *);
extern void *fn_8012C370(const char *, u32, s32 *, void *, void *, u8 *);
extern void fn_802E317C(const char *, ...);
extern void fn_801DC32C(void *);
extern char lbl_8033940C[];
extern char lbl_80339418[];
#pragma auto_inline off
#pragma scheduling invalid_target
/* Load the ground resource "track.gnd" (tag 'Grnd'), log a version/size mismatch if reported, and free the buffer when flagged. */
int fn_801DC9B0(void) {
    char *path = lbl_8033940C;
    s32 size = 0;
    u8 flag;
    int result;

    fn_8012E96C(path);
    result = (int)fn_8012C370(path, 0x47726E64, &size, 0, 0, &flag);
    if (result != 0) {
        if (size != 0) {
            fn_802E317C(lbl_80339418, path, size, 0);
        }
        if (flag != 0) {
            fn_801DC32C((void *)result);
        }
    }
    return result;
}
#pragma scheduling on

#pragma paired_single reset
void fn_801DCA5C(void) {
    fn_8012C4D8();
}

extern char lbl_80339444[], lbl_80339458[];
extern float lbl_80562B60, lbl_80562B64, lbl_80562B80, lbl_80562B84, lbl_80562B88, lbl_80562B8C, lbl_80562B90, lbl_80562B94, lbl_80562B98, lbl_80562B9C, lbl_80562BA0, lbl_80562BA4, lbl_80562BA8;
extern void *fn_801284F8(int, const char *);
extern void *fn_8012850C(int, const char *);
extern void *memset(void *, int, unsigned int);
extern double fn_8002F234(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
int fn_801DCA60(void) {
    float *object;
    float one, pi, falloff, peak, offset, range, zero, amplitude, maxR, minR;
    float scale, size, val, power, radius, factor, sum, amp, base;
    int row, col, row2, col2, offsetRow, dx, dz, width, octave;
    lbl_80446F08[1] = 256;
    lbl_80446F08[0] = 256;
    object = (float *)fn_801284F8(0x34, lbl_80339444);
    memset(object, 0, 0x34);
    scale = lbl_80562B80 * lbl_80562B60;
    size = scale * lbl_80562B64;
    object[0] = size;
    object[1] = size;
    size = (float)lbl_80446F08[0] / scale;
    object[3] = size;
    object[2] = size;
    lbl_80446F08[2] = (int)fn_8012850C(lbl_80446F08[0] * lbl_80446F08[1] * 4, lbl_80339458);
    one = lbl_80562B70;
    pi = lbl_80562BA4;
    falloff = lbl_80562BA8;
    peak = lbl_80562B90;
    offset = lbl_80562B94;
    range = lbl_80562B98;
    zero = lbl_80562B84;
    amplitude = lbl_80562B9C;
    maxR = lbl_80562B8C;
    minR = lbl_80562B88;
    row = 0; row2 = 0; offsetRow = 0;
    while (row < lbl_80446F08[0]) {
        dz = row - 128;
        col = 0; col2 = 0;
        while (col < lbl_80446F08[1]) {
            dx = col - 128;
            val = lbl_80562B84;
            factor = lbl_80562B70;
            radius = (float)dz * (float)dz + (float)dx * (float)dx;
            if (radius > minR && radius < maxR) {
                radius = (float)fn_8002F234(radius);
                if (radius > peak) radius = peak - (radius - peak);
                radius = (radius - offset) / range;
                if (one < radius) radius = one;
                radius = radius > zero ? radius : zero;
                factor = one + radius * amplitude;
            }
            width = lbl_80446F08[0];
            amp = lbl_80562BA0;
            octave = width / 2;
            power = falloff * factor;
            while (octave > 16) {
                base = val;
                sum = amp * (one + (float)sin(pi * ((float)row2 / (float)octave)));
                val = base + sum;
                val += amp * (one + (float)cos(pi * ((float)col2 / (float)octave)));
                amp *= power;
                octave /= 2;
            }
            ((float *)lbl_80446F08[2])[width * col + row] = val;
            col2 += 2;
            col++;
        }
        row2 += 2;
        row++;
        offsetRow += 4;
    }
    return (int)object;
}
#pragma pop

void fn_801DCD24(void) {
    fn_80128668();
}

#pragma scheduling invalid_target
void fn_801DCD28(int arg0) {
    lbl_8055E998 = 0;
    if (arg0 == 0) {
        fn_802E30C8(lbl_80339468, lbl_8055E990 = fn_801DC9B0());
        lbl_8055E994 = (void (*)(int))fn_801DCA5C;
    } else {
        lbl_8055E990 = fn_801DCA60();
        lbl_8055E994 = (void (*)(int))fn_801DCD24;
    }
    lbl_8055E9A4 = 1;
    fn_801D02B0();
}
#pragma scheduling on
void fn_801DCDA0(void) {

}

void fn_801DCDA4(void) {
    register void *entry = *(void **)((char *)lbl_80446F08 + 8);
    if (entry != 0) {
        fn_80128670();
        *(void **)((char *)lbl_80446F08 + 8) = 0;
    }
    lbl_8055E994(lbl_8055E990);
    lbl_8055E994 = 0;
    lbl_8055E990 = 0;
    lbl_8055E9A4 = 0;
    fn_801D049C();
}

void fn_801DCE0C(void) {
    ((void (*)(void))fn_801DCD28)();
}

void fn_801DCE10(void) {

}

int fn_801DCE14(short *arg0, float *arg1, float *arg2, int arg3, int *arg4) {
    float spC;
    int sp8;
    float b2;
    float b0;
    float t0;
    float tC;
    float t2;

    if (arg0 != 0) {
        *arg0 = 0;
    }
    b0 = arg1[0];
    sp8 = 0xFF;
    b2 = arg1[2];
    if (((int (*)(float *, int *, short *, int, float, float))fn_801DC258)((float *)&spC, &sp8, arg0, arg3, b0, b2) != 0) {
        if (arg4 != 0) {
            *arg4 = sp8;
        }
        tC = spC;
        t2 = arg1[2];
        t0 = arg1[0];
        arg2[1] = tC;
        arg2[0] = t0;
        arg2[2] = t2;
        return 1;
    }
    return 0;
}

float fn_801DCEC0(void) {
    return lbl_80562B70;
}

extern float lbl_804424B0[];
void fn_801DCEC8(int arg0, float arg1) {
    lbl_804424B0[arg0] = arg1;
}

extern float lbl_804425DC[];
void fn_801DCEDC(int arg0, float arg1) {
    lbl_804425DC[arg0] = arg1;
}

void fn_801DCEF0(void) {

}

extern void *lbl_8055E9A8;
void fn_801DCEF4(void) {
    lbl_8055E9A8 = 0;
}

extern void *lbl_8055E9A8;
void fn_801DCF00(void) {
    lbl_8055E9A8 = 0;
}

#pragma scheduling invalid_target
#pragma dont_inline on
float fn_801DCF0C(void) {
    float sp8 = lbl_80562BB8;
    ((int (*)(float *, int, int, int))fn_801DC258)(&sp8, 0, 0, 0);
    return sp8;
}
#pragma dont_inline reset
#pragma scheduling on
extern double fabs(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
float fn_801DCF48(void *arg0, float farg0, float farg1) {
    extern float lbl_80562B84;
    extern float lbl_80562BBC;
    char *state = (char *)lbl_8055E990;
    char *node, *layer;
    float sp8, var_f31, x, z, roundedX, roundedZ;
    float var_f8, var_f7, weight, slope, base, normalY, factorZ, factorX;
    int ix, iz, quotientX, quotientZ, tileX, tileZ, remX, remZ;
    int otherZ, otherX, deltaZ, deltaX, next;
    unsigned short tile;
    unsigned short *tileMap;
    unsigned short sample00, sample01, sample10;
    void *tileBase;
    if (*(int *)(state + 0x10) == 0) {
        sp8 = lbl_80562B84;
        if (((int (*)(float *, int, int, void *))fn_801DC258)(&sp8, 0, 0, arg0) == 0) {
            sp8 = lbl_80562B84;
            if (arg0 != 0) {
                float zero = lbl_80562B84;
                float one = lbl_80562B70;
                ((float *)arg0)[0] = zero;
                ((float *)arg0)[1] = one;
                ((float *)arg0)[2] = zero;
            }
        }
        var_f31 = sp8;
        goto done;
    }
    x = *(float *)(state + 8) * (farg0 + *(float *)(state + 0));
    z = *(float *)(state + 0xC) * (farg1 + *(float *)(state + 4));
    if (x < lbl_80562B84) roundedX = x - lbl_80562B64;
    else roundedX = lbl_80562B64 + x;
    ix = (int)roundedX;
    if (z < lbl_80562B84) roundedZ = z - lbl_80562B64;
    else roundedZ = lbl_80562B64 + z;
    iz = (int)roundedZ;
    quotientX = ix / 32;
    tileX = quotientX - lbl_8055E99C;
    remX = ix - quotientX * 32;
    quotientZ = iz / 32;
    remZ = iz - quotientZ * 32;
    tileZ = quotientZ - lbl_8055E9A0;
    if (tileX < 0 || tileZ < 0) {
        node = 0;
    } else if (tileX >= 0x60 || tileZ >= 0x60) {
        node = 0;
    } else {
        tileMap = lbl_80442708;
        tile = *(unsigned short *)((char *)tileMap + tileX * 0xC0 + tileZ * 2);
        if (tile == 0xFFFF) node = 0;
        else {
            tileBase = *(void **)(state + 0x18);
            node = (char *)tileBase + tile * 0x894;
        }
    }
    if (node == 0) {
        if (arg0 != 0) {
            float zero = lbl_80562B84;
            float one = lbl_80562B70;
            ((float *)arg0)[0] = zero;
            ((float *)arg0)[1] = one;
            ((float *)arg0)[2] = zero;
        }
        var_f31 = lbl_80562B84;
        goto done;
    }
    if (arg0 != 0) {
        deltaZ = remZ << 1;
        next = *(int *)(node + 0x890);
        deltaX = remX << 6;
        otherZ = (remZ ^ 1) << 1;
        otherX = (remX ^ 1) << 6;
        slope = *(float *)(node + 4);
        base = *(float *)(node + 0);
        sample00 = *(unsigned short *)(node + deltaX + deltaZ + 8);
        sample01 = *(unsigned short *)(node + deltaX + otherZ + 8);
        sample10 = *(unsigned short *)(node + otherX + deltaZ + 8);
        var_f31 = base + slope * (float)sample00;
        var_f8 = base + slope * (float)sample01;
        var_f7 = base + slope * (float)sample10;
        next = *(int *)(node + 0x890);
        if (next >= 0) {
            layer = (char *)*(char **)((char *)*(volatile int *)&lbl_8055E990 + 0x20) + next * 0x810;
            do {
                base = *(float *)(layer + 0);
                slope = *(float *)(layer + 4);
                weight = lbl_804424B0[*(int *)(layer + 0x808)];
                var_f31 += weight * (base + slope * (float)*(unsigned short *)(layer + deltaX + deltaZ + 8));
                var_f7 += weight * (base + slope * (float)*(unsigned short *)(layer + otherX + deltaZ + 8));
                var_f8 += weight * (base + slope * (float)*(unsigned short *)(layer + deltaX + otherZ + 8));
                next = *(int *)(layer + 0x80C);
                layer = next >= 0 ? (char *)*(char **)((char *)*(volatile int *)&lbl_8055E990 + 0x20) + next * 0x810 : 0;
            } while (layer != 0);
        }
        var_f7 -= var_f31;
        var_f8 -= var_f31;
        factorX = (remX & 1) ? lbl_80562BBC : lbl_80562B70;
        factorX /= *(float *)(state + 8);
        if (remZ & 1) factorZ = lbl_80562BBC;
        else factorZ = lbl_80562B70;
        factorZ /= *(float *)(state + 0xC);
        normalY = (float)fabs(factorX * factorZ);
        ((float *)arg0)[0] = -var_f7 * factorX;
        ((float *)arg0)[2] = -var_f8 * factorZ;
        ((float *)arg0)[1] = normalY;
        PSVECNormalize((float *)arg0, (float *)arg0);
    } else {
        deltaZ = remZ << 1;
        next = *(int *)(node + 0x890);
        deltaX = remX << 6;
        base = *(float *)(node + 0);
        slope = *(float *)(node + 4);
        sample00 = *(unsigned short *)(node + deltaX + deltaZ + 8);
        var_f31 = base + slope * (float)sample00;
        if (next >= 0) {
            layer = (char *)*(char **)((char *)*(volatile int *)&lbl_8055E990 + 0x20) + next * 0x810;
            do {
                weight = lbl_804424B0[*(int *)(layer + 0x808)];
                var_f31 += weight * (*(float *)(layer + 0) + *(float *)(layer + 4) * (float)*(unsigned short *)(layer + deltaX + deltaZ + 8));
                next = *(int *)(layer + 0x80C);
                layer = next >= 0 ? (char *)*(char **)((char *)*(volatile int *)&lbl_8055E990 + 0x20) + next * 0x810 : 0;
            } while (layer != 0);
        }
    }
done:
    return var_f31;
}
#pragma pop
extern float lbl_80558DC4[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma opt_propagation off
void fn_801DD3BC(float *value, int flag, float x, float z) {
    float saved[75];
    float before, base, delta, minimum, epsilon;
    float zero, one;
    unsigned char *pair;
    unsigned char *slot;
    int i, count, smallest;
    int depth = (int)lbl_8055E9A8;
    lbl_8055E9A8 = (void *)(depth + 1);
    slot = lbl_80446F18 + depth * 0x20;
    *(float **)slot = value;
    before = ((float (*)(float,float))fn_801DCF0C)(x,z);
    for (i=0; i<72; i+=8) {
      saved[i+0] = lbl_804424B0[i+0]; lbl_804424B0[i+0] = lbl_80562B84;
      saved[i+1] = lbl_804424B0[i+1]; lbl_804424B0[i+1] = lbl_80562B84;
      saved[i+2] = lbl_804424B0[i+2]; lbl_804424B0[i+2] = lbl_80562B84;
      saved[i+3] = lbl_804424B0[i+3]; lbl_804424B0[i+3] = lbl_80562B84;
      saved[i+4] = lbl_804424B0[i+4]; lbl_804424B0[i+4] = lbl_80562B84;
      saved[i+5] = lbl_804424B0[i+5]; lbl_804424B0[i+5] = lbl_80562B84;
      saved[i+6] = lbl_804424B0[i+6]; lbl_804424B0[i+6] = lbl_80562B84;
      saved[i+7] = lbl_804424B0[i+7]; lbl_804424B0[i+7] = lbl_80562B84;
    }
    saved[72]=lbl_804424B0[72]; lbl_804424B0[72]=lbl_80562B84;
    saved[73]=lbl_804424B0[73]; lbl_804424B0[73]=lbl_80562B84;
    saved[74]=lbl_804424B0[74]; lbl_804424B0[74]=lbl_80562B84;
    base = ((float (*)(float,float))fn_801DCF0C)(x,z);
    if (flag == 0) before=base;
    *(float *)(slot+4)=base+(*value-before);
    *(int *)(slot+8)=0; *(float *)(slot+12)=lbl_80562B84;
    *(int *)(slot+16)=0; *(float *)(slot+20)=lbl_80562B84;
    *(int *)(slot+24)=0; *(float *)(slot+28)=lbl_80562B84;
    epsilon=lbl_80558DC4[0];
    count=0; pair=slot; zero=lbl_80562B84; one=lbl_80562B70;
    for(i=0;i<75;i++) {
        lbl_804424B0[i]=one;
        delta=((float (*)(float,float))fn_801DCF0C)(x,z)-base;
        if (!((float)fabs(delta) <= epsilon)) {
            if (count<3) {
                *(int *)(pair+8)=i;
                *(float *)(pair+12)=delta;
                count++; pair+=8;
            } else {
                smallest=-1; minimum=zero;
                if (smallest<0 || (float)fabs(*(float *)(slot+12)) < (float)fabs(minimum)) { smallest=0; minimum=*(float *)(slot+12); }
                if (smallest<0 || (float)fabs(*(float *)(slot+20)) < (float)fabs(minimum)) { smallest=1; minimum=*(float *)(slot+20); }
                if (smallest<0 || (float)fabs(*(float *)(slot+28)) < (float)fabs(minimum)) { smallest=2; }
                if ((float)fabs(delta) > (float)fabs(*(float *)(slot+12+smallest*8))) {
                    *(float *)(slot+12+smallest*8)=delta;
                    *(int *)(slot+8+smallest*8)=i;
                }
            }
        }
        lbl_804424B0[i]=zero;
    }
    for (i=0;i<72;i+=24) {
      lbl_804424B0[i+0]=saved[i+0];
      lbl_804424B0[i+1]=saved[i+1];
      lbl_804424B0[i+2]=saved[i+2];
      lbl_804424B0[i+3]=saved[i+3];
      lbl_804424B0[i+4]=saved[i+4];
      lbl_804424B0[i+5]=saved[i+5];
      lbl_804424B0[i+6]=saved[i+6];
      lbl_804424B0[i+7]=saved[i+7];
      lbl_804424B0[i+8]=saved[i+8];
      lbl_804424B0[i+9]=saved[i+9];
      lbl_804424B0[i+10]=saved[i+10];
      lbl_804424B0[i+11]=saved[i+11];
      lbl_804424B0[i+12]=saved[i+12];
      lbl_804424B0[i+13]=saved[i+13];
      lbl_804424B0[i+14]=saved[i+14];
      lbl_804424B0[i+15]=saved[i+15];
      lbl_804424B0[i+16]=saved[i+16];
      lbl_804424B0[i+17]=saved[i+17];
      lbl_804424B0[i+18]=saved[i+18];
      lbl_804424B0[i+19]=saved[i+19];
      lbl_804424B0[i+20]=saved[i+20];
      lbl_804424B0[i+21]=saved[i+21];
      lbl_804424B0[i+22]=saved[i+22];
      lbl_804424B0[i+23]=saved[i+23];
    }
    lbl_804424B0[72]=saved[72]; lbl_804424B0[73]=saved[73]; lbl_804424B0[74]=saved[74];
    {
        int any=0;
        if (!((float)fabs(*(float *)(slot+12)) <= epsilon)) any=1;
        if (!((float)fabs(*(float *)(slot+20)) <= epsilon)) any=1;
        if (!((float)fabs(*(float *)(slot+28)) <= epsilon)) any=1;
        if (!any) lbl_8055E9A8=(void *)((int)lbl_8055E9A8-1);
    }
}
#pragma pop

extern int fn_801DC9B0(void);
extern int fn_801DCA60(void);
void fn_801DD808(void) {
    /* Write out computed float values for each 0x20-byte entry by combining a base
       value with three indexed terms from lbl_804424B0. */
    unsigned char *entry = lbl_80446F18;
    int i = 0;
    while (i < (int)lbl_8055E9A8) {
        int index0 = *(int *)(entry + 8);
        int index1 = *(int *)(entry + 0x10);
        int index2 = *(int *)(entry + 0x18);
        float value = *(float *)(entry + 4);
        value += *(float *)(entry + 0xC) * lbl_804424B0[index0];
        value += *(float *)(entry + 0x14) * lbl_804424B0[index1];
        value += *(float *)(entry + 0x1C) * lbl_804424B0[index2];
        *(float *)*(int *)entry = value;
        entry += 0x20;
        i++;
    }
}

extern float lbl_80562B84;
extern float fn_801DCF0C(void);
#pragma dont_inline fn_801DCF0C
void fn_801DD88C(void) {
    float temp[75];
    int i;

    for (i = 0; i < 72; i += 8) {
        temp[i + 0] = lbl_804424B0[i + 0];
        lbl_804424B0[i + 0] = lbl_80562B84;
        temp[i + 1] = lbl_804424B0[i + 1];
        lbl_804424B0[i + 1] = lbl_80562B84;
        temp[i + 2] = lbl_804424B0[i + 2];
        lbl_804424B0[i + 2] = lbl_80562B84;
        temp[i + 3] = lbl_804424B0[i + 3];
        lbl_804424B0[i + 3] = lbl_80562B84;
        temp[i + 4] = lbl_804424B0[i + 4];
        lbl_804424B0[i + 4] = lbl_80562B84;
        temp[i + 5] = lbl_804424B0[i + 5];
        lbl_804424B0[i + 5] = lbl_80562B84;
        temp[i + 6] = lbl_804424B0[i + 6];
        lbl_804424B0[i + 6] = lbl_80562B84;
        temp[i + 7] = lbl_804424B0[i + 7];
        lbl_804424B0[i + 7] = lbl_80562B84;
    }
    temp[72] = lbl_804424B0[72];
    lbl_804424B0[72] = lbl_80562B84;
    temp[73] = lbl_804424B0[73];
    lbl_804424B0[73] = lbl_80562B84;
    temp[74] = lbl_804424B0[74];
    lbl_804424B0[74] = lbl_80562B84;

    fn_801DCF0C();

    for (i = 0; i < 72; i += 24) {
        lbl_804424B0[i + 0] = temp[i + 0];
        lbl_804424B0[i + 1] = temp[i + 1];
        lbl_804424B0[i + 2] = temp[i + 2];
        lbl_804424B0[i + 3] = temp[i + 3];
        lbl_804424B0[i + 4] = temp[i + 4];
        lbl_804424B0[i + 5] = temp[i + 5];
        lbl_804424B0[i + 6] = temp[i + 6];
        lbl_804424B0[i + 7] = temp[i + 7];
        lbl_804424B0[i + 8] = temp[i + 8];
        lbl_804424B0[i + 9] = temp[i + 9];
        lbl_804424B0[i + 10] = temp[i + 10];
        lbl_804424B0[i + 11] = temp[i + 11];
        lbl_804424B0[i + 12] = temp[i + 12];
        lbl_804424B0[i + 13] = temp[i + 13];
        lbl_804424B0[i + 14] = temp[i + 14];
        lbl_804424B0[i + 15] = temp[i + 15];
        lbl_804424B0[i + 16] = temp[i + 16];
        lbl_804424B0[i + 17] = temp[i + 17];
        lbl_804424B0[i + 18] = temp[i + 18];
        lbl_804424B0[i + 19] = temp[i + 19];
        lbl_804424B0[i + 20] = temp[i + 20];
        lbl_804424B0[i + 21] = temp[i + 21];
        lbl_804424B0[i + 22] = temp[i + 22];
        lbl_804424B0[i + 23] = temp[i + 23];
    }
    lbl_804424B0[72] = temp[72];
    lbl_804424B0[73] = temp[73];
    lbl_804424B0[74] = temp[74];
}
extern int lbl_8055E99C;
extern int lbl_8055E9A0;
extern unsigned short lbl_80442708[];
extern float lbl_80562B64, lbl_80562B84;
extern double lbl_80562B78;
int fn_801DDA84(int unused, int *out, int max, float x, float z, float thr) {
    int *state = (int *)lbl_8055E990;
    int ix, iz, qx, qz, tileX, tileZ, remX, remZ;
    int tile, count, idx;
    char *node, *map;

    if (state[4] == 0)
        return 0;
    x = (x + *(float *)((char *)state + 0)) * *(float *)((char *)state + 8);
    z = (z + *(float *)((char *)state + 4)) * *(float *)((char *)state + 12);
    ix = (int)(x < lbl_80562B84 ? x - lbl_80562B64 : lbl_80562B64 + x);
    iz = (int)(z < lbl_80562B84 ? z - lbl_80562B64 : lbl_80562B64 + z);
    if (ix < 0 || iz < 0)
        return 0;
    qx = ix / 32;
    qz = iz / 32;
    tileX = qx - lbl_8055E99C;
    tileZ = qz - lbl_8055E9A0;
    remX = ix - qx * 32;
    remZ = iz - qz * 32;
    if (tileX < 0 || tileZ < 0 || tileX >= 0x60 || tileZ >= 0x60)
        return 0;
    tile = ((unsigned short (*)[0x60])lbl_80442708)[tileX][tileZ];
    if (tile == 0xFFFF)
        return 0;
    node = *(char **)((char *)state + 0x18) + tile * 0x894;
    if (node == 0)
        return 0;
    idx = *(int *)(node + 0x890);
    count = 0;
    if (idx < 0)
        return 0;
    map = *(char **)((char *)state + 0x20) + idx * 0x810;
    while (1) {
        float h = (float)fabs(*(float *)map + *(float *)(map + 4) * ((float)*(unsigned short *)(map + remX * 64 + remZ * 2 + 8) - lbl_80562B78));
        if (h < thr && count < max) {
            out[count] = *(int *)(map + 0x808);
            count++;
        }
        idx = *(int *)(map + 0x80C);
        if (idx < 0)
            break;
        map = *(char **)((char *)lbl_8055E990 + 0x20) + idx * 0x810;
    }
    return count;
}

#pragma push
#pragma paired_single off
#pragma opt_common_subs on
#pragma scheduling invalid_target
float fn_801DDC8C(float farg0, float farg1) {
    int *state = (int *)lbl_8055E990;
    int cellX;
    int cellZ;
    int tileWorldX;
    int tileWorldZ;
    int tileX;
    int tileZ;
    int remX;
    int remZ;
    unsigned short tile;
    char *node;
    int layerIndex;
    unsigned short sample;
    int next;
    int tblIdx;
    float offsetX;
    float scaleX;
    float offsetZ;
    float scaleZ;
    float x;
    float z;
    float roundX;
    float roundZ;
    float value;
    float result;
    char *layer;
    char *base;
    if (state[4] == 0)
        return lbl_80562B84;
    offsetX = farg0 + *(float *)((char *)state + 0);
    scaleX = *(float *)((char *)state + 8);
    offsetZ = farg1 + *(float *)((char *)state + 4);
    scaleZ = *(float *)((char *)state + 12);
    x = scaleX * offsetX;
    z = scaleZ * offsetZ;
    roundX = x < lbl_80562B84 ? x - lbl_80562B64 : lbl_80562B64 + x;
    cellX = (int)roundX;
    roundZ = z < lbl_80562B84 ? z - lbl_80562B64 : lbl_80562B64 + z;
    cellZ = (int)roundZ;
    if (cellX < 0 || cellZ < 0)
        return lbl_80562B84;
    tileWorldX = cellX / 32;
    tileWorldZ = cellZ / 32;
    tileX = tileWorldX - lbl_8055E99C;
    tileZ = tileWorldZ - lbl_8055E9A0;
    remX = cellX - tileWorldX * 32;
    remZ = cellZ - tileWorldZ * 32;
    if (tileX < 0 || tileZ < 0)
        node = 0;
    else if (tileX >= 0x60 || tileZ >= 0x60)
        node = 0;
    else {
        tile = *(unsigned short *)((char *)lbl_80442708 + tileX * 0xC0 + tileZ * 2);
        if (tile == 0xFFFF)
            node = 0;
        else
            node = (char *)*(int *)((char *)state + 0x18) + tile * 0x894;
    }
    if (node == 0)
        return lbl_80562B84;
    layerIndex = *(int *)(node + 0x890);
    result = lbl_80562B84;
    if (layerIndex >= 0) {
        base = (char *)*(int *)((char *)state + 0x20);
        layer = base + layerIndex * 0x810;
        do {
            tblIdx = *(int *)(layer + 0x808);
            sample = *(unsigned short *)(layer + (remX * 64 + remZ * 2) + 8);
            next = *(int *)(layer + 0x80C);
            value = *(float *)(layer + 0) + *(float *)(layer + 4) * (float)sample;
            result += value * lbl_804425DC[tblIdx];
            if (next < 0)
                break;
            base = (char *)*(int *)((char *)state + 0x20);
            layer = base + next * 0x810;
        } while (1);
        return result;
    } else
        return result;
}
#pragma pop

extern float lbl_80562B70;
extern float lbl_80562BB8;
extern int fn_80128670(void);
extern int fn_801D049C(void);
extern int lbl_80446F08[];
extern int lbl_8055E990;
extern void (*lbl_8055E994)(int);
extern char lbl_8055E9A4;
