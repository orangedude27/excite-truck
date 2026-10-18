#include "MSL/ctype.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
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

void* fn_80016508(void) {
    return lbl_8055D54C;
}

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

void *fn_8001668C(const char *arg0, int arg1) {
    int i, count = 0, offset = 0;
    for (i = 0; i < (int)lbl_8055D550; i++, offset += 0xA8) {
        if (stricmp((const char *)(lbl_8055D544 + offset + 0x2C), arg0) == 0) {
            if (count == arg1) return lbl_8055D544 + i * 0xA8;
            count++;
        }
    }
    return lbl_8055D544;
}

void *fn_80016720(const char *arg0) {
    void *result = fn_8001668C(arg0, 0);
    if (*(int *)((char *)result + 0xA0) & 2) {
        result = (void *)fn_80016544(*(int *)((char *)result + 8));
    }
    return (char *)result + 0x2C;
}

void *fn_800167B8(int arg0) { return lbl_803577F0 + arg0 * 0x5C; }

void fn_800167CC(void) {
    fn_80016510(*(int *)((char *)fn_80016474() + 0x4C));
}

extern void *lbl_8055D554;
extern unsigned char lbl_803577F0[];
extern unsigned char lbl_80357960[];
extern void *fn_80016474(void);
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
extern void *fn_80016474(void);
void fn_8001683C(void *arg0, int arg1) {
    void *temp = fn_80016474();
    *(void **)(lbl_803577F0 + arg1 * 0x5C + 4) = arg0;
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x4C) = *(int *)((char *)temp + 0x4C);
    *(int *)(lbl_803577F0 + arg1 * 0x5C + 0x50) = *(int *)((char *)temp + 0x50);
    *(int *)(lbl_80357960 + arg1 * 0xA8 + 4) = -1000;
}

extern unsigned char *lbl_8055D540;
extern unsigned char *lbl_8055D544;
void fn_800168B0(int arg0, int arg1) {
    int i;
    unsigned char *p;
    for (i = 0, p = lbl_803577F0; i < (int)lbl_8055D554; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) *(int *)(p + 0x50) = arg1;
    }
    for (i = 0, p = lbl_8055D540; i < (int)lbl_8055D54C; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) {
            *(int *)(lbl_8055D540 + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}

void fn_80016928(int arg0, int arg1) {
    int i;
    unsigned char *p;
    for (i = 0, p = lbl_8055D540; i < (int)lbl_8055D54C; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4)) {
            *(int *)(lbl_8055D540 + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}

void fn_80016970(int arg0, int arg1, int arg2, int arg3) {
    int offset = arg0 * 0x5C;
    unsigned char *entry = lbl_803577F0 + offset;
    *(int *)(entry + 4) = arg1;
    *(int *)(entry + 0x4C) = *(int *)fn_80016544(arg2);
    *(int *)(entry + 0x50) = arg3;
    *(int *)(lbl_80357960 + arg0 * 0xA8 + 4) = -1000;
}

void fn_800169F8(const char *src, int index) {
    char *dst = (char *)(lbl_803577F0 + index * 0x5C + 8);
    int count = 0x40;
    do {
        *dst++ = *src++;
        if (dst[-1] == 0) return;
        count--;
    } while (count > 0);
    dst[-1] = 0;
}

void fn_80016A44(void) {
    fn_8001766C();
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
        } while (--count != 0);
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
    unsigned int hex, red, green, blue;
    int c;
    int first = *(const unsigned char *)arg0;
    int result = 0xFF008040;
    if (first == '0') {
        c = arg0[1];
        c = (c < 0 || c >= 256) ? c : lbl_802FE850.cmap->to_lower_table[c];
        if (c == 'x') {
            if (sscanf(arg0 + 2, lbl_80558BE8, &hex) == 1) result = hex;
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
#pragma pop
void fn_80017708(void *arg0, int arg1, void *arg2) {
    int temp_r0;
    int temp_r0_2;
    int temp_r4;
    int temp_r4_2;
    memset(arg2, 0, 0xC);
    temp_r4 = *(int *)((char *)arg0 + 0x94);
    *(signed char *)((char *)arg2 + 8) = 0;
    if (temp_r4 >= 0) {
        temp_r0 = (temp_r4 + arg1) % *(int *)((char *)arg0 + 0x98);
        *(int *)arg2 = temp_r0;
        *(int *)((char *)arg2 + 4) = temp_r0;
        return;
    }
    temp_r4_2 = *(int *)((char *)arg0 + 0x98);
    temp_r0_2 = (*(int *)((char *)arg0 + 4) + ((arg1 * temp_r4_2) / 4)) % temp_r4_2;
    *(int *)arg2 = temp_r0_2;
    *(int *)((char *)arg2 + 4) = temp_r0_2;
}

void fn_800177B8(void) {
    int var_r28;
    int var_r30;
    int var_r31;
    void *temp_r29;
    memset(lbl_8055D548, 0, 0x960);
    var_r30 = 0;
    var_r31 = 0;
loop_5:
    if (var_r30 < (int)lbl_8055D550) {
        temp_r29 = lbl_8055D544 + var_r31;
        if (!(*(int *)((char *)temp_r29 + 0xA0) & 2)) {
            var_r28 = 0;
            do {
                fn_80017708(temp_r29, var_r28, fn_80016BC8(temp_r29, var_r28));
                var_r28 += 1;
            } while (var_r28 < 4);
        }
        var_r31 += 0xA8;
        var_r30 += 1;
        goto loop_5;
    }
}

