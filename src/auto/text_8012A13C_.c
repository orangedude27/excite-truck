// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef struct { int pad[4]; char *base; int stride; int count; int head; } PoolList_8012A218;
extern char lbl_8032A5FC[];
extern char lbl_8032A620[];
extern int lbl_8055E174;
extern float lbl_80561474;
int fn_802E317C(int *, ...);
int fn_80128658(int);
int fn_80128668(void *);
void fn_8013B950(void);
void *fn_8012A13C(void *arg0, int arg1, int arg2, int arg3) {
    *(int **)arg0 = (int *)lbl_8032A620;
    fn_8012A17C(arg0, arg1, arg2, arg3, 0);
    return arg0;
}

extern s32 fn_801284E8(s32, s32);
extern void fn_8012A218(void *);
extern char lbl_8032A5D8[];
s32 fn_8012A17C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base = (u8 *)arg0;
    s32 temp_r0;
    *(u8 *)(base + 4) = 1;
    *(s32 *)(base + 0x14) = arg3;
    *(s32 *)(base + 0x18) = arg2;
    *(u8 *)(base + 5) = (u8)(arg4 != 0);
    *(s32 *)(base + 8) = arg1;
    if (arg4 == 0) {
        *(s32 *)(base + 0xC) = fn_801284E8(arg1, arg2 * arg3);
    } else {
        *(s32 *)(base + 0xC) = arg4;
    }
    temp_r0 = *(s32 *)(base + 0xC);
    if (temp_r0 != 0) {
        *(s32 *)(base + 0x10) = temp_r0;
        fn_8012A218(base);
        return;
    }
    fn_802E317C((int *)&lbl_8032A5D8);
}

#pragma push
#pragma scheduling invalid_target
void fn_8012A218(void *arg0) {
    PoolList_8012A218 *l = (PoolList_8012A218 *)arg0;
    char *p;
    char *end = (char *)((l->count - 1) * l->stride + (int)l->base);
    for (p = l->base; p < end; p += l->stride) {
        int *q = (int *)p;
        *q = (int)p + l->stride;
    }
    *(int *)end = 0;
    l->head = 0;
}
#pragma pop
void *fn_8012A260(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(int **)arg0 = (int *)lbl_8032A620;
        if (*((u8 *)arg0 + 5) == 0) {
            fn_80128658(*(int *)((char *)arg0 + 0xc));
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
        fn_802E317C((int *)&lbl_8032A5FC, *(int *)((char *)arg0 + 8));
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
