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
