// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055F008;
extern s32 lbl_8055F010;
extern s32 lbl_80497E28[];
void fn_8000D838(void *);
void fn_80230040(void) {
    fn_8000D838(&lbl_8055F008);
    ((u32 *)&lbl_80497E28)[0] = 0;
    ((u32 *)&lbl_80497E28)[1] = 0x7B;
    ((u32 *)&lbl_80497E28)[2] = 0;
    ((u32 *)&lbl_80497E28)[3] = 0;
    ((u32 *)&lbl_80497E28)[4] = 0;
    lbl_8055F010 = 0x7F000000;
}
