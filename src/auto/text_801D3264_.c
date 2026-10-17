// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055E928;
extern unsigned char lbl_80438898[];
extern unsigned char lbl_80438958[];
extern void fn_801D32CC(void);
extern void fn_801D32C8(void);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
void fn_801D3264(void) {
    fn_8000D838(&lbl_8055E928);
    fn_8002F53C(lbl_80438898, fn_801D32CC, 0, 0x18, 8);
    fn_8002F53C(lbl_80438958, fn_801D32C8, 0, 0x4C4, 0x20);
}
