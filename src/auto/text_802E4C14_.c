// Code of main that had no source file yet: decomp.wtf gave it this one.
extern void *fn_801284F8(int, void *);
extern int fn_8012850C(int, void *);
extern void fn_802E30C8(const char *, ...);
extern int lbl_8055D1C8;
extern char lbl_8034D1D0[];
extern char lbl_8034D204[];
extern char lbl_8034D1F0[];
// split_file divides it into the game's real files (file_status shows its range).

void fn_802E4C14(void) {
}

void fn_802E4C18(void) {
}

#pragma dont_inline on
#pragma scheduling off
void *fn_802E4C1C(int arg0) {
    char *object = fn_801284F8(0xC, &lbl_8055D1C8);
    if (object != 0) {
        *(char **)object = lbl_8034D1D0;
        *(int *)(object + 8) = arg0;
        *(int *)(object + 4) = fn_8012850C(arg0, lbl_8034D204);
        fn_802E30C8(lbl_8034D1F0, arg0 / 1024);
    }
    return object;
}
#pragma scheduling on
#pragma dont_inline off

void *fn_802E4CA4(int arg0) {
    return fn_802E4C1C(arg0);
}

void fn_802E4CDC(void) {
}

extern void fn_80128668(void *);
extern void fn_80128670(int);
void *fn_802E4CE0(void *arg0, int arg1) {
    if (arg0 != 0) {
        *(char **)arg0 = lbl_8034D1D0;
        fn_80128670(*(int *)((char *)arg0 + 4));
        *(int *)((char *)arg0 + 4) = 0;
        *(int *)((char *)arg0 + 8) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

int fn_802E4D60(void *arg0, int arg1) {
    return *(int *)((char *)arg0 + 4) + arg1;
}

void fn_802E4D6C(void) {
}

void fn_802E4D70(void) {
}

int fn_802E4D74(void) {
    return 1;
}

