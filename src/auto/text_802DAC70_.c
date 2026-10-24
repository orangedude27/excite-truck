// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern unsigned char lbl_8055FE50;
extern float lbl_804DAC48[];
extern float lbl_804DB068[];
extern void fn_80144DC8(void);
extern void fn_8001BA68(void);

#pragma scheduling invalid_target
void fn_802DAC70(void) {
    fn_8000D838(&lbl_8055FE50);
    fn_8002F53C(lbl_804DAC48, fn_80144DC8, 0, 0x30, 0x16);
    fn_8002F53C(lbl_804DB068, fn_8001BA68, 0, 0xC, 0x51);
}
#pragma scheduling on
