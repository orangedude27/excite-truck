// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#define M2C_UNK s32
#define M2C_FIELD(expr, type, offset) (*(type *)((u8 *)(expr) + (offset)))
