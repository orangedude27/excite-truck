// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801EBBB4(void);
extern void fn_801EBD70(void);
extern void fn_801EBDCC(void);
extern void fn_801EBEF4(float);
extern void fn_801EB9FC(void *);
extern const float lbl_80563028;
extern char lbl_8033B5C8[];
#pragma scheduling on
/* Initialize the track.grf resource by setting its default EB scale to 2.0 and loading "track.grf". */
void fn_801FC8A8(void) {
    fn_801EBEF4(lbl_80563028);
    fn_801EB9FC(lbl_8033B5C8);
}

/* Shut the "track.grf" EB resource down: tail-call the shared EB teardown
 * (fn_801EBBB4), which releases the two resource handles lbl_8055AFBC and
 * lbl_8055AFB8, then destroys the gEBContext singleton lbl_8055EBA0 and
 * frees its block -- or, when no context is loaded, brings down the whole
 * list of engine subsystems (fn_802AE9D0) instead. */
void fn_801FC8D8(void) {
    fn_801EBBB4();
}

#pragma dont_inline on
/* Initialize the track.grf EB resource (default parameter value and resource load), then report success. */
int fn_801FC8DC(void) {
#define InitTrackGrf fn_801FC8A8
    InitTrackGrf();
    return 1;
#undef InitTrackGrf
}

/* Release the "track.grf" EB resource: the shutdown half of the pair whose init
 * is fn_801FC8A8 / fn_801FC8DC.  Tail-calls fn_801FC8D8 (-> fn_801EBBB4), which
 * releases the two resource handles lbl_8055AFBC / lbl_8055AFB8, clears the
 * 24-entry cached subsystem table lbl_804885E8 and frees the EB context
 * lbl_8055EBA0 (or resets the UI subsystems when there is none).  The race's
 * WorldEndCommon (endWorldCommon) calls this while tearing the world down. */
void fn_801FC900(void) {
#define ReleaseTrackGrf fn_801FC8D8
    ReleaseTrackGrf();
#undef ReleaseTrackGrf
}

/* Scene step for the case where no EB scene context (gEBContext,
 * lbl_8055EBA0) is loaded: tail-call fn_801EBD70, which ticks the UI
 * (fn_802B0144) and, when the UI flag lbl_8055EB2C is 1, hands the current
 * player's progress (player config +0x34, fn_801E8738) to the active screen
 * object (fn_802BF598).  The per-frame scene step fn_801EA404 calls it
 * before fn_801FC908, which does the same for the loaded-context case. */
void fn_801FC904(void) {
#define StepEBWithoutScene fn_801EBD70
    StepEBWithoutScene();
#undef StepEBWithoutScene
}

/* Per-frame scene step for the loaded-context case: tail-call fn_801EBDCC,
 * which runs the engine update sequence while the EB scene context
 * (gEBContext, lbl_8055EBA0) exists -- subsystem refresh, the projection
 * setup picked by the camera-mode flag (fn_801EA470) and the scene object
 * tick -- or, with no context loaded, the menu-side update fn_802B01A8.
 * fn_801EA404 calls it after its sibling step for the empty case,
 * fn_801FC904. */
void fn_801FC908(void) {
#define StepEBScene fn_801EBDCC
    StepEBScene();
#undef StepEBScene
}

