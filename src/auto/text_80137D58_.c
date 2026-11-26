// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

/* The "IdealLineRes" resource (magic 'ILIN', the "ideal:"/"idealres:" messages)
 * keeps a singly-linked list of typed extension records, first at +0x24.
 * fn_80138144 endian-swaps one record by type; fn_80138594, fn_80138B1C and
 * fn_80138B4C look records of a given type up in that list. */
struct IdealResExt {
    unsigned int type;         /* +0x00 enum IdealResExtType */
    struct IdealResExt *next;  /* +0x04 next record, 0 at the end of the list */
};

enum IdealResExtType {
    /* two words at +0x08/+0x0C; the float at +0x0C is a base timing
     * (fn_8013B590) -- fn_80137F30 swaps them */
    IDEAL_EXT_TIMING = 0,
    IDEAL_EXT_POINT = 1,        /* vec3 at +0x08 -- fn_80137F74 */
    IDEAL_EXT_ROAD_OBJECTS = 2, /* int count at +0x08, float spacing at +0x10,
                                 * count 8-byte {s16 item; s16 radius; s32 path
                                 * index} records at +0x14 -- fn_80137FF0 */
    IDEAL_EXT_MATRIX = 3        /* int size at +0x08, size*size words at +0x0C
                                 * -- fn_801380DC */
};

#define IDEAL_RES_EXT_LIST 0x24  /* IdealLineRes: first extension record */

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
/* Reorders the bytes of one node of the 0x38-byte structure loaded by fn_801381B4:
 * first the four bytes of each 32-bit word are reversed (0x00..0x2F), then the
 * 0x10..0x33 region is byte-swapped with its mirrored counterpart in a fixed
 * pattern (0x10<->0x29, 0x11<->0x2C, ... 0x28<->0x2B). */
extern "C" void fn_80137D58(void *arg0, int arg_sp0) {
    volatile int sp18, sp14, sp10, spC, sp8;
    volatile unsigned char *p = (volatile unsigned char *)arg0;
    register unsigned int temp_r0, temp_r0_2, temp_r0_4, temp_r0_5, temp_r0_3;
    register unsigned int swap_t;
    register unsigned int temp_r14 asm("r14"), temp_r4 asm("r4"), temp_r5 asm("r5"), temp_r6 asm("r6"), temp_r7 asm("r7"), temp_r8 asm("r8"), temp_r9 asm("r9"), temp_r10 asm("r10"), temp_r11 asm("r11"), temp_r12 asm("r12"), temp_r31 asm("r31"), temp_r30 asm("r30"), temp_r29 asm("r29"), temp_r28 asm("r28"), temp_r27 asm("r27"), temp_r26 asm("r26"), temp_r25 asm("r25"), temp_r24 asm("r24"), temp_r23 asm("r23"), temp_r22 asm("r22"), temp_r21 asm("r21"), temp_r20 asm("r20"), temp_r19 asm("r19"), temp_r18 asm("r18"), temp_r17 asm("r17"), temp_r16 asm("r16"), temp_r15 asm("r15");
    swap_t=p[0]; p[0]=p[3]; p[3]=swap_t;
    swap_t=p[1]; p[1]=p[2]; p[2]=swap_t;
    swap_t=p[4]; p[4]=p[7]; p[7]=swap_t;
    swap_t=p[5]; p[5]=p[6]; p[6]=swap_t;
    swap_t=p[8]; p[8]=p[11]; p[11]=swap_t;
    swap_t=p[9]; p[9]=p[10]; p[10]=swap_t;
    swap_t=p[12]; p[12]=p[15]; p[15]=swap_t;
    swap_t=p[13]; p[13]=p[14]; p[14]=swap_t;
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
    temp_r14=sp14;
    temp_r28=p[0x1c]; temp_r9=p[0x1f]; temp_r20=p[0x1d]; temp_r8=p[0x1e];
    temp_r27=p[0x20]; temp_r7=p[0x23]; temp_r19=p[0x21]; temp_r6=p[0x22];
    temp_r26=p[0x24]; temp_r5=p[0x27]; temp_r18=p[0x25]; temp_r4=p[0x26];
    temp_r25=p[0x28]; temp_r0_5=p[0x2b];
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
    p[0x28]=temp_r0_5; p[0x2b]=temp_r25;
    p[0x2a]=temp_r17; p[0x2f]=temp_r24;
    p[0x2e]=temp_r16; p[0x33]=temp_r23;
    p[0x31]=temp_r14; p[0x32]=temp_r15;
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
/* No-op stub: the original function has an empty body (its target is a bare `blr`),
 * but callers such as fn_80138434 still tail-call it. */
void fn_80137F2C(void) {

}

#pragma dont_inline on
/* Byte-swaps the two 32-bit fields at offsets 0x08 and 0x0C of an IDEAL_EXT_TIMING record. */
void fn_80137F30(void *arg0) {
    unsigned char *base = (unsigned char *)arg0;
    unsigned char byte8;
    unsigned char byteC;
    unsigned char byte9;
    unsigned char byteD;
    byte8 = base[8];
    byte9 = base[9];
    byteC = base[0xc];
    byteD = base[0xd];
    base[8] = base[0xb];
    base[0xb] = byte8;
    base[9] = base[0xa];
    base[0xa] = byte9;
    base[0xc] = base[0xf];
    base[0xf] = byteC;
    base[0xd] = base[0xe];
    base[0xe] = byteD;
}
#pragma dont_inline reset

void fn_80137F74(void *data) {
    /* Byte-swaps three consecutive 32-bit words (12 bytes) in place. */
    unsigned char byte0;
    unsigned char byte4;
    unsigned char byte8;
    unsigned char byte1;
    unsigned char byte5;
    unsigned char byte9;
    byte0 = ((unsigned char *)data)[0];
    byte1 = ((unsigned char *)data)[1];
    byte4 = ((unsigned char *)data)[4];
    byte5 = ((unsigned char *)data)[5];
    byte8 = ((unsigned char *)data)[8];
    byte9 = ((unsigned char *)data)[9];
    ((unsigned char *)data)[0] = ((unsigned char *)data)[3];
    ((unsigned char *)data)[3] = byte0;
    ((unsigned char *)data)[1] = ((unsigned char *)data)[2];
    ((unsigned char *)data)[2] = byte1;
    ((unsigned char *)data)[4] = ((unsigned char *)data)[7];
    ((unsigned char *)data)[7] = byte4;
    ((unsigned char *)data)[5] = ((unsigned char *)data)[6];
    ((unsigned char *)data)[6] = byte5;
    ((unsigned char *)data)[8] = ((unsigned char *)data)[0xb];
    ((unsigned char *)data)[0xb] = byte8;
    ((unsigned char *)data)[9] = ((unsigned char *)data)[0xa];
    ((unsigned char *)data)[0xa] = byte9;
}

/* Byte-swaps a 6-byte header region at +0x8..+0x13 and then swaps 8-byte records at +0x14 (count from *(int*)(base+8)). */
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
    while (i < *(int *)(base + 8)) {
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
    }
}

void fn_801380DC(void *extRecord) {
    /* idealres ext type 3 (square-matrix extension): byte-swap the record in
       place.  The 32-bit side length at +0x8 is swapped first (so the loop
       bound is read in this machine's byte order), then each of the
       size*size 32-bit entries of the matrix at +0xC is swapped. */
    struct IdealResMatrixExt {
        unsigned int type;    /* +0x00 extension type, swapped by the caller */
        unsigned int field_4; /* +0x04 */
        int size;             /* +0x08 matrix side length, swapped just below */
        unsigned int values;  /* +0x0C size*size 32-bit entries follow it */
    };
    struct IdealResMatrixExt *matrix = (struct IdealResMatrixExt *)extRecord;
    unsigned char *record = (unsigned char *)extRecord;
    unsigned char t0 = record[8];
    unsigned char *entry = record + 0xC;
    unsigned char t1 = record[9];
    int i;
    unsigned char t2;
    record[8] = record[11];
    record[11] = t0;
    record[9] = record[10];
    record[10] = t1;
    for (i = 0; i < matrix->size * matrix->size; i++) {
        t0 = entry[0];
        t2 = entry[3];
        entry[0] = t2;
        entry[3] = t0;
        t0 = entry[1];
        t2 = entry[2];
        entry[1] = t2;
        entry[2] = t0;
        entry += 4;
    }
}

void fn_80137F30(void *);
void fn_80137F74(void *);
void fn_80137FF0(void *);
void fn_801380DC(void *);
extern char lbl_8032BF00[];
void Abend_Panic(char *, ...);
#pragma dont_inline fn_80137F30
#pragma dont_inline fn_80137F74
#pragma dont_inline fn_80137FF0
#pragma dont_inline fn_801380DC
void fn_80138144(void *arg0) {
    /* Byte-swap the 4-byte type field at the start of an "idealres" record,
       then dispatch to the type-specific endian-fix routine; panic on an
       unhandled ext type. */
    unsigned char byte0 = *((unsigned char *)arg0);
    unsigned char byte1 = *((unsigned char *)arg0 + 1);
    *((unsigned char *)arg0) = *((unsigned char *)arg0 + 3);
    *((unsigned char *)arg0 + 3) = byte0;
    *((unsigned char *)arg0 + 1) = *((unsigned char *)arg0 + 2);
    *((unsigned char *)arg0 + 2) = byte1;
    {
        int type = *(int *)arg0;
        switch (type) {
        case 0: ((void (*)(void *, int))fn_80137F30)(arg0, type); break;
        case 1: ((void (*)(void *, int))fn_80137F74)((char *)arg0 + 8, type); break;
        case 2: ((void (*)(void *, int))fn_80137FF0)(arg0, type); break;
        case 3: ((void (*)(void *, int))fn_801380DC)(arg0, type); break;
        default: Abend_Panic(lbl_8032BF00); break;
        }
    }
}

extern void fn_80138434();
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma ppc_psq_save off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma scheduling invalid_target
void fn_801381B4(void *arg0) {
    volatile unsigned char *v = (volatile unsigned char *)arg0;
    unsigned char *base = (unsigned char *)arg0;
    unsigned char *p = base + 0x30;
    unsigned char *r;
    unsigned char *node;
    unsigned char t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
    int i0 = 0, i1, mode, found;
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
    for (; i0 < *(int *)(base + 0x2c); i0++) {
        t0 = p[0]; t1 = p[3]; p[0] = t1; p[3] = t0;
        t0 = p[1]; t1 = p[2]; p[1] = t1; p[2] = t0;
        p += 4;
    }
    r = ((unsigned char *)arg0);
    for (i1 = 0; i1 < *(int *)(base + 0x2c); i1++) {
        unsigned char *t = base + *(int *)(r + 0x30);
        r += 4;
        t0 = t[0]; t1 = t[3]; t[0] = t1; t[3] = t0;
        t0 = t[1]; t1 = t[2]; t[1] = t1; t[2] = t0;
        *(int *)t = *(int *)t + (int)base;
    }
    fn_80138434(base + 0x1C);
    fn_80138434(base + 0x20);
    fn_80137D58(*(void **)(base + 0x1C), (int)base);
    for (mode = 0; mode < 3; mode++) {
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
    }
    node = *(unsigned char **)(base + 0x20);
    if (node != 0) {
        while (node[0x34] == 3) {
            fn_80137D58(node, (int)base);
            node = *(unsigned char **)(node + 0x14);
        }
    }
    node = *(unsigned char **)(p - 0xC);
    while (node != 0) {
        fn_80138144(node);
        node = *(unsigned char **)(node + 4);
    }
}
#pragma scheduling on
#pragma opt_common_subs on
#pragma opt_loop_invariants on
#pragma ppc_psq_save on
#pragma pop

#pragma dont_inline on
/* Node in a line's circular list: +0x10 is the index/priority, +0x14 the next link. */
struct LineNode {
    char pad0[0x10];
    int index;                 /* +0x10 */
    struct LineNode *next;     /* +0x14 */
    char pad18[0x14];
    float metric;              /* +0x2C */
};

/* No-op endian-swap wrapper: called on the ideal-line pointer fields at +0x1C
 * and +0x20 during resource byte-swapping, it only tail-calls the empty
 * fn_80137F2C, leaving the pointer unchanged. */
void fn_80138434(void) {
    fn_80137F2C();
}
#pragma dont_inline reset
/* A node in the circular line-node ring.  fn_80138438/fn_8013846C scan the
   ring (terminated when next wraps back to the starting node) for the
   greatest/least path index at +0x10. */
struct IndexedLineNode {
    char pad[0x10];
    unsigned int index;             /* +0x10 path index */
    struct IndexedLineNode *next;   /* +0x14 next node in the ring */
};

void *fn_80138438(void *arg0) {
    struct LineNode *node;
    struct LineNode *best;

    /* Return the node with the highest index/priority in the circular list. */
    node = ((struct LineNode *)arg0)->next;
    best = (struct LineNode *)arg0;
    while (node != (struct LineNode *)arg0) {
        if ((unsigned int)node->index > (unsigned int)best->index) {
            best = node;
        }
        node = node->next;
    }
    return best;
}

void *fn_8013846C(void *arg0) {
    /* Return the node with the smallest path index in the circular line-node
       ring, using arg0 as the sentinel that ends the scan. */
    struct IndexedLineNode *node;
    struct IndexedLineNode *best;

    node = ((struct IndexedLineNode *)arg0)->next;
    best = (struct IndexedLineNode *)arg0;
    while (node != arg0) {
        if (node->index < best->index) {
            best = node;
        }
        node = node->next;
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
    /* Recompute index (+0x10) and metric (+0x2C) for every node in the line's
       circular node list (+0x1C), zero the lowest node's index, propagate a
       running maximum over the list, then release the scratch work buffer. */
    struct LineNode {
        char pad0[0x10];
        int index;                 /* +0x10 */
        struct LineNode *next;     /* +0x14 */
        char pad18[0x14];
        float metric;              /* +0x2C */
    };
    char work[0x70];
    int value;
    int runningMax;
    void *node;
    void *head;

    fn_80135DC4(work, 1, arg1);
    head = *(void **)((char *)arg0 + 0x1C);
    fn_80135F64(work, head, (char *)head + 8, 0, 0);
    node = *(void **)((char *)arg0 + 0x1C);
    do {
        fn_80136068(work, node, 0);
        ((struct LineNode *)node)->metric = *(float *)(work + 0x40);
        ((struct LineNode *)node)->index = *(int *)((char *)*(void **)(work + 4) + 0x10);
        node = ((struct LineNode *)node)->next;
    } while (node != *(void **)((char *)arg0 + 0x1C));
    node = fn_80138438(node);
    head = fn_8013846C(node);
    ((struct LineNode *)head)->index = 0;
    node = head;
    runningMax = 0;
    do {
        value = ((struct LineNode *)node)->index;
        if (runningMax > value) {
            value = runningMax;
        }
        ((struct LineNode *)node)->index = value;
        runningMax = value;
        node = ((struct LineNode *)node)->next;
    } while (node != head);
    if (*(void **)(work + 0x50) != 0) fn_80128670(*(void **)(work + 0x50));
    *(void **)(work + 0x50) = 0;
    fn_8013530C(work, 0);
}
#pragma dont_inline reset
#pragma scheduling on
void fn_801384A0();
int fn_801386D0(void *, float, float, float);
void fn_80138958(void *, float *);
#pragma dont_inline fn_80138594
#pragma dont_inline fn_801385F0
void fn_80138594(void *object) {
    /* Walk the object's entry list at +0x24; for each type-1 entry, apply its vec3 at +0x8 via fn_80138958. */
    void *entry;

    entry = *(void **)((char *)object + 0x24);
    while (entry != 0) {
        if (*(unsigned int *)entry == 1) {
            fn_80138958(object, (float *)((char *)entry + 8));
        }
        entry = *(void **)((char *)entry + 4);
    }
}

extern float lbl_80561398, lbl_8056139C, lbl_805613A0, lbl_805613A4, lbl_805613A8, lbl_805613AC;
extern float __fabsf(float);
extern double __fabs(double);
/* Compute a wrapped smoothstep-like falloff weight from a center over a radius. */
float fn_801385F0(float position, float period, float center, float radius) {
    float delta = position - center;
    float weight;
    if ((float)__fabs((double)delta) > period * lbl_80561398) {
        float adjust = delta > lbl_805613A4 ? lbl_8056139C : lbl_805613A0;
        delta -= period * adjust;
    }
    period = lbl_8056139C;
    weight = period - (float)__fabs((double)delta) / radius;
    period = (period < weight) ? period : weight;
    period = (period > lbl_805613A4) ? period : lbl_805613A4;
    if (period < lbl_805613A0) return lbl_805613A0;
    if (period > lbl_8056139C) return lbl_8056139C;
    if (period > lbl_805613A4) {
        weight = lbl_805613A8 * period;
        delta = lbl_805613AC * period;
        weight *= period;
        delta *= period;
        weight = period * weight;
        return weight + delta;
    }
    weight = lbl_805613A8 * period;
    delta = lbl_805613AC * period;
    weight *= period;
    delta *= period;
    weight = period * weight;
    return weight - delta;
}

extern float lbl_805613B0, lbl_805613B4;
extern double fn_8002F234(double);
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
int fn_801386D0(void *arg0, float farg0, float farg1, float farg2)
{
  struct Vec2
  {
    float x;
    float y;
  } new_var[3];
  char *ctx = (char *) arg0;
  char *n;
  int hit = 0;
  char *a;
  char *b;
  char *nx;
  float step;
  float f25;
  float f24b;
  float f24;
  float d;
  float len;
  float inv;
  f25 = 0.0f;
  do
  {
    step = farg0 - f25;
    step = (step < 0.02f) ? (step) : (0.02f);
    a = *((char **) (ctx + 0x1C));
    f24 = *((float *) (ctx + 8));
    n = *((char **) (a + 0x14));
    do
    {
      float v = fn_801385F0(*((float *) (n + 0x1C)), f24, farg1, farg2);
      if (v > 0.0f)
      {
        new_var[1].y = ((*((float *) (n + 0xC))) - (*((float *) (a + 0xC)))) * 0.5f + (*((float *) (a + 0xC)));
        new_var[1].x = ((*((float *) (n + 8))) - (*((float *) (a + 8)))) * 0.5f + (*((float *) (a + 8)));
        *((float *) (n + 0x2C)) += v * step;
        *((double *) (&new_var[2])) = *((double *) (&new_var[1]));
        {
          float oldx = new_var[2].x;
          new_var[2].x = new_var[2].y;
          new_var[2].y = -oldx;
          *((float *) n) += new_var[2].x * (v * step);
          *((float *) (n + 4)) += new_var[2].y * (v * step);
        }
      }
      b = *((char **) (ctx + 0x1C));
      a = n;
      n = *((char **) (n + 0x14));
    }
    while (a != b);
    f24b = 0.0f;
    do
    {
      nx = *((char **) (b + 0x14));
      *((float *) (b + 8)) = (*((float *) nx)) - (*((float *) b));
      d = (*((float *) (nx + 4))) - (*((float *) (b + 4)));
      *((float *) (b + 0xC)) = d;
      len = (float) fn_8002F234((double) (((*((float *) (b + 8))) * (*((float *) (b + 8)))) + (d * d)));
      if (0.01f > len)
      {
        len = 0.01f;
      }
      inv = 1.0f / len;
      *((float *) (b + 8)) *= inv;
      *((float *) (b + 0xC)) *= inv;
      *((float *) (b + 0x1C)) = f24b;
      nx = *((char **) (b + 0x14));
      {
        float px;
        float py;
        py = (*((float *) (b + 4))) - (*((float *) (nx + 4)));
        px = (*((float *) b)) - (*((float *) nx));
        new_var[0].y = py;
        new_var[0].x = px;
        *((float *) (b + 0x18)) = (float) fn_8002F234((double) ((px * px) + (py * py)));
      }
      if ((*((float *) (b + 0x18))) < 0.5f)
      {
        hit = 1;
      }
      len = *((float *) (b + 0x18));
      b = *((char **) (b + 0x14));
      f24b += len;
    }
    while ((b != (*((char **) (ctx + 0x1C)))) && (hit == 0));
    f25 += step;
  }
  while ((f25 < farg0) && (hit == 0));
  return hit == 0;
}
#pragma pop

extern float lbl_805613A4;
int fn_801388F4(void *arg0) {
    struct V { float x; float y; } v;
    void *p;
    float t;
    float prod1, prod2, sum;
    register int result;
    v = *(struct V *)((char *)arg0 + 8);
    p = *(void **)((char *)arg0 + 0x14);
    t = (float)(-(double)v.x);
    prod2 = t * *(float *)((char *)p + 0xC);
    prod1 = v.y * *(float *)((char *)p + 8);
    v.x = v.y;
    v.y = t;
    sum = prod1 + prod2;
    result = 0;
    if (sum < lbl_805613A4) result = 1;
    return result;
}

/* Forwards an object and the three components of a vec3 (an IDEAL_EXT_POINT's
 * data at +0x8) to fn_801386D0, which applies them to the object's line nodes. */
void fn_80138958(void *object, float *vec) { fn_801386D0(object, vec[0], vec[1], vec[2]); }

/* The two 32-bit words at the start of an IdealLineRes ('ILIN') resource.
 * They are byte-swapped in place when the resource came from a big-endian
 * file; the loader accepts ilsegSize 0x3C and resSize 0x30. */
typedef struct IdealLineHeader {
    unsigned int resSize;    /* +0x00, expected IDEAL_RES_RES_SIZE */
    unsigned int ilsegSize;  /* +0x04, expected IDEAL_RES_ILSEG_SIZE */
} IdealLineHeader;

/* Scratch area filled in by the resource manager while loading an IdealLineRes. */
typedef struct IdealResLoadInfo {
    unsigned char firstLoad;   /* +0x00 set on the first load of the resource */
    unsigned char swapEndian;  /* +0x01 set when the loaded bytes must be swapped */
    unsigned char pad[2];
    IdealLineHeader header;    /* +0x04 parsed (and possibly swapped) header words */
    int valid;                 /* +0x0C non-zero if the load succeeded */
    unsigned int version;      /* +0x10 resource version, expected IDEAL_RES_VERSION */
} IdealResLoadInfo;

#define IDEAL_RES_TAG 0x494C494E    /* 'ILIN' */
#define IDEAL_RES_VERSION 0x1E
#define IDEAL_RES_ILSEG_SIZE 0x3C
#define IDEAL_RES_RES_SIZE 0x30

#define sIdealSizeMismatchMsg lbl_8032BF20
#define sIdealBadVersionMsg lbl_8032BF70

extern void *getResourceData(int, int, unsigned int *, int *, void **, unsigned char *);
extern void fn_8012C4D8(void *);
extern void fn_801381B4(void *);
extern void fn_80138594(void *);
extern int fn_8013BFE8(int);
extern void fn_802E30C8(char *, ...);
extern char lbl_8032BF20[];
extern char lbl_8032BF70[];
#pragma dont_inline on
/* RealName: LoadIdealLineRes */
/* Load and validate the IdealLineRes ('ILIN') resource named `resourceName`:
 * check its version and header words, byte-swap it in place when needed, file
 * its name in the object cache and store the resulting handle at +0x28.
 * On any failed check the resource is released and 0 is returned. */
void *fn_80138968(int resourceName) {
    IdealResLoadInfo info;
    void *res;
    int accepted;

    res = getResourceData(resourceName, IDEAL_RES_TAG, &info.version, &info.valid, (void **)&info.firstLoad, &info.swapEndian);
    if (res != 0) {
        accepted = 0;
        if (info.valid != 0) {
            if (info.version == IDEAL_RES_VERSION) {
                unsigned int ilsegSize = ((volatile unsigned int *)res)[1];
                unsigned int resSize = ((volatile unsigned int *)res)[0];
                info.header.ilsegSize = ilsegSize;
                info.header.resSize = resSize;
                if (info.swapEndian) {
                    unsigned char *p = (unsigned char *)&info.header.ilsegSize;
                    unsigned char *q = (unsigned char *)&info.header.resSize;
                    unsigned char waTmp0, wbTmp0, waTmp1, wbTmp1;
                    waTmp0 = p[0]; p[0] = p[3]; p[3] = waTmp0;
                    waTmp1 = p[1]; p[1] = p[2]; p[2] = waTmp1;
                    wbTmp0 = q[0]; q[0] = q[3]; q[3] = wbTmp0;
                    wbTmp1 = q[1]; q[1] = q[2]; q[2] = wbTmp1;
                }
                if (info.header.ilsegSize == IDEAL_RES_ILSEG_SIZE && info.header.resSize == IDEAL_RES_RES_SIZE) {
                    if (info.swapEndian) {
                        fn_801381B4(res);
                        fn_80138594(res);
                    }
                    *(int *)((char *)res + 0x28) = fn_8013BFE8(resourceName);
                    accepted = 1;
                } else {
                    fn_802E30C8(sIdealSizeMismatchMsg, info.header.ilsegSize, IDEAL_RES_ILSEG_SIZE, info.header.resSize, IDEAL_RES_RES_SIZE, info.swapEndian);
                }
            } else {
                fn_802E30C8(sIdealBadVersionMsg, info.version, IDEAL_RES_VERSION);
            }
        }
        if (!accepted) {
            fn_8012C4D8(res);
            res = 0;
        }
    }
    return res;
}
#pragma dont_inline reset

/* RealName: ReleaseCachedObjectRef_80138AD8 */
void fn_80138AD8(void **objectSlot) {
    /* Release one reference to a cached object, free it, and clear the slot. */
    void *object = *objectSlot;
    CacheTable_releaseResource(*(int *)((char *)object + 0x28), object);
    fn_8012C4D8(*objectSlot);
    *objectSlot = 0;
}

/* Find the first IDEAL_EXT_TIMING extension record in the racing-line resource's list. */
void *fn_80138B1C(void *res) {
    struct IdealResExt *ext = *(struct IdealResExt **)((char *)res + IDEAL_RES_EXT_LIST);
    void *result = 0;
    while (ext) {
        if (ext->type == IDEAL_EXT_TIMING) {
            result = ext;
            break;
        }
        ext = ext->next;
    }
    return result;
}

/* First road-object extension record (type 2) of the racing-line resource
 * `res`, or the next one after the record `prev` -- pass 0 to start at the
 * resource's own extension list.  Callers walk every one of them with
 * `for (ext = fn_80138B4C(res, 0); ext; ext = fn_80138B4C(res, ext))`.
 * Returns 0 when the list runs out. */
void *fn_80138B4C(void *res, void *prev) {
    struct IdealResExt *result;
    struct IdealResExt *ext;
    ext = prev != 0 ? ((struct IdealResExt *)prev)->next : 0;
    result = 0;
    ext = ext != 0 ? ext : *(struct IdealResExt **)((char *)res + IDEAL_RES_EXT_LIST);
    while (ext != 0) {
        if (ext->type == IDEAL_EXT_ROAD_OBJECTS) {
            result = ext;
            break;
        }
        ext = ext->next;
    }
    return result;
}

void fn_80138BA0(void *resource, void *token) {
    /* Recompute the line node layout (fn_801384A0) only when the two values differ;
       both are forwarded unchanged in registers to that tail call. */
    if (resource != token) {
        fn_801384A0();
    }
}

