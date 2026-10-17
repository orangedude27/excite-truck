// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void*);
extern void fn_8002F53C(void*, void*, int, int, int);
extern unsigned char fn_801BF210[];
extern int lbl_80436D48[4];
extern int lbl_8055E780;
extern int lbl_8055E788;
void fn_801BF1C4(void) {
    void* storage;
    fn_8000D838(&lbl_8055E780);
    storage = lbl_80436D48;
    lbl_8055E788 = 0xFFFF0000;
    fn_8002F53C(storage, fn_801BF210, 0, 0x10, 0x100);
}
