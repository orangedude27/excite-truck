// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *fn_801284F8(int, void *);
extern void *fn_801E76A8(void *, int);
extern void fn_802D68C4(int, int, int, int);
extern void fn_80128670(void *);
extern void fn_80128668(void *);
#pragma small_data off
extern char lbl_80339B90[];
void fn_801E7828();
void fn_801E7790();
#pragma dont_inline on
extern void *fn_8012850C(int, void *);
extern char lbl_80339B70[];
extern char lbl_80339B80[];
void *fn_801E76A8(void *arg0, int arg1) {
    int count = arg1;

    *(void **)arg0 = fn_8012850C(count * 0x18, lbl_80339B70);
    *(int *)((char *)arg0 + 8) = count;
    count = (count - 2) * 3;
    *(int *)((char *)arg0 + 4) = 0;
    *(void **)((char *)arg0 + 0xC) = fn_8012850C(count * 2, lbl_80339B80);
    *(int *)((char *)arg0 + 0x10) = 0;
    *(int *)((char *)arg0 + 0x14) = count;
    return arg0;
}

void *__dt__12PhysicsWorldFv_801E7730(void *arg0, int arg1) {
    if (arg0 != 0) {
        fn_80128670(*(void **)((char *)arg0 + 0xC));
        fn_80128670(*(void **)((char *)arg0 + 0));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_801E7828(void) {
    int *p = (int *)0;
    fn_802D68C4(p[0], p[1], p[3], p[4]);
}

#pragma dont_inline off

void fn_801E7840(void *arg0) {
    void *obj;
    obj = fn_801284F8(0x18, lbl_80339B90);
    if (obj != 0)
        fn_801E76A8(obj, (int)arg0);
}

void *fn_801E7888(void *arg0) {
    return __dt__12PhysicsWorldFv_801E7730(arg0, 1);
}

void fn_801E7890(void) {
    fn_801E7790();
}

void fn_801E7894(void) {
    fn_801E7828();
}

