// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
typedef struct Entry { s32 state; s32 unk4; void *obj; void (*cb)(void *, void *, void *); void *unk10; } Entry;
typedef struct Container { void *data; s32 count; s32 stride; Entry *entries; } Container;
