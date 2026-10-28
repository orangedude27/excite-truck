// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern char fn_8011A168[];
extern void fn_80119214(void *, void *);
extern void fn_80116E54(void *, void *);
extern void fn_801282EC(u32);
extern void fn_801282F4(void);
extern void *fn_8012850C(u32, void *);
extern void *fn_802E0C04(u32);
extern void fn_802E0D44(u32);
extern u8 lbl_8055D150, lbl_8055D158, lbl_8055D160;
extern int fn_801345D8(void *, int, const char *, ...);
extern char *fn_80029004(char *, int);
extern void fn_802E0EAC(void *);
extern char lbl_8034CBC4[];
__declspec(section ".sdata") extern char lbl_8055D168[];
extern int fn_801186B8(void *);
extern void fn_80118C44(void *);
extern void fn_802E27A0(void *);
extern void fn_802E27B8(void *);
extern u8 fn_802ECC10(void);
extern char lbl_8034CBE0[], lbl_8034CBF8[];
extern void fn_802E30C8(const char *, ...);
extern void fn_802E2C20(void);
extern void fn_801284F8(void *, void *);
extern char lbl_8034CB68[];
extern void *lbl_8055FEEC;
extern void fn_80128668();
extern void fn_80128670();
extern char lbl_8034BAEC[], lbl_8034BB1C[], lbl_8034BB5C[], lbl_8034BB68[];
extern char lbl_8034BB7C[], lbl_8034BB88[], lbl_8034BB9C[], lbl_8034BBA8[];
extern char lbl_8034CB68[];
extern char lbl_8055D098[];
#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXTev.h>
extern void *lbl_8055FEE8;
extern void fn_802D3144(void);
extern void GXSetNumIndStages(u8);
extern void GXSetTevDirect(GXTevStageID);
extern void fn_80118DC0(void *);
extern void fn_802E1728(void *);

void fn_802DEAC4(void) {
    register u32 x = 1;
    GXSetTexCoordGen2(0, x, 0, 0x21, 0, 0x7D);
    GXSetTexCoordGen2(1, x, 0, 0x24, 0, 0x7D);
    GXSetTexCoordGen2(2, x, 0, 0x27, 0, 0x7D);
    GXSetTexCoordGen2(3, x, 0, 0x1E, 0, 0x7D);
    GXSetNumTexGens(4);
    GXSetTevOrder(0, 3, 1, 0xFF);
    GXSetTevOrder(1, 0, 2, 0xFF);
    GXSetTevOrder(2, 0, 3, 0xFF);
    GXSetTevOrder(3, 2, 0, 0xFF);
    GXSetTevOrder(4, 1, 4, 0xFF);
    GXSetTevSwapMode(0, 0, 0); GXSetTevSwapMode(1, 0, 0); GXSetTevSwapMode(2, 0, 0); GXSetTevSwapMode(3, 0, 0); GXSetTevSwapMode(4, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF); GXSetTevColorOp(0, 0, 0, 0, 1, 0); GXSetTevAlphaIn(0, 7, 7, 7, 7); GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 8, 0xF, 0xF, 0xF); GXSetTevColorOp(1, 0, 0, 0, 1, 1); GXSetTevAlphaIn(1, 7, 7, 7, 0); GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 0, 2, 9, 0xF); GXSetTevColorOp(2, 0, 0, 0, 1, 0); GXSetTevAlphaIn(2, 7, 7, 7, 0); GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetTevColorIn(3, 0xF, 0, 8, 0xF); GXSetTevColorOp(3, 0, 0, 0, 1, 0); GXSetTevAlphaIn(3, 7, 7, 7, 0); GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    GXSetTevColorIn(4, 0xF, 0xF, 0xF, 0); GXSetTevColorOp(4, 0, 0, 0, 1, 0); GXSetTevAlphaIn(4, 4, 7, 7, 7); GXSetTevAlphaOp(4, 0, 0, 0, 1, 0);
    GXSetNumTevStages(5);
}

void fn_802DEE1C(void) {
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetTevSwapMode(3, 0, 0);
    GXSetTevSwapMode(4, 0, 0);
}

void fn_802DEE88(void) {
    volatile int x = 1;
    GXSetTexCoordGen2(0, x, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 5, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetNumTevStages(1);
    GXSetBlendMode(1, 4, 5, 0);
}

#pragma scheduling invalid_target
void fn_802DEF70(void) {
    GXSetTevSwapMode(0, 0, 0);
    fn_802D3144();
}
#pragma scheduling on
void fn_802DEFA0(void) {
    s32 spC;
    s32 sp8;
    GXSetTexCoordGen2(0, 0, 1, 0x2A, 1, 0x4C);
    GXSetTexCoordGen2(1, 1, 1, 0x21, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetIndTexOrder(0, 0, 5);
    GXSetNumIndStages(1);
    GXSetTevOrder(0, 1, 7, 4);
    GXSetTevOrder(1, 0xFF, 6, 0xFF);
    GXSetTevSwapModeTable(1, 2, 2, 2, 0);
    GXSetTevSwapMode(0, 0, 1);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 0xF, 0xA, 6, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 4, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0, 8, 9, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevIndirect(1, 0, 0, 0, 1, 6, 6, 0, 0, 0);
    GXSetNumTevStages(2);
    GXSetBlendMode(1, 4, 0, 0);
    GXLoadTexObj(fn_802D312C(), 5);
    GXLoadTexObj(fn_802D30E4(), 7);
    GXLoadTexObj(fn_802D30F0(), 6);
}

#pragma scheduling invalid_target
void fn_802DF1B4(void) {
    register u32 stage = 1;
    register u32 zero = 0;
    register u32 last = 3;
    GXSetTevSwapModeTable(stage, zero, zero, zero, last);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    fn_802D3144();
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}
#pragma scheduling on
void fn_802DF21C(void) {
    GXSetTexCoordGen2(0, 1, 1, 0x2A, 0, 0x7D);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevColorIn(0, 0xF, 0xA, 8, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 1, 1, 1, 0);
    GXSetNumTevStages(1);
}

void fn_802DF2F0(void) {
    GXSetTevSwapMode(0, 0, 0);
}

void *fn_802D3138(void);
void fn_802DF300(void) {
    register u32 coord = 0;
    register u32 type = 1;
    GXSetTexCoordGen2(coord, type, 0, 0x2D, 0, 0x7D);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetTevOrder(1, 0, 7, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 0xF, 0xA, 6, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 1, 1, 1, 0);
    GXSetTevColorIn(1, 0, 8, 9, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
    GXLoadTexObj(fn_802D3138(), 7);
}

#pragma push
#pragma scheduling invalid_target
void fn_802DF46C(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
}
#pragma pop
void *fn_802D3130(void);
void *fn_802D3100(void);
void fn_802DF4A8(void) {
    s32 spC;
    s32 sp8;
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 0, 1, 0x2A, 1, 0x4C);
    GXSetNumTexGens(2);
    GXSetIndTexOrder(0, 1, 5);
    GXSetNumIndStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOrder(1, 0xFF, 6, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 0xF, 0xA, 8, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 1, 1, 1, 0);
    GXSetTevColorIn(1, 0, 8, 9, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevIndirect(1, 0, 0, 0, 1, 6, 6, 0, sp8, spC);
    GXSetNumTevStages(2);
    GXLoadTexObj(fn_802D3130(), 5);
    GXLoadTexObj(fn_802D3100(), 6);
}

#pragma scheduling invalid_target
void fn_802DF684(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}
#pragma scheduling on
void fn_802DF6D0(void) {
    volatile s32 spC = 0;
    volatile s32 sp8 = 0;
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 0, 1, 0x2A, 1, 0x4C);
    GXSetNumTexGens(2);
    GXSetIndTexOrder(0, 1, 5);
    GXSetNumIndStages(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOrder(1, 0xFF, 6, 0xFF);
    GXSetTevOrder(2, 0, 1, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetTevColorIn(0, 0xF, 8, 0xA, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0, 8, 9, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevIndirect(1, 0, 0, 0, 1, 6, 6, 0, spC, sp8);
    GXSetTevColorIn(2, 0xF, 0xF, 0xF, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 4, 7, 7, 7);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetNumTevStages(3);
    GXLoadTexObj(fn_802D3134(), 5);
    GXLoadTexObj(fn_802D30FC(), 6);
}

void fn_802DF938(void) {
    register GXTevStageID stage = GX_TEVSTAGE0;
    register GXTevSwapSel color = (GXTevSwapSel)0;
    register GXTevSwapSel alpha = (GXTevSwapSel)0;
    GXSetTevSwapMode(stage, color, alpha);
    stage = GX_TEVSTAGE1;
    GXSetTevSwapMode(stage, color, alpha);
    stage = GX_TEVSTAGE2;
    GXSetTevSwapMode(stage, color, alpha);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}

#pragma scheduling off
void fn_802DF994(void) {
    register u32 coord = 0;
    GXSetTexCoordGen2(coord, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0, 0, 4);
    GXSetTevOrder(1, 0xFF, 0xFF, 5);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 0xF, 8, 0xA, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 1, 1, 1, 0);
    GXSetTevColorIn(1, 0xF, 0xA, 5, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
}

#pragma push
#pragma scheduling invalid_target
void fn_802DFAF4(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
}
#pragma pop
void fn_802DFB30(void) {
    register u32 coord = 0;
    register u32 map = coord + 1;
    GXSetTexCoordGen2(coord, map, 0, 0x1E, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 0, 0x1E, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetTevOrder(0, 1, 1, 0xFF);
    GXSetTevOrder(1, 0, 0, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 1, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xF, 0, 8, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
    GXSetBlendMode(1, 4, 5, 0);
}

#pragma scheduling off
void fn_802DFCC0(void) {
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    fn_802D3144();
}
#pragma scheduling on
void fn_802DFD00(void) {
    GXSetTexCoordGen2(0, 1, 0, 0x1E, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetTevOrder(0, 1, 1, 0xFF);
    GXSetTevOrder(1, 0, 0, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevKAlphaSel(0, 0x1D);
    GXSetTevAlphaIn(0, 7, 4, 6, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xF, 0, 8, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
}
#pragma scheduling reset
void fn_802DFE88(void) {
    GXSetTexCoordGen2(0, 1, 0, 0x1E, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetTevOrder(0, 1, 1, 0xFF);
    GXSetTevOrder(1, 0, 0, 0xFF);
    GXSetTevOrder(2, 1, 2, 0xFF);
    GXSetTevSwapMode(0, 0, 0); GXSetTevSwapMode(1, 0, 0); GXSetTevSwapMode(2, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF); GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7); GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xF, 0, 8, 0xF); GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0); GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 0xF, 0xF, 0xF, 0); GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevKAlphaSel(2, 0x1D); GXSetTevAlphaIn(2, 7, 4, 6, 7);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0); GXSetNumTevStages(3);
}

void fn_802E009C(void) {
    register u32 coord = 0;
    register u32 type = 1;
    GXSetTexCoordGen2(coord, type, 5, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetTevOrder(0, 1, 1, 4);
    GXSetTevOrder(1, 0, 0, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 5, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xF, 0, 8, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
}

void fn_802E0218(void) {
    register u32 first = 0;
    GXSetTexCoordGen2(first, 1, 5, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetTevOrder(0, 1, 1, 0xFF);
    GXSetTevOrder(1, 0, 0, 0xFF);
    GXSetTevOrder(2, 1, 2, 4);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xF, 0, 8, 0xF);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 0xF, 0xF, 0xF, 0);
    GXSetTevColorOp(2, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(2, 7, 4, 5, 7);
    GXSetTevAlphaOp(2, 0, 0, 0, 1, 0);
    GXSetNumTevStages(3);
}

#pragma scheduling invalid_target
void fn_802E0420(void) {
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0, 1, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevKColorSel(0, 0xD);
    GXSetTevColorIn(0, 0xF, 8, 0xE, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevKAlphaSel(0, 0x1D);
    GXSetTevAlphaIn(0, 7, 4, 6, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetNumTevStages(1);
}
#pragma scheduling on
void fn_802E050C(void) {
    register u32 stage = 0;
    register u32 type = 1;
    GXSetTexCoordGen2(stage, type, 4, 0x3C, 0, 0x7D);
    GXSetNumTexGens(1);
    GXSetTevOrder(0, 0, 1, 0xFF);
    GXSetTevOrder(1, 0, 2, 0xFF);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevKColorSel(0, 0xD);
    GXSetTevColorIn(0, 0xF, 8, 0xE, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 0xF, 0xF, 0xF, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevKAlphaSel(1, 0x1D);
    GXSetTevAlphaIn(1, 7, 4, 6, 7);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
}

void fn_802E0684(void) {
    register u32 mode = 1;
    GXSetTexCoordGen2(0, mode, 0, 0x21, 0, 0x7D);
    GXSetTexCoordGen2(1, mode, 0, 0x1E, 0, 0x7D);
    GXSetTexCoordGen2(2, mode, 0, 0x27, 0, 0x7D);
    GXSetNumTexGens(3);
    GXSetTevOrder(0, 1, 1, 0xFF); GXSetTevOrder(1, 0, 3, 0xFF); GXSetTevOrder(2, 0, 4, 0xFF); GXSetTevOrder(3, 2, 0, 0xFF); GXSetTevOrder(4, 1, 2, 0xFF);
    GXSetTevSwapModeTable(1, 3, 3, 3, 3);
    GXSetTevSwapMode(0, 0, 0); GXSetTevSwapMode(1, 0, 0); GXSetTevSwapMode(2, 0, 1); GXSetTevSwapMode(3, 0, 0); GXSetTevSwapMode(4, 0, 0);
    GXSetTevColorIn(0, 8, 0xF, 0xF, 0xF); GXSetTevColorOp(0, 0, 0, 0, 1, 0); GXSetTevAlphaIn(0, 7, 7, 7, 7); GXSetTevAlphaOp(0, 0, 0, 0, 1, 0);
    GXSetTevColorIn(1, 8, 0xF, 0xF, 0xF); GXSetTevColorOp(1, 0, 0, 0, 1, 1); GXSetTevAlphaIn(1, 7, 7, 7, 0); GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevColorIn(2, 0, 2, 8, 0xF); GXSetTevColorOp(2, 0, 0, 0, 1, 0); GXSetTevAlphaIn(2, 4, 7, 7, 7); GXSetTevAlphaOp(2, 0, 0, 0, 1, 1);
    GXSetTevColorIn(3, 0xF, 0, 8, 0xF); GXSetTevColorOp(3, 0, 0, 0, 1, 0); GXSetTevAlphaIn(3, 7, 7, 7, 0); GXSetTevAlphaOp(3, 0, 0, 0, 1, 0);
    GXSetTevColorIn(4, 0xF, 0xF, 0xF, 0); GXSetTevColorOp(4, 0, 0, 0, 1, 0); GXSetTevAlphaIn(4, 7, 4, 1, 7); GXSetTevAlphaOp(4, 0, 0, 0, 1, 0);
    GXSetNumTevStages(5); GXSetBlendMode(1, 4, 5, 0);
}

void fn_802E09EC(void) {
    register u32 coord = 0;
    register u32 projection = 1;
    GXSetTexCoordGen2(coord, projection, 4, 0x3C, 0, 0x7D);
    GXSetTexCoordGen2(1, 1, 1, 0x2A, 0, 0x7D);
    GXSetNumTexGens(2);
    GXSetTevOrder(0, 1, 2, 0xFF);
    GXSetTevOrder(1, 0, 0, 4);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevColorIn(0, 0xF, 8, 5, 0xF);
    GXSetTevColorOp(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 7, 7);
    GXSetTevAlphaOp(0, 0, 1, 1, 1, 0);
    GXSetTevColorIn(1, 0xF, 8, 0xA, 0);
    GXSetTevColorOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 7, 7, 7, 0);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetNumTevStages(2);
}

#pragma push
#pragma scheduling invalid_target
void fn_802E0B68(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
}
#pragma pop
#pragma dont_inline on
void *fn_802E0BA4(void) {
}

void fn_802E0BA8(void) {
    u32 *p = ((u32 *(*)(s32, void *))fn_801284F8)(0x228, lbl_8034CB68);
    *p = 0x10011001;
}

#pragma dont_inline reset

#pragma scheduling on
#pragma dont_inline on
void fn_802E0BE0(void) {
    fn_802E0BA4();
    fn_80128668();
}

extern void fn_802E317C(char *, ...);
extern char lbl_8034BB28[];
#pragma push
#pragma optimization_level 3
#pragma scheduling invalid_target
void *fn_802E0C04(u32 size) {
    volatile int *head;
    int needed;
    void **link;
    int best;
    void **bestLink;
    void *result;
    void *node;

    best = 0x7FFFFFFF;
    bestLink = 0;
    result = 0;
    head = (volatile int *)lbl_8055FEE8;
    needed = head[1];
    link = (void **)&head[2];
    needed = (size + needed) & ~needed;

    while ((node = *link) != 0) {
        int freeSize = *(int *)((char *)node + 4);
        if (freeSize >= needed && best > freeSize) {
            bestLink = link;
            best = freeSize;
        }
        link = (void **)((char *)node + 8);
    }

    if (bestLink != 0) {
        void *freeNode = *bestLink;
        void *split = 0;
        int align = head[1];
        int freeSize = *(int *)((char *)freeNode + 4);
        void *next = *(void **)((char *)freeNode + 8);
        int r3 = (align + 0x10) & ~align;
        int left = freeSize - needed;

        if (left > r3 + 0x20) {
            char *p = (char *)freeNode + align + needed;
            int align2;
            *(int *)(p + 1) = 0xABCFEED0;
            split = p + 1;
            *(int *)(p + 9) = 0;
            align2 = head[1];
            *(int *)(p + 5) = left - ((align2 + 0x10) & ~align2);
            *(volatile int **)(p + 0xD) = head;
            *(int *)((char *)freeNode + 4) = needed;
        }

        if (split != 0) {
            *(void **)((char *)split + 8) = next;
            *bestLink = split;
        } else {
            *bestLink = next;
        }

        *(void **)((char *)freeNode + 8) = (void *)head[3];
        head[3] = (int)freeNode;
        result = (char *)freeNode + head[1] + 1;
    }

    if (result == 0 && *(volatile u8 *)head != 0) {
        fn_802E317C(lbl_8034BB28);
    }
    return result;
}
#pragma pop

void fn_802E0D44(u32 size) {
    u8 *head = (u8 *)lbl_8055FEE8;
    u32 align0 = *(u32 *)(head + 4);
    u8 *block = (u8 *)(size - (align0 + 1));
    u8 **link = (u8 **)(head + 12);
    u8 *node = (u8 *)size;
    do {
        if (node == block) {
            *link = *(u8 **)(block + 8);
            break;
        }
        link = (u8 **)(node + 8);
        node = *link;
    } while (node != 0);
    *(u8 **)(block + 8) = *(u8 **)(head + 8);
    *(u8 **)(head + 8) = block;
    {
        u8 **anchor = (u8 **)(head + 8);
        u32 changed;
        do {
            u8 **scan = (u8 **)(head + 8);
            u32 didMerge = 0;
            while (*scan != 0) {
                u8 *current = *scan;
                u8 *other = *anchor;
                u32 adjacent = 1;
                u32 align = *(u32 *)(head + 4);
                if (other + align + *(u32 *)(other + 4) + 1 != current &&
                    current + align + *(u32 *)(current + 4) + 1 != other) {
                    adjacent = 0;
                }
                if (adjacent != 0) {
                    u8 **selected = anchor;
                    if (current + align + *(u32 *)(current + 4) + 1 == other) {
                        selected = scan;
                        scan = anchor;
                    }
                    {
                        u8 *kept = *selected;
                        u8 *removed = *scan;
                        anchor = selected;
                        didMerge = 1;
                        *(u32 *)(kept + 4) = *(u32 *)(kept + 4) + *(u32 *)(removed + 4) + ((align + 16) & ~align);
                        *scan = *(u8 **)(removed + 8);
                    }
                } else {
                    scan = (u8 **)(current + 8);
                }
            }
            changed = didMerge;
        } while (changed != 0);
    }
}

void fn_802E0E60(arg0)
void *arg0;
{
    s32 *field;

    field = (s32 *)((u8 *)arg0 + 4);
    if (*field != 0) {
        fn_802E1728((u8 *)arg0 + 0x50);
        fn_80118DC0((void *)*field);
        *field = 0;
    }
}

extern s32 fn_802E36D8(void *);
extern void fn_802E3804(void *, u32);
extern void fn_802E3734(s32 *);
extern s32 fn_8011770C(void *, u32);
extern void fn_80117618(s32, void *);
extern s32 fn_802E1BB4(void *);
extern void fn_801176FC(s32, void *);
void fn_802E0EAC(void *arg0) {
    s32 sp8;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    char *label;
    fn_802E0E60(arg0);
    label = lbl_8034CB68;
    sp8 = fn_802E36D8((u8 *)arg0 + 8);
    if (sp8 != -1) {
        fn_802E3804(&sp10, 0x20);
        fn_802E3734(&sp8);
    }
    sp10 = fn_8011770C((u8 *)arg0 + 8, 0x10400);
    *(s32 *)((u8 *)arg0 + 4) = sp10;
    if (sp10 != 0) {
        fn_802E30C8(label + 0x10, (u8 *)arg0 + 8);
        fn_80117618(sp10, (u8 *)arg0 + 0x150);
        fn_80117618(sp10, (u8 *)arg0 + 0x150);
        if (fn_802E1BB4((u8 *)arg0 + 0x50) == 0) {
            fn_802E317C(label + 0x20);
        }
        fn_801176FC(sp10, (u8 *)arg0 + 0x150);
        *(s32 *)((u8 *)arg0 + 0x4C) = ((s32 (*)(void))fn_802E2C20)();
    } else {
        fn_802E30C8(label + 0x48, (u8 *)arg0 + 8);
    }
}

void fn_802E0F98(void) {
    void *object;
    fn_80119214((void *)fn_802E0C04, (void *)fn_802E0D44);
    fn_80116E54(&fn_8011A168, &lbl_8055D150);
    fn_801282EC(0x80);
    fn_801282F4();
    lbl_8055FEEC = fn_8012850C(0x600000, &lbl_8055D158);
    object = ((void *(*)(u32, void *))fn_801284F8)(0x10, &lbl_8055D160);
    if (object != 0) {
        register void *allocation = lbl_8055FEEC;
        *(u32 *)((char *)object + 0xC) = 0;
        *(u32 *)((char *)object + 4) = 0x1F;
        *(u32 *)allocation = 0xABCFEED0;
        *(u32 *)((char *)allocation + 8) = 0;
        {
            u32 size = *(u32 *)((char *)object + 4);
            *(u32 *)((char *)allocation + 4) = 0x600000 - ((size + 0x10) & ~size);
        }
        *(void **)((char *)allocation + 0xC) = object;
        *(void **)((char *)object + 8) = allocation;
        *(u8 *)object = 1;
    }
    lbl_8055FEE8 = object;
}

void fn_802E1058(void) {
    void *root;
    void *node;
    unsigned int total;
    unsigned int otherTotal;

    root = lbl_8055FEE8;
    if (root != 0) {
        if (*(int *)((char *)root + 0xC) != 0) {
            fn_802E30C8(lbl_8034BBA8, lbl_8034BB1C);
            fn_802E30C8(lbl_8034BB9C);

            node = *(void **)((char *)root + 0xC);
            total = 0;
            while (node != 0) {
                fn_802E30C8(lbl_8034BB88, (char *)node + 0x10,
                            *(int *)((char *)node + 4));
                total += *(unsigned int *)((char *)node + 4);
                node = *(void **)((char *)node + 8);
            }
            fn_802E30C8(lbl_8034BB7C, total >> 10);

            otherTotal = 0;
            fn_802E30C8(lbl_8055D098);
            node = *(void **)((char *)root + 8);
            while (node != 0) {
                fn_802E30C8(lbl_8034BB68, (char *)node + 0x10,
                            *(int *)((char *)node + 4));
                otherTotal += *(unsigned int *)((char *)node + 4);
                node = *(void **)((char *)node + 8);
            }
            fn_802E30C8(lbl_8034BB5C, otherTotal >> 10);
            fn_802E317C(lbl_8034BAEC);
        }
        fn_80128668(root);
    }
    lbl_8055FEE8 = 0;
    fn_80128670(lbl_8055FEEC);
    lbl_8055FEEC = 0;
}

#pragma push
#pragma use_lmw_stmw off
s32 fn_802E11A4(s32 arg0, s32 arg1) {
    s32 saved = ((s32 (*)(void))fn_802E0BA8)();
    register void *object = fn_802E0BA4();
    char *dot;
    register char *dest;
    register const char *suffix;
    register int remaining;
    *(s32 *)((char *)object + 4) = 0;
    *(u8 *)((char *)object + 0x48) = (u8)arg1;
    fn_801345D8((char *)object + 8, 0x40, lbl_8034CBC4, arg0);
    dot = fn_80029004((char *)object + 8, 0x2e);
    if (dot != 0)
        *dot = 0;
    dest = (char *)object + 8;
    remaining = 0x40;
    suffix = lbl_8055D168;
    while ((s8)*dest) {
        --remaining;
        ++dest;
    }
    if (remaining > 0) {
        while ((s8)(*dest++ = *suffix++) != 0) {
            if (--remaining <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    fn_802E0EAC(object);
    return saved;
}
#pragma pop
void fn_802E1290(void *arg0) {
    extern void fn_802E30C8(const char *, ...);
    extern void *fn_802E0BA4(void);
    extern void fn_802E0BE0(void);
    extern void fn_802E0E60();
    extern char lbl_8034CBD0[];
    fn_802E30C8(lbl_8034CBD0, lbl_8034CBD0);
    ((void (*)(void *))fn_802E0BA4)(arg0);
    fn_802E0E60();
    ((void (*)(void *))fn_802E0BE0)(arg0);
}

#pragma push
#pragma use_lmw_stmw off
void fn_802E12DC(void) {
    void *object = fn_802E0BA4();
    s32 current;
    if (*(void **)((char *)object + 4) != 0 &&
        *(s32 *)((char *)(*(void **)((char *)object + 4)) + 0x1C) != 0) {
        fn_802E30C8(lbl_8034CBE0);
        fn_802E0E60(object);
    }
    if (*(void **)((char *)object + 4) == 0)
        fn_802E0EAC(object);
    if (*(void **)((char *)object + 4) != 0) {
        fn_802E27B8((char *)object + 0x50);
        fn_801186B8(*(void **)((char *)object + 4));
        current = ((s32 (*)(void))fn_802E2C20)();
        if (current - *(s32 *)((char *)object + 0x4C) > 0x96) {
            fn_802E30C8(lbl_8034CBF8);
            *(s32 *)((char *)object + 0x4C) = current - 0x20;
        }
        if (current - *(s32 *)((char *)object + 0x4C) > 0x1E) {
            if (((s32 (*)(void))fn_802ECC10)() == 0)
                fn_80118C44(*(void **)((char *)object + 4));
            *(s32 *)((char *)object + 0x4C) += 0x20;
        }
        fn_802E27A0((char *)object + 0x50);
    }
}
#pragma pop
extern void GXSetZMode(GXBool, GXCompare, GXBool);
extern void fn_802C8C04(s32);
extern void fn_802C8D74(void);
extern void fn_802C8DB8(void *, s32, u16 *, s32, u16, u16, u16, u16);
extern void fn_802D007C(f32);
extern void fn_802D3360(void);
extern void fn_802E2C20(void);
extern void fn_802E1DA4(void *, u32, u32, f32, f32, f32, f32, f32);
extern const u16 lbl_802FAE28[];
extern const u8 lbl_805650C8, lbl_805650C9, lbl_805650CA, lbl_805650CB;
extern const f32 lbl_805650CC, lbl_805650D0, lbl_805650D4, lbl_805650D8, lbl_805650DC, lbl_805650E0;
extern const u16 lbl_80565238, lbl_8056523A, lbl_8056523C, lbl_8056523E;
#pragma push
#pragma scheduling invalid_target
#pragma optimization_level 3
void fn_802E13D8(f32 farg0, f32 farg1, f32 farg2, f32 farg3, void *arg0) {
    f32 sp30[24];
    u16 sp20[6];
    GXColor kColor;
    u16 tevColor[4];
    u8 *var_r3;
    f32 temp_f31;
    f32 temp_f28;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f1_6;
    f32 var_f1_7;
    f32 var_f1_8;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 var_ctr;
    s32 var_r6;
    void *temp_r31;
    u32 *temp_r5_3;
    u32 *temp_r3;
    temp_r31 = fn_802E0BA4();
    fn_802D3360();
    if (*(u32 **)((u8 *)temp_r31 + 4) != 0) {
        fn_802C8C04(-1);
        var_r3 = (u8 *)sp30;
        var_r6 = 0;
        for (var_ctr = 0; var_ctr < 2; var_ctr++) {
            temp_r4 = var_r6 & 1;
            if (temp_r4 != 0) var_f1 = lbl_805650CC;
            else var_f1 = lbl_805650D0;
            temp_r5 = var_r6 & 2;
            *(f32 *)(var_r3 + 0) = var_f1;
            if (temp_r5 != 0) var_f1_2 = lbl_805650D4;
            else var_f1_2 = lbl_805650D0;
            *(f32 *)(var_r3 + 4) = var_f1_2;
            *(f32 *)(var_r3 + 8) = lbl_805650D0;
            if (temp_r4 != 0) var_f1_3 = lbl_805650D8;
            else var_f1_3 = lbl_805650D0;
            *(f32 *)(var_r3 + 0x10) = var_f1_3;
            if (temp_r5 != 0) var_f1_4 = lbl_805650D8;
            else var_f1_4 = lbl_805650D0;
            *(f32 *)(var_r3 + 0x14) = var_f1_4;
            temp_r6 = var_r6 + 1;
            temp_r4_2 = temp_r6 & 1;
            *(s32 *)(var_r3 + 0xC) = -1;
            if (temp_r4_2 != 0) var_f1_5 = lbl_805650CC;
            else var_f1_5 = lbl_805650D0;
            temp_r5_2 = temp_r6 & 2;
            *(f32 *)(var_r3 + 0x18) = var_f1_5;
            if (temp_r5_2 != 0) var_f1_6 = lbl_805650D4;
            else var_f1_6 = lbl_805650D0;
            *(f32 *)(var_r3 + 0x1C) = var_f1_6;
            *(f32 *)(var_r3 + 0x20) = lbl_805650D0;
            if (temp_r4_2 != 0) var_f1_7 = lbl_805650D8;
            else var_f1_7 = lbl_805650D0;
            *(f32 *)(var_r3 + 0x28) = var_f1_7;
            if (temp_r5_2 != 0) var_f1_8 = lbl_805650D8;
            else var_f1_8 = lbl_805650D0;
            *(f32 *)(var_r3 + 0x2C) = var_f1_8;
            var_r6 = temp_r6 + 1;
            *(s32 *)(var_r3 + 0x24) = -1;
            var_r3 += 0x30;
        }
        {
            register volatile const u16 *indexPtr = lbl_802FAE28;
            sp20[0] = *indexPtr++;
            sp20[1] = *indexPtr++;
            sp20[2] = *indexPtr++;
            sp20[3] = *indexPtr++;
            sp20[4] = *indexPtr++;
            sp20[5] = *indexPtr++;
        }
        fn_802C8DB8(sp30, 4, sp20, 6, sp20[4], sp20[3], sp20[2], sp20[1]);
        fn_802C8D74();
        temp_r5_3 = *(u32 **)((u8 *)temp_r31 + 4);
        temp_f31 = lbl_805650DC + farg0;
        temp_f28 = lbl_805650E0 + -farg1;
        temp_f1 = (f32)temp_r5_3[0];
        temp_f2 = (f32)temp_r5_3[1];
        temp_f30 = farg2 / temp_f1;
        temp_f29 = farg3 / temp_f2;
        GXSetZMode(0, 7, 0);
        GXSetColorUpdate(1);
        GXSetAlphaCompare(7, 0, 1, 0, 0);
        temp_r3 = *(u32 **)((u8 *)temp_r31 + 4);
        fn_802E1DA4((u8 *)temp_r31 + 0x50, temp_r3[0], temp_r3[1], temp_f31, temp_f28, temp_f30, temp_f29, lbl_805650D8);
        fn_802D007C(lbl_805650D8);
        GXSetTevSwapMode(0, 0, 0);
        GXSetTevSwapMode(1, 0, 0);
        GXSetTevSwapMode(2, 0, 0);
        GXSetTevSwapMode(3, 0, 0);
        tevColor[0] = lbl_80565238;
        tevColor[1] = lbl_8056523A;
        tevColor[2] = lbl_8056523C;
        tevColor[3] = lbl_8056523E;
        ((void (*)(s32, void *))GXSetTevColorS10)(1, tevColor);
        kColor.r = lbl_805650C8;
        kColor.g = lbl_805650C9;
        kColor.b = lbl_805650CA;
        kColor.a = lbl_805650CB;
        GXSetTevKColor(0, kColor);
        GXSetTevKColor(1, kColor);
        GXSetTevKColor(2, kColor);
        GXSetTevSwapModeTable(0, 0, 1, 2, 3);
        fn_802D3360();
        fn_802E2C20();
    }
}
#pragma optimization_level reset
#pragma pop
extern void fn_802E30C8(const char *, ...);
extern void fn_80119214(void *, void *);
extern void fn_80116E54(void *, void *);
extern void fn_801282EC(u32);
extern void fn_801282F4(void);
extern void *fn_8012850C(u32, void *);
extern void fn_801284F8(void *, void *);
extern void fn_801282F4(void);
extern void *fn_802E0C04(u32);
extern void fn_802E0D44(u32);
extern char lbl_8034CBD0[];
extern u8 lbl_8055D150, lbl_8055D158, lbl_8055D160;
extern void *lbl_8055FEE8, *lbl_8055FEEC;
s32 fn_802E1718(void) { return 0; }

