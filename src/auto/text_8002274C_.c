// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct FileNode {
    int unk0;
    unsigned int flags;
    void *unk8;
    char *unkC;
    char pad[0x3C];
    struct FileNode *next;
} FileNode;
extern FileNode __files;
extern int fclose(FileNode *);
extern void free(void *);

void __close_all(void) {
    struct CloseFile {
        int unk0;
        unsigned int : 7;
        unsigned int mode : 3;
        unsigned int : 22;
        void *unk8;
        volatile unsigned char unkC[0x40];
        struct CloseFile * volatile next;
    };
    struct CloseFile *file = (struct CloseFile *)&__files;
    struct CloseFile *current;
    while (file != 0) {
        if (file->mode != 0)
            fclose((FileNode *)file);
        current = file;
        file = current->next;
        if (current->unkC[0] != 0) {
            free(current);
        } else {
            current->mode = 3;
            if (file != 0 && file->unkC[0] != 0)
                current->next = 0;
        }
    }
}
