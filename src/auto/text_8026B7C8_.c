// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int, void *);
extern void fn_8026B840(void);
extern unsigned char lbl_8049A010[];
extern unsigned char lbl_8049A028[];
extern unsigned char lbl_8055F4B8;
extern volatile int lbl_8055F4C0;
extern int lbl_8055F4C4;
#pragma scheduling invalid_target
void fn_8026B7C8(void) {
    int tmp;
    fn_8000D838(&lbl_8055F4B8);
    tmp = 0xFFFF0000;
    lbl_8055F4C0 = tmp;
    *(int *)(lbl_8049A010 + 0) = (tmp >> 16) + 1;
    *(int *)(lbl_8049A010 + 4) = 0x7B;
    *(int *)(lbl_8049A010 + 8) = 0;
    *(int *)(lbl_8049A010 + 0xC) = 0;
    *(int *)(lbl_8049A010 + 0x10) = 0;
    tmp = 0x7F000000;
    lbl_8055F4C4 = tmp;
    fn_8002F53C(&lbl_8049A028, fn_8026B840, 0, 0xC, 0x10, &lbl_8049A010);
}
#pragma scheduling on
