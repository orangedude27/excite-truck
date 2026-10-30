// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <macros.h>
extern void fn_802CBD30(void **, void **, void *);
#pragma dont_inline fn_802CBD30
extern char lbl_8034BA98[];
#pragma dont_inline fn_802CB3F8
extern void fn_802E317C(const char *, ...);
extern char lbl_8034B538[];
extern void *jumptable_8034B794[];
extern char lbl_8034B618[];
extern int lbl_8055D058;
extern int fn_802C90E0(void);
extern int fn_802D8E9C(void *, unsigned int);
extern int lbl_8055D038;
extern int lbl_8055D040;
extern int fn_8012850C(int, int *);
extern void fn_802CB424(void);
extern void fn_802E30C8(const char *, ...);
extern int fn_802D92B8(int);
extern int lbl_8055D03C;
extern char lbl_8034B5F0[];
void fn_802CAC54(int);
void fn_802CB6B4(void);
int fn_80128670(int);
int fn_802CA2A8(void *, int, int);
int fn_8012C5B8(void *, int, int *);
int fn_8012C6F0(void);
int fn_8012C958(int);

#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
DECL_SECTION(".sdata") extern int lbl_8055FCB4;
DECL_SECTION(".sdata") extern int lbl_8055FCB8;
void fn_802D8FB4(void);
void fn_802D9160(int, int);
void fn_802DBDE8(int, int);
#pragma small_data off
#pragma pop

extern char lbl_8055D07D;
extern float lbl_80564F30;
#pragma scheduling invalid_target
extern void fn_802CAC28(int, int);
void fn_802CA0E4(void) {
    char *strings = lbl_8034B538;
    int offset;
    int i;
    int result;
    register int base;

    lbl_8055FCB0 = fn_8012850C(0x9800, &lbl_8055D040);
    fn_802CB424();
    i = 0;
    offset = 0;
    do {
        memset((void *)(lbl_8055FCB0 + offset), 0, 0x4C);
        i++;
        offset += 0x4C;
    } while (i < 0x200);
    lbl_8055FCB8 = -2;
    result = ((int (*)(int, int))fn_802CAC28)(lbl_8055D038, 0);
    lbl_8055FCB4 = result;
    if (result == -1)
        fn_802E317C(strings + 0x40, lbl_8055D038);
    result = ((int (*)(int, int))fn_802CAC28)((int)(strings + 0x60), 0);
    lbl_8055D03C = result;
    if (result != -1) {
        fn_802E30C8(strings + 0x6C);
        base = lbl_8055FCB0;
        base += lbl_8055D03C * 0x4C;
        fn_802D92B8(*(int *)(base + 0x28));
        return;
    }
    fn_802E30C8(strings + 0x88);
}

void fn_802CA1E0(void) {
    int offset;
    int i;
    if (lbl_8055D03C != -1) {
        fn_802CAC54(lbl_8055D03C);
        lbl_8055D03C = -1;
    }
    fn_802CAC54(lbl_8055FCB4);
    lbl_8055FCB4 = -1;
    i = 0;
    offset = 0;
    do {
        if (*(int *)(lbl_8055FCB0 + offset) != 0)
            fn_802E317C(lbl_8034B5F0, i, lbl_8055FCB0 + offset + 4);
        i++;
        offset += 0x4C;
    } while (i < 0x200);
    fn_802CB6B4();
    fn_80128670(lbl_8055FCB0);
    lbl_8055FCB0 = 0;
}
#pragma scheduling on
int fn_802CA294(int arg0) {
    int offset = arg0 * 0x4C;
    int *base = (int *)lbl_8055FCB0;
    return *(int *)((char *)base + offset + 0x28);
}

extern char *fn_80029004(char *, int);
extern char lbl_8055D048;
int fn_802CA2A8(void *arg0, int arg1, int arg2) {
    int remaining = arg1;
    char *dst = (char *)arg0;
    const char *src = (const char *)arg2;
    const char *suffix;
    char *cursor;
    char *dot;

    {
        int copy_count = arg1;
        char *write = dst;
        while ((signed char)(*write++ = *src++) != 0) {
            if (--copy_count <= 0) {
                write[-1] = 0;
                break;
            }
        }
    }

    dot = fn_80029004(dst, '.');
    *dot = 0;
    suffix = &lbl_8055D048;
    cursor = dst;
    while ((signed char)*cursor != 0) {
        --remaining;
        ++cursor;
    }
    if (remaining > 0) {
        while ((signed char)(*cursor++ = *suffix++) != 0) {
            if (--remaining <= 0) {
                cursor[-1] = 0;
                break;
            }
        }
    }
    return (int)dst;
}

int fn_802CA380(int arg0) {
    char sp10[0x20];
    int sp8;
    int result;
    int temp;
    result = 0;
    fn_802CA2A8(sp10, 0x20, arg0);
    temp = fn_8012C5B8(sp10, 0x54455820, &sp8);
    if (temp != 0) {
        result = fn_8012C6F0();
        fn_8012C958(temp);
    }
    return result;
}

#pragma use_lmw_stmw off
int fn_802CA3F4(void *arg0, int arg1, int arg2, int arg3, int arg4) {
    register unsigned char *src = (unsigned char *)arg1;
    register int value = arg2;
    register int mode1 = arg3;
    register int mode2 = arg4;
    register int *dst = (int *)arg0;
    unsigned char c5, c12, c4, c7, c6, c10;
    unsigned short h12, h0, h2;
    int ptr14;
    int flags;

    memset(arg0, 0, 0x34);
    c5 = src[5];
    c12 = src[0xB];
    c4 = src[4];
    c7 = src[7];
    c6 = src[6];
    h12 = *(unsigned short *)(src + 0xC);
    c10 = src[0xA];
    h0 = *(unsigned short *)src;
    h2 = *(unsigned short *)(src + 2);
    ptr14 = *(int *)(src + 0x14);
    flags = c12 & 1;
    dst[2] = flags;
    dst[0] = c5 & 0x7F;
    dst[5] = c7;
    dst[4] = c6;
    dst[3] = h12;
    dst[6] = c12;
    *(unsigned char *)((char *)arg0 + 0x1C) = c10;
    dst[1] = value;
    dst[8] = (signed char)c4;
    dst[9] = h0;
    dst[10] = h2;
    dst[11] = ptr14;
    dst[12] = mode1;
    if (mode2 == 2) {
        flags |= 1;
        dst[2] = flags;
    } else if (mode2 == 6) {
        flags |= 2;
        dst[2] = flags;
    } else if (mode2 == 5) {
        flags |= 4;
        dst[2] = flags;
    }
}
#pragma use_lmw_stmw on
int fn_802CA4E0(int arg0, int arg1, int arg2, int arg3, int arg4) {
    char sp8[0x34];

    if (fn_802C90E0() == 0 && (unsigned int)arg1 != (unsigned int)lbl_8055D058) {
        const char *format = lbl_8034B618;
        fn_802E30C8(format, arg1);
    }
    fn_802CA3F4(sp8, arg0, arg2 == 1 ? 3 : 1, arg3, arg4);
    return fn_802D8E9C(sp8, arg1);
}

extern void fn_802D8DCC(void *, int);
#pragma scheduling invalid_target
void fn_802CA57C(void *arg0, int arg1, int arg2, int arg3) {
    register unsigned char *resource = (unsigned char *)arg0;
    register int context = arg1;
    volatile unsigned char *base = resource;
    unsigned char temp_r10;
    unsigned char temp_r11;
    unsigned char temp_r12;
    unsigned char temp_r29;
    unsigned char temp_r30;
    unsigned char temp_r8;
    unsigned char temp_r9;
    unsigned char temp_r9_2;
    unsigned char temp_r0;
    char sp8[0x34];

    if ((base[5] & 0x80) == 0) {
        temp_r9 = base[0x14];
        temp_r8 = base[0x17];
        temp_r29 = base[0x15];
        temp_r0 = base[0x16];
        base[0x14] = temp_r8;
        temp_r11 = base[0];
        temp_r10 = base[1];
        base[0x17] = temp_r9;
        temp_r12 = base[2];
        temp_r9_2 = base[3];
        base[0x15] = temp_r0;
        temp_r30 = base[0xC];
        temp_r8 = base[0xD];
        base[0x16] = temp_r29;
        base[0] = temp_r10;
        base[1] = temp_r11;
        base[2] = temp_r9_2;
        base[3] = temp_r12;
        base[0xC] = temp_r8;
        base[0xD] = temp_r30;
        *(int *)(base + 0x14) = (int)(resource + *(int *)(base + 0x14));
        ((void (*)(void *, int, int, int, int, int, int, int))fn_802CA3F4)(sp8, (int)resource, 0, arg2, arg3, temp_r8, temp_r9_2, temp_r10);
        fn_802D8DCC(sp8, context);
        base[5] |= 0x80;
    }
}
#pragma scheduling on
extern int fn_8012C370(const char *, int *, int *, signed char *, unsigned char *);
extern char lbl_8034B634[];
extern char lbl_8034B658[];
extern void fn_802CA57C(void *, int, int, int);
#pragma scheduling invalid_target
int fn_802CA658(int arg0, int arg1) {
    unsigned int sp10;
    int spC;
    signed char sp9 = 0;
    unsigned char sp8 = 0;
    int result;
    register unsigned int check;
    result = ((int (*)(int, int, unsigned int *, int *, signed char *, unsigned char *))fn_8012C370)(arg0, 0x54455820, &sp10, &spC, &sp9, &sp8);
    if (result != 0) {
        if ((result & 0x7F) != 0)
            fn_802E317C(lbl_8034B634, arg0, result);
        check = sp10;
        if (check != 0xF)
            fn_802E317C(lbl_8034B658, arg0);
        if (sp8 != 0)
            fn_802CA57C((void *)result, arg0, 0, arg1);
    }
    return result;
}
#pragma scheduling on
char *fn_802CA72C(unsigned int arg0) {
    char *base = lbl_8034B538;
    switch (arg0) {
    case 0: return base + 0x140;
    case 1: return base + 0x150;
    case 2: return base + 0x174;
    case 3: return base + 0x180;
    case 4: return base + 0x190;
    case 5: return base + 0x1A0;
    case 6: return base + 0x1B4;
    case 7: return base + 0x1C0;
    case 8: return base + 0x1CC;
    case 9: return base + 0x1E0;
    case 10: return base + 0x1F0;
    case 11: return base + 0x20C;
    case 12: return base + 0x21C;
    case 13: return base + 0x228;
    case 14: return base + 0x244;
    default: return base + 0x250;
    }
}

#pragma dont_inline fn_802CA7D4
char fn_802CA7D4(void) { return 1; }

#pragma dont_inline fn_802CA7DC
int fn_802CA7DC(const unsigned char *arg0) { return ((signed char)*arg0 - 0x2A) == 0; }

#pragma dont_inline fn_802CA7F4
int fn_802CA7F4(const char *arg0) { return strchr(arg0, 0x2F) != 0; }

extern int fn_802CA824(int);
extern void fn_802CA57C(void *, int, int, int);
extern int fn_802CA4E0(int, int, int, int, int);
extern int stricmp(const char *, const char *);
extern unsigned int strlen(const char *);
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma dont_inline on
int fn_802CA898(int arg0, int arg1, int arg2, int arg3) {
    int path_value;
    register int strings;
    register int flag;
    register int best;
    register int index;
    int offset;
    int resource;
    register int *entry;
    int size;
    char *src;
    char *dst;
    int count;
    int c;
    unsigned char first;

    path_value = arg0;
    strings = (int)lbl_8034B538;
    if (strlen((char *)path_value) >= 0x10 &&
        ((int (*)(const char *))fn_802CA7DC)((char *)path_value) == 0 &&
        fn_802CA7F4((char *)path_value) == 0) {
        fn_802E317C((const char *)(strings + 0x2B8), (char *)path_value, strlen((char *)path_value), 0x10);
    }
    if (strlen((char *)path_value) >= 0x20)
        fn_802E317C((const char *)(strings + 0x2E0), (char *)path_value, strlen((char *)path_value), 0x20);
    if ((signed char)*(char *)path_value == 0 && arg3 == 1)
        path_value = (int)(strings + 0x30C);

    first = *(unsigned char *)path_value;
    flag = arg2 != 0;
    if ((signed char)first == 0 || (signed char)first == '.' || (signed char)first == '#')
        return -1;

    best = -1;
    index = 0;
    offset = 0;
    do {
        entry = (int *)(lbl_8055FCB0 + offset);
        if (entry[0] > 0) {
            if (stricmp((char *)entry + 4, (char *)fn_802CA824((int)(char *)path_value)) == 0 &&
                entry[0x24 / 4] == arg1 &&
                flag == 0) {
                offset = index * 0x4C;
                if (((int (*)(int, int, int))fn_802CA7D4)((int)(char *)path_value, arg3, *(int *)(lbl_8055FCB0 + offset + 0x34)) == 0) {
                    fn_802E30C8((const char *)(strings + 0x318), (char *)path_value);
                    *(int *)(lbl_8055FCB0 + offset + 0x3C) = 0;
                    *(int *)(lbl_8055FCB0 + offset + 0x34) = 0xE;
                }
                entry[0]++;
                return index;
            }
        } else if (best < 0) {
            best = index;
        }
        index++;
        offset += 0x4C;
    } while (index < 0x200);

    if (best < 0)
        fn_802E317C((const char *)(strings + 0x33C), (char *)path_value);

    if (flag == 0) {
        resource = fn_802CA658((int)(char *)path_value, arg3);
        if (resource == 0) {
            fn_802E30C8((const char *)(strings + 0x354), (char *)path_value);
            resource = fn_802CA658((int)(strings + 0x370), 0xE);
        }
    } else {
        resource = arg2;
        ((int (*)(int, int, int, int))fn_802CA57C)(resource, (int)(char *)path_value, 0, arg3);
    }
    if (resource == 0)
        return -1;

    entry = (int *)(lbl_8055FCB0 + best * 0x4C);
    *(signed char *)((char *)entry + 0x30) = flag;
    entry[0] = 1;
    entry[0x48 / 4] = 0;
    entry[0x24 / 4] = arg1;

    if (((int (*)(const char *))fn_802CA7DC)((char *)path_value) == 0) {
        src = (char *)path_value;
        dst = (char *)entry + 4;
        count = 0x20;
        goto copy1_body;
copy1_check:
        count--;
        if (count > 0)
            goto copy1_body;
        dst[-1] = 0;
        goto copy1_done;
copy1_body:
        c = (unsigned char)*src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto copy1_check;
copy1_done:
        if (flag != 0)
            size = 0;
        else
            size = fn_802CA380((int)(char *)path_value);
        entry[0x3C / 4] = size;
        if (size < 0x3E80)
            entry[0x3C / 4] = 0;
    } else {
        fn_802E30C8((const char *)(strings + 0x380), (char *)path_value);
        src = (char *)fn_802CA824((int)(char *)path_value);
        dst = (char *)entry + 4;
        count = 0x20;
        goto copy2_body;
copy2_check:
        count--;
        if (count > 0)
            goto copy2_body;
        dst[-1] = 0;
        goto copy2_done;
copy2_body:
        c = (unsigned char)*src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto copy2_check;
copy2_done:
        entry[0x3C / 4] = 0;
    }

    entry[0x40 / 4] = 0;
    entry[0x44 / 4] = 0;
    entry[0x2C / 4] = resource;
    entry[0x34 / 4] = arg3;
    entry[0x28 / 4] = fn_802CA4E0(resource, (int)(char *)path_value, 0, 0, arg3);
    lbl_8055FCB8 = -2;
    return best;
}
#pragma dont_inline reset
#pragma scheduling on
#pragma use_lmw_stmw reset
void fn_802CAC28(int arg0, int arg1) {
    fn_802CA898(arg0, arg1, 0, 0xE);
}

void fn_802CAC34(int arg0, int arg1) {
    fn_802CA898(arg0, 0, arg1, 0xE);
}

void fn_802CAC44(int arg0, int arg1) {
    fn_802CA898(arg0, 0, 0, arg1);
}

extern void fn_8012C4D8(void *);
extern void fn_802CB82C(int);
extern void fn_802CAD28(int);
extern char lbl_8034B8E0[];
#pragma scheduling invalid_target
void fn_802CAC54(int arg0) {
    int *entry;

    if (arg0 == -1)
        return;
    if (arg0 >= 0 && arg0 < 0x200) {
        if (*(int *)((char *)lbl_8055FCB0 + arg0 * 0x4C) <= 0)
            fn_802E317C(lbl_8034B8E0, (char *)lbl_8055FCB0 + arg0 * 0x4C + 4);
    }
    entry = (int *)((char *)lbl_8055FCB0 + arg0 * 0x4C);
    if (*(unsigned char *)((char *)entry + 0x30) != 0) {
        fn_802CAD28(arg0);
        return;
    }
    entry[0]--;
    if (entry[0] == 0 && entry[0x2C / 4] != 0) {
        fn_802CB82C(arg0);
        fn_8012C4D8((void *)entry[0x2C / 4]);
        entry[0x2C / 4] = 0;
        ((void (*)(int))fn_802D8FB4)(entry[0x28 / 4]);
    }
}
#pragma scheduling on
void fn_802CAD28(int arg0) {
    int *p;
    int value;
    if (arg0 == -1)
        return;
    p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    value = --p[0];
    if (value != 0)
        return;
    if (p[0x2C / 4] == 0)
        return;
    p[0x2C / 4] = 0;
    ((void (*)(int))fn_802D8FB4)(p[0x28 / 4]);
}

void fn_802CAD68(void) {
    lbl_8055FCB8 = -2;
}

#pragma dont_inline fn_802CAD74
void fn_802CAD74(register int arg0) {
retry:
    if (arg0 == lbl_8055FCB8)
        return;
    lbl_8055FCB8 = arg0;
    if (arg0 == -1)
        goto retry_prev;
    goto process;
retry_prev:
    arg0 = *(volatile int *)&lbl_8055FCB4;
    goto retry;
process:
    {
        int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
        int value;
        p[0x48 / 4]++;
        value = p[0x40 / 4];
        if (value != 0)
            fn_802D9160(value, 0);
        else
            fn_802D9160(p[0x28 / 4], 0);
    }
}
void fn_802CADD0(int arg0, int arg1) {
    int offset;
    char *base;
    if (arg0 == -1) {
        fn_802DBDE8(arg1, 0);
    } else {
        offset = arg0 * 0x4C;
        base = (char *)lbl_8055FCB0;
        fn_802DBDE8(arg1, *(int *)(base + offset + 0x28));
    }
}

int fn_802CAE00(int arg0) {
    int value = 0;
    if (arg0 >= 0 && arg0 < 0x200 &&
        *(int *)(lbl_8055FCB0 + arg0 * 0x4C) > 0) {
        value = 1;
    }
    return value;
}

extern int fn_802C90E0(void);
extern void fn_802E30C8(const char *, ...);
extern int fn_802CA3F4(void *, int, int, int, int);
extern int fn_802D8E9C(void *, unsigned int);
extern char lbl_8034B618[];
extern char lbl_8034B538[];
extern void *jumptable_8034B794[];
extern int fn_802CAE00(int);
extern int lbl_8055FCB0;
extern char lbl_8034B904[];
extern char lbl_8034B914[];
char *fn_802CAE34(int arg0) {
    int offset;
    char *result;
    if (arg0 == -1)
        return lbl_8034B904;
    if (!((int (*)(int))fn_802CAE00)(arg0))
        return lbl_8034B914;
    offset = arg0 * 0x4C;
    result = (char *)lbl_8055FCB0 + offset;
    return result + 4;
}
#pragma dont_inline on
void fn_802CAE98(int arg0, char *arg1) {
    int count;
    char *dst;
    unsigned char c;

    if (!((int (*)(int))fn_802CAE00)(arg0))
        return;
    dst = (char *)lbl_8055FCB0 + arg0 * 0x4C + 4;
    count = 0x20;
    goto copy;
count_check:
    if (--count > 0)
        goto copy;
    dst[-1] = 0;
    goto done;
copy:
    c = *arg1++;
    *dst++ = c;
    if ((signed char)c != 0)
        goto count_check;
    goto done;
done:
    ;
}

void fn_802CAF1C(int arg0, signed char arg1, signed char arg2) {
    int offset;
    int ptr;
    if (fn_802CAE00(arg0)) {
        offset = arg0 * 0x4C;
        ptr = *(int *)(lbl_8055FCB0 + offset + 0x2C);
        *(signed char *)(ptr + 8) = arg1;
        ptr = *(int *)(lbl_8055FCB0 + offset + 0x2C);
        *(signed char *)(ptr + 9) = arg2;
    }
}

#pragma dont_inline reset
int fn_802DB2C0(int);
void fn_802CA57C(void *, int, int, int);
int fn_802CA4E0(int, int, int, int, int);
int fn_802CA898(int, int, int, int);
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
void fn_802D8FB4(void);
extern int lbl_8055D058;
extern int lbl_8055D078;
#pragma scheduling invalid_target
#pragma dont_inline fn_802CB38C
int fn_802CB38C(void *arg0, void *arg1, void *arg2) {
    register void *saved0 = arg0;
    register void *saved2 = arg2;
    register void *saved1 = arg1;
    ((void (*)(void *, int, int, void *))fn_802CA57C)(saved0, (int)&lbl_8055D078, 0, saved2);
    return fn_802CA4E0((int)saved0, lbl_8055D058, 0, (int)saved1, (int)saved2);
}
#pragma scheduling on
void fn_802CB3F4(void) {
    fn_802D8FB4();
}

void fn_802CB3F8(void) {
}

DECL_SECTION(".sdata") extern char lbl_8055FCBC[];
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern int lbl_8055FCB0;
#pragma small_data off
#pragma pop
extern float lbl_80564F40;
extern float lbl_80564F44;
extern float lbl_8055FCC4;
  extern unsigned short lbl_8055FCA8;
int fn_802CAF8C(int arg0) {
    int *entry;
    unsigned short expected;
    if (arg0 == -1)
        return 0;
    entry = (int *)(arg0 * 0x4C + lbl_8055FCB0);
    expected = lbl_8055FCA8;
    return *(unsigned short *)(*(entry + 11) + 0xC) != expected;
}
void fn_802CC550(int, float, float);
int fn_802CB274(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    return fn_802DB2C0(p[0x28 / 4]);
}

int fn_802DB2C4(int);
int fn_802CB288(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    return fn_802DB2C4(p[0x28 / 4]);
}

extern void fn_802D93E8(int);
extern void fn_802D9418(void);
extern int lbl_8055D06C;
void fn_802CB29C(int arg0) {
    if (arg0 != -1 && arg0 != -2) {
        int offset = arg0 * 0x4C;
        int *entry = (int *)(lbl_8055FCB0 + offset);
        fn_802D93E8(entry[0x28 / 4]);
        lbl_8055D06C = arg0;
        return;
    }
    fn_802D9418();
    lbl_8055D06C = -2;
}

char fn_802CAFC8(int arg0) {
    int offset;
    char *base;
    if (arg0 == -1)
        return 5;
    offset = arg0 * 0x4C;
    base = (char *)lbl_8055FCB0;
    return *(char *)(*(int *)(base + offset + 0x2C) + 8);
}

char fn_802CAFF0(int arg0) {
    int offset;
    char *base;
    if (arg0 == -1)
        return 0x32;
    offset = arg0 * 0x4C;
    base = (char *)lbl_8055FCB0;
    return *(char *)(*(int *)(base + offset + 0x2C) + 9);
}

extern char lbl_8034B940[];
#pragma scheduling invalid_target
int fn_802CB018(void) {
    int index = 1;
    int result = -1;
    int group;
    unsigned char *base = (unsigned char *)lbl_8055FCB0 + 0x4C;

    for (group = 0; group < 0x49; group++) {
        if (*(int *)(base + 0x00) == 0) { result = index; goto found; }
        index++;
        if (*(int *)(base + 0x4C) == 0) { result = index; goto found; }
        index++;
        if (*(int *)(base + 0x98) == 0) { result = index; goto found; }
        index++;
        if (*(int *)(base + 0xE4) == 0) { result = index; goto found; }
        index++;
        if (*(int *)(base + 0x130) == 0) { result = index; goto found; }
        index++;
        if (*(int *)(base + 0x17C) == 0) { result = index; goto found; }
        index++;
        if (*(int *)(base + 0x1C8) == 0) { result = index; goto found; }
        index++;
        base += 0x214;
    }
found:
    if (result < 0)
        fn_802E317C(lbl_8034B940);
    return (int)((unsigned char *)lbl_8055FCB0 + result * 0x4C);
}
#pragma scheduling on

#pragma push
#pragma small_data on
extern char lbl_8055D05C;
extern char lbl_8055D064;
extern unsigned short lbl_8055FCAA;
#pragma small_data off
#pragma pop
extern int fn_802CB2FC(int, int, int, unsigned char, unsigned short, unsigned char);
#pragma push
#pragma small_data on
#pragma small_data off
#pragma pop
#pragma push
#pragma dont_inline on
#pragma use_lmw_stmw off
int fn_802CB128(int arg0, int arg1, int arg2, int arg3) {
    register int n;
    const char *name;
    unsigned short id;
    int flags;
    int *p;

    id = lbl_8055FCAA;
    name = &lbl_8055D05C;
    flags = 3;
    if (arg3 & 0x20)
        flags = 2;
    if (arg3 & 0x40)
        flags = (unsigned char)(flags & 7);
    n = (arg3 & 1) + 2;
    p = (int *)((int (*)(int))fn_802CB018)(arg3 & 1);
    memset(p, 0, 0x4C);
    p[0] = 1;
    p[9] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[13] = 0xE;
    strcpy((char *)p + 4, name);
    p[11] = fn_802CB2FC(arg0, arg1, 1, (unsigned char)n, id, flags);
    p[10] = fn_802CA4E0(p[11], (int)&lbl_8055D064, 1, 0, p[13]);
    return ((char *)p - (char *)lbl_8055FCB0) / 0x4C;
}
#pragma use_lmw_stmw on
#pragma dont_inline reset
#pragma pop

void fn_802CB228(int arg0) { int *entry = (int *)(lbl_8055FCB0 + arg0 * 0x4C); ((void (*)(int))fn_802D8FB4)(entry[0x28 / 4]); fn_80128668(entry[0x2C / 4]); entry[0x2C / 4] = 0; entry[0] = 0; }

unsigned short fn_802CB3FC(int arg0) {
    int *p = (int *)(lbl_8055FCB0 + arg0 * 0x4C);
    unsigned short *q = (unsigned short *)p[0x2C / 4];
    if ((int)q[1] > (int)q[0])
        return q[1];
    return q[0];
}

extern char lbl_8034BAEC[];
extern char lbl_8034BB1C[];
extern char lbl_8034BB5C[];
extern char lbl_8034BB68[];
extern char lbl_8034BB7C[];
extern char lbl_8034BB88[];
extern char lbl_8034BB9C[];
extern char lbl_8034BBA8[];
extern char lbl_8055D098;
#pragma use_lmw_stmw off
void fn_802CB6B4(void) {
    register void *manager;
    register unsigned int total;
    register void *record;
    register void *root = *(void **)lbl_8055FCBC;
    register unsigned int secondTotal;

    if (root != 0) {
        if (root != 0) {
            fn_80128670(*(int *)((char *)root + 8));
            fn_80128670(*(int *)((char *)root + 0x14));
            *(int *)((char *)root + 0x38) = 0;
            manager = *(void **)((char *)root + 0x24);
            if (manager != 0) {
                if (*(int *)((char *)manager + 0xC) != 0) {
                    fn_802E30C8(lbl_8034BBA8, lbl_8034BB1C);
                    fn_802E30C8(lbl_8034BB9C);
                    total = 0;
                    record = *(void **)((char *)manager + 0xC);
                    while (record != 0) {
                        fn_802E30C8(lbl_8034BB88, (char *)record + 0x10, *(int *)((char *)record + 4));
                        total += *(unsigned int *)((char *)record + 4);
                        record = *(void **)((char *)record + 8);
                    }
                    fn_802E30C8(lbl_8034BB7C, total >> 10);
                    secondTotal = 0;
                    fn_802E30C8(&lbl_8055D098);
                    record = *(void **)((char *)manager + 8);
                    while (record != 0) {
                        fn_802E30C8(lbl_8034BB68, (char *)record + 0x10, *(int *)((char *)record + 4));
                        secondTotal += *(unsigned int *)((char *)record + 4);
                        record = *(void **)((char *)record + 8);
                    }
                    fn_802E30C8(lbl_8034BB5C, secondTotal >> 10);
                    fn_802E317C(lbl_8034BAEC);
                }
                fn_80128668(manager);
            }
            fn_80128670(*(int *)((char *)root + 0x20));
            *(int *)((char *)root + 0x20) = 0;
            *(void **)((char *)root + 0x24) = 0;
            *(int *)((char *)root + 0x28) = 0;
        }
        fn_80128668(root);
    }
    *(void **)lbl_8055FCBC = 0;
}
#pragma use_lmw_stmw on

extern void fn_8012C90C(int);
extern void fn_802D915C(void *);
extern void fn_802CBB9C(int **, int, int *);
extern char lbl_8034B9F4;
#pragma push
#pragma small_data on
DECL_SECTION(".sdata") extern char lbl_8055FCBC[];
#pragma push
#pragma small_data on
#pragma push
#pragma small_data on
#pragma small_data off
#pragma pop
void fn_802CB82C(int arg0) {
    char *temp_r30;
    char *temp_r31;
    char *temp_r29;
    int temp_r0;
    char *pool, *node, *other, *joined;
    char **link, **mergeLink, **scanLink;
    int pageSize, merged, mergeCandidate;

    temp_r29 = *(char **)lbl_8055FCBC;
    temp_r31 = temp_r29 + arg0 * 0x14;
    temp_r0 = *(int *)(temp_r31 + 0x40);

    if (temp_r0 == 2) {
        temp_r30 = (char *)lbl_8055FCB0 + arg0 * 0x4C;
        ((void (*)(int))fn_802CB3F4)(*(int *)(temp_r30 + 0x40));
        *(int *)(temp_r30 + 0x40) = 0;
        pool = *(char **)(*(char **)(temp_r29 + 0x38) + 4);
        link = (char **)(pool + 0xC);
        node = (char *)(*(int *)(temp_r30 + 0x44) - (*(int *)(pool + 4) + 1));
        other = *link;
        if (other != 0) {
            do {
                if (other == node) {
                    *link = *(char **)(node + 8);
                    break;
                }
                link = (char **)(other + 8);
                other = *link;
            } while (other != 0);
        }
        mergeLink = (char **)(pool + 8);
        *(char **)(node + 8) = *mergeLink;
        *mergeLink = node;
        do {
            scanLink = (char **)(pool + 8);
            merged = 0;
        merge2:
            other = *scanLink;
            if (other != 0) {
                joined = *mergeLink;
                pageSize = *(int *)(pool + 4);
                mergeCandidate = 1;
                if (((char *)joined + pageSize + *(int *)(joined + 4) + 1 != other) &&
                    ((char *)other + pageSize + *(int *)(other + 4) + 1 != joined))
                    mergeCandidate = 0;
                if (mergeCandidate != 0) {
                    link = mergeLink;
                    if ((char *)other + pageSize + *(int *)(other + 4) + 1 == joined) {
                        link = scanLink;
                        scanLink = mergeLink;
                    }
                    joined = *link;
                    mergeLink = link;
                    merged = 1;
                    *(int *)(joined + 4) = (((pageSize + 0x10) & ~pageSize) +
                        (*(int *)(joined + 4) + *(int *)(*scanLink + 4)));
                    *scanLink = *(char **)(*scanLink + 8);
                } else {
                    scanLink = (char **)(other + 8);
                    goto merge2;
                }
            }
        } while (merged != 0);
        *(int *)(temp_r30 + 0x44) = 0;
        ((void (*)(void *, void *))fn_802CB3F8)(temp_r30 + 4, &lbl_8034B9F4);
    } else if (temp_r0 == 1) {
        temp_r30 = *(char **)temp_r29;
    find:
        if (temp_r30 != 0) {
            if (*(int *)(temp_r30 + 4) == arg0) {
                other = *(char **)(temp_r29 + 0xC);
            remove1:
                if (other != 0) {
                    if (*(char **)(other + 0xC) == temp_r30)
                        *(char **)(other + 0xC) = 0;
                    other = *(char **)(other + 0x10);
                    goto remove1;
                }
                if (*(int *)(temp_r30 + 0x10) == -1)
                    fn_8012C90C(*(int *)temp_r30);
                fn_8012C958(*(int *)temp_r30);
                *(int *)temp_r30 = 0;
                fn_802D915C(*(void **)(temp_r30 + 0xC));
                *(int *)(temp_r30 + 0xC) = 0;

                pool = *(char **)(*(char **)(temp_r29 + 0x38) + 4);
                link = (char **)(pool + 0xC);
                node = (char *)(*(int *)(temp_r30 + 8) - (*(int *)(pool + 4) + 1));
                other = *link;
                if (other != 0) {
                    do {
                        if (other == node) {
                            *link = *(char **)(node + 8);
                            break;
                        }
                        link = (char **)(other + 8);
                        other = *link;
                    } while (other != 0);
                }
                mergeLink = (char **)(pool + 8);
                *(char **)(node + 8) = *mergeLink;
                *mergeLink = node;
                do {
                    scanLink = (char **)(pool + 8);
                    merged = 0;
                merge1:
                    other = *scanLink;
                    if (other != 0) {
                        joined = *mergeLink;
                        pageSize = *(int *)(pool + 4);
                        mergeCandidate = 1;
                        if (((char *)joined + pageSize + *(int *)(joined + 4) + 1 != other) &&
                            ((char *)other + pageSize + *(int *)(other + 4) + 1 != joined))
                            mergeCandidate = 0;
                        if (mergeCandidate != 0) {
                            link = mergeLink;
                            if ((char *)other + pageSize + *(int *)(other + 4) + 1 == joined) {
                                link = scanLink;
                                scanLink = mergeLink;
                            }
                            joined = *link;
                            mergeLink = link;
                            merged = 1;
                            *(int *)(joined + 4) = (((pageSize + 0x10) & ~pageSize) +
                                (*(int *)(joined + 4) + *(int *)(*scanLink + 4)));
                            *scanLink = *(char **)(*scanLink + 8);
                        } else {
                            scanLink = (char **)(other + 8);
                            goto merge1;
                        }
                    }
                } while (merged != 0);
                *(int *)(temp_r30 + 8) = 0;
                fn_802CBB9C((int **)(temp_r29 + 4), (int)temp_r29, (int *)temp_r30);
            } else {
                temp_r30 = *(char **)(temp_r30 + 0x14);
                goto find;
            }
        }
    }
    *(int *)(temp_r31 + 0x40) = 0;
}
int fn_802CBBE8();
extern char lbl_8034BA04[];
void fn_802CBB9C(int **arg0, int arg1, int *arg2) {
    fn_802CBBE8(arg1, arg2);
    *(int **)((char *)arg2 + 0x14) = *arg0;
    *arg0 = arg2;
}

#pragma scheduling invalid_target
int fn_802CBBE8(register int **link, register int *target, register int *current) { register int removed = 0; goto advance; check: if (current == target) { register int *next = *(int **)((char *)target + 0x14); *link = next; *(int **)((char *)target + 0x14) = 0; removed = 1; goto done; } advance: link = (int **)((char *)current + 0x14); current = *link; if (current != 0) goto check; done: if (removed == 0) fn_802E317C(lbl_8034BA04); }

#pragma use_lmw_stmw off
extern void fn_8012C720(void *, int, int, int);
extern char lbl_8034BA28[];
extern char lbl_8055D088;
extern void fn_802CBD30(void **, void **, void *);
#pragma use_lmw_stmw off
void fn_802CBC3C(void *arg0, int arg1) {
    register void **root = (void **)arg0;
    register int limit = arg1;
    register char *child;
    register char *node = (char *)root[3];
    register int zero = 0;
    register int minusOne = -1;
    int refCount;

    goto check;
inspect:
    if (*(int *)(node + 8) > limit)
        goto advance;
    ((void (*)(int, const char *))fn_802CB3F8)(*(int *)node, lbl_8034BA28);
    ((void (*)(int))fn_802CB3F4)(*(int *)(node + 4));
    *(int *)(node + 4) = zero;
    fn_802CBD30(root + 4, root + 3, node);
    child = *(char **)(node + 0xC);
    if (child != 0) {
        refCount = *(int *)(child + 0x10) - 1;
        *(int *)(child + 0x10) = refCount;
        if (refCount == 0) {
            *(int *)(child + 0x10) = minusOne;
            fn_8012C720(*(void **)child, *(int *)(child + 8),
                        *(int *)((char *)lbl_8055FCB0 +
                            *(int *)(child + 4) * 0x4C + 0x3C), 0);
            ((void (*)(void *, const char *))fn_802CB3F8)(
                (void *)((char *)lbl_8055FCB0 + *(int *)(child + 4) * 0x4C + 4),
                &lbl_8055D088);
        }
        *(void **)(node + 0xC) = 0;
    }
    node = (char *)root[3];
    goto check;
advance:
    node = *(char **)(node + 0x10);
check:
    if (node != 0)
        goto inspect;
}
#pragma use_lmw_stmw on

#pragma scheduling on
void fn_802CBD7C();
void fn_802CBD30(void **arg0, void **arg1, void *arg2) {
    fn_802CBD7C(arg1, arg2);
    *(void **)((char *)arg2 + 0x10) = *arg0;
    *arg0 = arg2;
}

void fn_802CBD7C(void **, void *, void *);
extern char lbl_8034BA04[];
void fn_802CBD7C(register void **link, void *target, void *current) {
    int removed = 0;
    while (current != 0) {
        if (current == target) {
            void *next = *(void **)((char *)target + 0x10);
            *link = next;
            *(void **)((char *)target + 0x10) = 0;
            removed = 1;
            break;
        }
        {
            void * volatile *next_link = (void * volatile *)((char *)current + 0x10);
            link = (void **)next_link;
            current = *next_link;
        }
    }
    if (removed == 0)
        fn_802E317C(lbl_8034BA04);
}

void fn_802CBFA0(void *arg0, unsigned int arg1) {
    void *node;
    node = *(void **)((char *)arg0 + 0xC);
    while (node != 0) {
        if (*(unsigned int *)((char *)node + 0xC) == arg1)
            *(unsigned int *)((char *)node + 0xC) = 0;
        node = *(void **)((char *)node + 0x10);
    }
}

extern char lbl_8034BA34[];
extern char lbl_8034BA70[];
int fn_802D9154(void);
void fn_802CC03C(int **arg0, int *arg1, int arg2) {
    int offset = arg2 * 0x4C;
    char sp10[0x20];
    int sp8;

    arg1[0] = fn_8012C5B8((char *)fn_802CA2A8(sp10, 0x20, (int)((char *)lbl_8055FCB0 + offset + 4)), 0x54455820, &sp8);
    arg1[1] = arg2;
    arg1[3] = fn_802D9154();
    if (arg1[0] == 0)
        fn_802E317C(lbl_8034BA34, sp10);
    if ((unsigned int)sp8 != 0xF)
        fn_802E317C(lbl_8034BA70, sp10, sp8, 0xF);
    ((void (*)(int **, int, int *))fn_802CBB9C)(arg0, (int)arg0 + 4, arg1);
}

#pragma optimization_level 2
int fn_802CC10C(void *arg0, int arg1, int arg2, int arg3) {
    char *table;
    char *node;
    char *pool;
    char **link;
    char **mergeLink;
    char *other;
    int result = 0;

    node = *(char **)((char *)arg0 + 0x10);
    if (node != 0) {
        table = (char *)&lbl_8055FCB0 + arg1 * 0x4C;
        *(int *)(node + 4) = *(int *)(table + 0x40);
        *(int *)(node + 8) = arg2;
        *(int *)(node + 0xC) = arg3;
        *(char **)node = table + 4;
        ((void (*)(void **, void **, void *))fn_802CBD30)(
            (void **)((char *)arg0 + 0xC),
            (void **)((char *)arg0 + 0x10), node);
        *(int *)(table + 0x40) = 0;

        pool = *(char **)(*(char **)((char *)arg0 + 0x38) + 4);
        link = (char **)(pool + 0xC);
        node = (char *)(*(int *)(table + 0x44) - (*(int *)(pool + 4) + 1));
        other = *link;
        if (other != 0) {
            do {
                if (other == node) {
                    *link = *(char **)(node + 8);
                    break;
                }
                link = (char **)(other + 8);
                other = *link;
            } while (other != 0);
        }
        mergeLink = (char **)(pool + 8);
        *(char **)(node + 8) = *mergeLink;
        *mergeLink = node;
        *(int *)(table + 0x44) = 0;
        ((void (*)(void *, void *))fn_802CB3F8)(table + 4, &lbl_8034BA98);
        result = 1;
    }
    return result;
}

extern char lbl_8034BB28[];
void *fn_802CC2C8(void *arg0, int arg1) {
    volatile int *manager = (volatile int *)arg0;
    int size = manager[1];
    int mask = ~size;
    int aligned = (arg1 + size) & mask;
    char *node = (char *)0x80000000;
    char **link = (char **)((char *)arg0 + 8);
    int best = (int)node - 1;
    char **choice = 0;
    void *result = 0;
    do {
        int start = *(int *)(node + 4);
        if (start >= aligned && best > start) {
            choice = link;
            best = start;
        }
        link = (char **)(node + 8);
        node = *link;
    } while (node != 0);
    if (choice != 0) {
        char *block = *choice;
        char *next = *(char **)(block + 8);
        char *split = 0;
        int remaining = *(int *)(block + 4) - aligned;
        if (remaining > (((size + 0x10) & mask) + 0x20)) {
            char *p = block + size + aligned;
            *(int *)(p + 1) = 0xABCFEED0;
            split = p + 1;
            *(int *)(p + 9) = 0;
            *(int *)(p + 5) = remaining - ((manager[1] + 0x10) & ~manager[1]);
            *(void **)(p + 0xD) = arg0;
            *(int *)(block + 4) = aligned;
        }
        if (split != 0) {
            *(char **)(split + 8) = next;
            *choice = split;
        } else {
            *choice = next;
        }
        *(char **)(block + 8) = *(char **)((char *)arg0 + 0xC);
        *(char **)((char *)arg0 + 0xC) = block;
        result = block + manager[1] + 1;
    }
    if (result == 0 && *(unsigned char *)arg0 != 0)
        fn_802E317C(lbl_8034BB28);
    return result;
}

int fn_802CC404(void *arg0) {
    return *(int *)(*(char **)((char *)arg0 + 0x38) + 4);
}

extern int fn_8012C7FC(void *, int *);
#pragma dont_inline on
extern char lbl_8055D090;
#pragma scheduling invalid_target
#pragma dont_inline on
#pragma use_lmw_stmw off
void fn_802CC410(void *arg0) {
    register int zero = 0;
    register int *node;
    register int value = -2;
    register int done = 2;
    register char *root = (char *)arg0;
    int temporary;
    int result;

outer:
    node = *(int **)root;
    value = -2;
    do {
        if (node[4] == -1) {
            result = fn_8012C7FC((void *)node[0], &temporary);
            if (result != 0) {
                value = lbl_8055FCB0 + node[1] * 0x4C;
                *(int *)(value + 0x44) = node[2];
                *(int *)(value + 0x40) = fn_802CB38C((void *)result,
                    (void *)node[3],
                    (void *)*(int *)(lbl_8055FCB0 + node[1] * 0x4C + 0x34));
                node[3] = zero;
                fn_8012C958(node[0]);
                node[0] = zero;
                node[2] = zero;
                fn_802CBB9C((int **)(root + 4), (int)root, node);
                ((void (*)(void *, const char *))fn_802CB3F8)(
                    (void *)(value + 4), &lbl_8055D090);
                *(int *)(root + 0x18) += *(int *)(value + 0x3C);
                value = node[1];
            }
        }
        node = *(int **)((char *)node + 0x14);
    } while (node != 0);
    if (value != -2) {
        *(int *)(root + value * 0x14 + 0x40) = done;
        goto outer;
    }
}
#pragma scheduling on
#pragma use_lmw_stmw on
#pragma dont_inline reset
extern double lbl_80564F38;
#pragma fp_contract on
void fn_802CC518(int arg0, float arg1) {
    union {
        double value;
        unsigned int words[2];
    } converted;
    double number;
    double magic;
    float result;

    converted.words[1] = (unsigned int)arg0 ^ 0x80000000;
    converted.words[0] = 0x43300000;
    number = converted.value;
    magic = lbl_80564F38;
    result = (lbl_80564F30 * arg1) / (float)(number - magic);
    lbl_8055FCC4 = result;
}

void fn_802CC550(int arg0, float arg1, float arg2) {
    int offset;
    char *entry;
    float limit;
    float value;
    float result;
    if (arg0 == -1)
        return;
    offset = arg0 * 0x4C;
    entry = (char *)lbl_8055FCB0 + offset;
    if (lbl_8055D07D == 0 || *(int *)(entry + 0x3C) == 0)
        return;
    limit = lbl_80564F40;
    if (limit <= arg1)
        limit = arg1;
    value = *(float *)(entry + 0x38);
    result = arg2 * (lbl_8055FCC4 * limit);
    if (value < result)
        value = result;
    *(float *)(entry + 0x38) = value;
}

void fn_802CC5B8(int arg0) {
    int offset;
    if (arg0 == -1)
        return;
    fn_802CC550(arg0, lbl_80564F40, lbl_80564F44);
    offset = arg0 * 0x4C;
    *(int *)((char *)lbl_8055FCB0 + offset + 0x48) = 1000000;
}

extern int lbl_8055FCC0;
extern float lbl_80564F48;
extern int fn_802E2C20(void);
#pragma scheduling invalid_target
void fn_802CC60C(void) {
    float value = lbl_80564F48;
    int offset = 0;
    int i;
    int zero = 0;
    int counter;
    int next;
    void *root;

    for (i = 0; i < 0x40; i++) {
        *(float *)((char *)lbl_8055FCB0 + offset + 0x38) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x48) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x84) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x94) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0xD0) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0xE0) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x11C) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x12C) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x168) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x178) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x1B4) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x1C4) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x200) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x210) = zero;
        *(float *)((char *)lbl_8055FCB0 + offset + 0x24C) = value;
        *(int *)((char *)lbl_8055FCB0 + offset + 0x25C) = zero;
        offset += 0x260;
    }

    root = *(void **)lbl_8055FCBC;
    counter = lbl_8055FCC0;
    *(int *)((char *)root + 0x2844) = zero;
    next = counter + 1;
    *(int *)((char *)root + 0x283C) = zero;
    *(int *)((char *)root + 0x2840) = zero;
    lbl_8055FCC0 = next;
    if ((unsigned char)counter == 0)
        *(int *)((char *)root + 0x1C) = fn_802E2C20();
}
#pragma scheduling on

void fn_802CC73C(char arg0) {
    lbl_8055D07D = arg0;
}

char fn_802CC744(void) {
    return lbl_8055D07D;
}

#pragma scheduling invalid_target
int fn_802CC74C(void) { int result = 0; char *p = *(char **)lbl_8055FCBC; if (p != 0) { if (*(int *)(p + 4) != 0) result = 1; } return result; }
#pragma scheduling on
extern void fn_802E317C(const char *, ...);
extern char lbl_8034B7D0[];

extern int lbl_8055D03C;
extern char lbl_8034B5F0[];
void fn_802CAC54(int);
void fn_802CB6B4(void);
int fn_80128670(int);
int fn_802CA2A8(void *, int, int);
int fn_8012C5B8(void *, int, int *);
int fn_8012C6F0(void);
int fn_8012C958(int);
extern char lbl_8034B538[];
extern char lbl_8034B904[];
extern char lbl_8034B914[];
extern int fn_802CAE00(int);
extern char lbl_8034B538[];
