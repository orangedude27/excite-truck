// mlist — material/model list ("mlist: unhandled priority %d").
// Recovered TU window 0x802CCBC0..0x802CE308+thunk (see docs/attribution_analysis.md).
// Static-init thunk fn_802CE308 (+ .ctors slot 0x802ED5B0) remains in
// auto/text_802CE308_.c pending a promotion pass.
extern void *lbl_8055FCD8;
extern int fn_802CAFC8(int);
extern char lbl_8034BBE0[];
extern float lbl_80564F58;
extern float lbl_80564F5C;
extern int fn_802D0514(int);
extern unsigned char *lbl_8055DFC4;
extern char lbl_804C1480[];
extern void fn_801293C8(void *);
extern void fn_801293DC(void *);
extern void __AXDSPInitCallback_801293D0(void);
extern void *fn_802C86DC(int);
extern int fn_802C94A0(void *, void *, void *, float, float, float, float, float, float);
extern void fn_802C98DC(void *, void *, void *, void *, float, float, float);
extern void fn_802CCBC0();
extern float lbl_8055D0A0;
extern float lbl_8055D0A4;
extern float lbl_8055FCD4;
extern signed char lbl_8055FCDC;
extern float lbl_8055FCE0;
extern float lbl_80564F60;
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
extern float PSVECDotProduct(float *, float *);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_802CCBC4(void *arg0, float *arg1, float arg2, float arg3) {
    struct {
        double copies[2];
        unsigned int words[4];
        float delta[3];
        unsigned int pad;
        float box[4];
    } temp;
    register float dx;
    register float dy;
    register float dz;
    float dot;
    float radius;
    int mask;
    temp.words[0] = *(unsigned int *)((char *)arg0 + 0);
    temp.words[1] = *(unsigned int *)((char *)arg0 + 4);
    temp.words[2] = *(unsigned int *)((char *)arg0 + 8);
    temp.words[3] = *(unsigned int *)((char *)arg0 + 12);
    memcpy(temp.box, temp.words, 0x10);
    dx = arg1[0] - *(float *)((char *)arg0 + 0x10);
    dy = arg1[1] - *(float *)((char *)arg0 + 0x14);
    dz = arg1[2] - *(float *)((char *)arg0 + 0x18);
    temp.delta[0] = dx;
    temp.delta[1] = dy;
    temp.delta[2] = dz;
    dot = PSVECDotProduct(temp.delta, temp.delta);
    radius = arg2 + dot;
    temp.copies[0] = *(double *)temp.box;
    temp.copies[1] = *((double *)temp.box + 1);
    radius = arg3 * radius;
    mask = 0;
    if (((float *)temp.copies)[0] > radius) mask |= 1;
    if (((float *)temp.copies)[0] < -radius) mask |= 2;
    if (((float *)temp.copies)[1] > radius) mask |= 4;
    if (((float *)temp.copies)[1] < -radius) mask |= 8;
    if (((float *)temp.copies)[2] > radius) mask |= 0x10;
    if (((float *)temp.copies)[2] < -radius) mask |= 0x20;
    return ~mask & 0x15;
}
#pragma pop
int fn_802CCD0C(void *arg0, void *arg1) {
    int x = fn_802CAFC8(*(int *)((char *)arg0 + 0x10));
    int y = fn_802CAFC8(*(int *)((char *)arg1 + 0x10));
    if (x != y) {
        return x - y;
    }
    x = fn_802CAFF0(*(int *)((char *)arg0 + 0x10));
    y = fn_802CAFF0(*(int *)((char *)arg1 + 0x10));
    if (x != y) {
        return x - y;
    }
    if (*(int *)((char *)arg0 + 0x10) == -1) {
        return 1;
    }
    if (*(int *)((char *)arg1 + 0x10) == -1) {
        return -1;
    }
    return stricmp((char *)arg0, (char *)arg1);
}

#pragma cplusplus on
extern "C" int fn_802CCDC4(void ***arg0, void ***arg1) {
    struct Local {
        virtual void v0();
        virtual void v1();
        virtual int v2();
    };
    Local *obj1 = (Local *)*arg1;
    int first = ((Local *)*arg0)->v2();
    return first - obj1->v2();
}
#pragma cplusplus reset
extern int fn_802CAC28(void *, int);
extern void fn_802E317C(const char *, ...);
extern void *memset(void *, int, unsigned int);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern char lbl_8034BBC0[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802CCE24(void *arg0) {
    union SwapTemp { unsigned int word[3]; unsigned short half[6]; };
    union SwapTemp saved;

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
        int var_r3;
        register int var_r4;
        int var_r11;
        int temp_r7;
        register unsigned int temp_r29_2;
        unsigned char *temp_r5;
        register unsigned char *temp_r30;
        register unsigned char *var_r12;
        unsigned char *temp_r28;
        register int var_r27_2;
        unsigned int var_ctr;
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
                    other = temp_r30 + back * 0xC;
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

    qsort(*(void **)((char *)arg0 + 0x90), *(unsigned int *)((char *)arg0 + 0x88), 4,
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
        char *group;
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
#pragma pop
extern void fn_802CAC54(int);
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void fn_802CD254(void *list) {
    int index;
    int byteOffset;
    int reset;
    char *entry;
    /* Clear material list entries and destroy referenced objects, then reset the list state. */
    index = 0;
    byteOffset = 0;
    reset = -2;
    while (index < *(int *)((char *)list + 0x30)) {
        entry = *(char **)((char *)list + 0x34) + byteOffset;
        fn_802CAC54(*(int *)(entry + 0x10));
        *(int *)(entry + 0x10) = reset;
        byteOffset += 0x1C;
        index++;
    }
    byteOffset = 0;
    index = 0;
    reset = 0;
    while (byteOffset < *(int *)((char *)list + 0x88)) {
        void **items = *(void ***)((char *)list + 0x90);
        void *obj = *(void **)((char *)items + index);
        if (obj != 0)
            ((Dummy *)obj)->method0(1);
        items = *(void ***)((char *)list + 0x90);
        byteOffset++;
        *(void **)((char *)items + index) = (void *)reset;
        index += 4;
    }
    *(int *)((char *)list + 0x88) = 0;
    *(int *)((char *)list + 8) &= ~2;
}
#pragma cplusplus reset

#pragma push
#pragma scheduling invalid_target
void fn_802CD320(void *arg0, int arg1) {
    unsigned int count;
    int *items;
    count = *(unsigned int *)((char *)arg0 + 0x88);
    items = *(int **)((char *)arg0 + 0x90);
    items[count] = arg1;
    *(unsigned int *)((char *)arg0 + 0x88) = count + 1;
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

void fn_802CD37C(void *arg0, void *arg1, float *arg2, int arg3, float farg0, float farg1) {
    float matrix[12];
    int v;
    int i;
    float *p;
    int *q;
    fn_801293C8(lbl_8034BBE0);
    lbl_8055FCD8 = arg0;
    matrix[0] = lbl_80564F58; matrix[1] = lbl_80564F5C; matrix[2] = lbl_80564F5C; matrix[3] = lbl_80564F5C;
    matrix[4] = lbl_80564F58; matrix[5] = lbl_80564F5C; matrix[6] = lbl_80564F5C; matrix[7] = lbl_80564F5C;
    matrix[8] = lbl_80564F58; matrix[9] = lbl_80564F5C; matrix[10] = lbl_80564F5C; matrix[11] = lbl_80564F5C;
    v = ((int (*)(void *, float))fn_802D0514)(matrix, lbl_80564F58);
    *(int *)((char *)lbl_8055DFC4 + 0x64) = v;
    p = arg2;
    q = (int *)lbl_8055DFC4;
    i = 0;
    while (i < arg3) {
        *(int *)((char *)q + 0x68) = ((int (*)(void *, float))fn_802D0514)(p, lbl_80564F58);
        p += 0x30 / 4;
        q += 1;
        i++;
    }
    if (arg3 < 0x100) {
        int rem = 0x100 - arg3;
        int ctr;
        int *dst = (int *)((char *)lbl_8055DFC4 + arg3 * 4);
        if (rem > 8) {
            ctr = (0xFF - arg3) >> 3;
            if (arg3 < 0xF8) {
                do {
                    *(dst + 0x19) = v; dst[0x1A] = v; dst[0x1B] = v; dst[0x1C] = v; dst[0x1D] = v; dst[0x1E] = v; dst[0x1F] = v; dst[0x20] = v;
                    dst += 8;
                    ctr--;
                } while (ctr != 0);
            }
        }
        ctr = 0x100 - arg3;
        if (arg3 < 0x100) {
            do { *(dst + 0x19) = v; dst++; ctr--; } while (ctr != 0);
        }
    }
    fn_801293DC(lbl_804C1480);
    __AXDSPInitCallback_801293D0();
}

void fn_802CDAA8(void) {
    lbl_8055FCD8 = 0;
}

void fn_802CDAB4(void *arg0, int arg1, void *arg2) {
    unsigned char *base = lbl_8055DFC4;
    *(int *)(base + arg1 * 4 + 0x64) = ((int (*)(void *))fn_802D0514)(arg2);
}

extern unsigned char *lbl_8055DFC4;
extern int fn_802D0514(int);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802CDAFC(void *arg0, int arg1) {
    int a = *(int *)((char *)arg0 + 0x18);
    unsigned b = *(int *)((char *)arg0 + 0x10);
    lbl_8055DFC4[arg1 + a + b + 1] = 0;
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

extern char lbl_8034BBEC[];
extern char lbl_804C1480[];
extern void fn_801293C8(void *);
extern void fn_801293E8(void *);
extern void fn_802D0610(int);
extern void fn_802C8B70(int);
extern void fn_802C8D74(void);
extern int fn_802DB2A8(int);
extern void fn_802DB2B0(int);
extern void fn_802DB2A0(void);
extern void __AXDSPInitCallback_801293D0(void);
extern void fn_802D6B08(void *);
extern void fn_802CC550(int, float, float);
extern float lbl_80564F58;
extern float lbl_80564F5C;
extern float lbl_804C5480[];
void fn_802CDB5C(int arg0) {
    struct Item {
        unsigned short id;
        unsigned short type;
        unsigned short state;
        unsigned short pad;
        void *object;
    };
    struct {
        int context30;
        int context34;
        int context28;
        int context2C;
        struct Item cur;
        int pad;
        int config38;
        int config3C;
        int config40;
        int config44;
        float matrix[12];
    } work;
    char *context;
    unsigned char *table;
    int outerIndex;
    int lastEntry;
    int recordId;
    int started;
    int itemCount;
    struct Item *item;
    int cursor;
    int callbackCount;
    int itemIndex;
    int outerEnd;
    char *itemBase;
    char *record;
    char *config;
    int itemStart;
    int handle;
    int i;
    void *object;
    void **objects;
    int a, b, c, d, e, f, g, h;

    fn_801293C8(&lbl_8034BBEC);
    fn_801293E8(&lbl_804C1480);
    context = (char *)lbl_8055FCD8;
    config = context + arg0 * 0x10;
    a = *(int *)(context + 0x28);
    b = *(int *)(context + 0x2C);
    c = *(int *)(config + 0x38);
    d = *(int *)(config + 0x3C);
    e = *(int *)(config + 0x40);
    f = *(int *)(config + 0x44);
    g = *(int *)(context + 0x30);
    h = *(int *)(context + 0x34);
    table = lbl_8055DFC4;
    work.context28 = a;
    work.context2C = b;
    work.config38 = c;
    work.config3C = d;
    work.config40 = e;
    work.config44 = f;
    work.context30 = g;
    work.context34 = h;
    work.matrix[0] = lbl_80564F58;
    work.matrix[1] = lbl_80564F5C;
    work.matrix[2] = lbl_80564F5C;
    work.matrix[3] = lbl_80564F5C;
    work.matrix[4] = lbl_80564F58;
    work.matrix[5] = lbl_80564F5C;
    work.matrix[6] = lbl_80564F5C;
    work.matrix[7] = lbl_80564F5C;
    work.matrix[8] = lbl_80564F58;
    work.matrix[9] = lbl_80564F5C;
    work.matrix[10] = lbl_80564F5C;
    work.matrix[11] = lbl_80564F5C;

    handle = ((int (*)(float *, int, int, int, int, int, int, int, float))fn_802D0514)(
        work.matrix, work.context30, work.config44, work.config40,
        work.config3C, work.config38, work.context2C, work.context28,
        lbl_80564F58);
    fn_802D0610(handle);
    outerIndex = work.config38;
    itemBase = (char *)work.context2C;
    outerEnd = work.config3C;
    record = (char *)work.context34 + outerIndex * 0x1C;
    *(int *)(table + 0x64) = handle;
    lastEntry = 0;
    for (; outerIndex < outerEnd; outerIndex++, record += 0x1C) {
        itemStart = *(int *)(record + 0x14);
        itemCount = *(int *)(record + 0x18) - itemStart;
        recordId = *(int *)(record + 0x10);
        item = (struct Item *)(itemBase + itemStart * 12);
        started = 0;
        cursor = 0;
        callbackCount = 0;
        for (itemIndex = 0; itemIndex < itemCount; itemIndex++) {
            work.cur = *item++;
            if (work.cur.type != (table[work.cur.id] & 0x7F))
                continue;
            if (started == 0) {
                started = 1;
                fn_802C8B70(recordId);
                cursor = fn_802DB2A8(itemCount * 2);
                if (cursor == 0) {
                    fn_802C8D74();
                    started = 0;
                }
            }
            handle = *(int *)(table + work.cur.state * 4 + 0x64);
            if (lastEntry != handle) {
                lastEntry = handle;
                fn_802D0610(handle);
                cursor += 0x10;
                callbackCount++;
            }
            object = work.cur.object;
            fn_802D6B08(object);
            fn_802CC550(recordId, lbl_804C5480[work.cur.id],
                        *(float *)((char *)object + 8));
            cursor += 0x10;
            callbackCount++;
        }
        if (started != 0) {
            fn_802DB2B0(callbackCount);
            fn_802C8D74();
        }
    }
    fn_802DB2A0();
    __AXDSPInitCallback_801293D0();
    objects = *(void ***)(context + 0x90);
    for (i = work.config40; i < work.config44; i++) {
        object = objects[i];
        ((void (*)(void *, void *))(((void **)(*(void **)object))[5]))(object, context);
    }
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
    volatile unsigned char *base = (volatile unsigned char *)arg0;
    volatile unsigned char *rec;
    unsigned char t;
    unsigned char tmp[12];
    int i;
    int index;
    int offset;
    tmp[0] = base[0]; tmp[1] = base[3]; tmp[2] = base[1]; tmp[3] = base[2];
    tmp[4] = base[4]; tmp[5] = base[7]; tmp[6] = base[5]; tmp[7] = base[6];
    tmp[8] = base[8]; tmp[9] = base[0xB]; tmp[10] = base[9]; tmp[11] = base[0xA];
    base[0] = tmp[1]; base[3] = tmp[0]; base[1] = tmp[3]; base[2] = tmp[2];
    base[4] = tmp[5]; base[7] = tmp[4]; base[5] = tmp[7]; base[6] = tmp[6];
    base[8] = tmp[9]; base[0xB] = tmp[8]; base[9] = tmp[11]; base[0xA] = tmp[10];
    t = base[0x10]; base[0x10] = base[0x13]; base[0x13] = t;
    t = base[0x11]; base[0x11] = base[0x12]; base[0x12] = t;
    t = base[0x14]; base[0x14] = base[0x17]; base[0x17] = t;
    t = base[0x15]; base[0x15] = base[0x16]; base[0x16] = t;
    t = base[0x18]; base[0x18] = base[0x1b]; base[0x1b] = t;
    t = base[0x19]; base[0x19] = base[0x1a]; base[0x1a] = t;
    t = base[0x1c]; base[0x1c] = base[0x1f]; base[0x1f] = t;
    t = base[0x1d]; base[0x1d] = base[0x1e]; base[0x1e] = t;
    t = base[0x20]; base[0x20] = base[0x23]; base[0x23] = t;
    t = base[0x21]; base[0x21] = base[0x22]; base[0x22] = t;
    t = base[0x24]; base[0x24] = base[0x27]; base[0x27] = t;
    t = base[0x25]; base[0x25] = base[0x26]; base[0x26] = t;
    t = base[0x28]; base[0x28] = base[0x2b]; base[0x2b] = t;
    t = base[0x29]; base[0x29] = base[0x2a]; base[0x2a] = t;
    t = base[0x2c]; base[0x2c] = base[0x2f]; base[0x2f] = t;
    t = base[0x2d]; base[0x2d] = base[0x2e]; base[0x2e] = t;
    t = base[0x30]; base[0x30] = base[0x33]; base[0x33] = t;
    t = base[0x31]; base[0x31] = base[0x32]; base[0x32] = t;
    t = base[0x34]; base[0x34] = base[0x37]; base[0x37] = t;
    t = base[0x35]; base[0x35] = base[0x36]; base[0x36] = t;
    rec = base + 0x38;
    for (i = 4; i != 0; --i) {
        t = rec[0x0]; rec[0x0] = rec[0x3]; rec[0x3] = t;
        t = rec[0x1]; rec[0x1] = rec[0x2]; rec[0x2] = t;
        t = rec[0x4]; rec[0x4] = rec[0x7]; rec[0x7] = t;
        t = rec[0x5]; rec[0x5] = rec[0x6]; rec[0x6] = t;
        t = rec[0x8]; rec[0x8] = rec[0xb]; rec[0xb] = t;
        t = rec[0x9]; rec[0x9] = rec[0xa]; rec[0xa] = t;
        t = rec[0xc]; rec[0xc] = rec[0xf]; rec[0xf] = t;
        t = rec[0xd]; rec[0xd] = rec[0xe]; rec[0xe] = t;
        t = rec[0x10]; rec[0x10] = rec[0x13]; rec[0x13] = t;
        t = rec[0x11]; rec[0x11] = rec[0x12]; rec[0x12] = t;
        rec += 0x14;
    }
    t = base[0x88]; base[0x88] = base[0x8b]; base[0x8b] = t;
    t = base[0x89]; base[0x89] = base[0x8a]; base[0x8a] = t;
    t = base[0x8c]; base[0x8c] = base[0x8f]; base[0x8f] = t;
    t = base[0x8d]; base[0x8d] = base[0x8e]; base[0x8e] = t;
    t = base[0x90]; base[0x90] = base[0x93]; base[0x93] = t;
    t = base[0x91]; base[0x91] = base[0x92]; base[0x92] = t;
    fn_802CE260((int *)(base + 0x14), arg1);
    fn_802CE278((int *)(base + 0x1C), arg1);
    fn_802CE290((int *)(base + 0x24), arg1);
    fn_802CE2A8((int *)(base + 0x2C), arg1);
    index = 0; offset = 0;
    while (index < *(volatile int *)(base + 0x28)) {
        rec = *(volatile unsigned char **)(base + 0x2C) + offset;
        t = rec[0x0]; rec[0x0] = rec[0x1]; rec[0x1] = t;
        t = rec[0x2]; rec[0x2] = rec[0x3]; rec[0x3] = t;
        t = rec[0x4]; rec[0x4] = rec[0x5]; rec[0x5] = t;
        t = rec[0x6]; rec[0x6] = rec[0x7]; rec[0x7] = t;
        t = rec[0x8]; rec[0x8] = rec[0xb]; rec[0xb] = t;
        t = rec[0x9]; rec[0x9] = rec[0xa]; rec[0xa] = t;
        fn_802CE2C0((int *)(rec + 8), arg1);
        offset += 0xC; index++;
    }
    fn_802CE2D8((int *)(base + 0x34), arg1);
    index = 0; offset = 0;
    while (index < *(volatile int *)(base + 0x30)) {
        rec = *(volatile unsigned char **)(base + 0x34) + offset;
        t = rec[0x14]; rec[0x14] = rec[0x17]; rec[0x17] = t;
        t = rec[0x15]; rec[0x15] = rec[0x16]; rec[0x16] = t;
        t = rec[0x18]; rec[0x18] = rec[0x1b]; rec[0x1b] = t;
        t = rec[0x19]; rec[0x19] = rec[0x1a]; rec[0x1a] = t;
        *(volatile int *)(rec + 0x10) = -2;
        offset += 0x1C; index++;
    }
    fn_802CE2F0((int *)(base + 0x90), arg1);
    index = 0; offset = 0;
    while (index < *(volatile int *)(base + 0x88)) {
        rec = *(volatile unsigned char **)(base + 0x90) + offset;
        t = rec[0x0]; rec[0x0] = rec[0x3]; rec[0x3] = t;
        t = rec[0x1]; rec[0x1] = rec[0x2]; rec[0x2] = t;
        offset += 4; index++;
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

