// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80345718[];
extern void fn_80235380(void*, void*);
extern void fn_80128668(void*);
extern int lbl_8055F3C4;
extern void fn_80128668(void *);
extern void fn_80214A9C(int);
extern void *fn_8023512C(void *, void *, void *);
extern char lbl_80345694[];
extern char lbl_8055C3E0[];
extern double lbl_80563B68;
extern float lbl_80563B58, lbl_80563B5C, lbl_80563B60;
extern void fn_80230C30(float *, float *, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
void *fn_8025D96C(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(int *)&lbl_8055F3C4 = 0;
        if ((char *)arg0 + 0x18 != 0 && (char *)arg0 + 0x18 != 0) {
            *(int *)((char *)arg0 + 0x18) = 0;
            *(int *)((char *)arg0 + 0x1c) = 0;
            *(int *)((char *)arg0 + 0x20) = 0;
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void* __dt__Q28PSSystem7SeqHeapFv_8025DA88(void* arg0, int arg1) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80345718;
        fn_80235380(*(void**)((char*)arg0 + 0x28), lbl_80345718);
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma use_lmw_stmw off
void fn_8025DF80(void *arg0) {
    register int index = 0;
    register int count = 0;
    while (count < *(int *)((char *)arg0 + 0x1c)) {
        fn_80214A9C(*(int *)(*(char **)((char *)arg0 + 0x18) + index));
        index += 4;
        count += 1;
    }
}
#pragma pop
extern double lbl_80563B68;
extern float lbl_80563B58, lbl_80563B5C, lbl_80563B60;
extern void fn_80230C30(float *, float *, int, int);
extern void fn_802354A0(int, unsigned char, int, float, float, float, float, float);
extern void fn_80231220(int, int, float, float, float, float, float, float, float, float);
