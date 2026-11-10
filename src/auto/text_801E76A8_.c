// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801284F8(int, void *);
extern void *fn_801E76A8(void *, int);
extern void fn_802D68C4(int, int, int, int);
extern void fn_80128670(void *);
extern void fn_80128668(void *);
#pragma small_data off
extern char lbl_80339B90[];
typedef struct { void *a; int b; int c; void *d; int e; int f; } S76;
void fn_801E7828();
void fn_801E7790(void *, int, int, float, float, float, float, float);
#pragma dont_inline on
extern void *fn_8012850C(int, void *);
extern char lbl_80339B70[];
extern char lbl_80339B80[];
void *fn_801E76A8(void *arg0, int arg1) {
    S76 *o = (S76 *)arg0;
    int rem;
    o->a = fn_8012850C(arg1 * 0x18, lbl_80339B70);
    rem = arg1 - 2;
    o->c = arg1;
    arg1 = (rem * 4) - rem;
    o->b = 0;
    o->d = fn_8012850C(arg1 * 2, lbl_80339B80);
    o->e = 0;
    o->f = arg1;
    return arg0;
}

void *__dt__12PhysicsWorldFv_801E7730(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80128670(*(void **)((char *)arg0 + 0xC));
        fn_80128670(*(void **)((char *)arg0 + 0));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_801E7790(void *buf, int id, int emit, float x, float y, float z, float u, float v) {
    int *b = (int *)buf;
    char *base = (char *)b[0];
    int cnt = b[1];
    float *dst = (float *)(base + cnt * 0x18);
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
    ((int *)dst)[3] = id;
    dst[4] = u;
    dst[5] = v;
    cnt++;
    b[1] = cnt;
    if (emit == 0) return;
    if (cnt <= 1) return;
    {
        short *ib = (short *)b[3];
        int ic = b[4];
        ib[ic] = (short)(cnt - 3);
        ic++;
        b[4] = ic;
        ib[ic] = (short)(cnt - 2);
        ic++;
        b[4] = ic;
        ib[ic] = (short)(cnt - 1);
        b[4] = ic + 1;
    }
}

void fn_801E7828(arg0)
    void *arg0;
{
    int *p = (int *)arg0;
    fn_802D68C4(p[0], p[1], p[3], p[4]);
}

#pragma dont_inline off

void fn_801E7840(void *arg0) {
    void *obj;
    obj = fn_801284F8(0x18, lbl_80339B90);
    if (obj != 0)
        fn_801E76A8(obj, (int)arg0);
}

void *fn_801E7888(void *arg0) {
    return __dt__12PhysicsWorldFv_801E7730(arg0, 1);
}

void fn_801E7890(void *a, int b, int c, float d, float e, float f, float g, float h) {
    fn_801E7790(a, b, c, d, e, f, g, h);
}

void fn_801E7894(void) {
    fn_801E7828();
}

