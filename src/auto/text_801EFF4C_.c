// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801EFF4C(void* alarm) {
    fn_801F17C8(fn_801F0AA0(alarm));
}

void fn_801EFF70(void* alarm) {
    fn_801F0CC4(fn_801F17DC(alarm));
}

int fn_801F0F18(int, int);
int fn_801F0E88(int, int);
int fn_801284F8(int, void *);
int fn_801F0DC0(int, int, int);
extern int lbl_8055B0B8;
void fn_801F0000(int arg0) {
    fn_801F0F18(arg0, -1);
}

int fn_801F0008(void) {
    return 0x4C;
}

int fn_801F0010(int arg0, int arg1) {
    int value = arg1;
    if (value != 0) {
        value = fn_801F0E88(value, arg0);
    }
    return value;
}

extern float lbl_80562F10;
extern float lbl_80562F14;
extern float lbl_80562F18;
extern int lbl_8033A400;
extern int lbl_8033A410;
extern int lbl_8055B0C0;
extern int lbl_8055EBEC;
extern int lbl_8055EBF0;
int stricmp(const char *, const char *);
void fn_801F08AC(int, const char *);
int fn_801F09FC(const char *arg0) {
    int offset = 0;
    int count = 0;
    while (count < lbl_8055EBF0) {
        if (stricmp((const char *)(lbl_8055EBEC + offset), arg0) == 0) {
            return lbl_8055EBEC + count * 0x138;
        }
        offset += 0x138;
        count++;
    }
    {
        int result = lbl_8055EBEC + lbl_8055EBF0 * 0x138;
        lbl_8055EBF0++;
        fn_801F08AC(result, arg0);
        return result;
    }
}

extern float lbl_80562F1C;
#pragma dont_inline on
int fn_801F0E88(int arg0, int arg1) {
    int result = fn_801F09FC((const char *)arg1);
    float zero = lbl_80562F1C;
    float one = lbl_80562F18;
    *(int *)(arg0 + 0) = result;
    *(int *)(arg0 + 4) = 0;
    *(int *)(arg0 + 8) = -1;
    *(int *)(arg0 + 0xC) = -1;
    *(int *)(arg0 + 0x10) = 0;
    *(char *)(arg0 + 0x14) = 1;
    *(float *)(arg0 + 0x18) = one;
    *(float *)(arg0 + 0x1C) = zero;
    *(float *)(arg0 + 0x20) = zero;
    *(float *)(arg0 + 0x24) = zero;
    *(float *)(arg0 + 0x28) = one;
    *(float *)(arg0 + 0x2C) = zero;
    *(float *)(arg0 + 0x30) = zero;
    *(float *)(arg0 + 0x34) = zero;
    *(float *)(arg0 + 0x38) = one;
    *(float *)(arg0 + 0x3C) = zero;
    *(float *)(arg0 + 0x40) = zero;
    *(float *)(arg0 + 0x44) = zero;
    return arg0;
}
#pragma dont_inline off
int fn_801F0F18(int arg0, int arg1) {
    if (arg0 != 0) {
        if (*(unsigned char *)(arg0 + 0x14) == 0) fn_801F18F0();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_801F131C(int arg0, int arg1) {
    if (*(unsigned int *)(arg0 + 4) != 3) {
        int value;
        if (arg1 != 0) value = 0;
        else value = fn_801F15A8(arg0, arg0 + 0x3C);
        fn_801F163C(arg0, value, *(float *)(arg0 + 0x48));
    }
}

void fn_801F1378(void *arg0) {
    if (*(unsigned int *)((char *)arg0 + 4) != 3)
        fn_801F163C(arg0, 0, *(float *)((char *)arg0 + 0x48));
}

int fn_801F1394(int *arg0, int arg1) {
    int frame = fn_801F1978(0);
    fn_802C70AC(*(*(int **)arg0 + *(int *)(arg0 + 4)) + 0x28, arg1, 0, frame);
}

void fn_801F13F4(int *arg0, float arg1, float arg2) {
    int *object = arg0;
    int *base = (int *)*arg0;
    int count;
    int *entry;
    base = (int *)((char *)base + 0xEC);
    if (arg1 > *(float *)((char *)base + 0x48)) return;
    if (*(unsigned int *)(arg0 + 1) == 3) return;
    count = *(int *)((char *)base + 0x40) - 1;
    entry = (int *)((char *)base + count * 8);
    if (count < 0) return;
    while (arg1 < *(float *)((char *)entry + 4)) {
        entry = (int *)((char *)entry - 8);
        count--;
        if (count < 0) return;
    }
    {
        float value = *(float *)((char *)base + 0x44);
        fn_802C7AE0(*((int *)((char *)base) + count * 2), (char *)object + 0x18, -1);
    }
}

void fn_801F1474(int *arg0, void *arg1) {
    int base = *arg0;
    if (*(int *)(base + 0x12C) <= 0) return;
    fn_802C7AE0(*(int *)(base + 0xEC), arg1, -1);
}

short fn_801EAC3C(void);
int fn_801F1494(int, void *, short);
int fn_801EAB2C(void);
int fn_801EAB80(void *, int);
int fn_80297988(void *);
int memset(void *, int, unsigned int);
#pragma push
#pragma small_data off
extern int lbl_8033A5E8;
#pragma pop
void *fn_801F19FC(void *arg0, int arg1) {
    fn_801EAB2C();
    *(int **)arg0 = &lbl_8033A5E8;
    fn_801EAB80(arg0, arg1);
    memset((char *)arg0 + 0x3C, 0, 0x44);
    *(int *)((char *)arg0 + 0x80) = 0;
    fn_80297988(arg0);
    return arg0;
}

int fn_801F1A70(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668(arg0);
    }
    return arg0;
}

#pragma dont_inline on
void fn_801F1AB0(void *arg0) {
    int *value = *(int **)((char *)arg0 + 0x80);
    if (value != 0) {
        fn_801F1394(value, (int)((char *)arg0 + 4));
    }
}

void fn_801F1AD0(void *arg0) {
    if (*(int *)((char *)arg0 + 0x80) != 0) {
        fn_801F1494(*(int *)((char *)arg0 + 0x80), (char *)arg0 + 4, fn_801EAC3C());
    }
}

#pragma dont_inline off
