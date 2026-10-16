// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_801EFF4C(void* alarm) {
    fn_801F17C8(fn_801F0AA0(alarm));
}

void fn_801EFF70(void* alarm) {
    fn_801F0CC4(fn_801F17DC(alarm));
}

int fn_801F0F18(int, int);
int fn_801F0E88(int, int);
int fn_801284F8(int, void *);
int fn_801F0DC0(int, int, int);
extern int lbl_8055B0B8;
void fn_801F0000(int arg0) {
    fn_801F0F18(arg0, -1);
}

int fn_801F0008(void) {
    return 0x4C;
}

int fn_801F0010(int arg0, int arg1) {
    int value = arg1;
    if (value != 0) {
        value = fn_801F0E88(value, arg0);
    }
    return value;
}

extern float lbl_80562F10;
extern float lbl_80562F14;
extern float lbl_80562F18;
extern int lbl_8033A400;
extern int lbl_8033A410;
extern int lbl_8055B0C0;
extern int lbl_8055EBEC;
extern int lbl_8055EBF0;
int stricmp(const char *, const char *);
void fn_801F08AC(int, const char *);
int fn_801F09FC(const char *arg0) {
    int offset = 0;
    int count = 0;
    while (count < lbl_8055EBF0) {
        if (stricmp((const char *)(lbl_8055EBEC + offset), arg0) == 0) {
            return lbl_8055EBEC + count * 0x138;
        }
        offset += 0x138;
        count++;
    }
    {
        int result = lbl_8055EBEC + lbl_8055EBF0 * 0x138;
        lbl_8055EBF0++;
        fn_801F08AC(result, arg0);
        return result;
    }
}

int fn_801F0F18(int arg0, int arg1) {
    if (arg0 != 0) {
        if (*(unsigned char *)(arg0 + 0x14) == 0) fn_801F18F0();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_801F131C(int arg0, int arg1) {
    if (*(unsigned int *)(arg0 + 4) != 3) {
        int value;
        if (arg1 != 0) value = 0;
        else value = fn_801F15A8(arg0, arg0 + 0x3C);
        fn_801F163C(arg0, value, *(float *)(arg0 + 0x48));
    }
}

void fn_801F1378(void *arg0) {
    if (*(unsigned int *)((char *)arg0 + 4) != 3)
        fn_801F163C(arg0, 0, *(float *)((char *)arg0 + 0x48));
}

