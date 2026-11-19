// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801FC8D8(void);
extern void fn_801EBBB4(void);
extern void fn_801EBD70(void);
extern void fn_801EBDCC(void);
extern void fn_801FC8A8(void);
extern void fn_801EBEF4(float);
extern void fn_801EB9FC(void *);
extern const float lbl_80563028;
extern char lbl_8033B5C8[];
#pragma scheduling on
void fn_801FC8A8(void) {
    /* Initialize the track.grf resource by setting its default EB scale to 2.0 and loading "track.grf". */
    fn_801EBEF4(lbl_80563028);
    fn_801EB9FC(lbl_8033B5C8);
}
void fn_801FC8D8(void) {
    fn_801EBBB4();
}

#pragma dont_inline on
int fn_801FC8DC(void) {
#define InitTrackGrf fn_801FC8A8
    /* Initialize the track.grf EB resource (default parameter value and resource load), then report success. */
    InitTrackGrf();
    return 1;
#undef InitTrackGrf
}
/* Release the "track.grf" EB resource: the shutdown half of the pair whose init
 * is fn_801FC8A8 / fn_801FC8DC.  Tail-calls fn_801FC8D8 (-> fn_801EBBB4), which
 * releases the two resource handles lbl_8055AFBC / lbl_8055AFB8, clears the
 * 24-entry cached subsystem table lbl_804885E8 and frees the EB context
 * lbl_8055EBA0 (or resets the UI subsystems when there is none).  The race's
 * WorldEndCommon (fn_801E7C28) calls this while tearing the world down. */
void fn_801FC900(void) {
#define ReleaseTrackGrf fn_801FC8D8
    ReleaseTrackGrf();
#undef ReleaseTrackGrf
}

void fn_801FC904(void) {
    fn_801EBD70();
}

void fn_801FC908(void) {
    fn_801EBDCC();
}

