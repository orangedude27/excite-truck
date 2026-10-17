// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8022D0D8(void* arg0) {
    ((signed char*)arg0)[1] = 0;
    ((signed char*)arg0)[0] = 0;
}

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

