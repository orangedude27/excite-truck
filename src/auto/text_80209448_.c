// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#define M2C_UNK s32
#define M2C_FIELD(expr, type, offset) (*(type *)((u8 *)(expr) + (offset)))
#define M2C_VFUNC(obj, slot, type) ((type)(*(void ***)(obj))[slot])
typedef void *(*M2CPtr0)(void *);
typedef void *(*M2CPtr1)(void *, const char *);
typedef void *(*M2CPtrIndex)(void *, s32);
typedef s32 (*M2CS32_1)(void *, const char *);
typedef f32 (*M2CF32_2)(void *, const char *, f32);
typedef f32 (*M2CF32_1)(void *, const char *);
typedef f32 (*M2CF32_0)(void *);
typedef void *(*M2CPtr2)(void *, const char *, s32);
