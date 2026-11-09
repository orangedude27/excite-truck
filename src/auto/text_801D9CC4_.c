// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern float lbl_80562B38;
extern float lbl_80562B3C;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void *fn_8012C370(void *, int, int *, int, int, u8 *);
extern void fn_802E317C(const char *, ...);
extern char lbl_80339200[];
extern char lbl_80339218[];
#define SWAP2(q, a, b) do { u8 t = (q)[a]; (q)[a] = (q)[b]; (q)[b] = t; } while (0)
#define SWAP4(q, o) do { SWAP2(q, (o), (o) + 3); SWAP2(q, (o) + 1, (o) + 2); } while (0)

void *fn_801D9CC4(void *arg0) {
    int type = 0;
    u8 flag = 0;
    volatile u8 *base;
    volatile u8 *e;
    volatile u8 *r;
    int i, j;
    base = (volatile u8 *)fn_8012C370(arg0, 0x50507468, &type, 0, 0, &flag);
    if (base == 0) {
        fn_802E317C(lbl_80339200, arg0);
        return 0;
    }
    if (type != 0) {
        fn_802E317C(lbl_80339218, arg0, 0);
        return 0;
    }
    if (flag != 0) {
        SWAP4(base, 0);
        e = base + 4;
        for (i = 0; i < *(s32 *)base; i++, e += 0x18) {
            SWAP4(e, 0x10);
            SWAP4(e, 0x14);
            *(u32 *)(e + 0x14) = (u32)base + *(u32 *)(e + 0x14);
            for (j = 0; j < *(s32 *)(e + 0x10); j++) {
                r = (volatile u8 *)*(u32 *)(e + 0x14) + j * 0x20;
                SWAP4(r, 0);
                SWAP4(r, 4);
                SWAP4(r, 8);
                SWAP4(r, 0xC);
                SWAP4(r, 0x10);
                SWAP4(r, 0x14);
                SWAP4(r, 0x18);
                SWAP4(r, 0x1C);
            }
        }
    }
    return (void *)base;
}

void fn_801D9F24(void) {
    fn_8012C4D8();
}

void fn_801D9F28(void *arg0) {
    volatile int *p = (volatile int *)arg0;
    float value = lbl_80562B38;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    *(volatile float *)((char *)arg0 + 0xC) = value;
}

extern int fn_80128668(void);
extern float lbl_80562B38;
extern int strcmp(const char *, const char *);
int fn_801D9F44(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

#pragma scheduling invalid_target
void fn_801D9F84(void *arg0, int *arg1) {
    float value = lbl_80562B38;
    int isNull = (arg1 == 0);
    *(int **)arg0 = arg1;
    *(int *)((char *)arg0 + 8) = 0;
    *(float *)((char *)arg0 + 0xC) = value;
    if (!isNull && *arg1 > 0)
        *(int *)((char *)arg0 + 4) = (int)(arg1 + 1);
    else
        *(int *)((char *)arg0 + 4) = 0;
}
#pragma scheduling on
#pragma use_lmw_stmw off
int fn_801D9FC4(char **arg0, const char *arg1) {
    register int count;
    register char *base;
    register int i;

    base = *arg0;
    count = *(int *)base;
    i = 0;
    while (i < count) {
        if (strcmp(base + i * 0x18 + 4, arg1) == 0)
            return 1;
        i++;
    }
    return 0;
}

void *fn_801DA03C(int **arg0, int arg1) {
    int *base = *arg0;
    if (arg1 < *base) {
        return (char *)base + arg1 * 0x18 + 4;
    }
    return 0;
}

#pragma use_lmw_stmw off
int fn_801DA064(void *arg0, const char *arg1, int arg2) {
    register int offset;
    register int count;
    register char *entries;
    register int index;
    char *base;

    base = *(char **)arg0;
    count = *(int *)base;
    entries = base + 4;
    index = 0;
    offset = 0;
    while (index < count) {
        if (strcmp(entries + offset, arg1) == 0) {
            *(char **)((char *)arg0 + 4) = entries + index * 0x18;
            return 1;
        }
        offset += 0x18;
        index++;
    }
    return 0;
}

void fn_801DA0EC(void *arg0, float farg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    int index;
    float *values;

    if (obj == 0) return;
    *(float *)((char *)arg0 + 0xC) = *(float *)((char *)arg0 + 0xC) + farg0;
    if (farg0 >= 0.0f) {
        do {
            index = *(int *)((char *)arg0 + 8) + 1;
            *(int *)((char *)arg0 + 8) = index;
            obj = *(void **)((char *)arg0 + 4);
            index = *(int *)((char *)arg0 + 8);
            if (index + 1 >= *(int *)((char *)obj + 0x10)) return;
            values = *(float **)((char *)obj + 0x14);
        } while (*(float *)((char *)arg0 + 0xC) > values[index * 8 + 8]);
    } else {
        do {
            index = *(int *)((char *)arg0 + 8) - 1;
            *(int *)((char *)arg0 + 8) = index;
            index = *(int *)((char *)arg0 + 8);
            if (index <= 0) return;
            obj = *(void **)((char *)arg0 + 4);
            values = *(float **)((char *)obj + 0x14);
        } while (values[index * 8] > *(float *)((char *)arg0 + 0xC));
    }
}

#pragma use_lmw_stmw reset

void fn_801DA198(void *arg0, float farg0) {
    register void *obj;
    register int index;
    float *values;
    *(float *)((char *)arg0 + 0xC) = farg0;
    *(int *)((char *)arg0 + 8) = 0;
    if (*(void **)((char *)arg0 + 4) == 0) return;
    while ((index = ++*(int *)((char *)arg0 + 8)) + 1 < *(int *)((char *)(obj = *(void **)((char *)arg0 + 4)) + 0x10)) {
        values = *(float **)((char *)obj + 0x14);
        if (values[index * 8 + 8] > *(float *)((char *)arg0 + 0xC)) return;
    }
}

int fn_801DA1F8(void *arg0, void **arg1, void **arg2, float *arg3) {
    register int index;
    register void *obj;
    register int max;
    register float *values;
    register float *next;
    register float *current;
    register float nextValue;
    register float value;
    register float difference;
    register float numerator;

    obj = *(void **)((char *)arg0 + 4);
    if (obj != 0) {
        max = *(int *)((char *)obj + 0x10) - 2;
        index = *(int *)((char *)arg0 + 8);
        if (max >= index) {
        } else {
            index = max;
        }

        values = *(float **)((char *)obj + 0x14);
        next = values + (index + 1) * 8;
        current = values + index * 8;
        nextValue = *next;
        value = *(float *)((char *)arg0 + 0xC);
        value = (value < nextValue) ? nextValue : value;
        difference = *next - *current;
        difference = (difference > lbl_80562B3C) ? difference : lbl_80562B3C;
        numerator = value - *current;

        *(float **)arg1 = current;
        *(float **)arg2 = next;
        *arg3 = numerator / difference;
        return 1;
    }
    return 0;
}

extern float lbl_80562B40, lbl_80562B44, lbl_80562B48, lbl_80562B4C, lbl_80558DC4;
extern double fn_8002F234(float);
extern double fn_8002EFA8(double);
extern double sin(double);
extern double __fabs(double);
extern int fn_801DA1F8(void *, void **, void **, float *);
extern float __fabsf(float);
#pragma processor 750
#pragma scheduling invalid_target
int fn_801DA294(void *arg0, void *arg1, void *arg2, void *arg3) {
    float *a, *b;
    float t, omt;
    float tr[3];
    float q[4];
    float inv, s, sc, len, w;
    float dl[3];
    float qa[4], qb[4];
    float ax[3];
    float *m = (float *)arg1;
    float *d = (float *)arg2;
    float *r = (float *)arg3;
    float x, y, z;
    float a2, b2, c2;
    a = 0;
    b = 0;
    t = lbl_80562B38;
    if (fn_801DA1F8(arg0, (void **)&a, (void **)&b, &t) == 0) return 0;
    z = a[3] + t * (b[3] - a[3]);
    y = a[2] + t * (b[2] - a[2]);
    x = a[1] + t * (b[1] - a[1]);
    m[0xB] = z;
    m[0xA] = y;
    tr[2] = z;
    m[9] = x;
    omt = lbl_80562B40 - t;
    q[3] = a[7] * omt + b[7] * t;
    q[2] = a[6] * omt + b[6] * t;
    q[0] = a[4] * omt + b[4] * t;
    q[1] = a[5] * omt + b[5] * t;
    tr[0] = x;
    tr[1] = y;
    inv = lbl_80562B40 / (float)fn_8002F234(q[0]*q[0] + (q[1]*q[1] + (q[3]*q[3] + q[2]*q[2])));
    q[1] *= inv; q[2] *= inv; q[0] *= inv; q[3] *= inv;
    a2 = q[1] + q[1]; b2 = q[2] + q[2]; c2 = q[0] + q[0];
    m[0] = lbl_80562B40 - (q[1]*a2 + q[2]*b2);
    m[4] = lbl_80562B40 - (q[0]*c2 + q[2]*b2);
    m[8] = lbl_80562B40 - (q[0]*c2 + q[1]*a2);
    m[6] = q[0]*b2 + q[3]*a2;
    m[3] = q[0]*a2 - q[3]*b2;
    m[1] = q[0]*a2 + q[3]*b2;
    m[7] = q[1]*b2 - q[3]*c2;
    m[2] = q[0]*b2 - q[3]*a2;
    m[5] = q[1]*b2 + q[3]*c2;
    len = b[0] - a[0];
    w = lbl_80562B44;
    if (w <= len) w = len;
    sc = lbl_80562B40 / w;
    dl[0] = b[1] - a[1];
    dl[1] = b[2] - a[2];
    dl[2] = b[3] - a[3];
    d[0] = dl[0] * sc;
    d[1] = dl[1] * sc;
    d[2] = dl[2] * sc;
    qa[0] = a[4] * lbl_80562B48;
    qa[1] = a[5] * lbl_80562B48;
    qa[2] = a[6] * lbl_80562B48;
    qa[3] = a[7] * lbl_80562B48;
    qb[0] = b[4] + qa[0];
    qb[1] = b[5] + qa[1];
    qb[2] = b[6] + qa[2];
    qb[3] = b[7] + qa[3];
    len = fn_8002EFA8(qb[3]);
    w = sin(len);
    if (__fabsf(w) > lbl_80558DC4) {
        s = lbl_80562B4C * len / w;
        ax[0] = qb[0] * s;
        ax[1] = qb[1] * s;
        ax[2] = qb[2] * s;
    } else {
        ax[0] = lbl_80562B38;
        ax[1] = lbl_80562B38;
        ax[2] = lbl_80562B38;
    }
    r[0] = ax[0] * sc;
    r[1] = ax[1] * sc;
    r[2] = ax[2] * sc;
    return 1;
}
int fn_801DA648(void *arg0) {
    void *obj;
    int count;
    float *values;
    obj = *(void **)((char *)arg0 + 4);
    if (obj != 0) {
        count = *(int *)((char *)obj + 0x10);
        values = *(float **)((char *)obj + 0x14);
        return *(float *)((char *)arg0 + 0xC) >= values[(count - 1) * 8];
    }
    return 0;
}

int fn_801DA688(void *arg0) {
    if (*(void **)((char *)arg0 + 4) != 0)
        return *(float *)((char *)arg0 + 0xC) <= lbl_80562B38;
    return 0;
}

extern float lbl_80562B3C;
float fn_801DA6B8(void *arg0) {
    void *obj = *(void **)((char *)arg0 + 4);
    if (obj != 0) {
        int count = *(int *)((char *)obj + 0x10);
        float *values = *(float **)((char *)obj + 0x14);
        return values[(count - 1) * 8];
    }
    return lbl_80562B38;
}

