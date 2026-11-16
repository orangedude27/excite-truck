// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern unsigned char lbl_8055E500;
extern unsigned char lbl_80332840[];
extern float lbl_80562058, lbl_8056205C, lbl_80562060, lbl_80562064;
void fn_8018FACC(void) {
    /* Initialize state lbl_8055E500 and set four angle limits in table lbl_80332840
       (offsets 0x0C/0x4C/0x210/0x250: -40deg, +40deg, +70deg, -70deg in radians). */
    fn_8000D838(&lbl_8055E500);
    *(float *)(lbl_80332840 + 0xC) = lbl_80562058;
    *(float *)(lbl_80332840 + 0x4C) = lbl_8056205C;
    *(float *)(lbl_80332840 + 0x210) = lbl_80562060;
    *(float *)(lbl_80332840 + 0x250) = lbl_80562064;
}
