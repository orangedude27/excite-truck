// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Return the sign bit of a double: 0x80000000 when negative, 0 otherwise. */
int fn_800251B0(double x) {
    union {
        double d;
        unsigned int words[2];
    } bits;
    bits.d = x;
    return bits.words[0] & 0x80000000;
}
