// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8027B8C0(void* alarm) {
    fn_8027BA24(fn_8027B834(alarm));
}

long fn_8027BAB8(void **arg0) {
    long var_r31;

    var_r31 = 0;
    do {
        void *item;
        long result;
        long count;

        item = ((void *(*)(void *, long))(*(void ***)*arg0)[4])(*arg0, var_r31);
        result = ((long (*)(void *))(*(void ***)item)[10])(item);
        if (result == 0) {
            return 0;
        }
        var_r31++;
        count = ((long (*)(void *))(*(void ***)*arg0)[3])(*arg0);
        if (var_r31 >= count) {
            return 1;
        }
    } while (1);
}

long fn_8027BB4C(long, long, long, long);
void fn_8027BCC0(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 0);
}

void fn_8027BCC8(long arg0, long arg1, long arg2, long arg3) {
    fn_8027BB4C(arg0, arg1, 1, arg3);
}

