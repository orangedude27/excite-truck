// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXTev.h>
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

#pragma push
#pragma scheduling off
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
#pragma pop
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

#pragma push
#pragma scheduling off
void fn_802DF684(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}
#pragma pop
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

void fn_802E0B68(void) {
    volatile u32 stage = 0;
    GXSetTevSwapMode(stage, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
}

#pragma dont_inline on
void *fn_802E0BA4(void) {
}
#pragma dont_inline reset

void fn_802E0BE0(void) {
    fn_802E0BA4();
    fn_80128668();
}

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
extern void fn_802E0C04(void);
extern void fn_802E0D44(void);
extern char lbl_8034CBD0[];
extern u8 lbl_8055D150, lbl_8055D158, lbl_8055D160;
extern void *lbl_8055FEE8, *lbl_8055FEEC;
s32 fn_802E1718(void) { return 0; }

