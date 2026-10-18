// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FAB8;
extern void *lbl_8055FABC;
int fn_8012C33C(void);
extern float lbl_80564D14;
extern float lbl_80564D18;
int fn_802CAC28(int, int);
void fn_802BD018(void *);
int fn_802BD070(void *);
void fn_80128668(void *);
int fn_802BC334(int arg0) {
    int valid = 0;
    if (arg0 != 0 && fn_8012C33C() != 0) valid = 1;
    if (valid != 0) return fn_802CAC28(arg0, 0);
    return -2;
}

#pragma dont_inline on
int stricmp(const char *, const char *);
extern const char lbl_8055CF38[];
int fn_802BC39C(void *arg0) {
    char *name = (*(char *(*)(void *))(*(void ***)arg0)[2])(arg0);
    return stricmp(lbl_8055CF38, name) == 0;
}
#pragma dont_inline reset

void *fn_802BE844(short, short, short);
int fn_802BC39C();
void fn_802BC3DC(void) {
    fn_802BC39C();
}

void fn_802BC3E0(short arg0, short arg1, short arg2, char *arg3) {
    char *obj = fn_802BE844(arg0, arg1, arg2);
    *(char **)arg3 = *(char **)(obj + 4);
    *(char **)(obj + 4) = arg3;
}

short fn_802BC424(int arg0) {
    short value = arg0 + 0x200;
    int mask = 0x1FF;
    while (1) {
        mask >>= 1;
        if ((value & mask) == 0)
            break;
    }
    return mask + 1;
}

void fn_802BC44C(void *arg0) {
    int offset = 0;
    int i = 0;
    char *entry;
    goto check;
loop:
    entry = *(char **)arg0 + offset;
    fn_802BC3E0(*(short *)(entry + 4), *(short *)(entry + 6), fn_802BC424(*(short *)(entry + 4)), entry);
    offset += 0x10;
    i++;
check:
    if (i < *(int *)((char *)arg0 + 4)) goto loop;
}

void *fn_802BC4D4(void *arg0) {
    return *(void **)(*(char **)((char *)arg0 + 4) + 0xC);
}

double fn_8002F234(float, float);
float fn_802BC540(void *arg0, float farg0) {
    float x = *(float *)arg0;
    float z = *(float *)((char *)arg0 + 8);
    return farg0 * (float)fn_8002F234(x * x + z * z, z);
}

#pragma push
#pragma processor 750
#pragma scheduling 750
#pragma use_lmw_stmw off
void *fn_802BC9B0(void *arg0, int arg1, float scale) {
    extern void *fn_801284F8(int, int);
    extern float lbl_80564D1C, lbl_80564D20;
    extern int lbl_8034AB54[], lbl_80333918[];
    float value = lbl_80564D1C;
    float b = *(float *)((char *)arg0 + 0x1C) * scale;
    float a = *(float *)((char *)arg0 + 0x18) * scale;
    char *obj = fn_801284F8(0x2C, (int)&lbl_8034AB54);
    if (obj != 0) {
        float initial = lbl_80564D20;
        *(int *)(obj + 0xC) = 0;
        *(int *)(obj + 4) = 0;
        *(int *)(obj + 8) = 0;
        *(int *)(obj + 0x18) = 0x54554245;
        *(float *)(obj + 0x10) = value;
        *(float *)(obj + 0x14) = lbl_80564D20;
        *(int *)(obj + 0x20) = 100;
        *(int *)(obj + 0x1C) = 0;
        *(float *)(obj + 0x24) = b;
        *(float *)(obj + 0x28) = a;
        *(void **)obj = &lbl_80333918;
    }
    (*(void (***)(void *, int))obj)[16](obj, arg1);
    return obj;
}

void fn_802BCFB0(int *arg0) {
    int temp_r31;
    temp_r31 = *arg0;
    if (temp_r31 != 0) {
        if (temp_r31 != 0) {
            fn_802BD018((char *)temp_r31 + 8);
            fn_802BD018((char *)temp_r31 + 4);
            fn_802BD070((void *)temp_r31);
            fn_80128668((void *)temp_r31);
        }
        *arg0 = 0;
    }
}

#pragma pop

int fn_802BD0C8(void *arg0) {
    int result = 0;
    if (*(int *)((char *)arg0 + 4) != 0) {
        void **ptr = *(void ***)((char *)arg0 + 0x58);
        if (ptr != 0)
            result = *(int *)((char *)*ptr + 4);
    }
    return result;
}

int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD0F4(void *arg0) {
    int i, offset, count;
    char *entries, *entry;
    void *array;
    float pos[2];
    if (*(int *)((char *)arg0 + 4) != 0 && (array = *(void **)((char *)arg0 + 0x58)) != 0) {
        entries = *(char **)array;
        count = *(int *)(entries + 4);
        i = 0; offset = 0;
        while (i < count) {
            array = *(void **)((char *)arg0 + 0x58);
            entries = *(char **)array;
            entry = entries + offset;
            pos[0] = *(float *)(entry + 0x30);
            pos[1] = *(float *)(entry + 0x38);
            *(int *)(entry + 4) = fn_802BA580(*(int *)((char *)arg0 + 4), pos, *(float *)(entry + 0x1c));
            offset += 0x44; i++;
        }
    }
}

void *fn_802BD194(void *arg0, const char *arg1) {
    unsigned int count = *(unsigned int *)arg0;
    unsigned int i = 0;
    unsigned int offset = 0;
    char *base;
    while (i < count) {
        base = *(char **)((char *)arg0 + 4);
        if (strcmp(base + offset, arg1) == 0)
            return base + i * 0x38;
        offset += 0x38;
        i++;
    }
    return 0;
}

void *fn_801284F8(int, int);
int strcmp(const char *, const char *);
int fn_802BA580(int, float *, float);
void fn_802BD414(int arg0, volatile int *arg1) {
    volatile int *result = (volatile int *)fn_801284F8(0xC, arg0);
    if (result != 0) {
        int second = arg1[1];
        int first = arg1[0];
        result[0] = second;
        result[2] = first;
        result[1] = 0;
        result[1] = result[1] + arg1[0];
    }
}

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
void fn_802BD4DC(void *arg0, int arg1) {
    extern void fn_802BD69C(void *, int);
    extern void fn_802BD5B0(void *, int);
    unsigned char *p = arg0;
    char *entry;
    int offset;
    unsigned int i;
    unsigned char b5, b4, b1, b0, b3, b2, b6;
    b4 = p[4];
    b5 = p[5];
    b6 = p[6];
    p[4] = p[7];
    b0 = p[0];
    b3 = p[3];
    p[7] = b4;
    b1 = p[1];
    b2 = p[2];
    p[5] = b6;
    p[6] = b5;
    p[0] = b3;
    p[3] = b0;
    p[1] = b2;
    p[2] = b1;
    *(int *)(p + 4) = fn_802BD5A8(*(int *)(p + 4), arg1);
    i = 0;
    offset = 0;
    while (i < *(unsigned int *)p) {
        entry = *(char **)(p + 4) + offset;
        fn_802BD69C(entry + 0x20, arg1);
        fn_802BD5B0(entry + 0x28, arg1);
        fn_802BD5B0(entry + 0x30, arg1);
        offset += 0x38;
        i++;
    }
}
#pragma pop

int fn_802BD5A8(int arg0, int arg1) { return arg0 + arg1; }

#pragma push
#pragma inline_depth(0)
#pragma use_lmw_stmw off
void fn_802BD5B0(void *arg0, int arg1) {
    extern int fn_802BD694(int, int);
    extern float lbl_80564D30;
    unsigned char *p = arg0;
    unsigned char tmp;
    unsigned char other;
    register unsigned char *entry;
    int offset;
    unsigned int i;
    float zero;
    unsigned char b7, b6, b2, b3, b0, b1, b4, b5;
    b4 = p[4]; b5 = p[5];
    b7 = p[7]; b6 = p[6]; p[4] = b7; b0 = p[0]; b3 = p[3]; p[7] = b4;
    b1 = p[1]; b2 = p[2]; p[5] = b6; p[6] = b5;
    p[0] = b3; p[3] = b0; p[1] = b2; p[2] = b1;
    *(int *)(p + 4) = fn_802BD694(*(int *)(p + 4), arg1);
    i = 0; zero = lbl_80564D30; offset = 0;
    while (i < *(unsigned int *)p) {
        entry = *(unsigned char **)(p + 4) + offset;
        tmp = entry[4]; other = entry[5]; entry[4] = other; entry[5] = tmp;
        tmp = entry[6]; entry[6] = entry[7]; entry[7] = tmp;
        tmp = entry[8]; entry[8] = entry[9]; entry[9] = tmp;
        tmp = entry[10]; entry[10] = entry[11]; entry[11] = tmp;
        *(float *)(entry + 12) = zero;
        offset += 0x10; i++;
    }
}
#pragma pop

int fn_802BD694(int arg0, int arg1) { return arg0 + arg1; }

int fn_802BD80C(int arg0, int arg1) { return arg0 + arg1; }

void fn_802BDC3C(void* alarm) {
    fn_802C1550(fn_802BD210(alarm));
}

void fn_802BCF04(void);
void fn_8012C4D8(void);
void fn_802C13A4(void);
void deleteThreads__6SystemFv_802BDCA4(void **);
void fn_802BDC60(void) {
    register int flag;
    fn_802BCF04();
    flag = lbl_8055FAB8;
    if (flag != 0) {
        fn_8012C4D8();
        lbl_8055FAB8 = 0;
    }
    fn_802C13A4();
    deleteThreads__6SystemFv_802BDCA4(&lbl_8055FABC);
}

extern int lbl_8034AB38, lbl_8034AC48;
extern int lbl_8055FAA8, lbl_8055FAAC, lbl_8055FAB0;
extern void *lbl_8055FABC;
void deleteThreads__6SystemFv_802BDCA4(void **arg0) {
    void *obj = *arg0;
    if (obj != 0) {
        if (obj != 0) {
            void (**vtable)(void *, int) = *(void (***)(void *, int))((char *)obj + 4);
            vtable[4](obj, 1);
        }
        *arg0 = 0;
    }
}

void fn_802C2930(void*, unsigned int);
void fn_802BD018(void *arg0) {
    void *obj = *(void **)arg0;
    if (obj) {
        if (obj) {
            *(int *)obj = 0;
            ((int *)obj)[1] = 0;
            ((int *)obj)[2] = 0;
            fn_80128668(obj);
        }
        *(void **)arg0 = 0;
    }
}
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_802BDCFC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_802C2930((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

void fn_802BDD54(void) {
    fn_802BD814();
}

void fn_802BDD58(void) {
    fn_801E7E18();
    fn_802C173C();
    if (fn_8020403C() != 0) fn_802BD814();
}

void fn_802BDFBC(void *arg0, int arg1, float farg0) {
    float value;
    void *node;
    value = farg0;
    if (arg1 < 8) value = lbl_80564D18;
    else if (arg1 > 8) value = lbl_80564D14;
    node = *(void **)((char *)arg0 + 4);
    while (node != 0) {
        *(float *)((char *)node + 0xC) = value;
        node = *(void **)node;
    }
}

extern float lbl_80564D14;
extern float lbl_80564D18;
void fn_802BDFF4(void **arg0) {
    register void *value = *(void **)((char *)arg0 - 8);
    if (value) fn_802BAF98();
}

extern int lbl_804C00D4;
int fn_802BE1D8(void) {
    int sum = 0;
    int i = 0;
    int offset = 0;
    while (i < *(int *)((char *)&lbl_804C00D4 + 4)) {
        sum += fn_802BD0C8(*(char **)&lbl_804C00D4 + offset);
        offset += 0x60;
        i++;
    }
    return sum;
}

void fn_802BE244(void) {
    int offset = 0;
    int i = 0;
    while (i < *(int *)((char *)&lbl_804C00D4 + 4)) {
        fn_802BD0F4(*(char **)&lbl_804C00D4 + offset);
        offset += 0x60;
        i++;
    }
}

void *fn_801284F8(int, int);
