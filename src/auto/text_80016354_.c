// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
extern unsigned char *lbl_8055D544;
extern int stricmp(const char *, const char *);
extern int fn_80016510(int);

extern void *lbl_8055D54C;
void* fn_80016508(void) {
    return lbl_8055D54C;
}

extern void *lbl_8055D550;
void* fn_800165D4(void) {
    return lbl_8055D550;
}

void fn_800165DC(void) {
    fn_80016510(*(int *)((char *)fn_80016474() + 0x4C));
}

int fn_80016604(const char *arg0) {
    int i, offset = 0, count = 0;
    for (i = 0; i < (int)lbl_8055D550; i++) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), arg0) == 0) count++;
        offset += 0xA8;
    }
    return count;
}

void *fn_8001668C(const char *arg0, int arg1) {
    int i, count = 0, offset = 0;
    for (i = 0; i < (int)lbl_8055D550; i++, offset += 0xA8) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), arg0) == 0) {
            if (count == arg1) return lbl_8055D544 + i * 0xA8;
            count++;
        }
    }
    return lbl_8055D544;
}

void *fn_80016720(const char *arg0) {
    void *result = fn_8001668C(arg0, 0);
    if (*(int *)((char *)result + 0xA0) & 2) {
        result = (void *)fn_80016544(*(int *)((char *)result + 8));
    }
    return (char *)result + 0x2C;
}

void *fn_800167B8(int arg0) { return lbl_803577F0 + arg0 * 0x5C; }

void fn_800167CC(void) {
    fn_80016510(*(int *)((char *)fn_80016474() + 0x4C));
}

extern void *lbl_8055D554;
extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
void* fn_800167F4(void) {
    return lbl_8055D554;
}

void fn_800167FC(void *arg0) {
    lbl_8055D554 = arg0;
}

int fn_80016804(int arg0, int arg1) {
    if (arg1 < (int)lbl_8055D554 &&
        arg0 == *(int *)(lbl_803577F0 + arg1 * 0x5C + 4)) {
        return 1;
    }
    return 0;
}

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
void fn_8001683C(void *arg0, int arg1) {
    void *temp = fn_80016474();
    *(void **)(lbl_803577F0 + arg1 * 0x5C + 4) = arg0;
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x4C) = *(int *)((char *)temp + 0x4C);
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x50) = *(int *)((char *)temp + 0x50);
    *(int *)(lbl_80357960 + arg1 * 0xA8 + 4) = -1000;
}

extern unsigned char *lbl_8055D540;
extern unsigned char *lbl_8055D544;
void fn_800168B0(int arg0, int arg1) {
    int i;
    unsigned char *p;
    for (i = 0, p = lbl_803577F0; i < (int)lbl_8055D554; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) *(int *)(p + 0x50) = arg1;
    }
    for (i = 0, p = lbl_8055D540; i < (int)lbl_8055D54C; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) {
            *(int *)(lbl_8055D540 + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}

void fn_80016928(int arg0, int arg1) {
    int i;
    unsigned char *p;
    for (i = 0, p = lbl_8055D540; i < (int)lbl_8055D54C; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) {
            *(int *)(lbl_8055D540 + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}

void fn_80016970(int arg0, int arg1, int arg2, int arg3) {
    int offset = arg0 * 0x5C;
    unsigned char *entry = lbl_803577F0 + offset;
    *(int *)(entry + 4) = arg1;
    *(int *)(entry + 0x4C) = *(int *)fn_80016544(arg2);
    *(int *)(entry + 0x50) = arg3;
    *(int *)(lbl_80357960 + arg0 * 0xA8 + 4) = -1000;
}

void fn_800169F8(const char *src, int index) {
    char *dst = (char *)(lbl_803577F0 + index * 0x5C + 8);
    int count = 0x40;
    do {
        *dst++ = *src++;
        if (dst[-1] == 0) return;
        count--;
    } while (count > 0);
    dst[-1] = 0;
}

void fn_80016A44(void) {
    fn_8001766C();
}
