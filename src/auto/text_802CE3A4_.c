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
void fn_802CE474(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(unsigned char *)arg0 = 0;
    *(int *)((char *)arg0 + 0x38) = 0;
    *(int *)((char *)arg0 + 0x34) = -1;
    *(int *)((char *)arg0 + 0x30) = 0;
    *(int *)((char *)arg0 + 0x2C) = -1;
    *(int *)((char *)arg0 + 0x3C) = -1;
}

void fn_802CE6C0(void *arg0) {
    if (*(int *)((char *)arg0 + 0x38) == 2) {
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
