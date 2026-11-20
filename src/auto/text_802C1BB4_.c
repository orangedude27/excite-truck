// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055FB20;
extern char lbl_804C0E10[];
extern void fn_802C1C28(void);
extern char lbl_8032CEB4[];
extern char lbl_8032DB08[];
extern char lbl_8034AF48[];
extern int lbl_8055FB40;
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
#pragma scheduling invalid_target
void fn_802C1BB4(void) {
    volatile int *p;
    int ceb4;
    register int db08 asm("r5");
    int af48;
    fn_8000D838(&lbl_8055FB20);
    fn_8002F53C(lbl_804C0E10, fn_802C1C28, 0, 0x48, 8);
    ceb4 = (int)lbl_8032CEB4;
    db08 = (int)lbl_8032DB08;
    af48 = (int)lbl_8034AF48;
    p = (volatile int *)&lbl_8055FB40;
    p[0] = ceb4;
    p[0] = af48;
    p[1] = db08;
    p[1] = af48 + 0x14;
}
#pragma scheduling on
