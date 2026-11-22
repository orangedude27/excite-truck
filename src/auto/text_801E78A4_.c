#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_8000D838(void *);
extern int lbl_8055EAE0;
extern int lbl_8055EAE8;
extern int lbl_8055EAEC;
#pragma opt_propagation off
#pragma opt_dead_assignments off
void fn_801E78A4(void) {
    fn_8000D838(&lbl_8055EAE0);
    *(u64 *)&lbl_8055EAE8 = 0xFFFF00007F000000ULL;
}
