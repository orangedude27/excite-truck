#include "revolution/MTX/mtxtypes.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern float lbl_80563140;
extern float lbl_80563144;

extern void fn_80128668(void*);
void* fn_80203F88(void* object, int shouldDelete) {
    /* Reset the object's three 32-bit fields to 0, then free it when
     * shouldDelete > 0 (deleting-destructor style helper). */
    if (object != 0) {
        if (object != 0) {
            *(int *)object = 0;
            *((int *)object + 1) = 0;
            *((int *)object + 2) = 0;
        }
        if (shouldDelete > 0)
            fn_80128668(object);
    }
    return object;
}

/* Returns the constant 16.0f held in lbl_80563140; callers use it as a fixed
 * scale/divisor, e.g. the 16-unit grid spacing when placing scene objects
 * (fn_801E95DC). */
float fn_80203FE0(void) { return lbl_80563140; }

/* No-op virtual-method stub in this unit's run of empty defaults: called during the world/object reset sequence but does nothing. */
void fn_80203FE8(void) {

}

/* Empty end-of-pass hook: updateStageDistanceAnims calls this after walking the nearby-object
 * lists (switching each object's animation on/off by distance).  Like the other
 * stubs of this unit it is linked in but does nothing in this build. */
void fn_80203FF8(void) {

}

/* No-op virtual-method default in this unit's run of empty stubs: reached only
 * through its owner's method table, where it intentionally does nothing. */
void fn_80204000(void) {

}

/* No-op virtual-method default in this unit's run of empty stubs: reached only
 * through its owner's method table, where it intentionally does nothing. */
void fn_80204008(void) {

}

/* One of this unit's run of trivial virtual-method stubs (the class whose global
 * instance fn_80203F10 registers for destruction): always answers 0/false.  No
 * code in the decomp calls it directly, so it is only reached through the
 * object's table of methods. */
int fn_8020400C(void) {
    return 0;
}

/* Notification sink that ignores everything it is handed.  The stage-object code
 * forwards a notification to it as (message code, the notified object's
 * resource-getter at +0x34, the sender's field at +0x19C, the sender itself)
 * when that notification has no effect in this build: fn_801FB40C forwards
 * straight here, and fn_801FC654 calls it through a three-argument function
 * pointer with the global resource manager in place of the sender. */
void fn_80204014(s32 code, s32 resourceGetter, s32 senderValue, void *sender) {

}

/* Stage-load half of the dynamic-object spawner, empty in this build.
 * fn_801F973C(typeDef, params, flags) walks a type definition's object list
 * (links at +0x24) and calls each entry's create method (vtable at +0x108, slot
 * index 4) with a parameter record built from the entry's +0x30 / +0x54
 * transforms plus the caller's params; when bit 0 of flags is set it then
 * forwards (typeDef, params) here as well.  Runtime spawns pass flags 2
 * (fn_801FA7F4), so only the stage load -- fn_801F9B28 -> fn_801F9928(list, 3)
 * over a resource's "objects" child -> fn_801F981C -> fn_801F973C -- reaches
 * this hook, where the per-type extra setup would happen. */
void fn_80204018(void *typeDef, void *params) {

}

/* Terrain/solid module's stage-init hook: empty in this build.  The
 * SolBuilder/StaticGOB subsystem init (fn_801F9E04) calls it last, once its
 * "race.res/obstacle.val" / "%s.trk/obstacle.val" / "tree.class.val" resource
 * names are logged, its 4-byte "SolBuilder" handle is allocated and its
 * GOB-flag event handler (fn_801F9CF8, event 0xC) is registered, handing it the
 * stage context it was given.  fn_80204020 is the matching (also empty) hook of
 * the teardown path fn_801F9F08, so this is where the terrain solids of a stage
 * would be built if this build did anything with them. */
void fn_8020401C(void *stageContext) {

}

/* Terrain/solid module's stage-shutdown hook: empty in this build, and the
 * counterpart of the init hook fn_8020401C.  The SolBuilder/StaticGOB subsystem
 * shutdown (fn_801F9F08) calls it first, right after unregistering the GOB-flag
 * event handler fn_801F9CF8 and before it drops the "SolBuilder" handle, frees
 * the sorted "StaticGOB tab" (lbl_8055EC54) and clears the two static-object
 * lists (lbl_8055EC4C / lbl_8055EC50) -- i.e. where the stage's terrain solids
 * would be released. */
void fn_80204020(void) {

}

int fn_80204024(void) {
    /* One of this unit's run of trivial virtual-method stubs: it answers 0/false
     * and callers use it as an "active/running" flag that never actually stops
     * the loop (e.g. the main-loop checks in text_8023B764_/text_8000AC98_). */
    return 0;
}

int fn_8020402C(void) {
    /* Another of this unit's trivial virtual-method stubs: always answers 0/false.
     * The world-setup path calls it as a "setup already active" guard (it never is). */
    return 0;
}

/* Empty entry point of the terrain/solid (SolBuilder/StaticGOB) module -- the unit
 * that owns the stage init/shutdown hooks fn_8020401C/fn_80204020, the "setup
 * already active" guard fn_8020402C and the screen-ray ground probe fn_80204054.
 * Unlike its neighbours fn_8020401C/fn_80204020/fn_8020402C, which the world setup
 * calls, nothing in the game calls this one or takes its address, so it is one of
 * the module's defaults that is linked in but never reached. */
void fn_80204034(void) {

}

/* Empty default of the terrain/solid (SolBuilder/StaticGOB) module, the run of
 * stubs that also holds the stage hooks fn_8020401C/fn_80204020 and the screen-ray
 * ground probe fn_80204054.  It sits between the two unreferenced stubs of that
 * run -- like fn_80204034 nothing calls it or takes its address -- just before the
 * always-true enable flag fn_8020403C, so the entry point stays empty here. */
void fn_80204038(void) {

}

int fn_8020403C(void) {
    /* A stub from the same run of virtual-method defaults as fn_80204024/2C, but
     * this one always answers 1/true.  Callers use it as an enable flag (aliased
     * as isDebugDrawEnabled in text_802BC334_), so that path is always taken. */
    return 1;
}

/* "tedash.val" terrain debug viewer, view mode 5: draw one sampled grid cell in
 * world space.  fn_802B6F34() walks the brush area and calls the viewer's brush
 * callback applyBrushSample() for every bilinearly sampled cell; in mode 5 that
 * callback reports the sample here with the cell's world position (its grid
 * coordinates scaled by 2.0), inside the overlay begun by fn_80204048() and
 * closed by fn_8020404C().  The overlay draws nothing in this build, so this
 * hook ignores all three arguments. */
void drawDebugWorldPoint(s32 sample, f32 worldX, f32 worldY) {

}

/* "tedash.val" terrain debug viewer, view mode 5: open the world-space overlay
 * that the sampled cells are reported to (drawDebugWorldPoint) and closed by
 * fn_8020404C().  fn_802B6F34() hands it the two opposite corners of the brush
 * area in world units -- corner0 (x,y) at grid cell (0,0) and corner1 (x,y) at
 * (width-1,height-1), each a pair of floats -- plus the far corner's unscaled
 * grid x.  The overlay draws nothing in this build, so all three are ignored. */
void fn_80204048(f32 *corner0, f32 *corner1, f32 farGridX) {

}

/* "tedash.val" terrain debug viewer, view mode 5: close the world-space overlay
 * fn_80204048() opened for one brush pass.  fn_802B6F34() calls it once every
 * sampled cell of the brush area has been reported to drawDebugWorldPoint(), so this is
 * where the overlay would be flushed to the screen -- and, like the other two
 * hooks of that pass, it draws nothing in this build. */
void fn_8020404C(void) {

}

/* Terrain/solid (SolBuilder) hook called once the stage's "track.sol" resource has
 * been applied to the static-object table.  fn_801FA9AC (run at the end of the
 * world setup, from WorldBeginCommon's sequence) looks up "track.sol", copies each
 * of its entries onto the static object whose id matches, frees the resource, then
 * calls this before walking the two static-object lists (lbl_8055EC4C /
 * lbl_8055EC50) to register the objects that no entry claimed -- i.e. where the
 * track's solid geometry would be built from the freshly loaded data.  It does
 * nothing in this build. */
void fn_80204050(void) {

}

extern int lbl_8055CFF0;
extern int lbl_8055CFF4;
extern float lbl_8055FC88;
extern float lbl_80563148;
extern float lbl_8056314C;
extern float lbl_80563150;
extern float lbl_80563154;
extern float lbl_80563158;
extern char lbl_8033BAD8[];
extern void PSVECNormalize(void *, void *);
extern void fn_801E9DC4(short *);
extern int fn_801E9E78(void *, void *, int, int);
extern void fn_802E30C8(const char *, ...);
extern double __fabs(double);
extern double lbl_80563160;
#pragma push
#pragma fp_contract on
static inline f32 fn_80204054_cvt(u32 value, f64 bias) {
    union { f64 d; u32 w[2]; } cvt;
    cvt.w[0] = 0x43300000;
    cvt.w[1] = value ^ 0x80000000;
    return (f32)(cvt.d - bias);
}
#pragma pop
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
s32 fn_80204054(Vec *outPos, Vec *outNormal, s16 *context, f32 *m, s32 screenX, s32 screenY) {
    Vec dir;
    Vec pos;
    Vec hit;
    Vec orig;
    s32 info;
    s16 localContext;
    f32 x, y, z, p, q, r, a, b, c;
    f32 dy, dx, scale;
    register f32 step, dist, minStep, maxDist, mult, tol;
    s32 noHit, flagB, found;

    scale = (f32)(lbl_8055CFF0 / 2) / lbl_8055FC88;
    dx = (f32)(screenX - lbl_8055CFF0 / 2);
    dy = (f32)(screenY - lbl_8055CFF4 / 2);

    a = m[6] * scale;
    b = m[7] * scale;
    c = m[8] * scale;
    p = m[0] * dx;
    q = m[1] * dx;
    r = m[2] * dx;
    dy = -dy;
    x = m[3] * dy;
    y = m[4] * dy;
    z = m[5] * dy;
    dir.x = a + p + x;
    dir.y = b + q + y;
    dir.z = c + r + z;
    PSVECNormalize(&dir, &dir);

    if (context == 0) {
        context = &localContext;
    }

    step = 10.0f;
    tol = 0.0254f;
    dist = step;
    mult = 0.5f;
    maxDist = 10000000.0f;
    minStep = 0.01f;
    flagB = 0;

    for (;;) {
        f32 px, py, pz;
        found = 0;
        px = m[9] + dir.x * dist;
        py = m[10] + dir.y * dist;
        pz = m[11] + dir.z * dist;
        orig.x = px;
        orig.y = py;
        orig.z = pz;
        pos.x = px;
        pos.y = py;
        pos.z = pz;

        fn_801E9DC4(context);
        noHit = (fn_801E9E78(context, &pos, (s32)&hit, (s32)&info) == 0);
        if (noHit == 0) {
            if (pos.y > orig.y) {
                found = 1;
                goto block11;
            }
            if ((f32)__fabs((f64)(pos.y - orig.y)) > tol) {
                if (flagB != 0) {
                    step *= mult;
                }
                dist += step;
                goto block11;
            }
        } else {
            found = 1;
        block11:
            if (found != 0) {
                step *= mult;
                flagB = 1;
                dist -= step;
            }
            if (dist > maxDist) {
                noHit = 1;
                fn_802E30C8(lbl_8033BAD8, orig.x, orig.z);
            } else if (step > minStep) {
                continue;
            }
        }
        if (noHit == 0) {
            outPos->x = pos.x;
            outPos->y = pos.y;
            outPos->z = pos.z;
            if (outNormal != 0) {
                outNormal->x = hit.x;
                outNormal->y = hit.y;
                outNormal->z = hit.z;
            }
        }
        return noHit == 0;
    }
}
/* Empty scratch hook of this unit -- the stage/terrain module that owns the
 * screen-ray ground probe fn_80204054.  Its neighbours here are the no-op
 * handlers this module supplies where a caller expects a function: fn_80204014
 * (the scratch handler the resource loader forwards to), fn_80204018 (empty
 * stage-object handler) and drawDebugWorldPoint (debug world-point draw, empty in this
 * build).  No function in the game calls fn_80204004, so this one is never even
 * reached; it does nothing either way. */
void fn_80204004(void) {

}

/* Terrain-system hook that does nothing in this build.  It belongs to the run of
 * empty terrain defaults in this unit -- fn_80203FE8 (called from the world
 * teardown sequence), fn_80203FEC (end of world setup) and fn_80203FF8 (end of
 * the per-frame animation pass) -- next to the screen-ray ground probe
 * fn_80204054 and its "TERRAIN SYSTEM IS LYING: no terrain is really at %.2f,
 * %.2f" warning.  No function in the game calls it, so the terrain subsystem
 * simply leaves this entry point empty. */
void fn_80203FFC(void) {

}

/* No-op reset hook of the terrain/environment module (the unit that owns the
 * screen-ray ground probe fn_80204054 and its "TERRAIN SYSTEM IS LYING: no
 * terrain is really at %.2f, %.2f" warning, and whose global imap resource list
 * lbl_8048897C is torn down by fn_80203F88).  WorldBeginCommon (fn_801E7984)
 * calls it at the end of the race/world setup, between the other subsystem
 * resets and the boot-progress checkpoint fn_80127464; like the other empty
 * defaults of this unit it does nothing in this build. */
void fn_80203FEC(void) {

}

/* Virtual-method getter: returns the constant 0.0f (held in lbl_80563144).
 * Callers add it as a zero base to a computed value, e.g.
 * lbl_8055F98C = fn_80203FF0() + var_f17 (text_802AE588_). */
float fn_80203FF0(void) { return lbl_80563144; }

extern float lbl_80563140;
extern float lbl_80563144;
