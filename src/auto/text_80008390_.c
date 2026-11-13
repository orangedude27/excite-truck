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
extern void fn_80131318(void *);
extern void fn_801345D8(void *, s32, void *, ...);
extern void fn_801473F8(void *, void *, void *, ...);
extern void fn_8014819C(void *, f32, f32);
extern void fn_801481C8(void *, s32);
extern s32 fn_801769F8(void);
static inline void check_entry(void *ptr) {
    if (*(u32 *)((char *)ptr + 8) != lbl_8055E044) {
        fn_80131318(ptr);
    }
}
static inline s32 get_diff_4(void *ptr) {
    return lbl_8055D380[1] - *(s32 *)((char *)ptr + 4);
}
static inline s32 get_diff_8(void *ptr) {
    return lbl_8055D380[1] - *(s32 *)((char *)ptr + 8);
}
extern s32 fn_800167F4(void);
extern void fn_801CEFD4(s32);
extern void fn_80137C74(void);
extern s32 __AXGetStackHead_80137CFC(s32);
extern void fn_80129AEC(void);
extern void *fn_801E86F8(s32);
extern void *fn_80145E70(void *);
extern s32 fn_802E2C20(void);
extern void fn_80176A00(s32);
extern void fn_80179588(void);
extern void fn_80176734(void);
extern s32 fn_8026DDD0(void);
extern s32 fn_801CB8FC(void);
extern void fn_80007210(void);
extern void fn_801E7E04(s32, s32);
extern s32 fn_8018FD38(void);
extern void __AXDSPInitCallback_801769E0(void);
extern void fn_80206454(void);
extern void fn_80206444(void);
extern void fn_801769EC(void);
extern s32 fn_802E47B8(void);
extern s32 fn_802E46F0(void);
extern void fn_802E4A10(void);
extern s32 fn_80137C98(void);
extern s32 fn_802E30C8(void *, ...);
extern void fn_80008F98(void);
extern void fn_80230E90(s32);
extern void fn_8017691C(void);
extern s32 fn_801E8838(void);
extern s32 fn_80008DBC(s32);
extern s32 fn_80008F68(s32);
extern void fn_8026DDD8(s32);
extern void fn_801E85DC(s32);
extern void fn_801E882C(void);
extern s32 fn_802E317C(void *, s32, ...);
extern void fn_80012158(void);
extern void fn_802C8530(void);
extern void fn_802C87B4(s32, s32, s32, s32);
extern void fn_801E7E48(void);
extern void fn_8026A1F0(s32, s32, s32);
extern void fn_801E81B8(s32, s32);
extern void fn_80230B5C(void *);
extern void fn_802C8638(void *);
extern void fn_802C974C(float, float, float);
extern void fn_80012624(float);
extern void fn_802C9A70(s32);
extern s32 fn_802787F4(void);
extern void fn_800073D8(s32);
extern void fn_80007318(s32);
extern void fn_802C942C(s32);
extern void fn_802C855C(void);
extern void fn_80211F64(void);
extern void fn_80129AFC(void);
extern void fn_802C2B48(void);
extern void fn_801795B0(void);
extern void fn_801E86E8(void *, s32);
extern char lbl_8055D378;
extern char lbl_8055D36D;
extern char lbl_8055D36C;
extern char lbl_805589B0;
extern char lbl_8034F44C[];
extern u8 lbl_8055D39C;
extern u8 lbl_8055D39D;
extern s32 lbl_8055CFF0;
extern s32 lbl_8055CFF4;
extern f32 lbl_805601D4;
extern f32 lbl_805601D8;
extern f32 lbl_805601E8;
extern s32 lbl_802ED6D8[];
extern s32 lbl_8055D370;
extern s32 lbl_805601B0;
extern char lbl_805589F0[8];
extern char lbl_805589F8[4];
extern char lbl_805589FC[8];
extern int lbl_8055D398;
extern float lbl_805601B8;
extern float lbl_805601BC;
extern float lbl_805601DC;
extern float lbl_805601E0;
extern float lbl_805601E4;
extern void fn_802782C4(void);
extern void fn_80278318(void);
extern int fn_80278358(void);
extern void fn_80278778(char *);
extern void fn_802787E4(void);
extern void fn_8027888C(int);
extern void fn_80278894(int);
extern void fn_8027889C(float);
extern void fn_802788E0(float);
extern int fn_80278924(float *, float *);
extern float fn_801E7E18(void);
extern void fn_801E85BC(int);
extern void fn_801E85CC(int);
extern void fn_80010188(int, int, const char *, ...);
extern int sprintf(char *, const char *, ...);
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

#pragma dont_inline on
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
#pragma dont_inline reset
#pragma dont_inline on
void fn_80008618(s32 arg0) {
    s32 value = fn_8026E20C();
    s32 result = value | arg0;
    if (value & arg0)
        result = value & ~arg0;
    fn_8026E204(result);
}
#pragma dont_inline reset

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
    /* Update UI/menu state (lbl_805589EC) from controller 0 input: if not
       blocked (lbl_8055D37A) and home-button flag fn_802ECC10() is clear, read
       pad state via fn_801298E8 into sp and map button bits at sp+0x40 to
       states (8/2 toggle 0xC/0xD based on fn_8000865C, 4->7, 1->0xE). Allowed
       inputs mask 0x8B; if input not allowed and idle timer lbl_8055D394 exceeds
       threshold lbl_805601B8 while not in state 4, force state 4. On state
       change reset timer to lbl_805601BC unless reverting from 4, else restore
       old; always advance timer by lbl_805601D0. Returns current state. */
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
void fn_80008684(s32 arg0) {
    char sp50[0x40];
    char sp10[0x40];
    char sp8[8];
    char *p31 = lbl_8034F3B0;
    char *p30 = lbl_802FB8F0;
    char *p28;
    char *var_r26;
    s32 *p9c;
    s32 temp_r0;
    f32 temp_f0;
    f32 temp_f31;
    f32 temp_f30;
    f32 var_f3;
    s32 temp_r27;
    s32 var_r22;
    s32 var_r24;
    s32 var_r25;
    s32 var_r29;
    u32 var_r23;

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
            check_entry(p31 + 0xA8);
            *(s32 *)(p30 + 8) = *(s32 *)(p31 + 0xA8 + 4);
            check_entry(p31 + 0xB4);
            *(s32 *)(p30 + 0x14) = *(s32 *)(p31 + 0xB4 + 4);
            check_entry(p31 + 0xC0);
            *(s32 *)(p30 + 0x20) = *(s32 *)(p31 + 0xC0 + 4);
            check_entry(p31 + 0xCC);
            *(s32 *)(p30 + 0x2C) = *(s32 *)(p31 + 0xCC + 4);
            check_entry(p31 + 0xD8);
            *(s32 *)(p30 + 0x38) = *(s32 *)(p31 + 0xD8 + 4);
            check_entry(p31 + 0xE4);
            *(s32 *)(p30 + 0x44) = *(s32 *)(p31 + 0xE4 + 4);
            check_entry(p31 + 0xF0);
            *(s32 *)(p30 + 0x50) = *(s32 *)(p31 + 0xF0 + 4);
            lbl_8055D391 = 1;
        }
        fn_8014819C(sp8, temp_f31, temp_f30);
        p28 = p31 + 0x20;
        var_r24 = 0;
        for (var_r23 = 0, var_r26 = p30; var_r23 < 7; var_r23++, var_r26 += 0xC) {
            temp_r27 = *(s32 *)var_r26;
            for (var_r22 = 0, var_r25 = 0; var_r22 < *(s32 *)(p28 + 4); var_r22++, var_r25 += 4) {
                if (temp_r27 == *(s32 *)(*(char **)p28 + var_r25)) {
                    fn_801345D8(sp50, 0x40, p30 + 0x100, var_r24);
                    fn_801345D8(sp10, 0x40, &lbl_805589D8, var_r24);
                    if (lbl_8055D374 != 0) {
                        fn_801473F8(lbl_8055D374, sp50, &lbl_805589E0, *(void **)(var_r26 + 4));
                        fn_801473F8(lbl_8055D374, sp10, &lbl_805589E0, *(s32 *)(var_r26 + 8));
                    }
                    var_r24++;
                }
            }
        }
        fn_801481C8(sp8, -1);
        if (fn_801769F8() != 0) {
            if (lbl_8055D380[1] % 1000 < 500) {
                check_entry(p31 + 0xFC);
                fn_801473F8(lbl_8055D374, &lbl_805589E4, &lbl_805589E0, *(s32 *)(p31 + 0xFC + 4));
            }
        } else {
            check_entry(p31 + 0x108);
            fn_801473F8(lbl_8055D374, &lbl_805589E4, &lbl_805589E0, *(s32 *)(p31 + 0x108 + 4));
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

#pragma dont_inline on
/* Turns a key from the Shot dev-box keyboard (fn_802E46F0) into the sound-test
 * command fn_80009534 runs; 0 means the key does nothing here.  Printable keys
 * arrive as their ASCII code (Enter, Esc, space, '+', ',', '-', '0'..'2', 'o')
 * and the special keys as 0x100+n; 0x170-0x176 are muted on purpose.  Whether a
 * command is honoured at all is decided by the enabled-command list fn_80008390
 * builds, which fn_800085D8 looks the result up in. */
s32 fn_80008DBC(s32 keyCode) {
    switch (keyCode) {
    case 0x125: return 2;      /* audio mode 0 (fn_8026DDD8(0)) */
    case 0x126: return 4;      /* audio mode 1 (fn_8026DDD8(1)) */
    case 0x128: return 5;      /* toggle sound flag bit 1 (fn_80008618(1)) */
    case 0x127: return 3;      /* audio mode 2 (fn_8026DDD8(2)) */
    case 0xD: return 0x13;     /* Enter */
    case 0x20: return 0xF;     /* space */
    case 0x6F: return 0xE;     /* 'o' */
    case 0x113: return 0x15;
    case 0x121: return 0x14;
    case 0x1B: return 0x12;    /* Esc: the caller turns this into 0x10 or 0x11 */
    case 0x122: return 0x15;
    case 0x170: return 0;
    case 0x171: return 0;
    case 0x172: return 0;
    case 0x173: return 0;
    case 0x174: return 0;
    case 0x175: return 0;
    case 0x176: return 0;
    case 0x31: return 0x17;    /* '1' */
    case 0x32: return 0x18;    /* '2' */
    case 0x30: return 0x19;    /* '0' */
    case 0x2D: return 0x1A;    /* '-' */
    case 0x2B: return 0x1B;    /* '+' */
    case 0x2C:                 /* ',' */
    default: return 0;
    }
}
#pragma dont_inline reset

#pragma dont_inline on
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

#pragma push
#pragma processor 750
void fn_80008F98(void) {
    char buf[0x40];
    char tmp[8];
    float spC;
    float sp8;
    float f1;
    float f24;
    float f25;
    float f27;
    float f29;
    float f30;
    float f31;
    int r24 = 0;
    int r26 = 0;
    int r31v = 0;
    unsigned int r25;
    extern char lbl_802FB8F0[];
    extern int lbl_8055CFF0;
    extern int lbl_8055CFF4;
    extern float lbl_805601B8;
    extern float lbl_805601D4;
    extern float lbl_805601D8;
    char *p27 = lbl_802FB8F0;
    f27 = lbl_805601BC;
    f29 = lbl_805601DC;
    f30 = lbl_805601E0;
    f31 = lbl_805601E4;
    fn_802E30C8((void *)(p27 + 0x1B0));
    fn_80176A00(1);
    fn_80278894(1);
    r26 = 0;
    __AXDSPInitCallback_801769E0();
    fn_80176734();
    fn_802782C4();
    r25 = (fn_801769F8() == 0);
    while (r26 == 0) {
        unsigned int t = (unsigned int)fn_801769F8();
        if (t != r25) {
            r25 = t;
            if (t == 0) fn_80206454();
            else fn_80206444();
        }
        fn_801E7E48();
        fn_802C8530();
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_801E81B8(1, 0);
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_80230B5C((void *)tmp);
        fn_802C8638((void *)tmp);
        fn_802C974C(lbl_805601B8, lbl_805601D4, lbl_805601D8);
        spC = f27;
        sp8 = f27;
        fn_80278924(&spC, &sp8);
        f1 = fn_801E7E18();
        r31v = 0;
        if (f1 >= spC && f1 <= sp8) r31v = 1;
        if (fn_802787F4() == 0 || r31v == 0) {
            f25 = f29 * (float)lbl_8055CFF0 - f30;
            f24 = f29 * (float)lbl_8055CFF4 - f30;
            fn_80010188(-1, 10, lbl_805589F0, lbl_805601B8, f25, f24, f1);
            f24 += f31;
            if (fn_80278358() != 0) {
                fn_80010188((int)0xFFFF0000, 10, lbl_805589F8, lbl_805601B8, f25, f24);
            }
            f24 += f31;
            if (fn_80278358() == 0) {
                fn_80010188((int)0xFF8040FF, 10, p27 + 0x1C0, lbl_805601B8, f25, f24, spC);
            }
            if (fn_80278358() == 0) {
                fn_80010188((int)0xFF4080FF, 10, p27 + 0x1CC, lbl_805601B8, f25, f24 + f31, sp8);
            }
        }
        fn_802C855C();
        fn_80211F64();
        fn_80129AFC();
        fn_802C2B48();
        if (r24 != 0) {
            r24 = 0;
            __AXDSPInitCallback_801769E0();
        }
        if (fn_802E47B8() != 0) {
            unsigned short code = (unsigned short)fn_802E46F0();
            switch (code) {
            case 0x1B: r26 = 1; break;
            case 0x31: fn_8027889C(f1); fn_802E30C8((void *)(p27 + 0x1D8)); break;
            case 0x32: fn_802788E0(f1); fn_802E30C8((void *)(p27 + 0x1EC)); break;
            case 0x2B: fn_802E30C8((void *)(p27 + 0x200)); fn_802787E4(); break;
            case 0x30:
                fn_80278318();
                __AXDSPInitCallback_801769E0();
                fn_80176734();
                if (code == 0x30) {
                    int v = lbl_8055D398;
                    lbl_8055D398 = v + 1;
                    sprintf(buf, lbl_805589FC, v);
                    fn_80278778(buf);
                    fn_802E30C8((void *)(p27 + 0x218), buf);
                } else {
                    fn_802E30C8((void *)(p27 + 0x23C));
                }
                fn_8026A1F0(0x19, 0, 1);
                break;
            case 0x72:
                __AXDSPInitCallback_801769E0();
                fn_80176734();
                fn_802782C4();
                break;
            case 0x70:
            case 0x113:
                if (fn_801769F8() != 0) fn_801769EC();
                else __AXDSPInitCallback_801769E0();
                fn_8027888C(0);
                break;
            case 0x73:
                r24 = 1;
                fn_8027888C(0);
                fn_801769EC();
                break;
            case 0x46: fn_8027888C(1); break;
            case 0x66: fn_8027888C(0); break;
            case 0x74: fn_80278894(0); break;
            case 0x54: fn_80278894(1); break;
            case 0x121: fn_801E85CC(0); break;
            case 0x122: fn_801E85BC(0); break;
            case 0x170: fn_8026A1F0(4, 0, 0); break;
            case 0x171: fn_8026A1F0(0x11, 0, 0); fn_8026DDD8(0); break;
            case 0x172: fn_8026A1F0(0x11, 0, 0); fn_8026DDD8(1); break;
            case 0x173: fn_8026A1F0(0x11, 0, 0); fn_8026DDD8(2); break;
            case 0x174: fn_8026A1F0(0x11, 0, 0); fn_8026DDD8(3); break;
            case 0x175: fn_8026A1F0(0x11, 0, 0); fn_8026DDD8(4); break;
            default: break;
            }
        }
    }
    fn_80278894(0);
}
#pragma pop

void fn_80009534(void) {
    s32 var16;
    char *p24;
    void *p14;
    s32 var15;
    s32 var23;
    s32 var22;
    s32 var21;
    s32 var20;
    s32 var19;
    s32 var17;
    s32 var18;
    s32 var25;
    s32 var26;
    s32 *p27;
    char *p28;
    s32 flag31;
    char sp8[8];
    s32 v;

    var16 = 0;
    ((u8 *)&lbl_8055D378)[0] = var16;
    p24 = lbl_802FB8F0;
    ((u8 *)&lbl_8055D378)[1] = var16;
    fn_801CEFD4(0);
    fn_80137C74();
    __AXGetStackHead_80137CFC(0);
    fn_80129AEC();
    p14 = fn_801E86F8(0);
    lbl_8055D374 = fn_80145E70(p24 + 0x258);
    var15 = 1;
    lbl_8055D36D = var15;
    lbl_8055D36C = var16;
    lbl_805589B0 = var15;
    lbl_8055D380[0] = fn_802E2C20();
    lbl_8055D380[1] = var16;
    *(s32 *)(lbl_8034F44C + 4) = -0x258;
    *(s32 *)(lbl_8034F44C + 8) = var16;
    lbl_8034F44C[0] = var15;
    lbl_8055D370 = var16;
    fn_80176A00(1);
    fn_80179588();
    fn_80176734();
    var23 = 1;
    var22 = 0;
    var21 = 0;
    var20 = 0;
    var19 = fn_802E2C20() - 0x7D0;
    var17 = 0;
    lbl_8055D37A = var17;
    var18 = fn_8026DDD0();
    var16 = 0;
    if (fn_801CB8FC() != 0)
        goto skip16;
    var16 = 1;
skip16:
    fn_80007210();
    fn_801E7E04(0, 0);
    fn_802E2C20();
    p28 = lbl_8034F44C;
    var25 = 1;
    var26 = 0;
    p27 = lbl_8055D380;
    while (var22 == 0 || var21 < 0x3C) {
        fn_80008390();
        if (var22 != 0)
            var21++;
        else if (fn_8018FD38() != 0 && fn_802E2C20() > var19 + 0x7D0) {
            __AXDSPInitCallback_801769E0();
            fn_80176734();
            var19 = fn_802E2C20();
        }
        v = fn_801769F8();
        if (v != var23) {
            var23 = v;
            if (v != 0)
                fn_80206444();
            else
                fn_80206454();
        }
        v = fn_802ECC10();
        if (v != lbl_8055D39C) {
            lbl_8055D39C = v;
            if (v == 0) {
                if (lbl_8055D39D != 0)
                    fn_801769EC();
            } else if (fn_801769F8() == 0) {
                lbl_8055D39D = var25;
                __AXDSPInitCallback_801769E0();
            } else {
                lbl_8055D39D = var26;
            }
        }
        if (fn_802E47B8() != 0) {
            var15 = fn_802E46F0();
            if (fn_802ECC10() != 0)
                goto do_print;
            fn_802E4A10();
            if (fn_80137C98() >= 0)
                goto check54;
        do_print:
            fn_802E30C8(p24 + 0x268);
            var15 = 0;
        check54:
            if ((unsigned short)var15 == 0x54)
                fn_80008F98();
            if (var22 == 0 && lbl_8055D37A != 0) {
                if ((unsigned short)var15 != 0) {
                    s32 cur = p27[1];
                    if (*(s32 *)(p28 + 8) - cur >= 0xBB8) {
                        if (*(s32 *)(p28 + 4) - cur >= 0x258)
                            *(s32 *)(p28 + 4) = cur;
                        else
                            *(s32 *)(p28 + 4) = *(s32 *)(p28 + 4) - 2 * cur - 0x258;
                    }
                    *(s32 *)(p28 + 8) = cur;
                }
                switch ((unsigned short)var15) {
                case 0x126:
                    if (var16 > 0)
                        var16--;
                    fn_80230E90(1);
                    break;
                case 0x128:
                    if (var16 < 2)
                        var16++;
                    fn_80230E90(1);
                    break;
                case 0x1B:
                    lbl_8055D37A = var26;
                    break;
                case 0xD:
                    if (var16 == 2)
                        lbl_8055D37A = var26;
                    else {
                        fn_8017691C();
                        var22 = 1;
                    }
                    break;
                default:
                    break;
                }
                goto after_first;
            }
            if (fn_801E8838() != 0) {
                var15 = fn_80008DBC(0);
                if (var15 != 0 && fn_80008F68(var15) == 0) {
                    s32 cur = p27[1];
                    if (*(s32 *)(p28 + 8) - cur >= 0xBB8) {
                        if (*(s32 *)(p28 + 4) - cur >= 0x258)
                            *(s32 *)(p28 + 4) = cur;
                        else
                            *(s32 *)(p28 + 4) = *(s32 *)(p28 + 4) - 2 * cur - 0x258;
                    }
                    *(s32 *)(p28 + 8) = cur;
                    if (*(s32 *)(p28 + 8) - cur >= 0xBB8)
                        var15 = 0;
                    else if (*(s32 *)(p28 + 4) - cur < 0x258)
                        var15 = 0;
                }
            }
            if (var17 != 0 && (u32)(var15 - 2) <= 3)
                var15 = 0;
            if (var15 == 0x12)
                var15 = lbl_8055D370 == 0 ? 0x11 : 0x10;
            if (fn_800085D8(var15) == 0)
                var15 = 0;
            flag31 = var15 != 0;
            if ((u32)var15 > 0x1B) {
                fn_802E317C(p24 + 0x274, var15);
            } else {
                switch (var15) {
                case 0:
                    flag31 = 0;
                    break;
                case 1:
                    var17 = var17 == 0;
                    var20 = 0;
                    break;
                case 2:
                    var20 = 1;
                    var17 = 1;
                    fn_8026DDD8(0);
                    break;
                case 3:
                    var20 = 1;
                    var17 = 1;
                    fn_8026DDD8(2);
                    break;
                case 4:
                    var20 = 1;
                    var17 = 1;
                    fn_8026DDD8(1);
                    break;
                case 5:
                    fn_80008618(1);
                    break;
                case 6:
                    fn_80008618(2);
                    break;
                case 7:
                    fn_80008618(4);
                    break;
                case 8:
                    if (fn_800167F4() > 1)
                        fn_801E85DC(0);
                    break;
                case 9:
                    lbl_8055D37A = var25;
                    break;
                case 10:
                    lbl_8055D36C = var26;
                    var19 = fn_802E2C20();
                    __AXDSPInitCallback_801769E0();
                    fn_80176734();
                    break;
                case 11:
                    if (fn_801769F8() != 0) {
                        fn_801E882C();
                        fn_801769EC();
                    } else {
                        __AXDSPInitCallback_801769E0();
                    }
                    break;
                case 12:
                    lbl_805589B0 = lbl_805589B0 == 0;
                    break;
                case 13:
                    lbl_8055D370 = var26;
                    break;
                case 14:
                    lbl_8055D370 = var25;
                    break;
                default:
                    break;
                }
            }
            if (flag31 != 0)
                fn_80012158();
        }
    after_first:
        var15 = fn_80008C5C();
        fn_802C8530();
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_801E7E48();
        fn_8026A1F0(var15, 0, var20);
        var20 = 0;
        fn_801E81B8(1, 0);
        fn_802E2C20();
        fn_802C87B4(0, 0, lbl_8055CFF0, lbl_8055CFF4);
        fn_80230B5C(sp8);
        fn_802C8638(sp8);
        fn_802C974C(lbl_805601B8, lbl_805601D4, lbl_805601D8);
        if (var22 != 0) {
            fn_80012624((float)var21 / lbl_805601E8);
            fn_80206444();
        }
        fn_802C9A70(0);
        flag31 = fn_802E2C20();
        if (fn_802ECC10() == 0) {
            lbl_8055D380[1] += lbl_8055D380[0] - flag31;
        }
        {
            s32 cur = p27[1];
            lbl_8055D380[0] = flag31;
            if (*(s32 *)(p28 + 4) - cur >= 0x258 && *(s32 *)(p28 + 8) - cur > 0xBB8 && *(s32 *)(p28 + 8) - cur < 0xE10)
                *(s32 *)(p28 + 4) = cur;
        }
        if (fn_802787F4() == 0) {
            if (lbl_8055D37A != 0)
                fn_800073D8(var16);
            else
                fn_80008684(var15);
        }
        if (lbl_8055D37A == 0)
            fn_80007318(0);
        if (fn_801E8838() != 0) {
            fn_802C942C(fn_801E8838() << 24);
        }
        fn_802C855C();
        fn_80211F64();
        fn_80129AFC();
        fn_802C2B48();
    }
    fn_80206444();
    fn_801795B0();
    fn_801E86E8(p14, 0);
    fn_8026DDD8(var18);
    if (lbl_8055D374 != 0) {
        lbl_8055D374 = 0;
    }
    lbl_8055D36D = 0;
    fn_801CEFD4(1);
    ((u8 *)&lbl_8055D378)[0] = var16 == 1;
    ((u8 *)&lbl_8055D378)[1] = var16 == 2;
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
