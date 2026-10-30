// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void *lbl_8055FE5C;
extern void *fn_801284F8(int, void *);
extern int fn_8012850C(int, void *);
extern void fn_802D9C5C(int, void *, int);
extern void fn_802D9DE4(void);
extern char lbl_8034C8F8[];
extern char lbl_8034C908[];
__declspec(section ".sdata") extern char lbl_8055D128[];
extern float lbl_80565030;
extern float lbl_80565034;
extern float lbl_804DAC48[];
extern float lbl_804DB434[];
extern char lbl_80346798[];
extern void fn_802E317C(char *, ...);
extern int memcpy(void *, const void *, unsigned int);
extern char lbl_80346798[];
extern void fn_802E317C(char *, ...);
extern int memcpy(void *, const void *, unsigned int);
extern float lbl_80565038;
extern float lbl_8056503C;
extern void *fn_802DA704(int, void *, int);
extern void fn_802DAA18(void *);
#pragma scheduling off
extern void fn_80128668(void *);
extern void fn_80128670(int);
extern char lbl_8034C8E8[];
#pragma scheduling on
#pragma opt_propagation off
void fn_802D9C5C(int arg0, void *arg1, int arg2) {
    extern float lbl_804DB068[];
    float *var_r3;
    float *var_r4;
    float temp_r0_2;
    float temp_r1;
    float temp_r0;
    int temp_r7;
    int temp_r7_2;
    int var_ctr_2;
    int var_r8;
    int var_r9 = 0;
    unsigned int var_ctr;
    float *var_r7;
    float *var_r6;

    if (arg2 > 0) {
        temp_r7 = arg2 - 8;
        if (arg2 > 8) {
            var_r8 = 0;
            if (arg2 >= 0 && arg2 <= 0x7FFFFFFE)
                var_r8 = 1;
            if (var_r8 != 0) {
                var_ctr = (unsigned int)(temp_r7 + 7) >> 3;
                var_r7 = (float *)arg1;
                var_r6 = &lbl_804DB068[arg0 * 3];
                if (temp_r7 > 0) {
                    do {
                        var_r9 += 8;
                        var_r6[0] = var_r7[0];
                        var_r6[1] = var_r7[1];
                        var_r6[2] = var_r7[2];
                        var_r6[3] = var_r7[3];
                        var_r6[4] = var_r7[4];
                        var_r6[5] = var_r7[5];
                        var_r6[6] = var_r7[6];
                        var_r6[7] = var_r7[7];
                        var_r6[8] = var_r7[8];
                        var_r6[9] = var_r7[9];
                        var_r6[10] = var_r7[10];
                        var_r6[11] = var_r7[11];
                        var_r6[12] = var_r7[12];
                        var_r6[13] = var_r7[13];
                        var_r6[14] = var_r7[14];
                        var_r6[15] = var_r7[15];
                        var_r6[16] = var_r7[16];
                        var_r6[17] = var_r7[17];
                        var_r6[18] = var_r7[18];
                        var_r6[19] = var_r7[19];
                        var_r6[20] = var_r7[20];
                        var_r6[21] = var_r7[21];
                        var_r6[22] = var_r7[22];
                        var_r6[23] = var_r7[23];
                        var_r7 += 24;
                        var_r6 += 24;
                        var_ctr -= 1;
                    } while (var_ctr != 0);
                }
            }
        }
        temp_r7_2 = var_r9 * 12;
        var_ctr_2 = arg2 - var_r9;
        var_r4 = (float *)((char *)arg1 + temp_r7_2);
        var_r3 = (float *)((char *)lbl_804DB068 + temp_r7_2 + (arg0 * 12));
        if (var_r9 < arg2) {
            do {
                temp_r0_2 = var_r4[0];
                temp_r1 = var_r4[1];
                var_r3[0] = temp_r0_2;
                temp_r0 = var_r4[2];
                var_r4 += 3;
                var_r3[1] = temp_r1;
                var_r3[2] = temp_r0;
                var_r3 += 3;
                var_ctr_2 -= 1;
            } while (var_ctr_2 != 0);
        }
    }
}

void fn_802DA1F4(int arg0, void *arg1, int arg2) {
    extern int lbl_804DB458[];
    extern signed char lbl_8055FE58;
    int *var_r3;
    int *var_r4;
    int temp_r0;
    int temp_r0_2;
    int temp_r6;
    int temp_r7;
    int temp_r7_2;
    int var_ctr_2;
    int var_r8;
    int var_r9 = 0;
    unsigned int var_ctr;
    int *var_r7;
    int *var_r8_2;

    if (arg2 > 0) {
        temp_r7 = arg2 - 8;
        if (arg2 > 8) {
            var_r8 = 0;
            if (arg2 >= 0 && arg2 <= 0x7FFFFFFE)
                var_r8 = 1;
            if (var_r8 != 0) {
                var_ctr = (unsigned int)(temp_r7 + 7) >> 3;
                var_r7 = (int *)arg1;
                var_r8_2 = &lbl_804DB458[arg0];
                if (temp_r7 > 0) {
                    do {
                        var_r9 += 8;
                        var_r8_2[0] = var_r7[0];
                        var_r8_2[1] = var_r7[1];
                        var_r8_2[2] = var_r7[2];
                        var_r8_2[3] = var_r7[3];
                        var_r8_2[4] = var_r7[4];
                        temp_r6 = var_r7[6];
                        var_r8_2[5] = var_r7[5];
                        temp_r0 = var_r7[7];
                        var_r7 += 8;
                        var_r8_2[6] = temp_r6;
                        var_r8_2[7] = temp_r0;
                        var_r8_2 += 8;
                        var_ctr -= 1;
                    } while (var_ctr != 0);
                }
            }
        }
        temp_r7_2 = var_r9 * 4;
        var_ctr_2 = arg2 - var_r9;
        var_r4 = (int *)((char *)arg1 + temp_r7_2);
        var_r3 = (int *)((char *)lbl_804DB458 + temp_r7_2 + (arg0 * 4));
        if (var_r9 < arg2) {
            do {
                temp_r0_2 = *var_r4;
                var_r4 += 1;
                *var_r3 = temp_r0_2;
                var_r3 += 1;
                var_ctr_2 -= 1;
            } while (var_ctr_2 != 0);
        }
    }
    lbl_8055FE58 = 1;
}

void fn_802DA2F4(void) {
    void *object;
    void *buffer;
    float *matrix;
    register int count;
    float value0;
    float value1;
    float *last;

    object = fn_801284F8(0x28, lbl_8055D128);
    if (object != 0) {
        buffer = (void *)fn_8012850C(0x19000, lbl_8034C908);
        *(void **)((char *)object + 8) = lbl_8034C8F8;
        *(int *)((char *)object + 0x10) = 0;
        *(int *)((char *)object + 0xC) = 0x19000;
        *(void **)((char *)object + 4) = buffer;
        *(void **)object = lbl_8034C8E8;
        *(void **)((char *)object + 0x14) = (void *)fn_802D9C5C;
        *(void **)((char *)object + 0x18) = (void *)fn_802D9DE4;
        *(void **)((char *)object + 0x1C) = (void *)fn_802DA1F4;
    }
    lbl_8055FE5C = object;

    value0 = lbl_80565030;
    value1 = lbl_80565034;
    matrix = lbl_804DAC48;
    count = 0xB;
    do {
        matrix[0] = value0;
        matrix[1] = value1;
        matrix[2] = value1;
        matrix[3] = value1;
        matrix[4] = value0;
        matrix[5] = value1;
        matrix[6] = value1;
        matrix[7] = value1;
        matrix[8] = value0;
        matrix[9] = value1;
        matrix[10] = value1;
        matrix[11] = value1;
        matrix[12] = value0;
        matrix[13] = value1;
        matrix[14] = value1;
        matrix[15] = value1;
        matrix[16] = value0;
        matrix[17] = value1;
        matrix[18] = value1;
        matrix[19] = value1;
        matrix[20] = value0;
        matrix[21] = value1;
        matrix[22] = value1;
        matrix[23] = value1;
        matrix += 24;
    } while (--count != 0);

    value0 = lbl_80565030;
    value1 = lbl_80565034;
    last = lbl_804DB434;
    *last++ = value0;
    *last++ = value1;
    *last++ = value1;
    *last++ = value1;
    *last++ = value0;
    *last++ = value1;
    *last++ = value1;
    *last++ = value1;
    *last = value0;
}

#pragma opt_propagation reset
#pragma scheduling off
void *fn_802DA450(void *arg0,int arg1) {
 if(arg0) { *(void**)arg0=(void*)((char*)&lbl_8034C8E8+0x10000); fn_80128670(*(int*)((char*)arg0+4)); if(arg0) *(int*)((char*)arg0+4)=0; if(arg1>0) fn_80128668(arg0); }
 return arg0;
}

void fn_802DA4C4(void) {
    void *p = lbl_8055FE5C;
    if (p != 0) {
        if (p != 0) {
            *(volatile void **)p = lbl_8034C8E8;
            fn_80128670(*(int *)((char *)p + 4));
            if (p != 0)
                *(int *)((char *)p + 4) = 0;
        }
        fn_80128668(p);
    }
    lbl_8055FE5C = 0;
}

#pragma scheduling invalid_target
void fn_802DA52C(void) {
    volatile unsigned char *p = (volatile unsigned char *)lbl_8055FE5C;
    *(volatile int *)(p + 0x10) = 0;
    *(volatile int *)(p + 0x20) = -1;
    p[0x24] = 1;
    p[0x25] = 0;
}
#pragma scheduling on
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma opt_propagation off
void *fn_802DA550(void *arg0, void *arg1, int arg2, void *arg3, void *arg4, int arg5) {
    struct DaaContext {
        int unk_0;
        unsigned char *buffer;
        void *name;
        int capacity;
        int used;
        void *callback0;
        void *callback1;
        void *callback2;
        void *current;
        unsigned char status;
        unsigned char initialized;
    };
    volatile struct DaaContext *ctx;
    register int count1 = arg5;
    register int count2 = arg2;
    int bytes1;
    int size1;
    int aligned1;
    int used;
    int limit;
    int position;
    unsigned char *base;
    unsigned char *record1;
    int bytes2;
    int size2;
    int aligned2;
    unsigned char saved;
    unsigned char *record2;

    ctx = (volatile struct DaaContext *)lbl_8055FE5C;
    bytes1 = count1 * 4;
    size1 = bytes1 + 8;
    aligned1 = (size1 + 3) & ~3;
    used = ctx->used;
    if (aligned1 + used + 8 > ctx->capacity) {
        limit = ctx->capacity;
        fn_802E317C(lbl_80346798, ctx->name, size1, limit / 1024);
        record1 = 0;
    } else {
        base = (unsigned char *)used;
        base += (unsigned int)ctx->buffer;
        *(int *)base = 1;
        record1 = base + 4;
        position = (unsigned int)ctx->buffer;
        position += ctx->used;
        position += aligned1;
        *(int *)(position + 4) = aligned1;
        used = ctx->used;
        used += aligned1;
        used += 8;
        ctx->used = used;
    }
    *(int *)record1 = (int)arg3;
    *(int *)(record1 + 4) = count1;
    memcpy(record1 + 8, arg4, bytes1);

    bytes2 = count2 * 12;
    saved = ctx->initialized;
    ctx->initialized = 0;
    size2 = bytes2 + 0x18;
    aligned2 = (size2 + 3) & ~3;
    used = ctx->used;
    if (aligned2 + used + 8 > ctx->capacity) {
        limit = ctx->capacity;
        fn_802E317C(lbl_80346798, ctx->name, size2, limit / 1024);
        record2 = 0;
    } else {
        base = (unsigned char *)used;
        base += (unsigned int)ctx->buffer;
        *(int *)base = 1;
        record2 = base + 4;
        position = (unsigned int)ctx->buffer;
        position += ctx->used;
        position += aligned2;
        *(int *)(position + 4) = aligned2;
        used = ctx->used;
        used += aligned2;
        used += 8;
        ctx->used = used;
    }
    *(int *)record2 = 7;
    *(int *)(record2 + 4) = (int)arg0;
    *(int *)(record2 + 8) = count2;
    *(int *)(record2 + 0x0C) = 0;
    *(int *)(record2 + 0x14) = (int)record1;
    record2[0x10] = saved;
    memcpy(record2 + 0x18, arg1, bytes2);
    return record2;
}
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802DA704(int owner, void *data, int count) {
    volatile unsigned char *state;
    unsigned char saved;
    unsigned char *base;
    int bytes;
    int size;
    int rounded;
    int used;
    int aligned;
    int limit;
    int position;
    int updated;
    void *result;
    state = (volatile unsigned char *)lbl_8055FE5C;
    bytes = count * 12;
    saved = state[0x25];
    state[0x25] = 0;
    size = bytes + 0x18;
    rounded = size + 3;
    used = *(volatile int *)(state + 0x10);
    aligned = rounded & ~3;
    limit = *(volatile int *)(state + 0x0C);
    if (aligned + used + 8 > limit) {
        fn_802E317C(lbl_80346798, *(volatile int *)(state + 8), size, *(volatile int *)(state + 0x0C) / 1024);
        result = 0;
    } else {
        base = (unsigned char *)used;
        base += *(unsigned int *)(state + 4);
        *(int *)base = 1;
        result = base + 4;
        position = *(unsigned int *)(state + 4);
        position += *(volatile int *)(state + 0x10);
        position += aligned;
        *(int *)(position + 4) = aligned;
        updated = *(volatile int *)(state + 0x10);
        updated += aligned;
        updated += 8;
        *(volatile int *)(state + 0x10) = updated;
    }
    *(int *)((char *)result + 0) = 7;
    *(int *)((char *)result + 4) = owner;
    *(int *)((char *)result + 8) = count;
    *(int *)((char *)result + 0x0C) = 0;
    *(int *)((char *)result + 0x14) = 0;
    *((unsigned char *)result + 0x10) = saved;
    memcpy((char *)result + 0x18, data, bytes);
    return result;
}
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802DA80C(int owner, void *data, int count) {
    volatile unsigned char *state;
    unsigned char saved;
    unsigned char *base;
    int bytes;
    int used;
    int size;
    int aligned;
    int position;
    int updated;
    void *result;
    state = (volatile unsigned char *)lbl_8055FE5C;
    bytes = count * 0x30;
    saved = state[0x25];
    state[0x25] = 0;
    size = bytes + 0x18;
    used = *(volatile int *)(state + 0x10);
    aligned = (size + 3) & ~3;
    if (aligned + used + 8 > *(volatile int *)(state + 0x0C)) {
        int limit = *(volatile int *)(state + 0x0C);
        fn_802E317C(lbl_80346798, *(volatile int *)(state + 8), size, limit / 1024);
        result = 0;
    } else {
        position = *(volatile int *)(state + 0x10);
        base = (unsigned char *)position;
        position = *(unsigned int *)(state + 4);
        base += position;
        *(int *)base = 1;
        result = base + 4;
        position = *(unsigned int *)(state + 4);
        used = *(volatile int *)(state + 0x10);
        used += position;
        position = used + aligned;
        *(int *)(position + 4) = aligned;
        updated = aligned + *(volatile int *)(state + 0x10);
        updated += 8;
        *(volatile int *)(state + 0x10) = updated;
    }
    *(int *)((char *)result + 0) = 7;
    *(int *)((char *)result + 4) = owner;
    *(int *)((char *)result + 8) = count;
    *(int *)((char *)result + 0x0C) = 1;
    *(int *)((char *)result + 0x14) = 0;
    *((unsigned char *)result + 0x10) = saved;
    memcpy((char *)result + 0x18, data, bytes);
    return result;
}
#pragma scheduling on
#pragma use_lmw_stmw reset

extern float lbl_80565030;
extern void fn_802E317C(char *, ...);
extern int memcpy(void *, const void *, unsigned int);
extern char lbl_80346798[];
void *fn_802DA918(float arg0, float arg1, float arg2) {
    float a, b, c;
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

extern void *memset(void *, int, unsigned int);
#pragma opt_propagation off
struct DaaContext {
    int unk_0;
    unsigned char *buffer;
    void *name;
    int capacity;
    int used;
    void *callback0;
    void *callback1;
    void *callback2;
    void *current;
    unsigned char status;
    unsigned char initialized;
};

struct DaaRecord {
    int kind;
    int unk_4;
    int capacity;
    int kind2;
    unsigned char status;
    unsigned char pad_11[3];
    void *next;
    unsigned char data[0x3C0];
};

#pragma scheduling invalid_target
#pragma opt_propagation off
void fn_802DAA18(void *arg0) {
    extern void *lbl_8055FE60;
    extern char lbl_80346798[];
    extern void fn_802E317C(char *, ...);
    extern int memcpy(void *, const void *, unsigned int);
    unsigned char sp8[0x3C0];
    void *var_r31 = arg0;
    struct DaaContext *ctx = (struct DaaContext *)lbl_8055FE5C;
    struct DaaRecord *entry;
    struct DaaRecord *var_r29;
    char *format;
    void *name;
    int size;

    lbl_8055FE60 = var_r31;
    if (var_r31 == 0) {
        entry = (struct DaaRecord *)ctx->current;
        if ((unsigned int)entry + 0x10000 == 0xFFFF) {
            memset(sp8, 0, 0x3C0);
            ctx->initialized = 0;
            var_r31 = (void *)1;
            if (ctx->used + 0x3E0 > ctx->capacity) {
                size = *(volatile int *)&ctx->capacity;
                format = lbl_80346798;
                name = ctx->name;
                fn_802E317C(format, name, 0x3D8, size / 0x400);
                var_r29 = 0;
            } else {
                var_r29 = (struct DaaRecord *)(ctx->buffer + ctx->used);
                *(int *)var_r29 = (int)var_r31;
                var_r29 = (struct DaaRecord *)((unsigned char *)var_r29 + 4);
                *(int *)(ctx->buffer + ctx->used + 0x3DC) = 0x3D8;
                ctx->used += 0x3E0;
            }
            var_r29->kind = 7;
            var_r29->unk_4 = 0;
            var_r29->capacity = 0x50;
            var_r29->kind2 = 0;
            var_r29->next = 0;
            var_r29->status = (unsigned char)var_r31;
            memcpy(var_r29->data, sp8, 0x3C0);
            ctx->current = var_r29;
        }
    }
    var_r31 = ctx->current;
    entry = (struct DaaRecord *)var_r31;
    if (entry->kind2 == 0) {
        ((void (*)(void *, void *, int))ctx->callback0)(
            *(void **)((unsigned char *)entry + 4), entry->data, entry->capacity);
    } else {
        ((void (*)(void *, void *, int))ctx->callback1)(
            *(void **)((unsigned char *)entry + 4), entry->data, entry->capacity);
    }
    var_r29 = (struct DaaRecord *)entry->next;
    if (var_r29 != 0) {
        ((void (*)(void *, void *, int))ctx->callback2)(
            *(void **)var_r29, (unsigned char *)var_r29 + 8, *(int *)((unsigned char *)var_r29 + 4));
    }
    ctx->status = entry->status;
}
#pragma opt_propagation reset
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
    fn_802DAA18(fn_802DA704(0x4C, &sp8, 4));
}

void fn_802DAC54(void) {
    *((unsigned char *)lbl_8055FE5C + 0x25) = 1;
}

unsigned char fn_802DAC64(void) {
    return *((unsigned char *)lbl_8055FE5C + 0x24);
}
