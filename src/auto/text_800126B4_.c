// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_801EA4B4(void*, int);
/* Set up the per-entry table from the counted word array in `source`
 * (count at +0x24, values at +0x28); the first parameter is unused. */
void fn_800126B4(void* unused, void* source) {
    fn_801EA4B4((char*)source + 0x28, *(int*)((char*)source + 0x24));
}

extern void fn_801EA4B8(void);
void fn_800126C0(void) {
    fn_801EA4B8();
}

