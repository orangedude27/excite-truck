// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
extern void *lbl_8055FEEC;
extern void fn_80128668();
extern void fn_80128670();
extern char lbl_8034BAEC[], lbl_8034BB1C[], lbl_8034BB5C[], lbl_8034BB68[];
extern char lbl_8034BB7C[], lbl_8034BB88[], lbl_8034BB9C[], lbl_8034BBA8[];
extern char lbl_8055D098[];
#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXTev.h>
extern void *lbl_8055FEE8;
extern void fn_802D3144(void);
extern void GXSetNumIndStages(u8);
extern void GXSetTevDirect(GXTevStageID);

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

void fn_802DEF70(void) {
    GXSetTevSwapMode(0, 0, 0);
    fn_802D3144();
}

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

#pragma push
#pragma scheduling off
void fn_802E0420(void) {
    volatile u32 mode = 1;
    GXSetTexCoordGen2(0, mode, 4, 0x3C, 0, 0x7D);
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
#pragma pop
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
#pragma dont_inline reset

#pragma scheduling on
#pragma dont_inline on
void fn_802E0BE0(void) {
    fn_802E0BA4();
    fn_80128668();
}

extern void fn_802E317C(char *, ...);
extern char lbl_8034BB28[];
void *fn_802E0C04(u32 size) {
    u8 *head = (u8 *)lbl_8055FEE8;
    u32 align = *(u32 *)(head + 4);
    u8 **link = (u8 **)(head + 8);
    u32 needed = (size + align) & ~align;
    u32 best = 0x7FFFFFFF;
    u8 **bestLink = 0;
    u8 *node;
    u8 *result = 0;
    while ((node = *link) != 0) {
        u32 freeSize = *(u32 *)(node + 4);
        if (freeSize >= needed && best > freeSize) {
            bestLink = link;
            best = freeSize;
        }
        link = (u8 **)(node + 8);
    }
    if (bestLink != 0) {
        u8 *freeNode = *bestLink;
        u8 *next = *(u8 **)(freeNode + 8);
        u32 left = *(u32 *)(freeNode + 4) - needed;
        u8 *split = 0;
        if (left > (((align + 0x10) & ~align) + 0x20)) {
            split = freeNode + align + needed;
            *(u32 *)(split + 1) = 0xABCFEED0;
            *(u32 *)(split + 9) = 0;
            *(u32 *)(split + 5) = left - ((align + 0x10) & ~align);
            *(u8 **)(split + 0xD) = head;
            *(u32 *)(freeNode + 4) = needed;
        }
        if (split != 0) {
            *(u8 **)(split + 8) = next;
            *bestLink = split;
        } else *bestLink = next;
        *(u8 **)(freeNode + 8) = *(u8 **)(head + 0xC);
        *(u8 **)(head + 0xC) = freeNode;
        result = freeNode + align + 1;
    }
    if (result == 0 && head[0] != 0) fn_802E317C(lbl_8034BB28);
    return result;
}

void fn_802E0D44(u32 size) {
    u8 *head = (u8 *)lbl_8055FEE8;
    u8 **link = (u8 **)(head + 0xC);
    u8 *block = (u8 *)(size - (*(u32 *)(head + 4) + 1));
    u8 *node;
    u8 **a;
    u8 **b;
    u32 align = *(u32 *)(head + 4);
    u32 merged = 0;
    while ((node = *link) != 0) {
        if (node == block) { *link = *(u8 **)(block + 8); break; }
        link = (u8 **)(node + 8);
    }
    *(u8 **)(block + 8) = *(u8 **)(head + 8);
    *(u8 **)(head + 8) = block;
    a = (u8 **)(head + 8);
    do {
        b = (u8 **)(head + 8);
        merged = 0;
        while (*b != 0) {
            u8 *x = *a;
            u8 *y = *b;
            u32 sx = *(u32 *)(x + 4);
            u32 sy = *(u32 *)(y + 4);
            if (x + sx + align + 1 == y || y + sy + align + 1 == x) {
                u8 **first = a;
                u8 **second = b;
                if (y + sy + align + 1 == x) { first = b; second = a; }
                *(u32 *)(*first + 4) = (*(u32 *)(*first + 4) + *(u32 *)(*second + 4) + ((align + 0x10) & ~align));
                *second = *(u8 **)(*second + 8);
                a = first;
                merged = 1;
                break;
            }
            b = (u8 **)(y + 8);
        }
        if (!merged) break;
    } while (1);
}

#pragma dont_inline reset
void fn_802E1290(void *arg0) {
    extern void fn_802E30C8(const char *, ...);
    extern void *fn_802E0BA4(void);
    extern void fn_802E0BE0(void);
    extern void fn_802E0E60(void);
    extern char lbl_8034CBD0[];
    fn_802E30C8(lbl_8034CBD0, lbl_8034CBD0);
    ((void (*)(void *))fn_802E0BA4)(arg0);
    fn_802E0E60();
    ((void (*)(void *))fn_802E0BE0)(arg0);
}

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
extern void *fn_801284F8(u32, void *);
extern void fn_80118DC0(void *);
extern void fn_802E1728(void *);
extern void fn_801282F4(void);
extern void fn_8011A168(void);
extern void *fn_802E0C04(u32);
extern void fn_802E0D44(u32);
extern char lbl_8034CBD0[];
extern u8 lbl_8055D150, lbl_8055D158, lbl_8055D160;
extern void *lbl_8055FEE8, *lbl_8055FEEC;
s32 fn_802E1718(void) { return 0; }

