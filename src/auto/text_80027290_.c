// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* memcpy(void*, const void*, unsigned int);
/* Write up to size bytes into a string output buffer, clamped to remaining capacity, and report success. */
int __StringWrite(void* stream, const void* source, unsigned int size) {
    unsigned int used = *(unsigned int*)((char*)stream + 8);
    unsigned int capacity = *(unsigned int*)((char*)stream + 4);
    unsigned int count = capacity - used;
    if (used + size <= capacity)
        count = size;
    memcpy((char*)*(char**)stream + used, source, count);
    *(unsigned int*)((char*)stream + 8) += count;
    return 1;
}
