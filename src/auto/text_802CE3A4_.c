// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_80128668(void *);
int fn_80128670(int);
int fn_801342B0(int, int);
void fn_802C6FB4(int);
void fn_802C703C(int);

int fn_80128668(void *);
int fn_80128670(int);
int fn_801342B0(int, int);
char *strcpy(char *, const char *);
void fn_802C6FB4(int);
void fn_802C703C(int);
extern void *fn_801284F8(int, void *);
extern void *fn_8012850C(int, void *);
extern void *fn_8013420C(int, int);
extern void *fn_8002F37C(void *, int, int, int);
extern char lbl_8055D0A8[];
extern char lbl_8034BCE4[];
extern char lbl_8034BCD8[];
extern void fn_802CE474(void *);
__declspec(section ".sdata") extern char lbl_8055D0A8[];
void *fn_802CE3A4(int arg0, int arg1, int arg2) {
    int count;
    void *manager;
    void *data;
    void *size;
    manager = fn_801284F8(0x14, lbl_8055D0A8);
    if (manager != 0) {
        *(int *)((char *)manager + 8) = arg0;
        *(int *)((char *)manager + 0xC) = arg1;
        data = fn_801284F8(0x10, lbl_8034BCE4);
        if (data != 0) data = ((void *(*)(void *, int, int))fn_8013420C)(data, *(int *)((char *)manager + 0xC), arg2);
        *(void **)((char *)manager + 4) = data;
        count = *(int *)((char *)manager + 8);
        size = fn_8012850C((count << 6) + 0x10, lbl_8034BCD8);
        *(void **)manager = ((void *(*)(void *, void *, int, int, int))fn_8002F37C)(size, fn_802CE474, 0, 0x40, count);
        *(int *)((char *)manager + 0x10) = 0;
    }
    return manager;
}

void fn_802CE474(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(unsigned char *)arg0 = 0;
    *(int *)((char *)arg0 + 0x38) = 0;
    *(int *)((char *)arg0 + 0x34) = -1;
    *(int *)((char *)arg0 + 0x30) = 0;
    *(int *)((char *)arg0 + 0x2C) = -1;
    *(int *)((char *)arg0 + 0x3C) = -1;
}

void fn_802CE49C(void *arg0) {
    int value;
    if (arg0 != 0) {
        value = *(int *)arg0;
        if (value != 0) {
            fn_80128670(value - 0x10);
        }
        fn_801342B0(*(int *)((char *)arg0 + 4), 1);
        fn_80128668(arg0);
    }
}

void *fn_802CE630(void *arg0, const char *arg1, int arg2) {
    int count = *(int *)((char *)arg0 + 8);
    int offset = 0;
    char *entry;
    while (count > 0) {
        entry = *(char **)arg0 + offset;
        if (*entry == 0 && *(int *)(entry + 0x38) == 0) {
            entry[0] = 1;
            *(void **)(entry + 4) = arg0;
            strcpy(entry + 8, arg1);
            *(int *)(entry + 0x28) = arg2;
            return entry;
        }
        offset += 0x40;
        count--;
    }
    return 0;
}

void fn_802CE6C0(void *arg0) {
    if (*(int *)((char *)arg0 + 0x38) == 2 && *(int *)((char *)arg0 + 0x38) == 2) {
        fn_802C6FB4(*(int *)((char *)arg0 + 0x30));
        fn_802C703C(*(int *)((char *)arg0 + 0x34));
        *(int *)((char *)arg0 + 0x34) = -1;
        *(int *)((char *)arg0 + 0x30) = 0;
        *(int *)((char *)arg0 + 0x38) = 3;
    }
    *(unsigned char *)arg0 = 0;
}

int fn_802CE728(void *arg0) {
    if (*(int *)((char *)arg0 + 0x38) == 2) {
        return *(int *)((char *)arg0 + 0x34);
    }
    return -1;
}

void fn_802CE7D4(int arg0, int arg1, void *arg2);
void fn_802CE7D4(int arg0, int arg1, void *arg2) {
    if (*(unsigned char *)arg2 != 0) {
        *(int *)((char *)arg2 + 0x30) = arg0;
        fn_802C61BC((char *)arg2 + 8);
        fn_802C6FA8(*(int *)((char *)arg2 + 0x30));
        *(int *)((char *)arg2 + 0x34) = fn_802C6DC4((char *)arg2 + 8, *(int *)((char *)arg2 + 0x30), 0, 0);
        *(int *)((char *)arg2 + 0x38) = 2;
    } else {
        *(int *)((char *)arg2 + 0x38) = 0;
        *(int *)((char *)arg2 + 0x2C) = -1;
    }
}

int fn_802CE850(void *arg0) {
    return *(int *)((char *)arg0 + 0x38);
}
