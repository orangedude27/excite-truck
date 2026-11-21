// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Game-state flags word, cleared by the AX DSP init callback. */
#define gGameStateFlags lbl_8055D430
extern void *gGameStateFlags;

/* AX DSP init callback: clear the game-state flags word. */
void __AXDSPInitCallback(void) {
    gGameStateFlags = 0;
}

void fn_8000D7E4(void) {
    /* Empty callback in the scene/menu shutdown chain; does nothing in this build. */
}
