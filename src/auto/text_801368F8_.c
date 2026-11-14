// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef float f32;
typedef signed char s8;
typedef unsigned char u8;

/* The "proxer" (lbl_8055E0D0 / lbl_8055E0D4): the pairwise proximity table of
 * the racing cars. One ProxPair record per unordered pair of cars, plus one
 * ProxRow per car; every row carries three planes of carCount ProxPair
 * pointers, so a car can look up its relation to any other car (its own
 * entries stay 0). */
typedef struct ProxPair {
    s8 near;                    /* +0x00 the two cars are within the radius */
    u8 pad01[3];
    f32 time;                   /* +0x04 seconds until the two would meet */
    u8 hitA;                    /* +0x08 car A (+0x0C) is about to be hit */
    u8 pad09[3];
    s32 indexA;                 /* +0x0C the pair's lower car index */
    u8 hitB;                    /* +0x10 car B (+0x14) is about to be hit */
    u8 pad11[3];
    s32 indexB;                 /* +0x14 the pair's higher car index */
    f32 distSq;                 /* +0x18 dx * dx + dz * dz */
    f32 dx;                     /* +0x1C B's x minus A's */
    f32 dz;                     /* +0x20 B's z minus A's */
    f32 dSpeed;                 /* +0x24 B's speed minus A's */
    f32 dVelocity;              /* +0x28 B's forward velocity minus A's */
} ProxPair;                     /* 0x2C bytes */

typedef struct ProxRow {
    f32 x;                      /* +0x00 */
    f32 z;                      /* +0x04 */
    f32 speed;                  /* +0x08 */
    f32 velocity;               /* +0x0C */
    u8 pad10[4];
    u8 flag14;                  /* +0x14 */
    u8 active;                  /* +0x15 this car's row is filled in */
    u8 state;                   /* +0x16 the car's state bits */
    u8 pad17;
    ProxPair *relations[1];     /* +0x18 plane 0; 3 planes of carCount follow */
} ProxRow;                      /* 0x18 + 12 * carCount bytes */

typedef struct Proxer {
    s32 carCount;               /* +0x00 how many cars the table covers */
    s32 sortIndex;              /* +0x04 car the last sort (fn_801376A8) was for */
    ProxPair *pairs;            /* +0x08 carCount * (carCount - 1) / 2 records */
    s32 rowStride;              /* +0x0C bytes per row: 0x18 + 12 * carCount */
    ProxRow *rows;              /* +0x10 one row per car */
    f32 time;                   /* +0x14 time the table was built */
} Proxer;                       /* 0x18 bytes */
#define F(p,o) (*(f32 *)((char *)(p)+(o)))
#define I(p,o) (*(s32 *)((char *)(p)+(o)))
#define B(p,o) (*(unsigned char *)((char *)(p)+(o)))
extern s32 lbl_8055E0D4;
extern s32 lbl_8055E0D0;
extern s32 lbl_80559BF8;
extern void fn_80136AA8(void*);
extern s32 fn_80136A18(s32, s32);
extern s32 fn_801284F8(s32, s32*);
/* fn_801368F8 (the proxer constructor) is defined below with its real types. */
extern f32 lbl_80561368;
extern f32 lbl_8056136C;
extern f32 lbl_80561370;
extern f32 lbl_80561374;
extern s32 lbl_8032BEB4[];
extern void fn_801376A8(s32, s32 *, s32, s32, s32 *);
extern void fn_80136D20(void *, s32);
extern s32 fn_8017960C(s32);
extern s32 fn_802C6C34(s32);
extern void *fn_801B2ED0(s32);
#pragma push
#pragma scheduling invalid_target
extern const char lbl_8032BE98[];   /* allocation tag: "proxer delta." */
extern const char lbl_8032BEA8[];   /* allocation tag: "proxer tab" */
extern void *fn_8012850C(s32 size, const char *tag);
extern void *fn_801284E8(const char *tag, s32 size);
extern s32 fn_8002F37C();
extern void *memset(void *, s32, s32);
extern float fn_8013672C(void);
extern void fn_801369EC(void *);
#pragma scheduling invalid_target
/* Builds the proximity table ("proxer") for carCount cars: one ProxPair record
 * per unordered pair of cars, cleared and constructed by fn_801369EC, plus a
 * carCount-row table whose rows hold three planes of pair pointers, which
 * fn_80136AA8 links up (a car's own entries stay 0). Returns the table, or the
 * half-built one if either allocation failed. */
Proxer *fn_801368F8(Proxer *proxer, s32 carCount) {
    s32 pairCount;
    s32 allocCount;
    s32 rowStride;
    s32 rowSize;
    s32 tableSize;
    ProxRow *rows;
    s32 product;
    s32 sign;
    product = carCount * (carCount - 1);
    sign = (s32)(((unsigned)product) >> 31);
    pairCount = (sign + product) >> 1; /* product / 2, rounded down */
    proxer->carCount = carCount;
    allocCount = (pairCount > 1) ? pairCount : 1;
    proxer->pairs = (ProxPair *)fn_8002F37C(fn_8012850C(allocCount * sizeof(ProxPair) + 0x10, lbl_8032BE98), (s32)&fn_801369EC, 0, sizeof(ProxPair), allocCount);
    rowStride = carCount * 4 - carCount; /* the row's three pointer planes */
    rowSize = rowStride * 4 + 0x18;
    proxer->rowStride = rowSize;
    tableSize = carCount * rowSize;
    rows = (ProxRow *)fn_801284E8(lbl_8032BEA8, tableSize);
    proxer->rows = rows;
    if (rows != 0 && proxer->pairs != 0) {
        memset(rows, 0, tableSize);
        fn_80136AA8(proxer);
    }
    proxer->time = fn_8013672C();
    return proxer;
}
void fn_801369EC(void *arg0) {
    f32 value = lbl_80561368;
    *(s32 *)((char *)arg0 + 0x14) = -1;
    *(f32 *)((char *)arg0 + 0x28) = value;
    *(f32 *)((char *)arg0 + 0x24) = value;
    *(f32 *)((char *)arg0 + 0x20) = value;
    *(f32 *)((char *)arg0 + 0x1C) = value;
    *(s32 *)((char *)arg0 + 0xC) = -1;
    *(signed char *)arg0 = 0;
}

#pragma dont_inline on
s32 fn_80136A18(s32 self, s32 deleteFlag) {
    /* Destroy owned buffers/state for the object, clear the global active pointer, and optionally free the object. */
    if (self != 0) {
        if (*(s32 *)(self + 0x10) != 0) {
            fn_80128658(*(s32 *)(self + 0x10));
            *(s32 *)(self + 0x10) = 0;
        }
        if (*(s32 *)(self + 8) != 0) {
            if (*(s32 *)(self + 8) != 0)
                fn_80128670(*(s32 *)(self + 8) - 0x10);
            *(s32 *)(self + 8) = 0;
        }
        lbl_8055E0D0 = 0;
        if (deleteFlag > 0)
            fn_80128668((void *)self);
    }
    return self;
}

void fn_80136AA8(void *g) {
    int i, j;
    int k = 0;
    int zero = 0;
    for (i = 0; i < I(g, 0); i++) {
        short si = i;
        B(I(g, 0x10) + i * I(g, 0xC), 0x15) = 1;
        I(i * I(g, 0xC) + (i * 4 + I(g, 0x10)), 0x18) = zero;
        I((I(g, 0) + i) * 4 + (I(g, 0x10) + i * I(g, 0xC)), 0x18) = zero;
        I((i + I(g, 0) * 2) * 4 + (I(g, 0x10) + i * I(g, 0xC)), 0x18) = zero;
        for (j = i + 1; j < I(g, 0); j++) {
            short sj = j;
            I(i * I(g, 0xC) + (j * 4 + I(g, 0x10)), 0x18) = I(g, 8) + k;
            I((j + I(g, 0)) * 4 + (I(g, 0x10) + i * I(g, 0xC)), 0x18) = I(g, 8) + k;
            I((j + I(g, 0) * 2) * 4 + (I(g, 0x10) + i * I(g, 0xC)), 0x18) = I(g, 8) + k;
            I(j * I(g, 0xC) + (i * 4 + I(g, 0x10)), 0x18) = I(g, 8) + k;
            I(I(g, 0) * 4 + (j * I(g, 0xC) + (i * 4 + I(g, 0x10))), 0x18) = I(g, 8) + k;
            I(I(g, 0) * 8 + (j * I(g, 0xC) + (i * 4 + I(g, 0x10))), 0x18) = I(g, 8) + k;
            I(I(g, 8) + k, 0xC) = si;
            I(I(g, 8) + k, 0x14) = sj;
            k += 0x2C;
        }
    }
}

#pragma dont_inline reset

void fn_80136CB8(void *arg0, s32 arg1) {
    s32 base;
    f32 value;
    fn_80136D20(arg0, arg1);
    value = lbl_80561368;
    base = *(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC);
    *(f32 *)((char *)base + 8) = value;
    *(f32 *)((char *)base + 0xC) = value;
    base = *(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC);
    *(f32 *)((char *)base + 0x10) = value;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma opt_propagation off
extern "C" void fn_80136D20(void *arg0, s32 arg1) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void *v4();
    };
    int stride = *(int*)((char*)arg0 + 0xC);
    void *base = *(void**)((char*)arg0 + 0x10);
    void *entry = (char*)base + arg1 * stride;
    void *obj = ((Dummy*)fn_801B2ED0(arg1))->v4();
    if (*(unsigned char*)((char*)entry + 0x15) != 0) {
        volatile unsigned char zero = 0;
        *(unsigned char*)((char*)entry + 0x14) = zero;
        void *r5 = *(void**)((char*)obj + 4);
        float f2 = *(float*)((char*)obj + 8);
        void *r4 = *(void**)((char*)r5 + 0x14);
        float f1 = *(float*)((char*)r5 + 0x2C);
        float f0 = *(float*)((char*)r4 + 0x2C);
        float f3 = *(float*)((char*)obj + 0x40);
        f0 = (f0 - f1) * f2 + f1;
        f2 = f3 + f0;
        f1 = *(float*)((char*)obj + 0x48) + *(float*)((char*)r5 + 0x30);
        if (zero != 0) {
            f1 = *(float*)((char*)arg0 + 0x14) - f1;
        }
        *(float*)((char*)entry + 8) = *(float*)((char*)obj + 0x44);
        *(float*)((char*)entry + 0) = f2;
        *(float*)((char*)entry + 4) = f1;
        f2 = *(float*)((char*)entry + 0xC);
        *(float*)((char*)entry + 0xC) = *(float*)((char*)obj + 0x4C);
        if (*(unsigned char*)((char*)entry + 0x14) != 0) {
            *(float*)((char*)entry + 0xC) *= lbl_8056136C;
        }
        f0 = *(float*)((char*)entry + 0xC);
        f1 = (f0 - f2) / lbl_80561370;
        f3 = *(float*)((char*)entry + 0x10);
        f0 = (f1 - f3) * lbl_80561374 + f3;
        *(float*)((char*)entry + 0x10) = f0;
        unsigned char flag = *(unsigned char*)((char*)*(void**)((char*)obj + 4) + 0x35);
        *(unsigned char*)((char*)entry + 0x16) = flag;
        if ((flag & ~1) && (flag & 1)) {
            void *sub = *(void**)((char*)*(void**)((char*)obj + 4) + 0x14);
            if (!(*(unsigned char*)((char*)sub + 0x35) & 1)) {
                *(unsigned char*)((char*)entry + 0x16) &= ~1;
            }
        }
    } else {
        float zero2 = lbl_80561368;
        *(float*)((char*)entry + 4) = zero2;
        *(float*)((char*)entry + 0) = zero2;
        *(float*)((char*)entry + 0xC) = zero2;
        *(float*)((char*)entry + 8) = zero2;
        *(unsigned char*)((char*)entry + 0x16) = 0;
    }
}
#pragma opt_propagation reset
#pragma scheduling reset
#pragma cplusplus reset
#pragma pop

void fn_80136E8C(void *arg0, s32 arg1, signed char arg2) {
    *(signed char *)((char *)*(s32 *)((char *)arg0 + 0x10) + arg1 * *(s32 *)((char *)arg0 + 0xC) + 0x15) = arg2;
}

void fn_80136EA4(void *arg0, s32 arg1) {
    s32 values[3];
    s32 *source;
    s32 stride;
    s32 index;
    s32 *base;
    s32 destination;
    s32 tmp;

    source = lbl_8032BEB4;
    values[0] = *source++;
    values[1] = *source++;
    values[2] = *source++;
    stride = *(s32 *)((char *)arg0 + 0xC);
    index = *(s32 *)arg0;
    tmp = arg1 * stride;
    base = *(s32 **)((char *)arg0 + 0x10);
    destination = (s32)base + tmp;
    destination += index * 8;
    destination += 0x18;
    fn_801376A8((s32)arg0, (s32 *)destination, (s32)values, arg1, base);
}

extern void *fn_801B2ED0(int);
extern void fn_8013776C(void*);
#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_801B2ED0(int);
extern "C" void fn_8013776C(void*);
extern "C" void fn_80136F08(void *arg0) {
    struct Dummy {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void *v6();
    };
    void *entry;
    int index;
    int entryCount;
    int pairCount;
    int pairOffset;
    int pairIndex;

    /* Copies per-entry data from fn_801B2ED0(index)->v6() and recomputes all pairwise deltas. */
    index = 0;
    while (index < *(int*)arg0) {
        int stride = *(int*)((char*)arg0 + 0xC);
        entry = (char*)*(void**)((char*)arg0 + 0x10) + index * stride;
        void *obj = fn_801B2ED0(index);
        obj = ((Dummy*)obj)->v6();
        *(float*)entry = *(float*)((char*)obj + 0x60);
        *(float*)((char*)entry + 4) = *(float*)((char*)obj + 0x68);
        *(float*)((char*)entry + 8) = *(float*)((char*)obj + 0x118);
        *(float*)((char*)entry + 0xC) = *(float*)((char*)obj + 0x120);
        *((unsigned char*)entry + 0x16) = 1;
        index++;
    }
    entryCount = *(int*)arg0;
    pairCount = entryCount * (entryCount - 1) / 2;
    pairIndex = 0;
    pairOffset = 0;
    while (pairIndex < pairCount) {
        void *p;
        void *a;
        void *b;
        int stride;
        void *base;
        void *pair;

        stride = *(int*)((char*)arg0 + 0xC);
        pair = (char*)*(void**)((char*)arg0 + 8) + pairOffset;
        base = *(void**)((char*)arg0 + 0x10);
        a = (char*)base + *(int*)((char*)pair + 0xC) * stride;
        b = (char*)base + *(int*)((char*)pair + 0x14) * stride;
        *(float*)((char*)pair + 0x24) = *(float*)((char*)b + 8) - *(float*)((char*)a + 8);
        *(float*)((char*)pair + 0x28) = *(float*)((char*)b + 0xC) - *(float*)((char*)a + 0xC);
        p = (char*)*(void**)((char*)arg0 + 8) + pairOffset;
        *(float*)((char*)p + 0x1C) = *(float*)((char*)b + 0) - *(float*)((char*)a + 0);
        *(float*)((char*)p + 0x20) = *(float*)((char*)b + 4) - *(float*)((char*)a + 4);
        fn_8013776C((char*)*(void**)((char*)arg0 + 8) + pairOffset);
        pairOffset += 0x2C;
        pairIndex++;
    }
}
#pragma scheduling reset
#pragma cplusplus reset
#pragma pop
s32 fn_8013705C(f32 arg0, f32 arg1) {
    return arg0 * arg1 >= lbl_80561368;
}

extern float PSVECDotProduct(const void *, const void *);
s32 fn_80137078(void *arg0, void *arg1, f32 farg0, f32 farg1) {
    f32 sp28, sp24, sp20, sp1C, sp18, sp14, sp10, spC, sp8;
    f32 temp_f10, temp_f11, temp_f1, temp_f2, temp_f3, temp_f4, temp_f5;
    f32 temp_f6, temp_f7, temp_f8, temp_f9;
    temp_f10 = *(f32 *)((char *)arg0 + 0x1C) * farg0;
    temp_f8 = *(f32 *)((char *)arg0 + 0x20) * farg0;
    temp_f11 = *(f32 *)((char *)arg0 + 0x24) + (*(f32 *)((char *)arg0 + 0x18) * farg0);
    temp_f6 = *(f32 *)((char *)arg1 + 0x24) + (*(f32 *)((char *)arg1 + 0x18) * farg1);
    temp_f7 = *(f32 *)((char *)arg0 + 0x2C);
    temp_f4 = *(f32 *)((char *)arg1 + 0x28) + (*(f32 *)((char *)arg1 + 0x1C) * farg1);
    temp_f9 = *(f32 *)((char *)arg0 + 0x28) + temp_f10;
    temp_f3 = *(f32 *)((char *)arg1 + 0x2C) + (*(f32 *)((char *)arg1 + 0x20) * farg1);
    temp_f5 = temp_f7 + temp_f8;
    sp20 = temp_f11;
    temp_f2 = temp_f11 - temp_f6;
    temp_f1 = temp_f9 - temp_f4;
    sp24 = temp_f9;
    sp28 = temp_f5;
    sp14 = temp_f6;
    sp18 = temp_f4;
    sp1C = temp_f3;
    sp8 = temp_f2;
    spC = temp_f1;
    sp10 = temp_f5 - temp_f3;
    PSVECDotProduct(&sp8, (char *)arg1 + 0x18);
    return PSVECDotProduct(&sp8, (char *)arg1 + 0x18) < lbl_80561368;
}

#pragma dont_inline on
s32 fn_80137140(s32 arg0, s32 arg1) {
    s32 oB;
    s32 wA;
    s32 wB;
    s32 res;
    s32 oA;
    f32 f1a;
    f32 f2a;
    oA = fn_8017960C(arg0);
    oB = fn_8017960C(arg1);
    wA = fn_802C6C34(*(s32 *)(oA + 0x59C));
    wB = fn_802C6C34(*(s32 *)(oB + 0x59C));
    f1a = *(f32 *)(wA + 0x40);
    f2a = *(f32 *)(wB + 0x3C);
    res = 0;
    if (fn_80137078((void *)(oA + 0x3C), (void *)(oB + 0x3C), f1a, f2a)) {
        f1a = *(f32 *)(wB + 0x40);
        f2a = *(f32 *)(wA + 0x3C);
        if (fn_80137078((void *)(oB + 0x3C), (void *)(oA + 0x3C), f1a, f2a)) {
            res = 1;
        }
    }
    return res;
}

extern void *fn_80137C54(int);
extern float lbl_80561378, lbl_8056137C, lbl_80561380, lbl_80561384, lbl_80561388, lbl_8056138C, lbl_80561390;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_801371E0(void *arg0) {
    register float c90, c8c, c68, c88, c84, threshold, c78, radius, limit;
    float dy, sign, velocity, distance, t, ya, yb;
    register void *a, *b;
    register int offset, i, count;
    int flag;
    int stride;
    void *pair, *base;
    radius = F(fn_80137C54(-1), 4);
    fn_80137C54(-1);
    count = I(arg0, 0) * (I(arg0, 0) - 1) / 2;
    threshold = radius * lbl_80561380;
    c90 = lbl_80561390; c8c = lbl_8056138C; c68 = lbl_80561368;
    c88 = lbl_80561388; c78 = lbl_80561378; c84 = lbl_80561384;
    i = 0;
    offset = 0;
    for (; i < count; offset += 0x2c, i++) {
        stride = I(arg0, 0xc);
        pair = (char *)I(arg0, 8) + offset;
        base = (void *)I(arg0, 0x10);
        a = (char *)base + I(pair, 0xc) * stride;
        b = (char *)base + I(pair, 0x14) * stride;
        F(pair, 0x24) = F(b, 8) - F(a, 8);
        F(pair, 0x28) = F(b, 0xc) - F(a, 0xc);
        pair = (char *)I(arg0, 8) + offset;
        F(pair, 0x1c) = F(b, 0) - F(a, 0);
        F(pair, 0x20) = F(b, 4) - F(a, 4);
        ya = F(a, 4);
        yb = F(b, 4);
        dy = yb - ya;
        if ((float)__fabs(dy) > F(arg0, 0x14) * c78 && !((B(a, 0x16) | B(b, 0x16)) & 8)) {
            sign = dy > c68 ? lbl_8056137C : lbl_8056136C;
            dy += F(arg0, 0x14) * -sign;
        }
        flag = 0;
        F((char *)I(arg0, 8) + offset, 0x20) = dy;
        if ((float)__fabs(dy) < threshold && fn_80137140(I((char *)I(arg0, 8) + offset, 0xc), I((char *)I(arg0, 8) + offset, 0x14)))
            flag = 1;
        B((char *)I(arg0, 8) + offset, 0) = flag;
        F((char *)I(arg0, 8) + offset, 4) = c84;
        if (B(a, 0x16) & B(b, 0x16)) {
            pair = (char *)I(arg0, 8) + offset;
            if (!B(pair, 0)) {
                limit = c88 * radius;
                if (fn_8013705C(F(a, 0xc), F(b, 0xc))) {
                    sign = F(a, 0xc) > c68 ? lbl_8056137C : lbl_8056136C;
                    if (sign * F(pair, 0x20) > c68) {
                        B(pair, 0x10) = 0;
                        velocity = sign * F(pair, 0x28);
                        if (velocity < c8c) {
                            distance = sign * F(pair, 0x20);
                            t = -((distance - radius) / velocity);
                            if (t < c90 || distance <= limit) {
                                B(pair, 8) = 1;
                                F(pair, 4) = t;
                            } else B(pair, 8) = 0;
                        } else if (sign * F(pair, 0x20) <= limit) {
                            F(pair, 4) = c90;
                            B(pair, 8) = 1;
                        } else B(pair, 8) = 0;
                    } else {
                        B(pair, 8) = 0;
                        velocity = F(pair, 0x28);
                        if (sign * -velocity < c8c) {
                            distance = F(pair, 0x20);
                            t = -((radius + sign * distance) / (sign * velocity));
                            if (t < c90 || sign * -distance <= limit) {
                                B(pair, 0x10) = 1;
                                F(pair, 4) = t;
                            } else B(pair, 0x10) = 0;
                        } else if (sign * -F(pair, 0x20) <= limit) {
                            F(pair, 4) = c90;
                            B(pair, 0x10) = 1;
                        } else B(pair, 0x10) = 0;
                    }
                } else if (!fn_8013705C(F(pair, 0x28), F(pair, 0x20))) {
                    distance = F(pair, 0x20);
                    velocity = F(pair, 0x28);
                    distance = (float)__fabs(distance);
                    velocity = (float)__fabs(velocity);
                    F(pair, 4) = (distance - radius) / velocity;
                    B(pair, 0x10) = 1;
                    B(pair, 8) = 1;
                } else {
                    B(pair, 0x10) = 0;
                    B(pair, 8) = 0;
                }
            } else {
                B(pair, 0x10) = 1;
                B(pair, 8) = 1;
            }
        } else {
            B((char *)I(arg0, 8) + offset, 0x10) = 0;
            B((char *)I(arg0, 8) + offset, 8) = 0;
        }
        fn_8013776C((char *)I(arg0, 8) + offset);
    }
}
#pragma pop
extern float lbl_80561368;
extern float lbl_80561394;
extern float __fabsf(float);
extern double __fabs(double);
int fn_80137598(void *context, void *left, void *right) {
    unsigned char leftState;
    unsigned char rightState;
    int contextId;
    float diff;

    /* Compare two entries for the given context id, by state flags and value. */
    if (left == 0 || right == 0)
        goto null_arg;

    contextId = *(int*)((char*)context + 4);
    if (contextId == *(int*)((char*)left + 0xC))
        leftState = *(unsigned char*)((char*)left + 8);
    else
        leftState = *(unsigned char*)((char*)left + 0x10);

    if (contextId == *(int*)((char*)right + 0xC))
        rightState = *(unsigned char*)((char*)right + 8);
    else
        rightState = *(unsigned char*)((char*)right + 0x10);

    if (leftState ^ rightState) {
        if (leftState != 0)
            return -1;
        return 1;
    }

    if (leftState != 0 && rightState != 0) {
        if (*(unsigned char*)left != 0 || *(unsigned char*)right != 0) {
            if (*(unsigned char*)left ^ *(unsigned char*)right) {
                if (*(unsigned char*)left == 0)
                    return -1;
                return 1;
            }
            return 0;
        }

        diff = *(float*)((char*)left + 4) - *(float*)((char*)right + 4);
        if ((float)__fabs(diff) < lbl_80561394)
            return 0;
        if (diff > lbl_80561368)
            return 1;
        return -1;
    }

    return 0;

null_arg:
    return left == 0 ? 1 : -1;
}

s32 fn_8002F768(void *, s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_801376A8(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 *arg4) {
    struct CompareObject { s32 compare(s32, s32); };
    typedef s32 (CompareObject::*CompareMethod)(s32, s32);
    register s32 *item;
    register s32 flag;
    register s32 start;
    register s32 length;
    register s32 end;
    register s32 index;
    register s32 temp;
    register CompareMethod *method;
    register s32 *array;
    *(s32 *)(arg0 + 4) = arg3;
    length = *(volatile s32 *)arg0;
    array = arg1;
    method = (CompareMethod *)arg2;
    start = 0;
    do {
        index = start + 1;
        item = array + index;
        end = length;
        flag = 1;
        while (index < length) {
            if ((((CompareObject *)arg0)->*(*method))(item[-1], item[0]) > 0) {
                temp = item[-1];
                end = index + 1;
                item[-1] = item[0];
                item[0] = temp;
                if (flag != 0) {
                    temp = index - 2;
                    start = temp & ~(temp >> 31);
                }
                flag = 0;
            }
            item++;
            index++;
        }
        length = end;
    } while (flag == 0);
}
#pragma scheduling on
#pragma cplusplus reset
#pragma pop
void fn_8013776C(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f0 = *(f32 *)((char *)arg0 + 0x20);
    temp_f1 = *(f32 *)((char *)arg0 + 0x1C);
    *(f32 *)((char *)arg0 + 0x18) = temp_f1 * temp_f1 + temp_f0 * temp_f0;
}

void fn_80137788(void *arg0, s32 arg1, void *arg2) {
    extern f32 lbl_8056136C;
    s32 state;
    s32 stride;
    long id;
    s32 difference;
    s32 entries;
    s32 entry;
    unsigned int equal;
    register unsigned char flag;
    f32 x;
    f32 y;
    f32 scale;

    state = lbl_8055E0D0;
    stride = *(s32 *)((char *)state + 0xC);
    id = *(s32 *)((char *)arg0 + 0x14);
    difference = id - arg1;
    entries = *(s32 *)((char *)state + 0x10);
    entry = entries + arg1 * stride;
    flag = *(unsigned char *)((char *)entry + 0x14);
    equal = difference == 0;
    if ((equal ^ flag) != 0) {
        x = *(f32 *)((char *)arg0 + 0x1C);
        scale = lbl_8056136C;
        x = x * scale;
        y = *(f32 *)((char *)arg0 + 0x20);
        *(f32 *)arg2 = x;
        y = y * scale;
        *(f32 *)((char *)arg2 + 4) = y;
        return;
    }
    y = *(f32 *)((char *)arg0 + 0x20);
    x = *(f32 *)((char *)arg0 + 0x1C);
    *(f32 *)((char *)arg2 + 4) = y;
    *(f32 *)arg2 = x;
}

void fn_801377EC(void *arg0, s32 arg1, void *arg2) {
    extern f32 lbl_8056136C;
    s32 state;
    s32 stride;
    s32 entries;
    s32 difference;
    s32 id;
    s32 entry;
    register s32 equal;
    unsigned char flag;
    f32 x;
    f32 y;
    f32 scale;

    state = lbl_8055E0D0;
    stride = *(s32 *)((char *)state + 0xC);
    id = *(s32 *)((char *)arg0 + 0x14);
    difference = id - arg1;
    entries = *(s32 *)((char *)state + 0x10);
    entry = entries + arg1 * stride;
    flag = *(unsigned char *)((char *)entry + 0x14);
    equal = difference == 0;
    if ((equal ^ flag) != 0) {
        x = *(f32 *)((char *)arg0 + 0x24);
        scale = lbl_8056136C;
        y = *(f32 *)((char *)arg0 + 0x28);
        x = x * scale;
        y = y * scale;
        *(f32 *)arg2 = x;
        *(f32 *)((char *)arg2 + 4) = y;
        return;
    }
    y = *(f32 *)((char *)arg0 + 0x28);
    x = *(f32 *)((char *)arg0 + 0x24);
    *(f32 *)((char *)arg2 + 4) = y;
    *(f32 *)arg2 = x;
}

float fn_80137850(void *arg0)
{
  float new_var;
  float *new_var2;
  int index = (*((int *) (((char *) arg0) - (-0x18)))) * (*((int *) (lbl_8055E0D0 + 0xC)));
  int base;
  float *p = (float *) ((*((int *) (lbl_8055E0D0 + 0x10))) + index);
  new_var2 = *((float **) arg0);
  return p[0] + ((new_var = new_var2[1]) * p[2]);
}

void fn_80137884(s32 arg0) {
 s32 var_r3 = fn_801284F8(0x18, &lbl_80559BF8);
 if (var_r3 != 0) var_r3 = ((s32 (*)(s32, s32))fn_801368F8)(var_r3, arg0);
 lbl_8055E0D4 = var_r3;
 lbl_8055E0D0 = var_r3;
}

void fn_801378D0(void) {
 fn_80136A18(lbl_8055E0D4, 1);
 lbl_8055E0D4 = 0; lbl_8055E0D0 = 0;
}

void fn_80137904(void) { fn_80136AA8((void*)lbl_8055E0D4); }
