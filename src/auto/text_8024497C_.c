#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"

extern char lbl_80342ED8[];
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

s32 fn_8024497C(void* arg0) {
    fn_80236900(arg0);
    return 1;
}

void fn_8013C804(void);
void fn_8013C8B8(void);
s32 fn_802E2C20(void);
void fn_802C519C(s32);
void fn_80128668(void *);
extern char lbl_80342ED8[];
void fn_80244C50(void) { fn_8013C804(); }

void fn_80244C54(void) { fn_8013C8B8(); }

s32 fn_80244C58(void *arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r3;
    switch (arg1) {
    case 0x126:
        *(s32 *)((char *)arg0 + 0xA8) = fn_802E2C20();
        *(s32 *)((char *)arg0 + 0x1C) = *(s32 *)((char *)arg0 + 0x1C) - 1;
        goto update;
    case 0x128:
        *(s32 *)((char *)arg0 + 0xAC) = fn_802E2C20();
        *(s32 *)((char *)arg0 + 0x1C) = *(s32 *)((char *)arg0 + 0x1C) + 1;
    update:
        temp_r4 = *(s32 *)((char *)arg0 + 0x1C);
        var_r3 = *(s32 *)((char *)arg0 + 0x18) - 3;
        temp_r0 = temp_r4 & ((-temp_r4 & ~temp_r4) >> 31);
        if (temp_r0 < var_r3) var_r3 = temp_r0;
        *(s32 *)((char *)arg0 + 0x1C) = var_r3;
        return 1;
    default:
        return 0;
    }
}

void fn_80244D0C(void *arg0) {
    s32 temp_r3;
    s32 limit;
    temp_r3 = fn_802E2C20();
    limit = *(s32 *)((char *)arg0 + 0xA8) + 0xFA;
    *(volatile s32 *)((char *)arg0 + 0xA0) = temp_r3 <= limit;
    limit = *(s32 *)((char *)arg0 + 0xAC) + 0xFA;
    *(volatile s32 *)((char *)arg0 + 0xA4) = temp_r3 <= limit;
}

