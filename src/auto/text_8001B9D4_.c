#include <types.h>

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
#pragma push
#pragma small_data off
extern s32 lbl_803583C8;
#pragma pop
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
extern s32 fn_8001CDB8(s32, s32, s32, s32, s32);

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

void fn_8001B9F4(void) {
    fn_8002F634(&lbl_803583C8, fn_8001BA10, 0x14, 0x10);
}

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

#pragma scheduling off
s32 fn_8001BA90(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp = fn_8001D25C(arg2);
    if (temp != 0) {
        return fn_8001CDB8(arg0, arg1, temp, arg3, arg4);
    }
    return arg4;
}

void fn_8001BB0C(s32 arg0, s32 arg1, volatile s32 arg2, volatile s32 arg3) {
    s32 saved2 = arg2;
    s32 saved3 = arg3;
    fn_8001CE34(arg0, fn_8001D25C(arg1), saved2, saved3);
}

void fn_8001BB58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    volatile register s32 a = arg3;
    volatile register s32 b = arg2;
    fn_8001CE74(arg0, fn_8001D25C(arg1), b, a);
}
#pragma scheduling reset
void fn_8001BBB4(void) {
    fn_8001D020();
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

s32 fn_8001BCF0(void *arg0) {
    s32 var_r5 = 0;
    
    s32 ptr = ((s32 *)arg0)[6] + ((s32 *)arg0)[3] * 0xC;
    
    if (*((u8 **)ptr + 0x10) != 0)
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

#pragma dont_inline on
void fn_8001BD54(Unk8001BBBC *arg0, void *arg1) {
    fn_8001BBBC(arg0, *(s32 *)((u8 *)*(void **)((u8 *)arg1 + 0x18) + *(s32 *)((u8 *)arg1 + 0xC) * 0xC + 0xC));
}
#pragma dont_inline reset
s32 fn_8001BD6C(void *arg0, void *arg1) {
    s32 r3 = ((s32 *)arg0)[6];
    s32 r4 = ((s32 *)arg0)[3];
    s32 r5 = ((s32 *)arg1)[6];
    s32 r6 = ((s32 *)arg1)[3];
    s32 result = fn_8001D2E4(r3, r4, r5, r6);
    return result >> 31;
}

extern void *lbl_80358628;
extern void *fn_800167CC(s32, void *, s32, s32);
extern void *fn_80016BC8(s32);
#pragma push
#pragma small_data off
#pragma pop
void fn_8001BDA8(void *arg0) {
    s32 index;
    void *result;
    void *temp;

    if (*(u8 *)((u8 *)arg0 + 0x20) != 0) {
        if (*(void **)((u8 *)arg0 + 0x18) != &lbl_80358628) {
            index = *(s32 *)((u8 *)arg0 + 0xC);
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x18) + index * 0xC + 8) =
                *(s32 *)((u8 *)arg0 + 0x1C);
            index = *(s32 *)((u8 *)arg0 + 0xC);
            *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x18) + index * 0xC + 0x10) = 1;
            result = fn_800167CC(0, (u8 *)*(void **)((u8 *)arg0 + 0x18) +
                                    *(s32 *)((u8 *)arg0 + 0xC) * 0xC, 1,
                                 *(s32 *)((u8 *)arg0 + 0x1C));
            temp = fn_80016BC8(0);
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x18) +
                     *(s32 *)((u8 *)arg0 + 0xC) * 0xC + 0xC) =
                fn_8001D220(*(u32 *)result, *(u32 *)((u8 *)temp + 4),
                            *(u8 *)((u8 *)temp + 8));
            fn_8001D298(*(s32 *)arg0);
        }
    }
    *(u8 *)((u8 *)arg0 + 0x20) = 0;
}
void fn_8001BE70(void *arg0) {
    s32 index = *(s32 *)((u8 *)arg0 + 0xC);
    s32 base = *(s32 *)((u8 *)arg0 + 0x18);
    *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)(base + index * 0xC + 8);
    *(u8 *)((u8 *)arg0 + 0x20) = 0;
}

void *fn_8001BE94(void *dest, int val, size_t count) {
    fn_8001BC38(dest, val, count);
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
void fn_8001BF0C(f32 arg0) {
    f32 temp = arg0;
    ((void (*)(f32, s32))fn_8001BC28)(arg0, *(s32 *)&temp);
}

void *fn_8001C070(void *dest, int val, size_t count) {
    fn_8001BC38(dest, val, count);
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

s32 fn_8001C200(const char *arg0, const char *arg1) {
    if (stricmp(arg0, arg1) == 0 || stricmp(arg0, "???") == 0 || stricmp(arg1, "???") == 0) {
        return 1;
    }
    return 0;
}

#pragma dont_inline on
s32 fn_8001C27C(void *arg0, u32 arg1, const char *arg2) {
    volatile u32 key = *(volatile u32 *)arg0;
    s32 result = 0;
    if (key == arg1 && fn_8001C200(*(const char **)((u8 *)arg0 + 4), arg2) != 0)
        result = 1;
    return result;
}
#pragma dont_inline reset
s32 fn_8001C2CC(s32 arg0, u32 arg1, const char *arg2, s32 arg3) {
    s32 i = 0;
    s32 offset = 0;
    void *entry;
    void *record;
    for (;;) {
        entry = lbl_80358658[arg0];
        if (i >= *(s32 *)((u8 *)entry + 4)) {
            return 0;
        }
        record = (void *)(*(s32 *)entry + offset);
        if (fn_8001C27C(record, arg1, arg2) != 0) {
            return (s32)record;
        }
        offset += 0x2C;
        i++;
    }
}

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
s32 *fn_8001C4E0(s32 arg0) {
    s32 compare = arg0;
    register s32 *entry = lbl_802ED7B8;
    do {
        if (*entry == compare) {
            return entry;
        }
        entry = (s32 *)((u8 *)entry + 0xC);
    } while (*entry != 0);
    fn_802E317C(lbl_802FD85C);
    return 0;
}

void fn_8001C714(void) {
    fn_80131234(*(s32 *)((u8 *)((s32 *(*)(void))fn_8001C4E0)() + 8));
}

extern s32 *fn_8001C4E0(s32);
extern int stricmp(const char *, const char *);
extern char lbl_802FD6D8[];
extern char lbl_80558CD8[];
extern void *lbl_8055D5D4;
extern void *lbl_8055E050;
s32 fn_8001CB8C(s32 flags, const char *name, void *out) {
    s32 *archive;
    void *node;
    s32 index;
    void **vtable;
    s32 type;
    f32 value;
    if (name == 0) return 0;
    archive = fn_8001C4E0(flags);
    if (archive[1] == 0) return 0;
    index = 0;
    do {
        node = ((void *(*)(void *, s32))((void **)*(void **)lbl_8055D5D4)[3])(lbl_8055D5D4, index);
        if (node == 0) break;
        vtable = *(void ***)node;
        if (stricmp(((const char *(*)(void *))vtable[2])(node), lbl_802FD6D8 + 0x39C) == 0 &&
            stricmp(((const char *(*)(void *, const char *, void *))vtable[6])(node, lbl_802FD6D8 + 0x3AC, lbl_80558CD8), name) == 0 &&
            ((s32 (*)(void *, s32))vtable[3])(node, archive[1]) != 0) break;
        index++;
    } while (1);
    if (node == 0)
        node = ((void *(*)(void *, const char *))((void **)*(void **)lbl_8055D5D4)[2])(lbl_8055D5D4, lbl_802FD6D8 + 0x3BC);
    if (out != 0) {
        type = flags & 0x300;
        if (type == 0x200) *(s32 *)out = ((s32 (*)(void *, s32))((void **)*(void **)node)[7])(node, archive[1]);
        else if (type == 0x100) {
            value = ((f32 (*)(void *, s32))((void **)*(void **)node)[9])(node, archive[1]);
            if ((flags & 0x3F800) == 0x800) value /= *(f32 *)((char *)lbl_8055E050 + 0x10);
            *(f32 *)out = value;
        }
    }
    return 1;
}

#pragma scheduling off
void fn_8001CD4C(s32 arg0, s32 arg1, s32 arg2) {
    void (* volatile init)(void) = fn_8001C4D8;
    init();
    if (((s32 (*)(s32, s32, s32))fn_8001C2CC)(arg0, arg1, arg2) == 0) {
        fn_8001C35C(arg0, arg1, arg2);
    }
}
#pragma scheduling reset
s32 fn_8001CED4(void *arg0, s32 arg1, s32 arg2, f32 arg3) {
    void *ptr = (void *)fn_8001285C(arg1);
    s32 count = *(s32 *)((u8 *)arg0 + 0x6C);
    s32 result = 0;
    if (count > 0 && *(s32 *)((u8 *)arg0 + 8) != 0 &&
        *(s32 *)((u8 *)arg0 + 0xC) >= arg2) {
        do {
            if (*(s32 *)((u8 *)arg0 + 0xC) == arg2) {
                if (*(u32 *)((u8 *)ptr + 8) == 0x18000302) {
                    if (*(f32 *)((u8 *)arg0 + 0x14) <= arg3)
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
#pragma scheduling reset
u32 fn_8001D220(u32 arg0, u32 arg1, u32 arg2) {
    register u32 value = arg0;
    value |= arg2 << 16;
    value |= arg1 << 8;
    return value;
}

void fn_8001D234(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    u32 value = arg0;
    u32 byte = (value >> 16) & 0xFF;
    *arg1 = value & 0xFF;
    *arg2 = (value >> 8) & 0xFF;
    *(s8 *)arg3 = (byte != 0);
}

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
    s32 *a = (s32 *)(arg0 + arg1 * 0xC);
    s32 *b = (s32 *)(arg2 + arg3 * 0xC);
    s32 value = *(s32 *)arg0;
    s32 kind;
    if (*(u8 *)((u8 *)a + 0x10) == 0) return *(u8 *)((u8 *)b + 0x10);
    if (*(u8 *)((u8 *)b + 0x10) == 0) return -1;
    switch (value & 0x300) {
    case 0x100:
        kind = value & 0x60000;
        switch (kind) {
        case 0x20000: return *(f32 *)((u8 *)a + 8) < *(f32 *)((u8 *)b + 8) ? -1 : 1;
        case 0x40000: return *(f32 *)((u8 *)a + 8) > *(f32 *)((u8 *)b + 8) ? -1 : 1;
        default: fn_802E317C(lbl_802FDAAC); return 0;
        }
    case 0x200:
        kind = value & 0x60000;
        switch (kind) {
        case 0x20000: return *(s32 *)((u8 *)a + 8) < *(s32 *)((u8 *)b + 8) ? -1 : 1;
        case 0x40000: return *(s32 *)((u8 *)a + 8) > *(s32 *)((u8 *)b + 8) ? -1 : 1;
        default: fn_802E317C(lbl_802FDAAC); return 0;
        }
    default: fn_802E317C(lbl_802FDAD8); return 0;
    }
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
#pragma pop
void fn_8001D528(void *arg0) {
    s32 var_r27;
    s32 var_r29;
    s32 var_r31;
    u8 *var_r28;
    u8 *var_r30;
    s32 (*callback)(s32);

    callback = (s32 (*)(s32))arg0;
    var_r29 = 0;
    var_r31 = 0;
loop_outer_528:
    var_r27 = 0;
    var_r28 = lbl_8055D5CC + var_r31;
    var_r30 = var_r28;
loop_inner_528:
    if (var_r27 < *(s32 *)(var_r28 + 0x6E00)) {
        *(s32 *)(var_r30 + 4) = callback(*(s32 *)(var_r30 + 4));
        var_r30 += 0x2C;
        var_r27 += 1;
        goto loop_inner_528;
    }
    ((void (*)(void *, s32, s32 (*)(s32)))fn_8001D484)(var_r28 + 0x6E04, 0xF0, callback);
    var_r29 += 1;
    var_r31 += 0xDAC4;
    if (var_r29 < 4) goto loop_outer_528;
    ((void (*)(void *, s32, s32 (*)(s32)))fn_8001D484)(lbl_8055D5CC + 0x36B10, 0xF0, callback);
}

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
#pragma dont_inline reset
void fn_8001D7A4(void) {

}

