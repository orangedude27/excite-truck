// cpulight - cpu lighting ("I only cpu-light from 8888 textures").
// Recovered TU window 0x802DB2D4..0x802DD430+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802DD430 (+ .ctors slot 0x802ED5DC) remains in
// auto/text_802DD430_.c pending a promotion pass.
#include "revolution/GX/GXHardware.h"
extern void GXSetAlphaCompare(int, unsigned char, int, unsigned char, int);
extern void fn_802CADD0(int, int);
extern void fn_802DFB30(void);
extern void *lbl_8055FEB4;
extern unsigned char lbl_8055FEB0, lbl_8055FEB9, lbl_8055FEBB, lbl_8055FD24;
extern unsigned char lbl_804DB480[];
extern void fn_802D0610(int);
extern void drawFifoTriangles(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetNumChans(int);
extern void GXSetChanCtrl(int, int, int, int, int, int, int);
extern unsigned char lbl_8055FEB8;
extern double lbl_80565058, lbl_80565070;
extern float lbl_80565050, lbl_80565060, lbl_80565064, lbl_80565068, lbl_80565078;
extern void GXSetNumTexGens(unsigned char);
extern void GXSetNumTevStages(unsigned char);
extern double fn_8002F208(double);
extern double fn_8002EFBC(double, double);
extern double ceil(double);
extern double __fabs(double);
extern void fn_802D3DF8(int, int, float, float);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct { unsigned char r, g, b, a; } fn_802DCAE4_GXColor;
extern void GXSetTevKColor(int, fn_802DCAE4_GXColor);

extern unsigned char lbl_8055FEC0;
extern int lbl_8055FD30;
extern void fn_802D3360(void);
extern void GXSetTevKAlphaSel(int, int);
extern void GXSetBlendMode(int, int, int, int);
extern unsigned char lbl_8055FEBA, lbl_8055FEB8;
extern signed char gCpuLightTexDirty;
extern int lbl_8055FEA0, lbl_8055FEA4;
#pragma push
#pragma small_data off
extern void *lbl_804DB468[];
#pragma pop
extern void *fn_802D94DC(void);
extern void *lbl_8055FEA8;
extern void *lbl_8055FEAC;
extern void GXLoadTexMtxImm(float *, unsigned int, unsigned char);
extern void GXLoadTexObj(void *, int);
extern float lbl_8055D148;
extern float lbl_80565040, lbl_80565044, lbl_80565048, lbl_8056504C;
extern unsigned char lbl_804DB068[];
extern unsigned char lbl_802FACF8[];
extern unsigned char lbl_802FACD8[];
extern unsigned char lbl_8055FEB0, lbl_8055FD24;
#pragma scheduling invalid_target
/* Clear the blend-override flag, copy the first bound texture's alpha-reference byte
 * (offset 0xE4) into lbl_8055FD24, and set GX alpha compare to pass alpha > reference. */
void fn_802DB2D4(void) {
    lbl_8055FEB0 = 0;
    lbl_8055FD24 = ((unsigned char *)lbl_804DB468[0])[0xE4];
    GXSetAlphaCompare(4, ((unsigned char *)lbl_804DB468[0])[0xE4], 1, 0, 0);
}

void fn_802DB304(void *dest, int mode) {
    /* Copy 1, 2, or 3 texture object pointers from lbl_804DB468 into dest based on mode (0, 2, or 1). */
    void **dst = (void **)dest;

    switch (mode) {
    case 0:
        dst[0] = lbl_804DB468[0];
        return;
    case 2:
        dst[0] = lbl_804DB468[0];
        dst[1] = lbl_804DB468[1];
        return;
    case 1:
        dst[0] = lbl_804DB468[0];
        dst[1] = lbl_804DB468[1];
        dst[2] = lbl_804DB468[2];
        return;
    }
}

#pragma scheduling on
int fn_802DB378(int mode, int textureIndex) {
    /* TEV color input for GXSetTevOrder: GX_COLOR0A0 (4) for the first texture in mode 2, else GX_COLOR_NULL (0xFF). */
    int color = 0xFF;
    if (mode == 2) {
        if (textureIndex == 0) color = 4;
    }
    return color;
}

void fn_802DB394(void) {
    /* Configure a simple 2-stage TEV setup: stages 0 and 1 modulate, stage 1 passes alpha through. */
    GXSetTevOp(0, 3);
    GXSetTevOp(1, 3);
    GXSetTevAlphaOp(1, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(1, 0, 7, 7, 7);
}

#pragma push
#pragma processor 750
/* Sets up the four TEV stages of CPU-light draw mode 1: stage 0 replaces the
 * colour, stage 1 passes it through taking alpha from the texture, stage 2
 * modulates, and stage 3 passes colour through with alpha from APREV and TEXA. */
void fn_802DB3FC(void) {
    GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GXSetTevOp(GX_TEVSTAGE1, GX_PASSCLR);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevOp(GX_TEVSTAGE2, GX_MODULATE);
    GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_APREV, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevOp(GX_TEVSTAGE3, GX_PASSCLR);
    GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_APREV, GX_CA_TEXA, GX_CA_ZERO);
}
#pragma push
#pragma scheduling on
void fn_802DB4E4(void) {
    /* Build the CPU-light pass's two 2x4 texture matrices from the global light
     * parameter block and load them into GX_TEXMTX0 and GX_TEXMTX1: TEXMTX0 takes
     * its U/V terms from params[3]/params[4], TEXMTX1 from params[6]/params[7],
     * and every other matrix entry is zero. */
    int texMtx[16];
    float *params = (float *)lbl_804DB068;
    texMtx[8] = 0;
    texMtx[14] = 0;
    texMtx[0] = 0;
    texMtx[6] = 0;
    texMtx[9] = 0;
    texMtx[10] = 0;
    texMtx[11] = 0;
    texMtx[12] = 0;
    texMtx[13] = 0;
    texMtx[15] = 0;
    *(float *)&texMtx[8] = params[3];
    *(float *)&texMtx[14] = params[4];
    texMtx[1] = 0;
    texMtx[2] = 0;
    texMtx[3] = 0;
    texMtx[4] = 0;
    texMtx[5] = 0;
    texMtx[7] = 0;
    *(float *)&texMtx[0] = params[6];
    *(float *)&texMtx[6] = params[7];
    GXLoadTexMtxImm((float *)texMtx + 8, GX_TEXMTX0, GX_MTX_2x4);
    GXLoadTexMtxImm((float *)texMtx, GX_TEXMTX1, GX_MTX_2x4);
}
#pragma pop
/* Load texture matrix 0x1E (GX_MTX2x4): copy the 8-word template from lbl_802FACD8 into a scratch matrix, overwrite X/Y scale entries with lbl_804DB068[3], and upload it with GXLoadTexMtxImm. */ void fn_802DB58C(void) {
    /* Load texture matrix 0x1E (GX_MTX2x4) from the lbl_802FACD8 template, scaling X/Y by lbl_804DB068[3]. */
    int texMtx[8];
    int *texMtxTemplate = (int *)lbl_802FACD8;
    float *texParams = (float *)lbl_804DB068;
    texMtx[0] = texMtxTemplate[0]; texMtx[1] = texMtxTemplate[1]; texMtx[2] = texMtxTemplate[2]; texMtx[3] = texMtxTemplate[3];
    texMtx[4] = texMtxTemplate[4]; texMtx[5] = texMtxTemplate[5]; texMtx[6] = texMtxTemplate[6]; texMtx[7] = texMtxTemplate[7];
    *(float *)&texMtx[0] = texParams[3];
    *(float *)&texMtx[6] = texParams[3];
    GXLoadTexMtxImm((float *)texMtx, 0x1e, 1);
}
#pragma scheduling on
/* Load texture matrix 0x1E (GX_MTX2x4) from the lbl_802FACF8 template (translation 0.5, 0.5), setting X/Y scale to lbl_8055D148 (1.0f). */
/* Load texture matrix 0x1E (GX_MTX2x4) from the lbl_802FACF8 template (translation 0.5, 0.5), setting X/Y scale to lbl_8055D148 (1.0f). */ void CpuLight_LoadTexMtx0(void) {
    int texMtx[8];
    int *texMtxTemplate = (int *)lbl_802FACF8;

    texMtx[0] = texMtxTemplate[0];
    texMtx[1] = texMtxTemplate[1];
    texMtx[2] = texMtxTemplate[2];
    texMtx[3] = texMtxTemplate[3];
    texMtx[4] = texMtxTemplate[4];
    texMtx[5] = texMtxTemplate[5];
    texMtx[6] = texMtxTemplate[6];
    texMtx[7] = texMtxTemplate[7];
    *(float *)&texMtx[0] = lbl_8055D148;
    *(float *)&texMtx[6] = lbl_8055D148;
    GXLoadTexMtxImm((float *)texMtx, 0x1e, 1);
}
#pragma dont_inline on
#pragma use_lmw_stmw off
/* Load each active texture object into GX and assign TEV stages: one stage per texture, plus an extra stage for textures carrying a second map. Returns the number of TEV stages configured. */
int fn_802DB69C(void **texObjs, int mode) {
    extern int lbl_8055FEA4;
    extern void GXLoadTexObj(void *, int);
    extern void GXSetTevOrder(int, int, int, int);
    extern void GXSetNumTexGens(unsigned char);
    void **objIter = texObjs;
    int tevStage = 0;
    int nextTexMap = 0;
    unsigned char *texObj;
    int texIndex = 0;
    while (texIndex < lbl_8055FEA4) {
        int baseTexMap;
        unsigned char *baseTexObj;
        texObj = *objIter;
        baseTexMap = nextTexMap;
        baseTexObj = texObj + 0x24;
        nextTexMap = baseTexMap + 1;
        GXLoadTexObj(baseTexObj, baseTexMap);
        if (texObj[0xCC]) {
            int extraTexMap = nextTexMap++;
            GXLoadTexObj(texObj + 0x78, extraTexMap);
            GXSetTevOrder(tevStage++, texIndex, extraTexMap, GX_COLOR_NULL);
        }
        {
            int curTevStage = tevStage++;
            GXSetTevOrder(curTevStage, texIndex, baseTexMap, fn_802DB378(mode, texIndex));
        }
        objIter++;
        texIndex++;
    }
    GXSetNumTexGens((unsigned char)lbl_8055FEA4);
    return tevStage;
}

// Re-applies this module's GX pipeline for one of its three draw modes, and only
// when the mode's textures changed: the flag is raised by the texture setters
// (fn_802DBD88 / fn_802DBDE8) and cleared here, and each draw entry point calls
// this for its mode right before sending its display list. It sets the alpha
// compare from the texture entry, loads the mode's textures with their TEV order
// (returning how many TEV stages that needs), picks the TEV stages and the
// texture coordinate generation of the mode, and blends on the source alpha.
/* Re-applies this module's GX pipeline for one of three draw modes, but only when the texture-changed flag (raised by the texture setters, cleared here) is set: sets alpha compare from the bound texture, loads the mode's textures with TEV order, selects the mode's TEV stages and texture-coordinate generation, and blends on source alpha. */ void cpulightSetupGxForMode(int mode) {
    void *texObjs[3];
    int numTevStages;

    if ((unsigned char)gCpuLightTexDirty != 0) {
        gCpuLightTexDirty = 0;
        fn_802DB2D4();
        fn_802DB304(texObjs, mode);
        numTevStages = fn_802DB69C(texObjs, mode);
        switch (mode) {
        case 0:
            fn_802DB394();
            break;
        case 1:
            fn_802DB3FC();
            break;
        case 2:
            // stage 0: the texture modulated by the vertex colour, alpha from the vertex
            GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
            GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
            GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            if (numTevStages >= 2) {
                // stage 1: keep the previous colour where the second texture is lit
                GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_COMP_R8_GT, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
                GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_C1, GX_CC_TEXC, GX_CC_A1, GX_CC_CPREV);
                GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_ENABLE, GX_TEVPREV);
                GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_APREV, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
            }
            break;
        }
        GXSetNumTevStages((unsigned char)numTevStages);
        switch (mode) {
        case 0:
            GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
            break;
        case 1:
            GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX2, GX_FALSE, GX_PTIDENTITY);
            GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
            GXSetTexCoordGen2(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX2, GX_FALSE, GX_PTIDENTITY);
            break;
        case 2:
            CpuLight_LoadTexMtx0();
            GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
            GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
            break;
        }
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
    }
}

void fn_802DB9DC(int replaceFramebuffer) {
    /* Skip blend setup in the second lighting mode (lbl_8055FEBA); otherwise use
     * alpha blending that replaces the framebuffer for the lowest light of a
     * chain (dst=ZERO) and adds to it for every other light (dst=ONE). */
    if (lbl_8055FEBA != 0)
        return;
    if (replaceFramebuffer != 0) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ZERO, GX_LO_NOOP);
    } else {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_NOOP);
    }
}

/* Sets up GX for one batch of CPU-lit billboards and picks the pipeline for it.

 * The two 2x4 texture matrices of the light pass are copied out of the read-only
 * matrix pair and loaded into GX_TEXMTX2 and GX_TEXMTX3 (fn_802DB4E4 loads the
 * GX_TEXMTX0/GX_TEXMTX1 pair next to them), the alpha compare is set to always
 * pass, and then one of the two texture sets of lbl_804DB468 is bound to texmaps
 * 0-4: each entry is a texture wrapper whose first GXTexObj sits at +0x24 and
 * whose second one at +0x78. The first lighting mode binds the plain textures and
 * installs GXSetupFiveStageTevPipelineA; the second mode (lbl_8055FEBA) binds the
 * set that includes the two extra textures, installs
 * GXSetupFiveStageTevPipelineB and turns the Z test off, because that mode
 * replays the batch a second time with colour writes off to fill the Z buffer. */
void fn_802DBA1C(unsigned char secondMode) {
    extern unsigned char lbl_802FAD18[];   /* the light pass's 2x4 matrix, GX_TEXMTX2 */
    extern unsigned char lbl_802FAD38[];   /* the light pass's 2x4 matrix, GX_TEXMTX3 */
    extern void *lbl_804DB468[];           /* the light pass's textures: GXTexObj at +0x24, a second at +0x78 */
    extern void GXSetupFiveStageTevPipelineA(void);
    extern void GXSetupFiveStageTevPipelineB(void);
    int texMtx2[8];
    int texMtx3[8];
    int *mtxSrc;
    int i;

    mtxSrc = (int *)lbl_802FAD18;
    for (i = 0; i < 8; i++)
        texMtx2[i] = mtxSrc[i];
    GXLoadTexMtxImm((float *)texMtx2, GX_TEXMTX2, 1 /* GX_MTX2x4_TB */);

    mtxSrc = (int *)lbl_802FAD38;
    for (i = 0; i < 8; i++)
        texMtx3[i] = mtxSrc[i];
    GXLoadTexMtxImm((float *)texMtx3, GX_TEXMTX3, 1 /* GX_MTX2x4_TB */);

    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
    fn_802DB4E4();
    if (secondMode == 0) {
        GXLoadTexObj((unsigned char *)lbl_804DB468[0] + 0x24, GX_TEXMAP0);
        GXLoadTexObj((unsigned char *)lbl_804DB468[1] + 0x24, GX_TEXMAP1);
        GXLoadTexObj((unsigned char *)lbl_804DB468[2] + 0x24, GX_TEXMAP2);
        GXLoadTexObj((unsigned char *)lbl_804DB468[2] + 0x78, GX_TEXMAP3);
        GXLoadTexObj((unsigned char *)lbl_804DB468[3] + 0x24, GX_TEXMAP4);
        GXSetupFiveStageTevPipelineA();
    } else {
        GXLoadTexObj((unsigned char *)lbl_804DB468[0] + 0x24, GX_TEXMAP0);
        GXLoadTexObj((unsigned char *)lbl_804DB468[1] + 0x24, GX_TEXMAP1);
        GXLoadTexObj((unsigned char *)lbl_804DB468[1] + 0x78, GX_TEXMAP2);
        GXLoadTexObj((unsigned char *)lbl_804DB468[2] + 0x24, GX_TEXMAP3);
        GXLoadTexObj((unsigned char *)lbl_804DB468[2] + 0x78, GX_TEXMAP4);
        GXSetupFiveStageTevPipelineB();
        GXSetZMode(GX_DISABLE, GX_ALWAYS, GX_DISABLE);
    }
}

#pragma dont_inline reset
#pragma use_lmw_stmw on

/* Bind the CPU-light position vertex array: when the cached buffer changes, reset the vertex descriptor, set GX attribute 9 to three floats, point GX at the buffer and flush it from the data cache. */
void fn_802DBBE4(int positionArray, int vertexCount) {
    if ((void *)lbl_8055FEA8 != (void *)positionArray) {
        lbl_8055FEA8 = (void *)positionArray;
        lbl_8055FEAC = (void *)vertexCount;
        GXClearVtxDesc();
        GXSetVtxDesc(9, 3);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetArray(9, (void *)positionArray, 0xC);
        DCFlushRange((void *)positionArray, vertexCount * 0xC);
    }
}

extern void fn_802DBC70(int,int);
/* Sets up GX position vertex array (vtx attr 9, 3 floats, index mode) for the given
 * vertex buffer and flushes it from data cache when the cached buffer changes. */
/* Configure GX to draw the indexed position array for the mode-1 CPU-light pass, but only when the cached array pointer changes; then flush its vertex data from the data cache. */ /* Configure GX to draw the indexed position array for the mode-1 CPU-light pass, but only when the cached array pointer changes; then flush its vertex data from the data cache. */ /* Configure GX to draw the indexed position array for the mode-1 CPU-light pass, but only when the cached array pointer changes; then flush its vertex data from the data cache. */ void fn_802DBC70(int positionArray, int vertexCount) {
    if ((void *)lbl_8055FEA8 != (void *)positionArray) {
        lbl_8055FEA8 = (void *)positionArray;
        lbl_8055FEAC = (void *)vertexCount;
        GXClearVtxDesc();
        GXSetVtxDesc(9, 3);
        GXSetVtxAttrFmt(0, 9, 1, 4, 0);
        GXSetArray(9, (void *)positionArray, 0xC);
        DCFlushRange((void *)positionArray, vertexCount * 0xC);
    }
}

extern void fn_802DBCFC(int,int);
/* Sets up the GX position vertex array (GX_VA_POS, XYZ floats, GX_INDEX16) when the
 * cached buffer changes, then flushes the new buffer from the data cache. */
void fn_802DBCFC(int positionArray, int vertexCount) {
    if ((void *)lbl_8055FEA8 != (void *)positionArray) {
        lbl_8055FEA8 = (void *)positionArray;
        lbl_8055FEAC = (void *)vertexCount;
        GXClearVtxDesc();
        GXSetVtxDesc(GX_VA_POS, GX_INDEX16);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetArray(GX_VA_POS, (void *)positionArray, 0xC);
        DCFlushRange((void *)positionArray, vertexCount * 0xC);
    }
}

#pragma push
#pragma small_data off
/* Reset CPU-light GX vertex array cache/state and bind the default texture object. */
void fn_802DBD88(void) {
    void *defaultTex;
    void **texSlots;
    lbl_8055FEA8 = 0;
    lbl_8055FEAC = 0;
    gCpuLightTexDirty = 1;
    lbl_8055FEA0 = -1;
    defaultTex = fn_802D94DC();
    lbl_8055FEA4 = 1;
    texSlots = (void **)&lbl_804DB468;
    *texSlots = defaultTex;
}
#pragma pop
/* Cached GX position vertex array: the buffer pointer and the vertex count. */
#define sCachedPositionArray lbl_8055FEA8
#define sCachedVertexCount   lbl_8055FEAC
void fn_802DBDD8(void) {
    // Invalidate the cached GX position vertex array so the next setup call reconfigures it.
    sCachedPositionArray = 0;
    sCachedVertexCount = 0;
}

#pragma scheduling off
void fn_802DBDE8(int arg0, void *arg1) {
    int count;
    void **entry;
    int oldCount;
    unsigned int value;

    if (arg1 != 0) {
        oldCount = *(int *)((char *)arg1 + 0xF0);
        value = lbl_8055FD30;
        *(int *)((char *)arg1 + 0xF0) = oldCount + 1;
        *(int *)((char *)arg1 + 0xEC) = value;
    }
    entry = lbl_804DB468;
    lbl_804DB468[arg0] = arg1;
    count = 0;
    lbl_8055FEA4 = count;
    while (count < 3 && entry[0] != 0) {
        count++;
        lbl_8055FEA4 = count;
        entry++;
    }
    gCpuLightTexDirty = 1;
}

#pragma scheduling invalid_target
void fn_802DBE4C(void) {
    unsigned char one;
    fn_802D0610(0);
    drawFifoTriangles(0, 0, 0, 0);
    one = 1;
    GXSetZMode(one, 3, one);
    GXSetNumChans(one);
    GXSetChanCtrl(4, 0, one, one, 0, 0, 2);
    lbl_8055FEB8 = one;
}
#pragma scheduling on

#pragma scheduling on
void fn_802DBECC(void) {
    /* Disable CPU lighting: reinitialize the GX/TEV render state, reset TEV stage 0's K-alpha select, and clear the CPU-lighting enabled flag. */
    fn_802D3360();
    GXSetTevKAlphaSel(0, 0);
    lbl_8055FEB8 = 0;
}

#pragma dont_inline on
/* Reset the CPU-light GX vertex-array/pipeline state, then set the current lighting mode byte (lbl_8055FEBA). */
void fn_802DBF00(signed char lightMode) {
    fn_802DBD88();
    lbl_8055FEBA = lightMode;
}
#pragma dont_inline reset
typedef unsigned char u8;
extern void fn_802DBDD8(void);
extern void fn_802DEE1C(void);
extern void fn_802DBD88(void);
extern void fn_802D3360(void);
extern void GXSetTevKAlphaSel(int, int);
extern void fn_802D0610(int);
extern void drawFifoTriangles(int, int, int, int);
extern void GXSetZMode(int, int, int);
extern void GXSetNumChans(int);
extern void GXSetChanCtrl(int, int, int, int, int, int, int);
extern u8 lbl_8055FEBA;
extern u8 lbl_8055FEB8;
extern int lbl_8055FD30, lbl_8055FEA4;
extern signed char gCpuLightTexDirty;
extern int lbl_8055FEA0;
extern void *lbl_8055FEA8, *lbl_8055FEAC;
extern void *fn_802D94DC(void);
extern void fn_802DBA1C(unsigned char);
extern void fn_802DB9DC(int);
extern void fn_802DBBE4(int,int);
extern void fn_802DBF54(unsigned short *__restrict, int);
extern void GXSetColorUpdate(int);
extern void GXSetZMode(int,int,int);
extern unsigned char lbl_8055FEBA;
#pragma dont_inline on
/* Reset per-frame render state: clear the CPU light tracking pointers
   (fn_802DBDD8) and restore all TEV swap-mode selectors to their defaults
   (fn_802DEE1C). */
void fn_802DBF30(void) {
    fn_802DBDD8();
    fn_802DEE1C();
}

extern void GXBegin(int, int, unsigned short);
#pragma processor 750
#pragma use_lmw_stmw off
/* Replay a packed triangle-fan index list into the GX FIFO, one packet of an index count followed by that many u16 vertex indices at a time. */ void fn_802DBF54(unsigned short *__restrict list, int entryCount) {
    /* Replay a packed triangle-fan index list into the GX FIFO: each packet
       starts with its index count, followed by that many u16 vertex indices. */
    int packetSize;
    int i;
    volatile unsigned short *fifo = (volatile unsigned short *)0xCC008000;
    while (entryCount > 0) {
        packetSize = *list++;
        GXBegin(GX_TRIANGLEFAN, 0, packetSize);
        entryCount -= packetSize + 1;
        for (i = 0; i < packetSize; i++) {
            unsigned short vertexIndex = *list++;
            *fifo = vertexIndex;
        }
    }
}
#pragma push
#pragma use_lmw_stmw off
/* Draws one batch of CPU-lit billboards (a light's triangle-fan display list)
 * with the current lighting mode: applies the mode's texture and TEV setup, the
 * blend mode, points GX at the batch's position array and replays the list into
 * the FIFO.  `first` is the lowest light of a chain, which replaces the
 * framebuffer instead of adding to it; the light index is passed in unused.
 * In the second mode (lbl_8055FEBA) the list is replayed once more with colour
 * writes off and the Z test and Z write on, so the batch also fills the Z
 * buffer it was blended over. */
/* DrawLitBillboardBatch: apply the lighting pipeline, blend mode and position array for one batch, then replay its triangle-fan list; in the second mode replay it again with color writes off to fill the Z buffer. */ void fn_802DC078(void* positions, s32 posCount, u16* list, s32 size, s32 first,
                 s32 light) {
    fn_802DBA1C(lbl_8055FEBA);
    fn_802DB9DC(first);
    fn_802DBBE4((int)positions, posCount);
    fn_802DBF54(list, size);
    if (lbl_8055FEBA != 0) {
        GXSetZMode(GX_ENABLE, GX_LEQUAL, GX_ENABLE);
        GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
        GXSetColorUpdate(GX_DISABLE);
        fn_802DBF54(list, size);
        GXSetColorUpdate(GX_ENABLE);
    }
}
#pragma pop
extern void GXSetBlendMode(int, int, int, int);
/* Forwarder: resets the CPU-light GX vertex-array cache and binds the default texture (fn_802DBD88). */
void fn_802DC130(void) {
    fn_802DBD88();
}

/* Forwarder: invalidate the cached GX position array/vertex count so the next
   setup reconfigures it (fn_802DBDD8). */
void fn_802DC134(void) {
    fn_802DBDD8();
}

/* Submit indexed GX triangle-fan primitives (mode 0): apply the mode 0 CPU-light
   state and position array, then for each run in the index list read its length,
   begin a fan of that many indices, and stream the indices to the GP FIFO. */
void fn_802DC138(int positionArray, int vertexCount, unsigned short *__restrict indexList, int indexListSize) {
    int runLength;
    int idx;
    volatile unsigned short *fifo = (volatile unsigned short *)0xCC008000;
    cpulightSetupGxForMode(0);
    fn_802DBCFC(positionArray, vertexCount);
    while (indexListSize > 0) {
        runLength = *indexList;
        indexList++;
        GXBegin(0xA0, 0, runLength);
        indexListSize -= runLength + 1;
        #pragma unroll 8
        for (idx = 0; idx < runLength; idx++, indexList++) {
            *fifo = *indexList;
        }
    }
}

/* Forwarder: resets the CPU-light GX vertex-array cache and binds the default texture (same as fn_802DC130). */
void fn_802DC278(void) { fn_802DBD88(); }

/* Forwarder: invalidates the cached GX position array/vertex count so the next setup reconfigures it (same as fn_802DC134). */
void fn_802DC27C(void) { fn_802DBDD8(); }

#pragma push
#pragma use_lmw_stmw off
/* Submit indexed GX triangle-fan primitives (mode 1): apply the mode 1 CPU-light
   state and position array, then for each run in the index list read its length,
   begin a fan of that many indices, and stream the indices to the GP FIFO. */
void fn_802DC280(int positionArray, int vertexCount, unsigned short *__restrict indexList, int indexListSize) {
    int runLength;
    int idx;
    volatile unsigned short *fifo = (volatile unsigned short *)0xCC008000;

    cpulightSetupGxForMode(1);
    fn_802DBC70(positionArray, vertexCount);
    while (indexListSize > 0) {
        runLength = *indexList;
        indexList++;
        GXBegin(0xA0, 0, runLength);
        indexListSize -= runLength + 1;
        #pragma unroll 8
        for (idx = 0; idx < runLength; idx++, indexList++) {
            *fifo = *indexList;
        }
    }
}

/* Prepare cpulight draw state for the given light mode: reset the cached GX state and texture matrix,
   bind the mode's texture to unit 1, load the two CPU-light textures into texmaps 0 and 1, set the
   alpha compare to always-pass, and configure the two-stage TEV/blend pipeline. */
void fn_802DC3C0(int mode) {
    fn_802DBD88();
    fn_802DB58C();
    fn_802CADD0(mode, 1);
    GXLoadTexObj((unsigned char *)lbl_804DB468[0] + 0x24, GX_TEXMAP0);
    GXLoadTexObj((unsigned char *)lbl_804DB468[1] + 0x24, GX_TEXMAP1);
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
    fn_802DFB30();
}

#pragma pop

extern void fn_802DFCC0(void);
extern int GXGetTexObjMipMap(void *);
extern unsigned short GXGetTexObjWrapS(void *);
extern int GXGetTexObjFmt(void *);
extern void fn_802E317C(const char *);
extern char lbl_8034CB00[];
extern char lbl_8034CB24[];
extern unsigned int lbl_8055FEBC;
  
void fn_802DC440(void) {
#define CpuLight_ClearState fn_802DBDD8
    /* Clear the CPU-light state, then restore the video TEV swap/blend setup. */
    ((void (*)(void))CpuLight_ClearState)();
    fn_802DFCC0();
#undef CpuLight_ClearState
}

extern float lbl_80565040, lbl_80565044, lbl_80565048;
extern void GXSetTevColor();
/* fn_802DC464 (intended name CpuLight_DrawFadeFans; rename_symbol is currently refused
 * project-wide): draws an indexed triangle-fan overlay with a cpu-light fade alpha. */
#define CpuLight_SetPositionArray fn_802DBBE4
#define CpuLight_AlphaScale lbl_80565040 /* 255.0f */
#define CpuLight_RoundHalf lbl_80565044  /* 0.5f */
#define CpuLight_Zero lbl_80565048       /* 0.0f */
#define CpuLight_CachedTevAlpha lbl_8055FEA0
/* Float 5 of the global cpu-light parameter block lbl_804DB068 (the same falloff
 * scale the surf shading uses): current light strength in 0..1. */
#define CpuLight_FadeScale (((float *)lbl_804DB068)[5])
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802DC464(int positionArray, int vertexCount, unsigned short *__restrict indexList, int indexListSize) {
    /* Point the GX position array at `positionArray` (vertexCount xyz vertices), fade TEV
     * colour 1 to round(255 * CpuLight_FadeScale) clamped to 0..255 (only when that byte
     * changed since the last call), then push every [count, index...] run of `indexList`
     * to the GP FIFO as a GX triangle fan until indexListSize words have been written. */
    float fadeFactor;
    float scaledAlpha;
    float roundedAlpha;
    int alpha;
    int positiveMask;
    int positiveAlpha;
    int roundedInt;
    unsigned char alphaByte;
    GXColor color;
    int indexCount;
    int i;
    unsigned short vertexIndex;
    volatile unsigned short *fifo = (volatile unsigned short *)GXFIFO_ADDR;
    CpuLight_SetPositionArray(positionArray, vertexCount);
    fadeFactor = CpuLight_FadeScale;
    scaledAlpha = CpuLight_AlphaScale * fadeFactor;
    if (scaledAlpha < CpuLight_Zero)
        roundedAlpha = scaledAlpha - CpuLight_RoundHalf;
    else
        roundedAlpha = CpuLight_RoundHalf + scaledAlpha;
    roundedInt = (int)roundedAlpha;
    positiveMask = -roundedInt & ~roundedInt;
    positiveMask >>= 31;
    positiveAlpha = roundedInt & positiveMask;
    alpha = 0xFF;
    if (positiveAlpha < 0xFF)
        alpha = positiveAlpha;
    alphaByte = (unsigned char)alpha;
    if (alphaByte != CpuLight_CachedTevAlpha) {
        color.b = 0xFF;
        color.g = 0xFF;
        color.r = 0xFF;
        color.a = alphaByte;
        CpuLight_CachedTevAlpha = alphaByte;
        GXSetTevColor(GX_TEVREG0, color);
    }
    while (indexListSize > 0) {
        indexCount = *indexList++;
        GXBegin(GX_TRIANGLEFAN, GX_VTXFMT0, indexCount);
        indexListSize -= indexCount + 1;
        for (i = 0; i < indexCount; ++i) {
            vertexIndex = *indexList++;
            *fifo = vertexIndex;
        }
    }
}
#pragma pop

void fn_802DC628(void) {
    /* No-op default lookup hook: returns without touching any register. */
}

#pragma push
#pragma small_data off
/* Validate the CPU-light source GX texture (mipmap count 6, S wrap 0x200) and cache its GX format, tagged with 0x80000000, for texel lookups. */ void fn_802DC62C(void) {
    volatile unsigned char *cpuLightTexObj = (volatile unsigned char *)*(void **)&lbl_804DB468;
    /* Validate CPU-light source texture (mipmap/wrap/size expectations) and cache its GX format for lookups. */
    if (GXGetTexObjMipMap((void *)(cpuLightTexObj + 0x24)) != 6)
        ((void (*)(const char *, ...))fn_802E317C)(lbl_8034CB00);
    if (GXGetTexObjWrapS((void *)(cpuLightTexObj + 0x24)) != 0x200)
        ((void (*)(const char *, ...))fn_802E317C)(lbl_8034CB24);
    lbl_8055FEBC = GXGetTexObjFmt((void *)(cpuLightTexObj + 0x24)) + 0x80000000;
}
#pragma pop
extern int GXGetTexObjMipMap(void *);
extern unsigned short GXGetTexObjWrapS(void *);
extern int GXGetTexObjFmt(void *);
extern void fn_802E317C(const char *);
extern char lbl_8034CB00[];
extern char lbl_8034CB24[];
extern unsigned int lbl_8055FEBC;
extern unsigned int lbl_8055FEBC;
/* CpuLightSampleTexelPair: sample two adjacent 16-bit texels from the CPU-light texture at (x,y) in texel units, returning (texel[x,y+1] | texel[x,y] << 16). gCpuLightTexBase (lbl_8055FEBC) is the GX texture data base cached by fn_802DC62C. */
int fn_802DC6AC(int a, unsigned int b) {
#define gCpuLightTexBase lbl_8055FEBC
    int row = a / 4;
    int col = (int)b / 4;
    int x = a % 4;
    int y = (int)b % 4;
    int index = ((x + (y << 2)) << 4) / 8;
    char *tile = (char *)gCpuLightTexBase + (row + (col << 7)) * 64 + index;
    int result = *(unsigned short *)(tile + 32) | ((unsigned int)*(unsigned short *)tile << 16);
#undef gCpuLightTexBase
    return result;
}

extern void fn_802CADD0(int, int);
extern void GXLoadPosMtxImm(float (*)[4], unsigned int);
extern void GXCallDisplayList(void *, unsigned int);
extern void PSMTXScale(float (*)[4], float, float, float);
extern int fn_802CFF64();
extern void fn_802D0E48(int);
extern void fn_802D2ED8(int, int);
extern void fn_802D2F70(int);
extern void fn_802D3D94(void *, int);
extern void fn_802D6B54(void *);
extern void fn_802D6B78(void *);
extern void fn_802D6B7C(void *);
extern void buildViewXform(void);
extern void GXSetupThreeStageTevPipelineAlt(void);
extern void fn_802E009C(void);
extern void fn_802E050C(void);
extern void fn_802E0420(void);
extern void GXSetupThreeStageTevPipeline(void);
extern void fn_802DFD00(void);
extern int __cntlzw(unsigned int);
#pragma scheduling invalid_target
#pragma push
#pragma optimization_level 3
#pragma cplusplus on
extern "C" void fn_802DC71C(int arg0, int arg1) {
    extern void GXLoadTexObj(void *, int);
    register int useAlt;
    void **base;
    void *tex1;
    int texFlag;
    void *info;
    int wrapS;
    fn_802DBD88();
    lbl_8055FEB4 = 0;
    fn_802CADD0(arg1, 1);
    buildViewXform();
    base = lbl_804DB468;
    tex1 = base[1];
    useAlt = *((unsigned char *)tex1 + 0xCC);
    info = ((void *(*)(int))fn_802DC628)(arg0);
    texFlag = *((unsigned char *)info + 8);
    *(bool *)&lbl_8055FEBB = (texFlag == 0x1D);
    wrapS = GXGetTexObjWrapS((unsigned char *)base[0] + 0x24);
    *(bool *)&lbl_8055FEB9 = (wrapS == 0x200);
    GXLoadTexObj((unsigned char *)base[0] + 0x24, 0);
    GXLoadTexObj((unsigned char *)tex1 + 0x24, 1);
    if (useAlt != 0) GXLoadTexObj((unsigned char *)tex1 + 0x78, 2);
    if (lbl_8055FEBB != 0) {
        if (useAlt != 0) GXSetupThreeStageTevPipelineAlt();
        else fn_802E009C();
        lbl_8055FEB0 = 0;
    } else {
        if (lbl_8055FEB9 != 0) {
            if (useAlt != 0) fn_802E050C();
            else fn_802E0420();
            fn_802DC62C();
        } else if (useAlt != 0) GXSetupThreeStageTevPipeline();
        else fn_802DFD00();
        lbl_8055FEB0 = (*(unsigned int *)((unsigned char *)tex1 + 0xE0) >> 3) & 1;
    }
    GXSetAlphaCompare(4, *((unsigned char *)tex1 + 0xE4), 1, 0, 0);
    lbl_8055FD24 = *((unsigned char *)tex1 + 0xE4);
    *(unsigned int *)(lbl_804DB480 + 4) = 0;
    *(unsigned int *)(lbl_804DB480 + 0x214) = 0;
    *(unsigned char *)(lbl_804DB480 + 0x218) = 1;
    GXSetBlendMode(1, 4, 5, 5);
}
#pragma pop
#pragma cplusplus off
#pragma push
#pragma processor 750
void fn_802DC8B4(void) {
    unsigned int *colorOut;
    int byteOffset;
    float *coordOut;
    void *data;
    unsigned char *g;
    int i;
    int n;
    float *coords;
    unsigned int *colors;
    float matrix[3][4];
    float temp_f31;
    float temp_f30;
    float temp_f29;

    g = lbl_804DB480;
    if (*(int *)(g + 4) > 0) {
        colors = (unsigned int *)fn_802CFF64(0x28);
        coords = (float *)fn_802CFF64(0x50);
        if (colors != 0 && coords != 0) {
            if (*(unsigned char *)(g + 0x218) != 0)
                fn_802D6B54(*(void **)(g + 0x214));
            data = ((void *(*)(void *))fn_802DC628)(*(void **)(lbl_804DB480 + 0x214));
            n = *(int *)(lbl_804DB480 + 4);
            temp_f29 = lbl_80565040;
            colorOut = colors;
            temp_f30 = lbl_8056504C;
            temp_f31 = lbl_80565044;
            coordOut = coords;
            i = 0;
            byteOffset = 0;
            while (i < n) {
                unsigned char *r = *(unsigned char **)lbl_804DB480 + byteOffset;
                int v = (int)(temp_f29 * *(float *)(r + 0x30));
                int c = 0xFF;
                v = (unsigned char)v;
                v = v & ((-v & ~v) >> 31);
                if (v < 0xFF) c = v;
                *colorOut = 0xFFFFFF00U | (unsigned char)c;
                coordOut[0] = temp_f31 + *(float *)(r + 0x24) / temp_f30;
                coordOut[1] = temp_f31 + *(float *)(r + 0x2C) / temp_f30;
                fn_802D2ED8((int)r, i);
                byteOffset += 0x34;
                colorOut++;
                coordOut += 2;
                i++;
            }
            if (i < 10) {
                int mtxId;
                PSMTXScale(matrix, lbl_80565048, lbl_80565048, lbl_80565048);
                mtxId = i * 3;
                while (i < 10) {
                    GXLoadPosMtxImm(matrix, mtxId);
                    mtxId += 3;
                    i++;
                }
            }
            if (*(unsigned char *)(lbl_804DB480 + 0x218) != 0) {
                GXSetArray(9, *(void **)((unsigned char *)data + 0x20), 0xC);
                GXSetArray(0xD, *(void **)((unsigned char *)data + 0x28), 4);
            }
            GXSetArray(0xB, colors, 4);
            GXSetArray(0xE, coords, 8);
            GXCallDisplayList(*(void **)((unsigned char *)data + 0x30), *(unsigned int *)((unsigned char *)data + 0x2C));
            *(unsigned char *)(lbl_804DB480 + 0x218) = 0;
        }
        *(int *)(lbl_804DB480 + 4) = 0;
        *(void **)(lbl_804DB480 + 0x214) = 0;
    }
    fn_802CADD0(-1, 1);
    fn_802DBDD8();
}
#pragma pop

#pragma scheduling on
extern unsigned char lbl_8055FEB0, lbl_8055FEB9, lbl_8055FEBB;
extern void *lbl_8055FEB4;
extern float lbl_80565040, lbl_80565044, lbl_80565048, lbl_8056504C;
#pragma push
#pragma small_data off
extern unsigned char lbl_804DB480[];
#pragma optimization_level 3
void fn_802DCAE4(void *arg0, void *arg1, float farg0) {
    unsigned char *g;
    void *data;
    float *coordOut;
    unsigned int *colorOut;
    void *input;
    void *state;
    int byteOffset;
    int i;
    int n;
    float *coords;
    unsigned int *colors;
    float matrix[3][4];
    float temp_f31;
    float temp_f30;
    float temp_f29;
    float alpha;
    unsigned int count;
    unsigned int first;
    unsigned int *dstWords;
    unsigned int *srcWords;

    input = arg1;
    state = arg0;
    alpha = farg0;
    if (lbl_8055FEBB != 0) {
        g = lbl_804DB480;
        srcWords = (unsigned int *)input;
        first = srcWords[0];
        dstWords = *(unsigned int **)g;
        count = *(unsigned int *)(g + 4);
        *(void **)(g + 0x214) = state;
        dstWords += count * 0xD;
        *(int *)(g + 4) = count + 1;
        dstWords[0] = first;
        dstWords[1] = srcWords[1];
        dstWords[2] = srcWords[2];
        dstWords[3] = srcWords[3];
        dstWords[4] = srcWords[4];
        dstWords[5] = srcWords[5];
        dstWords[6] = srcWords[6];
        dstWords[7] = srcWords[7];
        dstWords[8] = srcWords[8];
        dstWords[9] = srcWords[9];
        dstWords[10] = srcWords[10];
        dstWords[11] = srcWords[11];
        *(float *)(dstWords + 12) = alpha;
        if (*(int *)(lbl_804DB480 + 4) + 1 > *(int *)(lbl_804DB480 + 8)) {
            colors = (unsigned int *)fn_802CFF64(0x28);
            coords = (float *)fn_802CFF64(0x50);
            if (colors != 0 && coords != 0) {
                if (*(unsigned char *)(lbl_804DB480 + 0x218) != 0)
                    fn_802D6B54(*(void **)(lbl_804DB480 + 0x214));
                data = ((void *(*)(void *))fn_802DC628)(*(void **)(lbl_804DB480 + 0x214));
                n = *(int *)(lbl_804DB480 + 4);
                temp_f29 = lbl_80565040;
                colorOut = colors;
                temp_f30 = lbl_8056504C;
                temp_f31 = lbl_80565044;
                coordOut = coords;
                i = 0;
                byteOffset = 0;
                while (i < n) {
                    unsigned char *r = *(unsigned char **)lbl_804DB480 + byteOffset;
                    int v = (int)(temp_f29 * *(float *)(r + 0x30));
                    int c = 0xFF;
                    v = (unsigned char)v;
                    v = v & ((-v & ~v) >> 31);
                    if (v < 0xFF) c = v;
                    *colorOut = 0xFFFFFF00U | (unsigned char)c;
                    coordOut[0] = temp_f31 + *(float *)(r + 0x24) / temp_f30;
                    coordOut[1] = temp_f31 + *(float *)(r + 0x2C) / temp_f30;
                    fn_802D2ED8((int)r, i);
                    byteOffset += 0x34;
                    colorOut++;
                    coordOut += 2;
                    i++;
                }
                if (i < 10) {
                    int mtxId;
                    PSMTXScale(matrix, lbl_80565048, lbl_80565048, lbl_80565048);
                    mtxId = i * 3;
                    while (i < 10) {
                        GXLoadPosMtxImm(matrix, mtxId);
                        mtxId += 3;
                        i++;
                    }
                }
                if (*(unsigned char *)(lbl_804DB480 + 0x218) != 0) {
                    GXSetArray(9, *(void **)((unsigned char *)data + 0x20), 0xC);
                    GXSetArray(0xD, *(void **)((unsigned char *)data + 0x28), 4);
                }
                GXSetArray(0xB, colors, 4);
                GXSetArray(0xE, coords, 8);
                GXCallDisplayList(*(void **)((unsigned char *)data + 0x30), *(unsigned int *)((unsigned char *)data + 0x2C));
                *(unsigned char *)(lbl_804DB480 + 0x218) = 0;
            }
            *(int *)(lbl_804DB480 + 4) = 0;
            *(void **)(lbl_804DB480 + 0x214) = 0;
        }
    } else {
        if (lbl_8055FEB9 != 0) {
            fn_802DCAE4_GXColor col;
            float t = lbl_80565040 * alpha;
            float rounded;
            int a;
            unsigned int pixel;
            if (t < lbl_80565048)
                rounded = t - lbl_80565044;
            else
                rounded = lbl_80565044 + t;
            a = 0xFF;
            {
                int raw = (int)rounded;
                int masked = raw & ((-raw & ~raw) >> 31);
                if (masked < 0xFF) a = masked;
            }
            pixel = fn_802DC6AC(((int)*(float *)((unsigned char *)input + 0x24) / 4) + 0x100,
                                ((int)*(float *)((unsigned char *)input + 0x2C) / 4) + 0x100);
            col.r = (unsigned char)(pixel >> 16);
            col.g = (unsigned char)(pixel >> 8);
            col.b = (unsigned char)pixel;
            col.a = a;
            GXSetTevKColor(1, col);
        } else {
            float matrix[2][4];
            float x = *(float *)((unsigned char *)input + 0x24);
            float scale = lbl_8056504C;
            float y = *(float *)((unsigned char *)input + 0x2C);
            matrix[0][0] = lbl_80565048;
            matrix[0][1] = lbl_80565048;
            matrix[0][2] = lbl_80565048;
            matrix[1][0] = lbl_80565048;
            matrix[1][1] = lbl_80565048;
            matrix[1][2] = lbl_80565048;
            matrix[0][3] = lbl_80565044 + x / scale;
            matrix[1][3] = lbl_80565044 + y / scale;
            fn_802D3D94(0, (int)matrix);
            {
                fn_802DCAE4_GXColor col;
                float t = lbl_80565040 * alpha;
                float rounded;
                int a;
                if (t < lbl_80565048)
                    rounded = t - lbl_80565044;
                else
                    rounded = lbl_80565044 + t;
                a = 0xFF;
                {
                    int raw = (int)rounded;
                    int masked = raw & ((-raw & ~raw) >> 31);
                    if (masked < 0xFF) a = masked;
                }
                if ((unsigned char)a != lbl_8055FEA0) {
                    fn_802DCAE4_GXColor color;
                    color.r = 0xFF; color.g = 0xFF; color.b = 0xFF; color.a = a;
                    GXSetTevKColor(1, color);
                }
            }
        }
        fn_802D2F70((int)input);
        if (lbl_8055FEB4 != state) {
            lbl_8055FEB4 = state;
            if (lbl_8055FEB0 != 0) {
                fn_802D6B7C(state);
                return;
            }
            fn_802D6B78(state);
            return;
        }
        if (lbl_8055FEB0 != 0) {
            fn_802D0E48(0);
            GXCallDisplayList(*(void **)((unsigned char *)state + 0x30), *(unsigned int *)((unsigned char *)state + 0x2C));
            fn_802D0E48(1);
            GXCallDisplayList(*(void **)((unsigned char *)state + 0x30), *(unsigned int *)((unsigned char *)state + 0x2C));
        } else {
            GXCallDisplayList(*(void **)((unsigned char *)state + 0x30), *(unsigned int *)((unsigned char *)state + 0x2C));
        }
    }
}
#pragma optimization_level 4
/* Set up the CPU-light indirect (bump-map) pass: bind the pass texture to
 * texcoord slot 1 unless texSlot1 == -2, derive a base-2 indirect-matrix scale
 * from the light level and load it into indirect matrix 1, then configure the
 * indirect TEV and vertex state. indTexSlot == -2 skips the indirect setup;
 * arg0 is unused. */
void CpuLight_BeginIndirectPass(int arg0, int indTexSlot, int texSlot1, float lightLevel, float texScale) {
    float logDiff;
    float magnitude;
    float sign;
    float base;
    float scale;
    int clampedExp;
    int rawExp;
    int scaleExp;
    float powResult;
    fn_802DCAE4_GXColor col;

    lbl_8055D148 = texScale;
    fn_802DBD88();
    if (texSlot1 != -2) {
        fn_802CADD0(texSlot1, 1);
    }
    cpulightSetupGxForMode(2);
    if (indTexSlot != -2) {
        lbl_8055FEC0 = 1;
        base = lbl_80565050 * lightLevel;
        logDiff = (float)fn_8002F208(lbl_80565058) - (float)fn_8002F208(base);
        magnitude = (float)ceil(lbl_80565060 + (float)__fabs(logDiff));
        if (logDiff > lbl_80565048) {
            sign = lbl_80565064;
        } else {
            sign = lbl_80565068;
        }
        clampedExp = -0x2E;
        rawExp = (int)(sign * magnitude);
        if (rawExp > -0x2E) {
            clampedExp = rawExp;
        }
        scaleExp = 0x11;
        if (clampedExp < 0x11) {
            scaleExp = clampedExp;
        }
        powResult = (float)fn_8002EFBC(lbl_80565070, (float)scaleExp);
        scale = base * lbl_80565078 / powResult;
        fn_802D3DF8(fn_802CA294(indTexSlot), scaleExp, scale, scale);
        GXSetNumIndStages(1);
        GXSetTevIndirect(GX_TEVSTAGE0, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_ST, GX_ITM_0, GX_ITW_OFF,
                         GX_ITW_OFF, FALSE, FALSE, GX_ITBA_OFF);
        GXSetIndTexOrder(GX_INDTEXSTAGE0, lbl_8055FEA4, GX_TEXMAP2);
        GXSetNumTexGens((unsigned char)(lbl_8055FEA4 + 1));
        GXSetTexCoordGen2(lbl_8055FEA4, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX2, FALSE, GX_PTIDENTITY);
    }
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX16);
    GXSetVtxDesc(GX_VA_CLR0, GX_INDEX16);
    GXSetVtxDesc(GX_VA_TEX0, GX_INDEX16);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    col.r = 0xC0;
    col.g = 0xC0;
    col.b = 0xC0;
    col.a = 0x14;
    GXSetTevColor(GX_TEVREG1, col);
}

#pragma pop
/* Ends the indirect-texture pass CpuLight_BeginIndirectPass set up, once the geometry drawn
 * with it is on screen (its caller fn_802C03F0 draws it with fn_802DD27C in
 * between): drops the indirect texture matrix from the GX state block, forgets
 * the cached position array, unbinds the pass' texture from texcoord slot 1,
 * turns indirect stages off and makes tev stage 0 direct again.
 * (rename_symbol is refused here; suggested name CpuLight_EndIndirectPass.) */
void fn_802DD228(void) {
    /* Whether CpuLight_BeginIndirectPass left an indirect-texture pass running. */
#define indirectPassRunning lbl_8055FEC0
#define ClearIndTexMtxFlag fn_802D3E88 /* lbl_804C5700[13]: indirect tex matrix loaded */
#define ForgetPositionArray fn_802DBDD8 /* cached position array + vertex count */
#define BindTextureSlot fn_802CADD0 /* (texture handle, texcoord slot) */
#define NO_TEXTURE (-1) /* BindTextureSlot's "clear this slot" handle */
#define TEXCOORD_SLOT_INDIRECT 1 /* the slot the indirect pass' texture sits in */

    if (indirectPassRunning != 0) {
        ClearIndTexMtxFlag();
        indirectPassRunning = 0;
    }
    ForgetPositionArray();
    BindTextureSlot(NO_TEXTURE, TEXCOORD_SLOT_INDIRECT);
    GXSetNumIndStages(0);
    GXSetTevDirect(GX_TEVSTAGE0);
#undef indirectPassRunning
#undef ClearIndTexMtxFlag
#undef ForgetPositionArray
#undef BindTextureSlot
#undef NO_TEXTURE
#undef TEXCOORD_SLOT_INDIRECT
}

/* The vertex record the light renderer builds and points the GX vertex arrays
 * at: a position, one RGBA8 color and one texture coordinate, 24 bytes. */
typedef struct { f32 x, y, z; } LightVec3;
typedef struct { LightVec3 pos; u32 color; f32 u, v; } LightVtx;

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
/* Draws one batch of CPU-lit geometry as an indexed triangle list: points the
 * position, color 0 and texture coordinate 0 arrays at the vertex buffer,
 * flushes it and begins a GX_TRIANGLES draw in vertex format 0, writing each
 * 16-bit index three times (once per array) to the FIFO. */
void fn_802DD27C(LightVtx *__restrict vertices, s32 vertexCount,
                 u16 *__restrict indices, s32 count) {
    register s32 listIndex;
    u16 vertexIndex;
    volatile u16 *fifo = (volatile u16 *)0xCC008000;
    GXSetArray(GX_VA_POS, vertices, sizeof(LightVtx));
    GXSetArray(GX_VA_CLR0, (char *)&vertices->color, sizeof(LightVtx));
    GXSetArray(GX_VA_TEX0, (char *)&vertices->u, sizeof(LightVtx));
    DCFlushRange(vertices, vertexCount * sizeof(LightVtx));
    GXBegin(GX_TRIANGLES, GX_VTXFMT0, (u16)count);
    for (listIndex = 0; listIndex < count; ++listIndex) {
        vertexIndex = indices[listIndex];
        *fifo = vertexIndex;
        *fifo = vertexIndex;
        *fifo = vertexIndex;
    }
}
#pragma pop
/* Bump-allocates the CPU-light renderer's vertex buffer out of the GX dynamic
 * display-list buffer: the caller passes the byte size (0x6000) in r3, which
 * this thunk forwards to the display-list allocator, whose returned base it
 * passes back as the vertex array. */
void fn_802DD42C(void) { fn_802CFF64(); }

