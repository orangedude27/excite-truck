// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
typedef struct Buffer {
    void *data;
    unsigned char pad04[0x14];
    s32 pos, read, end, capacity, count, mask;
    unsigned char pad30[4];
    s32 write_pos;
    unsigned char pad38[8];
    s32 (*flush)(void *, s32, void *, s32);
    unsigned char pad44[4];
    s32 size;
} Buffer;
