// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80137D58(void *arg0, int arg_sp0) {
    volatile int sp18, sp14, sp10, spC, sp8;
    volatile unsigned char *p = (volatile unsigned char *)arg0;
    register unsigned char temp_r0 asm("r0"), temp_r0_2 asm("r0"), temp_r0_4 asm("r0"), temp_r0_5 asm("r0"); register unsigned int temp_r0_3 asm("r0");
    register unsigned char temp_r12 asm("r12"), temp_r11 asm("r11"), temp_r10 asm("r10"), temp_r9 asm("r9"), temp_r8 asm("r8"), temp_r7 asm("r7"), temp_r6 asm("r6"), temp_r5 asm("r5"), temp_r4 asm("r4");
    register unsigned char temp_r31 asm("r31"), temp_r30 asm("r30"), temp_r29 asm("r29"), temp_r28 asm("r28"), temp_r27 asm("r27"), temp_r26 asm("r26"), temp_r25 asm("r25"), temp_r24 asm("r24"), temp_r23 asm("r23"), temp_r22 asm("r22"), temp_r21 asm("r21"), temp_r20 asm("r20"), temp_r19 asm("r19"), temp_r18 asm("r18"), temp_r17 asm("r17"), temp_r16 asm("r16"), temp_r15 asm("r15"), temp_r14 asm("r14");
    temp_r4=p[0]; p[0]=p[3]; p[3]=temp_r4;
    temp_r4=p[1]; p[1]=p[2]; p[2]=temp_r4;
    temp_r4=p[4]; p[4]=p[7]; p[7]=temp_r4;
    temp_r4=p[5]; p[5]=p[6]; p[6]=temp_r4;
    temp_r4=p[8]; p[8]=p[11]; p[11]=temp_r4;
    temp_r4=p[9]; p[9]=p[10]; p[10]=temp_r4;
    temp_r4=p[12]; p[12]=p[15]; p[15]=temp_r4;
    temp_r4=p[13]; p[13]=p[14]; p[14]=temp_r4;
    temp_r0=p[0x2a]; temp_r17=p[0x29]; sp18=temp_r0;
    temp_r0_2=p[0x2f]; temp_r24=p[0x2c]; sp8=temp_r0_2;
    temp_r0_3=p[0x2e]; temp_r16=p[0x2d]; spC=temp_r0_3;
    temp_r0_4=p[0x33]; temp_r23=p[0x30]; sp10=temp_r0_4;
    temp_r0_5=p[0x32]; temp_r15=p[0x31]; sp14=temp_r0_5;
    temp_r0=sp18;
    temp_r30=p[0x10]; temp_r31=p[0x13]; p[0x29]=temp_r0;
    temp_r0_2=sp8;
    temp_r22=p[0x11]; temp_r12=p[0x12]; p[0x2c]=temp_r0_2;
    temp_r0_3=spC;
    temp_r29=p[0x18]; temp_r11=p[0x1b]; p[0x2d]=temp_r0_3;
    temp_r0_4=sp10;
    temp_r21=p[0x19]; temp_r10=p[0x1a]; p[0x30]=temp_r0_4;
    temp_r0_5=sp14;
    temp_r28=p[0x1c]; temp_r9=p[0x1f]; temp_r20=p[0x1d]; temp_r8=p[0x1e];
    temp_r27=p[0x20]; temp_r7=p[0x23]; temp_r19=p[0x21]; temp_r6=p[0x22];
    temp_r26=p[0x24]; temp_r5=p[0x27]; temp_r18=p[0x25]; temp_r4=p[0x26];
    temp_r25=p[0x28]; temp_r14=p[0x2b];
    p[0x10]=temp_r31; p[0x13]=temp_r30;
    p[0x11]=temp_r12; p[0x12]=temp_r22;
    p[0x18]=temp_r11; p[0x1b]=temp_r29;
    p[0x19]=temp_r10; p[0x1a]=temp_r21;
    p[0x1c]=temp_r9; p[0x1f]=temp_r28;
    p[0x1d]=temp_r8; p[0x1e]=temp_r20;
    p[0x20]=temp_r7; p[0x23]=temp_r27;
    p[0x21]=temp_r6; p[0x22]=temp_r19;
    p[0x24]=temp_r5; p[0x27]=temp_r26;
    p[0x25]=temp_r4; p[0x26]=temp_r18;
    p[0x28]=temp_r14; p[0x2b]=temp_r25;
    p[0x2a]=temp_r17; p[0x2f]=temp_r24;
    p[0x2e]=temp_r16; p[0x33]=temp_r23;
    p[0x31]=temp_r0_5; p[0x32]=temp_r15;
}
#pragma cplusplus reset
#pragma scheduling on
#pragma use_lmw_stmw on
static inline void Swap32_801381B4(unsigned char *p) {
    unsigned char a = p[0];
    unsigned char b = p[1];
    p[0] = p[3];
    p[3] = a;
    p[1] = p[2];
    p[2] = b;
}
void fn_80137F2C(void) {

}

#pragma dont_inline on
void fn_80137F30(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char a;
    unsigned char c;
    unsigned char b;
    unsigned char d;
    a = base[8];
    b = base[9];
    c = base[0xc];
    d = base[0xd];
    base[8] = base[0xb];
    base[0xb] = a;
    base[9] = base[0xa];
    base[0xa] = b;
    base[0xc] = base[0xf];
    base[0xf] = c;
    base[0xd] = base[0xe];
    base[0xe] = d;
}
#pragma dont_inline reset

void fn_80137F74(void *arg0) {
    unsigned char a0;
    unsigned char a4;
    unsigned char a8;
    unsigned char a1;
    unsigned char a5;
    unsigned char a9;
    a0 = ((unsigned char *)arg0)[0];
    a1 = ((unsigned char *)arg0)[1];
    a4 = ((unsigned char *)arg0)[4];
    a5 = ((unsigned char *)arg0)[5];
    a8 = ((unsigned char *)arg0)[8];
    a9 = ((unsigned char *)arg0)[9];
    ((unsigned char *)arg0)[0] = ((unsigned char *)arg0)[3];
    ((unsigned char *)arg0)[3] = a0;
    ((unsigned char *)arg0)[1] = ((unsigned char *)arg0)[2];
    ((unsigned char *)arg0)[2] = a1;
    ((unsigned char *)arg0)[4] = ((unsigned char *)arg0)[7];
    ((unsigned char *)arg0)[7] = a4;
    ((unsigned char *)arg0)[5] = ((unsigned char *)arg0)[6];
    ((unsigned char *)arg0)[6] = a5;
    ((unsigned char *)arg0)[8] = ((unsigned char *)arg0)[0xb];
    ((unsigned char *)arg0)[0xb] = a8;
    ((unsigned char *)arg0)[9] = ((unsigned char *)arg0)[0xa];
    ((unsigned char *)arg0)[0xa] = a9;
}

void fn_80137FF0(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char a, c, e;
    unsigned char *p;
    unsigned char b, d, f;
    unsigned char x, y;
    int i;

    p = base + 0x14;
    i = 0;
    a = base[8];
    b = base[9];
    c = base[0xc];
    d = base[0xd];
    e = base[0x10];
    f = base[0x11];
    base[8] = base[0xb];
    base[0xb] = a;
    base[9] = base[0xa];
    base[0xa] = b;
    base[0xc] = base[0xf];
    base[0xf] = c;
    base[0xd] = base[0xe];
    base[0xe] = d;
    base[0x10] = base[0x13];
    base[0x13] = e;
    base[0x11] = base[0x12];
    base[0x12] = f;
    if (i == 0)
        goto loop;
loop:
    y = p[0];
    i++;
    x = p[1];
    p[0] = x;
    p[1] = y;
    x = p[2];
    y = p[3];
    p[2] = y;
    p[3] = x;
    y = p[4];
    x = p[7];
    p[4] = x;
    p[7] = y;
    y = p[5];
    x = p[6];
    p[5] = x;
    p[6] = y;
    p += 8;
    if (i < *(int *)(base + 8))
        goto loop;
}

void fn_801380DC(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char a = base[8];
    unsigned char *p = base + 12;
    unsigned char b = base[9];
    int i;
    unsigned char c;
    base[8] = base[11];
    base[11] = a;
    base[9] = base[10];
    base[10] = b;
    for (i = 0; i < *(int *)(base + 8) * *(int *)(base + 8); i++) {
        a = p[0];
        c = p[3];
        p[0] = c;
        p[3] = a;
        a = p[1];
        c = p[2];
        p[1] = c;
        p[2] = a;
        p += 4;
    }
}

void fn_80137F30(void *);
void fn_80137F74(void *);
void fn_80137FF0(void *);
void fn_801380DC(void *);
extern char lbl_8032BF00[];
void fn_802E317C(char *, ...);
#pragma dont_inline fn_80137F30
#pragma dont_inline fn_80137F74
#pragma dont_inline fn_80137FF0
#pragma dont_inline fn_801380DC
void fn_80138144(void *arg0) {
    unsigned char a = *((unsigned char *)arg0);
    unsigned char b = *((unsigned char *)arg0 + 1);
    *((unsigned char *)arg0) = *((unsigned char *)arg0 + 3);
    *((unsigned char *)arg0 + 3) = a;
    *((unsigned char *)arg0 + 1) = *((unsigned char *)arg0 + 2);
    *((unsigned char *)arg0 + 2) = b;
    {
        int mode = *(int *)arg0;
        switch (mode) {
        case 0: ((void (*)(void *, int))fn_80137F30)(arg0, mode); break;
        case 1: ((void (*)(void *, int))fn_80137F74)((char *)arg0 + 8, mode); break;
        case 2: ((void (*)(void *, int))fn_80137FF0)(arg0, mode); break;
        case 3: ((void (*)(void *, int))fn_801380DC)(arg0, mode); break;
        default: fn_802E317C(lbl_8032BF00); break;
        }
    }
}

extern void fn_80138434();
void fn_801381B4(void *arg0) {
    volatile unsigned char *v = (volatile unsigned char *)arg0;
    unsigned char *base = (unsigned char *)arg0;
    unsigned char *p = base + 0x30;
    unsigned char *r;
    unsigned char *node;
    unsigned char t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
    int i, mode, found;
    t0 = v[0]; t3 = v[3]; t1 = v[1]; t2 = v[2]; t4 = v[4]; t7 = v[7]; t5 = v[5]; t6 = v[6];
    v[0] = t3; v[3] = t0; v[1] = t2; v[2] = t1; v[4] = t7; v[7] = t4; v[5] = t6; v[6] = t5;
    t0 = v[8]; t1 = v[0xb]; v[8] = t1; v[0xb] = t0;
    t0 = v[9]; t1 = v[0xa]; v[9] = t1; v[0xa] = t0;
    t0 = v[0xc]; t1 = v[0xf]; v[0xc] = t1; v[0xf] = t0;
    t0 = v[0xd]; t1 = v[0xe]; v[0xd] = t1; v[0xe] = t0;
    t0 = v[0x10]; t1 = v[0x13]; v[0x10] = t1; v[0x13] = t0;
    t0 = v[0x11]; t1 = v[0x12]; v[0x11] = t1; v[0x12] = t0;
    t0 = v[0x14]; t1 = v[0x17]; t2 = v[0x15]; t3 = v[0x16];
    t4 = v[0x18]; t5 = v[0x1b]; t6 = v[0x19]; t7 = v[0x1a];
    t8 = v[0x2c]; t9 = v[0x2f]; t10 = v[0x2d]; t11 = v[0x2e];
    v[0x14] = t1; v[0x17] = t0; v[0x15] = t3; v[0x16] = t2;
    v[0x18] = t5; v[0x1b] = t4; v[0x19] = t7; v[0x1a] = t6;
    v[0x2c] = t9; v[0x2f] = t8; v[0x2d] = t11; v[0x2e] = t10;
    i = 0;
    while (i < *(int *)(base + 0x2c)) {
        t0 = p[0]; t1 = p[3]; p[0] = t1; p[3] = t0;
        t0 = p[1]; t1 = p[2]; p[1] = t1; p[2] = t0;
        p += 4;
        i++;
    }
    r = base;
    for (i = 0; i < *(int *)(base + 0x2c); i++) {
        unsigned char *t = base + *(int *)(r + 0x30);
        r += 4;
        t0 = t[0]; t1 = t[3]; t[0] = t1; t[3] = t0;
        t0 = t[1]; t1 = t[2]; t[1] = t1; t[2] = t0;
        *(int *)t = *(int *)t + (int)base;
    }
    fn_80138434(base + 0x1C);
    fn_80138434(base + 0x20);
    fn_80137D58(*(void **)(base + 0x1C), (int)base);
    mode = 0;
    do {
        found = 0;
        node = *(unsigned char **)(*(unsigned char **)(base + 0x1C) + 0x14);
        while (node != *(unsigned char **)(base + 0x1C)) {
            if (node[0x34] == mode) {
                found = 1;
                fn_80137D58(node, (int)base);
            } else if (found != 0) {
                break;
            }
            node = *(unsigned char **)(node + 0x14);
        }
        mode++;
    } while (mode < 3);
    node = *(unsigned char **)(base + 0x20);
    if (node != 0) {
        do {
            fn_80137D58(node, (int)base);
            node = *(unsigned char **)(node + 0x14);
        } while (node[0x34] == 3);
    }
    node = *(unsigned char **)(base + 0x24);
    while (node != 0) {
        fn_80138144(node);
        node = *(unsigned char **)(node + 4);
    }
}

#pragma dont_inline on
void fn_80138434(void) {
    fn_80137F2C();
}
#pragma dont_inline reset
void *fn_80138438(void *arg0) { void *node; void *best; node=*(void **)((char *)arg0+0x14); best=arg0; while(node!=arg0) { if(*(unsigned int *)((char *)node+0x10)>*(unsigned int *)((char *)best+0x10)) best=node; node=*(void **)((char *)node+0x14); } return best; }

void *fn_8013846C(void *arg0) {
    void *node;
    void *best;

    node = *(void **)((char *)arg0 + 0x14);
    best = arg0;
    while (node != arg0) {
        if (*(unsigned int *)((char *)node + 0x10) < *(unsigned int *)((char *)best + 0x10)) {
            best = node;
        }
        node = *(void **)((char *)node + 0x14);
    }
    return best;
}

void fn_80128670(void *);
void fn_8013530C(void *, int);
void fn_80135DC4(void *, int, int);
void fn_80135F64(void *, void *, void *, int, int);
void fn_80136068(void *, void *, int);
void *fn_80138438(void *);
void *fn_8013846C(void *);
#pragma scheduling invalid_target
#pragma dont_inline on
void fn_801384A0(void *arg0, int arg1) {
    char sp[0x70];
    int value;
    int max;
    void *node;
    void *head;
    fn_80135DC4(sp, 1, arg1);
    head = *(void **)((char *)arg0 + 0x1C);
    fn_80135F64(sp, head, (char *)head + 8, 0, 0);
    node = *(void **)((char *)arg0 + 0x1C);
    do {
        fn_80136068(sp, node, 0);
        *(float *)((char *)node + 0x2C) = *(float *)(sp + 0x40);
        *(int *)((char *)node + 0x10) = *(int *)((char *)*(void **)(sp + 4) + 0x10);
        node = *(void **)((char *)node + 0x14);
    } while (node != *(void **)((char *)arg0 + 0x1C));
    node = fn_80138438(node);
    head = fn_8013846C(node);
    *(int *)((char *)head + 0x10) = 0;
    node = head;
    max = 0;
    do {
        value = *(int *)((char *)node + 0x10);
        if (max > value) {
            value = max;
            *(int *)((char *)node + 0x10) = value;
        }
        max = value;
        node = *(void **)((char *)node + 0x14);
    } while (node != head);
    if (*(void **)(sp + 0x50) != 0) fn_80128670(*(void **)(sp + 0x50));
    *(void **)(sp + 0x50) = 0;
    fn_8013530C(sp, 0);
}
#pragma dont_inline reset
#pragma scheduling on
void fn_801384A0();
int fn_801386D0(void *, float, float, float);
void fn_80138958(void *, float *);
#pragma dont_inline fn_80138594
void fn_80138594(void *arg0) {
    void *node;

    node = *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(unsigned int *)node == 1) {
            fn_80138958(arg0, (float *)((char *)node + 8));
        }
        node = *(void **)((char *)node + 4);
    }
}

extern float lbl_80561398, lbl_8056139C, lbl_805613A0, lbl_805613A4, lbl_805613A8, lbl_805613AC;
extern float __fabsf(float);
extern double __fabs(double);
float fn_801385F0(float arg0, float arg1, float arg2, float arg3) {
    float diff = arg0 - arg2;
    float value;
    if ((float)__fabs((double)diff) > arg1 * lbl_80561398) {
        float adjust = diff > lbl_805613A4 ? lbl_8056139C : lbl_805613A0;
        diff -= arg1 * adjust;
    }
    arg1 = lbl_8056139C;
    value = arg1 - (float)__fabs((double)diff) / arg3;
    arg1 = (arg1 < value) ? arg1 : value;
    arg1 = (arg1 > lbl_805613A4) ? arg1 : lbl_805613A4;
    if (arg1 < lbl_805613A0) return lbl_805613A0;
    if (arg1 > lbl_8056139C) return lbl_8056139C;
    if (arg1 > lbl_805613A4) {
        return arg1 * (lbl_805613A8 * arg1 * arg1) + (lbl_805613AC * arg1 * arg1);
    }
    return arg1 * (lbl_805613A8 * arg1 * arg1) - (lbl_805613AC * arg1 * arg1);
}

extern float lbl_805613B0, lbl_805613B4;
extern double fn_8002F234(double);
int fn_801386D0(void *arg0, float farg0, float farg1, float farg2) {
    char *ctx = (char *)arg0;
    char *a, *b, *n;
    float step, d, f24, f25, one, half, zero, big, minLen, len, inv;
    float tmp[2];
    float p[2];
    int hit = 0;
    f25 = lbl_805613A4;
    half = lbl_80561398;
    zero = f25;
    minLen = lbl_805613B4;
    one = lbl_8056139C;
    big = lbl_805613B0;
    do {
        step = farg0 - f25;
        if (step < big) {
        } else {
            step = big;
        }
        a = *(char **)(ctx + 0x1C);
        f24 = *(float *)(ctx + 8);
        n = *(char **)(a + 0x14);
        do {
            float v = fn_801385F0(*(float *)(n + 0x1C), f24, farg1, farg2);
            if (v > zero) {
                float k = v * step;
                float y1 = *(float *)(a + 0xC);
                float x1 = *(float *)(a + 8);
                *(float *)(n + 0x2C) = *(float *)(n + 0x2C) + k;
                p[1] = y1 + half * (*(float *)(n + 0xC) - y1);
                p[0] = x1 + half * (*(float *)(n + 8) - x1);
                tmp[0] = p[0];
                tmp[1] = -p[1];
                *(float *)n = *(float *)n + p[1] * k;
                *(float *)(n + 4) = *(float *)(n + 4) + tmp[1] * k;
            }
            b = *(char **)(ctx + 0x1C);
            a = n;
            n = *(char **)(n + 0x14);
        } while (a != b);
        f24 = lbl_805613A4;
        do {
            char *nx = *(char **)(b + 0x14);
            *(float *)(b + 8) = *(float *)nx - *(float *)b;
            d = *(float *)(nx + 4) - *(float *)(b + 4);
            *(float *)(b + 0xC) = d;
            len = fn_8002F234(*(float *)(b + 8) * *(float *)(b + 8) + d * d);
            if (minLen > len)
                len = minLen;
            inv = one / len;
            *(float *)(b + 8) = *(float *)(b + 8) * inv;
            *(float *)(b + 0xC) = *(float *)(b + 0xC) * inv;
            *(float *)(b + 0x1C) = f24;
            nx = *(char **)(b + 0x14);
            p[1] = *(float *)(b + 4) - *(float *)(nx + 4);
            p[0] = *(float *)b - *(float *)nx;
            *(float *)(b + 0x18) = fn_8002F234(p[0] * p[0] + p[1] * p[1]);
            if (*(float *)(b + 0x18) < half)
                hit = 1;
            len = *(float *)(b + 0x18);
            b = *(char **)(b + 0x14);
            f24 += len;
        } while (b != *(char **)(ctx + 0x1C) && hit == 0);
        f25 += step;
    } while (f25 < farg0 && hit == 0);
    return hit == 0;
}

extern float lbl_805613A4;
int fn_801388F4(void *arg0) {
    void *p;
    volatile float sp8, spC;
    double neg;
    float rounded, product0, product1, value;
    p = *(void **)((char *)arg0 + 0x14);
    sp8 = *(float *)((char *)arg0 + 8);
    spC = *(float *)((char *)arg0 + 0xC);
    neg = -(double)sp8;
    rounded = (float)neg;
    product0 = spC * *(float *)((char *)p + 8);
    sp8 = spC;
    spC = (float)neg;
    product1 = rounded * *(float *)((char *)p + 0xC);
    value = product0 + product1;
    if (value >= lbl_805613A4) goto done;
    return 1;
done:
    return 0;
}

void fn_80138958(void *arg0, float *arg1) { fn_801386D0(arg0, arg1[0], arg1[1], arg1[2]); }

extern void *fn_8012C370(int, int, unsigned int *, int *, void **, unsigned char *);
extern void fn_8012C4D8(void *);
extern void fn_801381B4(void *);
extern void fn_80138594(void *);
extern int fn_8013BFE8(int);
extern void fn_802E30C8(char *, ...);
extern char lbl_8032BF20[];
extern char lbl_8032BF70[];
#pragma dont_inline on
void *fn_80138968(int arg0) {
    struct {
        void *data;
        union {
            struct {
                unsigned char padding[8];
                int valid;
                unsigned int size;
            } output;
            struct {
                unsigned int b;
                unsigned int a;
            } words;
        } scratch;
    } local;
    void *obj;
    int ok;
    obj = fn_8012C370(arg0, 0x494C494E, &local.scratch.output.size,
                      &local.scratch.output.valid, &local.data,
                      ((unsigned char *)&local.data) + 1);
    if (obj != 0) {
        ok = 0;
        if (local.scratch.output.valid != 0) {
            if (local.scratch.output.size == 0x1E) {
                unsigned int *words = (unsigned int *)obj;
                unsigned char swap = ((unsigned char *)&local.data)[1];
                unsigned int a = words[1];
                unsigned int b = words[0];
                local.scratch.words.a = a;
                local.scratch.words.b = b;
                if (swap) {
                    unsigned char *p = (unsigned char *)&local.scratch.words.a;
                    unsigned char *q = (unsigned char *)&local.scratch.words.b;
                    unsigned char t;
                    t = p[0]; p[0] = p[3]; p[3] = t;
                    t = p[1]; p[1] = p[2]; p[2] = t;
                    t = q[0]; q[0] = q[3]; q[3] = t;
                    t = q[1]; q[1] = q[2]; q[2] = t;
                }
                if (local.scratch.words.a == 0x3C && local.scratch.words.b == 0x30) {
                    if (((unsigned char *)&local.data)[1]) {
                        fn_801381B4(obj);
                        fn_80138594(obj);
                    }
                    *(int *)((char *)obj + 0x28) = fn_8013BFE8(arg0);
                    ok = 1;
                } else {
                    fn_802E30C8(lbl_8032BF20, local.scratch.words.a, 0x3C,
                                local.scratch.words.b, 0x30,
                                ((unsigned char *)&local.data)[1]);
                }
            } else {
                fn_802E30C8(lbl_8032BF70, local.scratch.output.size, 0x1E);
            }
        }
        if (!ok) {
            fn_8012C4D8(obj);
            obj = 0;
        }
    }
    return obj;
}
#pragma dont_inline reset

void fn_80138AD8(void **arg0) { void *p=*arg0; fn_8013C428(*(int*)((char*)p+0x28),p); fn_8012C4D8(*arg0); *arg0=0; }

void *fn_80138B1C(void *arg0) { void *p=*(void **)((char*)arg0+0x24); void *result=0; while(p){ if(*(int*)p==0){result=p;break;} p=*(void **)((char*)p+4); } return result; }

void *fn_80138B4C(void *arg0, void *arg1) {
    void *result;
    void *node;
    node = arg1 != 0 ? *(void **)((char *)arg1 + 4) : 0;
    result = 0;
    node = node != 0 ? node : *(void **)((char *)arg0 + 0x24);
    while (node != 0) {
        if (*(unsigned int *)node == 2) {
            result = node;
            break;
        }
        node = *(void **)((char *)node + 4);
    }
    return result;
}

void fn_80138BA0(void *arg0, void *arg1) {
    if (arg0 != arg1) {
        fn_801384A0();
    }
}

