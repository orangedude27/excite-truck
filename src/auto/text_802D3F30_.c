#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
extern void fn_802E317C(const char *, ...);
extern s32 fn_802DAC64(void);
extern const char lbl_8034C2F8[];
extern const char lbl_8034C334[];
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
extern void GXLoadPosMtxImm(void *, u32);
extern void PSMTXRotTrig(void *, void *, f32, f32, f32);
extern f32 lbl_80565008;
extern u8 lbl_8055FD19;
extern u32 lbl_804C5650[];
void fn_802D3F30(void) {
}

void fn_802D3F34(void *arg0) {
    void *array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0xC);
    GXSetArray(0xB, *(void **)((char *)arg0 + 0x24), 2);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D3F98(void *arg0) {
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xB, *(void **)((char *)arg0 + 0x24), 4);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D3FFC(void *arg0) {
    void *array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0xC);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXSetArray(0xE, *(void **)((char *)arg0 + 0x24), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D41C8(void *arg0) {
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D422C(void *arg0) {
    GXSetArray(9, *(void **)((char *)arg0 + 0x20), 0xC);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D4280(void *arg0) {
    void * volatile array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0x10);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXSetArray(0xD, *(void **)((char *)arg0 + 0x28), 4);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D5680(void *arg0) {
    void * volatile array = *(void **)((char *)arg0 + 0x20);
    GXSetArray(9, array, 0x10);
    GXSetArray(0xA, *(void **)((char *)arg0 + 0x24), 3);
    GXCallDisplayList(*(void **)((char *)arg0 + 0x30), *(u32 *)((char *)arg0 + 0x2C));
}

void fn_802D62FC(void *arg0, s32 *arg1, s32 *arg2) {
    extern u8 lbl_804CA438[];
    extern s32 lbl_8055FDF0;
    extern s32 lbl_8055FDF4;
    extern s32 lbl_8055FDF8;
    extern void GXBeginDisplayList(void *, u32);
    extern u32 GXEndDisplayList(void);
    extern void fn_802D5DE8(u32);
    u32 id = *(u32 *)((char *)arg0 + 0xC);
    u8 key = *(u8 *)((char *)arg0 + 9);
    s32 count = lbl_8055FDF0;
    u8 *base = lbl_804CA438;
    u8 *entry;
    s32 i;
    if (count > 0) {
        for (i = 0; i < count; i++, base += 0x10) {
            if (*(u32 *)base == id && base[4] == key) {
                *arg1 = *(s32 *)(base + 8);
                *arg2 = *(s32 *)(base + 0xC);
                return;
            }
        }
    }
    count = lbl_8055FDF0;
    entry = lbl_804CA438;
    entry += count * 0x10;
    *(u32 *)entry = id;
    lbl_8055FDF0 = count + 1;
    entry[4] = key;
    GXBeginDisplayList((void *)lbl_8055FDF8, lbl_8055FDF4 + 0x4000 - lbl_8055FDF8);
    fn_802D5DE8(id);
    *(s32 *)(entry + 8) = lbl_8055FDF8;
    *(s32 *)(entry + 0xC) = GXEndDisplayList();
    lbl_8055FDF8 += *(s32 *)(entry + 0xC);
    *arg1 = *(s32 *)(entry + 8);
    *arg2 = *(s32 *)(entry + 0xC);
}

void fn_802D657C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802D6594(void *arg0) {
    u8 *bytes = arg0;
    u8 t0, t1, t2, t3;
    register u8 *p;
    s32 i;

    t0 = bytes[0x34];
    p = bytes + 0x38;
    t1 = bytes[0x37];
    i = 0;
    t2 = bytes[0x35];
    t3 = bytes[0x36];
    bytes[0x34] = t1;
    bytes[0x37] = t0;
    bytes[0x35] = t3;
    bytes[0x36] = t2;

    while (i < *(s32 *)(bytes + 0x34)) {
        t0 = p[0];
        p[0] = p[3];
        p[3] = t0;
        t0 = p[1];
        p[1] = p[2];
        p[2] = t0;
        p += 4;
        i += 1;
    }
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

extern void fn_802D65F8(s32, s32);
extern void fn_802E317C(const char *, ...);
extern const char lbl_8034C440[];
void fn_802D6B80(u8 *arg0, s32 arg1, s32 arg2) {
    u8 a = arg0[0];
    u8 b = arg0[3];
    u8 c = arg0[1];
    u8 d = arg0[2];
    arg0[0] = b;
    arg0[3] = a;
    arg0[1] = d;
    arg0[2] = c;
    if (fn_802D62E4(arg0, c, arg2) != 0) {
        fn_802D65F8(arg1, arg2);
    } else {
        s32 sp8 = *(s32 *)arg0;
        u8 *p = (u8 *)&sp8;
        u8 x = p[0];
        p[0] = p[3];
        p[3] = x;
        x = p[1];
        p[1] = p[2];
        p[2] = x;
        p[4] = 0;
        fn_802E317C(lbl_8034C440, arg2, &sp8);
    }
}

void fn_802D6C44(void) {
}

void fn_802D6C48(void) {
}

void fn_802D6C4C(f32 arg0) {
    lbl_8055FDE0 = arg0;
}

extern float lbl_804CA308[];
void fn_802D6C54(int arg0, float arg1) {
    lbl_804CA308[arg0] = arg1;
}

void fn_802D6C68(void) {
    lbl_8055FDE8 = 0;
    lbl_8055FDEC = 0;
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
extern void fn_802E30C8(const char *, ...);
extern void fn_80128670(s32);
