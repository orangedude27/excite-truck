// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern void fn_8000D838(void *);
extern void fn_801491B8(void *, s32);
extern void __register_global_object(void *, void *, void *);
extern char lbl_8032D2C8[];
extern char lbl_8032D2E4[];
extern char lbl_8032D300[];
extern char lbl_8032D31C[];
extern char lbl_8032D338[];
extern s32 lbl_8042FBA0[];
extern s32 lbl_8055E1F0;
extern s32 lbl_8055E1F8;
extern s32 lbl_8055E1FC;
extern s32 lbl_8055E20C;
extern s32 lbl_8055E210;
extern s32 lbl_8055E214;
extern s32 lbl_8055E218;
extern s32 lbl_8055E220;

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_801490E0(void) {
    register s32 *base asm("r31") = (s32 *)lbl_8042FBA0;
    s32 *sub;
    s32 *p218;
    s32 *p220;
    s32 v7f = 0x7F000000;
    fn_8000D838(&lbl_8055E1F0);
    lbl_8055E20C = (s32)lbl_8032D338;
    lbl_8055E210 = (s32)lbl_8032D31C;
    sub = base + 8;
    lbl_8055E1F8 = 0xFFFF0000;
    base[0] = 0;
    base[1] = 0x7B;
    lbl_8055E214 = (s32)lbl_8032D300;
    lbl_8055E218 = (s32)lbl_8032D2E4;
    base[2] = 0;
    base[3] = 0;
    base[4] = 0;
    lbl_8055E1FC = v7f;
    p218 = (s32 *)&lbl_8055E218;
    p220 = (s32 *)&lbl_8055E220;
    lbl_8055E220 = (s32)lbl_8032D2C8;
    p218[1] = 0;
    p220[1] = 0;
    sub[0] = (s32)(sub + 3);
    sub[2] = 0x28;
    sub[1] = 0;
    __register_global_object(sub, fn_801491B8, base + 5);
}
#pragma pop
