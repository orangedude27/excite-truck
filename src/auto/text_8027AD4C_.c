// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_804A4380[];
void fn_8027AF94(void *);
void fn_8027B288(void *);
long fn_80131818(long);

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
unsigned char fn_8027AF84(void *arg0) {
    return *((unsigned char *)arg0 + 0x11);
}

unsigned char fn_8027AF8C(void *arg0) { return *((unsigned char *)arg0 + 0x10); }

void fn_8027AF94(void *arg0) { ((unsigned char *)arg0)[4] = 0; }

unsigned char fn_8027B280(void *arg0) {
    return *((unsigned char *)arg0 + 0x12);
}

void fn_8027B288(void *arg0) {
    long i = 0;
    long offset = 0;
    do {
        fn_8027AF94((char *)*(void **)((char *)arg0 + 0x18) + offset);
        offset += 0x3C;
        i++;
    } while (i < *(long *)((char *)arg0 + 0x1C));
    *(long *)((char *)arg0 + 0x1C) = 0;
    *(long *)((char *)arg0 + 0x10) = 0;
}

void fn_8027B60C(void *arg0) {
    long i;
    long offset;
    if (*(long *)((char *)arg0 + 4) != 0) {
        i = 0;
        offset = 0;
        do {
            fn_8027B288((char *)*(void **)((char *)arg0 + 8) + offset);
            offset += 0x1F4;
            i++;
        } while (i < *(long *)((char *)arg0 + 0xC));
        offset = 0;
        fn_80131818(*(long *)((char *)arg0 + 4));
        *(long *)((char *)arg0 + 0xC) = 0;
        *(long *)((char *)arg0 + 4) = 0;
    }
}

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

long fn_8027CBF0(void) { return 1; }

void fn_8027CBF8(long arg0, char *arg1, long arg2) {
    long count;
    char *src;
    char c;

    count = arg2;
    if (fn_8027CB28()) {
        src = fn_80131234(lbl_80347B78);
        count--;
        if (count > 0)
            goto copy_a;
        goto terminate_a;
copy_a:
        c = *src++;
        *arg1++ = c;
        if ((signed char)c == 0)
            goto finish_a;
        count--;
        if (count > 0)
            goto copy_a;
terminate_a:
        arg1[-1] = 0;
finish_a:
        ;
    } else {
        src = fn_80131234(lbl_80347C14);
        count--;
        if (count > 0)
            goto copy_b;
        goto terminate_b;
copy_b:
        c = *src++;
        *arg1++ = c;
        if ((signed char)c == 0)
            goto finish_b;
        count--;
        if (count > 0)
            goto copy_b;
terminate_b:
        arg1[-1] = 0;
finish_b:
        ;
    }
}

long fn_8027CE4C(long arg0) {
    long value;
    value = *fn_8027C120(lbl_8055F654, arg0);
    switch (value) {
    case 0:
        return fn_8027C8B0();
    case 1:
        return fn_8027CB20();
    default:
        fn_802E317C(lbl_80347C38, arg0);
        return 1;
    }
}

