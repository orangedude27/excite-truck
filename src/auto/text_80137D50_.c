// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055E0D8[4];
void fn_8000D838(void *arg0);

void fn_80137D50(void) {
    fn_8000D838(lbl_8055E0D8);
}

void *const D_802ED184 __attribute__((section(".ctors"))) = (void *)fn_80137D50;
