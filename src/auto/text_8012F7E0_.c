// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_805599E8;
extern unsigned char lbl_80422F40;
extern signed char lbl_8032AFE0;
#pragma dont_inline on
unsigned char fn_8012F7E0(signed char arg0) {
    int i, j;
    signed char index;
    if (lbl_805599E8 != 0) {
        lbl_805599E8 = 0;
        memset(&lbl_80422F40, 0xFF, 0x100);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 16; j++) {
                index = *((signed char *)&lbl_8032AFE0 + i * 16 + j);
                *((unsigned char *)&lbl_80422F40 + index) = i * 16 + j;
            }
        }
    }
    return *((unsigned char *)&lbl_80422F40 + arg0);
}
#pragma dont_inline off
