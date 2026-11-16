// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80129BD4(void) {
    /* Per-frame hook: refresh the seven RNG states, then tick the TOC subsystem. */
    fn_80129C24();
    fn_8012BE90();
}

void fn_80129BF8(void* alarm) {
    /* Alarm callback: run the fn_8012C4E8 resource cleanup, then the fn_80129C60 handler. */
    fn_80129C60(fn_8012C4E8(alarm));
}

