// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80012870();
extern float fn_8020A5F0(void);
extern void fn_802146BC(int *, int, int, int, int, int, int, int);
extern int lbl_802FA320[];
extern char lbl_80342DC8[];
extern int lbl_80498860[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_802445FC(int arg0, int arg1, int arg2) {
    int work[0x1B];
    int *ctx;
    int v0, v1, v2, v3, v4;
    work[22] = fn_80012870();
    work[16] = (int)lbl_80342DC8;
    ctx = &work[16];
    work[21] = 0;
    work[23] = arg2;
    work[24] = 0;
    work[25] = 1000;
    *(float *)&work[26] = fn_8020A5F0();
    v1 = lbl_802FA320[1];
    work[1] = v1;
    work[11] = lbl_80498860[0];
    work[12] = lbl_80498860[1];
    work[7] = 5;
    work[13] = lbl_80498860[2];
    work[14] = lbl_80498860[3];
    work[15] = lbl_80498860[4];
    v0 = lbl_802FA320[0];
    work[0] = v0;
    v2 = lbl_802FA320[2];
    work[2] = v2;
    v3 = lbl_802FA320[3];
    work[3] = v3;
    v4 = lbl_802FA320[4];
    work[4] = v4;
    work[6] = 0;
    work[8] = (int)ctx;
    work[9] = 0;
    work[10] = 0;
    work[1] = (int)&work[6];
    fn_802146BC(work, -999, -999, 1, v4, v3, v2, v1 - v1 + v0);
}
#pragma pop
#pragma scheduling on
#pragma opt_propagation reset
#pragma opt_dead_assignments reset

int fn_802446F8(int object, int deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668();
    }
    return object;
}

/* Sets up a display-list context, initializes and draws it with opaque black, then tears it down. */
void fn_80244738(void) {
    char displayListBuffer[56];

    __AXDSPInitCallback_800216B8();
    fn_80230B5C(displayListBuffer);
    fn_80230AD8(displayListBuffer);
    fn_802C942C(0xFF000000);
    fn_800216C8();
    fn_80230B38();
    fn_800216C4();
}

/* Load race.res and cache timing/state on the arg object. */
void fn_8024477C(void *arg0) {
    extern int lbl_80342E28[];
#define raceResName lbl_80342E28
    fn_8012E81C(&raceResName);
    fn_80021464(*(int *)((char *)arg0 + 0x18), *(int *)((char *)arg0 + 0x1C));
    *(int *)((char *)arg0 + 0x20) = fn_802E2C20();
#undef raceResName
}

extern int lbl_80342E28[];
__declspec(section ".sdata") extern float lbl_805637F0;
__declspec(section ".sdata") extern float lbl_805637F4;
__declspec(section ".sdata") extern double lbl_805637F8;

void fn_802447C4(void *fadeState) {
#define HideOverlay fn_8002167C
#define ClearMusicPlayFlag fn_8020A634
#define SetPlayerMusicVolume fn_8020A5F8
    /* Start a race music fade: hide the tips/results overlay, clear the
     * "music: play!" flag and set player music volume to the state's start value. */
    HideOverlay();
    ClearMusicPlayFlag();
    SetPlayerMusicVolume(*(float *)((char *)fadeState + 0x28));
#undef SetPlayerMusicVolume
#undef ClearMusicPlayFlag
#undef HideOverlay
}

#pragma scheduling invalid_target
void fn_802447FC(void *fadeState) {
    /* Advance a race music fade-out: +0x20 is the fade start time (ms), +0x24
     * its duration, +0x28 the starting volume. Scale that volume by a linear
     * factor falling from 1 to 0 over the duration, set the player music volume,
     * and mark the fade finished (result 0) once time is up, unless the Home menu
     * is open. */
    float factor;
    int elapsedMs;
    float blend;
    elapsedMs = fn_802E2C20() - *(int *)((char *)fadeState + 0x20);
    blend = lbl_805637F4;
    factor = lbl_805637F0 - ((float)elapsedMs / (float)*(int *)((char *)fadeState + 0x24));
    blend = blend > factor ? blend : factor;
    fn_8020A5F8(*(float *)((char *)fadeState + 0x28) * blend);
    if (elapsedMs > *(int *)((char *)fadeState + 0x24) && fn_802ECC10() == 0) {
        fn_80221F94(fadeState, 0);
    }
}
void fn_802448BC(void *fadeState) {
    /* Redraw the tips overlay, then draw a black full-screen quad whose alpha
     * ramps from opaque down to clear over (duration - 50) ms, revealing the
     * scene. +0x20 is the fade start time and +0x24 the duration, both in ms. */
    int elapsedMs;
    int scaled;
    int alpha;
    unsigned char result;
    fn_80021680();
    elapsedMs = fn_802E2C20() - *(int *)((char *)fadeState + 0x20);
    scaled = (elapsedMs << 8) - elapsedMs;
    alpha = 0xFF - scaled / (*(int *)((char *)fadeState + 0x24) - 0x32);
    result = alpha & ((-alpha & ~alpha) >> 31);
    if (result != 0) fn_802C942C(result << 24);
}

