// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).


extern void fn_8000D838(void *);
extern void fn_80287668(void);
extern void fn_80287610(void);
extern void fn_802875B8(void);
extern void __register_global_object(void *, void *, void *, ...);
extern unsigned int lbl_804B2FF8[];
extern int lbl_8055F678;
extern float lbl_80564200;
extern unsigned char lbl_8033D618[];
extern unsigned char lbl_803489C0[];
extern int lbl_8055F670;
#pragma scheduling on
void fn_802874C8(void) {
    register volatile unsigned char *base = (volatile unsigned char *)lbl_804B2FF8;
    register volatile unsigned int *obj;
    register volatile float *fobj;
    volatile unsigned int *root;

    fn_8000D838(&lbl_8055F670);
    *(volatile unsigned int *)(base + 0x20) = (unsigned int)lbl_8033D618;
    obj = (volatile unsigned int *)(base + 0x20);
    fobj = (volatile float *)(base + 0x38);
    *fobj = lbl_80564200;
    root = (volatile unsigned int *)&lbl_804B2FF8[0];
    *(volatile int *)base = 0;
    root[1] = 0x7b;
    root[2] = 0;
    root[3] = 0;
    root[4] = 0;
    *(volatile int *)&lbl_8055F678 = 0x7f000000;
    obj[5] = 0;
    obj[0] = (unsigned int)lbl_803489C0;
    ((void (*)(void *, void *, void *, void *, void *))__register_global_object)(
        (void *)obj, fn_80287668, (void *)(base + 0x14), lbl_803489C0, (void *)base);

    obj = (volatile unsigned int *)(base + 0x50);
    obj[1] = 0;
    obj[0] = (unsigned int)(obj + 3);
    obj[2] = 5;
    ((void (*)(void *, void *, void *))__register_global_object)(
        (void *)obj, fn_80287610, (void *)(base + 0x40));

    obj = (volatile unsigned int *)(base + 0xe0);
    obj[2] = 5;
    obj[0] = (unsigned int)(obj + 3);
    obj[1] = 0;
    ((void (*)(void *, void *, void *))__register_global_object)(
        (void *)obj, fn_802875B8, (void *)(base + 0xd4));
}
