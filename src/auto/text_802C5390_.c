#include "types.h"
extern void fn_802CC550(int, void *, float, float);
extern void *fn_8012C370(int, int, u32 *, int *, u8 *, u8 *);
extern void fn_802E317C(const char *, ...);
extern void DCStoreRangeNoSync(const void *, u32);
extern void fn_802C61BC(void *, int);
extern const char lbl_8034B2E8[];
extern const char lbl_8034B314[];
#pragma push
#pragma small_data off
extern void fn_802D6C48(void);
extern void fn_802D6C44(void);
#pragma pop
void fn_802C5DF0(void *, void *);
extern int lbl_8055D008;
void* fn_802C5390(int);
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);

extern int lbl_8055D00C;
extern void fn_802DB2B4(void);
extern int lbl_804C1338[];
extern unsigned char lbl_804C1348[];
struct Entry16 {
    char data[16];
};
extern int lbl_804C139C[];
extern int lbl_804C13A8[];
extern int lbl_804C13B4[];
extern const char lbl_8034B1D8[];
extern s8 lbl_8055FC21;
char *fn_802CAE34(char *);
int stricmp(const char *, const char *);
extern const char lbl_8034B3DC[];
extern const char lbl_8034B34C[];
int fn_802C6C20(int);
int fn_802C90E0(void);
int fn_802E30C8(const char *, int);
int fn_802C6B44(int);
void fn_802C6DC4(int, int, int, int);
void fn_802C6C38(int);
extern float *fn_802C9A40(float, float, float, float);
extern float lbl_80564EF4;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma dont_inline on
void *fn_802C5390(int arg0) {
    u32 base = *(u32 *)((char *)lbl_804C139C + 8);
    return (void *)(base + (arg0 << 4));
}

int fn_802C53A8(arg0)
int arg0;
{
    int *base = *(int * volatile *)((char *)lbl_804C139C + 8);
    return *(int *)((char *)base + (arg0 << 4) + 4);
}

#pragma scheduling invalid_target
void fn_802C53C4(void *a, void *b, int x, int y, signed char z) {
    register int count = lbl_804C1338[0];
    register int limit = lbl_804C1338[1];
    unsigned char *entry;
    if (count < limit) {
        register int offset = count * 0x14;
        unsigned char *base = (unsigned char *)(unsigned long)lbl_804C1338[2];
        lbl_804C1338[0] = count + 1;
        entry = base + offset;
    } else {
        entry = 0;
    }
    if (entry == 0)
        return;
    *(int *)(entry + 0) = *(int *)((char *)a + 12);
    *(signed char *)(entry + 4) = z;
    *(int *)(entry + 8) = x;
    if ((*(unsigned int *)((char *)a + 4) & 1) != 0)
        *(int *)(entry + 12) = y;
    else
        *(int *)(entry + 12) = -1;
    *(void **)(entry + 16) = *(void **)((char *)b + 8);
    *(void **)((char *)b + 8) = entry;
}
#pragma scheduling on
void fn_802C543C(void) {
    lbl_804C1338[0] = 0;
}
#pragma dont_inline off

int fn_802C544C(void **a, void **b) {
    void *right = *b;
    void *left = *a;
    short x = *(short *)((char *)right + 6);
    short y = *(short *)((char *)left + 6);
    if (y != x) return y - x;
    return stricmp(fn_802CAE34(*(char **)left), fn_802CAE34(*(char **)right));
}

void *fn_802C54B4(int i) { return (void *)(lbl_804C1348 + (i - 1) * 8); }

unsigned char fn_802C54CC(unsigned int arg0) { return (unsigned char)(arg0 >> 8); }

extern void fn_802C8B70(int);
extern void fn_802C8D74(void);
extern void fn_802D0610(int);
extern void fn_802D6B08(int);
extern void fn_802DAA18(void);
extern void fn_802DB2BC(unsigned char);
extern int lbl_804C139C[];
void fn_802C5690(void *arg0) {
    void *node;
    if (*(int *)((char *)arg0 + 8) != 0) {
        fn_802C8B70(*(int *)arg0);
        node = *(void **)((char *)arg0 + 8);
        while (node != 0) {
            fn_802D0610(*(int *)((char *)node + 8));
            if ((unsigned int)(*(int *)((char *)node + 12) + 0x10000) != 0xFFFF) {
                fn_802DAA18();
            }
            fn_802DB2BC(*(unsigned char *)((char *)node + 4));
            fn_802D6B08(*(int *)node);
            node = *(void **)((char *)node + 16);
        }
        fn_802C8D74();
        *(int *)((char *)arg0 + 8) = 0;
    }
}

extern void fn_802C54D4(void);
extern int lbl_804C1390[];
#pragma dont_inline on
#pragma dont_inline on
void fn_802C5720(int arg0) {
    int count;
    void **items;
    int i;
    fn_802C54D4();
    if (arg0 > 0) {
        void *entry = fn_802C54B4(arg0);
        items = *(void ***)entry;
        count = *(int *)((char *)entry + 4);
    } else {
        count = lbl_804C1390[0];
        items = *(void ***)(lbl_804C1390 + 2);
    }
    for (i = 0; i < count; i++) {
        fn_802C5690(items[i]);
    }
    fn_802DB2BC(1);
}
#pragma dont_inline reset

void fn_802C57B0(void) { }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline fn_802C53C4
void fn_802C57B4(int arg0, int arg1, int arg2, unsigned char arg3, float arg4) {
    extern int lbl_8055D008;
    extern s8 lbl_8055FC20;
    extern void fn_802C543C(void);
    extern void fn_802C5720(int);
    extern void fn_802C53C4(void *, void *, int, int, signed char);
    extern void fn_802C57B0(void);
    extern void fn_802CC550(int, void *, float, float);
    extern int fn_802C9638(void *, unsigned char *, float);

    void *manager;
    int *outer_info;
    int idx_shift;
    int i;
    int offset;

    manager = fn_802C5390(arg0);
    outer_info = *(int **)((char *)manager + 4);
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C543C();
    }
    idx_shift = *(int *)((char *)manager + 8) << 2;
    for (i = 0, offset = 0; i < *outer_info; i++, offset += 0x10) {
        char *entry = *(char **)((char *)outer_info + 4) + offset;
        int bit_idx = *(int *)entry;
        if (lbl_8055D008 & (1 << bit_idx)) {
            unsigned char local_d = arg3;
            char *sub = *(char **)((char *)manager + 12);
            if (sub == 0 || fn_802C9638(sub + offset, &local_d, *(float *)(sub + offset + 12)) != 0) {
                unsigned char d = local_d;
                int *inner_info = *(int **)(entry + 8);
                int j;
                int inner_offset;
                for (j = 0, inner_offset = 0; j < *inner_info; j++, inner_offset += 4) {
                    void *elem = *(void **)(*(char **)((char *)inner_info + 4) + inner_offset);
                    unsigned int type = *(unsigned int *)elem;
                    int valid = 0;
                    if (type < 13) {
                        int skip;
                        valid = 1;
                        switch (type) {
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            skip = 1;
                            break;
                        default:
                            skip = 0;
                            break;
                        }
                        if (skip) valid = 0;
                    }
                    if (valid) {
                        void *node = *(void **)((char *)elem + idx_shift + 0x14);
                        void *r4;
                        fn_802C53C4(entry, node, arg1, arg2, d);
                        r4 = ((void *(*)(void *))fn_802C57B0)(*(void **)(entry + 12));
                        fn_802CC550(*(int *)node, r4, arg4, *(float *)((char *)r4 + 0x18));
                    }
                }
            }
        }
    }
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C5720(-1);
    }
}
#pragma push
#pragma use_lmw_stmw off
void fn_802C595C(char *dst, int size, const char *name, int id) {
    int offset;
    int i;
    char *entry;
    register const unsigned char *src;
    unsigned char c;

    i = 0;
    offset = 0;
    goto table_check;

table_loop:
    entry = (char *)(unsigned long)lbl_804C13B4[2] + offset;
    if (stricmp(name, entry) == 0) {
        if (id == *(int *)(entry + 0x10)) {
            src = (const unsigned char *)(entry + 0x14);
            goto matched_copy;
        }
    }
    goto table_next;

matched_copy:
    do {
        if (--size <= 0) {
            dst[-1] = 0;
            goto done;
        }
        c = *src++;
        *dst++ = c;
    } while ((signed char)c != 0);
    goto done;

table_next:
    offset += 0x2C;
    i++;

table_check:
    if (i < lbl_804C13B4[0]) {
        goto table_loop;
    }

fallback_copy:
    do {
        if (--size <= 0) {
            dst[-1] = 0;
            goto done;
        }
        c = *name++;
        *dst++ = c;
    } while ((signed char)c != 0);

done:
    return;
}
#pragma pop
u16 fn_802C5A50(int arg0, int arg1) {
    return (u16)((arg0 << 8) | arg1);
}

void *fn_802C5A60(int arg0, int arg1, u16 arg2) {
    struct Entry {
        s32 key0;
        u16 refs;
        s16 key2;
        s32 reserved;
        s32 key1;
    };
    struct Entry *entry;
    register s32 savedArg0 = arg0;
    s32 count = lbl_804C13A8[0];
    struct Entry *match = 0;
    struct Entry *freeEntry = 0;
    s32 zero = 0;
    s32 one = 1;
    s32 i;

    entry = (struct Entry *)(unsigned long)lbl_804C13A8[2];
    for (i = count; i > 0; i--, entry++) {
        if (entry->refs != 0) {
            if (entry->key1 == arg1 && entry->key2 == arg2 && entry->key0 == arg0) {
                match = entry;
                break;
            }
        } else {
            freeEntry = entry;
        }
    }

    if (match == 0) {
        if (freeEntry == 0) {
            if (count < lbl_804C13A8[1]) {
                s32 next = *(volatile s32 *)&lbl_804C13A8[0];
                void *base = *(void * volatile *)&lbl_804C13A8[2];
                freeEntry = (struct Entry *)((char *)base + next * 0x10);
                lbl_804C13A8[0] = next + 1;
            } else {
                freeEntry = 0;
            }
            if (freeEntry == 0) {
                fn_802E317C(lbl_8034B1D8);
            }
            freeEntry->key0 = savedArg0;
        }
        freeEntry->refs = zero;
        match = freeEntry;
        freeEntry->key2 = arg2;
        freeEntry->reserved = zero;
        freeEntry->key1 = arg1;
        lbl_8055FC21 = one;
    }

    match->refs++;
    return match;
}

extern void fn_802CAC54(int);
extern s8 lbl_8055FC21;
void fn_802C5BA0(int *arg0) {
    u16 temp;
    fn_802CAC54(*arg0);
    temp = *(u16 *)((char *)arg0 + 4);
    temp--;
    *(u16 *)((char *)arg0 + 4) = temp;
    if (temp == 0) {
        lbl_8055FC21 = 1;
    }
}

#pragma scheduling invalid_target
u16 fn_802C5BEC(int arg0, int arg1) {
    int temp = ((arg0 * 2) & 0xFFFE) + ((int (*)(int, int))fn_802C5A50)(5, 0x64);
    return temp + (arg1 & 0xFFFF);
}
#pragma scheduling on
extern int fn_802CAC28(void *, int);
extern void *fn_802C5A60(int, int, u16);
#pragma push
#pragma small_data off
extern int lbl_8034B1F0[];
#pragma push
#pragma small_data off
#pragma scheduling invalid_target
void fn_802C5C40(int *arg0, int arg1, int arg2) {
    int temp_r30 = *arg0;
    int result = fn_802CAC28(lbl_8034B1F0, 0);
    int *entry = *(int **)((char *)arg2 + arg1 * 4 + 0x14);
    s16 field = *(s16 *)((char *)entry + 6);
    u16 adjusted = field - 1;
    *(int *)((char *)arg0 + arg1 * 4 + 0x14) =
        (int)fn_802C5A60(result, temp_r30, adjusted);
}
#pragma pop
extern int fn_8012C33C(char *);
extern void fn_801345D8(char *, int, const char *, ...);
extern int fn_802CAC44(char *, int);
extern int fn_802CAF8C(void);
extern int fn_802CAFF0(void);
extern int fn_802CAFC8(int);
__declspec(section ".sdata") extern const char lbl_8055D010[];
void fn_802C5CC4(void *arg0, int arg1, int arg2, int arg3) {
    char name[0x100];
    char temp[0x100];
    int other;
    int value;
    int index;
    u16 result;

    fn_802C595C(name, 0x100, (char *)arg0 + 4, arg1);
    if (arg3 != 0) {
        fn_801345D8(temp, 0x100, lbl_8055D010, arg3, name);
        if (fn_8012C33C(temp) != 0) {
            char *src = temp;
            int count = 0x100;
            char *dst = name;
            while (*dst++ = *src++) {
                if (--count <= 0) {
                    dst[-1] = '\0';
                    break;
                }
            }
        }
    }
    value = *(int *)arg0;
    index = fn_802CAC44(name, value);
    if (arg2 != 0) {
        result = fn_802C5BEC(value, fn_802CAF8C());
    } else {
        other = fn_802CAFF0();
        result = fn_802C5A50(fn_802CAFC8(index), other);
    }
    *(int *)((char *)arg0 + arg1 * 4 + 0x14) = (int)fn_802C5A60(index, value, result);
}

void fn_802C5DF0(void *arg0, void *arg1) {
    int offset = 0;
    int index = 0;
    while (index < *(int *)arg0) {
        void *table = *(void **)((char *)arg0 + 4);
        int value = *(int *)((char *)table + offset + 0xC);
        ((void (*)(int))arg1)(value);
        offset += 0x10;
        index += 1;
    }
}

void fn_802C5E6C(void *arg0, void *arg1) {
    void *temp = fn_802D6C44;
    ((void (*)(void *, void *))fn_802C5DF0)(arg1, temp);
}

#pragma pop
s32 fn_802C5EB8(void *, u32);

s32 fn_802C5E7C(void *arg0) {
    char *result = (char *)fn_802C5EB8(arg0, 0x5350484C);
    if (result != 0) {
        return (s32)(result + 8);
    }
    return 0;
}

#pragma scheduling invalid_target
s32 fn_802C5EB8(void *arg0, u32 arg1) {
    s32 count = *(s32 *)((char *)arg0 + 0x10);
    u32 *result = NULL;
    s32 i;
    for (i = 0; count > i; i++) {
        u32 *entry = *(u32 **)(*(char **)((char *)arg0 + 0x14) + i * 4);
        if (*entry == arg1) {
            result = entry;
            break;
        }
    }
    return (s32)result;
}
#pragma scheduling invalid_target
void *fn_802C5EFC(int arg0) {
    int count = lbl_804C13A8[0];
    void *entry = (void *)(unsigned long)lbl_804C13A8[2];
    int i;
    for (i = 0; i < count; i++, entry = (void *)((char *)entry + 0x10)) {
        if (*(u16 *)((char *)entry + 4) != 0 && *(int *)entry == arg0) {
            return entry;
        }
    }
    return 0;
}

extern void *fn_8012850C(int, void *);
extern void *fn_8002F37C(void *, void *, void *, int, int);
extern char jumptable_8034B1B8[];
extern void fn_802C6068(void *);
extern void fn_802C6074(s32 *);
void fn_802C5F48(void) {
    char *base = (char *)lbl_804C1338;
    char *jumpTable = jumptable_8034B1B8;
    char *entry;
    void *memory;
    int zero = 0;

    entry = base + 0x64;
    *(int *)(entry + 4) = 0x280;
    memory = fn_8012850C(0x2810, jumpTable + 0x44);
    *(void **)(entry + 8) = fn_8002F37C(memory, (void (*)(void *))fn_802C6074, 0, 0x10, 0x280);
    *(int *)(entry + 0) = zero;

    entry = base;
    *(int *)(entry + 4) = 0x800;
    *(void **)(entry + 8) = fn_8012850C(0xA000, jumpTable + 0x58);

    entry = base + 0x70;
    *(int *)(entry + 4) = 0x400;
    memory = fn_8012850C(0x4010, jumpTable + 0x70);
    *(void **)(entry + 8) = fn_8002F37C(memory, (void (*)(void *))fn_802C6068, 0, 0x10, 0x400);
    *(int *)(entry + 0) = zero;

    entry = base + 0x58;
    *(int *)(entry + 4) = 0x400;
    *(void **)(entry + 8) = fn_8012850C(0x1000, jumpTable + 0x80);
    *(int *)(entry + 0) = zero;

    entry = base + 0x7C;
    *(int *)(entry + 4) = 0x80;
    *(void **)(entry + 8) = fn_8012850C(0x1600, jumpTable + 0x90);
    *(int *)(entry + 0) = zero;
    *(int *)(base + 0x88) = -1;
    lbl_8055D00C = 1;
}

#pragma scheduling on
void fn_802C6068(void *arg0) {
    *(s16 *)((char *)arg0 + 4) = 0;
}

void fn_802C6074(s32 *arg0) {
    *arg0 = 0;
}

extern void fn_80128670(void *);
extern void fn_802C7A10(void *);
extern const char lbl_8034B258[];
extern const char lbl_8034B294[];
extern int (*fn_802E30C8_varargs)(const char *, ...);

struct SubList {
    int count;
    int capacity;
    void *buf;
};

struct MasterList {
    struct SubList list0;
    char pad0[0x58 - 0xC];
    struct SubList list58;
    struct SubList list64;
    struct SubList list70;
    struct SubList list7C;
    int unk88;
};

#define fn_802C6080_free1(list) do { \
    fn_80128670((list)->buf); \
    (list)->buf = 0; \
    (list)->capacity = 0; \
    (list)->count = 0; \
} while (0)

#define fn_802C6080_free2(list) do { \
    void *buf = (list)->buf; \
    if (buf != 0) { \
        fn_80128670((char *)buf - 0x10); \
    } \
    (list)->count = 0; \
    (list)->buf = 0; \
    (list)->capacity = 0; \
} while (0)
#pragma scheduling on
void fn_802C6080(void) {
    struct SubList {
        int count;
        int capacity;
        void *buf;
    };
    register struct SubList *e;
    register struct SubList *e58;
    register struct SubList *e7c;
    register char *base;
    register int offset;
    register int i;
    int zero;
    void *ptr;

    base = (char *)lbl_804C1338;
    e = (struct SubList *)(base + 0x64);
    for (i = 0, offset = 0; i < *(int *)(base + 0x64); i++, offset += 0x10) {
        if (*(int *)((char *)e->buf + offset) > 0) {
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034B258, i);
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_8034B294, ((int (*)(int))fn_802C7A10)(i));
        }
    }

    e7c = (struct SubList *)(base + 0x7C);
    fn_80128670(e7c->buf);
    ptr = *(void **)(base + 0x70 + 8);
    e7c->buf = 0;
    e7c->capacity = 0;
    *(int *)(base + 0x7C) = 0;
    if (ptr != 0) {
        fn_80128670((char *)ptr - 0x10);
    }

    e58 = (struct SubList *)(base + 0x58);
    zero = 0;
    ptr = e58->buf;
    *(int *)(base + 0x70) = zero;
    *(void **)(base + 0x70 + 8) = (void *)zero;
    *(int *)(base + 0x70 + 4) = zero;
    fn_80128670(ptr);

    e = (struct SubList *)base;
    e58->buf = (void *)zero;
    ptr = e->buf;
    e58->capacity = zero;
    *(int *)(base + 0x58) = zero;
    fn_80128670(ptr);

    e->buf = (void *)zero;
    ptr = *(void **)(base + 0x64 + 8);
    e->capacity = zero;
    *(int *)base = zero;
    if (ptr != 0) {
        fn_80128670((char *)ptr - 0x10);
    }

    *(int *)(base + 0x64) = 0;
    *(void **)(base + 0x64 + 8) = 0;
    *(int *)(base + 0x64 + 4) = 0;
}
void fn_802C6A84(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6A9C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AB4(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6ACC(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AE4(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AFC(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6B14(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6B2C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

int fn_802C6B44(int arg0) {
    void *result;
    int sp10;
    u32 spC;
    u8 sp9;
    u8 sp8;

    result = fn_8012C370(arg0, 0x4D4F444C, &spC, &sp10, &sp8, &sp9);
    if (result != 0) {
        if (sp9 != 0) {
            if (spC != 0xC) {
                fn_802E317C(lbl_8034B2E8, spC, 0xC, arg0);
            }
            DCStoreRangeNoSync(result, sp10);
            fn_802C61BC(result, arg0);
        }
        if (sp8 != 0) {
            fn_802C5DF0(result, fn_802D6C48);
        }
        return (int)result;
    }
    fn_802E317C(lbl_8034B314, arg0);
    return 0;
}

#pragma dont_inline on
int fn_802C6C20(int arg0) {
    return fn_8012C4E4((void *)arg0, (void *)fn_802C5E6C, arg0);
}
#pragma dont_inline reset

void fn_802C6C30(void) {}

void fn_802C6C34(void) { fn_802C53A8(); }

void fn_802C6C38(int arg0) {
    void *manager = fn_802C5390(arg0);
    int *count = *(int **)manager;
    if (*count-- > 0) {
        int *outer_info = *(int **)((char *)manager + 4);
        int *outer_count = *(int **)((char *)outer_info + 8);
        int *outer_table = *(int **)((char *)outer_info + 4);
        int i;
        for (i = 0; i < *outer_count; i++) {
            int *inner_info = *(int **)((char *)outer_table + i * 4);
            int *inner_count = *(int **)inner_info;
            int *inner_table = *(int **)((char *)inner_info + 4);
            int j;
            for (j = 0; j < *inner_count; j++) {
                int *item = *(int **)((char *)inner_table + j * 4);
                int *node = *(int **)((char *)item + (*(int *)((char *)manager + 8) << 2) + 0x14);
                *(int **)((char *)item + (*(int *)((char *)manager + 8) << 2) + 0x14) = 0;
                fn_802C5BA0(node);
            }
        }
        *(void **)((char *)manager + 4) = 0;
        *(int **)((char *)manager + 0xC) = 0;
    }
}

void fn_802C6CF8(int arg0) {
    int temp_r31;
    if (arg0 == -1) {
        ((int (*)(const char *, ...))fn_802E30C8)(lbl_8034B34C);
        return;
    }
    temp_r31 = fn_802C53A8();
    fn_802C6C38(arg0);
    fn_802C6C20(temp_r31);
}

s32 fn_802C6D5C(void *arg0) {
    s32 outer_offset;
    s32 outer_count;
    s32 inner_offset;
    s32 outer_index;
    char *entry;
    s32 inner_count;
    s32 inner_index;
    outer_count = *(s32 *)((char *)arg0 + 8);
    outer_index = 0;
    outer_offset = 0;
    while (outer_index < outer_count) {
        entry = *(char **)(*(char **)((char *)arg0 + 0xC) + outer_offset);
        inner_count = *(s32 *)entry;
        for (inner_index = 0, inner_offset = 0; inner_index < inner_count; inner_index++, inner_offset += 4) {
            char *item = *(char **)(*(char **)(entry + 4) + inner_offset);
            if (*(s32 *)item != 0) {
                return 1;
            }
        }
        outer_offset += 4;
        outer_index++;
    }
    return 0;
}

#pragma push
#pragma small_data off
#pragma pop
void fn_802C6FA8(void *arg0) {
    ((void (*)(void *, void *))fn_802C5DF0)(arg0, fn_802D6C48);
}

extern void fn_802D6C44(void);
void fn_802C6FB4(void *arg0) {
    ((void (*)(void *, void *))fn_802C5DF0)(arg0, fn_802D6C44);
}

void fn_802C6FC0(void *arg0, int arg1, int arg2) {
    if (fn_802C90E0() == 0) {
        ((int (*)(const char *, ...))fn_802E30C8)(lbl_8034B3DC, arg0);
    }
    fn_802C6DC4((int)arg0, fn_802C6B44((int)arg0), arg1, arg2);
}

void fn_802C703C(int arg0) {
    fn_802C6C38(arg0);
}

int fn_802C90E0(void);
int fn_802E30C8(const char*, int);
extern const char lbl_8034B34C[];
int fn_802C53A8();
int fn_802C6C20(int);
int fn_802C6B44(int);
void fn_802C6DC4(int, int, int, int);
extern const char lbl_8034B3DC[];
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);
void fn_802C7040(int arg0) {
    float spC;
    unsigned char sp8;
    void* temp;
    if (arg0 != -1) {
        temp = *(void**)((char*)fn_802C5390(arg0) + 4);
        if (fn_802C94A0((char*)temp + 0x20, &sp8, &spC, *(float*)((char*)temp + 0x1C))) {
            fn_802C57B4(arg0, 0, -1, sp8, spC);
        }
    }
}

extern unsigned char lbl_804C13C0[];
extern float lbl_80564EF0;
extern float PSVECSquareDistance(const float *, const float *);
void fn_802C729C(int arg0, float arg1) {
    char *outerEntry;
    int globalValue;
    int innerIndex;
    int *innerInfo;
    int outerOffset;
    void *vectorDistance;
    void *vectorHeight;
    int innerOffset;
    int *outerInfo;
    void *vectors;
    int outerIndex;
    float distance;
    float radius;

    if ((unsigned int)(*(unsigned int *)lbl_804C13C0 + 0x10000U) == 0xFFFFU)
        return;
    if (arg0 == -1)
        return;

    outerInfo = (int *)fn_802C53A8(arg0);
    if (*outerInfo <= 0)
        return;

    radius = lbl_80564EF0;
    vectors = (void *)fn_802C5E7C(outerInfo);
    vectorDistance = vectors;
    vectorHeight = vectors;

    for (outerIndex = 0, outerOffset = 0;
         outerIndex < *outerInfo;
         outerOffset += 0x10,
         vectorDistance = (char *)vectorDistance + 0x10,
         vectorHeight = (char *)vectorHeight + 0x10,
         outerIndex++) {
        if (*(int *)((char *)*(int **)((char *)outerInfo + 4) + outerOffset) != 2)
            continue;
        if (vectors != 0) {
            distance = PSVECSquareDistance((float *)(lbl_804C13C0 + 4),
                                           (float *)vectorDistance);
            if (!(distance < (arg1 + *(float *)((char *)vectorHeight + 0xC)) *
                             (arg1 + *(float *)((char *)vectorHeight + 0xC))))
                continue;
        }

        innerIndex = 0;
        globalValue = *(int *)lbl_804C13C0;
        innerOffset = 0;
        outerEntry = (char *)*(int **)((char *)outerInfo + 4) + outerOffset;
        innerInfo = *(int **)(outerEntry + 8);

        for (; innerIndex < *innerInfo;
             innerOffset += 4, innerIndex++) {
            int valid = 0;
            void **innerEntries = *(void ***)((char *)innerInfo + 4);
            void *element = *(void **)((char *)innerEntries + innerOffset);
            unsigned int type = *(unsigned int *)element;

            if (type < 13) {
                int skip;
                valid = 1;
                switch (type) {
                case 4:
                case 6:
                case 9:
                case 11:
                    skip = 1;
                    break;
                default:
                    skip = 0;
                    break;
                }
                if (skip)
                    valid = 0;
            }
            if (valid) {
                void *node = *(void **)((char *)element + 0x14);
                void *r4;
                fn_802C53C4(outerEntry, node, globalValue, -1, 0);
                r4 = ((void *(*)(void *))fn_802C57B0)(
                    *(void **)(outerEntry + 0xC));
                fn_802CC550(*(int *)node, r4, radius,
                            *(float *)((char *)r4 + 0x18));
            }
        }
    }
}

void fn_802C744C(int arg0, void *arg1) { fn_802C70AC(arg0, arg1, -1, -1); }

void fn_802C7458(int arg0, int arg1) {
    float spC;
    unsigned char sp8;
    int temp_r31;
    void *temp;

    if (arg0 != -1) {
        temp_r31 = lbl_8055D008;
        lbl_8055D008 = arg1;
        temp = *(void **)((char *)fn_802C5390(arg0) + 4);
        if (fn_802C94A0((char *)temp + 0x20, &sp8, &spC, *(float *)((char *)temp + 0x1C))) {
            fn_802C57B4(arg0, 0, -1, sp8, spC);
        }
        lbl_8055D008 = temp_r31;
    }
}

void fn_802C7730(void) { fn_802DABA4(); }

void fn_802C7734(void* alarm) {
    fn_802D0610(fn_802D0514(alarm));
}

void fn_802C7758(void);
#pragma dont_inline fn_802C7758
void fn_802C7758(void) {
    fn_802D0610(0);
}

void fn_802C7760(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    void *temp_r3 = fn_802C5390((int)arg0);
    *arg1 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x2C);
    *arg2 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x30);
    *arg3 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x34);
    *arg4 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x38);
    *arg5 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x3C);
    *arg6 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x40);
}

#pragma dont_inline fn_802C7760
void fn_802C77F0(void *arg0, f32 *arg1) {
    fn_802C7760(arg0, arg1, arg1 + 1, arg1 + 2, arg1 + 3, arg1 + 4, arg1 + 5);
}

float fn_802C7808(int arg0) {
    return *(float *)((char *)(*(void **)((char *)fn_802C5390(arg0) + 4)) + 0x1C);
}

s32 fn_802C7830(char *arg0, s32 arg1, signed char c) {
    s32 value = 0;
    register s32 is_digit;
    while (c != 0) {
        value <<= 4;
        is_digit = 0;
        if (c >= '0') {
            if (c <= '9') {
                is_digit = 1;
            }
        }
        if (is_digit != 0) {
            value |= c - '0';
        } else {
            value |= c - '7';
        }
        arg0++;
        c = *arg0;
    }
    return value;
}

#pragma scheduling invalid_target
void fn_802C7888(void *src, s32 count) {
    s32 i;
    if (count <= 0) return;
    for (i = 0; i < count; i++) {
        volatile u8 *source = (volatile u8 *)src;
        register volatile u8 *dest;
        s32 index;
        s32 *key = *(s32 **)((u8 *)src + 0x28);
        register u8 a, b;
        u32 word;
        if (key != 0) *key = -1;
        index = lbl_804C13B4[0];
        if (index < lbl_804C13B4[1]) {
            dest = (volatile u8 *)(unsigned long)lbl_804C13B4[2] + index * 0x2C;
            lbl_804C13B4[0] = index + 1;
        } else dest = 0;
        a = source[0]; b = source[1]; dest[0] = a;
        a = source[2]; dest[1] = b;
        b = source[3]; dest[2] = a;
        a = source[4]; dest[3] = b;
        b = source[5]; dest[4] = a;
        a = source[6]; dest[5] = b;
        b = source[7]; dest[6] = a;
        a = source[8]; dest[7] = b;
        b = source[9]; dest[8] = a;
        a = source[10]; dest[9] = b;
        b = source[11]; dest[10] = a;
        a = source[12]; dest[11] = b;
        b = source[13]; dest[12] = a;
        a = source[14]; dest[13] = b;
        b = source[15];
        dest[14] = a;
        word = *(volatile u32 *)(source + 0x10);
        dest[15] = b;
        b = source[0x14];
        *(volatile u32 *)(dest + 0x10) = word;
        a = source[0x15]; dest[0x14] = b;
        b = source[0x16]; dest[0x15] = a;
        a = source[0x17]; dest[0x16] = b;
        b = source[0x18]; dest[0x17] = a;
        a = source[0x19]; dest[0x18] = b;
        b = source[0x1A]; dest[0x19] = a;
        a = source[0x1B]; dest[0x1A] = b;
        b = source[0x1C]; dest[0x1B] = a;
        a = source[0x1D]; dest[0x1C] = b;
        b = source[0x1E]; dest[0x1D] = a;
        a = source[0x1F]; dest[0x1E] = b;
        b = source[0x20]; dest[0x1F] = a;
        a = source[0x21]; dest[0x20] = b;
        b = source[0x22]; dest[0x21] = a;
        a = source[0x23]; dest[0x22] = b;
        word = *(volatile u32 *)(source + 0x24);
        dest[0x23] = a;
        *(volatile u32 *)(dest + 0x24) = word;
        word = *(volatile u32 *)(source + 0x28);
        *(volatile u32 *)(dest + 0x28) = word;
        src = (u8 *)src + 0x2C;
    }
}
#pragma scheduling on
extern int lbl_804C13B4[];
extern void fn_802C7A00(void);
void fn_802C7A00(void) {
    lbl_804C13B4[0] = 0;
}

void fn_802C7A10(void* alarm) {
    fn_8012C58C(fn_802C53A8(alarm));
}

void fn_802C7A34(void) { fn_802DA704(); }

extern void fn_802DA80C(void);
void fn_802C7A38(void) { fn_802DA80C(); }

extern void fn_802DA918(void);
void fn_802C7A3C(void) { fn_802DA918(); }

extern void fn_802DA80C(void);
extern void fn_802DA918(void);
extern void fn_802DA550(void);
void fn_802C7A40(void) { fn_802DA550(); }

extern s8 lbl_8055FC20;
extern void fn_802C543C(void);
void fn_802C7A44(void) {
    lbl_8055FC20 = 1;
    fn_802C543C();
}

void fn_802C7A50(void) {
    int i = 0;
    do {
        fn_802C5720(i);
        i++;
    } while (i < 9);
    lbl_8055FC20 = 0;
}

void fn_802C7A94(int arg0) {
    fn_802C7758();
    fn_802C5720(arg0);
    if (arg0 == 9) {
        fn_802C543C();
    }
}

#pragma dont_inline on
void fn_802C7AD4(void) {
    fn_802C7A94(9);
}
#pragma dont_inline reset
void fn_802D754C(void);
void fn_802C7ADC(void) { fn_802D754C(); }

void fn_802C8218(s32 arg0) {
    s32 var_r0;

    var_r0 = 1;
    if (arg0 != 0) {
        var_r0 = 2;
    }
    lbl_8055D00C = var_r0;
}

void fn_802C8230(void) {
    fn_802DB2B4();
}

extern void fn_802DB2B8(void);
void fn_802C8234(void) { fn_802DB2B8(); }

extern int lbl_8055D008;
extern int fn_8012C4E4(void *, void *, int);

