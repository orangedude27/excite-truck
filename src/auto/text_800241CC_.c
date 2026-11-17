// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Returns the absolute value of value (branchless abs via the sign bit). */
int fn_800241CC(int value) {
    int sign;
    sign = value >> 31;
    return (sign ^ value) - sign;
}
