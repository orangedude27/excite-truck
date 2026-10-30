// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
extern void *fn_80131234();
#pragma inline off(fn_801302E0)
extern int fn_801302E0(void *);

__declspec(section ".sdata") extern char lbl_80559AF8;
extern char lbl_8032B224[];
__declspec(section ".sdata") extern char lbl_80559B00[];

extern int lbl_804230D0;
extern char lbl_80423054[];
extern char lbl_8042F4B8[];
extern char lbl_8055E048;
extern void fn_8013111C();

typedef struct {
    int f[26];
    char pad[12];
    char f2;
} MsgCopy;

extern int lbl_802F8E60[];
extern int lbl_8055E04C;
extern char *lbl_8055E050;
extern int fn_8012BF24(void *);
extern int stricmp(const char *, const char *);
void fn_801301E0(unsigned char *arg0) {
    unsigned char *base;
    unsigned char *p;
    unsigned char *q;
    unsigned char a, b, c, d;
    int i;

    a = arg0[0x40];
    b = arg0[0x43];
    c = arg0[0x41];
    d = arg0[0x42];
    arg0[0x40] = b;
    arg0[0x43] = a;
    arg0[0x41] = d;
    arg0[0x42] = c;

    p = arg0 + 0x44;
    q = arg0 + 0x48;
    base = arg0;
    for (i = 0; i < *(int *)(arg0 + 0x40); i++) {
        a = p[0]; b = p[3]; p[0] = b; p[3] = a;
        a = p[1]; b = p[2]; p[1] = b; p[2] = a;
        p += 8;

        a = q[0]; b = q[3]; q[0] = b; q[3] = a;
        a = q[1]; b = q[2]; q[1] = b; q[2] = a;
        q += 8;

        *(unsigned int *)(base + 0x44) += (unsigned int)arg0;
        *(unsigned int *)(base + 0x48) += (unsigned int)arg0;
        base += 8;
    }
}

__declspec(section ".data") extern int lbl_804230D0;
#pragma dont_inline on
void fn_8013028C(void) {
    int index = lbl_804230D0;
    if (index >= 0 && (unsigned int)index < 2) {
        fn_8012BF24(*(void **)((char *)lbl_802F8E60 + index * 12));
    }
    lbl_804230D0 = -1;
}
#pragma dont_inline reset

int fn_80130390(void) {
    int index = lbl_8055E04C;
    return *(int *)((char *)lbl_802F8E60 + index * 12);
}

extern char lbl_80423054[];
extern char lbl_8042F4B8[];
extern char lbl_8055E048;
extern void fn_8013111C();
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_801303A8(void) {
    register unsigned int *s;
    register unsigned int *d;
    register unsigned int v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11;
    register unsigned int v12, v13, v14, v15, v16, v17, v18, v19, v20, v21;
    register unsigned int v22, v23, v24, v25, v26, v27;
    register unsigned char c;

    lbl_8055E048 = 1;
    lbl_804230D0 = -1;
    fn_8013111C(lbl_8055E04C);
    s = (unsigned int *)lbl_8042F4B8;
    d = (unsigned int *)lbl_80423054;

    v22 = s[22]; d[24] = v22;
    v24 = s[24]; d[26] = v24;
    v25 = s[25]; d[27] = v25;
    v26 = s[26]; d[28] = v26;
    v27 = s[27]; d[29] = v27;
    c = *((unsigned char *)s + 0x70);

    v0 = s[0]; v1 = s[1]; v2 = s[2]; v3 = s[3];
    v4 = s[4]; v5 = s[5]; v6 = s[6]; v7 = s[7];
    v8 = s[8]; v9 = s[9]; v10 = s[10]; v11 = s[11];
    v12 = s[12]; v13 = s[13]; v14 = s[14]; v15 = s[15];
    v16 = s[16]; v17 = s[17]; v18 = s[18]; v19 = s[19];
    v20 = s[20]; v21 = s[21]; v23 = s[23];
    d[2] = v0; d[3] = v1; d[4] = v2; d[5] = v3;
    d[6] = v4; d[7] = v5; d[8] = v6; d[9] = v7;
    d[10] = v8; d[11] = v9; d[12] = v10; d[13] = v11;
    d[14] = v12; d[15] = v13; d[16] = v14; d[17] = v15;
    d[18] = v16; d[19] = v17; d[20] = v18; d[21] = v19;
    d[22] = v20; d[23] = v21; d[25] = v23;

    lbl_80423054[0] = c ? 0x2E : 0x2C;
    *((char *)d + 0x78) = c;
}
#pragma scheduling on
#pragma use_lmw_stmw on
void fn_80130518(void) {
    fn_8013028C();
    *(int *)((char *)0x804230D0 + 4) = 0;
    memset((char *)0x804230D0 + 8, 0, 0xC350);
    *(char *)0x8055E048 = 0;
}

extern char *strchr(const char *, int);
void fn_80130568(char *arg0) {
    char *base = arg0;
    if (*(char *)lbl_8055E050 != '.') {
        *arg0 = *(char *)lbl_8055E050;
        while ((arg0 = strchr(base, '.')) != 0) {
            *arg0 = *(char *)lbl_8055E050;
        }
    }
}

void fn_801308E4(void *arg0, void *arg1, int arg2, int arg3) {
    fn_801305C4(arg0, arg1, (char *)lbl_8055E050 + 8, arg2);
}

void fn_801308F4(char *dst, int count, int value) {
    fn_8013072C(dst, count, value);
}

void fn_801308F8(char *dst, int count, int limit) {
    char *src;
    unsigned char c;
    if (limit < 1000)
        goto fallback;
    src = (char *)fn_80131234(lbl_8032B224);
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
    goto done;
fallback:
    fn_8013072C();
done:
    ;
}

void fn_80130978(int arg0, int arg1) { fn_80130980(arg0, arg1, 3); }

extern void fn_801345D8(void *, ...);
extern void *lbl_80559AA0;
#pragma scheduling invalid_target
void fn_80130FCC(void *arg0, int arg1, void *arg2) {
    fn_801345D8(arg0, arg1, &lbl_80559AA0, 1, arg2);
}
#pragma scheduling on
extern int lbl_802F8EE0[];
extern char lbl_8032B300[];
#pragma scheduling invalid_target
int fn_80130FE0(int arg0) {
    int values[10];
    int *p;
    int quotient;
    int remainder;
    p = &lbl_802F8EE0[0];
    values[0] = *p++;
    values[1] = *p++;
    values[2] = *p++;
    values[3] = *p++;
    values[4] = *p++;
    values[5] = *p++;
    values[6] = *p++;
    values[7] = *p++;
    values[8] = *p++;
    values[9] = *p++;
    quotient = arg0 / 10;
    if (quotient == 1) {
        fn_80131234(lbl_8032B300);
    } else {
        remainder = arg0 % 10;
        fn_80131234((void *)values[remainder]);
    }
}

void fn_801310B4(void *arg0, void *arg1, int arg2) {
    int result = fn_80130FE0(arg2);
    fn_801345D8(arg0, arg1, &lbl_80559AF8, arg2, result + 1);
}

extern void *fn_8012C370(const char *, unsigned int, unsigned int *, int *, int, void **);
extern void fn_8012C4D8(void *);
extern void fn_8012BEF0(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_8012FAB8(void *);
extern void fn_80131308(void);
extern void *memcpy(void *, const void *, unsigned int);
extern char lbl_8032B028[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8013111C(int index) {
    int size;
    unsigned int status;
    void *out;
    char *data;
    char *strings = lbl_8032B028;
    char *path;
    void *buffer;
    if (index < 0)
        return;
    if ((unsigned int)index >= 2)
        return;
    fn_8013028C();
    fn_80131308();
    fn_8012BEF0(*(void **)((char *)lbl_802F8E60 + index * 0xC));
    path = strings + 0x2E8;
    size = 0;
    buffer = fn_8012C370(path, 0x4C414E47, &status, &size, 0, &out);
    if (buffer != 0) {
        data = (char *)&lbl_804230D0;
        memcpy(data + 8, buffer, size);
        fn_8012C4D8(buffer);
        if (status == 1) {
            fn_801301E0((unsigned char *)(data + 8));
        } else {
            fn_802E30C8(strings + 0x1C0, path);
        }
        *(char **)((char *)&lbl_804230D0 + 4) = (char *)&lbl_804230D0 + 8;
    } else {
        fn_802E30C8(strings + 0x1D4, path);
    }
    fn_8012FAB8(strings + 0x2F4);
    lbl_804230D0 = index;
}
#pragma scheduling on
#pragma use_lmw_stmw on
void *fn_80131234(void *arg0) {
    int result = fn_801302E0(arg0);
    switch (result) {
    case 0:
        return lbl_80559B00;
    default:
        return (void *)result;
    }
}
#pragma scheduling on
void fn_80131264(void *arg0) {
    fn_801302E0(arg0);
}

void fn_80131268(void *arg0) {
    fn_80131234(arg0);
}

extern int lbl_8055E044;
void fn_80131308(void) { lbl_8055E044 += 1; }

void fn_801312EC(int *arg0, int arg1) {
    arg0[0] = arg1;
    arg0[1] = 0;
    arg0[2] = ~lbl_8055E044;
}

void fn_80131318(int *arg0) {
    int temp_r3;
    temp_r3 = fn_801302E0((void *)arg0[0]);
    arg0[1] = temp_r3;
    if (temp_r3 == 0) {
        arg0[1] = arg0[0];
        return;
    }
    arg0[2] = lbl_8055E044;
}

__declspec(section ".data") extern int lbl_802FE850;
extern int atoi(const char *);
extern int strlen(const char *);
extern int fn_8002B1D8(const char *, const char *, int);
#pragma scheduling invalid_target
void fn_80131368(char *arg0) {
    int flag = 0;
    int c;
    int signedC;
    int isNumber;
    int *p;
    unsigned int i;

    c = *(unsigned char *)arg0;
    signedC = (signed char)c;
    if (signedC < 0 || signedC >= 0x100)
        flag = 1;
    if (flag != 0)
        isNumber = 0;
    else
        isNumber = *(unsigned short *)(*(int *)(*(int *)((char *)&lbl_802FE850 + 0x38) + 8) + signedC * 2) & 8;

    if (isNumber) {
        lbl_8055E04C = atoi(arg0);
        return;
    }

    p = lbl_802F8E60;
    i = 0;
    do {
        if (fn_8002B1D8(arg0, (const char *)p[0], strlen(arg0)) == 0) {
            lbl_8055E04C = i;
            return;
        }
        i++;
        p += 3;
    } while (i < 2);
}
#pragma scheduling on
extern int lbl_8055E044;
extern char lbl_8032B328[];
int fn_802E317C(const char *, ...);

char *fn_8013126C(char *arg0, const char *arg1) {
    const unsigned char *src = (const unsigned char *)arg1;
    int count;
    unsigned char c;
    char *dst;
    fn_802E317C(lbl_8032B328);
    dst = arg0;
    for (count = 0x12c; count > 0; count--) {
    }
    dst[-1] = 0;
    do {
        c = *src++;
        *dst++ = c;
    } while ((signed char)c != 0);
    return arg0;
}
extern char lbl_80559B00[];
extern char lbl_8032B224[];
