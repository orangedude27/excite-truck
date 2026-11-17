// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055DEA8;
void fn_801076C4(void) {
    /* Clear the leaf global of the registered-object pointer chain (returned by fn_801076BC) to null. */
#define sLeafObject lbl_8055DEA8
    sLeafObject = 0;
#undef sLeafObject
}
