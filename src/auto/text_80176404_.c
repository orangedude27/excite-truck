// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed int s32;
typedef unsigned int u32;
extern void fn_8000D838(void *);
extern s32 lbl_80430378[];
extern u32 lbl_8055E390;
extern volatile s32 lbl_8055E398;
extern volatile s32 lbl_8055E39C;
extern volatile s32 lbl_8055E3A0;
  
void fn_80176404(void) {
    s32 v;
    s32 *p;
    fn_8000D838(&lbl_8055E390);
    p = lbl_80430378 + 1;
    lbl_80430378[0] = 0;
    v = 0x7B;
    lbl_80430378[1] = v;
    lbl_80430378[2] = 0;
    lbl_80430378[3] = 0;
    lbl_80430378[4] = 0;
    lbl_8055E398 = 0xFFFF0000;
    lbl_8055E39C = 0xFFFF0000;
    lbl_8055E3A0 = 0x7F000000;
}
