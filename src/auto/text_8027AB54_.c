// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_801E952C(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_8027AA08(void);
extern unsigned char lbl_804A21E8[];
__declspec(section ".sdata") extern unsigned char lbl_8055F628[];
extern int lbl_8055F630;
void fn_8027AB54(void) {
    unsigned char *base = lbl_804A21E8;
    fn_8000D838(lbl_8055F628);
    *(int *)(base + 0) = 0;
    *(int *)(base + 8) = 0;
    *(int *)(base + 4) = 0x7b;
    *(int *)(base + 0xc) = 0;
    *(int *)(base + 0x10) = 0;
    lbl_8055F630 = 0x7f000000;
    *(int *)(base + 0x5a4 + 0x30) = 0;
    __register_global_object(base + 0x5a4, fn_8027AA08, base + 0x598);
    *(int *)(base + 0x5e4 + 0x30) = 0;
    __register_global_object(base + 0x5e4, fn_8027AA08, base + 0x5d8);
    fn_801E952C(base + 0x1cf8 + 0xc);
}
