// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055D430;
/* AX DSP init callback: clear the game-state flags word (lbl_8055D430). */
void __AXDSPInitCallback(void) {
#define gGameStateFlags lbl_8055D430
    gGameStateFlags = 0;
#undef gGameStateFlags
}

void fn_8000D7E4(void) {
}
