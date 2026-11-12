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
extern void *lbl_8055DFD4;
#pragma scheduling invalid_target
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
#pragma push
#pragma scheduling invalid_target
void fn_80129458(void) {
    lbl_80422380[0] = 1;
    *(u16 *)(lbl_80422380 + 6) = 0x58;
    *(u16 *)(lbl_80422380 + 4) = 0x54;
    lbl_80422380[2] = 0;
    *(u16 *)(lbl_80422380 + 12) = 0x1B;
    *(u16 *)(lbl_80422380 + 8) = 0x43;
    *(u16 *)(lbl_80422380 + 10) = 0x53;
    lbl_804223A0[0] = 1;
    lbl_804223A0[2] = 1;
    lbl_804223A0[1] = 0;
    *(u16 *)(lbl_804223A0 + 6) = 0xD;
    *(u16 *)(lbl_804223A0 + 12) = 0x113;
    *(u16 *)(lbl_804223A0 + 4) = 0x20;
    *(u16 *)(lbl_804223A0 + 8) = 0x6F;
    *(u16 *)(lbl_804223A0 + 10) = 0x1B;
    *(u16 *)(lbl_804223A0 + 0x1C) = 0x121;
    *(u16 *)(lbl_804223A0 + 0xE) = 0;
    *(u16 *)(lbl_804223A0 + 0x12) = 0;
    *(u16 *)(lbl_804223A0 + 0x10) = 0;
    *(u16 *)(lbl_804223A0 + 0x14) = 0;
}
#pragma pop
void fn_801294FC(s32 arg0, s32 arg1);
#pragma dont_inline fn_801294FC
void fn_801294FC(s32 arg0, s32 arg1) {
    fn_802E4800(arg0 | ((arg1 << 12) & 0xF000));
}

void fn_80129508(void *arg0, s32 arg1, void *arg2) {
    u8* inputState = (u8*)arg0;
    u8* inputSource = (u8*)arg2;
    s32 action = 0;
    s32 directionFlags;
    s32 newDirectionPress;
    f32 axisValue;

    /* From analog axes in inputSource, derive directional press flags when enabled, detect newly-pressed directions, store flags/active marker, and emit an action if a new direction was pressed. */
    if (inputSource[0] != 0) {
        directionFlags = *(s32*)(inputState + 0x5C);
        if (directionFlags == 0 && inputSource[1] != 0 && lbl_8055DFD0 != 0) {
            axisValue = *(f32*)(inputState + 0x1C);
            if (axisValue < lbl_80561248) {
                directionFlags |= 8;
            } else if (axisValue > lbl_8056124C) {
                directionFlags |= 2;
            }
            axisValue = *(f32*)(inputState + 0x20);
            if (axisValue < lbl_80561248) {
                directionFlags |= 1;
            } else if (axisValue > lbl_8056124C) {
                directionFlags |= 4;
            }
        }
        newDirectionPress = (directionFlags ^ *(s32*)(inputState + 0x18)) & directionFlags;
        switch (newDirectionPress) {
        case 1:
            action = 0x126;
            break;
        case 4:
            action = 0x128;
            break;
        case 8:
            action = 0x125;
            break;
        case 2:
            action = 0x127;
            break;
        }
        *(s32*)(inputState + 0x18) = directionFlags;
        if (directionFlags != 0) {
            inputState[8] = 1;
        }
    }
    if (action != 0) {
        ((void (*)(s32, s32))fn_801294FC)(action, arg1);
    }
}

void fn_8012960C(void *arg0) {
    u8 *p = (u8 *)arg0;
    s32 now = fn_802E2C20();
    s32 count;
    s32 old;
    s32 elapsed;
    s32 limit;

    if (p[8] != 0) {
        count = *(s32 *)(p + 4);
        limit = 0xFA;
        old = *(s32 *)p;
        elapsed = now - old;
        if (count != 0)
            limit = 0x7D;
        if (elapsed > limit) {
            *(s32 *)p = now;
            *(s32 *)(p + 0x18) = 0;
            *(s32 *)(p + 4) = *(s32 *)(p + 4) + 1;
        }
    } else {
        *(s32 *)p = now;
        *(s32 *)(p + 4) = 0;
    }
}

extern void fn_80129508(void *, s32, void *);
#pragma dont_inline fn_801294FC
void fn_80129690(void *arg0, s32 arg1, void *arg2) {
    u8 *dst = (u8 *)arg0;
    u8 *params = (u8 *)arg2;
    s32 *entries;
    s32 offset;
    s32 i;
    s32 active;
    u8 value;
    u16 type;
    active = 0;
    if (params[2] != 0 && (s32)lbl_8055DFD4 != -1 && (s32)lbl_8055DFD4 == arg1) {
        active = 1;
    }
    dst[8] = 0;
    if (active != 0) {
        fn_80129508(arg0, arg1, arg2);
    }
    entries = (s32 *)lbl_804223C0;
    i = 0;
    do {
        offset = *entries;
        if (offset >= 0 && (type = *(u16 *)(params + 4)) != 0 && active != 0) {
            value = dst[offset + 0x3C];
            if (value != 0) {
                dst[8] = 1;
                if (dst[i + 9] == 0) {
                    fn_801294FC(type, arg1);
                }
                dst[i + 9] = value;
            }
        }
        i++;
        entries++;
        params += 2;
    } while (i < 0xE);
    fn_8012960C(arg0);
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

// Copies a 0x64-byte record for the given index from the table at lbl_80422180 (stride 0x80)
// into dst when present, otherwise clears dst; returns nonzero if found.
void *fn_801298E8(void *dst, int index) {
    s32 found;
    volatile u8 *src;
    u8 *out;
    u8 a, b;
    u32 wordA, wordB;
    found = fn_802E8504(index);
    if (found) {
        src = lbl_80422180 + (index << 7);
        out = dst;
        *(f32 *)(out + 0x00) = *(f32 *)(src + 0x1C);
        *(f32 *)(out + 0x04) = *(f32 *)(src + 0x20);
        *(f32 *)(out + 0x08) = *(f32 *)(src + 0x24);
        *(f32 *)(out + 0x0C) = *(f32 *)(src + 0x28);
        *(f32 *)(out + 0x10) = *(f32 *)(src + 0x2C);
        *(f32 *)(out + 0x14) = *(f32 *)(src + 0x30);
        *(f32 *)(out + 0x18) = *(f32 *)(src + 0x34);
        *(f32 *)(out + 0x1C) = *(f32 *)(src + 0x38);
        b = src[0x3C]; a = src[0x3D]; out[0x20] = b; out[0x21] = a;
        b = src[0x3E]; a = src[0x3F]; out[0x22] = b; out[0x23] = a;
        b = src[0x40]; a = src[0x41]; out[0x24] = b; out[0x25] = a;
        b = src[0x42]; a = src[0x43]; out[0x26] = b; out[0x27] = a;
        b = src[0x44]; a = src[0x45]; out[0x28] = b; out[0x29] = a;
        b = src[0x46]; a = src[0x47]; out[0x2A] = b; out[0x2B] = a;
        b = src[0x48]; a = src[0x49]; out[0x2C] = b; out[0x2D] = a;
        b = src[0x4A]; a = src[0x4B]; out[0x2E] = b; out[0x2F] = a;
        b = src[0x4C]; a = src[0x4D]; out[0x30] = b; out[0x31] = a;
        b = src[0x4E]; a = src[0x4F]; out[0x32] = b; out[0x33] = a;
        b = src[0x50]; a = src[0x51]; out[0x34] = b; out[0x35] = a;
        b = src[0x52]; a = src[0x53]; out[0x36] = b; out[0x37] = a;
        b = src[0x54]; a = src[0x55]; out[0x38] = b; out[0x39] = a;
        b = src[0x56]; a = src[0x57]; out[0x3A] = b; out[0x3B] = a;
        b = src[0x58]; a = src[0x59]; out[0x3C] = b; out[0x3D] = a;
        b = src[0x5A]; a = src[0x5B]; out[0x3E] = b; out[0x3F] = a;
        *(u32 *)(out + 0x40) = *(u32 *)(src + 0x5C);
        wordB = *(volatile u32 *)(src + 0x60);
        wordA = *(volatile u32 *)(src + 0x64);
        *(u32 *)(out + 0x44) = wordB;
        *(u32 *)(out + 0x48) = wordA;
        wordA = *(volatile u32 *)(src + 0x68);
        wordB = *(volatile u32 *)(src + 0x6C);
        *(u32 *)(out + 0x4C) = wordA;
        *(u32 *)(out + 0x50) = wordB;
        wordA = *(volatile u32 *)(src + 0x70);
        wordB = *(volatile u32 *)(src + 0x74);
        *(u32 *)(out + 0x54) = wordA;
        *(u32 *)(out + 0x58) = wordB;
        *(u32 *)(out + 0x5C) = *(u32 *)(src + 0x78);
        out[0x60] = src[0x7C];
    } else {
        memset(dst, 0, 0x64);
    }
    return (void *)found;
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
        p += 0x80;
    } while (i < 4);
}

void fn_80129B60(void) {
    u8 *p = lbl_80422180;
    s32 i = 0;
    do {
        fn_80129690(p, i, lbl_80422380);
        i++;
        p += 0x80;
    } while (i < 4);
}

s32 fn_80129BC4(void) {
    return 1;
}
