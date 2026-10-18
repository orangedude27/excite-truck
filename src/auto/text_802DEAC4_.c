// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXTev.h>
extern void fn_802D3144(void);
extern void GXSetNumIndStages(u8);
extern void GXSetTevDirect(GXTevStageID);

void fn_802DEE1C(void) {
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetTevSwapMode(3, 0, 0);
    GXSetTevSwapMode(4, 0, 0);
}

void fn_802DEE88(void) {
    register u32 x = 1;
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

void fn_802DF21C(void) {
    register u32 x = 1;
    GXSetTexCoordGen2(0, x, 1, 0x2A, 0, 0x7D);
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

void fn_802DF46C(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
}

void fn_802DF684(void) {
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}

void fn_802DF938(void) {
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    GXSetTevSwapMode(2, 0, 0);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}

void fn_802DFCC0(void) {
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    fn_802D3144();
}

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

#pragma dont_inline on
void *fn_802E0BA4(void) {
}
#pragma dont_inline reset

void fn_802E0BE0(void) {
    fn_802E0BA4();
    fn_80128668();
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

