// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef int M2C_UNK;
extern void *fn_801284F8(unsigned int, void *);
extern void *fn_8012850C(s32, void *);
extern void fn_801312EC(void *, void *);
__declspec(section ".sdata") extern char lbl_8055C0E0[];
extern char lbl_80344378[], lbl_80344384[], lbl_80344690[];
extern unsigned char lbl_8055C0E8;
extern unsigned int lbl_8055E044;
extern unsigned char *fn_80019098(unsigned char *);
extern int fn_80131318(void *);
extern u8 *fn_80131234(void *);
extern unsigned char lbl_8034287C[];
extern char *strncpy(char *, const char *, unsigned int);
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
extern unsigned char lbl_8055C0C0;
extern void fn_801345D8(void *, s32, void *, ...);
extern void *lbl_8055F2E4;
extern s32 lbl_8055F2E8;
extern unsigned int lbl_8055F2EC;
extern void *fn_80018A8C(void *, void *);
extern s32 fn_80019258(void *, s32 *, s32 *);
extern void *fn_8001EFC0(s32, void *);
extern void fn_80130FCC(void *, s32, void *);
extern void fn_801345D8(void *, s32, void *, ...);
extern void fn_80255918(void *, s32);
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

#pragma push
#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" void *fn_8024E6E4(void *arg0, s32 arg1) {
    extern unsigned char lbl_80344410[];
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    class V { public: virtual void f2(int); };
    V *object;
    if (arg0 != 0) {
        object = *(V **)((u8 *)arg0 + 0xD4);
        *(void **)arg0 = lbl_80344410;
        if (object != 0) object->f2(1);
        if (arg0 != 0) {
            *(void **)arg0 = lbl_803444D8;
            fn_80128670(*(s32 *)((u8 *)arg0 + 0xCC));
            if (--lbl_8055F2E8 == 0) { CleanupEntries(lbl_8055F2E4); lbl_8055F2E4 = 0; }
            if (arg0 != 0) {
                *(void **)arg0 = lbl_8034453C;
                fn_80128670(*(s32 *)((u8 *)arg0 + 0x18));
                fn_80235380(*(s32 *)((u8 *)arg0 + 0x24));
                fn_802CAC54(*(s32 *)((u8 *)arg0 + 0x20));
            }
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}
#pragma scheduling on
#pragma pop
void *fn_8024E818(void *arg0, s32 arg1) {
    extern unsigned int lbl_8055F2EC;
    extern unsigned char lbl_8034453C[];
    extern s32 fn_80128670(s32);
    extern s32 fn_80235380(s32);
    extern s32 fn_802CAC54(s32);
    extern s32 fn_80128668(void *);
    if (arg0 != 0) {
        lbl_8055F2EC = 0;
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
        }
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
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

#pragma push
#pragma opt_common_subs off
#pragma scheduling invalid_target
void fn_8024EA1C(s32 arg0) {
    s32 base = fn_8001668C(arg0 + 0x60, 0);
    s32 *secondary;
    s32 choiceBase;
    s32 selected;
    u8 *dst;
    u8 *src;
    s32 count;
    u8 c;

    if (lbl_80498C48[4] != 0) {
        ((s32 *(*)(s32, s32))fn_80016BC8)(base, 0)[0] =
            *(s32 *)((u8 *)arg0 + 0x2C);
    } else {
        ((s32 *(*)(s32, s32))fn_80016BC8)(base, 0)[1] =
            *(s32 *)((u8 *)arg0 + 0x2C);
    }

    *(s32 *)*(s32 **)((u8 *)arg0 + 0xDC) =
        *(s32 *)((u8 *)base +
                 *(s32 *)((u8 *)arg0 + 0x2C) * 4 + 0x64);

    secondary = (s32 *)fn_8001668C(arg0 + 0x60, 0);
    choiceBase = fn_8001668C(arg0 + 0x60, 0);
    if (lbl_80498C48[4] != 0) {
        selected = ((s32 *(*)(s32, s32))fn_80016BC8)(choiceBase, 0)[0];
    } else {
        selected = ((s32 *(*)(s32, s32))fn_80016BC8)(choiceBase, 0)[1];
    }

    {
        s32 value = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0xCC) +
                             *(s32 *)((u8 *)arg0 + 0x2C) * 0x14 + 0x10);
        if (value == 0) {
            value = *(s32 *)((u8 *)secondary + selected * 4 + 0x64);
        }
        fn_80255918(*(void **)((u8 *)arg0 + 0x4C), value);
    }

    fn_801345D8((u8 *)arg0 + 0xE0, 0x100, lbl_8034287C,
                *(s32 *)((u8 *)arg0 + 0x2C) + 1);
    src = fn_80131234((u8 *)arg0 + 0xE0);
    dst = (u8 *)arg0 + 0xE0;
    count = 0x100;
    goto copy_loop;
copy_count:
    count--;
    if (count <= 0) {
        dst[-1] = 0;
        return;
    }
copy_loop:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) {
        goto copy_count;
    }
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
    virtual void d4(); virtual int f5(int);
};
#pragma cplusplus on
extern "C" s32 fn_8024EC3C(void) {
    extern unsigned int lbl_8055F2EC;
    extern s32 fn_80129800(void *, int);
    extern s32 fn_802E4A10(void);
    extern void fn_80216D28(void);
    extern s32 fn_80214D50(s32);
    s32 enabled = 0;
    if (fn_80129800((void *)fn_802E4A10(), 5) != 0) {
        if (fn_80129800((void *)fn_802E4A10(), 6) != 0) enabled = 1;
    }
    if (enabled == 0) {
        u8 *base = (u8 *)lbl_8055F2EC;
        void *obj = *(void **)(base + 0xD0);
        s32 arg = *(s32 *)(base + 0x2C);
        if (((Dummy_8024EC3C *)obj)->f5(arg) == 0) goto do_callback;
    }
    return 1;
do_callback:
    fn_80216D28();
    fn_80214D50(1);
    return 0;
}

extern "C" void *memset(void *, int, unsigned int);

extern unsigned char lbl_803442E4[];
extern "C" s32 fn_80129D18(s32, s32);
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
extern "C" s32 fn_8024ECD4(void) {
    typedef signed char s8;
    typedef void *(*VCall)(void *, s32);
    typedef s32 (*VTest)(void *, s32);
    typedef void *(*VGet)(void *, s32);
    typedef s32 (*VFill)(void *, s32, void *, void *);
    class Table {
    public:
        virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
        virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7();
        virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11();
        virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
        virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19();
        virtual void t20(); virtual void t21();
        virtual void fill(s32, void *, void *);
    };
    class Selector {
    public:
        virtual void v0(); virtual void v1(); virtual void v2();
        virtual void v3();
        virtual void *get0(s32); virtual s32 get1(s32);
        virtual void *get2(s32); virtual s32 get3(s32);
    };
    void *temp_r31;
    u8 *temp_r30;
    void *var_r21;
    s32 temp_r3_14;
    s32 var_r0;
    register s32 copy_a;
    s32 var_r29;
    register s32 temp_r3;
    s32 temp_r3_end;
    s32 spC;
    s32 sp8;
    s32 *temp_r4;
    s32 temp_9c;
    register s32 copy_b;
    s32 var_r4_4;
    void *call_obj;
    s32 var_r4_3;
    u8 *var_r4;
    u8 *var_r4_2;
    s32 var_r5;
    s32 var_r5_2;
    s32 var_r5_4;
    u8 *var_r5_3;
    u8 *var_r6;
    u8 *var_r6_2;
    u8 *var_r6_3;
    s32 temp_r3_11;
    s32 temp_r3_6;
    s32 temp_r3_8;
    void **temp_r3_2;
    u8 *temp_r23;
    void *temp_r3_10;
    void **temp_r3_12;
    void **temp_r3_13;
    void **temp_r3_3;
    void **temp_r3_4;
    u8 *temp_r3_5;
    void **temp_r3_7;
    void **temp_r3_9;
    u8 *var_r27;
    u8 *var_r26;
    u8 *var_r25;
    u8 *var_r24;
    u8 *var_r23;
    u8 *temp_r22;

    temp_r3 = fn_80129D18(1, M2C_FIELD(lbl_8055F2EC, s32, 0x1C) - 1);
    temp_r22 = (u8 *)lbl_8055F2EC;
    M2C_FIELD(temp_r22, s32, 0x2C) = temp_r3;
    var_r21 = (*(Selector **)(temp_r22 + 0xD0))->get0(temp_r3);
    temp_r3_14 = fn_8001668C((s32)var_r21, 0);
    temp_r31 = var_r21;
    if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_14, 0), u8, 8) != 0) {
        if ((*(Selector **)(temp_r22 + 0xD0))->get3(temp_r3) != 0) {
            var_r21 = (*(Selector **)(temp_r22 + 0xD0))->get2(temp_r3);
        }
    }
    temp_r3_5 = (u8 *)fn_8001668C((s32)var_r21, 0);
    var_r4 = temp_r3_5 + 0x2C;
    var_r6 = temp_r22 + 0x60;
    var_r5 = 0x20;
    goto copy_loop_a_body;
copy_loop_a_count:
    var_r5--;
    if (var_r5 > 0) goto copy_loop_a_body;
    M2C_FIELD(var_r6, s8, -1) = 0;
    goto copy_loop_a_end;
copy_loop_a_body:
    temp_r3_6 = *var_r4++;
    *var_r6++ = temp_r3_6;
    if ((s8)temp_r3_6 != 0) goto copy_loop_a_count;
copy_loop_a_end:
    if ((*(Selector **)(temp_r22 + 0xD0))->get3(temp_r3) != 0) {
        fn_801345D8(temp_r22 + 0x80, 0x40, &lbl_803442E4, temp_r3_5 + 0xD);
    } else {
        var_r4_2 = temp_r3_5 + 0xC;
        var_r6_2 = temp_r22 + 0x80;
        var_r5_2 = 0x40;
        goto copy_loop_b_body;
copy_loop_b_count:
        var_r5_2--;
        if (var_r5_2 > 0) goto copy_loop_b_body;
        M2C_FIELD(var_r6_2, s8, -1) = 0;
        goto copy_loop_b_end;
copy_loop_b_body:
        temp_r3_8 = *var_r4_2++;
        *var_r6_2++ = temp_r3_8;
        if ((s8)temp_r3_8 != 0) goto copy_loop_b_count;
copy_loop_b_end: ;
    }
    M2C_FIELD(temp_r22, s32, 0xC4) = ((*(Selector **)(temp_r22 + 0xD0))->get3(temp_r3) != 0) ? 5 : -1;
    *M2C_FIELD(temp_r22, s32 **, 0x34) = M2C_FIELD(temp_r3_5, s32 *, 4);
    temp_9c = *(volatile s32 *)((u8 *)temp_r3_5 + 0x9C);
    temp_r4 = *(s32 * volatile *)((u8 *)temp_r22 + 0x30);
    *temp_r4 = temp_9c;
    temp_r30 = (u8 *)M2C_FIELD(temp_r22, void *, 0x38);
    temp_r3_10 = fn_80018A8C(temp_r3_5 + 0x2C, temp_r4);
    if (temp_r3_10 != 0) {
        var_r27 = temp_r30;
        var_r25 = temp_r30;
        M2C_FIELD(temp_r30, s32, 0) = M2C_FIELD(temp_r3_10, s32, 0);
        copy_b = M2C_FIELD(temp_r3_10, s32, 4);
        copy_a = M2C_FIELD(temp_r3_10, s32, 8);
        M2C_FIELD(temp_r30, s32, 4) = copy_b;
        M2C_FIELD(temp_r30, s32, 8) = copy_a;
        copy_a = M2C_FIELD(temp_r3_10, s32, 0xC);
        copy_b = M2C_FIELD(temp_r3_10, s32, 0x10);
        M2C_FIELD(temp_r30, s32, 0xC) = copy_a;
        M2C_FIELD(temp_r30, s32, 0x10) = copy_b;
        copy_a = M2C_FIELD(temp_r3_10, s32, 0x14);
        copy_b = M2C_FIELD(temp_r3_10, s32, 0x18);
        M2C_FIELD(temp_r30, s32, 0x14) = copy_a;
        M2C_FIELD(temp_r30, s32, 0x18) = copy_b;
        copy_a = M2C_FIELD(temp_r3_10, volatile s32, 0x1C);
        copy_b = M2C_FIELD(temp_r3_10, volatile s32, 0x20);
        M2C_FIELD(temp_r30, s32, 0x1C) = copy_a;
        M2C_FIELD(temp_r30, s32, 0x20) = copy_b;
        copy_a = M2C_FIELD(temp_r3_10, volatile s32, 0x24);
        copy_b = M2C_FIELD(temp_r3_10, volatile s32, 0x28);
        M2C_FIELD(temp_r30, s32, 0x24) = copy_a;
        M2C_FIELD(temp_r30, s32, 0x28) = copy_b;
        var_r26 = temp_r30 + 0xF4;
        var_r24 = temp_r30 + 8;
        var_r23 = temp_r30 + 0x2C;
        var_r29 = 0;
        do {
            var_r6_3 = M2C_FIELD(var_r27, u8 *, 4);
            if (var_r6_3 != 0) {
                var_r5_3 = var_r26;
                var_r4_3 = 0x64;
                goto copy_loop_c_body;
copy_loop_c_count:
                var_r4_3--;
                if (var_r4_3 > 0) goto copy_loop_c_body;
                M2C_FIELD(var_r5_3, s8, -1) = 0;
                goto copy_loop_c_end;
copy_loop_c_body:
                temp_r3_11 = *var_r6_3++;
                *var_r5_3++ = temp_r3_11;
                if ((s8)temp_r3_11 != 0) {
                    goto copy_loop_c_count;
                } else {
                    goto copy_loop_c_end;
                }
copy_loop_c_end: ;
            } else {
                M2C_FIELD(var_r25, s8, 0xF4) = 0;
            }
            ((Table *)var_r23)->fill(var_r29, var_r24, temp_r30 + 0x2E8);
            var_r29 += 1;
            var_r27 += 8;
            var_r26 += 0x64;
            var_r25 += 0x64;
            var_r24 += 8;
            var_r23 += 0x28;
        } while (var_r29 < 5);
    } else {
        memset(temp_r30, 0, 0x2C);
        M2C_FIELD(temp_r30, s8, 0xF4) = 0;
        M2C_FIELD(temp_r30, s8, 0x158) = 0;
        M2C_FIELD(temp_r30, s8, 0x1BC) = 0;
        M2C_FIELD(temp_r30, s8, 0x220) = 0;
        M2C_FIELD(temp_r30, s8, 0x284) = 0;
    }
    M2C_FIELD(M2C_FIELD(temp_r22, void *, 0x4C), s8, 0xDD) = (s8) ((*(Selector **)(temp_r22 + 0xD0))->get1(temp_r3) == 0);
    sp8 = -1;
    spC = -1;
    if (fn_80019258(temp_r31, &sp8, &spC) == 0) {
        spC = -1;
        sp8 = -1;
    }
    if (((*(Selector **)(temp_r22 + 0xD0))->get3(temp_r3) == 0) && (sp8 >= 0) && (spC >= 0)) {
        fn_801345D8(temp_r22 + 0x3C, 0x10, &lbl_8055C0C0, fn_8001EFC0(0, temp_r22 + 0x60), sp8);
        fn_801345D8(temp_r22 + 0x50, 0x10, &lbl_8055C0C0, fn_8001EFC0(1, temp_r22 + 0x60), spC);
    } else {
        fn_80130FCC(temp_r22 + 0x3C, 0x10, fn_8001EFC0(0, temp_r22 + 0x60));
        fn_80130FCC(temp_r22 + 0x50, 0x10, fn_8001EFC0(1, temp_r22 + 0x60));
    }
    temp_r23 = (u8 *)fn_8001668C((s32)(temp_r22 + 0x60), 0);
    temp_r3_end = fn_8001668C((s32)(temp_r22 + 0x60), 0);
    if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) {
        var_r5_4 = *((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0);
    } else {
        var_r5_4 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
    }
    call_obj = M2C_FIELD(temp_r22, void *, 0x4C);
    var_r4_4 = M2C_FIELD(((u8 *)M2C_FIELD(temp_r22, s32 *, 0xCC) + (M2C_FIELD(temp_r22, s32, 0x2C) * 0x14)), s32, 0x10);
    switch (var_r4_4) {
    case 0:
        var_r4_4 = M2C_FIELD((temp_r23 + (var_r5_4 * 4)), s32, 0x64);
        break;
    default:
        break;
    }
    fn_80255918(call_obj, var_r4_4);
    return 0;
}
#pragma pop

#pragma cplusplus off

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
    extern unsigned char lbl_8055C0C0;
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
        fn_801345D8((u8 *)this_obj + 0x3C, 0x10, &lbl_8055C0C0, fn_8001EFC0(0, (u8 *)this_obj + 0x60), sp8);
        fn_801345D8((u8 *)this_obj + 0x50, 0x10, &lbl_8055C0C0, fn_8001EFC0(1, (u8 *)this_obj + 0x60), spC);
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

void fn_8024FBD8(void *arg0, s32 arg1) {
    extern void fn_8013C804(void);
    extern void fn_8001880C(void);
    extern void fn_802556BC(void *, s32);
    extern s32 fn_802E4A10(void);
    extern void fn_8002F53C(void *, void *, void *, s32, s32);
    extern void fn_8002F634(void *, void *, s32, s32);
    extern void fn_80018B24(void);
    extern void fn_8013C8B8(void);
    extern void fn_802146BC(s32 *, s32, s32, s32);
    extern void fn_80255758(void *, s32);
    extern void *fn_80258354(void);
    extern unsigned char lbl_80344170[];
    extern char lbl_803443B0[];
    extern unsigned char lbl_803446AC[];
    extern unsigned char lbl_803446B8[];
    extern unsigned char lbl_803446C8[];
    extern unsigned char lbl_80498C30[];
    extern unsigned char lbl_802FA594[];
    extern unsigned char lbl_8055C0D8;
    extern const f32 lbl_80563964;
    extern s32 fn_80241098(void);
    extern s32 fn_80240928(void);
    u8 stack[0x778];
    u8 *s = stack;
    s32 i, count;
    void *object;
    fn_8013C804();
    fn_8001880C();
    fn_802556BC(s+0x320, 1);
    *(s32 *)(s+0x3f8) = fn_802E4A10();
    fn_8002F53C(s+0x470, fn_80241098, fn_80240928, 0x28, 5);
    memset(s+0x444, 0, 0x2c);
    *(void **)(s+0x198) = arg0;
    *(s32 *)(s+0x194) = 0;
    *(void **)(s+0x180) = lbl_803443B0;
    *(void **)(s+0x1a0) = s+0x320;
    *(void **)(s+0x1a4) = s+0x444;
    *(s32 *)(s+0x19c) = 0;
    if (arg1 != 0) *(s32 *)(s+0x19c) = arg1;
    *(u8 *)(s+0x538) = 0;
    *(u8 *)(s+0x59c) = 0;
    *(u8 *)(s+0x5fc) = 0;
    *(u8 *)(s+0x660) = 0;
    *(u8 *)(s+0x6c4) = 0;
    object = fn_80258354();
    *(void **)(s+0x308) = object;
    if (object != 0) {
        (*(void (**)(void *, void *, void *, s32))(*(void ***)object+5))
            (object, lbl_803446C8, lbl_803446B8, 0);
        (*(void (**)(void *, void *, f32))(*(void ***)object+16))
            (object, lbl_803446AC, lbl_80563964);
    }
    *(void **)(s+0x18)=s+0x180;
*(s32 *)(s+0x1c)=5;
*(void **)(s+0x20)=lbl_80344170+0x40;
*(s32 *)(s+0x24)=0;
*(s32 *)(s+0x28)=0;
*(void **)(s+0x2c)=&lbl_8055C0D8;
*(s32 *)(s+0x30)=3;
*(void **)(s+0x34)=s+0x288;
*(s32 *)(s+0x38)=0;
*(s32 *)(s+0x3c)=0;
*(void **)(s+0x40)=lbl_80344170+0x40;
*(s32 *)(s+0x44)=0x13;
*(void **)(s+0x48)=s+0x320;
*(s32 *)(s+0x4c)=0;
*(s32 *)(s+0x50)=0;
*(void **)(s+0x54)=lbl_80344170+0x40;
*(s32 *)(s+0x58)=3;
*(void **)(s+0x5c)=s+0x1a8;
*(s32 *)(s+0x60)=0;
*(s32 *)(s+0x64)=0;
*(s32 *)(s+0x68)=5;
*(void **)(s+0x6c)=lbl_80344170+0x58;
*(void **)(s+0x70)=s+0x41c;
*(s32 *)(s+0x74)=0;
*(s32 *)(s+0x78)=0;
*(void **)(s+0x7c)=lbl_80344170+0x1f0;
*(s32 *)(s+0x80)=3;
*(void **)(s+0x84)=s+0x208;
*(s32 *)(s+0x88)=0;
*(s32 *)(s+0x8c)=0;
*(void **)(s+0x90)=lbl_80344170+0x1fc;
*(s32 *)(s+0x94)=3;
*(void **)(s+0x98)=s+0x1c8;
*(s32 *)(s+0x9c)=0;
*(s32 *)(s+0xa0)=0;
*(void **)(s+0xa4)=lbl_80344170+0x68;
*(s32 *)(s+0xa8)=3;
*(void **)(s+0xac)=s+0x538;
*(s32 *)(s+0xb0)=0;
*(s32 *)(s+0xb4)=0;
*(void **)(s+0xb8)=lbl_80344170+0x78;
*(s32 *)(s+0xbc)=2;
*(void **)(s+0xc0)=s+0x444;
*(s32 *)(s+0xc4)=0;
*(s32 *)(s+0xc8)=0;
*(void **)(s+0xcc)=lbl_80344170+0x84;
*(s32 *)(s+0xd0)=3;
*(void **)(s+0xd4)=s+0x59c;
*(s32 *)(s+0xd8)=0;
*(s32 *)(s+0xdc)=0;
*(void **)(s+0xe0)=lbl_80344170+0x94;
*(s32 *)(s+0xe4)=2;
*(void **)(s+0xe8)=s+0x454;
*(s32 *)(s+0xec)=0;
*(s32 *)(s+0xf0)=0;
*(void **)(s+0xf4)=lbl_80344170+0xa0;
*(s32 *)(s+0xf8)=3;
*(void **)(s+0xfc)=s+0x5fc;
*(s32 *)(s+0x100)=0;
*(s32 *)(s+0x104)=0;
*(void **)(s+0x108)=lbl_80344170+0xb0;
*(s32 *)(s+0x10c)=2;
*(void **)(s+0x110)=s+0x45c;
*(s32 *)(s+0x114)=0;
*(s32 *)(s+0x118)=0;
*(void **)(s+0x11c)=lbl_80344170+0xbc;
*(s32 *)(s+0x120)=3;
*(void **)(s+0x124)=s+0x660;
*(s32 *)(s+0x128)=0;
*(s32 *)(s+0x12c)=0;
*(void **)(s+0x130)=lbl_80344170+0xcc;
*(s32 *)(s+0x134)=5;
*(void **)(s+0x138)=s+0x4e8;
*(s32 *)(s+0x13c)=0;
*(s32 *)(s+0x140)=0;
*(void **)(s+0x144)=lbl_80344170+0xdc;
*(s32 *)(s+0x148)=3;
*(void **)(s+0x14c)=s+0x6c4;
*(s32 *)(s+0x150)=0;
*(s32 *)(s+0x154)=0;
*(void **)(s+0x158)=lbl_80344170+0xec;
*(s32 *)(s+0x15c)=2;
*(void **)(s+0x160)=s+0x46c;
*(s32 *)(s+0x164)=0;
*(s32 *)(s+0x168)=0;
    *(s32 *)(s+0x16c) = *(s32 *)lbl_80498C30;
    *(s32 *)(s+0x170) = *(s32 *)(lbl_80498C30+4);
    *(s32 *)(s+0x174) = *(s32 *)(lbl_80498C30+8);
    *(s32 *)(s+0x178) = *(s32 *)(lbl_80498C30+0xc);
    *(s32 *)(s+0x17c) = *(s32 *)(lbl_80498C30+0x10);
    *(s32 *)(s+0x0) = *(s32 *)lbl_802FA594;
    *(s32 *)(s+0x8) = *(s32 *)(lbl_802FA594+8);
    *(s32 *)(s+0xc) = *(s32 *)(lbl_802FA594+0xc);
    *(s32 *)(s+0x10) = *(s32 *)(lbl_802FA594+0x10);
    *(void **)(s+0x4) = s+0x18;
    i=0;
    do {
        *(s32 *)(s+0x30c)=i;
        fn_802146BC((s32 *)s, -0x3e7, -0x3e7, 1);
        ++i;
        count = (*(s32 (**)(void *))(*(void ***)arg0+5))(arg0);
    } while (i<count);
    fn_80018B24();
    fn_8013C8B8();
    *(void **)(s+0x180)=lbl_803443B0;
    if (object != 0) {
        if (object != 0)
            (*(void (**)(void *, s32))(*(void ***)object+2))(object, 1);
    }
    fn_8002F634(s+0x470, fn_80240928, 0x28, 5);
    fn_80255758(s+0x320, -1);
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

#pragma push
#pragma small_data on
void *fn_8025007C(s32 arg0) {
    void *result;
    void *array;
    result = fn_801284F8(0x20, lbl_80344378);
    if (result != 0) {
        *(void **)result = lbl_80344384;
        array = fn_8012850C(arg0 * 0x48, &lbl_8055C0E0);
        *(void **)((u8 *)result + 4) = array;
        *(s32 *)((u8 *)result + 0xC) = arg0;
        *(s32 *)((u8 *)result + 8) = 0;
        *(void **)((u8 *)result + 0x10) = array;
        fn_801312EC((u8 *)result + 0x14, lbl_80344690);
    }
    return result;
}
#pragma pop
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

extern double fn_8002EFB4(double, double);
extern double fabs(double);
extern double lbl_80563978;
#pragma push
#pragma scheduling invalid_target
#pragma use_lmw_stmw on
#pragma cplusplus on
extern "C" s32 fn_80250204(void *arg0, s32 arg1, M2C_UNK arg_sp0) {
    typedef signed char s8;
    extern f32 lbl_80558DC4;
    extern void fn_80216D28(void);
    extern s32 fn_80214D50(s32);

    class Selector {
    public:
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void *get0(s32); virtual s32 get1(s32); virtual void *get2(s32); virtual s32 get3(s32);
    };
    class Table {
    public:
        virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
        virtual void t4(); virtual void t5(); virtual void t6(); virtual void t7();
        virtual void t8(); virtual void t9(); virtual void t10(); virtual void t11();
        virtual void t12(); virtual void t13(); virtual void t14(); virtual void t15();
        virtual void t16(); virtual void t17(); virtual void t18(); virtual void t19();
        virtual void t20(); virtual void t21();
        virtual void fill(s32, void *, void *);
    };
    s32 temp_r3_end;
    s32 compare_result;
    f32 abs_value;
    f32 remainder;
    register s32 copy_a;
    register s32 copy_b;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 *temp_r21;
    s32 *temp_r4;
    s32 *temp_r4_2;
    s32 *temp_r4_3;
    s32 temp_r22;
    s32 temp_r27;
    register s32 temp_r27_2;
    register s32 temp_r27_3;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r28;
    s32 var_r29;
    s32 var_r29_2;
    s32 var_r4_11;
    s32 var_r4_12;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r4_7;
    s32 var_r4_8;
    s32 var_r5;
    s32 var_r5_10;
    s32 var_r5_12;
    s32 var_r5_2;
    s32 var_r5_4;
    s32 var_r5_5;
    s32 var_r5_6;
    s32 var_r5_8;
    s32 var_r5_9;
    u8 *var_r23;
    u8 *var_r23_2;
    u8 *var_r25_3;
    volatile u8 *var_r4;
    volatile u8 *var_r4_10;
    volatile u8 *var_r4_2;
    volatile u8 *var_r4_5;
    volatile u8 *var_r4_6;
    volatile u8 *var_r4_9;
    u8 *var_r5_11;
    u8 *var_r5_3;
    u8 *var_r5_7;
    volatile u8 *var_r6;
    volatile u8 *var_r6_2;
    volatile u8 *var_r6_3;
    volatile u8 *var_r6_4;
    volatile u8 *var_r6_5;
    volatile u8 *var_r6_6;
    volatile u8 *var_r6_7;
    volatile u8 *var_r6_8;
    volatile u8 *var_r6_9;
    u8 temp_r23_2;
    u8 temp_r3_10;
    u8 temp_r3_17;
    u8 temp_r3_19;
    u8 temp_r3_22;
    u8 temp_r3_30;
    u8 temp_r3_32;
    u8 temp_r3_35;
    u8 temp_r3_5;
    u8 temp_r3_7;
    u8 var_r3;
    void **temp_r3;
    void **temp_r3_11;
    void **temp_r3_12;
    void **temp_r3_13;
    void **temp_r3_14;
    void **temp_r3_15;
    void **temp_r3_18;
    void **temp_r3_20;
    void **temp_r3_23;
    void **temp_r3_24;
    void **temp_r3_26;
    void **temp_r3_27;
    void **temp_r3_28;
    void **temp_r3_2;
    void **temp_r3_31;
    void **temp_r3_33;
    void **temp_r3_36;
    void **temp_r3_37;
    void **temp_r3_3;
    void **temp_r3_6;
    void **temp_r3_8;
    u8 *var_r22_3;
    u8 *var_r26;
    u8 *var_r26_2;
    u8 *temp_r21_2;
    u8 *temp_r21_3;
    u8 *temp_r22_2;
    u8 *temp_r23;
    u8 *temp_r28;
    u8 *temp_r28_2;
    u8 *temp_r29;
    u8 *temp_r30;
    u8 *temp_r30_2;
    u8 *temp_r30_3;
    u8 *temp_r3_16;
    u8 *temp_r3_21;
    u8 *temp_r3_25;
    u8 *temp_r3_29;
    u8 *temp_r3_34;
    u8 *temp_r3_4;
    u8 *temp_r3_9;
    u8 *var_r21;
    u8 *var_r21_2;
    u8 *var_r21_3;
    u8 *var_r22;
    u8 *var_r22_2;
    u8 *var_r23_3;
    u8 *var_r24;
    u8 *var_r24_2;
    u8 *var_r24_3;
    u8 *var_r25;
    u8 *var_r25_2;
    u8 *var_r26_3;

    temp_r22 = M2C_FIELD(arg0, s32, 0x2C);
    temp_r23 = (u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (temp_r22 * 0x14);
    temp_r21 = ((s32 *(*)(s32, s32))fn_80016BC8)(M2C_FIELD(temp_r23, s32, 8), 0);
    switch (arg1) {                                 /* irregular */
    case 0x125:
        if (temp_r22 > 0) {
            temp_r27 = temp_r22 - 1;
            temp_r3 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(arg0, s32, 0x2C) = temp_r27;
            var_r21 = (u8*)((Selector*)temp_r3)->get0(temp_r27);
            temp_r3_4 = (u8 *)fn_8001668C((s32)var_r21, 0);
            temp_r30 = var_r21;
            if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)((s32)temp_r3_4, 0), u8, 8) != 0) {
                temp_r3_2 = M2C_FIELD(arg0, void **, 0xD0);
                if (((Selector*)temp_r3_2)->get3(temp_r27) != 0) {
                    temp_r3_3 = M2C_FIELD(arg0, void **, 0xD0);
                    var_r21 = (u8*)((Selector*)temp_r3_3)->get2(temp_r27);
                }
            }
            temp_r3_4 = (u8*)fn_8001668C((s32)var_r21, 0);
            var_r4 = temp_r3_4 + 0x2C;
            var_r6 = ((u8*)arg0 + 0x60);
            var_r5 = 0x20;
goto copy_125_a_body;
copy_125_a_count:
            var_r5 -= 1;
            if (var_r5 > 0) goto copy_125_a_body;
            M2C_FIELD(var_r6, s8, -1) = 0;
            goto copy_125_a_end;
copy_125_a_body:
            temp_r3_5 = *var_r4++;
            *var_r6++ = temp_r3_5;
            if ((s8)temp_r3_5 != 0) goto copy_125_a_count;
copy_125_a_end: ;
            temp_r3_6 = M2C_FIELD(arg0, void **, 0xD0);
            if (((Selector*)temp_r3_6)->get3(temp_r27) != 0) {
                fn_801345D8(((u8*)arg0 + 0x80), 0x40, &lbl_803442E4, temp_r3_4 + 0xD);
            } else {
                var_r4_2 = temp_r3_4 + 0xC;
                var_r6_2 = ((u8*)arg0 + 0x80);
                var_r5_2 = 0x40;
goto copy_125_b_body;
copy_125_b_count:
                var_r5_2 -= 1;
                if (var_r5_2 > 0) goto copy_125_b_body;
                M2C_FIELD(var_r6_2, s8, -1) = 0;
                goto copy_125_b_end;
copy_125_b_body:
                temp_r3_7 = *var_r4_2++;
                *var_r6_2++ = temp_r3_7;
                if ((s8)temp_r3_7 != 0) goto copy_125_b_count;
copy_125_b_end: ;
            }
            temp_r3_8 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(arg0, s32, 0xC4) = (((Selector*)temp_r3_8)->get3(temp_r27) != 0) ? 5 : -1;
            *M2C_FIELD(arg0, s32 **, 0x34) = M2C_FIELD(temp_r3_4, s32 *, 4);
            temp_r4 = M2C_FIELD(arg0, s32 *, 0x30);
            *temp_r4 = M2C_FIELD(temp_r3_4, s32, 0x9C);
            temp_r29 = (u8 *)M2C_FIELD(arg0, void *, 0x38);
            temp_r3_9 = (u8 *)fn_80018A8C(temp_r3_4 + 0x2C, temp_r4);
            if (temp_r3_9 != 0) {
                M2C_FIELD(temp_r29, s32, 0) = M2C_FIELD(temp_r3_9, s32, 0);
                var_r22 = temp_r29;
                var_r24 = temp_r29;
                var_r23 = temp_r29 + 0xF4;
                var_r25 = temp_r29 + 8;
                copy_b = M2C_FIELD(temp_r3_9, s32, 4);
                var_r26 = temp_r29 + 0x2C;
                copy_a = M2C_FIELD(temp_r3_9, s32, 8);
                var_r28 = 0;
                M2C_FIELD(temp_r29, s32, 4) = copy_b;
                M2C_FIELD(temp_r29, s32, 8) = copy_a;
                copy_a = M2C_FIELD(temp_r3_9, s32, 0xC);
                copy_b = M2C_FIELD(temp_r3_9, s32, 0x10);
                M2C_FIELD(temp_r29, s32, 0xC) = copy_a;
                M2C_FIELD(temp_r29, s32, 0x10) = copy_b;
                copy_a = M2C_FIELD(temp_r3_9, s32, 0x14);
                copy_b = M2C_FIELD(temp_r3_9, s32, 0x18);
                M2C_FIELD(temp_r29, s32, 0x14) = copy_a;
                M2C_FIELD(temp_r29, s32, 0x18) = copy_b;
                copy_a = M2C_FIELD(temp_r3_9, s32, 0x1C);
                copy_b = M2C_FIELD(temp_r3_9, s32, 0x20);
                M2C_FIELD(temp_r29, s32, 0x1C) = copy_a;
                M2C_FIELD(temp_r29, s32, 0x20) = copy_b;
                M2C_FIELD(temp_r29, s32, 0x28) = M2C_FIELD(temp_r3_9, s32, 0x28);
                M2C_FIELD(temp_r29, s32, 0x24) = M2C_FIELD(temp_r3_9, s32, 0x24);
do {
                        var_r6_3 = M2C_FIELD(var_r22, u8 *, 4);
                        if (var_r6_3 != 0) {
                            var_r5_3 = var_r23;
                            var_r4_3 = 0x64;
                            goto copy_c125_body;
copy_c125_count:
                            var_r4_3 -= 1;
                            if (var_r4_3 > 0) goto copy_c125_body;
                            M2C_FIELD(var_r5_3, s8, -1) = 0;
                            goto copy_c125_end;
copy_c125_body:
                            temp_r3_10 = *var_r6_3++;
                            *var_r5_3++ = temp_r3_10;
                            if ((s8)temp_r3_10 != 0) goto copy_c125_count;
                            goto copy_c125_end;
copy_c125_end: ;
                        } else {
                            M2C_FIELD(var_r24, s8, 0xF4) = 0;
                        }
                        ((Table *)var_r26)->fill(var_r28, var_r25, temp_r29 + 0x2E8);
                        var_r22 += 8;
                        var_r23 += 0x64;
                        var_r24 += 0x64;
                        var_r25 += 8;
                        var_r26 += 0x28;
                        var_r28 += 1;
                        if (var_r28 < 5) goto copy_c125_continue;
                        break;
copy_c125_continue: ;
} while (1);
            } else {
                memset(temp_r29, 0, 0x2C);
                M2C_FIELD(temp_r29, s8, 0xF4) = 0;
                M2C_FIELD(temp_r29, s8, 0x158) = 0;
                M2C_FIELD(temp_r29, s8, 0x1BC) = 0;
                M2C_FIELD(temp_r29, s8, 0x220) = 0;
                M2C_FIELD(temp_r29, s8, 0x284) = 0;
            }
            temp_r3_11 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8, 0xDD) = (s8) (((Selector*)temp_r3_11)->get1(temp_r27) == 0);
            sp18 = -1;
            sp1C = -1;
            if (fn_80019258(temp_r30, &sp18, &sp1C) == 0) {
                sp1C = -1;
                sp18 = -1;
            }
            temp_r3_12 = M2C_FIELD(arg0, void **, 0xD0);
            if ((((Selector*)temp_r3_12)->get3(temp_r27) == 0) && (sp18 >= 0) && (sp1C >= 0)) {
                fn_801345D8(((u8*)arg0 + 0x3C), 0x10, &lbl_8055C0C0, fn_8001EFC0(0, ((u8*)arg0 + 0x60)), sp18);
                fn_801345D8(((u8*)arg0 + 0x50), 0x10, &lbl_8055C0C0, fn_8001EFC0(1, ((u8*)arg0 + 0x60)), sp1C);
            } else {
                fn_80130FCC(((u8*)arg0 + 0x3C), 0x10, fn_8001EFC0(0, ((u8*)arg0 + 0x60)));
                fn_80130FCC(((u8*)arg0 + 0x50), 0x10, fn_8001EFC0(1, ((u8*)arg0 + 0x60)));
            }
            temp_r21_2 = (u8*)fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
            temp_r3_end = fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
            if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) {
                var_r5_4 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 0);
            } else {
                var_r5_4 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
            }
            var_r4_4 = M2C_FIELD(((u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (M2C_FIELD(arg0, s32, 0x2C) * 0x14)), s32, 0x10);
            if (var_r4_4 != 0) {

            } else {
                var_r4_4 = M2C_FIELD((temp_r21_2 + (var_r5_4 * 4)), s32, 0x64);
            }
            fn_80255918(M2C_FIELD(arg0, void **, 0x4C), var_r4_4);
        } else {
            fn_80216D28();
            fn_80214D50(1);
        }
        return 1;
    case 0x127:
        temp_r27_2 = temp_r22 + 1;
        if (temp_r27_2 < (s32) M2C_FIELD(arg0, s32 *, 0x1C)) {
            M2C_FIELD(arg0, s32, 0x2C) = temp_r27_2;
            temp_r3_13 = M2C_FIELD(arg0, void **, 0xD0);
            var_r21_2 = (u8*)((Selector*)temp_r3_13)->get0(temp_r27_2);
            temp_r3_16 = (u8 *)fn_8001668C((s32)var_r21_2, 0);
            temp_r30_2 = var_r21_2;
            if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)((s32)temp_r3_16, 0), u8, 8) != 0) {
                temp_r3_14 = M2C_FIELD(arg0, void **, 0xD0);
                if (((Selector*)temp_r3_14)->get3(temp_r27_2) != 0) {
                    temp_r3_15 = M2C_FIELD(arg0, void **, 0xD0);
                    var_r21_2 = (u8*)((Selector*)temp_r3_15)->get2(temp_r27_2);
                }
            }
            temp_r3_16 = (u8*)fn_8001668C((s32)var_r21_2, 0);
            var_r4_5 = temp_r3_16 + 0x2C;
            var_r6_4 = ((u8*)arg0 + 0x60);
            var_r5_5 = 0x20;
goto copy_127_a_body;
copy_127_a_count:
            var_r5_5 -= 1;
            if (var_r5_5 > 0) goto copy_127_a_body;
            M2C_FIELD(var_r6_4, s8, -1) = 0;
            goto copy_127_a_end;
copy_127_a_body:
            temp_r3_17 = *var_r4_5++;
            *var_r6_4++ = temp_r3_17;
            if ((s8)temp_r3_17 != 0) goto copy_127_a_count;
copy_127_a_end: ;
            temp_r3_18 = M2C_FIELD(arg0, void **, 0xD0);
            if (((Selector*)temp_r3_18)->get3(temp_r27_2) != 0) {
                fn_801345D8(((u8*)arg0 + 0x80), 0x40, &lbl_803442E4, temp_r3_16 + 0xD);
            } else {
                var_r4_6 = temp_r3_16 + 0xC;
                var_r6_5 = ((u8*)arg0 + 0x80);
                var_r5_6 = 0x40;
goto copy_127_b_body;
copy_127_b_count:
                var_r5_6 -= 1;
                if (var_r5_6 > 0) goto copy_127_b_body;
                M2C_FIELD(var_r6_5, s8, -1) = 0;
                goto copy_127_b_end;
copy_127_b_body:
                temp_r3_19 = *var_r4_6++;
                *var_r6_5++ = temp_r3_19;
                if ((s8)temp_r3_19 != 0) goto copy_127_b_count;
copy_127_b_end: ;
            }
            temp_r3_20 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(arg0, s32, 0xC4) = (((Selector*)temp_r3_20)->get3(temp_r27_2) != 0) ? 5 : -1;
            *M2C_FIELD(arg0, s32 **, 0x34) = M2C_FIELD(temp_r3_16, s32 *, 4);
            temp_r4_2 = M2C_FIELD(arg0, s32 *, 0x30);
            *temp_r4_2 = M2C_FIELD(temp_r3_16, s32, 0x9C);
            temp_r28 = (u8 *)M2C_FIELD(arg0, void *, 0x38);
            temp_r3_21 = (u8 *)fn_80018A8C(temp_r3_16 + 0x2C, temp_r4_2);
            if (temp_r3_21 != 0) {
                M2C_FIELD(temp_r28, s32, 0) = M2C_FIELD(temp_r3_21, s32, 0);
                var_r22_2 = temp_r28;
                var_r24_2 = temp_r28;
                var_r23_2 = temp_r28 + 0xF4;
                var_r25_2 = temp_r28 + 8;
                copy_a = M2C_FIELD(temp_r3_21, s32, 4);
                var_r26_2 = temp_r28 + 0x2C;
                copy_b = M2C_FIELD(temp_r3_21, s32, 8);
                var_r29 = 0;
                M2C_FIELD(temp_r28, s32, 4) = copy_a;
                M2C_FIELD(temp_r28, s32, 8) = copy_b;
                copy_a = M2C_FIELD(temp_r3_21, s32, 0xC);
                copy_b = M2C_FIELD(temp_r3_21, s32, 0x10);
                M2C_FIELD(temp_r28, s32, 0xC) = copy_a;
                M2C_FIELD(temp_r28, s32, 0x10) = copy_b;
                copy_a = M2C_FIELD(temp_r3_21, s32, 0x14);
                copy_b = M2C_FIELD(temp_r3_21, s32, 0x18);
                M2C_FIELD(temp_r28, s32, 0x14) = copy_a;
                M2C_FIELD(temp_r28, s32, 0x18) = copy_b;
                M2C_FIELD(temp_r28, s32, 0x20) = M2C_FIELD(temp_r3_21, s32, 0x20);
                M2C_FIELD(temp_r28, s32, 0x1C) = M2C_FIELD(temp_r3_21, s32, 0x1C);
                copy_a = M2C_FIELD(temp_r3_21, s32, 0x24);
                copy_b = M2C_FIELD(temp_r3_21, s32, 0x28);
                M2C_FIELD(temp_r28, s32, 0x24) = copy_a;
                M2C_FIELD(temp_r28, s32, 0x28) = copy_b;
do {
                        var_r6_6 = M2C_FIELD(var_r22_2, u8 *, 4);
                        if (var_r6_6 != 0) {
                            var_r5_7 = var_r23_2;
                            var_r4_7 = 0x64;
                            goto copy_c127_body;
copy_c127_count:
                            var_r4_7 -= 1;
                            if (var_r4_7 > 0) goto copy_c127_body;
                            M2C_FIELD(var_r5_7, s8, -1) = 0;
                            goto copy_c127_end;
copy_c127_body:
                            temp_r3_22 = *var_r6_6++;
                            *var_r5_7++ = temp_r3_22;
                            if ((s8)temp_r3_22 != 0) goto copy_c127_count;
                            goto copy_c127_end;
copy_c127_end: ;
                        } else {
                            M2C_FIELD(var_r24_2, s8, 0xF4) = 0;
                        }
                        ((Table *)var_r26_2)->fill(var_r29, var_r25_2, temp_r28 + 0x2E8);
                        var_r22_2 += 8;
                        var_r23_2 += 0x64;
                        var_r24_2 += 0x64;
                        var_r25_2 += 8;
                        var_r26_2 += 0x28;
                        var_r29 += 1;
                        if (var_r29 < 5) goto copy_c127_continue;
                        break;
copy_c127_continue: ;
} while (1);
            } else {
                memset(temp_r28, 0, 0x2C);
                M2C_FIELD(temp_r28, s8, 0xF4) = 0;
                M2C_FIELD(temp_r28, s8, 0x158) = 0;
                M2C_FIELD(temp_r28, s8, 0x1BC) = 0;
                M2C_FIELD(temp_r28, s8, 0x220) = 0;
                M2C_FIELD(temp_r28, s8, 0x284) = 0;
            }
            temp_r3_23 = M2C_FIELD(arg0, void **, 0xD0);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8, 0xDD) = (s8) (((Selector*)temp_r3_23)->get1(temp_r27_2) == 0);
            sp10 = -1;
            sp14 = -1;
            if (fn_80019258(temp_r30_2, &sp10, &sp14) == 0) {
                sp14 = -1;
                sp10 = -1;
            }
            temp_r3_24 = M2C_FIELD(arg0, void **, 0xD0);
            if ((((Selector*)temp_r3_24)->get3(temp_r27_2) == 0) && (sp10 >= 0) && (sp14 >= 0)) {
                fn_801345D8(((u8*)arg0 + 0x3C), 0x10, &lbl_8055C0C0, fn_8001EFC0(0, ((u8*)arg0 + 0x60)), sp10);
                fn_801345D8(((u8*)arg0 + 0x50), 0x10, &lbl_8055C0C0, fn_8001EFC0(1, ((u8*)arg0 + 0x60)), sp14);
            } else {
                fn_80130FCC(((u8*)arg0 + 0x3C), 0x10, fn_8001EFC0(0, ((u8*)arg0 + 0x60)));
                fn_80130FCC(((u8*)arg0 + 0x50), 0x10, fn_8001EFC0(1, ((u8*)arg0 + 0x60)));
            }
            temp_r21_3 = (u8*)fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
            temp_r3_end = fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
            if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) {
                var_r5_8 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 0);
            } else {
                var_r5_8 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
            }
            var_r4_8 = M2C_FIELD(((u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (M2C_FIELD(arg0, s32, 0x2C) * 0x14)), s32, 0x10);
            if (var_r4_8 != 0) {

            } else {
                var_r4_8 = M2C_FIELD((temp_r21_3 + (var_r5_8 * 4)), s32, 0x64);
            }
            fn_80255918(M2C_FIELD(arg0, void **, 0x4C), var_r4_8);
        } else {
            fn_80216D28();
            fn_80214D50(1);
        }
        return 1;
    case 0x126:
    case 0x128:
        temp_r23_2 = M2C_FIELD(temp_r23, u8, 0xC);
        if ((s32) temp_r23_2 != 0) {
            temp_r3_25 = (u8 *)M2C_FIELD(arg0, u8 *, 0x18) + (temp_r22 * 0xC);
            abs_value = __fabs(M2C_FIELD(temp_r3_25, f32, 8));
            remainder = fn_8002EFB4(abs_value, lbl_80563978);
            compare_result = __fabs(remainder) <= M2C_FIELD(&lbl_80558DC4, f32, 0);
            if (compare_result != 0) {
                var_r3 = 0;
                if (((s32) M2C_FIELD(temp_r21, u8, 8) == 0) && ((s32) temp_r23_2 != 0)) {
                    var_r3 = 1;
                }
                M2C_FIELD(temp_r21, u8, 8) = var_r3;
                temp_r3_26 = M2C_FIELD(arg0, void **, 0xD0);
                temp_r27_3 = M2C_FIELD(arg0, s32, 0x2C);
                var_r21_3 = (u8*)((Selector*)temp_r3_26)->get0(temp_r27_3);
                temp_r3_29 = (u8 *)fn_8001668C((s32)var_r21_3, 0);
                temp_r30_3 = var_r21_3;
                if ((s32) M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)((s32)temp_r3_29, 0), u8, 8) != 0) {
                    temp_r3_27 = M2C_FIELD(arg0, void **, 0xD0);
                    if (((Selector*)temp_r3_27)->get3(temp_r27_3) != 0) {
                        temp_r3_28 = M2C_FIELD(arg0, void **, 0xD0);
                        var_r21_3 = (u8*)((Selector*)temp_r3_28)->get2(temp_r27_3);
                    }
                }
                temp_r3_29 = (u8*)fn_8001668C((s32)var_r21_3, 0);
                var_r4_9 = temp_r3_29 + 0x2C;
                var_r6_7 = ((u8*)arg0 + 0x60);
                var_r5_9 = 0x20;
goto copy_128_a_body;
copy_128_a_count:
                var_r5_9 -= 1;
                if (var_r5_9 > 0) goto copy_128_a_body;
                M2C_FIELD(var_r6_7, s8, -1) = 0;
                goto copy_128_a_end;
copy_128_a_body:
                temp_r3_30 = *var_r4_9++;
                *var_r6_7++ = temp_r3_30;
                if ((s8)temp_r3_30 != 0) goto copy_128_a_count;
copy_128_a_end: ;
                temp_r3_31 = M2C_FIELD(arg0, void **, 0xD0);
                if (((Selector*)temp_r3_31)->get3(temp_r27_3) != 0) {
                    fn_801345D8(((u8*)arg0 + 0x80), 0x40, &lbl_803442E4, temp_r3_29 + 0xD);
                } else {
                    var_r4_10 = temp_r3_29 + 0xC;
                    var_r6_8 = ((u8*)arg0 + 0x80);
                    var_r5_10 = 0x40;
goto copy_128_b_body;
copy_128_b_count:
                    var_r5_10 -= 1;
                    if (var_r5_10 > 0) goto copy_128_b_body;
                    M2C_FIELD(var_r6_8, s8, -1) = 0;
                    goto copy_128_b_end;
copy_128_b_body:
                    temp_r3_32 = *var_r4_10++;
                    *var_r6_8++ = temp_r3_32;
                    if ((s8)temp_r3_32 != 0) goto copy_128_b_count;
copy_128_b_end: ;
                }
                temp_r3_33 = M2C_FIELD(arg0, void **, 0xD0);
                var_r0_3 = -1;
                if (((Selector*)temp_r3_33)->get3(temp_r27_3) != 0) {
                    var_r0_3 = 5;
                }
                M2C_FIELD(arg0, s32, 0xC4) = var_r0_3;
                *M2C_FIELD(arg0, s32 **, 0x34) = M2C_FIELD(temp_r3_29, s32 *, 4);
                temp_r4_3 = M2C_FIELD(arg0, s32 *, 0x30);
                *temp_r4_3 = M2C_FIELD(temp_r3_29, s32, 0x9C);
                temp_r28_2 = (u8 *)M2C_FIELD(arg0, void *, 0x38);
                temp_r3_34 = (u8 *)fn_80018A8C(temp_r3_29 + 0x2C, temp_r4_3);
                if (temp_r3_34 != 0) {
                    M2C_FIELD(temp_r28_2, s32, 0) = M2C_FIELD(temp_r3_34, s32, 0);
                    var_r26_3 = temp_r28_2;
                    var_r24_3 = temp_r28_2;
                    var_r25_3 = temp_r28_2 + 0xF4;
                    var_r23_3 = temp_r28_2 + 8;
                    copy_b = M2C_FIELD(temp_r3_34, s32, 4);
                    var_r22_3 = temp_r28_2 + 0x2C;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 8);
                    var_r29_2 = 0;
                    M2C_FIELD(temp_r28_2, s32, 4) = copy_b;
                    M2C_FIELD(temp_r28_2, s32, 8) = copy_a;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 0xC);
                    copy_b = M2C_FIELD(temp_r3_34, s32, 0x10);
                    M2C_FIELD(temp_r28_2, s32, 0xC) = copy_a;
                    M2C_FIELD(temp_r28_2, s32, 0x10) = copy_b;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 0x14);
                    copy_b = M2C_FIELD(temp_r3_34, s32, 0x18);
                    M2C_FIELD(temp_r28_2, s32, 0x14) = copy_a;
                    M2C_FIELD(temp_r28_2, s32, 0x18) = copy_b;
                    copy_a = M2C_FIELD(temp_r3_34, s32, 0x1C);
                    copy_b = M2C_FIELD(temp_r3_34, s32, 0x20);
                    M2C_FIELD(temp_r28_2, s32, 0x1C) = copy_a;
                    M2C_FIELD(temp_r28_2, s32, 0x20) = copy_b;
                    M2C_FIELD(temp_r28_2, s32, 0x28) = M2C_FIELD(temp_r3_34, s32, 0x28);
                    M2C_FIELD(temp_r28_2, s32, 0x24) = M2C_FIELD(temp_r3_34, s32, 0x24);
do {
                            var_r6_9 = M2C_FIELD(var_r26_3, u8 *, 4);
                            if (var_r6_9 != 0) {
                                var_r5_11 = var_r25_3;
                                var_r4_11 = 0x64;
                                goto copy_c128_body;
copy_c128_count:
                                var_r4_11 -= 1;
                                if (var_r4_11 > 0) goto copy_c128_body;
                                M2C_FIELD(var_r5_11, s8, -1) = 0;
                                goto copy_c128_end;
copy_c128_body:
                                temp_r3_35 = *var_r6_9++;
                                *var_r5_11++ = temp_r3_35;
                                if ((s8)temp_r3_35 != 0) goto copy_c128_count;
                                goto copy_c128_end;
copy_c128_end: ;
                            } else {
                                M2C_FIELD(var_r24_3, s8, 0xF4) = 0;
                            }
                            ((Table *)var_r22_3)->fill(var_r29_2, var_r23_3, temp_r28_2 + 0x2E8);
                            var_r26_3 += 8;
                            var_r25_3 += 0x64;
                            var_r24_3 += 0x64;
                            var_r23_3 += 8;
                            var_r22_3 += 0x28;
                            var_r29_2 += 1;
                            if (var_r29_2 < 5) goto copy_c128_continue;
                            break;
copy_c128_continue: ;
} while (1);
                } else {
                    memset(temp_r28_2, 0, 0x2C);
                    M2C_FIELD(temp_r28_2, s8, 0xF4) = 0;
                    M2C_FIELD(temp_r28_2, s8, 0x158) = 0;
                    M2C_FIELD(temp_r28_2, s8, 0x1BC) = 0;
                    M2C_FIELD(temp_r28_2, s8, 0x220) = 0;
                    M2C_FIELD(temp_r28_2, s8, 0x284) = 0;
                }
                temp_r3_36 = M2C_FIELD(arg0, void **, 0xD0);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8, 0xDD) = (s8) (((Selector*)temp_r3_36)->get1(temp_r27_3) == 0);
                sp8 = -1;
                spC = -1;
                if (fn_80019258(temp_r30_3, &sp8, &spC) == 0) {
                    spC = -1;
                    sp8 = -1;
                }
                temp_r3_37 = M2C_FIELD(arg0, void **, 0xD0);
                if ((((Selector*)temp_r3_37)->get3(temp_r27_3) == 0) && (sp8 >= 0) && (spC >= 0)) {
                    fn_801345D8(((u8*)arg0 + 0x3C), 0x10, &lbl_8055C0C0, fn_8001EFC0(0, ((u8*)arg0 + 0x60)), sp8);
                    fn_801345D8(((u8*)arg0 + 0x50), 0x10, &lbl_8055C0C0, fn_8001EFC0(1, ((u8*)arg0 + 0x60)), spC);
                } else {
                    fn_80130FCC(((u8*)arg0 + 0x3C), 0x10, fn_8001EFC0(0, ((u8*)arg0 + 0x60)));
                    fn_80130FCC(((u8*)arg0 + 0x50), 0x10, fn_8001EFC0(1, ((u8*)arg0 + 0x60)));
                }
                temp_r22_2 = (u8*)fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
                fn_8001668C((s32)(((u8*)arg0 + 0x60)), 0);
                if ((s32) M2C_FIELD(&lbl_80498C48, u8, 4) != 0) {
                    var_r5_12 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 0);
                } else {
                    var_r5_12 = M2C_FIELD(((s32 *(*)(s32, s32))fn_80016BC8)(temp_r3_end, 0), s32, 4);
                }
                var_r4_12 = M2C_FIELD(((u8 *)M2C_FIELD(arg0, s32 *, 0xCC) + (M2C_FIELD(arg0, s32, 0x2C) * 0x14)), s32, 0x10);
                if (var_r4_12 != 0) {

                } else {
                    var_r4_12 = M2C_FIELD((temp_r22_2 + (var_r5_12 * 4)), s32, 0x64);
                }
                fn_80255918(M2C_FIELD(arg0, void **, 0x4C), var_r4_12);
            } else {
                fn_80216D28();
            }
        } else {
            fn_80216D28();
            fn_80214D50(1);
        }
        return 1;
    default:
        return 0;
    }
}
#pragma pop

extern f32 lbl_80563960;
extern void fn_802354A0(s32, s32, s32, f32, f32, f32, f32, f32);
extern f32 fn_80216CB4(void);
#pragma push
#pragma processor 750
#pragma scheduling invalid_target
void fn_802514B4(void *arg0, s32 arg1, f32 x, f32 y, f32 w, f32 h) {
    s32 value = *(s32 *)(*(char **)((char *)arg0 + 0xCC) + arg1 * 0x14 + 0x10);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 0, -1, x, y, lbl_80563960, w, h);
    fn_80216CB4();
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 3, value, x, y, lbl_80563960, w, h);
    fn_802354A0(*(s32 *)((char *)arg0 + 0x24), 6, -1, x, y, lbl_80563960, w, h);
}
#pragma scheduling on

#pragma cplusplus on
extern "C" void fn_80216D28(void);
extern "C" s32 fn_80214D50(s32);
extern "C" void fn_80255918(void *, s32);
extern "C" void fn_801345D8(void *, s32, void *, ...);
#pragma cplusplus on
#pragma cplusplus off
#pragma optimize_for_size off
#pragma scheduling invalid_target
s32 fn_8025157C(char *arg0, s32 arg1) {
    u8 *source, *dest;
    s32 count;
    s32 index, newIndex, context;
    u8 ch;

    switch (arg1) {
    case 0x125: {
        
        index = *(s32 *)(arg0 + 0x2C);
        if (index <= 0)
            goto done_prev;
        newIndex = index - 1;
        *(s32 *)(arg0 + 0x2C) = newIndex;

        context = fn_8001668C((s32)(arg0 + 0x60), 0);
        if (lbl_80498C48[4] != 0)
            ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0] = newIndex;
        else
            ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1] = newIndex;

        newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
        if (lbl_80498C48[4] != 0)
            ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[0] = *(s32 *)(arg0 + 0x2C);
        else
            ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[1] = *(s32 *)(arg0 + 0x2C);

        index = *(s32 *)(arg0 + 0x2C);
        *(*(s32 **)(arg0 + 0xDC)) =
            *(s32 *)((u8 *)newIndex + index * 4 + 0x64);

        newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
        context = fn_8001668C((s32)(arg0 + 0x60), 0);
        if (lbl_80498C48[4] != 0)
            context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0];
        else
            context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1];

        index = *(s32 *)((u8 *)*(s32 **)(arg0 + 0xCC) +
                         *(s32 *)(arg0 + 0x2C) * 0x14 + 0x10);
        source = *(u8 **)(arg0 + 0x4C);
        fn_80255918(source,
                     index != 0 ? index :
                     *(s32 *)((u8 *)newIndex + context * 4 + 0x64));

        fn_801345D8(arg0 + 0xE0, 0x100, lbl_8034287C,
                    *(s32 *)(arg0 + 0x2C) + 1);
        source = fn_80131234(arg0 + 0xE0);
        dest = (u8 *)(arg0 + 0xE0);
        count = 0x100;
        goto copy_loop_1;
    copy_count_1:
        count -= 1;
        if (count > 0)
            goto copy_loop_1;
        dest[-1] = 0;
        goto copy_done_1;
    copy_loop_1:
        ch = *source++;
        *dest++ = ch;
        if ((signed char)ch != 0)
            goto copy_count_1;
    copy_done_1:;

    done_prev:
        fn_80216D28();
        fn_80214D50(1);
        return 1;
    }
    case 0x127: {
        
        index = *(s32 *)(arg0 + 0x2C);
        if (index >= *(s32 *)(arg0 + 0x1C) - 1)
            goto done_next;
        newIndex = index + 1;
        *(s32 *)(arg0 + 0x2C) = newIndex;

        context = fn_8001668C((s32)(arg0 + 0x60), 0);
        if (lbl_80498C48[4] != 0)
            ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0] = newIndex;
        else
            ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1] = newIndex;

        newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
        if (lbl_80498C48[4] != 0)
            ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[0] = *(s32 *)(arg0 + 0x2C);
        else
            ((s32 *(*)(s32, s32))fn_80016BC8)(newIndex, 0)[1] = *(s32 *)(arg0 + 0x2C);

        index = *(s32 *)(arg0 + 0x2C);
        *(*(s32 **)(arg0 + 0xDC)) =
            *(s32 *)((u8 *)newIndex + index * 4 + 0x64);

        newIndex = fn_8001668C((s32)(arg0 + 0x60), 0);
        context = fn_8001668C((s32)(arg0 + 0x60), 0);
        if (lbl_80498C48[4] != 0)
            context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[0];
        else
            context = ((s32 *(*)(s32, s32))fn_80016BC8)(context, 0)[1];

        index = *(s32 *)((u8 *)*(s32 **)(arg0 + 0xCC) +
                         *(s32 *)(arg0 + 0x2C) * 0x14 + 0x10);
        source = *(u8 **)(arg0 + 0x4C);
        fn_80255918(source,
                     index != 0 ? index :
                     *(s32 *)((u8 *)newIndex + context * 4 + 0x64));

        fn_801345D8(arg0 + 0xE0, 0x100, lbl_8034287C,
                    *(s32 *)(arg0 + 0x2C) + 1);
        source = fn_80131234(arg0 + 0xE0);
        dest = (u8 *)(arg0 + 0xE0);
        count = 0x100;
        goto copy_loop_2;
    copy_count_2:
        count -= 1;
        if (count > 0)
            goto copy_loop_2;
        dest[-1] = 0;
        goto copy_done_2;
    copy_loop_2:
        ch = *source++;
        *dest++ = ch;
        if ((signed char)ch != 0)
            goto copy_count_2;
    copy_done_2:;

    done_next:
        fn_80216D28();
        fn_80214D50(1);
        return 1;
    }
    default:
        return 0;
    }
}
#pragma scheduling on
#pragma optimize_for_size reset
extern void fn_80255904(s32);
extern void fn_80214A9C(s32, f32);
extern void fn_80221F94(void *, s32);
extern void *fn_801284F8(u32, void *);
extern void *fn_8012850C(s32, void *);
extern void fn_801312EC(void *, void *);
extern f32 lbl_80563960, lbl_805639C0;
__declspec(section ".data") extern f32 lbl_80558DC4;
extern char lbl_8055C0E0[];
extern char lbl_80344378[], lbl_80344384[], lbl_80344690[], lbl_803443B0[];
#pragma scheduling off
void fn_80251D0C(void *arg0) {
    float value1;
    int zero;
    float value0;

    fn_80255904(*(s32 *)((char *)arg0 + 0x20));
    value1 = lbl_80563960;
    zero = 0;
    value0 = lbl_805639C0;
    *(s32 *)((char *)arg0 + 0x190) = -1;
    *(u8 *)((char *)arg0 + 0x28) = zero;
    *(u8 *)((char *)arg0 + 0x48) = zero;
    *(u8 *)((char *)arg0 + 0x88) = zero;
    *(u8 *)((char *)arg0 + 0x108) = zero;
    *(f32 *)((char *)arg0 + 0x194) = value1;
    *(f32 *)((char *)arg0 + 0x198) = value0;
    fn_80214A9C(0x1F, value1);
    *(u8 *)((char *)arg0 + 0x19C) = zero;
}
#pragma scheduling on
s32 fn_80252238(void *arg0, s32 arg1) {
    extern double __fabs(double);
    if (arg1 == 13 &&
        (lbl_80558DC4 >= (f32)__fabs((double)*(f32 *)((char *)arg0 + 0x194)) ||
         lbl_80558DC4 >= (f32)__fabs((double)*(f32 *)((char *)arg0 + 0x198)))) {
        fn_80221F94(arg0, 0);
        return 1;
    }
    return 0;
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

void fn_80252320(void *arg0, u8 *arg1, signed char arg2, int arg3) {
    register s32 index = *(s32 *)((u8 *)arg0 + 8);
    u8 *record = *(u8 **)((u8 *)arg0 + 4) + index * 0x48;
    register u8 *dst;
    register u8 *src;
    register s32 count;
    u8 c;
    *(s32 *)((u8 *)arg0 + 8) = index + 1;
    src = arg1;
    dst = record;
    count = 0x20;
    goto copy_first;
first_loop:
    count--;
    if (count <= 0) { dst[-1] = 0; goto first_done; }
copy_first:
    c = *src++;
    *dst++ = c;
    if ((signed char)c != 0) goto first_loop;
first_done:
    record[0x20] = arg2;
    record[0x41] = arg3;
    if (arg3 != 0) {
        src = fn_80019098(arg1);
        dst = record + 0x21;
        count = 0x20;
        goto copy_second;
second_loop:
        count--;
        if (count <= 0) { dst[-1] = 0; goto second_done; }
copy_second:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0) goto second_loop;
second_done:
        ;
    } else {
        src = &lbl_8055C0E8;
        dst = record + 0x21;
        count = 0x20;
        goto copy_default;
default_loop:
        count--;
        if (count <= 0) { dst[-1] = 0; goto default_done; }
copy_default:
        c = *src++;
        *dst++ = c;
        if ((signed char)c != 0) goto default_loop;
default_done:
        ;
    }
    if (*(u32 *)((u8 *)arg0 + 0x1C) != lbl_8055E044)
        fn_80131318((u8 *)arg0 + 0x14);
    *(s32 *)(record + 0x44) = *(s32 *)((u8 *)arg0 + 0x18);
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
#pragma push
#pragma opt_common_subs off
