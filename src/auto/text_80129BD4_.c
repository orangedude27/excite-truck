// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* fn_80129C24 seeds the seven RNG state blocks; fn_8012BE90 initializes the
 * TOC/resource subsystem; fn_8012C4E8 tears it down; fn_80129C60 is an empty
 * completion hook. */

/* Per-frame hook: reseed the RNGs, then tick the TOC subsystem. */
void fn_80129BD4(void) {
    fn_80129C24();
    fn_8012BE90();
}

/* Alarm callback: tear down the TOC/resource subsystem, then run the completion hook. */
void fn_80129BF8(void* alarm) {
    fn_8012C4E8(alarm);
    fn_80129C60();
}

