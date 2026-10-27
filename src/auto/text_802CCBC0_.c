// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FCD8;
extern int fn_802CAFC8(int);
extern int fn_802CAFF0(int);
extern int stricmp(const char *, const char *);
#pragma cplusplus on
struct Dummy {
    virtual void method0(int);
    virtual void method1();
    virtual void method2(int);
};
#pragma cplusplus reset
void fn_802CCBC0(void) {}

extern void *memcpy(void *, const void *, unsigned int);
extern float PSVECDotProduct(float *, float *, ...);
int fn_802CCBC4(void *arg0, float *arg1, float arg2, float arg3) {
    float box[4];
    float delta[3];
    unsigned int words[4];
    float dot;
    int mask;

    words[0] = *(unsigned int *)((char *)arg0 + 0);
    words[1] = *(unsigned int *)((char *)arg0 + 4);
    words[2] = *(unsigned int *)((char *)arg0 + 8);
    words[3] = *(unsigned int *)((char *)arg0 + 12);
    memcpy(box, words, 0x10);

    delta[0] = arg1[0] - *(float *)((char *)arg0 + 0x10);
    delta[1] = arg1[1] - *(float *)((char *)arg0 + 0x14);
    delta[2] = arg1[2] - *(float *)((char *)arg0 + 0x18);
    dot = ((float (*)(float *, float *))PSVECDotProduct)(delta, delta);
    dot = arg3 * (arg2 + dot);
    mask = 0;

    if (box[0] > dot) mask |= 1;
    if (box[0] < -dot) mask |= 2;
    if (box[1] > dot) mask |= 4;
    if (box[1] < -dot) mask |= 8;
    if (box[2] > dot) mask |= 0x10;
    if (box[2] < -dot) mask |= 0x20;
    return ~mask & 0x15;
}

int fn_802CCD0C(void *arg0, void *arg1) {
    int result;
    int x = fn_802CAFC8(*(int *)((char *)arg0 + 0x10));
    int y = fn_802CAFC8(*(int *)((char *)arg1 + 0x10));
    if (x != y) return x - y;
    x = fn_802CAFF0(*(int *)((char *)arg0 + 0x10));
    y = fn_802CAFF0(*(int *)((char *)arg1 + 0x10));
    if (x != y) return x - y;
    if (*(int *)((char *)arg0 + 0x10) == -1) return 1;
    if (*(int *)((char *)arg1 + 0x10) == -1) return -1;
    result = stricmp(arg0, arg1);
    return result;
}

int fn_802CCDC4(void ***arg0, void ***arg1) {
    void **obj0 = **arg0;
    void **obj1 = *arg1[0];
    int (*method0)(void **) = (int (*)(void **))(*(void **)(*arg0[0]));
    int (*method1)(void **) = (int (*)(void **))(*(void **)(*obj1));
    return method0(obj0) - method1(obj1);
}

extern int fn_802CAC28(void *, int);
extern void fn_802E317C(const char *, ...);
extern void *memset(void *, int, unsigned int);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern char lbl_8034BBC0[];
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma scheduling invalid_target
#pragma scheduling invalid_target
void fn_802CCE24(void *arg0) {
    union SwapTemp { unsigned int word[3]; unsigned short half[6]; };
    volatile union SwapTemp saved;

    {
        int var_r27;
        int var_r28;
        unsigned char *record;
        var_r28 = 0;
        var_r27 = 0;
        goto loop_2_test;
loop_2_body:
        record = *(unsigned char **)((char *)arg0 + 0x34) + var_r27;
        *(int *)(record + 0x10) = fn_802CAC28(record, 0);
        var_r27 += 0x1C;
        var_r28 += 1;
loop_2_test:
        if (var_r28 < *(int *)((char *)arg0 + 0x30)) goto loop_2_body;
    }
    {
        int (*compare)(const void *, const void *) = (int (*)(const void *, const void *))fn_802CCD0C;
        qsort(*(void **)((char *)arg0 + 0x34), *(int *)((char *)arg0 + 0x30), 0x1C, compare);
    }

    {
        register int var_r3;
        register int var_r4;
        register int var_r11;
        register int temp_r7;
        register unsigned int temp_r29_2;
        register unsigned char *temp_r5;
        register unsigned char *temp_r30;
        register unsigned char *var_r12;
        unsigned char *temp_r28;
        register int var_r27_2;
        register unsigned int var_ctr;
        var_r3 = 0;
    var_r11 = 0;
    goto loop_11_test;
loop_11_body:
    {
        var_r4 = 0;
        temp_r5 = *(unsigned char **)((char *)arg0 + 0x34) + var_r11;
        temp_r7 = *(int *)(temp_r5 + 0x14);
        temp_r29_2 = *(int *)(temp_r5 + 0x18) - temp_r7;
        temp_r30 = *(unsigned char **)((char *)arg0 + 0x2C) + temp_r7 * 0xC;
        var_r27_2 = (int)((temp_r29_2 >> 31) + temp_r29_2) >> 1;
        var_r12 = temp_r30;
        if (var_r27_2 > 0) {
            var_ctr = (unsigned int)var_r27_2 >> 1;
            for (; var_ctr != 0; var_ctr--) {
                    int back = temp_r29_2 - var_r4;
                    unsigned char *other;
                    saved.word[0] = *(unsigned int *)var_r12;
                    saved.word[1] = *(unsigned int *)(var_r12 + 4);
                    saved.word[2] = *(unsigned int *)(var_r12 + 8);
                    back *= 0xC;
                    other = temp_r30 + back;
                    *(unsigned short *)var_r12 = *(unsigned short *)(other - 0xC);
                    *(unsigned short *)(var_r12 + 2) = *(unsigned short *)(other - 0xA);
                    *(unsigned short *)(var_r12 + 4) = *(unsigned short *)(other - 8);
                    *(unsigned short *)(var_r12 + 6) = *(unsigned short *)(other - 6);
                    *(unsigned int *)(var_r12 + 8) = *(unsigned int *)(other - 4);
                    *(unsigned short *)(other - 0xC) = saved.half[0];
                    *(unsigned short *)(other - 0xA) = saved.half[1];
                    *(unsigned short *)(other - 8) = saved.half[2];
                    *(unsigned short *)(other - 6) = saved.half[3];
                    *(unsigned int *)(other - 4) = saved.word[2];
                    var_r4++;

                    back = (temp_r29_2 - var_r4) * 0xC;
                    other = temp_r30 + back;
                    saved.word[0] = *(unsigned int *)(var_r12 + 0xC);
                    saved.word[1] = *(unsigned int *)(var_r12 + 0x10);
                    saved.word[2] = *(unsigned int *)(var_r12 + 0x14);
                    *(unsigned short *)(var_r12 + 0xC) = *(unsigned short *)(other - 0xC);
                    *(unsigned short *)(var_r12 + 0xE) = *(unsigned short *)(other - 0xA);
                    *(unsigned short *)(var_r12 + 0x10) = *(unsigned short *)(other - 8);
                    *(unsigned short *)(var_r12 + 0x12) = *(unsigned short *)(other - 6);
                    *(unsigned int *)(var_r12 + 0x14) = *(unsigned int *)(other - 4);
                    *(unsigned short *)(other - 0xC) = saved.half[0];
                    *(unsigned short *)(other - 0xA) = saved.half[1];
                    *(unsigned short *)(other - 8) = saved.half[2];
                    *(unsigned short *)(other - 6) = saved.half[3];
                    *(unsigned int *)(other - 4) = saved.word[2];
                    var_r4++;
                    var_r12 += 0x18;
                }
                var_r27_2 &= 1;
            if (var_r27_2 != 0) {
block_8:
                var_ctr = var_r27_2;
                do {
                    int back = temp_r29_2 - var_r4;
                    unsigned char *other;
                    saved.word[0] = *(unsigned int *)var_r12;
                    saved.word[1] = *(unsigned int *)(var_r12 + 4);
                    saved.word[2] = *(unsigned int *)(var_r12 + 8);
                    back *= 0xC;
                    other = temp_r30 + back;
                    *(unsigned short *)var_r12 = *(unsigned short *)(other - 0xC);
                    *(unsigned short *)(var_r12 + 2) = *(unsigned short *)(other - 0xA);
                    *(unsigned short *)(var_r12 + 4) = *(unsigned short *)(other - 8);
                    *(unsigned short *)(var_r12 + 6) = *(unsigned short *)(other - 6);
                    *(unsigned int *)(var_r12 + 8) = *(unsigned int *)(other - 4);
                    *(unsigned short *)(other - 0xC) = saved.half[0];
                    *(unsigned short *)(other - 0xA) = saved.half[1];
                    *(unsigned short *)(other - 8) = saved.half[2];
                    *(unsigned short *)(other - 6) = saved.half[3];
                    *(unsigned int *)(other - 4) = saved.word[2];
                    var_r4++;
                    var_r12 += 0xC;
                    var_ctr--;
                } while (var_ctr != 0);
            }
        }
        var_r11 += 0x1C;
        var_r3++;
    }
loop_11_test:
    if (var_r3 < *(int *)((char *)arg0 + 0x30)) goto loop_11_body;
    }

    qsort(*(void **)((char *)arg0 + 0x90), *(int *)((char *)arg0 + 0x88), 4,
          (int (*)(const void *, const void *))fn_802CCDC4);
    memset((char *)arg0 + 0x38, 0, 0x50);


    {
        int var_r26 = 0;
        int var_r25 = 0;
        int var_r27 = 0;
        char *var_r28 = (char *)arg0;
        int var_r25_2;
        int var_r27_4;
        int value;
        void *object;
        do {
            var_r25 = 0;
            var_r27 = 0;
            *(int *)(var_r28 + 0x38) = *(int *)((char *)arg0 + 0x30);
            *(int *)(var_r28 + 0x3C) = -1;
            *(int *)(var_r28 + 0x40) = 0;
            *(int *)(var_r28 + 0x44) = 0;
            goto loop_21_test;
loop_21_body:
            object = *(void **)(*(void ***)((char *)arg0 + 0x90) + var_r27);
            value = ((int (*)(void *))((int (**)(void *))*(void **)object)[4])(object);
            if (var_r26 == value) {
                *(int *)(var_r28 + 0x40) = var_r25;
                var_r25_2 = var_r25 + 1;
                var_r27_4 = var_r25_2 * 4;
                *(int *)(var_r28 + 0x44) = var_r25_2;
                goto loop_23_test;
            }
            var_r27 += 4;
            var_r25++;
            goto loop_21_test;
loop_23_body:
            object = *(void **)(*(void ***)((char *)arg0 + 0x90) + var_r27_4);
            value = ((int (*)(void *))((int (**)(void *))*(void **)object)[4])(object);
            if (var_r26 != value) goto loop_23_end;
            var_r27_4 += 4;
            var_r25_2++;
            *(int *)(var_r28 + 0x44) += 1;
loop_23_test:
            if (var_r25_2 < *(int *)((char *)arg0 + 0x88)) goto loop_23_body;
loop_23_end:
            ;
loop_21_test:
            if (var_r25 < *(int *)((char *)arg0 + 0x88)) goto loop_21_body;
            var_r26++;
            var_r28 += 0x10;
        } while (var_r26 < 5);
    }

    {
        int index = 0;
        int recordOffset = 0;
        volatile char *group;
        unsigned char *record;
        int type;
        int category;
        goto loop_41_test;
loop_41_body:
        record = *(unsigned char **)((char *)arg0 + 0x34) + recordOffset;
        type = fn_802CAFC8(*(int *)(record + 0x10));
        category = 0;
        if (type == 1) category = 0;
        else if ((unsigned int)(type - 2) <= 1U) category = 1;
        else if (type == 4) category = 2;
        else if (type >= 5 && type <= 8) category = 3;
        else if (type == 9) category = 4;
        else fn_802E317C(lbl_8034BBC0, type);
        group = (char *)arg0 + category * 0x10 + 0x38;
        if (index < *(int *)group) *(int *)group = index;
        if (index + 1 > *(int *)(group + 4)) *(int *)(group + 4) = index + 1;
        recordOffset += 0x1C;
        index++;
loop_41_test:
        if (index < *(int *)((char *)arg0 + 0x30)) goto loop_41_body;
    }
    *(unsigned int *)((char *)arg0 + 8) |= 2;
}

#pragma use_lmw_stmw off
extern void fn_802CAC54(int);
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802CD254(void *arg0) {
    int index;
    int byteOffset;
    int reset;
    char *entry;
    index = 0;
    byteOffset = 0;
    reset = -2;
    while (index < *(int *)((char *)arg0 + 0x30)) {
        entry = *(char **)((char *)arg0 + 0x34) + byteOffset;
        fn_802CAC54(*(int *)(entry + 0x10));
        *(int *)(entry + 0x10) = reset;
        byteOffset += 0x1C;
        index++;
    }
    byteOffset = 0;
    index = 0;
    reset = 0;
    while (byteOffset < *(int *)((char *)arg0 + 0x88)) {
        void **items = *(void ***)((char *)arg0 + 0x90);
        void *obj = *(void **)((char *)items + index);
        if (obj != 0)
            ((Dummy *)obj)->method0(1);
        items = *(void ***)((char *)arg0 + 0x90);
        byteOffset++;
        *(void **)((char *)items + index) = (void *)reset;
        index += 4;
    }
    *(int *)((char *)arg0 + 0x88) = 0;
    *(int *)((char *)arg0 + 8) &= ~2;
}
#pragma cplusplus reset

#pragma push
#pragma scheduling invalid_target
void fn_802CD320(void *arg0, int arg1) {
    register int *items;
    register int count;

    count = *(int *)((char *)arg0 + 0x88);
    items = *(int **)((char *)arg0 + 0x90);
    items[count] = arg1;
    *(int *)((char *)arg0 + 0x88) = count + 1;
}
#pragma pop
void fn_802CD33C(void *arg0, int arg1, int arg2) {
    if (arg2 != 0) {
        unsigned short *p = (unsigned short *)(*(char **)((char *)arg0 + 0x24) + (arg1 << 5) + 0x12);
        *p &= ~0x40;
    } else {
        unsigned short *p = (unsigned short *)(*(char **)((char *)arg0 + 0x24) + (arg1 << 5) + 0x12);
        *p |= 0x40;
    }
}

void fn_802CDAA8(void) {
    lbl_8055FCD8 = 0;
}

extern unsigned char *lbl_8055DFC4;
extern int fn_802D0514(int);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802CDAFC(void *arg0, int arg1) {
    int a = *(int *)((char *)arg0 + 0x18);
    int b = *(int *)((char *)arg0 + 0x10);
    *(unsigned char *)((char *)lbl_8055DFC4 + a + arg1 + b + 1) = 0;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma opt_propagation off
int fn_802CDB20(void *arg0, int arg1) {
    int a;
    int b;
    int index;
    unsigned char *base;

    if (arg1 < 0) {
        return 0;
    }
    a = *(int *)((char *)arg0 + 0x18);
    b = *(int *)((char *)arg0 + 0x10);
    index = arg1 + a;
    base = lbl_8055DFC4;
    index = index + b;
    return base[index + 1] != 0;
}
#pragma opt_propagation on
#pragma scheduling on
#pragma pop
void fn_802CE260(int *, int);
void fn_802CE278(int *, int);
void fn_802CE290(int *, int);
void fn_802CE2A8(int *, int);
void fn_802CE2C0(int *, int);
void fn_802CE2D8(int *, int);
void fn_802CE2F0(int *, int);
#pragma scheduling on
void fn_802CDDC8(void *arg0, int arg1) {
register int delta = arg1;
volatile unsigned char *base = (volatile unsigned char *)arg0;
volatile unsigned char *rec;
unsigned char t;
int i;
int index;
int offset;
{
register unsigned int a0 = base[0], a1 = base[3], a2 = base[1], a3 = base[2];
register unsigned int a4 = base[4], a5 = base[7], a6 = base[5], a7 = base[6];
register unsigned int a8 = base[8], a9 = base[0xB], a10 = base[9], a11 = base[0xA];
base[0] = a1; base[3] = a0; base[1] = a3; base[2] = a2;
base[4] = a5; base[7] = a4; base[5] = a7; base[6] = a6;
base[8] = a9; base[0xB] = a8; base[9] = a11; base[0xA] = a10;
}
t = base[0x10];
base[0x10] = base[0x13];
base[0x13] = t;
t = base[0x11];
base[0x11] = base[0x12];
base[0x12] = t;
t = base[0x14];
base[0x14] = base[0x17];
base[0x17] = t;
t = base[0x15];
base[0x15] = base[0x16];
base[0x16] = t;
t = base[0x18];
base[0x18] = base[0x1b];
base[0x1b] = t;
t = base[0x19];
base[0x19] = base[0x1a];
base[0x1a] = t;
t = base[0x1c];
base[0x1c] = base[0x1f];
base[0x1f] = t;
t = base[0x1d];
base[0x1d] = base[0x1e];
base[0x1e] = t;
t = base[0x20];
base[0x20] = base[0x23];
base[0x23] = t;
t = base[0x21];
base[0x21] = base[0x22];
base[0x22] = t;
t = base[0x24];
base[0x24] = base[0x27];
base[0x27] = t;
t = base[0x25];
base[0x25] = base[0x26];
base[0x26] = t;
t = base[0x28];
base[0x28] = base[0x2b];
base[0x2b] = t;
t = base[0x29];
base[0x29] = base[0x2a];
base[0x2a] = t;
t = base[0x2c];
base[0x2c] = base[0x2f];
base[0x2f] = t;
t = base[0x2d];
base[0x2d] = base[0x2e];
base[0x2e] = t;
t = base[0x30];
base[0x30] = base[0x33];
base[0x33] = t;
t = base[0x31];
base[0x31] = base[0x32];
base[0x32] = t;
t = base[0x34];
base[0x34] = base[0x37];
base[0x37] = t;
t = base[0x35];
base[0x35] = base[0x36];
base[0x36] = t;
rec = base + 0x38;
for (i = 4; i != 0; --i) {
t = rec[0x0];
rec[0x0] = rec[0x3];
rec[0x3] = t;
t = rec[0x1];
rec[0x1] = rec[0x2];
rec[0x2] = t;
t = rec[0x4];
rec[0x4] = rec[0x7];
rec[0x7] = t;
t = rec[0x5];
rec[0x5] = rec[0x6];
rec[0x6] = t;
t = rec[0x8];
rec[0x8] = rec[0xb];
rec[0xb] = t;
t = rec[0x9];
rec[0x9] = rec[0xa];
rec[0xa] = t;
t = rec[0xc];
rec[0xc] = rec[0xf];
rec[0xf] = t;
t = rec[0xd];
rec[0xd] = rec[0xe];
rec[0xe] = t;
t = rec[0x10];
rec[0x10] = rec[0x13];
rec[0x13] = t;
t = rec[0x11];
rec[0x11] = rec[0x12];
rec[0x12] = t;
rec += 0x14;
}
t = base[0x88]; base[0x88] = base[0x8b]; base[0x8b] = t;
t = base[0x89]; base[0x89] = base[0x8a]; base[0x8a] = t;
t = base[0x8c]; base[0x8c] = base[0x8f]; base[0x8f] = t;
t = base[0x8d]; base[0x8d] = base[0x8e]; base[0x8e] = t;
t = base[0x90]; base[0x90] = base[0x93]; base[0x93] = t;
t = base[0x91]; base[0x91] = base[0x92]; base[0x92] = t;
fn_802CE260((int *)(base + 0x14), delta);
fn_802CE278((int *)(base + 0x1C), delta);
fn_802CE290((int *)(base + 0x24), delta);
fn_802CE2A8((int *)(base + 0x2C), delta);
index = 0;
offset = 0;
while (index < *(volatile int *)(base + 0x28)) {
rec = *(volatile unsigned char **)(base + 0x2C) + offset;
t = rec[0x0];
rec[0x0] = rec[0x1];
rec[0x1] = t;
t = rec[0x2];
rec[0x2] = rec[0x3];
rec[0x3] = t;
t = rec[0x4];
rec[0x4] = rec[0x5];
rec[0x5] = t;
t = rec[0x6];
rec[0x6] = rec[0x7];
rec[0x7] = t;
t = rec[0x8];
rec[0x8] = rec[0xb];
rec[0xb] = t;
t = rec[0x9];
rec[0x9] = rec[0xa];
rec[0xa] = t;
fn_802CE2C0((int *)(rec + 8), delta);
offset += 0xC;
index++;
}
fn_802CE2D8((int *)(base + 0x34), delta);
index = 0;
offset = 0;
while (index < *(volatile int *)(base + 0x30)) {
rec = *(volatile unsigned char **)(base + 0x34) + offset;
t = rec[0x14];
rec[0x14] = rec[0x17];
rec[0x17] = t;
t = rec[0x15];
rec[0x15] = rec[0x16];
rec[0x16] = t;
t = rec[0x18];
rec[0x18] = rec[0x1b];
rec[0x1b] = t;
t = rec[0x19];
rec[0x19] = rec[0x1a];
rec[0x1a] = t;
*(volatile int *)(rec + 0x10) = -2;
offset += 0x1C;
index++;
}
fn_802CE2F0((int *)(base + 0x90), delta);
index = 0;
offset = 0;
while (index < *(volatile int *)(base + 0x88)) {
rec = *(volatile unsigned char **)(base + 0x90) + offset;
t = rec[0x0];
rec[0x0] = rec[0x3];
rec[0x3] = t;
t = rec[0x1];
rec[0x1] = rec[0x2];
rec[0x2] = t;
offset += 4;
index++;
}
*(volatile int *)(base + 8) |= 1;
}
#pragma scheduling invalid_target
void fn_802CE260(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE278(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE290(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2A8(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2C0(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2D8(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802CE2F0(int *arg0, int arg1) {
    int val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

