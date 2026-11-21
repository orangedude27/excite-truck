// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;

/* No-op stub called once after all mlist item callbacks have been submitted
   (at the end of fn_802CDB5C), apparently to finalize/reset the list builder. */
void fn_802DB2A0(void) {
}

void fn_802DB2A4(void) {
    // Empty placeholder hook: invoked in the single-player update when the checked
    // value exceeds 0.1, immediately before the fn_802DD754 screen effect.
}

s32 fn_802DB2A8(s32 slotCount) {
    // Reserve a starting cursor for a run of slotCount list slots; 0 tells the caller to skip the run.
    return 0;
}

/* No-op stub marking the end of a list-building run; slotCount is the number of
   slots finalized via fn_802DB2A8/fn_802DB2B0 in fn_802CDB5C. */
void fn_802DB2B0(s32 slotCount) {
}

/* No-op model-manager hook forwarded by fn_802C8230; this build leaves it empty. */
void fn_802DB2B4(void) {}

/* No-op model-config hook: fn_802C8234 forwards the water amplitude value
 * here, but this build leaves the setter empty. */
void fn_802DB2B8(void) {}

void fn_802DB2BC(void) {}

void fn_802DB2C0(void) {}

void fn_802DB2C4(void) {}

void fn_802DB2C8(void) {}

