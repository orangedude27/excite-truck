// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_8055EAF0;
extern unsigned char lbl_80487D00[];
extern unsigned char lbl_80487DE0[];
extern void fn_801E9C80(void);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void (*)(void), int, int, int);
extern void fn_801E952C(void *);
extern int lbl_8055EAF8;
extern float lbl_8055EAFC;
extern int lbl_8055EB00;
extern float lbl_80562E24;
#pragma scheduling invalid_target
void fn_801E9C18(void) {
    fn_8000D838(&lbl_8055EAF0);
    lbl_8055EAF8 = 0xFFFF0000;
    lbl_8055EAFC = lbl_80562E24;
    lbl_8055EB00 = 0x7F000000;
    fn_8002F53C(lbl_80487D00, fn_801E9C80, 0, 0x38, 4);
    fn_801E952C(lbl_80487DE0);
}
#pragma scheduling on
