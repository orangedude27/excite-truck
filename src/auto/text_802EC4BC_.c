// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"
#include "revolution/OS/OSFastCast.h"

extern char lbl_805600E8;
extern u8 lbl_805600E9;
extern s8 lbl_805600EA;
extern u8 lbl_805600EB;
extern u8 lbl_805600ED;
s32 fn_8002173C(void);
void fn_802CFCA0(void);
void fn_802D02F8(s32, s32);
void fn_802D68C4(s32, s32, s32, s32);
void fn_802CFDE0(void);
void fn_802CFF10(void);
void fn_80127464(void);
  extern s32 fn_802E9A0C(void);
  extern char lbl_80558860[];
  extern char lbl_8034E9E0[];
  extern void *jumptable_8034EA80[];
  void fn_801345D8(void *, s32, void *, s32);
  s32 fn_802E36D8(void *);
  void fn_802E317C(void *, void *);
  s32 fn_802E37C4(s32);
  void fn_801282EC(s32);
  s32 fn_8012850C(s32, void *);
  void fn_802E3804(s32, s32, s32);
  void fn_802E3734(s32 *);
  s32 fn_802EC4BC(void) {
      return fn_802E9A0C() == 1;
  }
  
#pragma scheduling invalid_target
#pragma dont_inline on
s32 fn_802EC4E8(s32 arg0) {
    char sp10[0x40];
    char *base = lbl_8034E9E0;
    s32 sp8;
    s32 temp_r30;
    s32 temp_r31;
    ((void (*)(void *, s32, ...))fn_801345D8)(sp10, 0x40, base, arg0);
    sp8 = fn_802E36D8(sp10);
    if (sp8 == -1)
        ((void (*)(void *, ...))fn_802E317C)(base + 0x10, sp10);
    temp_r30 = fn_802E37C4(sp8);
    fn_801282EC(0x20);
    temp_r31 = fn_8012850C(temp_r30, base + 0x28);
    fn_802E3804(sp8, temp_r31, temp_r30);
    fn_802E3734(&sp8);
    return temp_r31;
}
#pragma dont_inline off
extern s32 lbl_80558898[];
extern s32 lbl_805600E0, lbl_805600E4;
extern u8 lbl_805600EC;
extern u8 lbl_8055D2F0;
extern f32 lbl_805651E0, lbl_805651E4, lbl_805651E8, lbl_805651EC;
extern u8 SCGetLanguage(void);
extern void fn_801282F4(void);
extern void fn_800C64F4(void *);
extern void *memset(void *, int, unsigned int);
#pragma scheduling on
  extern char lbl_80558860[];
  extern char lbl_8034E9E0[];
  extern void *jumptable_8034EA80[];
extern void fn_801345D8(void *, s32, void *, s32);
extern s32 fn_802E36D8(void *);
extern void fn_802E317C(void *, void *);
extern s32 fn_802E37C4(s32);
extern void fn_801282EC(s32);
extern s32 fn_8012850C(s32, void *);
extern void fn_802E3804(s32, s32, s32);
extern void fn_802E3734(s32 *);
#pragma scheduling invalid_target
#pragma dont_inline on
void *fn_802EC598(void) {
    s32 index = *(s32 *)(lbl_80558860 + 0x1c);
    char *base = lbl_8034E9E0;
    switch (index) {
    default:
        *(s32 *)(lbl_80558860 + 0x1c) = 0;
    case 0: return base + 0x34;
    case 1: return base + 0x40;
    case 2: return base + 0x50;
    case 3: return base + 0x60;
    case 4: return base + 0x70;
    case 5: return base + 0x80;
    case 6: return base + 0x90;
    }
}
#pragma dont_inline off

#pragma scheduling invalid_target
void fn_802EC614(void) {
    // Fix note: initialize the controller flags and configuration, then allocate and register the menu resources in target order.
    char *info;
    register s32 zero = 0;
    register char *base = lbl_8034E9E0;
    s32 *config;
    void *buffer;

    lbl_805600E9 = zero;
    lbl_805600EA = zero;
    OSInitFastCast();

    config = (s32 *)((char *)lbl_80558898 + (base - base));
    config[3] = zero;
    ((f32 *)config)[1] = lbl_805651E0;
    ((f32 *)config)[2] = lbl_805651E0;
    ((f32 *)config)[5] = lbl_805651E0;
    ((f32 *)config)[6] = lbl_805651E0;
    config[7] = zero;
    ((f32 *)config)[9] = lbl_805651E0;
    ((f32 *)config)[10] = lbl_805651E0;
    config[11] = zero;
    ((f32 *)config)[13] = lbl_805651E0;
    ((f32 *)config)[14] = lbl_805651E0;
    config[15] = zero;
    fn_801282EC((s32)((base + 0x20) - base));

    info = lbl_80558860;
    buffer = (void *)fn_8012850C(0x80000, (void *)&lbl_8055D2F0);
    *(void **)(info + 0x10) = buffer;
    memset(buffer, 0, 0x80000);
    *(s32 *)(info + 0x24) = 0x80000;
    *(s32 *)(info + 0x1C) = SCGetLanguage();
    *(s32 *)(info + 0x00) = fn_802EC4E8((s32)fn_802EC598());
    *(s32 *)(info + 0x04) = fn_802EC4E8((s32)(base + 0x100));
    *(s32 *)(info + 0x08) = fn_802EC4E8((s32)(base + 0x110));
    *(s32 *)(info + 0x0C) = fn_802EC4E8((s32)(base + 0x11C));
    *(s32 *)(info + 0x14) = zero;
    *(s32 *)(info + 0x18) = zero;
    *(s32 *)(info + 0x20) = zero;
    ((f32 *)info)[0x2C / 4] = lbl_805651E4;
    ((f32 *)info)[0x30 / 4] = lbl_805651E8;
    ((f32 *)info)[0x28 / 4] = lbl_805651EC;
    fn_801282EC(0x20);
    fn_801282F4();

    buffer = (void *)fn_8012850C(0x19000, base + 0x128);
    lbl_805600E0 = (s32)buffer;
    memset(buffer, zero, 0x19000);
    lbl_805600E4 = fn_802EC4E8((s32)(base + 0x134));
    fn_800C64F4(info);
    lbl_805600EC = 1;
}
#pragma scheduling on
extern void fn_800C657C(void);
extern void fn_80128670(s32);
extern char lbl_8034EB28[];
extern char lbl_805588D8[];
extern s32 lbl_805600E0;
extern s32 lbl_805600E4;
extern u8 lbl_805600EC;
extern s32 lbl_80558898[];
extern f32 lbl_805651E0, lbl_805651E4, lbl_805651E8, lbl_805651EC;
extern u8 SCGetLanguage(void);
extern void fn_801282F4(void);
extern void fn_800C64F4(void *);
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
void fn_802EC7AC(void) {
    register s32 *p;
    s32 i;
    lbl_805600EC = 0;
    fn_800C657C();
    p = (s32 *)lbl_805588D8;
    i = 0;
    do {
        if (*p != 0)
            ((void (*)(void *, ...))fn_802E317C)(lbl_8034EB28, (void *)*p);
        ++i;
        ++p;
    } while (i < 8);
    p = (s32 *)&lbl_80558860;
    fn_80128670(p[4]);
    fn_80128670(p[0]);
    if (p[1] != 0)
        fn_80128670(p[1]);
    p = (s32 *)&lbl_80558860;
    fn_80128670(p[2]);
    fn_80128670(p[3]);
    if (lbl_805600E0 != 0)
        fn_80128670(lbl_805600E0);
    if (lbl_805600E4 != 0)
        fn_80128670(lbl_805600E4);
}
#pragma scheduling on
#pragma small_data on
extern char lbl_8055D2F8;
#pragma small_data off
extern void WPADControlMotor(s32, s32);
extern void fn_800C65C4(void);
extern s32 fn_800C65CC(void *);
extern s32 fn_800C673C(void);
extern s32 fn_800C6768(void);
extern void fn_800C675C(void);
extern void fn_800C6774(s32, s32, s32);
extern void fn_800C687C(void);
extern void fn_800C68B0(void);
extern s32 fn_802D9BF0(void);
extern void fn_802E2C20(void);
extern void fn_802E2E38(s32);
extern void fn_802E30C8(const char *, ...);
extern void fn_802E5438(void);
extern void fn_802E7C40(void);
extern s32 fn_802E8668(s32);
extern void fn_802E99AC(void);
extern s32 lbl_80558898[];
void fn_802EC884(void) {
    register char *base = lbl_8034E9E0;
    s32 motor;
    s32 index;

    if ((u8)lbl_805600EC == 0) {
        return;
    }
    if ((u8)lbl_805600EA != 0) {
        lbl_805600EA = 0;
        if (fn_802D9BF0() == 0) {
            lbl_805600EB = (u8)(lbl_805600E9 == 0);
            fn_802E30C8(base + 0x16C,
                lbl_805600EB != 0 ? base + 0x198 : &lbl_8055D2F8);
            lbl_805600E8 = 1;
            for (motor = 0; motor < 4; motor++) {
                WPADControlMotor(motor, 0);
            }
            fn_800C6774(lbl_805600E4, lbl_805600E0, 0x19000);
            fn_800C65C4();
            fn_802EC4BC();
            fn_800C675C();
        }
    }
    fn_802E2C20();
    if ((u8)lbl_805600E8 == 0) {
        return;
    }
    for (index = 0; index < 4; index++) {
        lbl_80558898[index * 4] = fn_802E8668(index);
    }
    if (fn_800C65CC(lbl_80558898) < 0) {
        return;
    }
    fn_802E99AC();
    fn_802E7C40();
    fn_802E5438();
    fn_802E30C8(base + 0x1A4);
    fn_802E30C8(base + 0x1C0, fn_800C673C());
    fn_802E30C8(base + 0x1D0, fn_800C6768());
    switch (fn_800C673C()) {
    case 1:
        fn_802E30C8(base + 0x1E0);
        fn_802E2E38(1);
        break;
    case 2:
        fn_802E30C8(base + 0x200);
        fn_802E2E38(0);
        break;
    }
    fn_800C687C();
    lbl_805600E8 = 0;
    if ((u8)lbl_805600E8 != 0) {
        fn_800C68B0();
    }
}

extern void *fn_802D2D14(void);
extern void GXClearVtxDesc(void);
extern void GXSetVtxAttrFmt(int, int, int, int, int);
extern void GXSetVtxDesc(int, int);
extern void GXSetViewport(float, float, float, float, float, float);
extern void GXSetScissor(unsigned int, unsigned int, unsigned int, unsigned int);
extern void GXSetNumChans(int);
extern void GXSetNumTexGens(int);
extern void GXSetNumTevStages(int);
extern void GXSetTevOrder(int, int, int, int);
extern void GXSetTevOp(int, int);
extern void GXSetBlendMode(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetCurrentMtx(int);
extern void C_MTXOrtho(void *, float, float, float, float, float, float);
extern void GXSetProjection(void *, int);
extern void fn_800C6610(void);
extern void fn_802D3360(void);
extern s32 fn_802EC4BC(void);
extern float lbl_805651E0, lbl_805651E8, lbl_805651F0, lbl_805651F4;
extern float lbl_805651F8, lbl_805651FC, lbl_80565200, lbl_80565204, lbl_80565208;
#pragma dont_inline on
void fn_802ECA48(void) {
    u8 projection[0x40];
    u16 *dims;
    float scale;
    if ((u8)lbl_805600E8 != 0) {
        GXClearVtxDesc();
        GXSetVtxAttrFmt(4, 9, 0, 4, 0);
        GXSetVtxAttrFmt(4, 0xB, 0, 1, 0);
        GXSetVtxDesc(9, 1);
        GXSetVtxDesc(0xB, 1);
        dims = fn_802D2D14();
        scale = lbl_805651E0;
        GXSetViewport(scale, scale, (float)dims[2], (float)dims[3], scale, lbl_805651E8);
        GXSetScissor(0, 0, dims[2], dims[3]);
        GXSetNumChans(1);
        GXSetNumTexGens(0);
        GXSetNumTevStages(1);
        GXSetTevOrder(0, 0xFF, 0xFF, 4);
        GXSetTevOp(0, 4);
        GXSetBlendMode(0, 0, 0, 0);
        GXSetZMode(1, 3, 1);
        GXSetCurrentMtx(3);
        if (fn_802EC4BC() != 0)
            C_MTXOrtho(projection, lbl_805651F0, lbl_805651F4, lbl_805651F8, lbl_805651FC, lbl_805651E0, lbl_80565200);
        else
            C_MTXOrtho(projection, lbl_805651F0, lbl_805651F4, lbl_80565204, lbl_80565208, lbl_805651E0, lbl_80565200);
        GXSetProjection(projection, 1);
        if ((u8)lbl_805600E8 != 0) fn_800C6610();
        fn_802D3360();
    }
}
#pragma dont_inline off
void fn_802ECBF8(void) {
    if ((u8)lbl_805600E8 == 0) {
        lbl_805600EA = 1;
    }
}

char fn_802ECC10(void) {
    return lbl_805600E8;
}

void fn_802ECC18(u8 arg0) {
    lbl_805600E9 = arg0;
}

#pragma dont_inline on
void fn_802ECC20(void) {
    if (fn_8002173C() == 0) {
        fn_802CFCA0();
        fn_802D02F8(0xFF000000, 1);
        fn_802D68C4(0, 0, 0, 0);
        fn_802CFDE0();
        fn_802CFF10();
    }
}

void fn_802ECC74(void) {
    u8 temp;

    if (lbl_805600ED != 0) {
        return;
    }
    temp = lbl_805600EB;
    lbl_805600ED = 1;
    if (temp != 0) {
        while ((u8)lbl_805600E8 != 0) {
            fn_802ECC20();
            fn_80127464();
        }
        fn_802ECC20();
        lbl_805600EB = 0;
    }
    lbl_805600ED = 0;
}

#pragma dont_inline off
