// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
extern void *fn_801E87A8(void);
extern s32 fn_8026E20C(void);
extern void fn_8026E204(s32);
#pragma small_data off
typedef struct { s32 *data; s32 count; char pad[0x40]; } IdList;
extern IdList lbl_8034F3D0;
extern char lbl_802FB8F0[];
extern char lbl_8034F3B0[];
#pragma small_data on
extern void *lbl_8055D374;
extern s32 lbl_8055D380[];
extern u8 lbl_8055D388;
extern u8 lbl_8055D389;
extern u8 lbl_8055D38A;
extern u8 lbl_8055D38B;
extern u8 lbl_8055D38C;
extern u8 lbl_8055D38D;
extern u8 lbl_8055D38E;
extern u8 lbl_8055D38F;
extern u8 lbl_8055D390;
extern u8 lbl_8055D391;
extern u32 lbl_8055E044;
extern s32 lbl_805589D8;
extern s32 lbl_805589E0;
extern s32 lbl_805589E4;
extern f32 lbl_805601B4;
extern f32 lbl_805601C0;
extern double lbl_805601C8;
extern void fn_80011A2C(void);
extern s32 fn_80131234(void *);
extern void fn_801312EC(void *, void *);
extern void fn_80131318(void);
extern void fn_801345D8(void *, s32, void *, ...);
extern void fn_801473F8(void *, void *, void *, ...);
extern void fn_8014819C(void *, f32, f32);
extern void fn_801481C8(void *, s32);
extern s32 fn_801769F8(void);
extern s32 fn_800167F4(void);
extern s32 lbl_802ED6D8[];
extern s32 lbl_8055D370;
extern s32 lbl_805601B0;
#define ID_LIST (&lbl_8034F3D0)
static inline void IdList_Add(s32 *src) {
    s32 *data = lbl_8034F3D0.data;
    s32 n = lbl_8034F3D0.count;
    lbl_8034F3D0.count = n + 1;
    data[n] = *src;
}
#define ID_PUSH(v) { s32 n_ = ID_LIST->count; ID_LIST->count = n_ + 1; ID_LIST->data[n_] = (v); }
void fn_80008390(void) {
    s32 *base = lbl_802ED6D8;
    s32 *p;
    s32 i;
    ID_LIST->count = 0;
    if (fn_800167F4() > 1) IdList_Add(&lbl_805601B0);
    if (lbl_8055D370 == 0) {
        p = base;
        IdList_Add(p); IdList_Add(p + 1); IdList_Add(p + 2); IdList_Add(p + 3);
    } else {
        p = base + 4;
        IdList_Add(p); IdList_Add(p + 1); IdList_Add(p + 2); IdList_Add(p + 3); IdList_Add(p + 4);
    }
    for (i = 0; i < ID_LIST->count; i++) {
        if (ID_LIST->data[i] == 1) {
            p = base + 10;
            IdList_Add(p); IdList_Add(p + 1); IdList_Add(p + 2); IdList_Add(p + 3);
            break;
        }
    }
}

#pragma scheduling invalid_target
s32 fn_800085D8(s32 arg0) {
    s32 i;
    s32 *data = lbl_8034F3D0.data;
    s32 count = lbl_8034F3D0.count;
    for (i = 0; i < count; i++) {
        if (arg0 == data[i])
            return 1;
    }
    return 0;
}
#pragma scheduling on
void fn_80008618(s32 arg0) {
    s32 value = fn_8026E20C();
    s32 result = value | arg0;
    if (value & arg0)
        result = value & ~arg0;
    fn_8026E204(result);
}

extern s32 fn_8000865C(void);
extern s32 fn_801298E8(void *, s32);
extern s32 fn_802ECC10(void);
extern s32 lbl_805589EC;
extern u8 lbl_8055D37A;
extern f32 lbl_8055D394;
extern f32 lbl_805601B8;
extern f32 lbl_805601BC;
extern f32 lbl_805601D0;
#pragma dont_inline on
#pragma optimization_level 2
s32 fn_80008C5C(void) {
    unsigned char sp[0x68];
    s32 old = *(volatile s32 *)&lbl_805589EC;
    u32 input;
    u32 bit;
    s32 allowed;
    if (*(volatile u8 *)&lbl_8055D37A == 0 && fn_802ECC10() == 0 && fn_801298E8(sp, 0) != 0) {
        input = *(u32 *)(sp + 0x40);
        if (input == 8) {
            s32 flag = fn_8000865C();
            s32 mode = 0xC;
            if (flag != 0)
                mode = 0xD;
            lbl_805589EC = mode;
        } else if (input == 2) {
            s32 flag = fn_8000865C();
            s32 mode = 0xD;
            if (flag != 0)
                mode = 0xC;
            lbl_805589EC = mode;
        } else if (input == 4) {
            lbl_805589EC = 7;
        } else if (input == 1) {
            lbl_805589EC = 0xE;
        }
        allowed = 0;
        bit = *(volatile u32 *)(sp + 0x40) - 1;
        if (bit <= 7 && ((1 << bit) & 0x8B))
            allowed = 1;
        if (allowed == 0 && lbl_8055D394 > lbl_805601B8 && lbl_805589EC != 4)
            lbl_805589EC = 4;
        if (lbl_805589EC != old) {
            if (lbl_8055D394 > lbl_805601B8)
                goto set_timer;
            if (old != 4)
                goto restore_old;
        set_timer:
            lbl_8055D394 = lbl_805601BC;
            goto state_done;
        }
    restore_old:
        lbl_805589EC = old;
    state_done:
        lbl_8055D394 += lbl_805601D0;
    }
    return lbl_805589EC;
}
#pragma optimization_level reset
#pragma dont_inline off

s32 fn_8000865C(void) {
    return (*(u32 *)((char *)fn_801E87A8() + 0x10) >> 1) & 1;
}

s32 fn_80008DBC(s32 arg0) {
    switch (arg0) {
    case 0x113: return 0x15;
    case 0x2C: return 0;
    case 0x1B: return 0x12;
    case 0xD: return 0x13;
    case 0x20: return 0xF;
    case 0x2B: return 0x1B;
    case 0x2D: return 0x1A;
    case 0x2E: return 0;
    case 0x32: return 0x18;
    case 0x30: return 0x19;
    case 0x6F: return 0xE;
    case 0x170: return 0;
    case 0x125: return 2;
    case 0x122: return 0x15;
    case 0x121: return 0x14;
    case 0x128: return 5;
    case 0x127: return 3;
    case 0x174: return 0;
    case 0x172: return 0;
    case 0x176: return 0;
    case 0x126: return 4;
    case 0x31: return 0x17;
    default: return 0;
    }
}

s32 fn_80008F68(s32 arg0) {
    switch (arg0) {
    case 0x15:
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}

void fn_80009C80(void) {
    fn_80009534();
}

extern char lbl_8055D36D;
char fn_80009C84(void) {
    return lbl_8055D36D;
}

extern char lbl_8055D378;
s32 fn_80009C8C(void) {
    s32 result = 0;

    if ((u8)lbl_8055D36D == 0 && (u8)lbl_8055D378 != 0)
        result = 1;
    lbl_8055D378 = 0;
    return result;
}

#pragma optimization_level 2
s32 fn_80009CB8(void) {
    s32 result = 0;

    if ((u8)lbl_8055D36D == 0 && ((u8 *)&lbl_8055D378)[1] != 0)
        result = 1;
    ((u8 *)&lbl_8055D378)[1] = 0;
    return result;
}
#pragma optimization_level reset
