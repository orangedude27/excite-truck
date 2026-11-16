// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void __prep_buffer(void *file) {
    /* Prepare a FILE's buffer for I/O: buffer_ptr = buffer,
       buffer_length = buffer_size - (position & buffer_alignment), and
       buffer_position = position. Word indices map to the FILE fields at
       0x18 position, 0x1C buffer, 0x20 size, 0x24 ptr, 0x28 length,
       0x2C alignment, 0x34 buffer_position. */
    volatile unsigned int *p = (volatile unsigned int *)file;
    unsigned int position;
    unsigned int alignment;
    unsigned int bufferSize;
    unsigned int buffer;
    unsigned int maskedPosition;
    position = p[6];
    alignment = p[11];
    buffer = p[7];
    bufferSize = p[8];
    maskedPosition = position & alignment;
    p[9] = buffer;
    p[10] = bufferSize - maskedPosition;
    p[13] = position;
}
