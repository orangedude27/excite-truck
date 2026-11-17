// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055DE20;
extern unsigned int lbl_8055DE48;
/* Point a sound pointer global at the nw4r sound library's shared dummy value. */
void fn_800F0E58(void) {
#define s_sndDummy lbl_8055DE20
#define gpSndPointer lbl_8055DE48
    gpSndPointer = (unsigned int)&s_sndDummy;
#undef gpSndPointer
#undef s_sndDummy
}
