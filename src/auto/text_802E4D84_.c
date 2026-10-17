// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_8055FFB5;
extern void *lbl_8055FF8C;
extern float lbl_80565128;
extern float lbl_8056512C;
extern float lbl_80565130;
extern float lbl_80565134;
extern void fn_802E5264(int, int);
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
extern void fn_802E51D0();
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
extern char lbl_8055D1E4[];
extern char lbl_8034D490[];
extern char lbl_8034D4A0[];
extern char lbl_8034D5B0[];
extern void fn_802E317C(char *, int, void *, ...);
extern int lbl_8055FF98;
extern char lbl_8034D584[];
extern char lbl_8034D528[];
extern void fn_80128670(int);
extern void fn_8012C4D8(void);
extern void fn_8012BF24(void *);
void fn_802E4D84(void *dst, void *src, int size) {
    memcpy(dst, src, size);
    DCFlushRange(dst, size);
}

extern float lbl_80565130;
extern float lbl_80565134;
unsigned short fn_802E5168(float arg0) {
    float value = lbl_80565130 * arg0;
    int converted;
    int result;
    if (value < lbl_8056512C) {
        value = value - lbl_80565134;
    } else {
        value = lbl_80565134 + value;
    }
    converted = (int)value;
    result = converted & ((-converted & ~converted) >> 31);
    if (result < 0x8000) {
        return (unsigned short)result;
    }
    return 0x8000;
}

void fn_802E51D0(void) {
}

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

void fn_802E5824(void) {
}

void fn_802E5828(void) {
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
    while (count > 0) {
        count--;
    }
    if (count == 0) {
        *dst = 0;
    }
    while ((*src) != 0) {
        unsigned char c = *src++;
        *dst++ = c;
    }
    fn_8012BEF0(arg0);
    fn_8012C41C(fn_802E589C, 0, arg0);
}

void fn_802E5A54(void) {
    int i;
    unsigned char *ptr;
    for (i = 0; i < lbl_8055FFA0; i++) {
        fn_802E5D5C(lbl_8055FF9C[i]);
    }
    lbl_8055FFA0 = 0;
    for (i = 0, ptr = lbl_804FC558; i < lbl_8055FF78; i++, ptr += 0x20) {
        fn_8012BF24(ptr);
    }
    lbl_8055FF78 = 0;
}

float fn_802E6040(void *arg0) {
    if (arg0 != 0) return *(float *)((char *)arg0 + 0xA4);
    return lbl_8056512C;
}

void fn_802E6138(void *arg0) {
    if (((unsigned char *)arg0)[0x23] != 0) {
        fn_802E317C(lbl_8034D5B0, *(int *)arg0, *(void **)((char *)arg0 + 0x1C));
    }
    {
        void *temp_r4 = *(void **)((char *)arg0 + 0x1C);
        *(int *)((char *)temp_r4 + 0x98) -= 1;
    }
    ((unsigned char *)arg0)[0x20] = 0;
    lbl_8055FF98 -= 1;
}

void fn_802E61A8(void *arg0) {
    ((unsigned char *)arg0)[0x25] = 0;
    ((unsigned char *)arg0)[0x23] = 1;
}

void fn_802E61BC(void *arg0) {
    if (((unsigned char *)arg0)[0x23] == 0) {
        ((unsigned char *)arg0)[0x25] = 1;
        ((unsigned char *)arg0)[0x23] = 1;
    }
}

void fn_802E61D8(void *arg0) {
    ((unsigned char *)arg0)[0x23] = 0;
}

void fn_802E61E4(void *arg0, float farg0) {
    *(float *)((char *)arg0 + 8) = farg0;
}

void fn_802E61EC(void *arg0, float farg0) {
    if (lbl_8055FF8C != 0) {
        *(float *)((char *)arg0 + 0xC) = farg0;
        return;
    }
    *(float *)((char *)arg0 + 0xC) = lbl_8056512C;
}

void fn_802E620C(void *arg0, float farg0) {
    if ((int)lbl_8055FF8C == 2) {
        *(float *)((char *)arg0 + 0x14) = farg0;
        return;
    }
    *(float *)((char *)arg0 + 0x14) = lbl_80565128;
}

void fn_802E622C(void *arg0, float farg0) { *(float *)((char *)arg0 + 0x10) = farg0; }

void fn_802E6234(void) {}

void fn_802E6238(void) {}

void fn_802E623C(void) {}

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

void fn_802E6B44(int arg0, int arg1) { fn_802E5264(arg0, arg1); }

