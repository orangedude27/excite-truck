// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* memcpy(void*, const void*, unsigned int);
int __StringWrite(void* arg0, const void* source, unsigned int size) {
    unsigned int used = *(unsigned int*)((char*)arg0 + 8);
    unsigned int capacity = *(unsigned int*)((char*)arg0 + 4);
    unsigned int count = capacity - used;
    if (used + size <= capacity)
        count = size;
    memcpy((char*)*(char**)arg0 + used, source, count);
    *(unsigned int*)((char*)arg0 + 8) += count;
    return 1;
}
