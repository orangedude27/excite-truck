// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_8028E240(int);
int fn_802C2C00(int);
int fn_802C990C(int);
void fn_802C2BB8(int *, int *, int *);
void fn_802C2B78(float, float, float);
extern int lbl_804BD7B0[4];
extern unsigned char lbl_8055F92D;
extern float lbl_805649FC;
extern float lbl_80564AAC;
void fn_8028E398(int);
void fn_80128668(void *);
extern void *lbl_8055F924;
void fn_8028E080(void);
__declspec(section ".sdata") extern float lbl_805649F0;
void fn_802A9FE0(void *arg0) {
    float value = lbl_805649F0;
    int i;
    for (i = 0; i <= 0xC0; i += 4) *(float *)((char *)arg0 + i) = value;
    *(unsigned char *)((char *)arg0 + 0xC4) = 0;
    *(float *)((char *)arg0 + 0xCC) = value;
    *(float *)((char *)arg0 + 0xC8) = value;
    *(float *)((char *)arg0 + 0xD0) = value;
    *(float *)((char *)arg0 + 0xD4) = value;
    *(float *)((char *)arg0 + 0xD8) = value;
}

void fn_802AA0C8(void *arg0) {
    extern float lbl_805649F0;
    extern float lbl_805649F4;
    volatile float first = lbl_805649F0;
    volatile float second = lbl_805649F4;
    *(unsigned char *)((char *)arg0 + 0xDC) = 0;
    *(float *)((char *)arg0 + 0xE0) = first;
    *(float *)((char *)arg0 + 0xE4) = second;
    *(int *)((char *)arg0 + 0xE8) = -1;
}

void fn_802AA0EC(void *arg0) {
    extern float lbl_805649F0;
    volatile float value = lbl_805649F0;
    *(unsigned char *)((char *)arg0 + 0xEC) = 0;
    *(float *)((char *)arg0 + 0xF0) = value;
}

extern float PSVECDotProduct(const void *, const void *);
void fn_802AA100(void *arg0, void *arg1, void *arg2, void *arg3) {
    float sp1C, sp18, sp14, sp10, spC, sp8;
    float dot0, dot1, x1, x0, y1, x2, y0, y2;
    dot0 = PSVECDotProduct(arg1, arg2);
    dot1 = PSVECDotProduct(arg1, arg3);
    x1 = ((float *)arg2)[1] * dot0;
    x0 = ((float *)arg2)[0] * dot0;
    y1 = ((float *)arg3)[1] * dot1;
    x2 = ((float *)arg2)[2] * dot0;
    y0 = ((float *)arg3)[0] * dot1;
    sp14 = x0;
    y2 = ((float *)arg3)[2] * dot1;
    sp18 = x1;
    sp1C = x2;
    ((float *)arg0)[1] = x1 + y1;
    ((float *)arg0)[0] = x0 + y0;
    ((float *)arg0)[2] = x2 + y2;
    sp8 = y0;
    spC = y1;
    sp10 = y2;
}

void fn_802AA1D0(unsigned int arg0) {
    extern int lbl_8055F928;
    extern int lbl_80488648[];
    extern int fn_801EE0C8(int);
    extern void fn_802C77F0(int, float *);
    float sp[8];
    int *p = (int *)(lbl_8055F928 + arg0 * 0x108);
    int v = fn_801EE0C8(arg0 < 8 ? lbl_80488648[arg0] : 0);
    fn_802C77F0(v, sp);
    *(float *)((char *)p + 0xF8) = sp[1] - sp[0];
    *(float *)((char *)p + 0x100) = sp[3] - sp[2];
    *(float *)((char *)p + 0xFC) = sp[5] - sp[4];
}

void fn_802AAC80(void *arg0, void *arg1, float farg0) {
    extern void fn_801E86F8(int);
    extern float lbl_805649F0, lbl_805649FC, lbl_80564A04;
    volatile float step = lbl_80564A04;
    float current;
    fn_801E86F8(0);
    if (*(unsigned char *)((char *)arg0 + 0xEC)) {
        current = *(float *)((char *)arg0 + 0xF0);
        *(unsigned char *)((char *)arg0 + 0xEC) = 0;
        current = current + step * farg0;
        if (current < lbl_805649FC) {
            *(float *)((char *)arg0 + 0xF0) = current;
        } else {
            *(float *)((char *)arg0 + 0xF0) = lbl_805649FC;
        }
    } else if (*(unsigned char *)((char *)arg1 + 0x118)) {
        *(float *)((char *)arg0 + 0xF0) = lbl_805649F0;
    } else {
        current = *(float *)((char *)arg0 + 0xF0) - step * farg0;
        if (current > lbl_805649F0) {
            *(float *)((char *)arg0 + 0xF0) = current;
        } else {
            *(float *)((char *)arg0 + 0xF0) = lbl_805649F0;
        }
    }
    if (*(unsigned int *)((char *)arg1 + 0x68) & 8)
        *(float *)((char *)arg0 + 0xF0) = lbl_805649F0;
}

void fn_802AAF00(int a, int b, int c) {}

void fn_802AB500(void) {}

void fn_802AB504(void) {
    extern void fn_801EF024(void (*)(void));
    extern void fn_80128670(void *);
    extern void fn_802CAC54(int);
    extern void fn_802A9F30(void), fn_802A9F90(void), fn_802A9FB0(void);
    extern unsigned char lbl_8055F92C;
    extern void *lbl_8055F924;
    extern int lbl_8055F928, lbl_8055CC60, lbl_8055CC64;
    int *p;
    int *q;
    lbl_8055F92C = 0;
    fn_801EF024(fn_802A9F30);
    fn_801EF024(fn_802A9F90);
    fn_801EF024(fn_802A9FB0);
    p = (int *)lbl_8055F924;
    if (p) {
        fn_8028E398(p[0]);
        fn_8028E398(p[1]);
        fn_80128668(p);
    }
    lbl_8055F924 = 0;
    q = (int *)lbl_8055F928;
    if (q) fn_80128670((char *)q - 0x10);
    lbl_8055F928 = 0;
    fn_802CAC54(lbl_8055CC60);
    lbl_8055CC60 = -2;
    fn_802CAC54(lbl_8055CC64);
    lbl_8055CC64 = -2;
}

void fn_802AB6D0(void) {}

void fn_802AB6D4(void) {
    extern int fn_80287B14(void);
    extern int fn_80287B24(int);
    extern int fn_802C86DC(void);
    extern void fn_802AAD5C(int, int, int);
    extern void fn_802AAF00(int, int, int);
    extern void fn_802AAF04(int, int, int);
    extern int lbl_8055F928;
    int count = fn_80287B14();
    int obj = fn_802C86DC();
    int i;
    for (i = 0; i < count; i++) {
        int item = fn_80287B24(i);
        int data = lbl_8055F928 + i * 0x108;
        fn_802AAD5C(obj, data, item);
        fn_802AAF00(obj, data, item);
        fn_802AAF04(obj, data, item);
    }
}

void fn_802AB994(void) {
    fn_802C990C(lbl_804BD7B0[0]);
    ((void (*)(void *, float, float, float))fn_802C2B78)((void *)lbl_804BD7B0, *(float *)&lbl_804BD7B0[1], *(float *)&lbl_804BD7B0[2], *(float *)&lbl_804BD7B0[3]);
    fn_802C2C00(lbl_8055F92D);
}

void fn_802AB9E0(void) { fn_8028E070(); }

void fn_802AB9E4(void) { fn_8028E080(); }

void fn_802ABC2C(void) {
    int *p = (int *)lbl_8055F924;
    if (p == 0) return;
    if (p != 0) {
        fn_8028E398(p[0]);
        fn_8028E398(p[1]);
        fn_80128668(p);
    }
    lbl_8055F924 = 0;
}

void fn_802ABE50(void) { fn_8028E240(0); }

void fn_802ABFF8(int arg0, float farg0) {
    lbl_8055F92D = fn_802C2C00(1);
    lbl_804BD7B0[0] = fn_802C990C(arg0);
    fn_802C2BB8(&lbl_804BD7B0[1], &lbl_804BD7B0[2], &lbl_804BD7B0[3]);
    fn_802C2B78(farg0, lbl_80564AAC + farg0, lbl_805649FC);
}

void fn_802AC070(void) {
    fn_802C990C(lbl_804BD7B0[0]);
    ((void (*)(void *, float, float, float))fn_802C2B78)((void *)lbl_804BD7B0, *(float *)&lbl_804BD7B0[1], *(float *)&lbl_804BD7B0[2], *(float *)&lbl_804BD7B0[3]);
    fn_802C2C00(lbl_8055F92D);
}
struct Obj802AAC80 { char pad[0xEC]; unsigned char flag; float value; };
struct Ctrl802AAC80 { char pad[0x68]; unsigned int flags; char pad2[0xAC]; unsigned char flag; };
