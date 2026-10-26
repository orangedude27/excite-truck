// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80488678[];
void *memset(void *, int, unsigned int);
#pragma scheduling off
void fn_801EEFC8(void) {
    memset(lbl_80488678, 0, 0x120);
}
#pragma scheduling on
void fn_801EEFDC(int arg0, unsigned int arg1) {
    int i;
    unsigned int *base = (unsigned int *)(lbl_80488678 + ((arg1 & 0xFF) << 4));
    for (i = 0; i < 4; i++) {
        if (base[i] == 0) {
            base[i] = arg0;
            return;
        }
    }
}
void fn_802E317C(const char *, ...);
extern char lbl_8033A328[];
#pragma scheduling invalid_target
void fn_801EF024(unsigned int arg0) {
    unsigned int *base = (unsigned int *)lbl_80488678;
    unsigned int *p;
    int found = 0;
    int i;
    int j;

    for (i = 0; i < 18; i++, base += 4) {
        p = base;
        for (j = 0; j < 4; p++, j++) {
            if (*p == arg0) {
                *(volatile unsigned int *)((char *)lbl_80488678 + (i << 4) + (j << 2)) = 0;
                found = 1;
                goto done;
            }
        }
    }
done:
    if (!found) {
        fn_802E317C(lbl_8033A328);
    }
}
#pragma scheduling on
void fn_801EF184(void) {

}
