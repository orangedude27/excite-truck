#include "MSL/ctype.h"
extern void fn_8001766C();
extern void *lbl_8055D550;
extern void *lbl_8055D554;
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474();
extern unsigned char *lbl_8055D540;
extern unsigned char *lbl_8055D544;
extern int stricmp(const char *, const char *);
extern int fn_80016510(int);
extern void *lbl_8055D548;
extern void *fn_80016BC8(void *, int);

extern void *lbl_8055D54C;
extern void fn_80128670(void *);
extern void fn_80131818(void);
void fn_800163F0(void) {
    extern void *lbl_8055D538;
    extern void *lbl_8055D53C;
    extern unsigned char *lbl_8055D540;
    extern unsigned char *lbl_8055D544;
    extern void *lbl_8055D54C;
    extern void *lbl_8055D550;
    void *value;
    lbl_8055D550 = 0;
    fn_80128670(lbl_8055D544);
    lbl_8055D544 = 0;
    lbl_8055D54C = 0;
    fn_80128670(lbl_8055D540);
    value = lbl_8055D538;
    lbl_8055D540 = 0;
    if (value) {
        fn_80131818();
        lbl_8055D538 = 0;
    }
    value = lbl_8055D53C;
    if (value) {
        fn_80131818();
        lbl_8055D53C = 0;
    }
}

void *fn_80016464(int arg0) {
    return lbl_8055D540 + arg0 * 0x5C;
}

#pragma scheduling invalid_target
void *fn_80016474(void) {
    register int j;
    register int i;
    unsigned char *base;
    register unsigned char *entry1;
    register unsigned char *entry2;
    int key = 0;

    for (i = 0, entry1 = lbl_803577F0; i < (int)lbl_8055D554; entry1 += 0x5C, i++) {
        if (key == *(int *)(entry1 + 4)) {
            return lbl_803577F0 + i * 0x5C;
        }
    }
    j = 0;
    base = lbl_8055D540;
    entry2 = base;
    for (; j < (int)lbl_8055D54C; entry2 += 0x5C, j++) {
        if (key == *(int *)(entry2 + 4)) {
            return base + j * 0x5C;
        }
    }
    return lbl_803577F0;
}
#pragma scheduling on

void* fn_80016508(void) {
    return lbl_8055D54C;
}

#pragma dont_inline on
#pragma scheduling invalid_target
int fn_80016510(int arg0) { extern void *lbl_8055D550; if (arg0 < (int)lbl_8055D550) return (int)(lbl_8055D544 + arg0 * 0xA8); return (int)(lbl_80357960 + (arg0 - (int)lbl_8055D550) * 0xA8); }

#pragma scheduling invalid_target
void *fn_80016544(int arg0) {
    register unsigned char *entry1;
    register unsigned char *entry2;
    unsigned char *base;
    int i;
    register int j;
    for (i = 0, entry1 = lbl_80357960; i < (int)lbl_8055D554; entry1 += 0xA8, i++) {
        if (arg0 == *(int *)(entry1 + 4)) {
            return lbl_80357960 + i * 0xA8;
        }
    }
    j = 0;
    base = lbl_8055D544;
    entry2 = base;
    for (; j < (int)lbl_8055D550; entry2 += 0xA8, j++) {
        if (arg0 == *(int *)(entry2 + 4)) {
            return base + j * 0xA8;
        }
    }
    return base;
}
#pragma scheduling on

#pragma scheduling on
#pragma dont_inline reset

extern void *lbl_8055D550;
void* fn_800165D4(void) {
    return lbl_8055D550;
}

void fn_800165DC(void) {
    fn_80016510(*(int *)((char *)fn_80016474() + 0x4C));
}

int fn_80016604(const char *arg0) {
    int offset = 0, count = 0, i = 0;
    while (i < (int)lbl_8055D550) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), arg0) == 0)
            count++;
        offset += 0xA8;
        i++;
    }
    return count;
}

#pragma push
#pragma use_lmw_stmw off
void *fn_8001668C(const char *arg0, int arg1) {
    int offset;
    int count;
    int index;
    count = 0;
    index = 0;
    offset = 0;
    while (index < (int)lbl_8055D550) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), arg0) == 0) {
            if (count == arg1)
                return lbl_8055D544 + index * 0xA8;
            count++;
        }
        offset += 0xA8;
        index++;
    }
    return lbl_8055D544;
}
#pragma dont_inline on
void *fn_80016720(const char *arg0) {
    void *result = fn_8001668C(arg0, 0);
    if (*(int *)((char *)result + 0xA0) & 2) {
        result = (void *)fn_80016544(*(int *)((char *)result + 8));
    }
    return (char *)result + 0x2C;
}

#pragma scheduling invalid_target
void *fn_8001675C(unsigned int arg0, int arg1) { int i; int found = 0; unsigned char *entry; for (i = 0, entry = lbl_8055D544; i < (int)lbl_8055D550; i++, entry += 0xA8) { if (arg0 == (arg0 & *(unsigned int *)(entry + 0xA0))) { if (found == arg1) return lbl_8055D544 + i * 0xA8; found++; } } return lbl_8055D544; }
#pragma scheduling on
void *fn_800167B8(int arg0) { return lbl_803577F0 + arg0 * 0x5C; }

void *fn_800167CC(int arg0) {
    return (void *)fn_80016510(*(int *)((char *)fn_800167B8(arg0) + 0x4C));
}

extern void *lbl_8055D554;
extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474();
void* fn_800167F4(void) {
    return lbl_8055D554;
}

void fn_800167FC(void *arg0) {
    lbl_8055D554 = arg0;
}

int fn_80016804(int arg0, int arg1) {
    if (arg1 < (int)lbl_8055D554 &&
        arg0 == *(int *)(lbl_803577F0 + arg1 * 0x5C + 4)) {
        return 1;
    }
    return 0;
}

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474();
void fn_8001683C(void *arg0, int arg1) {
    void *temp = fn_80016474((int)arg0);
    *(void **)(lbl_803577F0 + arg1 * 0x5C + 4) = arg0;
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x4C) = *(int *)((char *)temp + 0x4C);
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x50) = *(int *)((char *)temp + 0x50);
    *(int *)(lbl_80357960 + arg1 * 0xA8 + 4) = -1000;
}
#pragma pop
extern unsigned char *lbl_8055D540;
extern unsigned char *lbl_8055D544;
void fn_800168B0(int arg0, int arg1) {
    int i;
    unsigned char *p;
    int base;
    for (i = 0, p = lbl_803577F0; i < (int)lbl_8055D554; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) *(int *)(p + 0x50) = arg1;
    }
    base = (int)lbl_8055D540;
    for (i = 0, p = (unsigned char *)base; i < (int)lbl_8055D54C; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) {
            *(int *)(base + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80016928(int arg0, int arg1) {
    register unsigned char *entry;
    register unsigned char *base;
    register int i;

    i = 0;
    base = lbl_8055D540;
    entry = base;
    for (; i < (int)lbl_8055D54C; i++, entry += 0x5C) {
        if (arg0 == *(int *)(entry + 4)) {
            *(int *)(base + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}
#pragma push
#pragma scheduling invalid_target
void fn_80016970(int arg0, int arg1, int arg2, int arg3) {
    *(int *)(lbl_803577F0 + arg0 * 0x5C + 4) = arg1;
    *(int *)(lbl_803577F0 + arg0 * 0x5C + 0x4C) = *(int *)fn_80016544(arg2);
    *(int *)(lbl_803577F0 + arg0 * 0x5C + 0x50) = arg3;
    *(int *)(lbl_80357960 + arg0 * 0xA8 + 4) = -1000;
}
#pragma pop
void fn_800169F8(const char *src, int index) { int count = 0x40; char *dst = (char *)(lbl_803577F0 + index * 0x5C + 8); while ((*dst++ = *src++) != 0) { if (--count <= 0) { dst[-1] = 0; return; } } }

void fn_80016A44(void) {
    fn_8001766C();
}

#pragma dont_inline fn_800167B8
void fn_80016A48(void *arg0, int arg1) {
    extern unsigned char lbl_80357C20[];
    extern void *fn_8027953C(void *);
    int index;
    int found;

    found = -1;
    index = 0;
    do {
        int value;
        value = *(int *)((unsigned char *)fn_80016510(*(int *)((unsigned char *)fn_800167B8(index) + 0x4C)) + 4);
        if (arg1 == value)
            found = index;
        index++;
    } while (index < *(int *)&lbl_8055D554 && found == -1);
    if (found != -1 && lbl_80357C20[found * 0x68] != 0) {
        unsigned char *record = lbl_80357C20 + found * 0x68;
        *(unsigned char *)arg0 = record[4];
        *(float *)((unsigned char *)arg0 + 4) = *(float *)(record + 8);
        *(float *)((unsigned char *)arg0 + 8) = *(float *)(record + 0xC);
        *(float *)((unsigned char *)arg0 + 0xC) = *(float *)(record + 0x10);
        *(float *)((unsigned char *)arg0 + 0x10) = *(float *)(record + 0x14);
        *(float *)((unsigned char *)arg0 + 0x14) = *(float *)(record + 0x18);
        *(float *)((unsigned char *)arg0 + 0x18) = *(float *)(record + 0x1C);
        *(float *)((unsigned char *)arg0 + 0x1C) = *(float *)(record + 0x20);
        *(float *)((unsigned char *)arg0 + 0x20) = *(float *)(record + 0x24);
        *(float *)((unsigned char *)arg0 + 0x24) = *(float *)(record + 0x28);
        *(float *)((unsigned char *)arg0 + 0x28) = *(float *)(record + 0x2C);
        *(float *)((unsigned char *)arg0 + 0x2C) = *(float *)(record + 0x30);
        *(float *)((unsigned char *)arg0 + 0x30) = *(float *)(record + 0x34);
        *(float *)((unsigned char *)arg0 + 0x34) = *(float *)(record + 0x38);
        *(float *)((unsigned char *)arg0 + 0x38) = *(float *)(record + 0x3C);
        *(float *)((unsigned char *)arg0 + 0x3C) = *(float *)(record + 0x40);
        *(float *)((unsigned char *)arg0 + 0x40) = *(float *)(record + 0x44);
        *(float *)((unsigned char *)arg0 + 0x44) = *(float *)(record + 0x48);
        *(float *)((unsigned char *)arg0 + 0x48) = *(float *)(record + 0x4C);
        *(float *)((unsigned char *)arg0 + 0x4C) = *(float *)(record + 0x50);
        *(float *)((unsigned char *)arg0 + 0x50) = *(float *)(record + 0x54);
        *(float *)((unsigned char *)arg0 + 0x54) = *(float *)(record + 0x58);
        *(float *)((unsigned char *)arg0 + 0x58) = *(float *)(record + 0x5C);
        *(float *)((unsigned char *)arg0 + 0x5C) = *(float *)(record + 0x60);
        *(float *)((unsigned char *)arg0 + 0x60) = *(float *)(record + 0x64);
        return;
    }
    fn_8027953C(arg0);
}

void *fn_80016BC8(void *arg0, int arg1) {
    int *var_r3;

    var_r3 = (int *)arg0;
    if (*(int *)((char *)var_r3 + 0xA0) & 2) {
        var_r3 = (int *)fn_80016544(*(int *)((char *)var_r3 + 8));
    }
    return (void *)((char *)lbl_8055D548 + ((*var_r3 + (arg1 * 0x32)) * 0xC));
}

extern void *lbl_8055D538;
extern void *lbl_8055D53C;
extern char lbl_802FCEEC[];
extern void fn_8013C804(void);
extern void fn_8013C8B8(void);
extern void fn_80017558(void);
extern void fn_80016D14(void **);
extern void fn_802E317C(const char *, ...);
#pragma push
#pragma processor 750
void fn_80016C1C(void) {
    int offset;
    unsigned char *p;
    int i;
    unsigned char *entry;
    int found, j;
    int count;
    fn_8013C804();
    lbl_8055D54C = 0;
    lbl_8055D550 = 0;
    if (lbl_8055D538 != 0) fn_80016D14(lbl_8055D538);
    if (lbl_8055D53C != 0) fn_80016D14(lbl_8055D53C);
    if (lbl_8055D550 == 0) fn_802E317C(lbl_802FCEEC);
    for (i = 0, offset = 0; i < (int)lbl_8055D54C; offset += 0x5C, i++) {
        count = *(volatile int *)&lbl_8055D550;
        found = 0;
        j = 0;
        p = lbl_8055D544;
        entry = *(unsigned char * volatile *)&lbl_8055D540 + offset;
        if (count > 0) do {
            if (*(int *)(p + 4) == *(int *)(entry + 0x4C)) {
                *(int *)(entry + 0x4C) = j;
                found = 1;
                break;
            }
            p += 0xA8;
            j++;
        } while (j < count);
        if (!found) *(int *)(entry + 0x4C) = i % (int)lbl_8055D550;
    }
    fn_80017558();
    fn_8013C8B8();
}
#pragma pop
__declspec(section ".sdata") extern char lbl_80558BD4[];
__declspec(section ".sdata") extern char lbl_80558BE0[];
extern void fn_80016ED4(void *);
extern void fn_80017010(void *);
void fn_80016D14(void **arg0) {
    void **child;
    int i;
    i = 0;
    for (; (child = (*(void **(**)())((char *)*arg0 + 0xC))(arg0, i)) != 0; i++) {
        if (stricmp((*(const char *(**)())((char *)*child + 8))(child), lbl_80558BD4) == 0) {
            fn_80016ED4(child);
        } else if (stricmp((*(const char *(**)())((char *)*child + 8))(child), lbl_80558BE0) == 0) {
            fn_80017010(child);
        }
    }
}

extern __Locale lbl_802FE850;
extern char lbl_802FCF04[];
__declspec(section ".sdata") extern char lbl_80558BE8[];
extern int sscanf(const char *, const char *, ...);
#pragma push
#pragma processor gekko
int fn_80016DD8(const char *arg0) {
    unsigned int hex, blue, green, red;
    int c;
    int first = *(const unsigned char *)arg0;
    int result = 0xFF008040;
    if (first == '0') {
        c = arg0[1];
        c = (c < 0 || c >= 256) ? c : lbl_802FE850.cmap->to_lower_table[c];
        if (c == 'x') {
            const char *p = arg0 + 2;
            if (sscanf(p, lbl_80558BE8, &hex) == 1) result = hex;
            goto done;
        }
    }
    if ((signed char)first >= '0' && (signed char)first <= '9' &&
        sscanf(arg0, lbl_802FCF04, &red, &green, &blue) == 3) {
        result = ((red & 255) << 16) | ((green & 255) << 8) | (blue & 255) | 0xFF000000;
    }
done:
    return result;
}

extern char lbl_80558BEC, lbl_80558BF4, lbl_80558BFC;
extern char lbl_802FCF10[];
extern void fn_801345D8(char *, int, const char *, int);
#pragma cplusplus on
extern "C" void fn_80016ED4(void *arg0) {
    struct Interface {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual void m3();
        virtual char *m4(const char *, int);
        virtual void m5();
        virtual int m6(const char *, int);
    };
    struct Entry {
        int id;
        int value;
        char name[0x40];
        int unk48;
        int unk4C;
        int unk50;
        int unk54;
        void *obj;
    };
    Entry *entry;
    int value;
    char *name;
    int n;
    char *dst;

    entry = (Entry *)(lbl_8055D540 + (int)lbl_8055D54C * 0x5C);
    entry->obj = arg0;
    entry->id = (int)lbl_8055D54C;
    value = ((Interface *)arg0)->m6(&lbl_80558BEC, (int)lbl_8055D54C);
    name = ((Interface *)arg0)->m4(&lbl_80558BF4, 0);
    if (name != 0) {
        n = 0x40;
        dst = entry->name;
        while (*dst++ = *name++) {
            if (--n <= 0) {
                dst[-1] = 0;
                break;
            }
        }
    } else {
        ((void (*)(char *, int, const char *, ...))fn_801345D8)(entry->name, 0x40, lbl_802FCF10, entry->id);
    }
    entry->value = value;
    entry->unk54 = -1;
    entry->unk48 = ((Interface *)arg0)->m6(&lbl_80558BFC, value);
    entry->unk4C = -1;
    entry->unk50 = 0xFF008040;
    lbl_8055D54C = (void *)((int)lbl_8055D54C + 1);
}
#pragma cplusplus reset
extern char lbl_802FD00C[];
extern char lbl_802FD040[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
void fn_80017558(void) {
    {
        register int innerOffset;
        register int outerOffset;
        register int i;
        register int j;

        for (i = 0, outerOffset = 0; i < (int)lbl_8055D54C; outerOffset += 0x5C, i++) {
            for (j = i + 1, innerOffset = j * 0x5C; j < (int)lbl_8055D54C; innerOffset += 0x5C, j++) {
                if (*(int *)(lbl_8055D540 + innerOffset + 4) == *(int *)((u32)outerOffset + (u32)lbl_8055D540 + 4)) {
                    fn_802E317C(lbl_802FD00C, (void *)((u32)outerOffset + (u32)lbl_8055D540 + 8), lbl_8055D540 + innerOffset + 8);
                }
            }
        }
    }

    {
        register int j;
        register int i;
        register int innerOffset;
        register int outerOffset;

        for (i = 0, outerOffset = 0; i < (int)lbl_8055D550; outerOffset += 0xA8, i++) {
            for (j = i + 1, innerOffset = j * 0xA8; j < (int)lbl_8055D550; innerOffset += 0xA8, j++) {
                if (*(int *)((u32)outerOffset + (u32)lbl_8055D544 + 4) == *(int *)(lbl_8055D544 + innerOffset + 4)) {
                    fn_802E317C(lbl_802FD040, (void *)((u32)outerOffset + (u32)lbl_8055D544 + 0x2C), lbl_8055D544 + innerOffset + 0x2C);
                }
            }
        }
    }
}
#pragma pop
extern unsigned char lbl_802FD07C[];
extern void *memset(void *, int, unsigned int);
#pragma scheduling invalid_target
void fn_8001766C(int arg0) {
    unsigned char *base = lbl_803577F0;
    int recordOffset = arg0 * 0x5C;
    unsigned char *entryBase = base;
    unsigned char *entry = entryBase + recordOffset;
    int index = arg0;
    int offset68 = index * 0x68;
    int offset8 = index * 8;

    memset(entry, 0, 0x5C);
    *(int *)(entry + 4) = -1000;
    ((void (*)(char *, int, const char *, ...))fn_801345D8)(
        (char *)(entry + 8), 0x40, (const char *)lbl_802FD07C, index + 1);
    *(int *)(entry + 0x48) = 1000;
    *(unsigned char *)(lbl_803577F0 + 0x410 + offset8) = 0;
    *(unsigned char *)(lbl_803577F0 + 0x430 + offset68) = 0;
}
#pragma scheduling on
void fn_80017708(void *arg0, int arg1, void *arg2) {
    int temp_r0;
    int temp_r0_2;
    int temp_r4;
    int temp_r4_2;
    memset(arg2, 0, 0xC);
    temp_r4 = *(int *)((char *)arg0 + 0x94);
    *(signed char *)((char *)arg2 + 8) = 0;
    if (temp_r4 < 0) {
        temp_r4_2 = *(int *)((char *)arg0 + 0x98);
        temp_r0_2 = (*(int *)((char *)arg0 + 4) + ((arg1 * temp_r4_2) / 4)) % temp_r4_2;
        *(int *)arg2 = temp_r0_2;
        *(int *)((char *)arg2 + 4) = temp_r0_2;
        return;
    }
    temp_r0 = (temp_r4 + arg1) % *(int *)((char *)arg0 + 0x98);
    *(int *)arg2 = temp_r0;
    *(int *)((char *)arg2 + 4) = temp_r0;
}
#pragma dont_inline on
void fn_800177B8(void) {
    int var_r31;
    int var_r30;
    void *temp_r29;
    int var_r28;

    memset(lbl_8055D548, 0, 0x960);
    var_r30 = 0;
    var_r31 = 0;
    goto loop_test;
loop_body:
    temp_r29 = lbl_8055D544 + var_r31;
    if ((*(int *)((char *)temp_r29 + 0xA0) & 2) == 0) {
        var_r28 = 0;
        do {
            fn_80017708(temp_r29, var_r28, fn_80016BC8(temp_r29, var_r28));
            var_r28++;
        } while (var_r28 < 4);
    }
    var_r31 += 0xA8;
    var_r30++;
loop_test:
    if (var_r30 < (int)lbl_8055D550) {
        goto loop_body;
    }
}
#pragma dont_inline reset
