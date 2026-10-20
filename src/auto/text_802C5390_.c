#include "types.h"
#pragma push
#pragma small_data off
extern void fn_802D6C48(void);
extern void fn_802D6C44(void);
#pragma pop
void fn_802C5DF0(int*);
extern int lbl_8055D008;
void* fn_802C5390(int);
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);

extern int lbl_8055D00C;
extern void fn_802DB2B4(void);
extern int lbl_804C1338[];
extern unsigned char lbl_804C1348[];
struct Entry16 {
    char data[16];
};
extern int lbl_804C139C[];
extern int lbl_804C13A8[];
extern int lbl_804C13B4[];
char *fn_802CAE34(char *);
int stricmp(const char *, const char *);
extern const char lbl_8034B3DC[];
int fn_802C90E0(void);
int fn_802E30C8(const char *, int);
int fn_802C6B44(int);
void fn_802C6DC4(int, int, int, int);
void fn_802C6C38(int);
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#pragma dont_inline on
void *fn_802C5390(int arg0) {
    u32 base = *(u32 *)((char *)lbl_804C139C + 8);
    return (void *)(base + (arg0 << 4));
}

void fn_802C53C4(void *a, void *b, int x, int y, signed char z) {
    int *count = lbl_804C1338;
    unsigned char *entry = 0;
    if (*count < count[1]) {
        entry = (unsigned char *)(unsigned long)count[2] + *count * 20;
        ++*count;
    }
    if (entry) {
        *(int *)(entry + 0) = *(int *)((char *)a + 12);
        *(signed char *)(entry + 4) = z;
        *(int *)(entry + 8) = x;
        *(int *)(entry + 12) = (*(unsigned int *)((char *)a + 4) & 1) ? y : -1;
        *(void **)(entry + 16) = *(void **)((char *)b + 8);
        *(void **)((char *)b + 8) = entry;
    }
}

#pragma dont_inline on
void fn_802C543C(void) {
    lbl_804C1338[0] = 0;
}
#pragma dont_inline off

int fn_802C544C(void **a, void **b) {
    void *right = *b;
    void *left = *a;
    short x = *(short *)((char *)right + 6);
    short y = *(short *)((char *)left + 6);
    if (y != x) return y - x;
    return stricmp(fn_802CAE34(*(char **)left), fn_802CAE34(*(char **)right));
}

void *fn_802C54B4(int i) { return (void *)(lbl_804C1348 + (i - 1) * 8); }

unsigned char fn_802C54CC(unsigned int arg0) { return (unsigned char)(arg0 >> 8); }

extern void fn_802C8B70(int);
extern void fn_802C8D74(void);
extern void fn_802D0610(int);
extern void fn_802D6B08(int);
extern void fn_802DAA18(void);
extern void fn_802DB2BC(unsigned char);
extern int lbl_804C139C[];
void fn_802C5690(void *arg0) {
    void *node;
    if (*(int *)((char *)arg0 + 8) != 0) {
        fn_802C8B70(*(int *)arg0);
        node = *(void **)((char *)arg0 + 8);
        while (node != 0) {
            fn_802D0610(*(int *)((char *)node + 8));
            if ((unsigned int)(*(int *)((char *)node + 12) + 0x10000) != 0xFFFF) {
                fn_802DAA18();
            }
            fn_802DB2BC(*(unsigned char *)((char *)node + 4));
            fn_802D6B08(*(int *)node);
            node = *(void **)((char *)node + 16);
        }
        fn_802C8D74();
        *(int *)((char *)arg0 + 8) = 0;
    }
}

extern void fn_802C54D4(void);
extern int lbl_804C1390[];
void fn_802C5720(int arg0) {
    int count;
    void **items;
    int i;
    if (arg0 > 0) {
        void *entry = fn_802C54B4(arg0);
        items = *(void ***)entry;
        count = *(int *)((char *)entry + 4);
    } else {
        count = lbl_804C1390[0];
        items = *(void ***)(lbl_804C1390 + 2);
    }
    fn_802C54D4();
    for (i = 0; i < count; i++) {
        fn_802C5690(items[i]);
    }
    fn_802DB2BC(1);
}

void fn_802C57B0(void) { }

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline fn_802C53C4
void fn_802C57B4(int arg0, int arg1, int arg2, unsigned char arg3, float arg4) {
    extern int lbl_8055D008;
    extern s8 lbl_8055FC20;
    extern void fn_802C543C(void);
    extern void fn_802C5720(int);
    extern void fn_802C53C4(void *, void *, int, int, signed char);
    extern void fn_802C57B0(void);
    extern void fn_802CC550(int, void *, float, float);
    extern int fn_802C9638(void *, unsigned char *, float);

    void *manager;
    int *outer_info;
    int idx_shift;
    int i;
    int offset;

    manager = fn_802C5390(arg0);
    outer_info = *(int **)((char *)manager + 4);
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C543C();
    }
    idx_shift = *(int *)((char *)manager + 8) << 2;
    for (i = 0, offset = 0; i < *outer_info; i++, offset += 0x10) {
        char *entry = *(char **)((char *)outer_info + 4) + offset;
        int bit_idx = *(int *)entry;
        if (lbl_8055D008 & (1 << bit_idx)) {
            unsigned char local_d = arg3;
            char *sub = *(char **)((char *)manager + 12);
            if (sub == 0 || fn_802C9638(sub + offset, &local_d, *(float *)(sub + offset + 12)) != 0) {
                unsigned char d = local_d;
                int *inner_info = *(int **)(entry + 8);
                int j;
                int inner_offset;
                for (j = 0, inner_offset = 0; j < *inner_info; j++, inner_offset += 4) {
                    void *elem = *(void **)(*(char **)((char *)inner_info + 4) + inner_offset);
                    unsigned int type = *(unsigned int *)elem;
                    int valid = 0;
                    if (type < 13) {
                        int skip;
                        valid = 1;
                        switch (type) {
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            skip = 1;
                            break;
                        default:
                            skip = 0;
                            break;
                        }
                        if (skip) valid = 0;
                    }
                    if (valid) {
                        void *node = *(void **)((char *)elem + idx_shift + 0x14);
                        void *r4;
                        fn_802C53C4(entry, node, arg1, arg2, d);
                        r4 = ((void *(*)(void *))fn_802C57B0)(*(void **)(entry + 12));
                        fn_802CC550(*(int *)node, r4, arg4, *(float *)((char *)r4 + 0x18));
                    }
                }
            }
        }
    }
    if ((u8)lbl_8055FC20 == 0) {
        fn_802C5720(-1);
    }
}
#pragma pop
void fn_802C595C(char *dst, int size, const char *name, int id) {
    int i = 0;
    int offset = 0;
    const char *src;
    if (i < lbl_804C13B4[0]) {
        do {
            char *entry = (char *)(unsigned long)lbl_804C13B4[2] + offset;
            if (stricmp(name, *(char **)(entry + 8)) == 0 && id == *(int *)(entry + 0x10)) {
                src = entry + 0x14;
                while (size > 0) {
                    char c = *src++;
                    *dst++ = c;
                    if (c == 0) return;
                    if (--size <= 0) {
                        dst[-1] = 0;
                        return;
                    }
                }
                return;
            }
            offset += 0x2C;
            i++;
        } while (i < lbl_804C13B4[0]);
    }
    while (size > 0) {
        char c = *name++;
        *dst++ = c;
        if (c == 0) return;
        if (--size <= 0) {
            dst[-1] = 0;
            return;
        }
    }
}

u16 fn_802C5A50(int arg0, int arg1) {
    return (u16)((arg0 << 8) | arg1);
}

extern void fn_802CAC54(int);
extern s8 lbl_8055FC21;
void fn_802C5BA0(int *arg0) {
    u16 temp;
    fn_802CAC54(*arg0);
    temp = *(u16 *)((char *)arg0 + 4);
    temp--;
    *(u16 *)((char *)arg0 + 4) = temp;
    if (temp == 0) {
        lbl_8055FC21 = 1;
    }
}

u16 fn_802C5BEC(int arg0, u16 arg1) {
    u16 a = fn_802C5A50(5, arg1);
    u16 b = arg0 & 0xFFFE;
    return a + b;
}

extern int fn_802CAC28(void *, int);
extern void *fn_802C5A60(int, int, u16);
#pragma push
#pragma small_data off
extern int lbl_8034B1F0;
#pragma pop
#pragma push
#pragma small_data off
#pragma pop
#pragma push
#pragma scheduling off
void fn_802C5C40(int *arg0, int arg1, int arg2) {
    int temp_r30 = *arg0;
    int result = fn_802CAC28(&lbl_8034B1F0, 0);
    *(int *)((char *)arg0 + arg1 * 4 + 0x14) =
        (int)fn_802C5A60(result, temp_r30,
            (u16)(*(s16 *)(*(int *)((char *)arg2 + arg1 * 4 + 0x14) + 6) - 1));
}

void fn_802C5E6C(void *arg0, void *arg1) {
    void *temp = fn_802D6C44;
    ((void (*)(void *, void *))fn_802C5DF0)(arg1, temp);
}

#pragma pop
s32 fn_802C5EB8(void *, u32);

s32 fn_802C5E7C(void *arg0) {
    s32 result = fn_802C5EB8(arg0, 0x5350484C);
    if (result != 0) {
        return result + 8;
    }
    return 0;
}

s32 fn_802C5EB8(void *arg0, u32 arg1) {
    s32 count = *(s32 *)((char *)arg0 + 0x10);
    u32 *result = NULL;
    s32 i;
    for (i = 0; count > i; i++) {
        u32 *entry = *(u32 **)(*(char **)((char *)arg0 + 0x14) + i * 4);
        if (*entry == arg1) {
            result = entry;
            break;
        }
    }
    return (s32)result;
}

void *fn_802C5EFC(int arg0) {
    int count = lbl_804C13A8[0];
    void *entry = (void *)(unsigned long)lbl_804C13A8[2];
    if (count > 0) {
        while (count-- > 0) {
            if (*(u16 *)((char *)entry + 4) != 0 && *(int *)entry == arg0) {
                return entry;
            }
            entry = (void *)((char *)entry + 0x10);
        }
    }
    return 0;
}

void fn_802C6068(void *arg0) {
    *(s16 *)((char *)arg0 + 4) = 0;
}

void fn_802C6074(s32 *arg0) {
    *arg0 = 0;
}

void fn_802C6A84(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6A9C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AB4(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6ACC(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AE4(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6AFC(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6B14(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6B2C(s32 *arg0, s32 arg1) {
    s32 val = *arg0;
    if (val != 0) {
        *arg0 = val + arg1;
    }
}

void fn_802C6C30(void) {}

void fn_802C6C34(void) { fn_802C53A8(); }

#pragma push
#pragma small_data off
#pragma pop
void fn_802C6FA8(void *arg0) {
    ((void (*)(void *, void *))fn_802C5DF0)(arg0, fn_802D6C48);
}

extern void fn_802D6C44(void);
void fn_802C6FB4(void *arg0) {
    ((void (*)(void *, void *))fn_802C5DF0)(arg0, fn_802D6C44);
}

void fn_802C6FC0(void *arg0, int arg1, int arg2) {
    if (fn_802C90E0() == 0) {
        ((int (*)(const char *, ...))fn_802E30C8)(lbl_8034B3DC, arg0);
    }
    fn_802C6DC4((int)arg0, fn_802C6B44((int)arg0), arg1, arg2);
}

void fn_802C703C(int arg0) {
    fn_802C6C38(arg0);
}

int fn_802C90E0(void);
int fn_802E30C8(const char*, int);
extern const char lbl_8034B34C[];
int fn_802C53A8();
int fn_802C6C20(int);
int fn_802C6B44(int);
void fn_802C6DC4(int, int, int, int);
extern const char lbl_8034B3DC[];
int fn_802C94A0(void*, unsigned char*, float*, float);
void fn_802C57B4(int, int, int, unsigned char, float);
void fn_802C7040(int arg0) {
    float spC;
    unsigned char sp8;
    void* temp;
    if (arg0 != -1) {
        temp = *(void**)((char*)fn_802C5390(arg0) + 4);
        if (fn_802C94A0((char*)temp + 0x20, &sp8, &spC, *(float*)((char*)temp + 0x1C))) {
            fn_802C57B4(arg0, 0, -1, sp8, spC);
        }
    }
}

void fn_802C744C(int arg0, void *arg1) { fn_802C70AC(arg0, arg1, -1, -1); }

void fn_802C7458(int arg0, int arg1) {
    float spC;
    unsigned char sp8;
    int temp_r31;
    void *temp;

    if (arg0 != -1) {
        temp_r31 = lbl_8055D008;
        lbl_8055D008 = arg1;
        temp = *(void **)((char *)fn_802C5390(arg0) + 4);
        if (fn_802C94A0((char *)temp + 0x20, &sp8, &spC, *(float *)((char *)temp + 0x1C))) {
            fn_802C57B4(arg0, 0, -1, sp8, spC);
        }
        lbl_8055D008 = temp_r31;
    }
}

void fn_802C7730(void) { fn_802DABA4(); }

void fn_802C7734(void* alarm) {
    fn_802D0610(fn_802D0514(alarm));
}

void fn_802C7758(void);
void fn_802C7758(void) {
    fn_802D0610(0);
}

void fn_802C7760(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    void *temp_r3 = fn_802C5390((int)arg0);
    *arg1 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x2C);
    *arg2 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x30);
    *arg3 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x34);
    *arg4 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x38);
    *arg5 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x3C);
    *arg6 = *(f32 *)((u8 *)*(void **)((u8 *)temp_r3 + 4) + 0x40);
}

void fn_802C77F0(void *arg0, f32 *arg1) {
    fn_802C7760(arg0, arg1, arg1 + 1, arg1 + 2, arg1 + 3, arg1 + 4, arg1 + 5);
}

float fn_802C7808(int arg0) {
    return *(float *)((char *)(*(void **)((char *)fn_802C5390(arg0) + 4)) + 0x1C);
}

s32 fn_802C7830(char *arg0, s32 arg1, signed char c) {
    s32 value = 0;
    s32 is_digit;
    do {
        value <<= 4;
        is_digit = 0;
        if (c >= '0') {
            if (c <= '9') {
                is_digit = 1;
            }
        }
        if (is_digit == 0) {
            value |= c - '7';
        } else {
            value |= c - '0';
        }
        arg0++;
        c = *arg0;
    } while (c != 0);
    return value;
}

extern int lbl_804C13B4[];
extern void fn_802C7A00(void);
void fn_802C7A00(void) {
    lbl_804C13B4[0] = 0;
}

void fn_802C7A10(void* alarm) {
    fn_8012C58C(fn_802C53A8(alarm));
}

void fn_802C7A34(void) { fn_802DA704(); }

extern void fn_802DA80C(void);
void fn_802C7A38(void) { fn_802DA80C(); }

extern void fn_802DA918(void);
void fn_802C7A3C(void) { fn_802DA918(); }

extern void fn_802DA80C(void);
extern void fn_802DA918(void);
extern void fn_802DA550(void);
void fn_802C7A40(void) { fn_802DA550(); }

extern s8 lbl_8055FC20;
extern void fn_802C543C(void);
void fn_802C7A44(void) {
    lbl_8055FC20 = 1;
    fn_802C543C();
}

void fn_802C7A50(void) {
    int i = 0;
    do {
        fn_802C5720(i);
        i++;
    } while (i < 9);
    lbl_8055FC20 = 0;
}

void fn_802C7A94(int arg0) {
    fn_802C7758();
    fn_802C5720(arg0);
    if (arg0 == 9) {
        fn_802C543C();
    }
}

#pragma dont_inline on
void fn_802C7AD4(void) {
    fn_802C7A94(9);
}
#pragma dont_inline reset
void fn_802D754C(void);
void fn_802C7ADC(void) { fn_802D754C(); }

void fn_802C8218(s32 arg0) {
    s32 var_r0;

    var_r0 = 1;
    if (arg0 != 0) {
        var_r0 = 2;
    }
    lbl_8055D00C = var_r0;
}

void fn_802C8230(void) {
    fn_802DB2B4();
}

extern void fn_802DB2B8(void);
void fn_802C8234(void) { fn_802DB2B8(); }

extern int lbl_8055D008;
extern void fn_8012C4E4(void *, int);

