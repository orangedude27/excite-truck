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
extern int fn_801DB348(int, int, float *, int *);
extern float fn_801DB398(float grid[4][4], float, float);
extern float fn_801DB514(float grid[4][4], void *, float, float);

static inline int sample_tile(int x, int y, float *out_h, int *out_type, void *arg4) {
    int tileX, tileZ, remX, remZ;
    char *node;
    char *layer;
    unsigned char *type_p;
    int tile, next, sum;
    float h;

    if (x < 0 || y < 0) {
        return 0;
    }
    if (*(int *)((char *)lbl_8055E990 + 0x10) == 0) {
        return fn_801DB348(x, y, out_h, out_type);
    }
    tileX = (x / 32) - lbl_8055E99C;
    tileZ = (y / 32) - lbl_8055E9A0;
    remX = x - (x / 32) * 32;
    remZ = y - (y / 32) * 32;
    if (tileX >= 0 && tileZ >= 0 && tileX < 0x60 && tileZ < 0x60) {
        tile = ((unsigned short (*)[0x60])lbl_80442708)[tileX][tileZ];
        if (tile != 0xFFFF) {
            node = *(char **)((char *)lbl_8055E990 + 0x18) + tile * 0x894;
        } else {
            node = 0;
        }
    } else {
        node = 0;
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

int fn_801DB348(int arg0, int arg1, float *arg2, int *arg3) {
    int width, height;
    float *data;

    if (arg3 != 0) {
        *arg3 = 0;
    }
    width = lbl_80446F08[0];
    height = lbl_80446F08[1];
    data = (float *)lbl_80446F08[2];

    arg1 = (arg1 & (height - 1)) * width;
    arg0 = (arg0 & (width - 1)) + arg1;
    *arg2 = data[arg0];
    return 1;
}

extern float lbl_80562B64;
extern float lbl_80562B68;
extern float lbl_80562B6C;
#pragma push
#pragma paired_single off
#pragma opt_common_subs off
#pragma scheduling invalid_target
float fn_801DB398(float grid[4][4], float t, float u) {
    float values[4];
    float *src = &grid[0][0];
    float *out = values;
    float t2;
    float t3;
    float p2;
    float p0;
    float p1;
    float p3;
    float dp20;
    float dp21;
    float dp31;
    float half20;
    float half31;
    float twice20;
    float twice21;
    float sum;
    float coeff2;
    float coeff3;
    float base;
    float term1;
    float term2;
    float p2y;
    float p0y;
    float p3y;
    float p1y;
    float dy20;
    float dy21;
    float dy31;
    float yhalf20;
    float yhalf31;
    float ytwice20;
    float ytwice21;
    float ysum;
    float ycoeff2;
    float ycoeff3;
    float ybase;
    float yterm1;
    float yterm2;
    int i;

    t2 = t * t;
    t3 = t2 * t;
    for (i = 0; i < 2; i++) {
        p2 = src[8];
        p0 = src[0];
        p1 = src[4];
        dp20 = p2 - p0;
        p3 = src[12];
        dp21 = p2 - p1;
        p2y = src[9];
        dp31 = p3 - p1;
        half20 = lbl_80562B64 * dp20;
        p0y = src[1];
        half31 = lbl_80562B64 * dp31;
        p3y = src[13];

        twice20 = lbl_80562B68 * half20;
        sum = half20 + half31;
        twice21 = lbl_80562B68 * dp21;
        coeff3 = lbl_80562B6C * dp21;
        coeff3 = coeff3 - twice20;
        base = half20 * t;
        coeff2 = sum - twice21;
        coeff3 = coeff3 - half31;
        term1 = coeff2 * t3;
        term2 = coeff3 * t2;
        coeff2 = term1 + term2;
        coeff2 = base + coeff2;
        out[0] = p1 + coeff2;

        p1y = src[5];
        src += 2;
        dy20 = p2y - p0y;
        dy21 = p2y - p1y;
        dy31 = p3y - p1y;
        yhalf31 = lbl_80562B64 * dy31;
        yhalf20 = lbl_80562B64 * dy20;
        ytwice20 = lbl_80562B68 * yhalf20;
        ysum = yhalf20 + yhalf31;
        ytwice21 = lbl_80562B68 * dy21;
        ycoeff3 = lbl_80562B6C * dy21;
        ycoeff3 = ycoeff3 - ytwice20;
        ybase = yhalf20 * t;
        ycoeff2 = ysum - ytwice21;
        ycoeff3 = ycoeff3 - yhalf31;
        yterm1 = ycoeff2 * t3;
        yterm2 = ycoeff3 * t2;
        ycoeff2 = yterm1 + yterm2;
        ycoeff2 = ybase + ycoeff2;
        out[1] = p1y + ycoeff2;

        out += 2;
    }

    {
        float p0 = values[0];
        float p1 = values[1];
        float p2 = values[2];
        float p3 = values[3];
        float d20 = p2 - p1;
        float d21 = p2 - p0;
        float d31 = p3 - p1;
        float half20 = lbl_80562B64 * d21;
        float half31 = lbl_80562B64 * d31;
        float two20 = lbl_80562B68 * half20;
        float sum = half20 + half31;
        float two21 = lbl_80562B68 * d20;
        float coeff3 = lbl_80562B6C * d20;
        float base = half20 * u;
        float coeff2 = sum - two21;
        float u2 = u * u;
        float u3 = u2 * u;
        coeff3 = coeff3 - two20;
        coeff3 = coeff3 - half31;
        coeff2 = coeff2 * u3;
        coeff3 = coeff3 * u2;
        coeff2 = coeff2 + coeff3;
        coeff2 = base + coeff2;
        return p1 + coeff2;
    }
}
#pragma pop

float fn_801DB514(float grid[4][4], void *out, float t, float u) {
    float a[4], b[4];
    float q = t * t;
    float c = q * t;
    float *src = &grid[0][0];
    float *pa = a;
    float *pb = b;
    int i;
    for (i = 0; i < 4; i++) {
        float x = src[8] - src[0];
        float y = src[4] - src[0];
        float z = src[12] - src[4];
        float p = lbl_80562B64 * x;
        float r = lbl_80562B64 * z;
        float s = lbl_80562B6C * y;
        float v = (p + r) - lbl_80562B68 * y;
        float w = (s - lbl_80562B68 * p) - r;
        *pa++ = p + lbl_80562B6C * v * q + lbl_80562B68 * w * t;
        *pb++ = src[4] + p * t + v * c + w * q;
        src++;
    }
    {
        float x = b[2] - b[0];
        float y = b[3] - b[1];
        float p = lbl_80562B64 * x;
        float r = lbl_80562B64 * y;
        float v = (p + r) - lbl_80562B68 * (b[2] - b[1]);
        float w = (lbl_80562B6C * (b[2] - b[1]) - lbl_80562B68 * p) - r;
        float h = p + lbl_80562B6C * v * (u * u) + lbl_80562B68 * w * u;
        float dx = a[2] - a[0];
        float dy = a[3] - a[1];
        float factor = lbl_80562B70 / *(float *)((char *)lbl_8055E990 + 8);
        float z = -(h);
        ((float *)out)[0] = z;
        ((float *)out)[1] = factor;
        ((float *)out)[2] = -z;
        PSVECNormalize(out, out);
        return a[1] + dx * u + dy * (u * u);
    }
}

#pragma paired_single off
int fn_801DB74C(int arg0, int arg1, float *arg2, int *arg3, void *arg4, void *arg5, float farg0, float farg1) {
    float grid[4][4];
    float sp8;
    int i, j;

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

extern void *fn_8012E96C(const char *);
extern void *fn_8012C370(const char *, u32, s32 *, void *, void *, u8 *);
extern void fn_802E317C(const char *, ...);
extern void fn_801DC32C(void *);
extern char lbl_8033940C[];
extern char lbl_80339418[];
#pragma push
#pragma auto_inline off
#pragma scheduling invalid_target
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
#pragma pop

#pragma paired_single reset
void fn_801DCA5C(void) {
    fn_8012C4D8();
}

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

    if (arg0 != 0) {
        *arg0 = 0;
    }
    sp8 = 0xFF;
    if (fn_801DC258(&spC, &sp8, arg0, (void *)arg3, arg1[0], arg1[2]) != 0) {
        if (arg4 != 0) {
            *arg4 = sp8;
        }
        arg2[1] = spC;
        arg2[0] = arg1[0];
        arg2[2] = arg1[2];
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
float fn_801DCF0C(void) {
    float sp8;
    float *p = &sp8;
    sp8 = lbl_80562BB8;
    ((int (*)(float *, int, int, int))fn_801DC258)(p, 0, 0, 0);
    return sp8;
}
#pragma scheduling on
extern double fabs(double);
float fn_801DCF48(void *arg0, float farg0, float farg1) {
    extern float lbl_80562B84;
    extern float lbl_80562BBC;
    char *state = (char *)lbl_8055E990;
    char *node, *layer;
    float sp8, var_f31, x, z, roundedX, roundedZ;
    float base, slope, weight, var_f7, var_f8, factorX, factorZ, normalY;
    int ix, iz, quotientX, quotientZ, tileX, tileZ, remX, remZ;
    int tile, next, deltaX, deltaZ, otherX, otherZ;
    unsigned short *tileMap;
    unsigned short sample00, sample01, sample10;
    void *tileBase;

    if (*(int *)(state + 0x10) == 0) {
        sp8 = lbl_80562B84;
        if (((int (*)(float *, int, int, void *))fn_801DC258)(&sp8, 0, 0, arg0) == 0) {
            sp8 = lbl_80562B84;
            if (arg0 != 0) {
                ((float *)arg0)[0] = lbl_80562B84;
                ((float *)arg0)[1] = lbl_80562B70;
                ((float *)arg0)[2] = lbl_80562B84;
            }
        }
        return sp8;
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
    quotientZ = iz / 32;
    tileX = quotientX - lbl_8055E99C;
    tileZ = quotientZ - lbl_8055E9A0;
    remX = ix - quotientX * 32;
    remZ = iz - quotientZ * 32;
    node = 0;
    if (tileX < 0) {
        node = 0;
    } else if (tileZ < 0) {
        node = 0;
    } else if (tileX >= 0x60) {
        node = 0;
    } else if (tileZ >= 0x60) {
        node = 0;
    } else {
        tileMap = lbl_80442708;
        tile = tileMap[tileX * 0x60 + tileZ];
        if (tile != 0xFFFF) {
            tileBase = *(void **)(state + 0x18);
            node = (char *)tileBase + tile * 0x894;
        }
    }
    if (node == 0) {
        if (arg0 != 0) {
            ((float *)arg0)[0] = lbl_80562B84;
            ((float *)arg0)[1] = lbl_80562B70;
            ((float *)arg0)[2] = lbl_80562B84;
        }
        return lbl_80562B84;
    }

    if (arg0 != 0) {
        deltaX = remX << 6;
        next = *(int *)(node + 0x890);
        deltaZ = remZ << 1;
        otherX = (remX ^ 1) << 6;
        otherZ = (remZ ^ 1) << 1;
        base = *(float *)(node + 0);
        slope = *(float *)(node + 4);
        sample00 = *(unsigned short *)(node + deltaX + deltaZ + 8);
        sample01 = *(unsigned short *)(node + deltaX + otherZ + 8);
        sample10 = *(unsigned short *)(node + otherX + deltaZ + 8);
        var_f31 = base + slope * (float)sample00;
        var_f8 = base + slope * (float)sample01;
        var_f7 = base + slope * (float)sample10;
        next = *(int *)(node + 0x890);
        if (next >= 0) {
            do {
                layer = (char *)*(char **)(state + 0x20) + next * 0x810;
                base = *(float *)(layer + 0);
                slope = *(float *)(layer + 4);
                weight = lbl_804424B0[*(int *)(layer + 0x808)];
                var_f31 += weight * (base + slope * (float)*(unsigned short *)(layer + deltaX + deltaZ + 8));
                var_f7 += weight * (base + slope * (float)*(unsigned short *)(layer + otherX + deltaZ + 8));
                var_f8 += weight * (base + slope * (float)*(unsigned short *)(layer + deltaX + otherZ + 8));
                next = *(int *)(layer + 0x80C);
            } while (next >= 0);
        }
        var_f7 -= var_f31;
        var_f8 -= var_f31;
        if (remX & 1) factorX = lbl_80562BBC;
        else factorX = lbl_80562B70;
        factorX /= *(float *)(state + 8);
        if (remZ & 1) factorZ = lbl_80562BBC;
        else factorZ = lbl_80562B70;
        factorZ /= *(float *)(state + 0xC);
        ((float *)arg0)[0] = -var_f7 * factorX;
        normalY = (float)fabs(factorX * factorZ);
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
            do {
                layer = (char *)*(char **)(state + 0x20) + next * 0x810;
                weight = lbl_804424B0[*(int *)(layer + 0x808)];
                var_f31 += weight * (*(float *)(layer + 0) +
                    *(float *)(layer + 4) * (float)*(unsigned short *)(layer + deltaX + deltaZ + 8));
                next = *(int *)(layer + 0x80C);
            } while (next >= 0);
        }
    }
    return var_f31;
}

extern int fn_801DC9B0(void);
extern int fn_801DCA60(void);
void fn_801DD808(void) {
    unsigned char *entry = lbl_80446F18;
    int i = 0;
    do {
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
    } while (i < (int)lbl_8055E9A8);
}

extern float lbl_80562B84;
extern float fn_801DCF0C(void);
void fn_801DD88C(void) {
    float temp[75];
    int i,j;
    for(i=0;i<9;i++) for(j=0;j<8;j++) { temp[i*8+j]=lbl_804424B0[i*8+j]; lbl_804424B0[i*8+j]=lbl_80562B84; }
    temp[72]=lbl_804424B0[72]; lbl_804424B0[72]=lbl_80562B84;
    temp[73]=lbl_804424B0[73]; lbl_804424B0[73]=lbl_80562B84;
    temp[74]=lbl_804424B0[74]; lbl_804424B0[74]=lbl_80562B84;
    fn_801DCF0C();
    for(i=0;i<3;i++) for(j=0;j<24;j++) lbl_804424B0[i*24+j]=temp[i*24+j];
    lbl_804424B0[72]=temp[72]; lbl_804424B0[73]=temp[73]; lbl_804424B0[74]=temp[74];
}

extern int lbl_8055E99C;
extern int lbl_8055E9A0;
extern unsigned short lbl_80442708[];
extern float lbl_80562B64, lbl_80562B84, lbl_80562B78;
int fn_801DDA84(int *arg0, int arg1, float farg0, float farg1, float farg2) {
    int *state = (int *)lbl_8055E990;
    int ix, iz, tileX, tileZ, remX, remZ;
    int tile, node, count = 0, offset = 0;
    float x, z;
    float roundX, roundZ;
    float *map;

    if (state[4] == 0)
        return 0;
    x = farg0 + *(float *)((char *)state + 0);
    z = farg1 + *(float *)((char *)state + 4);
    x *= *(float *)((char *)state + 8);
    z *= *(float *)((char *)state + 12);
    roundX = x < lbl_80562B84 ? x - lbl_80562B64 : lbl_80562B64 + x;
    roundZ = z < lbl_80562B84 ? z - lbl_80562B64 : lbl_80562B64 + z;
    ix = (int)roundX;
    iz = (int)roundZ;
    if (ix < 0 || iz < 0)
        return 0;
    tileX = (ix >> 5) - lbl_8055E99C;
    tileZ = (iz >> 5) - lbl_8055E9A0;
    remX = ix - (tileX + lbl_8055E99C) * 32;
    remZ = iz - (tileZ + lbl_8055E9A0) * 32;
    if (tileX < 0 || tileZ < 0 || tileX >= 0x60 || tileZ >= 0x60)
        return 0;
    tile = lbl_80442708[tileX * 0x60 + tileZ];
    if (tile == 0xFFFF)
        return 0;
    node = *(int *)(*(int *)((char *)state + 0x18) + tile * 0x894);
    if (node == 0)
        return 0;
    if (*(int *)((char *)node + 0x890) < 0)
        return 0;
    map = (float *)(*(int *)((char *)state + 0x20) + *(int *)((char *)node + 0x890) * 0x810);
    do {
        unsigned short value = *(unsigned short *)((char *)map + (remX * 64 + remZ * 2) + 8);
        float h = fabsf(map[1] * ((float)value - lbl_80562B78) + map[0]);
        if (h < farg2 && count < arg1) {
            arg0[count++] = *(int *)((char *)map + 0x808);
        }
        node = *(int *)((char *)map + 0x80C);
        if (node < 0)
            break;
        map = (float *)(*(int *)((char *)lbl_8055E990 + 0x20) + node * 0x810);
    } while (1);
    return count;
}

#pragma push
#pragma paired_single off
#pragma opt_common_subs off
#pragma scheduling invalid_target
float fn_801DDC8C(float farg0, float farg1) {
    int *state = (int *)lbl_8055E990;
    int cellX;
    int cellZ;
    int tileX;
    int tileZ;
    int remX;
    int remZ;
    int tile;
    int node;
    int layerIndex;
    int sample;
    int weightIndex;
    int next;
    int i;
    float x;
    float z;
    float roundX;
    float roundZ;
    float value;
    float weight;
    float result;

    if (state[4] == 0)
        return lbl_80562B84;

    x = farg0 + *(float *)((char *)state + 0);
    z = farg1 + *(float *)((char *)state + 4);
    x *= *(float *)((char *)state + 8);
    z *= *(float *)((char *)state + 12);

    roundX = x < lbl_80562B84 ? x - lbl_80562B64 : lbl_80562B64 + x;
    roundZ = z < lbl_80562B84 ? z - lbl_80562B64 : lbl_80562B64 + z;
    cellX = (int)roundX;
    cellZ = (int)roundZ;
    if (cellX < 0 || cellZ < 0)
        return lbl_80562B84;

    tileX = (cellX >> 5) - lbl_8055E99C;
    tileZ = (cellZ >> 5) - lbl_8055E9A0;
    remX = cellX - ((cellX >> 5) << 5);
    remZ = cellZ - ((cellZ >> 5) << 5);
    if (tileX < 0 || tileZ < 0)
        return lbl_80562B84;
    if (tileX >= 0x60 || tileZ >= 0x60)
        return lbl_80562B84;

    tile = lbl_80442708[tileX * 0x60 + tileZ];
    if (tile == 0xFFFF)
        return lbl_80562B84;
    node = *(int *)(*(int *)((char *)state + 0x18) + tile * 0x894);
    if (node == 0)
        return lbl_80562B84;

    layerIndex = *(int *)((char *)node + 0x890);
    result = lbl_80562B84;
    if (layerIndex < 0)
        return result;

    do {
        char *layer = (char *)(*(int *)((char *)state + 0x20) + layerIndex * 0x810);
        weightIndex = *(int *)(layer + 0x808);
        sample = *(unsigned short *)(layer + (remX * 64 + remZ * 2) + 8);
        value = *(float *)(layer + 0) +
                *(float *)(layer + 4) * (float)sample;
        weight = lbl_804425DC[weightIndex];
        result += value * weight;
        next = *(int *)(layer + 0x80C);
        if (next < 0)
            break;
        layerIndex = next;
    } while (1);
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
