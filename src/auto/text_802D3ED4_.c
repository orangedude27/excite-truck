// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed short s16;
typedef unsigned int u32;
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, u32, u32, u32);
extern s16 lbl_8055FD08, lbl_8055FD0A, lbl_8055FD0C;
extern unsigned char lbl_8055FD00;
extern unsigned char lbl_804CA088;
extern void fn_802D3F30(void);
#pragma scheduling off
void fn_802D3ED4(void) {
    fn_8000D838(&lbl_8055FD00);
    lbl_8055FD08 = 0x100;
    lbl_8055FD0A = 0x405;
    lbl_8055FD0C = 0x401;
    fn_8002F53C(&lbl_804CA088, &fn_802D3F30, 0, 0x14, 7);
}
#pragma scheduling on
