// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
extern void fn_8000D838(void *);
extern int __register_global_object(void *, void *, void *);
extern unsigned char lbl_8055E280, lbl_8042FD34[16], lbl_8042FD28[];
extern void fn_8015EBF8(void);
extern int lbl_8055E288;
#pragma scheduling invalid_target
// Global constructor for callback/list object lbl_8042FD34: initializes lbl_8055E280,
// sets sentinel lbl_8055E288, sets up inline storage {data,count,capacity}, and registers
// destructor fn_8015EBF8 via __register_global_object.
void fn_8015EB98(void) {
    fn_8000D838(&lbl_8055E280);
    lbl_8055E288 = 0x7F000000;
    *(void **)&lbl_8042FD34 = (char *)&lbl_8042FD34 + 12;
    *(int *)((char *)&lbl_8042FD34 + 8) = 8;
    *(int *)((char *)&lbl_8042FD34 + 4) = 0;
    __register_global_object(&lbl_8042FD34, &fn_8015EBF8, &lbl_8042FD28);
}
#pragma scheduling on
