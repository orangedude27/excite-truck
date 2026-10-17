// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { void *p; int a; int b; } GlobalObj;
extern unsigned char lbl_8055F8C8;
extern int lbl_8055F8D0;
extern GlobalObj lbl_804BD6C4;
extern unsigned char lbl_804BD6B8;
extern void fn_8000D838(void *);
extern void fn_802A8F94(void);
extern void __register_global_object(void *, void (*)(void), void *, int);

void fn_802A8F34(void) {
    fn_8000D838(&lbl_8055F8C8);
    lbl_804BD6C4.p = (char *)&lbl_804BD6C4 + 12;
    lbl_8055F8D0 = 0xFFFF0000;
    lbl_804BD6C4.b = 10;
    lbl_804BD6C4.a = 0;
    __register_global_object(&lbl_804BD6C4, fn_802A8F94, (char *)&lbl_804BD6B8, 10);
}
#pragma scheduling on
