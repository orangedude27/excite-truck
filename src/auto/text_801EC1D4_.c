// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct { float values[12]; } Unk_801ECFE0;
extern long lbl_80488648[];
void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);

void fn_801EC9CC(void*, unsigned int);
void fn_80128668(void*);
void fn_801ECCE0(long, long);
long fn_801E866C(long);
long fn_801E89C8(long);
float fn_802C99E8(void *, float);
void fn_801ED718(void *);
void fn_801ECC70(void);
float fn_801F159C(long);
long fn_80201018(long, void *, long);
long fn_801ECB60(void);
extern unsigned int lbl_8055EBC8;
void fn_801F131C(void *, long, void *, float);
void fn_801EFC90(long, long, void *);
extern float lbl_80488668[3];
extern unsigned int lbl_8055EBC8;
long fn_801ECB60(void);
void fn_801EC1D4(void) {
    ((unsigned int *)lbl_80488668)[0] = 0x555766;
    ((unsigned int *)lbl_80488668)[1] = 0xFFF5D9;
}

void *fn_801EC1F8(void) {
    return lbl_80488668;
}

void *fn_801EC204(void) {
    return &lbl_80488668[1];
}

void *__dt__24J3DUMtxAnmCacheTableBaseFv_801EC448(void *arg0, int arg1) {
    void *self = arg0;
    if (arg0 != 0) {
        arg0 = *(void **)arg0;
        if (arg0 != 0) fn_801E323C();
        if (arg1 > 0) fn_80128668(self);
    }
    return self;
}

void fn_801E353C(long, float);
void fn_801E34E4(void *, long);
#pragma push
#pragma scheduling off
void fn_801EC4A8(void *arg0, long arg1) {
    char *p;
    long object;
    long i, count;
    char *a, *b;
    float lower, value, upper;
    float x, y, nextY;
    object = *(long *)arg0;
    if (object != 0) {
        value = *(float *)((char *)arg0 + 8);
        upper = **(float **)((char *)arg0 + 0x50);
        lower = *(float *)((char *)arg0 + 4);
        value = value < upper ? value : upper;
        value = value > lower ? value : lower;
        p = arg0;
        i = 0;
        count = *(long *)((char *)arg0 + 0x4C) - 2;
        for (; count > 0; count--) {
            if (*(float *)(p + 0x14) > value) break;
            p += 8;
            i++;
        }
        a = (char *)arg0 + i * 8;
        b = (char *)arg0 + (i + 1) * 8;
        x = *(float *)(a + 0xC);
        y = *(float *)(a + 0x10);
        nextY = *(float *)(b + 0x10);
        fn_801E353C(object, -(y + (nextY - y) * ((value - x) / (*(float *)(b + 0xC) - x))));
        fn_801E34E4(*(void **)arg0, arg1);
    }
}
#pragma pop
void fn_801EC714(void *arg0, float *arg1, float *arg2) {
    *arg1 = *(float *)((char *)arg0 + 8) + (*(*(float **)arg0) * *(float *)((char *)arg0 + 4));
    *arg2 = *(float *)((char *)arg0 + 0x10) + (*(*(float **)arg0) * *(float *)((char *)arg0 + 0xC));
}

float fn_802C88D4(void *);
float fn_801E88F0(long);
#pragma push
#pragma processor 750
#pragma scheduling 7400
void fn_801ECB80(void *arg0) {
    float value;
    long *count;
    long offset;
    long i;
    value = fn_802C88D4((char *)arg0 + 0x28);
    value *= fn_801E88F0(-1);
    count = *(long **)((char *)arg0 + 0x174);
    i = 0;
    offset = 0;
    *(long *)((char *)arg0 + 0x3F8) = *count - 1;
    for (; i < *count; offset += 8, i++) {
        if (value < *(float *)(*(char **)((char *)arg0 + 0x170) + offset)) {
            *(long *)((char *)arg0 + 0x3F8) = i;
            break;
        }
    }
    if (*(long *)((char *)arg0 + 0x3F8) < *(long *)((char *)arg0 + 0x3FC))
        *(long *)((char *)arg0 + 0x3F8) = *(long *)((char *)arg0 + 0x3FC);
    if (*(long *)((char *)arg0 + 0x3F8) >= **(long **)((char *)arg0 + 0x174))
        *(long *)((char *)arg0 + 0x3F8) = **(long **)((char *)arg0 + 0x174) - 1;
    if (*(long *)((char *)arg0 + 0x40) == fn_801E866C(-1)) {
        long n = *(long *)((char *)arg0 + 0x3F8);
        *(long *)((char *)arg0 + 0x3F8) = n > 1 ? 1 : n;
    }
}
#pragma pop

long fn_801ECC8C(unsigned int arg0) {
    long result = 0;
    if (fn_801ECB60() == 0 && arg0 == lbl_8055EBC8)
        result = 1;
    return result;
}

void fn_801ECF58(void *arg0) {
    long flag;
    long entry;
    long owner;

    if (*(long *)((char *)arg0 + 0x184) != 0) {
        flag = 0;
        entry = *(long *)((char *)arg0 + 0x170) +
                *(long *)((char *)arg0 + 0x3F8) * 8;
        if (*(unsigned char *)(entry + 5) != 0) {
            owner = *(long *)((char *)arg0 + 0x3C);
            if ((*(long *)(owner + 0x2C0) & 0x100) == 0)
                flag = 1;
        }
        fn_801ECC70();
        fn_80201018(*(long *)((char *)arg0 + 0x184),
                    *(void **)((char *)arg0 + 0x3C), flag);
    }
}

void fn_801ED2D0(void *arg0) {
    long flag;
    long i;
    long offset;
    char *p;
    fn_801ECC70();
    flag = *(long *)((char *)arg0 + 0x40) == fn_801E866C(-1);
    i = 0;
    offset = 0;
    do {
        p = (char *)*(void **)((char *)arg0 + 0x3C) + offset;
        fn_801F131C(*(void **)((char *)arg0 + 0x4D4 + i * 4), flag, p,
                    *(float *)(p + 0xB0));
        i++;
        offset += 0x6C;
    } while (i < 4);
}

void fn_801ED68C(long arg0) {
    fn_801ECCE0(arg0, 1);
}

void fn_801ED694(long arg0) {
    fn_801ECCE0(arg0, 0);
}

void fn_801ED69C(void *arg0) {
    void *ptr;
    if (*(long *)((char *)arg0 + 0x40) == fn_801E866C(-1) &&
        fn_801E89C8(-1) != 0) {
        ptr = *(void **)((char *)arg0 + 0x3C);
        lbl_80488668[2] = fn_802C99E8(ptr, *(float *)((char *)ptr + 0x2CC));
        fn_802C99E8(((void *(*)(void *))fn_801ED718)(arg0), lbl_80488668[2]);
    }
}

void fn_801EDD68(void *arg0) {
    fn_801EFC90(*(long *)((char *)arg0 + 0x3F0),
                *(long *)((char *)arg0 + 0x3C), (char *)arg0 + 0x4D4);
}

extern void fn_801EABA8(long);
extern void fn_801F0F78(long, long, void *, float);
extern float lbl_80558DC4;
extern float lbl_80562E90;
extern float __fabsf(float);
void fn_801EDD7C(void *arg0, long arg1) {
    float scale;
    unsigned int *a, *b, *c, *d, *e, *f, *g, *h, *j, *k, *m, *n;
    long i, offset;
    char *entry;
    fn_801EABA8(*(long *)((char *)arg0 + 0x3C));
    scale = *(float *)((char *)arg1 + 0x2D0);
    *(float *)((char *)arg0 + 0x4D0) = scale;
    if (__fabsf(scale - lbl_80562E90) <= lbl_80558DC4) {
        a = (unsigned int *)((char *)arg0 + 4); b = a + 1; c = a + 2; d = a + 3;
        e = a + 4; f = a + 5; g = a + 6; h = a + 7;
        j = a + 8; k = a + 9; m = a + 10; n = a + 11;
        *(unsigned int *)((char *)arg0 + 0x4A0) = *a;
        *(unsigned int *)((char *)arg0 + 0x4A4) = *b;
        *(unsigned int *)((char *)arg0 + 0x4A8) = *c;
        *(unsigned int *)((char *)arg0 + 0x4AC) = *d;
        *(unsigned int *)((char *)arg0 + 0x4B0) = *e;
        *(unsigned int *)((char *)arg0 + 0x4B4) = *f;
        *(unsigned int *)((char *)arg0 + 0x4B8) = *g;
        *(unsigned int *)((char *)arg0 + 0x4BC) = *h;
        *(unsigned int *)((char *)arg0 + 0x4C0) = *j;
        *(unsigned int *)((char *)arg0 + 0x4C4) = *k;
        *(unsigned int *)((char *)arg0 + 0x4C8) = *m;
        *(unsigned int *)((char *)arg0 + 0x4CC) = *n;
    } else {
        *(float *)((char *)arg0 + 0x4A0) = *(float *)((char *)arg0 + 4) * scale;
        *(float *)((char *)arg0 + 0x4A4) = *(float *)((char *)arg0 + 8) * scale;
        *(float *)((char *)arg0 + 0x4A8) = *(float *)((char *)arg0 + 0xC) * scale;
        *(float *)((char *)arg0 + 0x4AC) = *(float *)((char *)arg0 + 0x10) * scale;
        *(float *)((char *)arg0 + 0x4B0) = *(float *)((char *)arg0 + 0x14) * scale;
        *(float *)((char *)arg0 + 0x4B4) = *(float *)((char *)arg0 + 0x18) * scale;
        *(float *)((char *)arg0 + 0x4B8) = *(float *)((char *)arg0 + 0x1C) * scale;
        *(float *)((char *)arg0 + 0x4BC) = *(float *)((char *)arg0 + 0x20) * scale;
        *(float *)((char *)arg0 + 0x4C0) = *(float *)((char *)arg0 + 0x24) * scale;
        *(float *)((char *)arg0 + 0x4C4) = *(float *)((char *)arg0 + 0x28);
        *(float *)((char *)arg0 + 0x4C8) = *(float *)((char *)arg0 + 0x2C);
        *(float *)((char *)arg0 + 0x4CC) = *(float *)((char *)arg0 + 0x30);
    }
    entry = arg0; i = 0; offset = 0;
    do {
        fn_801F0F78(*(long *)(entry + 0x4D4), *(long *)((char *)arg0 + 0x3C) + offset + 0x7C,
                    (char *)arg0 + 4, *(float *)((char *)arg0 + 0x4D0));
        i++; offset += 0x6C; entry += 4;
    } while (i < 4);
}

long fn_801EE0C8(void *arg0) {
    return *(long *)((char *)arg0 + 0x48);
}

void fn_801EE0D0(long arg0, long arg1) {
    fn_801F159C(*(long *)(arg0 + arg1 * 4 + 0x4D4));
}

extern char lbl_8033A1C8[];
extern char lbl_8055B070[8];
extern char lbl_8055B078[8];
long fn_801EFF94(void *, long, long);
#pragma push
#pragma use_lmw_stmw off
void fn_801EE974(void *arg0, void *arg1) {
    char *entries;
    char *out;
    long i;
    long flag;
    void *object;
    void *result;
    void *(*method)(void *, void *);
    out = arg1;
    entries = arg0;
    i = 0;
    do {
        flag = 0;
        if (i == 0) goto enabled;
        if (i != 1) goto checked;
    enabled:
        flag = 1;
    checked:
        if (flag) {
            object = *(void **)(*(char **)((char *)arg0 + 0x188) + 0x2134);
            method = *(void *(**)(void *, void *))((char *)*(void **)object + 8);
            result = method(object, lbl_8055B070);
            method = *(void *(**)(void *, void *))((char *)*(void **)result + 0x14);
            result = method(result, lbl_8033A1C8);
        } else {
            object = *(void **)(*(char **)((char *)arg0 + 0x188) + 0x2134);
            result = (*(void *(**)(void *, void *))((char *)*(void **)object + 8))(object, lbl_8055B078);
            result = (*(void *(**)(void *, void *))((char *)*(void **)result + 0x14))(result, lbl_8033A1C8);
        }
        *(long *)(entries + 0x4D4) = fn_801EFF94(result, *(long *)((char *)arg0 + 0x40), i);
        *(float *)(out + 0x10C) = fn_801F159C(*(long *)(entries + 0x4D4));
        i++;
        entries += 4;
        out += 4;
    } while (i < 4);
}
#pragma pop
void fn_801EDD7C(void *, long);
long fn_80179CB0(void);
void fn_801EECAC(long, long);
void fn_802C6CF8(long);
void fn_801EEC68(void *arg0) {
    long value;
    value = *(long *)((char *)arg0 + 0x488);
    if (value != -1) {
        fn_802C6CF8(value);
        *(long *)((char *)arg0 + 0x488) = -1;
    }
}

long fn_801EEE38(void) {
    long *entries;
    long context;
    long i;
    long value;
    context = fn_80179CB0();
    entries = lbl_80488648;
    i = 0;
    do {
        if (i >= 8) value = 0;
        else value = *entries;
        if (value == 0) return value;
        fn_801EECAC(value, context);
        entries++;
        i++;
    } while (1);
}

extern void fn_801EC750(void *);
extern int lbl_8033A2D4[64];
#pragma scheduling off
void **fn_801EEEB0(void **arg0) {
    fn_801EC750(arg0);
    *arg0 = &lbl_8033A2D4;
    return arg0;
}
#pragma scheduling on

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_801EEEEC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_801EC9CC((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_801EEF44(void *arg0, void *arg1) {
    long base;
    long p44;
    long pc8;
    long p148;
    base = *(long *)((char *)lbl_80488648 + *(long *)((char *)arg1 + 0xFA8) * 4);
    p44 = base + 0x44;
    pc8 = base + 0xC8;
    p148 = base + 0x148;
    *(long *)((char *)arg0 + 0x16C) = p44;
    *(long *)((char *)arg0 + 0x170) = pc8;
    *(long *)((char *)arg0 + 0x174) = p148;
    fn_801EDD7C(arg0, (long)arg1);
}

unsigned int fn_801EEF74(void) { return 1; }

