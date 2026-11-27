// video — platform video layer ("video/%s", Vid*).
// Recovered TU window 0x802DEAC4..0x802E1720 (see docs/attribution_analysis.md).
// Static-init thunk fn_802E1720 (+ .ctors slot 0x802ED5E4) remains in
// auto/text_802E1720_.c pending a promotion pass.
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
extern void VideoObject_OpenMovie(void *);
extern char lbl_8034CBC4[];
__declspec(section ".sdata") extern char lbl_8055D168[];
extern int fn_801186B8(void *);
extern void BinkMgr_AdvanceFrame(void *);
extern void videoRingFlushSlot(void *);
extern void fn_802E27B8(void *);
extern u8 fn_802ECC10(void);
extern char lbl_8034CBE0[], lbl_8034CBF8[];
extern void fn_802E30C8(const char *, ...);
extern void KERNEL_GetTimeMs(void);
extern void fn_801284F8(void *, void *);
extern char lbl_8034CB68[];
 extern void *lbl_8055FEEC; /* SimpleHeap backing memory (0x600000 bytes) */
 extern void fn_80128668(); /* free to the system heap */
 extern void fn_80128670(); /* free to the system heap */
 /* SimpleHeap dump text, shared with the twin heap in texture.c:
    lbl_8034BAEC "SimpleHeap Destroyed with pending allocations" (panic)
    lbl_8034BB1C "~SimpleHeap"          lbl_8034BB9C "Allocated:"
    lbl_8034BBA8 "SimpleHeap dump: %s"  lbl_8034BB88 "\tuser ptr %8.8p: %d"
    lbl_8034BB7C "\t%dK total"          (lbl_8034BB68/BB5C reuse those two) */
 extern char lbl_8034BAEC[], lbl_8034BB1C[], lbl_8034BB5C[], lbl_8034BB68[];
 extern char lbl_8034BB7C[], lbl_8034BB88[], lbl_8034BB9C[], lbl_8034BBA8[];
 extern char lbl_8034CB68[];
 extern char lbl_8055D098; /* "Free:" */

#include <revolution/GX/GXTypes.h>
#include <revolution/GX/GXTev.h>
#include <revolution/GX/GXAttr.h>
#include <revolution/GX/GXPixel.h>
extern void *lbl_8055FEE8;
extern void fn_802D3144(void);
extern void GXSetNumIndStages(u8);
extern void GXSetTevDirect(GXTevStageID);
extern void fn_80118DC0(void *);
extern void freeStoredBufferHandle(void *);

/* SimpleHeap: the small first-fit heap this TU creates in fn_802E0F98.
 * One 0x10-byte header owns two block lists; every block carries a
 * 0xABCFEED0 signature and the user pointer sits at block + 0x10. */
typedef struct SimpleHeapBlock {
    /* +0x00 */ u32 magic;                        /* 0xABCFEED0 */
    /* +0x04 */ u32 size;                         /* usable bytes after the header */
    /* +0x08 */ struct SimpleHeapBlock *next;
    /* +0x0C */ struct SimpleHeap *heap;          /* heap this block came from */
} SimpleHeapBlock;

typedef struct SimpleHeap {
    /* +0x00 */ u8 enabled;                       /* set once the free block exists */
    u8 pad[3];
    /* +0x04 */ u32 alignMask;                    /* allocation alignment (0x1F) */
    /* +0x08 */ SimpleHeapBlock *freeList;        /* free blocks */
    /* +0x0C */ SimpleHeapBlock *allocList;       /* blocks handed out */
} SimpleHeap;

#pragma scheduling invalid_target
/* TEV pipeline for the CPU light pass (installed by setupCpuLightPass): texcoords
 * 0-3 are generated from the vertex position through 2x4 texture matrices and
 * five stages read texmaps 0-4 with no vertex colour channel and the identity
 * swap tables. Stages 0-1 clear TEVPREV and TEVREG0, stages 2-3 combine that
 * with texmap3's alpha and texmap0's colour, and stage 4 passes the result on
 * with alpha zero. */
/* First of the two five-stage TEV pipelines selected by setupCpuLightPass: four position-driven texgens feed texmaps 0-4, with five combiners building the CPU-light pass result. */ /* First of the two five-stage TEV pipelines selected by setupCpuLightPass: four position-driven texgens feed texmaps 0-4, with five combiners building the CPU-light pass result. */ void GXSetupFiveStageTevPipelineA(void) {
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX1,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX2,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX3,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD3, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(4);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD3, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP2, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP3, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD2, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD1, GX_TEXMAP4, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE4, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO,
                    GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO,
                    GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO,
                    GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVREG0);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO,
                    GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_CPREV, GX_CC_C0, GX_CC_TEXA,
                    GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO,
                    GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_ZERO, GX_CC_CPREV, GX_CC_TEXC,
                    GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO,
                    GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE4, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO,
                    GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE4, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO,
                    GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(5);
}

#pragma scheduling invalid_target
/* Resets TEV swap modes for stages 0-4 to the identity ras/tex swap selectors. */
void GXResetTevSwapModes0To4(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE4, GX_TEV_SWAP0, GX_TEV_SWAP0);
}
#pragma scheduling on
/* Set up the single-texture TEV pipeline: texcoord 0 comes from TEX0 through the
 * identity matrix, stage 0 outputs TEXC with the raster alpha, and standard
 * SRCALPHA/INVSRCALPHA blending is enabled. */
void fn_802DEE88(void) {
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1,
                    GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(1);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
}

#pragma scheduling invalid_target
/* Reset TEV stage 0 to the identity colour/alpha swap, then reapply the
   currently configured blend mode. */
void fn_802DEF70(void) {
#define gxApplyBlendMode fn_802D3144
    GXSetTevSwapMode(0, 0, 0);
    gxApplyBlendMode();
#undef gxApplyBlendMode
}
#pragma scheduling on
/* Set up the two-stage indirect-texture TEV pipeline used by render mode 2
 * (without the extra texture stage of GXSetupWaterBumpTevPipelineB): texcoord 0
 * samples the surface, texcoord 1 carries the indirect coordinate read from
 * TEXMAP5, and stage 1 folds in the distort texture held in TEXMAP6.  Load the
 * indirect matrix/map (fn_802D312C) into map 5, the indirect texture
 * (gxGetIndirectTexObj) into map 7 and the distort texture (fn_802D30F0) into map 6.
 * spC/sp8 reserve stack slots for GXSetTevIndirect's trailing arguments. */
void GXSetupIndirectTevPipeline(void) {
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
    GXLoadTexObj(gxGetIndirectTexObj(), 7);
    GXLoadTexObj(fn_802D30F0(), 6);
}

#pragma scheduling invalid_target
/* Configure TEV swap mode table/stages, run shared GX state update, and reset indirect/direct TEV state. */
/* Undo the indirect-texture TEV setup: fill swap table 1, reset stage 0/1 swap modes, reapply the configured blend mode, and disable indirect texturing while making stage 1 sample directly. */ void GXResetIndirectTevPipeline(void) {
    register u32 swapTableId = 1;
    register u32 colorChannel = 0;
    register u32 alphaChannel = 3;
    GXSetTevSwapModeTable(swapTableId, colorChannel, colorChannel, colorChannel, alphaChannel);
    GXSetTevSwapMode(0, 0, 0);
    GXSetTevSwapMode(1, 0, 0);
    fn_802D3144();
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}
#pragma scheduling on
/* Configure the simple TEV pipeline: one texcoord generator and one color/alpha combine stage. */ void fn_802DF21C(void) {
    /* Configure a simple 1-texgen, 1-stage GX TEV setup (texcoord gen, color/alpha combine passes, 1 TEV stage). */
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

/* Reset TEV stage 0's raster and texture colour swap selectors to identity (swap table 0);
 * the single-stage counterpart of GXResetTevSwapModes0To4. */
void GXResetTevSwapMode0(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
}

void *gxGetSceneTexObj(void);
/* Configures GX TEV/texture state for a 2-stage textured blend setup. */
/* Configure the 2-stage TEV pipeline for render mode 2's non-indirect branch: stage 0 uses the rasterized color, stage 1 samples the texture from gxGetSceneTexObj() loaded into GX_TEXMAP7. */ void fn_802DF300(void) {
    register u32 texCoordId = 0;
    register u32 texGenType = 1;
    GXSetTexCoordGen2(texCoordId, texGenType, 0, 0x2D, 0, 0x7D);
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
    GXLoadTexObj(gxGetSceneTexObj(), 7);
}

#pragma push
#pragma scheduling invalid_target
/* Reset TEV swap modes for stages 0-1 to the identity (swap 0) selectors;
 * the two-stage counterpart of GXResetTevSwapModes0To4. */
/* Reset TEV swap modes for stages 0-1 to the identity (swap 0) selectors; the two-stage counterpart of GXResetTevSwapModes0To4. */ void fn_802DF46C(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
}
#pragma pop
void *gxGetBumpMapTexObj(void); /* the current material's bump map, into GX_TEXMAP5 */
void *gxGetDistortTexObj(void); /* the texture it distorts, into GX_TEXMAP6 */
/* The water surface pass: drgc_surf.c asks for mode 3 of the render request
 * block (gRenderRequest) and fn_802D2B0C builds the pipeline here.  Stage 0 draws
 * the surface itself, stage 1 adds the GX_TEXMAP6 texture whose coordinates
 * indirect stage 0 shifts with the bump map in GX_TEXMAP5.  GXResetWaterBumpTevPipelineA undoes
 * it again; GXSetupWaterBumpTevPipelineB is the twin used when a second texture stage is wanted.
 */
/* Set up the two-stage water-surface TEV pipeline: stage 0 draws the lit surface, stage 1 adds the GX_TEXMAP6 texture shifted by the bump map in GX_TEXMAP5. */ /* Configure the two-stage TEV pipeline for the water surface: stage 0 draws the lit surface, stage 1 adds the GX_TEXMAP6 texture whose coordinates indirect stage 0 shifts with the bump map in GX_TEXMAP5. */ void GXSetupWaterBumpTevPipelineA(void) {
    s32 alphaSel = GX_ITBA_OFF; /* GXSetTevIndirect's last two arguments go on */
    s32 utcLod = FALSE;         /* the stack, so they need somewhere to live */
    /* texcoord0 is the model's own texture coordinates; texcoord1 is the normal,
     * taken through GX_TEXMTX4 and post-multiplied by GX_PTTEXMTX4. */
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_NRM, GX_TEXMTX4, GX_TRUE, GX_PTTEXMTX4);
    GXSetNumTexGens(2);
    GXSetIndTexOrder(GX_INDTEXSTAGE0, GX_TEXCOORD1, GX_TEXMAP5);
    GXSetNumIndStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP6, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    /* Stage 0: the texture over the lit surface. */
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    /* the alpha equation ignores bias and scale; the game still sets them */
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ADDHALF, GX_CS_SCALE_2, GX_TRUE, GX_TEVPREV);
    /* Stage 1: the bump-shifted texture, added to stage 0's result. */
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_CPREV, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevIndirect(GX_TEVSTAGE1, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_NONE, GX_ITM_0, GX_ITW_0,
                     GX_ITW_0, GX_DISABLE, utcLod, alphaSel);
    GXSetNumTevStages(2);
    GXLoadTexObj(gxGetBumpMapTexObj(), GX_TEXMAP5);
    GXLoadTexObj(fn_802D3100(), GX_TEXMAP6);
}

#pragma scheduling invalid_target
/* Reset TEV swap tables to identity for stages 0-1 and disable indirect stages. */
/* Reset TEV swap tables to identity for stages 0-1 and disable indirect stages (teardown twin of GXSetupWaterBumpTevPipelineA). */ void GXResetWaterBumpTevPipelineA(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}
#pragma scheduling on
void *fn_802D3134(void); /* the current material's bump map, into GX_TEXMAP5 */
void *fn_802D30FC(void); /* the texture it distorts, into GX_TEXMAP6 */
/* Water-surface bump TEV pipeline: the GXSetupWaterBumpTevPipelineA twin used
 * when the render request block gRenderRequest also asks for the second texture
 * stage (+0x08); fn_802D2B0C selects it in mode 3 and stores GXResetWaterBumpTevPipelineB as the
 * undo.  Two texgens feed one indirect stage, which shifts GX_TEXMAP6's
 * coordinates by the bump map in GX_TEXMAP5.  Stage 0 draws the surface, stage
 * 1 adds the shifted texture, and stage 2 passes that colour through while
 * taking alpha from the second texture in GX_TEXMAP1.
 */
void GXSetupWaterBumpTevPipelineB(void) {
    s32 alphaSel = GX_ITBA_OFF; /* GXSetTevIndirect's last two arguments go on */
    s32 utcLod = FALSE;         /* the stack, so they need somewhere to live */
    /* texcoord0 is the model's own texture coordinates; texcoord1 is the normal,
     * taken through GX_TEXMTX4 and post-multiplied by GX_PTTEXMTX4. */
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_NRM, GX_TEXMTX4, GX_TRUE, GX_PTTEXMTX4);
    GXSetNumTexGens(2);
    GXSetIndTexOrder(GX_INDTEXSTAGE0, GX_TEXCOORD1, GX_TEXMAP5);
    GXSetNumIndStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP6, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
    /* Stage 0: the surface's texture against its raster colour. */
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    /* the alpha equation ignores bias and scale; the game still sets them */
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    /* Stage 1: the bump-shifted GX_TEXMAP6 texture, weighted by its own alpha. */
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_CPREV, GX_CC_TEXC, GX_CC_TEXA, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevIndirect(GX_TEVSTAGE1, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_NONE, GX_ITM_0, GX_ITW_0,
                     GX_ITW_0, GX_DISABLE, utcLod, alphaSel);
    /* Stage 2: the colour passes through; the alpha comes from GX_TEXMAP1's texture. */
    GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(3);
    GXLoadTexObj(fn_802D3134(), GX_TEXMAP5);
    GXLoadTexObj(fn_802D30FC(), GX_TEXMAP6);
}

/* Undo GXSetupWaterBumpTevPipelineB: reset TEV swap modes for stages 0-2 to identity,
 * disable indirect texturing, and make stage 1 sample directly. */
void GXResetWaterBumpTevPipelineB(void) {
    register GXTevStageID tevStage = GX_TEVSTAGE0;
    register GXTevSwapSel rasSel = GX_TEV_SWAP0;
    register GXTevSwapSel texSel = GX_TEV_SWAP0;
    GXSetTevSwapMode(tevStage, rasSel, texSel);
    tevStage = GX_TEVSTAGE1;
    GXSetTevSwapMode(tevStage, rasSel, texSel);
    tevStage = GX_TEVSTAGE2;
    GXSetTevSwapMode(tevStage, rasSel, texSel);
    GXSetNumIndStages(0);
    GXSetTevDirect(1);
}

#pragma push
#pragma scheduling on
/* Mode-4 render setup: one texgen passes the model's texcoords through the
 * identity matrix, then a 2-stage TEV combiner multiplies the texel colour by
 * the raster colour (stage 0) and folds the raster alpha into the result (stage 1). */
/* Set up the mode-4 TEV pipeline used after gxSetupSceneLights: one texgen passes model texcoords through the identity matrix; stage 0 multiplies the texel colour by the raster colour, stage 1 folds the second vertex colour's alpha into the result. */ void fn_802DF994(void) {
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR1A1);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ADDHALF, GX_CS_SCALE_2, GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_RASC, GX_CC_A1, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(2);
}
#define ResetTevSwapModes fn_802DFAF4 /* reset TEV swap selectors for stages 0 and 1 */
/* Reset TEV swap selectors (used by GXResetSceneLightsPipeline): set stages 0 and 1 both to swap 0 / swap 0. */ /* Reset TEV swap selectors (used by GXResetSceneLightsPipeline): set stages 0 and 1 both to swap 0 / swap 0. */ /* Reset TEV swap selectors (used by GXResetSceneLightsPipeline): set stages 0 and 1 both to swap 0 / swap 0. */ void fn_802DFAF4(void) {
    /* Reset the TEV swap selectors to swap 0 for the first two stages. */
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
}
#pragma pop
/* Configure the TEV/blend pipeline for CPU-light drawing: two texgens transform position by texmatrix 0, stage 0 passes the texel colour and vertex alpha through, stage 1 multiplies by the previous colour, and source-alpha blending is enabled. */ void GXSetupCpuLightTevPipeline(void) {
    /* Configures texcoord generation and a two-stage TEV combiner with alpha blending for this renderer path. */
    register u32 texCoordId = 0;
    register u32 texGenType = texCoordId + 1;
    GXSetTexCoordGen2(texCoordId, texGenType, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(2);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
}

#pragma scheduling invalid_target
/* Reset TEV stages 0 and 1 swap selectors to GX_TEV_SWAP0, then refresh the shared blend state. */ void fn_802DFCC0(void) {
    /* Reset both TEV stages' swap selectors, then refresh the shared blend state. */
    GXSetTevSwapMode(GX_TEVSTAGE0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode(GX_TEVSTAGE1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    fn_802D3144();
}
#pragma scheduling on
/* Configure texcoord generation and a two-stage TEV combiner that modulates by a texture with constant alpha, then adds the previous color and texture. */ void GXSetupModulateAddTevPipeline(void) {
    /* Configures texcoord generation and a two-stage TEV combiner: stage 0 modulates
       the raster color by a texture with constant alpha, stage 1 adds the prior color
       and texture, and alpha blending is applied. */
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevKAlphaSel(GX_TEVSTAGE0, GX_TEV_KASEL_K1_A);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(2);
}
#pragma scheduling reset
/* TEV pipeline of the overlay pass when the overlay texture carries a second
 * (alpha) texture: texcoord0 is the vertex position through GX_TEXMTX0 and
 * texcoord1 the same coordinates unchanged (GX_IDENTITY). Stage 0 takes texmap1's
 * colour, stage 1 adds texmap0's colour to it and stage 2 passes that sum through
 * while building the alpha from texmap2's alpha scaled by the K1 constant alpha. */
void GXSetupThreeStageTevPipeline(void) {
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_POS, GX_TEXMTX0,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY,
                      GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevKAlphaSel(GX_TEVSTAGE2, GX_TEV_KASEL_K1_A);
    GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetNumTevStages(3);
}

/* Non-alternate 2-stage TEV pipeline selected by fn_802DC71C for material flag
 * 0x1D when there is no alternate texture (useAlt == 0); its alternate-texture
 * twin is GXSetupThreeStageTevPipelineAlt. Stage 0 takes TEXMAP1's colour with
 * alpha = texel alpha + raster alpha, stage 1 adds TEXMAP0's colour on top and
 * carries that alpha through. */
void GXSetupTwoStageTevPipelineNoAlt(void) {
    register u32 texCoord = 0;
    register u32 texGenType = 1;
    GXSetTexCoordGen2(texCoord, texGenType, GX_TG_TEX1, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_RASA, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetNumTevStages(2);
}

/* Three-stage TEV pipeline for a material flagged 0x1D that has an alternate
 * texture (loaded into map 2 by fn_802DC71C): texcoord 0 samples map 1, texcoord
 * 1 samples map 0, and the combiner blends both into the final stage 2.  The
 * non-alternate twin is GXSetupTwoStageTevPipelineNoAlt. */
void GXSetupThreeStageTevPipelineAlt(void) {
    register u32 texCoord = 0;
    GXSetTexCoordGen2(texCoord, 1, 5, 0x3C, 0, 0x7D);
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
/* RealName: GXSetupOneStageKColorTevPipeline
 * TEV pipeline for the CPU-light pass when the light texture carries no extra
 * map: fn_802DC71C picks it (with fn_802DC62C) when that texture's S wrap is
 * GX_REPEAT; GXSetupAltTextureTevPipeline is its two-stage twin for the extra-map case and
 * GXSetupModulateAddTevPipeline the variant used when the wrap is not GX_REPEAT.
 * One texture generator: texcoord 0 passes the vertex's texcoord0 through the
 * identity matrix.  The single combiner stage samples texmap 1 with that
 * texcoord, ignores the vertex colour channel and clamps into TEVPREV, reading
 * constant colour K1 for both combine terms:
 *   rgb   = 0 + texC - K1   + 0   (GX_CC_ZERO, TEXC, KONST, ZERO)
 *   alpha = 0 + texA - K1.a + 0   (GX_CA_ZERO, TEXA, KONST, ZERO) */
void fn_802E0420(void) {
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE,
                      GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevKColorSel(GX_TEVSTAGE0, GX_TEV_KCSEL_K1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevKAlphaSel(GX_TEVSTAGE0, GX_TEV_KASEL_K1_A);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetNumTevStages(1);
}
#pragma scheduling on
/* RealName: GXSetupTwoStageKColorTevPipeline — the "alt texture" variant of
 * fn_802E0420 (both are installed by fn_802DC71C when the second texture wraps
 * with GX_REPEAT; this one is used when that texture carries the extra map).
 * One texture generator: texcoord 0 passes the vertex's texcoord0 through the
 * identity matrix.  Two combiner stages, neither using a vertex colour
 * channel and both clamped into TEVPREV:
 *   stage 0 (texmap 1, constant colour K1): rgb = K1 - texC, alpha = 0;
 *   stage 1 (texmap 2, constant alpha K1.a): rgb = the previous stage's rgb,
 *                                            alpha = K1.a - texA. */
/* Set up the alt-texture TEV pipeline: one texcoord generator feeding two K-color combiner stages (texmap 1 K1 colour, texmap 2 K1 alpha), both clamped into TEVPREV. */ void GXSetupAltTextureTevPipeline(void) {
    register u32 texCoordId = GX_TEXCOORD0;
    register u32 texGenType = GX_TG_MTX2x4;
    GXSetTexCoordGen2(texCoordId, texGenType, GX_TG_TEX0, GX_IDENTITY, GX_FALSE,
                      GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP2, GX_COLOR_NULL);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevKColorSel(GX_TEVSTAGE0, GX_TEV_KCSEL_K1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevKAlphaSel(GX_TEVSTAGE1, GX_TEV_KASEL_K1_A);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetNumTevStages(2);
}

/* Second of the two five-stage TEV pipelines setupCpuLightPass() picks between: three
 * position-driven texture coordinate generators feed five combiner stages that
 * modulate texture maps 0..4 together into the previous-colour register, build
 * their alpha through TEV register 0, and leave the result to standard
 * source-alpha blending.
 */
void GXSetupFiveStageTevPipelineB(void) {
    register GXTexGenType texGenType = GX_TG_MTX2x4;

    /* texcoord0..2 = vertex position through texture matrices 0, 1 and 3 */
    GXSetTexCoordGen2(GX_TEXCOORD0, texGenType, GX_TG_POS, GX_TEXMTX1, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, texGenType, GX_TG_POS, GX_TEXMTX0, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD2, texGenType, GX_TG_POS, GX_TEXMTX3, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(3);

    /* stage: texture coordinates / texture map / raster colour channel */
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP3, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP4, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD2, GX_TEXMAP0, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE4, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR_NULL);

    /* swap table 1: every output channel takes the input's alpha */
    GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_ALPHA);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP1);
    GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE4, GX_TEV_SWAP0, GX_TEV_SWAP0);

    /* 0: rgb = map1, alpha = 0 */
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

    /* 1: rgb = map3 into TEV register 0, alpha carried through */
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

    /* 2: rgb = previous + map4, alpha = map4's into TEV register 0 */
    GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_CPREV, GX_CC_C0, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVREG0);

    /* 3: rgb = previous + map0, alpha carried through */
    GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_ZERO, GX_CC_CPREV, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

    /* 4: rgb = previous, alpha = map2's + the raster's alpha0 */
    GXSetTevColorIn(GX_TEVSTAGE4, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE4, GX_CA_ZERO, GX_CA_TEXA, GX_CA_A0, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE4, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);

    GXSetNumTevStages(5);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
}

/* RealName: GXSetupTwoStageTevPipeline — the TEV pipeline render mode 5 installs
 * (the render-mode switch in gx.c calls this and later fn_802E0B68 to undo the
 * swap selectors).  Two texture generators: texcoord 0 passes the vertex's
 * texcoord0 through unchanged (identity matrix), texcoord1 transforms the
 * vertex normal with texture matrix 4.  Two combiner stages:
 *   stage 0 (texmap 2, no colour channel): rgb = alpha1 - texC,
 *           alpha = (0 + 1/2) * 2 = 1.0, so the stage is opaque;
 *   stage 1 (texmap 0, colour0/alpha0):    rgb = raster + previous - texC,
 *           alpha = the previous stage's alpha.
 * Both stages clamp and write TEVPREV. */
/* Configure the render-mode 5 two-stage TEV pipeline: texcoord generators, texture/color orders, swap modes, and both combiners. */ void GXSetupTevPipelineMode5(void) {
    register u32 texCoordId = GX_TEXCOORD0;
    register u32 texGenType = GX_TG_MTX2x4;
    GXSetTexCoordGen2(texCoordId, texGenType, GX_TG_TEX0, GX_IDENTITY, GX_FALSE,
                      GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_NRM, GX_TEXMTX4, GX_FALSE,
                      GX_PTIDENTITY);
    GXSetNumTexGens(2);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_A1, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ADDHALF, GX_CS_SCALE_2, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_RASC, GX_CC_CPREV);
    GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE,
                    GX_TEVPREV);
    GXSetNumTevStages(2);
}

#pragma push
#pragma scheduling invalid_target
/* Reset the TEV swap selectors to swap 0 for the first two stages. */
/* Resets the TEV swap selectors of stages 0 and 1 back to swap 0 (identity ras/tex swap). Called after a two-stage TEV pipeline setup to undo its swap-mode changes. */ void fn_802E0B68(void) {
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
}
#pragma pop
#pragma dont_inline on
void *fn_802E0BA4(void) {
    /* No-op free hook used during BinkMovie teardown; it returns nothing and
     * leaves the movie pointer untouched (the heap block is freed separately). */
}

/* Allocate the BinkMovie object (0x228 bytes, tagged with the "BinkMovie" name
 * block at lbl_8034CB68) and seed its first word with its initial state; the
 * returned pointer is picked up by the caller that opens the movie. */
/* BinkMovie_Create: allocate a BinkMovie playback object (0x228 bytes, tagged with the "BinkMovie" name at lbl_8034CB68) and seed its state word at +0 to 0x10011001; the caller picks up the pointer through the videoFreeHook thunk. */ void fn_802E0BA8(void) {
    u32 *movie = ((u32 *(*)(s32, void *))fn_801284F8)(0x228, lbl_8034CB68);
    *movie = 0x10011001;
}

#pragma dont_inline reset

#pragma scheduling on
#pragma dont_inline on
/* BinkMovie teardown helpers: a no-op free hook and the heap-block free. */
#define videoFreeHook   fn_802E0BA4
#define freeVideoObject fn_80128668
/**
 * Final teardown of a BinkMovie: run the (currently no-op) free hook, then
 * release the movie object's heap block. The incoming movie pointer stays in
 * r3 and is passed straight through to both calls.
 */
void BinkMovie_FreeObject(void) {
    /* Final BinkMovie teardown: run the no-op free hook, then free the object's heap block. */
    videoFreeHook();
    freeVideoObject();
}

extern void Abend_Panic(char *, ...);
extern char lbl_8034BB28[];
#pragma push
#pragma optimization_level 3
#pragma scheduling invalid_target
void *fn_802E0C04(u32 size) {
    int needed;
    int *head;
    char *link;
    int best;
    void *freeNode;
    void **bestLink;
    void *split;
    int left;
    void *result;
    void *node;
    int freeSize;
    int align, align2;

    best = 0x7FFFFFFF;
    bestLink = 0;
    result = 0;
    head = (int *)lbl_8055FEE8;
    needed = *(volatile int *)((char *)head + 4);
    link = (char *)head + 8;
    {
        int r0 = size + needed;
        needed = r0 & ~needed;
    }
    while ((node = *(void **)link) != 0) {
        freeSize = *(int *)((char *)node + 4);
        if (freeSize >= needed && best > freeSize) {
            bestLink = (void **)link;
            best = freeSize;
        }
        link = (char *)node + 8;
    }
    if (bestLink != 0) {
        freeNode = *bestLink;
        split = 0;
        align = *(volatile int *)((char *)head + 4);
        freeSize = *(int *)((char *)freeNode + 4);
        best = *(int *)((char *)freeNode + 8);
        left = freeSize - needed;
        if (left > ((align + 0x10) & ~align) + 0x20) {
            link = (char *)freeNode + align + needed;
            *(int *)(link + 1) = 0xABCFEED0;
            split = link + 1;
            *(int *)(link + 9) = 0;
            align2 = *(volatile int *)((char *)head + 4);
            *(int *)(link + 5) = left - ((align2 + 0x10) & ~align2);
            *(int **)(link + 0xD) = head;
            *(int *)((char *)freeNode + 4) = needed;
        }
        if (split != 0) {
            *(int *)((char *)split + 8) = best;
            *bestLink = (void *)split;
        } else {
            *bestLink = (void *)best;
        }
        *(void **)((char *)freeNode + 8) = (void *)*(volatile int *)((char *)head + 0xC);
        *(volatile int *)((char *)head + 0xC) = (int)freeNode;
        result = (char *)freeNode + *(volatile int *)((char *)head + 4) + 1;
    }
    if (result == 0 && *(volatile u8 *)head != 0) {
        Abend_Panic(lbl_8034BB28);
    }
    return result;
}
#pragma pop

void fn_802E0D44(u32 size)
{
  u8 *node;
  int new_var;
  u8 **link;
  u8 *block;
  u8 *head;
  u8 **anchor;
  u8 **scan;
  u32 align;
  head = (u8 *) lbl_8055FEE8;
  align = *((u32 *) (head + 4));
  new_var = 4;
  link = (u8 **) (head + 12);
  block = (u8 *) (size - (align + 1));
  while ((node = *link) != 0)
  {
    if (node == block)
    {
      *link = *((u8 **) (block + 8));
      break;
    }
    link = (u8 **) (node + 8);
  }

  *((u8 **) (block + 8)) = *((u8 **) (head + 8));
  *((u8 **) (head + 8)) = block;
  anchor = (u8 **) (head + 8);
  do
  {
    u8 *current;
    scan = (u8 **) (head + 8);
    align = 0;
    while ((current = *scan) != 0)
    {
      u8 *other = *anchor;
      u32 adjacent = 1;
      u32 a = *((u32 *) (head + 4));
      if (((((other + a) + (*((u32 *) (other + 4)))) + 1) != current) && ((((current + a) + (*((u32 *) (current + 4)))) + 1) != other))
      {
        adjacent = 0;
      }
      if (adjacent != 0)
      {
        u8 **selected = anchor;
        if ((((current + a) + (*((u32 *) (current + 4)))) + 1) == other)
        {
          selected = scan;
          scan = anchor;
        }
        {
          u8 *kept = *selected;
          anchor = selected;
          align = 1;
          *((u32 *) (kept + 4)) = ((*((u32 *) (kept + new_var))) + (*((u32 *) ((*scan) + 4)))) + ((a + 16) & (~a));
          *scan = *((u8 **) ((*scan) + 8));
        }
      }
      else
      {
        scan = (u8 **) (current + 8);
      }
    }

  }
  while (align != 0);
}

/* Close a video object's Bink handle at +4 if loaded: free the subobject at
 * +0x50, close the Bink through fn_80118DC0, then clear the handle. */
/* Close the video object's Bink handle at +4 if loaded, freeing its +0x50 subobject and clearing the handle. */ void VideoObject_FreeBink(object)
void *object;
{
    s32 *binkHandle;

    binkHandle = (s32 *)((u8 *)object + 4);
    if (*binkHandle != 0) {
        freeStoredBufferHandle((u8 *)object + 0x50);
        fn_80118DC0((void *)*binkHandle);
        *binkHandle = 0;
    }
}

extern s32 FileLookup(void *);
extern void fn_802E3804(void *, u32);
extern void closeFileHandle(s32 *);
extern s32 fn_8011770C(void *, u32);
extern void fn_80117618(s32, void *);
extern s32 buildImageBankTextures(void *);
extern void fn_801176FC(s32, void *);
/* Open a Bink movie into this video object, logging open/failure status. */
/* VideoObject movie loader: free the current Bink, resolve and open the movie file by its name at +8, and store the new handle at +4. */ void VideoObject_OpenMovie(void *videoObj) {
    s32 movieIndex;
    char name[0x20];
    char *messages = (char *)lbl_8034CB68;
    s32 binkHandle;
    unsigned char *video = videoObj;
    VideoObject_FreeBink(videoObj);
    movieIndex = FileLookup(video + 8);
    if (movieIndex != -1) {
        ((void (*)(s32, void *, s32))fn_802E3804)(movieIndex, name, 0x20);
        closeFileHandle(&movieIndex);
    }
    binkHandle = fn_8011770C(video + 8, 0x100400);
    *(s32 *)(video + 4) = binkHandle;
    if (binkHandle != 0) {
        fn_802E30C8(messages + 0x10, video + 8);
        fn_80117618(*(s32 *)(video + 4), video + 0x150);
        fn_80117618(*(s32 *)(video + 4), video + 0x150);
        if (buildImageBankTextures(video + 0x50) == 0) {
            Abend_Panic(messages + 0x20);
        }
        fn_801176FC(*(s32 *)(video + 4), video + 0x150);
        *(s32 *)(video + 0x4C) = ((s32 (*)(void))KERNEL_GetTimeMs)();
    } else {
        fn_802E30C8(messages + 0x48, video + 8);
    }
}

/* InitSimpleHeap: register the best-fit alloc/free callbacks, allocate 0x600000 bytes of backing memory and a heap-head node, then link them into one aligned free block as the initial heap. */ void fn_802E0F98(void) {
    void *heapHead;
    fn_80119214((void *)fn_802E0C04, (void *)fn_802E0D44);
    fn_80116E54(&fn_8011A168, &lbl_8055D150);
    fn_801282EC(0x80);
    fn_801282F4();
    lbl_8055FEEC = fn_8012850C(0x600000, &lbl_8055D158);
    heapHead = ((void *(*)(u32, void *))fn_801284F8)(0x10, &lbl_8055D160);
    if (heapHead != 0) {
        register void *freeBlock = lbl_8055FEEC;
        *(u32 *)((char *)heapHead + 0xC) = 0;
        *(u32 *)((char *)heapHead + 4) = 0x1F;
        *(u32 *)freeBlock = 0xABCFEED0;
        *(u32 *)((char *)freeBlock + 8) = 0;
        {
            u32 align = *(u32 *)((char *)heapHead + 4);
            *(u32 *)((char *)freeBlock + 4) = 0x600000 - ((align + 0x10) & ~align);
        }
        *(void **)((char *)freeBlock + 0xC) = heapHead;
        *(void **)((char *)heapHead + 8) = freeBlock;
        *(u8 *)heapHead = 1;
    }
    lbl_8055FEE8 = heapHead;
}

/* Destroys the SimpleHeap (lbl_8055FEE8): if any block is still handed out it
 * first dumps the heap -- "SimpleHeap dump: ~SimpleHeap", then every allocated
 * and every free block with its user pointer and size and the two totals in K
 * -- and panics with "SimpleHeap Destroyed with pending allocations". Either
 * way the heap header and its backing memory (lbl_8055FEEC) go back to the
 * system heap and both globals are cleared. */
/* Destroy the global SimpleHeap: if blocks are still allocated, dump both block lists and panic; otherwise free the heap header and its backing memory and clear both globals. */ void fn_802E1058(void) {
    register u32 allocatedTotal;
    register SimpleHeapBlock *block;
    register SimpleHeap *heap;
    register unsigned int freeBytes;
    heap = (SimpleHeap *)lbl_8055FEE8;
    if (heap != 0) {
        if (heap->allocList != 0) {
            fn_802E30C8(lbl_8034BBA8, lbl_8034BB1C); /* "SimpleHeap dump: %s", "~SimpleHeap" */
            fn_802E30C8(lbl_8034BB9C);               /* "Allocated:" */
            block = heap->allocList;
            allocatedTotal = 0;
            while (block != 0) {
                fn_802E30C8(lbl_8034BB88, (void *)(block + 1), block->size); /* "\tuser ptr %8.8p: %d" */
                allocatedTotal += block->size;
                block = block->next;
            }
            fn_802E30C8(lbl_8034BB7C, allocatedTotal >> 10);  /* "\t%dK total" */
            freeBytes = 0;
            fn_802E30C8((const char *)&lbl_8055D098); /* "Free:" */
            block = heap->freeList;
            while (block != 0) {
                fn_802E30C8(lbl_8034BB68, (void *)(block + 1), block->size); /* "\tuser ptr %8.8p: %d" */
                freeBytes += block->size;
                block = block->next;
            }
            fn_802E30C8(lbl_8034BB5C, freeBytes >> 10); /* "\t%dK total" */
            Abend_Panic(lbl_8034BAEC); /* panic: "SimpleHeap Destroyed with pending allocations" */
        }
        fn_80128668((void *)heap);
    }
    lbl_8055FEE8 = 0;
    fn_80128670(lbl_8055FEEC);
    lbl_8055FEEC = 0;
}

#pragma push
#pragma use_lmw_stmw off
/* Bink movie playback state: fn_802E0BA8 allocates it and VideoObject_OpenMovie opens the
 * movie whose filename is stored in name. */
struct BinkMovieInfo {
    char pad[4];        /* 0x00 */
    s32 binkHandle;     /* 0x04, 0 while no movie is open */
    char name[0x40];    /* 0x08, "video/<name>.bik" */
    u8 flags;           /* 0x48 */
    char pad49[3];      /* 0x49 */
    s32 frameTimerMs;   /* 0x4C, millisecond timer used to pace movie frames */
    char videoRing[1];  /* 0x50, start of the decoded-frame ring buffer */
};
/* Open a Bink movie: build "video/<name>.bik" in the movie object, reset its
 * handle, set its mode byte, and pass it to VideoObject_OpenMovie to actually open it.
 * Returns the movie system state saved on entry. */
s32 fn_802E11A4(const char *name, u8 mode) {
#define VIDEO_PATH_FMT lbl_8034CBC4  /* "video/%s" */
#define BIK_EXT        lbl_8055D168  /* ".bik" */
#define NAME_CAPACITY  0x40          /* size of BinkMovieInfo.name */
#define DOT_CHAR       0x2e          /* '.' */
    s32 saved;
    struct BinkMovieInfo *object;
    char *dot;
    const char *suffix;
    int remaining;
    char *dest;
    saved = ((s32 (*)(void))fn_802E0BA8)();
    object = (struct BinkMovieInfo *)fn_802E0BA4();
    object->binkHandle = 0;
    object->flags = mode;
    fn_801345D8(object->name, NAME_CAPACITY, VIDEO_PATH_FMT, name);
    dot = fn_80029004(object->name, DOT_CHAR);
    if (dot != 0)
        *dot = 0;
    dest = object->name;
    remaining = NAME_CAPACITY;
    suffix = BIK_EXT;
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
    VideoObject_OpenMovie(object);
    return saved;
#undef DOT_CHAR
#undef NAME_CAPACITY
#undef BIK_EXT
#undef VIDEO_PATH_FMT
}
#pragma pop
/* Log and unload a movie: destroy it, run movie teardown, and close its handle. */
/* Log "drMovieUnload" and tear down a Bink movie: run the free hook, close the loaded Bink handle, then free the movie object. */ void BinkMovie_Unload(void *movie) {
    extern void fn_802E30C8(const char *, ...);
    extern void *fn_802E0BA4(void);
    extern void BinkMovie_FreeObject(void);
    extern void VideoObject_FreeBink();
    extern char lbl_8034CBD0[];
    fn_802E30C8(lbl_8034CBD0);
    ((void (*)(void *))fn_802E0BA4)(movie);
    VideoObject_FreeBink();
    ((void (*)(void *))BinkMovie_FreeObject)(movie);
}

#pragma opt_common_subs off
/* Per-frame Bink movie update: close a movie that reports an error, open one if
 * none is loaded, then pump its frame and resync the frame timer when it drifts. */
void fn_802E12DC(void) {
    struct BinkMovieInfo *movie = (struct BinkMovieInfo *)fn_802E0BA4();
    s32 nowMs;
    if (movie->binkHandle != 0 &&
        *(s32 *)((char *)movie->binkHandle + 0x1C) != 0) {
        fn_802E30C8(lbl_8034CBE0);
        VideoObject_FreeBink(movie);
    }
    if (movie->binkHandle == 0)
        VideoObject_OpenMovie(movie);
    if (movie->binkHandle != 0) {
        fn_802E27B8(movie->videoRing);
        fn_801186B8((void *)movie->binkHandle);
        nowMs = ((s32 (*)(void))KERNEL_GetTimeMs)();
        if (nowMs - movie->frameTimerMs > 0x96) {
            fn_802E30C8(lbl_8034CBF8);
            movie->frameTimerMs = nowMs - 0x20;
        }
        if (nowMs - movie->frameTimerMs > 0x1E) {
            if (((s32 (*)(void))fn_802ECC10)() == 0)
                BinkMgr_AdvanceFrame((void *)movie->binkHandle);
            movie->frameTimerMs += 0x20;
        }
        videoRingFlushSlot(movie->videoRing);
    }
}
extern void GXSetZMode(GXBool, GXCompare, GXBool);
extern void fn_802C8C04(s32);
extern void DrawList_RestoreNormalMode(void);
extern void fn_802C8DB8(void *, s32, u16 *, s32, u16, u16, u16, u16);
extern void fn_802D007C(f32);
extern void gxInitRenderState(void);
extern void KERNEL_GetTimeMs(void);
extern void fn_802E1DA4(void *, u32, u32, f32, f32, f32, f32, f32);
extern const u16 lbl_802FAE28[];
extern const u8 lbl_805650C8, lbl_805650C9, lbl_805650CA, lbl_805650CB;
extern const f32 lbl_805650CC, lbl_805650D0, lbl_805650D4, lbl_805650D8, lbl_805650DC, lbl_805650E0;
extern const u16 lbl_80565238, lbl_8056523A, lbl_8056523C, lbl_8056523E;
#pragma processor 7400
void fn_802E13D8(f32 p0, f32 p1, f32 p2, f32 p3, void *arg0) {
    register f32 v31 = p0;
    register f32 v28 = p1;
    register f32 v30 = p2;
    register f32 v29 = p3;
    f32 sp30[24];
    u16 sp20[6];
    GXColor kColor;
    u16 tevColor[4];
    u8 *var_r3;
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
    gxInitRenderState();
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
        DrawList_RestoreNormalMode();
        temp_r5_3 = *(u32 **)((u8 *)temp_r31 + 4);
        temp_f1 = (f32)temp_r5_3[0];
        temp_f2 = (f32)temp_r5_3[1];
        v31 = lbl_805650DC + v31;
        v28 = lbl_805650E0 + -v28;
        v30 = v30 / temp_f1;
        v29 = v29 / temp_f2;
        GXSetZMode(0, 7, 0);
        GXSetColorUpdate(1);
        GXSetAlphaCompare(7, 0, 1, 0, 0);
        temp_r3 = *(u32 **)((u8 *)temp_r31 + 4);
        fn_802E1DA4((u8 *)temp_r31 + 0x50, temp_r3[0], temp_r3[1], v31, v28, v30, v29, lbl_805650D8);
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
        gxInitRenderState();
        KERNEL_GetTimeMs();
    }
}
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
/* Movie-layer query stub: always answers 0.  The movie player's wrapper
 * fn_802ED040 hands it the handle stored in its MoviePlayInfo record (the one
 * fn_802E11A4 opened) and drops the answer, so whatever movie state this would
 * report never reads as set in this build. */
s32 fn_802E1718(void) { return 0; }

