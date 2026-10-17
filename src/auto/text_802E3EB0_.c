// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055FF38;
extern unsigned char lbl_804FBAA0[0x10 * 0x91];
extern unsigned int lbl_8034D038;
extern unsigned int lbl_8034D054;
extern unsigned int lbl_8055FF40;
extern void fn_802E317C(void *);
unsigned int *fn_802E3EB0(void) { return &lbl_8055FF38; }

void fn_802E3EB8(void) {}

void *fn_802E3EBC(void) {
    int i;
    for (i = 0; i < 0x10; i++) {
        if (lbl_804FBAA0[i * 0x91] == 0) {
            lbl_804FBAA0[i * 0x91] = 1;
            return &lbl_804FBAA0[i * 0x91 + 1];
        }
    }
    fn_802E317C(&lbl_8034D038);
    return (void *)lbl_8055FF40;
}

void fn_802E3F38(void *arg0) {
    unsigned char *base = lbl_804FBAA0;
    int i;
    for (i = 0; i < 0x10; i++) {
        if (arg0 == base + i * 0x91 + 1) {
            base[i * 0x91] = 0;
            return;
        }
    }
    fn_802E317C(&lbl_8034D054);
}

int fn_802E4030(int arg0, int arg1) {
    void (*reset)(void);
    if (arg0 != 0 && arg1 > 0) {
        reset = fn_802E3EB8;
        reset();
    }
    return arg0;
}

extern unsigned int lbl_8055D1B0;
extern unsigned int lbl_8034D074;
extern unsigned int lbl_8034D098;
extern void DVDInit(void);
extern void OSReport(const char *);
extern unsigned int lbl_8034D098;
extern void DVDInit(void);
extern void OSReport(const char *);
extern int DVDClose(void *);
extern void fn_802E30C8(const char *, void *);
extern void fn_802E3F38(void *);
extern unsigned int lbl_8034D0E4;
extern unsigned int lbl_8034D130;
void *fn_802E41C4(void *arg0, int arg1) {
    void (*release)(void *);
    if (arg0 != 0) {
        if (*((unsigned char *)arg0 + 0x80) != 0) *(void **)arg0 = &lbl_8034D130;
        else *(void **)arg0 = &lbl_8034D130;
        if (*((unsigned char *)arg0 + 0x80) != 0 && DVDClose((char *)arg0 + 4) == 0) {
            fn_802E30C8((const char *)&lbl_8034D0E4, (char *)arg0 + 0x40);
        }
        if (arg1 > 0) {
            release = fn_802E3F38;
            release(arg0);
        }
    }
    return arg0;
}

int fn_802E43D8(void *arg0, int arg1) {
    if (arg1 >= 0 && arg1 <= *(int *)((char *)arg0 + 0x84)) {
        *(int *)((char *)arg0 + 0x88) = arg1;
        return 1;
    }
    return 0;
}

int fn_802E4400(void *arg0) {
    return *(int *)((char *)arg0 + 0x84);
}

void fn_802E4408(int unused, void *arg0) {
    if (arg0 != 0) {
        ((void (*)(void *, int))(*(void ***)arg0)[12])(arg0, 1);
    }
}
