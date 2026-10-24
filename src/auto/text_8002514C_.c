// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __fpclassifyf(float x) {
    union { float f; unsigned int u; } bits;
    unsigned int exp;
    bits.f = x;
    exp = bits.u & 0x7F800000;
    switch (exp) {
    case 0x7F800000: {
        unsigned int frac = bits.u & 0x7FFFFF;
        return ((int)(-frac | frac) >> 31) + 2;
    }
    case 0:
        if (bits.u & 0x7FFFFF) return 5;
        return 3;
    default:
        return 4;
    }
}
