// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void PSVECCrossProduct(void *, void *, void *);
extern void fn_8019EECC(void *, void *);
extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);

void fn_801BF210(void) {

}

#pragma scheduling invalid_target
void *fn_801BF214(void) {
    extern void *fn_801284F8(int, void *);
    extern void fn_8017B0B0(void);
    extern int fn_801C1BA4(int, int, int, void *, int);
    extern int lbl_8055A948;
    extern char lbl_80336A90[];
    extern char lbl_80437D48[];
    extern int lbl_8055E7BC;
    void *p = fn_801284F8(0x278, &lbl_8055A948);
    if (p != 0) {
        int offset;
        fn_8017B0B0();
        *(char **)p = lbl_80336A90;
        *(int *)((char *)p + 0x1EC) = 0;
        *(int *)((char *)p + 0x1F0) = -1;
        offset = lbl_8055E7BC * 4;
        lbl_8055E7BC = lbl_8055E7BC + 1;
        *(void **)(lbl_80437D48 + offset) = p;
        *(int *)((char *)p + 0x214) = fn_801C1BA4(4, 6, 2, lbl_80437D48, lbl_8055E7BC);
    }
    return p;
}
#pragma scheduling on
int fn_801BF754(int arg0) { return arg0 + 0x124; }

extern float fn_80144514(float, float, float, float, float, float);
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma dont_inline on
void fn_801BF75C(float *arg0, const float *arg1, const float *arg2, int arg3) {
    union { unsigned int bits[9]; float values[9]; } local;
    register float *localPtr = local.values;
    float t3, t5, t4;
    float temp_f1;
    float temp_f24, temp_f25, temp_f26, temp_f27;
    float temp_f28, temp_f29, temp_f30, temp_f31;
    float dx, dy, dz;

    local.bits[1] = ((const unsigned int *)arg2)[1];
    local.bits[2] = ((const unsigned int *)arg2)[2];
    local.bits[3] = ((const unsigned int *)arg2)[3];
    local.bits[5] = ((const unsigned int *)arg2)[5];
    local.bits[6] = ((const unsigned int *)arg2)[6];
    local.bits[7] = ((const unsigned int *)arg2)[7];
    local.bits[0] = ((const unsigned int *)arg2)[0];
    local.bits[4] = ((const unsigned int *)arg2)[4];
    local.bits[8] = ((const unsigned int *)arg2)[8];
    t3 = localPtr[1];
    t5 = localPtr[2];
    t4 = localPtr[5];
    localPtr[1] = localPtr[3];
    localPtr[3] = t3;
    localPtr[2] = localPtr[6];
    localPtr[6] = t5;
    localPtr[5] = localPtr[7];
    localPtr[7] = t4;

    if (arg0 == arg1 || arg0 == local.values) {
        temp_f24 = fn_80144514(localPtr[0], arg1[0], localPtr[3], arg1[1], localPtr[6], arg1[2]);
        temp_f25 = fn_80144514(localPtr[0], arg1[3], localPtr[3], arg1[4], localPtr[6], arg1[5]);
        temp_f26 = fn_80144514(localPtr[0], arg1[6], localPtr[3], arg1[7], localPtr[6], arg1[8]);
        temp_f27 = fn_80144514(localPtr[1], arg1[0], localPtr[4], arg1[1], localPtr[7], arg1[2]);
        temp_f28 = fn_80144514(localPtr[1], arg1[3], localPtr[4], arg1[4], localPtr[7], arg1[5]);
        temp_f29 = fn_80144514(localPtr[1], arg1[6], localPtr[4], arg1[7], localPtr[7], arg1[8]);
        temp_f30 = fn_80144514(localPtr[2], arg1[0], localPtr[5], arg1[1], localPtr[8], arg1[2]);
        temp_f31 = fn_80144514(localPtr[2], arg1[3], localPtr[5], arg1[4], localPtr[8], arg1[5]);
        temp_f1 = fn_80144514(localPtr[2], arg1[6], localPtr[5], arg1[7], localPtr[8], arg1[8]);
        arg0[0] = temp_f24;
        arg0[3] = temp_f25;
        arg0[6] = temp_f26;
        arg0[1] = temp_f27;
        arg0[4] = temp_f28;
        arg0[7] = temp_f29;
        arg0[2] = temp_f30;
        arg0[5] = temp_f31;
        arg0[8] = temp_f1;
    } else {
        arg0[0] = fn_80144514(localPtr[0], arg1[0], localPtr[3], arg1[1], localPtr[6], arg1[2]);
        arg0[3] = fn_80144514(localPtr[0], arg1[3], localPtr[3], arg1[4], localPtr[6], arg1[5]);
        arg0[6] = fn_80144514(localPtr[0], arg1[6], localPtr[3], arg1[7], localPtr[6], arg1[8]);
        arg0[1] = fn_80144514(localPtr[1], arg1[0], localPtr[4], arg1[1], localPtr[7], arg1[2]);
        arg0[4] = fn_80144514(localPtr[1], arg1[3], localPtr[4], arg1[4], localPtr[7], arg1[5]);
        arg0[7] = fn_80144514(localPtr[1], arg1[6], localPtr[4], arg1[7], localPtr[7], arg1[8]);
        arg0[2] = fn_80144514(localPtr[2], arg1[0], localPtr[5], arg1[1], localPtr[8], arg1[2]);
        arg0[5] = fn_80144514(localPtr[2], arg1[3], localPtr[5], arg1[4], localPtr[8], arg1[5]);
        arg0[8] = fn_80144514(localPtr[2], arg1[6], localPtr[5], arg1[7], localPtr[8], arg1[8]);
    }
    dx = arg1[9] - arg2[9];
    arg0[9] = dx;
    dy = arg1[10] - arg2[10];
    arg0[10] = dy;
    dz = arg1[11] - arg2[11];
    arg0[9] = dz * arg2[2] + (dx * arg2[0] + dy * arg2[1]);
    arg0[10] = dz * arg2[5] + (dx * arg2[3] + dy * arg2[4]);
    arg0[11] = dz * arg2[8] + (dx * arg2[6] + dy * arg2[7]);
}
#pragma dont_inline off
#pragma opt_propagation reset

void fn_801BFD34(float *out, float *in, const float *m) {
    if (out == in) {
        float y = in[1];
        float y0 = y * m[3];
        float y1 = y * m[4];
        float y2 = y * m[5];

        float x = in[0];
        float x0 = x * m[0];
        float x1 = x * m[1];
        float x2 = x * m[2];

        float z = in[2];
        float z0 = z * m[6];
        float z1 = z * m[7];
        float z2 = z * m[8];

        out[0] = (x0 + y0) + z0;
        out[1] = (x1 + y1) + z1;
        out[2] = (x2 + y2) + z2;
    } else {
        float m0 = m[0], m1 = m[1], m2 = m[2];
        float m3 = m[3], m4 = m[4], m5 = m[5];
        float m6 = m[6], m7 = m[7], m8 = m[8];

        out[0] = (m3 * in[1] + m0 * in[0]) + m6 * in[2];
        out[1] = (m4 * in[1] + m1 * in[0]) + m7 * in[2];
        out[2] = (m5 * in[1] + m2 * in[0]) + m8 * in[2];
    }
    {
        float tx = out[0] + m[9];
        float ty = out[1] + m[10];
        float tz = out[2] + m[11];
        out[0] = tx;
        out[1] = ty;
        out[2] = tz;
    }
}

void fn_801BFE7C(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] + arg2[0];
    float y = arg1[1] + arg2[1];
    float z = arg1[2] + arg2[2];
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

void fn_801BFEB0(void) {

}

long fn_801BFEB4(long arg0) { return arg0 + 0x6C; }

void GXInitLightAttnA_801BFEBC(void *arg0, float farg0, float farg1, float farg2) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
}

#pragma scheduling on
void fn_801BFECC(void *arg0, void *arg1) {
    register int a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0;
    a3 = *(volatile int *)((char *)arg1 + 0x0C);
    a4 = *(volatile int *)((char *)arg1 + 0x10);
    a2 = *(volatile int *)((char *)arg1 + 0x08);
    a1 = *(volatile int *)((char *)arg1 + 0x04);
    a0 = *(volatile int *)((char *)arg1 + 0x00);
    a5 = *(volatile int *)((char *)arg1 + 0x14);
    a6 = *(volatile int *)((char *)arg1 + 0x18);
    a7 = *(volatile int *)((char *)arg1 + 0x1C);
    a8 = *(volatile int *)((char *)arg1 + 0x20);
    a9 = *(volatile int *)((char *)arg1 + 0x24);
    a10 = *(volatile int *)((char *)arg1 + 0x28);
    a11 = *(volatile int *)((char *)arg1 + 0x2C);
    *(int *)((char *)arg0 + 0x3C) = a0;
    *(int *)((char *)arg0 + 0x40) = a1;
    *(int *)((char *)arg0 + 0x44) = a2;
    *(int *)((char *)arg0 + 0x48) = a3;
    *(int *)((char *)arg0 + 0x4C) = a4;
    *(int *)((char *)arg0 + 0x50) = a5;
    *(int *)((char *)arg0 + 0x54) = a6;
    *(int *)((char *)arg0 + 0x58) = a7;
    *(int *)((char *)arg0 + 0x5C) = a8;
    *(int *)((char *)arg0 + 0x60) = a9;
    *(int *)((char *)arg0 + 0x64) = a10;
    *(int *)((char *)arg0 + 0x68) = a11;
    ((void (*)(void *, void *, int, int, int, int, int, int))fn_8017A580)(arg0, arg1, a10, a9, a8, a7, a6, a5);
}

static inline void inline_transform_vec(float *out, const float *in, const float *m) {
    if (out == in) {
        float y0 = m[3] * in[1];
        float y1 = m[4] * in[1];
        float y2 = m[5] * in[1];

        float x0 = m[0] * in[0];
        float x1 = m[1] * in[0];
        float x2 = m[2] * in[0];

        float z0 = m[6] * in[2];
        float z1 = m[7] * in[2];
        float z2 = m[8] * in[2];

        out[0] = z0 + (x0 + y0);
        out[1] = z1 + (x1 + y1);
        out[2] = z2 + (x2 + y2);
    } else {
        {
            float y0 = m[3] * in[1];
            float x0 = m[0] * in[0];
            float z0 = m[6] * in[2];
            out[0] = z0 + (x0 + y0);
        }
        {
            float y1 = m[4] * in[1];
            float x1 = m[1] * in[0];
            float z1 = m[7] * in[2];
            out[1] = z1 + (x1 + y1);
        }
        {
            float y2 = m[5] * in[1];
            float x2 = m[2] * in[0];
            float z2 = m[8] * in[2];
            out[2] = z2 + (x2 + y2);
        }
    }
}

void fn_801BFF64(float *m, const float *in) {
    float tmp[3];
    inline_transform_vec(tmp, in, m);
    m[9] += tmp[0];
    m[10] += tmp[1];
    m[11] += tmp[2];
}

extern void fn_8019EECC(void *, void *);
void fn_801C00B8(void *arg0, float *arg1) {
    void *callback = *(void **)((char *)arg0 + 4);
    void *self = arg0;
    float x = arg1[0];
    float y = arg1[1];
    float z = arg1[2];
    *(float *)((char *)self + 0x28) = x;
    *(float *)((char *)self + 0x2C) = y;
    *(float *)((char *)self + 0x30) = z;
    if (callback == 0) return;
    fn_8019EECC(callback, (char *)self + 0x28);
}

long fn_801C00F0(void *arg0) { return *(long *)((char *)arg0 + 0x18); }

long fn_801C00F8(void *arg0, long arg1) {
    if (arg1 >= 0 && arg1 < *(long *)((char *)arg0 + 0x24))
        return *(long *)((char *)arg0 + arg1 * 4 + 0x14);
    return 0;
}

void fn_801C0124(float *arg0, float *arg1, float arg2) {
    float x = arg1[0];
    float y = arg1[1];
    float z = arg1[2];
    x *= arg2;
    y *= arg2;
    z *= arg2;
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

extern void fn_8017A580(int, int, int, int, int, int);
extern void fn_8017A57C(float, float);
void fn_801C014C(void *arg0, float *arg1) {
    float temp_f2 = arg1[0];
    float temp_f1 = arg1[1];
    float temp_f0 = arg1[2];
    *(float *)((char *)arg0 + 0x30) = temp_f2;
    *(float *)((char *)arg0 + 0x34) = temp_f1;
    *(float *)((char *)arg0 + 0x38) = temp_f0;
    fn_8017A57C(temp_f1, temp_f2);
}

int fn_801C0168(void *arg0) { return *(int *)((char *)arg0 + 0x5A4); }

int fn_801C0170(void *arg0) { return *(int *)((char *)arg0 + 0x59C); }

float fn_801C0178(void) { extern float lbl_8055E3C8; return lbl_8055E3C8; }

extern void fn_801C1C7C(void *, int);
extern void fn_80179EE8(void *, int);
extern void fn_80128668(void *);
extern int lbl_8055E7BC;
extern char lbl_80336A90[];
void *fn_801C0180(void *arg0, int arg1) {
    int temp_r4;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_80336A90;
        temp_r4 = lbl_8055E7BC;
        lbl_8055E7BC = temp_r4 - 1;
        fn_801C1C7C(*(void **)((char *)arg0 + 0x214), temp_r4);
        if (arg0 != 0) fn_80179EE8(arg0, 0);
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

/* The frame places Setup at sp+0x30; reversed float locals preserve the target FPR order. */
void fn_801C0204(void *arg0, int *arg1) {
    struct Setup {
        int value;
        int size;
        float first;
        float second;
        float third;
        float fourth;
    };
    struct Frame {
        float stack0;
        float stack1;
        float stack2;
        float stack3;
        float stack4;
        float stack5;
        float stack6;
        float stack7;
        float stack8;
        float stack9;
        volatile struct Setup setup;
    };
    extern void *memset(void *, int, unsigned int);
    extern void fn_8017B0F8(void *, void *);
    extern void *fn_801284F8(int, void *);
    extern void *fn_801A25F8(void *, void *, int, void *, float);
    extern void fn_80179F94(void *, void *);
    extern float lbl_805628B8, lbl_805628D0, lbl_805628D4, lbl_805628D8;
    extern float lbl_805628DC, lbl_805628E0, lbl_805628E4;
    extern char lbl_80336AE4[];
    struct Frame frame;
    void *result;
    memset((void *)&frame.setup, 0, 0x18);
    {
        float next, first;
        int value;
        first = *(volatile float *)&lbl_805628D0;
        frame.setup.size = 0x18;
        next = *(volatile float *)&lbl_805628D4;
        value = *(volatile int *)arg1;
        frame.setup.value = value;
        frame.setup.first = first;
        frame.setup.second = next;
        frame.setup.third = next;
        frame.setup.fourth = next;
    }
    fn_8017B0F8(arg0, (void *)&frame.setup);
    {
        float f3 = lbl_805628B8;
        float f2 = lbl_805628D8;
        float f1 = lbl_805628DC;
        float f0 = lbl_805628E0;
        *(float *)((char *)arg0 + 0x1FC) = f3;
        *(float *)((char *)arg0 + 0x200) = f3;
        *(float *)((char *)arg0 + 0x204) = f2;
        *(float *)((char *)arg0 + 0x208) = f3;
        *(float *)((char *)arg0 + 0x20C) = f1;
        *(float *)((char *)arg0 + 0x210) = f0;
        frame.stack6 = f3;
        frame.stack1 = f3;
        frame.stack5 = f3;
        result = ((void *(*)(int, const char *, float, float, float))fn_801284F8)(
            0x34, lbl_80336AE4, f1, f2, f3);
    }
    if (result != 0) {
        float value = lbl_805628E4;
        int field = *(int *)((char *)arg0 + 0x214);
        result = fn_801A25F8(result, (char *)arg0 + 0x3C, field, arg0, value);
    }
    fn_80179F94(arg0, result);
    *(unsigned char *)((char *)arg0 + 0x1E8) = 0;
}

static inline void helper_801C02F4(void *self, int flag) {
    if (flag) {
        *(int *)((char *)self + 0x1F0) = 0;
    } else {
        *(int *)((char *)self + 0x1F0) = -1;
    }
}

#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_801C02F4(void *arg0) {
    struct Mat43 {
        float m[4][3];
    };
    extern float lbl_805628B8, lbl_805628BC, lbl_805628E8, lbl_805628EC;
    extern void fn_8017B164(void *);
    struct Mat43 mat;
    float f;
    int flag;

    f = lbl_805628E8;
    *(int *)((char *)arg0 + 0x1EC) = 0;
    *(float *)((char *)arg0 + 0x218) = f;
    flag = 0;
    if (flag) {
        *(int *)((char *)arg0 + 0x1F0) = 0;
    } else {
        *(int *)((char *)arg0 + 0x1F0) = -1;
    }
    fn_8017B164(arg0);

    mat.m[0][0] = lbl_805628BC;
    mat.m[0][1] = lbl_805628B8;
    mat.m[0][2] = lbl_805628B8;
    mat.m[1][0] = lbl_805628B8;
    mat.m[1][1] = lbl_805628BC;
    mat.m[1][2] = lbl_805628B8;
    mat.m[2][0] = lbl_805628B8;
    mat.m[2][1] = lbl_805628B8;
    mat.m[2][2] = lbl_805628BC;
    mat.m[3][0] = lbl_805628B8;
    mat.m[3][2] = lbl_805628B8;
    mat.m[3][1] = lbl_805628EC;

    *(int *)((char *)arg0 + 0x1F4) = -1;
    *(int *)((char *)arg0 + 0x1F8) = 0;
    *(struct Mat43 *)((char *)arg0 + 0x3C) = mat;
    ((void (*)(void *))fn_8017A580)(arg0);

    {
        float f0, f1, f2;
        f2 = lbl_805628B8;
        f1 = lbl_805628E8;
        f0 = lbl_805628BC;
        *(float *)((char *)arg0 + 0x118) = f2;
        *(float *)((char *)arg0 + 0x11C) = f2;
        *(float *)((char *)arg0 + 0x120) = f2;
        *(float *)((char *)arg0 + 0x124) = f2;
        *(float *)((char *)arg0 + 0x128) = f2;
        *(float *)((char *)arg0 + 0x12C) = f2;
        *(float *)((char *)arg0 + 0x260) = f2;
        *(float *)((char *)arg0 + 0x264) = f1;
        *(float *)((char *)arg0 + 0x268) = f2;
        *(float *)((char *)arg0 + 0x26C) = f2;
        *(float *)((char *)arg0 + 0x270) = f0;
        *(float *)((char *)arg0 + 0x274) = f2;
    }
}
#pragma opt_dead_assignments reset
#pragma opt_propagation reset
int fn_801C0440(void *arg0) {
    return *(int *)((char *)arg0 + 0x1EC) != 0;
}

void fn_801C092C(void *arg0, void *arg1, void *arg2, int arg3) {
    float *out = (float *)arg0;
    float *input = (float *)arg1;
    float *matrix = (float *)arg2;
    float temp_f24, temp_f25, temp_f26, temp_f27;
    float temp_f28, temp_f29, temp_f30, temp_f31;
    float temp_f1;

    if ((char *)out + 0x24 == (char *)input + 0x24) {
        float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12;

        f0 = matrix[3];
        f6 = input[10];
        f2 = matrix[4];
        f4 = f6 * f0;
        f11 = matrix[5];
        f1 = matrix[0];
        f5 = input[9] * f1;
        f3 = matrix[1];
        f2 = f6 * f2;
        f0 = input[9];
        f3 = f0 * f3;
        f10 = matrix[2];
        f8 = matrix[6];
        f1 = f0 * f10;
        f0 = f6 * f11;
        f7 = input[11];
        f9 = matrix[7];
        f5 = f5 + f4;
        f6 = f7 * f8;
        f12 = matrix[8];
        f3 = f3 + f2;
        f4 = f7 * f9;
        f0 = f1 + f0;
        f2 = f7 * f12;
        f5 = f6 + f5;
        f1 = f4 + f3;
        f0 = f2 + f0;
        out[9] = f5;
        out[10] = f1;
        out[11] = f0;
    } else {
        out[9] = input[11] * matrix[6] + (input[9] * matrix[0] + input[10] * matrix[3]);
        out[10] = input[11] * matrix[7] + (input[9] * matrix[1] + input[10] * matrix[4]);
        out[11] = input[11] * matrix[8] + (input[9] * matrix[2] + input[10] * matrix[5]);
    }

    out[9] += matrix[9];
    out[10] += matrix[10];
    out[11] += matrix[11];

    if (out == input || out == matrix) {
        temp_f24 = fn_80144514(matrix[0], input[0], matrix[3], input[1], matrix[6], input[2]);
        temp_f25 = fn_80144514(matrix[0], input[3], matrix[3], input[4], matrix[6], input[5]);
        temp_f26 = fn_80144514(matrix[0], input[6], matrix[3], input[7], matrix[6], input[8]);
        temp_f27 = fn_80144514(matrix[1], input[0], matrix[4], input[1], matrix[7], input[2]);
        temp_f28 = fn_80144514(matrix[1], input[3], matrix[4], input[4], matrix[7], input[5]);
        temp_f29 = fn_80144514(matrix[1], input[6], matrix[4], input[7], matrix[7], input[8]);
        temp_f30 = fn_80144514(matrix[2], input[0], matrix[5], input[1], matrix[8], input[2]);
        temp_f31 = fn_80144514(matrix[2], input[3], matrix[5], input[4], matrix[8], input[5]);
        temp_f1 = fn_80144514(matrix[2], input[6], matrix[5], input[7], matrix[8], input[8]);
        out[0] = temp_f24;
        out[3] = temp_f25;
        out[6] = temp_f26;
        out[1] = temp_f27;
        out[4] = temp_f28;
        out[7] = temp_f29;
        out[2] = temp_f30;
        out[5] = temp_f31;
        out[8] = temp_f1;
    } else {
        out[0] = fn_80144514(matrix[0], input[0], matrix[3], input[1], matrix[6], input[2]);
        out[3] = fn_80144514(matrix[0], input[3], matrix[3], input[4], matrix[6], input[5]);
        out[6] = fn_80144514(matrix[0], input[6], matrix[3], input[7], matrix[6], input[8]);
        out[1] = fn_80144514(matrix[1], input[0], matrix[4], input[1], matrix[7], input[2]);
        out[4] = fn_80144514(matrix[1], input[3], matrix[4], input[4], matrix[7], input[5]);
        out[7] = fn_80144514(matrix[1], input[6], matrix[4], input[7], matrix[7], input[8]);
        out[2] = fn_80144514(matrix[2], input[0], matrix[5], input[1], matrix[8], input[2]);
        out[5] = fn_80144514(matrix[2], input[3], matrix[5], input[4], matrix[8], input[5]);
        out[8] = fn_80144514(matrix[2], input[6], matrix[5], input[7], matrix[8], input[8]);
    }
}

#pragma scheduling invalid_target
/* Reverse-ordered scalar loads keep the vector copies and final register restore matching. */
void fn_801C0D6C(void *arg0) {
    extern void PSVECNormalize(void *, void *);
    float vec1[3];
    float cross[3];
    float vec0[3];
    float *input = (float *)arg0;
    float x, y, z, a, b, c;
    z = input[2];
    y = input[1];
    x = input[0];
    vec0[0] = x;
    vec0[1] = y;
    vec0[2] = z;
    c = input[8];
    b = input[7];
    a = input[6];
    vec1[0] = a;
    vec1[1] = b;
    vec1[2] = c;
    PSVECCrossProduct(vec1, vec0, cross);
    PSVECNormalize(vec0, vec0);
    PSVECNormalize(cross, cross);
    PSVECCrossProduct(vec0, cross, vec1);
    input[0] = vec0[0];
    input[1] = vec0[1];
    input[2] = vec0[2];
    input[3] = cross[0];
    input[4] = cross[1];
    input[5] = cross[2];
    input[6] = vec1[0];
    input[7] = vec1[1];
    input[8] = vec1[2];
}
#pragma scheduling on
extern void PSVECDotProduct(void *, void *);
extern void PSVECCrossProduct(void *, void *, void *);
extern float lbl_805628B8;
extern float lbl_805628BC;
void fn_801C0E44(void *arg0) { PSVECDotProduct(arg0, arg0); }

void fn_801C0E4C(void *arg0, void *arg1, void *arg2) {
    PSVECCrossProduct(arg1, arg2, arg0);
}

void fn_801C0E60(float *arg0, float *arg1, float *arg2) {
    float x = arg1[0] - arg2[0];
    float y = arg1[1] - arg2[1];
    float z = arg1[2] - arg2[2];
    arg0[0] = x;
    arg0[1] = y;
    arg0[2] = z;
}

