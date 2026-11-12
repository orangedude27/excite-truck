// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

float fn_80235EF0(int, int);
extern float lbl_80563AD0;
extern float fn_80235EF0(int, int);
extern float fn_80235F64(int, int);
extern void fn_802354A0(int, int, int, float, float, float, float);
extern float lbl_80563ACC;
extern void fn_80235380(int);
extern void fn_802328D4(int);
extern void fn_80128668(void *);
extern int lbl_80344D98;
__declspec(section ".data") extern int lbl_80344D98;
extern char lbl_80344D88[];
extern void *fn_801284F8(int, void *);
extern char lbl_8055C258[];
__declspec(section ".sdata") extern char lbl_8055C258[];
extern float lbl_80563AC8;
#pragma scheduling invalid_target
void fn_80258354(void) {
    void *p = fn_801284F8(0x1328, lbl_80344D88);
    if (p != 0) {
        *(void **)p = &lbl_80344D98;
        *(void **)((char *)p + 4) = (char *)p + 0x10;
        *(int *)((char *)p + 0xC) = 0x20;
        *(int *)((char *)p + 8) = 0;
        *(void **)((char *)p + 0x910) = (char *)p + 0x91C;
        *(int *)((char *)p + 0x918) = 0x20;
        *(int *)((char *)p + 0x914) = 0;
        *(void **)((char *)p + 0xD9C) = (char *)p + 0xDA8;
        *(int *)((char *)p + 0xDA4) = 0x20;
        *(int *)((char *)p + 0xDA0) = 0;
    }
}
#pragma scheduling on

#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma cplusplus on
extern "C" void *fn_802583CC(void *o, int arg1, int arg2) {
    struct Release { virtual void release(int); };
    char *p = (char *)o;
    int zero;
    int idx;
    int offset;
    int scan;
    int index3;
    int offset3;

    if (o != 0) {
        *(void **)p = &lbl_80344D98;
        offset = 0;
        idx = 0;
        goto L_check1;
L_loop1:
        fn_80235380(*(int *)(*(char **)(p + 4) + idx + 0x40));
        idx += 0x48;
        offset++;
L_check1:
        if (offset < *(int *)(p + 8))
            goto L_loop1;
        zero = 0;
        *(int *)(p + 8) = zero;
        scan = 0;
        idx = 0;
        goto L_check2;
L_loop2:
        offset = *(int *)(*(char **)(p + 0x910) + idx + 0x20);
        if (offset != 0) {
            fn_802328D4(*(int *)offset);
            *(int *)offset = zero;
            fn_80128668((void *)offset);
        }
        idx += 0x24;
        scan++;
L_check2:
        if (scan < *(int *)(p + 0x914))
            goto L_loop2;
        zero = 0;
        *(int *)(p + 0x914) = zero;
        index3 = 0;
        offset3 = 0;
        goto L_check3;
L_loop3:
        if (*(void **)(*(char **)(p + 0xd9c) + offset3 + 0x20) != 0) {
            void *item = *(void **)(*(char **)(p + 0xd9c) + offset3 + 0x20);
            ((Release *)item)->release(1);
        }
        offset3 += 0x2c;
        index3++;
L_check3:
        if (index3 < *(int *)(p + 0xda0))
            goto L_loop3;
        zero = 0;
        *(int *)(p + 0xda0) = zero;
        if ((unsigned int)p + 0xd9c != 0) {
            if ((unsigned int)p + 0xd9c != 0) {
                *(int *)(p + 0xd9c) = 0;
                *(int *)(p + 0xda0) = 0;
                *(int *)(p + 0xda4) = 0;
            }
        }
        if ((unsigned int)p + 0x910 != 0) {
            if ((unsigned int)p + 0x910 != 0) {
                *(int *)(p + 0x910) = zero;
                *(int *)(p + 0x914) = zero;
                *(int *)(p + 0x918) = zero;
            }
        }
        if ((unsigned int)p + 4 != 0) {
            if ((unsigned int)p + 4 != 0) {
                *(int *)(p + 4) = zero;
                *(int *)(p + 8) = zero;
                *(int *)(p + 0xc) = zero;
            }
        }
        if (arg1 > 0)
            fn_80128668(o);
    }
    return o;
}
#pragma cplusplus reset
#pragma use_lmw_stmw on
#pragma scheduling on
extern int fn_8023512C(void *);

/* One entry of UIObjects_impl's object table (array at +0x04, count at +0x08,
 * 0x20 entries of 0x48 bytes; fn_80258550 adds them and fn_8025878C,
 * fn_802588C8, fn_80258A00, fn_80258AB0, fn_80258B60 and fn_80258C08 look them
 * up by name).  The pair at +0x40 says which item of an art set the object
 * shows: fn_80235EF0 and fn_80235F64 read that item's two floats, which the
 * callers use as the x and y offset to draw at. */
typedef struct UIObjectEntry {
    char name[0x20];    /* +0x00 what callers look the object up by */
    char artName[0x20]; /* +0x20 name of the art set it draws from */
    void *art;          /* +0x40 the art set, referenced (see fn_8023512C) */
    int item;           /* +0x44 which item of that art set */
} UIObjectEntry;        /* == 0x48 */

#pragma scheduling invalid_target
/* UIObjects_impl: add a named object to the manager's object table.  The next
 * free entry (+0x04 array, its count at +0x08 incremented here) takes a copy of
 * the name callers look the object up by and of the art set's name -- both at
 * most 0x20 characters, the last one given up to the terminator when the string
 * is longer -- then a reference on that art set and the number of the item
 * within it the object shows. */
void fn_80258550(void *mgr, const char *name, const char *artName, int item) {
    UIObjectEntry *entry;
    int remaining;
    char *dst;
    remaining = 0x20;
    entry = &((UIObjectEntry *)*(unsigned int *)((char *)mgr + 4))[( *(int *)((char *)mgr + 8))++];
    dst = entry->name;
    goto copy1;
check1:
    if (--remaining > 0) goto copy1;
    dst[-1] = 0;
    goto copied1;
copy1:
    if ((*dst++ = *name++) != 0) goto check1;
copied1:
    name = artName;
    dst = entry->artName;
    remaining = 0x20;
    goto copy2;
check2:
    if (--remaining > 0) goto copy2;
    dst[-1] = 0;
    goto copied2;
copy2:
    if ((*dst++ = *name++) != 0) goto check2;
copied2:
    entry->art = (void *)fn_8023512C((void *)artName);
    entry->item = item;
}
#pragma scheduling on
void fn_8025861C(void *arg0, const char *arg1, void *arg2) {
    char *base;
    int n = 0x20;
    char *dst;
    void *p;
    base = *(char **)((char *)arg0 + 0x910) + (*(int *)((char *)arg0 + 0x914))++ * 0x24;
    dst = base;
    goto copy;
check:
    if (--n > 0) {
        goto copy;
    }
    dst[-1] = 0;
    goto copied;
copy:
    if ((*dst++ = *arg1++) != 0) {
        goto check;
    }
copied:
    p = fn_801284F8(0x14, lbl_8055C258);
    if (p != 0) {
        ((int *)p)[0] = 0;
        ((int *)p)[1] = -1;
        ((int *)p)[2] = 9;
        ((float *)p)[3] = lbl_80563AC8;
        ((float *)p)[4] = lbl_80563AC8;
        ((int *)p)[0] = fn_80232578(arg2);
    }
    *(void **)(base + 0x20) = p;
}
#pragma scheduling on
extern void *fn_80207848(int, int);
extern float lbl_80563AC8;
#pragma scheduling invalid_target
void fn_802586F0(void *arg0, void *arg1, int arg2, int arg3) {
    char *base = (char *)arg0;
    int count = 0x20;
    char *entry;
    char *dst;
    char *ptr = (char *)arg1;
    entry = *(char **)(base + 0xD9C) + (*(int *)(base + 0xDA0))++ * 0x2C;
    dst = entry;
    goto copy;
check:
    if (--count > 0) {
        goto copy;
    }
    dst[-1] = 0;
    goto done;
copy:
    if ((*dst++ = *ptr++) != 0) {
        goto check;
    }
done:
    *(void **)(entry + 0x20) = fn_80207848(arg2, 0);
    *(float *)(entry + 0x28) = lbl_80563AC8;
    *(char *)(entry + 0x24) = (char)arg3;
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8025878C(void *arg0, const char *arg1, int flags, int arg3, float x, float y) {
    int index = 0;
    int offset = 0;
    float cosine;
    float sine;
    float k;
    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1)) >> 5) {
    case 0:
        offset += 0x48;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = (int)(*(unsigned int *)((char *)arg0 + 4) + index * 0x48);
    cosine = fn_80235EF0(*(int *)(index + 0x40), *(int *)(index + 0x44));
    sine = fn_80235F64(*(int *)(index + 0x40), *(int *)(index + 0x44));
    if (flags & 2)
        x -= cosine;
    else if (flags & 4)
        x -= lbl_80563ACC * cosine;
    if (flags & 0x40)
        y += sine;
    else if (flags & 0x10)
        y += lbl_80563ACC * sine;
    k = lbl_80563AD0;
    ((void (*)(int, int, int, float, float, float, float, float))fn_802354A0)(
        *(int *)(index + 0x40), *(int *)(index + 0x44), arg3,
        x, y, k, cosine, sine);
}
#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_802588C8(void *arg0, const char *arg1, int flags, int arg3, float x, float y, float scale) {
    int index = 0;
    int offset = 0;
    int result;
    register float c;
    float s;
    goto check;
loop:
    result = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    switch (((unsigned int)__cntlzw(result) >> 5)) {
    case 0:
        offset += 0x48;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = *(int *)((char *)arg0 + 4) + index * 0x48;
    c = scale * fn_80235EF0(*(int *)(index + 0x40), *(int *)(index + 0x44));
    s = scale * fn_80235F64(*(int *)(index + 0x40), *(int *)(index + 0x44));
    if (flags & 2)
        x -= c;
    else if (flags & 4)
        x -= lbl_80563ACC * c;
    if (flags & 0x40)
        y += s;
    else if (flags & 0x10)
        y += lbl_80563ACC * s;
    ((void (*)(int, int, int, float, float, float, float, float))fn_802354A0)(*(int *)(index + 0x40), *(int *)(index + 0x44), arg3, x, y, lbl_80563AD0, c, s);
}
#pragma scheduling on
#pragma pop
/* Look up a named entry in a 0x48-byte stride table and return its value via fn_80235EF0, or 0.0f if not found. */
float fn_80258A00(void *table, int name) {
    int index = 0;
    int offset = 0;
    int compareResult;
    goto check;
loop:
    compareResult = stricmp((const char *)(*(unsigned int *)((char *)table + 4) + offset), (const char *)name);
    if (((unsigned int)__cntlzw(compareResult) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)table + 8)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        unsigned int entry = *(unsigned int *)((char *)table + 4) + index * 0x48;
        return fn_80235EF0(*(unsigned int *)(entry + 0x40), *(unsigned int *)(entry + 0x44));
    }
    return lbl_80563AD0;
}

// Look up a named entry in a 0x48-byte stride table and return its computed float value, or 0.0f if not found.
float fn_80258AB0(void *table, int name) {
    int index = 0;
    int offset = 0;
    int compareResult;
    goto check;
loop:
    compareResult = stricmp((const char *)(*(unsigned int *)((char *)table + 4) + offset), (const char *)name);
    if (((unsigned int)__cntlzw(compareResult) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)table + 8)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        unsigned int entry = *(unsigned int *)((char *)table + 4) + index * 0x48;
        return fn_80235F64(*(unsigned int *)(entry + 0x40), *(unsigned int *)(entry + 0x44));
    }
    return lbl_80563AD0;
}

#pragma push
#pragma scheduling on
void *fn_80258B60(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    int len;
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    switch (((unsigned int)__cntlzw(len) >> 5)) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int byte_offset = index;
        byte_offset *= 0x48;
        return (void *)((char *)*(unsigned int *)((char *)arg0 + 4) + byte_offset + 0x20);
    }
    return 0;
}

int fn_80258C08(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    char *entries;
    int entry_offset;
    int len;
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)arg0 + 4) + offset), arg1);
    switch (((unsigned int)__cntlzw(len) >> 5)) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x48;
    index++;
check:
    if (index < *(int *)((char *)arg0 + 8)) {
        goto loop;
    }
    index = -1;
found:
    if (index >= 0) {
        entry_offset = index * 0x48;
        entries = *(char **)((char *)arg0 + 4);
        return *(int *)(entries + entry_offset + 0x44);
    }
    return 0;
}

int fn_80258CB0(void *mgr, const char *name) {
    int index = 0;
    int offset = 0;
    int len;
    /* Look up name in the text-entry table (+0x910, count +0x914, stride 0x24) and return its +0x20 value, or 0. */
    goto check;
loop:
    len = stricmp((const char *)(*(unsigned int *)((char *)mgr + 0x910) + offset), name);
    switch (((unsigned int)__cntlzw(len) >> 5)) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x24;
    index++;
check:
    if (index < *(int *)((char *)mgr + 0x914))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int byte_offset = index;
        byte_offset *= 0x24;
        return *(int *)((char *)*(unsigned int *)((char *)mgr + 0x910) + byte_offset + 0x20);
    }
    return 0;
}

#pragma pop
extern int stricmp(const char *, const char *);
extern int fn_80232B70(int, int, int);
extern double lbl_80563AD8;

/* The per-text object UIObjects_impl keeps (0x14 bytes, alloc name "gText";
 * created by fn_8025861C). */
typedef struct UITextObject {
    void *font;    /* +0x00 font block loaded by gText (fn_80232578) */
    int value;     /* +0x04 -1 until a caller sets it */
    unsigned int flags; /* +0x08 draw flags, 9 when created */
    float scale;   /* +0x0C pixels per font unit */
    float field10; /* +0x10 0 when created */
} UITextObject;

/* One entry of the manager's text table (array at +0x910, count at +0x914,
 * 0x24 bytes each: a 0x20-byte name and the object drawn for it). */
typedef struct UITextEntry {
    char name[0x20];
    UITextObject *text;
} UITextEntry;

/* UIObjects_impl: set up the named text object.  Looks the name up in the
 * manager's text table (+0x910, count +0x914), copies the low seven bits of
 * `flags` into the object's draw flags, makes its scale `height` pixels over
 * the font's own height (gText keeps that as a byte in the font block) and
 * stores `value`; returns the object, or 0 when the name is unknown. */
void *fn_80258D58(void *mgr, const char *name, int flags, int height, int value) {
    char *base = (char *)mgr;
    int index = 0;
    int offset = 0;
    int compare;
    UITextObject *text;
    unsigned int old;
    unsigned int temp;
    unsigned int mask;
    goto check;
loop:
    compare = stricmp((*(UITextEntry **)(base + 0x910))->name + offset, name);
    switch ((unsigned int)__cntlzw((unsigned int)compare) >> 5) {
    case 0:
        goto increment;
    default:
        goto found;
    }
increment:
    offset += 0x24;
    index++;
check:
    if (index < *(int *)(base + 0x914))
        goto loop;
    index = -1;
found:
    if (index >= 0) {
        int divisor;
        text = *(UITextObject **)(*(char **)(base + 0x910) + index * 0x24 + 0x20);
        temp = (unsigned int)flags & 7;
        old = text->flags;
        mask = (unsigned int)flags & 0x78;
        temp = __rlwimi(temp, old, 0, 0, 28);
        text->flags = (temp & ~0x58U) | mask;
        divisor = fn_80232B70((int)text->font, temp, old);
        text->scale = (float)height / (float)divisor;
        text->value = value;
        return text;
    }
    return 0;
}

extern float fn_80209028(void);
/* Find a named sub-object entry on this object, apply its timed value, and update
 * playback/control flags based on whether the entry requests a restart. */
void fn_80258E64(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    void *obj;
    float value;

    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 0xD9C) + offset), arg1)) >> 5) {
    case 0:
        offset += 0x2C;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 0xDA0))
        goto loop;
    index = -1;
found:
    if (index < 0)
        return;
    index = (int)(*(unsigned int *)((char *)arg0 + 0xD9C) + index * 0x2C);
    if (*(void **)(index + 0x20) == 0)
        return;
    value = *(float *)(index + 0x28) * fn_80209028();
    obj = *(void **)(index + 0x20);
    if (value != *(float *)((char *)obj + 8)) {
        *(unsigned char *)((char *)obj + 0x4D) = 1;
        *(float *)((char *)obj + 8) = value;
    }
    if (*(unsigned char *)(index + 0x24)) {
        obj = *(void **)(index + 0x20);
        *(unsigned char *)((char *)obj + 0x4A) = 0;
        *(unsigned char *)((char *)obj + 0x4B) = 1;
        *(unsigned char *)((char *)obj + 0x49) = 1;
        return;
    }
    obj = *(void **)(index + 0x20);
    if (*(unsigned char *)((char *)obj + 0x19)) {
        *(unsigned char *)((char *)obj + 0x4C) = 1;
        *(unsigned char *)((char *)obj + 0x4A) = 0;
    }
    obj = *(void **)(index + 0x20);
    *(unsigned char *)((char *)obj + 0x49) = 1;
    *(unsigned char *)((char *)obj + 0x4B) = 0;
    *(unsigned char *)((char *)obj + 0x4A) = 0;
}

/* Find the named entry (table at +0xD9C, count at +0xDA0, stride 0x2C) and mark its object active (+0x4A=1, +0x4C=0). */
void fn_80258F94(void *arg0, const char *arg1) {
    int index = 0;
    int offset = 0;
    unsigned int entry;
    void *object;
    goto check;
loop:
    switch ((unsigned int)__cntlzw(stricmp((const char *)(*(unsigned int *)((char *)arg0 + 0xD9C) + offset), arg1)) >> 5) {
    case 0:
        offset += 0x2C;
        index++;
        goto check;
    default:
        goto found;
    }
check:
    if (index < *(int *)((char *)arg0 + 0xDA0)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        entry = *(unsigned int *)((char *)arg0 + 0xD9C);
        entry += index * 0x2C;
        object = *(void **)(entry + 0x20);
        if (object != 0) {
            *(unsigned char *)((char *)object + 0x4A) = 1;
            *(unsigned char *)((char *)object + 0x4C) = 0;
        }
    }
}

#pragma scheduling invalid_target
/* Find the named entry (entries at +0xD9C, count at +0xDA0, stride 0x2C) and set its float value at +0x28. */
void fn_8025904C(void *table, int name, float value) {
    int index = 0;
    int offset = 0;
    int cmp;
    goto check;
loop:
    cmp = stricmp((const char *)(*(unsigned int *)((char *)table + 0xD9C) + offset), (const char *)name);
    if (((unsigned int)__cntlzw(cmp) >> 5)) {
        if (lbl_80563AD0) goto found;
        else goto found;
    }
    offset += 0x2C;
    index++;
check:
    if (index < *(int *)((char *)table + 0xDA0)) goto loop;
    index = -1;
found:
    if (index >= 0) {
        struct Entry { char pad[0x28]; float value; };
        ((struct Entry *)(*(unsigned int *)((char *)table + 0xD9C)))[index].value = value;
    }
}
#pragma scheduling on

