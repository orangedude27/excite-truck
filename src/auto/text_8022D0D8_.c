// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8022D0D8(void* arg0) {
    ((signed char*)arg0)[1] = 0;
    ((signed char*)arg0)[0] = 0;
}

extern unsigned int strlen(const char *);
extern unsigned int strlen(const char *);
#pragma push
#pragma scheduling invalid_target
void fn_8022D0E8(unsigned char *buffer, int capacity, unsigned char *suffix) {
    unsigned char *cursor = buffer;
    int remaining = capacity;
    int copyRemaining;
    unsigned char *write;
    int len;
    /* Append suffix to the end of a double-NUL-terminated buffer within capacity. */
    while ((signed char)*cursor != 0) {
        do {
            cursor++;
            remaining--;
        } while ((signed char)*cursor != 0);
        cursor++;
        remaining--;
    }
    if (remaining > 0) {
        write = cursor;
        copyRemaining = remaining;
        while ((signed char)(*write++ = *suffix++) != 0) {
            if (--copyRemaining <= 0) {
                write[-1] = 0;
                break;
            }
        }
        len = strlen((const char *)cursor) + 1;
        remaining -= len;
        if (remaining >= 1) {
            cursor[len] = 0;
        } else {
            *(cursor + len - 2) = 0;
        }
    }
}
#pragma pop
int fn_8022D1B4(unsigned char *arg0) {
    int var_r4;
    unsigned char *var_r3;
    unsigned char temp_r0;

    var_r3 = arg0;
    var_r4 = 0;
    do {
        var_r4 += 1;
    loop_2:
        temp_r0 = *var_r3;
        var_r3 += 1;
        if ((signed char)temp_r0 != 0) {
            goto loop_2;
        }
    } while ((signed char)*var_r3 != 0);
    return var_r4;
}

