// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FE5C;
extern float lbl_80565038;
extern float lbl_8056503C;
extern int fn_802DA704(int, void *, int);
extern void fn_802DAA18(void);
void fn_802DAC54(void) {
    *((unsigned char *)lbl_8055FE5C + 0x25) = 1;
}

unsigned char fn_802DAC64(void) {
    return *((unsigned char *)lbl_8055FE5C + 0x24);
}
