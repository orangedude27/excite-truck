#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

f64 fn_8002F234(f32);
f32 fn_8002B0B0(f64 x) {
#define sqrt_d fn_8002F234
    /* Single-precision square root: round the input to f32, take the double-precision sqrt, round the result back to f32. */
    return (f32) sqrt_d((f32) x);
#undef sqrt_d
}
