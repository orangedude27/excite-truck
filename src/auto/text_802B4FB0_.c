// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128658(void *);
extern int fn_802B4FD0(void *, ...);
extern void *fn_802B51E4(int, int);
extern int fn_802B50E8(int, int, int);
extern void *fn_801284E8(void *, int, int);
extern int fn_802B4FB0(unsigned char);
extern char lbl_8034A4E0[];

int fn_802B5070(void *arg0, int arg1) {
    int result = 0;
    if (*(unsigned char *)((char *)arg0 + 2) == 2 &&
        fn_802B4FB0(*(unsigned char *)((char *)arg0 + 0x10)) != 0 &&
        arg1 == *(unsigned short *)((char *)arg0 + 0xC) *
                *(unsigned short *)((char *)arg0 + 0xE)) {
        result = 1;
    }
    return result;
}

void *fn_802B51E4(int arg0, int arg1) {
    int size = arg0 * arg1 * 4;
    char *result = fn_801284E8(lbl_8034A4E0, size + 0xC, size);
    *(int *)result = arg0;
    *(int *)(result + 4) = arg1;
    *(void **)(result + 8) = result + 0xC;
    return result;
}

void *fn_802B5240(int arg0) {
    int spC;
    int sp8;
    void *result = 0;
    if (fn_802B4FD0((void *)arg0, &spC, &sp8) != 0) {
        result = fn_802B51E4(spC, sp8);
        fn_802B50E8(arg0, *(int *)((char *)result + 8),
                    *(int *)result * *(int *)((char *)result + 4));
    }
    return result;
}

void fn_802B52B4(void *arg0) {
    *(int *)((char *)arg0 + 8) = 0;
    fn_80128658(arg0);
}
