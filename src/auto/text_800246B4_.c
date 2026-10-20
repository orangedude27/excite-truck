// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
typedef struct FILE {
    s32 fp;
    u32 flags;
    u32 unk8;
    void *mem;
    u32 pad[0x2C];
    s32 (*close)(s32);
} FILE;
s32 fflush(void);
void free(void *);
s32 fclose(void *arg0) {
    s32 temp_r30;
    s32 temp_r31;
    s32 var_r0;
    u32 flags;
    if (arg0 == 0) return -1;
    if (!((((u32)*(u32 *)((char *)arg0 + 4)) >> 22) & 7)) return 0;
    temp_r30 = fflush();
    temp_r31 = ((s32 (*)(s32))*(u32 *)((char *)arg0 + 0x44))(*(s32 *)arg0);
    *(s32 *)arg0 = 0;
    flags = *(u32 *)((char *)arg0 + 4);
    *(u32 *)((char *)arg0 + 4) = flags & 0xFE3FFFFF;
    if (((*(u32 *)((char *)arg0 + 8) >> 28) & 1) != 0) free(*(void **)((char *)arg0 + 0x1C));
    var_r0 = 0;
    if ((temp_r30 != 0) || (temp_r31 != 0)) var_r0 = 1;
    return -var_r0;
}
