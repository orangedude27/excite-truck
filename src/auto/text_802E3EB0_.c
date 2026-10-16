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
    unsigned char *p = lbl_804FBAA0;
    for (i = 0; i < 0x10; i++, p += 0x91) {
        if (*p == 0) {
            *p = 1;
            return p + 1;
        }
    }
    fn_802E317C(&lbl_8034D038);
    return (void *)lbl_8055FF40;
}

void fn_802E3F38(void *arg0) {
    int i;
    unsigned char *p = lbl_804FBAA0;
    for (i = 0; i < 0x10; i++, p += 0x91) {
        if (arg0 == p + 1) {
            *p = 0;
            return;
        }
    }
    fn_802E317C(&lbl_8034D054);
}
extern unsigned int lbl_8055FF38;
extern unsigned char lbl_804FBAA0[0x10 * 0x91];
extern unsigned int lbl_8034D038;
extern unsigned int lbl_8034D054;
extern unsigned int lbl_8055FF40;
extern void fn_802E317C(void *);
