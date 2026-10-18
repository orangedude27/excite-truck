// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
extern int lbl_8032A5FC;
extern int lbl_8032A620;
extern int lbl_8055E174;
extern float lbl_80561474;
int fn_802E317C(int *, ...);
int fn_80128658(int);
int fn_80128668(void *);
void fn_8013B950(void);
void *fn_8012A13C(void *arg0, int arg1, int arg2, int arg3) {
    *(int **)arg0 = &lbl_8032A620;
    fn_8012A17C(arg0, arg1, arg2, arg3, 0);
    return arg0;
}

void fn_8012A218(void *arg0) {
    unsigned char *base = *(unsigned char **)((char *)arg0 + 0x10);
    int stride = *(int *)((char *)arg0 + 0x14);
    unsigned char *end = base + (*(int *)((char *)arg0 + 0x18) - 1) * stride;
    unsigned char *p;
    for (p = base; p < end; p += stride) *(unsigned char **)p = p + stride;
    *(int *)end = 0;
    *(int *)((char *)arg0 + 0x1c) = 0;
}

void *fn_8012A260(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if (*((u8 *)arg0 + 5) == 0) {
            *(int **)arg0 = &lbl_8032A620;
            fn_80128658(*(int *)((char *)arg0 + 0xc));
        } else {
            *(int **)arg0 = &lbl_8032A620;
        }
        *(int *)((char *)arg0 + 0xc) = 0;
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

int *fn_8012A2D8(void *arg0) {
    int *temp_r31 = *(int **)((char *)arg0 + 0x10);
    int *temp_r3;
    if (temp_r31 == 0) {
        if (*((u8 *)arg0 + 4) == 0) return 0;
        fn_802E317C(&lbl_8032A5FC, *(int *)((char *)arg0 + 8));
    }
    temp_r3 = *(int **)((char *)arg0 + 0x10);
    if (temp_r3 != 0) *(int **)((char *)arg0 + 0x10) = (int *)*temp_r3;
    *(int *)((char *)arg0 + 0x1c) += 1;
    return temp_r31;
}

void fn_8012A364(void *arg0, int *arg1) {
    *arg1 = *(int *)((char *)arg0 + 0x10);
    *(int *)((char *)arg0 + 0x10) = (int)arg1;
    *(int *)((char *)arg0 + 0x1c) -= 1;
}
