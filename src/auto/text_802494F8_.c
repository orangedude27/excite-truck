typedef signed long s32;
typedef s32 (*UnkFunc)(s32);

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

long __dt__Q36nw4hbm3snd18MemorySoundArchiveFv_8024A1AC(long arg0, long arg1) {
    if (arg0 != 0) {
        fn_80236074((void*)arg0, 0);
        if (arg1 > 0) {
            fn_80128668((void*)arg0);
        }
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

s32 fn_8024B874(s32 arg0) { return arg0 + 0x64; }

s32 fn_8024B8CC(s32 arg0) {
    return arg0 + 0x4C;
}

