// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void __prep_buffer(void *arg0) {
    volatile unsigned int *p = (volatile unsigned int *)arg0;
    unsigned int a;
    unsigned int b;
    unsigned int d;
    unsigned int c;
    unsigned int e;
    a = p[6];
    b = p[11];
    c = p[7];
    d = p[8];
    e = a & b;
    p[9] = c;
    p[10] = d - e;
    p[13] = a;
}
