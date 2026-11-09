// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float a, b, c, d; } Rec801D;
typedef struct {
    float out;
    float f4;
    int in;
    int cur;
    int prev;
    int target;
    float timer1;
    float timer2;
    int max;
    float div;
    float mul;
    Rec801D rec[8];
} Obj801D;
extern unsigned char *lbl_804348E8[];
extern float lbl_80562A58, lbl_80562A6C, lbl_80562A70, lbl_80562A74, lbl_80562A78, lbl_80562A7C, lbl_80562A80, lbl_80562A84, lbl_80562A88, lbl_80562A8C;
extern int fn_800241CC(int);
#pragma scheduling invalid_target
extern char lbl_80338238[];
extern char lbl_80338244[];
void fn_801D14EC(void) {
    extern void *fn_801284F8(int, const char *);
    extern void fn_801D0FA4(void);
    void *object;
    object = fn_801284F8(4, (const char *)&lbl_80338238[0]);
    if (object != 0) {
        fn_801D0FA4();
        *(void **)object = &lbl_80338244[0];
    }
}
#pragma scheduling on

extern float lbl_80562A58;
void fn_801D1540();
void fn_801D153C(void) {
    fn_801D1540();
}

extern void *memset(void *, int, unsigned long);
extern unsigned char *lbl_8055E908;
extern float lbl_80562A50, lbl_80562A54, lbl_80562A5C, lbl_80562A60, lbl_80562A64, lbl_80562A68;
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_801D1540(Obj801D *p, int idx) {
    unsigned char *cfg = lbl_804348E8[idx];
    float *curve = (float *)(lbl_8055E908 + idx * 0x34);
    unsigned char *ratios = cfg + 0x32c;
    float limit;
    float v, top, base, scale;
    v = *(float *)(cfg + 0x35c);
    p->mul = v;
    top = *(float *)(cfg + 0x2544);
    base = *(float *)(cfg + 0x23e8);
    scale = *(float *)(cfg + 0x358);
    p->div = lbl_80562A50 * (base + scale * (top - base)) / v;
    limit = curve[12];
    memset(p->rec, 0, 0x70);
    p->max = *(int *)(ratios + 0x34);
    {
        unsigned char *src = ratios;
        unsigned char *dst = (unsigned char *)p;
        int i;
        for (i = 0; i < *(int *)(ratios + 0x34); i++) {
            *(float *)(dst + 0x2c) = *(float *)(src + 0x38);
            src += 4;
            dst += 16;
        }
    }
    {
    float a, b, x, y, t, u, z;
    float zero = lbl_80562A58, dscale = lbl_80562A68, cscale = lbl_80562A64, last = lbl_80562A60, step = lbl_80562A5C;
    unsigned char *prev = (unsigned char *)p;
    Rec801D *r = p->rec;
    int count;
    int i;
    for (i = 0; i < (count = p->max); i++, r++, prev += 16) {
        a = r->a;
        if (i < count - 1) {
            b = r[1].a;
            for (x = lbl_80562A54; x < limit; x += step) {
                y = x / a * b;
                if (x > curve[11]) {
                    z = x - curve[8];
                    if (zero > z) z = zero;
                    t = curve[3] + (curve[2] * x + curve[1] * (x*x)) - curve[9] * z;
                    if (curve[10] > t) t = curve[10];
                } else {
                    t = curve[6] + (curve[5] * x + curve[4] * (x*x));
                }
                t = a * (t - curve[7] * x);
                if (y > curve[11]) {
                    z = y - curve[8];
                    if (zero > z) z = zero;
                    u = curve[3] + (curve[2] * y + curve[1] * (y*y)) - curve[9] * z;
                    if (curve[10] > u) u = curve[10];
                } else {
                    u = curve[6] + (curve[5] * y + curve[4] * (y*y));
                }
                if (b * (u - curve[7] * y) > t) break;
            }
            r->b = x / a;
        } else r->b = last;
        if (i - 1 >= 0) {
            x = limit / a;
            y = *(float *)(prev + 0x20);
            if (y > x) y = x;
            r->c = cscale * y;
            r->d = dscale * y;
        } else {
            r->c = zero;
            r->d = zero;
        }
    }
    }
}

#pragma dont_inline on
void fn_801D1810(int arg0, int arg1) {
    float zero = lbl_80562A58;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(float *)arg0 = zero;
    *(float *)((char *)arg0 + 4) = zero;
    *(float *)((char *)arg0 + 0x1C) = zero;
    *(float *)((char *)arg0 + 0x18) = zero;
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 8) = 0;
}
#pragma dont_inline off

#pragma pop

void fn_801D183C(int arg0, int idx) {
    Obj801D *p = (Obj801D *)arg0;
    unsigned char *cfg = lbl_804348E8[idx];
    float g = *(float *)(cfg + 0x25F4);
    int in = p->in;
    int cur;
    int tgt;
    float x;
    float step = lbl_80562A7C;
    p->f4 = lbl_80562A58;
    if (in == -10) {
        if (p->target < 1) {
            p->target = 1;
            p->cur = 1;
        }
    } else {
        p->target = in;
    }
    cur = p->cur;
    if (p->in != -10) {
        cur = p->in;
        p->cur = cur;
    } else if (cur == p->target) {
        Rec801D *r;
        float lo, v, k;
        if (cur < 1) {
            cur = 1;
            p->target = cur;
        }
        r = &p->rec[cur - 1];
        k = *(float *)(cfg + 0x25CC);
        v = (k + lbl_80562A70 * (*(float *)(cfg + 0x25D8) * lbl_80562A6C - k)) / p->div;
        lo = r->d + g * (r->c - r->d);
        if (cur > 0) {
            if (v > r->b) {
                if (cur < p->max) cur++;
            } else if (v < lo) {
                if (cur > 1) cur--;
            }
        }
        p->cur = cur;
    }
    tgt = p->target;
    if (cur != tgt) {
        float lim;
        int f = 0;
        if (cur == p->prev && cur < tgt) f = 1;
        lim = f ? lbl_80562A74 : lbl_80562A78;
        if (cur >= 1 && tgt >= 1 && !(p->timer2 > lim)) {
            cur = tgt;
            p->cur = tgt;
        }
    }
    tgt = p->target;
    p->timer2 += step;
    if (tgt != cur) {
        p->timer1 += step;
        if (cur >= 1 && tgt >= 1 && p->timer1 > lbl_80562A80) {
            p->prev = tgt;
            p->target = cur;
            p->timer1 = lbl_80562A58;
            p->timer2 = lbl_80562A58;
        } else if (cur > 1 && tgt > cur) {
            p->f4 = lbl_80562A84;
        } else if (tgt < cur && tgt != 0) {
            p->f4 = lbl_80562A88;
        }
    } else {
        p->timer1 = lbl_80562A58;
    }
    if (cur != 0) {
        x = p->rec[fn_800241CC(cur) - 1].a * p->mul;
    } else {
        x = lbl_80562A58;
    }
    p->out = x;
    if (cur < 0) {
        p->out = (float)x * lbl_80562A8C;
    }
}

void fn_801D1008(void*, unsigned int);
void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801D1AB4(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_801D1008((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

extern int lbl_8055E918;
extern float lbl_80562A58;
extern int fn_80128670(int);
void fn_801D1B0C(void) {
    if (lbl_8055E918 != 0) {
        fn_80128670(lbl_8055E918 - 0x10);
    }
    lbl_8055E918 = 0;
}

void fn_801D1B44(void) {

}

extern int lbl_8055E8F8;
extern int lbl_8055ABD8;
extern float lbl_80562A58;
void fn_801D183C(int, int);
void fn_801D153C(void);
int fn_8012850C(int, int *);
int fn_8002F37C(int, int, int, int);
void fn_801D1B48(void) {
    int offset = 0;
    int i = 0;
    while (i < lbl_8055E8F8) {
        fn_801D183C(lbl_8055E918 + offset, i);
        offset += 0x9c;
        i++;
    }
}

void fn_801D1BA4(void) {
    int offset = 0;
    int i = 0;
    while (i < lbl_8055E8F8) {
        fn_801D1810(lbl_8055E918 + offset, i);
        offset += 0x9c;
        i++;
    }
}

void fn_801D1C00(void *arg0, int arg1) {
    ((void (*)(int))fn_801D153C)(lbl_8055E918 + arg1 * 0x9C);
}

void fn_801D1C10(void) {
    int count = lbl_8055E8F8;
    int result = fn_8012850C(count * 0x9c + 0x10, &lbl_8055ABD8);
    lbl_8055E918 = ((int (*)(int, int, int, int, int))fn_8002F37C)(result, 0, 0, 0x9c, count);
}

