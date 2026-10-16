// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8027B8C0(void* alarm) {
    fn_8027BA24(fn_8027B834(alarm));
}

void fn_8027B9EC(void *arg0) {
    fn_8027B984(arg0, fn_8000DA10());
}

long fn_8027BAB8(void *arg0) {
    long i = 0;
    while (1) {
        void *item = ((void *(*)(void *, long))(*(void ***)arg0)[4])(arg0, i);
        if (((long (*)(void *))(*(void ***)item)[10])(item) == 0)
            return 0;
        i++;
        if (i >= ((long (*)(void *))(*(void ***)arg0)[3])(arg0))
            return 1;
    }
}

long fn_8027BB4C(long, long, long, long);
void fn_8027BCC0(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 0);
}

void fn_8027BCC8(long arg0, long arg1, long arg2) {
    fn_8027BB4C(arg0, arg1, arg2, 1);
}

