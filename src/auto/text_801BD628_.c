// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float x, y, z; } Vec801BD;
static inline void Vec801BD_Copy(Vec801BD *dst, const Vec801BD *src) {
    float x = src->x, y = src->y, z = src->z;
    dst->x = x; dst->y = y; dst->z = z;
}
typedef struct { float x, y, z, w; } V4_801BDA74;
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

/* The per-vehicle simulation pools built by fn_801BD694 (8 vehicles): one block
 * per list from the ring-buffer allocator, every list indexed by slot.  The
 * names are the game's own allocation tags ("masslist", "cslist", ...). */
#define massList      lbl_8055E794 /* 0xB0-byte body record per slot (pose, mass) */
#define csList        lbl_8055E798 /* 0x1F0-byte orientation record per slot */
#define ccList        lbl_8055E79C /* 0x190-byte wheel record per slot */
#define cxList        lbl_8055E7A4 /* 0x14 bytes per slot */
#define aList         lbl_8055E7A0 /* one "leave this slot alone" flag byte per slot */
#define poolCapacity  lbl_8055E790 /* slots the pools were sized for */
#define poolIndex     lbl_8055E78C /* next free slot */
#define Mem_Free      fn_80128670  /* frees a block; the data sits 0x10 above its header */
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
/* Initializes object pool lists/buffers for count entries and marks system initialized. */
void fn_801BD694(int count) {
    extern int lbl_8055E78C, lbl_8055E790, lbl_8055E794, lbl_8055E798, lbl_8055E79C, lbl_8055E7A0, lbl_8055E7A4;
    extern signed char lbl_8055E7A8;
    extern char lbl_80336A50[], lbl_8055A924[], lbl_8055A92C[], lbl_8055A934[], lbl_8055A93C[];
    extern void fn_801BD78C(void), fn_801BD788(void), fn_801BD784(void);
    extern void *fn_8012850C(int, const char *);
    extern void *fn_8002F37C(void *, void (*)(void), int, int, int);
    int poolCount;
    void *memory;

    /* lbl_8055E790 = pool count, lbl_8055E78C = current index */
    *(volatile int *)&lbl_8055E790 = count;
    *(volatile int *)&lbl_8055E78C = 0;
    /* Allocate and build mass/cs/cc lists (element sizes 0xB0, 0x1F0, 0x190) */
    memory = fn_8012850C(count * 0xB0 + 0x10, lbl_80336A50);
    lbl_8055E794 = (int)fn_8002F37C(memory, fn_801BD78C, 0, 0xB0, count);
    poolCount = lbl_8055E790;
    memory = fn_8012850C(poolCount * 0x1F0 + 0x10, lbl_8055A924);
    lbl_8055E798 = (int)fn_8002F37C(memory, fn_801BD788, 0, 0x1F0, poolCount);
    poolCount = lbl_8055E790;
    memory = fn_8012850C(poolCount * 0x190 + 0x10, lbl_8055A92C);
    lbl_8055E79C = (int)fn_8002F37C(memory, fn_801BD784, 0, 0x190, poolCount);
    /* Allocate cx/alist buffers and set initialized flag (lbl_8055E7A8) */
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
    struct { float q[7][4]; float m[4][4]; float buf[78]; } tmp;
    float z, s, c;
    float z2, one;
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
    {
        float two, eps, hz, m33, m23, m13, m03;
        two = lbl_8056284C;
        o30[0] = z;
        eps = lbl_80562850;
        o30[1] = two;
        hz = lbl_80562854 * z;
        o30[2] = z;
        m33 = tmp.m[3][3];
        o30[3] = m33;
        o30[0x14] = z;
        m23 = tmp.m[2][3];
        o30[0x15] = z; o30[0x16] = z; o30[0x17] = m23;
        m13 = tmp.m[1][3];
        o30[0x18] = z; o30[0x19] = z; o30[0x1a] = eps;
        m03 = tmp.m[0][3];
        o30[0x1b] = m13;
        o30[0x28] = z; o30[0x29] = z; o30[0x2a] = z;
        tmp.m[3][0] = z; tmp.m[3][1] = two; tmp.m[3][2] = z;
        tmp.m[2][0] = z; tmp.m[2][1] = z; tmp.m[2][2] = z;
        tmp.m[1][0] = z; tmp.m[1][1] = z; tmp.m[1][2] = eps;
        tmp.m[0][0] = z; tmp.m[0][1] = z; tmp.m[0][2] = z;
        o30[0x2b] = m03;
        c = (float)cos(hz);
        s = (float)sin(lbl_80562854 * z);
    }
    z2 = lbl_80562838;
    one = lbl_8056283C;
    o30[0x10] = z2; o30[0x11] = z2; o30[0x12] = s; o30[0x13] = c;
    o30[4] = one; o30[5] = z2; o30[6] = z2; o30[7] = tmp.q[5][3];
    o30[8] = z2; o30[9] = one; o30[10] = z2; o30[11] = tmp.q[4][3];
    o30[12] = z2; o30[13] = z2; o30[14] = one; o30[15] = tmp.q[3][3];
    o29[0x64] = z2; o29[0x65] = z2; o29[0x66] = z2; o29[0x67] = z2;
    o29[0x68] = z2; o29[0x69] = z2; o29[0x6a] = z2; o29[0x6b] = z2;
    o29[0xc] = z2; o29[0xd] = z2; o29[0xe] = z2;
    tmp.q[6][0] = z2; tmp.q[6][1] = z2; tmp.q[6][2] = s; tmp.q[6][3] = c;
    tmp.q[5][0] = one; tmp.q[5][1] = z2; tmp.q[5][2] = z2;
    tmp.q[4][0] = z2; tmp.q[4][1] = one; tmp.q[4][2] = z2;
    tmp.q[3][0] = z2; tmp.q[3][1] = z2; tmp.q[3][2] = one;
    tmp.q[2][0] = z2; tmp.q[2][1] = z2; tmp.q[2][2] = z2; tmp.q[2][3] = z2;
    tmp.q[1][0] = z2; tmp.q[1][1] = z2; tmp.q[1][2] = z2; tmp.q[1][3] = z2;
    tmp.q[0][0] = z2; tmp.q[0][1] = z2; tmp.q[0][2] = z2; tmp.q[0][3] = z2;
    o29[0xf] = z2;
    ((void (*)())fn_801BDA70)(tmp.buf);
    ((void (*)(int, void *))fn_801BDA74)(idx, tmp.buf);
}
#pragma pop
void fn_801BDA70(void) {
    fn_80279D40();
}

extern float lbl_80562840, lbl_80562858, lbl_8056285C, lbl_80562860, lbl_80562864, lbl_80562868, lbl_8056286C, lbl_80562870, lbl_80562874, lbl_80562878, lbl_8056287C, lbl_80562880, lbl_80562884, lbl_80562888, lbl_8056288C, lbl_80562890, lbl_80562894, lbl_80562898, lbl_8056289C, lbl_805628A0;
extern char lbl_8055E7A0_c[];
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801BDA74(int idx, float *p) {
    float *o30 = (float *)(lbl_8055E794 + idx * 0xB0);
    float *o28 = (float *)(lbl_8055E79C + idx * 0x190);
    float stk[96];
    float *s = stk;
    float K1 = lbl_8056283C, Z = lbl_80562838, H = lbl_80562854, A = lbl_8056285C, B = lbl_80562858, M1 = lbl_80562840;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13;
    float f19, f20;
    int i;
    ((char *)lbl_8055E7A0)[idx] = 0;
    f2 = p[1]; f6 = p[2]; f7 = p[3]; f8 = p[0];
    f9 = K1 / f2; f10 = K1 / f6; f11 = K1 / f7; f1 = K1 / f8;
    o30[28] = f2; o30[29] = f6; o30[30] = f7; o30[31] = f8;
    o30[32] = f9; o30[33] = f10; o30[34] = f11; o30[35] = f1;
    o28[16] = A; o28[17] = A; o28[18] = A; o28[19] = A;
    o28[20] = B; o28[21] = B; o28[22] = B;
    s[92] = f2; s[93] = f6; s[94] = f7; s[95] = f8;
    s[88] = f9; s[89] = f10; s[90] = f11; s[91] = f1;
    s[84] = A; s[85] = A; s[86] = A; s[87] = A;
    s[80] = B; s[81] = B; s[82] = B; s[83] = B;
    o28[23] = B;
    for (i = 0; i < 4; i += 2) {
        s[76] = lbl_80562860 * ((i & 1) ? K1 : M1);
        s[77] = lbl_80562864 - Z;
        s[78] = lbl_80562868 * ((i & 2) ? M1 : K1);
        o28[i * 4 + 0] = s[76];
        o28[i * 4 + 1] = s[77];
        o28[i * 4 + 2] = s[78];
        o28[i * 4 + 3] = s[79];
        s[76] = lbl_80562860 * (((i + 1) & 1) ? K1 : M1);
        s[77] = lbl_80562864 - Z;
        s[78] = lbl_80562868 * (((i + 1) & 2) ? M1 : K1);
        o28[i * 4 + 4] = s[76];
        o28[i * 4 + 5] = s[77];
        o28[i * 4 + 6] = s[78];
        o28[i * 4 + 7] = s[79];
    }
    f10 = (float)sin(p[74]);
    f12 = lbl_8056286C; f13 = lbl_80562870;
    f7 = -f12; f6 = -f13;
    f19 = lbl_80562874 * (H * p[10]);
    o28[72] = f10; o28[73] = f10; o28[74] = Z; o28[75] = Z;
    o28[76] = f12; o28[77] = f7; o28[78] = f13; o28[79] = f6;
    f4 = p[71]; f2 = p[72];
    f9 = f2 * f4; f11 = f2 * (K1 - f4);
    f2 = p[8] - p[9];
    o28[80] = Z; o28[81] = Z; o28[82] = Z; o28[83] = Z;
    o28[84] = Z; o28[85] = Z; o28[86] = H; o28[87] = H;
    o28[24] = f19; o28[25] = Z; o28[26] = Z;
    s[72] = f10; s[73] = f10; s[74] = Z; s[75] = Z;
    s[68] = f12; s[69] = f7; s[70] = f13; s[71] = f6;
    s[64] = Z; s[65] = Z; s[66] = Z; s[67] = Z;
    s[60] = Z; s[61] = Z; s[62] = H; s[63] = H;
    s[56] = f19; s[57] = Z; s[58] = Z; s[59] = f2;
    o28[27] = f2;
    o28[88] = f9;
    f8 = lbl_80562878 * p[68];
    f10 = p[70];
    f13 = lbl_80562884 * f8;
    f12 = lbl_80562880 * f10;
    f6 = lbl_8056287C * p[69];
    o28[89] = f9;
    f4 = lbl_80562888 * f10 - f12;
    f7 = lbl_80562890 * f8 * f6;
    o28[90] = f11;
    f5 = (lbl_8056288C * f8 - f13) / f4;
    o28[91] = f11;
    s[52] = f9; s[53] = f9; s[54] = f11; s[55] = f11;
    f4 = (lbl_80562894 * f8 * f6 - f7) / f4;
    s[49] = f5;
    f3 = f13 - f5 * f12;
    s[51] = f4;
    o28[40] = f3;
    f2 = f7 - f4 * f12;
    o28[41] = f5; o28[42] = f2; o28[43] = f4; o28[44] = f3; o28[45] = f5; o28[46] = f2;
    s[48] = f3; s[50] = f2;
    o28[47] = f4;
    for (i = 0; i < 4; i++) {
        float *q = p + 32 + i * 9;
        int lo = (i & 2) == 0;
        int ev = (i & 1) == 0;
        f4 = lo ? p[7] : K1 - p[7];
        f5 = lbl_80562898 * (H * f4 * p[0]);
        f2 = lo ? p[4] : p[5];
        f12 = H * f2 * (ev ? M1 : K1);
        f11 = lo ? K1 : M1;
        f9 = K1 - f4;
        o28[i * 4] = f12;
        s[44] = f12;
        s[46] = (f9 * p[6]) * f11;
        s[45] = (((q[6] - q[0]) - p[8]) - f5 / q[1]) - f5 / q[7];
        o28[i * 4 + 1] = s[45];
        o28[i * 4 + 2] = s[46];
        o28[i * 4 + 3] = s[47];
    }
    o28[48] = p[33]; o28[49] = p[42]; o28[50] = p[51]; o28[51] = p[60];
    o28[52] = p[34]; o28[53] = p[43]; o28[54] = p[52]; o28[55] = p[61];
    o28[56] = p[35]; o28[57] = p[44]; o28[58] = p[53]; o28[59] = p[62];
    o28[60] = p[30]; o28[61] = Z; o28[62] = p[31]; o28[63] = Z;
    o28[64] = p[36]; o28[65] = p[45]; o28[66] = p[54]; o28[67] = p[63];
    o28[68] = p[37]; o28[69] = p[46]; o28[70] = p[55]; o28[71] = p[64];
    o28[32] = p[39]; o28[33] = p[48]; o28[34] = p[57]; o28[35] = p[66];
    o28[36] = p[40]; o28[37] = p[49]; o28[38] = p[58]; o28[39] = p[67];
    o28[28] = p[38]; o28[29] = p[47]; o28[30] = p[56]; o28[31] = p[65];
    f3 = p[11];
    f20 = H * f3;
    f4 = H * (K1 - f3);
    f1 = lbl_8056289C; f2 = lbl_805628A0;
    o28[84] = f4; o28[85] = f4; o28[86] = f20; o28[87] = f20;
    o28[92] = f1; o28[93] = Z; o28[94] = Z; o28[95] = f2;
    s[40] = p[33]; s[41] = p[42]; s[42] = p[51]; s[43] = p[60];
    s[36] = p[34]; s[37] = p[43]; s[38] = p[52]; s[39] = p[61];
    s[32] = p[35]; s[33] = p[44]; s[34] = p[53]; s[35] = p[62];
    s[28] = p[30]; s[29] = Z; s[30] = p[31]; s[31] = Z;
    s[24] = p[36]; s[25] = p[45]; s[26] = p[54]; s[27] = p[63];
    s[20] = p[37]; s[21] = p[46]; s[22] = p[55]; s[23] = p[64];
    s[16] = p[39]; s[17] = p[48]; s[18] = p[57]; s[19] = p[66];
    s[12] = p[40]; s[13] = p[49]; s[14] = p[58]; s[15] = p[67];
    s[8] = p[38]; s[9] = p[47]; s[10] = p[56]; s[11] = p[65];
    s[4] = f4; s[5] = f4; s[6] = f20; s[7] = f20;
    s[0] = f1; s[1] = Z; s[2] = Z; s[3] = f2;
}
#pragma pop
extern float lbl_80562838, lbl_8056283C, lbl_80562854;
extern double fn_8002F234(float);
extern signed char lbl_8055E7A8;
void fn_801BE168(int index, float (*m)[3], float *a, float *b) {
    extern int lbl_8055E794;
    struct V4 { float x, y, z, w; };
    float out[4], t, q, inv;
    struct V4 pos, quat, la, lb;
    int i, j, k;
    float *dst = (float *)(lbl_8055E794 + index * 0xB0);
    t = m[0][0] + m[1][1] + m[2][2];
    pos.x = m[3][0]; pos.y = m[3][1]; pos.z = m[3][2];
    dst[0] = pos.x;
    dst[1] = pos.y;
    dst[2] = pos.z;
    dst[3] = pos.w;
    if (t > lbl_80562838) {
        q = fn_8002F234(lbl_8056283C + t);
        inv = lbl_80562854 / q;
        out[3] = lbl_80562854 * q;
        out[0] = inv * (m[1][2] - m[2][1]);
        out[1] = inv * (m[2][0] - m[0][2]);
        out[2] = inv * (m[0][1] - m[1][0]);
    } else {
        float *o = out;
        i = 0; if (m[1][1] > m[0][0]) i = 1; if (m[2][2] > m[i][i]) i = 2;
        j = (i + 1) % 3; k = (j + 1) % 3;
        q = fn_8002F234(lbl_8056283C + m[i][i] - (m[k][k] + m[j][j]));
        inv = lbl_80562854 / q;
        o[i] = lbl_80562854 * q;
        o[3] = inv * (m[j][k] - m[k][j]);
        o[j] = inv * (m[i][j] + m[j][i]);
        o[k] = inv * (m[i][k] + m[k][i]);
    }
    quat.x = -out[0]; quat.y = -out[1]; quat.z = -out[2]; quat.w = out[3];
    la.x = a[0]; la.y = a[1]; la.z = a[2];
    lb.x = b[0]; lb.y = b[1]; lb.z = b[2];
    dst[16] = quat.x; dst[17] = quat.y; dst[18] = quat.z; dst[19] = quat.w;
    dst[20] = la.x; dst[21] = la.y; dst[22] = la.z; dst[23] = la.w;
    dst[24] = lb.x; dst[25] = lb.y; dst[26] = lb.z; dst[27] = lb.w;
}

void fn_801BE400(int index, float *m, float scale) {
    float out[4], t, q, inv;
    float *dst = (float *)(lbl_8055E794 + index * 0xB0);
    void *p4 = (void *)(lbl_8055E7A4 + index * 0x14);
    float z = lbl_80562838;
    int i, j, k;

    t = m[0] + m[4] + m[8];
    dst[0] = m[9];
    dst[1] = m[10];
    dst[2] = m[11];
    if (t > z) {
        q = fn_8002F234(lbl_8056283C + t);
        inv = lbl_80562854 / q;
        out[3] = lbl_80562854 * q;
        out[0] = inv * (m[5] - m[7]);
        out[1] = inv * (m[6] - m[2]);
        out[2] = inv * (m[1] - m[3]);
    } else {
        i = 0;
        if (m[4] > m[0]) i = 1;
        if (m[8] > m[i * 4]) i = 2;
        j = (i + 1) % 3;
        k = (j + 1) % 3;
        q = fn_8002F234(lbl_8056283C + (m[i * 4] - (m[j * 4] + m[k * 4])));
        inv = lbl_80562854 / q;
        out[i] = lbl_80562854 * q;
        out[3] = inv * (m[j * 3 + k] - m[k * 3 + j]);
        out[j] = inv * (m[i * 3 + j] + m[j * 3 + i]);
        out[k] = inv * (m[i * 3 + k] + m[k * 3 + i]);
    }
    dst[16] = -out[0];
    dst[17] = -out[1];
    dst[18] = -out[2];
    dst[19] = out[3];
    memset(p4, 0, 0x14);
    fn_801E9DC4(p4);
    lbl_8055E7A8 = 1;
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
    char tmp90[16], tmp80[16], tmp70[16], tmp60[16], tmp50[16], tmp40[16];
    float v30[3], v24[3], m2[3], m1[3];
    int sp8;
    int i;
    for (i = 0; i < lbl_8055E78C; i++) {
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
    float temp_f0, temp_f1, temp_f2;
    temp_f2 = ((float *)arg1)[2];
    temp_f1 = ((float *)arg1)[1];
    temp_f0 = ((float *)arg1)[0];
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
