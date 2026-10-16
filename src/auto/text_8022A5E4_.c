// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055B8B0[];
extern char lbl_80490968[];
extern char *strstr(const char *, const char *);
extern void fn_8022C9D0(void);
extern void fn_8022CAA8(void *);
void fn_8022A7D0(void) {
    fn_8022C9D0();
}

int fn_8022A7D4(const char *arg0) {
    return strstr(arg0, lbl_8055B8B0) != 0;
}

unsigned int fn_8022A834(unsigned int arg0) {
    unsigned int byte = arg0 >> 24;
    if (byte >= 0x20 || byte == 0) {
    } else {
        arg0 = (arg0 & 0x00FFFFFF) | 0xFF000000;
    }
    return arg0;
}

void fn_8022A858(int arg0) {
    fn_8022CAA8(lbl_80490968 + arg0 * 0x74);
}

int fn_8022A86C(int arg0) {
    int i;
    for (i = 0; i < 0x100; i++) {
        if ((unsigned char)lbl_80490968[i * 0x74] == 0) {
            fn_8022A858(i);
            return i;
        }
    }
    return -1;
}

extern void *fn_8022CA2C(void);
int fn_8022AA84(void) {
    return *(int *)((char *)fn_8022CA2C() + 0x38);
}

int fn_8022AB18(int unused, int arg1, int arg2) {
    void *p = fn_8022CA2C();
    if (arg1 == 0) {
        if (arg2 == 2) return *(int *)((char *)p + 0x44);
        return *(int *)((char *)p + 0x4c);
    }
    if (arg1 == 1) {
        if (arg2 == 2) return *(int *)((char *)p + 0x48);
        return *(int *)((char *)p + 0x50);
    }
    return 0;
}

