// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef int s32;
extern void fn_801D611C(s32);
extern void fn_801D77E8(s32);
extern void fn_801D77EC(s32);
extern void fn_801D7874(s32);

extern void fn_80128668(void*);
void* fn_801D9090(void* arg0, s32 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            *(s32 *)arg0 = 0;
            *((s32 *)arg0 + 1) = 0;
            *((s32 *)arg0 + 2) = 0;
        }
        if (arg1 > 0)
            fn_80128668(arg0);
    }
    return arg0;
}

void fn_801D90E8(s32 arg0) {
    fn_801D611C(arg0 - 4);
}

void fn_801D90F0(s32 arg0) {
    fn_801D77E8(arg0 - 4);
}

void fn_801D90F8(s32 arg0) {
    fn_801D77EC(arg0 - 4);
}

void fn_801D9100(s32 arg0) {
    fn_801D7874(arg0 - 4);
}

void fn_801D9108(int arg0) { fn_801D8938(arg0 - 4); }

void fn_801D9110(int arg0) { fn_801D893C(arg0 - 4); }

void fn_801D9118(int arg0) { fn_801D89C0(arg0 - 4); }

extern void *lbl_8055E96C;
extern void *lbl_8055E964;
extern int lbl_8055E960;
extern float lbl_80562B28;
extern int fn_802C6CF8(int);
extern int fn_801D985C(int *);
extern int fn_801D9948(int *);
extern void fn_801D9120(float *, float *, int, float);
void *fn_801D9260(int count) {
    void *node = lbl_8055E96C;
    do {
        node = *(void **)((char *)node + 0x54);
        if (node == 0)
            break;
        count--;
    } while (count >= 0);
    return node;
}

void fn_801D9828(void) {
    fn_802C6CF8(lbl_8055E960);
    fn_801D985C((int *)&lbl_8055E96C);
    fn_801D9948((int *)&lbl_8055E964);
}

