// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern void *lbl_8055EFB0;
extern s32 lbl_8055EFB8;
extern s32 lbl_80490920[];
void fn_8000D838(void *);
void fn_8022A594(void) {
    fn_8000D838(&lbl_8055EFB0);
    *(int *)&lbl_80490920 = 0;
    *((int *)&lbl_80490920 + 1) = 0x7b;
    *((int *)&lbl_80490920 + 2) = 0;
    *((int *)&lbl_80490920 + 3) = 0;
    *((int *)&lbl_80490920 + 4) = 0;
    lbl_8055EFB8 = 0x7f000000;
}
