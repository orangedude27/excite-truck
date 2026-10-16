// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FFB5;
extern void *lbl_8055FF8C;
extern float lbl_804FC680[];
extern int lbl_8055D1EC;
extern int lbl_8055D1F0;
extern void fn_802E7770(void);
extern int fn_802E7774(void (*arg0)(void));
extern void fn_802E2E0C(void *arg0, void *arg1);
extern int TRKReadBuffer_ui32(void);
extern void fn_802E9A2C(void);
extern void fn_80060CC0(int, int, void (*)());
extern void fn_802E30C8(char *, int, char *, ...);
extern void fn_802E5248(int, int);
extern void fn_802E51D0(void);
extern char lbl_8055D1D8[];
extern char lbl_8034D39C[];
extern char lbl_8034D3C0[];
extern unsigned char lbl_804FC800[];
extern unsigned char lbl_804FC558[];
extern int lbl_8055FF78;
extern int lbl_8055FFA0;
extern int *lbl_8055FF9C;
extern int fn_802E5AE8(void);
extern void fn_8012BEF0(unsigned char *);
extern void fn_8012C41C(void (*)(void), int, unsigned char *);
extern void fn_802E589C(void);
extern int fn_802E582C(void);
void fn_802E5248(int arg0, int arg1) {
    if (arg1 == 0) fn_80060CC0(arg0, 4, (void (*)())fn_802E51D0);
}

void fn_802E5264(int arg0, int arg1) {
    fn_802E30C8(lbl_8034D39C, arg0,
                 arg1 < 0 ? lbl_8034D3C0 : lbl_8055D1D8);
    lbl_804FC800[arg0 * 0x2C] = 0;
    if (arg1 >= 0) fn_80060CC0(arg0, 1, (void (*)())fn_802E5248);
}

int fn_802E540C(int arg0) {
    if (arg0 == 1) TRKReadBuffer_ui32();
    return 0;
}

void fn_802E589C(void) {
    fn_802E582C();
}

extern unsigned char lbl_804FC558[];
extern int lbl_8055FF78;
extern int lbl_8055FFA0;
extern int *lbl_8055FF9C;
extern int fn_802E5AE8(void);
extern void fn_8012BEF0(unsigned char *);
extern void fn_8012C41C(void (*)(void), int, unsigned char *);
extern int fn_802E582C(void);
int fn_802E58A0(void *arg0, int arg1) {
    if (arg1 == 0x53465830) return fn_802E582C();
    return 1;
}

void fn_802E58B8(unsigned char *arg0) {
    int index = lbl_8055FF78;
    unsigned char *dst;
    unsigned char *src;
    int count;
    lbl_8055FF78 = index + 1;
    dst = lbl_804FC558 + (index << 5);
    src = arg0;
    count = 0x20;
    do {
        unsigned char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0) break;
        count--;
    } while (count > 0);
    if (count == 0) dst[-1] = 0;
    fn_8012BEF0(arg0);
    fn_8012C41C(fn_802E589C, 0, arg0);
}

void fn_802E6240(void* arg0, int arg1) {
    *(int*)((char*)arg0 + 0x18) = arg1;
}

void fn_802E6248(int arg0, float arg1) {
    lbl_804FC680[arg0] = arg1;
}

void fn_802E625C(void* hi) {
    lbl_8055FF8C = hi;
}

int* fn_802E6ABC(void) {
    return &lbl_8055D1EC;
}

void fn_802E6AC4(void) {
    lbl_8055FFB5 = 1;
}

int fn_802E6AD0(int arg0) {
    if (arg0 == 1) {
        fn_802E7774(fn_802E6AC4);
    }
    return 0;
}

void fn_802E6B04(void) {
    fn_802E7770();
    {
        void *b = &lbl_8055D1F0;
        fn_802E2E0C(fn_802E6AD0, b);
    }
}

void fn_802E6B34(void) {
}

void fn_802E6B38(void* arg0, signed char* arg1) {
    *arg1 = 0;
}

