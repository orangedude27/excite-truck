// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

int fn_80174298(void *arg0, int arg1) {
    extern float lbl_80558DC4[];
    extern float lbl_8055E3C8;
    extern float lbl_80561A44;
    int result = *((unsigned char *)arg0 + arg1 * 0x1C + 0x90);
    if (result != 0) {
        float one = lbl_8055E3C8;
        float value = *(float *)((char *)arg0 + 0x19C) - one;
        float limit = lbl_80561A44;
        limit = limit > value ? limit : value;
        result = !((float)__fabs(limit) <= lbl_80558DC4[0]);
    }
    return result;
}

int fn_801742FC(void *arg0) {
    extern float lbl_80561A44;
    return *(float *)((char *)arg0 + 0x1A0) > lbl_80561A44;
}

int fn_80174314(void) {
    return 8;
}

void fn_80174794(void *arg0) {
    extern float fn_801B306C(void);
    extern int fn_800216D0(void);
    extern int fn_801EA994(void);
    extern int fn_801E866C(int);
    extern void fn_8017248C(int);
    extern float lbl_80561A44;
    int count;
    int i;
    if (fn_801B306C() < lbl_80561A44 && fn_800216D0() == 0) {
        count = fn_801EA994();
        for (i = 0; i < count; i++) {
            if (i != fn_801E866C(-1) &&
                (*(int (***)(void *, int))arg0)[8](arg0, i)) {
                fn_8017248C(i);
            }
        }
    }
}

int fn_801757B0(void) { return 1; }

int fn_801758B8(void *arg0) { return *(int *)((char *)arg0 + 0x1AC) == 2; }

int fn_80175A38(void *arg0, float *arg1, float *arg2, int arg3, int arg4, int *arg5) {
    char *p = (char *)arg0 + arg3 * 0x24;
    *arg5 = 0x21F;
    arg1[0] = *(float *)(p + 0x18);
    arg1[1] = *(float *)(p + 0x1C);
    *arg2 = *(float *)(p + 0x20);
    return 1;
}

extern void *fn_8017960C(int);
extern float lbl_80561AF0;
extern float lbl_80561AF4;
int fn_80175A68(void *unused, float *arg0, float *arg1, int arg2, void *unused2, int *arg3) {
    float *p = (float *)fn_8017960C(arg2);
    float scale = lbl_80561AF0;
    float x = p[0x54 / 4] * scale + p[0x60 / 4];
    float y = p[0x5C / 4] * scale + p[0x68 / 4];
    float z = p[0x58 / 4] * scale + p[0x64 / 4];
    arg0[0] = x;
    arg0[1] = y;
    *arg3 = 0x21F;
    *arg1 = lbl_80561AF4;
    return 1;
}

int fn_80176030(void) { return 0; }

int fn_80176038(void) { return 0; }

void fn_80176400(void) {
}
