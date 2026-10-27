// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char *strchr(const char *, int);
extern char *fn_80029004(char *, int);
extern void *fn_801284F8(int, const char *);
extern void fn_8013A264(void *);
extern void fn_8013BF3C(void);
extern const char lbl_8032C414[];
char *fn_8013BC90(char *arg0, int arg1, const char *arg2) {
    char *base=arg0, *dst=arg0;
    const char *src=arg2;
    int n=arg1;
    char c;
    while (--n > 0) {
        c=*src++;
        *dst++=c;
        if (!c) goto copied;
    }
    dst[-1]=0;
copied:
    if (strchr(base, '/') != 0) base=strchr(base, '/')+1;
    { char *p=fn_80029004(base,'.'); if(p) *p=0; }
    return base;
}

extern float lbl_80561480;
extern float lbl_80561484;
extern float lbl_80561488;
extern float lbl_8056148C;
extern float lbl_80561490;
#pragma dont_inline on
void fn_8013BD30(void *arg0) {
    float e, d, c, b, a;
    float *p = (float *)arg0;
    a = lbl_80561480;
    b = lbl_80561484;
    c = lbl_80561488;
    d = lbl_8056148C;
    e = lbl_80561490;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[4] = d;
    p[3] = e;
}

extern void fn_8013BD30(void *);
extern char lbl_8032C3D8[];
__declspec(section ".sdata") extern const char lbl_80559CE0[];
__declspec(section ".sdata") extern const char lbl_80559CE8[];
__declspec(section ".sdata") extern const char lbl_80559CF0[];
void fn_8013BD5C(void *arg0, void *arg1) {
    float *v = (float *)arg0;
    void *p;
    fn_8013BD30(arg0);
    p = (*(void *(*)(void *, const char *))((char *)*(void **)arg1 + 0x5c))(arg1, lbl_8032C3D8);
    if (p != 0) {
        v[0] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, lbl_80559CE0, v[0]);
        v[1] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, lbl_80559CE8, v[1]);
        v[2] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, (const char *)lbl_8032C3D8 + 0xC, v[2]);
        v[4] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, (const char *)lbl_8032C3D8 + 0x18, v[4]);
        v[3] = (*(float (*)(void *, const char *, float))((char *)*(void **)p + 0x28))(p, lbl_80559CF0, v[3]);
    }
}

extern void fn_8013A2FC(void *, int);
extern void fn_8013BD5C(void *, void *);
extern const char lbl_8032C420[];
void *fn_8013BE64(void *arg0, const char *arg1) {
    void *p;
    char *dst;
    const char *src;
    int n;
    char c;
    p = fn_801284F8(0x78, lbl_8032C414);
    if (p != 0) fn_8013A264((char *)p + 0x40);
    dst = (char *)p;
    src = arg1;
    n = 0x40;
    while (--n > 0) {
        c = *src++;
        *dst++ = c;
        if (!c) goto copied;
    }
    dst[-1] = 0;
copied:
    fn_8013A2FC((char *)p + 0x40, (*(int (**)(void *, const char *))((char *)*(void **)arg0 + 0x5c))(arg0, lbl_8032C420));
    fn_8013BD5C((char *)p + 0x60, arg0);
    *(int *)((char *)p + 0x74) = 0;
    return p;
}

void fn_8013BF3C(void) {
    ((void (*)(void))fn_8013BD30)();
}

#pragma scheduling invalid_target
void *fn_8013BF40(char *arg0) {
    void *p = fn_801284F8(0x78, lbl_8032C414);
    int count;
    char *dst;
    unsigned char c;
    if (p != 0)
        fn_8013A264((char *)p + 0x40);
    dst = (char *)p;
    count = 0x40;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto copied;
copy:
    c = (unsigned char)*arg0++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
copied:
    ((void (*)(void *))fn_8013BF3C)((char *)p + 0x60);
    *(volatile int *)((char *)p + 0x74) = 0;
    return p;
}
#pragma scheduling on
void fn_8013BFE0(void) {

}

void fn_8013BFE4(void) {

}

extern void fn_80128658(void);
extern void fn_80128668(void *);
extern void fn_8013A598(void *, int);
extern unsigned char lbl_8042F8C8[];
void fn_8013C428(void *arg0) {
    int i;
    int count;
    unsigned char *r5 = lbl_8042F8C8;
    i = 0;
    count = *(int *)(lbl_8042F8C8 + 0x240);
    if (count > 0) {
        do {
            if (*(void **)r5 == arg0) {
                int offset = i * 0x48;
                unsigned char *entry = lbl_8042F8C8 + offset;
                int ref = *(int *)(entry + 0x44) - 1;
                *(int *)(entry + 0x44) = ref;
                if (ref == 0) {
                    int n;
                    int tail;
                    unsigned char *dst;
                    unsigned char *src;
                    if (*(int *)((char *)arg0 + 0x74) != 0) fn_80128658();
                    if (arg0 != 0) {
                        fn_8013A598((char *)arg0 + 0x40, -1);
                        fn_80128668(arg0);
                    }
                    n = *(int *)(lbl_8042F8C8 + 0x240) - 1;
                    *(int *)(lbl_8042F8C8 + 0x240) = n;
                    tail = n * 0x48;
                    dst = lbl_8042F8C8 + offset;
                    src = lbl_8042F8C8 + tail;
                    *(int *)dst = *(int *)src;
                    { unsigned char a = src[4]; unsigned char b = src[5]; dst[4] = a; dst[5] = b; }
                    { unsigned char a = src[6]; unsigned char b = src[7]; dst[6] = a; dst[7] = b; }
                    { unsigned char a = src[8]; unsigned char b = src[9]; dst[8] = a; dst[9] = b; }
                    { unsigned char a = src[10]; unsigned char b = src[11]; dst[10] = a; dst[11] = b; }
                    { unsigned char a = src[12]; unsigned char b = src[13]; dst[12] = a; dst[13] = b; }
                    { unsigned char a = src[14]; unsigned char b = src[15]; dst[14] = a; dst[15] = b; }
                    { unsigned char a = src[16]; unsigned char b = src[17]; dst[16] = a; dst[17] = b; }
                    { unsigned char a = src[18]; unsigned char b = src[19]; dst[18] = a; dst[19] = b; }
                    { unsigned char a = src[20]; unsigned char b = src[21]; dst[20] = a; dst[21] = b; }
                    { unsigned char a = src[22]; unsigned char b = src[23]; dst[22] = a; dst[23] = b; }
                    { unsigned char a = src[24]; unsigned char b = src[25]; dst[24] = a; dst[25] = b; }
                    { unsigned char a = src[26]; unsigned char b = src[27]; dst[26] = a; dst[27] = b; }
                    { unsigned char a = src[28]; unsigned char b = src[29]; dst[28] = a; dst[29] = b; }
                    { unsigned char a = src[30]; unsigned char b = src[31]; dst[30] = a; dst[31] = b; }
                    { unsigned char a = src[32]; unsigned char b = src[33]; dst[32] = a; dst[33] = b; }
                    { unsigned char a = src[34]; unsigned char b = src[35]; dst[34] = a; dst[35] = b; }
                    { unsigned char a = src[36]; unsigned char b = src[37]; dst[36] = a; dst[37] = b; }
                    { unsigned char a = src[38]; unsigned char b = src[39]; dst[38] = a; dst[39] = b; }
                    { unsigned char a = src[40]; unsigned char b = src[41]; dst[40] = a; dst[41] = b; }
                    { unsigned char a = src[42]; unsigned char b = src[43]; dst[42] = a; dst[43] = b; }
                    { unsigned char a = src[44]; unsigned char b = src[45]; dst[44] = a; dst[45] = b; }
                    { unsigned char a = src[46]; unsigned char b = src[47]; dst[46] = a; dst[47] = b; }
                    { unsigned char a = src[48]; unsigned char b = src[49]; dst[48] = a; dst[49] = b; }
                    { unsigned char a = src[50]; unsigned char b = src[51]; dst[50] = a; dst[51] = b; }
                    { unsigned char a = src[52]; unsigned char b = src[53]; dst[52] = a; dst[53] = b; }
                    { unsigned char a = src[54]; unsigned char b = src[55]; dst[54] = a; dst[55] = b; }
                    { unsigned char a = src[56]; unsigned char b = src[57]; dst[56] = a; dst[57] = b; }
                    { unsigned char a = src[58]; unsigned char b = src[59]; dst[58] = a; dst[59] = b; }
                    { unsigned char a = src[60]; unsigned char b = src[61]; dst[60] = a; dst[61] = b; }
                    { unsigned char a = src[62]; unsigned char b = src[63]; dst[62] = a; dst[63] = b; }
                    { unsigned char a = src[64]; unsigned char b = src[65]; dst[64] = a; dst[65] = b; }
                    { unsigned char a = src[66]; unsigned char b = src[67]; dst[66] = a; dst[67] = b; }
                    *(int *)(entry + 0x44) = *(int *)(src + 0x44);
                }
                break;
            }
            r5 += 0x48;
            i++;
        } while (--count);
    }
}

