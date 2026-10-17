// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
extern void fn_8000D838(void *);
extern int __register_global_object(void *, void *, void *, int);
extern unsigned char lbl_8055E280, lbl_8042FD34[16], lbl_8042FD28[];
extern void fn_8015EBF8(void);
extern int lbl_8055E288;
void fn_8015EB98(void) {
    fn_8000D838(&lbl_8055E280);
    *(void **)&lbl_8042FD34 = (void *)((char *)&lbl_8042FD34 + 0xC);
    lbl_8055E288 = 0x7F000000;
    *(u32 *)((char *)&lbl_8042FD34 + 8) = 8;
    *(u32 *)((char *)&lbl_8042FD34 + 4) = 0;
    __register_global_object(&lbl_8042FD34, &fn_8015EBF8, &lbl_8042FD28, 8);
}
