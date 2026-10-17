// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct FileNode {
    int unk0;
    unsigned int flags;
    char pad[0x44];
    struct FileNode* next;
} FileNode;
extern FileNode __files;
extern int fflush(FileNode*);

int __flush_all(void) {
    int result = 0;
    FileNode* file = &__files;
    while (file != 0) {
        if (((file->flags >> 22) & 7) != 0 && fflush(file) != 0)
            result = -1;
        file = file->next;
    }
    return result;
}
