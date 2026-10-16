// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055DA2C;
extern int lbl_8055DA44;
extern unsigned int lbl_800030F0;
extern void *memcpy(void *, const void *, unsigned int);
extern void ICFlashInvalidate(void);
extern int lbl_8055DA44;
extern unsigned int lbl_800030F0;
extern void *memcpy(void *, const void *, unsigned int);
extern void ICFlashInvalidate(void);
void fn_8004DD88(void (*target)(void)) {
    ICFlashInvalidate();
    __asm_sync_placeholder();
    target();
}

void __AXDSPInitCallback_8004DDC4(void) {
    lbl_8055DA44 = 1;
}

void fn_8004DDF4(void* hi) {
    lbl_8055DA2C = hi;
}
