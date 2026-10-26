// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct Obj8027AB54 {
    unsigned char unk_00[0x30];
    unsigned int unk_30;
} Obj8027AB54;

extern void fn_8000D838(void *);
extern void fn_801E952C(void *);
extern void __register_global_object(void *, void *, void *);
extern void fn_8027AA08(void);
extern unsigned char lbl_804A21E8[];
__declspec(section ".sdata") extern unsigned char lbl_8055F628[];
extern int lbl_8055F630;
#pragma push
#pragma scheduling invalid_target
void fn_8027AB54(void) {
    register volatile unsigned char *base asm("r29") = lbl_804A21E8;
    register int zero asm("r30");
    register volatile unsigned int *record asm("r6");
    register void (*dtor)(void) asm("r31");
    register volatile unsigned char *object asm("r3");
    volatile unsigned char *last;
    fn_8000D838(lbl_8055F628);
    zero = 0;
    record = (volatile unsigned int *)base;
    *(volatile unsigned int *)base = zero;
    object = base + 0x5A4;
    record[2] = zero;
    record[1] = 0x7B;
    dtor = fn_8027AA08;
    record[3] = zero;
    record[4] = zero;
    lbl_8055F630 = 0x7F000000;
    *(volatile unsigned int *)(object + 0x30) = zero;
    __register_global_object((void *)object, dtor, (void *)(base + 0x598));
    object = base + 0x5E4;
    *(volatile unsigned int *)(object + 0x30) = zero;
    __register_global_object((void *)object, dtor, (void *)(base + 0x5D8));
    last = base + 0x1CF8;
    last += 0x0C;
    fn_801E952C((void *)last);
}
#pragma pop
