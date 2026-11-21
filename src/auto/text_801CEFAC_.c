/* Replay-mode state helpers: enter/leave replay, toggle it via the arena-event
 * subsystem, and start/end cutscene replay playback with a debug log. */

extern char lbl_8055AB50;
extern char lbl_8055E8A0;
extern char lbl_8055E8A1;
#define sReplayMode      lbl_8055AB50 /* nonzero while replay mode is active */
#define sReplayPlayback  lbl_8055E8A0 /* nonzero while cutscene replay is playing */
#define sReplayAuxFlag   lbl_8055E8A1 /* secondary flag raised on entering replay */
extern void fn_801AED68(void);
extern void fn_801AED5C(void);
/* Enter replay mode: raise the replay and auxiliary flags while clearing the
 * in-playback flag. */
void fn_801CEFAC(void) {
    sReplayMode = 1;
    sReplayPlayback = 0;
    sReplayAuxFlag = 1;
}

/* Leave replay mode: clear the replay-mode and in-playback flags. */
void fn_801CEFC4(void) {
    sReplayMode = 0;
    sReplayPlayback = 0;
}

/* Set the replay-mode flag and enable or disable its associated subsystem. */
void fn_801CEFD4(int enabled) {
    sReplayMode = enabled;
    if (enabled) {
        fn_801AED68();
    } else {
        fn_801AED5C();
    }
}

extern char lbl_8033807C[];
extern char lbl_80338060[];
#define sLogReplayStart  lbl_80338060 /* "CSReplayStartReplayPlayback" */
#define sLogReplayEnd    lbl_8033807C /* "CSReplayEndReplayPlayback" */
extern void fn_802E30C8(char *, ...);
#pragma scheduling invalid_target
/* Log that cutscene replay playback has started and set the in-playback flag. */
void fn_801CEFE8(void) {
    fn_802E30C8(lbl_80338060);
    lbl_8055E8A0 = 1;
}
#pragma scheduling on
void fn_801CF01C(void) {
    /* Log that cutscene replay playback ended and clear the in-playback flag. */
    char *message;
    message = lbl_8033807C;
    fn_802E30C8(message);
    lbl_8055E8A0 = 0;
}

#pragma scheduling on
/* Return nonzero while replay mode is active (lbl_8055AB50 flag set). */
int fn_801CF050(void) {
    return *(unsigned char *)&lbl_8055AB50 != 0;
}

/* Return nonzero while cutscene replay playback is in progress (in-playback flag). */
int fn_801CF064(void) {
    return *(unsigned char *)&lbl_8055E8A0 != 0;
}

