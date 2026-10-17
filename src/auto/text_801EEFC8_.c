// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80488678[];
void *memset(void *, int, unsigned int);
#pragma scheduling off
void fn_801EEFC8(void) {
    memset(lbl_80488678, 0, 0x120);
}
#pragma scheduling off
void fn_801EEFDC(int arg0, unsigned int arg1) {
    unsigned int *base = (unsigned int *)(lbl_80488678 + ((arg1 & 0xFF) << 4));
    unsigned int *p = base;
    int i;
    for (i = 0; i < 4; i++) {
        if (*p == 0) {
            base[i] = arg0;
            return;
        }
        p++;
    }
}

void fn_802E317C(const char *, ...);
extern char lbl_8033A328[];
void fn_801EF024(unsigned int arg0) {
    unsigned int *base = (unsigned int *)lbl_80488678;
    int found = 0;
    int i;
    for (i = 0; i < 18; i++, base += 4) {
        unsigned int *p = base;
        int j;
        for (j = 0; j < 4; j++, p++) {
            if (*p == arg0) {
                p[-j] = 0;
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
