// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef struct StringReadContext {
    unsigned char *current;
    int eof;
} StringReadContext;

/* Read/unget/test EOF for string scanning (__ReadProcActions: 0=get, 1=unget, 2=test). */
int __StringRead(StringReadContext *context, unsigned char ch, int action) {
    unsigned char *current;
    unsigned char currentChar;

    switch (action) {
    case 0:
        current = context->current;
        currentChar = *current;
        if ((signed char) currentChar == 0) {
            context->eof = 1;
            return -1;
        }
        context->current = current + 1;
        return currentChar;
    case 1:
        if (context->eof == 0) {
            context->current = context->current - 1;
        } else {
            context->eof = 0;
        }
        return ch;
    case 2:
        return context->eof;
    default:
        return 0;
    }
}
