// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int fn_80131810(void);
extern int lbl_804BD8CC[3];
#pragma scheduling invalid_target
void fn_802AE2E0(void) {
    int result = fn_80131810();
    if (result) {
        int count = lbl_804BD8CC[1];
        lbl_804BD8CC[1] = count + 1;
        ((int *)lbl_804BD8CC[0])[count] = result;
    }
}

extern u8 lbl_8055F958;
extern u8 lbl_8055F959;
extern void fn_80131818(void *);
extern void fn_802AE328(void);
#pragma scheduling invalid_target
s32 fn_802AE4C8(s32 arg0) {
    s32 count;
    s32 *items;
    s32 result;
    if ((s32)lbl_8055F958 == 0)
        fn_802AE328();
    if (arg0 < 0)
        return 0;
    count = lbl_804BD8CC[1];
    if (arg0 >= count)
        return 0;
    items = (s32 *)lbl_804BD8CC[0];
    result = items[arg0];
    return result;
}
#pragma scheduling on
