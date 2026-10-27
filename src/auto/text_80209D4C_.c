// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8033C258[];
extern char lbl_8033C268[];
extern int lbl_8055B548;
extern void *fn_801284F8(unsigned int, void *);
extern void *fn_802077A4(void *, int, void *, void *);
extern void *fn_8020CA3C(void *);
extern float lbl_80563278, lbl_8056327C, lbl_80563280, lbl_80563284, lbl_80563288;
#pragma scheduling invalid_target
void *fn_80209D4C(void *arg0) {
    void *obj;
    void *child;
    obj = fn_801284F8(0x10, &lbl_8055B548);
    if (obj != 0) {
        *(void **)obj = lbl_8033C258;
        *((void **)obj + 1) = arg0;
        child = fn_802077A4(lbl_8033C268, 4, (char *)arg0 + 0x118, (char *)arg0 + 0x60);
        *((void **)obj + 2) = child;
        if (child != 0) *(int *)((char *)child + 0x10) = *(int *)((char *)*((void **)obj + 1) + 0x1ec);
        *((void **)obj + 3) = (void *)fn_8020CA3C(arg0);
    }
    return obj;
}

extern void fn_80128668(void *);
#pragma scheduling invalid_target
void *fn_80209DE4(void *arg0, int arg1) {
    register void *p;
    if (arg0 != 0) {
        p = *(void **)((char *)arg0 + 8);
        *(void **)arg0 = lbl_8033C258;
        if (p != 0) {
            if (p != 0) {
                ((void (*)(void *, int))(*(void * volatile **)p)[2])(p, 1);
            }
            *(void **)((char *)arg0 + 8) = 0;
        }
        p = *(void **)((char *)arg0 + 0xc);
        if (p != 0) {
            if (p != 0) {
                ((void (*)(void *, int))(*(void * volatile **)p)[2])(p, 1);
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on


