// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern char lbl_80340394[];
extern char lbl_803403CC[];
extern char lbl_80340408[];
int fn_80230020(void);
void fn_8022F824(void *);
void fn_802E30C8(void *);
extern void *lbl_8055F014;
extern float lbl_805635FC;
extern float lbl_8056360C;
void fn_8022FB6C(void);
float fn_80214D48(void);
void fn_8022FD9C(void *, float);
void fn_80015EB0(float);
void fn_80015E30(void *, float);
void fn_80015B20(void *, void *, void *);
void fn_80015AA0(void *, float);
char *stricmp(const char *, const char *);
void fn_802E317C();
extern char lbl_80340350[];
extern char lbl_80497E3C[];
extern char lbl_8055B988;
#pragma scheduling invalid_target
void fn_8022F248(void) {
    if (lbl_8055F014 != 0) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80340350);
    }
    strcpy(lbl_80497E3C + 0x3c, &lbl_8055B988);
}

void fn_8022F294(void) {
    void *var_r0;
    void *var_r31;
    if (fn_80230020() != 0) {
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_80340394);
        var_r0 = lbl_8055F014;
        var_r31 = var_r0;
        while (var_r0 != 0) {
            fn_8022F824(*(void **)var_r31);
            var_r31 = *(void **)((char *)var_r31 + 8);
            var_r0 = 0;
            lbl_8055F014 = var_r31;
        }
    }
}

#pragma scheduling on

void *fn_8022F2FC(char *arg0) {
    void *node = lbl_8055F014;
    while (node != 0) {
        if (stricmp((char *)*(void **)node + 0x3c, arg0) == 0) return node;
        node = *(void **)((char *)node + 8);
    }
    return 0;
}

extern char lbl_80340394[];
extern char lbl_803403CC[];
extern char lbl_80340408[];
int fn_80230020(void);
void fn_8022F824(void *);
void fn_802E30C8(void *);

void *fn_801284F8(int, const char *);
void fn_80128668(void *);
int fn_8022EDC4(void);
void fn_801BFD34(void *, void *, int);
void fn_8022F364(void *arg0) {
    void *node;
    if (arg0 == 0) return;
    node = lbl_8055F014;
    if (node == 0) {
        node = fn_801284F8(0xc, lbl_803403CC);
        lbl_8055F014 = node;
        *(void **)node = arg0;
        *(int *)((char *)node + 4) = 1;
        *(void **)((char *)node + 8) = 0;
    } else {
        while (*(void **)((char *)node + 8) != 0) node = *(void **)((char *)node + 8);
        *(void **)((char *)node + 8) = fn_801284F8(0xc, lbl_803403CC);
        node = *(void **)((char *)node + 8);
        *(void **)node = arg0;
        *(int *)((char *)node + 4) = 1;
        *(void **)((char *)node + 8) = 0;
    }
}

void fn_8022F418(arg0)
void *arg0;
{
    struct Pair { unsigned int a; unsigned int b; };
    struct Pair *from = (struct Pair *)arg0;
    struct Pair *to = (struct Pair *)lbl_80497E3C;
    unsigned int *words = (unsigned int *)arg0;
    float value;
    unsigned char byte;

    to[0] = from[0];
    to[1] = from[1];
    to[2] = from[2];
    to[3] = from[3];
    to[4].a = words[8];
    *(struct Pair *)((char *)to + 0x24) = *(struct Pair *)((char *)from + 0x24);
    to[5].b = words[11];
    to[6].a = (unsigned int)-1;
    to[6].b = words[13];
    to[7].a = words[14];
    strcpy((char *)lbl_80497E3C + 0x3c, (char *)arg0 + 0x3c);
    value = *(float *)((char *)arg0 + 0x7c);
    *(float *)((char *)lbl_80497E3C + 0x7c) = value;
    *(unsigned int *)((char *)lbl_80497E3C + 0x80) = *(unsigned int *)((char *)arg0 + 0x80);
    *(unsigned int *)((char *)lbl_80497E3C + 0x84) = *(unsigned int *)((char *)arg0 + 0x84);
    *(unsigned int *)((char *)lbl_80497E3C + 0x88) = *(unsigned int *)((char *)arg0 + 0x88);
    value = *(float *)((char *)arg0 + 0x8c);
    *(float *)((char *)lbl_80497E3C + 0x8c) = value;
    value = *(float *)((char *)arg0 + 0x90);
    *(float *)((char *)lbl_80497E3C + 0x90) = value;
    value = *(float *)((char *)arg0 + 0x94);
    *(float *)((char *)lbl_80497E3C + 0x94) = value;
    value = *(float *)((char *)arg0 + 0x98);
    *(float *)((char *)lbl_80497E3C + 0x98) = value;
    byte = *((unsigned char *)arg0 + 0x9c);
    *((unsigned char *)lbl_80497E3C + 0x9c) = byte;
    byte = *((unsigned char *)arg0 + 0x9d);
    *((unsigned char *)lbl_80497E3C + 0x9d) = byte;
    value = *(float *)((char *)arg0 + 0xa0);
    *(float *)((char *)lbl_80497E3C + 0xa0) = value;
    value = *(float *)((char *)arg0 + 0xa4);
    *(float *)((char *)lbl_80497E3C + 0xa4) = value;
    value = *(float *)((char *)arg0 + 0xa8);
    *(float *)((char *)lbl_80497E3C + 0xa8) = value;
    value = *(float *)((char *)arg0 + 0xac);
    *(float *)((char *)lbl_80497E3C + 0xac) = value;
    value = *(float *)((char *)arg0 + 0xb0);
    *(float *)((char *)lbl_80497E3C + 0xb0) = value;
}

void fn_8022F548(void *arg0) {
    struct Pair { unsigned int a; unsigned int b; };
    unsigned int *src = (unsigned int *)lbl_80497E3C;
    struct Pair *dst = (struct Pair *)arg0;
    struct Pair *from = (struct Pair *)src;
    float fvalue;
    unsigned char byte;

    dst[0] = from[0];
    dst[1] = from[1];
    dst[2] = from[2];
    dst[3] = from[3];
    *(unsigned int *)((char *)arg0 + 0x20) = src[8];
    *(struct Pair *)((char *)arg0 + 0x24) = *(struct Pair *)((char *)src + 0x24);
    *(unsigned int *)((char *)arg0 + 0x2C) = src[11];
    *(unsigned int *)((char *)arg0 + 0x34) = src[13];
    *(unsigned int *)((char *)arg0 + 0x38) = src[14];
    fvalue = *(float *)((char *)src + 0x7C);
    *(float *)((char *)arg0 + 0x7C) = fvalue;
    *(unsigned int *)((char *)arg0 + 0x80) = *(unsigned int *)((char *)src + 0x80);
    *(unsigned int *)((char *)arg0 + 0x84) = *(unsigned int *)((char *)src + 0x84);
    *(unsigned int *)((char *)arg0 + 0x88) = *(unsigned int *)((char *)src + 0x88);
    fvalue = *(float *)((char *)src + 0x8C);
    *(float *)((char *)arg0 + 0x8C) = fvalue;
    fvalue = *(float *)((char *)src + 0x90);
    *(float *)((char *)arg0 + 0x90) = fvalue;
    fvalue = *(float *)((char *)src + 0x94);
    *(float *)((char *)arg0 + 0x94) = fvalue;
    fvalue = *(float *)((char *)src + 0x98);
    *(float *)((char *)arg0 + 0x98) = fvalue;
    byte = *((unsigned char *)src + 0x9C);
    *((unsigned char *)arg0 + 0x9C) = byte;
    byte = *((unsigned char *)src + 0x9D);
    *((unsigned char *)arg0 + 0x9D) = byte;
    fvalue = *(float *)((char *)src + 0xA0);
    *(float *)((char *)arg0 + 0xA0) = fvalue;
    fvalue = *(float *)((char *)src + 0xA4);
    *(float *)((char *)arg0 + 0xA4) = fvalue;
    fvalue = *(float *)((char *)src + 0xA8);
    *(float *)((char *)arg0 + 0xA8) = fvalue;
    fvalue = *(float *)((char *)src + 0xAC);
    *(float *)((char *)arg0 + 0xAC) = fvalue;
    fvalue = *(float *)((char *)src + 0xB0);
    *(float *)((char *)arg0 + 0xB0) = fvalue;
}

extern char lbl_803403DC[];
extern char lbl_8055B98C;
extern float lbl_805635E8, lbl_805635EC, lbl_805635F0, lbl_805635F4, lbl_805635F8;
extern int fn_8012C33C(void *);
extern int fn_802CAC28(void *, int);
void fn_8022FF90(void *);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma dont_inline fn_8022F2FC
void *fn_8022F638(char *arg0, unsigned char arg1, unsigned char arg2, int arg3, float farg0) {
    void *node;
    float e8, ec, f0, f4, f8;

    if (arg0 == 0) return 0;
    ((void *(*)(void))fn_8022F2FC)();
    node = fn_801284F8(0xb4, &lbl_8055B98C);
    if (fn_8012C33C(arg0) != 0) {
        *(int *)((char *)node + 0x30) = fn_802CAC28(arg0, 0);
        *(int *)((char *)node + 0x80) = arg3;
    } else {
        *(int *)((char *)node + 0x30) = -1;
        ((void (*)(const char *, ...))fn_802E30C8)(lbl_803403DC, arg0);
        *(int *)((char *)node + 0x80) = 0;
    }
    strcpy((char *)node + 0x3c, arg0);
    if (strcmp(arg0, lbl_80497E3C + 0x3c) != 0) {
        fn_8022FF90(node);
        *((unsigned char *)node + 0x9d) = arg2;
        *(int *)((char *)node + 0x84) = 0x2d0;
        e8 = lbl_805635E8;
        *(int *)((char *)node + 0x88) = 0x1e0;
        *((unsigned char *)node + 0x9c) = arg1;
        ec = lbl_805635EC;
        *(float *)((char *)node + 0xa0) = e8;
        f0 = lbl_805635F0;
        *(float *)((char *)node + 0x7c) = farg0;
        f4 = lbl_805635F4;
        *(float *)((char *)node + 0xac) = ec;
        f8 = lbl_805635F8;
        *(float *)((char *)node + 0xb0) = f0;
        *(float *)((char *)node + 0xa4) = f4;
        *(float *)((char *)node + 0xa8) = f8;
    } else {
        fn_8022F548(node);
    }
    fn_8022F364(node);
    return node;
}
#pragma use_lmw_stmw reset
#pragma scheduling on
#pragma pop
void fn_8022F77C(void *arg0) {
    void *prev = 0;
    void *node = lbl_8055F014;
    while (*(void **)node != arg0) {
        if (node == 0) fn_802E317C((void *)0x80340408, (char *)arg0 + 0x3c);
        prev = node;
        node = *(void **)((char *)node + 8);
    }
    if (prev == 0) lbl_8055F014 = *(void **)((char *)node + 8);
    else *(void **)((char *)prev + 8) = *(void **)((char *)node + 8);
    *(int *)((char *)node + 4) = 0;
    *(void **)((char *)node + 8) = 0;
    *(void **)node = 0;
    fn_80128668(node);
}

void fn_8022F824(void *arg0) {
    fn_8022F418();
    fn_802CAC54(*(int *)((char *)arg0 + 0x30));
    fn_8022F77C(arg0);
    fn_80128668(arg0);
}

void fn_8022F868(void *arg0, void *arg1) {
    int temp = fn_8022EDC4();
    fn_801BFD34((char *)arg0 + 0x24, (char *)arg1 + 0x24, temp);
    fn_80015B20(arg0, arg1, (void *)temp);
}

extern void PSVECCrossProduct(float *, const float *, const float *);
extern void PSVECNormalize(float *, const float *);
extern void fn_8022FF10(void *, void *);

void fn_8022FF10(void *arg0, void *arg1) {
    int sp8;
    float temp_f31 = *(float *)((char *)arg1 + 0);
    float temp_f30 = *(float *)((char *)arg1 + 8);
    fn_80015EB0(*(float *)((char *)arg1 + 4));
    fn_80015E30(&sp8, temp_f31);
    fn_80015B20(arg0, arg0, &sp8);
    fn_80015AA0(&sp8, temp_f30);
    fn_80015B20(arg0, arg0, &sp8);
}

void fn_8022FF90(void *arg0) {
    float f0 = lbl_805635FC;
    float f1 = lbl_8056360C;
    *(float *)((char *)arg0 + 4) = f0;
    *(float *)((char *)arg0 + 0) = f1;
    *(float *)((char *)arg0 + 8) = f0;
    *(float *)((char *)arg0 + 0xC) = f0;
    *(float *)((char *)arg0 + 0x10) = f1;
    *(float *)((char *)arg0 + 0x14) = f0;
    *(float *)((char *)arg0 + 0x18) = f0;
    *(float *)((char *)arg0 + 0x1C) = f0;
    *(float *)((char *)arg0 + 0x20) = f1;
    *(float *)((char *)arg0 + 0x24) = f0;
    *(float *)((char *)arg0 + 0x28) = f0;
    *(float *)((char *)arg0 + 0x2C) = f0;
    *(unsigned int *)((char *)arg0 + 0x34) = 0xFF000000;
    *(int *)((char *)arg0 + 0x38) = -1;
    *(float *)((char *)arg0 + 0x8C) = f0;
    *(float *)((char *)arg0 + 0x94) = f0;
    *(float *)((char *)arg0 + 0x98) = f0;
}

void fn_8022FFE8(int arg0) {
    float scale;
    fn_8022FB6C();
    scale = fn_80214D48();
    fn_8022FD9C((void *)arg0, scale);
}

int fn_80230020(void) {
    int count = 0;
    void *p = lbl_8055F014;
    while (p != 0) {
        p = *(void **)((char *)p + 8);
        count++;
    }
    return count;
}
