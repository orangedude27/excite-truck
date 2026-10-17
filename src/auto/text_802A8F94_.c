#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern s32 lbl_804BD740;
extern s32 lbl_804BD790;
extern f32 lbl_80564978;
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055F8F1;
extern void fn_80128668(void*);
void* fn_802A8F94(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

s32 fn_802A9048(void) {
    u32 value;
    s32 result;
    value = *((u32 *)fn_801E87A8() + 1);
    result = 0;
    if (value & 0x100) {
        value -= 0x180000;
        if (value != 0x303U && value != 0x304U)
            result = 1;
    }
    return result;
}

void fn_802A93A4(void) {
    s32 *p;
    u32 i;
    if (lbl_8055F8F0 != 0) {
        p = (s32 *)&lbl_804BD740;
        i = 0;
        do {
            s32 value = p[1];
            if (value != -1) {
                fn_802C6CF8();
                p[1] = -1;
            }
            i++;
            p += 2;
        } while (i < 4);
        fn_802CAC54(lbl_8055CC58);
        lbl_8055CC58 = -2;
    }
}

void fn_802A9574(void) {
    s32 *p = (s32 *)&lbl_804BD790;
    f32 f = lbl_80564978;
    p[2] = -1;
    p[1] = -1;
    p[0] = -1;
    *(f32 *)(p + 3) = f;
    p[6] = -1;
    p[5] = -1;
    p[4] = -1;
    *(f32 *)(p + 7) = f;
}

void fn_802A95A8(void) {
    fn_802A9090();
}

void fn_802A95AC(u8 arg0) {
    lbl_8055F8F1 = arg0;
}
extern u8 lbl_8055F8F0;
extern s32 lbl_8055CC58;
extern s32 lbl_804BD740;
extern s32 lbl_804BD790;
extern f32 lbl_80564978;
extern f32 fn_801EA0E8(f32, f32);
