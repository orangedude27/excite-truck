// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int *lbl_8055D46C;
extern int lbl_8055D464;
extern int lbl_80558A88;
extern unsigned char lbl_8055D470;
extern char lbl_802FC240[];
extern int fn_801284E8(const char *, int);
extern void fn_802E6BD8(int, int, int, int, void *);
extern void fn_8000DD98(void);
extern void fn_8000D984(int);
extern void fn_8000DA80(void);
extern void fn_8000DC84(int);
extern int lbl_8055D468;
extern unsigned char lbl_8034F650[];
extern void fn_8000DF2C(int);
extern void *memset(void *, int, unsigned int);
extern void fn_80247624(void);
extern void *fn_80131234(const char *);
extern char lbl_802FC24C[];
extern int fn_80128658(int);
extern void fn_80247624(void);
extern void *fn_80131234(const char *);
extern char lbl_802FC24C[];
extern int fn_80128658(int);
static inline void copyName(char *dst, const char *src) {
    int n = 0x12;
    char c;
    do {
        c = *src++;
        *dst++ = c;
        if (c == 0) return;
    } while (--n > 0);
    dst[-1] = 0;
}

void fn_8000D884(int arg0, int arg1, int arg2, int arg3, int arg4) {
    int *entry;
    int count;
    int newCount;
    count = lbl_8055D464;
    entry = (int *)(lbl_8034F650 + count * 0x18);
    *entry = arg0;
    newCount = count + 1;
    entry[1] = arg1;
    entry[2] = arg2;
    entry[3] = arg3;
    entry[4] = arg4;
    lbl_8055D464 = newCount;
    entry[5] = lbl_80558A88;
    lbl_80558A88 += arg3 * 4;
}

#pragma push
#pragma scheduling invalid_target
void fn_8000D8C8(void) {
    /* Initialize the IdentInfo subsystem: allocate its buffer, register it, then
       run setup for each of the four initial IDs. */
    int id;
    int stack = *(volatile int *)&lbl_80558A88;

    *(volatile unsigned char *)&lbl_8055D470 = 1;
    fn_802E6BD8(0x49646E74, 2,
        (*(volatile int *)&lbl_8055D468 = fn_801284E8(lbl_802FC240, stack)),
        lbl_80558A88, fn_8000DC84);
    lbl_8055D46C = (int *)lbl_8055D468;
    fn_8000DD98();
    for (id = 3; id >= 0; id--) {
        fn_8000D984(id);
        fn_8000DA80();
    }
}
#pragma pop
void fn_8000D94C(void) {
    int zero;
    zero = 0;
    lbl_8055D46C = (int *)zero;
    fn_80128658(lbl_8055D468);
    lbl_8055D468 = zero;
}

#pragma push
#pragma optimization_level 2
#pragma scheduling invalid_target
void fn_8000D984(int selectedIndex) {
    int *record;
    int *currentSlotPtr;
    int i;

    fn_8000DF2C(2);
    currentSlotPtr = lbl_8055D46C;
    record = (int *)lbl_8034F650;
    *currentSlotPtr = selectedIndex;
    i = 0;
    goto check;
loop:
    currentSlotPtr = lbl_8055D46C;
    i++;
    *(int *)record[2] = record[3] * *currentSlotPtr + (lbl_8055D468 + record[5]);
    record += 6;
check:
    if (i < lbl_8055D464) goto loop;
    fn_8000DF2C(3);
}
#pragma pop
int fn_8000DA10(void) {
    return *lbl_8055D46C;
}

#pragma push
#pragma optimization_level 2
void fn_8000DA1C(const char *arg0) {
    register int n;
    register char *dst;
    register char *base;
    register unsigned char c;
    base = (char *)lbl_8055D46C;
    *(int *)(base + *lbl_8055D46C * 0x18 + 4) = 2;
    base = (char *)lbl_8055D46C;
    base += (*lbl_8055D46C) * 0x18;
    dst = base + 8;
    n = 0x12;
    while (--n > 0) {}
    dst[-1] = 0;
    do {
        c = *arg0++;
        *dst++ = c;
    } while ((signed char)c != 0);
}
#pragma pop
void fn_8000DA80(void) {
    int *entry;
    int i;

    entry = (int *)((char *)lbl_8055D46C + *lbl_8055D46C * 0x18);
    *(volatile int *)&entry[1] = 0;
    fn_8000DF2C(0);
    entry = (int *)lbl_8034F650;
    i = (int)(entry - (int *)lbl_8034F650);
    goto check;
loop:
    memset(**(void ***)(&entry[2]), 0, entry[3]);
    if (entry[4] != 0)
        ((void (*)(void))entry[4])();
    entry += 6;
    i++;
check:
    if (i < lbl_8055D464) goto loop;
}

void fn_8000DB18(void) {
    int *entry;
    entry = (int *)((char *)lbl_8055D46C + *lbl_8055D46C * 0x18);
    entry[1] = 2;
}

void *fn_8000DB34(int arg0) {
    char *entry;
    fn_80247624();
    entry = (char *)lbl_8055D46C + arg0 * 0x18;
    if (*(int *)(entry + 4) == 0)
        return fn_80131234(lbl_802FC24C);
    return entry + 8;
}

int fn_8000DB8C(int arg0) {
    return *(int *)((char *)lbl_8055D46C + arg0 * 0x18 + 4) == 2;
}

int fn_8000DBAC(int arg0) {
    return *(int *)((char *)lbl_8055D46C + arg0 * 0x18 + 4) == 0;
}

extern int lbl_8055D460;
extern unsigned int lbl_8034F628[];
extern char lbl_802FC264[];
extern void fn_802E30C8();
#pragma push
#pragma scheduling invalid_target
void fn_8000DBC8(int arg0) {
    int count;
    unsigned int *entry;

    count = lbl_8055D460;
    entry = lbl_8034F628;
    for (; count > 0; count--) {
        if (*entry == (unsigned int)arg0) {
            ((void (*)(const char *, ...))fn_802E30C8)(lbl_802FC264, arg0);
            return;
        }
        entry++;
    }
    lbl_8034F628[lbl_8055D460++] = arg0;
}
#pragma optimization_level 2
void fn_8000DC28(const char *source, int arg1) {
    int remaining = 0x12;
    char *p;
    volatile char *destination;
    p = (char *)lbl_8055D46C;
    p += arg1 * 0x12;
    destination = (volatile char *)(p + 0x64);
    while ((*destination++ = *source++) != '\0') {
        if (--remaining > 0)
            continue;
        destination[-1] = '\0';
        return;
    }
}
int fn_8000DC70(int arg0) {
    return (int)((char *)lbl_8055D46C + arg0 * 0x12 + 0x64);
}

#pragma push
#pragma optimization_level 2
#pragma dont_inline on
void fn_8000DC84(int arg0) {
    volatile int *p;
    switch (arg0) {
    case 1:
        fn_8000D984(*lbl_8055D46C);
        break;
    case 2:
        fn_8000DD98();
        break;
    case 3:
        fn_8000DF2C(1);
    case 4:
        p = (volatile int *)lbl_8055D46C;
        if (p[1] != 0) p[1] = 1;
        p = (volatile int *)lbl_8055D46C;
        if (p[7] != 0) p[7] = 1;
        p = (volatile int *)lbl_8055D46C;
        if (p[13] != 0) p[13] = 1;
        p = (volatile int *)lbl_8055D46C;
        if (p[19] != 0) p[19] = 1;
        break;
    case 5:
        p = (volatile int *)lbl_8055D46C;
        if (p[1] != 0) p[1] = 2;
        p = (volatile int *)lbl_8055D46C;
        if (p[7] != 0) p[7] = 2;
        p = (volatile int *)lbl_8055D46C;
        if (p[13] != 0) p[13] = 2;
        p = (volatile int *)lbl_8055D46C;
        if (p[19] != 0) p[19] = 2;
        break;
    }
}
#pragma pop
extern char lbl_80558A8C;
extern char lbl_802FC298[];
extern void fn_801345D8(char *, int, const char *, ...);
#pragma use_lmw_stmw off
#pragma optimization_level 2
#pragma scheduling invalid_target
void fn_8000DD98(void) {
    register int zero = 0;
    register int minusOne;
    register const char *format;
    register int index;
    register int stringOffset;
    register int fieldOffset;
    register int outer;
    register int offset;
    int remaining;
    char *src;
    char *dst;
    char c;

    *lbl_8055D46C = zero;
    offset = 0;
    outer = 2;
    do {
        *((int *)((char *)lbl_8055D46C + offset + 4)) = zero;
        src = (char *)&lbl_80558A8C;
        dst = (char *)lbl_8055D46C + offset + 8;
        remaining = 0x12;
        goto copy0;
limit0:
        remaining--;
        if (remaining > 0)
            goto copy0;
        dst[-1] = zero;
        goto done0;
copy0:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto limit0;
done0:
        offset += 0x18;
        *((int *)((char *)lbl_8055D46C + offset + 4)) = zero;
        src = (char *)&lbl_80558A8C;
        dst = (char *)lbl_8055D46C + offset + 8;
        remaining = 0x12;
        goto copy1;
limit1:
        remaining--;
        if (remaining > 0)
            goto copy1;
        dst[-1] = zero;
        goto done1;
copy1:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto limit1;
done1:
        offset += 0x18;
    } while (--outer != 0);

    zero = 0;
    minusOne = -1;
    format = lbl_802FC298;
    index = 0;
    stringOffset = 0;
    fieldOffset = 0;
    do {
        dst = (char *)lbl_8055D46C + stringOffset + 0x64;
        fn_801345D8(dst, 0x12, format, index + 1);
        src = fn_80131234(dst);
        remaining = 0x12;
        goto copy2;
limit2:
        remaining--;
        if (remaining > 0)
            goto copy2;
        dst[-1] = (char)zero;
        goto done2;
copy2:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0)
            goto limit2;
done2:
        *((int *)((char *)lbl_8055D46C + fieldOffset + 0xAC)) = minusOne;
        index++;
        stringOffset += 0x12;
        fieldOffset += 4;
    } while (index < 4);
}

void fn_8000DF2C(int arg0) {
    unsigned int *entry;
    int i;
    i = 0;
    entry = lbl_8034F628;
    while (i < lbl_8055D460) {
        ((void (*)(int, int))*entry)(*lbl_8055D46C, arg0);
        entry++;
        i++;
    }
}

#pragma scheduling on
#pragma optimization_level 4
#pragma use_lmw_stmw on
extern int lbl_8055D460;
extern unsigned int lbl_8034F628[];
extern char lbl_802FC264[];
extern void fn_802E30C8();
