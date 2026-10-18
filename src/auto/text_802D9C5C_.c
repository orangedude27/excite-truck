// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FE5C;
extern float lbl_80565038;
extern float lbl_8056503C;
extern int fn_802DA704(int, void *, int);
extern void fn_802DAA18(void);
#pragma scheduling off
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern char lbl_8034C8E8[];
void fn_802DA1F4(int arg0, unsigned int *arg1, int arg2) {
    extern int lbl_804DB458[];
    extern signed char lbl_8055FE58;
    unsigned int *dst;
    int count;
    int i;
    int n;

    if (arg2 <= 0)
        goto done;
    i = 0;
    n = arg2 - 8;
    if (n > 0 && arg2 <= 0x7FFFFFFE) {
        count = (n + 7) >> 3;
        dst = (unsigned int *)(&lbl_804DB458[arg0]);
        for (i = 0; i < count; i++) {
            dst[0] = arg1[0];
            dst[1] = arg1[1];
            dst[2] = arg1[2];
            dst[3] = arg1[3];
            dst[4] = arg1[4];
            dst[5] = arg1[5];
            dst[6] = arg1[6];
            dst[7] = arg1[7];
            dst += 8;
            arg1 += 8;
        }
    }
    count = (i << 3);
    dst = (unsigned int *)(&lbl_804DB458[arg0 + count]);
    count += 0;
    while (count < arg2) {
        *dst++ = *arg1++;
        count++;
    }
done:
    lbl_8055FE58 = 1;
}

void *fn_802DA450(void *arg0,int arg1) {
 if(arg0) { *(void**)arg0=(void*)((char*)&lbl_8034C8E8+0x10000); fn_80128670(*(int*)((char*)arg0+4)); if(arg0) *(int*)((char*)arg0+4)=0; if(arg1>0) fn_80128668(arg0); }
 return arg0;
}

void fn_802DA4C4(void) {
    void *p = lbl_8055FE5C;
    if (p != 0) {
        if (p != 0) {
            *(volatile void **)p = (void *)((char *)&lbl_8034C8E8 + 0x10000);
            fn_80128670(*(int *)((char *)p + 4));
            if (p != 0)
                *(int *)((char *)p + 4) = 0;
        }
        fn_80128668(p);
    }
    lbl_8055FE5C = 0;
}

void fn_802DA52C(void) {
    volatile unsigned char *p = (volatile unsigned char *)lbl_8055FE5C;
    *(volatile int *)(p + 0x10) = 0;
    *(volatile int *)(p + 0x20) = -1;
    p[0x24] = 1;
    p[0x25] = 0;
}

extern float lbl_80565030;
extern void fn_802E317C(char *, ...);
extern int memcpy(void *, const void *, unsigned int);
extern char lbl_80346798[];
void *fn_802DA918(float arg0, float arg1, float arg2) {
    float c, a, b;
    unsigned char saved;
    unsigned char *p;
    void *result;
    c = lbl_80565030 / (arg2 * arg2);
    a = arg0;
    b = arg1;
    p = (unsigned char *)lbl_8055FE5C;
    saved = p[0x25];
    p[0x25] = 0;
    if (*(int *)(p + 0x10) + 0x2c > *(int *)(p + 0xc)) {
        fn_802E317C((char *)0, *(int *)(p + 8), 0x24, *(int *)(p + 0xc) >> 10);
        result = 0;
    } else {
        int *base = (int *)(*(int *)(p + 4) + *(int *)(p + 0x10));
        *base = 1;
        result = base + 1;
        *(int *)((char *)base + 0x28) = 0x24;
        *(int *)(p + 0x10) += 0x2c;
    }
    *(int *)((char *)result + 0) = 7;
    *(int *)((char *)result + 4) = 1;
    *(int *)((char *)result + 8) = 1;
    *(int *)((char *)result + 0xc) = 0;
    *(int *)((char *)result + 0x14) = 0;
    *((unsigned char *)result + 0x10) = saved;
    memcpy((char *)result + 0x18, &a, 0xc);
    return result;
}

#pragma scheduling on
void fn_802DABA4(float *arg0) {
    float sp8, spC, sp10, sp14, sp18, sp1C, sp20, sp24, sp28, sp2C, sp30, sp34;
    float f6 = arg0[0];
    float f4 = arg0[1];
    float f3 = arg0[2];
    float f12 = lbl_80565038;
    float f9 = lbl_8056503C;
    float f2 = arg0[3];
    float f1 = arg0[4];
    float f0 = arg0[5];
    sp8 = f6 * f12;
    spC = f4 * f12;
    sp10 = f3 * f12;
    sp14 = f6 * f9;
    sp18 = f4 * f9;
    sp1C = f3 * f9;
    sp20 = f2 * f12;
    sp24 = f1 * f12;
    sp28 = f0 * f12;
    sp2C = f2 * f9;
    sp30 = f1 * f9;
    sp34 = f0 * f9;
    fn_802DA704(0x4C, &sp8, 4);
    fn_802DAA18();
}

void fn_802DAC54(void) {
    *((unsigned char *)lbl_8055FE5C + 0x25) = 1;
}

unsigned char fn_802DAC64(void) {
    return *((unsigned char *)lbl_8055FE5C + 0x24);
}
