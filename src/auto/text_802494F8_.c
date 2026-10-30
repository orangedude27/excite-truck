extern void *memset(void *, int, unsigned int);
extern void *lbl_8055F28C;
static inline int find_sound_entry_inline(int *key) {
    void *table = lbl_8055F28C;
    int i;
    int count = *(int *)((char *)table + 4);
    for (i = 0; i < count; i++) {
        int value;
        int id;
        value = *(int *)(*(char **)table + i * 0x18);
        id = *key;
        if (value == id) return i;
    }
    return -1;
}
static inline int has_sound_entry(int *key) {
    return find_sound_entry_inline(key) != -1;
}
static inline int find_sound_entry(int id);
typedef signed long s32;
typedef signed char s8;
typedef unsigned char u8;
typedef int M2C_UNK;
#define M2C_FIELD(p,T,o) (*(T*)((u8*)(p)+(o)))
typedef s32 (*UnkFunc)(s32);
extern s32 lbl_802FA4B0[];
extern s32 fn_80257BB8(void *, s32);
extern s32 fn_801345D8(void *, s32, s32 *, s32, s32 *);
extern s32 lbl_80343E70;
extern s32 lbl_8055BFF8;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80236074(void*, unsigned int);
void fn_80128668(void*);
extern void* lbl_8055BF34;
s32 fn_80214D04(void);
s32 fn_802494F8(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

s32 fn_80249538(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

void fn_80249578(void *arg0) {
    fn_8023E52C(*(s32 *)*(void **)((char *)arg0 + 0x10));
}

void fn_80249584(void) {}

void fn_80249588(void) {}

#pragma scheduling on
int fn_8024958C(int *arg0) {
    int result = arg0[2] == 0x180302;
    if (result) result = find_sound_entry_inline(arg0) != -1;
    if (result) result = *(unsigned char *)(*(char **)lbl_8055F28C + find_sound_entry_inline(arg0) * 0x18 + 0x14);
    return result;
}
int fn_80249660(void) { return 1; }

int fn_80249668(int *arg0) {
    extern char *lbl_802FA4C8[3];
    extern unsigned char lbl_8055F290;
    extern unsigned char *lbl_8055F294;
    extern int fn_802411D4(void);
    char *strings[3];
    char **stringPtr = lbl_802FA4C8;
    char *src;
    unsigned char *dst;
    unsigned char c;
    int index;
    int count;

    strings[0] = *stringPtr++;
    strings[1] = *stringPtr++;
    strings[2] = *stringPtr;
    index = fn_80214D04();
    src = strings[index];
    dst = lbl_8055F294;
    count = 0x100;
    goto copy;
decrement:
    count--;
    if (count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto decrement;
done:
    if (lbl_8055F290 != 0 && fn_802411D4() == 0) {
        *(volatile int *)arg0 = -1;
        return 1;
    }
    return 0;
}

void fn_80249720(void) {
    lbl_8055BF34 = (void*)fn_80214D04();
}

void fn_80249744(void) {
    fn_80214CB4(lbl_8055BF34);
}

void fn_8022D7C4(void *, unsigned int);
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8024A110(void *this_, s32 flag) {
    if (this_) {
        if (this_ != 0) {
            fn_8022D7C4(this_, 0);
        }
        if (flag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

s32 fn_8024A16C(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668((void *)arg0);
    }
    return arg0;
}

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80236074((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
    }
    return arg0;
}

#pragma scheduling invalid_target
void *fn_8024A204(void *arg0, s32 arg1) {
    char *base;
    unsigned int offset;
    s32 zero = 0;
    if (arg0 != 0) {
        base = (char *)arg0;
        *(s32 *)(base + 0x11C) = zero;
        if ((base + 0x10 != 0) && ((char *)arg0 + 0x10 != 0)) {
            offset = 0x10;
            *(s32 *)((char *)arg0 + offset) = zero;
            *(s32 *)((char *)arg0 + 0x14) = zero;
            *(s32 *)((char *)arg0 + 0x18) = zero;
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}
#pragma scheduling reset
void *fn_8024A268(void *arg0, s32 arg1) {
    volatile s32 *p;
    volatile s32 test;
    if (arg0 != 0) {
        p = (volatile s32 *)arg0;
        p[4] = 0;
        test = arg1;
        p[6] = -1;
        if (test > 0) {
            p[7] = 0;
            fn_80128668(arg0);
        } else {
            p[7] = 0;
        }
    }
    return arg0;
}

void fn_8024A2BC(void *arg0, s32 arg1, s32 arg2) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    char *entry = (char *)arg0;
    s32 index = 0;
    if (count <= 0) return;
    for (; index < count; index++) {
        if (arg1 == *(s32 *)(entry + 0x20) && arg2 == *(s32 *)(entry + 0x24)) {
            *(s32 *)((char *)arg0 + 0x10) = index;
            return;
        }
        entry += 0xC;
    }
}

extern char lbl_80343E7C[];
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8024A304(void *arg0, void **arg1, int arg2, int arg3) {
    extern unsigned char lbl_8055F290;
    int zero = 0;
    register void *object;
    register void **list;
    register int index;
    (void)arg3;
    *(int *)((char *)arg0 + 0x1C) = arg2;
    object = arg0;
    *(int *)((char *)object + 0x10) = zero;
    list = arg1;
    index = zero;
    *(int *)((char *)object + 0x14) = zero;
    {
        register void *record;
        register int offset;
        register int archiveIndex;
        register int archiveCount;
        offset = zero;
        goto outer_check;
outer_body:
        if (stricmp((char *)fn_800081BC(
                        *(void **)((char *)*(void **)*list + offset)),
                    *(char **)((char *)object + 0x1C)) == 0) {
            void *header = *list;
            int itemCount = *(int *)((char *)object + 0x14);
            char *array = *(char **)header;
            char *entry = array + offset;
            record = *(void **)(entry + 4);
            {
                char *item = (char *)object + itemCount * 0xC;
                *(int *)(item + 0x20) = *(int *)((char *)record + 4);
            }
            archiveCount = *(int *)((char *)fn_80012820(
                             *(int *)((char *)record + 4)) + 0x70);
            for (archiveIndex = 0; archiveIndex < archiveCount;
                 archiveIndex++) {
                if (record != (void *)fn_80012870(
                        *(int *)((char *)record + 4), archiveIndex))
                    continue;
                break;
            }
            if (archiveIndex >= archiveCount)
                archiveIndex = -1;
            *(int *)((char *)object +
                     *(int *)((char *)object + 0x14) * 0xC + 0x24) =
                archiveIndex;
            {
                int tableIndex = 0;
                int tableOffset = 0;
                void *table = lbl_8055F28C;
                int tableCount = *(int *)((char *)table + 4);
                for (; tableIndex < tableCount;
                     tableIndex++, tableOffset += 0x18) {
                    if (*(int *)(*(char **)table + tableOffset) !=
                        *(int *)record)
                        continue;
                    goto table_found;
                }
                tableIndex = -1;
table_found:
                if (lbl_8055F290 != 0 && tableIndex >= 0) {
                    *(int *)((char *)object +
                             *(int *)((char *)object + 0x14) * 0xC + 0x28) =
                        *(int *)(*(char **)table + tableIndex * 0x18 + 4);
                } else {
                    int key = fn_80012910(*(int *)record);
                    void *dispatchObject =
                        *(void **)((char *)record + 0x20);
                    int (*method)(void *, char *, int) =
                        (int (*)(void *, char *, int))
                        (*(void ***)dispatchObject)[6];
                    *(int *)((char *)object +
                             *(int *)((char *)object + 0x14) * 0xC + 0x28) =
                        method(dispatchObject, lbl_80343E7C, key);
                }
            }
            *(int *)((char *)object + 0x14) =
                *(int *)((char *)object + 0x14) + 1;
        }
        offset += 8;
        index += 1;
outer_check:
        if (index < *(int *)((char *)*list + 4))
            goto outer_body;
    }
}
#pragma scheduling reset
#pragma use_lmw_stmw on
int stricmp(const char*, const char*);
void fn_8024A4B8(const char** arg0, const char** arg1) {
    stricmp(*arg0, *arg1);
}

s32 fn_8024974C();
void fn_8024A4C4(s32 arg0, s32 arg1, s32 arg2) {
    fn_8024974C(arg0, arg1, arg2, 0);
}

s32 fn_8024A6A4(s32 *arg0) {
    if (fn_802411D4() == 0) {
        *(volatile s32 *)arg0 = -1;
        return 1;
    }
    return 0;
}

void *fn_8024AC54(void *arg0, int arg1) {
    if (arg0 != 0) {
        if ((unsigned int)arg0 + 0x18 != 0) {
            if ((unsigned int)arg0 + 0x18 != 0) {
                *(int *)((char *)arg0 + 0x18) = 0;
                *(int *)((char *)arg0 + 0x1C) = 0;
                *(int *)((char *)arg0 + 0x20) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

extern void *fn_8024B73C(void *, const char *, void *);
extern void fn_8024B830(void *, s32);
extern s32 fn_8024B874(s32);
extern s32 fn_8024B87C(void *, s32);
extern s32 fn_8024B8A4(void *, s32);
extern s32 fn_8024B8CC(s32);
extern s32 fn_8024B8D4(s32);
extern s32 fn_802146BC(s32 *, s32, s32, s32, s32, s32, s32, s32);
extern void fn_80236074(void *, unsigned int);
extern s32 lbl_802FA4FC[];
extern char lbl_80343998[];
extern s32 lbl_80498998[];
extern int lbl_8055B860;
extern int lbl_8055BF68;
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
s32 fn_8024ACB4(s32 *arg0, s32 arg1, void *arg2) {
    char storage[0x1F8];
    register s32 *output = arg0;
    register s32 key = arg1;
    register void *work = arg2;
    register char *name = lbl_80343998;
    register s32 zero = 0;
    register s32 three = 3;
    register s32 *configStackPointer = (s32 *)storage;
    s32 result;

    if (fn_802411D4() == 0) {
        return 0;
    }
    fn_8024B73C((char *)storage + 0x18, (const char *)key, work);
    fn_8024B830((char *)storage + 0x18, *output);
    work = (char *)storage + 0x18;

    configStackPointer[49] = zero;
    configStackPointer[46] = (s32)&lbl_8055BF68;
    configStackPointer[48] = (s32)work;
    configStackPointer[47] = 5;
    configStackPointer[50] = zero;

    configStackPointer[53] = fn_8024B87C(work, 0);
    configStackPointer[51] = (s32)(name + 0x16c);
    configStackPointer[52] = three;
    configStackPointer[54] = zero;
    configStackPointer[55] = (s32)work;
    configStackPointer[59] = fn_8024B8A4(work, 0);
    configStackPointer[56] = (s32)(name + 0x16c);
    configStackPointer[57] = (s32)work;
    configStackPointer[58] = zero;
    configStackPointer[60] = zero;

    configStackPointer[63] = fn_8024B87C(work, 1);
    configStackPointer[61] = (s32)(name + 0x178);
    configStackPointer[62] = three;
    configStackPointer[64] = zero;
    configStackPointer[65] = (s32)work;
    configStackPointer[69] = fn_8024B8A4(work, 1);
    configStackPointer[66] = (s32)(name + 0x178);
    configStackPointer[67] = (s32)work;
    configStackPointer[68] = zero;
    configStackPointer[70] = zero;

    configStackPointer[73] = fn_8024B87C(work, 2);
    configStackPointer[71] = (s32)(name + 0x184);
    configStackPointer[72] = three;
    configStackPointer[74] = zero;
    configStackPointer[75] = (s32)work;
    configStackPointer[79] = fn_8024B8A4(work, 2);
    configStackPointer[76] = (s32)(name + 0x184);
    configStackPointer[77] = (s32)work;
    configStackPointer[78] = zero;
    configStackPointer[80] = zero;

    configStackPointer[83] = fn_8024B87C(work, 3);
    configStackPointer[81] = (s32)(name + 0x190);
    configStackPointer[82] = three;
    configStackPointer[84] = zero;
    configStackPointer[85] = (s32)work;
    configStackPointer[89] = fn_8024B8A4(work, 3);
    configStackPointer[86] = (s32)(name + 0x190);
    configStackPointer[87] = (s32)work;
    configStackPointer[88] = zero;
    configStackPointer[90] = zero;

    configStackPointer[93] = fn_8024B87C(work, 4);
    configStackPointer[91] = (s32)(name + 0x19c);
    configStackPointer[92] = three;
    configStackPointer[94] = zero;
    configStackPointer[95] = (s32)work;
    configStackPointer[99] = fn_8024B8A4(work, 4);
    configStackPointer[96] = (s32)(name + 0x19c);
    configStackPointer[97] = (s32)work;
    configStackPointer[98] = zero;
    configStackPointer[100] = zero;

    configStackPointer[101] = (s32)(name + 0xCC);
    configStackPointer[102] = 0x12;
    configStackPointer[103] = fn_8024B8CC((s32)work);
    configStackPointer[104] = zero;
    configStackPointer[105] = (s32)work;
    configStackPointer[106] = (s32)(name + 0xCC);
    configStackPointer[107] = 2;
    configStackPointer[108] = fn_8024B8D4((s32)work);
    configStackPointer[109] = zero;
    configStackPointer[110] = (s32)work;
    configStackPointer[111] = (s32)(name + 0xBC);
    configStackPointer[112] = three;
    configStackPointer[113] = fn_8024B874((s32)work);
    configStackPointer[114] = zero;
    configStackPointer[115] = (s32)work;
    configStackPointer[116] = (s32)&lbl_8055B860;
    configStackPointer[117] = 6;
    configStackPointer[118] = zero;
    configStackPointer[119] = -1;
    configStackPointer[120] = 0x1B;
    configStackPointer[121] = lbl_80498998[0];
    configStackPointer[122] = lbl_80498998[1];
    configStackPointer[123] = lbl_80498998[2];
    configStackPointer[124] = lbl_80498998[3];
    configStackPointer[125] = lbl_80498998[4];
    configStackPointer[0] = lbl_802FA4FC[0];
    configStackPointer[1] = (s32)&configStackPointer[46];
    configStackPointer[2] = lbl_802FA4FC[2];
    configStackPointer[3] = lbl_802FA4FC[3];
    configStackPointer[4] = lbl_802FA4FC[4];

    result = fn_802146BC(configStackPointer, -0x3E7, -0x3E7, 1,
                         lbl_802FA4FC[4], lbl_802FA4FC[3],
                         lbl_802FA4FC[2], lbl_802FA4FC[0]);
    if (result != -1) {
        *output = result;
        fn_80236074((char *)storage + 0x64, -1);
        configStackPointer[12] = zero;
        configStackPointer[13] = zero;
        configStackPointer[14] = zero;
        return 1;
    }
    fn_80236074((char *)storage + 0x64, -1);
    configStackPointer[12] = zero;
    configStackPointer[13] = zero;
    configStackPointer[14] = zero;
    return 0;
}
#pragma pop
void *fn_8024AFF8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80236074((char *)arg0 + 0x4C, -1);
        if ((unsigned int)arg0 + 0x18 != 0) {
            if ((unsigned int)arg0 + 0x18 != 0) {
                *(s32 *)((char *)arg0 + 0x18) = 0;
                *(s32 *)((char *)arg0 + 0x1C) = 0;
                *(s32 *)((char *)arg0 + 0x20) = 0;
            }
        }
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

extern s32 fn_80215228(void);
extern s32 fn_8024A6EC(s32 *, void *);
extern s32 fn_8024ACB4(s32 *, s32, void *);
extern u8 lbl_8055F298;
u8 fn_8024B070(s32 *arg0, s32 **arg1) {
    s32 sp8;
    s32 i = 0;
    s32 offset = 0;
    s32 count = *(s32 *)((u8 *)arg1 + 4);

    if (count > 0) {
        for (; i < count; i++) {
            s32 item = *(s32 *)((u8 *)*arg1 + offset);
            s32 key = *arg0;
            if (item != key) {
                offset += 0x18;
                continue;
            }
            goto found;
        }
    }
    i = -1;
found:
    if (i >= 0) {
        sp8 = *(s32 *)((u8 *)*arg1 + i * 0x18 + 0xC);
    } else {
        sp8 = 0;
    }
    if (fn_80215228() != 0) {
        lbl_8055F298 = 0;
    }
    for (;;) {
        if (fn_8024ACB4(arg0, sp8, arg1) != 0) {
            lbl_8055F298 = 1;
            break;
        }
        if (lbl_8055F298 == 0 && fn_8024A6EC(&sp8, arg1) == 0) {
            break;
        }
    }
    return lbl_8055F298;
}

extern void *fn_8001285C(s32);
extern int strlen(const char *);
extern int strncmp(const char *, const char *, unsigned int);
extern s32 lbl_8055BFC0;
extern s32 lbl_8055BFC8;
extern s32 lbl_8055BFD0;
extern char lbl_804989AC[];
#pragma scheduling invalid_target
#pragma inline no fn_8024B178
extern s32 fn_8024B178(s32);
#pragma inline no fn_8024B178
s32 fn_8024B178(s32 arg0) {
    void *manager;
    void *object;
    register char *result;
    register char *prefix;
    s32 comparison;
    char *buffer;

    manager = ((void *(*)(s32))fn_8001285C)(arg0);
    object = *(void **)((char *)manager + 0x20);
    result = ((char *(*)(void *, const char *))(*(void **)((char *)*(void **)object + 0x14)))(
        object, (const char *)&lbl_8055BFC0);
    prefix = (char *)&lbl_8055BFC8;
    comparison = strncmp(result, prefix, strlen(prefix));
    if (comparison != 0)
        goto mismatch;
    result += strlen(prefix);
    buffer = lbl_804989AC;
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(
        buffer, 0x21, (const char *)&lbl_8055BFD0, result);
    return (s32)buffer;
mismatch:
    return comparison;
}
int fn_8024B214(char *arg0, char *arg1) {
    unsigned char first = ((unsigned char *)arg0)[4];
    if (first != 0 && ((unsigned char *)arg1)[4] == 0) return 1;
    if (((unsigned char *)arg1)[4] != 0 && first == 0) return -1;
    return stricmp(*(char **)arg0, *(char **)arg1);
}

extern void *fn_80131234(void *);
extern char lbl_80343B54[];
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void fn_8024B260(arg0)
void *arg0;
{
    s32 selected;
    char *search;
    s32 i;
    s32 offset;
    s32 one;
    s32 zero;
    void *list;
    u8 *entry;
    u8 *record;
    u8 **strings;

    selected = fn_80214D04();
    *(s32 *)((u8 *)arg0 + 0x280) = selected;
    strings = *(u8 ***)((u8 *)arg0 + 0x18);
    search = (char *)strings[selected * 2];
    memset((u8 *)arg0 + 0x78, 0, 0x208);

    one = 1;
    *(s32 *)((u8 *)arg0 + 0xDC) = one;
    i = 0;
    offset = 0;
    *(s32 *)((u8 *)arg0 + 0x144) = one;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 0x1AC) = one;
    *(s32 *)((u8 *)arg0 + 0x214) = one;
    *(s32 *)((u8 *)arg0 + 0x27C) = one;

    goto check_loop;
loop_body:
    entry = *(u8 **)list + offset;
    if (stricmp(search, *(char **)(entry + 0xC)) == 0) {
        record = (u8 *)arg0 + *(s32 *)(entry + 8) * 0x68 + 0x78;
        {
            char *src = *(char **)(entry + 4);
            char *dst = (char *)record;
            s32 remaining = 0x32;
            while ((s8)(*dst++ = *src++) != 0) {
                if (--remaining <= 0) {
                    dst[-1] = zero;
                    break;
                }
            }
        }
        if (entry[0x14] != 0) {
            char *src = *(char **)(entry + 0x10);
            char *dst = (char *)(record + 0x32);
            s32 remaining = 0x32;
            while ((s8)(*dst++ = *src++) != 0) {
                if (--remaining <= 0) {
                    dst[-1] = zero;
                    break;
                }
            }
            *(s32 *)(record + 0x64) = one;
        } else {
            char *src = (char *)fn_80131234(lbl_80343B54);
            char *dst = (char *)(record + 0x32);
            s32 remaining = 0x32;
            while ((s8)(*dst++ = *src++) != 0) {
                if (--remaining <= 0) {
                    dst[-1] = zero;
                    break;
                }
            }
            *(s32 *)(record + 0x64) = zero;
        }
    }
    offset += 0x18;
    i += 1;
check_loop:
    list = *(void **)((u8 *)arg0 + 0x74);
    if (i < *(s32 *)((u8 *)list + 4)) {
        goto loop_body;
    }
}
#pragma pop
extern void fn_80265DCC(void *, int, int, void *);
extern char lbl_80343BD0[];
extern int stricmp(const char *, const char *);
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void *fn_8024B3E8(void *arg0, void *arg1, int arg2) {
    typedef struct ArchiveEntry {
        char pad0[0xC];
        char *name;
        unsigned char pad10[8];
    } ArchiveEntry;
    register int active = 1;
    register ArchiveEntry *entry;
    register int itemOffset;
    register int found;
    register int innerIndex;
    register int outerOffset;
    register int outerIndex;
    volatile int *itemCount = (volatile int *)((char *)arg0 + 0x1C);
    (void)arg2;
    *(void **)((char *)arg0 + 0x74) = arg1;
    *(int *)((char *)arg0 + 0x14) = 0;
    *(char **)arg0 = lbl_80343BD0;
    *(void **)((char *)arg0 + 0x18) = (char *)arg0 + 0x24;
    *(int *)((char *)arg0 + 0x20) = 10;
    *itemCount = 0;
    *((unsigned char *)arg0 + 0x284) = 0;
    outerIndex = 0;
    outerOffset = 0;
    while (outerIndex < *(int *)((char *)arg1 + 4)) {
        entry = (ArchiveEntry *)((char *)*(void **)arg1 + outerOffset);
        found = 1;
        innerIndex = 0;
        itemOffset = 0;
        while (innerIndex < *itemCount) {
            if (((unsigned char *)entry)[0x14] == 0 ||
                stricmp(*(char **)(*(char **)((char *)arg0 + 0x18) + itemOffset),
                        entry->name) == 0)
                found = 0;
            itemOffset += 8;
            innerIndex++;
        }
        if (found) {
            int n = *itemCount;
            void * volatile *itemsField =
                (void * volatile *)((char *)arg0 + 0x18);
            void *items = *itemsField;
            void *slot;
            *itemCount = n + 1;
            slot = (char *)items + n * 8;
            *(char **)slot = entry->name;
            *((unsigned char *)slot + 4) = ((unsigned char *)entry)[0x15];
        }
        if (((unsigned char *)entry)[0x14] != 0 &&
            ((unsigned char *)entry)[0x15] != 0)
            *((unsigned char *)arg0 + 0x284) = active;
        outerOffset += 0x18;
        outerIndex++;
    }
    fn_80265DCC(*(void **)((char *)arg0 + 0x18),
                *itemCount, 8, fn_8024B214);
    memset((char *)arg0 + 0x78, 0, 0x208);
    *(int *)((char *)arg0 + 0x280) = -1;
    return arg0;
}
#pragma scheduling reset
#pragma use_lmw_stmw reset
void fn_8024B544(void *arg0, char *arg1) {
    register s32 offset;
    register s32 index;
    *(s32 *)((char *)arg0 + 0x280) = 0;
    if (arg1 != 0) {
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)arg0 + 0x1C)) {
            if (stricmp(*(char **)((char *)*(s32 **)((char *)arg0 + 0x18) + offset), arg1) == 0) {
                *(s32 *)((char *)arg0 + 0x280) = index;
            }
            offset += 8;
            index++;
        }
    }
}

s32 fn_8024B5D4(void *arg0, s32 arg1) {
    extern s32 lbl_8055BFD8;
    if (arg1 < *(s32 *)((char *)arg0 + 0x1C)) {
        return *(s32 *)((char *)*(s32 **)((char *)arg0 + 0x18) + arg1 * 8);
    }
    return (s32)&lbl_8055BFD8;
}

s32 fn_8024B5F8(s32 arg0, s32 arg1) {
    return arg0 + arg1 * 0x68 + 0xAA;
}

s32 fn_8024B608(s32 arg0, s32 arg1) {
    return arg0 + arg1 * 0x68 + 0x78;
}

s32 fn_8024B618(s32 arg0, s32 arg1) {
    return arg0 + arg1 * 0x68 + 0xDC;
}

void fn_8024B628(void *arg0) {
    s32 index;
    fn_80214CB4(*(s32 *)((char *)arg0 + 0x280));
    index = *(s32 *)((char *)arg0 + 0x1C);
    goto loop_test;
    do {
        fn_80214A9C(index + 1);
        index++;
    loop_test:
        ;
    } while (index < *(s32 *)((char *)arg0 + 0x20));
    if (*(unsigned char *)((char *)arg0 + 0x284) == 0)
        fn_80214A9C(10);
    else
        fn_80214AF0(10);
    fn_8024B260(arg0);
}

void fn_8024B6A8(void) {
    fn_8024B260();
}

void fn_8024B6AC(void *arg0) {
    s32 index;
    void **array;
    char c;
    char *src;
    s32 count;
    char *dst;

    index = fn_80214D04();
    *(s32 *)((char *)arg0 + 0x9C) = index;
    array = *(void ***)((char *)arg0 + 0x18);
    dst = (char *)arg0 + 0x64;
    count = 0x32;
    src = *(char **)((char *)array[index] + 0x10);
    goto copy;
decrement:
    count--;
    if (count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto decrement;
done:
    array = *(void ***)((char *)arg0 + 0x18);
    index = *(s32 *)((char *)arg0 + 0x9C);
    *(s32 *)((char *)arg0 + 0x98) = *(s32 *)array[index];
}

#pragma push
#pragma scheduling on
#pragma opt_loop_invariants off
#pragma use_lmw_stmw off
#pragma opt_common_subs off
void *fn_8024B73C(void *arg0, const char *arg1, void *arg2) {
    extern char lbl_80343B70[];
    void fn_80236008(void *, s32, s32);
    void fn_80236134(void *, s32, s32);
    s32 fn_8024B178(s32);
    char *entry;
    s32 offset, index;
    *(volatile s32 *)((char *)arg0 + 0x14) = 0;
    *(void **)arg0 = lbl_80343B70;
    *(void **)((char *)arg0 + 0x18) = (char *)arg0 + 0x24;
    *(s32 *)((char *)arg0 + 0x20) = 10;
    *(s32 *)((char *)arg0 + 0x1C) = 0;
    fn_80236008((char *)arg0 + 0x4C, 10, 0);
    index = 0;
    offset = 0;
    while (index < *(s32 *)((char *)arg2 + 4)) {
        entry = *(char **)arg2 + offset;
        if (stricmp(arg1, *(char **)(entry + 0xC)) == 0) {
            register s32 next;
            register void **array;
            register s32 n;
            n = *(s32 *)((char *)arg0 + 0x1C);
            array = *(void ***)((char *)arg0 + 0x18);
            next = n + 1;
            *(s32 *)((char *)arg0 + 0x1C) = next;
            array[n] = entry;
            fn_80236134((char *)arg0 + 0x4C, *(s32 *)entry, fn_8024B178(*(s32 *)entry));
        }
        offset += 0x18;
        index++;
    }
    {
        register s32 zero = 0;
        register s32 invalid = -1;
        *(s32 *)((char *)arg0 + 0x98) = invalid;
        *(char *)((char *)arg0 + 0x64) = zero;
        *(s32 *)((char *)arg0 + 0x9C) = invalid;
    }
    return arg0;
}
#pragma pop
void fn_8024B830(void *arg0, s32 arg1) {
    s32 offset;
    s32 index;
    *(s32 *)((char *)arg0 + 0x9C) = -1;
    index = 0;
    offset = 0;
    while (index < *(s32 *)((char *)arg0 + 0x1C)) {
        if (arg1 == **(s32 **)((char *)*(s32 **)((char *)arg0 + 0x18) + offset))
            *(s32 *)((char *)arg0 + 0x9C) = index;
        offset += 4;
        index++;
    }
}

s32 fn_8024B874(s32 arg0) { return arg0 + 0x64; }

s32 fn_8024B87C(void *arg0, s32 arg1) {
    extern s32 lbl_8055BFD8;
    if (arg1 < *(s32 *)((char *)arg0 + 0x1C)) {
        s32 **array = *(s32 ***)((char *)arg0 + 0x18);
        return *(s32 *)((char *)array[arg1] + 4);
    }
    return (s32)&lbl_8055BFD8;
}

s32 fn_8024B8A4(void *arg0, s32 arg1) {
    if (arg1 < *(s32 *)((char *)arg0 + 0x1C)) {
        return *(s32 *)*(s32 **)(*(s32 **)((char *)arg0 + 0x18) + arg1);
    }
    return -1;
}

s32 fn_8024B8CC(s32 arg0) {
    return arg0 + 0x4C;
}

s32 fn_8024B8D4(s32 arg0) {
    return arg0 + 0x98;
}

void fn_8024B8DC(void *arg0) {
    unsigned offset;
    long index;
    fn_80214CB4(*(s32 *)((char *)arg0 + 0x9C));
    index = 0;
    offset = 0;
    while (index < *(s32 *)((char *)arg0 + 0x20)) {
        if (index < *(s32 *)((char *)arg0 + 0x1C)) {
            if (*(unsigned char *)((char *)*(s32 *)((char *)*(s32 **)((char *)arg0 + 0x18) + offset) + 0x14) == 0) {
                fn_80214B44(index + 1);
            }
        } else {
            fn_80214A9C(index + 1);
        }
        index += 1;
        offset += 4;
    }
}

void fn_8024B970(void *arg0) {
    fn_8024B6AC(arg0);
}

s32 fn_8024B974(void *arg0) {
    return *(s32 *)((char *)arg0 + *(s32 *)((char *)arg0 + 0x10) * 0xC + 0x28);
}

void fn_8024B988(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    s32 index = *(s32 *)((char *)arg0 + 0x10);
    *(s32 *)((char *)arg0 + 0x10) = (count + index - 1) % count;
}

void fn_8024B9AC(void *arg0) {
    s32 index = *(s32 *)((char *)arg0 + 0x10);
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    *(s32 *)((char *)arg0 + 0x10) = (index + 1) % count;
}

void fn_8024B9CC(void *arg0, s32 *arg1, s32 *arg2) {
    register char *entry = (char *)arg0 + *(s32 *)((char *)arg0 + 0x10) * 0xC;
    register s32 value2 = *(s32 *)(entry + 0x24);
    register s32 value1 = *(s32 *)(entry + 0x20);
    *arg1 = value1;
    *arg2 = value2;
}

s32 fn_8024B9EC(void *arg0) {
    return *(s32 *)(*(char **)((char *)arg0 + 0x10) + *(s32 *)((char *)arg0 + 0x11C) * 8);
}

void fn_8024BA00(void *arg0) {
    s32 count;
    s32 index;
    s32 sum;
    s32 value;
    s32 item;
    s32 *items;

    count = *(s32 *)((char *)arg0 + 0x14);
    index = *(s32 *)((char *)arg0 + 0x11C);
    items = *(s32 **)((char *)arg0 + 0x10);
    sum = count + index;
    value = *(s32 *)((char *)arg0 + 0x120);
    index = (sum - 1) % count;
    *(s32 *)((char *)arg0 + 0x11C) = index;
    item = items[index * 2 + 1];
    ((void (*)(void *, s32, s32, s32, s32))*(void **)((char *)*(void **)((char *)*(void **)((char *)arg0 + 0x124) + 0xC) + 0x30))(
        *(void **)((char *)arg0 + 0x124), value, item, count - 1, count);
    index = *(s32 *)((char *)arg0 + 0x11C);
    items = *(s32 **)((char *)arg0 + 0x10);
    fn_801345D8((char *)arg0 + 0x128, 0x20, &lbl_80343E70,
        items[index * 2 + 1], &lbl_8055BFF8);
}

#pragma scheduling invalid_target
void fn_8024BAA0(void *arg0) {
    s32 index = *(s32 *)((char *)arg0 + 0x11C);
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    s32 *items = *(s32 **)((char *)arg0 + 0x10);
    void *object = *(void **)((char *)arg0 + 0x124);
    s32 next = (index + 1) % count;
    *(s32 *)((char *)arg0 + 0x11C) = next;
    ((void (*)(void *, s32, s32, s32, s32))(*(void ***)((char *)object + 0xC))[12])(object, *(s32 *)((char *)arg0 + 0x120), items[next * 2 + 1], count, index + 1);
    fn_801345D8((char *)arg0 + 0x128, 0x20, &lbl_80343E70, items[next * 2 + 1], &lbl_8055BFF8);
}
#pragma scheduling on
void fn_8024BB3C(void *arg0) {
    s32 value = *(s32 *)((char *)arg0 + 0x10) - 1;
    *(s32 *)((char *)arg0 + 0x10) = value & ((-value & ~value) >> 31);
}

void fn_8024BB5C(void *arg0) {
    register s32 result = 2;
    register s32 value = *(s32 *)((char *)arg0 + 0x10) + 1;
    if (value <= 2) result = value;
    *(s32 *)((char *)arg0 + 0x10) = result;
}

s32 fn_8024BB7C(void *arg0) {
    return *(s32 *)((char *)lbl_802FA4B0 + (*(s32 *)((char *)arg0 + 0x10) << 3) + 4);
}

extern char lbl_80343E60[];
void fn_8024BBF4(void *arg0) {
      s32 spC, sp8;
      void *obj;
      void *result;
      char *src, *dst;
      s32 count;
      int (*get_name)(void *, char *);
      obj = *(void **)((char *)arg0 + 0x30);
      if (obj != 0) {
          ((void (*)(void *, s32 *, s32 *))*(void **)((char *)*(volatile void **)((char *)obj + 0xC) + 0x38))(obj, &sp8, &spC);
          result = (void *)fn_80012870(sp8, spC);
          *(s32 *)((char *)arg0 + 0x34) = *(s32 *)result;
          obj = *(void **)((char *)result + 0x20);
          get_name = *(int (**)(void *, char *))((char *)*(void **)obj + 0x14);
          src = (char *)get_name(obj, lbl_80343E60);
          dst = (char *)arg0 + 0x38;
          count = 0x64;
          do {
              count--;
              if (count <= 0) {
                  dst[-1] = 0;
                  break;
              }
              {
                  char c = *src++;
                  *dst++ = c;
                  if ((signed char)c == 0) break;
              }
          } while (1);
      } else {
          *(s32 *)((char *)arg0 + 0x34) = -1;
          *(char *)((char *)arg0 + 0x38) = 0;
      }
}
  
  void fn_8024BCC0(void *arg0) {
      s32 spC, sp8;
      void *obj;
      void *result;
      char *src, *dst;
      s32 count;
      int (*get_name)(void *, char *);
      obj = *(void **)((char *)arg0 + 0x30);
      if (obj != 0) {
          ((void (*)(void *, s32 *, s32 *))*(void **)((char *)*(void **)((char *)obj + 0xC) + 0x38))(obj, &sp8, &spC);
          result = (void *)fn_80012870(sp8, spC);
        *(s32 *)((char *)arg0 + 0x34) = *(s32 *)result;
        obj = *(void **)((char *)result + 0x20);
        get_name = *(int (**)(void *, char *))((char *)*(void **)obj + 0x14);
        src = (char *)get_name(obj, lbl_80343E60);
        dst = (char *)arg0 + 0x38;
        count = 0x64;
        do {
            count--;
            if (count <= 0) {
                dst[-1] = 0;
                break;
            }
            {
                char c = *src++;
                *dst++ = c;
                if ((signed char)c == 0) break;
            }
        } while (1);
    } else {
        *(s32 *)((char *)arg0 + 0x34) = -1;
        *(char *)((char *)arg0 + 0x38) = 0;
    }
}

extern void *lbl_8055F28C;
static inline int find_sound_entry(int id) {
    int i;
    int count = *(int *)((char *)lbl_8055F28C + 4);
    for (i = 0; i < count; i++) {
        if (*(int *)(*(char **)lbl_8055F28C + i * 0x18) == id) return i;
    }
    return -1;
}
