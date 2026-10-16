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
    *(int *)(arg0 + 0) = result;
    *(int *)(arg0 + 4) = 0;
    *(int *)(arg0 + 8) = -1;
    *(int *)(arg0 + 0xC) = -1;
    *(int *)(arg0 + 0x10) = 0;
    *(char *)(arg0 + 0x14) = 1;
    *(float *)(arg0 + 0x18) = lbl_80562F18;
    *(float *)(arg0 + 0x1C) = lbl_80562F1C;
    *(float *)(arg0 + 0x20) = lbl_80562F1C;
    *(float *)(arg0 + 0x24) = lbl_80562F1C;
    *(float *)(arg0 + 0x28) = lbl_80562F18;
    *(float *)(arg0 + 0x2C) = lbl_80562F1C;
    *(float *)(arg0 + 0x30) = lbl_80562F1C;
    *(float *)(arg0 + 0x34) = lbl_80562F1C;
    *(float *)(arg0 + 0x38) = lbl_80562F18;
    *(float *)(arg0 + 0x3C) = lbl_80562F1C;
    *(float *)(arg0 + 0x40) = lbl_80562F1C;
    *(float *)(arg0 + 0x44) = lbl_80562F1C;
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
    int result = fn_801F1978(0);
    fn_802C70AC(*(int *)(*(int *)arg0 + *(int *)(arg0 + 4) * 4 + 0x28), arg1, 0, result);
}

void fn_801F13F4(int *arg0) {
    int base = *arg0 + 0xEC;
    int count;
    int index;
    float value;
    if (*(float *)(base + 0x48) < (float)__builtin_fabsf(0.0f)) return;
    if (arg0[1] == 3) return;
    count = *(int *)(base + 0x40) - 1;
    index = count;
    while (index >= 0 && *(float *)(base + index * 8 + 4) > 0.0f) {
        index--;
    }
    if (index < 0) return;
    value = *(float *)(base + 0x44);
    fn_802C7AE0(*(int *)(base + index * 8), arg0 + 6, -1);
}

void fn_801F1474(int *arg0, void *arg1) {
    int base = *arg0;
    if (*(int *)(base + 0x12C) <= 0) return;
    fn_802C7AE0(*(int *)(base + 0xEC), arg1, -1);
}

