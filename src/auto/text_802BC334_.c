// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_8012C33C(void);
int fn_802CAC28(int, int);
int fn_802BC334(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

int fn_802BD0C8(void *arg0) {
    int result = 0;
    if (*(int *)((char *)arg0 + 4) != 0) {
        void **ptr = *(void ***)((char *)arg0 + 0x58);
        if (ptr != 0)
            result = *(int *)((char *)*ptr + 4);
    }
    return result;
}

int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD0F4(void *arg0) {
    int i = 0;
    int offset = 0;
    int count;
    char *entry;
    void *ptr;
    float a, b;
    if (*(int *)((char *)arg0 + 4) == 0)
        return;
    ptr = *(void **)((char *)arg0 + 0x58);
    if (ptr == 0)
        return;
    entry = *(char **)ptr;
    count = *(int *)(entry + 4);
    while (i < count) {
        ptr = *(void **)((char *)arg0 + 0x58);
        entry = *(char **)ptr + offset;
        a = *(float *)(entry + 0x30);
        b = *(float *)(entry + 0x38);
        *(int *)(entry + 4) = fn_802BA580(*(int *)((char *)arg0 + 4), &a, *(float *)(entry + 0x1c));
        offset += 0x44;
        i++;
    }
}

void *fn_801284F8(int, int);
int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD414(int arg0, volatile int *arg1) {
    volatile int *result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result != 0) {
        int first = arg1[0];
        result[1] = 0;
        result[0] = arg1[1];
        result[2] = first;
        result[1] = result[1] + arg1[0];
    }
}

int fn_802BD5A8(int arg0, int arg1) { return arg0 + arg1; }

int fn_802BD694(int arg0, int arg1) { return arg0 + arg1; }

int fn_802BD80C(int arg0, int arg1) { return arg0 + arg1; }

void fn_802BDC3C(void* alarm) {
    fn_802C1550(fn_802BD210(alarm));
}

void fn_802C2930(void*, unsigned int);
void fn_80128668(void*);
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802BDCFC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_802C2930((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}
void *fn_801284F8(int, int);
