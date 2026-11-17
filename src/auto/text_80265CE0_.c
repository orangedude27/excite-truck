// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void*);
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

void fn_80265D38(void) {}

void fn_80265D3C(void) {}

void fn_80265D40(void) {}

void fn_80265D44(void) {}

void fn_80265D48(void) {}

void fn_80265D4C(void) {}

void fn_80265D50(void) {}

void fn_80265D54(void) {}

int fn_80265D58(void) { return 0; }

void fn_80265D60(void) {}

/* MP-client query stub: always answers 0 ("wants restart" is false). */
int fn_80265D64(void) {
    return 0;
}

/* MP-client query stub: always answers 0 (false / nothing to report). */
int fn_80265D6C(void) { return 0; }

void fn_80265D74(void) {}

void fn_80265D78(void) {}

/* CarMgr query stub: always answers 0 (false), so CAR_TYPE_R ('R') cars are never in play in this build. */
int fn_80265D7C(void) { return 0; }

void fn_80265D84(void) {}

void fn_80265D88(void) {}

void fn_80265D8C(void) {}

void fn_80265D90(void) {}

void fn_80265D94(void) {}

/* Camera move-follow blend-parameter query stub: returns null in this build,
 * so callers fall back to fully blending the camera with 1.0 factors. */
float *fn_80265D98(void) {
    return 0;
}

