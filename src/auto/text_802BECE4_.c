// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void fn_80128668(void *);
extern void fn_802CAC54(int);
extern char lbl_8034AE20[];
typedef unsigned int u32;
extern int fn_801E85B4(void);
extern void fn_802BF160(void);
extern int fn_802C2C00(int);
extern void fn_802C6CF8(void);
extern void *lbl_804C07F0[];
extern unsigned char lbl_8055CF70;
extern int lbl_8055FADC;
extern int lbl_8055CF6C;
int fn_802BF4F0(void) {
    return (int)(unsigned int)lbl_804C07F0 != 0;
}

void fn_802C0054(void *dst, const void *src) {
    struct Copy {
        u32 words[9];
    };
    *(struct Copy *)dst = *(const struct Copy *)src;
}

int fn_802C0C98(void *arg0) { return *(int *)((char *)arg0 + 8); }

float fn_802C0CA0(void *arg0) { return *(float *)((char *)arg0 + 0x14); }

int fn_802C0CA8(void) { return 1; }

void *fn_802C0CB0(void *arg0, int arg1) {
    int temp_r0;

    if (arg0 != 0) {
        temp_r0 = *(int *)((char *)arg0 + 4);
        *(char **)arg0 = lbl_8034AE20;
        if (temp_r0 != -2) {
            fn_802CAC54(temp_r0);
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_802C0D20(void) {
}

int fn_802C0D24(void *arg0) {
    return *(int *)((char *)arg0 + 4);
}

unsigned int fn_802C0D34(void) {
    return 1;
}

unsigned char fn_802C0D3C(void *arg0) {
    return *((unsigned char *)arg0 + 0x2C5C);
}

