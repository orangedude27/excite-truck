// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int frexp(int *);
extern int ldexp(int);
// FDLIBM scalbn: return x * 2^n. x arrives in f1 (implicit arg to frexp) and the result leaves in f1.
void fn_8002B060(int n) {
    int exponent;
    frexp(&exponent);
    exponent += n;
    ldexp(exponent);
}
