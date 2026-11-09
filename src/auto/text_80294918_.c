// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, int, int, int);
extern void fn_8029496C(void);
extern unsigned char lbl_8055F760;
extern unsigned char lbl_804B4030[];
extern unsigned char lbl_804B4168[];

#pragma scheduling invalid_target
void fn_80294918(void) {
    fn_8000D838(&lbl_8055F760);
    fn_8002F53C(lbl_804B4030, fn_8029496C, 0, 0x34, 6);
    *(s32 *)(lbl_804B4168 + 0x180) = 0;
}
