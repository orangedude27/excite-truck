// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_801392F8(void *arg0) {
    if (*(int *)((unsigned char *)arg0 + 0x1F0) == 0x50) {
        return *(unsigned char *)((unsigned char *)arg0 + 0x260) & 3;
    }
    return 0;
}
