// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055F208;
extern int lbl_8055F210;
extern int lbl_8055F214;
extern int lbl_80498848[];
struct SdaPair { int at210; int at214; };
#pragma scheduling invalid_target
void fn_802445A4(void) {
    register int *p asm("r5");
    register int zero asm("r4");
    register int ffff asm("r0");
    register int mask asm("r3");
    fn_8000D838(&lbl_8055F208);
    p = lbl_80498848;
    zero = 0;
    p[0] = zero;
    p[1] = 0x7b;
    p[2] = zero;
    p[3] = zero;
    p[4] = zero;
    ffff = 0xffff0000;
    mask = 0x7f000000;
    lbl_8055F214 = ffff;
    lbl_8055F210 = mask;
}
#pragma scheduling on
