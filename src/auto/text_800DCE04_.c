// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055DDF8;
extern unsigned int lbl_8055DE00;
/* Initialize a pointer global so it aliases the shared storage word. */
void fn_800DCE04(void) {
#define gSharedStorageWord lbl_8055DDF8
#define gpSharedPointer lbl_8055DE00
    gpSharedPointer = (unsigned int)&gSharedStorageWord;
#undef gpSharedPointer
#undef gSharedStorageWord
}
