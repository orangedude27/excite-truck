// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int frexp(int *);
extern int ldexp(int);
void fn_8002B060(int arg0) {
    int exponent;
    frexp(&exponent);
    exponent += arg0;
    ldexp(exponent);
}
