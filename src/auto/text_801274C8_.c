// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
struct State { s32 *next; s32 size; s32 zero; };
extern struct State lbl_8041DEE0;

struct Channel {
    u8 pad0[0x10];
    u32 words[10];
    u8 pad38[9];
    u8 flag;
    u8 pad42[6];
};

struct Player {
    struct Channel channels[8];
};

struct SoundSub {
    u8 flag;
    u8 pad1[0x23];
    u32 *ptr;
    u8 pad2[4];
};

struct SoundGroup {
    struct SoundSub subs[7];
    struct SoundSub master;
};

struct SoundSystem {
    struct Player players[2];
    void (*callbacks[4])(s32);
    struct SoundGroup groups[2];
};
extern u8 lbl_8041D790[];
extern void fn_80127968(void);
extern void *memset(void*, int, unsigned long);
extern u32 lbl_8055DF1C;
extern s32 lbl_8055DF44;
extern const char lbl_80329EF4[];
extern const char lbl_80329E30[];
extern u8 lbl_8041D790[];
extern u8 lbl_8041DC10[];
extern s32 lbl_8041DF30[];
extern void fn_80127C90(void (*)(void), const char*);
extern void fn_80127D58(void (*)(void));
extern void fn_802E30C8(const char*, ...);
extern s32 fn_802E2C20(void);
extern u64 lbl_8055DF28;
extern s32 lbl_8055DF28_unused;
extern s32 lbl_8055DF2C;
extern s32 lbl_8055DF30;
extern s32 fn_801274C8(void);
extern void fn_8012766C(void);
extern u32 lbl_8055DF34;
extern u64 lbl_8055DF38;
extern s32 lbl_8055DF3C;
extern s32 lbl_8055DF40;
extern u64 lbl_8055DF18;
extern u64 lbl_8055DF20;
extern u64 fn_802E2C9C(void);

#pragma dont_inline on
s32 fn_801274C8(void) {
    s32 count = lbl_8041DEE0.zero;
    s32 *p = lbl_8041DEE0.next + count;
    s32 i = 0;
    while (i < count && p != 0) {
        p--;
        lbl_8041D790[*p * 0x48 + 0x42] = 1;
        i++;
    }
    return 0;
}
s32 fn_80127538(void) {
    memset(lbl_8041D790, 0, 0x480);
    memset(lbl_8041DC10, 0, 0x10);
    fn_80127968();
    fn_80127C90(fn_80127968, lbl_80329EF4);
    lbl_8055DF1C = 0;
    *(u32 *)&lbl_8055DF18 = 0;
    lbl_8055DF30 = 0;
    lbl_8055DF34 = 0;
    return 1;
}

#pragma scheduling invalid_target
void fn_801275AC(void) {
    const char *base = lbl_80329E30;
    s32 *entry;
    s32 i;

    fn_80127D58(fn_80127968);
    if (lbl_8055DF44 == 0)
        return;
    fn_802E30C8(base + 0xD0);
    fn_802E30C8(base + 0x108, lbl_8055DF44);
    entry = lbl_8041DF30;
    i = 0;
    while (i < lbl_8055DF44) {
        s32 start = entry[2];
        fn_802E30C8(base + 0x11C, start, entry[5] - start, entry[0], entry[1]);
        entry += 3;
        i++;
    }
    fn_802E30C8(base + 0xD0);
}

void fn_8012766C(void) {
    u8 *base = lbl_8041D790;
    u8 *r3 = base + 0;
    u8 *r5;
    s32 i;
    s32 idx;
    void (**cb)(s32);

    for (i = 0; i < 2; i++) {
        r3[0x41] = 0;
        *(u32*)(r3 + 0x34) = 0;
        *(u32*)(r3 + 0x30) = 0;
        *(u32*)(r3 + 0x2C) = 0;
        *(u32*)(r3 + 0x28) = 0;
        *(u32*)(r3 + 0x24) = 0;
        *(u32*)(r3 + 0x20) = 0;
        *(u32*)(r3 + 0x1C) = 0;
        *(u32*)(r3 + 0x18) = 0;
        *(u32*)(r3 + 0x14) = 0;
        *(u32*)(r3 + 0x10) = 0;

        r3[0x89] = 0;
        *(u32*)(r3 + 0x7C) = 0;
        *(u32*)(r3 + 0x78) = 0;
        *(u32*)(r3 + 0x74) = 0;
        *(u32*)(r3 + 0x70) = 0;
        *(u32*)(r3 + 0x6C) = 0;
        *(u32*)(r3 + 0x68) = 0;
        *(u32*)(r3 + 0x64) = 0;
        *(u32*)(r3 + 0x60) = 0;
        *(u32*)(r3 + 0x5C) = 0;
        *(u32*)(r3 + 0x58) = 0;

        r3[0xD1] = 0;
        *(u32*)(r3 + 0xC4) = 0;
        *(u32*)(r3 + 0xC0) = 0;
        *(u32*)(r3 + 0xBC) = 0;
        *(u32*)(r3 + 0xB8) = 0;
        *(u32*)(r3 + 0xB4) = 0;
        *(u32*)(r3 + 0xB0) = 0;
        *(u32*)(r3 + 0xAC) = 0;
        *(u32*)(r3 + 0xA8) = 0;
        *(u32*)(r3 + 0xA4) = 0;
        *(u32*)(r3 + 0xA0) = 0;

        r3[0x119] = 0;
        *(u32*)(r3 + 0x10C) = 0;
        *(u32*)(r3 + 0x108) = 0;
        *(u32*)(r3 + 0x104) = 0;
        *(u32*)(r3 + 0x100) = 0;
        *(u32*)(r3 + 0xFC) = 0;
        *(u32*)(r3 + 0xF8) = 0;
        *(u32*)(r3 + 0xF4) = 0;
        *(u32*)(r3 + 0xF0) = 0;
        *(u32*)(r3 + 0xEC) = 0;
        *(u32*)(r3 + 0xE8) = 0;

        r3[0x161] = 0;
        *(u32*)(r3 + 0x154) = 0;
        *(u32*)(r3 + 0x150) = 0;
        *(u32*)(r3 + 0x14C) = 0;
        *(u32*)(r3 + 0x148) = 0;
        *(u32*)(r3 + 0x144) = 0;
        *(u32*)(r3 + 0x140) = 0;
        *(u32*)(r3 + 0x13C) = 0;
        *(u32*)(r3 + 0x138) = 0;
        *(u32*)(r3 + 0x134) = 0;
        *(u32*)(r3 + 0x130) = 0;

        r3[0x1A9] = 0;
        *(u32*)(r3 + 0x19C) = 0;
        *(u32*)(r3 + 0x198) = 0;
        *(u32*)(r3 + 0x194) = 0;
        *(u32*)(r3 + 0x190) = 0;
        *(u32*)(r3 + 0x18C) = 0;
        *(u32*)(r3 + 0x188) = 0;
        *(u32*)(r3 + 0x184) = 0;
        *(u32*)(r3 + 0x180) = 0;
        *(u32*)(r3 + 0x17C) = 0;
        *(u32*)(r3 + 0x178) = 0;

        r3[0x1F1] = 0;
        *(u32*)(r3 + 0x1E4) = 0;
        *(u32*)(r3 + 0x1E0) = 0;
        *(u32*)(r3 + 0x1DC) = 0;
        *(u32*)(r3 + 0x1D8) = 0;
        *(u32*)(r3 + 0x1D4) = 0;
        *(u32*)(r3 + 0x1D0) = 0;
        *(u32*)(r3 + 0x1CC) = 0;
        *(u32*)(r3 + 0x1C8) = 0;
        *(u32*)(r3 + 0x1C4) = 0;
        *(u32*)(r3 + 0x1C0) = 0;

        r3[0x239] = 0;
        *(u32*)(r3 + 0x22C) = 0;
        *(u32*)(r3 + 0x228) = 0;
        *(u32*)(r3 + 0x224) = 0;
        *(u32*)(r3 + 0x220) = 0;
        *(u32*)(r3 + 0x21C) = 0;
        *(u32*)(r3 + 0x218) = 0;
        *(u32*)(r3 + 0x214) = 0;
        *(u32*)(r3 + 0x210) = 0;
        *(u32*)(r3 + 0x20C) = 0;
        *(u32*)(r3 + 0x208) = 0;

        r3 += 0x240;
    }

    lbl_8055DF18 = 0;
    r5 = base + 0x490;
    lbl_8055DF30 = 0;
    lbl_8055DF34 = 0;
    lbl_8055DF28 = 0;
    lbl_8055DF38 = 0;

    idx = 0;
    for (i = 0; i < 2; i++, idx += 7) {
        if (r5[0x00] != 0) {
            **(u32**)(r5 + 0x24) = 0;
        }
        if (r5[0x2C] != 0) {
            **(u32**)(r5 + 0x50) = 0;
        }
        if (r5[0x58] != 0) {
            **(u32**)(r5 + 0x7C) = 0;
        }
        if (r5[0x84] != 0) {
            **(u32**)(r5 + 0xA8) = 0;
        }
        if (r5[0xB0] != 0) {
            **(u32**)(r5 + 0xD4) = 0;
        }
        if (r5[0xDC] != 0) {
            **(u32**)(r5 + 0x100) = 0;
        }
        if (r5[0x108] != 0) {
            **(u32**)(r5 + 0x12C) = 0;
        }
        if (r5[0x134] != 0) {
            **(u32**)(r5 + 0x158) = 0;
        }
        r5 += 0x160;
    }

    lbl_8055DF40 = fn_802E2C20();

    cb = (void (**)(s32))(base + 0x480);
    for (i = 0; i < 4; i++, cb++) {
        if (*cb != NULL) {
            (*cb)(0);
        }
    }
}

#pragma scheduling on
void fn_80127930(void* alarm) {
    fn_8012766C();
    fn_801274C8();
}

void fn_80127954(void) {
    fn_802E2C20();
}

void fn_80127958(void) {

}

s32 fn_8012795C(void) {
    return 0;
}

void fn_80127964(void) {

}

void fn_80127968(void) {
    u64 now = fn_802E2C9C();
    lbl_8055DF18 += now - lbl_8055DF20;
    lbl_8055DF20 = now;
}

void fn_801279B8(void) {
    if (++lbl_8055DF34 != 0) {
        return;
    }
    fn_80127954();
}

void fn_801279D0(void) {
    lbl_8055DF30 += 1;
}
extern u32 lbl_8055DF1C;
extern s32 lbl_8055DF44;
extern void fn_80127C90(void (*)(void), const char*);
extern void fn_80127D58(void (*)(void));
extern void fn_802E30C8(const char*, ...);
extern const char lbl_80329EF4[];
extern const char lbl_80329E30[];
extern u8 lbl_8041D790[];
extern u8 lbl_8041DC10[];
extern s32 lbl_8041DF30[];

