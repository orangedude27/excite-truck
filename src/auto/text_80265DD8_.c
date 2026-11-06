extern char lbl_80499080[];
typedef struct { float x, y, z; } V3_80267EF8;
typedef struct { V3_80267EF8 r[4]; } M34_80267EF8;
typedef struct { float m[9]; } R9_80267EF8;
typedef struct { float m[9]; V3_80267EF8 pos; } MP_80267EF8;
extern float lbl_80563C80, lbl_80563C84, lbl_80563C88, lbl_80563C64;
extern float lbl_8055F48C;
extern int fn_802E2C20(void);
extern void fn_80209190(int, float);
extern int fn_8000D75C(void);
extern void fn_801769EC(void);
extern void fn_8022FF10(void *, void *);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_80499E50[];
extern double lbl_80563C38;
extern int lbl_8055C4B4;
extern int lbl_8055C4B8;
extern float lbl_8055C4BC;
extern float lbl_80563C30;
extern void fn_80135DC4(void *, int, int);
extern float fn_80134E34(float);
extern void fn_80136468(int *, void *, float);
extern float lbl_80563C28;
extern float lbl_80563C9C;
extern char lbl_80499950[];
extern void fn_80128670(void);
extern void fn_8013530C(void *, int);
extern void fn_80268BD4(void *, int, float, float);

extern char lbl_8055F488;
extern float lbl_8055F484;
extern float lbl_80499980[8];
extern float lbl_80563C6C;
extern float lbl_80563C20;
void fn_802693F4(void);
extern void fn_80265E08(void*);
extern float lbl_80563C24;
extern float lbl_80563C44;
extern float lbl_80563C48;
extern float lbl_80563C2C;
extern float lbl_80563C34;
extern float lbl_80563C4C;
extern float lbl_80563C50;
extern float lbl_80563C98;
extern char lbl_80499920[];
extern float lbl_8055C4E0;
extern float lbl_8055C4E4;
extern int lbl_8055C4E8;
extern int lbl_8055C4EC;
extern int lbl_804999A0[];
extern float fn_80129DC4(int, float, float);
extern int fn_80129D90(int, int, int);
extern float PSVECMag(void*);
void* fn_80265DD8(void* arg0) {
    fn_80265E08(arg0);
    return arg0;
}

#pragma dont_inline on
void fn_80265E08(void* arg0) {
    float zero = lbl_80563C20;
    *(int*)((char*)arg0 + 0) = 0;
    *(float*)((char*)arg0 + 0x14) = zero;
    *(float*)((char*)arg0 + 0x10) = zero;
    *(float*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 4) = 0;
    *(int*)((char*)arg0 + 8) = 0;
}
#pragma dont_inline reset

#pragma dont_inline on
void fn_80265E2C(void) {
    #pragma scheduling invalid_target
    struct Record { float x; float y; int value; };
    float scale = lbl_80563C24;
    struct Record *record = (struct Record *)lbl_804999A0;
    int count = 0;

    do {
        record->x = scale * fn_80129DC4(6, -lbl_8055C4E0, lbl_8055C4E0);
        record->y = scale * fn_80129DC4(6, -lbl_8055C4E4, lbl_8055C4E4);
        {
            int value = fn_80129D90(6, lbl_8055C4E8, lbl_8055C4EC);
            count++;
            record->value = value;
        }
        record++;
    } while (count < 0x64);
}
#pragma dont_inline reset

#pragma scheduling invalid_target
void fn_80265EC4(void *arg0, int arg1, int arg2) {
    struct Record { float first; float second; int duration; };
    int *state = (int *)arg0;
    int index;
    int elapsed;
    int duration;
    int nextIndex;
    int updatedElapsed;
    float ratio;
    float weight;
    struct Record *current;
    struct Record *next;

    if (arg2 != 0) {
        state[2] = arg1;
        return;
    }
    state[1] = state[1] + (arg1 - state[2]);
    state[2] = arg1;
    goto check;

advance:
    index = *(volatile int *)arg0;
    elapsed = *(volatile int *)((char *)arg0 + 4);
    nextIndex = (index + 1) % 100;
    updatedElapsed = elapsed - duration;
    *(volatile int *)((char *)arg0 + 4) = updatedElapsed;
    *(volatile int *)arg0 = nextIndex;

check:
    index = *(volatile int *)arg0;
    elapsed = *(volatile int *)((char *)arg0 + 4);
    duration = ((struct Record *)lbl_804999A0)[index].duration;
    if (elapsed > duration) {
        goto advance;
    }

    ratio = (float)elapsed / (float)duration;
    if (ratio < lbl_80563C28) {
        weight = lbl_80563C28;
        goto weight_done;
    }
    if (ratio > lbl_80563C2C) {
        weight = lbl_80563C2C;
    } else if (ratio > lbl_80563C20) {
        weight = (((lbl_80563C30 * ratio) * ratio) * ratio) +
                 ((lbl_80563C34 * ratio) * ratio);
    } else {
        weight = (((lbl_80563C30 * ratio) * ratio) * ratio) -
                 ((lbl_80563C34 * ratio) * ratio);
    }
weight_done:
    *(float *)((char *)arg0 + 0xC) = weight;
    index = *(volatile int *)arg0;
    nextIndex = (index + 1) % 100;
    current = &((struct Record *)lbl_804999A0)[index];
    next = &((struct Record *)lbl_804999A0)[nextIndex];
    *(float *)((char *)arg0 + 0x10) =
        current->first + (float)(double)weight * (next->first - current->first);
    *(float *)((char *)arg0 + 0x14) =
        current->second + (float)(double)weight * (next->second - current->second);
}
#pragma scheduling on
void fn_80266070(void *arg0, void *arg1, void *arg2, void *arg3) {
    volatile float scaled[3];
    float mag;
    float f;
    float y;
    float xOut;
    float yOut;
    float zOut;
    float *out = (float *)arg1;
    float *base = (float *)arg2;
    float scale = *(float *)((char *)arg0 + 0x10);
    scaled[0] = *(float *)((char *)arg3 + 0) * scale;
    scaled[1] = *(float *)((char *)arg3 + 4) * scale;
    scaled[2] = *(float *)((char *)arg3 + 8) * scale;
    mag = PSVECMag(arg3);
    f = *(float *)((char *)arg0 + 0x14) * mag;
    y = scaled[1] + f;
    xOut = base[0] + scaled[0];
    yOut = base[1] + y;
    zOut = base[2] + scaled[2];
    out[0] = xOut;
    out[1] = yOut;
    out[2] = zOut;
}

extern float lbl_8055C4C0;
extern float lbl_80563C2C;
extern float lbl_8055C4C4;
extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
void fn_80266150(void *arg0);
int fn_80178CA4(void);
float PSQUATMultiply(float *arg0, int arg1);
void *fn_80266120(void *arg0) {
    fn_80266150(arg0);
    return arg0;
}

#pragma dont_inline on
void fn_80266150(void *arg0) {
    *(float *)((char *)arg0 + 0xC) = lbl_80563C2C;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 0) = 0;
    *(float *)((char *)arg0 + 8) = lbl_8055C4C0;
}
#pragma dont_inline reset

void fn_80266170(void *arg0, int arg1, int arg2, int arg3, float farg0) {
    float temp_f0;
    float temp_f0_2;
    float var_f3;
    float temp_f4;
    float var_f0;
    register float var_f4;
    int temp_r0_2;
    int temp_r0;

    if (arg3 != 0) {
        register float reset_scale;
        register float reset_limit;
        *(int *)((char *)arg0 + 0) = arg1;
        *(int *)((char *)arg0 + 4) = 0;
        reset_scale = lbl_8055C4BC;
        reset_limit = lbl_8055C4C0;
        var_f0 = reset_scale * farg0;
        var_f0 = (var_f0 < reset_limit) ? var_f0 : reset_limit;
        *(float *)((char *)arg0 + 8) = var_f0;
    }
    if (arg2 != 0) {
        *(int *)((char *)arg0 + 0) = arg1;
        return;
    }
    temp_r0 = *(int *)((char *)arg0 + 0);
    temp_r0_2 = *(int *)((char *)arg0 + 4);
    temp_r0 = arg1 - temp_r0;
    *(int *)((char *)arg0 + 0) = arg1;
    temp_r0 = temp_r0_2 + temp_r0;
    *(int *)((char *)arg0 + 4) = temp_r0;
    var_f4 = lbl_80563C2C;
    temp_f0 = (float)lbl_8055C4B4;
    temp_f0_2 = ((float)temp_r0 - temp_f0) / ((float)lbl_8055C4B8 - temp_f0);
    var_f4 = (var_f4 < temp_f0_2) ? var_f4 : temp_f0_2;
    var_f4 = (var_f4 > lbl_80563C20) ? var_f4 : lbl_80563C20;
    var_f3 = lbl_80563C28;
    temp_f4 = lbl_80563C20 + (var_f4 * lbl_80563C2C);
    if (temp_f4 < var_f3) {
    } else if (temp_f4 > lbl_80563C2C) {
        var_f3 = lbl_80563C2C;
    } else if (temp_f4 > lbl_80563C20) {
        var_f3 = (temp_f4 * (lbl_80563C30 * temp_f4 * temp_f4)) +
                 (lbl_80563C34 * temp_f4 * temp_f4);
    } else {
        var_f3 = (temp_f4 * (lbl_80563C30 * temp_f4 * temp_f4)) -
                 (lbl_80563C34 * temp_f4 * temp_f4);
    }
    *(float *)((char *)arg0 + 0xC) = var_f3;
}

void fn_802662D8(float *arg0, float *arg1, float *arg2, float *arg3, int arg4) {
    float t;
    float weight;
    float factor;
    float x;
    float y;
    float z;

    t = PSQUATMultiply(arg2, arg4) - lbl_8055C4C4;
    weight = arg0[3];
    t = t - lbl_80563C20;
    factor = lbl_80563C20 + weight * t;
    x = arg2[0] + arg3[0] * factor;
    y = arg2[1] + arg3[1] * factor;
    z = arg2[2] + arg3[2] * factor;
    arg1[0] = x;
    arg1[1] = y;
    arg1[2] = z;
}

#pragma dont_inline on
void fn_802670A0(int *arg0, int arg1) {
    int count;
    int cols;
    int div;
    int a;
    int b;

    count = fn_80178CA4();
    cols = (count > 1) ? 2 : 1;
    div = (count + cols - 1) / cols;
    a = lbl_8055CFF0 / cols;
    b = lbl_8055CFF4 / div;
    arg0[16] = a;
    arg0[17] = b;
    arg0[14] = a * (arg1 / div);
    arg0[15] = b * (arg1 % div);
}

#pragma scheduling invalid_target
void fn_80267130(void *arg0) {
    float value;
    float clamp;
    clamp = lbl_80563C2C;
    value = (*(float *)((char *)arg0 + 0x30) - lbl_80563C44) / lbl_80563C48;
    clamp = clamp < value ? value : clamp;
    clamp = clamp > lbl_80563C20 ? lbl_80563C20 : clamp;
    *(float *)((char *)arg0 + 0x48) = lbl_80563C34 + clamp * lbl_80563C4C;
    if (fn_80178CA4() == 1) value = lbl_80563C2C;
    else value = lbl_80563C50;
    *(float *)((char *)arg0 + 0x4C) = lbl_8055F484 * value;
}
#pragma scheduling on
extern float lbl_8055D020;
extern double lbl_80563C38;
extern float fn_801EA0E8(float, float);
#pragma push
#pragma ppc_psq_save off
void fn_802671CC(void *arg0, int arg1) {
    union IntDouble {
        double value;
        unsigned int word[2];
    };
    struct Scratch {
        float output[3];
        float input[3];
        union IntDouble width;
        union IntDouble height;
    } scratch;
    float *in = scratch.input;
    float *out = scratch.output;
    float *matrix;
    unsigned int widthBits;
    unsigned int heightBits;
    float z;
    float delta;
    float xstep;
    float widthValue;
    float heightValue;
    float ystep;
    float best;
    double bias;
    int i;

    widthBits = *(unsigned int *)((char *)arg0 + 0x44) ^ 0x80000000;
    heightBits = *(unsigned int *)((char *)arg0 + 0x40) ^ 0x80000000;
    scratch.width.word[0] = 0x43300000;
    scratch.width.word[1] = widthBits;
    matrix = (float *)arg0;
    z = *(float *)((char *)arg0 + 0x48);
    delta = z * *(float *)((char *)arg0 + 0x34);
    xstep = delta / lbl_8055D020;
    scratch.height.word[1] = heightBits;
    scratch.height.word[0] = 0x43300000;
    bias = lbl_80563C38;
    widthValue = (float)(scratch.width.value - bias);
    heightValue = (float)(scratch.height.value - bias);
    ystep = widthValue * delta / heightValue;
    best = lbl_80563C20;
    i = 0;

    for (; i < 4; i++) {
        float x;
        float y;
        float heightDiff;

        if ((i & 1) != 0) x = xstep;
        else x = -xstep;
        if ((i & 2) != 0) y = ystep;
        else y = -ystep;

        in[0] = x;
        in[1] = y;
        in[2] = z;
        if (out == in) {
            out[0] = x * matrix[0] + y * matrix[3] + z * matrix[6];
            out[1] = x * matrix[1] + y * matrix[4] + z * matrix[7];
            out[2] = x * matrix[2] + y * matrix[5] + z * matrix[8];
        } else {
            out[0] = in[0] * matrix[0] + in[1] * matrix[3] + in[2] * matrix[6];
            out[1] = in[0] * matrix[1] + in[1] * matrix[4] + in[2] * matrix[7];
            out[2] = in[0] * matrix[2] + in[1] * matrix[5] + in[2] * matrix[8];
        }
        out[0] += matrix[9];
        out[1] += matrix[10];
        out[2] += matrix[11];
        heightDiff = fn_801EA0E8(out[0], out[2]) - out[1];
        if (best > heightDiff) best = heightDiff;
    }

    if (*(int *)((char *)arg0 + 0x58) != 0x11 &&
        *(int *)((char *)arg0 + 0x58) != 0x15) {
        *(float *)((char *)arg0 + 0x28) += best;
    }
    (void)arg1;
}
#pragma pop
#pragma dont_inline reset

extern int fn_8026A554(int *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_80267420(void) {
    extern void *__AXFXGetLfoSinTable_801769CC(void);
    extern float lbl_80563C54;
    extern int lbl_8055F494;
    extern void *lbl_8055F490;
    extern char lbl_803467D0[], lbl_803467DC[];
    extern void fn_80276B8C(void), fn_80278214(void), fn_80273354(void), fn_8027045C(void);
    extern void fn_80267680(void), fn_80268D94(void), fn_80268E00(void);
    extern int fn_802090D4(void *);
    extern void *fn_80207848(void *, int);
    extern void fn_801EEFDC(void *, int);
    extern void *memset(void *, int, unsigned long);
    struct M33 { float m[9]; };
    struct V3 { float v[3]; };
    char *p;
    float angle, one, zero;
    int i;

    __AXFXGetLfoSinTable_801769CC();
    zero = lbl_80563C20;
    one = lbl_80563C2C;
    p = lbl_80499080;
    angle = lbl_80563C54;
    for (i = 0; i < 4; i++, p += 0x228) {
        memset(p, 0, 0x228);
        *(int *)(p + 0x0) = i;
        *(float *)(p + 0x8) = zero;
        *(float *)(p + 0xC) = zero;
        *(int *)(p + 0x24) = 0;
        *(int *)(p + 0x20) = 0;
        *(int *)(p + 0x14) = 10;
        *(int *)(p + 0x10) = 10;
        *(float *)(p + 0x28) = zero;
        *(float *)(p + 0x2C) = one;
        *(float *)(p + 0x30) = zero;
        *(float *)(p + 0x34) = zero;
        *(float *)(p + 0x38) = zero;
        *(float *)(p + 0x3C) = zero;
        *(char *)(p + 0x138) = 1;
        *(float *)(p + 0x58) = one;
        *(float *)(p + 0x5C) = zero;
        *(float *)(p + 0x60) = zero;
        *(float *)(p + 0x64) = zero;
        *(float *)(p + 0x68) = one;
        *(float *)(p + 0x6C) = zero;
        *(float *)(p + 0x70) = zero;
        *(float *)(p + 0x74) = zero;
        *(float *)(p + 0x78) = one;
        *(float *)(p + 0x7C) = zero;
        *(float *)(p + 0x80) = zero;
        *(float *)(p + 0x84) = zero;
        *(struct M33 *)(p + 0x88) = *(struct M33 *)(p + 0x58);
        *(struct V3 *)(p + 0xAC) = *(struct V3 *)(p + 0x7C);
        *(float *)(p + 0x120) = zero;
        *(float *)(p + 0x124) = zero;
        *(float *)(p + 0x128) = zero;
        *(float *)(p + 0x12C) = zero;
        *(float *)(p + 0x130) = zero;
        *(float *)(p + 0x134) = zero;
        *(float *)(p + 0xF0) = one;
        *(float *)(p + 0xF4) = zero;
        *(float *)(p + 0xF8) = zero;
        *(float *)(p + 0xFC) = zero;
        *(float *)(p + 0x100) = one;
        *(float *)(p + 0x104) = zero;
        *(float *)(p + 0x108) = zero;
        *(float *)(p + 0x10C) = zero;
        *(float *)(p + 0x110) = one;
        *(float *)(p + 0x114) = zero;
        *(float *)(p + 0x118) = zero;
        *(float *)(p + 0x11C) = zero;
        *(float *)(p + 0xC0) = one;
        *(float *)(p + 0xC4) = zero;
        *(float *)(p + 0xC8) = zero;
        *(float *)(p + 0xCC) = zero;
        *(float *)(p + 0xD0) = one;
        *(float *)(p + 0xD4) = zero;
        *(float *)(p + 0xD8) = zero;
        *(float *)(p + 0xDC) = zero;
        *(float *)(p + 0xE0) = one;
        *(float *)(p + 0xE4) = zero;
        *(float *)(p + 0xE8) = zero;
        *(float *)(p + 0xEC) = zero;
        *(int *)(p + 0x140) = 0;
        *(int *)(p + 0x144) = 0;
        *(int *)(p + 0x4) = 10;
        *(int *)(p + 0x1C) = 10;
        *(float *)(p + 0x1A4) = one;
        *(float *)(p + 0x1A8) = zero;
        *(float *)(p + 0x1AC) = zero;
        *(float *)(p + 0x1B0) = zero;
        *(float *)(p + 0x1B4) = one;
        *(float *)(p + 0x1B8) = zero;
        *(float *)(p + 0x1BC) = zero;
        *(float *)(p + 0x1C0) = zero;
        *(float *)(p + 0x1C4) = one;
        *(float *)(p + 0x1C8) = zero;
        *(float *)(p + 0x1CC) = zero;
        *(float *)(p + 0x1D0) = zero;
        *(float *)(p + 0x1D4) = angle;
    }
    fn_80276B8C();
    fn_80268D94();
    fn_80268E00();
    fn_80278214();
    fn_80273354();
    fn_8027045C();
    lbl_8055F494 = fn_802090D4(lbl_803467D0);
    lbl_8055F490 = fn_80207848(lbl_803467DC, 0);
    fn_801EEFDC((void *)fn_8026A554, 0xD);
    fn_80267680();
}
#pragma pop

#pragma scheduling invalid_target
#pragma push
#pragma optimize_for_size on
#pragma use_lmw_stmw on
void fn_80267680(void) {
    extern float lbl_80563C54, lbl_80563C58, lbl_80563C5C, lbl_80563C60, lbl_80563C64;
    extern int lbl_8055F494;
    extern float lbl_8055F48C;
    extern void fn_802733C8(void);
    extern int fn_80276BE4(int, int);
    extern void fn_801E9DC4(int *);
    extern void fn_80209190(int, float);
    extern void fn_80268B94(int);
    extern void fn_80270484(void);
    struct StackData {
        float matrix[12];
        union { double d; unsigned int word[2]; } value;
    };
    char *p;
    volatile struct StackData temp;
    unsigned int high;
    int oneInt, minusOne, zeroInt, i;
    float bottom, limit;
    double conversionConstant;
    float start, angle, one, zero;
    fn_802733C8();
    zero = lbl_80563C20;
    one = lbl_80563C2C;
    p = lbl_80499080;
    angle = lbl_80563C54;
    i = 0;
    start = lbl_80563C58;
    conversionConstant = lbl_80563C38;
    zeroInt = 0;
    limit = lbl_80563C5C;
    minusOne = -1;
    bottom = lbl_80563C60;
    oneInt = 1;
    high = 0x43300000;
    do {
        *(float *)(p + 8) = zero;
        *(float *)(p + 0xC) = zero;
        *(int *)(p + 0x144) = zeroInt;
        *(int *)(p + 0xB8) = minusOne;
        *(unsigned char *)(p + 0x138) = (unsigned char)oneInt;
        *(unsigned char *)(p + 0x139) = (unsigned char)oneInt;
        *(float *)(p + 0x13C) = zero;
        *(float *)(p + 0x40) = zero;
        *(float *)(p + 0x44) = zero;
        *(float *)(p + 0x48) = zero;
        *(float *)(p + 0x28) = zero;
        *(float *)(p + 0x2C) = one;
        *(float *)(p + 0x30) = zero;
        *(int *)(p + 0x148) = zeroInt;
        *(float *)(p + 0x194) = angle;
        fn_80265E08(p + 0x160);
        fn_80266150(p + 0x178);
        temp.value.word[0] = high;
        temp.value.word[1] = ((unsigned int)i) ^ 0x80000000;
        *(float *)(p + 0x158) = start;
        *(float *)(p + 0x15C) = temp.value.d - conversionConstant;
        *(float *)(p + 0x198) = zero;
        *(float *)(p + 0x19C) = zero;
        *(int *)(p + 0x14C) = minusOne;
        *(int *)(p + 0x150) = minusOne;
        if (fn_801796B4() == 0) {
            temp.matrix[0] = one;
            temp.matrix[1] = zero;
            temp.matrix[2] = zero;
            temp.matrix[3] = zero;
            temp.matrix[4] = one;
            temp.matrix[5] = zero;
            temp.matrix[6] = zero;
            temp.matrix[7] = zero;
            temp.matrix[8] = one;
            temp.matrix[9] = zero;
            temp.matrix[10] = zero;
            temp.matrix[11] = zero;
            fn_80276BE4((int)(p + 0x1A4), (int)(p + 0x1D4));
        }
        fn_801E9DC4((int *)(p + 0x1EC));
        *(float *)(p + 0x1F8) = one;
        ++i;
        *(float *)(p + 0x1FC) = zero;
        *(float *)(p + 0x200) = zero;
        *(float *)(p + 0x204) = zero;
        *(float *)(p + 0x208) = one;
        *(float *)(p + 0x20C) = zero;
        *(float *)(p + 0x210) = zero;
        *(float *)(p + 0x214) = zero;
        *(float *)(p + 0x218) = one;
        *(float *)(p + 0x21C) = zero;
        *(float *)(p + 0x220) = zero;
        *(float *)(p + 0x224) = zero;
        *(float *)(p + 0x1F4) = limit;
        *(float *)(p + 0x1F0) = bottom;
        p += 0x228;
    } while (i < 4);
    lbl_8055F488 = 0;
    lbl_8055F48C = lbl_80563C64;
    fn_80209190(lbl_8055F494, lbl_80563C2C);
    fn_80265E2C();
    fn_80268B94(0);
    fn_80270484();
    zero = lbl_80563C20;
    {
        float *out = lbl_80499980;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
        *out++ = zero;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw reset
#pragma pop
extern void *lbl_8055F490;
extern int lbl_8055F494;
extern void *fn_80267EE4(int);
extern void fn_801EF024(void *);
extern void fn_80278288(void);
extern void fn_802733F0(void);
extern void fn_80209110(void *);
extern float lbl_8055E3C8;
void *fn_802678E4(int arg0) {
    return fn_80267EE4(arg0);
}

extern void fn_80267EE0(void);
extern int fn_801C5B68(void *, int);
extern void fn_8026B768(int, int), fn_80268E94(void *, int), fn_8020655C(void *, int);
extern void *fn_8017960C(int);
extern int fn_801769F8(void), fn_8026B734(int, float *);
extern float fn_801B8950(int), PSVECDotProduct(void *, void *);
extern double fn_8002EF30(float), fabs(double);
extern int lbl_8055E3C4;
extern char lbl_8055F480;
extern float lbl_8055E460, lbl_80563C68, lbl_80563C70, lbl_80563C74, lbl_80563C78, lbl_80563C7C;
#pragma push
#pragma inline off
void fn_802678E8(void *arg0, int arg1) {
 struct Frame { unsigned char flag; char gap0[3]; float height; char gap1[4]; float y; char gap2[12]; float z; int object; void *matrix; void *extra; float x; char gap3[8]; MP_80267EF8 transform; } frame;
 char *p, *entity; int flags, i; float height, t;
 fn_802670A0(arg0, arg1);
 if (fn_801C5B68(arg0,arg1)) { fn_80267130(arg0); return; }
 p = fn_80267EE4(arg1);
 *(float *)(p+0x1a0) = lbl_80563C28;
 fn_8026B768(*(int *)(p+0x20), arg1);
 if (lbl_8055E3C4 != *(int *)(p+0xb8)) {
   *(MP_80267EF8 *)(p+0x88) = *(MP_80267EF8 *)(p+0x58);
   *(int *)(p+0xb8) = lbl_8055E3C4;
 }
 if (*(int *)(p+0x14) < 0 || *(int *)(p+0x14) >= 0x22) *(int *)(p+0x14) = 4;
 *(int *)((char *)arg0+0x5c) = *(int *)(p+0x1c);
 lbl_8055F480 = 0;
 *(int *)(p+0x20) = *(int *)(p+0x24);
 *(int *)(p+0x10) = *(int *)(p+0x14);
 *(float *)(p+0xbc) = lbl_80563C68;
 *(void **)(p+0x140) = fn_8017960C(*(int *)(p+0x20));
 frame.x = *(float *)(p+0x7c); frame.flag = 0; frame.y = *(float *)(p+0x80); frame.z = *(float *)(p+0x84);
 entity = *(char **)(p+0x140);
 if (entity) {
   ((void (*)(void *, void *, int))fn_802693F4)(p, &frame.flag, arg1);
   flags = ((int (*)(int))fn_80267EE0)(*(int *)(p+0x10));
   if (*(unsigned char *)(*(char **)(p+0x140)+0x260c)) flags |= 0x20;
 } else flags = ((int (*)(int))fn_80267EE0)(*(int *)(p+0x10));
 fn_80268E94(p,arg1);
 frame.object = *(int *)(p+0x20); frame.matrix = p+0x58; frame.extra = p+0x120;
 fn_8020655C(&frame.object,arg1);
 if (*(int *)(p+0x10) != 0x11) {
   float *out = (float *)&frame.transform;
   float *cur = (float *)(p+0x58), *prev = (float *)(p+0x88);
   for (i=0;i<2;i++) {
     out[0]=prev[0]+lbl_8055E460*(cur[0]-prev[0]); out[1]=prev[1]+lbl_8055E460*(cur[1]-prev[1]);
     out[2]=prev[2]+lbl_8055E460*(cur[2]-prev[2]); out[3]=prev[3]+lbl_8055E460*(cur[3]-prev[3]);
     out[4]=prev[4]+lbl_8055E460*(cur[4]-prev[4]); out[5]=prev[5]+lbl_8055E460*(cur[5]-prev[5]);
     out+=6; cur+=6; prev+=6;
   }
   *(MP_80267EF8 *)arg0 = frame.transform;
 } else *(MP_80267EF8 *)arg0 = *(MP_80267EF8 *)(p+0x58);
 *(float *)((char *)arg0+0x30) = *(float *)(p+0xbc);
 *(float *)((char *)arg0+0x34) = fn_8002EF30(lbl_80563C6C * *(float *)(p+0xbc));
 if (fn_801769F8() == 0) {
   if (fn_8026B734(*(int *)(p+0x20), &frame.height)) height = frame.height;
   else {
     int mode = *(int *)(p+0x10);
     if ((mode >= 0 && mode < 10) || mode == 14) {
       frame.height = fn_801B8950(*(int *)(p+0x20));
       t = ((float)fabs(PSVECDotProduct(p+0x70,p+0xd8))-lbl_80563C70)/lbl_80563C74;
       if (lbl_80563C2C < t) t = lbl_80563C2C;
       if (t < lbl_80563C20) t = lbl_80563C20;
       height = frame.height * (lbl_80563C2C + t*lbl_80563C78);
     } else height = lbl_80563C20;
   }
 } else height = lbl_80563C20;
 *(float *)((char *)arg0+0x50) = height;
 *(float *)((char *)arg0+0x54) = *(float *)(p+0x1a0);
 if (*(unsigned char *)(p+0x138)) flags |= 0x10;
 *(char *)(p+0x138)=0; *(char *)(p+0x139)=0;
 *(int *)((char *)arg0+0x58)=*(int *)(p+0x10);
 *(int *)((char *)arg0+0x60)=*(int *)(p+0x20);
 *(int *)((char *)arg0+0x68)=flags;
 if (frame.flag) *(short *)((char *)arg0+0x64)=*(short *)(p+0x1ec);
 else *(short *)((char *)arg0+0x64)=*(short *)(*(char **)(p+0x140)+0x6c);
 if (!fn_801769F8()) {
   float *q=lbl_80499980; float dec=lbl_80563C7C, zero=lbl_80563C20;
   for (i=0;i<2;i++) {
     t=q[0]-dec; if (t<zero) t=zero; q[0]=t;
     t=q[1]-dec; if (t<zero) t=zero; q[1]=t;
     t=q[2]-dec; if (t<zero) t=zero; q[2]=t;
     t=q[3]-dec; if (t<zero) t=zero; q[3]=t;
     q+=4;
   }
 }
 fn_80267130(arg0); ((void (*)(void *))fn_802671CC)(arg0);
}
#pragma pop
void fn_80267E40(unsigned int arg0, float arg1, int arg2) {
    float temp_f29;
    float temp_f30;
    float temp_f31;
    int i;
    void *p;
    temp_f29 = lbl_8055E3C8;
    temp_f30 = lbl_80563C6C;
    temp_f31 = lbl_80563C2C;
    for (i = 0; i < 4; i++) {
        p = fn_80267EE4(i);
        if (*(unsigned int *)((char *)p + 0x140) == arg0) {
            if (arg1 > *(float *)((char *)p + 0x154) * (temp_f31 - ((temp_f29 - *(float *)((char *)p + 0x158)) / temp_f30))) {
                *(float *)((char *)p + 0x158) = temp_f29;
                *(float *)((char *)p + 0x154) = arg1;
                return;
            }
        }
    }
}

extern void fn_802734F0(void);
extern char lbl_80499080[];
extern float lbl_80499050[];
extern float lbl_8055F47C;
extern void fn_801BFD34(void *, void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern int lbl_8055F4A0;
extern int lbl_8055F4A4;
extern int lbl_8055F4A8;
extern void fn_801E9DC4(int *);
void fn_80267EE0(void) {
    fn_802734F0();
}

void *fn_80267EE4(int arg0) {
    return lbl_80499080 + arg0 * 0x228;
}

#pragma push
#pragma processor 750
void fn_80267EF8(void *arg0) {
    char *p = (char *)arg0;
    float t = lbl_80563C80 * (float)fn_802E2C20() - lbl_8055F48C;
    if (t > lbl_80563C34) {
        lbl_8055F488 = 0;
        lbl_8055F48C = lbl_80563C64;
        fn_80209190(lbl_8055F494, lbl_80563C2C);
        if (fn_8000D75C() == 0) {
            fn_801769EC();
        }
    } else {
        float ratio = t / lbl_80563C34;
        float f = lbl_80563C20;
        float w;
        float s;
        MP_80267EF8 a, b, c;
        V3_80267EF8 axis;
        char tmp[0x24];
        if (t < lbl_80563C6C) {
            float q = t / lbl_80563C6C;
            f = lbl_80563C2C + q * lbl_80563C28;
        } else if (t > lbl_80563C84) {
            float q = (t - lbl_80563C84) / lbl_80563C6C;
            f += q * lbl_80563C2C;
        }
        fn_80209190(lbl_8055F494, f);
        s = lbl_80563C2C - f;
        {
            char *o = (char *)lbl_8055F490;
            if (s != *(float *)(o + 8)) {
                *(char *)(o + 0x4d) = 1;
                *(float *)(o + 8) = s;
            }
        }
        if (ratio < lbl_80563C28) {
            w = lbl_80563C28;
        } else if (ratio > lbl_80563C2C) {
            w = lbl_80563C2C;
        } else if (ratio > lbl_80563C20) {
            w = (((lbl_80563C30 * ratio) * ratio) * ratio) + ((lbl_80563C34 * ratio) * ratio);
        } else {
            w = (((lbl_80563C30 * ratio) * ratio) * ratio) - ((lbl_80563C34 * ratio) * ratio);
        }
        *(R9_80267EF8 *)&a = *(R9_80267EF8 *)(p + 0x58);
        a.pos = *(V3_80267EF8 *)(p + 0x7c);
        w = lbl_80563C24 * (lbl_80563C20 + w * lbl_80563C88);
        *(R9_80267EF8 *)&b = *(R9_80267EF8 *)(p + 0xc0);
        b.pos = *(V3_80267EF8 *)(p + 0xe4);
        f = PSQUATMultiply((float *)&b.pos, (int)&a.pos);
        ((double *)&c)[0] = ((double *)&a)[0];
        ((double *)&c)[1] = ((double *)&a)[1];
        ((double *)&c)[2] = ((double *)&a)[2];
        ((double *)&c.m[6])[0] = ((double *)&a.m[6])[0];
        *(int *)&c.m[8] = *(int *)&a.m[8];
        ((double *)&c.pos)[0] = ((double *)&a.pos)[0];
        *(int *)&c.pos.z = *(int *)&a.pos.z;
        c.pos.x = c.pos.x + c.m[6] * f;
        c.pos.y = c.pos.y + c.m[7] * f;
        c.pos.z = c.pos.z + c.m[8] * f;
        axis.x = lbl_80563C20;
        axis.y = w;
        axis.z = lbl_80563C20;
        fn_8022FF10(tmp, &axis);
        fn_80015B20(&c, &c, tmp);
        f = -f;
        c.pos.x = c.pos.x + c.m[6] * f;
        c.pos.y = c.pos.y + c.m[7] * f;
        c.pos.z = c.pos.z + c.m[8] * f;
        *(R9_80267EF8 *)(p + 0x58) = *(R9_80267EF8 *)&c;
        *(V3_80267EF8 *)(p + 0x7c) = c.pos;
    }
}
#pragma pop
void fn_802682B0(void *arg0) {
    char *p = (char *)arg0;
    float *base;
    if (*(unsigned char *)(p + 0x138) != 0) {
        float b;
        float a;
        float *q;
        a = lbl_80563C2C;
        q = lbl_80499050 - 1;
        b = lbl_80563C20;
        *++q = a;
        q[1] = b; q[2] = b; q[3] = b;
        q[4] = a;
        q[5] = b; q[6] = b; q[7] = b;
        q[8] = a;
        q[9] = b; q[10] = b; q[11] = b;
    }
    base = lbl_80499050;
    fn_801BFD34(p + 0x7c, base + 9, p + 0xc0);
    fn_80015B20(p + 0x58, base, p + 0xc0);
    *(float *)(p + 0xbc) = lbl_8055F47C;
}

void fn_80268B94(int arg0) {
    lbl_8055F4A0 = arg0;
    lbl_8055F4A4 = arg0;
    fn_801E9DC4(&lbl_8055F4A8);
}

extern char lbl_80499920[];
extern float lbl_80563C44, lbl_80563C48, lbl_80563C2C, lbl_80563C34, lbl_80563C4C, lbl_80563C50;
extern float lbl_80563C98;
extern int fn_80178CA4(void);
int fn_80268BA4(int arg0) {
    unsigned int shift = arg0 - 4;
    int result = 0;
    if (shift > 0x13)
        goto done;
    if (!((1U << shift) & 0x80037))
        goto done;
    result = 1;
done:
    return result;
}

extern float lbl_80563C20, lbl_80563C2C, lbl_80563C8C, lbl_80563C90, lbl_80563C94;
extern float fn_8002F234(void*, float, float, float, float, float, float, float, float);
extern void fn_801EA140(void*, float, float, float, float, float, float, float);
extern void PSVECCrossProduct(void*, void*, void*);
extern double cos(float);
extern double sin(float);
#pragma push
#pragma processor 750
void fn_80268BD4(void *out, int arg1, float t, float angle) {
    float *inp = (float *)arg1;
    float *b = *(float **)((char *)inp + 0x14);
    volatile float sp[4];
    float x;
    float y;
    float z;
    float w;
    float scale;
    float xScaled;
    float yScaled;
    float rotation;
    float cosine;
    float sine;

    x = inp[2] + t * (b[2] - inp[2]);
    sp[0] = x;
    y = inp[3] + t * (b[3] - inp[3]);
    sp[1] = y;
    z = inp[0] + t * (b[0] - inp[0]);
    w = inp[1] + t * (b[1] - inp[1]);
    sp[2] = z;
    sp[3] = w;

    scale = lbl_80563C2C /
        (float)((double (*)(void *, float, float, float, float, float, float, float, float))fn_8002F234)(
            out, x * x + y * y, x * x, t * (b[1] - inp[1]),
            z, inp[0], inp[1], y, x);
    xScaled = sp[0] * scale;
    yScaled = sp[1] * scale;
    sp[0] = yScaled;
    sp[1] = -xScaled;

    *(float *)((char *)out + 0x28) = lbl_80563C20;
    rotation = lbl_80563C8C * inp[10] - lbl_80563C90;
    *(float *)((char *)out + 0x24) = sp[2] + yScaled * rotation;
    *(float *)((char *)out + 0x2C) = sp[3] + sp[1] * rotation;
    fn_801EA140((char *)out + 0x24, sp[3],
                sp[2] + yScaled * rotation, yScaled * rotation,
                rotation, sp[1], yScaled, xScaled);
    *(float *)((char *)out + 0x28) += lbl_80563C94;

    cosine = (float)cos(angle);
    sine = (float)sin(angle);
    *(float *)((char *)out + 0xC) = lbl_80563C20;
    *(float *)((char *)out + 0x10) = lbl_80563C2C;
    *(float *)((char *)out + 0x14) = lbl_80563C20;
    *(float *)((char *)out + 0x18) = yScaled * cosine - sp[1] * sine;
    *(float *)((char *)out + 0x1C) = lbl_80563C20;
    *(float *)((char *)out + 0x20) = yScaled * sine + sp[1] * cosine;
    PSVECCrossProduct((char *)out + 0xC, (char *)out + 0x18, out);
}
#pragma pop
void fn_80268D94(void) {
    struct {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        int g;
        int h;
        int i;
        int j;
        int k;
        int l;
        int m;
        int n;
        int o;
        int p;
        int q;
        int r;
        int s;
    } sp8;
    int sp58;
    fn_80135DC4(&sp8, 0, 0);
    fn_80268BD4(lbl_80499920, *(int *)&sp8 + 0x1c, lbl_80563C20, lbl_80563C98);
    if (sp58 != 0) {
        fn_80128670();
    }
    sp58 = 0;
    fn_8013530C(&sp8, 0);
}

void fn_80268E00(void) {
    #pragma scheduling invalid_target
    struct Result {
        int value;
        float fraction;
        int mode;
        int padding;
    } result;
    struct Object {
        char pad2c[0x2C];
        void *context;
        char pad30[0x20];
        int resource;
        int field54;
        int field58;
    } object;

    fn_80135DC4(&object, 0, 0);
    fn_80136468((int *)&result, &object, fn_80134E34(lbl_80563C28));
    if (result.value == 0) {
        result.value = *(int *)((char *)object.context + 0x1C);
    }
    fn_80268BD4(lbl_80499950, result.value, result.fraction, lbl_80563C9C);
    if (object.resource != 0) {
        ((void (*)(int))fn_80128670)(object.resource);
    }
    object.resource = 0;
    fn_8013530C(&object, 0);
}

#pragma dont_inline on
void fn_8026A248(int arg0, int arg1) {
    *(int *)((char *)fn_80267EE4(arg1) + 0x24) = arg0;
}
extern void fn_802735F4(int, int);
extern void fn_80135DC4(void *, int, int);
extern float fn_80134E34(float);
extern void fn_80136468(int *, void *, float);
extern void fn_80128670(void);
extern void fn_8013530C(void *, int);
extern void fn_80268BD4(void *, int, float, float);
extern float lbl_80563C28;
extern float lbl_80563C9C;
extern char lbl_80499950[];
#pragma push
#pragma scheduling invalid_target
int fn_8026A27C(int arg0) {
    int value = lbl_80499E50[arg0];
    lbl_80499E50[arg0] = 0;
    return value;
}
#pragma pop
void fn_8026A298(int arg0) {
    lbl_80499E50[arg0] = -1;
}

extern void fn_801EA994(void);
extern int lbl_80499E50[];
void fn_8026A2B0(int arg0) {
    lbl_80499E50[arg0] = 1;
}

void fn_8026A2C8(void) {
    fn_801EA994();
}

#pragma scheduling invalid_target
#pragma scheduling on
void fn_8026A2CC(int *arg0, int arg1, float arg2) {
    int *dst = (int *)((char *)lbl_80499080 + arg1 * 0x228 + 0x1a4);
    int *src = arg0;
    int a = src[0];
    int b = src[1];
    int c = src[2];
    int d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    dst[4] = src[4];
    dst[5] = src[5];
    dst[6] = src[6];
    dst[7] = src[7];
    dst[8] = src[8];
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
    *(float *)(dst + 12) = arg2;
}
int fn_8026A344(int arg0) {
    return *(int *)((char *)fn_80267EE4(arg0) + 0x20);
}
void *fn_80267EE4();
int fn_8026A368(void) {
    return *(int *)((char *)fn_80267EE4() + 0x10);
}
int fn_802678C0(void) {
    return (int)fn_80267EE4() + 0x58;
}
char fn_8026A38C(void) {
    return lbl_8055F488;
}

extern float lbl_80563CBC, lbl_80563C2C, lbl_80563C20, lbl_8055E3C8;
#pragma scheduling invalid_target
void fn_8026A394(void *arg0) {
 int i = 0;
 while (i < 4) {
  char *p = (char *)fn_80267EE4(i);
  if (*(void **)(p + 0x140) == arg0) {
   char *q;
   volatile unsigned int *src;
   volatile unsigned int *dst;
   unsigned int one;
   float factor;
   float scale;
   float threshold;
   float zero;
   float copy;
   unsigned int value1;
   unsigned int value0;
   unsigned int value3;
   unsigned int value2;
   unsigned int value5;
   unsigned int value4;
   unsigned int value7;
   unsigned int value6;
   unsigned int value8;
   unsigned int value10;
   unsigned int value9;
   unsigned int value11;
   one = 1;
   factor = *(volatile float *)&lbl_80563CBC;
   *(volatile unsigned char *)(p + 0x139) = one;
   threshold = lbl_80563C2C;
   *(volatile unsigned char *)(p + 0x138) = one;
   q = *(char * volatile *)(p + 0x140);
   scale = *(float *)(q + 0x25d4);
   factor = factor * scale;
   *(volatile float *)(p + 0x13c) = threshold < factor ? factor : threshold;
   zero = lbl_80563C20;
   *(float *)(p + 0x154) = zero;
   *(float *)(p + 0x158) = zero;
   src = (volatile unsigned int *)(p + 0x58);
   dst = (volatile unsigned int *)(p + 0x1f8);
   value0 = src[0];
   value1 = src[1];
   dst[0] = value0;
   dst[1] = value1;
   src = (volatile unsigned int *)(p + 0x60);
   dst = (volatile unsigned int *)(p + 0x200);
   value2 = src[0];
   value3 = src[1];
   dst[0] = value2;
   dst[1] = value3;
   src = (volatile unsigned int *)(p + 0x68);
   dst = (volatile unsigned int *)(p + 0x208);
   value4 = src[0];
   value5 = src[1];
   dst[0] = value4;
   dst[1] = value5;
   src = (volatile unsigned int *)(p + 0x70);
   dst = (volatile unsigned int *)(p + 0x210);
   value6 = src[0];
   value7 = src[1];
   dst[0] = value6;
   dst[1] = value7;
   src = (volatile unsigned int *)(p + 0x78);
   dst = (volatile unsigned int *)(p + 0x218);
   value8 = src[0];
   dst[0] = value8;
   src = (volatile unsigned int *)(p + 0x7c);
   dst = (volatile unsigned int *)(p + 0x21c);
   value9 = src[0];
   value10 = src[1];
   dst[0] = value9;
   dst[1] = value10;
   src = (volatile unsigned int *)(p + 0x84);
   dst = (volatile unsigned int *)(p + 0x224);
   value11 = src[0];
   dst[0] = value11;
   copy = *(float *)(p + 0xbc);
   *(float *)(p + 0x1f4) = copy;
   copy = lbl_8055E3C8;
   *(float *)(p + 0x1f0) = copy;
   return;
  }
  i++;
 }
}
#pragma scheduling on
  extern void fn_80269BB0(void);
  void fn_8026A49C(void) {
    fn_80269BB0();
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8026A4A0(int arg0, int *arg1, float *arg2) {
    char *base = (char *)lbl_80499080 + arg0 * 0x228;
    arg1[0] = *(int *)(base + 0x58);
    arg1[1] = *(int *)(base + 0x5c);
    arg1[2] = *(int *)(base + 0x60);
    arg1[3] = *(int *)(base + 0x64);
    arg1[4] = *(int *)(base + 0x68);
    arg1[5] = *(int *)(base + 0x6c);
    arg1[6] = *(int *)(base + 0x70);
    arg1[7] = *(int *)(base + 0x74);
    arg1[8] = *(int *)(base + 0x78);
    arg1[9] = *(int *)(base + 0x7c);
    arg1[10] = *(int *)(base + 0x80);
    arg1[11] = *(int *)(base + 0x84);
    *arg2 = *(float *)(base + 0xbc);
}
#pragma pop
extern float lbl_8055F484;
extern float lbl_80563C6C;
extern float lbl_80499980[8];
extern float lbl_80563C20;
void fn_802693F4(void);
void fn_8026A51C(void) {
    fn_802693F4();
}

float fn_8026A520(int arg0) {
    if (arg0 >= 0 && (unsigned int)arg0 < 8U) {
        return lbl_80499980[arg0];
    }
    return lbl_80563C20;
}

void fn_8026A54C(float arg0) {
    lbl_8055F484 = arg0;
}

int fn_8026A554(int *arg0) {
    int index = *arg0;
    if (index >= 0 && (unsigned int)index < 8U) {
        lbl_80499980[index] = lbl_80563C6C;
    }
    return 4;
}
extern float lbl_80563C20;
extern int lbl_80499E50[];
