// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct StringReadContext {
    unsigned char *current;
    int eof;
} StringReadContext;

int __StringRead(StringReadContext *arg0, unsigned char arg1, int arg2) {
    unsigned char *temp_r4;
    unsigned char temp_r5;

    switch (arg2) {
    case 0:
        temp_r4 = arg0->current;
        temp_r5 = *temp_r4;
        if ((signed char) temp_r5 == 0) {
            arg0->eof = 1;
            return -1;
        }
        arg0->current = temp_r4 + 1;
        return temp_r5;
    case 1:
        if (arg0->eof == 0) {
            arg0->current = arg0->current - 1;
        } else {
            arg0->eof = 0;
        }
        return arg1;
    case 2:
        return arg0->eof;
    default:
        return 0;
    }
}
