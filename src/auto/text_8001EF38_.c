// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

int fn_8001F7E4();
s32 fn_8001FD24(void);
extern s8 lbl_8055D614;
extern s32 lbl_8055D618;
extern char lbl_802FE060[];

typedef struct SrcCoef {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
} SrcCoef;

extern SrcCoef lbl_802FDF30[8];
extern s32 lbl_8055D610;
extern s32 fn_8000DA10(void);
void fn_80128668(void*);
void fn_80128670(s32);
void fn_80131818(s32);
s32 fn_8001F89C();
s32 fn_8001F2C8();
s32 fn_8001F388();
s32 fn_8001F3AC();
s32 stricmp(const char*, const char*);
extern void* memset(void*, int, unsigned long);
extern char lbl_80358698[0x2080];
extern char lbl_8035AF38[0x820];

void fn_8001F578();
void fn_8001FBE4();
void fn_8001F724();
void fn_8001F780();
s32 fn_8001F9A4();
s32 fn_8001FA20();
s32 fn_8001FA8C();

extern void fn_802E6BD8(int, int, void *, int, void (*)(long));
extern void fn_8000DBC8(void (*)(long, long));
void fn_8001F528(void);
void fn_8001EFF0(void);
extern char lbl_802FDE68[];
extern char lbl_802FE0D4[], lbl_802FE0E0[], lbl_802FE0EC[], lbl_802FE0FC[];
extern char lbl_80558D5C[8], lbl_80558D64[8], lbl_80558D6C[8];
#pragma use_lmw_stmw off
extern s32 fn_80131234(s32);
extern s32 fn_80131810(void*);
extern void* fn_801284F8(int, void*);
extern void* fn_8012850C(int, void*);
extern void fn_802E317C(const char*, ...);
extern void fn_802E30C8(const char *, ...);
s32 fn_8001F41C(const char* arg);
#define VFN(o, off, T) ((T)(*(void***)(o))[(off) / 4])
typedef struct VObj VObj;
typedef struct VTbl {
    void* s0; void* s1;
    char* (*getName)(VObj*);
    VObj* (*getAt)(VObj*, s32);
    void* s4;
    s32 (*getAttr)(VObj*, char*);
    void* s6;
    s32 (*getAttr2)(VObj*, char*);
    void* pad[0x18 - 8];
    VObj* (*getChild)(VObj*, s32);
} VTbl;
struct VObj { VTbl* vt; };
void fn_8001EF38(void* alarm) {
    fn_8001F528();
    fn_8001EFF0();
}

void fn_8001EF5C(void) {
    fn_8001F7E4();
}

void fn_8001EF60(void* alarm) {
    fn_8001F89C(alarm, fn_8000DA10());
}

void fn_8001EF98(void) {
    fn_8001F89C();
}

void fn_8001EF9C(void) {
    fn_8001F388();
}

void fn_8001EFA0(void) {
    fn_8001F9A4();
}

void fn_8001EFA4(void) {
    fn_8001FA20();
}

void fn_8001EFA8(void) {
    fn_8001FA8C();
}

void fn_8001EFAC(void) {
    fn_8001F3AC();
}

void fn_8001F908(void *);

void fn_8001EFB0(void *arg0) {
    fn_8001F908(arg0);
}

void fn_8001EFB4(void) {
    fn_8001F724();
}

void fn_8001F76C(void);

void fn_8001EFB8(void) {
    fn_8001F76C();
}

void fn_8001EFBC(void) {
    fn_8001F780();
}

void fn_8001EFC0(void) {
    fn_8001FAC8();
}

void fn_8001EFC4(void) {
    fn_8001FBE4();
}

void fn_8001EFC8(void) {
    fn_8001F578();
}

void fn_8001EFCC(void* alarm) {
    fn_8001F578(fn_8001F2C8(alarm));
}

#pragma scheduling invalid_target
void fn_8001EFF0(void) {
    char* base = lbl_802FDE68;
    SrcCoef* p;
    u32 n;
    s32 i;
    s32 j;
    s32 idx;
    VObj* obj;
    VObj* child;
    s32* res;

    p = (SrcCoef*)(base + 0xC8);
    n = 0;
    do {
        p->unk8 = fn_80131234(p->unk4);
        n++;
        p++;
    } while (n < 8);
    lbl_8055D610 = fn_80131810(base + 0x148);
    if (lbl_8055D610 != 0) {
        p = (SrcCoef*)(base + 0xC8);
        for (i = 0; (obj = ((VObj*)lbl_8055D610)->vt->getAt((VObj*)lbl_8055D610, i)) != NULL; i++) {
            if (stricmp(obj->vt->getName(obj), base + 0x15C) == 0) {
                idx = fn_8001F41C((char*)obj->vt->getAttr(obj, lbl_80558D5C));
                if (idx >= 0 && idx < 8) {
                    if ((u32)idx < 8) {
                        res = (s32*)fn_801284F8(8, base + 0x174);
                        if (res != NULL) {
                            res[0] = 0;
                            res[1] = 0;
                            for (j = 0; (child = obj->vt->getChild(obj, j)) != NULL; j++) {
                                if (stricmp(child->vt->getName(child), lbl_80558D6C) == 0) {
                                    res[1]++;
                                }
                            }
                            if (res[1] == 0) {
                                fn_802E317C(lbl_802FE0FC, obj->vt->getName(obj));
                            }
                            res[0] = (s32)fn_8012850C(res[1] * 8, lbl_802FE0EC);
                            res[1] = 0;
                            for (j = 0; (child = obj->vt->getChild(obj, j)) != NULL; j++) {
                                if (stricmp(child->vt->getName(child), lbl_80558D64) == 0) {
                                    *(s32*)(res[0] + res[1] * 8) = child->vt->getAttr2(child, lbl_802FE0E0);
                                    ((s32*)(res[0] + res[1] * 8))[1] = child->vt->getAttr(child, lbl_802FE0D4);
                                    res[1]++;
                                }
                            }
                        }
                        p[idx].unkC = res;
                    }
                } else {
                    s32 name = obj->vt->getAttr(obj, lbl_80558D5C);
                    fn_802E30C8(base + 0x188, obj->vt->getName(obj), name);
                }
            }
        }
    }
}
#pragma scheduling on
s32 fn_8001F2C8(void* alarm) {
    if (lbl_8055D610 != 0) {
        SrcCoef* p = lbl_802FDF30;
        void* c;
        u32 i = 0;
        void* zero = NULL;
        do {
            c = p->unkC;
            if (c != NULL && c != NULL) {
                if (*(s32*)c != 0) {
                    fn_80128670(*(s32*)c);
                }
                *(s32*)c = (s32)zero;
                ((s32*)c)[1] = (s32)zero;
                fn_80128668(c);
            }
            p->unkC = zero;
            i++;
            p++;
        } while (i < 8);
        fn_80131818(lbl_8055D610);
        lbl_8055D610 = 0;
    }
}
#pragma scheduling reset
f32* __AXFXGetSrcCoef(u32 i) {
    return (f32*)&lbl_802FDF30[i];
}

#pragma dont_inline on
s32 fn_8001F388(s32 arg) {
    return ((s32*)__AXFXGetSrcCoef(arg))[2];
}

s32 fn_8001F3AC(s32 a, s32 b) {
    s32 *q = *(s32 **)((s32 *)__AXFXGetSrcCoef(a) + 3);
    if (q == 0) goto null_result;
    if (b <= 0) goto bad_index;
    if (b > q[1]) goto bad_index;
    return ((s32 *)(q[0] + ((b - 1) * 8)))[1];
bad_index:
    return 0;
null_result:
    return 0;
}

s32 fn_8001F41C(const char* arg) {
    SrcCoef* p = lbl_802FDF30;
    u32 idx = 0;
    for (;;) {
        if (stricmp((const char*)p->unk0, arg) == 0) {
            return idx;
        }
        idx++;
        p++;
        if (idx >= 8) {
            return -1;
        }
    }
}

#pragma scheduling off
void fn_8001F490(s32 arg) {
    if (arg == 2)
        goto reset;
    if (arg < 2) {
        if (arg == 0)
            goto reset;
        return;
    }
    return;
reset:
    memset(&lbl_80358698, 0, 0x2080);
}
#pragma scheduling on
extern char lbl_802FE024[];
extern void fn_802E30C8(const char *, ...);
#pragma scheduling invalid_target
void fn_8001F4C4(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        fn_802E30C8(lbl_802FE024, arg0);
        memset(lbl_80358698 + arg0 * 0x820, 0, 0x820);
        break;
    default:
        break;
    }
}

void fn_8001F528(void) {
    fn_802E6BD8(0x41434856, 3, lbl_80358698, 0x2080, fn_8001F490);
    fn_8000DBC8(fn_8001F4C4);
    fn_8001F578();
}

#pragma scheduling on
extern char lbl_8035A718[0x820];
#pragma scheduling invalid_target
void fn_8001F578(void) {
    memset(lbl_8035A718, 0, 0x820);
    memset(lbl_8035AF38, 0, 0x820);
}
#pragma scheduling on
extern void *memcpy(void *, const void *, unsigned long);
void fn_8001F5BC(void *arg0, void *arg1, int arg2) {
    volatile int *a = (volatile int *)arg0;
    volatile int *b = (volatile int *)arg1;
    char *input = (char *)arg1 + 0x50;
    char *output = (char *)arg0;
    char *entry;
    int sum7, sum6, sum5, sum4, sum3, sum2, sum1, sum0;
    int found, empty;
    unsigned int i, j;

    sum0 = a[0] + b[0];
    sum1 = a[1] + b[1];
    sum2 = a[2] + b[2];
    sum3 = a[3] + b[3];
    sum4 = a[4] + b[4];
    sum5 = a[5] + b[5];
    sum6 = a[6] + b[6];
    sum7 = a[7] + b[7];
    a[0] = sum0;
    a[1] = sum1;
    a[2] = sum2;
    a[3] = sum3;
    a[4] = sum4;
    a[5] = sum5;
    a[6] = sum6;
    a[7] = sum7;

    i = 0;
    for (; i < 0x32; i++, input += 0x28) {
        entry = output + 0x50;
        found = 0;
        empty = -1;
        for (j = 0; found == 0 && j < 0x32; entry += 0x28, j++) {
            if (empty < 0 && (signed char)*entry == 0) {
                empty = j;
            } else if (stricmp(entry, input) == 0) {
                int value20 = *(int *)(entry + 0x20) + *(int *)(input + 0x20);
                int value24 = *(int *)(input + 0x24);
                found = 1;
                *(volatile int *)(entry + 0x20) = value20;
                *(int *)(entry + 0x24) += value24;
            }
        }
        if (found == 0) {
            memcpy(output + 0x50 + empty * 0x28, input, 0x28);
        }
    }
}

#pragma scheduling invalid_target
void fn_8001F724(void) {
    ((void (*)())fn_8001F5BC)(lbl_8035A718, lbl_8035AF38);
    memset(lbl_8035AF38, 0, 0x820);
}
#pragma scheduling on

#pragma scheduling invalid_target
void fn_8001F76C(void) {
    memset(lbl_8035AF38, 0, 0x820);
}

#pragma scheduling invalid_target
int fn_8001F7E4(s32 arg0, s32 arg1) {
    s32 limit;
    s32 adjusted;

    if (fn_8001FD24()) {
        if (arg0 == 0 && *(u8 *)&lbl_8055D614 != 0) {
            limit = lbl_8055D618 - fn_8001F89C(arg0, fn_8000DA10());
            adjusted = arg1;
            if (limit < arg1)
                adjusted = limit;
            fn_802E30C8(lbl_802FE060, arg1, adjusted);
            arg1 = adjusted;
        }
        *(s32 *)(arg0 * 4 + (u32)lbl_8035AF38) += arg1;
    }
}
#pragma scheduling on
extern char lbl_802FE0A0[];
s32 fn_8001F89C(s32 arg0, s32 arg1) {
    if (arg1 >= 0 && (u32)arg1 < 4) {
        return *(s32 *)(lbl_8035A718 + arg0 * 4)
             + *(s32 *)(lbl_80358698 + arg1 * 0x820 + arg0 * 4);
    }
    fn_802E30C8(lbl_802FE0A0);
    return 0;
}

void fn_8001F908(void *arg0) {
    s32 index = fn_8000DA10();

    if (index >= 0 && (u32)index < 4U) {
        *(s32 *)((u8 *)arg0 + 4) =
            *((s32 *)&lbl_80358698 +
              index * 0x208 + *(s32 *)arg0);
    } else {
        *(s32 *)((u8 *)arg0 + 4) = 0;
    }

    *(s32 *)((u8 *)arg0 + 8) =
        *((s32 *)&lbl_80358698 + 0xA28 + *(s32 *)arg0) +
        (*(s32 *)((u8 *)arg0 + 4) +
         *((s32 *)&lbl_80358698 + 0x820 + *(s32 *)arg0));
}

#pragma scheduling invalid_target
s32 fn_8001F9A4(s32 arg0, s32 arg1) {
    volatile s32 *temp_r5;
    s32 *var_r6;
    s32 temp_r0;
    s32 var_ctr;
    s32 var_r3;
    if (arg0 < 0) goto no_coef;
    if ((u32)arg0 >= 8) goto no_coef;
    temp_r5 = (volatile s32 *)lbl_802FDF30[arg0].unkC;
    if (temp_r5 == 0) goto no_coef;
    var_r6 = (s32 *)temp_r5[0];
    if (var_r6 != 0) goto have_data;
    return 0;
have_data:
    temp_r0 = temp_r5[1];
    var_r3 = 0;
    for (var_ctr = temp_r0; var_ctr > 0; var_ctr--) {
        if (var_r6[0] > arg1) return var_r3;
        var_r6 += 2;
        var_r3++;
    }
    return temp_r5[1];
no_coef:
    return 0;
}
#pragma scheduling on
s32 fn_8001FA20(s32 arg0, s32 arg1) {
    s32 *q;
    s32 data;
    if (arg0 < 0) goto no_coef;
    if ((u32)arg0 >= 8) goto no_coef;
    q = lbl_802FDF30[arg0].unkC;
    if (q == 0) goto no_coef;
    data = q[0];
    if (data == 0) goto invalid;
    if (q[1] < arg1) goto invalid;
    if (arg1 > 0) goto get_value;
invalid:
    return -1;
get_value:
    return *(s32 *)(data + ((arg1 - 1) * 8));
no_coef:
    return 0;
}
#pragma scheduling on
s32 fn_8001FA8C(s32 arg0) {
    SrcCoef *base;
    void *p;

    if (arg0 < 0)
        goto zero;
    if ((u32)arg0 >= 8)
        goto zero;
    base = lbl_802FDF30;
    p = base[arg0].unkC;
    if (p == 0)
        goto zero;
    return ((s32 *)p)[1];
zero:
    return 0;
}

extern void *fn_80016720(const char *);
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
int fn_8001FAC8(int arg0, const char *arg1) {
    register char *table = lbl_80358698;
    register char *name;
    register int total;
    register int offset;
    register char *region;
    register char *nameTable;
    register char *valueTable;

    name = (char *)fn_80016720(arg1);
    total = 0;
    region = table + fn_8000DA10() * 0x820;
    offset = arg0 * 4;
    nameTable = region + 0x50;
    valueTable = region + offset;
    arg0 = 0;
    for (; (unsigned int)arg0 < 0x32; arg0++) {
        if (stricmp(nameTable, name) == 0)
            total += *(int *)(valueTable + 0x70);
        nameTable += 0x28;
        valueTable += 0x28;
    }

    region = table + 0x2080;
    nameTable = region + 0x50;
    valueTable = region + offset;
    arg0 = 0;
    for (; (unsigned int)arg0 < 0x32; arg0++) {
        if (stricmp(nameTable, name) == 0)
            total += *(int *)(valueTable + 0x70);
        nameTable += 0x28;
        valueTable += 0x28;
    }

    region = table + 0x28A0;
    nameTable = region + 0x50;
    valueTable = region + offset;
    arg0 = 0;
    for (; (unsigned int)arg0 < 0x32; arg0++) {
        if (stricmp(nameTable, name) == 0)
            total += *(int *)(valueTable + 0x70);
        nameTable += 0x28;
        valueTable += 0x28;
    }
    return total;
}

void fn_8001FBE4(s32 arg0, const char *arg1, s32 arg2) {
    char *record;
    char *entry;
    char *name;
    s32 count;
    char *dst;
    s32 found;
    s32 empty;
    u32 i;
    s32 address;
    s32 rowOffset;

    if (fn_8001FD24() == 0)
        return;

    name = (char *)fn_80016720(arg1);
    record = lbl_8035AF38;
    entry = record + 0x50;
    found = -1;
    empty = -1;
    i = 0;
    do {
        if (empty < 0 && (signed char)record[0x50] == 0)
            empty = i;
        else if (stricmp(entry, name) == 0)
            found = i;
        i++;
        record += 0x28;
        entry += 0x28;
    } while (i < 0x32);

    if (found < 0) {
        rowOffset = empty * 0x28;
        address = (s32)lbl_8035AF38;
        address += rowOffset;
        dst = (char *)(address + 0x50);
        count = 0x20;
        do {
            count--;
            if (count <= 0) {
                dst[-1] = 0;
                break;
            }
            *dst++ = *name++;
        } while ((signed char)dst[-1] != 0);
        address = (s32)lbl_8035AF38;
        address += rowOffset;
        address += arg0 * 4;
        *(s32 *)(address + 0x70) = arg2;
    } else {
        address = (s32)lbl_8035AF38;
        address += found * 0x28;
        address += arg0 * 4;
        *(s32 *)(address + 0x70) += arg2;
    }
}

#pragma pop

extern s32 fn_801E8838(void);
s32 fn_8001FD24(void) {
    return fn_801E8838() == 0;
}

extern s8 lbl_8055D614;
extern s32 lbl_8055D618;
extern s32 fn_80018FB4(void);
void fn_8001FD4C(s8 arg0) {
    lbl_8055D614 = arg0;
    lbl_8055D618 = fn_80018FB4();
}

#pragma dont_inline off
#pragma scheduling invalid_target
