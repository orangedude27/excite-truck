// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int *lbl_8055D46C;
extern int lbl_8055D464;
extern int lbl_8055D468;
extern unsigned char lbl_8034F650[];
extern int fn_8000DF2C(int);
extern void *memset(void *, int, unsigned int);
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

int fn_8000DBAC(int arg0) {
    return *(int *)((char *)lbl_8055D46C + arg0 * 0x18 + 4) == 0;
}

extern int lbl_8055D460;
extern unsigned int lbl_8034F628[];
extern char lbl_802FC264[];
extern void fn_802E30C8(const char *, int);
void fn_8000DBC8(int arg0) {
    int i;
    for (i = 0; i < lbl_8055D460; i++) {
        if (lbl_8034F628[i] == (unsigned int)arg0) {
            fn_802E30C8(lbl_802FC264, arg0);
            return;
        }
    }
    lbl_8034F628[lbl_8055D460] = arg0;
    lbl_8055D460++;
}
extern int lbl_8055D460;
extern unsigned int lbl_8034F628[];
extern char lbl_802FC264[];
extern void fn_802E30C8(const char *, int);
