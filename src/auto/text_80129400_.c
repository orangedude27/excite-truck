// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

extern u8 lbl_80422180[0x200];
extern u8 lbl_804223A0[0x20];
void fn_80129690(void *arg0, s32 arg1, void *arg2);
s32 fn_802E8504(s32);

void *fn_801298E8(void *arg0, int arg1);
extern u8 lbl_804223C0[];
extern u8 lbl_8032A5B0[];
extern u8 lbl_8055DFD0;
extern f32 lbl_80561248;
extern f32 lbl_8056124C;
extern void fn_80129400(void);
void fn_802E7C64(void);
void fn_80127C90(void *, void *);
void fn_80129458(void);
void fn_802E830C(void *);
void fn_80127D58(void *);
void fn_802E7D0C(void);

extern u8 lbl_80422380[0x20];
void fn_80129400(void) {
    u8 *p;
    s32 i;
    fn_802E7FD0();
    p = lbl_80422180;
    i = 0;
    do {
        fn_802E8364(p + 0x1C, i);
        i += 1;
        p += 0x80;
    } while (i < 4);
}

void fn_80129458(void) {
    u8 *a = lbl_80422380;
    u8 *b = lbl_804223A0;
    a[0]=1; *(u16 *)(a+6)=0x58; *(u16 *)(a+4)=0x54; a[2]=0;
    *(u16 *)(a+12)=0x1B; *(u16 *)(a+8)=0x43; *(u16 *)(a+10)=0x53;
    b[0]=1; b[2]=1; b[1]=0; *(u16 *)(b+6)=0xD; *(u16 *)(b+12)=0x113;
    *(u16 *)(b+4)=0x20; *(u16 *)(b+8)=0x6F; *(u16 *)(b+10)=0x1B;
    *(u16 *)(b+0x1C)=0x121; *(u16 *)(b+0xE)=0; *(u16 *)(b+0x12)=0;
    *(u16 *)(b+0x10)=0; *(u16 *)(b+0x14)=0;
}

void fn_801294FC(s32 arg0, s32 arg1) {
    fn_802E4800(arg0 | ((arg1 << 12) & 0xF000));
}

void fn_8012960C(void *arg0) {
    s32 now = fn_802E2C20();
    u8 *p = (u8 *)arg0;
    s32 count;
    s32 old;
    s32 limit = 0xFA;
    if (p[8] == 0) {
        *(s32 *)p = now;
        *(s32 *)(p+4) = 0;
        return;
    }
    count = *(s32 *)(p+4);
    old = *(s32 *)p;
    if (count != 0) limit = 0x7D;
    if (now - old > limit) {
        *(s32 *)p = now;
        *(s32 *)(p+0x18) = 0;
        *(s32 *)(p+4) = count + 1;
    }
}

void fn_80129790(void) {
    fn_802E7C64();
    fn_80127C90(fn_80129400, lbl_8032A5B0);
    fn_80129458();
    lbl_8055DFD0 = 1;
    memset(lbl_804223C0, -1, 0x38);
    fn_802E830C(lbl_804223C0);
}

void *__AXFXGetLfoSinTable_801297F4(void) { return lbl_804223C0; }

u8 fn_80129800(void *arg0, int arg1) {
    u8 buffer[0x70];
    s32 offset;
    if (fn_801298E8(buffer, (int)arg0) != 0) {
        offset = ((s32 *)lbl_804223C0)[arg1];
        if (offset >= 0) return buffer[offset + 0x20];
    }
    return 0;
}

void fn_80129864(void) {
    fn_80127D58(fn_80129400);
    fn_802E7D0C();
}

s32 fn_80129890(void) {
    s32 count = 0;
    s32 i = 0;
    do {
        if (fn_802E8504(i) != 0) {
            count++;
        }
        i++;
    } while (i < 4);
    return count;
}

void *fn_80129AE8(void *arg0, int arg1) {
    return fn_801298E8(arg0, arg1);
}

extern void *lbl_8055DFD4;
void* fn_80129AF4(void) {
    return lbl_8055DFD4;
}
void fn_80129AEC(void *arg0) {
    lbl_8055DFD4 = arg0;
}

void fn_80129AFC(void) {
    u8 *p = lbl_80422180;
    s32 i = 0;
    do {
        fn_80129690(p, i, lbl_804223A0);
        i++;
    } while (i < 4);
    p += 0x80 * i;
}

s32 fn_80129BC4(void) {
    return 1;
}

