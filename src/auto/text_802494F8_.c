extern void *memset(void *, int, unsigned int);
extern void *lbl_8055F28C;
extern int MRollBothControllersReady(void);
extern unsigned char lbl_8055F290;
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
static inline int find_sound_entry_first(int *key) {
    register int byteOffset;
    register int i;
    register int table;
    int count;
    table = (int)lbl_8055F28C;
    i = 0;
    byteOffset = 0;
    count = *(int *)((char *)table + 4);
    for (; i < count; i++) {
        int value = *(int *)(*(char **)table + byteOffset);
        int id = *key;
        if (value == id) return i;
        byteOffset += 0x18;
    }
    return -1;
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
extern s32 fn_801345D8(void *, s32, const char *, ...);
extern char lbl_80343E70[];
extern char lbl_8055BFF8;

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80236074(void*, unsigned int);
void fn_80128668(void*);
extern void* lbl_8055BF34;
s32 fn_80214D04(void);
s32 fn_802494F8(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

s32 fn_80249538(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

/* Request the controller grip-name string for the index held by this object. */
void fn_80249578(void *gripSetting) {
    fn_8023E52C(*(s32 *)*(void **)((char *)gripSetting + 0x10));
}

/* Intentional no-op (compiles to a bare return): a do-nothing default/virtual hook. */
void fn_80249584(void) {}

/* Intentional no-op (compiles to a bare return): a do-nothing default/virtual hook. */
void fn_80249588(void) {}

#pragma scheduling on
/* Sound-entry filter callback: only for the "excite" contest (key[2]), look
 * the id in key[0] up in the sound table and return that entry's +0x14 flag
 * byte; 0 is returned when the key is for another contest or has no entry. */
int fn_8024958C(int *key) {
    #define EXCITE_EVENT_ID 0x180302
    #pragma scheduling invalid_target
    int result = key[2] == EXCITE_EVENT_ID;
    if (result) result = find_sound_entry_first(key) != -1;
    if (result) result = *(unsigned char *)(*(char **)lbl_8055F28C + find_sound_entry_inline(key) * 0x18 + 0x14);
    #undef EXCITE_EVENT_ID
    return result;
}
/* "Accept all" filter callback used as the sound-entry filter when no filtering is
 * requested: pairs with fn_8024958C (the conditional filter) and returns 1 so every
 * entry is included.  Extra call arguments are ignored. */
int fn_80249660(void) { return 1; }

#pragma push
#pragma scheduling invalid_target
int fn_80249668(int *outResult) {
    /* Copy a language-selected location string into lbl_8055F294 and optionally set a failure result. */
    extern char *lbl_802FA4C8[3];
    extern unsigned char lbl_8055F290;
    extern unsigned char *lbl_8055F294;
    extern int MRollBothControllersReady(void);
    char *strings[3];
    char **stringPtr = lbl_802FA4C8;
    int index2;
    char *src2;
    int count2;
    unsigned char *dst2;
    unsigned char c2;
    strings[0] = *stringPtr++;
    strings[1] = *stringPtr++;
    strings[2] = *stringPtr;
    index2 = fn_80214D04();
    src2 = strings[index2];
    dst2 = lbl_8055F294;
    count2 = 0x100;
    goto copy2;
decrement2:
    count2--;
    if (count2 > 0)
        goto copy2;
    dst2[-1] = 0;
    goto done2;
copy2:
    c2 = *src2++;
    *dst2++ = c2;
    if ((signed char)c2 != 0)
        goto decrement2;
done2:
    if (lbl_8055F290 != 0 && MRollBothControllersReady() == 0) {
        *(volatile int *)outResult = -1;
        return 1;
    }
    return 0;
}
void fn_80249720(void) {
#define sSavedMenuIndex lbl_8055BF34
#define GetMenuIndex    fn_80214D04
    /* Save the active UI window's current menu index so it can be restored later (fn_80249744). */
    sSavedMenuIndex = (void*)GetMenuIndex();
#undef sSavedMenuIndex
#undef GetMenuIndex
}

void fn_80249744(void) {
#define sSavedMenuIndex lbl_8055BF34
#define SetMenuIndex    fn_80214CB4
    /* Restore the active UI window's menu index from the value saved by fn_80249720. */
    SetMenuIndex(sSavedMenuIndex);
#undef sSavedMenuIndex
#undef SetMenuIndex
}

#pragma push
#pragma dont_inline on
s32 fn_8024974C(s32 arg0, s32 arg1, s32 arg2, int arg3) {
    extern void *fn_801284F8(int, void *);
    extern char lbl_8055BF38[];
    extern s32 lbl_8055BF10, lbl_8055BF14;
    extern void LoadIntOptionValue(s32, s32, s32 *);
    extern void fn_8027BCD0(void *);
    extern int MRollBothControllersReady(void);
    void *block;
    if (arg3 != 0 && MRollBothControllersReady() == 0) {
        return 0;
    }
    lbl_8055F290 = (unsigned char)arg3;
    block = fn_801284F8(0xC0C, lbl_8055BF38);
    if (block != 0) {
        *(void **)block = (char *)block + 0xC;
        *(int *)((char *)block + 8) = 0x80;
        *(int *)((char *)block + 4) = 0;
    }
    lbl_8055F28C = block;
    fn_8027BCD0(block);
    *(int *)arg0 = -1;
    *(int *)arg1 = 5;
    *(int *)arg2 = 0;
    LoadIntOptionValue(0, lbl_8055BF10, (s32 *)arg1);
    LoadIntOptionValue(0, lbl_8055BF14, (s32 *)arg0);
    return 0;
}
#pragma pop

void fn_8022D7C4(void *, unsigned int);
/* Deleting destructor for nw4hbm::snd::detail::DisposeCallbackManager. */
void *__dt__Q46nw4hbm3snd6detail22DisposeCallbackManagerFv_8024A110(void *this_, s32 deletingFlag) {
    if (this_) {
        if (this_ != 0) {
            fn_8022D7C4(this_, 0);
        }
        if (deletingFlag > 0) {
            fn_80128668(this_);
        }
    }
    return this_;
}

s32 fn_8024A16C(s32 object, s32 deleteFlag) {
    /* CodeWarrior deleting-destructor helper: free the object with MemFree when deleting, then return it. */
    if (object != 0 && deleteFlag > 0) {
        fn_80128668((void *)object);
    }
    return object;
}

/* Scalar deleting destructor for nw4hbm::snd::MemorySoundArchive: runs the base
 * subobject destructor (fn_80236074, deleteFlag 0) and, when deletingFlag > 0,
 * frees the object (fn_80128668 = operator delete, mode 3). Returns this_. */
long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC(long this_, long deletingFlag) {
    if (this_ != 0) {
        fn_80236074((void*)this_, 0);
        if (deletingFlag > 0) {
            fn_80128668((void*)this_);
        }
    }
    return this_;
}

#pragma scheduling invalid_target
/* Deleting destructor of the race-movie list: the object keeps its {item array,
 * count, flag} record at +0x10 (items are {id, name} pairs; its prev/next
 * handlers pick a name by the +0x11C index and build a "%s/race.%s" path), so
 * this drops the current selection, re-initialises that record, and frees the
 * object when deleteFlag > 0. The guard tests the record's own address -- an
 * inlined member call's `this != NULL` check, so it can never fail. */
void *fn_8024A204(void *self, s32 deleteFlag) {
    char *base;
    unsigned int offset;
    s32 zero = 0;
    if (self != 0) {
        base = (char *)self;
        *(s32 *)(base + 0x11C) = zero;
        if ((base + 0x10 != 0) && ((char *)self + 0x10 != 0)) {
            offset = 0x10;
            *(s32 *)((char *)self + offset) = zero;
            *(s32 *)((char *)self + 0x14) = zero;
            *(s32 *)((char *)self + 0x18) = zero;
        }
        if (deleteFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}
#pragma scheduling reset
/* Deleting-destructor helper: reset fields at +0x10, +0x18, and +0x1C, then free the
 * object when deleteFlag > 0. */
void *fn_8024A268(void *self, s32 deleteFlag) {
    if (self != 0) {
        *(s32 *)((char *)self + 0x18) = -1;
        *(s32 *)((char *)self + 0x1C) = *(s32 *)((char *)self + 0x10) = 0;
        if (deleteFlag > 0) {
            fn_80128668(self);
        }
    }
    return self;
}

#pragma push
#pragma scheduling invalid_target
void fn_8024A2BC(void *arg0, s32 arg1, s32 arg2) {
    /* Search entries starting at +0x20 (stride 0xC) for a pair (arg1,arg2) and set the
     * selected index at +0x10 to the match's position; does nothing if not found. */
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    char *entry = (char *)arg0;
    s32 index = 0;
    while (count-- > 0) {
        if (arg1 == *(s32 *)(entry + 0x20) && arg2 == *(s32 *)(entry + 0x24)) {
            *(s32 *)((char *)arg0 + 0x10) = index;
            return;
        }
        entry += 0xC;
        index++;
    }
}
#pragma pop
extern char lbl_80343E7C[];
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8024A304(void *arg0, void **arg1, int arg2, int arg3) {
    extern unsigned char lbl_8055F290;
    int zero = 0;
    register void *object;
    register int index;
    void **list;
    (void)arg3;
    *(int *)((char *)arg0 + 0x1C) = arg2;
    object = arg0;
    *(int *)((char *)object + 0x10) = zero;
    list = arg1;
    index = zero;
    *(int *)((char *)object + 0x14) = zero;
    {
        register int archiveIndex;
        register int archiveCount;
        register void *record;
        register int offset;
        offset = zero;
        goto outer_check;
outer_body:
        if (stricmp((char *)getEventEnvironName(
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
            archiveIndex = 0;
            while (archiveCount > archiveIndex) {
                if (record != (void *)fn_80012870(
                        *(int *)((char *)record + 4), archiveIndex)) {
                    archiveIndex++;
                    continue;
                }
                goto archive_done;
            }
            archiveIndex = -1;
archive_done:
            *(int *)((char *)object +
                     *(int *)((char *)object + 0x14) * 0xC + 0x24) =
                archiveIndex;
            {
                int tableIndex = 0;
                int tableOffset = 0;
                void *table = lbl_8055F28C;
                int tableCount = *(int *)((char *)table + 4);
                while (tableIndex < tableCount) {
                    if (*(int *)(*(char **)table + tableOffset) !=
                        *(int *)record) {
                        tableOffset += 0x18;
                        tableIndex += 1;
                    } else {
                        goto table_found;
                    }
                }
                tableIndex = -1;
table_found:
                if (lbl_8055F290 != 0 && tableIndex >= 0) {
                    *(int *)((char *)object +
                             *(int *)((char *)object + 0x14) * (unsigned short)0xC + 0x28) =
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
        ++index;
outer_check:
        if (index < *(int *)((char *)*list + 4))
            goto outer_body;
    }
}
#pragma scheduling reset
#pragma use_lmw_stmw on
int stricmp(const char*, const char*);
// qsort comparison callback: case-insensitively compare the strings held in the two elements.
void fn_8024A4B8(const char** lhs, const char** rhs) {
    stricmp(*lhs, *rhs);
}

s32 fn_8024974C();
/* Run the selection-menu setup with the conditional filter disabled (accept
 * all), passing through the three output slots that receive the selection. */
void fn_8024A4C4(s32 out0, s32 out1, s32 out2) {
    fn_8024974C(out0, out1, out2, 0);
}

extern int fn_80012818(void);
extern int fn_80012820();
extern int fn_80012870();
extern void LoadIntOptionValue(s32, s32, s32 *);
extern s32 fn_80133348(s32, s32, s32);
extern void fn_8027BCD0(void *);
extern u8 fn_8024B070(s32 *, s32 **);
extern s32 lbl_8055BF10;
extern s32 lbl_8055BF14;
#pragma push
#pragma scheduling invalid_target
#pragma processor 750
s32 fn_8024A4CC(s32 *arg0, s32 *arg1, s32 *arg2) {
    extern void *fn_8001285C(s32);
    struct Buffer {
        void *data;
        s32 count;
        s32 size;
        u8 bytes[0xC00];
    } buffer;
    s32 key;
    register s32 *entry;
    register s32 i;
    register s32 targetKey;
    s32 index;
    register s32 count;
    void *record;
    s32 result;

    *arg0 = -1;
    *arg1 = 0;
    *arg2 = 0;
    LoadIntOptionValue(0, lbl_8055BF14, arg0);
    LoadIntOptionValue(0, lbl_8055BF10, arg1);

    *(volatile s32 *)&buffer.count = 0;
    *(volatile void **)&buffer.data = buffer.bytes;
    *(volatile s32 *)&buffer.size = 0x80;
    fn_8027BCD0(&buffer);
    key = -1;

    index = *arg0;
    if (index >= 0 && index < fn_80012818()) {
        record = (void *)fn_80012820(index);
        count = *arg1;
        if (count >= 0 && count < *(s32 *)((u8 *)record + 0x70)) {
            record = (void *)fn_80012870(*(volatile s32 *)arg0, count);
            count = buffer.count;
            i = 0;
            targetKey = *(s32 *)record;
            entry = (s32 *)buffer.data;
            for (; i < count; i++) {
                if (*entry != targetKey)
                    goto scan_increment;
                goto found_entry;
scan_increment:
                entry = (s32 *)((u8 *)entry + 0x18);
            }
            i = -1;
found_entry:
            if (i >= 0)
                key = targetKey;
        }
    }

    if (((s32 (*)(s32 *, s32 **))fn_8024B070)(&key, (s32 **)&buffer.data)) {
        *arg0 = *(s32 *)((u8 *)fn_8001285C(key) + 4);
        *arg1 = -1;
        index = count;
        count = *(s32 *)((u8 *)fn_80012820(*arg0) + 0x70);
        goto record_continue;
record_loop:
        if (*(s32 *)fn_80012870(*arg0, index) == key) {
            *arg1 = index;
            goto record_done;
        }
record_continue:
        if (index-- > 0)
            goto record_loop;
record_done:
        fn_80133348(0, lbl_8055BF14, *arg0);
        fn_80133348(0, lbl_8055BF10, *arg1);
        *(volatile s32 *)&buffer.data = 0;
        result = 1;
        *(volatile s32 *)&buffer.count = 0;
        *(volatile s32 *)&buffer.size = 0;
        return result;
    }
    *(volatile s32 *)&buffer.data = 0;
    result = 0;
    *(volatile s32 *)&buffer.count = 0;
    *(volatile s32 *)&buffer.size = 0;
    return result;
}
#pragma pop
/* Sets -1 and returns 1 when the system is not ready, otherwise returns 0. */
s32 fn_8024A6A4(s32 *outValue) {
    if (MRollBothControllersReady() == 0) {
        *outValue = -1;
        return 1;
    } else {
        return 0;
    }
}

#pragma use_lmw_stmw off
s32 fn_8024A6EC(s32* arg0, void* arg1) {
    extern int MRollBothControllersReady(void);
    extern void* fn_8024B3E8(void*, void*, int);
    extern void fn_8024B544(void*, char*);
    extern s32 fn_8024B5D4(void*, s32);
    extern s32 fn_8024B5F8(s32, s32);
    extern s32 fn_8024B608(s32, s32);
    extern s32 fn_8024B618(s32, s32);
    extern s32 fn_802146BC(s32*, s32, s32, s32, s32, s32, s32, s32);
    extern char lbl_80343998[];
    extern s32 lbl_802FA4E8[];
    extern s32 lbl_80498998[];
    extern int lbl_8055BF68, lbl_8055BF70, lbl_8055BF78, lbl_8055BF80;
    extern int lbl_8055BF88, lbl_8055BF90, lbl_8055BF98, lbl_8055BFA0;
    extern int lbl_8055BFA8, lbl_8055BFB0, lbl_8055BFB8;
    extern int lbl_8055B860;
    char work[0x2B0];
    s32 cfg[0xB0];
    char* base = lbl_80343998;
    s32 zero = 0;
    s32 three = 3;
    s32 r;
    if (MRollBothControllersReady() == 0) return 0;
    fn_8024B3E8(work + 0x18, (void*)arg1, 0);
    fn_8024B544(work + 0x18, (char*)*arg0);
    cfg[8] = (s32)(work + 0x18); cfg[6] = (s32)&lbl_8055BF68; cfg[7] = 5; cfg[9] = 0; cfg[10] = 0;
    cfg[13] = fn_8024B5D4(work + 0x18, 0); cfg[12] = three; cfg[11] = (s32)(base + 0x118);
    cfg[14] = zero; cfg[15] = 0; cfg[17] = 0; cfg[16] = (s32)(base + 0x118); cfg[18] = 0; cfg[19] = 1; cfg[20] = 0;
    cfg[23] = fn_8024B5D4(work + 0x18, 1); cfg[22] = three; cfg[21] = (s32)(base + 0x124);
    cfg[24] = 0; cfg[25] = 0; cfg[27] = 0; cfg[26] = (s32)(base + 0x124); cfg[28] = 0; cfg[29] = 2; cfg[30] = 0;
    cfg[33] = fn_8024B5D4(work + 0x18, 2); cfg[32] = three; cfg[31] = (s32)(base + 0x130);
    cfg[34] = 0; cfg[35] = 0; cfg[37] = 0; cfg[36] = (s32)(base + 0x130); cfg[38] = 0; cfg[39] = three; cfg[40] = 0;
    cfg[43] = fn_8024B5D4(work + 0x18, 3); cfg[42] = three; cfg[41] = (s32)(base + 0x13C);
    cfg[44] = 0; cfg[45] = 0; cfg[47] = 0; cfg[46] = (s32)(base + 0x13C); cfg[48] = 0; cfg[49] = 4; cfg[50] = 0;
    cfg[53] = fn_8024B5D4(work + 0x18, 4); cfg[52] = three; cfg[51] = (s32)(base + 0x148);
    cfg[54] = 0; cfg[55] = 0; cfg[57] = 0; cfg[56] = (s32)(base + 0x148); cfg[58] = 0; cfg[59] = 5; cfg[60] = 0;
    cfg[63] = fn_8024B5D4(work + 0x18, 5); cfg[62] = three; cfg[61] = (s32)(base + 0x154);
    cfg[64] = 0; cfg[65] = 0; cfg[67] = 0; cfg[66] = (s32)(base + 0x154); cfg[68] = 0; cfg[69] = 6; cfg[70] = 0;
    cfg[73] = fn_8024B5D4(work + 0x18, 6); cfg[72] = three; cfg[71] = (s32)(base + 0x160);
    cfg[74] = 0; cfg[75] = 0; cfg[77] = 0; cfg[76] = (s32)(base + 0x160); cfg[78] = 0; cfg[79] = 7; cfg[80] = 0;
    cfg[83] = fn_8024B608((s32)(work + 0x18), 0); cfg[82] = three; cfg[81] = (s32)&lbl_8055BF70; cfg[84] = 0; cfg[85] = 0;
    cfg[88] = fn_8024B5F8((s32)(work + 0x18), 0); cfg[87] = three; cfg[86] = (s32)(base + 0x16C); cfg[89] = 0; cfg[90] = 0;
    cfg[93] = fn_8024B618((s32)(work + 0x18), 0); cfg[92] = 2; cfg[91] = (s32)&lbl_8055BF78; cfg[94] = 0; cfg[95] = 0;
    cfg[98] = fn_8024B608((s32)(work + 0x18), 1); cfg[97] = three; cfg[96] = (s32)&lbl_8055BF80; cfg[99] = 0; cfg[100] = 0;
    cfg[103] = fn_8024B5F8((s32)(work + 0x18), 1); cfg[102] = three; cfg[101] = (s32)(base + 0x178); cfg[104] = 0; cfg[105] = 0;
    cfg[108] = fn_8024B618((s32)(work + 0x18), 1); cfg[107] = 2; cfg[106] = (s32)&lbl_8055BF88; cfg[109] = 0; cfg[110] = 0;
    cfg[113] = fn_8024B608((s32)(work + 0x18), 2); cfg[112] = three; cfg[111] = (s32)&lbl_8055BF90; cfg[114] = 0; cfg[115] = 0;
    cfg[118] = fn_8024B5F8((s32)(work + 0x18), 2); cfg[117] = three; cfg[116] = (s32)(base + 0x184); cfg[119] = 0; cfg[120] = 0;
    cfg[123] = fn_8024B618((s32)(work + 0x18), 2); cfg[122] = 2; cfg[121] = (s32)&lbl_8055BF98; cfg[124] = 0; cfg[125] = 0;
    cfg[128] = fn_8024B608((s32)(work + 0x18), 3); cfg[127] = three; cfg[126] = (s32)&lbl_8055BFA0; cfg[129] = 0; cfg[130] = 0;
    cfg[133] = fn_8024B5F8((s32)(work + 0x18), 3); cfg[132] = three; cfg[131] = (s32)(base + 0x190); cfg[134] = 0; cfg[135] = 0;
    cfg[138] = fn_8024B618((s32)(work + 0x18), 3); cfg[137] = 2; cfg[136] = (s32)&lbl_8055BFA8; cfg[139] = 0; cfg[140] = 0;
    cfg[143] = fn_8024B608((s32)(work + 0x18), 4); cfg[142] = three; cfg[141] = (s32)&lbl_8055BFB0; cfg[144] = 0; cfg[145] = 0;
    cfg[148] = fn_8024B5F8((s32)(work + 0x18), 4); cfg[147] = three; cfg[146] = (s32)(base + 0x19C); cfg[149] = 0; cfg[150] = 0;
    cfg[153] = fn_8024B618((s32)(work + 0x18), 4);
    cfg[151] = (s32)&lbl_8055BFB8; cfg[152] = 2; cfg[154] = 0; cfg[155] = 0; cfg[156] = (s32)&lbl_8055B860;
    cfg[157] = 0; cfg[158] = 0; cfg[159] = -1; cfg[160] = 0x1b;
    cfg[161] = lbl_80498998[0]; cfg[162] = lbl_80498998[1]; cfg[163] = lbl_80498998[2];
    cfg[164] = lbl_80498998[3]; cfg[165] = lbl_80498998[4];
    cfg[0] = lbl_802FA4E8[0]; cfg[1] = (s32)&cfg[6]; cfg[2] = lbl_802FA4E8[2]; cfg[3] = lbl_802FA4E8[3]; cfg[4] = lbl_802FA4E8[4];
    r = fn_802146BC(cfg, -0x3E7, -0x3E7, 1, lbl_802FA4E8[4], lbl_802FA4E8[3], lbl_802FA4E8[2], lbl_802FA4E8[0]);
    if (r != -1) {
        *arg0 = fn_8024B5D4(work + 0x18, r - 1);
        return 1;
    }
    return 0;
}
void *fn_8024AC54(void *object, int shouldDelete) {
    /* Destructor helper: clear embedded fields at offsets 0x18-0x20, then optionally free the object. */
    if (object != 0) {
        if ((unsigned int)object + 0x18 != 0) {
            if ((unsigned int)object + 0x18 != 0) {
                *(int *)((char *)object + 0x18) = 0;
                *(int *)((char *)object + 0x1C) = 0;
                *(int *)((char *)object + 0x20) = 0;
            }
        }
        if (shouldDelete > 0) fn_80128668(object);
    }
    return object;
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
#pragma opt_common_subs off
#pragma use_lmw_stmw off
s32 fn_8024ACB4(s32 *arg0, s32 arg1, void *arg2) {
    typedef struct { s32 words[5]; } ConfigTemplate;
    union {
        s32 words[126];
        struct {
            ConfigTemplate header;
            s32 setup[116];
            ConfigTemplate footer;
        } parts;
    } config;
    register s32 *output = arg0;
    register void *work = arg2;
    char *const name = lbl_80343998;
    register s32 zero = 0;
    register s32 three = 3;
    register s32 five = 5;
    register s32 minusOne = -1;
    register s32 hex12 = 0x12;
    register const char *label = (const char *)arg1;
    s32 result;

    if (MRollBothControllersReady() == 0) return 0;
    fn_8024B73C((char *)config.words + 0x18, label, work);
    fn_8024B830((char *)config.words + 0x18, *output);
    config.words[49] = zero;
    work = (char *)config.words + 0x18;
    config.words[46] = (s32)&lbl_8055BF68;
    config.words[48] = (s32)work;
    config.words[47] = five;
    config.words[50] = zero;

    config.words[53] = fn_8024B87C(work, 0);
    label = name + 0x16c;
    config.words[52] = three;
    config.words[51] = (s32)label;
    config.words[54] = zero;
    config.words[55] = zero;
    config.words[59] = fn_8024B8A4(work, 0);
    config.words[57] = zero;
    config.words[56] = (s32)label;
    config.words[58] = zero;
    config.words[60] = zero;

    config.words[63] = fn_8024B87C(work, 1);
    label = name + 0x178;
    config.words[62] = three;
    config.words[61] = (s32)label;
    config.words[64] = zero;
    config.words[65] = zero;
    config.words[69] = fn_8024B8A4(work, 1);
    config.words[67] = zero;
    config.words[66] = (s32)label;
    config.words[68] = zero;
    config.words[70] = zero;

    config.words[73] = fn_8024B87C(work, 2);
    label = name + 0x184;
    config.words[72] = three;
    config.words[71] = (s32)label;
    config.words[74] = zero;
    config.words[75] = zero;
    config.words[79] = fn_8024B8A4(work, 2);
    config.words[77] = zero;
    config.words[76] = (s32)label;
    config.words[78] = zero;
    config.words[80] = zero;

    config.words[83] = fn_8024B87C(work, 3);
    label = name + 0x190;
    config.words[82] = three;
    config.words[81] = (s32)label;
    config.words[84] = zero;
    config.words[85] = zero;
    config.words[89] = fn_8024B8A4(work, 3);
    config.words[87] = zero;
    config.words[86] = (s32)label;
    config.words[88] = zero;
    config.words[90] = zero;

    config.words[93] = fn_8024B87C(work, 4);
    label = name + 0x19c;
    config.words[92] = three;
    config.words[91] = (s32)label;
    config.words[94] = zero;
    config.words[95] = zero;
    config.words[99] = fn_8024B8A4(work, 4);
    config.words[97] = zero;
    config.words[96] = (s32)label;
    config.words[98] = zero;
    config.words[100] = zero;

    config.words[103] = fn_8024B8CC((s32)work);
    label = name + 0xCC;
    config.words[102] = hex12;
    config.words[101] = (s32)label;
    config.words[104] = zero;
    config.words[105] = zero;
    config.words[108] = fn_8024B8D4((s32)work);
    config.words[107] = 2;
    config.words[106] = (s32)label;
    config.words[109] = zero;
    config.words[110] = zero;
    config.words[113] = fn_8024B874((s32)work);
    config.words[111] = (s32)(name + 0xBC);
    config.words[112] = three;
    config.words[114] = zero;
    config.words[115] = zero;
    config.words[117] = 6;
    config.words[116] = (s32)&lbl_8055B860;
    config.words[118] = zero;
    config.words[119] = minusOne;
    config.words[120] = 0x1B;
    config.words[121] = lbl_80498998[0];
    config.words[122] = lbl_80498998[1];
    config.words[123] = lbl_80498998[2];
    config.words[124] = lbl_80498998[3];
    config.words[125] = lbl_80498998[4];
    config.parts.header = *(const ConfigTemplate *)lbl_802FA4FC;
    config.words[1] = (s32)&config.words[46];

    result = fn_802146BC(config.words, -0x3E7, -0x3E7, 1,
                         config.words[4], config.words[3],
                         config.words[2], config.words[0]);
    if (result != -1) {
        *output = result;
        fn_80236074((char *)config.words + 0x64, -1);
        config.words[12] = zero;
        config.words[13] = zero;
        config.words[14] = zero;
        return 1;
    }
    fn_80236074((char *)config.words + 0x64, -1);
    config.words[12] = zero;
    config.words[13] = zero;
    config.words[14] = zero;
    return 0;
}
/* Destructor of the sound-archive selector object: tears down the embedded
 * nw4hbm::snd::MemorySoundArchive at +0x4C (flag -1: the archive itself is a
 * member, so it is not freed), drops the entry-array descriptor at +0x18
 * (array pointer, count and capacity), and frees the object itself only when
 * deleteFlag > 0 (the scalar-deleting-destructor case). */
void *fn_8024AFF8(void *object, s32 deleteFlag) {
    struct ArchiveSelector {
        void* vtable;                // at 0x00
        s32 field_4;                 // at 0x04
        s32 field_8;                 // at 0x08
        s32 field_C;                 // at 0x0C
        s32 field_10;                // at 0x10
        s32 field_14;                // at 0x14
        void** entries;              // at 0x18: matching sound entries
        s32 entryCount;              // at 0x1C
        s32 entryCapacity;           // at 0x20: 10 while the inline array is used
        char inlineEntries[0x28];    // at 0x24: first entries live here
        s32 soundArchive;            // at 0x4C: nw4hbm::snd::MemorySoundArchive
    };
    struct ArchiveSelector* self = (struct ArchiveSelector*)object;

    if (object != 0) {
        fn_80236074(&self->soundArchive, -1);
        if (&self->entries != 0) {
            if (&self->entries != 0) {
                self->entries = 0;
                self->entryCount = 0;
                self->entryCapacity = 0;
            }
        }
        if (deleteFlag > 0) {
            fn_80128668(object);
        }
    }
    return object;
}

extern s32 fn_80215228(void);
extern s32 fn_8024A6EC(s32 *, void *);
extern s32 fn_8024ACB4(s32 *, s32, void *);
extern u8 lbl_8055F298;
static inline s32 findEntry8024B070(s32 **arg1, s32 *arg0, s32 n) {
    s32 offset;
    s32 i;
    i = 0;
    offset = 0;
    for (; i < n; offset += 0x18, i++) {
        s32 item = *(s32 *)((u8 *)*arg1 + offset);
        s32 key = *arg0;
        if (item == key) return i;
    }
    return -1;
}

#pragma scheduling invalid_target
u8 fn_8024B070(s32 *arg0, s32 **arg1) {
    s32 sp8;
    s32 i = findEntry8024B070(arg1, arg0, *(const s32 *)((const u8 *)arg1 + 4));
    if (i >= 0) {
        sp8 = *(s32 *)((u8 *)*arg1 + i * 0x18 + 0xC);
    } else {
        sp8 = 0;
    }
    if (fn_80215228() != 0) {
        lbl_8055F298 = 0;
    }
    while (lbl_8055F298 != 0 || fn_8024A6EC(&sp8, arg1) != 0) {
        lbl_8055F298 = 0;
        if (fn_8024ACB4(arg0, sp8, arg1) != 0) {
            lbl_8055F298 = 1;
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
#pragma dont_inline on
#pragma dont_inline fn_8024B178
extern s32 fn_8024B178(s32);
#pragma push
#pragma scheduling invalid_target
#pragma cplusplus on
s32 fn_8024B178(s32 arg0) {
    class Obj {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *get(const char *);
    };
    void *manager;
    void *object;
    char *result;
    char *prefix;
    s32 comparison;
    char *buffer;
    char *suffix;

    manager = ((void *(*)(s32))fn_8001285C)(arg0);
    object = *(void **)((char *)manager + 0x20);
    result = ((Obj *)object)->get((const char *)&lbl_8055BFC0);
    prefix = (char *)&lbl_8055BFC8;
    comparison = strncmp(result, prefix, strlen(prefix));
    if (comparison != 0)
        goto mismatch;
    result += strlen(prefix);
    suffix = result;
    buffer = lbl_804989AC;
    ((void (*)(void *, int, const char *, ...))fn_801345D8)(
        buffer, 0x21, (const char *)&lbl_8055BFD0, suffix);
    return (s32)buffer;
mismatch:
    return comparison;
}
#pragma pop
/* RealName: CompareArchiveEntryByName (qsort comparator: flagged entries first, then case-insensitive name) */
int fn_8024B214(char *arg0, char *arg1) {
#define CompareArchiveEntryByName fn_8024B214
#define entryA arg0
#define entryB arg1
    /* Compare 8-byte archive entries: sort flagged entries before unflagged, then by name (case-insensitive). */
    unsigned char first = ((unsigned char *)entryA)[4];
    if (first != 0 && ((unsigned char *)entryB)[4] == 0) return 1;
    if (((unsigned char *)entryB)[4] != 0 && first == 0) return -1;
    return stricmp(*(char **)entryA, *(char **)entryB);
#undef first
#undef entryA
#undef entryB
#undef CompareArchiveEntryByName
}

extern void *fn_80131234(void *);
extern char lbl_80343B54[];
#pragma push
#pragma use_lmw_stmw off
void fn_8024B260(arg0)
void *arg0;
{
    s32 selected;
    s32 one;
    s32 i;
    s32 offset;
    char *search;
    void *list;
    s32 zero;
    unsigned int entry;
    unsigned int record;
    u8 **strings;
    entry = 0;
    record = 0;
    selected = fn_80214D04();
    *(s32 *)((u8 *)arg0 + 0x280) = selected;
    strings = *(u8 ***)((u8 *)arg0 + 0x18);
    search = (char *)strings[selected * 2];
    memset((u8 *)arg0 + 0x78, 0, 0x208);
    one = 1;
    i = 0;
    *(s32 *)((u8 *)arg0 + 0xDC) = one;
    offset = 0;
    *(s32 *)((u8 *)arg0 + 0x144) = one;
    zero = 0;
    *(s32 *)((u8 *)arg0 + 0x1AC) = one;
    *(s32 *)((u8 *)arg0 + 0x214) = one;
    *(s32 *)((u8 *)arg0 + 0x27C) = one;
    goto check_loop;
loop_body:
    entry = *(unsigned int *)list + offset;
    if (stricmp(search, *(char **)(entry + 0xC)) == 0) {
        record = (unsigned int)arg0 + *(s32 *)(entry + 8) * 0x68 + 0x78;
        {
            char *src = *(char **)(entry + 4);
            s32 remaining = 0x32;
            char *dst = (char *)record;
            while ((s8)(*dst++ = *src++) != 0) {
                if (--remaining <= 0) { dst[-1] = zero; break; }
            }
        }
        if (*(u8 *)(entry + 0x14) != 0) {
            char *src = *(char **)(entry + 0x10);
            s32 remaining = 0x32;
            char *dst = (char *)(record + 0x32);
            while ((s8)(*dst++ = *src++) != 0) {
                if (--remaining <= 0) { dst[-1] = zero; break; }
            }
            *(s32 *)(record + 0x64) = one;
        } else {
            char *src = (char *)fn_80131234(lbl_80343B54);
            s32 remaining = 0x32;
            char *dst = (char *)(record + 0x32);
            while ((s8)(*dst++ = *src++) != 0) {
                if (--remaining <= 0) { dst[-1] = zero; break; }
            }
            *(s32 *)(record + 0x64) = zero;
        }
    }
    offset += 0x18;
    i++;
check_loop:
    list = *(void **)((u8 *)arg0 + 0x74);
    if (i < *(s32 *)((u8 *)list + 4)) goto loop_body;
}
#pragma pop
extern void fn_80265DCC(void *, int, int, void *);
extern char lbl_80343BD0[];
extern int stricmp(const char *, const char *);
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
void *fn_8024B3E8(void *archiveList, void *archiveRoot, int unused) {
    /* Build sorted unique archive entry list from archiveRoot into archiveList. */
    typedef struct ArchiveEntry {
        char pad0[0xC];
        char *name;
        unsigned char pad10[8];
    } ArchiveEntry;
    register int hasSpecialEntry = 1;
    register ArchiveEntry *entry;
    register int itemOffset;
    register int isUnique;
    register int innerIndex;
    register int outerOffset;
    register int outerIndex;
    volatile int *itemCount = (volatile int *)((char *)archiveList + 0x1C);
    (void)unused;
    *(void **)((char *)archiveList + 0x74) = archiveRoot;
    *(int *)((char *)archiveList + 0x14) = 0;
    *(char **)archiveList = lbl_80343BD0;
    *(void **)((char *)archiveList + 0x18) = (char *)archiveList + 0x24;
    *(int *)((char *)archiveList + 0x20) = 10;
    *itemCount = 0;
    *((unsigned char *)archiveList + 0x284) = 0;
    outerIndex = 0;
    outerOffset = 0;
    while (outerIndex < *(int *)((char *)archiveRoot + 4)) {
        entry = (ArchiveEntry *)((char *)*(void **)archiveRoot + outerOffset);
        isUnique = 1;
        innerIndex = 0;
        itemOffset = 0;
        while (innerIndex < *itemCount) {
            if (((unsigned char *)entry)[0x14] == 0 ||
                stricmp(*(char **)(*(char **)((char *)archiveList + 0x18) + itemOffset),
                        entry->name) == 0)
                isUnique = 0;
            itemOffset += 8;
            innerIndex++;
        }
        if (isUnique) {
            int n = *itemCount;
            void * volatile *itemsField =
                (void * volatile *)((char *)archiveList + 0x18);
            void *items = *itemsField;
            void *slot;
            *itemCount = n + 1;
            slot = (char *)items + n * 8;
            *(char **)slot = entry->name;
            *((unsigned char *)slot + 4) = ((unsigned char *)entry)[0x15];
        }
        if (((unsigned char *)entry)[0x14] != 0 &&
            ((unsigned char *)entry)[0x15] != 0)
            *((unsigned char *)archiveList + 0x284) = hasSpecialEntry;
        outerOffset += 0x18;
        outerIndex++;
    }
    fn_80265DCC(*(void **)((char *)archiveList + 0x18),
                *itemCount, 8, fn_8024B214);
    memset((char *)archiveList + 0x78, 0, 0x208);
    *(int *)((char *)archiveList + 0x280) = -1;
    return archiveList;
}
#pragma scheduling reset
#pragma use_lmw_stmw reset
/* Select the entry by name in this object's list, storing its index at +0x280 (or 0 if not found). */
void fn_8024B544(void *obj, char *name) {
    register s32 offset;
    register s32 index;
    *(s32 *)((char *)obj + 0x280) = 0;
    if (name != 0) {
        index = 0;
        offset = 0;
        while (index < *(s32 *)((char *)obj + 0x1C)) {
            if (stricmp(*(char **)((char *)*(s32 **)((char *)obj + 0x18) + offset), name) == 0) {
                *(s32 *)((char *)obj + 0x280) = index;
            }
            offset += 8;
            index++;
        }
    }
}

/* gEmptyString: shared zero buffer in .sdata, used as an empty C string fallback. */
#define gEmptyString lbl_8055BFD8

s32 fn_8024B5D4(void *config, s32 index) {
    /* Return the first word (name pointer) of the indexed 8-byte entry in the
     * config's inline entry array, or the shared empty-string pointer if out of range. */
    extern s32 gEmptyString;
    if (index < *(s32 *)((char *)config + 0x1C)) {
        return *(s32 *)((char *)*(s32 **)((char *)config + 0x18) + index * 8);
    }
    return (s32)&gEmptyString;
}

s32 fn_8024B5F8(s32 base, s32 recordIndex) {
    /* Address of the field at +0xAA in record recordIndex of a 0x68-byte-stride array based at base. */
    return base + recordIndex * 0x68 + 0xAA;
}

s32 fn_8024B608(s32 base, s32 recordIndex) {
    /* Address of the field at +0x78 in record recordIndex of a 0x68-byte-stride array based at base. */
    return base + recordIndex * 0x68 + 0x78;
}

/* Return a pointer (as s32) to the text field at offset 0xDC within the
 * index-th 0x68-byte record of the table based at base (work + 0x18). */
s32 fn_8024B618(s32 base, s32 index) {
    return base + index * 0x68 + 0xDC;
}

void fn_8024B628(void *obj) {
    s32 index;
    /* Update menu/UI selection state from object fields and refresh display (via fn_8024B260). */
    fn_80214CB4(*(s32 *)((char *)obj + 0x280));
    index = *(s32 *)((char *)obj + 0x1C);
    goto loop_test;
    do {
        fn_80214A9C(index + 1);
        index++;
    loop_test:
        ;
    } while (index < *(s32 *)((char *)obj + 0x20));
    if (*(unsigned char *)((char *)obj + 0x284) == 0)
        fn_80214A9C(10);
    else
        fn_80214AF0(10);
    fn_8024B260(obj);
}

void fn_8024B6A8(void) {
    /* Tail-call the menu/UI name-record initializer, forwarding the object
       pointer still held in r3. */
    fn_8024B260();
}

/* Cache the selected entry (from fn_80214D04): store its index, copy up to 0x32 chars of its name into the local buffer at +0x64, and cache its value pointer at +0x98. */
void fn_8024B6AC(void *arg0) {
    s32 selectedIndex;
    void **entryArray;
    char ch;
    char *srcText;
    s32 remaining;
    char *dstText;

    selectedIndex = fn_80214D04();
    *(s32 *)((char *)arg0 + 0x9C) = selectedIndex;
    entryArray = *(void ***)((char *)arg0 + 0x18);
    dstText = (char *)arg0 + 0x64;
    remaining = 0x32;
    srcText = *(char **)((char *)entryArray[selectedIndex] + 0x10);
    goto copy;
decrement:
    remaining--;
    if (remaining > 0)
        goto copy;
    dstText[-1] = 0;
    goto done;
copy:
    ch = *srcText++;
    *dstText++ = ch;
    if ((signed char)ch != 0)
        goto decrement;
done:
    entryArray = *(void ***)((char *)arg0 + 0x18);
    selectedIndex = *(s32 *)((char *)arg0 + 0x9C);
    *(s32 *)((char *)arg0 + 0x98) = *(s32 *)entryArray[selectedIndex];
}

#pragma push
#pragma scheduling on
#pragma opt_loop_invariants off
#pragma use_lmw_stmw off
#pragma opt_common_subs off
void *fn_8024B73C(void *soundList, const char *searchName, void *entryTable) {
    extern char lbl_80343B70[];
    void fn_80236008(void *, s32, s32);
    void fn_80236134(void *, s32, s32);
    s32 fn_8024B178(s32);
    char *entry;
    s32 byteOffset, index;
    /* Build a sound-archive search result: set up its vtable, match array (capacity
     * 10) and name pool, record every entry whose name equals searchName, then
     * clear the current-selection fields. */
    *(s32 *)((char *)soundList + 0x14) = 0;
    *(void **)soundList = lbl_80343B70;
    *(void **)((char *)soundList + 0x18) = (char *)soundList + 0x24;
    *(s32 *)((char *)soundList + 0x20) = 10;
    *(s32 *)((char *)soundList + 0x1C) = 0;
    fn_80236008((char *)soundList + 0x4C, 10, 0);
    index = 0;
    byteOffset = 0;
    while (index < *(s32 *)((char *)entryTable + 4)) {
        entry = *(char **)entryTable + byteOffset;
        if (stricmp(searchName, *(char **)(entry + 0xC)) == 0) {
            register s32 matchCount;
            register void **matches;
            matchCount = *(s32 *)((char *)soundList + 0x1C);
            matches = *(void ***)((char *)soundList + 0x18);
            *(s32 *)((char *)soundList + 0x1C) = matchCount + 1;
            matches[matchCount] = entry;
            fn_80236134((char *)soundList + 0x4C, *(s32 *)entry, fn_8024B178(*(s32 *)entry));
        }
        byteOffset += 0x18;
        index++;
    }
    *(char *)((char *)soundList + 0x64) = 0;
    *(s32 *)((char *)soundList + 0x98) = -1;
    *(s32 *)((char *)soundList + 0x9C) = -1;
    return soundList;
}
#pragma pop
void fn_8024B830(void *container, s32 targetId) {
    /* Find the entry whose id matches targetId and store its index at +0x9C, or -1 if not found. */
    s32 byteOffset;
    s32 entryIndex;
    *(s32 *)((char *)container + 0x9C) = -1;
    entryIndex = 0;
    byteOffset = 0;
    while (entryIndex < *(s32 *)((char *)container + 0x1C)) {
        if (targetId == **(s32 **)((char *)*(s32 **)((char *)container + 0x18) + byteOffset))
            *(s32 *)((char *)container + 0x9C) = entryIndex;
        byteOffset += 4;
        entryIndex++;
    }
}

/* Return the address of the embedded field at offset 0x64 of base. */
s32 fn_8024B874(s32 base) { return base + 0x64; }

/* gEmptyString: shared zero buffer in .sdata, used as an empty C string fallback. */
#define gEmptyString lbl_8055BFD8

/* Return the s32 at offset 4 of the indexed entry in the config's entry array,
 * or a pointer to an empty string when the index is out of range. */
s32 fn_8024B87C(void *config, s32 index) {
    extern s32 gEmptyString;
    s32 **entries;
    if (index < *(s32 *)((char *)config + 0x1C)) {
        entries = *(s32 ***)((char *)config + 0x18);
        return *(s32 *)((char *)entries[index] + 4);
    }
    return (s32)&gEmptyString;
}

s32 fn_8024B8A4(void *config, s32 index) {
    /* Return the first s32 of the indexed entry in the config's entry array, or -1 when out of range. */
    s32 **entries;
    if (index < *(s32 *)((char *)config + 0x1C)) {
        entries = *(s32 ***)((char *)config + 0x18);
        return *(s32 *)entries[index];
    }
    return -1;
}

/* Return the address of the embedded field at offset 0x4C of base. */
s32 fn_8024B8CC(s32 base) {
    return base + 0x4C;
}

/* Return the address of the embedded field at offset 0x98 of base. */
s32 fn_8024B8D4(s32 base) {
    return base + 0x98;
}

/* Refreshes per-entry UI state: notifies the handler for the selected entry (0x9C),
   marks active entries with flag 0x14 clear, and marks inactive slots beyond 0x1C. */
void fn_8024B8DC(void *arg0) {
    int offset;
    int index;
    fn_80214CB4(*(int *)((char *)arg0 + 0x9C));
    index = 0;
    offset = 0;
    while (index < *(int *)((char *)arg0 + 0x20)) {
        if (index < *(int *)((char *)arg0 + 0x1C)) {
            if (*(unsigned char *)((char *)*(int *)((char *)*(int **)((char *)arg0 + 0x18) + offset) + 0x14) == 0) {
                fn_80214B44(index + 1);
            }
        } else {
            fn_80214A9C(index + 1);
        }
        offset += 4;
        index++;
    }
}

/* Tail-call the selected-entry cache refresh, forwarding the sound-list object pointer unchanged. */
void fn_8024B970(void *soundList) {
    fn_8024B6AC(soundList);
}

s32 fn_8024B974(void *selector) {
    /* Return the third s32 field (+0x28) of the selector's currently selected 0xC-byte entry. */
    char *entry = (char *)selector + *(s32 *)((char *)selector + 0x10) * 0xC;
    return *(s32 *)(entry + 0x28);
}

void fn_8024B988(void *selector) {
    /* Move the selection to the previous entry, wrapping to the last when at 0. */
    s32 count = *(s32 *)((char *)selector + 0x14);
    s32 index = *(s32 *)((char *)selector + 0x10);
    *(s32 *)((char *)selector + 0x10) = (count + index - 1) % count;
}

void fn_8024B9AC(void *selector) {
    /* Move the selection to the next entry, wrapping to the first when at the end. */
    s32 index = *(s32 *)((char *)selector + 0x10);
    s32 count = *(s32 *)((char *)selector + 0x14);
    *(s32 *)((char *)selector + 0x10) = (index + 1) % count;
}

s32 fn_8024B9CC(void *selector, s32 *outFirst, s32 *outSecond) {
    /* Read two values (+0x20, +0x24) from the selector's currently selected
     * 0xC-byte entry, write them to the two outputs, and return the first. */
    char *entry = (char *)selector + *(s32 *)((char *)selector + 0x10) * 0xC;
    s32 value1 = *(s32 *)(entry + 0x20);
    s32 value2 = *(s32 *)(entry + 0x24);
    *outFirst = value1;
    *outSecond = value2;
    return value1;
}

/* Returns the first s32 of the currently selected 8-byte entry in a selector's
   item array (array pointer at +0x10, selected index at +0x11C). */
s32 fn_8024B9EC(void *selector) {
    return *(s32 *)(*(char **)((char *)selector + 0x10) + *(s32 *)((char *)selector + 0x11C) * 8);
}

/* Race-movie selector, the list fn_8024BA00/fn_8024BAA0 step through: +0x10 is an
 * array of {id, name} pairs (+0x14 its count), +0x11C the current entry, +0x120 an
 * argument handed to the handler object at +0x124, and +0x128 a 0x20-byte buffer
 * holding the current entry's archive path "<name>/race.m2v". */
typedef struct RaceMovieSelector {
    char pad_00[0x10];
    s32 *items;    /* 0x10: {id, name} pairs, 8 bytes each */
    s32 count;     /* 0x14 */
    char pad_18[0x104];
    s32 index;     /* 0x11C: currently selected entry */
    s32 handlerArg; /* 0x120: first argument of the handler's select() */
    void *handler; /* 0x124: notified when the selection changes */
    char path[0x20]; /* 0x128: "<name>/race.m2v" */
} RaceMovieSelector;

#pragma cplusplus on
extern "C" void fn_8024BA00(RaceMovieSelector *selector) {
    #define sRacePathFormat lbl_80343E70 /* "%s/race.%s" */
    #define sM2vExtension   lbl_8055BFF8 /* "m2v" */
    #define sSnprintf       fn_801345D8
    class Base {
    public:
        char pad[0xC];
    };
    /* selection handler: vtable+0x30 = select(handlerArg, entryName) */
    class SelectionHandler : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void select(s32 handlerArg, s32 entryName);
    };
    s32 count = selector->count;
    s32 next = (count + selector->index - 1) % count;
    selector->index = next;
    ((SelectionHandler *)selector->handler)->select(selector->handlerArg, selector->items[next * 2 + 1]);
    sSnprintf(selector->path, 0x20, (const char *)&sRacePathFormat, selector->items[selector->index * 2 + 1], (const char *)&sM2vExtension);
}
#pragma cplusplus on
extern "C" void fn_8024BAA0(RaceMovieSelector *selector) {
    #define sRacePathFormat lbl_80343E70 /* "%s/race.%s" */
    #define sM2vExtension   lbl_8055BFF8 /* "m2v" */
    #define sSnprintf       fn_801345D8
    class Base {
    public:
        char pad[0xC];
    };
    /* selection handler: vtable+0x30 = select(handlerArg, entryName) */
    class SelectionHandler : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void select(s32 handlerArg, s32 entryName);
    };
    s32 next = (selector->index + 1) % selector->count;
    selector->index = next;
    ((SelectionHandler *)selector->handler)->select(selector->handlerArg, selector->items[next * 2 + 1]);
    sSnprintf(selector->path, 0x20, (const char *)&sRacePathFormat, selector->items[selector->index * 2 + 1], (const char *)&sM2vExtension);
}
#pragma cplusplus off
void fn_8024BB3C(void *sound) {
    /* Decrement the counter at +0x10 in place, saturating at zero (max(value - 1, 0)). */
    s32 decremented = *(s32 *)((char *)sound + 0x10) - 1;
    *(s32 *)((char *)sound + 0x10) = decremented & ((-decremented & ~decremented) >> 31);
}

void fn_8024BB5C(void *sound) {
    /* Increment the counter at +0x10 in place, saturating at 2 (min(value + 1, 2)). */
    register s32 capped = 2;
    register s32 incremented = *(s32 *)((char *)sound + 0x10) + 1;
    if (incremented <= 2) capped = incremented;
    *(s32 *)((char *)sound + 0x10) = capped;
}

s32 fn_8024BB7C(void *obj) {
    /* Return the difficulty-name string from lbl_802FA4B0 selected by the index at +0x10. */
    return *(s32 *)((char *)lbl_802FA4B0 + (*(s32 *)((char *)obj + 0x10) << 3) + 4);
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8024BB98(void *arg0) {
    class Base {
    public:
        char pad[0xC];
    };
    class Dummy : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12(s32 *, s32 *);
    };
    s32 out0;
    s32 out1;
    void *child = *(void **)((char *)arg0 + 0x4C);

    /* Query the child object for two ids via vtable slot 12, then apply the looked-up value to this object. */
    ((Dummy *)child)->v12(&out0, &out1);
    fn_80257BB8(arg0, *(s32 *)fn_80012870(out0, out1));
}
#pragma scheduling on
#pragma cplusplus off

extern char lbl_80343E60[];
#pragma cplusplus on
/* Fill this object's contest id (+0x34) and copy the selected contest's
 * "friendly_name" into its +0x38 string buffer (bounded to 100 bytes).
 * Leaves the id at -1 and an empty string when no selector is present. */
extern "C" void fn_8024BBF4(void *self) {
    class Base {
    public:
        char pad[0xC];
    };
    /* contest selector: vtable+0x38 = getSelection(&eventId, &contestIndex) */
    class Selector : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void getSelection(s32 *eventId, s32 *contestIndex);
    };
    /* contest record's parameter block: vtable+0x14 = get(name) -> string value */
    class Params {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *get(const char *name);
    };
    s32 contestIndex, eventId;
    unsigned char *src;
    unsigned char c;
    s32 remaining;
    unsigned char *dst;
    void *selector = *(void **)((char *)self + 0x30);
    if (selector != 0) {
        ((Selector *)selector)->getSelection(&eventId, &contestIndex);
        void *contest = (void *)fn_80012870(eventId, contestIndex);
        *(s32 *)((char *)self + 0x34) = *(s32 *)contest;
        Params *params = *(Params **)((char *)contest + 0x20);
        src = (unsigned char *)params->get(lbl_80343E60); /* "friendly_name" */
        remaining = 0x64;
        dst = (unsigned char *)self + 0x38;
        goto copy;
    check_remaining:
        remaining--;
        if (remaining > 0)
            goto copy;
        dst[-1] = 0;
        return;
    copy:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto check_remaining;
        return;
    }
    *(s32 *)((char *)self + 0x34) = -1;
    *(char *)((char *)self + 0x38) = 0;
}
#pragma cplusplus on
/* Virtual method (reached through the thunk at fn_8024BDF4, which shifts `this` by -0x18).
 * Asks the contest selector held at +0x30 for the current (event, contest) selection, looks
 * that contest record up with fn_80012870, keeps the record's id at +0x34 and copies the
 * record's parameter block (record+0x20) "friendly_name" string (lbl_80343E60) into the
 * 100-byte name buffer at +0x38, truncating it to fit. With no selector (+0x30 == 0) the id
 * becomes -1 and the name is cleared. */
extern "C" void fn_8024BCC0(void *self) {
    class Base {
    public:
        char pad[0xC];
    };
    /* contest selector: vtable+0x38 = getSelection(&eventId, &contestIndex) */
    class Selector : public Base {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void getSelection(s32 *eventId, s32 *contestIndex);
    };
    /* contest record's parameter block: vtable+0x14 = get(name) -> string value */
    class Params {
    public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual char *get(const char *name);
    };
    s32 contestIndex, eventId;
    unsigned char *src;
    unsigned char c;
    s32 remaining;
    unsigned char *dst;
    void *selector = *(void **)((char *)self + 0x30);
    if (selector != 0) {
        ((Selector *)selector)->getSelection(&eventId, &contestIndex);
        void *contest = (void *)fn_80012870(eventId, contestIndex);
        *(s32 *)((char *)self + 0x34) = *(s32 *)contest;
        Params *params = *(Params **)((char *)contest + 0x20);
        src = (unsigned char *)params->get(lbl_80343E60); /* "friendly_name" */
        remaining = 0x64;
        dst = (unsigned char *)self + 0x38;
        goto copy;
    check_remaining:
        remaining--;
        if (remaining > 0)
            goto copy;
        dst[-1] = 0;
        return;
    copy:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto check_remaining;
        return;
    }
    *(s32 *)((char *)self + 0x34) = -1;
    *(char *)((char *)self + 0x38) = 0;
}
#pragma scheduling on
#pragma cplusplus off
extern void *lbl_8055F28C;
static inline int find_sound_entry(int id) {
    int i;
    int count = *(int *)((char *)lbl_8055F28C + 4);
    for (i = 0; i < count; i++) {
        if (*(int *)(*(char **)lbl_8055F28C + i * 0x18) == id) return i;
    }
    return -1;
}
