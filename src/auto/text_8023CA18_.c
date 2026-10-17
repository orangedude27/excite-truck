#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
extern char lbl_803415CC[0xC0];
extern s32 lbl_8055BB68;
extern s32 lbl_803415E8;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8023CA18(void) {
    if (lbl_8055BB68 == 0) {
        fn_80214A9C(0x1F);
    }
    fn_80214A9C(1);
}

void fn_8023CA50(void) {}

s32 fn_8023CB54(void) {
    fn_801330E8(4);
    fn_8023CA54();
    return 0;
}

s32 fn_8023CB80(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

void* fn_8023D134(void* arg0, s32 arg1) {
    s32* vtable;
    s32* temp;
    if (arg0 == 0) return 0;
    temp = *(s32**)((u8*)arg0 + 0x38);
    *(s32**)arg0 = &lbl_803415E8;
    if (temp != 0) {
        vtable = *(s32**)temp;
        ((void (*)(void*, s32))vtable[2])(temp, 1);
        *(s32**)((u8*)arg0 + 0x38) = 0;
    }
    if (arg1 > 0) fn_80128668(arg0);
    return arg0;
}

void fn_8023D1C0(void) {
    lbl_8055BB68 = 0;
    fn_8023CC84(lbl_803415CC);
    lbl_8055BB68 = 2;
}

void fn_8023D1F8(void) {}

extern s32 lbl_8055BB68;
extern s32 lbl_803415E8;
