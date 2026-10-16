// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80214CB4(int);
extern int fn_80235380(int);
extern int fn_80128668(void *);
extern int fn_80214A9C(int);
extern int fn_80214AF0(int);
extern int fn_80214B44(int);
extern void *lbl_803430E8;
extern void *lbl_8055F244;
extern int fn_80232578(void *);
extern int fn_802C5130(void *);
extern int fn_802C519C(void *);
extern int fn_802E30C8(void *);
extern int fn_802328D4(void *);
extern int fn_802451DC(void *, int);
extern int fn_8024521C(void *, int);
extern int fn_80245264(void *);
extern int fn_802452E4(void *);
int fn_802451DC(void *arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668(arg0);
    return (int)arg0;
}

int fn_8024521C(void *arg0, int arg1) {
    if (arg0 != 0) {
        lbl_8055F244 = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return (int)arg0;
}

void fn_80246210(void) {
    int i;
    int count;

    i = 0;
    *((char *)lbl_8055F244 + 0x1E) = 0;
    count = *(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x14);
    do {
        fn_80214AF0(i);
        i++;
    } while (i < count);
    do {
        fn_80214B44(count);
        fn_80214A9C(count);
        count++;
    } while (count < 4);
    fn_80214CB4(*(int *)((char *)*(void **)((char *)lbl_8055F244 + 0x20) + 0x10));
}

void *fn_80246428(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 0x1C);
        *(void **)arg0 = lbl_803430E8;
        if (temp_r0 != 0) {
            fn_80235380(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_80246498(void *arg0) {
    fn_80214CB4(*(unsigned char *)((char *)arg0 + 0x18) == 0);
}

void fn_802464A8(void *arg0) {
    *((signed char *)arg0 + 0x19) = 0;
}

