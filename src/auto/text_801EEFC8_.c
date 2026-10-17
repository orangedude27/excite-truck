// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80488678[];
void *memset(void *, int, unsigned int);
#pragma scheduling off
void fn_801EEFC8(void) {
    memset(lbl_80488678, 0, 0x120);
}
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

void fn_801EF184(void) {

}
