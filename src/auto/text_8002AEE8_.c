// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* Bits of the stream's flags word at +4. Bits 22-24 (_pad) must be nonzero for
 * the stream to be usable; bits 20-21 hold the orientation that fwide sets. */
typedef struct {
    unsigned int _pad : 10;         /* bits 22-31 */
    unsigned int orientation : 2;   /* bits 20-21: 0 unoriented, 1 byte, 2 wide */
    unsigned int _rest : 20;        /* bits 0-19 */
} FwideFlags;

/* wcslen: count the non-NUL 16-bit characters before the terminator. */
int fn_8002AEE8(unsigned short* str) {
    unsigned short* p = str - 1;
    int len = -1;
    do {
        len++;
    } while (*++p);
    return len;
}

/* Determine or set stream orientation: >0 wide, <0 byte, 0 query/error. */
int fwide(void *stream, int mode) {
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
            ((FwideFlags *)((char *)stream + 4))->orientation = 2;
        } else if (result < 0) {
            ((FwideFlags *)((char *)stream + 4))->orientation = 1;
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

