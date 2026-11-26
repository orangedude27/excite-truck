// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
void *fn_80265CE0(void *object, int shouldDelete) {
    /* Clears a 3-word object and optionally deletes it. */
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

/* No-op reset hook called from fn_801A5258 with the object and its +0x1EC
 * subobject pointer; this build leaves it empty. */
void fn_80265D38(void) {}

/* No-op teardown hook called with the object from its destructor in
 * text_801A520C_ (just after the vtable is reinstalled); this build leaves it empty. */
void fn_80265D3C(void) {}

/* No-op hook called at the end of the camera/vehicle state reset (fn_801A65FC)
 * with the object, its tracked-object slot (+0x1EC) and a scalar value (1.0);
 * this build leaves it empty. */
void fn_80265D40(void *object, int objectSlot, float scalarValue) {}

/* No-op teardown hook called from the destructor fn_801A669C (text_801A6370_.c)
 * just after the vtable is reinstalled and before the owned buffer at +0x2700
 * is released; this build leaves it empty. */
void fn_80265D44(void) {}

/* No-op per-frame loop-start subsystem hook: called first in the main-loop
 * iteration fn_80004E20, paired with fn_80265D4C at its end; this build leaves
 * it empty. */
void fn_80265D48(void) {}

/* No-op per-frame loop-end subsystem hook: paired with fn_80265D48 at the
 * start of each main-loop iteration (fn_80004E20); this build leaves it empty. */
void fn_80265D4C(void) {}

/* No-op MP-client stub: called from the restart menu's "stop" path (fn_8000B42C)
   when the client wants a restart but is not running; this build has no MP client. */
void fn_80265D50(void) {}

/* No-op MP-client stub taking a mode/flags argument (called with 2 from the
   game-loop restart menu in fn_8000B42C); this build has no MP client. */
void fn_80265D54(int mode) {
}

/* Stub getter, always 0: the third memory figure of the debug "info" blocks,
 * filled in next to the two heap "bytes used" counters read by fn_80128314
 * (callers: the "msingle:do_event()" report and the track-editor screen). */
int fn_80265D58(void) { return 0; }

/* No-op MP-client session-reset stub: called from the game init/reset pass
 * (fn_80179320) with a pointer to the session block at gGameState+0x32F0.
 * Other builds clear per-player session state here; this build has no MP client. */
void fn_80265D60(int *sessionState) {
}

/* MP-client query stub: always answers 0 ("wants restart" is false). */
int fn_80265D64(void) {
    return 0;
}

/* MP-client query stub: always answers 0 (false / nothing to report). */
int fn_80265D6C(void) { return 0; }

/* No-op stub: invoked in the state-0xD setup sequence of fn_8000AF1C, alongside
   the other subsystem hooks; this build leaves it empty. */
void fn_80265D74(void) {}

/* No-op stub: called during startup subsystem initialization in fn_8000B09C;
   this build leaves it empty. */
void fn_80265D78(void) {}

/* CarMgr query stub: always answers 0 (false), so CAR_TYPE_R ('R') cars are never in play in this build. */
int fn_80265D7C(void) { return 0; }

/* No-op per-step subsystem hook: called from the main game step (fn_80177F40)
 * alongside the other subsystem update hooks, after clearing gGameState+0x2E0.
 * This build leaves it empty. */
void fn_80265D84(void) {}

/* No-op stub: called near the end of fn_80177F40's state transition; this build
   leaves it empty. */
void fn_80265D88(void) {}

/* No-op scene-init subsystem hook: called from the scene setup sequence
 * (fn_801E7984) with the scene-data pointer; this build leaves it empty. */
void fn_80265D8C(void *sceneData) {}

/* No-op subsystem-shutdown stub: called from WorldEndCommon (endWorldCommon)
 * among the race-subsystem teardown hooks; this build leaves it empty. */
void fn_80265D90(void) {}

/* No-op stub in the MP-client/subsystem hook cluster; unreferenced in this build. */
void fn_80265D94(void) {}

/* Camera move-follow blend-parameter query stub: returns null in this build,
 * so callers fall back to fully blending the camera with 1.0 factors. */
float *fn_80265D98(void) {
    return 0;
}

