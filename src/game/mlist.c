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
// Shared draw context: per-object type/visibility flags at +0x00, draw-entry handles at +0x64.
#define gDrawContext lbl_8055DFC4
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
/* Intentionally empty no-op; placeholder diagnostic hook in the mlist draw path (invoked through a 12-argument function-pointer cast). */
void fn_802CCBC0(void) {}

extern void *memcpy(void *, const void *, unsigned int);
extern float PSVECDotProduct(float *, float *);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
/* Visibility test for one 0x20-byte mlist entry 'entry': build a radius from the two
   tuning factors baseRadius/radiusScale and the squared distance from the viewer point
   'view' to the entry's centre at +0x10, then test the entry's first three floats against
   +-radius. Returns a 3-bit mask (bits 0, 2, 4) of bounds that lie inside the radius. */
/* Visibility test for a 0x20-byte mlist entry: build a cull radius from the tuning factors and the squared viewer-to-centre distance, flag each box extent that falls outside +/-radius, and return a 3-bit mask of the axes still inside. */ int fn_802CCBC4(void *__restrict entry, float *view, float baseRadius, float radiusScale) {
    struct {
        double copies[2];
        unsigned int words[4];
        float delta[3];
        unsigned int pad;
        float box[4];
    } scratch;
    register float dx;
    register float dy;
    register float dz;
    float distSq;
    float cullRadius;
    int outsideMask;
    scratch.words[0] = *(unsigned int *)((char *)entry + 0);
    scratch.words[1] = *(unsigned int *)((char *)entry + 4);
    scratch.words[2] = *(unsigned int *)((char *)entry + 8);
    scratch.words[3] = *(unsigned int *)((char *)entry + 12);
    memcpy(scratch.box, scratch.words, 0x10);
    dx = view[0] - *(float *)((char *)entry + 0x10);
    dy = view[1] - *(float *)((char *)entry + 0x14);
    dz = view[2] - *(float *)((char *)entry + 0x18);
    scratch.delta[0] = dx;
    scratch.delta[1] = dy;
    scratch.delta[2] = dz;
    distSq = PSVECDotProduct(scratch.delta, scratch.delta);
    cullRadius = baseRadius + distSq;
    scratch.copies[0] = *(double *)scratch.box;
    scratch.copies[1] = *((double *)scratch.box + 1);
    cullRadius = radiusScale * cullRadius;
    outsideMask = 0;
    if (((float *)scratch.copies)[0] > cullRadius) outsideMask |= 1;
    if (((float *)scratch.copies)[0] < -cullRadius) outsideMask |= 2;
    if (((float *)scratch.copies)[1] > cullRadius) outsideMask |= 4;
    if (((float *)scratch.copies)[1] < -cullRadius) outsideMask |= 8;
    if (((float *)scratch.copies)[2] > cullRadius) outsideMask |= 0x10;
    if (((float *)scratch.copies)[2] < -cullRadius) outsideMask |= 0x20;
    return ~outsideMask & 0x15;
}
#pragma pop
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
int fn_802CCD0C(void * const arg0, void * const arg1) {
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
#pragma pop

#pragma cplusplus on
// One element of the draw-entry pointer array at mlist+0x90. The virtual method
// at vtable+0x10 returns the entry's sort key.
struct MListEntry {
    virtual void method0();
    virtual void method1();
    virtual int getSortKey();
};

// qsort comparator for the 4-byte entry pointers in the array at mlist+0x90
// (installed by fn_802CCE24): orders the entries by their virtual sort key.
/* qsort comparator: order the MList draw entries by their virtual sort key. */ extern "C" int fn_802CCDC4(void *** __restrict itemA, void *** __restrict itemB) {
    /* qsort comparator: order the MList draw entries by their virtual sort key. */
    MListEntry *entryA = (MListEntry *)*itemA;
    MListEntry *entryB = (MListEntry *)*itemB;
    return entryA->getSortKey() - entryB->getSortKey();
}
#pragma cplusplus reset
extern int fn_802CAC28(void *, int);
extern void Abend_Panic(const char *, ...);
extern void *memset(void *, int, unsigned int);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern char lbl_8034BBC0[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802CCE24(void *arg0) {
    union SwapTemp { unsigned int word[3]; unsigned short half[6]; };
    union SwapTemp saved;
    unsigned char *temp_r30;
    {
        int var_r27;
        unsigned char *record;
        int var_r28;
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
        int var_r3 = 0;
        int var_r11 = 0;
        goto loop_11_test;
loop_11_body:
        {
            int var_r4 = 0;
            int half;
            unsigned char *dst;
            unsigned char *temp_r5 = *(unsigned char **)((char *)arg0 + 0x34) + var_r11;
            int temp_r7 = *(int *)(temp_r5 + 0x14);
            int temp_len = *(int *)(temp_r5 + 0x18) - temp_r7;
            temp_r30 = *(unsigned char **)((char *)arg0 + 0x2C) + temp_r7 * 0xC;
            half = temp_len / 2;
            dst = temp_r30;
            for (var_r4 = 0; var_r4 < half; var_r4++) {
                unsigned char *other = temp_r30 + (temp_len - var_r4) * 0xC;
                saved.word[0] = *(unsigned int *)dst;
                saved.word[1] = *(unsigned int *)(dst + 4);
                saved.word[2] = *(unsigned int *)(dst + 8);
                *(unsigned short *)dst = *(unsigned short *)(other - 0xC);
                *(unsigned short *)(dst + 2) = *(unsigned short *)(other - 0xA);
                *(unsigned short *)(dst + 4) = *(unsigned short *)(other - 8);
                *(unsigned short *)(dst + 6) = *(unsigned short *)(other - 6);
                *(unsigned int *)(dst + 8) = *(unsigned int *)(other - 4);
                *(unsigned short *)(other - 0xC) = saved.half[0];
                *(unsigned short *)(other - 0xA) = saved.half[1];
                *(unsigned short *)(other - 8) = saved.half[2];
                *(unsigned short *)(other - 6) = saved.half[3];
                *(unsigned int *)(other - 4) = saved.word[2];
                dst += 0xC;
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
            object = *(void **)((char *)*(void ***)((char *)arg0 + 0x90) + var_r27);
            value = ((int (*)(void *))((int (**)(void *))*(void **)object)[4])(object);
            if (var_r26 == value) {
                *(int *)(var_r28 + 0x40) = var_r25;
                var_r25_2 = var_r25 + 1;
                var_r27 = var_r25_2 * 4;
                *(int *)(var_r28 + 0x44) = var_r25_2;
                goto loop_23_test;
            }
            goto loop_21_inc;
loop_23_body:
            object = *(void **)((char *)*(void ***)((char *)arg0 + 0x90) + var_r27);
            value = ((int (*)(void *))((int (**)(void *))*(void **)object)[4])(object);
            if (var_r26 != value) goto loop_21_inc;
            var_r27 += 4;
            var_r25_2++;
            *(int *)(var_r28 + 0x44) += 1;
loop_23_test:
            if (var_r25_2 < *(int *)((char *)arg0 + 0x88)) goto loop_23_body;
loop_21_inc:
            var_r27 += 4;
            var_r25++;
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
        else Abend_Panic(lbl_8034BBC0, type);
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
    char *materialEntry;
    /* Clear a material list: release each material handle in the 0x1C-byte entries at +0x34 (marking it invalid, -2), detach each draw-entry object in the pointer array at +0x90 via its virtual method0(1) and null the slots, then zero the object count at +0x88 and clear the built flag at +8. */
    index = 0;
    byteOffset = 0;
    reset = -2;
    while (index < *(int *)((char *)list + 0x30)) {
        materialEntry = *(char **)((char *)list + 0x34) + byteOffset;
        fn_802CAC54(*(int *)(materialEntry + 0x10));
        *(int *)(materialEntry + 0x10) = reset;
        byteOffset += 0x1C;
        index++;
    }
    byteOffset = 0;
    index = 0;
    reset = 0;
    while (byteOffset < *(int *)((char *)list + 0x88)) {
        void **drawEntries = *(void ***)((char *)list + 0x90);
        void *drawEntry = *(void **)((char *)drawEntries + index);
        if (drawEntry != 0)
            ((Dummy *)drawEntry)->method0(1);
        drawEntries = *(void ***)((char *)list + 0x90);
        byteOffset++;
        *(void **)((char *)drawEntries + index) = (void *)reset;
        index += 4;
    }
    *(int *)((char *)list + 0x88) = 0;
    *(int *)((char *)list + 8) &= ~2;
}
#pragma cplusplus reset

#pragma push
#pragma scheduling invalid_target
void fn_802CD320(void *list, int object) {
    /* Append a draw-entry object to the material list's handle array at +0x90, bumping the count at +0x88. */
    int *countPtr = (int *)((char *)list + 0x88);
    int **itemsPtr = (int **)((char *)list + 0x90);
    (*itemsPtr)[(*countPtr)++] = object;
}
#pragma pop
void fn_802CD33C(void *list, int entryIndex, int clearFlag) {
    /* RealName: MlistSetEntryFlag. Sets bit 0x40 in the u16 flags at +0x12 of
     * material-list entry entryIndex (32-byte entries in the table at +0x24);
     * a nonzero clearFlag clears the bit instead. */
    if (clearFlag != 0) {
        unsigned short *flags = (unsigned short *)(*(char **)((char *)list + 0x24) + (entryIndex << 5) + 0x12);
        *flags &= ~0x40;
    } else {
        unsigned short *flags = (unsigned short *)(*(char **)((char *)list + 0x24) + (entryIndex << 5) + 0x12);
        *flags |= 0x40;
    }
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void fn_802CD37C(void *arg0, void *arg1, float *arg2, int arg3, float farg0, float farg1) {
    float f[0x5A];
    int v, i;
    float *p;
    int *q;
    float *r;
    unsigned char sp9;
    unsigned char sp8;
    int ctr, k, n;
    void **entries;
    int *out;
    int idx;
    fn_801293C8(lbl_8034BBE0);
    lbl_8055FCD8 = arg0;
    f[78] = lbl_80564F58; f[79] = lbl_80564F5C; f[80] = lbl_80564F5C; f[81] = lbl_80564F5C;
    f[82] = lbl_80564F58; f[83] = lbl_80564F5C; f[84] = lbl_80564F5C; f[85] = lbl_80564F5C;
    f[86] = lbl_80564F58; f[87] = lbl_80564F5C; f[88] = lbl_80564F5C; f[89] = lbl_80564F5C;
    v = ((int (*)(void *, float))fn_802D0514)(&f[78], lbl_80564F58);
    *(int *)(gDrawContext + 0x64) = v;
    p = arg2;
    q = (int *)gDrawContext;
    i = 0;
    while (i < arg3) {
        *(q + 0x1A) = ((int (*)(void *, float))fn_802D0514)(p, 0.0f);
        p += 0x30 / 4;
        q += 1;
        i++;
    }
    if (arg3 < 0x100) {
        int rem = 0x100 - arg3;
        int *dst = (int *)(gDrawContext + arg3 * 4);
        if (rem > 8) {
            ctr = (0xFF - arg3) >> 3;
            if (arg3 < 0xF8) {
                do {
                    dst[0x19] = v; dst[0x1A] = v; dst[0x1B] = v; dst[0x1C] = v;
                    dst[0x1D] = v; dst[0x1E] = v; dst[0x1F] = v; dst[0x20] = v;
                    dst += 8;
                    ctr--;
                } while (ctr != 0);
            }
        }
        ctr = 0x100 - arg3;
        if (arg3 < 0x100) {
            do { dst[0x19] = v; dst++; ctr--; } while (ctr != 0);
        }
    }
    f[6] = *(int *)((char *)arg0 + 0x10);
    entries = *(void ***)((char *)arg0 + 0x14);
    r = (float *)fn_802C86DC(f[6]);
    {
        float *g = (float *)(lbl_804C1480 + 0x4190);
        for (k = 0; k < 12; k++) { g[k] = r[k]; f[66 + k] = r[k]; }
    }
    {
        float x = f[75], y = f[63], z = f[77];
        f[63] = z * f[68] + (x * f[66] + y * f[67]);
        f[64] = z * f[71] + (x * f[69] + y * f[70]);
        f[65] = z * f[74] + (x * f[72] + y * f[73]);
    }
    f[63] *= lbl_80564F60; f[64] *= lbl_80564F60; f[65] *= lbl_80564F60;
    fn_802C98DC(&lbl_8055FCD4, &lbl_8055D0A0, &lbl_8055D0A4, &f[1], f[64], f[63], lbl_80564F60);
    {
        float t8 = (lbl_8055D0A4 + lbl_8055D0A0) / (lbl_8055D0A4 - lbl_8055D0A0);
        float t42 = lbl_80564F58 / lbl_8055FCD4;
        float t52 = lbl_8055D0A4 * (lbl_80564F58 - t8);
        f[42] = lbl_80564F5C; f[43] = lbl_80564F5C;
        f[52] = t8; f[46] = lbl_80564F5C; f[47] = lbl_80564F5C;
        f[50] = t42; f[51] = t42;
        f[44] = lbl_80564F58 / f[1];
        f[48] = t52;
        *(double *)&f[26] = f[42]; *(double *)&f[28] = f[44];
        *(double *)&f[30] = f[46]; *(double *)&f[32] = f[48];
        *(double *)&f[34] = f[50]; *(double *)&f[36] = f[52];
        ((void (*)(float *, double *, double *, double *, float, float, float, float, float, float, float, float))fn_802CCBC0)(&f[57], (double *)&f[34], (double *)&f[30], (double *)&f[26], f[50], f[48], f[46], f[44], t52, lbl_8055D0A4, f[1], t8);
    }
    *gDrawContext = 0x81;
    out = (int *)(gDrawContext + 1);
    n = 0;
    idx = 1;
    {
        void *e = entries[0];
        while (n < f[6]) {
            float a = ((float *)e)[0], b = ((float *)e)[1], c = ((float *)e)[2], dd = ((float *)e)[3];
            f[22] = a; f[23] = b; f[24] = c; f[25] = dd;
            f[11] = f[22]; f[12] = f[23]; f[13] = f[24];
            if (fn_802C94A0(&f[11], &sp9, &lbl_8055FCE0, c, b, a, dd, f[23], f[22]) != 0) {
                int res = sp9 ? 0x81 : 1;
                lbl_8055FCDC = res;
                *out = res;
            } else {
                lbl_8055FCDC = 0;
                *out = 0;
            }
            e = (char *)e + 0x10;
            n++;
            idx++;
            out++;
        }
    }
    out = (int *)(gDrawContext + idx);
    n = 0;
    {
        void *e2 = *(void **)((char *)arg0 + 0x1C);
        int cnt2 = *(int *)((char *)arg0 + 0x18);
        f[38] = f[75]; f[39] = f[63]; f[40] = f[77]; f[41] = lbl_80564F5C;
        while (n < cnt2) {
            int res;
            if (*(signed char *)(gDrawContext + *(unsigned short *)((char *)e2 + 0xC)) != 0) {
                float px = f[38], pz = f[40];
                float pair[2];
                pair[0] = px; pair[1] = pz;
                res = fn_802CCBC4(e2, pair, farg0, farg1);
            } else {
                res = 0;
            }
            *out = res;
            e2 = (char *)e2 + 0x20;
            n++;
            idx++;
            out++;
        }
    }
    out = (int *)(gDrawContext + idx);
    {
        void *e3 = *(void **)((char *)arg0 + 0x24);
        int cnt3 = *(int *)((char *)arg0 + 0x20);
        int off = idx * 4;
        n = 0;
        while (n < cnt3) {
            float a, b, c, dd;
            int res;
            if (*(unsigned short *)((char *)e3 + 0x12) == (*(unsigned char *)(gDrawContext + *(unsigned short *)((char *)e3 + 0x10)) & 0x7F)) {
                a = ((float *)e3)[0]; b = ((float *)e3)[1]; c = ((float *)e3)[2]; dd = ((float *)e3)[3];
                f[10] = a; f[11] = b; f[12] = c;
                if (fn_802C94A0(&f[10], &sp8, &lbl_8055FCE0, c, b, a, dd, b, a) != 0) {
                    res = sp8 ? 0x81 : 1;
                    lbl_8055FCDC = res;
                } else {
                    res = 0;
                    lbl_8055FCDC = 0;
                }
                *(float *)(lbl_804C1480 + 0x4000 + off) = lbl_8055FCE0;
                off += 4;
                *out = res;
                out++;
            } else {
                *out = 0;
                off += 4;
                out++;
            }
            e3 = (char *)e3 + 0x20;
            n++;
        }
    }
    {
        int j = 0, cnt4 = *(int *)((char *)arg0 + 0x88);
        while (j < cnt4) {
            void **cb = *(void ***)((char *)arg0 + 0x90) + j;
            ((void (*)(void **, void *))((void **)*cb)[3])(*cb, arg0);
            j++;
        }
    }
    fn_801293DC(lbl_804C1480);
    __AXDSPInitCallback_801293D0();
}
#pragma pop
void fn_802CDAA8(void) {
    /* Clear the current mlist context pointer once the scene's draw list has been submitted. */
    #define s_currentMlist lbl_8055FCD8
    s_currentMlist = 0;
    #undef s_currentMlist
}

/* Submit one object's 12-float model transform (3x3 rotation, position and
 * scale) to the shared draw-entry table and store the returned handle in
 * this object's slot of the draw context. objectList is unused. */
void MlistSetObjectDraw(void *objectList, int objectIndex, float *transform) {
    struct DrawContext {
        unsigned char objectFlags[0x64]; /* +0x00: per-object type/visibility flags */
        int drawHandles[0x100];          /* +0x64: draw-entry handle per object */
    };
    struct DrawContext *context = (struct DrawContext *)gDrawContext;
    context->drawHandles[objectIndex] = ((int (*)(float *))fn_802D0514)(transform);
}

extern unsigned char *lbl_8055DFC4;
extern int fn_802D0514(int);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802CDAFC(void *object, int objectIndex) {
    /* Clear this object's per-object flag byte in the shared draw context, the
     * same byte fn_802CDB20 tests. */
    int offset18 = *(int *)((char *)object + 0x18);
    unsigned offset10 = *(int *)((char *)object + 0x10);
    gDrawContext[objectIndex + offset18 + offset10 + 1] = 0;
}

#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma opt_propagation off
/* RealName: MlistIsObjectFlagged. Test whether an object's per-object flag byte in the
 * shared draw context is set; fn_802CDAFC clears that same byte. */
int fn_802CDB20(void *object, int objectIndex) {
    int offset18;
    int offset10;
    int flagIndex;
    unsigned char *flags;

    if (objectIndex < 0) {
        return 0;
    }
    offset18 = *(int *)((char *)object + 0x18);
    offset10 = *(int *)((char *)object + 0x10);
    flagIndex = objectIndex + offset18;
    flags = gDrawContext;
    flagIndex = flagIndex + offset10;
    return flags[flagIndex + 1] != 0;
}

extern char lbl_8034BBEC[];
extern char lbl_804C1480[];
extern void fn_801293C8(void *);
extern void fn_801293E8(void *);
extern void fn_802D0610(int);
extern void fn_802C8B70(int);
extern void DrawList_RestoreNormalMode(void);
extern int fn_802DB2A8(int);
extern void fn_802DB2B0(int);
extern void fn_802DB2A0(void);
extern void __AXDSPInitCallback_801293D0(void);
extern void fn_802D6B08(void *);
extern void fn_802CC550(int, float, float);
extern float lbl_80564F58;
extern float lbl_80564F5C;
extern float lbl_804C5480[];
#pragma cplusplus on
/* Dispatch slot 0x14 of an mlist object's vtable (a real C++ virtual call, so
 * the vtable pointer goes through r12). */
static inline void MlistCallV3(void *object, void *context) {
    class MlistObj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3(void *context);
    };
    ((MlistObj *)object)->v3(context);
}
#pragma cplusplus off
#pragma opt_propagation off
void fn_802CDB5C(int arg0) {
    #pragma opt_propagation off
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
        volatile struct Item cur;
        int pad;
        int config38;
        int config3C;
        int config40;
        int config44;
        float matrix[12];
    } work;
    char *record;
    char *itemBase;
    int outerEnd;
    int itemCount2;
    void *object;
    char *context;
    unsigned char *table;
    int outerIndex;
    unsigned int lastEntry;
    int recordId;
    int started;
    int itemCount;
    struct Item *item;
    int cursor;
    int callbackCount;
    int i;
    float *fxTable;
    char *config;
    int handle;
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
    fxTable = lbl_804C5480;
    record = (char *)work.context34 + outerIndex * 0x1C;
    *(int *)(table + 0x64) = handle;
    itemBase = (char *)work.context2C;
    outerEnd = work.config3C;
    lastEntry = 0;
    for (; outerIndex < outerEnd; record += 0x1C, outerIndex++) {
        int itemStart = *(int *)(record + 0x14);
        itemCount = *(int *)(record + 0x18) - itemStart;
        recordId = *(int *)(record + 0x10);
        item = (struct Item *)(itemBase + itemStart * 12);
        itemCount2 = itemCount * 2;
        started = 0;
        cursor = 0;
        callbackCount = 0;
        for (i = 0; i < itemCount; i++) {
            work.cur = *item++;
            if ((table[work.cur.id] & 0x7F) != work.cur.type)
                continue;
            if (started == 0) {
                started = 1;
                fn_802C8B70(recordId);
                cursor = fn_802DB2A8(itemCount2);
                if (cursor == 0) {
                    DrawList_RestoreNormalMode();
                    started = 0;
                    break;
                }
            }
            handle = *(int *)(table + work.cur.state * 4 + 0x64);
            if (lastEntry != (unsigned int)handle) {
                lastEntry = (unsigned int)handle;
                fn_802D0610(handle);
                cursor += 0x10;
                callbackCount++;
            }
            object = work.cur.object;
            fn_802D6B08(object);
            fn_802CC550(recordId, fxTable[work.cur.id],
                        *(float *)((char *)object + 8));
            cursor += 0x10;
            callbackCount++;
        }
        if (started != 0) {
            fn_802DB2B0(callbackCount);
            DrawList_RestoreNormalMode();
        }
    }
    fn_802DB2A0();
    __AXDSPInitCallback_801293D0();
    i = work.config40;
    callbackCount = work.config44;
    for (; i < callbackCount; i++) {
        object = (*(void ***)(context + 0x90))[i];
        MlistCallV3(object, context);
    }
}
#pragma opt_propagation reset
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
    unsigned char a10, a6, a2, a8, a4, a0, a1, a3, a5, a7, a9, a11;
    unsigned char t;
    int i;
    int index;
    int offset;
    {
        a0 = base[0];
        a1 = base[3];
        a2 = base[1];
        a3 = base[2];
        a4 = base[4];
        a5 = base[7];
        a6 = base[5];
        a7 = base[6];
        a8 = base[8];
        a9 = base[0xB];
        a10 = base[9];
        a11 = base[0xA];
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
    fn_802CE260((int *)(base + 0x14), arg1);
    fn_802CE278((int *)(base + 0x1C), arg1);
    fn_802CE290((int *)(base + 0x24), arg1);
    fn_802CE2A8((int *)(base + 0x2C), arg1);
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
        fn_802CE2C0((int *)(rec + 8), arg1);
        offset += 0xC;
        index++;
    }
    fn_802CE2D8((int *)(base + 0x34), arg1);
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
    fn_802CE2F0((int *)(base + 0x90), arg1);
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
void fn_802CE260(int *value, int delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802CE278(int *value, int delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802CE290(int *value, int delta) {
    /* Add delta to *value (rebasing a stored pointer/handle), leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802CE2A8(int *value, int delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802CE2C0(int *value, int delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802CE2D8(int *value, int delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

void fn_802CE2F0(int *value, int delta) {
    /* Add delta to *value, leaving a zero (null) sentinel unchanged. */
    int cur = *value;
    if (cur != 0) {
        *value = cur + delta;
    }
}

