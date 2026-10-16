#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u8 lbl_8055FDE4;
extern f32 lbl_8055FDE0;
extern s32 lbl_8055FDF0;
extern s32 lbl_8055FDF4;
extern s32 lbl_8055FDF8;
extern u8 lbl_8034C3DC;
extern void fn_801282EC(s32);
extern void *fn_8012850C(s32, void *);
extern void DCInvalidateRange(void *, u32);
extern void fn_802D6C68(void);
void fn_802D657C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802D6810(void) {
    void *buffer;

    lbl_8055FDF0 = 0;
    fn_801282EC(0x20);
    buffer = fn_8012850C(0x4000, &lbl_8034C3DC);
    lbl_8055FDF4 = (s32)buffer;
    lbl_8055FDF8 = (s32)buffer;
    DCInvalidateRange(buffer, 0x4000);
    fn_802D6C68();
}

void fn_802D6B54(void* alarm) {
    fn_802D5F88(fn_802D62E4(alarm));
}

void fn_802D6C4C(f32 arg0) {
    lbl_8055FDE0 = arg0;
}

extern float lbl_804CA308[];
void fn_802D6C54(int arg0, float arg1) {
    lbl_804CA308[arg0] = arg1;
}

void fn_802D754C(u8 arg0) {
    lbl_8055FDE4 = arg0;
}

extern u8 lbl_8055FDFC;
void fn_802D7554(u8 arg0) {
    lbl_8055FDFC = arg0;
}

