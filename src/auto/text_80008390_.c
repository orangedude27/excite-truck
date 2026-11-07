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
extern s32 lbl_8055D380[2];
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
static inline void check_entry(void *ptr) {
    if (*(u32 *)((char *)ptr + 8) != lbl_8055E044) {
        fn_80131318();
    }
}
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

#pragma dont_inline on
s32 fn_8000865C(void) {
    return (*(u32 *)((char *)fn_801E87A8() + 0x10) >> 1) & 1;
}
#pragma dont_inline reset

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_80008684(s32 arg0) {
    char sp50[0x40];
    char sp10[0x40];
    char sp8[8];
    char *var_r26;
    f32 temp_f0;
    f32 temp_f31;
    f32 temp_f30;
    f32 var_f3;
    s32 temp_r0;
    s32 temp_r27;
    s32 var_r22;
    s32 var_r24;
    s32 var_r25;
    s32 var_r29;
    u32 var_r23;
    char *p31 = lbl_8034F3B0;
    char *p30 = lbl_802FB8F0;
    char *p28;
    s32 *p9c;
    char *pfc;
    char *p108;

    var_r29 = arg0;
    if (lbl_8055D374 != 0) {
        p9c = (s32 *)(p31 + 0x9C);
        temp_r0 = lbl_8055D380[1] - p9c[1];
        if (temp_r0 < 0x258) {
            var_f3 = lbl_805601B8;
            temp_f0 = (f32)temp_r0 / lbl_805601B4;
            if (var_f3 >= temp_f0) {
                var_f3 = temp_f0;
            }
            if (var_f3 <= lbl_805601BC) {
                var_f3 = lbl_805601BC;
            }
        } else {
            var_f3 = lbl_805601B8;
        }
        if (lbl_8055D380[1] - p9c[2] < 0xBB8) {
            var_f3 = lbl_805601B8 - var_f3;
        }
        temp_f30 = lbl_805601BC;
        temp_f31 = lbl_805601C0 * var_f3;
        if ((s8)lbl_8055D388 == 0) {
            fn_801312EC(p31 + 0xA8, p30 + 0x54);
            lbl_8055D388 = 1;
        }
        if ((s8)lbl_8055D389 == 0) {
            fn_801312EC(p31 + 0xB4, p30 + 0x64);
            lbl_8055D389 = 1;
        }
        if ((s8)lbl_8055D38A == 0) {
            fn_801312EC(p31 + 0xC0, p30 + 0x78);
            lbl_8055D38A = 1;
        }
        if ((s8)lbl_8055D38B == 0) {
            fn_801312EC(p31 + 0xCC, p30 + 0x88);
            lbl_8055D38B = 1;
        }
        if ((s8)lbl_8055D38C == 0) {
            fn_801312EC(p31 + 0xD8, p30 + 0x98);
            lbl_8055D38C = 1;
        }
        if ((s8)lbl_8055D38D == 0) {
            fn_801312EC(p31 + 0xE4, p30 + 0xA4);
            lbl_8055D38D = 1;
        }
        if ((s8)lbl_8055D38E == 0) {
            fn_801312EC(p31 + 0xF0, p30 + 0xC0);
            lbl_8055D38E = 1;
        }
        if ((s8)lbl_8055D38F == 0) {
            fn_801312EC(p31 + 0xFC, p30 + 0xD8);
            lbl_8055D38F = 1;
        }
        if ((s8)lbl_8055D390 == 0) {
            fn_801312EC(p31 + 0x108, p30 + 0xEC);
            lbl_8055D390 = 1;
        }
        if ((s8)lbl_8055D391 == 0) {
            if (*(u32 *)(p31 + 0xA8 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 8) = *(s32 *)(p31 + 0xA8 + 4);
            if (*(u32 *)(p31 + 0xB4 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 0x14) = *(s32 *)(p31 + 0xB4 + 4);
            if (*(u32 *)(p31 + 0xC0 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 0x20) = *(s32 *)(p31 + 0xC0 + 4);
            if (*(u32 *)(p31 + 0xCC + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 0x2C) = *(s32 *)(p31 + 0xCC + 4);
            if (*(u32 *)(p31 + 0xD8 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 0x38) = *(s32 *)(p31 + 0xD8 + 4);
            if (*(u32 *)(p31 + 0xE4 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 0x44) = *(s32 *)(p31 + 0xE4 + 4);
            if (*(u32 *)(p31 + 0xF0 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            *(s32 *)(p30 + 0x50) = *(s32 *)(p31 + 0xF0 + 4);
            lbl_8055D391 = 1;
        }
        fn_8014819C(sp8, temp_f31, temp_f30);
        p28 = p31 + 0x20;
        var_r24 = 0;
        for (var_r23 = 0, var_r26 = p30; var_r23 < 7; var_r23++, var_r26 += 0xC) {
            temp_r27 = *(s32 *)var_r26;
            for (var_r22 = 0, var_r25 = 0; var_r22 < *(s32 *)(p28 + 4); var_r22++, var_r25 += 4) {
                if (temp_r27 == *(s32 *)(*(char **)(p31 + 0x20) + var_r25)) {
                    fn_801345D8(sp50, 0x40, p30 + 0x100, var_r24);
                    fn_801345D8(sp10, 0x40, &lbl_805589D8, var_r24);
                    if (lbl_8055D374 != 0) {
                        fn_801473F8(sp50, &lbl_805589E0, *(void **)(var_r26 + 4));
                        fn_801473F8(lbl_8055D374, sp10, &lbl_805589E0, *(s32 *)(var_r26 + 8));
                    }
                    var_r24++;
                }
            }
        }
        fn_801481C8(sp8, -1);
        if (fn_801769F8() != 0) {
            if (lbl_8055D380[1] % 1000 < 500) {
                pfc = p31 + 0xFC;
                if (*(u32 *)(pfc + 8) != lbl_8055E044) {
                    fn_80131318();
                }
                fn_801473F8(lbl_8055D374, &lbl_805589E4, &lbl_805589E0, *(s32 *)(pfc + 4));
            }
        } else {
            p108 = p31 + 0x108;
            if (*(u32 *)(p108 + 8) != lbl_8055E044) {
                fn_80131318();
            }
            fn_801473F8(lbl_8055D374, &lbl_805589E4, &lbl_805589E0, *(s32 *)(p108 + 4));
        }
        if (var_r29 != 4) {
            if (var_r29 == 13) {
                if (fn_8000865C() != 0) {
                    var_r29 = 12;
                }
            } else if (var_r29 == 12) {
                if (fn_8000865C() != 0) {
                    var_r29 = 13;
                }
            }
            switch (var_r29) {
            case 13:
                fn_801473F8(lbl_8055D374, p30 + 0x10C, &lbl_805589E0, fn_80131234(p30 + 0x118));
                break;
            case 12:
                fn_801473F8(lbl_8055D374, p30 + 0x10C, &lbl_805589E0, fn_80131234(p30 + 0x12C));
                break;
            case 14:
                fn_801473F8(lbl_8055D374, p30 + 0x10C, &lbl_805589E0, fn_80131234(p30 + 0x140));
                break;
            case 7:
                fn_801473F8(lbl_8055D374, p30 + 0x10C, &lbl_805589E0, fn_80131234(p30 + 0x154));
                break;
            default:
                fn_801473F8(lbl_8055D374, p30 + 0x10C, &lbl_805589E0, fn_80131234(p30 + 0x168));
                break;
            }
        }
        fn_80011A2C();
    }
}
#pragma pop

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
