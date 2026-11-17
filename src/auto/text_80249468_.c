// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma scheduling invalid_target
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, void *, int, int, void *);
extern void fn_80249538(void);
extern unsigned char lbl_804988F0[];
extern unsigned char lbl_803438C0[];
extern int lbl_8055F250;
extern int lbl_8055F258;
#pragma scheduling invalid_target
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, void *, int, int, void *);
extern void fn_80249538(void);
extern unsigned char lbl_804988F0[];
extern unsigned char lbl_803438C0[];
extern int lbl_8055F250;
extern int lbl_8055F258;
#pragma push
#pragma scheduling on
void fn_80249468(void) {
    register unsigned char *base asm("r31") = lbl_804988F0;
    unsigned char *obj;
    fn_8000D838(&lbl_8055F250);
    obj = base + 0x68;
    *(void **)(obj + 0x24) = obj;
    *(int *)(base + 0x00) = 0;
    *(int *)(base + 0x04) = 0x7B;
    *(int *)(base + 0x08) = 0;
    *(int *)(base + 0x0C) = 0;
    *(int *)(base + 0x10) = 0;
    lbl_8055F258 = 0x7F000000;
    *(char *)(obj + 0x14) = 0;
    *(int *)(obj + 0x18) = -1;
    *(char *)(obj + 0x1C) = 0;
    *(void **)(obj + 0x20) = lbl_803438C0;
    __register_global_object(obj, fn_80249538, base + 0x58, lbl_803438C0, 0x7F000000, 0, base);
}
#pragma pop
