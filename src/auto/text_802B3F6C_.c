#define NULL 0
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F9C8;
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern void fn_802B4D40(void *);
extern int fn_802B40B0(int, int);
extern unsigned short lbl_8055F9CC;
extern int fn_802B3FC4(void *);
extern int lbl_8055CE00;
extern int lbl_804BE248[128];
extern char lbl_8034A408[];
extern void *fn_80131810(void *);
extern void fn_80131818(void *);
extern void *fn_801284F8(int, void *);
extern float fn_80129DC4(int, float, float);
extern void *memset(void *, int, unsigned int);
extern float lbl_80564C48;
extern void *fn_8012850C(int, void *);
extern char lbl_8055CE08[];
extern float lbl_80564C30;
extern float lbl_80564C40;
extern float lbl_80564C44;
extern unsigned short lbl_80564C38, lbl_80564C3A, lbl_80564C3C, lbl_80564C3E;
extern int fn_80129D90(int, int, int);
extern void *fn_8002F37C(void (*)(void), int, int, int);
extern void fn_802B4BD8(void);
extern float lbl_802FAAD0[];
extern int lbl_8055F9D0[];
extern int fn_802B475C(void *);
extern void *fn_802B47A0(void *, int *, void *, int, int **);
extern int fn_802B4BC0(int, int, int);
extern void *fn_802B4014(void *);
#define GRID (*(int **)lbl_8055F9D0)
typedef int (*VFn)(void *, void *);
#define VT(o, i) ((VFn)(*(void ***)(o))[i])
void *fn_802B3F6C(void *arg0, int arg1) {
    if (arg0 != NULL) {
        if (arg0 != NULL) {
            *(int *)arg0 = 0;
            *((int *)arg0 + 1) = 0;
            *((int *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

int stricmp(const char *, const char *);
extern char lbl_8055CDF8[];
__declspec(section ".sdata") extern char lbl_8055CDF8[];
#pragma push
#pragma cplusplus on
extern "C" int fn_802B3FC4(void *arg0) {
    class Obj {
    public:
        virtual const char *getName();
    };
    return stricmp((char *)&lbl_8055CDF8, ((Obj *)arg0)->getName()) == 0;
}
#pragma cplusplus reset
#pragma pop
void fn_802B4004(void) {
    lbl_8055F9CC += 1;
}

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
#pragma dont_inline on
extern "C" void *fn_802B4014(void *arg0) {
    class Object {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual int check(int *);
    };
    class List {
    public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12();
        virtual void f13();
        virtual void f14();
        virtual void f15();
        virtual void f16();
        virtual void f17();
        virtual void f18();
        virtual void f19();
        virtual void f20();
        virtual void f21();
        virtual void *get(int);
    };
    void *p;
    int i = 0;

    goto get_next;
check:
    if (fn_802B3FC4(p) != 0) {
        if (((Object *)p)->check(&lbl_8055CE00) == 1)
            goto done;
    }
    i += 1;
get_next:
    p = ((List *)arg0)->get(i);
    if (p != 0)
        goto check;
done:
    return p;
}
#pragma dont_inline off
#pragma cplusplus reset
#pragma pop
int fn_802B40B0(int arg0, int arg1) {
    int p;
    if (arg0 >= 0 && (unsigned int)arg0 < 0x80) {
        p = lbl_804BE248[arg0];
        if (p != 0) {
            if ((int)lbl_8055F9C8 == -1 || arg1 == (int)lbl_8055F9C8)
                return p;
        }
    }
    return 0;
}

int fn_80129D90(int, int, int);
#pragma scheduling off
int fn_802B475C(void* arg0) {
    int index = fn_80129D90(0, 0, *(int*)((char*)arg0 + 4));
    return ((int*)*(void**)arg0)[index];
}

extern void fn_802B4BD8(void);
extern void *memcpy(void *, const void *, unsigned int);
extern int fn_80129D90(int, int, int);
extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void (*)(void), int, int, int);
extern char lbl_8034A4A0[];
extern char lbl_8034A4AC[];
extern char lbl_8055CE08[];
extern float lbl_80564C30;
extern float lbl_80564C40;
extern float lbl_80564C44;
extern unsigned short lbl_80564C38, lbl_80564C3A, lbl_80564C3C, lbl_80564C3E;
extern float lbl_802FAAD0[];
void *fn_802B47A0(void *arg0, int *arg1, void *arg2, int arg3, int **arg4) {
    int sp[4];
    unsigned short sel[4];
    float quad[4];
    float st[2];
    int *out = (int *)arg0;
    int a, b, cnt, n, lane, tries, k;
    float f28, f27, f29, f30, f25, f26;
    int (**vt)(void *, void *) = *(int (***)(void *, void *))arg2;

    a = vt[7](arg2, lbl_8034A4A0);
    n = arg3 * (arg3 * a) / 10;
    b = (*(int (***)(void *, void *))arg2)[7](arg2, lbl_8034A4AC);
    cnt = fn_80129D90(0, n, arg3 * (arg3 * b) / 10 + 1);
    fn_8012850C(cnt * 0x24 + 0x10, lbl_8055CE08);
    out[0] = (int)fn_8002F37C(fn_802B4BD8, 0, 0x24, cnt);
    out[3] = out[0];
    out[2] = cnt;
    out[1] = 0;
    f28 = (float)(arg3 / 2) * lbl_80564C30;
    f27 = (float)arg3 * lbl_80564C30;
    sp[0] = sp[1] = sp[2] = sp[3] = 0;
    lane = fn_80129D90(0, 0, 4);
    f29 = lbl_80564C40;
    f30 = f28 * f29;
    f25 = f27 * f29;
    f26 = lbl_80564C44;
    for (k = 0; k < out[2]; k++) {
        char *src;
        char *dst;
        float x, y, nx, ny, ex, ey, u, v, d0, d1;
        unsigned short code, s;
        int *lanep;
        tries = 0;
        do {
            lane = (lane + 1) & 3;
            tries++;
        } while (tries < 100 && sp[lane] >= ((int *)arg1[lane])[1]);
        lanep = (int *)arg1[lane];
        src = (char *)lanep[0] + sp[lane] * 0x24;
        dst = (char *)out[0] + out[1] * 0x24;
        out[1]++;
        *(unsigned short *)(dst + 8) = *(unsigned short *)(src + 8);
        memcpy(dst + 0xc, src + 0xc, 0x18);
        s = *(unsigned short *)(src + 0xa);
        x = *(float *)src * f28 * f29;
        y = *(float *)(src + 4) * f28 * f29;
        nx = f30 + ((float *)lbl_802FAAD0)[8 + s * 2] * x + ((float *)lbl_802FAAD0)[8 + ((s + 1) & 3) * 2] * y;
        ny = f30 + ((float *)lbl_802FAAD0)[9 + s * 2] * x + ((float *)lbl_802FAAD0)[9 + ((s + 1) & 3) * 2] * y;
        quad[0] = nx;
        quad[1] = ny;
        ex = nx + f28 * (float)((int *)lbl_802FAAD0)[lane];
        ey = ny + f28 * (float)((int *)lbl_802FAAD0)[4 + lane];
        quad[2] = ex;
        quad[3] = ey;
        d0 = ex - f25;
        d1 = ey - f25;
        code = 0;
        if (d0 + d1 >= f26) code |= 1;
        if (-d0 + d1 >= f26) code |= 2;
        sel[0] = lbl_80564C38;
        sel[1] = lbl_80564C3A;
        sel[2] = lbl_80564C3C;
        sel[3] = lbl_80564C3E;
        u = (quad[2] - f25) / f27;
        v = (quad[3] - f25) / f27;
        st[0] = u;
        st[1] = v;
        s = sel[code];
        *(unsigned short *)(dst + 0xa) = s;
        sp[lane] += 1;
        *(float *)dst = ((float *)lbl_802FAAD0)[8 + s * 2] * u + ((float *)lbl_802FAAD0)[9 + s * 2] * v;
        *(float *)(dst + 4) = ((float *)lbl_802FAAD0)[8 + ((s + 1) & 3) * 2] * u + ((float *)lbl_802FAAD0)[9 + ((s + 1) & 3) * 2] * v;
    }
    *arg4[0] = sp[0];
    *arg4[1] = sp[1];
    *arg4[2] = sp[2];
    *arg4[3] = sp[3];
    return arg0;
}

#pragma scheduling on
int fn_802B4BC0(int arg0, int arg1, int arg2) {
    return arg0 + (((arg1 & 0x1F) + ((arg2 << 5) & 0x3E0)) << 3);
}

void fn_802B4BD8(void) {}

extern int lbl_8055F9D0[];
extern void fn_802B4CB4(void *);
extern void fn_802B4DC0(void *);
__declspec(section ".sdata") extern int lbl_8055F9D0[];
#pragma push
#pragma scheduling invalid_target
void fn_802B4BDC(void) {
    void *entry;
    int zero;
    int offset;
    int *p;
    int i;
    int count;

    i = 0;
    p = lbl_804BE248;
    do {
        fn_802B4CB4(p);
        i += 1;
        p += 1;
    } while ((unsigned int)i < 0x80);

    count = 0;
    offset = 0;
    zero = 0;
    goto check_count;
loop:
    entry = *(void **)((char *)*(void **)*(void * volatile *)lbl_8055F9D0 + offset);
    if (entry != 0) {
        if (entry != 0) {
            int data = *(int *)((char *)entry + 0xC);
            if (data != 0)
                fn_80128670(data - 0x10);
            if (entry != 0) {
                *(int *)entry = zero;
                *(int *)((char *)entry + 4) = zero;
                *(int *)((char *)entry + 8) = zero;
            }
        }
        fn_80128668(entry);
    }
    offset += 4;
    count += 1;
check_count:
    if (count < ((int *)*(void * volatile *)lbl_8055F9D0)[1])
        goto loop;
    fn_802B4DC0(lbl_8055F9D0);
}
#pragma pop

#pragma push
#pragma scheduling invalid_target
void fn_802B4CB4(void *arg0) {
    unsigned int i;
    char *q;
    void *p;

    p = *(void **)arg0;
    if (p != 0) {
        if (p != 0) {
            if (*(unsigned char *)((char *)p + 0x2000) != 0) {
                i = 0;
                q = (char *)p;
                do {
                    int keep;
                    fn_802B4D40(q);
                    i += 1;
                    keep = i < 0x400;
                    q += 8;
                    if (!keep)
                        break;
                } while (1);
            }
            fn_80128668(p);
        }
        *(void **)arg0 = 0;
    }
}
#pragma pop
void fn_802B4D40(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            if (p != NULL) {
                int x = ((int *)p)[3];
                if (x != 0) {
                    fn_80128670(x - 0x10);
                }
                if (p != NULL) {
                    ((int *)p)[0] = 0;
                    ((int *)p)[1] = 0;
                    ((int *)p)[2] = 0;
                }
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

void fn_802B4DC0(void *arg0) {
    void *p = *(void **)arg0;
    if (p != NULL) {
        if (p != NULL) {
            fn_80128670(((int *)p)[3]);
            if (p != NULL) {
                ((int *)p)[0] = 0;
                ((int *)p)[1] = 0;
                ((int *)p)[2] = 0;
            }
            fn_80128668(p);
        }
        *(void **)arg0 = NULL;
    }
}

void fn_802B4E30(void) {
    lbl_8055F9C8 = (void*)-1;
}

void fn_802B4E3C(void* hi) {
    lbl_8055F9C8 = hi;
}

extern int fn_802B3DA4(int, unsigned short, int);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_802B4E44(int arg0, int arg1) {
    unsigned int slotIndex;
    int index;
    int *record;
    int count;
    int *table;
    int offset;
    int *out;
    char *slot;
    int *entry;
    unsigned int outer;
    int keepSlot;
    int keepOuter;

    table = lbl_804BE248;
    outer = 0;
outer_loop:
    slot = (char *)*table;
    if (slot != 0) {
        slotIndex = 0;
slot_loop:
        entry = *(int **)slot;
        if (entry != 0) {
            count = 0;
            offset = 0;
            goto record_test;
record_loop:
            record = (int *)(*(int *)entry + offset);
            out = record;
            index = 0;
field_loop:
            *(int *)((char *)out + 0xC) =
                fn_802B3DA4(arg0, *(unsigned short *)((char *)record + 8), index);
            index++;
            out++;
            if (index < 6)
                goto field_loop;
            offset += 0x24;
            count++;
record_test:
            if (count < entry[1])
                goto record_loop;
        }
        slotIndex++;
        keepSlot = slotIndex < 0x400;
        slot += 8;
        if (keepSlot)
            goto slot_loop;
    }
    outer++;
    keepOuter = outer < 0x80;
    table++;
    if (keepOuter)
        goto outer_loop;
}
#pragma use_lmw_stmw on
#pragma scheduling on
#pragma pop
void *fn_802B4F10(void *out, int x, int y, int a, int b) {
    int result = 0;
    int r = fn_802B40B0(a, b);
    if (r != 0) {
        int idx = (((x & 0x1F) + ((y << 5) & 0x3E0)) << 3);
        int *p = (int *)(r + idx);
        *(int *)out = p[1];
        result = p[0];
        if (((int *)p[0])[1] > 0) return (void *)result;
        result = 0;
    }
    return (void *)result;
}
#pragma dont_inline reset
typedef struct { int *ptr; int value; } Slot;
typedef struct { char *data; int count; } Entry;
typedef struct { int a, b, c, d; } EtOut;
