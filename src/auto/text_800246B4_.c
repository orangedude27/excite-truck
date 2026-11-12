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
/* Flushes and closes a stream, freeing its owned buffer; returns 0 on success, -1 on failure or NULL. */
s32 fclose(void *stream) {
    FILE *file = (FILE *)stream;
    s32 flushResult;
    s32 closeResult;
    s32 failed;

    if (stream == 0) {
        return -1;
    }
    if (file->file_kind == 0) {
        return 0;
    }
    flushResult = fflush(file);
    closeResult = file->close(file->fp);
    file->fp = 0;
    file->file_kind = 0;
    if (file->free_buffer != 0) {
        free(file->mem);
    }
    failed = 0;
    if ((flushResult != 0) || (closeResult != 0)) {
        failed = 1;
    }
    return -failed;
}
