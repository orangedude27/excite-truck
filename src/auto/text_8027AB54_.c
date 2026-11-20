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
    register unsigned int *base asm("r29") = (unsigned int *)lbl_804A21E8;
    register unsigned int zero asm("r30");
    register unsigned int recAddr asm("r6");
    register void (*dtor)(void) asm("r31");
    register unsigned int objAddr asm("r3");
    register unsigned int lastAddr asm("r3");
    fn_8000D838(lbl_8055F628);
    zero = 0;
    recAddr = (unsigned int)base;
    *(unsigned int *)recAddr = zero;
    objAddr = (unsigned int)base + 0x5A4;
    *(unsigned int *)(recAddr + 0x8) = zero;
    *(unsigned int *)(recAddr + 0x4) = 0x7B;
    dtor = fn_8027AA08;
    *(unsigned int *)(recAddr + 0xC) = zero;
    *(unsigned int *)(recAddr + 0x10) = zero;
    lbl_8055F630 = 0x7F000000;
    *(unsigned int *)(objAddr + 0x30) = zero;
    __register_global_object((void *)objAddr, dtor, (unsigned char *)base + 0x598);
    objAddr = (unsigned int)base + 0x5E4;
    *(unsigned int *)(objAddr + 0x30) = zero;
    __register_global_object((void *)objAddr, dtor, (unsigned char *)base + 0x5D8);
    lastAddr = (unsigned int)base + 0x1CF8;
    lastAddr += 0x0C;
    fn_801E952C((void *)lastAddr);
}
#pragma pop
