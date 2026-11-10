// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;

static inline float Vec2Dot_802A0F7C(const float *a, const float *b) {
    return a[0] * b[0] + a[1] * b[1];
}

extern double fabs(double);
extern float lbl_805646F0;
extern double __fabs(double);
extern float lbl_80558DC4[];
extern float lbl_805646E8, lbl_805646EC, lbl_805646F4;
extern void fn_801E9E30(s32, float *);
extern void fn_802CA09C(s32, u32, u32, float, float, float, float, float);
extern void fn_802A9428(void);
extern s32 lbl_8055F840;
extern s32 lbl_8055F844;
extern void fn_802C8BD0(s32);
extern void fn_802CA0A0(s32);
extern void fn_802C8D74(void);
extern void fn_802CAC54(s32);
extern void fn_802CA094(s32);
extern void fn_802A93A4(void);
extern void *fn_8000AC38(void);
extern s32 fn_80161C38(void);
extern char lbl_80349900[];
#pragma ppc_psq_save off
void fn_802A0D60(s32 arg0, float *arg1, float *arg2, float *arg3, s32 arg4, float farg0, float farg1) {
    float sp10[3];
    float v;
    s32 i, c;
    u32 color;
    s32 n;
    float zero;
    if (arg4 != 0 && !((float)__fabs(farg1) <= lbl_80558DC4[0])) {
        v = lbl_805646E8 * farg1;
        if (v < lbl_805646F0)
            v = v - lbl_805646EC;
        else
            v = lbl_805646EC + v;
        i = (s32)v;
        c = 0xFF;
        i = i > 0 ? i : 0;
        if (i < 0xFF)
            c = i;
        n = -arg4;
        color = ((n & 0xFF) | ((n << 8) & 0xFF00)) | (((n << 16) & 0xFF0000) | (c << 24));
        zero = lbl_805646F0;
        for (i = 0; i < 4; i++) {
            u32 a = i & 1;
            u32 b = i & 2;
            u32 a1 = a ^ 1;
            u32 a2 = a == 0;
            u32 b1 = (((u32)i >> 1) & 1) ^ 1;
            u32 b2 = b == 0;
            float x, y, u, w;
            x = arg1[0] + arg2[0] * (farg0 * (float)a1) + arg3[0] * (farg0 * (float)b1);
            y = arg1[1] + arg2[1] * (farg0 * (float)a2) + arg3[1] * (farg0 * (float)b2);
            sp10[0] = x;
            sp10[1] = zero;
            sp10[2] = y;
            fn_801E9E30(arg0, sp10);
            u = a != 0 ? lbl_805646F4 : lbl_805646F0;
            w = b != 0 ? lbl_805646F4 : lbl_805646F0;
            fn_802CA09C(lbl_8055F840, color, (u32)(((i ^ 1) >> 1) - ((i ^ 1) & i)) >> 31, sp10[0], sp10[1], sp10[2], u, w);
        }
    }
}
#pragma cplusplus on
extern "C" s32 fn_802A0FBC(void) {
    struct V30 {
        virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
        virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
        virtual void d8(); virtual void d9(); virtual s32 v30(const char *, long);
    };
    char *self = (char *)fn_8000AC38();
    V30 *obj = *(V30 **)(self + 0x20);
    s32 status = obj->v30(lbl_80349900, 1);
    u32 type = *(u32 *)(self + 8);
    s32 result = 0;
    if (status == 0) goto done;
    if (type == 0x180304) goto done;
    if ((type & 0x100) == 0) goto done;
    if (fn_80161C38() != 0) goto done;
    result = 1;
done:
    return result;
}
#pragma cplusplus reset
extern float lbl_805646F0;
extern float fn_802A0F7C(void *, void *, void *);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_802A1040(void *arg0, void *arg1, void *arg2) {
    register s32 count = 0;
    void *entry = arg1;
    for (;;) {
        float first;
        float threshold;
        float next;
        first = fn_802A0F7C((char *)arg0 + 8, entry, arg0);
        threshold = lbl_805646F0;
        next = fn_802A0F7C((void *)((u32)arg0 + 8), *(void **)((char *)entry + 0x14), arg0);
        if (threshold <= first) {
            if (next > threshold)
                break;
            if (threshold <= first) {
                entry = *(void **)((char *)entry + 0x14);
                goto step;
            }
        }
        if (*(u32 *)((char *)arg2 + 0x1c) == (u32)entry) {
            entry = (void *)(*(u32 *)((char *)arg2 + 0x1c) +
                             ((*(u32 *)((char *)arg2 + 0x18) >> 16) * 0x3c));
            entry = (char *)entry - 0x3c;
        } else {
            entry = (char *)entry - 0x3c;
        }
    step:
        if (count++ >= 10)
            break;
    }
    return entry;
}
#pragma scheduling on

void fn_802A1548(void) {
    if (lbl_8055F840 != 0) {
        fn_802C8BD0(lbl_8055F844);
        fn_802CA0A0(lbl_8055F840);
        fn_802C8D74();
    }
}

void fn_802A1584(void) { fn_802A9428(); }
#pragma scheduling on
extern void *fn_80156A40(void);
extern void fn_801352B8(void *);
extern s32 fn_80135D60(void *, s32);
extern void fn_801355C0(void *, void *, s32, void *, s32);
extern void *fn_802A1040(void *, void *, void *);
extern void fn_8013530C(void *, s32);
extern float lbl_805646F0;
extern float lbl_805646F4;
extern float lbl_80564700;
extern float fn_802A0F7C(void *, void *, void *);
#pragma cplusplus on
extern "C" void *fn_80156A40(void);
struct Dummy802A1120 {
    virtual void *getFirst(s32);
    virtual s32 getSecond(s32);
};
extern "C" inline void *fn_802A1120_getFirst(void) {
    return ((Dummy802A1120 *)fn_80156A40())->getFirst(0);
}
extern "C" inline void *fn_802A1120_getSecond(void) {
    return (void *)((Dummy802A1120 *)fn_80156A40())->getSecond(0);
}
#pragma cplusplus reset
#pragma paired off
#pragma paired_single off
void fn_802A1120(float *arg0, float *arg1) {
    struct Search { s32 index; float value; s32 max; };
    char work[0x14];
    struct Search search;
    void *manager;
    void *entry;
    register float end;
    register float increment;
    register float baseline;
    register float step;
    manager = fn_802A1120_getFirst();
    arg1[0] = *(float *)(*(char **)((char *)manager + 0x1C) + 8);
    arg1[1] = *(float *)(*(char **)((char *)manager + 0x1C) + 0xC);
    fn_801352B8(work);
    entry = fn_802A1120_getSecond();
    fn_80135D60(work, (s32)entry);
    search.index = 0;
    search.max = 0x2710;
    search.value = lbl_805646F0;
    fn_801355C0(work, *(void **)((char *)manager + 0x1C), 0, &search, 0);
    entry = fn_802A1040(*(void **)((char *)manager + 0x1C), (void *)search.index, entry);
    step = lbl_805646F0;
    baseline = lbl_805646F0;
    increment = lbl_80564700;
    end = lbl_805646F4;
    while (step < end) {
        arg0[0] = *(float *)entry + step * (*(float *)*(void **)((char *)entry + 0x14) -
                                             *(float *)entry);
        arg0[1] = *(float *)((char *)entry + 4) +
                  step * (*(float *)((char *)*(void * volatile *)((char *)entry + 0x14) + 4) -
                          *(float *)((char *)entry + 4));
        if (fn_802A0F7C((char *)*(char **)((char *)manager + 0x1C) + 8, arg0,
                        *(void **)((char *)manager + 0x1C)) >= baseline)
            break;
        step += increment;
    }
    fn_8013530C(work, -1);
}

extern double fn_8002F208(double);
extern double fn_8002F234(double);
extern void fn_801E9DC4(void *);
extern s32 fn_802A0FBC(void);
extern void fn_802A1120(float *, float *);
extern void fn_802A92CC(void);
extern s32 fn_802CA04C(s32);
extern s32 fn_802CAC28(void *, s32);
extern char lbl_80349914[];
extern float lbl_8055F848;
extern float lbl_8055F850[2];
extern float lbl_8055F858[2];
extern float lbl_8055F860[2];
extern float lbl_80564704, lbl_80564708, lbl_80564718, lbl_8056471C;
extern double lbl_80564710;
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802A1290(void) {
    float sp18[2];
    float sp10[2];
    float sp8[2];
    s32 i, j, n;
    float sz, k, a, b, d, lo, hi, scale;
    float x, y, t;
    fn_802A92CC();
    if (fn_802A0FBC() != 0) {
        lbl_8055F844 = fn_802CAC28(lbl_80349914, 0);
        n = (s32)(lbl_80564704 / lbl_80564708) | 1;
        sz = lbl_80564708 * (float)n;
        lbl_8055F840 = fn_802CA04C(n * 12 / 2);
        lbl_8055F848 = (float)fn_8002F208(lbl_80564710);
        fn_802A1120(lbl_8055F850, lbl_8055F858);
        lbl_8055F860[0] = lbl_8055F858[0];
        lbl_8055F860[1] = lbl_8055F858[1];
        lbl_8055F860[0] = lbl_8055F858[1];
        lbl_8055F860[1] = -lbl_8055F858[0];
        fn_801E9DC4(sp8);
        a = sz * lbl_805646EC;
        b = lbl_805646EC * (lbl_80564718 * sz);
        d = a - b;
        k = lbl_80564708;
        hi = lbl_805646F4;
        lo = lbl_805646F0;
        scale = lbl_8056471C;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 3; j++) {
                x = lbl_8055F850[0] + lbl_8055F858[0] * (k * (float)j) + lbl_8055F860[0] * (k * (float)i - a);
                y = lbl_8055F850[1] + lbl_8055F858[1] * (k * (float)j) + lbl_8055F860[1] * (k * (float)i - a);
                sp10[0] = x - lbl_8055F850[0];
                sp10[1] = y - lbl_8055F850[1];
                sp18[0] = x;
                sp18[1] = y;
                t = ((float)fn_8002F234(sp10[0] * sp10[0] + sp10[1] * sp10[1]) - b) / d;
                if (hi < t) t = hi;
                if (!(t > lo)) t = lo;
                fn_802A0D60((s32)sp8, sp18, lbl_8055F858, lbl_8055F860, (i + j) & 1, lbl_80564708, hi + t * scale);
            }
        }
    } else {
        lbl_8055F840 = 0;
        lbl_8055F844 = -2;
    }
}

void fn_802A14F8(void) {
    if (lbl_8055F844 != -2) {
        fn_802CAC54(lbl_8055F844);
        lbl_8055F844 = -2;
    }
    if (lbl_8055F840 != 0) {
        fn_802CA094(lbl_8055F840);
        lbl_8055F840 = 0;
    }
    fn_802A93A4();
}

#pragma pop
