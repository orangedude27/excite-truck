#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern int lbl_8055E348;
extern int lbl_8055E350;
extern int lbl_8042FF60[];
extern int lbl_80430260[];
extern void fn_80144DC8(void);
extern void fn_8016A0AC(void);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, int, int, int);

#pragma scheduling invalid_target
void fn_8016A040(void) {
    fn_8000D838(&lbl_8055E348);
    lbl_8055E350 = 0xFFFF0000;
    fn_8002F53C(lbl_8042FF60, fn_80144DC8, 0, 0x30, 0x10);
    fn_8002F53C(lbl_80430260, fn_8016A0AC, 0, 0x10, 8);
}
#pragma scheduling on

DECL_SECTION(".ctors") funcptr_t D_802ED1EC = fn_8016A040;
