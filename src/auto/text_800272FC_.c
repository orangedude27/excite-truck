// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct FileNode {
    int unk0;
    unsigned int flags;
    char pad[0x44];
    struct FileNode* next;
} FileNode;
extern FileNode __files;
extern int __FileWrite(void *, void *, unsigned int);
extern int fwide(void *, int);
extern int __pformatter_800269DC(void *, void *, const char *, void *);
