#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;

int fn_8027AA48(void); /* extern */
void fn_80214A9C(s32); /* extern */

void fn_8023C2B4(void) {
    if (fn_8027AA48() == 0) {
        fn_80214A9C(0x1F);
    }
}

s32 fn_8023C2E4(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

s32 fn_80236914(void*); /* extern */
void fn_8023C55C(void*); /* extern */
int fn_8027AA48(void); /* extern */
void fn_80214A9C(s32); /* extern */
extern char lbl_80341430[16];
extern char lbl_8034143C[16];
s32 fn_8023C3CC(void) {
    return 0;
}

void fn_8023C94C(void) {
    fn_8023C55C(lbl_80341430);
}

void fn_8023C958(void) {
    fn_8023C55C(lbl_8034143C);
}

