#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern s32 lbl_8055FD1C;
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
extern void GXSetArray(u32, void *, u32);
void fn_802D3F30(void) {
}

void fn_802D657C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802D6594(void *arg0) {
    u8 *bytes = (u8 *)arg0;
    u8 *cursor = bytes + 0x38;
    u8 temp0 = bytes[0x34];
    u8 temp1 = bytes[0x37];
    s32 i = 0;

    bytes[0x34] = temp1;
    bytes[0x37] = temp0;
    temp0 = bytes[0x35];
    temp1 = bytes[0x36];
    bytes[0x35] = temp1;
    bytes[0x36] = temp0;

    do {
        temp0 = cursor[0];
        cursor[0] = cursor[3];
        cursor[3] = temp0;
        temp0 = cursor[1];
        cursor[1] = cursor[2];
        cursor[2] = temp0;
        cursor += 4;
        i++;
    } while (i < *(s32 *)(bytes + 0x34));
}

#pragma push
#pragma small_data off
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

extern void fn_802D0E48(s32);
extern void fn_802D5FE4(void *);
extern void GXCallDisplayList(void *, u32);
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);
void fn_802D6860(void) {
    fn_802E30C8(lbl_8034C3F4, lbl_8055FDF8 - lbl_8055FDF4, lbl_8055FDF0);
    fn_80128670(lbl_8055FDF4);
    lbl_8055FDF4 = 0;
    lbl_8055FDF8 = 0;
    fn_802E30C8(lbl_8034C428, lbl_8055FE00);
}

void fn_802D6B08(void *arg0) {
    fn_802D61BC();
    if (lbl_8055FD1C & 8) {
        fn_802D6170(arg0);
        return;
    }
    fn_802D5FE4(arg0);
}

#pragma pop
void fn_802D6B54(void* alarm) {
    fn_802D5F88(fn_802D62E4(alarm));
}


extern s32 lbl_8055FD1C;
void fn_802D6B78(void *arg0) {
    fn_802D5FE4(arg0);
}

void fn_802D6B7C(void *arg0) {
    fn_802D6170(arg0);
}

void fn_802D6C44(void) {
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
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern u32 lbl_8055FDE8;
extern u8 lbl_8055FDEC;
extern s32 lbl_8055FE00;
extern const char lbl_8034C3F4[];
extern const char lbl_8034C428[];
extern void fn_802D5FE4(void *);
extern void GXCallDisplayList(void *, u32);
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);
