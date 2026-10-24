// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <types.h>

#define M2C_UNK s32
#define M2C_FIELD(expr, type, offset) (*(type)((u8 *)(expr) + (offset)))
#define M2C_VFUNC(obj, slot, type) ((type)(*(void ***)(obj))[slot])
typedef void *(*M2CPtr0)(void *);
typedef void *(*M2CPtr1)(void *, const char *);
typedef void *(*M2CPtrIndex)(void *, s32);
typedef s32 (*M2CS32_1)(void *, const char *);
typedef f32 (*M2CF32_2)(void *, const char *, f32);
typedef f32 (*M2CF32_1)(void *, const char *);
typedef f32 (*M2CF32_0)(void *);
typedef void *(*M2CPtr2)(void *, const char *, s32);

extern f32 lbl_8056323C;
extern int strcmp(const char *, const char *);
extern void *memset(void *, int, unsigned int);
extern void fn_80127C90(void *, const char *);
extern void *fn_801284F8(s32, const char *);
extern void *fn_80131808(void);
extern void fn_80131818(void *);
extern s32 fn_80137C74(void);
extern void *fn_802077A4(s32, void *, void *);
extern void *fn_80207848(s32);
extern void fn_802E30C8(const char *, ...);
extern void fn_80209904(void);
extern u8 lbl_8033C1E0, lbl_8033C1F0, lbl_8033C1FC, lbl_8033C208;
extern u8 lbl_8033C21C, lbl_8033C22C, lbl_8033C238, lbl_8033C248;
extern s32 lbl_8055B4F8, lbl_8055EDBC;
extern u8 lbl_8055B500, lbl_8055B508, lbl_8055B510, lbl_8055B514;
extern u8 lbl_8055B518, lbl_8055B51C, lbl_8055B520, lbl_8055B528;
extern u8 lbl_8055B52C, lbl_8055B534, lbl_8055B53C;
extern f32 lbl_8055EDB8;
extern f32 lbl_80563238, lbl_8056323C, lbl_80563240, lbl_80563244;
extern f32 lbl_80563248, lbl_8056324C, lbl_80563250, lbl_80563254;
void *fn_80209448(void *arg0) {
    void *result, *item, *manager, *object, *props, *props2;
    void *block, *entry, *base;
    const char *text;
    f32 width, scale, height, z, x, y, a, b, c, d, e;
    s32 index, count, mode;
    result = fn_801284F8(0x158, (const char *)&lbl_8055B500);
    if (result == 0) return result;
    M2C_FIELD(result, void **, 0) = (void *)&lbl_8033C1E0;
    if (lbl_8055EDBC == 0) {
        lbl_8055EDB8 = lbl_80563238;
        fn_80127C90((void *)fn_80209904, (const char *)&lbl_8055B520);
    }
    lbl_8055EDBC++;
    M2C_FIELD(result, void **, 0x140) = arg0;
    M2C_FIELD(result, s32 *, 0x13C) = 0;
    object = M2C_FIELD(M2C_FIELD(arg0, void **, 0x26C), void **, 0x2134);
    object = M2C_VFUNC(object, 2, M2CPtr1)(object, (const char *)&lbl_8033C248);
    M2C_VFUNC(object, 6, M2CPtr2)(object, (const char *)&lbl_8033C238, lbl_8055B4F8);
    manager = fn_80131808();
    object = M2C_VFUNC(manager, 2, M2CPtr1)(manager, (const char *)&lbl_8055B53C);
    M2C_FIELD(result, f32 *, 0x14C) =
        M2C_VFUNC(object, 10, M2CF32_2)(object, (const char *)&lbl_8033C22C, lbl_8056323C);
    width = M2C_VFUNC(object, 9, M2CF32_1)(object, (const char *)&lbl_8033C21C);
    M2C_FIELD(result, f32 *, 0x144) = width;
    M2C_FIELD(result, f32 *, 0x148) = lbl_80563240 * width;
    scale = lbl_8056323C;
    height = lbl_80563244;
    z = lbl_80563238;
    index = 0;
    do {
        item = M2C_VFUNC(manager, 3, M2CPtrIndex)(manager, index);
        if (item == 0) break;
        if (strcmp(M2C_VFUNC(item, 2, M2CPtr0)(item), (const char *)&lbl_8055B534) == 0) {
            count = M2C_FIELD(result, s32 *, 0x13C);
            M2C_FIELD(result, s32 *, 0x13C) = count + 1;
            base = (u8 *)result + count * 0x34;
            block = (u8 *)base + 4;
            memset(block, 0, 0x34);
            text = M2C_VFUNC(item, 5, M2CPtr1)(item, (const char *)&lbl_8055B52C);
            object = M2C_FIELD(result, void **, 0x140);
            if (M2C_FIELD(object, s32 *, 0x1F0) != 0x50) {
                entry = fn_802077A4(3, (u8 *)object + 0x118, (u8 *)arg0 + 0x60);
                M2C_FIELD(block, void **, 0) = entry;
            } else {
                entry = fn_80207848(2);
                if (entry != 0) {
                    if (fn_80137C74() == 2) {
                        mode = M2C_FIELD(object, u8 *, 0x260) & 3;
                        if (mode == 0) {
                            if (height != M2C_FIELD(entry, f32 *, 0x64)) {
                                M2C_FIELD(entry, u8 *, 0x6C) = 1;
                                M2C_FIELD(entry, f32 *, 0x64) = height;
                            }
                        } else if (scale != M2C_FIELD(entry, f32 *, 0x64)) {
                            M2C_FIELD(entry, u8 *, 0x6C) = 1;
                            M2C_FIELD(entry, f32 *, 0x64) = scale;
                        }
                    }
                    if (z != M2C_FIELD(entry, f32 *, 0x68)) {
                        M2C_FIELD(entry, u8 *, 0x6D) = 1;
                        M2C_FIELD(entry, f32 *, 0x68) = z;
                    }
                }
                M2C_FIELD(block, void **, 0) = entry;
            }
            M2C_FIELD(block, f32 *, 0x30) = z;
            entry = M2C_FIELD(block, void **, 0);
            if (entry == 0) {
                fn_802E30C8((const char *)&lbl_8033C208, text);
                M2C_FIELD(result, s32 *, 0x13C)--;
            } else {
                M2C_FIELD(entry, s32 *, 0x10) = M2C_FIELD(arg0, s32 *, 0x1EC);
                props = M2C_VFUNC(item, 23, M2CPtr1)(item, (const char *)&lbl_8033C1FC);
                y = M2C_VFUNC(props, 10, M2CF32_2)(props, (const char *)&lbl_8055B508, lbl_8056323C);
                x = M2C_VFUNC(props, 10, M2CF32_2)(props, (const char *)&lbl_8055B510, lbl_80563248);
                a = M2C_VFUNC(props, 10, M2CF32_2)(props, (const char *)&lbl_8055B514, lbl_8056324C);
                b = M2C_VFUNC(props, 10, M2CF32_2)(props, (const char *)&lbl_8055B518, lbl_80563250);
                c = M2C_VFUNC(props, 10, M2CF32_2)(props, (const char *)&lbl_8055B51C, lbl_80563254);
                M2C_FIELD(block, f32 *, 0x1C) = b;
                M2C_FIELD(block, f32 *, 0x20) = a;
                d = scale / (b - c);
                M2C_FIELD(block, f32 *, 0x24) = d;
                M2C_FIELD(block, f32 *, 0x28) = scale / (x - a);
                M2C_FIELD(block, f32 *, 0x2C) = y;
                props2 = M2C_VFUNC(item, 23, M2CPtr1)(item, (const char *)&lbl_8055B528);
                e = M2C_VFUNC(props2, 10, M2CF32_2)(props2, (const char *)&lbl_8055B508, lbl_8056323C);
                a = M2C_VFUNC(props2, 10, M2CF32_2)(props2, (const char *)&lbl_8055B510, lbl_80563248);
                x = M2C_VFUNC(props2, 10, M2CF32_2)(props2, (const char *)&lbl_8055B514, lbl_8056324C);
                b = M2C_VFUNC(props2, 10, M2CF32_2)(props2, (const char *)&lbl_8055B518, lbl_80563250);
                c = M2C_VFUNC(props2, 10, M2CF32_2)(props2, (const char *)&lbl_8055B51C, lbl_80563254);
                M2C_FIELD(block, f32 *, 8) = b;
                M2C_FIELD(block, f32 *, 0xC) = x;
                d = scale / (b - c);
                M2C_FIELD(block, f32 *, 0x10) = d;
                M2C_FIELD(block, f32 *, 0x14) = scale / (a - x);
                M2C_FIELD(block, f32 *, 0x18) = e;
                M2C_FIELD(block, f32 *, 4) =
                    scale / M2C_VFUNC(item, 9, M2CF32_1)(item, (const char *)&lbl_8033C1F0);
            }
        }
        index++;
    } while (1);
    fn_80131818(manager);
    M2C_FIELD(result, f32 *, 0x150) = lbl_80563238;
    M2C_FIELD(result, f32 *, 0x154) = lbl_80563238;
    return result;
}
