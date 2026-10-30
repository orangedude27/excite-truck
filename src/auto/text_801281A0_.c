#include <types.h>
extern char lbl_8032A05C[];

extern char lbl_8055DF88;
__declspec(section ".data") extern u32 lbl_802F8E40;
extern u32 lbl_80559968;
extern char lbl_8032A430[];
extern char lbl_8032A01C[];
extern u8 lbl_8055DF80;
extern s32 *lbl_8055DF84;
extern s32 lbl_8055DF98;
extern char lbl_8041E140[];
extern s32 lbl_8041E140_s32[];
extern char lbl_8032A000[];
extern char lbl_8032A068[];
extern char lbl_8032A074[];
extern char lbl_8041E160[];
extern s32 lbl_8055DF8C;
extern s32 lbl_8055DF90;
extern s32 lbl_8055DF94;
extern char lbl_8055DF81;
extern char lbl_8032A448[];
void fn_801287D0(void *);

s32 fn_801281F4(s32, s32);
void fn_802E30C8(void *, void *, void *, ...);
s32 fn_802E317C(void *, void *);
void fn_8012834C(void *, void *, s32);
void fn_802E3DF8(s32, void *, void *);
void fn_80128714(void *, s32, s32);
extern void *memset(void *, int, unsigned long);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

u32 fn_801281A0(s32 arg0) {
    u32 vals[4];
    u32 *p = (u32 *)&lbl_802F8E40;
    vals[0] = *p++;
    vals[1] = *p++;
    vals[2] = *p++;
    vals[3] = *p;
    if (arg0 >= 0 && (u32)arg0 < 4) return vals[arg0];
    return (u32)&lbl_80559968;
}

#pragma scheduling off
s32 fn_801281F4(s32 arg0, s32 arg1) {
    return ((arg0 + arg1) - 1) & ~(arg1 - 1);
}
#pragma scheduling on
void fn_80128208(void) {

}

extern char lbl_8032A01C[];
extern u32 lbl_802F8E40;
extern u32 lbl_80559968;
extern char lbl_8032A430[];
void fn_8012820C(void) {
    s32 sp14, sp10, spC, sp8;
    s32 zero, one;
    ((void (*)(char *))fn_80128208)(lbl_8032A01C);
    zero = 0; one = 1;
    lbl_8055DF8C = zero;
    sp10 = zero; sp8 = zero;
    lbl_8055DF90 = one;
    fn_802E3DF8(0, &sp14, &spC);
    fn_802E3DF8(1, &sp10, &sp8);
    fn_80128714(&lbl_8041E140, sp14, spC);
    fn_80128714(&lbl_8041E160, sp10, sp8);
    lbl_8055DF94 = sp14;
    (void)one;
}

extern void fn_80128710(void);
#pragma dont_inline on
void fn_801282A0(void) {
    fn_801287D0(&lbl_8041E140);
    fn_801287D0(&lbl_8041E160);
    ((void (*)(s32))fn_80128710)(lbl_8055DF94);
    lbl_8055DF94 = 0;
    lbl_8055DF90 = 0;
}
#pragma dont_inline reset

void fn_801282E8(void) {

}

void fn_801282EC(s32 arg0) { lbl_8055DF8C = arg0; }

void fn_801282F4(void) {
    s32 value = ((s32 *)lbl_8041E160)[2];
    lbl_8055DF81 = (u32)((-value) & ~value) >> 31;
}

s32 fn_80128314(s32 arg0) {
    if (arg0 == 0) return ((s32 *)lbl_8041E140)[1];
    if (arg0 == 1) return ((s32 *)lbl_8041E160)[1];
    return 0;
}

extern char lbl_8032A034[];
s32 fn_80127964(void);
void *fn_801288AC(void *, s32, char *, s32);
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void fn_8012834C(void *arg0, void *arg1, s32 arg2) {
    struct Ring {
        virtual void d0();
        virtual void d1();
        virtual void *alloc(s32, void *, s32);
    };
    void *queue;
    void *result;
    s32 sum;
    s32 mask;
    s32 size;
    s32 offset;

    fn_80127964();
    if (lbl_8055DF80 == 0 && (u8)lbl_8055DF88 != 0) {
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A034, arg0);
    }

    size = lbl_8055DF8C;
    if (size != 0) {
        if ((u8)lbl_8055DF81 == 0) {
            if (size > 0x40) {
                queue = lbl_8041E140;
                mask = size - 1;
                sum = *(s32 *)((u8 *)queue + 0xC) +
                      *(s32 *)((u8 *)queue + 4);
                if (((sum + 0x40) & mask) != 0) {
                    mask = mask & (size - ((sum + 0x80) & mask));
                    result = ((Ring *)queue)->alloc(mask, lbl_8032A05C, 3);
                    *(u8 *)((u8 *)result - 0x1C) = 0;
                }
            }
        } else if (size > 0x40) {
            queue = lbl_8041E160;
            mask = size - 1;
            sum = *(s32 *)((u8 *)queue + 0xC) +
                  *(s32 *)((u8 *)queue + 4);
            if (((sum + 0x40) & mask) != 0) {
                mask = mask & (size - ((sum + 0x80) & mask));
                result = ((Ring *)queue)->alloc(mask, lbl_8032A05C, 3);
                *(u8 *)((u8 *)result - 0x1C) = 0;
            }
        }
        lbl_8055DF8C = 0;
    }

    if ((u8)lbl_8055DF81 != 0) {
        ((void *(*)(void *, void *, void *, s32))fn_801288AC)(
            lbl_8041E160, arg1, arg0, arg2);
    } else {
        ((void *(*)(void *, void *, void *, s32))fn_801288AC)(
            lbl_8041E140, arg1, arg0, arg2);
    }
    lbl_8055DF81 = 0;
}
#pragma scheduling on
#pragma cplusplus off

s32 fn_801284E8(void *arg0, void *arg1) {
    fn_8012834C(arg0, arg1, 1);
}

void fn_801284F0(void *arg0, void *arg1) {
    fn_8012834C(arg0, arg1, 2);
}

void fn_801284F8(void *arg0, void *arg1) {
    fn_8012834C(arg1, arg0, 3);
}

void fn_8012850C(void *arg0, void *arg1) {
    fn_8012834C(arg1, arg0, 0);
}

#pragma scheduling off
s32 fn_80128520(s32 arg0) {
    if (lbl_8055DF80 == 0)
        goto do_log;
    if (*(volatile s32 **)&lbl_8055DF84 == NULL) {
        fn_8012834C(lbl_8032A068, (void *)arg0, 3);
        goto done;
    }
    goto do_log;
do_log:
    ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A074, arg0);
done:
    return lbl_8055DF98;
}

extern char lbl_8032A0A0[];
void fn_80128AA4(void *, u8 *, s32, s32);
#pragma dont_inline on
#pragma scheduling invalid_target
void fn_80128584(s32 arg0, s32 arg1) {
    s32 var_r4;
    u32 start;
    u32 end;
    if (((s32)lbl_8055DF80 == 0) || (arg0 != 0)) {
        fn_80127964();
        if (((s32)lbl_8055DF80 == 0) && ((u8)lbl_8055DF88 != 0))
            ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A0A0);
        var_r4 = 0;
        start = *(u32 *)(lbl_8041E140 + 0xC);
        if ((u32)arg0 >= start) {
            end = start + *(u32 *)(lbl_8041E140 + 8);
            if ((u32)arg0 < end)
                var_r4 = 1;
        }
        if (var_r4 != 0) {
            ((void (*)(void *, u8 *, s32))fn_80128AA4)(lbl_8041E140, (u8 *)arg0, arg1);
            return;
        }
        ((void (*)(void *, u8 *, s32))fn_80128AA4)(lbl_8041E160, (u8 *)arg0, arg1);
    }
}
#pragma scheduling on
#pragma dont_inline reset

#pragma scheduling on
void fn_80128678(void) {
    lbl_8055DF88 = 1;
}

extern char lbl_8055DF88;
void fn_80128684(void) {
    lbl_8055DF88 = 0;
}

s32 fn_80128690(void) {
    u8 val = lbl_8055DF88;
    u32 shifted;
    shifted = __cntlzw(val);
    return shifted >> 5;
}

void fn_80128710(void) {

}

const char* __AXGetStudio_80129164(void) {
    return lbl_8032A068;
}

s32 fn_80129170(void *arg0, u32 arg1) {
    u32 end = ((u32 *)arg0)[1];
    s32 result = 0;
    if (arg1 >= end && arg1 < end + ((u32 *)arg0)[3]) {
        result = 1;
    }
    return result;
}

s32 fn_8012919C(void *arg0) { return ((s32 *)arg0)[2]; }

s32 fn_801291A4(void *arg0) { return ((s32 *)arg0)[3] - ((s32 *)arg0)[2]; }

s32 fn_801291B4(void *arg0) { return ((s32 *)arg0)[3]; }

void fn_801291BC(void) {

}

void fn_801291C0(void) {

}

void fn_801291C4(void) {

}

s32 fn_801291C8(void *arg0, u32 arg1) {
    u32 end = ((u32 *)arg0)[3];
    s32 result = 0;
    if (arg1 >= end) {
        u32 limit = end + ((u32 *)arg0)[2];
        if (arg1 < limit) result = 1;
    }
    return result;
}

s32 fn_801291F4(void *arg0) { return ((s32 *)arg0)[1]; }

s32 fn_801291FC(void *arg0) {
    return ((s32 *)arg0)[2] - ((s32 *)arg0)[1];
}

s32 fn_8012920C(void *arg0) { return ((s32 *)arg0)[2]; }

void fn_80129214(void) {

}

void fn_80129218(void) {

}

#pragma scheduling invalid_target
void fn_8012921C(void *arg0, s32 arg1) {
    register s32 mask;
    register s32 sum;
    s32 offset;
    void *result;
    if (arg1 <= 0x40)
        return;
    mask = arg1 - 1;
    sum = *(s32 *)((u8 *)arg0 + 0xC) + *(s32 *)((u8 *)arg0 + 4);
    if (((sum + 0x40) & mask) == 0)
        return;
    offset = mask & (arg1 - ((sum + 0x80) & mask));
    result = ((void *(*)(void *, s32, void *, s32))(*(void **)((u8 *)*(void **)arg0 + 0x10)))(arg0, offset, lbl_8032A05C, 3);
    *(u8 *)((u8 *)result - 0x1C) = 0;
}
#pragma scheduling on
void fn_80128584(s32, s32);

void fn_80128658(s32 arg0) {
    fn_80128584(arg0, 1);
}

void fn_80128660(s32 arg0) { fn_80128584(arg0, 2); }

void fn_80128668(s32 arg0) {
    fn_80128584(arg0, 3);
}

void fn_80128670(s32 arg0) {
    fn_80128584(arg0, 0);
}

#pragma scheduling invalid_target
void fn_801286A0(void *arg0, s32 arg1) {
    s32 *base = (s32 *)arg0;
    s32 aligned = arg1 & ~0x3F;
    s32 offset;
    u32 magic;
    base[-6] -= aligned;
    base[-5] -= aligned;
    ((s32 *)lbl_8041E140)[1] -= aligned;
    offset = ((s32 (*)(s32, s32))fn_801281F4)(base[-5], 4);
    magic = 0x53544B41;
    *(u32 *)((u8 *)base + offset) = magic;
}
#pragma scheduling on
void fn_80128714(void *arg0, s32 arg1, s32 arg2) {
    s32 *obj = (s32 *)arg0;
    char *base = lbl_8032A000;
    s32 zero = 0;

    obj[2] = arg2;
    obj[1] = zero;
    obj[4] = zero;
    obj[3] = arg1;

    if (arg1 != 0) {
        fn_802E30C8(base + 0xE8, (void *)arg1, (void *)arg2);
        fn_802E30C8(base + 0x10C, &obj[3], (void *)(obj[3] + obj[2]));
        obj[7] = zero;
        obj[6] = zero;
        obj[5] = 0x200;
        return;
    }

    if (arg2 == 0) {
        obj[7] = zero;
        obj[6] = zero;
        return;
    }

    {
        s32 shifted = arg2 >> 10;
        fn_802E317C(base + 0x130, (void *)(shifted + (shifted >> 31)));
    }
    obj[7] = zero;
    obj[6] = zero;
}

void fn_801287D0(void *arg0) {
    u32 *p = (u32 *)arg0;
    u32 *vtable;
    s32 value;

    fn_802E30C8(lbl_8032A000 + 0x140, (void *)((*(s32 *)(p + 5)) >> 10), (void *)p[7]);
    fn_802E30C8(lbl_8032A000 + 0x178, (void *)p[6], (void *)((p[7] - p[6]) >> 10));
    fn_802E30C8(lbl_8032A000 + 0x1AC, (void *)((*(s32 *)(p + 2) - *(s32 *)(p + 5)) >> 10), 0);
    if (p[1] != 0) {
        vtable = *(u32 **)arg0;
        ((void (*)(void *, s32))vtable[14])(arg0, 1);
        fn_802E317C(lbl_8032A000 + 0x1C8, (void *)p[1]);
    }
    p[3] = 0;
}

s32 fn_801288A4(void) {
    return 0;
}

extern char lbl_8032A1F8[];
extern char lbl_8032A204[];
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void *fn_801288AC(void *arg0, s32 arg1, char *arg2, s32 arg3) {
    s32 size = ((s32 (*)(s32, s32))fn_801281F4)(arg1, 0x40);
    void *found = ((void *(*)(void *, s32))fn_801288A4)(arg0, size);
    void *record;
    u8 *start;
    u8 *p;
    s32 limit;
    s32 rounded;
    if (found != NULL) {
        sprintf((char *)found + 4, lbl_8032A1F8, arg2, size);
        *((u8 *)found + 0x24) = 1;
        return (u8 *)found + 0x40;
    }
    limit = size + *(s32 *)((u8 *)arg0 + 4) + 0x40;
    if (limit >= *(s32 *)((u8 *)arg0 + 8)) {
        void **vtable = *(void ***)arg0;
        ((void (*)(void *, s32))vtable[14])(arg0, 1);
        ((s32 (*)(void *, ...))fn_802E317C)(lbl_8032A204, arg2, size);
    }
    record = (u8 *)*(void **)((u8 *)arg0 + 0xC) + *(s32 *)((u8 *)arg0 + 4);
    memset(record, 0, 0x40);
    strcpy((char *)record + 4, arg2);
    *((u8 *)record + 0x24) = 1;
    *(s32 *)((u8 *)record + 0x30) = arg3;
    *(s32 *)((u8 *)record + 0x28) = size;
    *(s32 *)((u8 *)record + 0x2C) = arg1;
    *(u32 *)record = 0x53544B41;
    *(void **)((u8 *)record + 0x34) = *(void **)((u8 *)arg0 + 0x10);
    *(u32 *)((u8 *)record + 0x3C) = 0x53544B41;
    *(void **)((u8 *)arg0 + 0x10) = record;
    start = (u8 *)record + 0x40;
    memset(start, 0xE3, size);
    p = start + *(s32 *)((u8 *)record + 0x2C);
    do {
        *p++ = 0xE3;
        rounded = ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)((u8 *)record + 0x2C), 4);
    } while (p < start + rounded);
    limit = size + *(s32 *)((u8 *)arg0 + 4) + 0x40;
    *(s32 *)((u8 *)arg0 + 4) = limit;
    if (limit < *(s32 *)((u8 *)arg0 + 8)) {
        rounded = ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)((u8 *)record + 0x2C), 4);
        *(u32 *)(start + rounded) = 0x53544B41;
    }
    if (*(s32 *)((u8 *)arg0 + 0x14) < limit) *(s32 *)((u8 *)arg0 + 0x14) = limit;
    if (start + size >= *(u8 **)((u8 *)arg0 + 0x1C)) *(u8 **)((u8 *)arg0 + 0x1C) = start + size;
    if (start < *(u8 **)((u8 *)arg0 + 0x18)) *(u8 **)((u8 *)arg0 + 0x18) = start;
    return start;
}
#pragma scheduling on
#pragma use_lmw_stmw on
u32 fn_801281A0(s32);
void fn_80128AA4(void *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u32 magic = *(u32 *)(arg1 - 0x40);
    u8 *p;
    char *text = lbl_8032A000;
    u8 *base = arg1 - 0x40;
    void *entry;

    if (magic != 0x53544B41)
        ((s32 (*)(void *, ...))fn_802E317C)(text + 0x228, base);

    if (*(u32 *)(arg1 + ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)(arg1 - 0x14), 4)) != 0x53544B41)
        ((s32 (*)(void *, ...))fn_802E317C)(text + 0x244, base + 4);

    p = arg1 + *(s32 *)(base + 0x2C);
    while (p < arg1 + ((s32 (*)(s32, s32))fn_801281F4)(*(s32 *)(base + 0x2C), 4)) {
        if (*p != 0xE3)
            ((s32 (*)(void *, ...))fn_802E317C)(
                text + 0x278, p, p - (arg1 + *(s32 *)(base + 0x2C)), base + 4, 0xE3);
        p++;
    }

    if (*(u32 *)(base + 0x3C) != 0x53544B41)
        ((s32 (*)(void *, ...))fn_802E317C)(text + 0x2C8, base + 4);
    if (base[0x24] == 0)
        ((s32 (*)(void *, ...))fn_802E317C)(text + 0x304, base + 4);
    if (*(s32 *)(base + 0x30) != arg2) {
        u32 newname = ((u32 (*)(s32))fn_801281A0)(arg2);
        u32 oldname = ((u32 (*)(s32))fn_801281A0)(*(s32 *)(base + 0x30));
        ((s32 (*)(void *, ...))fn_802E317C)(text + 0x31C, base + 4, oldname, newname);
    }

    entry = *(void **)((u8 *)arg0 + 0x10);
    base[0x24] = 0;
    while (entry != 0 && *(u8 *)((u8 *)entry + 0x24) == 0) {
        *(void **)((u8 *)arg0 + 0x10) = *(void **)((u8 *)entry + 0x34);
        *(void **)((u8 *)entry + 0x34) = 0;
        entry = *(void **)((u8 *)arg0 + 0x10);
    }
    if (entry != 0)
        *(u32 *)((u8 *)arg0 + 4) =
            ((u8 *)entry - *(u8 **)((u8 *)arg0 + 0xC)) +
            *(u32 *)((u8 *)entry + 0x28) + 0x40;
    else
        *(u32 *)((u8 *)arg0 + 4) = 0;
}

extern int strcmp(const char *, const char *);
extern char lbl_80559970, lbl_80559974;
void fn_80128C5C(void *arg0, int arg1, int arg2) {
    register char *text = lbl_8032A000;
    int used;
    int count;
    int offset;
    int equal;
    int useAlt;
    void *message;
    if ((arg1 & 1) != 0) {
        ((void (*)(void *, ...))fn_802E30C8)(text + 0x348);
        offset = 0;
        used = 0;
        count = 0;
        goto check;
    loop:
        {
            char *record = *(char **)((char *)arg0 + 0xC) + offset;
            if (*(unsigned int *)record != 0x53544B41)
                ((void (*)(void *, ...))fn_802E317C)(text + 0x380, record);
            equal = !strcmp(record + 4, text + 0x5C);
            useAlt = 0;
            if (*(unsigned char *)(record + 0x24) != 0) {
                if (equal == 0)
                    useAlt = 1;
            }
            message = useAlt ? (void *)&lbl_80559970 : (void *)&lbl_80559974;
            fn_802E30C8(text + 0x394, message,
                        record + 4, (void *)*(int *)(record + 0x28), record);
            if (*(unsigned char *)(record + 0x24) == 0)
                used += *(int *)(record + 0x28) + 0x40;
            count++;
            offset += *(int *)(record + 0x28) + 0x40;
            if ((offset & 0x1F) == 0)
                fn_802E2D74(1);
        }
    check:
        if (offset < *(int *)((char *)arg0 + 4))
            goto loop;
        fn_802E30C8(text + 0x3B4,
                    (void *)(*(int *)((char *)arg0 + 4) / 1024),
                    (void *)(*(int *)((char *)arg0 + 8) / 1024),
                    (void *)((*(int *)((char *)arg0 + 8) - *(int *)((char *)arg0 + 4)) / 1024),
                    (void *)(used / 1024));
        ((void (*)(void *, ...))fn_802E30C8)(text + 0x3E8, (void *)count);
        ((void (*)(void *, ...))fn_802E30C8)(text + 0x3F8);
    }
}

void fn_80128DCC(void *arg0) {
    register s32 *base = (s32 *)arg0;
    register s32 offset = 0;
    register s32 *entry;
    goto check;
loop:
    entry = (s32 *)(base[3] + offset);
    if ((u32)entry[0] != 0x53544B41)
        ((s32 (*)(const char *, ...))fn_802E317C)(lbl_8032A430, entry);
    offset = offset + entry[10] + 0x40;
check:
    if (offset < base[1])
        goto loop;
}

s32 fn_80128E58(void *arg0, s32 arg1) {
    s32 aligned = ((s32 (*)(s32, s32))fn_801281F4)(arg1, 0x40);
    s32 end = *(s32 *)((u8 *)arg0 + 8);
    s32 result;
    if (*(s32 *)((u8 *)arg0 + 4) < end - aligned)
        result = *(s32 *)((u8 *)arg0 + 0xC) + end - aligned;
    else
        result = 0;
    return result;
}

void *fn_80128EB4(void *arg0, void *arg1) {
    if ((u32)*(s32 *)((u8 *)arg1 - 0x40) != 0x53544B41U) {
        return &lbl_8032A068;
    }
    return (u8 *)arg1 - 0x3C;
}

void fn_80128ED8(void *arg0, s32 arg1, s32 arg2) {
    s32 *p = (s32 *)arg0;
    p[1] = arg1;
    p[2] = 0;
    p[3] = arg2;
    p[4] = 0;
}

void fn_80128EF0(void *arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r30;
    u32 var_r6;
    temp_r30 = *(s32 *)((u8 *)arg0 + 8);
    var_r6 = arg1 - (temp_r30 & (arg1 - 1));
    if (var_r6 < 0x30U) var_r6 += arg1;
    temp_r31 = *(s32 *)((u8 *)arg0 + 4);
    ((void (*)(void *, s32, void *, s32))(*(void **)((u8 *)*(void **)arg0 + 0x10)))(arg0, var_r6 - 0x30, &lbl_8032A05C, 3);
    *(u32 *)(temp_r31 + temp_r30) = 0x06630216;
}

void fn_80128F68(void *arg0) {
    s32 *p = (s32 *)arg0;
    s32 a = p[4];
    s32 b = p[3];
    fn_802E30C8(&lbl_8032A448, (void *)a, (void *)b);
}

extern s32 fn_801281F4(s32, s32);
extern s32 fn_802E317C(void *, void *);
extern char lbl_8032A470[];
void *fn_80128F94(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    register u32 *header = (u32 *)arg0;
    register void *logArg = arg2;
    s32 size = ((s32 (*)(s32, s32))fn_801281F4)(arg1, 0x10);
    s32 total = size + 0x20;
    if (header[2] + total > header[3]) {
        ((void (*)(void *, ...))fn_802E317C)(lbl_8032A470, logArg, size / 1024);
    }
    {
        u32 used = header[2];
        u8 *start = (u8 *)header[1];
        u8 *base = start + used;
        u8 *result = base + 0x10;
        *(u32 *)(start + used) = 0xAAAA5555;
        *(s32 *)(base + 4) = arg3;
        *(u32 *)(result + size) = 0xFEEDFACE;
        *(s32 *)(result + size + 4) = size;
        header[2] = header[2] + total;
        memset(result, 0xE3, size);
        if (header[2] > header[4]) header[4] = header[2];
        return result;
    }
}

#pragma dont_inline on
void fn_80129088(void *arg0) {
    s32 *candidate;
    s32 base;
    void *end;
    while (*(volatile s32 *)((u8 *)arg0 + 8) > 0) {
        base = *(s32 *)((u8 *)arg0 + 4);
        end = (void *)(base + *(s32 *)((u8 *)arg0 + 8));
        candidate = (s32 *)((u8 *)end - 0x20 - *(s32 *)((u8 *)end - 0xC));
        if ((u32)*candidate + 0x55560000U == 0x5555U)
            return;
        *(s32 *)((u8 *)arg0 + 8) = (s32)((u8 *)candidate - (u8 *)base);
    }
}
#pragma dont_inline reset

void fn_801290CC(void *arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 - 0x10) = 0x06630216;
    fn_80129088(arg0);
}

s32 fn_801290DC(void *arg0, s32 arg1) {
    s32 aligned = ((s32 (*)(s32, s32))fn_801281F4)(arg1, 0x40);
    s32 end = *(s32 *)((u8 *)arg0 + 0xC);
    s32 result;
    if (*(s32 *)((u8 *)arg0 + 8) < end - aligned)
        result = *(s32 *)((u8 *)arg0 + 4) + end - aligned;
    else
        result = 0;
    return result;
}

extern char lbl_8032A498[];
#pragma scheduling invalid_target
void fn_80129138(void *arg0) {
    fn_802E30C8(lbl_8032A498,
        (void *)(*(s32 *)((u8 *)arg0 + 8) / 1024),
        (void *)(*(s32 *)((u8 *)arg0 + 0xC) / 1024));
}
#pragma scheduling on
