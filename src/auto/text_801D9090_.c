// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
extern unsigned char lbl_8055E968;
extern float lbl_80562B2C;
extern void fn_80178DBC(int, float);
extern void fn_801D9AB8(void *, float);
extern void fn_801D611C(s32);
extern void fn_801D77E8(s32);
extern void fn_801D77EC(s32);
extern void fn_801D7874(s32);

extern void fn_80128668(void*);
void* fn_801D9090(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801D90E8(s32 arg0) {
    fn_801D611C(arg0 - 4);
}

void fn_801D90F0(s32 arg0) {
    fn_801D77E8(arg0 - 4);
}

void fn_801D90F8(s32 arg0) {
    fn_801D77EC(arg0 - 4);
}

void fn_801D9100(s32 arg0) {
    fn_801D7874(arg0 - 4);
}

void fn_801D9108(int arg0) { fn_801D8938(arg0 - 4); }

void fn_801D9110(int arg0) { fn_801D893C(arg0 - 4); }

void fn_801D9118(int arg0) { fn_801D89C0(arg0 - 4); }

#pragma dont_inline on
void fn_801D9120(float *out, float *values, int count, float weight) {
    extern float lbl_80562B28;
    int last = count - 1;
    float value = *(float *)((char *)values + last * 4);
    if (count == 1) {
        out[1] = weight * value;
        out[0] = weight * (lbl_80562B28 - value);
    } else {
        fn_801D9120(out, values, last, weight * (lbl_80562B28 - value));
        fn_801D9120(out + (1 << last), values, last, weight * value);
    }
}
#pragma dont_inline off
void fn_801D91D8(void) {
    extern void *lbl_8055E96C;
    extern void *lbl_8055E964;
    void *node;
    void *item;
    int index;
    int offset;
    int n;
    void **entries;
    for (node = lbl_8055E96C; node != 0; node = *(void **)((char *)node + 0x54)) {
        for (item = lbl_8055E964; item != 0; item = *(void **)((char *)item + 0x34)) {
            entries = *(void ***)item;
            n = *(int *)((char *)item + 4);
            index = 0;
            offset = 0;
            while (n > 0) {
                if (entries[offset / 4] == node)
                    break;
                offset += 4;
                index++;
                n--;
            }
            if (n <= 0)
                index = -1;
            if (index != -1) {
                int used = *(int *)((char *)node + 0x2C);
                *(int *)((char *)node + 0x2C) = used + 1;
                *(void **)(*(char **)((char *)node + 0x28) + used * 4) = item;
            }
        }
    }
}

extern void *lbl_8055E96C;
extern void *lbl_8055E964;
extern int lbl_8055E960;
extern float lbl_80562B28;
extern int fn_802C6CF8(int);
extern int fn_801D985C(int *);
extern int fn_801D9948(int *);
extern void fn_801D9120(float *, float *, int, float);
void *fn_801D9260(int count) {
    extern void *lbl_8055E96C;
    void *node = lbl_8055E96C;
    do {
        node = *(void **)((char *)node + 0x54);
        if (node == 0)
            break;
        count--;
    } while (count >= 0);
    return node;
}

void fn_801D9828(void) {
    fn_802C6CF8(lbl_8055E960);
    fn_801D985C((int *)&lbl_8055E96C);
    fn_801D9948((int *)&lbl_8055E964);
}

void *fn_801D9A54(const char *arg0) {
    void *node = lbl_8055E96C;
    while (node != 0) {
        if (strcmp(arg0, (const char *)node) == 0)
            return node;
        node = *(void **)((char *)node + 0x54);
    }
    return 0;
}

extern unsigned char lbl_8055E968;
extern float lbl_80562B2C;
extern int strcmp(const char *, const char *);
extern void fn_80178DBC(int, float);
extern void fn_801D9AB8(void *, float);
int fn_801D9B28(void *arg0, int arg1) {
    void *node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(int *)((char *)node + 8) == arg1)
            return 1;
        node = *(void **)((char *)node + 0xC);
    }
    return 0;
}

