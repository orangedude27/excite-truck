// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed long s32;

/* No-op stub called once after all mlist item callbacks have been submitted
   (at the end of fn_802CDB5C), apparently to finalize/reset the list builder. */
void fn_802DB2A0(void) {}

/* Empty placeholder hook: invoked in the single-player update when the checked
   value exceeds 0.1, immediately before the fn_802DD754 screen effect. */
void fn_802DB2A4(void) {}

/* Reserve a starting cursor for a run of slotCount list slots; 0 tells the caller to skip the run. */
s32 fn_802DB2A8(s32 slotCount) {
    return 0;
}

/* No-op stub marking the end of a list-building run; slotCount is the number of
   slots finalized via fn_802DB2A8/fn_802DB2B0 in fn_802CDB5C. */
void fn_802DB2B0(s32 slotCount) {}

/* No-op model-manager hook forwarded by fn_802C8230; this build leaves it empty. */
void fn_802DB2B4(void) {}

/* No-op model-config hook: fn_802C8234 forwards the water amplitude value
   here, but this build leaves the setter empty. */
void fn_802DB2B8(void) {}

/* No-op status-hook: mrmodel forwards each torn-down node's status byte
   (and a final 1 after a full refresh); this build ignores it. */
void fn_802DB2BC(void) {}

/* No-op texture trace hook: forwarded a texture slot's +0x28 handle by
   Texture_BindRenderTarget, but this build does nothing with it. */
void fn_802DB2C0(void) {}

/* No-op trace hook: texture.c forwards a texture slot's +0x28 handle here;
   this build discards it. */
void Texture_ShadowMapTraceHook(void) {}

/* No-op blit hook: fn_802C40B8 calls this instead of drawing when the global
   canvas's "no draw" flag (bit 2) is set; this build does nothing. */
void fn_802DB2C8(void) {}

