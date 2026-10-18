// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include "types.h"

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
extern u32 lbl_80558860;
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

s32 fn_802EC4E8(s32 arg0) {
    char sp10[0x40];
    s32 sp8;
    s32 temp_r30;
    s32 temp_r31;
    fn_801345D8(sp10, 0x40, lbl_8034E9E0, arg0);
    sp8 = fn_802E36D8(sp10);
    if (sp8 == -1) fn_802E317C(lbl_8034E9E0 + 0x10, sp10);
    temp_r30 = fn_802E37C4(sp8);
    fn_801282EC(0x20);
    temp_r31 = fn_8012850C(temp_r30, lbl_8034E9E0 + 0x28);
    fn_802E3804(sp8, temp_r31, temp_r30);
    fn_802E3734(&sp8);
    return temp_r31;
}

extern u32 lbl_80558860;
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
void *fn_802EC598(void) {
    s32 index = *(s32 *)((u8 *)&lbl_80558860 + 0x1c);
    switch (index) {
    case 0: return lbl_8034E9E0 + 0x34;
    case 1: return lbl_8034E9E0 + 0x40;
    case 2: return lbl_8034E9E0 + 0x50;
    case 3: return lbl_8034E9E0 + 0x60;
    case 4: return lbl_8034E9E0 + 0x70;
    case 5: return lbl_8034E9E0 + 0x80;
    case 6: return lbl_8034E9E0 + 0x90;
    default:
        *(s32 *)((u8 *)&lbl_80558860 + 0x1c) = 0;
        return lbl_8034E9E0 + 0x34;
    }
}

extern void fn_800C657C(void);
extern void fn_80128670(s32);
extern s32 lbl_8034EB28;
extern s32 lbl_805588D8;
extern s32 lbl_805600E0;
extern s32 lbl_805600E4;
extern u8 lbl_805600EC;
void fn_802EC7AC(void) {
    s32 *p;
    char *format;
    s32 i;
    lbl_805600EC = 0;
    fn_800C657C();
    p = &lbl_805588D8;
    i = 0;
    format = (char *)&lbl_8034EB28;
    do {
        if (*p != 0)
            fn_802E317C(format, (void *)*p);
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

