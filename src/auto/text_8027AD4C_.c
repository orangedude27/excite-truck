// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_804A4380[];

extern char lbl_80347B78[];
extern char lbl_80347C14[];
extern char lbl_80347C38[];
extern char *fn_80131234(char *);
long fn_8027CB28(void);
extern long lbl_8055F654;
long *fn_8027C120(long, long);
long fn_8027C8B0(void);
long fn_802E317C(char *, ...);

extern char lbl_804A4380[];
void *fn_8027B878(long arg0) {
    return lbl_804A4380 + fn_8000DA10() * 0x3B10 + arg0 * 0xBD0 + 0x2370;
}

void fn_8027B8C0(void* alarm) {
    fn_8027BA24(fn_8027B834(alarm));
}

void fn_8027B94C(void *arg0) {
    fn_8027B8E4(arg0, fn_8000DA10());
}

void fn_8027B9EC(void *arg0) {
    fn_8027B984(arg0, fn_8000DA10());
}

long fn_8027BAB8(void *arg0) {
    long i = 0;
    while (1) {
        void *item = ((void *(*)(void *, long))(*(void ***)arg0)[4])(arg0, i);
        if (((long (*)(void *))(*(void ***)item)[10])(item) == 0)
            return 0;
        i++;
        if (i >= ((long (*)(void *))(*(void ***)arg0)[3])(arg0))
            return 1;
    }
}

long fn_8027BB4C(long, long, long, long);
void fn_8027BCC0(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 0);
}

void fn_8027BCC8(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 1);
}

long fn_8027C8B0(void) { return 1; }

long fn_8027CB20(void) { return 1; }

