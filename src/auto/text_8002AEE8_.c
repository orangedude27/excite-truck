// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8002AEE8(unsigned short* s) {
    unsigned short* p = s - 1;
    int len = -1;
    do {
        len++;
    } while (*++p);
    return len;
}
