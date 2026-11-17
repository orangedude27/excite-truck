// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned int lbl_8055DDF8;
extern unsigned int lbl_8055DE10;
// Static constructor: point lbl_8055DE10 at the shared storage word lbl_8055DDF8 that several globals alias.
void fn_800E2520(void) {
    lbl_8055DE10 = (unsigned int)&lbl_8055DDF8;
}
