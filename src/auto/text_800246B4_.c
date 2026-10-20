// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
typedef struct FILE {
    s32 fp;
    u32 flags;
    u32 unk8;
    u32 pad[0x13];
    void *mem;
    u32 pad2[0x12];
    s32 (*close)(s32);
} FILE;
s32 fflush(void);
void free(void *);
s32 fclose(void *arg0) {
    FILE *f = (FILE *)arg0;
    s32 temp_r30;
    s32 temp_r31;
    s32 var_r0;
    if (arg0 == 0) return -1;
    if ((((u32)f->flags) >> 22) & 7) {
        temp_r30 = fflush();
        temp_r31 = f->close(f->fp);
        f->fp = 0;
        f->flags &= 0xFE3FFFFF;
        if (((u32)f->unk8) >> 28) free(f->mem);
        var_r0 = 0;
        if ((temp_r30 != 0) || (temp_r31 != 0)) var_r0 = 1;
        return -var_r0;
    }
    return 0;
}
