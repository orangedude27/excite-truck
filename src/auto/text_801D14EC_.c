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

