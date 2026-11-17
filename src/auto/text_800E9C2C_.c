// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055DE20;
void fn_800E9C2C(void) {
    /* Reset to zero the nw4r sound library's shared dummy value, whose address
       fn_800E9C24 returns and several sound pointers use as a default target. */
    #define s_sndDummy lbl_8055DE20
    s_sndDummy = 0;
    #undef s_sndDummy
}
