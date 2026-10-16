// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80171D10(int arg0) { fn_80171930(arg0 - 4); }

void fn_80171D18(int arg0) { fn_80171934(arg0 - 4); }

void fn_80171D20(int arg0) { fn_80171A4C(arg0 - 4); }

void fn_80171D28(int arg0) { fn_80171A80(arg0 - 4); }

int fn_80171D38(int arg0) {
    unsigned char sp[0x68];
    int index;
    int result = 0;
    if (fn_801298E8(sp, arg0) != 0) {
        index = *(int *)(__AXFXGetLfoSinTable_801297F4() + 0x30);
        if (*(sp + 0x20 + index) != 0)
            result = 1;
    }
    return result;
}

int fn_80171DE4(void *arg0) {
    extern int fn_80139EC4(int, float, float);
    extern int lbl_8055E3A4;
    int result = 0;
    if (lbl_8055E3A4 != 0 && fn_80139EC4(lbl_8055E3A4, *(float *)arg0, *(float *)((char *)arg0 + 4)) != 0) result = 1;
    return result;
}

int fn_80171E3C(void *arg0) {
    extern int fn_802B04D4(float *, float, float);
    extern int fn_80139EC4(int, float, float);
    extern int lbl_8055E3A4;
    extern float lbl_80561A38;
    float sp8, spC, sp10;
    sp10 = *(float *)((char *)arg0 + 4);
    sp8 = *(float *)arg0;
    spC = lbl_80561A38;
    if (fn_802B04D4(&sp8, sp8, sp10)) return 0;
    if (lbl_8055E3A4 && fn_80139EC4(lbl_8055E3A4, *(float *)arg0, *(float *)((char *)arg0 + 4))) return 0;
    return 1;
}

int fn_80171EC0(void) {
    extern void *fn_8017960C(int);
    return *(int *)((char *)fn_8017960C(0) + 0x10) == 0x50434152;
}

unsigned int fn_801720E0(unsigned int arg0) {
    return ((arg0 >> 1) & 0x7F7F7F) | (arg0 & 0xFF000000);
}

float fn_801725C8(float arg0) {
    extern float lbl_8043038C[];
    extern float lbl_80561A40;
    extern float lbl_80561A44;
    float f0 = lbl_8043038C[2];
    float f2 = lbl_8043038C[3];
    float f3 = lbl_8043038C[0];
    float f4 = lbl_8043038C[1];
    float value = (arg0 - f0) / (f2 - f0);
    float t = lbl_80561A40;
    if (t < value)
        t = value;
    if (t > lbl_80561A44)
        t = lbl_80561A44;
    return f3 + t * (f4 - f3);
}

int fn_80172624(void *arg0, int arg1) {
    extern void *fn_8017960C(int);
    extern float PSQUATMultiply(void *, void *);
    extern float lbl_8043038C[];
    void *a = fn_8017960C((int)arg0);
    void *b = fn_8017960C(arg1);
    float dot = PSQUATMultiply((char *)a + 0x118, (char *)b + 0x118);
    float threshold = *(float *)((char *)a + 0x25D4);
    float value = lbl_8043038C[9] * dot + lbl_8043038C[10] * threshold;
    int result = 0;
    if (value >= lbl_8043038C[8])
        return 2;
    if (value >= lbl_8043038C[7])
        result = 1;
    return result;
}

void *fn_801726C4(void *arg0) {
    extern void *fn_801284F8(unsigned int, void *);
    extern char lbl_80330F48[];
    extern char lbl_80330FE8[];
    void *result = fn_801284F8(0x12C, lbl_80330F48);
    if (result != 0) {
        *(void **)result = lbl_80330FE8;
        *(int *)((char *)result + 0x124) = fn_801EA994();
        *(void **)((char *)result + 0x128) = arg0;
    }
    return result;
}

int fn_80172E24(int arg0, int arg1) {
    extern int fn_80128668(void);
    if (arg0 != 0 && arg1 > 0)
        fn_80128668();
    return arg0;
}

int fn_80173A84(void *arg0) {
    int count = *(int *)((char *)arg0 + 0x170);
    int result = 0;
    int i;
    if (count > 0) {
        for (i = 0; i < count; i++) {
            if (*(unsigned char *)((char *)arg0 + 0x91) == 0 &&
                *(unsigned char *)((char *)arg0 + 0x90) != 0)
                result++;
            arg0 = (char *)arg0 + 0x1C;
        }
    }
    return result != 0;
}

int fn_80174298(void *arg0, int arg1) {
    extern float lbl_80558DC4[];
    extern float lbl_8055E3C8;
    extern float lbl_80561A44;
    int result = *((unsigned char *)arg0 + arg1 * 0x1C + 0x90);
    if (result != 0) {
        float one = lbl_8055E3C8;
        float value = *(float *)((char *)arg0 + 0x19C) - one;
        float limit = lbl_80561A44;
        limit = limit > value ? limit : value;
        result = !((float)__fabs(limit) <= lbl_80558DC4[0]);
    }
    return result;
}

int fn_801742FC(void *arg0) {
    extern float lbl_80561A44;
    return *(float *)((char *)arg0 + 0x1A0) > lbl_80561A44;
}

int fn_80174314(void) {
    return 8;
}

void fn_80174794(void *arg0) {
    extern float fn_801B306C(void);
    extern int fn_800216D0(void);
    extern int fn_801EA994(void);
    extern int fn_801E866C(int);
    extern void fn_8017248C(int);
    extern float lbl_80561A44;
    int count;
    int i;
    if (fn_801B306C() < lbl_80561A44 && fn_800216D0() == 0) {
        count = fn_801EA994();
        for (i = 0; i < count; i++) {
            if (i != fn_801E866C(-1) &&
                (*(int (***)(void *, int))arg0)[8](arg0, i)) {
                fn_8017248C(i);
            }
        }
    }
}

void fn_80175228(void *arg0) {
    register void *vtable = *(void **)arg0;
    register void *slot = *(void **)((char *)vtable + 0x4C);
    ((void (*)(void))slot)();
}

extern float lbl_80561AEC;
float fn_801757A8(void) { return lbl_80561AEC; }

int fn_801757B0(void) { return 1; }

int fn_801758B8(void *arg0) { return *(int *)((char *)arg0 + 0x1AC) == 2; }

int fn_80175A38(void *arg0, float *arg1, float *arg2, int arg3, int arg4, int *arg5) {
    char *p = (char *)arg0 + arg3 * 0x24;
    *arg5 = 0x21F;
    arg1[0] = *(float *)(p + 0x18);
    arg1[1] = *(float *)(p + 0x1C);
    *arg2 = *(float *)(p + 0x20);
    return 1;
}

extern void *fn_8017960C(int);
extern float lbl_80561AF0;
extern float lbl_80561AF4;
int fn_80175A68(void *unused, float *arg0, float *arg1, int arg2, void *unused2, int *arg3) {
    float *p = (float *)fn_8017960C(arg2);
    float scale = lbl_80561AF0;
    float x = p[0x54 / 4] * scale + p[0x60 / 4];
    float y = p[0x5C / 4] * scale + p[0x68 / 4];
    float z = p[0x58 / 4] * scale + p[0x64 / 4];
    arg0[0] = x;
    arg0[1] = y;
    *arg3 = 0x21F;
    *arg1 = lbl_80561AF4;
    *(volatile float *)((char *)&z) = z;
    return 1;
}

int fn_80176030(void) { return 0; }

int fn_80176038(void) { return 0; }

void fn_80176400(void) {
}
