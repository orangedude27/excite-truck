// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055DE20;
extern unsigned int lbl_8055DE70;
/* Point a sound-library pointer global (lbl_8055DE70, returned by fn_800FDE14) at the shared nw4r sound dummy value lbl_8055DE20. */
void fn_800FDE1C(void) {
    #define s_sndDummy lbl_8055DE20
    #define gpSndPointer lbl_8055DE70
    gpSndPointer = (unsigned int)&s_sndDummy;
    #undef gpSndPointer
    #undef s_sndDummy
}
