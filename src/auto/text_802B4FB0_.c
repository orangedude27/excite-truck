// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128658(void *);
extern int fn_802B4FD0(void *, int *, int *);
extern void *fn_802B51E4(int, int);
extern int fn_802B50E8(int, int, int);
extern void *fn_801284E8(void *, int);
int fn_802B4FB0(unsigned char arg0) {
    int result = 0;
    if (arg0 == 0x20 || arg0 == 0x18) {
        result = 1;
    }
    return result;
}
extern char lbl_8034A4E0[];
extern int fn_802E3D04(void);
extern int fn_802E39D0(int, void *, int);
extern void fn_802E3734(int *);

int fn_802B5070(void *arg0, int arg1) {
    int result = 0;
    if (*(unsigned char *)((char *)arg0 + 2) == 2 &&
        fn_802B4FB0(*(unsigned char *)((char *)arg0 + 0x10)) != 0 &&
        arg1 == *(unsigned short *)((char *)arg0 + 0xC) *
                *(unsigned short *)((char *)arg0 + 0xE)) {
        result = 1;
    }
    return result;
}

extern int fn_802B5070(void *, int);
int fn_802B50E8(int arg0, int arg1, int arg2) {
    int result = 0;
    int handle;
    char header[0x12];
    int value;
    int i;
    int (*read_fn)(void *, void *, int) =
        (int (*)(void *, void *, int))fn_802E39D0;

    handle = fn_802E3D04();
    if (handle != -1) {
        if (read_fn((void *)handle, header, 0x12) != 0 &&
            fn_802B5070(header, arg2) != 0) {
            if ((unsigned char)header[0x10] == 0x20) {
                result = read_fn((void *)handle, (void *)arg1, arg2 * 4);
            } else {
                result = 1;
                i = 0;
                while (result != 0 && i < arg2) {
                    if (read_fn((void *)handle, &value, 3) != 0) {
                        *(int *)(arg1 + i * 4) = value;
                    } else {
                        result = 0;
                    }
                    i++;
                }
            }
        }
        fn_802E3734(&handle);
    }
    return result;
}

#pragma dont_inline on
void *fn_802B51E4(int arg0, int arg1) {
    int size = arg0 * arg1 * 4;
    char *result = fn_801284E8(lbl_8034A4E0, size + 0xC);
    *(int *)result = arg0;
    *(int *)(result + 4) = arg1;
    *(void **)(result + 8) = result + 0xC;
    return result;
}
#pragma scheduling off
void *fn_802B5240(void *arg0) {
    int spC;
    int sp8;
    void *result = 0;
    if (fn_802B4FD0(arg0, &spC, &sp8) != 0) {
        result = fn_802B51E4(spC, sp8);
        fn_802B50E8((int)arg0, *(int *)((char *)result + 8),
                    *(int *)result * *(int *)((char *)result + 4));
    }
    return result;
}
#pragma scheduling on
void fn_802B52B4(void *arg0) {
    *(int *)((char *)arg0 + 8) = 0;
    fn_80128658(arg0);
}

extern void *memset(void *, int, unsigned int);
extern int fn_802E3D68(int, int, int);
extern int fn_802E3A64(int, void *, int);
extern void fn_802E30C8(char *, int);
extern char lbl_8034A4EC[];
int fn_802B52C0(int arg0, void *arg1) {
    int result = 0;
    int sp8;
    char spC[0x12];
    memset(spC, 0, 0x12);
    spC[2] = 2;
    *(short *)(spC + 0xC) = (short)*(int *)arg1;
    *(short *)(spC + 0xE) = (short)*(int *)((char *)arg1 + 4);
    spC[0x10] = 0x20;
    sp8 = fn_802E3D68(arg0, *(int *)((char *)arg1 + 4), *(int *)arg1);
    if (sp8 != -1) {
        fn_802E3A64(sp8, spC, 0x12);
        fn_802E3A64(sp8, *(void **)((char *)arg1 + 8),
                     *(int *)((char *)arg1 + 4) * (*(int *)arg1 * 4));
        fn_802E3734(&sp8);
        result = 1;
    } else {
        fn_802E30C8(lbl_8034A4EC, arg0);
    }
    return result;
}

