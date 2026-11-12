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
    struct Pair { int a; int b; };
    int *src = (int *)arg0;
    int *dst = (int *)src[1];
    struct Pair *s = (struct Pair *)src;
    struct Pair *d = (struct Pair *)dst;
    if (dst == 0) {
        return;
    }
    d[0] = s[1];
    d[1] = s[2];
    d[2] = s[3];
    d[3] = s[4];
    dst[8] = src[10];
    *(struct Pair *)(dst + 9) = *(struct Pair *)(src + 11);
    dst[11] = src[13];
    ((int **)lbl_8055FB30)[src[0]] = (int *)src[1];
    src[1] = 0;
}
#pragma scheduling on
void *fn_802C120C(void) {
    unsigned int oldIndex;
    unsigned int nextIndex;
    unsigned int leftPart;
    unsigned int rightPart;
    unsigned int value;
    void *entry;
    oldIndex = lbl_8055FB34;
    entry = (char *)&lbl_804C0E10 + oldIndex * 0x48;
    nextIndex = oldIndex + 1;
    leftPart = nextIndex << 29;
    rightPart = nextIndex >> 31;
    value = leftPart - rightPart;
    value = ((value << 3) | (value >> 29)) + rightPart;
    lbl_8055FB34 = value;
    fn_802C1180(entry);
    return entry;
}
#pragma scheduling invalid_target
void fn_802C126C(void) {
    register char *var_r30;
    int *var_r29;
    unsigned char *var_r4;
    int var_r5;
    unsigned char *var_r6;
    int var_r28, var_r28_2;
    char *check_base, *call_base;

    lbl_8055FB2C = 0;
    lbl_8055FB28 = 0;
    lbl_8055CFA0 = fn_801FB1F4(0x1F40);
    lbl_8055FB38 = lbl_80564E50;
    lbl_8055FB30 = fn_8012850C(0x7D00, lbl_8034AEF8);
    fn_801D0590(&lbl_8055FB40);
    call_base = (char *)&lbl_8055FB40;
    check_base = (char *)&lbl_8055FB40;
    if ((int)check_base != 0)
        fn_801D0800(call_base + 4);

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
    int next;
    index = lbl_8055FB28;
    entry = (int *)((char *)&lbl_804C0810 + index * 0x60);
    entry[0] = -1;
    next = index + 1;
    lbl_8055FB28 = next;
    *((u8 *)entry + 0x28) = 1;
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
int fn_802C1500(int arg0, int arg1) {
    struct Entry {
        int first;
        int second;
        char padding[0x58];
    };
    int index = lbl_8055FB2C;
    int *list = (int *)lbl_8055FB30;
    lbl_8055FB2C = index + 1;
    list[index] = arg0;
    if (((struct Entry *)lbl_804C0810)[arg1].first < 0) {
        ((struct Entry *)lbl_804C0810)[arg1].first = index;
        ((struct Entry *)lbl_804C0810)[arg1].second = index;
    } else {
        ((struct Entry *)lbl_804C0810)[arg1].second = index;
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
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma paired off
extern "C" void fn_802C1550(void) {
    struct Dispatch {
        virtual void u0();
        virtual void u1();
        virtual void u2();
        virtual char *getResource(const char *);
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
    };
    char *strings = lbl_8034AED0;
    char *entry = lbl_804C0810;
    int outer = 0;
    int zero = 0;
    register f32 depth;
    register f32 blank;
    register f32 diagonal;
    f32 pos[12];
    diagonal = lbl_80564E54;
    blank = lbl_80564E50;
    depth = lbl_80564E58;
    while (outer < lbl_8055FB28) {
        Dispatch *obj;
        int count;
        char *index;
        char *name;
        entry[0x28] = ((Dispatch *)*(void **)(entry + 0x30))->hasFlag(strings + 0x54, zero) == zero;
        obj = ((Dispatch *)*(void **)(entry + 0x30))->find(strings + 0x60);
        if (obj != 0) {
            *(f32 *)(entry + 0x2c) = obj->getValue(strings + 0x6c);
            index = obj->getResource(lbl_8055CFA4);
            count = obj->getCount(lbl_8055CFAC);
            *(int *)(entry + 0x38) = count;
            *(int *)(entry + 0x3c) = zero;
            {
                void *buffer = (void *)fn_8012850C(count * 4, lbl_8055CFB8);
                *(void **)(entry + 0x34) = buffer;
                memset(buffer, zero, *(int *)(entry + 0x38) * 4);
            }
            name = ((Dispatch *)*(void **)(entry + 0x30))->getResource(lbl_8055CFC0);
            {
                char *source = name;
                char *destination = entry + 8;
                int remaining = 0x20;
                char c;
                for (;;) {
                    remaining--;
                    if (remaining == 0) {
                        destination[-1] = zero;
                        break;
                    }
                    c = *source++;
                    *destination++ = c;
                    if ((signed char)c == 0)
                        break;
                }
            }
            if (count <= 0)
                goto next_entry;
            {
                int item = 0;
                do {
                    pos[0] = diagonal;
                    pos[1] = blank; pos[2] = blank;
                    pos[3] = blank; pos[4] = diagonal;
                    pos[5] = blank; pos[6] = blank;
                    pos[7] = blank; pos[8] = diagonal;
                    pos[9] = blank; pos[10] = depth; pos[11] = blank;
                    fn_801FA7F4((int)index, pos, *(void **)(entry + 0x30));
                    item++;
                } while (item < count);
            }
        }
    next_entry:
        entry += 0x60;
        outer++;
    }
}
#pragma pop
extern f64 sin(f32);
extern void fn_8022FF10(void *, void *);
extern void fn_80015B20(void *, void *, void *);
extern f32 lbl_80564E50, lbl_80564E54, lbl_80564E5C, lbl_80564E60;
extern f32 lbl_80564E64, lbl_80564E68, lbl_80564E6C;
#pragma push
#pragma processor 750
#pragma paired_single off
void fn_802C173C(float time) {
    struct Scratch { f32 vec[3]; f32 rot[3]; char padding[0x18]; int data[12]; };
    register f32 scaleBase, base, slope, angle, min, upper, lower;
    volatile char *record;
    int i;
    lbl_8055FB38 = time;
    min = lbl_80564E50; angle = lbl_80564E64; slope = lbl_80564E68;
    base = lbl_80564E54; scaleBase = lbl_80564E6C;
    upper = lbl_80564E60; lower = lbl_80564E5C;
    record = lbl_804C0E10; i = 0;
    do {
        if (*(volatile int *)(record + 4) != 0) {
            f32 age = lbl_8055FB38 - *(volatile f32 *)(record + 0x44);
            if (age >= lower && age < upper) {
                struct Scratch scratch;
                int d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0;
                f32 factor, scaledSin, delta, z, y, x, product, sn, clamped;
                d0 = *(volatile int *)(record + 8);
                d1 = *(volatile int *)(record + 0xC);
                d2 = *(volatile int *)(record + 0x10);
                d3 = *(volatile int *)(record + 0x14);
                d4 = *(volatile int *)(record + 0x18);
                d5 = *(volatile int *)(record + 0x1C);
                d6 = *(volatile int *)(record + 0x20);
                d7 = *(volatile int *)(record + 0x24);
                d8 = *(volatile int *)(record + 0x28);
                d9 = *(volatile int *)(record + 0x2C);
                d10 = *(volatile int *)(record + 0x30);
                d11 = *(volatile int *)(record + 0x34);
                scratch.data[0] = d0; scratch.data[1] = d1; scratch.data[2] = d2;
                scratch.data[3] = d3; scratch.data[4] = d4; scratch.data[5] = d5;
                scratch.data[6] = d6; scratch.data[7] = d7; scratch.data[8] = d8;
                scratch.data[9] = d9; scratch.data[10] = d10; scratch.data[11] = d11;
                clamped = age > min ? age : min;
                sn = (f32)sin(angle * clamped);
                x = *(volatile f32 *)(record + 0x38);
                product = age * slope;
                y = *(volatile f32 *)(record + 0x3C);
                z = *(volatile f32 *)(record + 0x40);
                delta = base - product;
                scaledSin = scaleBase * sn;
                factor = delta * scaledSin;
                scratch.vec[0] = x * factor;
                scratch.vec[1] = y * factor;
                scratch.vec[2] = z * factor;
                fn_8022FF10(scratch.rot, scratch.vec);
                fn_80015B20(scratch.data, scratch.data, scratch.rot);
                {
                    volatile int *dst = (volatile int *)*(volatile int *)(record + 4);
                    register int out1;
                    register int out0;
                    out0 = scratch.data[0]; out1 = scratch.data[1];
                    dst[0] = out0; dst[1] = out1;
                    out0 = scratch.data[2]; out1 = scratch.data[3];
                    dst[2] = out0; dst[3] = out1;
                    out0 = scratch.data[4]; out1 = scratch.data[5];
                    dst[4] = out0; dst[5] = out1;
                    out0 = scratch.data[6]; out1 = scratch.data[7];
                    dst[6] = out0; dst[7] = out1;
                    out0 = scratch.data[8];
                    dst[8] = out0;
                    out0 = scratch.data[9]; out1 = scratch.data[10];
                    dst[9] = out0; dst[10] = out1;
                    out0 = scratch.data[11];
                    dst[11] = out0;
                }
            } else fn_802C1180((void *)record);
        }
        i = i + 1;
        record = record + 0x48;
    } while (i < 8);
}
#pragma pop
extern f32 lbl_804C1050[16];
extern f32 lbl_80564E58;
extern f32 lbl_80564E70;
extern f32 lbl_80564E74;
extern void fn_802BDFF4(int *);
#pragma push
#pragma processor 750
void fn_802C1928(void) {
    {
        f32 zero = lbl_80564E58;
        f32 *values = (f32 *)((char *)&lbl_804C1050 + 4);
        values[0] = zero;
        values[2] = zero;
        values[4] = zero;
        values[6] = zero;
        values[8] = zero;
        values[10] = zero;
        values[12] = zero;
        values[14] = zero;
    }
    {
        char *entry = (char *)&lbl_804C0E10;
        int j = 0;
        do {
            fn_802C1180(entry);
            j++;
            entry += 0x48;
        } while (j < 8);
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
#pragma pop
void fn_802C1A08(void) {}

/* ---- treehit: the trees the trucks drive into ------------------------------
 * lbl_804C0810  the tree classes (fn_802C143C adds one per level object,
 *               fn_802C1550 fills them in from the object's parameters,
 *               count lbl_8055FB28, looked up by tree index in fn_802C110C)
 * lbl_8055FB30  the tree list (heap block "treehittree", lbl_8034AEF8),
 *               count lbl_8055FB2C; fn_802C1500 appends a tree to it
 * lbl_8055CFA0  base of the tree handles fn_801500 hands out: handle - base is
 *               the index in the tree list, which is what the level objects
 *               report when something hits them
 * lbl_804C0E10  the eight queued hits (ring, next slot lbl_8055FB34); fn_802C1C34
 *               queues one, fn_802C1180 hands its pose back to the tree and
 *               fn_802C173C swings the tree about the hit axis (time lbl_8055FB38)
 * lbl_80564E50 / lbl_80564E54  0.0f / 1.0f
 * lbl_80564E70  -2000.0f: a tree whose Y is under it has been cut
 * lbl_80564E74  -9000.0f: how far below a cut tree is dropped
 */
struct TreeClass {
    int firstTree;     /* 0x00 this class's tree indices, -1 until it has one */
    int lastTree;      /* 0x04 */
    char name[0x20];   /* 0x08 the "drop_model" object's name */
    u8 wobbles;        /* 0x28 clear when the model has "no_wobble" */
    u8 pad29[3];       /* 0x29 */
    f32 dropHeight;    /* 0x2C how far above the tree its drops spawn */
    void *modelObject; /* 0x30 the level's tree object */
    void **drops;      /* 0x34 the drop models, added by fn_802C1F8C */
    int dropCount;     /* 0x38 how many the model asks for */
    int dropsAdded;    /* 0x3C how many have been added */
    int eventId[8];    /* 0x40 "efx_event_id%d" per slot, -1 when it has none */
};                     /* 0x60 */

struct TreeObject {
    f32 matrix[9];     /* 0x00 rotation, swung about the hit axis by fn_802C173C */
    f32 pos[3];        /* 0x24 Y goes 9000 below the ground once the tree is cut */
};

struct TreeHitRecord {
    int treeIndex;     /* 0x00 the tree this hit is waiting for */
    struct TreeObject *tree; /* 0x04 0 once fn_802C1180 gave the pose back */
    f32 matrix[9];     /* 0x08 the pose to give it */
    f32 pos[3];        /* 0x2C */
    f32 axis[3];       /* 0x38 the axis it is being swung about */
    f32 time;          /* 0x44 when it was hit */
};                     /* 0x48 */

struct TreeHitEvent {  /* the 0x20-byte payload of efx event 10, fn_801796EC */
    f32 pos[3];        /* 0x00 where the tree was hit */
    f32 velocity[3];   /* 0x0C the player's velocity */
    s16 angle;         /* 0x18 the player's heading */
    u8 pad1A[2];       /* 0x1A */
    int eventId;       /* 0x1C the class slot's "efx_event_id" */
};                     /* 0x20 */

struct PlayerObject {  /* one of the eight players of lbl_80430830, fn_8017960C */
    u8 pad0[0x6C];
    s16 heading;       /* 0x6C */
    u8 pad6E[0x118 - 0x6E];
    f32 velocity[3];   /* 0x118 */
};

#define TREE_CLASS_EVENT_ID 0x40 /* offsetof(struct TreeClass, eventId) */

extern void *fn_8017960C(int);
extern void fn_801796EC(int, void *, int);
#pragma push
#pragma processor 750
#pragma cplusplus on
#pragma dont_inline on
#pragma scheduling invalid_target
#pragma paired off
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
#pragma pop
typedef struct { int a, b; } Pair802C;
