#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int lbl_8055FB28, lbl_8055FB2C, lbl_8055FB30, lbl_8055FB34, lbl_8055CFA0;
extern int lbl_8055FB40;
extern char lbl_804C0810[];
extern char lbl_804C0E10[];
extern f32 lbl_8055FB38;
extern f32 lbl_80564E50;
extern char lbl_8034AEF8[], lbl_8034AF04[];
extern int fn_801FB1F4(int);
extern int fn_8012850C(int, const char *);
extern void fn_801D0590(void *);
extern void fn_801D0800(void *);
extern void *memset(void *, int, unsigned int);
void fn_802C1928(void);
void fn_802C1A08(void);
extern void fn_80128670(int);
extern void fn_801D05B4(void *);
extern void fn_801D0824(void *);
extern void fn_802C1180(void *);
extern int fn_802E317C(const char *);
extern char lbl_8034AED0[];
#pragma scheduling invalid_target
void *fn_802C110C(int arg0) {
    char *entry = lbl_804C0810;
    int count = lbl_8055FB28;
    for (; count > 0; --count, entry += 0x60) {
        if (arg0 < *(int *)entry)
            continue;
        if (arg0 <= *(int *)(entry + 4))
            return entry;
    }
    ((int (*)(const char *, ...))fn_802E317C)(lbl_8034AED0, arg0);
    return 0;
}
#pragma scheduling on
void fn_802C1180(void *arg0) {
    volatile int *src = (volatile int *)arg0;
    volatile int *dst = (volatile int *)src[1];
    int zero = 0;
    int a, b;
    if (dst == 0) return;
    b = src[2]; a = src[3]; dst[0] = b; dst[1] = a;
    b = src[4]; a = src[5]; dst[2] = b; dst[3] = a;
    b = src[6]; a = src[7]; dst[4] = b; dst[5] = a;
    b = src[8]; a = src[9]; dst[6] = b; dst[7] = a;
    dst[8] = src[10];
    b = src[11]; a = src[12]; dst[9] = b; dst[10] = a;
    dst[11] = src[13];
    ((int **)lbl_8055FB30)[src[0]] = (int *)src[1];
    src[1] = zero;
}
#pragma scheduling invalid_target
void *fn_802C120C(void) {
    unsigned int nextIndex;
    unsigned int oldIndex;
    unsigned int value;
    void *entry;
    oldIndex = lbl_8055FB34;
    entry = (char *)&lbl_804C0E10 + oldIndex * 0x48;
    nextIndex = oldIndex + 1;
    value = (nextIndex << 29) - (nextIndex >> 31);
    value = ((value << 3) | (value >> 29)) + (nextIndex >> 31);
    lbl_8055FB34 = value;
    fn_802C1180(entry);
    return entry;
}
#pragma scheduling on
void fn_802C126C(void) {
    register char *var_r30;
    int *var_r29;
    unsigned char *var_r4;
    int var_r5;
    unsigned char *var_r6;
    int var_r28, var_r28_2;
    char *call_base;
    int check_value;

    lbl_8055FB2C = 0;
    lbl_8055FB28 = 0;
    lbl_8055CFA0 = fn_801FB1F4(0x1F40);
    lbl_8055FB38 = lbl_80564E50;
    lbl_8055FB30 = fn_8012850C(0x7D00, lbl_8034AEF8);
    fn_801D0590(&lbl_8055FB40);
    call_base = (char *)&lbl_8055FB40;
    check_value = (int)&lbl_8055FB40;
    if (check_value != 0) {
        fn_801D0800(call_base + 4);
    } else {
        goto address_done;
    }
address_done:

    var_r29 = (int *)&lbl_804C0810;
    var_r28 = 0;
    do {
        memset(var_r29, 0, 0x60);
        var_r4 = (unsigned char *)lbl_8034AF04;
        var_r6 = (unsigned char *)((char *)var_r29 + 8);
        var_r5 = 0x20;
        goto copy_string;
decrement_count:
        if (--var_r5 > 0)
            goto copy_string;
        var_r6[-1] = 0;
        goto copied_string;
copy_string:
        if ((signed char)(*var_r6++ = *var_r4++) != 0)
            goto decrement_count;
copied_string:
        var_r28++;
        var_r29 = (int *)((char *)var_r29 + 0x60);
    } while (var_r28 < 0x10);

    var_r30 = (char *)&lbl_804C0E10;
    var_r28_2 = 0;
    do {
        memset(var_r30, 0, 0x48);
        var_r28_2++;
        var_r30 += 0x48;
    } while (var_r28_2 < 8);
    lbl_8055FB34 = 0;
    fn_802C1928();
    fn_802C1A08();
}

#pragma scheduling invalid_target
void fn_802C13A4(void) {
    char *entry;
    int address_check;
    char *base;
    int i;
    int value;

    fn_801D05B4(&lbl_8055FB40);
    address_check = (int)&lbl_8055FB40;
    base = (char *)&lbl_8055FB40;
    if (address_check != 0)
        fn_801D0824(base + 4);

    entry = lbl_804C0810;
    i = 0;
    goto check;
loop:
    value = *(int *)(entry + 0x34);
    if (value != 0)
        fn_80128670(value);
    entry += 0x60;
    i += 1;
check:
    if (i < lbl_8055FB28)
        goto loop;

    fn_80128670(lbl_8055FB30);
    lbl_8055FB30 = 0;
    lbl_8055FB2C = 0;
    lbl_8055FB28 = 0;
}
#pragma scheduling on
extern int fn_801345D8(char *, int, const char *, ...);
extern char lbl_8034AF14[];

extern int lbl_8055FB28;
#pragma use_lmw_stmw off
int fn_802C143C(void *arg0) {
    char buf[0x20];
    int index;
    int *entry;
    u32 i;

    index = lbl_8055FB28;
    entry = (int *)((char *)&lbl_804C0810 + index * 0x60);
    entry[0] = -1;
    *((u8 *)entry + 0x28) = 1;
    lbl_8055FB28 = index + 1;
    entry[0x30 / 4] = (int)arg0;

    i = 0;
    do {
        if (arg0 != NULL) {
            fn_801345D8(buf, 0x20, lbl_8034AF14, i + 1);
            entry[0x40 / 4] =
                ((int (**)(void *, char *, int))(*(void **)arg0))[8](arg0, buf, -1);
        } else {
            entry[0x40 / 4] = -1;
        }
        i++;
        entry++;
    } while (i < 8);
    return index;
}
#pragma use_lmw_stmw reset
int fn_802C1500(int arg0, int arg1) {
    struct Entry {
        int first;
        int second;
        char padding[0x58];
    };
    int index = lbl_8055FB2C;
    struct Entry *entry = (struct Entry *)lbl_804C0810 + arg1;
    int *list = (int *)lbl_8055FB30;
    lbl_8055FB2C = index + 1;
    list[index] = arg0;
    if (entry->first < 0) {
        entry->first = index;
        entry->second = index;
    } else {
        entry->second = index;
    }
    return lbl_8055CFA0 + index;
}
#pragma scheduling on
#pragma optimization_level reset
extern char lbl_8034AED0[];
extern f32 lbl_80564E54, lbl_80564E50, lbl_80564E58;
extern char lbl_8055CFA4[], lbl_8055CFAC[], lbl_8055CFB8[], lbl_8055CFC0[];
__declspec(section ".sdata") extern char lbl_8055CFA4[];
__declspec(section ".sdata") extern char lbl_8055CFAC[];
__declspec(section ".sdata") extern char lbl_8055CFB8[];
__declspec(section ".sdata") extern char lbl_8055CFC0[];
extern void fn_801FA7F4(int, f32 *, void *);
#pragma cplusplus on
extern "C" void fn_802C1550(void) {
    struct Dispatch {
        virtual void u0();
        virtual void u1();
        virtual void u2();
        virtual int getIndex(const char *);
        virtual void u4();
        virtual int getCount(const char *);
        virtual void u6();
        virtual float getValue(const char *);
        virtual void u8();
        virtual void u9();
        virtual int hasFlag(const char *, int);
        virtual void u11();
        virtual void u12();
        virtual void u13();
        virtual void u14();
        virtual void u15();
        virtual void u16();
        virtual void u17();
        virtual void u18();
        virtual void u19();
        virtual void u20();
        virtual Dispatch *find(const char *);
        virtual char *getName(const char *);
    };
    register char *entry = lbl_804C0810;
    register char *strings = lbl_8034AED0;
    register int outer = 0;
    register int zero = 0;
    register f32 diagonal = lbl_80564E54;
    register f32 blank = lbl_80564E50;
    register f32 depth = lbl_80564E58;
    f32 pos[12];

    while (outer < lbl_8055FB28) {
        Dispatch *obj = *(Dispatch **)(entry + 0x30);
        int count;
        int index;
        char *name;
        entry[0x28] = obj->hasFlag(strings + 0x54, 0) == 0;
        obj = obj->find(strings + 0x60);
        if (obj != 0) {
            *(f32 *)(entry + 0x2c) = obj->getValue(strings + 0x6c);
            index = obj->getIndex(lbl_8055CFA4);
            count = obj->getCount(lbl_8055CFAC);
            *(int *)(entry + 0x38) = count;
            *(int *)(entry + 0x3c) = zero;
            *(void **)(entry + 0x34) = (void *)fn_8012850C(count * 4, lbl_8055CFB8);
            memset(*(void **)(entry + 0x34), zero, count * 4);
            name = obj->getName(lbl_8055CFC0);
            {
                char *source = name;
                char *destination = entry + 8;
                int remaining = 0x20;
                while (remaining > 0) {
                    char c = *source++;
                    *destination++ = c;
                    remaining--;
                    if ((signed char)c == 0)
                        break;
                }
                if (remaining == 0)
                    destination[-1] = zero;
            }
            if (count > 0) {
                int item;
                for (item = 0; item < count; item++) {
                    pos[0] = diagonal;
                    pos[1] = blank; pos[2] = blank;
                    pos[3] = blank; pos[4] = diagonal;
                    pos[5] = blank; pos[6] = blank;
                    pos[7] = blank; pos[8] = diagonal;
                    pos[9] = blank; pos[10] = depth; pos[11] = blank;
                    fn_801FA7F4(index, pos, *(void **)(entry + 0x30));
                }
            }
        }
        entry += 0x60;
        outer++;
    }
}
#pragma cplusplus reset
extern f32 lbl_804C1050[16];
extern f32 lbl_80564E58;
extern f32 lbl_80564E70;
extern f32 lbl_80564E74;
extern void fn_802BDFF4(int *);
#pragma use_lmw_stmw off
#pragma paired off
#pragma paired_single off
void fn_802C1928(void) {
    int i;

    {
        f32 zero = lbl_80564E58;
        f32 *values = (f32 *)((char *)&lbl_804C1050 + 4);
        for (i = 0; i < 8; i++)
            values[i * 2] = zero;
    }

    {
        char *entry = (char *)&lbl_804C0E10;
        i = 0;
        do {
            fn_802C1180(entry);
            i++;
            entry += 0x48;
        } while (i < 8);
    }

    {
        register f32 delta = lbl_80564E74;
        register int count = 0;
        register f32 min = lbl_80564E70;
        register int offset = 0;

        goto check;
    loop:
        {
            int *obj = (int *)*(int *)((char *)(int *)lbl_8055FB30 + offset);
            if (*(f32 *)((char *)obj + 0x28) < min) {
                *(f32 *)((char *)obj + 0x28) -= delta;
                ((void (*)(int *, int))fn_802BDFF4)(
                    (int *)*(int *)((char *)(int *)lbl_8055FB30 + offset), 1);
            }
        }
        offset += 4;
        count++;
    check:
        if (count < lbl_8055FB2C)
            goto loop;
    }
}
#pragma paired_single reset
#pragma paired reset
#pragma use_lmw_stmw reset
void fn_802C1A08(void) {}

extern void *fn_8017960C(int);
extern void fn_801796EC(int, void *, int);
#pragma cplusplus on
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma paired off
#pragma paired_single on
extern "C" void fn_802C1A0C(void **arg0, int arg1) {
    struct Dispatch {
        virtual void unk0();
        virtual void unk1();
        virtual void unk2();
        virtual void unk3();
        virtual void call18(int);
        virtual void unk5();
        virtual void unk6();
        virtual int call24();
    };
    struct Params {
        f32 pos[3];
        f32 extra[3];
        s16 id;
        u8 pad[2];
        int item;
    };
    struct Params params;
    int current;
    register char *entry;
    register int index;
    int *record;
    void *target;
    register f32 delta;
    f32 value;
    f32 z;

    entry = lbl_804C0E10;
    for (index = 0; index < 8; index++, entry += 0x48) {
        current = ((Dispatch *)arg0)->call24() - lbl_8055CFA0;
        if (*(int *)(entry + 4) != 0 && *(int *)entry == current)
            fn_802C1180(entry);
    }

    index = ((Dispatch *)arg0)->call24() - lbl_8055CFA0;
    if (index < 0)
        goto done;
    if (index >= lbl_8055FB2C)
        goto done;

    record = (int *)fn_802C110C(index);
    entry = (char *)lbl_8055FB30;
    target = *(void **)(entry + index * 4);
    if (*(f32 *)((char *)target + 0x28) > lbl_80564E70) {
        target = fn_8017960C(arg1);
        params.extra[0] = *(f32 *)((char *)target + 0x118);
        params.extra[1] = *(f32 *)((char *)target + 0x11C);
        params.extra[2] = *(f32 *)((char *)target + 0x120);
        params.id = *(s16 *)((char *)target + 0x6C);
        delta = lbl_80564E54;
        {
            u32 i;
            for (i = 0; i < 8; i++, record++) {
                if (record[0x40 / 4] >= 0) {
                    volatile f32 *pos = params.pos;
                    target = *(void **)(entry + index * 4);
                    value = *(f32 *)((char *)target + 0x24);
                    pos[0] = value;
                    value = *(f32 *)((char *)target + 0x28);
                    pos[1] = value;
                    value += delta;
                    z = *(f32 *)((char *)target + 0x2C);
                    pos[2] = z;
                    pos[1] = value;
                    params.item = record[0x40 / 4];
                    fn_801796EC(10, &params, 0x20);
                }
            }
        }
        target = *(void **)(entry + index * 4);
        *(f32 *)((char *)target + 0x28) += lbl_80564E74;
        ((Dispatch *)arg0)->call18(0);
        ((void (*)(int *, int))fn_802BDFF4)((int *)*(void **)(entry + index * 4), 0);
    }
done:
    ;
}
#pragma cplusplus reset

typedef struct { int a, b; } Pair802C;
