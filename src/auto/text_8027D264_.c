// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055C790;
int fn_8027D8F4(void *arg0) {
    return ((int *)arg0)[3];
}

int fn_8027D8FC(void *arg0) {
    return ((int *)arg0)[4];
}

int fn_8027D914(void *arg0, int arg1) {
    return ((int *)arg0)[6] + arg1 * 0x3C;
}

unsigned char fn_8027D924(void *arg0) {
    return ((unsigned char *)arg0)[0x1F0];
}

void fn_8027DE6C(void) {
    fn_8027B77C();
    fn_8027BF38();
    fn_8027B690();
    fn_8027DA08();
}

void* fn_8027DED0(void) {
    return lbl_8055C790;
}
