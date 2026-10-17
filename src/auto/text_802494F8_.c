extern void *lbl_8055F28C;
static inline int find_sound_entry_inline(int *key) {
    void *table = lbl_8055F28C;
    int i;
    int count = *(int *)((char *)table + 4);
    for (i = 0; i < count; i++) {
        if (*key == *(int *)(*(char **)table + i * 0x18)) return i;
    }
    return -1;
}
static inline int find_sound_entry(int id);
typedef signed long s32;
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

int fn_8024958C(int *arg0) {
    int result = arg0[2] == 0x180302;
    if (result) result = find_sound_entry_inline(arg0) != -1;
    if (result) result = *(unsigned char *)(*(char **)lbl_8055F28C + find_sound_entry_inline(arg0) * 0x18 + 0x14);
    return result;
}

int fn_80249660(void) { return 1; }

int fn_80249668(int *arg0) {
    extern int lbl_802FA4C8[3];
    extern unsigned char lbl_8055F290;
    extern unsigned char lbl_8055F294[];
    extern int fn_802411D4(void);
    unsigned char *src;
    unsigned char *dst;
    int count;
    int index;

    index = fn_80214D04();
    src = (unsigned char *)(&lbl_802FA4C8[2])[index];
    dst = lbl_8055F294;
    count = 0x100;
    do {
        unsigned char c = *src++;
        *dst++ = c;
        if ((signed char)c == 0) break;
        count--;
    } while (count > 0);
    if (count == 0) dst[-1] = 0;
    if (lbl_8055F290 && fn_802411D4() == 0) {
        *arg0 = -1;
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

void *fn_8024A204(void *arg0, s32 arg1) {
    register s32 zero = 0;
    if (arg0 != 0) {
        *(s32 *)((char *)arg0 + 0x11C) = zero;
        if ((unsigned int)arg0 + 0x10 != 0) {
            if ((unsigned int)arg0 + 0x10 != 0) {
                *(s32 *)((char *)arg0 + 0x10) = zero;
                *(s32 *)((char *)arg0 + 0x14) = zero;
                *(s32 *)((char *)arg0 + 0x18) = zero;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8024A268(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(s32 *)((char *)arg0 + 0x10) = 0;
        *(s32 *)((char *)arg0 + 0x18) = -1;
        *(s32 *)((char *)arg0 + 0x1C) = 0;
        if (arg1 > 0) {
            fn_80128668(arg0);
        }
    }
    return arg0;
}

void fn_8024A2BC(void *arg0, s32 arg1, s32 arg2) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    char *entry = (char *)arg0;
    s32 index;
    for (index = 0; index < count; index++) {
        if (arg1 == *(s32 *)(entry + 0x20) && arg2 == *(s32 *)(entry + 0x24)) {
            *(s32 *)((char *)arg0 + 0x10) = index;
            return;
        }
        entry += 0xC;
    }
}

int stricmp(const char*, const char*);
void fn_8024A4B8(const char** arg0, const char** arg1) {
    stricmp(*arg0, *arg1);
}

s32 fn_8024974C(s32, s32, s32, s32);
void fn_8024A4C4(s32 arg0, s32 arg1, s32 arg2) {
    fn_8024974C(arg0, arg1, arg2, 0);
}

s32 fn_8024A6A4(s32 *arg0) {
    s32 result;
    if (fn_802411D4() == 0) {
        *arg0 = -1;
        result = 1;
    } else {
        result = 0;
    }
    return result;
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

int fn_8024B214(char *arg0, char *arg1) {
    unsigned char first = ((unsigned char *)arg0)[4];
    if (first != 0 && ((unsigned char *)arg1)[4] == 0) return 1;
    if (((unsigned char *)arg1)[4] != 0 && first == 0) return -1;
    return stricmp(*(char **)arg0, *(char **)arg1);
}

void fn_8024B544(void *arg0, char *arg1) {
    s32 offset;
    s32 index;
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
    do {
        fn_80214A9C(index + 1);
        index++;
    } while (index < *(s32 *)((char *)arg0 + 0x20));
    if (*(unsigned char *)((char *)arg0 + 0x284) == 0) {
        fn_80214A9C(10);
    } else {
        fn_80214AF0(10);
    }
    fn_8024B260(arg0);
}

void fn_8024B6A8(void) {
    fn_8024B260();
}

void fn_8024B6AC(void *arg0) {
    s32 index;
    s32 count;
    s32 *array;
    char *src;
    char *dst;
    char c;

    index = fn_80214D04();
    *(s32 *)((char *)arg0 + 0x9C) = index;
    array = *(s32 **)((char *)arg0 + 0x18);
    dst = (char *)arg0 + 0x64;
    count = 0x32;
    src = *(char **)((char *)array[index] + 0x10);
    goto decrement;
copy:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto decrement;
    goto done;
decrement:
    count--;
    if (count > 0)
        goto copy;
    *(s32 *)0 = 0;
    dst[-1] = 0;
done:
    array = *(s32 **)((char *)arg0 + 0x18);
    index = *(s32 *)((char *)arg0 + 0x9C);
    *(s32 *)((char *)arg0 + 0x98) = array[index];
}

void fn_8024B830(void *arg0, s32 arg1) {
    s32 offset;
    s32 index;
    index = 0;
    offset = 0;
    *(s32 *)((char *)arg0 + 0x9C) = -1;
    while (index < *(s32 *)((char *)arg0 + 0x1C)) {
        if (arg1 == **(s32 **)((char *)*(s32 **)((char *)arg0 + 0x18) + offset)) {
            *(s32 *)((char *)arg0 + 0x9C) = index;
        }
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
    register void *base = arg0;
    s32 offset;
    s32 index;
    fn_80214CB4(*(s32 *)((char *)base + 0x9C));
    index = 0;
    offset = 0;
    while (index < *(s32 *)((char *)base + 0x20)) {
        if (index < *(s32 *)((char *)base + 0x1C)) {
            if (*(unsigned char *)((char *)*(s32 *)((char *)*(s32 **)((char *)base + 0x18) + offset) + 0x14) == 0) {
                fn_80214B44(index + 1);
            }
        } else {
            fn_80214A9C(index + 1);
        }
        offset += 4;
        index++;
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
    register s32 value1 = *(s32 *)(entry + 0x20);
    register s32 value2 = *(s32 *)(entry + 0x24);
    *arg1 = value1;
    *arg2 = value2;
}

s32 fn_8024B9EC(void *arg0) {
    return *(s32 *)(*(char **)((char *)arg0 + 0x10) + *(s32 *)((char *)arg0 + 0x11C) * 8);
}

void fn_8024BA00(void *arg0) {
    s32 count = *(s32 *)((char *)arg0 + 0x14);
    s32 index = *(s32 *)((char *)arg0 + 0x11C);
    s32 *items = *(s32 **)((char *)arg0 + 0x10);
    s32 next = (count + index - 1) % count;
    void *object = *(void **)((char *)arg0 + 0x124);
    *(s32 *)((char *)arg0 + 0x11C) = next;
    ((void (*)(void *, s32, s32, s32, s32))(*(void ***)((char *)object + 0xC))[12])(object, *(s32 *)((char *)arg0 + 0x120), *(s32 *)((char *)items + next * 8 + 4), count - 1, count);
    fn_801345D8((char *)arg0 + 0x128, 0x20, &lbl_80343E70, *(s32 *)((char *)items + next * 8 + 4), &lbl_8055BFF8);
}

void fn_8024BAA0(void *arg0) {
    s32 index, count, next;
    s32 *items;
    void *object;
    index = *(s32 *)((char *)arg0 + 0x11C);
    count = *(s32 *)((char *)arg0 + 0x14);
    next = (index + 1) % count;
    items = *(s32 **)((char *)arg0 + 0x10);
    *(s32 *)((char *)arg0 + 0x11C) = next;
    object = *(void **)((char *)arg0 + 0x124);
    ((void (*)(void *, s32, s32, s32, s32))(*(void ***)((char *)object + 0xC))[12])(object, *(s32 *)((char *)arg0 + 0x120), *(s32 *)((char *)items + next * 8 + 4), count, index + 1);
    fn_801345D8((char *)arg0 + 0x128, 0x20, &lbl_80343E70, *(s32 *)((char *)items + next * 8 + 4), &lbl_8055BFF8);
}

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

void *fn_80012870(s32, s32);
extern char lbl_80343E60[];
void fn_8024BBF4(void *arg0) {
    s32 spC, sp8;
    void *obj;
    void *result;
    char *src, *dst;
    s32 count;
    if ((obj = *(void **)((char *)arg0 + 0x30)) != 0) {
        ((void (*)(void *, s32 *, s32 *))*(void **)((char *)*(void **)((char *)obj + 0xC) + 0x38))(obj, &sp8, &spC);
        result = fn_80012870(sp8, spC);
        *(s32 *)((char *)arg0 + 0x34) = *(s32 *)result;
        obj = *(void **)((char *)result + 0x20);
        src = (char *)((char *(*)(void *, char *))*(void **)((char *)*(void **)obj + 0x14))(obj, lbl_80343E60);
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
