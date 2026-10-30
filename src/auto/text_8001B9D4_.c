#include <types.h>

extern s32 fn_8001D020(s32, s32, s32, const char *, s32, s32, f32);

extern char lbl_802FD6D8[];
extern const char lbl_80558CD0;
extern u8 lbl_8055D5D8;
extern void fn_802E30C8(const char *, ...);
extern void *fn_801284F8(s32, const char *);
extern void fn_802E6BD8(u32, s32, void *, u32, void (*)(s32));
extern void fn_8000DBC8(void *);
extern s32 fn_80131808(const char *);
extern void memset(void *, s32, u32);
extern void fn_8001D5F0(s32);
extern void fn_8001D728(s32, s32);

extern void *lbl_8055D5D4;

extern u32 fn_8001D220(u32, u32, u32);
extern void fn_8001D298(s32);

extern void fn_8001C714(void);

typedef struct Unk8001BBBC {
    s32 unk_0x0;
    s32 unk_0x4;
    s32 unk_0x8;
} Unk8001BBBC;

extern s8 lbl_8055D5C8;
extern s32 *lbl_8055D5D0;
extern u8 *lbl_8055D5CC;
extern char lbl_803583C8[];
extern void fn_8002F634(void *, void *, s32, s32);
extern s32 fn_8001BA10(s32, s32);
extern s32 fn_8001D2E4(s32, s32, s32, s32);
extern void *lbl_80358658[];
extern s32 lbl_802ED7B8[];
extern const char lbl_802FD85C[];
extern s32 fn_802E317C(const char *);
extern void fn_8001C9C4(void);
extern void fn_8001CAF8(void);
extern s32 fn_8001D25C(s32);
extern void fn_8001CD4C(s32, s32, s32);
extern s32 fn_8001CB8C(s32, const char *, void *);
extern void *fn_8001BC38();
extern char lbl_80358628[];
extern s32 fn_8001CDB8(s32, s32, s32, s32, s32);
extern s32 fn_8001CE34(s32, s32, s32, s32);
extern s32 fn_8001CE74(s32, s32, s32, s32);
extern const char lbl_80558C90[];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).



extern void fn_8001C4D4(void);
void fn_8001B9D4(void *arg0) {
    ((s32 *)arg0)[0] = -2;
    ((s32 *)arg0)[1] = -2;
    ((s32 *)arg0)[2] = -2;
    ((s32 *)arg0)[3] = -2;
    ((s32 *)arg0)[5] = -2;
    ((s32 *)arg0)[6] = -2;
}

#pragma scheduling invalid_target
#pragma scheduling on
void fn_8001B9F4(void) {
    fn_8002F634(&lbl_803583C8, fn_8001BA10, 0x14, 0x10);
}
#pragma scheduling reset
s32 fn_8001BA10(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

void fn_8001BA50(void *arg0) {
    ((s8 *)arg0)[0x10] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = -1;
}

void fn_8001BA68(void) {
}

void fn_8001BA6C(void) {
    fn_8001C714();
}

void fn_8001BA70(void) {
    fn_8001C73C();
}

void fn_8001BA74(void) {
    fn_8001C960();
}

void fn_8001BA78(void) {
    lbl_8055D5C8 = 1;
    fn_8001C9C4();
}

void fn_8001BA84(void) {
    lbl_8055D5C8 = 0;
    fn_8001CAF8();
}

#pragma scheduling invalid_target
s32 fn_8001BA90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp = fn_8001D25C(arg2);
    if (temp != 0) {
        return fn_8001CDB8(arg0, arg1, temp, arg3, arg4);
    }
    return arg4;
}

#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8001BB0C(s32 arg0, s32 arg1, s32 arg2) {
    s32 saved2 = arg2;
    s32 saved0 = arg0;
    ((void (*)(s32, s32, s32))fn_8001CE34)(saved0, fn_8001D25C(arg1), saved2);
}
#pragma pop
void fn_8001BB58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    volatile register s32 a = arg3;
    volatile register s32 b = arg2;
    fn_8001CE74(arg0, fn_8001D25C(arg1), b, a);
}
#pragma scheduling reset
s32 fn_8001BBB4(s32 arg0, s32 arg1, s32 arg2, const char *arg3, s32 arg4, s32 arg5, f32 arg6) {
    return fn_8001D020(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

void fn_8001BBB8(void) {
    fn_8001CF8C();
}

extern void fn_8001D234(s32, s32 *, s32 *, s32 *);
void fn_8001BBBC(Unk8001BBBC *arg0, s32 arg1) {
    Unk8001BBBC value;
    fn_8001D234(arg1, &value.unk_0x0, &value.unk_0x4, &value.unk_0x8);
    *arg0 = value;
}

s32 ARCGetStartOffset(void *arg0) { return ((s32 *)arg0)[2]; }

s32 fn_8001BC18(s32 arg0) { return arg0 + 0x14; }

s32 fn_8001BC20(s32 arg0) { return arg0 + 0x1C; }

void fn_8001BC28(void *arg0, s32 arg1) {
    *(s32 *)((char *)arg0 + 0x1C) = arg1;
    *(s8 *)((char *)arg0 + 0x20) = 1;
}

#pragma push
#pragma small_data off
void *fn_8001BC38(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *base = (u8 *)arg0;
    s32 count;
    *(s32 *)(base + 0) = arg1;
    *(s32 *)(base + 0xC) = arg4;
    *(s32 *)(base + 4) = arg2;
    *(s32 *)(base + 8) = arg3;
    count = fn_8001D25C(arg3);
    if (count != 0) {
        *(void **)(base + 0x18) =
            ((void *(*)(s32, s32, s32))fn_8001CD4C)(*(s32 *)(base + 0), *(s32 *)(base + 4), count);
        *(u8 *)(base + 0x10) = fn_8001CB8C(*(s32 *)(base + 4), (const char *)count, base + 0x14);
    } else {
        *(void **)(base + 0x18) = &lbl_80358628;
        *(u8 *)(base + 0x10) = 0;
    }
    *(s32 *)(base + 0x1C) =
        *(s32 *)((u8 *)*(void **)(base + 0x18) + *(s32 *)(base + 0xC) * 0xC + 8);
    *(u8 *)(base + 0x20) = 0;
    return arg0;
}
#pragma pop
s32 fn_8001BCF0(void *arg0) {
    s32 var_r5 = 0;
    u8 *ptr = (u8 *)(((s32 *)arg0)[6] + ((s32 *)arg0)[3] * 0xC);
    if (ptr[0x10] != 0)
        goto done;
    if (((u8 *)arg0)[0x20] == 0)
        goto done;
    var_r5 = 1;
done:
    return var_r5;
}

s32 fn_8001BD28(void *arg0) {
    return ((s32 *)arg0)[1];
}

u8 fn_8001BD30(void *arg0) {
    return *(u8 *)((u8 *)arg0 + 0x10);
}

void fn_8001BD38(void *arg0, s32 arg1, s32 arg2) {
    s32 r4 = arg1;
    s32 r5 = arg2;
    s32 r6 = (s32)arg0;
    s32 r3 = *(s32 *)(r6 + 4);
    s32 r4b = *(s32 *)(r6 + 0x1C);
    fn_8001C73C(r3, r4b, r4, r5);
}

#pragma dont_inline on
void fn_8001BD54(Unk8001BBBC *arg0, void *arg1) {
    fn_8001BBBC(arg0, *(s32 *)((u8 *)*(void **)((u8 *)arg1 + 0x18) + *(s32 *)((u8 *)arg1 + 0xC) * 0xC + 0xC));
}
#pragma scheduling invalid_target
u32 fn_8001BD6C(void *arg0, void *arg1) {
    u32 a0 = *(u32 *)((s8 *)arg0 + 0x18);
    u32 a0c = *(u32 *)((s8 *)arg0 + 0xC);
    u32 a18 = *(u32 *)((s8 *)arg1 + 0x18);
    u32 a1c = *(u32 *)((s8 *)arg1 + 0xC);
    u32 r = fn_8001D2E4(a0, a0c, a18, a1c);
    return (r & 0x80000000) >> 31;
}
#pragma scheduling on
extern void *fn_800167CC(s32);
extern void *fn_80016BC8(void *, s32);
#pragma push
#pragma small_data off
#pragma pop
void fn_8001BDA8(void *arg0) {
    u8 *base = (u8 *)arg0;
    s32 index;
    void *result;
    void *temp;

    if (base[0x20] != 0) {
        if (*(void **)(base + 0x18) != &lbl_80358628) {
            index = *(s32 *)(base + 0xC);
            *(s32 *)((u8 *)*(void **)(base + 0x18) + index * 0xC + 8) =
                *(s32 *)(base + 0x1C);
            index = *(s32 *)(base + 0xC);
            *(u8 *)((u8 *)*(void **)(base + 0x18) + index * 0xC + 0x10) = 1;
            result = fn_800167CC(0);
            temp = fn_80016BC8((void *)0, 0);
            *(s32 *)((u8 *)*(void **)(base + 0x18) +
                     *(s32 *)(base + 0xC) * 0xC + 0xC) =
                fn_8001D220(*(u32 *)result, *(u32 *)((u8 *)temp + 4),
                            *(u8 *)((u8 *)temp + 8));
            fn_8001D298(*(s32 *)arg0);
        }
    }
    base[0x20] = 0;
}
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8001BE70(void *arg0) {
    s32 index = *(s32 *)((u8 *)arg0 + 0xC);
    s32 base = *(s32 *)((u8 *)arg0 + 0x18);
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)(base + index * 0xC + 8);
    *(u8 *)((u8 *)arg0 + 0x20) = 0;
}
#pragma scheduling reset
void *fn_8001BE94(void *dest, int val, size_t count) {
    ((void *(*)())fn_8001BC38)(dest, val, count);
    return dest;
}

s32 fn_8001BC18(s32 arg0);
#pragma dont_inline reset
f32 fn_8001BEC4(s32 arg0) {
    return *(f32 *)((s32 (*)(s32))fn_8001BC18)(arg0);
}

f32 fn_8001BEE8(s32 arg0) {
    return *(f32 *)((s32 (*)(s32))fn_8001BC20)(arg0);
}

extern void fn_8001BC28();
extern void fn_8001BC28(void *arg0, s32 arg1);
void fn_8001BF0C(s32 arg0, f32 arg1) {
    f32 temp = arg1;
    ((void (*)(s32, s32))fn_8001BC28)(arg0, *(s32 *)&temp);
}

#pragma push
#pragma dont_inline on
#pragma paired off
#pragma paired_single off
s32 fn_8001BF34(s32 arg0, f32 arg1) {
    f32 var_f31;
    s32 temp_r3;
    s32 var_r31;

    if (fn_8001BCF0((void *)arg0) == 0 &&
        ((s32 (*)(void *))fn_8001BD30)((void *)arg0) == 0) {
        goto return_one;
    }
    if (fn_8001BCF0((void *)arg0) != 0) {
        var_f31 = fn_8001BEE8(arg0);
    } else {
        var_f31 = fn_8001BEC4(arg0);
    }
    temp_r3 = fn_8001BD28((void *)arg0);
    var_r31 = temp_r3 & 0x60000;
    if ((u32)(temp_r3 - 0x20000) == 0x507 && ARCGetStartOffset((void *)arg0) >= 0) {
        if (*(u32 *)((u8 *)fn_8001285C() + 8) == 0x180302) {
            var_r31 = 0x20000;
        } else {
            var_r31 = 0x40000;
        }
    }
    switch (var_r31) {
    case 0x40000:
        goto compare_greater;
    case 0x20000:
        goto compare_less;
    default:
        break;
    }
    {
        s32 logBits = fn_8001BD28((void *)arg0) & 0x60000;
        s32 logValue = fn_8001BD28((void *)arg0);
        ((void (*)(const char *, ...))fn_802E317C)(lbl_802FD6D8, logValue, logBits);
    }
compare_greater:
    return arg1 > var_f31;
compare_less:
    return arg1 < var_f31;
return_one:
    return 1;
}
#pragma pop

void *fn_8001C070(void *dest, int val, size_t count) {
    ((void *(*)())fn_8001BC38)(dest, val, count);
    return dest;
}

#pragma dont_inline on
s32 fn_8001C0A0(void) {
    return *(s32 *)((s32 (*)(void))fn_8001BC18)();
}

s32 fn_8001C0C4(void) {
    return *(s32 *)((s32 (*)(void))fn_8001BC20)();
}

#pragma dont_inline reset
void fn_8001C0E8(void) {
    ((void (*)(void))fn_8001BC28)();
}

extern const char lbl_802FD718[];
#pragma dont_inline on
s32 fn_8001C0EC(s32 arg0, s32 arg1) {
    s32 var_r30;
    s32 temp_r3;
    s32 temp_r31;
    if (fn_8001BCF0((void *)arg0) == 0) {
        if (((s32 (*)(void *))fn_8001BD30)((void *)arg0) == 0)
            goto return_one;
    }
    if (fn_8001BCF0((void *)arg0) != 0) {
        var_r30 = ((s32 (*)(void *))fn_8001C0C4)((void *)arg0);
    } else {
        var_r30 = ((s32 (*)(void *))fn_8001C0A0)((void *)arg0);
    }
    temp_r3 = fn_8001BD28((void *)arg0) & 0x60000;
    switch (temp_r3) {
    case 0x40000:
        goto compare_a;
    case 0x20000:
        goto compare_b;
    default:
        break;
    }
    temp_r31 = fn_8001BD28((void *)arg0) & 0x60000;
    {
        s32 logValue = fn_8001BD28((void *)arg0);
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_802FD718, logValue, temp_r31);
    }
compare_a:
    return var_r30 < arg1;
compare_b:
    return arg1 < var_r30;
return_one:
    return 1;
}
#pragma dont_inline reset
s32 fn_8001C200(const char *arg0, const char *arg1) {
    s32 result = 0;
    if (stricmp(arg0, arg1) == 0 || stricmp(arg0, lbl_80558C90) == 0 || stricmp(arg1, lbl_80558C90) == 0) {
        result = 1;
    }
    return result;
}
#pragma scheduling reset
s32 fn_8001C27C(void *arg0, u32 arg1, const char *arg2) {
    volatile u32 key = *(volatile u32 *)arg0;
    s32 result = 0;
    if (key == arg1 && fn_8001C200(*(const char **)((u8 *)arg0 + 4), arg2) != 0)
        result = 1;
    return result;
}
#pragma dont_inline on
#pragma use_lmw_stmw off
s32 fn_8001C2CC(s32 arg0, u32 arg1, const char *arg2, s32 arg3) {
    s32 offset = 0;
    s32 i = 0;
    void *entry;
    void *record;
    for (;;) {
        entry = lbl_80358658[arg0];
        record = (void *)(*(s32 *)entry + offset);
        if (fn_8001C27C(record, arg1, arg2) != 0) {
            return (s32)record;
        }
        offset += 0x2C;
        i++;
        if (i >= *(s32 *)((u8 *)entry + 4)) {
            return 0;
        }
    }
}
#pragma use_lmw_stmw reset
#pragma dont_inline reset
extern const char lbl_802FD750[];
#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
s32 fn_8001C35C(s32 arg0, s32 arg1, s32 arg2) {
    struct List { void *data; s32 count; s32 capacity; };
    struct TextBuffer { char *data; s32 size; };
    struct Record {
        s32 key;
        char *name;
        u8 pad08[8];
        u8 state10;
        u8 pad11[11];
        u8 state1c;
        u8 pad1d[11];
        u8 state28;
    };
    struct List *list = (struct List *)lbl_80358658[arg0];
    struct TextBuffer *descriptor;
    s32 count = list->count;
    char *input = (char *)arg2;
    char *records;
    s32 offset;
    struct Record *entry;
    char *p;
    char *out;
    s32 room;
    char c;

    if (count + 1 > list->capacity) {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_802FD750, arg0, 0x280);
    }

    list = (struct List *)lbl_80358658[arg0];
    count = list->count;
    records = (char *)list->data;
    offset = count * 0x2C;
    list->count = count + 1;
    entry = (struct Record *)(records + offset);
    entry->key = arg1;

    descriptor = (struct TextBuffer *)lbl_8055D5D0;
    ((u8 *)descriptor)[8] = 0;
    p = descriptor->data;
    for (;;) {
        if (stricmp(p, input) == 0) {
            break;
        }
        while (*p != 0) {
            p++;
        }
        p++;
        if (*p == 0) {
            room = descriptor->size - (p - descriptor->data) - 1;
            if (room <= 0) {
                p[-1] = 0;
            } else {
                out = p;
                do {
                    c = *input++;
                    *out++ = c;
                } while (c != 0);
            }
            break;
        }
    }

    entry->name = p;
    entry->state10 = 0;
    entry->state1c = 0;
    entry->state28 = 0;
    *(s32 *)(lbl_8055D5CC + arg0 * 0xDAC4 + 0x6E00) = list->count;
    return (s32)entry;
}
#pragma pop
void fn_8001C4D4(void) {

}

void fn_8001C4D8(void) {
    fn_8001C4D4();
    __builtin_unreachable();
}

void fn_8001C4DC(void) {
    fn_8001C4D8();
}

extern void *lbl_80358658[];
extern s32 lbl_802ED7B8[];
extern const char lbl_802FD85C[];
extern s32 fn_802E317C(const char *);
#pragma scheduling invalid_target
#pragma scheduling on
s32 *fn_8001C4E0(s32 arg0) {
    s32 *entry = lbl_802ED7B8;
    for (;;) {
        if (*entry == arg0) {
            return entry;
        }
        entry += 3;
        if (*entry == 0) {
            fn_802E317C(lbl_802FD85C);
            return 0;
        }
    }
}

extern const char lbl_802FD894[];
extern const char lbl_802FD8C4[];
#pragma push
#pragma scheduling invalid_target
#pragma scheduling on
#pragma use_lmw_stmw off
void *fn_8001C540(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *name = (char *)arg1;
    char *record;
    char *freeEntry;
    char *p;
    char *out;
    s32 i;
    s32 room;
    char c;
    s32 *descriptor;

    if (arg0 < 0) {
        record = (char *)(lbl_8055D5CC + 0x36B10);
    } else {
        record = (char *)(lbl_8055D5CC + arg0 * 0xDAC4 + 0x6E04);
    }
    freeEntry = 0;
    i = 0;
    do {
        if (*(u8 *)(record + 0x70) == 0) {
            freeEntry = record;
        } else if (*(s32 *)(record + 4) == arg2 &&
                   *(s32 *)record != 0 &&
                   stricmp(name, *(const char **)record) == 0) {
            return record;
        }
        i++;
        record += 0x74;
    } while (i < 0xF0);

    if (arg3 == 0) {
        return 0;
    }
    fn_802E30C8(lbl_802FD894, name);
    if (freeEntry == 0) {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_802FD8C4, name);
    }
    memset(freeEntry, 0, 0x74);

    descriptor = lbl_8055D5D0;
    *((u8 *)descriptor + 8) = 0;
    p = *(char **)descriptor;
    for (;;) {
        if (stricmp(p, name) == 0) {
            break;
        }
        while (*p != 0) {
            p++;
        }
        p++;
        if (*p == 0) {
            room = descriptor[1] - (p - *(char **)descriptor) - 1;
            if (room <= 0) {
                p[-1] = 0;
            } else {
                out = p;
                do {
                    c = *name++;
                    *out++ = c;
                } while (c != 0);
            }
            break;
        }
    }
    *(char **)freeEntry = p;
    *(s32 *)(freeEntry + 4) = arg2;
    *(u8 *)(freeEntry + 0x70) = 1;
    return freeEntry;
}
#pragma pop

#pragma scheduling reset
void fn_8001C714(void) {
    fn_80131234(*(s32 *)((u8 *)((s32 *(*)(void))fn_8001C4E0)() + 8));
}

extern const char lbl_802FD9E8[];
int fn_8001C960(u32 arg0) {
    volatile s32 *entry;
    s32 value;

    entry = lbl_802ED7B8;
    goto check;
loop:
    if ((u8)value == arg0) {
        return *entry;
    }
    entry += 3;
check:
    value = *entry;
    if (value != 0) {
        goto loop;
    }
    ((s32 (*)(const char *, ...))fn_802E317C)(lbl_802FD9E8, arg0);
    return 0;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8001C9C4(void) {
    char *base = lbl_802FD6D8;
    s32 var_r28;
    void **var_r27;
    s32 var_r26;
    s32 var_r30 = 0x280;
    s32 var_r31 = 0;
    void *descriptor;

    fn_802E30C8(base + 0x344, 0x3E7D0);
    lbl_8055D5CC = fn_801284F8(0x3E7D0, (const char *)&lbl_80558CD0);
    memset(lbl_8055D5CC, 0, 0x3E7D0);
    var_r27 = lbl_80358658;
    var_r26 = 0;
    var_r28 = 0;
    do {
        descriptor = fn_801284F8(0xC, base + 0x374);
        if (descriptor != 0) {
            *(u8 **)descriptor = lbl_8055D5CC + var_r28;
            *(s32 *)((u8 *)descriptor + 8) = var_r30;
            *(s32 *)((u8 *)descriptor + 4) = var_r31;
        }
        var_r26++;
        *var_r27 = descriptor;
        var_r28 += 0xDAC4;
        var_r27++;
    } while (var_r26 < 4);
    descriptor = fn_801284F8(0x14, base + 0x380);
    if (descriptor != 0) {
        *(u8 **)descriptor = lbl_8055D5CC + 0x3D7D0;
        *(s32 *)((u8 *)descriptor + 4) = 0x1000;
    }
    lbl_8055D5D0 = descriptor;
    fn_802E6BD8(0x53746174, 7, lbl_8055D5CC, 0x3E7D0, fn_8001D5F0);
    fn_8000DBC8(fn_8001D728);
    lbl_8055D5D4 = (void *)fn_80131808(base + 0x390);
    lbl_8055D5D8 = 1;
}
#pragma pop

extern void fn_80131818(void *);
extern int fn_80128668();
void fn_8001CAF8(void) {
    void **ptr;
    s32 i;

    fn_80131818(lbl_8055D5D4);
    fn_80128668(lbl_8055D5D0);
    ptr = lbl_80358658;
    i = 0;
    do {
        void *entry = *ptr;
        if (entry == 0) {
        } else {
            if (entry == 0) {
            } else {
                ((s32 *)entry)[0] = 0;
                ((s32 *)entry)[1] = 0;
                ((s32 *)entry)[2] = 0;
            }
            fn_80128668();
        }
        i++;
        ptr++;
    } while (i < 4);
    fn_80128668(lbl_8055D5CC);
    lbl_8055D5CC = 0;
}

extern s32 *fn_8001C4E0(s32);
extern int stricmp(const char *, const char *);
extern char lbl_802FD6D8[];
extern char lbl_80558CD8;
extern void *lbl_8055D5D4;
extern void *lbl_8055E050;
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" s32 fn_8001CB8C(s32 flags, const char *name, void *out) {
    struct Node {
        virtual const char *GetName();
        virtual s32 IsValid(s32);
        virtual void Unused2();
        virtual void Unused3();
        virtual const char *GetParam(const char *, void *);
        virtual s32 GetInt(s32);
        virtual void Unused6();
        virtual f32 GetFloat(s32);
    };
    struct Manager {
        virtual Node *GetFallback(const char *);
        virtual Node *GetAt(s32);
    };
    s32 *archive;
    char *strings;
    Node *node;
    s32 index;
    f32 value;
    /* Fix note: preserve virtual slots and use a switch for the unit conversion flag. */
    strings = lbl_802FD6D8;
    if (name == 0) return 0;
    archive = fn_8001C4E0(flags);
    if (archive[1] == 0) return 0;
    index = 0;
    while ((node = ((Manager *)lbl_8055D5D4)->GetAt(index)) != 0) {
        if (stricmp(node->GetName(), strings + 0x39C) == 0 &&
            stricmp(node->GetParam(strings + 0x3AC, &lbl_80558CD8), name) == 0 &&
            node->IsValid(archive[1]) != 0) break;
        index++;
    }
    if (node == 0)
        node = ((Manager *)lbl_8055D5D4)->GetFallback(strings + 0x3BC);
    if (out != 0) {
        switch (flags & 0x300) {
        case 0x200:
            *(s32 *)out = node->GetInt(archive[1]);
            break;
        case 0x100:
            value = node->GetFloat(archive[1]);
            switch (flags & 0x1FC00) {
            case 0x800:
                value /= *(f32 *)((char *)lbl_8055E050 + 0x10);
                break;
            }
            *(s32 *)out = *(s32 *)&value;
            break;
        }
    }
    return 1;
}
#pragma cplusplus reset
#pragma scheduling on
#pragma dont_inline reset
void fn_8001CD4C(s32 arg0, s32 arg1, s32 arg2) {
    fn_8001C4D8();
    if (((s32 (*)(s32, s32, s32))fn_8001C2CC)(arg0, arg1, arg2) == 0) {
        fn_8001C35C(arg0, arg1, arg2);
    }
}

#pragma use_lmw_stmw off
s32 fn_8001CDB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *entry;

    fn_8001C4DC();
    entry = ((s32 *(*)(s32, s32, s32))fn_8001C2CC)(arg0, arg1, arg2);
    if (entry == 0) {
        goto fallback;
    }
    entry = (s32 *)((u8 *)entry + arg3 * 0xC);
    if (*(u8 *)((u8 *)entry + 0x10) != 0) {
        goto result;
    }
fallback:
    return arg4;
result:
    return entry[2];
}
#pragma use_lmw_stmw reset
s32 fn_8001CE34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *result;
    if (arg1 != 0) {
        result = fn_8001C540(arg0, arg1, arg2, 0);
        if (result != 0) {
            return *(s32 *)((u8 *)result + 0x6C);
        }
    }
    return 0;
}

s32 fn_8001CE74(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *result;
    if (arg1 != 0) {
        result = fn_8001C540(arg0, arg1, arg2, 0);
        if (result != 0) {
            if (arg3 < *(s32 *)((u8 *)result + 0x6C)) {
                return (s32)((u8 *)result + arg3 * 0x14 + 8);
            }
        }
    }
    return 0;
}

#pragma paired off
#pragma paired_single off
s32 fn_8001CED4(void *arg0, s32 arg1, s32 arg2, f32 arg3) {
    void *ptr = (void *)fn_8001285C(arg1);
    s32 count = *(s32 *)((u8 *)arg0 + 0x6C);
    s32 result = 0;
    if (count > 0 && *(s32 *)((u8 *)arg0 + 8) != 0 &&
        *(s32 *)((u8 *)arg0 + 0xC) >= arg2) {
        do {
            if (*(s32 *)((u8 *)arg0 + 0xC) == arg2) {
                if (*(u32 *)((u8 *)ptr + 8) == 0x00180302) {
                    if (*(f32 *)((u8 *)arg0 + 0x14) > arg3)
                        break;
                } else if (*(f32 *)((u8 *)arg0 + 0x14) < arg3) {
                    break;
                }
            }
            arg0 = (u8 *)arg0 + 0x14;
            result++;
        } while (--count != 0);
    }
    return result;
}
#pragma paired_single reset
#pragma paired reset
int fn_8001CF8C(arg0, arg1, arg2, arg3, arg4)
s32 arg0, arg1, arg2, arg3;
double arg4;
{
    s32 count = fn_8001D25C(arg1);
    void *result;
    if (count != 0) {
        result = fn_8001C540(arg0, count, arg2, 1);
        return ((int (*)(void *, s32, s32, double))fn_8001CED4)(result, arg1, arg3, arg4);
    }
    return 5;
}

#pragma push
#pragma paired off
#pragma paired_single off
#pragma use_lmw_stmw off
#pragma scheduling on
s32 fn_8001D020(s32 arg0, s32 arg1, s32 arg2, const char *arg3, s32 arg4, s32 arg5, f32 arg6) {
    struct SavedValues {
        char *name;
        s32 value0;
        s32 value1;
        f32 scale;
        s32 encoded;
    };
    register s32 savedArg2 = arg2;
    register const char *savedArg3 = arg3;
    register s32 savedArg4 = arg4;
    register s32 savedArg5 = arg5;
    s32 swap;
    void *record;
    s32 count;
    s32 temp;
    s32 maxCount;
    s32 offset;
    s32 remaining;
    s32 oldCount;
    s32 sourceByte;
    s32 *pool;
    char *cursor;
    char *base;
    char *dest;
    void *entry;
    void *layout;
    volatile struct SavedValues saved;
    /* Fix note: scan the pool, then shift and fill the selected record slot. */
    swap = arg0;
    arg0 = arg1;
    arg1 = swap;
    temp = fn_8001D25C(arg0);
    if (temp != 0) {
        record = fn_8001C540(arg1, temp, savedArg2, 1);
        count = fn_8001CED4(record, arg0, savedArg4, arg6);
        if (count < 5) {
            pool = lbl_8055D5D0;
            *(u8 *)((u8 *)pool + 8) = 0;
            cursor = *(char **)pool;
            goto scan_name;
        skip_name:
            while ((s8)*cursor != 0) cursor++;
            cursor++;
        scan_name:
            if ((s8)*cursor == 0 || cursor - *(char **)pool >= *(s32 *)((u8 *)pool + 4)) {
                dest = cursor;
                remaining = *(s32 *)((u8 *)pool + 4) -
                            (cursor - *(char **)pool) - 1;
            copy_name:
                sourceByte = (u8)*savedArg3;
                savedArg3++;
                *dest = (u8)sourceByte;
                dest++;
                if ((s8)sourceByte != 0) {
                    remaining--;
                    if (remaining <= 0) {
                        dest[-1] = 0;
                    } else {
                        goto copy_name;
                    }
                }
                goto name_ready;
            } else if (stricmp(cursor, savedArg3) == 0) {
                goto name_ready;
            } else {
                goto skip_name;
            }
        name_ready:
            saved.name = cursor;
            saved.value0 = savedArg4;
            saved.value1 = savedArg5;
            saved.scale = arg6;
            entry = fn_800167CC(0);
            layout = fn_80016BC8(entry, 0);
            saved.encoded = fn_8001D220(*(u32 *)entry,
                                        *(u32 *)((u8 *)layout + 4),
                                        *(u8 *)((u8 *)layout + 8));
            oldCount = *(s32 *)((u8 *)record + 0x6C);
            maxCount = oldCount <= 4 ? oldCount : 4;
            *(s32 *)((u8 *)record + 0x6C) = maxCount;
            offset = count * 0x14;
            base = (char *)record + offset;
            dest = base + 8;
            memmove(dest + 0x14, dest, (maxCount - count) * 0x14);
            *(char **)dest = saved.name;
            *(s32 *)(base + 0xC) = saved.value0;
            *(s32 *)(base + 0x10) = saved.value1;
            *(f32 *)(base + 0x14) = saved.scale;
            *(s32 *)(base + 0x18) = saved.encoded;
            oldCount = *(s32 *)((u8 *)record + 0x6C);
            *(s32 *)((u8 *)record + 0x6C) = oldCount + 1;
            return 1;
        }
    }
    return 0;
}

#pragma pop
#pragma scheduling reset
u32 fn_8001D220(u32 arg0, u32 arg1, u32 arg2) {
    u32 result = arg0 | (arg2 << 16);
    result |= arg1 << 8;
    return result;
}

#pragma scheduling invalid_target
void fn_8001D234(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u32 value = arg0;
    u32 byte = (value >> 16) & 0xFF;
    u32 mid = (value >> 8) & 0xFF;
    *arg1 = value & 0xFF;
    *arg2 = mid;
    *(s8 *)arg3 = (byte != 0);
}
#pragma scheduling on
void fn_8001D298(s32 arg0) {
    s32 temp_r31;
    temp_r31 = fn_8000DA10();
    fn_8000D984(arg0);
    fn_8000DB18();
    fn_8000D984(temp_r31);
}

extern const char lbl_802FDAAC[];
extern const char lbl_802FDAD8[];
s32 fn_8001D2E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *a = (u8 *)(arg0 + arg1 * 0xC);
    u8 *b;
    s32 type;
    s32 kind;

    if (*(u8 *)(a + 0x10) != 0) {
        b = (u8 *)(arg2 + arg3 * 0xC);
        if (*(u8 *)(b + 0x10) != 0) {
            type = *(s32 *)arg0 & 0x300;
            switch (type) {
            case 0x100:
                kind = *(s32 *)arg0 & 0x60000;
                switch (kind) {
                case 0x20000:
                    return *(f32 *)(a + 8) < *(f32 *)(b + 8) ? -1 : 1;
                case 0x40000:
                    return *(f32 *)(a + 8) > *(f32 *)(b + 8) ? -1 : 1;
                default:
                    ((void (*)(const char *, ...))fn_802E317C)(lbl_802FDAAC, kind);
                    return 0;
                }
            case 0x200:
                kind = *(s32 *)arg0 & 0x60000;
                switch (kind) {
                case 0x20000:
                    return *(s32 *)(a + 8) < *(s32 *)(b + 8) ? -1 : 1;
                case 0x40000:
                    return *(s32 *)(a + 8) > *(s32 *)(b + 8) ? -1 : 1;
                default:
                    ((void (*)(const char *, ...))fn_802E317C)(lbl_802FDAAC, kind);
                    return 0;
                }
            default:
                ((void (*)(const char *, ...))fn_802E317C)(lbl_802FDAD8, type);
                return 0;
            }
        }
        return -1;
    }
    return *(u8 *)(arg2 + arg3 * 0xC + 0x10);
}

s32 fn_8001D464(s32 arg0) {
    return arg0 + *lbl_8055D5D0;
}

s32 fn_8001D474(s32 arg0) {
    return arg0 - *lbl_8055D5D0;
}

#pragma push
#pragma use_lmw_stmw off
void fn_8001D484(void *arg0, s32 arg1, s32 (*arg2)(s32), s32 arg3) {
    void *var_r31;
    void *var_r30;
    s32 var_r29;
    s32 var_r28;
    var_r31 = arg0;
    var_r29 = 0;
    goto outer;
    do {
outer:
        if (*((u8 *)var_r31 + 0x70) != 0) {
            *(s32 *)var_r31 = arg2(*(s32 *)var_r31);
            var_r30 = var_r31;
            var_r28 = 0;
            goto inner;
            do {
inner:
                *(s32 *)((u8 *)var_r30 + 8) = arg2(*(s32 *)((u8 *)var_r30 + 8));
                var_r28 += 1;
                var_r30 = (u8 *)var_r30 + 0x14;
            } while (var_r28 < *(s32 *)((u8 *)var_r31 + 0x6C));
        }
        var_r29 += 1;
        var_r31 = (u8 *)var_r31 + 0x74;
    } while (var_r29 < arg1);
}
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8001D528(void *arg0) {
    s32 var_r31;
    u8 *var_r30;
    s32 var_r29;
    u8 *var_r28;
    s32 var_r27;
    s32 (*callback)(s32);

    callback = (s32 (*)(s32))arg0;
    var_r29 = 0;
    var_r31 = 0;
loop_outer_528:
    var_r27 = 0;
    var_r28 = lbl_8055D5CC + var_r31;
    var_r30 = var_r28;
    do {
        *(s32 *)(var_r30 + 4) = callback(*(s32 *)(var_r30 + 4));
        var_r30 += 0x2C;
        var_r27 += 1;
    } while (var_r27 < *(s32 *)(var_r28 + 0x6E00));
    ((void (*)(void *, s32, s32 (*)(s32)))fn_8001D484)(var_r28 + 0x6E04, 0xF0, callback);
    var_r29 += 1;
    var_r31 += 0xDAC4;
    if (var_r29 < 4) goto loop_outer_528;
    ((void (*)(void *, s32, s32 (*)(s32)))fn_8001D484)(lbl_8055D5CC + 0x36B10, 0xF0, callback);
}
#pragma scheduling reset
extern s32 fn_8001D464(s32);
extern void fn_8001D528(void *);
void fn_8001D5D8(void) {
    fn_8001D528(fn_8001D464);
}

extern s32 fn_8001D474(s32);
void fn_8001D5E4(void) {
    fn_8001D528(fn_8001D474);
}

extern void fn_8001D5D8(void);
extern void fn_8001D5E4(void);
extern void fn_8001D7A4(void);
extern void memset(void *, s32, u32);
extern u8 lbl_8055D5D8;
#pragma dont_inline on
void fn_8001D5F0(s32 arg0) {
    if (arg0 == 2) {
        memset(lbl_8055D5CC, 0, 0x3E7D0);
        ((s32 *)lbl_80358658[0])[1] = *(s32 *)(lbl_8055D5CC + 0x6E00);
        ((s32 *)lbl_80358658[1])[1] = *(s32 *)(lbl_8055D5CC + 0x148C4);
        ((s32 *)lbl_80358658[2])[1] = *(s32 *)(lbl_8055D5CC + 0x22388);
        ((s32 *)lbl_80358658[3])[1] = *(s32 *)(lbl_8055D5CC + 0x2FE4C);
        return;
    }
    if (arg0 < 2) {
        if (arg0 == 0) return;
        fn_8001D5D8();
        ((s32 *)lbl_80358658[0])[1] = *(s32 *)(lbl_8055D5CC + 0x6E00);
        ((s32 *)lbl_80358658[1])[1] = *(s32 *)(lbl_8055D5CC + 0x148C4);
        ((s32 *)lbl_80358658[2])[1] = *(s32 *)(lbl_8055D5CC + 0x22388);
        ((s32 *)lbl_80358658[3])[1] = *(s32 *)(lbl_8055D5CC + 0x2FE4C);
        if (lbl_8055D5D8 != 0) {
            fn_8001D7A4();
            lbl_8055D5D8 = 0;
        }
        return;
    }
    if (arg0 >= 6) return;
    if (arg0 < 4) {
        fn_8001D5E4();
        return;
    }
    fn_8001D5D8();
}

extern void fn_802E30C8(const char *, ...);
extern const char lbl_802FDB04[];
#pragma scheduling invalid_target
#pragma scheduling on
void fn_8001D728(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        fn_802E30C8(lbl_802FDB04, arg0);
        memset(lbl_8055D5CC + arg0 * 0xDAC4, 0, 0xDAC4);
        ((s32 *)lbl_80358658[arg0])[1] = 0;
        break;
    default:
        break;
    }
}
#pragma scheduling reset
void fn_8001D7A4(void) {

}
#pragma paired off
#pragma paired_single off
#pragma use_lmw_stmw off
#pragma scheduling invalid_target

