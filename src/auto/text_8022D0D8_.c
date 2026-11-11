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
void fn_8022D0E8(unsigned char *arg0, int arg1, unsigned char *arg2) {
    unsigned char *dst = arg0;
    int remaining = arg1;
    int copyRemaining;
    unsigned char *write;
    int len;
    while ((signed char)*dst != 0) {
        do {
            dst++;
            remaining--;
        } while ((signed char)*dst != 0);
        dst++;
        remaining--;
    }
    if (remaining > 0) {
        write = dst;
        copyRemaining = remaining;
        while ((signed char)(*write++ = *arg2++) != 0) {
            if (--copyRemaining <= 0) {
                write[-1] = 0;
                break;
            }
        }
        len = strlen((const char *)dst) + 1;
        remaining -= len;
        if (remaining >= 1) {
            dst[len] = 0;
        } else {
            *(dst + len - 2) = 0;
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

