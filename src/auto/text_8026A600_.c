// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_80499E60[];
extern float PSVECDotProduct(void *, void *, void *);
extern void fn_80265DD8(void *);
extern void fn_80266120(void *);
void *fn_8026A600(void *arg0) {
    fn_80265DD8((char *)arg0 + 0x160);
    fn_80266120((char *)arg0 + 0x178);
    return arg0;
}

unsigned char fn_8026B0C0(int arg0) {
    extern unsigned char lbl_80499E60[];
    return lbl_80499E60[arg0 * 0x6C];
}

