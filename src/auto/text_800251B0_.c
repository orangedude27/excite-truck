// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_800251B0(double arg0) {
    union {
        double d;
        unsigned int words[2];
    } value;
    value.d = arg0;
    return value.words[0] & 0x80000000;
}
