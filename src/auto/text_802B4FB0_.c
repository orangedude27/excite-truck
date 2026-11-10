// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_802E3D04(void);
extern int fn_802E39D0(int, void *, int);
extern void fn_802E3734(int *);
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

#pragma dont_inline on
int fn_802B4FD0(void *arg0, int *arg1, int *arg2) {
    int result = 0;
    int handle;
    char header[0x12];
    handle = fn_802E3D04();
    if (handle != -1) {
        if (fn_802E39D0(handle, header, 0x12) != 0 &&
            (unsigned char)header[2] == 2 &&
            fn_802B4FB0((unsigned char)header[0x10]) != 0) {
            result = 1;
            *arg1 = *(unsigned short *)(header + 0xC);
            *arg2 = *(unsigned short *)(header + 0xE);
        }
        fn_802E3734(&handle);
    }
    return result;
}
#pragma dont_inline reset
typedef struct { unsigned char pad0[2]; unsigned char kind; unsigned char pad3[9]; unsigned short w; unsigned short h; unsigned char idx; } Fn802B5070Arg;
extern char lbl_8034A4E0[];
extern int fn_802E3D04(void);
extern int fn_802E39D0(int, void *, int);
extern void fn_802E3734(int *);

#pragma dont_inline on
#pragma scheduling invalid_target
#pragma scheduling on
int fn_802B5070(void *p, int arg1) {
    Fn802B5070Arg *arg0 = p;
    int result = 0;
    if (arg0->kind != 2) goto out;
    if (fn_802B4FB0(arg0->idx) == 0) goto out;
    if (arg1 != arg0->w * arg0->h) goto out;
    result = 1;
out:
    return result;
}
extern int fn_802B5070(void *, int);
int fn_802B50E8(int arg0, int arg1, int arg2) {
    int result = 0;
    int handle;
    char header[0x12];
    int value;
    int i;

    handle = fn_802E3D04();
    if (handle != -1) {
        if (fn_802E39D0(handle, header, 0x12) != 0 &&
            fn_802B5070(header, arg2) != 0) {
            if ((unsigned char)header[0x10] == 0x20) {
                result = fn_802E39D0(handle, (void *)arg1, arg2 * 4);
            } else {
                result = 1;
                i = 0;
                while (result != 0 && i < arg2) {
                    if (fn_802E39D0(handle, &value, 3) != 0) {
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
#pragma scheduling invalid_target
int fn_802B52C0(int arg0, void *arg1) {
    int result = 0;
    int value0;
    int value1;
    int sp8;
    char spC[0x12];

    memset(spC, 0, 0x12);
    value0 = *(int *)arg1;
    spC[2] = 2;
    value1 = *(int *)((char *)arg1 + 4);
    *(short *)(spC + 0xC) = (short)value0;
    *(short *)(spC + 0xE) = (short)value1;
    spC[0x10] = 0x20;
    sp8 = fn_802E3D68(arg0, value1, value0);
    if (sp8 != -1) {
        fn_802E3A64(sp8, spC, 0x12);
        fn_802E3A64(sp8, *(void **)((char *)arg1 + 8),
                    *(int *)((char *)arg1 + 4) * (*(int *)arg1 * 4));
        fn_802E3734(&sp8);
        result = 1;
    } else {
        ((void (*)(char *, ...))fn_802E30C8)(lbl_8034A4EC, arg0);
    }
    return result;
}
#pragma scheduling on
