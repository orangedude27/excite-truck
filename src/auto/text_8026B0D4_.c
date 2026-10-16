// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, int, int, int);
extern unsigned char lbl_8055F4B0[1];
extern char lbl_80499E60[];
extern void fn_8026B118(void);
void fn_8026B0D4(void) {
    fn_8000D838(lbl_8055F4B0);
    fn_8002F53C(lbl_80499E60, (void *)fn_8026B118, 0, 0x6C, 4);
}
