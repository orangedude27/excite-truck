// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned int u32;
extern void fn_8000D838(void *);
typedef struct { s32 a, b, c, d, e; } Data;
extern Data lbl_804986E0;
extern s32 lbl_8055F0F0;
extern s32 lbl_8055F0F8;
void fn_8023995C(void) {
    fn_8000D838(&lbl_8055F0F0);
    ((s32 *)&lbl_804986E0)[0] = 0;
    ((s32 *)&lbl_804986E0)[1] = 0x7B;
    ((s32 *)&lbl_804986E0)[2] = 0;
    ((s32 *)&lbl_804986E0)[3] = 0;
    ((s32 *)&lbl_804986E0)[4] = 0;
    lbl_8055F0F8 = 0x7F000000;
}
