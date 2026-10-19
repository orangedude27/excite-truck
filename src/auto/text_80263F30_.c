// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F444;
extern void *lbl_8055F448;
extern void fn_80235380(void *);
extern void fn_80128670(void *);
extern void *lbl_8055C458;
extern void fn_80236914(void);
extern void fn_80264098(void *, int);
extern void *fn_80264A54(void);
extern void *fn_80264580(void);
#pragma dont_inline on
void fn_80264098(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 4) = arg1;
}
#pragma dont_inline off

#pragma dont_inline on
#pragma dont_inline off
void fn_802640A0(void *arg0) {
    *(int *)((char *)arg0 + 8) = 0;
    *(void **)arg0 = lbl_8055C458;
    *(int *)((char *)arg0 + 4) = 0x7b;
    *(int *)((char *)arg0 + 0xc) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
}
#pragma dont_inline on
#pragma dont_inline off
void fn_802643B8(void *arg0) {
    *(void **)arg0 = lbl_8055C458;
    fn_80264098(arg0, 8);
    *(void (**)(void))((char *)arg0 + 8) = fn_80236914;
    *(int *)((char *)arg0 + 0xc) = 2;
}
#pragma dont_inline on
#pragma dont_inline off
void fn_80264404(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264A54();
}

void fn_80264444(void *arg0) {
    *(void **)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = fn_80264580();
}

void fn_80264484(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_803464A8[];
    extern char lbl_803464F8[];
    extern struct {
        void **items;
        int count;
    } lbl_80498F78;
    void *result = fn_801284F8(0x18, lbl_803464A8);
    if (result != 0) {
        *(int *)((char *)result + 0x14) = 0;
        *(void **)result = lbl_803464F8;
    }
    lbl_80498F78.items[lbl_80498F78.count++] = result;
    *(int *)arg0 = 0;
    fn_80264098(arg0, 5);
    *(void **)((char *)arg0 + 8) = result;
}

void fn_8026451C(void *arg0) {
    extern char lbl_803466D8[];
    *(void **)arg0 = lbl_803466D8;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F444 = arg0;
}

int fn_80264538(int arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F444 = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

void* fn_80264580(void) {
    return lbl_8055F444;
}

float fn_80264588(void) {
    extern int fn_802645C0(void);
    extern float lbl_80563BF4;
    if (fn_802645C0() != 0) {
        return *(float *)((char *)lbl_8055F444 + 0x20);
    }
    return lbl_80563BF4;
}

int fn_802645C0(void) {
    extern float lbl_80558DC4[];
    float v = *(float *)((char *)lbl_8055F444 + 0x18);
    double abs = __fabs((double)v);
    return (float)abs <= lbl_80558DC4[0];
}

void fn_802645EC(void) {
    extern float lbl_8055C454;
    *(float *)((char *)lbl_8055F444 + 0x1C) = lbl_8055C454;
}

void fn_802645FC(void *arg0) {
    extern float lbl_80563BF8;
    extern float lbl_8055C454;
    extern float lbl_80563BF0;
    float b = lbl_80563BF8;
    float a = lbl_80563BF0;
    *(float *)((char *)arg0 + 0x18) = b;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055C454;
    *(float *)((char *)arg0 + 0x20) = a;
}

void fn_80264618(void *arg0) {
    extern float lbl_80558DC4[];
    extern float lbl_80563BF0;
    extern float fn_80214D48(void);
    extern int fn_802645C0(void);
    extern void fn_80221F94(void *, int);
    extern void fn_80216CA8(void);
    float a;
    float b;
    float c;
    a = *(float *)((char *)arg0 + 0x1C);
    a = a < 0.0f ? -a : a;
    a = a * a;
    if (a == lbl_80558DC4[0]) {
        fn_80221F94(0, 0);
        fn_80216CA8();
        a = fn_80214D48();
    }
    b = *(float *)((char *)arg0 + 0x18);
    b = b - a;
    if (lbl_80563BF0 <= b) {
        b = lbl_80563BF0;
    }
    *(float *)((char *)arg0 + 0x18) = b;
    if (fn_802645C0() != 0) {
        c = *(float *)((char *)arg0 + 0x20);
        c = c + a;
        *(float *)((char *)arg0 + 0x20) = c;
        a = fn_80214D48();
    }
    c = *(float *)((char *)arg0 + 0x1C);
    c = c - a;
    if (lbl_80563BF0 <= c) {
        c = lbl_80563BF0;
    }
    *(float *)((char *)arg0 + 0x1C) = c;
}

void *fn_80264968(void *arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F448 = 0;
        if ((char *)arg0 + 0x78 != 0) {
            if (*(void **)((char *)arg0 + 0xB4) != 0) {
                fn_80235380(*(void **)((char *)arg0 + 0xB4));
                *(void **)((char *)arg0 + 0xB4) = 0;
            }
            if ((char *)arg0 + 0xB8 != 0) {
                fn_80128670(*(void **)((char *)arg0 + 0xC4));
                if ((volatile char *)arg0 + 0xB8 != 0) {
                    *(int *)((char *)arg0 + 0xB8) = 0;
                    *(int *)((char *)arg0 + 0xBC) = 0;
                    *(int *)((char *)arg0 + 0xC0) = 0;
                }
            }
        }
        if ((char *)arg0 + 0x18 != 0) {
            if (*(void **)((char *)arg0 + 0x54) != 0) {
                fn_80235380(*(void **)((char *)arg0 + 0x54));
                *(void **)((char *)arg0 + 0x54) = 0;
            }
            if ((char *)arg0 + 0x58 != 0) {
                fn_80128670(*(void **)((char *)arg0 + 0x64));
                if ((volatile char *)arg0 + 0x58 != 0) {
                    *(int *)((char *)arg0 + 0x58) = 0;
                    *(int *)((char *)arg0 + 0x5C) = 0;
                    *(int *)((char *)arg0 + 0x60) = 0;
                }
            }
        }
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

extern void *lbl_8055F448;
void* fn_80264A54(void) {
    return lbl_8055F448;
}

#pragma push
#pragma processor 750
void fn_80264A5C(float farg0, float farg1) {
    extern float lbl_80558DC4[];
    extern float lbl_80563C0C;
    extern float fn_80214D48(void);
    extern void fn_80230C30(float *, float *, int, int);
    float x, y;

    if (!((float)__fabs((double)fn_80214D48()) <= lbl_80558DC4[0])) {
        fn_80230C30(&x, &y, (int)farg0, (int)farg1);
        x = x + (farg0 - (float)(int)farg0);
        y = y - (farg1 - (float)(int)farg1);
        fn_80264A5C_emit((char *)lbl_8055F448 + 0x18, x, y);
        fn_80264A5C_emit((char *)lbl_8055F448 + 0x78, x, lbl_80563C0C + y);
    }
}
#pragma pop
void fn_80264FD4(void *arg0) {
    void (*fn)(void *) = *(void (**)(void *))((char *)*(void **)arg0 + 0x1C);
    fn(arg0);
}

void fn_8026523C(void *arg0) {
    extern char lbl_80346618[];
    extern float lbl_80563BF0;
    float value = lbl_80563BF0;
    *(void **)arg0 = lbl_80346618;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(unsigned char *)((char *)arg0 + 0x1C) = 0;
    *(int *)((char *)arg0 + 0xB4) = 0;
    *(float *)((char *)arg0 + 0xB8) = value;
}

int strlen(char *);
void fn_80265268(void *arg0, int arg1, char *arg2, float farg0) {
    int count = 0x96;
    char *dst = (char *)arg0 + 0x1C;
    char *src = arg2;
    *(int *)((char *)arg0 + 0x18) = arg1;
    do {
        unsigned char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0) break;
        count--;
    } while (count > 0);
    if (count == 0) dst[-1] = 0;
    *(int *)((char *)arg0 + 0xB4) = strlen((char *)arg0 + 0x1C);
    *(float *)((char *)arg0 + 0xB8) = farg0;
}

void fn_80265558(void *arg0) {
    extern char lbl_803465B8[];
    extern float lbl_80563BF0;
    float value = lbl_80563BF0;
    *(void **)arg0 = lbl_803465B8;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(float *)((char *)arg0 + 0x18) = value;
    *(float *)((char *)arg0 + 0x1C) = value;
}

void fn_8026557C(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 0x18) = farg0;
}

void fn_80265584(void *arg0) {
    extern float lbl_8055C454;
    *(float *)((char *)arg0 + 0x1C) = lbl_8055C454;
    lbl_8055C454 = *(float *)((char *)arg0 + 0x18);
}

extern char lbl_80346558[];
extern float lbl_80563BF0;
extern float lbl_8055C454;
void fn_80265598(void *arg0) {
    extern float lbl_8055C454;
    lbl_8055C454 = *(float *)((char *)arg0 + 0x1C);
}

void fn_802655A4(void *arg0) {
    extern void *lbl_8055F44C;
    extern char lbl_80346558[];
    extern float lbl_80563BF0;
    void *ptr = lbl_80346558;
    float value = lbl_80563BF0;
    *(void **)arg0 = ptr;
    *(int *)((char *)arg0 + 0x14) = 0;
    lbl_8055F44C = arg0;
    *(float *)((char *)arg0 + 0x1C) = value;
}

int fn_802655C8(int arg0, int arg1) {
    extern void *lbl_8055F44C;
    if (arg0 != 0) {
        lbl_8055F44C = 0;
        if (arg1 > 0) fn_80128668();
    }
    return arg0;
}

typedef float f32;
void fn_80265610(void *arg0, f32 farg0) { *(f32 *)((char *)arg0 + 0x1C) = farg0; }

void fn_80265618(void *arg0) {
    *(unsigned char *)((char *)arg0 + 0x20) = 0;
    *(float *)((char *)arg0 + 0x18) = *(float *)((char *)arg0 + 0x1C);
}

#pragma dont_inline on
void fn_8026562C(void *arg0) {
    extern float lbl_80558DC4[];
    extern float fn_80214D48();
    fn_802645EC();
    if (*(float *)((char *)arg0 + 0x18) > lbl_80558DC4[0]) {
        *(float *)((char *)arg0 + 0x18) -= fn_80214D48();
    } else {
        *(unsigned char *)((char *)arg0 + 0x20) = 1;
    }
}
#pragma dont_inline reset
extern char lbl_8055C4A8[4];
extern void fn_80236954(void *queue);
void fn_802658FC(void) {
    fn_80236954(lbl_8055C4A8);
}

extern int fn_802146BC(int *, int, int, int, int, int, int, int);
extern int lbl_80498F58[5];
extern int lbl_802FA73C[5];
__declspec(section ".sdata") extern char lbl_8055BAC0[];
__declspec(section ".sdata") extern char lbl_8055BAB8[];
extern void fn_802658FC(void);
extern void fn_80265904(void);
#pragma push
#pragma use_lmw_stmw off
void fn_80265940(void) {
    int data[20];
    int *v;
    v = lbl_802FA73C;
    data[0] = v[0];
    data[1] = (int)&data[5];
    data[2] = v[2];
    data[3] = v[3];
    data[4] = v[4];
    data[5] = (int)lbl_8055BAC0;
    data[6] = 8;
    data[7] = (int)fn_802658FC;
    data[8] = 0;
    data[9] = 0;
    data[10] = (int)lbl_8055BAB8;
    data[11] = 8;
    data[12] = (int)fn_80265904;
    data[13] = 2;
    data[14] = 0;
    data[15] = lbl_80498F58[0];
    data[16] = lbl_80498F58[1];
    data[17] = lbl_80498F58[2];
    data[18] = lbl_80498F58[3];
    data[19] = lbl_80498F58[4];
    fn_802146BC(data, -999, -999, 1, v[4], v[3], v[2], v[0]);
}
#pragma pop
extern void fn_80236954(void *);
extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
extern char lbl_803464EC[];
extern void *lbl_8055F44C;
extern unsigned char lbl_8055F450;
int fn_80128668(void);
#pragma push
#pragma small_data off
void fn_80265A28(void) {
    fn_80236954(lbl_803464EC);
}
#pragma pop
void fn_80265A34(void) {
    fn_80236914();
    if (fn_8023695C(lbl_803464EC) == 2) {
        fn_80216CA8();
        fn_802168BC(0);
    }
}

int fn_80265B5C(void) {
    register void *p = lbl_8055F44C;
    register int result = 1;
    register int found = 0;

    if (p != 0 && *((unsigned char *)p + 0x20) != 0) {
        found = 1;
    }
    if (found != 0) {
        return result;
    }
    if (lbl_8055F450 != 0) {
        return result;
    }
    return 0;
}

int fn_80265B9C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265BDC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

int fn_80265C1C(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

