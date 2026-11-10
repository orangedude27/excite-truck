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
extern char lbl_802FCEA8[];
extern void *lbl_8055D538;
extern int fn_80131808(void *);
extern int fn_8012850C(int, void *);
extern void fn_80016C1C(void);
extern void fn_8000D884(int, int, void *, int, void *);
extern void fn_800177B8(void);
extern void *fn_80016BC8(void *, int);

extern void *lbl_8055D54C;
extern void fn_80128670(void *);
extern void fn_80131818(void);
void fn_80016354(void) {
    int i = 0;
    lbl_8055D538 = (void *)fn_80131808((char *)lbl_802FCEA8 + 0xC);
    lbl_8055D540 = (void *)fn_8012850C(0x11F8, (char *)lbl_802FCEA8 + 0x18);
    lbl_8055D544 = (void *)fn_8012850C(0x20D0, (char *)lbl_802FCEA8 + 0x28);
    fn_80016C1C();
    lbl_8055D554 = 0;
    for (i = 0; i < 4; i++) {
        fn_8001766C(i);
    }
    fn_8000D884(0x44727672, 1, &lbl_8055D548, 0x960, fn_800177B8);
}

void fn_800163F0(void) {
    extern void *lbl_8055D538;
    extern void *lbl_8055D53C;
    lbl_8055D550 = 0;
    fn_80128670(lbl_8055D544);
    lbl_8055D544 = 0;
    lbl_8055D54C = 0;
    fn_80128670(lbl_8055D540);
    lbl_8055D540 = 0;
    if (lbl_8055D538) {
        ((void (*)(void *))fn_80131818)(lbl_8055D538);
        lbl_8055D538 = 0;
    }
    if (lbl_8055D53C) {
        ((void (*)(void *))fn_80131818)(lbl_8055D53C);
        lbl_8055D53C = 0;
    }
}

void *fn_80016464(int arg0) {
    return lbl_8055D540 + arg0 * 0x5C;
}

#pragma scheduling invalid_target
void *fn_80016474(int arg0) {
    unsigned char *entry;
    int i;
    for (i = 0, entry = lbl_803577F0; i < (int)lbl_8055D554; entry += 0x5C, i++) {
        if (arg0 == *(int *)(entry + 4)) {
            return lbl_803577F0 + i * 0x5C;
        }
    }
    {
        unsigned char *e2;
        unsigned char *b2;
        int k = 0;
        e2 = b2 = lbl_8055D540;
        for (k = 0; k < (int)lbl_8055D54C; e2 += 0x5C, k++) {
            if (arg0 == *(int *)(e2 + 4)) {
                return b2 + k * 0x5C;
            }
        }
        return lbl_803577F0;
    }
}

void* fn_80016508(void) {
    return lbl_8055D54C;
}

#pragma dont_inline on
#pragma scheduling invalid_target
int fn_80016510(int arg0) { extern void *lbl_8055D550; if (arg0 < (int)lbl_8055D550) return (int)(lbl_8055D544 + arg0 * 0xA8); return (int)(lbl_80357960 + (arg0 - (int)lbl_8055D550) * 0xA8); }

#pragma scheduling invalid_target
void *fn_80016544(int arg0) {
    unsigned char *entry;
    unsigned char *base;
    int i;
    int j;
    for (i = 0, entry = lbl_80357960; i < (int)lbl_8055D554; entry += 0xA8, i++) {
        if (arg0 == *(int *)(entry + 4)) {
            return lbl_80357960 + i * 0xA8;
        }
    }
    {
        unsigned char *e2;
        unsigned char *b2;
        int k = 0;
        e2 = b2 = lbl_8055D544;
        for (k = 0; k < (int)lbl_8055D550; e2 += 0xA8, k++) {
            if (arg0 == *(int *)(e2 + 4)) {
                return b2 + k * 0xA8;
            }
        }
        return b2;
    }
}
#pragma scheduling on

#pragma scheduling on
#pragma dont_inline reset

extern void *lbl_8055D550;
void* fn_800165D4(void) {
    return lbl_8055D550;
}

void fn_800165DC(void) {
    fn_80016510(*(int *)((char *)((void *(*)())fn_80016474)() + 0x4C));
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
void *fn_8001675C(unsigned int arg0, int arg1) {
    unsigned char *entry;
    unsigned char *base;
    int found = 0;
    int i = 0;
    entry = base = lbl_8055D544;
    for (i = 0; i < (int)lbl_8055D550; entry += 0xA8, i++) {
        if (arg0 == (arg0 & *(unsigned int *)(entry + 0xA0))) {
            if (found == arg1)
                return base + i * 0xA8;
            found++;
        }
    }
    return base;
}
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
    for (i = 0, p = lbl_803577F0; i < (int)lbl_8055D554; i++, p += 0x5C) {
        if (arg0 == *(int *)(p + 4))
            *(int *)(p + 0x50) = arg1;
    }
    {
        unsigned char *entry;
        unsigned char *base;
        int j = 0;
        entry = base = lbl_8055D540;
        for (j = 0; j < (int)lbl_8055D54C; entry += 0x5C, j++) {
            if (arg0 == *(int *)(entry + 4)) {
                *(int *)(base + j * 0x5C + 0x50) = arg1;
                return;
            }
        }
    }
}

#pragma push
#pragma scheduling invalid_target
void fn_80016928(int arg0, int arg1) {
    unsigned char *entry;
    unsigned char *base;
    int i = 0;
    entry = base = lbl_8055D540;
    for (i = 0; i < (int)lbl_8055D54C; entry += 0x5C, i++) {
        if (arg0 == *(int *)(entry + 4)) {
            *(int *)(base + i * 0x5C + 0x50) = arg1;
            return;
        }
    }
}
#pragma push
#pragma scheduling invalid_target
void fn_80016970(int arg0, int arg1, int arg2, int arg3) {
    struct E { char pad[0x4]; int id; char pad2[0x44]; int f4C; int f50; char rest[0x8]; };
    struct E *b = (struct E *)lbl_803577F0;
    int idx = arg0;
    int saved = arg3;
    b[idx].id = arg1;
    b[idx].f4C = *(int *)fn_80016544(arg2);
    b[idx].f50 = saved;
    *(int *)(lbl_80357960 + idx * 0xA8 + 4) = -1000;
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
    int found;
    int index;

    found = -1;
    for (index = 0; index < *(int *)&lbl_8055D554 && found == -1; index++) {
        if (arg1 == *(int *)((unsigned char *)fn_80016510(*(int *)((unsigned char *)fn_800167B8(index) + 0x4C)) + 4))
            found = index;
    }
    if (found != -1) {
        unsigned char *base = lbl_80357C20;
        int offset = found * 0x68;
        if (base[offset] != 0) {
            unsigned char *record = base + offset;
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
        count = (int)lbl_8055D550;
        found = 0;
        entry = lbl_8055D540 + offset;
        p = lbl_8055D544;
        for (j = 0; j < count; p += 0xA8, j++) {
            if (*(int *)(p + 4) == *(int *)(entry + 0x4C)) {
                *(int *)(entry + 0x4C) = j;
                found = 1;
                break;
            }
        }
        if (!found) *(int *)(entry + 0x4C) = i % (int)lbl_8055D550;
    }
    fn_80017558();
    fn_8013C8B8();
}
__declspec(section ".sdata") extern char lbl_80558BD4[];
__declspec(section ".sdata") extern char lbl_80558BE0[];
extern void fn_80016ED4(void *);
extern void fn_80017010(void *);
#pragma cplusplus on
extern "C" void fn_80016D14(void **arg0) {
    struct Node {
        virtual const char *name();
    };
    struct List {
        virtual void m0();
        virtual void *get(int);
    };
    void *child;
    int i;
    i = 0;
    for (; (child = ((List *)arg0)->get(i)) != 0; i++) {
        if (stricmp(((Node *)child)->name(), lbl_80558BD4) == 0) {
            fn_80016ED4(child);
        } else if (stricmp(((Node *)child)->name(), lbl_80558BE0) == 0) {
            fn_80017010(child);
        }
    }
}
#pragma cplusplus reset
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

#pragma push
#pragma cplusplus on
extern char lbl_802FCEA8[];
extern char lbl_80558C08[];
extern char lbl_80558C10[];
extern char lbl_80558BD0[];
extern char *fn_80029004(char *, int);
extern char *fn_80131234(char *);
extern int fn_80016DD8(const char *);
extern int fn_8013C8E8(char *);
extern void fn_802E317C(char *, char *);
extern "C" void fn_80017010(void *arg0) {
    struct Interface {
        virtual void m0();
        virtual void m1();
        virtual void m2();
        virtual char *m3(const char *, int);
        virtual char *m4(const char *, void *);
        virtual void m5();
        virtual int m6(const char *, int);
        virtual void m7();
        virtual void m8();
        virtual void m9();
        virtual int m10(const char *, int);
    };
    char *entry;
    char *src;
    int c;
    int v29, v30, v31;
    char *found;
    char *r26;
    int eidx, off;
    char *nameArg;
    entry = (char *)lbl_8055D544 + (int)lbl_8055D550 * 0xA8;
    *(int *)entry = (int)lbl_8055D550;
    *(int *)(entry + 4) = (int)lbl_8055D550 | 0x40000000;
    src = ((Interface *)arg0)->m3(lbl_80558C08, (int)lbl_8055D550);
    {
        char *p = src;
        char *q = entry + 0x2C;
        int lim = 0x20;
        for (;;) {
            unsigned char ch = *p++;
            *q++ = ch;
            if ((signed char)ch != 0) {
                lim--;
                if (lim <= 0) { *(q - 1) = 0; break; }
            } else break;
        }
    }
    c = (signed char)*(unsigned char *)(entry + 0x2C);
    if (c < 0 || c >= 0x100) {
    } else {
        c = lbl_802FE850.cmap->to_lower_table[c];
        *(unsigned char *)(entry + 0x2C) = c;
    }
    v29 = ((Interface *)arg0)->m10(lbl_802FCEA8 + 0x74, 0);
    v30 = ((Interface *)arg0)->m10(lbl_802FCEA8 + 0x84, 0);
    v31 = ((Interface *)arg0)->m10(lbl_80558C10, 0);
    r26 = (char *)0;
    if (v29 != 0) {
        *(int *)(entry + 8) = 0;
        {
            char sp88[64];
            char *p = entry + 0x2C;
            char *q = sp88;
            int lim = 0x40;
            for (;;) {
                unsigned char ch = *p++;
                *q++ = ch;
                if ((signed char)ch != 0) {
                    lim--;
                    if (lim <= 0) { *(q - 1) = 0; break; }
                } else break;
            }
            found = fn_80029004(sp88, 0x5F);
            if (found != (char *)0) {
                *found = 0;
                eidx = 0;
                off = 0;
                while (eidx < (int)lbl_8055D550) {
                    if (stricmp(sp88, (char *)lbl_8055D544 + off + 0x2C) == 0) {
                        *(int *)(entry + 8) = *(int *)((char *)lbl_8055D544 + eidx * 0xA8 + 4);
                        *(int *)((char *)lbl_8055D544 + eidx * 0xA8 + 8) = *(int *)(entry + 4);
                        r26 = (char *)lbl_8055D544 + eidx * 0xA8 + 0x2C;
                        break;
                    }
                    off += 0xA8;
                    eidx++;
                }
                if (*(int *)(entry + 8) == 0) fn_802E317C(lbl_802FCEA8 + 0x94, entry + 0x2C);
            } else {
                fn_802E317C(lbl_802FCEA8 + 0xC4, entry + 0x2C);
            }
        }
    } else {
        *(int *)(entry + 8) = *(int *)(entry + 4);
    }
    nameArg = r26 ? r26 : entry + 0x2C;
    src = ((Interface *)arg0)->m4(lbl_802FCEA8 + 0xFC, nameArg);
    {
        char *p = src;
        char *q = entry + 0xC;
        int lim = 0x20;
        for (;;) {
            unsigned char ch = *p++;
            *q++ = ch;
            if ((signed char)ch != 0) {
                lim--;
                if (lim <= 0) { *(q - 1) = 0; break; }
            } else break;
        }
    }
    {
        char *p = lbl_802FCEA8 + 0x10C;
        char *q = entry + 0x4C;
        int lim = 0x10;
        for (;;) {
            unsigned char ch = *p++;
            *q++ = ch;
            if ((signed char)ch != 0) {
                lim--;
                if (lim <= 0) { *(q - 1) = 0; break; }
            } else break;
        }
    }
    {
        char sp48[64];
        fn_801345D8(sp48, 0x40, lbl_802FCEA8 + 0x118, (int)(entry + 0xC));
        src = fn_80131234(sp48);
        char *p = src;
        char *q = entry + 0xC;
        int lim = 0x20;
        for (;;) {
            unsigned char ch = *p++;
            *q++ = ch;
            if ((signed char)ch != 0) {
                lim--;
                if (lim <= 0) { *(q - 1) = 0; break; }
            } else break;
        }
    }
    *(int *)(entry + 0x98) = 0;
    while (*(int *)(entry + 0x98) < 0xC) {
        char sp28[32];
        fn_801345D8(sp28, 0x20, lbl_802FCEA8 + 0x124, *(int *)(entry + 0x98) + 1);
        if (((Interface *)arg0)->m4(lbl_802FCEA8 + 0x124, sp28) != (char *)0) {
            *(int *)(entry + 0x64 + *(int *)(entry + 0x98) * 4) = fn_80016DD8(sp28);
            *(int *)(entry + 0x98) = *(int *)(entry + 0x98) + 1;
            continue;
        }
        if (*(int *)(entry + 0x98) == 0) {
            *(int *)(entry + 0x64) = 0xFF008040;
            *(int *)(entry + 0x98) = *(int *)(entry + 0x98) + 1;
        }
        break;
    }
    *(int *)(entry + 0x94) = ((Interface *)arg0)->m6(lbl_802FCEA8 + 0x134, 0) - 1;
    *(int *)(entry + 0x9C) = fn_8013C8E8(entry + 0x2C);
    *(int *)(entry + 0xA0) = 0;
    if (((Interface *)arg0)->m10(lbl_802FCEA8 + 0x14C, 0) != 0) *(int *)(entry + 0xA0) |= 1;
    if (v29 != 0) *(int *)(entry + 0xA0) |= 2;
    if (v30 != 0) *(int *)(entry + 0xA0) |= 4;
    if (v31 != 0) *(int *)(entry + 0xA0) |= 8;
    *(int *)(entry + 0xA4) = 0x0FF807FF;
    eidx = 0;
    while (1) {
        char sp8[32];
        int count;
        fn_801345D8(sp8, 0x20, lbl_802FCEA8 + 0x158, eidx + 1);
        count = ((Interface *)arg0)->m6(sp8, 0);
        if (count == 0) break;
        if (count >= 0) *(int *)(entry + 0xA4) |= (1 << count);
        else *(int *)(entry + 0xA4) &= ~(1 << -count);
        eidx++;
    }
    fn_801345D8(entry + 0x5C, 8, lbl_80558BD0, *(int *)(entry + 4) & 0xBFFFFFFF);
    lbl_8055D550 = (void *)((int)lbl_8055D550 + 1);
}
#pragma cplusplus reset
#pragma pop

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
    int off5c = arg0 * 0x5c;
    unsigned char *entry = base + off5c;
    int idx = arg0;
    int off1 = 0x410 + idx * 8;
    int off2 = 0x430 + idx * 0x68;
    memset(entry, 0, 0x5c);
    *(int *)(entry + 4) = -1000;
    ((void (*)(char *, int, const char *, ...))fn_801345D8)((char *)(entry + 8), 0x40, (const char *)lbl_802FD07C, idx + 1);
    *(int *)(entry + 0x48) = 1000;
    base[off1] = 0;
    base[off2] = 0;
}
#pragma scheduling on
void fn_80017708(void *arg0, int arg1, void *arg2) {
    register int temp_r4;
    int temp_r0;
    int temp_r0_2;
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
