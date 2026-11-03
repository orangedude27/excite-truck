// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <types.h>

extern int __register_global_object(void *, void *, void *);
extern void fn_8000D838(void *);
extern void fn_8002F53C(void *, void *, void *, int, int);
extern void fn_801DF678(void);
extern void fn_801DF6D0(void);
extern char lbl_804872B0[];
extern unsigned char lbl_8055AE2C;
extern unsigned char lbl_8055E9D0;
extern int lbl_8055E9D8;

struct Elem {
    s8 f0;
    void *f4;
    void *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
};

struct Container {
    struct Elem *elems;
    s32 count;
    s32 capacity;
    struct Elem buf[8];
};

struct BigObj {
    struct Elem arr[9];
    char pad[0xC];
    struct Container container;
};

#define FIELD_PTR(base, offset) (*(void **)((char *)(base) + (offset)))
#define FIELD_S32(base, offset) (*(s32 *)((char *)(base) + (offset)))
#define FIELD_S8(base, offset) (*(s8 *)((char *)(base) + (offset)))

void fn_801DF3BC(void) {
    char *base;
    s32 temp_r12;
    s32 temp_r6_2;
    s32 temp_r7;
    s32 var_r4;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r6;
    s32 temp_r11;
    u32 var_ctr;
    u32 var_ctr_2;
    char *temp_r5;
    char *temp_r5_2;
    char *temp_r6;
    char *temp_r8;
    char *temp_r9;
    char *var_r3;

    base = lbl_804872B0;
    fn_8000D838(&lbl_8055E9D0);
    lbl_8055E9D8 = 0x7F000000;
    fn_8002F53C(base, &fn_801DF6D0, 0, 0x1C, 9);
    temp_r9 = base + 0x108;
    temp_r8 = temp_r9 + 0xC;
    var_r3 = temp_r8 + 0x1C;
    FIELD_PTR(base, 0x108) = temp_r8;
    FIELD_S32(temp_r9, 4) = 0;
    temp_r5 = temp_r9 + 0xEC;
    FIELD_PTR(temp_r9, 0x10) = &lbl_8055AE2C;
    FIELD_S32(temp_r9, 8) = 8;
    FIELD_PTR(temp_r9, 0x14) = &lbl_8055AE2C;
    FIELD_S32(temp_r9, 0x24) = 0;
    FIELD_S8(temp_r9, 0xC) = 0;
    FIELD_S32(temp_r9, 0x18) = 0;
    FIELD_S32(temp_r9, 0x1C) = 0;
    FIELD_S32(temp_r9, 0x20) = -1;
    if (var_r3 < temp_r5) {
        temp_r6 = temp_r9 + 0x28;
        temp_r7 = (s32)(temp_r5 - temp_r6);
        temp_r11 = (s32)(temp_r7 + 0x1B) / 28;
        temp_r12 = temp_r11 + 1;
        if (temp_r12 > 8) {
            var_r4 = 0;
            var_r5 = 0;
            if (temp_r6 <= temp_r5) {
                var_r6 = 1;
                if (!(temp_r7 & 0x80000000) && ((temp_r7 + 0x1B) & 0x80000000)) {
                    var_r6 = 0;
                }
                if (var_r6 != 0) {
                    var_r5 = 1;
                }
            }
            if (var_r5 != 0) {
                temp_r6_2 = temp_r11 & 0x80000000;
                var_r5_2 = 1;
                if ((temp_r6_2 == 0) && (temp_r6_2 != (s32)(temp_r12 & 0x80000000))) {
                    var_r5_2 = 0;
                }
                if (var_r5_2 != 0) {
                    var_r4 = 1;
                }
            }
            if (var_r4 != 0) {
                var_ctr = (u32)((temp_r8 + 0xDF) - var_r3) / 224U;
                if (var_r3 < temp_r8) {
                    do {
                        FIELD_PTR(var_r3, 4) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 8) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0x18) = 0;
                        FIELD_S8(var_r3, 0) = 0;
                        FIELD_S32(var_r3, 0xC) = 0;
                        FIELD_S32(var_r3, 0x10) = 0;
                        FIELD_S32(var_r3, 0x14) = -1;
                        FIELD_PTR(var_r3, 0x20) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0x24) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0x34) = 0;
                        FIELD_S8(var_r3, 0x1C) = 0;
                        FIELD_S32(var_r3, 0x28) = 0;
                        FIELD_S32(var_r3, 0x2C) = 0;
                        FIELD_S32(var_r3, 0x30) = -1;
                        FIELD_PTR(var_r3, 0x3C) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0x40) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0x50) = 0;
                        FIELD_S8(var_r3, 0x38) = 0;
                        FIELD_S32(var_r3, 0x44) = 0;
                        FIELD_S32(var_r3, 0x48) = 0;
                        FIELD_S32(var_r3, 0x4C) = -1;
                        FIELD_PTR(var_r3, 0x58) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0x5C) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0x6C) = 0;
                        FIELD_S8(var_r3, 0x54) = 0;
                        FIELD_S32(var_r3, 0x60) = 0;
                        FIELD_S32(var_r3, 0x64) = 0;
                        FIELD_S32(var_r3, 0x68) = -1;
                        FIELD_PTR(var_r3, 0x74) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0x78) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0x88) = 0;
                        FIELD_S8(var_r3, 0x70) = 0;
                        FIELD_S32(var_r3, 0x7C) = 0;
                        FIELD_S32(var_r3, 0x80) = 0;
                        FIELD_S32(var_r3, 0x84) = -1;
                        FIELD_PTR(var_r3, 0x90) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0x94) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0xA4) = 0;
                        FIELD_S8(var_r3, 0x8C) = 0;
                        FIELD_S32(var_r3, 0x98) = 0;
                        FIELD_S32(var_r3, 0x9C) = 0;
                        FIELD_S32(var_r3, 0xA0) = -1;
                        FIELD_PTR(var_r3, 0xAC) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0xB0) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0xC0) = 0;
                        FIELD_S8(var_r3, 0xA8) = 0;
                        FIELD_S32(var_r3, 0xB4) = 0;
                        FIELD_S32(var_r3, 0xB8) = 0;
                        FIELD_S32(var_r3, 0xBC) = -1;
                        FIELD_PTR(var_r3, 0xC8) = &lbl_8055AE2C;
                        FIELD_PTR(var_r3, 0xCC) = &lbl_8055AE2C;
                        FIELD_S32(var_r3, 0xDC) = 0;
                        FIELD_S8(var_r3, 0xC4) = 0;
                        FIELD_S32(var_r3, 0xD0) = 0;
                        FIELD_S32(var_r3, 0xD4) = 0;
                        FIELD_S32(var_r3, 0xD8) = -1;
                        var_r3 += 0xE0;
                        var_ctr -= 1;
                    } while (var_ctr != 0);
                }
            }
        }
        temp_r5_2 = temp_r9 + 0xEC;
        var_ctr_2 = (u32)((temp_r5_2 + 0x1B) - var_r3) / 28U;
        if (var_r3 < temp_r5_2) {
            do {
                FIELD_PTR(var_r3, 4) = &lbl_8055AE2C;
                FIELD_PTR(var_r3, 8) = &lbl_8055AE2C;
                FIELD_S32(var_r3, 0x18) = 0;
                FIELD_S8(var_r3, 0) = 0;
                FIELD_S32(var_r3, 0xC) = 0;
                FIELD_S32(var_r3, 0x10) = 0;
                FIELD_S32(var_r3, 0x14) = -1;
                var_r3 += 0x1C;
                var_ctr_2 -= 1;
            } while (var_ctr_2 != 0);
        }
    }
    __register_global_object(base + 0x108, (void *)&fn_801DF678, base + 0xFC);
}
