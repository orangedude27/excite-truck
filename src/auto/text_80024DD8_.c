// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void *memchr(const unsigned char *arg0, int arg1, unsigned int arg2) {
    const unsigned char *p = arg0 - 1;
    unsigned int n = arg2 + 1;
    if ((unsigned char)arg1 == *++p) return (void *)p;
    while (--n != 0) {
        if ((unsigned char)arg1 == *++p) return (void *)p;
    }
    return 0;
}

void *__memrchr(const unsigned char *arg0, int arg1, unsigned int arg2) {
    const unsigned char *p = arg0 + arg2;
    unsigned int n = arg2 + 1;
    while (--n != 0) {
        if ((unsigned char)arg1 == *--p) return (void *)p;
    }
    return 0;
}

int memcmp(const unsigned char *arg0, const unsigned char *arg1, unsigned int arg2) {
    const unsigned char *p = arg0 - 1;
    const unsigned char *q = arg1 - 1;
    unsigned int n = arg2 + 1;
    while (--n != 0) {
        if (*++p != *++q) {
            if (*p < *q) return -1;
            return 1;
        }
    }
    return 0;
}

