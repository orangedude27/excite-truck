// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_804230D0;
extern int lbl_802F8E60[];
extern int lbl_8055E04C;
extern int lbl_8055E050;
extern int fn_8012BF24(void *);
extern int stricmp(const char *, const char *);
void fn_801301E0(unsigned char *arg0) {
    unsigned char a, b, c, d;
    unsigned char *p = arg0 + 0x44;
    unsigned char *q = arg0 + 0x48;
    int i;
    a = arg0[0x40]; b = arg0[0x43]; c = arg0[0x41]; d = arg0[0x42];
    arg0[0x40] = b; arg0[0x43] = a; arg0[0x41] = d; arg0[0x42] = c;
    for (i = 0; i < arg0[0x40]; i++) {
        a=p[0]; b=p[3]; p[0]=b; p[3]=a;
        a=p[1]; b=p[2]; p[1]=b; p[2]=a;
        a=q[0]; b=q[3]; q[0]=b; q[3]=a;
        a=q[1]; b=q[2]; q[1]=b; q[2]=a;
        *(unsigned int *)p += (unsigned int)arg0;
        *(unsigned int *)q += (unsigned int)arg0;
        p += 8; q += 8;
    }
}

__declspec(section ".data") extern int lbl_804230D0;
void fn_8013028C(void) {
    int index = lbl_804230D0;
    if (index >= 0 && (unsigned int)index < 2) {
        fn_8012BF24(*(void **)((char *)lbl_802F8E60 + index * 12));
    }
    lbl_804230D0 = -1;
}

int fn_80130390(void) {
    return lbl_802F8E60[lbl_8055E04C * 3];
}

void fn_80130518(void) {
    fn_8013028C();
    *(int *)((char *)0x804230D0 + 4) = 0;
    memset((char *)0x804230D0 + 8, 0, 0xC350);
    *(char *)0x8055E048 = 0;
}

void fn_801308E4(void *arg0, void *arg1, int arg2, int arg3) {
    fn_801305C4(arg0, arg1, *(char **)0x8055E050 + 8, arg2);
}

void fn_801308F4(void) {
    fn_8013072C();
}

void fn_801308F8(char *dst, int count, int limit) {
    char *src;
    if (limit < 1000) {
        fn_8013072C();
        return;
    }
    src = (char *)fn_80131234();
    for (;;) {
        int c = *src++;
        *dst++ = c;
        if ((signed char)c == 0)
            break;
        if (--count <= 0) {
            dst[-1] = 0;
            break;
        }
    }
}

void fn_80130978(int arg0, int arg1) { fn_80130980(arg0, arg1, 3); }

extern void fn_801345D8(void *, ...);
extern char lbl_80559AA0[];
void fn_80130FCC(void *arg0, int arg1, int arg2, int arg3, void *arg4) {
    fn_801345D8(arg0, arg1, lbl_80559AA0, 1, arg4);
}

extern int lbl_802F8EE0[];
extern char lbl_8032B300[];
void fn_80130FE0(int arg0) {
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
        {
            int *selected = &values[remainder];
            fn_80131234((void *)*selected);
        }
    }
}

void fn_80131264(void) {
    fn_801302E0();
}

void fn_80131268(void) {
    fn_80131234();
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
    temp_r3 = fn_801302E0(arg0[0]);
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
void fn_80131368(char *arg0) {
    register int c;
    int flag = 0;
    int isNumber;
    int *p;
    unsigned int i;

    c = *(unsigned char *)arg0;
    c = (signed char)c;
    if (c < 0 || c >= 0x100)
        flag = 1;
    if (flag != 0)
        isNumber = 0;
    else
        isNumber = *(unsigned short *)(*(int *)(*(int *)((char *)&lbl_802FE850 + 0x38) + 8) + c * 2) & 8;

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

extern int lbl_8055E044;
extern char lbl_8032B328[];
int fn_802E317C(const char *, ...);

char *fn_8013126C(char *arg0, const char *arg1) {
    int count;
    char *dst;
    const char *src;
    src = arg1;
    fn_802E317C(lbl_8032B328);
    dst = arg0;
    count = 0x12c;
    do {
        count--;
    } while (count > 0);
    count = 0x12c;
    for (;;) {
        int c = *src++;
        if ((signed char)c == 0)
            break;
        *dst++ = c;
    }
    *dst = 0;
    return arg0;
}
extern char lbl_80559AF8[];
extern char lbl_80559B00[];
extern char lbl_8032B224[];
