// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float x, y, z; } Vec801BD;
static inline void Vec801BD_Copy(Vec801BD *dst, const Vec801BD *src) {
    float x = src->x, y = src->y, z = src->z;
    dst->x = x; dst->y = y; dst->z = z;
}
extern float lbl_80562844;
__declspec(section ".sdata") extern char lbl_8055A924[];
__declspec(section ".sdata") extern char lbl_8055A92C[];
__declspec(section ".sdata") extern char lbl_8055A934[];
__declspec(section ".sdata") extern char lbl_8055A93C[];
extern float lbl_80562848;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E794, lbl_8055E78C, lbl_8055E790, lbl_8055E7A0, lbl_8055E7A4;
extern int fn_80128670(int);
int fn_801BD628(float *arg0) {
    int result = 0;
    if (arg0[0] >= lbl_80562844 && arg0[0] <= lbl_80562848 &&
        arg0[1] >= lbl_80562844 && arg0[1] <= lbl_80562848 &&
        arg0[2] >= lbl_80562844 && arg0[2] <= lbl_80562848) {
        result = 1;
    }
    return result;
}

#pragma push
#pragma scheduling invalid_target
void fn_801BD694(int arg0) {
    extern int lbl_8055E78C, lbl_8055E790, lbl_8055E794, lbl_8055E798, lbl_8055E79C, lbl_8055E7A0, lbl_8055E7A4;
    extern signed char lbl_8055E7A8;
    extern char lbl_80336A50[], lbl_8055A924[], lbl_8055A92C[], lbl_8055A934[], lbl_8055A93C[];
    extern void fn_801BD78C(void), fn_801BD788(void), fn_801BD784(void);
    extern void *fn_8012850C(int, const char *);
    extern void *fn_8002F37C(void *, void (*)(void), int, int, int);
    int temp;
    void *memory;

    *(volatile int *)&lbl_8055E790 = arg0;
    *(volatile int *)&lbl_8055E78C = 0;
    memory = fn_8012850C(arg0 * 0xB0 + 0x10, lbl_80336A50);
    lbl_8055E794 = (int)fn_8002F37C(memory, fn_801BD78C, 0, 0xB0, arg0);
    temp = lbl_8055E790;
    memory = fn_8012850C(temp * 0x1F0 + 0x10, lbl_8055A924);
    lbl_8055E798 = (int)fn_8002F37C(memory, fn_801BD788, 0, 0x1F0, temp);
    temp = lbl_8055E790;
    memory = fn_8012850C(temp * 0x190 + 0x10, lbl_8055A92C);
    lbl_8055E79C = (int)fn_8002F37C(memory, fn_801BD784, 0, 0x190, temp);
    lbl_8055E7A4 = (int)fn_8012850C(lbl_8055E790 * 0x14, lbl_8055A934);
    lbl_8055E7A0 = (int)fn_8012850C(lbl_8055E790, lbl_8055A93C);
    lbl_8055E7A8 = 1;
}
#pragma pop
void fn_801BD784(void) {

}

void fn_801BD788(void) {

}

void fn_801BD78C(void) {

}

void fn_801BD790(void) {
    if (lbl_8055E794 != 0) {
        fn_80128670(lbl_8055E794 - 0x10);
    }
    if (lbl_8055E798 != 0) {
        fn_80128670(lbl_8055E798 - 0x10);
    }
    if (lbl_8055E79C != 0) {
        fn_80128670(lbl_8055E79C - 0x10);
    }
    fn_80128670(lbl_8055E7A4);
    fn_80128670(lbl_8055E7A0);
    lbl_8055E794 = 0;
    lbl_8055E78C = 0;
    lbl_8055E790 = 0;
}

extern void *memset(void *, int, unsigned long);
extern double cos(double);
extern double sin(double);
extern void fn_801E9DC4(void *);
extern void fn_801BDA70(void);
extern void fn_801BDA74();
extern int lbl_8055E78C, lbl_8055E794, lbl_8055E798, lbl_8055E79C, lbl_8055E7A4;
extern float lbl_80562838, lbl_8056283C, lbl_8056284C, lbl_80562850, lbl_80562854;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801BD808(void) {
    int idx = lbl_8055E78C;
    float *o30;
    float *o29;
    void *o28;
    void *o27;
    float q[7][4];
    float m[4][4];
    float buf[0x50];
    float z, s, c;
    o30 = (float *)(lbl_8055E794 + idx * 0xB0);
    lbl_8055E78C = idx + 1;
    o29 = (float *)(lbl_8055E798 + idx * 0x1F0);
    o28 = (void *)(lbl_8055E79C + idx * 0x190);
    o27 = (void *)(lbl_8055E7A4 + idx * 0x14);
    memset(o30, 0, 0xB0);
    memset(o29, 0, 0x1F0);
    memset(o28, 0, 0x190);
    memset(o27, 0, 0x14);
    fn_801E9DC4(o27);
    z = lbl_80562838;
    o30[0] = z; o30[1] = lbl_8056284C; o30[2] = z; o30[3] = m[3][3];
    o30[0x14] = z; o30[0x15] = z; o30[0x16] = z; o30[0x17] = m[2][3];
    o30[0x18] = z; o30[0x19] = z; o30[0x1a] = lbl_80562850; o30[0x1b] = m[1][3];
    o30[0x28] = z; o30[0x29] = z; o30[0x2a] = z;
    m[3][0] = z; m[3][1] = lbl_8056284C; m[3][2] = z;
    m[2][0] = z; m[2][1] = z; m[2][2] = z;
    m[1][0] = z; m[1][1] = z; m[1][2] = lbl_80562850;
    m[0][0] = z; m[0][1] = z; m[0][2] = z;
    o30[0x2b] = m[0][3];
    c = (float)cos(lbl_80562854 * z);
    s = (float)sin(lbl_80562854 * z);
    o30[0x10] = lbl_80562838; o30[0x11] = lbl_80562838; o30[0x12] = s; o30[0x13] = c;
    o30[4] = lbl_8056283C; o30[5] = lbl_80562838; o30[6] = lbl_80562838; o30[7] = q[5][3];
    o30[8] = lbl_80562838; o30[9] = lbl_8056283C; o30[10] = lbl_80562838; o30[11] = q[4][3];
    o30[12] = lbl_80562838; o30[13] = lbl_80562838; o30[14] = lbl_8056283C; o30[15] = q[3][3];
    o29[0x64] = lbl_80562838; o29[0x65] = lbl_80562838; o29[0x66] = lbl_80562838; o29[0x67] = lbl_80562838;
    o29[0x68] = lbl_80562838; o29[0x69] = lbl_80562838; o29[0x6a] = lbl_80562838; o29[0x6b] = lbl_80562838;
    o29[0xc] = lbl_80562838; o29[0xd] = lbl_80562838; o29[0xe] = lbl_80562838;
    q[6][0] = lbl_80562838; q[6][1] = lbl_80562838; q[6][2] = s; q[6][3] = c;
    q[5][0] = lbl_8056283C; q[5][1] = lbl_80562838; q[5][2] = lbl_80562838;
    q[4][0] = lbl_80562838; q[4][1] = lbl_8056283C; q[4][2] = lbl_80562838;
    q[3][0] = lbl_80562838; q[3][1] = lbl_80562838; q[3][2] = lbl_8056283C;
    q[2][0] = lbl_80562838; q[2][1] = lbl_80562838; q[2][2] = lbl_80562838; q[2][3] = lbl_80562838;
    q[1][0] = lbl_80562838; q[1][1] = lbl_80562838; q[1][2] = lbl_80562838; q[1][3] = lbl_80562838;
    q[0][0] = lbl_80562838; q[0][1] = lbl_80562838; q[0][2] = lbl_80562838; q[0][3] = lbl_80562838;
    o29[0xf] = lbl_80562838;
    ((void (*)(void *, float, float, float, float, float))fn_801BDA70)(buf, q[4][3], q[5][3], lbl_8056283C, lbl_80562838, s);
    ((void (*)(int, void *))fn_801BDA74)(idx, buf);
}
#pragma pop
void fn_801BDA70(void) {
    fn_80279D40();
}

extern float lbl_80562838, lbl_8056283C, lbl_80562854;
extern double fn_8002F234(float);
extern signed char lbl_8055E7A8;
void fn_801BE168(int index, float (*m)[3], float *a, float *b) {
    extern int lbl_8055E794;
    struct V4 { float x, y, z, w; };
    float out[4], t, q;
    struct V4 pos, quat, la, lb;
    int i, j, k;
    float *dst = (float *)(lbl_8055E794 + index * 0xB0);
    float *v = (float *)m;
    t = m[0][0] + m[1][1] + m[2][2];
    pos.x = v[9]; pos.y = v[10]; pos.z = v[11];
    dst[0] = pos.x; dst[1] = pos.y; dst[2] = pos.z; dst[3] = pos.w;
    if (t > lbl_80562838) {
        q = fn_8002F234(lbl_8056283C + t);
        out[3] = lbl_80562854 * q;
        out[0] = lbl_80562854 / q * (m[1][2] - m[2][1]);
        out[1] = lbl_80562854 / q * (m[2][0] - m[0][2]);
        out[2] = lbl_80562854 / q * (m[0][1] - m[1][0]);
    } else {
        i = 0; if (m[1][1] > m[0][0]) i = 1; if (m[2][2] > m[i][i]) i = 2;
        j = (i + 1) % 3; k = (j + 1) % 3;
        q = fn_8002F234(lbl_8056283C + m[i][i] - (m[j][j] + m[k][k]));
        out[i] = lbl_80562854 * q;
        out[3] = lbl_80562854 / q * (m[j][k] - m[k][j]);
        out[j] = lbl_80562854 / q * (m[i][j] + m[j][i]);
        out[k] = lbl_80562854 / q * (m[i][k] + m[k][i]);
    }
    quat.x = -out[0]; quat.y = -out[1]; quat.z = -out[2]; quat.w = out[3];
    la.x = a[0]; la.y = a[1]; la.z = a[2];
    lb.x = b[0]; lb.y = b[1]; lb.z = b[2];
    dst[16] = quat.x; dst[17] = quat.y; dst[18] = quat.z; dst[19] = quat.w;
    dst[20] = la.x; dst[21] = la.y; dst[22] = la.z; dst[23] = la.w;
    dst[24] = lb.x; dst[25] = lb.y; dst[26] = lb.z; dst[27] = lb.w;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_801BEAEC(int arg0, int arg1, void *arg2) {
    float *temp;
    float f0;
    float f1;
    float f2;
    temp = (float *)(arg0 * 0x1F0 + lbl_8055E798);
    temp = (float *)((char *)temp + arg1 * 0x10);
    f2 = temp[18];
    f1 = temp[17];
    f0 = temp[16];
    ((float *)arg2)[0] = f0;
    ((float *)arg2)[1] = f1;
    ((float *)arg2)[2] = f2;
}
#pragma opt_propagation on
#pragma scheduling on
#pragma pop
void fn_801BEB1C(int arg0, int *arg1) {
    *arg1 = lbl_8055E798 + arg0 * 0x1F0;
}

void fn_801BEB30(int arg0, int *arg1) {
    *arg1 = lbl_8055E79C + (arg0 * 0x190);
}

extern float lbl_80562838, lbl_8056283C, lbl_805628A8, lbl_805628AC, lbl_805628B0;
extern float PSVECDotProduct(const void *, const void *);
extern void PSVECNormalize(const void *, void *);
void fn_801BEB44(int i, int j, float *target, float *velocity) {
    unsigned char *base = (unsigned char *)lbl_8055E798 + i * 0x1F0;
    int off = j * 16;
    unsigned char *p = base + off;
    Vec801BD a, b, n, diff, tmp, lerp;
    Vec801BD *tg = (Vec801BD *)target;
    Vec801BD *vel = (Vec801BD *)velocity;
    float d0, d1, t;
    Vec801BD_Copy(&a, (Vec801BD *)(p + 0x40));
    Vec801BD_Copy(&b, (Vec801BD *)(p + 0x150));
    diff.x = a.x - b.x; diff.y = a.y - b.y; diff.z = a.z - b.z;
    Vec801BD_Copy(&n, (Vec801BD *)(p + 0x110));
    d0 = PSVECDotProduct(&diff, &n);
    tmp.x = a.x - tg->x; tmp.y = a.y - tg->y; tmp.z = a.z - tg->z;
    d1 = PSVECDotProduct(&tmp, vel) - d0;
    if (d1 > lbl_805628A8) return;
    if (PSVECDotProduct(vel, &n) < lbl_805628AC) return;
    t = lbl_805628B0 * (lbl_805628A8 + d1);
    t = (lbl_8056283C < t) ? lbl_8056283C : t;
    t = (t > lbl_80562838) ? t : lbl_80562838;
    lerp.x = vel->x + t * (n.x - vel->x);
    lerp.y = vel->y + t * (n.y - vel->y);
    lerp.z = vel->z + t * (n.z - vel->z);
    Vec801BD_Copy(&n, &lerp);
    PSVECNormalize(&n, &n);
    lerp.x = tg->x + t * (b.x - tg->x);
    lerp.y = tg->y + t * (b.y - tg->y);
    lerp.z = tg->z + t * (b.z - tg->z);
    p = base + off;
    Vec801BD_Copy((Vec801BD *)(p + 0x150), &lerp);
    *(float *)(p + 0x15C) = *(float *)(p + 0x24);
    Vec801BD_Copy((Vec801BD *)(p + 0x110), &n);
    *(float *)(p + 0x11C) = *(float *)(p + 0x14);
}

extern float lbl_80562838;
extern float lbl_8056283C;
extern float lbl_805628A4;
extern int fn_801E9E78(int, void *, void *);
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A4;
extern int lbl_8055E78C;
void fn_801BEDA8(int *arg0, int *arg1, int *arg2, int *arg3, int *arg4) {
    *arg0 = lbl_8055E794;
    *arg1 = lbl_8055E798;
    *arg2 = lbl_8055E79C;
    *arg3 = lbl_8055E7A4;
    *arg4 = lbl_8055E78C;
}

extern char lbl_80436D48[];
extern char lbl_80336A60[];
extern int lbl_8055A920;
extern float lbl_805628B4;
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_8001BA68(void *);
extern void fn_801BA088(void *, int, int, int);
extern void fn_802E30C8(const char *, ...);
extern void GXInitLightAttnA_80144B44(void *, float, float, float);
void fn_801BF12C(float *arg0, float *arg1);
void fn_801BF150(void *arg0, float farg0, float farg1, float farg2, float farg3);
void fn_801BF164(float *arg0, float *arg1);
void GXInitLightAttnA_801BF188(void *arg0, float farg0, float farg1, float farg2);
void fn_801BF198(void *arg0, void *arg1);
void fn_801BF0C4(void *arg0, void *arg1, int arg2);
void fn_801BEDD4(void) {
    int i = 0;
    char tmp90[16], tmp80[16], tmp70[16], tmp60[16], tmp50[16], tmp40[16];
    float v30[3], v24[3], m2[3], m1[3];
    int sp8;
    while (i < lbl_8055E78C) {
        char *p3, *p4, *p5;
        memcpy(lbl_80436D48, (char *)lbl_8055E794 + i * 0xB0, 0xB0);
        memcpy(lbl_80436D48 + 0xB0, (char *)lbl_8055E798 + i * 0x1F0, 0x1F0);
        memcpy(lbl_80436D48 + 0x2A0, (char *)lbl_8055E79C + i * 0x190, 0x190);
        lbl_8055A920 = i;
        fn_801BA088(lbl_80436D48, 0, 0xB, 0x2A);
        lbl_8055A920 = -1;
        if (((unsigned char *)lbl_8055E7A0)[i] == 0) {
            memcpy((char *)lbl_8055E794 + i * 0xB0, lbl_80436D48, 0xB0);
            memcpy((char *)lbl_8055E798 + i * 0x1F0, lbl_80436D48 + 0xB0, 0x1F0);
        }
        p5 = (char *)lbl_8055E7A4 + i * 0x14;
        p4 = (char *)lbl_8055E798 + i * 0x1F0;
        p3 = (char *)lbl_8055E794 + i * 0xB0;
        fn_8001BA68(m1);
        fn_801BF198(m1, p3);
        if (((int (*)(float *))fn_801BD628)(m1) == 0) {
            fn_802E30C8(lbl_80336A60, m1[0], m1[1], m1[2]);
            ((void *(*)(void *, void *))fn_801BF164)(p3, ((void *(*)(void *, float, float, float))GXInitLightAttnA_801BF188)(tmp40, lbl_80562838, lbl_805628B4, lbl_80562838));
            ((void *(*)(void *, void *))fn_801BF12C)(p3 + 0x40, ((void *(*)(void *, float, float, float, float))fn_801BF150)(tmp50, lbl_80562838, lbl_80562838, lbl_80562838, lbl_8056283C));
            ((void *(*)(void *, void *))fn_801BF164)(p3 + 0x50, ((void *(*)(void *, void *))fn_801BF164)(p3 + 0x60, ((void *(*)(void *, float, float, float))GXInitLightAttnA_801BF188)(tmp60, lbl_80562838, lbl_80562838, lbl_80562838)));
            ((void *(*)(void *, void *))fn_801BF12C)(p4, ((void *(*)(void *, void *))fn_801BF12C)(p4 + 0x10, ((void *(*)(void *, void *))fn_801BF12C)(p4 + 0x20, ((void *(*)(void *, void *))fn_801BF12C)(p4 + 0x30, ((void *(*)(void *, float, float, float, float))fn_801BF150)(tmp70, lbl_80562838, lbl_80562838, lbl_80562838, lbl_80562838)))));
            fn_801BF198(m1, p3);
        }
        fn_8001BA68(m2);
        fn_801BF198(m2, p3 + 0x30);
        {
            char *a = p4 + 0x40;
            char *pq = p5;
            char *b = p4 + 0x110;
            int j = 0;
            char *c = p4 + 0x150;
            do {
                fn_8001BA68(v24);
                fn_801BF198(v24, a);
                sp8 = 0xFF;
                GXInitLightAttnA_80144B44(v30, lbl_80562838, lbl_8056283C, lbl_80562838);
                ((void (*)(void *, void *, void *, void *))fn_801BF0C4)(v24, v30, p5, &sp8);
                ((int *)pq)[1] = sp8;
                ((void *(*)(void *, void *))fn_801BF12C)(b, ((void *(*)(void *, float, float, float, float))fn_801BF150)(tmp80, v30[0], v30[1], v30[2], v24[1]));
                ((void *(*)(void *, void *))fn_801BF164)(c, ((void *(*)(void *, float, float, float))GXInitLightAttnA_801BF188)(tmp90, v24[0], v24[1], v24[2]));
                j++; a += 0x10; pq += 4; b += 0x10; c += 0x10;
            } while (j < 4);
        }
        i++;
    }
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801BF0C4(void *arg0, void *arg1, int arg2) {
    float d;
    float b;
    float a;

    if (fn_801E9E78(arg2, arg0, arg1) == 0) {
        a = lbl_80562838;
        b = lbl_8056283C;
        *(float *)arg1 = a;
        d = lbl_805628A4;
        *(float *)((char *)arg1 + 4) = b;
        *(float *)((char *)arg1 + 8) = a;
        *(float *)((char *)arg0 + 4) = d;
    }
}
#pragma scheduling on
#pragma pop
void fn_801BF12C(float *arg0, float *arg1) {
    float d;
    float c;
    float b;
    float a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
}

void fn_801BF150(void *arg0, float farg0, float farg1, float farg2, float farg3) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
    ((float *)arg0)[3] = farg3;
}

void fn_801BF164(float *arg0, float *arg1) {
    float d;
    float c;
    float b;
    float a;
    a = arg1[0];
    b = arg1[1];
    c = arg1[2];
    d = arg1[3];
    arg0[0] = a;
    arg0[1] = b;
    arg0[2] = c;
    arg0[3] = d;
}

void GXInitLightAttnA_801BF188(void *arg0, float farg0, float farg1, float farg2) {
    ((float *)arg0)[0] = farg0;
    ((float *)arg0)[1] = farg1;
    ((float *)arg0)[2] = farg2;
}

void fn_801BF198(void *arg0, void *arg1) {
    float temp_f0 = ((float *)arg1)[0];
    float temp_f1 = ((float *)arg1)[1];
    float temp_f2 = ((float *)arg1)[2];
    ((float *)arg0)[1] = temp_f1;
    ((float *)arg0)[0] = temp_f0;
    ((float *)arg0)[2] = temp_f2;
}

void fn_801BF1B4(void) {

}

void fn_801BF1B8(int arg0, char arg1) {
    extern int lbl_8055E7A0;
    ((char *)lbl_8055E7A0)[arg0] = arg1;
}

extern float lbl_80562838;
extern float lbl_8056283C;
extern float lbl_805628A4;
extern int fn_801E9E78(int, void *, void *);
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A4;
extern int lbl_8055E78C;
extern int lbl_8055E78C;
extern int lbl_8055E790;
extern int lbl_8055E794;
extern int lbl_8055E798;
extern int lbl_8055E79C;
extern int lbl_8055E7A0;
extern int lbl_8055E7A4;
extern signed char lbl_8055E7A8;
extern char lbl_80336A50[];
extern char lbl_8055A924[];
extern char lbl_8055A92C[];
extern char lbl_8055A934[];
extern char lbl_8055A93C[];
