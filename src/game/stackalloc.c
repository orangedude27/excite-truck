// stackalloc — stack allocator (StackAlloc::buf, BoneHandleAlloc).
// Recovered TU window 0x802D9C5C..0x802DAC70+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802DAC70 (+ .ctors slot 0x802ED5D0) remains in
// auto/text_802DAC70_.c pending a promotion pass.
extern void *lbl_8055FE5C;
extern void *fn_801284F8(int, void *);
extern int fn_8012850C(int, void *);
extern void fn_802D9C5C(int, void *, int);
extern void fn_802D9DE4(int, void *, int);
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

// One StackAlloc instance, "BoneHandleAlloc" (lbl_8055FE5C), over a 0x19000
// byte arena named "StackAlloc::buf".  It bump-allocates records that queue a
// write into one of the shared bone tables; fn_802DAA18 applies the current
// record through the copy callback selected by its elemType.
struct StackAlloc {
    /* 0x00 */ void *vtable;    // lbl_8034C8E8, destructor at +8
    /* 0x04 */ unsigned char *buffer; // arena base
    /* 0x08 */ void *name;      // "BoneHandleAlloc"
    /* 0x0C */ int capacity;    // arena size
    /* 0x10 */ int used;        // bytes of the arena taken so far
    /* 0x14 */ void *copyVec3;  // fn_802D9C5C: write 12-byte elements
    /* 0x18 */ void *copyMtx;   // fn_802D9DE4: write 0x30-byte 3x4 matrices
    /* 0x1C */ void *copyInt;   // fn_802DA1F4: write 4-byte elements
    /* 0x20 */ void *current;   // record being applied, -1 when none
    /* 0x24 */ unsigned char status;
    /* 0x25 */ unsigned char initialized;
};

// A queued write, as handed out by the allocators below.  The arena block
// around it is [u32 1][this record, alignedSize bytes][u32 alignedSize].
struct StackAllocRecord {
    /* 0x00 */ int kind;        // 7 for the records queued here
    /* 0x04 */ int index;       // first element to write in the table
    /* 0x08 */ int count;       // number of elements in data[]
    /* 0x0C */ int elemType;    // 0 = Vec3 (copyVec3), 1 = matrix (copyMtx)
    /* 0x10 */ unsigned char status; // StackAlloc::status to restore
    /* 0x11 */ unsigned char pad_11[3];
    /* 0x14 */ void *next;      // companion 4-byte write {index, count, data}, or 0
    /* 0x18 */ unsigned char data[0x3C0];
};

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

#pragma push
void fn_802D9DE4(int arg0, void *arg1, int arg2) {
    unsigned int *src, *dest;
    int i = 0, n, ctr, safe;
    unsigned int t0, t1;
    if (arg2 > 0) {
        n = arg2 - 8;
        if (arg2 > 8) {
            safe = 0;
            if ((arg2 >= 0) && (arg2 <= 0x7ffffffe)) safe = 1;
            if (safe) {
                ctr = (unsigned int)(n + 7) >> 3;
                src = (unsigned int *)arg1;
                dest = (unsigned int *)((char *)lbl_804DAC48 + arg0 * 0x30);
                if (n > 0) do {
                t0 = src[0];
                t1 = src[1];
                dest[0] = t0;
                t0 = src[2];
                dest[1] = t1;
                t1 = src[3];
                dest[2] = t0;
                t0 = src[4];
                dest[3] = t1;
                t1 = src[5];
                dest[4] = t0;
                t0 = src[6];
                dest[5] = t1;
                t1 = src[7];
                dest[6] = t0;
                t0 = src[8];
                dest[7] = t1;
                t1 = src[9];
                dest[8] = t0;
                t0 = src[10];
                dest[9] = t1;
                t1 = src[11];
                dest[10] = t0;
                t0 = src[12];
                dest[11] = t1;
                t1 = src[13];
                dest[12] = t0;
                t0 = src[14];
                dest[13] = t1;
                t1 = src[15];
                dest[14] = t0;
                t0 = src[16];
                dest[15] = t1;
                t1 = src[17];
                dest[16] = t0;
                t0 = src[18];
                dest[17] = t1;
                t1 = src[19];
                dest[18] = t0;
                t0 = src[20];
                dest[19] = t1;
                t1 = src[21];
                dest[20] = t0;
                t0 = src[22];
                dest[21] = t1;
                t1 = src[23];
                dest[22] = t0;
                t0 = src[24];
                dest[23] = t1;
                t1 = src[25];
                dest[24] = t0;
                t0 = src[26];
                dest[25] = t1;
                t1 = src[27];
                dest[26] = t0;
                t0 = src[28];
                dest[27] = t1;
                t1 = src[29];
                dest[28] = t0;
                t0 = src[30];
                dest[29] = t1;
                t1 = src[31];
                dest[30] = t0;
                t0 = src[32];
                dest[31] = t1;
                t1 = src[33];
                dest[32] = t0;
                t0 = src[34];
                dest[33] = t1;
                t1 = src[35];
                dest[34] = t0;
                t0 = src[36];
                dest[35] = t1;
                t1 = src[37];
                dest[36] = t0;
                t0 = src[38];
                dest[37] = t1;
                t1 = src[39];
                dest[38] = t0;
                t0 = src[40];
                dest[39] = t1;
                t1 = src[41];
                dest[40] = t0;
                t0 = src[42];
                dest[41] = t1;
                t1 = src[43];
                dest[42] = t0;
                t0 = src[44];
                dest[43] = t1;
                t1 = src[45];
                dest[44] = t0;
                t0 = src[46];
                dest[45] = t1;
                t1 = src[47];
                dest[46] = t0;
                t0 = src[48];
                dest[47] = t1;
                t1 = src[49];
                dest[48] = t0;
                t0 = src[50];
                dest[49] = t1;
                t1 = src[51];
                dest[50] = t0;
                t0 = src[52];
                dest[51] = t1;
                t1 = src[53];
                dest[52] = t0;
                t0 = src[54];
                dest[53] = t1;
                t1 = src[55];
                dest[54] = t0;
                t0 = src[56];
                dest[55] = t1;
                t1 = src[57];
                dest[56] = t0;
                t0 = src[58];
                dest[57] = t1;
                t1 = src[59];
                dest[58] = t0;
                t0 = src[60];
                dest[59] = t1;
                t1 = src[61];
                dest[60] = t0;
                t0 = src[62];
                dest[61] = t1;
                t1 = src[63];
                dest[62] = t0;
                t0 = src[64];
                dest[63] = t1;
                t1 = src[65];
                dest[64] = t0;
                t0 = src[66];
                dest[65] = t1;
                t1 = src[67];
                dest[66] = t0;
                t0 = src[68];
                dest[67] = t1;
                t1 = src[69];
                dest[68] = t0;
                t0 = src[70];
                dest[69] = t1;
                t1 = src[71];
                dest[70] = t0;
                t0 = src[72];
                dest[71] = t1;
                t1 = src[73];
                dest[72] = t0;
                t0 = src[74];
                dest[73] = t1;
                t1 = src[75];
                dest[74] = t0;
                t0 = src[76];
                dest[75] = t1;
                t1 = src[77];
                dest[76] = t0;
                t0 = src[78];
                dest[77] = t1;
                t1 = src[79];
                dest[78] = t0;
                t0 = src[80];
                dest[79] = t1;
                t1 = src[81];
                dest[80] = t0;
                t0 = src[82];
                dest[81] = t1;
                t1 = src[83];
                dest[82] = t0;
                t0 = src[84];
                dest[83] = t1;
                t1 = src[85];
                dest[84] = t0;
                t0 = src[86];
                dest[85] = t1;
                t1 = src[87];
                dest[86] = t0;
                t0 = src[88];
                dest[87] = t1;
                t1 = src[89];
                dest[88] = t0;
                t0 = src[90];
                dest[89] = t1;
                t1 = src[91];
                dest[90] = t0;
                t0 = src[92];
                dest[91] = t1;
                t1 = src[93];
                dest[92] = t0;
                t0 = src[94];
                dest[93] = t1;
                t1 = src[95];
                dest[94] = t0;
                dest[95] = t1;
                    i += 8;
                    src += 96;
                    dest += 96;
                } while (--ctr);
            }
        }
        ctr = arg2 - i;
        src = (unsigned int *)arg1 + i * 12;
        dest = (unsigned int *)((char *)lbl_804DAC48 + arg0 * 0x30) + i * 12;
        if (i < arg2) do {
            t0 = src[0];
            t1 = src[1];
            dest[0] = t0;
            t0 = src[2];
            dest[1] = t1;
            t1 = src[3];
            dest[2] = t0;
            t0 = src[4];
            dest[3] = t1;
            t1 = src[5];
            dest[4] = t0;
            t0 = src[6];
            dest[5] = t1;
            t1 = src[7];
            dest[6] = t0;
            t0 = src[8];
            dest[7] = t1;
            t1 = src[9];
            dest[8] = t0;
            t0 = src[10];
            dest[9] = t1;
            t1 = src[11];
            dest[10] = t0;
            dest[11] = t1;
            src += 12; dest += 12;
        } while (--ctr);
    }
}
#pragma pop
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
    int count;
    float value1;
    float value0;
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
    count = 0xB;
    value0 = lbl_80565030;
    value1 = lbl_80565034;
    matrix = lbl_804DAC48;
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

#pragma scheduling on
void *fn_802DA450(void *arg0, int arg1) {
    if (arg0) {
        *(void **)arg0 = lbl_8034C8E8;
        fn_80128670(*(int *)((char *)arg0 + 4));
        if (arg0)
            *(int *)((char *)arg0 + 4) = 0;
        if (arg1 > 0)
            fn_80128668(arg0);
    }
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
void *fn_802DA550(void *arg0, void *arg1, int arg2, void *arg3, void *arg4, int arg5) {
    volatile struct StackAlloc *ctx;
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

    ctx = (volatile struct StackAlloc *)lbl_8055FE5C;
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
/* Allocates a 12-byte-per-element record from the stack allocator arena (type 7). */
void *fn_802DA704(int owner, void *data, int count) {
    volatile unsigned char *state;
    int savedInitialized;
    unsigned char *blockBase;
    int payloadBytes;
    int used;
    int recordSize;
    int roundedSize;
    int alignedSize;
    unsigned int blockOffset;
    int newUsed;
    void *record;

    state = (volatile unsigned char *)lbl_8055FE5C;
    payloadBytes = count * 12;
    savedInitialized = state[0x25];
    state[0x25] = 0;
    recordSize = payloadBytes + 0x18;
    roundedSize = recordSize + 3;
    used = *(volatile int *)(state + 0x10);
    alignedSize = roundedSize & ~3;
    if (alignedSize + used + 8 > *(volatile int *)(state + 0x0C)) {
        int capacity = *(volatile int *)(state + 0x0C);
        fn_802E317C(lbl_80346798, *(volatile int *)(state + 8), recordSize, capacity / 1024);
        record = 0;
    } else {
        blockOffset = *(unsigned int *)(state + 4);
        blockBase = (unsigned char *)*(volatile int *)(state + 0x10);
        blockBase += blockOffset;
        *(int *)blockBase = 1;
        record = blockBase + 4;
        blockOffset = *(unsigned int *)(state + 4);
        used = *(volatile int *)(state + 0x10);
        used = blockOffset + used;
        blockOffset = used + alignedSize;
        *(int *)(blockOffset + 4) = alignedSize;
        newUsed = alignedSize + *(volatile int *)(state + 0x10);
        *(volatile int *)(state + 0x10) = newUsed + 8;
    }
    *(int *)((char *)record + 0) = 7;
    *(int *)((char *)record + 4) = owner;
    *(int *)((char *)record + 8) = count;
    *(int *)((char *)record + 0x0C) = 0;
    *(int *)((char *)record + 0x14) = 0;
    *(unsigned char *)((char *)record + 0x10) = (unsigned char)savedInitialized;
    memcpy((char *)record + 0x18, data, payloadBytes);
    return record;
}
#pragma scheduling on
#pragma use_lmw_stmw reset

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_802DA80C(int owner, void *data, int count) {
    void *record;
    volatile unsigned char *state;
    int savedInitialized;
    unsigned char *blockBase;
    int payloadBytes;
    int used;
    int recordSize;
    int roundedSize;
    int alignedSize;
    unsigned int blockOffset;
    int newUsed;

    state = (volatile unsigned char *)lbl_8055FE5C;
    payloadBytes = count * 0x30;
    savedInitialized = state[0x25];
    state[0x25] = 0;
    recordSize = payloadBytes + 0x18;
    roundedSize = recordSize + 3;
    used = *(volatile int *)(state + 0x10);
    alignedSize = roundedSize & ~3;
    if (alignedSize + used + 8 > *(volatile int *)(state + 0x0C)) {
        int capacity = *(volatile int *)(state + 0x0C);
        fn_802E317C(lbl_80346798, *(volatile int *)(state + 8), recordSize, capacity / 1024);
        record = 0;
    } else {
        blockOffset = *(unsigned int *)(state + 4);
        blockBase = (unsigned char *)*(volatile int *)(state + 0x10);
        blockBase += blockOffset;
        *(int *)blockBase = 1;
        record = blockBase + 4;
        blockOffset = *(unsigned int *)(state + 4);
        used = *(volatile int *)(state + 0x10);
        used = blockOffset + used;
        blockOffset = used + alignedSize;
        *(int *)(blockOffset + 4) = alignedSize;
        newUsed = alignedSize + *(volatile int *)(state + 0x10);
        *(volatile int *)(state + 0x10) = newUsed + 8;
    }
    *(int *)((char *)record + 0) = 7;
    *(int *)((char *)record + 4) = owner;
    *(int *)((char *)record + 8) = count;
    *(int *)((char *)record + 0x0C) = 1;
    *(int *)((char *)record + 0x14) = 0;
    *(unsigned char *)((char *)record + 0x10) = (unsigned char)savedInitialized;
    memcpy((char *)record + 0x18, data, payloadBytes);
    return record;
}
#pragma scheduling on
#pragma use_lmw_stmw reset

extern float lbl_80565030;
extern void fn_802E317C(char *, ...);
extern int memcpy(void *, const void *, unsigned int);
extern char lbl_80346798[];
#pragma scheduling on
void *fn_802DA918(float x0, float x1, float x2) {
    unsigned char saved;
    unsigned char *base;
    int off;
    void *result;
    void *st;
    x2 = lbl_80565030 / (x2 * x2);
    st = lbl_8055FE5C;
    saved = *(volatile unsigned char *)((char *)st + 0x25);
    *(volatile unsigned char *)((char *)st + 0x25) = 0;
    if (*(volatile int *)((char *)st + 0x10) + 0x2c > *(volatile int *)((char *)st + 0x0C)) {
        int lim = *(volatile int *)((char *)st + 0x0C);
        fn_802E317C(lbl_80346798, *(volatile int *)((char *)st + 8), 0x24, lim / 1024);
        result = 0;
    } else {
        off = *(volatile int *)((char *)st + 4);
        base = (unsigned char *)*(volatile int *)((char *)st + 0x10);
        base += off;
        *(int *)base = 1;
        result = base + 4;
        *(int *)((*(volatile int *)((char *)st + 4) + *(volatile int *)((char *)st + 0x10)) + 0x28) = 0x24;
        *(volatile int *)((char *)st + 0x10) += 0x2c;
    }
    *(int *)((char *)result + 0) = 7;
    *(int *)((char *)result + 4) = 1;
    *(int *)((char *)result + 8) = 1;
    *(int *)((char *)result + 0x0C) = 0;
    *(int *)((char *)result + 0x14) = 0;
    *((unsigned char *)result + 0x10) = saved;
    memcpy((char *)result + 0x18, &x0, 0xc);
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
    register void *var_r31 = arg0;
    struct StackAlloc *ctx = (struct StackAlloc *)lbl_8055FE5C;
    struct StackAllocRecord *entry;
    struct StackAllocRecord *var_r29;
    char *format;
    void *name;
    int size;
    lbl_8055FE60 = var_r31;
    if (var_r31 == 0) {
        entry = (struct StackAllocRecord *)ctx->current;
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
                var_r29 = (struct StackAllocRecord *)(ctx->buffer + ctx->used);
                *(int *)var_r29 = (int)var_r31;
                var_r29 = (struct StackAllocRecord *)((unsigned char *)var_r29 + 4);
                *(int *)(ctx->buffer + ctx->used + 0x3DC) = 0x3D8;
                ctx->used += 0x3E0;
            }
            var_r29->kind = 7;
            var_r29->index = 0;
            var_r29->count = 0x50;
            var_r29->elemType = 0;
            var_r29->next = 0;
            var_r29->status = (unsigned char)var_r31;
            memcpy(var_r29->data, sp8, 0x3C0);
            ctx->current = var_r29;
        }
    }
    var_r31 = ctx->current;
    entry = (struct StackAllocRecord *)var_r31;
    if (entry->elemType == 0) {
        ((void (*)(void *, void *, int))ctx->copyVec3)(
            *(void **)((unsigned char *)entry + 4), entry->data, entry->count);
    } else {
        ((void (*)(void *, void *, int))ctx->copyMtx)(
            *(void **)((unsigned char *)entry + 4), entry->data, entry->count);
    }
    var_r29 = (struct StackAllocRecord *)entry->next;
    if (var_r29 != 0) {
        ((void (*)(void *, void *, int))ctx->copyInt)(
            *(void **)var_r29, (unsigned char *)var_r29 + 8, *(int *)((unsigned char *)var_r29 + 4));
    }
    ctx->status = entry->status;
}
#pragma opt_propagation reset
#pragma scheduling on
void fn_802DABA4(float *arg0) {
    float a0 = arg0[0];
    float s1 = lbl_80565038;
    float a1 = arg0[1];
    float s2 = lbl_8056503C;
    float t0 = a0 * s1;
    float a2 = arg0[2];
    float t3 = a0 * s2;
    float t1 = a1 * s1;
    float t2 = a2 * s1;
    float sp[12];
    sp[0] = t0;
    a0 = arg0[3];
    t0 = a0 * s1;
    t3 = a1 * s2;
    a1 = arg0[4];
    t1 = a2 * s2;
    a2 = arg0[5];
    t2 = a1 * s1;
    a0 = a2 * s1;
    sp[1] = t1;
    t1 = a0;
    a0 = arg0[3];
    t2 = a0 * s2;
    t1 = a1 * s2;
    a1 = a2 * s2;
    sp[2] = t2;
    sp[3] = t3;
    sp[4] = t3;
    sp[5] = t1;
    sp[6] = t0;
    sp[7] = t2;
    sp[8] = a0;
    sp[9] = t2;
    sp[10] = t1;
    sp[11] = a1;
    fn_802DAA18(fn_802DA704(0x4C, sp, 4));
}

void fn_802DAC54(void) {
    *((unsigned char *)lbl_8055FE5C + 0x25) = 1;
}

unsigned char fn_802DAC64(void) {
    return *((unsigned char *)lbl_8055FE5C + 0x24);
}
