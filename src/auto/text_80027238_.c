// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int __fwrite(void *, unsigned int, unsigned int, void *);
int __FileWrite(void *file, void *buffer, unsigned int size) {
    unsigned int result = ((unsigned int (*)(void *, unsigned int, unsigned int, void *))__fwrite)(buffer, 1, size, file);
    if (size != result) {
        file = 0;
    }
    return (int)file;
}
