// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055F878;
extern unsigned char lbl_804BCFB8[];
extern void fn_802A7BD8(void);
extern void fn_8000D838(void *);
extern double fn_8002F208(double);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern float lbl_8055F880, lbl_8055F884;
extern double lbl_805648E0, lbl_805648E8;
void fn_802A7B74(void) {
    fn_8000D838(&lbl_8055F878);
    lbl_8055F880 = (float) fn_8002F208(lbl_805648E0);
    lbl_8055F884 = (float) fn_8002F208(lbl_805648E8);
    fn_8002F53C(lbl_804BCFB8, fn_802A7BD8, 0, 0xC4, 8);
}
