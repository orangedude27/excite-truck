// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void qsort(void *, unsigned long, unsigned long, int (*)(const void *, const void *));
#pragma opt_tail_call on
void fn_80265DCC(void *base, unsigned long num, unsigned long size, int (*compar)(const void *, const void *)) {
    qsort(base, num, size, compar);
}
