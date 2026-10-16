#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F064;
extern u8 lbl_8055F068[0x16C];
extern s32 stricmp(const char *, const char *);
extern void *fn_8012850C(s32, const char *, s32, s32, void *);
extern char *strcpy(char *, const char *);
extern char lbl_80340440[];
extern void fn_802CAC54(void *);
extern void fn_8012C4D8(void *);
extern void fn_80128670(void *);
extern void *lbl_8055F060;
s32 fn_80231504(void) {
    return 0;
}

void fn_80232928(void* hi) {
    lbl_8055F060 = hi;
}

u8 fn_80232B70(void *arg0) {
    return ((u8 *)arg0)[4];
}

u8 fn_80232B78(void *arg0) {
    return ((u8 *)arg0)[5];
}

void fn_802344C4(u8 arg0) {
    lbl_8055F064 = arg0;
}
