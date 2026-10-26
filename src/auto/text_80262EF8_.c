// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma push
#pragma scheduling invalid_target
extern void fn_8000D838(void *);
extern void __register_global_object(void *, void *, void *, void *, int, void *);
extern void fn_80262F8C(void);
extern unsigned int lbl_80498F00[];
extern unsigned char lbl_8033D618[];
extern unsigned char lbl_80345F70[];
extern int lbl_8055F3D8;
extern int lbl_8055F3E0;
extern float lbl_80563B90;
#pragma push
#pragma scheduling invalid_target
void fn_80262EF8(void) {
    volatile unsigned int *base = (volatile unsigned int *)lbl_80498F00;
    volatile unsigned int *obj;
    fn_8000D838(&lbl_8055F3D8);
    base[8] = (unsigned int)lbl_8033D618;
    obj = (volatile unsigned int *)((volatile unsigned char *)base + 0x20);
    *(volatile float *)((volatile unsigned char *)obj + 0x18) = lbl_80563B90;
    base[0] = 0;
    base[1] = 0x7B;
    base[2] = 0;
    base[3] = 0;
    base[4] = 0;
    lbl_8055F3E0 = 0x7F000000;
    obj[5] = 0;
    base[8] = (unsigned int)lbl_80345F70;
    __register_global_object((void *)obj, fn_80262F8C, (void *)(base + 5), lbl_80345F70, 0, (void *)base);
}
#pragma pop
