__declspec(section ".sdata") extern char lbl_8055B8B8[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

__declspec(section ".sdata") extern char lbl_8055B8B0[];
extern char lbl_80490968[];
extern char *strstr(const char *, const char *);
extern void fn_8022C9D0(void);
extern int fn_80232B70(int);
extern void fn_8022A8E4(int);
extern double lbl_80563590;
extern char lbl_8033FF98[];
extern int stricmp(const char *, const char *);
extern void fn_8022CAA8(void *);
extern float lbl_80563588;
extern char *strncpy(char *, const char *, unsigned int);
extern void fn_8023293C(void *, char *, float);
extern int fn_800241CC(int);
extern void fn_8022B390(const char *, const char *, int, int *, int *);
void fn_8022A7D0(void) {
    fn_8022C9D0();
}

int fn_8022A7D4(const char *arg0) {
    return strstr(arg0, lbl_8055B8B0) != 0;
}

int fn_8022A804(const char *arg0) {
    return strstr(arg0, lbl_8055B8B8) != 0;
}

unsigned int fn_8022A834(unsigned int arg0) {
    unsigned int byte = arg0 >> 24;
    if (byte >= 0x20 || byte == 0) {
    } else {
        arg0 = (arg0 & 0x00FFFFFF) | 0xFF000000;
    }
    return arg0;
}

void fn_8022A858(int arg0) {
    fn_8022CAA8(lbl_80490968 + arg0 * 0x74);
}

int fn_8022A86C(int arg0) {
    int i;
    for (i = 0; i < 0x100; i++) {
        if ((unsigned char)lbl_80490968[i * 0x74] == 0) {
            fn_8022A858(i);
            return i;
        }
    }
    return -1;
}

extern void *fn_8022CA2C(void);
int fn_8022AA84(void) {
    return *(int *)((char *)fn_8022CA2C() + 0x38);
}

extern float fn_8022CA40(void *);
extern float lbl_8056358C;
float fn_8022AAA8(void *unused, char *arg1) {
    void *p = fn_8022CA2C();
    if (*(int *)((char *)p + 8) != 0) {
        float scale = fn_8022CA40(p);
        return scale * ((float (*)(void *, char *, float))fn_8023293C)(*(void **)((char *)p + 8), arg1, lbl_80563588);
    }
    return lbl_8056358C;
}

int fn_8022AB18(int unused, int arg1, int arg2) {
    void *p = fn_8022CA2C();
    if (arg1 == 0) {
        if (arg2 == 2) return *(int *)((char *)p + 0x44);
        return *(int *)((char *)p + 0x4c);
    }
    if (arg1 == 1) {
        if (arg2 == 2) return *(int *)((char *)p + 0x48);
        return *(int *)((char *)p + 0x50);
    }
    return 0;
}

int fn_8022AB94(const char *arg0, char arg1) {
    int count = 0;
    while (*arg0 != 0) {
        if (*arg0 == arg1) count++;
        arg0++;
    }
    return count;
}

void fn_8022ABC8(void *arg0, const char *arg1, int arg2) {
    char buffer[0x800];
    strncpy(buffer, arg1, arg2);
    buffer[arg2] = 0;
    fn_8023293C(arg0, buffer, lbl_80563588);
}

extern void fn_8022ACFC(float *, float *, float *, float *, float, float);
__declspec(section ".sdata") extern double lbl_80563590;
void fn_8022AC1C(int unused0, int unused1, int arg2, int arg3, int *arg4, int *arg5, int *arg6, int *arg7) {
    float a, b, c, d;
    fn_8022ACFC(&a, &b, &c, &d, (float)(unsigned int)arg2, (float)(unsigned int)arg3);
    *arg4 = (int)a;
    *arg5 = (int)b;
    *arg6 = (int)c;
    *arg7 = (int)d;
}

extern float lbl_80563588;
extern char *strncpy(char *, const char *, unsigned int);
extern void fn_8023293C(void *, char *, float);
extern int fn_800241CC(int);
extern void fn_8022B390(const char *, const char *, int, int *, int *);
#pragma push
#pragma use_lmw_stmw off
int fn_8022B2D4(int arg0, const char *arg1, int arg2, int arg3) {
    int bestIndex = 0, best = -1, i = 0;
    goto check;
body: {
        int x, y;
        int cost;
        fn_8022B390((const char *)arg0, arg1, i, &x, &y);
        cost = fn_800241CC(x - arg2) + fn_800241CC(y - arg3);
        if (best < 0 || cost < best) {
            bestIndex = i;
            best = cost;
        }
        i = i + 1;
    }
check:
    if (i == 0) goto body;
    if ((signed char)arg1[i - 1] != 0) goto body;
    return bestIndex;
}
#pragma pop
void fn_8022BAD0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, double arg7, int arg8) {
    int a = arg0 ^ 0x8000;
    int b = arg1 ^ 0x8000;
    int c = arg2 ^ 0x8000;
    int d = arg3 ^ 0x8000;
    int e = arg4 ^ 0x8000;
    double f = arg7;
    fn_8022BD40(c, e, arg8, a - lbl_80563590, b - lbl_80563590, d - lbl_80563590, f - lbl_80563590, arg5, arg6);
}

extern void fn_80230C30(int, int);
void fn_8022BB60(float *arg0, float *arg1, float farg0, float farg1) {
    int iarg0 = (int)farg0;
    int iarg1 = (int)farg1;
    fn_80230C30(iarg0, iarg1);
    *arg0 += farg0 - (float)iarg0;
    *arg1 -= farg1 - (float)iarg1;
}

void fn_8022C9D0(void) {
    unsigned char *p = (unsigned char *)lbl_80490968;
    int i = 0;
loop:
    if (*p != 0) fn_8022A8E4(i);
    i++;
    if (i < 0x100) {
        p += 0x74;
        goto loop;
    }
}

float fn_8022CA40(void *arg0) {
    float value = *(float *)((char *)arg0 + 0x34);
    if (value < lbl_80563588) return lbl_80563588;
    return value / fn_80232B70(*(int *)((char *)arg0 + 8));
}

extern double lbl_80563590;
extern int fn_80232B70(int);
extern char lbl_8033FF98[];
extern int stricmp(const char *, const char *);
int fn_8022CC8C(const char *arg0) {
    unsigned int i;
    char *p = lbl_8033FF98;
    for (i = 0; i < 0x1b; i++, p += 8) {
        if (stricmp(arg0, *(const char **)(p + 4)) == 0) return *(int *)(lbl_8033FF98 + i * 8);
    }
    return 0x1a;
}

__declspec(section ".sdata") extern char lbl_8055B928[];
extern char lbl_80340070[];
extern int sscanf(const char *, const char *, ...);
int fn_8022CD0C(char *arg0) {
    int sp18;
    int sp14;
    int sp10;
    int spC;
    int sp8;
    int result;

    if (sscanf(arg0, lbl_8055B928, &sp18) == 1) {
        return sp18;
    }
    result = sscanf(arg0, lbl_80340070, &sp14, &sp10, &spC, &sp8);
    if (result == 3) {
        sp18 = ((sp14 & 0xFF) << 16) | ((sp10 & 0xFF) << 8) | (spC & 0xFF) | 0xFF000000;
        return sp18;
    }
    if (result == 4) {
        sp18 = ((sp14 & 0xFF) << 24) | ((sp10 & 0xFF) << 16) | ((spC & 0xFF) << 8) | (sp8 & 0xFF);
        return sp18;
    }
    return 0xFFFF00FF;
}

