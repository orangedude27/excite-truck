// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
struct State { s32 *next; s32 size; s32 zero; };
extern struct State lbl_8041DEE0;
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
extern void fn_801274C8(void);
extern void fn_8012766C(void);
extern u32 lbl_8055DF34;
extern u64 lbl_8055DF38;
extern s32 lbl_8055DF3C;
extern s32 lbl_8055DF40;
extern u64 lbl_8055DF18;
extern u64 lbl_8055DF20;
extern u64 fn_802E2C9C(void);

s32 fn_80127538(void) {
    memset(lbl_8041D790, 0, 0x480);
    memset(lbl_8041DC10, 0, 0x10);
    fn_80127968();
    fn_80127C90(fn_80127968, lbl_80329EF4);
    lbl_8055DF18 = 0;
    lbl_8055DF1C = 0;
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
    u8 *r31 = lbl_8041D790;
    u8 *r3 = r31;
    u8 *r5;
    s32 i, j;
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

    lbl_8055DF1C = 0;
    r5 = r31 + 0x490;
    lbl_8055DF18 = 0;
    lbl_8055DF30 = 0;
    lbl_8055DF34 = 0;
    lbl_8055DF2C = 0;
    lbl_8055DF28 = 0;
    lbl_8055DF3C = 0;
    lbl_8055DF38 = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            u8 *e = r5 + j * 0x2C;
            if (e[0] != 0) {
                **(u32**)(e + 0x24) = 0;
            }
        }
        r5 += 0x160;
    }

    lbl_8055DF40 = fn_802E2C20();

    cb = (void (**)(s32))(r31 + 0x480);
    for (i = 0; i < 4; i++) {
        if (cb[i] != NULL) {
            cb[i](0);
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

