// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055F444;
extern void *lbl_8055C458;
extern void fn_80236914(void);
extern void fn_80264098(void *, int);
extern void *fn_80264A54(void);
void fn_80264098(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 4) = arg1;
}

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

void fn_80264618(void *arg0) {
    extern float lbl_80558DC4;
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
    if (a == lbl_80558DC4) {
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

extern void *lbl_8055F448;
void* fn_80264A54(void) {
    return lbl_8055F448;
}

void fn_80264FD4(void *arg0) {
    void *v = *(void **)arg0;
    void (*fn)(void) = *(void (**)(void))((char *)v + 0x1C);
    fn();
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

extern char lbl_8055C4A8[4];
extern void fn_80236954(void *queue);
void fn_802658FC(void) {
    fn_80236954(lbl_8055C4A8);
}

extern int fn_802146BC(int *, int, int, int);
extern int lbl_80498F58[5];
extern int lbl_802FA73C[5];
extern char lbl_8055BAC0[];
extern char lbl_8055BAB8[];
extern void fn_802658FC(void);
extern void fn_80265904(void);
void fn_80265940(void) {
    int a = lbl_80498F58[0];
    int b = lbl_80498F58[1];
    int c = lbl_80498F58[2];
    int d = lbl_80498F58[3];
    int e = lbl_80498F58[4];
    int f = lbl_802FA73C[0];
    int g = lbl_802FA73C[2];
    int h = lbl_802FA73C[3];
    int i = lbl_802FA73C[4];
    int values[20];
    values[0] = f;
    values[1] = (int)&values[5];
    values[2] = g;
    values[3] = h;
    values[4] = i;
    values[5] = (int)lbl_8055BAC0;
    values[6] = 8;
    values[7] = (int)fn_802658FC;
    values[8] = 0;
    values[9] = 0;
    values[10] = (int)lbl_8055BAB8;
    values[11] = 8;
    values[12] = (int)fn_80265904;
    values[13] = 2;
    values[14] = 0;
    values[15] = a;
    values[16] = b;
    values[17] = c;
    values[18] = d;
    values[19] = e;
    fn_802146BC(values, -0x3E7, -0x3E7, 1);
}

extern void fn_80236954(void *);
extern int fn_8023695C(void *);
extern void fn_80216CA8(void);
extern void fn_802168BC(int);
extern char lbl_803464EC[4];
extern void *lbl_8055F44C;
extern unsigned char lbl_8055F450;
int fn_80128668(void);
#pragma push
#pragma small_data off
void fn_80265A28(void) {
    fn_80236954(lbl_803464EC);
}
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

