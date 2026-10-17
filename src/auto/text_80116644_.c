// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed char s8;
typedef unsigned char u8;
extern u8 lbl_8055DEBC;
extern u8 lbl_8055DEBD;
extern char lbl_8055DEB4[];
extern char lbl_8055DEB8[];
extern void fn_8010C7DC(void *);
extern void fn_8010D0E0(void *);
extern void fn_8010C7EC(void);
extern void fn_8010D0F0(void);
extern char lbl_8041D4F0[];
extern char lbl_8041D4FC[];
extern void __register_global_object(void *, void (*)(void), void *);
__declspec(section ".sdata") extern u8 lbl_8055DEBC;
__declspec(section ".sdata") extern u8 lbl_8055DEBD;
__declspec(section ".sdata") extern char lbl_8055DEB4[];
__declspec(section ".sdata") extern char lbl_8055DEB8[];
void fn_80116644(void) {
    if ((s8)lbl_8055DEBC == 0) {
        fn_8010C7DC(lbl_8055DEB4);
        __register_global_object(lbl_8055DEB4, fn_8010C7EC, lbl_8041D4F0);
        lbl_8055DEBC = 1;
    }
    if ((s8)lbl_8055DEBD == 0) {
        fn_8010D0E0(lbl_8055DEB8);
        __register_global_object(lbl_8055DEB8, fn_8010D0F0, lbl_8041D4FC);
        lbl_8055DEBD = 1;
    }
}
