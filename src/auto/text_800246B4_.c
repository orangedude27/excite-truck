// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef struct FILE {
    union {
        s32 fp;
        s32 handle;
    };
    union {
        u32 flags;
        struct {
            u32 mode : 7;
            u32 file_kind : 3;
            u32 rest_flags : 22;
        };
    };
    union {
        u32 unk8;
        struct {
            u32 dummy : 3;
            u32 free_buffer : 1;
            u32 rest_state : 28;
        };
    };
    u8 pad[0x10];
    void *mem;
    u8 pad2[0x24];
    s32 (*close)(s32);
} FILE;
s32 fflush();
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
