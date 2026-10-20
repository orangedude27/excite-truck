// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef int M2C_UNK;
#define M2C_FIELD(p,T,o) (*(T*)((u8*)(p)+(o)))
#define M2C_STRUCT_COPY(d,s,n) memcpy((d),(s),(n))
extern void *memcpy(void *, const void *, unsigned int);
static inline void CleanupEntries(void *table) {
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128670(s32);
    extern s32 fn_80128668(void *);
    s32 offset, i;
    u8 *entry;
    if (table != 0) {
        i = 0;
        offset = 0;
        for (; i < *(s32 *)((u8 *)table + 4); offset += 0x38, i++) {
            entry = *(u8 **)table + offset;
            fn_802CAC54(*(s32 *)(entry + 0x20));
            fn_802CAC54(*(s32 *)(entry + 0x24));
        }
        fn_80128670(*(s32 *)table);
        fn_80128668(table);
    }
}
extern double lbl_80563958;
extern unsigned char lbl_80498C48[];
s32 fn_8001668C(s32, s32);
s32 *fn_80016BC8(s32);
extern unsigned char lbl_803444D8[];
extern void *lbl_8055F2E4;
extern s32 lbl_8055F2E8;
extern void fn_8024739C(void);
#pragma push
#pragma use_lmw_stmw off
void fn_8024DAD8(void) {
    fn_8024739C();
}

#pragma opt_tail_call on
void fn_8024DADC(void) {
    fn_8024739C();
}

void *fn_8024E920(void *arg0, s32 arg1) {
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    unsigned char *entry;
    s32 i, offset;
    void *table;
    if (arg0 != 0) {
        *(void **)arg0 = lbl_803444D8;
        fn_80128670(*(s32 *)((u8 *)arg0 + 0xCC));
        if (--lbl_8055F2E8 == 0) {
            CleanupEntries(lbl_8055F2E4);
            lbl_8055F2E4 = 0;
        }
        if (arg0 != 0) {
            *(void **)arg0 = lbl_8034453C;
            fn_80128670(*(s32 *)((u8 *)arg0 + 0x18));
            fn_80235380(*(s32 *)((u8 *)arg0 + 0x24));
            fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x20));
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop
s32 fn_8024EB94(void *arg0) { return *(s32 *)((char *)arg0 + 0x1C); }

s32 fn_8024EB9C(void *arg0, s32 arg1) { return *(s32 *)((char *)arg0 + 0xCC) + arg1 * 0x14; }

void fn_8024EBAC(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((char *)arg0 + 0x2C) = arg1;
    if (arg2 != 0) {
        *(f32 *)((char *)arg0 + 0x28) = (f32)arg1;
    }
}

s32 fn_8024EBE4(s32 arg0) {
    s32 value = fn_8001668C(arg0 + 0x60, 0);
    if (lbl_80498C48[4] != 0) {
        return ((s32 *(*)(s32, s32))fn_80016BC8)(value, 0)[0];
    }
    return ((s32 *(*)(s32, s32))fn_80016BC8)(value, 0)[1];
}

#pragma cplusplus on
class Dummy_8024EC3C {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual int f7(int);
};
#pragma cplusplus off
s32 fn_8024EC3C(void) {
    extern unsigned int lbl_8055F2EC;
    extern s32 fn_80129800(s32);
    extern void fn_802E4A10(void);
    extern void fn_80216D28(void);
    extern s32 fn_80214D50(s32);
    s32 enabled = 0;
    fn_802E4A10();
    if (fn_80129800(5) != 0 && fn_80129800(6) != 0) enabled = 1;
    if (enabled != 0) return 1;
    {
        u8 *base = (u8 *)lbl_8055F2EC;
        void *obj = *(void **)(base + 0xD0);
        s32 arg = *(s32 *)(base + 0x2C);
        if (((s32 (*)(void *, s32))(*(void ***)obj)[7])(obj, arg) != 0) return 1;
    }
    fn_80216D28();
    fn_80214D50(1);
    return 0;
}

#pragma push
#pragma processor 750
#pragma use_lmw_stmw off
void *fn_8024F17C(void *arg0, void **arg1, s32 *arg2, s32 *arg3, void *arg4, void *arg5) {
    typedef signed char s8;
    extern f32 lbl_80563960;
    extern unsigned char lbl_80344170[];
    extern unsigned char lbl_8034453C[];
    extern unsigned char lbl_80344720[];
    extern unsigned char lbl_80344730[];
    extern unsigned char lbl_80344740[];
    extern unsigned char lbl_80344750[];
    extern unsigned char lbl_80344760[];
    extern unsigned char lbl_8055C0C0[];
    extern unsigned char lbl_8055C0C8[];
    extern unsigned char lbl_8055C0D0[];
    extern unsigned char lbl_8055C0EC[];
    extern unsigned char lbl_8055C0F0[];
    extern unsigned char lbl_8055C0F4[];
    extern unsigned char lbl_8055C0F8[];
    extern unsigned char lbl_8055C0FC[];
    extern unsigned char lbl_8055C100[];
    extern unsigned char lbl_8055C108[];
    extern unsigned char lbl_8055C10C[];
    extern unsigned char lbl_8055C114[];

    extern void *fn_80016544(void *);
    extern void *fn_80018A8C(void *, void *);
    extern s32 fn_80019258(void *, s32 *, s32 *);
    extern void *fn_8001EFC0(s32, void *);
    extern void *fn_801284F8(unsigned int, void *);
    extern void *fn_8012850C(s32, void *);
    extern void fn_80130FCC(void *, s32, void *);
    extern void *fn_80131808(void *);
    extern void fn_80131818(void *);
    extern void fn_801345D8(void *, s32, void *, ...);
    extern s32 fn_8023512C(void *);
    extern void fn_80255918(void *, s32);
    extern s32 fn_802CAC28(void *, s32);
    extern void fn_802E317C(void *, void *);
    extern int strcmp(const char *, const char *);
    extern int stricmp(const char *, const char *);

    register void *this_obj = arg0;
    register void **v_arg1 = arg1;
    register s32 *v_arg2 = arg2;
    register s32 *v_arg3 = arg3;
    register void *v_arg4 = arg4;
    register void *v_arg5 = arg5;
    const unsigned char *base_4170 = lbl_80344170;

    const char *s;
    void *t7;
    s32 spC;
    s32 sp8;
    void *var_r3_2;
    void *var_r3_3;
    f32 temp_f31;
    void *temp_r21;
    s32 *temp_r4_2;
    void *var_r17;
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r5;
    s32 temp_r5_2;
    void *temp_r6;
    s32 var_r0;
    s32 var_r14;
    s32 var_r16;
    s32 var_r17_2;
    s32 var_r17_3;
    s32 var_r19;
    s32 var_r22;
    s32 var_r22_2;
    s32 var_r23;
    s32 var_r23_2;
    s32 var_r27;
    s32 var_r28;
    s32 var_r4;
    s32 var_r4_5;
    s32 var_r4_6;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_3;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_7;
    u8 *temp_r24;
    u8 *var_r19_2;
    u8 *var_r3;
    u8 *var_r4_2;
    u8 *var_r4_3;
    u8 *var_r4_4;
    u8 *var_r5_6;
    u8 *var_r6;
    u8 *var_r6_2;
    u8 *var_r6_3;
    u8 *var_r6_4;
    u8 *var_r6_5;
    u8 temp_r3_17;
    u8 temp_r3_19;
    u8 temp_r3_22;
    u8 temp_r3_6;
    u8 temp_r4;
    void *temp_r18;
    void **temp_r3_10;
    void **temp_r3_13;
    void **temp_r3_14;
    void **temp_r3_15;
    void **temp_r3_18;
    void **temp_r3_20;
    void **temp_r3_23;
    void **temp_r3_24;
    void **temp_r3_4;
    void **temp_r3_5;
    void **temp_r3_7;
    void **temp_r3_9;
    void *var_r22_3;
    void *temp_r14;
    void *temp_r14_2;
    void *temp_r16;
    void *temp_r26;
    void *temp_r3_11;
    void *temp_r3_12;
    void *temp_r3_16;
    void *temp_r3_21;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_8;
    void *var_r16_2;
    void *var_r18;
    void *var_r20;
    void *var_r21;
    void *var_r24;

    temp_r3 = ((s32 (*)(void *))(*(void ***)v_arg1)[5])(v_arg1);
    M2C_FIELD(this_obj, s32, 0x1C) = temp_r3;
    M2C_FIELD(this_obj, void *, 0) = lbl_8034453C;
    M2C_FIELD(this_obj, s32, 0x14) = 0;
    M2C_FIELD(this_obj, void *, 0x18) = fn_8012850C(temp_r3 * 0xC, lbl_8055C0C8);
    for (var_r4 = 0, var_r5 = 0; var_r4 < M2C_FIELD(this_obj, s32, 0x1C); var_r4++, var_r5 += 0xC) {
        temp_r0 = (s32)M2C_FIELD(this_obj, void *, 0x18);
        temp_r3_2 = (void *)(temp_r0 + var_r5);
        M2C_FIELD(temp_r3_2, s32, 4) = 0;
        *(s32 *)(var_r5 + temp_r0) = 0;
        M2C_FIELD(temp_r3_2, f32, 8) = lbl_80563960;
    }
    M2C_FIELD(this_obj, s32, 0x24) = fn_8023512C((void *)(base_4170 + 0x188));
    M2C_FIELD(this_obj, s32, 0x20) = fn_802CAC28((void *)(base_4170 + 0x198), 0);
    M2C_FIELD(this_obj, s32, 0x2C) = 0;
    M2C_FIELD(this_obj, void *, 0) = lbl_803444D8;
    M2C_FIELD(this_obj, f32, 0x28) = 0.0f;
    if (lbl_8055F2E8 == 0) {
        temp_r3_3 = fn_801284F8(8, lbl_8055C114);
        if (temp_r3_3 != 0) {
            temp_r3_4 = (void **)fn_80131808(lbl_80344760);
            M2C_FIELD(temp_r3_3, s32, 4) = 0;
            M2C_FIELD(temp_r3_3, void *, 0) = fn_8012850C(0xAF0, lbl_8055C10C);
            var_r22 = 0;
loop_27:
            temp_r3_5 = ((void **(*)(void *, s32))temp_r3_4[3])(temp_r3_4, var_r22);
            if (temp_r3_5 != 0) {
                s = ((const char *(*)(void *))temp_r3_5[2])(temp_r3_5);
                if (strcmp(s, (const char *)lbl_8055C108) == 0) {
                    var_r23 = 0;
                    do {
                        temp_r5 = M2C_FIELD(temp_r3_3, s32, 4);
                        temp_r6 = M2C_FIELD(temp_r3_3, void *, 0);
                        M2C_FIELD(temp_r3_3, s32, 4) = temp_r5 + 1;
                        temp_r24 = (u8 *)temp_r6 + (temp_r5 * 0x38);
                        var_r3 = ((u8 *(*)(void *, void *))temp_r3_5[5])(temp_r3_5, lbl_8055C100);
                        var_r6 = temp_r24;
                        var_r5_2 = 0x20;
loop_11:
                        temp_r4 = *var_r3;
                        var_r3 += 1;
                        *var_r6 = temp_r4;
                        var_r6 += 1;
                        if ((s8) temp_r4 != 0) {
                            var_r5_2 -= 1;
                            if (var_r5_2 <= 0) {
                                *(s8 *)(var_r6 - 1) = 0;
                            } else {
                                goto loop_11;
                            }
                        }
                        if (var_r23 != 0) {
                            var_r6_2 = temp_r24;
                            var_r5_3 = 0x20;
loop_15:
                            if ((s8) *var_r6_2 != 0) {
                                var_r5_3 -= 1;
                                var_r6_2 += 1;
                                goto loop_15;
                            }
                            if (var_r5_3 > 0) {
                                var_r4_2 = lbl_8055C0FC;
loop_20:
                                temp_r3_6 = *var_r4_2;
                                var_r4_2 += 1;
                                *var_r6_2 = temp_r3_6;
                                var_r6_2 += 1;
                                if ((s8) temp_r3_6 != 0) {
                                    var_r5_3 -= 1;
                                    if (var_r5_3 <= 0) {
                                        *(s8 *)(var_r6_2 - 1) = 0;
                                    } else {
                                        goto loop_20;
                                    }
                                }
                            }
                        }
                        var_r3_2 = lbl_80344740;
                        if (var_r23 != 0) {
                            var_r3_2 = lbl_80344750;
                        }
                        M2C_FIELD(temp_r24, s32, 0x20) = fn_802CAC28(var_r3_2, 0);
                        var_r3_3 = lbl_80344720;
                        if (var_r23 != 0) {
                            var_r3_3 = lbl_80344730;
                        }
                        M2C_FIELD(temp_r24, s32, 0x24) = fn_802CAC28(var_r3_3, 0);
                        M2C_FIELD(temp_r24, f32, 0x28) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0F8);
                        M2C_FIELD(temp_r24, f32, 0x2C) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0F4);
                        M2C_FIELD(temp_r24, f32, 0x30) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0F0);
                        var_r23 += 1;
                        M2C_FIELD(temp_r24, f32, 0x34) = ((f32 (*)(void *, void *))temp_r3_5[9])(temp_r3_5, lbl_8055C0EC);
                    } while (var_r23 < 2);
                }
                var_r22 += 1;
                goto loop_27;
            }
            fn_80131818(temp_r3_4);
        }
        lbl_8055F2E4 = temp_r3_3;
    }
    temp_r5_2 = lbl_8055F2E8;
    lbl_8055F2E8 = temp_r5_2 + 1;
    M2C_FIELD(this_obj, void *, 0xC8) = lbl_8055F2E4;
    M2C_FIELD(this_obj, void *, 0xD0) = v_arg1;
    M2C_FIELD(this_obj, void *, 0x30) = v_arg2;
    M2C_FIELD(this_obj, void *, 0x34) = v_arg3;
    M2C_FIELD(this_obj, void *, 0x38) = v_arg4;
    M2C_FIELD(this_obj, void *, 0x4C) = v_arg5;
    M2C_FIELD(this_obj, s8, 0x80) = 0;
    M2C_FIELD(this_obj, void *, 0xCC) = fn_8012850C(M2C_FIELD(this_obj, s32, 0x1C) * 0x14, lbl_8055C0D0);
    temp_f31 = lbl_80563960;
    temp_r18 = fn_80131808((void *)(base_4170 + 0x1A8));
    var_r23_2 = 0;
    var_r19 = 0;
    var_r14 = 0;
    var_r16 = 0;
loop_54:
    if (var_r19 < M2C_FIELD(this_obj, s32, 0x1C)) {
        temp_r3_7 = M2C_FIELD(this_obj, void **, 0xD0);
        temp_r21 = (u8 *)M2C_FIELD(this_obj, void *, 0xCC) + var_r14;
        t7 = ((void *(*)(void *, s32))temp_r3_7[6])(temp_r3_7, var_r19);
        temp_r3_8 = (void *)fn_8001668C((s32)t7, 0);
        M2C_FIELD(temp_r21, void *, 8) = temp_r3_8;
        if (M2C_FIELD(temp_r3_8, s32, 4) == *v_arg3) {
            var_r23_2 = var_r19;
        }
        temp_r3_9 = M2C_FIELD(this_obj, void **, 0xD0);
        M2C_FIELD(temp_r21, u8, 0xC) = (u8)((s32 (*)(void *, s32))temp_r3_9[9])(temp_r3_9, var_r19);
        var_r17 = temp_r21;
        var_r22_2 = 0;
        do {
            temp_r3_10 = M2C_FIELD(this_obj, void **, 0xD0);
            var_r24 = ((void *(*)(void *, s32))temp_r3_10[6])(temp_r3_10, var_r19);
            if ((var_r22_2 == 1) && (M2C_FIELD(temp_r21, u8, 0xC) != 0)) {
                temp_r3_11 = fn_80016544((void *)M2C_FIELD(M2C_FIELD(temp_r21, void *, 8), s32, 8));
                if (M2C_FIELD(temp_r3_11, s32, 4) == *v_arg3) {
                    var_r23_2 = var_r19;
                }
                var_r24 = (u8 *)temp_r3_11 + 0x2C;
            }
            temp_r26 = M2C_FIELD(this_obj, void *, 0xC8);
            var_r27 = 0;
            var_r28 = 0;
loop_43:
            if (var_r27 >= M2C_FIELD(temp_r26, s32, 4)) {
                var_r27 = -1;
            } else if (stricmp((char *)M2C_FIELD(temp_r26, void *, 0) + var_r28, (const char *)var_r24) == 0) {

            } else {
                var_r28 += 0x38;
                var_r27 += 1;
                goto loop_43;
            }
            *(s32 *)var_r17 = var_r27;
            if (var_r27 < 0) {
                fn_802E317C((void *)(base_4170 + 0x1B8), var_r24);
            }
            var_r22_2 += 1;
            var_r17 = (u8 *)var_r17 + 4;
        } while (var_r22_2 < 2);
        var_r17_2 = 0;
        if ((*(u8 *)((u8 *)((s32 *(*)(s32, s32))fn_80016BC8)((s32)M2C_FIELD(temp_r21, void *, 8), 0) + 8) != 0) && (M2C_FIELD(temp_r21, u8, 0xC) != 0)) {
            var_r17_2 = 1;
        }
        temp_r3_12 = (u8 *)M2C_FIELD(this_obj, void *, 0x18) + var_r16;
        if (var_r17_2 != M2C_FIELD(temp_r3_12, s32, 4)) {
            M2C_FIELD(temp_r3_12, s32, 4) = var_r17_2;
            M2C_FIELD(temp_r3_12, f32, 8) = (f32) __fabs(M2C_FIELD(temp_r3_12, f32, 8));
        }
        M2C_FIELD(temp_r3_12, s32, 0) = var_r17_2;
        var_r14 += 0x14;
        var_r16 += 0xC;
        M2C_FIELD(temp_r3_12, f32, 8) = temp_f31;
        var_r19 += 1;
        M2C_FIELD(temp_r21, s32, 0x10) = 0;
        goto loop_54;
    }
    fn_80131818(temp_r18);
    temp_r3_13 = M2C_FIELD(this_obj, void **, 0xD0);
    M2C_FIELD(this_obj, s32, 0x2C) = var_r23_2;
    M2C_FIELD(this_obj, f32, 0x28) = (f32) var_r23_2;
    var_r16_2 = ((void *(*)(void *, s32))temp_r3_13[6])(temp_r3_13, var_r23_2);
    fn_8001668C((s32)var_r16_2, 0);
    temp_r14 = var_r16_2;
    if (*(u8 *)((u8 *)((s32 *(*)(s32, s32))fn_80016BC8)((s32)var_r16_2, 0) + 8) != 0) {
        temp_r3_14 = M2C_FIELD(this_obj, void **, 0xD0);
        if (((s32 (*)(void *, s32))temp_r3_14[9])(temp_r3_14, var_r23_2) != 0) {
            temp_r3_15 = M2C_FIELD(this_obj, void **, 0xD0);
            var_r16_2 = ((void *(*)(void *, s32))temp_r3_15[8])(temp_r3_15, var_r23_2);
        }
    }
    temp_r3_16 = (void *)fn_8001668C((s32)var_r16_2, 0);
    var_r4_3 = (u8 *)temp_r3_16 + 0x2C;
    var_r6_3 = (u8 *)this_obj + 0x60;
    var_r5_4 = 0x20;
loop_61:
    temp_r3_17 = *var_r4_3;
    var_r4_3 += 1;
    *var_r6_3 = temp_r3_17;
    var_r6_3 += 1;
    if ((s8) temp_r3_17 != 0) {
        var_r5_4 -= 1;
        if (var_r5_4 <= 0) {
            *(s8 *)(var_r6_3 - 1) = 0;
        } else {
            goto loop_61;
        }
    }
    temp_r3_18 = M2C_FIELD(this_obj, void **, 0xD0);
    if (((s32 (*)(void *, s32))temp_r3_18[9])(temp_r3_18, var_r23_2) != 0) {
        fn_801345D8((u8 *)this_obj + 0x80, 0x40, (void *)(base_4170 + 0x174), (u8 *)temp_r3_16 + 0xD);
    } else {
        var_r4_4 = (u8 *)temp_r3_16 + 0xC;
        var_r6_4 = (u8 *)this_obj + 0x80;
        var_r5_5 = 0x40;
loop_67:
        temp_r3_19 = *var_r4_4;
        var_r4_4 += 1;
        *var_r6_4 = temp_r3_19;
        var_r6_4 += 1;
        if ((s8) temp_r3_19 != 0) {
            var_r5_5 -= 1;
            if (var_r5_5 <= 0) {
                *(s8 *)(var_r6_4 - 1) = 0;
            } else {
                goto loop_67;
            }
        }
    }
    temp_r3_20 = M2C_FIELD(this_obj, void **, 0xD0);
    var_r0 = -1;
    if (((s32 (*)(void *, s32))temp_r3_20[9])(temp_r3_20, var_r23_2) != 0) {
        var_r0 = 5;
    }
    M2C_FIELD(this_obj, s32, 0xC4) = var_r0;
    *v_arg3 = M2C_FIELD(temp_r3_16, s32, 4);
    *v_arg2 = M2C_FIELD(temp_r3_16, s32, 0x9C);
    temp_r16 = v_arg4;
    temp_r3_21 = fn_80018A8C((u8 *)temp_r3_16 + 0x2C, v_arg2);
    if (temp_r3_21 != 0) {
        var_r18 = temp_r16;
        var_r20 = temp_r16;
        M2C_FIELD(temp_r16, s32, 0) = M2C_FIELD(temp_r3_21, s32, 0);
        var_r19_2 = (u8 *)temp_r16 + 0xF4;
        var_r21 = (u8 *)temp_r16 + 8;
        var_r22_3 = (u8 *)temp_r16 + 0x2C;
        var_r17_3 = 0;
        M2C_FIELD(temp_r16, s32, 4) = M2C_FIELD(temp_r3_21, s32, 4);
        M2C_FIELD(temp_r16, s32, 8) = M2C_FIELD(temp_r3_21, s32, 8);
        memcpy(temp_r16, temp_r3_21, 0x20);
        do {
            var_r6_5 = M2C_FIELD(var_r18, u8 *, 4);
            if (var_r6_5 != 0) {
                var_r5_6 = var_r19_2;
                var_r4_5 = 0x64;
loop_76:
                temp_r3_22 = *var_r6_5;
                var_r6_5 += 1;
                *var_r5_6 = temp_r3_22;
                var_r5_6 += 1;
                if ((s8) temp_r3_22 == 0) {

                } else {
                    var_r4_5 -= 1;
                    if (var_r4_5 <= 0) {
                        *(s8 *)(var_r5_6 - 1) = 0;
                    } else {
                        goto loop_76;
                    }
                }
            } else {
                *(s8 *)((u8 *)var_r20 + 0xF4) = 0;
            }
            ((void (*)(void *, s32, void *, void *))(*(void ***)var_r22_3)[0x18])(var_r22_3, var_r17_3, var_r21, (u8 *)temp_r16 + 0x2E8);
            var_r17_3 += 1;
            var_r18 = (u8 *)var_r18 + 8;
            var_r19_2 += 0x64;
            var_r20 = (u8 *)var_r20 + 0x64;
            var_r21 = (u8 *)var_r21 + 8;
            var_r22_3 = (u8 *)var_r22_3 + 0x28;
        } while (var_r17_3 < 5);
    } else {
        memset(temp_r16, 0, 0x2C);
        *(s8 *)((u8 *)temp_r16 + 0xF4) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x158) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x1BC) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x220) = 0;
        *(s8 *)((u8 *)temp_r16 + 0x284) = 0;
    }
    temp_r3_23 = M2C_FIELD(this_obj, void **, 0xD0);
    *(s8 *)((u8 *)v_arg5 + 0xDD) = (s8)(((s32 (*)(void *, s32))temp_r3_23[7])(temp_r3_23, var_r23_2) == 0);
    sp8 = -1;
    spC = -1;
    if (fn_80019258(temp_r14, &sp8, &spC) == 0) {
        spC = -1;
        sp8 = -1;
    }
    temp_r3_24 = M2C_FIELD(this_obj, void **, 0xD0);
    if ((((s32 (*)(void *, s32))temp_r3_24[9])(temp_r3_24, var_r23_2) == 0) && (sp8 >= 0) && (spC >= 0)) {
        fn_801345D8((u8 *)this_obj + 0x3C, 0x10, lbl_8055C0C0, fn_8001EFC0(0, (u8 *)this_obj + 0x60), sp8);
        fn_801345D8((u8 *)this_obj + 0x50, 0x10, lbl_8055C0C0, fn_8001EFC0(1, (u8 *)this_obj + 0x60), spC);
    } else {
        fn_80130FCC((u8 *)this_obj + 0x3C, 0x10, fn_8001EFC0(0, (u8 *)this_obj + 0x60));
        fn_80130FCC((u8 *)this_obj + 0x50, 0x10, fn_8001EFC0(1, (u8 *)this_obj + 0x60));
    }
    temp_r14_2 = (void *)fn_8001668C((s32)((u8 *)this_obj + 0x60), 0);
    fn_8001668C((s32)((u8 *)this_obj + 0x60), 0);
    if (lbl_80498C48[4] != 0) {
        var_r5_7 = *(s32 *)((s32 *(*)(s32, s32))fn_80016BC8)(0, 0);
    } else {
        var_r5_7 = ((s32 *)((s32 *(*)(s32, s32))fn_80016BC8)(0, 0))[1];
    }
    var_r4_6 = *(s32 *)((u8 *)M2C_FIELD(this_obj, void *, 0xCC) + (M2C_FIELD(this_obj, s32, 0x2C) * 0x14) + 0x10);
    if (var_r4_6 == 0) {
        var_r4_6 = *(s32 *)((u8 *)temp_r14_2 + (var_r5_7 * 4) + 0x64);
    }
    fn_80255918(v_arg5, var_r4_6);
    M2C_FIELD(this_obj, s32, 0xC0) = 1;
    return this_obj;
}
#pragma pop
typedef unsigned int u32;
extern unsigned char lbl_8034453C[];
extern s32 fn_80128670(s32);
extern s32 fn_80235380(s32);
extern s32 fn_802CAC54(s32);
extern s32 fn_80128668(void *);
void *fn_8024FB64(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)arg0 = lbl_8034453C;
        fn_80128670(*(s32 *)((u8 *)arg0 + 0x18));
        fn_80235380(*(s32 *)((u8 *)arg0 + 0x24));
        fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x20));
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void *fn_8024FFF8(void *arg0, s32 arg1) {
    extern char lbl_803443B0[];
    if (arg0) {
        register void *child = *(void **)((char *)arg0 + 0x188);
        *(void **)arg0 = lbl_803443B0;
        if (child) {
            ((void (*)(void *, s32))(*(void ***)child)[2])(child, 1);
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_80250108(void *arg0) {
    extern f32 fn_80214D48(void);
    extern f32 lbl_80563960;
    extern const f32 lbl_80563964, lbl_80563968, lbl_8056396C, lbl_80563970;
    f32 limit, speed, subtract, threshold;
    f32 dt = fn_80214D48();
    s32 offset;
    s32 i;
    f32 current;
    i = 0;
    offset = 0;
    limit = lbl_80563960;
    current = *(f32 *)((u8 *)arg0 + 0x28);
    *(f32 *)((u8 *)arg0 + 0x28) = current + lbl_80563968 * ((f32)*(s32 *)((u8 *)arg0 + 0x2C) - current);
    speed = lbl_8056396C;
    subtract = lbl_80563970;
    threshold = lbl_80563964;
    for (; i < *(s32 *)((u8 *)arg0 + 0x1C); offset += 12, i++) {
        u8 *entry = *(u8 **)((u8 *)arg0 + 0x18) + offset;
        if (*(s32 *)(entry + 4) != *(s32 *)entry) {
            *(f32 *)(entry + 8) += speed * dt;
            if (*(f32 *)(entry + 8) >= threshold) {
                *(s32 *)entry = *(s32 *)(entry + 4);
                *(f32 *)(entry + 8) -= subtract;
            }
        } else {
            f32 value = *(f32 *)(entry + 8) + speed * dt;
            if (limit < value) value = limit;
            *(f32 *)(entry + 8) = value;
        }
    }
}

extern f32 lbl_80563960;
extern void fn_802354A0(s32, s32, f32, f32, f32, f32, f32, s32);
extern f32 fn_80216CB4(void);
#pragma push
#pragma processor 750
void fn_802514B4(void *arg0, s32 arg1, f32 x, f32 y, f32 w, f32 h) {
    s32 value = *(s32 *)(*(char **)((char *)arg0 + 0xCC) + arg1 * 0x14 + 0x10);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 0, -1, x, y, lbl_80563960, w, h);
    fn_80216CB4();
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 3, value, x, y, lbl_80563960, w, h);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 6, -1, x, y, lbl_80563960, w, h);
}
#pragma pop
extern void fn_80255904(s32);
extern void fn_80214A9C(s32, f32);
extern void fn_80221F94(void *, s32);
extern void *fn_801284F8(u32, void *);
extern void *fn_8012850C(s32, void *);
extern void fn_801312EC(void *, void *);
extern f32 lbl_80563960, lbl_805639C0, lbl_80558DC4;
extern char lbl_8055C0E0[];
extern char lbl_80344378[], lbl_80344384[], lbl_80344690[], lbl_803443B0[];
void fn_80251D0C(void *arg0) {
    fn_80255904(*(s32 *)((char *)arg0 + 0x20));
    *(s32 *)((char *)arg0 + 0x190) = -1;
    *(u8 *)((char *)arg0 + 0x28) = 0; *(u8 *)((char *)arg0 + 0x48) = 0;
    *(u8 *)((char *)arg0 + 0x88) = 0; *(u8 *)((char *)arg0 + 0x108) = 0;
    *(f32 *)((char *)arg0 + 0x194) = lbl_80563960;
    *(f32 *)((char *)arg0 + 0x198) = lbl_805639C0;
    fn_80214A9C(0x1f, lbl_80563960);
    *(u8 *)((char *)arg0 + 0x19c) = 0;
}

s32 fn_80252238(void *arg0, s32 arg1) {
    extern f32 lbl_80558DC4;
    if (arg1 != 13) return 0;
    if ((f32)fabs((double)*(f32 *)((char *)arg0 + 0x194)) > lbl_80558DC4) return 0;
    if ((f32)fabs((double)*(f32 *)((char *)arg0 + 0x198)) > lbl_80558DC4) return 0;
    fn_80221F94(arg0, 0);
    return 1;
}

#pragma push
#pragma opt_common_subs off
void *fn_802522A8(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        if ((char *)arg0 + 4 != 0) {
            fn_80128670(*(s32 *)((char *)arg0 + 0x10));
            if ((char *)arg0 + 4 != 0) {
                *(s32 *)((char *)arg0 + 4) = 0;
                *(s32 *)((char *)arg0 + 8) = 0;
                *(s32 *)((char *)arg0 + 0xC) = 0;
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma pop

void fn_80252454(void *arg0, s32 arg1, s32 arg2) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    *(s32 *)((char *)base + offset + 0x44) = arg2;
}

s32 fn_80252468(void *arg0) { return *(s32 *)((char *)arg0 + 8); }

s32 fn_80252470(void *arg0, s32 arg1) { return *(s32 *)((char *)arg0 + 4) + arg1 * 0x48; }

u8 fn_80252480(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    return *(u8 *)((char *)base + offset + 0x20);
}

char *fn_80252494(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    char *base = *(char **)((char *)arg0 + 4);
    return base + offset + 0x21;
}

u8 fn_802524A8(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    return *(u8 *)((char *)base + offset + 0x41);
}

s32 fn_802524BC(void *arg0, s32 arg1) {
    s32 offset = arg1 * 0x48;
    s32 *base = *(s32 **)((char *)arg0 + 4);
    return *(s32 *)((char *)base + offset + 0x44);
}

