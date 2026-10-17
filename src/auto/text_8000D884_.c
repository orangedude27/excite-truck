// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int *lbl_8055D46C;
extern int lbl_8055D464;
extern int lbl_80558A88;
extern unsigned char lbl_8055D470;
extern char lbl_802FC240[];
extern int fn_801284E8(const char *, int);
extern void fn_802E6BD8(int, int, int, int, void *);
extern void fn_8000DD98(void);
extern void fn_8000D984(int);
extern void fn_8000DA80(void);
extern void fn_8000DC84(void);
extern int lbl_8055D468;
extern unsigned char lbl_8034F650[];
extern void fn_8000DF2C(int);
extern void *memset(void *, int, unsigned int);
extern void fn_80247624(void);
extern void *fn_80131234(const char *);
extern char lbl_802FC24C[];
extern int fn_80128658(int);
extern void fn_80247624(void);
extern void *fn_80131234(const char *);
extern char lbl_802FC24C[];
extern int fn_80128658(int);
void fn_8000D884(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int *entry;
    int count;
    int offset;

    count = lbl_8055D464;
    entry = (int *)(lbl_8034F650 + count * 0x18);
    entry[0] = arg0;
    entry[1] = arg1;
    entry[2] = arg2;
    entry[3] = arg3;
    entry[4] = arg4;
    lbl_8055D464 = count + 1;
    entry[5] = lbl_80558A88;
    offset = arg3 * 4;
    lbl_80558A88 += offset;
}

void fn_8000D8C8(void) {
    int size;
    int i;
    size = fn_801284E8(lbl_802FC240, lbl_80558A88);
    lbl_8055D470 = 1;
    lbl_8055D468 = size;
    fn_802E6BD8(0x49646E74, 2, size, lbl_80558A88, fn_8000DC84);
    lbl_8055D46C = (int *)lbl_8055D468;
    fn_8000DD98();
    for (i = 3; i >= 0; i--) {
        fn_8000D984(i);
        fn_8000DA80();
    }
}

void fn_8000D94C(void) {
    int zero;
    zero = 0;
    lbl_8055D46C = (int *)zero;
    fn_80128658(lbl_8055D468);
    lbl_8055D468 = zero;
}

void fn_8000D984(int arg0) {
    unsigned char *entry;
    int i;

    fn_8000DF2C(2);
    entry = lbl_8034F650;
    *lbl_8055D46C = arg0;
    i = 0;
    do {
        if (i < lbl_8055D464) {
            i++;
            *(int **)(entry + 8) = (int *)(*(int *)(entry + 12) * *lbl_8055D46C + lbl_8055D468 + *(int *)(entry + 20));
            entry += 0x18;
        }
    } while (i < lbl_8055D464);
    fn_8000DF2C(3);
}

int fn_8000DA10(void) {
    return *lbl_8055D46C;
}

void fn_8000DA1C(const char *arg0) {
    int *p;
    char *dst;
    int n;
    unsigned char c;
    p = (int *)((char *)lbl_8055D46C + *lbl_8055D46C * 0x18);
    p[1] = 2;
    p = (int *)((char *)lbl_8055D46C + *lbl_8055D46C * 0x18);
    dst = (char *)p + 8;
    n = 0x12;
    do { n--; } while (n > 0);
    dst[-1] = 0;
    do {
        c = *arg0++;
        *dst++ = c;
    } while ((signed char)c != 0);
}

void fn_8000DA80(void) {
    int *entry;
    int i;
    entry = (int *)((char *)lbl_8055D46C + *lbl_8055D46C * 0x18);
    entry[1] = 0;
    fn_8000DF2C(0);
    entry = (int *)lbl_8034F650;
    i = 0;
    do {
        memset(*(void **)((char *)entry + 8), 0, *(unsigned int *)((char *)entry + 12));
        if (*(void (**)(void))((char *)entry + 16) != 0)
            (*(void (**)(void))((char *)entry + 16))();
        entry = (int *)((char *)entry + 0x18);
        i++;
    } while (i < lbl_8055D464);
}

void fn_8000DB18(void) {
    int *entry;
    entry = (int *)((char *)lbl_8055D46C + *lbl_8055D46C * 0x18);
    entry[1] = 2;
}

void *fn_8000DB34(int arg0) {
    char *entry;
    fn_80247624();
    entry = (char *)lbl_8055D46C + arg0 * 0x18;
    if (*(int *)(entry + 4) == 0)
        return fn_80131234(lbl_802FC24C);
    return entry + 8;
}

int fn_8000DB8C(int arg0) {
    return *(int *)((char *)lbl_8055D46C + arg0 * 0x18 + 4) == 2;
}

int fn_8000DBAC(int arg0) {
    return *(int *)((char *)lbl_8055D46C + arg0 * 0x18 + 4) == 0;
}

extern int lbl_8055D460;
extern unsigned int lbl_8034F628[];
extern char lbl_802FC264[];
extern void fn_802E30C8(const char *, int);
void fn_8000DBC8(int arg0) {
    int count;
    unsigned int *entry;

    count = lbl_8055D460;
    entry = lbl_8034F628;
    if (count > 0) {
        for (; count != 0; count--) {
            if (*entry == (unsigned int)arg0) {
                fn_802E30C8(lbl_802FC264, arg0);
                return;
            }
            entry++;
        }
    }
    count = lbl_8055D460;
    lbl_8034F628[count] = arg0;
    lbl_8055D460 = count + 1;
}

void fn_8000DC28(const char *arg0, int arg1) {
    register char *dst;
    register unsigned char c;
    register int count;

    dst = (char *)lbl_8055D46C + arg1 * 0x12 + 0x64;
    count = 0x12;
    while (count-- > 0) {
    }
    dst[-1] = 0;
    do {
        c = *arg0++;
        *dst++ = c;
    } while ((signed char)c != 0);
}

int fn_8000DC70(int arg0) {
    return (int)((char *)lbl_8055D46C + arg0 * 0x12 + 0x64);
}

extern int lbl_8055D460;
extern unsigned int lbl_8034F628[];
extern char lbl_802FC264[];
extern void fn_802E30C8(const char *, int);
