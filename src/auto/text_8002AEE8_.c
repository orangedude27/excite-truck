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

/* Determine or set stream orientation: >0 wide, <0 byte, 0 query/error. */
int fwide(void *stream, int mode)
{
    unsigned int file_modes;
    unsigned int orientation;
    int result = mode;
    if ((stream == 0) || ((file_modes = *(unsigned int *)((char *)stream + 4), (((file_modes >> 22) & 7) == 0)))) {
        return 0;
    }
    orientation = (file_modes >> 20) & 3;
    switch (orientation) {
    case 0:
        if (result > 0) {
            ((FwideFlags *)((char *)stream + 4))->mode = 2;
        } else if (result < 0) {
            ((FwideFlags *)((char *)stream + 4))->mode = 1;
        }
        break;
    case 2:
        result = 1;
        break;
    case 1:
        result = -1;
        break;
    }
    return result;
}

