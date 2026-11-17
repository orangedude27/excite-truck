// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055DDF8;
extern unsigned int lbl_8055DE08;
/* Static initializer: point the global sentinel pointer lbl_8055DE08 at the shared storage word lbl_8055DDF8. */
void fn_800DFC5C(void) {
#define gSharedStorageWord lbl_8055DDF8
#define gpSharedPointer lbl_8055DE08
    gpSharedPointer = (unsigned int)&gSharedStorageWord;
#undef gpSharedPointer
#undef gSharedStorageWord
}
