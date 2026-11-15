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
/* Initializes subsystem state: links lbl_8055FE50 into the list managed by
 * fn_8000D838, then constructs the fixed-size element arrays at lbl_804DAC48
 * (0x30-byte elements, 0x16 entries) and lbl_804DB068 (0xC-byte elements,
 * 0x51 entries) using fn_8002F53C with their respective callbacks. */
void fn_802DAC70(void) {
    fn_8000D838(&lbl_8055FE50);
    fn_8002F53C(lbl_804DAC48, fn_80144DC8, 0, 0x30, 0x16);
    fn_8002F53C(lbl_804DB068, fn_8001BA68, 0, 0xC, 0x51);
}
#pragma scheduling on
