// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
typedef double f64;
/* Classify a double: 1=NaN, 2=infinity, 3=zero, 4=normal, 5=subnormal. */
s32 __fpclassifyd(f64 x) {
    union { f64 d; struct { u32 hi; u32 lo; } w; } bits;
    u32 exponentBits;
    bits.d = x;
    exponentBits = bits.w.hi & 0x7FF00000;
    switch (exponentBits) {
    case 0x7FF00000:
        if ((bits.w.hi & 0x000FFFFF) || bits.w.lo) return 1;
        return 2;
    case 0:
        if ((bits.w.hi & 0x000FFFFF) || bits.w.lo) return 5;
        return 3;
    default:
        return 4;
    }
}
