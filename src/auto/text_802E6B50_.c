// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *memcpy(void *, const void *, unsigned long);
extern int lbl_8055FFC8;
extern unsigned char lbl_804FC8B0[];
extern int lbl_8055FFC0;
extern unsigned char lbl_8055FFC4;
extern unsigned char lbl_8055FFC5;
extern void *memset(void *, int, unsigned long);
void fn_802E6B50(void) {
    memset(lbl_804FC8B0, 0, 0xC8);
    lbl_8055FFC0 = 0;
    lbl_8055FFC4 = 1;
    lbl_8055FFC5 = 0;
}
#pragma scheduling on
void fn_802E6B94(void) {}

void *fn_802E6B98(int arg0) {
    int sp8 = arg0;
    ((unsigned char *)&lbl_8055FFC8)[4] = 0;
    memcpy(&lbl_8055FFC8, &sp8, 4);
    return &lbl_8055FFC8;
}

void fn_802E6CA4(void) {}

void fn_802E712C(void) {}

