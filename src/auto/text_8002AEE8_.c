// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef struct {
    unsigned int _pad : 10;
    unsigned int mode : 2;
    unsigned int _rest : 20;
} FwideFlags;

int fn_8002AEE8(unsigned short* s) {
    unsigned short* p = s - 1;
    int len = -1;
    do {
        len++;
    } while (*++p);
    return len;
}

int fwide(void *stream, int mode)
{
    unsigned int flags;
    unsigned int orient;
    int m = mode;
    if ((stream == 0) || ((flags = *(unsigned int *)((char *)stream + 4), (((flags >> 22) & 7) == 0)))) {
        return 0;
    }
    orient = (flags >> 20) & 3;
    switch (orient) {
    case 0:
        if (m > 0) {
            *(unsigned int *)((char *)stream + 4) = (flags & 0xffcfffff) | (2 << 20);
        } else if (m < 0) {
            *(unsigned int *)((char *)stream + 4) = (flags & 0xffcfffff) | (1 << 20);
        }
        break;
    case 2:
        m = 1;
        break;
    case 1:
        m = -1;
        break;
    }
    return m;
}

