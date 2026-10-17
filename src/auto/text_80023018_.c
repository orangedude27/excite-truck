// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int __equals_dec(void *a, void *b) {
    unsigned char *x = (unsigned char *)a;
    unsigned char *y = (unsigned char *)b;
    unsigned char c;
    int nx;
    int ny;
    int i;
    int n;

    c = x[5];
    if (c == 0) return y[5] == 0;
    if (y[5] == 0) return c == 0;
    if (*(short *)(x + 2) == *(short *)(y + 2)) {
        nx = x[4];
        ny = y[4];
        n = nx;
        if (nx > ny) n = ny;
        for (i = 0; i < n; i++) {
            if (x[i + 5] != y[i + 5]) return 0;
        }
        if (n == nx) x = y;
        for (; i < x[4]; i++) {
            if (x[i + 5] != 0) return 0;
        }
        return 1;
    }
    return 0;
}
