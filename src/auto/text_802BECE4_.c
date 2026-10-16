// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
extern void fn_802BEDFC(void);
extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C(int);
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
extern void fn_802CAC54(int);
extern char lbl_8034AE20[];
typedef unsigned int u32;
extern float lbl_8055FAF4;
extern float lbl_80564D7C;
extern float lbl_80564D80;
extern float PSVECMag(void *);
extern char lbl_8034ACC0[];
extern char lbl_8055CF78[];
extern unsigned char lbl_8055CF71;
extern int fn_801E85B4(void);
extern void fn_802BF160(void);
extern int fn_802C2C00(int);
extern void fn_802C6CF8(void);
extern void *lbl_804C07F0[];
extern unsigned char lbl_8055CF70;
extern int lbl_8055FADC;
extern int lbl_8055CF6C;
void fn_802BED90(float *arg0) {
    float mag = PSVECMag(arg0);
    float scale;
    if (lbl_80564D7C > mag) mag = lbl_80564D7C;
    scale = lbl_80564D80 / mag;
    arg0[0] *= scale;
    arg0[1] *= scale;
    arg0[2] *= scale;
}

float fn_802BEFB4(void) {
    float value;
    float limit;
    float result;
    fn_801E866C(-1);
    value = (*(float *)((char *)*(void **)((char *)fn_801EA9A0() + 8) + 0x64) - lbl_80564D88) / lbl_80564D8C;
    limit = lbl_80564D80;
    if (value < limit) limit = value;
    if (limit > lbl_80564D90) limit = lbl_80564D90;
    result = limit * lbl_80564D94;
    return lbl_80564D84 + result;
}

void fn_802BF350(void) {
    int i;
    fn_802BEDFC();
    lbl_8055FADC = fn_801E85AC();
    for (i = 0; i < lbl_8055FADC; i++) {
        lbl_804C07F0[i] = (void *)fn_802C00A4();
        if (i == 0 && lbl_804C07F0[i] != 0) {
            fn_802E30C8(lbl_8034AD78);
        }
    }
    if (fn_8012C33C(lbl_8055CF68) != 0) {
        lbl_8055CF6C = fn_802C6FC0(lbl_8055CF68, 0, 0);
    } else {
        lbl_8055CF6C = -1;
    }
}

void fn_802BF40C(void) {
    int i;
    void **obj;
    for (i = 0; i < lbl_8055FADC; i++) {
        obj = (void **)lbl_804C07F0[i];
        if (obj != 0) {
            if (obj != 0) {
                ((void (*)(void *, int))(*(void ***)obj)[2])(obj, 1);
            }
            lbl_804C07F0[i] = 0;
        }
    }
    lbl_8055FADC = 0;
    if (lbl_8055CF6C != -1) {
        fn_802C6CF8();
        lbl_8055CF6C = -1;
    }
}

int fn_802BF4B0(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

int fn_802BF4F0(void) {
    return (int)(unsigned int)lbl_804C07F0 != 0;
}

void fn_802BF508(void) {
    int index = fn_801E85B4();
    int saved;
    if (lbl_804C07F0[index] != 0 && lbl_8055CF70 != 0) {
        saved = fn_802C2C00(0);
        ((void (*)(void *, int))(*(void ***)lbl_804C07F0[index])[4])(lbl_804C07F0[index], 0);
        fn_802C2C00(saved);
    }
    fn_802BF160();
}

float fn_802BF590(void) { return lbl_8055FAF4; }

extern void *fn_801284F8(int, const char*);
extern void* fn_802BF780(void);
extern const char lbl_8034AD90[];
extern void* lbl_804C07F0[];
extern float lbl_80564DA8, lbl_80564DB0, lbl_8055FAE0;
int fn_802BF740(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668((void *)arg0);
    return arg0;
}

void fn_802C0054(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

void fn_802C00A0(void) {
}

int fn_802C0C98(void *arg0) { return *(int *)((char *)arg0 + 8); }

float fn_802C0CA0(void *arg0) { return *(float *)((char *)arg0 + 0x14); }

int fn_802C0CA8(void) { return 1; }

void *fn_802C0CB0(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 4);
        *(char **)arg0 = lbl_8034AE20;
        if (temp_r0 != -2) {
            fn_802CAC54(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_802C0D20(void) {
}

int fn_802C0D24(void *arg0) {
    return *(int *)((char *)arg0 + 4);
}

unsigned int fn_802C0D34(void) {
    return 1;
}

unsigned char fn_802C0D3C(void *arg0) {
    return *((unsigned char *)arg0 + 0x2C5C);
}

extern int fn_801E85AC(void);
extern int fn_802C00A4(void);
extern int fn_8012C33C(int);
extern int fn_802C6FC0(int, int, int);
extern void fn_802E30C8(const char *, ...);
extern char lbl_8034AD78[];
extern int lbl_8055CF68;
extern void fn_801E866C(int);
extern void *fn_801EA9A0(void);
extern float lbl_80564D80, lbl_80564D84, lbl_80564D88, lbl_80564D8C;
extern float lbl_80564D90, lbl_80564D94;
