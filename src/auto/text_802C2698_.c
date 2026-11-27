// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>
extern void fn_80128668(void *);
extern s32 fn_8012C33C(void *);
extern s32 RegisterTextureByName(void *, s32);
extern s32 fn_802CB128(s32, s32, s32, s32);
extern void fn_802CB228();
extern void fn_802CAC54();
extern char lbl_8034AFF8[16];
extern s32 lbl_8055FB6C;
extern s32 lbl_8055FB70;

// The level's "swlmap" light map, held as two src/game/texture.c slots: the
// swlmap.tex file when the disc has it, otherwise a 512x512 "rtarg" render
// target the game draws the map into itself (fn_802C276C).
#define ResFindFile fn_8012C33C        /* is this resource name in the archive? */
#define TextureLoad RegisterTextureByName        /* load a .tex file into a slot; the slot number */
#define RenderTargetCreate fn_802CB128 /* make a "rtarg" render-target slot, width, height */
#define RenderTargetFree fn_802CB228   /* free a render-target slot */
#define TextureFree fn_802CAC54        /* release a loaded texture slot */
#define NO_TEXTURE_SLOT (-2)           /* the "no slot" value of the two globals below */
#define sSwlMapName lbl_8034AFF8       /* "swlmap.tex" */
#define sSwlMapTargetSlot lbl_8055FB6C /* render target, NO_TEXTURE_SLOT when the file loaded */
#define sSwlMapFileSlot lbl_8055FB70   /* swlmap.tex's slot, NO_TEXTURE_SLOT when absent */

void *fn_802C2698(void *object, s32 shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            *(s32 *)object = 0;
            *((s32 *)object + 1) = 0;
            *((s32 *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Prepare the level's swlmap light map: load "swlmap.tex" from the archive when
 * the disc has it, and otherwise make a 512x512 render target to draw it into. */
void fn_802C26F0(void) {
    char *name = sSwlMapName;
    s32 fileSlot;
    s32 targetSlot;

    if (ResFindFile(name) != 0)
        fileSlot = TextureLoad(name, 0);
    else
        fileSlot = NO_TEXTURE_SLOT;
    sSwlMapFileSlot = fileSlot;
    if (fileSlot == NO_TEXTURE_SLOT)
        targetSlot = RenderTargetCreate(0x200, 0x200, 0, 1);
    else
        targetSlot = NO_TEXTURE_SLOT;
    sSwlMapTargetSlot = targetSlot;
}

extern s32 fn_801D9B58(void); /* draw the current scene */
extern s32 fn_802C2C00(s32); /* save/restore the depth-test state word */
extern s32 DrawList_loadMatrix(f32 *, f32, f32, f32, f32); /* set a transform matrix and scale */
extern s32 fn_802C86E8(s32); /* set the clear color */
extern s32 DrawList_setViewport(s32, s32, s32, s32); /* set a screen rectangle */
extern s32 HomeMenu_applySavedFade(s32); /* set a render mode (-1 resets) */
extern s32 fn_802C9294(s32, s32); /* select the active texture and draw flags */
extern s32 setCameraProjection(f32, f32, f32); /* update projection / field-of-view parameters */
extern s32 Texture_BindRenderTarget(s32); /* bind a render target */
/* Swlmap transform constants: a runtime intensity scale, then the literal
 * values 1/512, 0, 512, 0.5, 1, -1, 100 and pi/2. */
extern f32 lbl_8055FB74; /* runtime swlmap intensity scale */
extern f32 lbl_80564EB4; /* 1/512 */
extern f32 lbl_80564EB8; /* 0.0f */
extern f32 lbl_80564EBC; /* 512.0f */
extern f32 lbl_80564EC0; /* 0.5f */
extern f32 lbl_80564EC4; /* 1.0f */
extern f32 lbl_80564EC8; /* -1.0f */
extern f32 lbl_80564ECC; /* 100.0f */
extern f32 lbl_80564ED0; /* pi/2 */
#pragma scheduling invalid_target
/* When the level's swlmap.tex is absent, render the light map into its 512x512
 * render target: bind the target, build the transform from the runtime scale,
 * draw the map in a saved graphics state, then release the target. */
void fn_802C276C(void) {
    #define SWL_INTENSITY  lbl_8055FB74   /* runtime light-map scale */
    #define SWL_INV_SIZE   lbl_80564EB4   /* 1/512 */
    #define SWL_ZERO       lbl_80564EB8   /* 0.0f */
    #define SWL_SIZE       lbl_80564EBC   /* 512.0f */
    #define SWL_HALF       lbl_80564EC0   /* 0.5f */
    #define SWL_ONE        lbl_80564EC4   /* 1.0f */
    #define SWL_NEG_ONE    lbl_80564EC8   /* -1.0f */
    #define SWL_DEPTH      lbl_80564ECC   /* 100.0f */
    #define SWL_HALF_PI    lbl_80564ED0   /* pi/2 */

    f32 transform[12];
    f32 halfScale;
    f32 scale;
    s32 savedState;

    if (sSwlMapFileSlot == NO_TEXTURE_SLOT) {
        Texture_BindRenderTarget(sSwlMapTargetSlot);
        fn_802C9294(sSwlMapTargetSlot, 0);
        scale = SWL_INTENSITY * SWL_INV_SIZE;
        scale = SWL_SIZE * scale;
        halfScale = scale * SWL_HALF;
        transform[9] = SWL_ZERO;
        transform[11] = SWL_ZERO;
        transform[10] = halfScale;
        transform[0] = SWL_ONE;
        transform[1] = SWL_ZERO;
        transform[2] = SWL_ZERO;
        transform[3] = SWL_ZERO;
        transform[4] = SWL_ZERO;
        transform[5] = SWL_NEG_ONE;
        transform[6] = SWL_ZERO;
        transform[7] = SWL_NEG_ONE;
        transform[8] = SWL_ZERO;
        DrawList_loadMatrix(transform, SWL_ONE, halfScale, scale, SWL_ZERO);
        DrawList_setViewport(0, 0, 0x200, 0x200);
        setCameraProjection(SWL_ONE, SWL_DEPTH + transform[10], SWL_HALF_PI);
        fn_802C86E8(0xFF00FF00);
        HomeMenu_applySavedFade(-1);
        savedState = fn_802C2C00(0);
        fn_801D9B58();
        fn_802C2C00(savedState);
        fn_802C9294(-1, 0);
    }

    #undef SWL_INTENSITY
    #undef SWL_INV_SIZE
    #undef SWL_ZERO
    #undef SWL_SIZE
    #undef SWL_HALF
    #undef SWL_ONE
    #undef SWL_NEG_ONE
    #undef SWL_DEPTH
    #undef SWL_HALF_PI
}
#pragma scheduling reset
void fn_802C2874(void) {
    /* Release the swlmap render-target and texture slots when allocated. */
    if (sSwlMapTargetSlot != NO_TEXTURE_SLOT) {
        RenderTargetFree(sSwlMapTargetSlot);
        sSwlMapTargetSlot = NO_TEXTURE_SLOT;
    }
    if (sSwlMapFileSlot != NO_TEXTURE_SLOT) {
        TextureFree(sSwlMapFileSlot);
        sSwlMapFileSlot = NO_TEXTURE_SLOT;
    }
}

s32 fn_802C28C0(void) {
    /* Return the active swlmap texture slot: the loaded file's slot when
     * present, otherwise the fallback render target. */
    if (sSwlMapFileSlot != NO_TEXTURE_SLOT)
        return sSwlMapFileSlot;
    return sSwlMapTargetSlot;
}

