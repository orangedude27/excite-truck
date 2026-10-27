#include <types.h>

s32 fn_80019430(void);
s32 fn_80019438(void);
void *fn_80019054(s32);
s32 fn_80019088(void);
s32 fn_80019098(s32);
s32 fn_80019144(s32);
s32 fn_8027DE68(s32);
void fn_80131234(void *);
void fn_80131818(s32);
s32 fn_80018E44(const char *, s32);
s32 fn_802E317C(void *, void *);
void fn_80018BA4(void);
void fn_80018CCC(void);
void *fn_80131808(void *);
extern const char lbl_80558C50[] __attribute__((section(".sdata2")));
extern const char lbl_802FD2F4[];
extern const char lbl_802FD308[];
void fn_80018B74(void);
void fn_8027DEAC(void);
void fn_8001EF60(s32);
s32 stricmp(const char *, const char *);
extern char lbl_8055D588;
extern u8 lbl_80357E0C[12];

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80018B70(void) {
    fn_8027DEAC();
}

s32 fn_80018B7C(void *arg0, void *arg1) {
    s32 diff;
    
    diff = ((s32 *)arg0)[2] - ((s32 *)arg1)[2];
    if (diff == 0) {
        return ((s32 *)arg0)[4] - ((s32 *)arg1)[4];
    }
    return diff;
}

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
#pragma cplusplus on
extern "C" void fn_80018BA4(void) {
    struct Manager { virtual void unused(); virtual void *get(int); };
    struct Item {
        virtual const char *name();
        virtual void unused1();
        virtual void unused2();
        virtual const char *value(const char *);
        virtual void unused4();
        virtual const char *other(const char *);
    };
    extern void *lbl_8055D58C;
    extern unsigned char lbl_80357E0C[12];
    extern void *lbl_802FD2A0 __attribute__((section(".rodata")));
    extern int strcmp(const char *, const char *);
    extern int fn_80265DCC(void *, int, int, void *);
    extern const char lbl_80558C30[] __attribute__((section(".sdata")));
    extern const char lbl_80558C38[] __attribute__((section(".sdata")));
    extern const char lbl_80558C40[] __attribute__((section(".sdata")));
    int *entry;
    register int found = 0;
    register int index = 0;
    register int zero = 0;
    Item *object;

    for (;;) {
        object = (Item *)((Manager *)lbl_8055D58C)->get(index);
        if (object == 0)
            break;
        if (strcmp(object->name(), (const char *)&lbl_802FD2A0) == 0) {
            entry = (int *)((char *)*(void **)lbl_80357E0C +
                            *(int *)(lbl_80357E0C + 4) * 0x14);
            *(int *)(lbl_80357E0C + 4) = *(int *)(lbl_80357E0C + 4) + 1;
            entry[0] = (int)object->value(lbl_80558C30);
            entry[1] = (int)object->value(lbl_80558C38);
            entry[2] = (int)object->other(lbl_80558C40);
            *((char *)entry + 0xC) = (char)zero;
            entry[4] = found++;
        }
        ++index;
    }
    fn_80265DCC(*(void **)lbl_80357E0C, *(int *)(lbl_80357E0C + 4), 0x14, fn_80018B7C);
}
#pragma cplusplus reset
#pragma cplusplus on
extern "C" void fn_80018CCC(void) {
    extern void *lbl_8055D58C;
    extern void *lbl_803580A4;
    extern void *lbl_802FD2A0;
    extern char lbl_80558C48[];
    // Fix note: adds unique named objects to the shared table and fills their three metadata fields.
    int index = 0, num, i, offset, found;
    void *obj, *table;
    const char *name;
    void *(*getAt)(void *, int);
    const char *(*getName)(void *);
    const char *(*getValue)(void *, const char *);
    void *(*getProperty)(void *, const char *);
    getAt = (void *(*)(void *, int))((void **)*(void **)lbl_8055D58C)[3];
    while ((obj = getAt(lbl_8055D58C, index)) != 0) {
        getName = (const char *(*)(void *))((void **)*(void **)obj)[2];
        if (stricmp(getName(obj), (const char *)&lbl_802FD2A0 + 0x10) == 0) {
            getValue = (const char *(*)(void *, const char *))((void **)*(void **)obj)[5];
            name = getValue(obj, (const char *)&lbl_802FD2A0 + 0x20);
            table = lbl_803580A4;
            num = *(int *)((char *)table + 4);
            found = -1;
            offset = 0;
            for (i = 0; i < num; i++) {
                if (stricmp(*(const char **)((char *)*(void **)table + offset), name) == 0) {
                    found = i;
                    break;
                }
                offset += 0x10;
            }
            if (found < 0) {
                num = *(int *)((char *)table + 4);
                found = num;
                *(int *)((char *)table + 4) = num + 1;
                *(const char **)((char *)*(void **)table + num * 0x10) = name;
            }
            table = (char *)*(void **)table + found * 0x10;
            getProperty = (void *(*)(void *, const char *))((void **)*(void **)obj)[7];
            *(void **)((char *)table + 4) = getProperty(obj, (const char *)&lbl_802FD2A0 + 0x30);
            *(void **)((char *)table + 8) = getProperty(obj, lbl_80558C48);
            getValue = (const char *(*)(void *, const char *))((void **)*(void **)obj)[5];
            *(const char **)((char *)table + 0xC) = getValue(obj, (const char *)&lbl_802FD2A0 + 0x10);
        }
        index++;
    }
}
#pragma cplusplus reset

#pragma push
#pragma dont_inline on
s32 fn_80018E3C(void) {
    fn_80018B74();
}

s32 fn_80018E40(void) {
    fn_80018B70();
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling invalid_target
s32 fn_80018E44(const char *arg0, s32 arg1) {
    /* Fix note: select the matching record and reject it only when its mode is newer and its flag is clear. */
    register s32 mode;
    register s32 offset;
    register s32 index;

    if ((u8)lbl_8055D588 != 0) {
        return 1;
    }
    if (stricmp(arg0, lbl_80558C50) == 0) {
        mode = fn_80018E3C();
    } else {
        mode = fn_80018E40();
    }
    index = 0;
    offset = 0;
    goto check;
loop:
    if (stricmp((const char *)arg1,
                *(const char **)((char *)*(void **)lbl_80357E0C + offset + 4)) == 0 &&
        stricmp(arg0,
                *(const char **)((char *)*(void **)lbl_80357E0C + offset)) == 0) {
        char *entry = (char *)*(void **)lbl_80357E0C + index * 0x14;
        s32 rank = *(s32 *)(entry + 8);
        s32 result = 1;
        if (rank > mode && *(u8 *)(entry + 0xC) == 0) {
            result = 0;
        }
        return result;
    }
    offset += 0x14;
    index++;
check:
    if (index < ((s32 *)lbl_80357E0C)[1]) {
        goto loop;
    }
    return 1;
}
#pragma pop
void fn_80018FA8(s32 arg0) {
    fn_80018E44(lbl_80558C50, arg0);
}

s32 fn_80019430(void) {
    return 0;
}

s32 fn_800194C8(void) {
    fn_80019438();
}

extern char lbl_8055D588;
extern s32 lbl_8055DDF8;
extern void *lbl_8055D58C;
extern char lbl_802FD404[];
extern char lbl_802FD3CC[];
extern char lbl_802FD3A0[];
extern char lbl_802FD3B4[];
extern char lbl_802FD434[];
extern void *lbl_802FD2DC;
extern const char lbl_80558C54[];
extern void *lbl_803580A4;
extern u8 lbl_80357E0C[12];
void fn_80019708(void) {
    lbl_8055D588 = 0;
}

char fn_80019714(void) {
    return lbl_8055D588;
}

void fn_800196FC(void) {
    lbl_8055D588 = 1;
}

void fn_800196F0(void) {
    fn_80131234(lbl_802FD404);
}

s32 fn_80019604(void) {
    s32 var_r31;
    volatile u16 result;
    if ((s32)(u8)lbl_8055D588 != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
        result = (u16)fn_80019430();
        if ((result != 0) || (fn_8027DE68(2) != 0)) {
            var_r31 = 1;
        }
    }
    return var_r31;
}

#pragma cplusplus on
#pragma scheduling invalid_target
extern "C" s32 fn_80019664(void) {
    struct Dummy {
        virtual Dummy *f0(void *);
        virtual void f1();
        virtual s32 f2(void *);
        virtual void f3();
        virtual s32 f4(void *, s32);
    };
    if (lbl_8055D58C != 0) {
        if (((Dummy *)lbl_8055D58C)->f2(lbl_802FD3A0) != 0) {
            return ((Dummy *)lbl_8055D58C)->f0(lbl_802FD3A0)->f4(lbl_802FD434, 0);
        }
    }
    return 0;
}
#pragma scheduling on
#pragma cplusplus off
void fn_800195C0(void) {
    if (fn_80019438() != 0) {
        fn_80131234(lbl_802FD3CC);
        return;
    }
    fn_80131234(lbl_802FD404);
}

#pragma cplusplus on
struct Dummy_80019534 {
    virtual Dummy_80019534 *f0(void *);
    virtual void f1();
    virtual s32 f2(void *);
    virtual void f3();
    virtual s32 f4(void *, s32);
};
#pragma scheduling on
#pragma cplusplus on
extern "C" s32 fn_80019534(void) {
    if (lbl_8055D58C) {
        if (((Dummy_80019534 *)lbl_8055D58C)->f2(lbl_802FD3A0) != 0) {
            return ((Dummy_80019534 *)lbl_8055D58C)->f0(lbl_802FD3A0)->f4(lbl_802FD3B4, 0);
        }
    }
    return 0;
}
#pragma cplusplus off
__declspec(section ".data") extern void *lbl_803580A4;
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
s32 fn_80019098(s32 arg0) {
    register s32 index;
    register s32 offset;
    register const char *name;
    char *entry;

    name = (const char *)arg0;
    index = 0;
    offset = 0;
    goto loop;
loop:
    if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name) != 0)
        goto advance;
    goto found;
advance:
    offset += 0x10;
    index++;
    if (index < *(s32 *)((char *)&lbl_803580A4 + 4))
        goto loop;
    index = -1;
found:
    entry = (char *)lbl_803580A4 + index * 0x10 + 4;
    if (index < 0) entry = 0;
    if (entry != 0) return *(s32 *)(entry + 8);
    return 0;
}
#pragma pop

s32 fn_8001EFC0(s32, s32);
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
s32 fn_80019144(s32 arg0) {
    register s32 index;
    register s32 offset;
    register const char *name;
    char *entry;
    s32 value0;
    s32 value1;
    s32 found2;
    s32 result;

    name = (const char *)arg0;
    index = 0;
    offset = 0;
    while (index < *(volatile s32 *)((char *)&lbl_803580A4 + 4)) {
        if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name) == 0)
            goto found;
        offset += 0x10;
        index++;
    }
    index = -1;
found:
    entry = (char *)lbl_803580A4 + index * 0x10 + 4;
    if (index < 0) entry = 0;
    if (entry != 0) {
        if ((u8)lbl_8055D588 != 0) return 1;
        value0 = fn_8001EFC0(0, arg0);
        offset = *(s32 *)entry <= value0;
        value1 = fn_8001EFC0(1, arg0);
        found2 = *(s32 *)(entry + 4) <= value1;
        result = 0;
        if (offset != 0 || found2 != 0)
            result = 1;
        return result;
    }
    return 0;
}
#pragma pop
__declspec(section ".data") extern void *lbl_803580A4;
__declspec(section ".data") extern void *lbl_802FD2A0;
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
int fn_80019258(const char *name, int *out0, int *out1, int unused) {
    register s32 i;
    register s32 offset;
    register const char *name_r;
    register char *p;

    name_r = name;
    i = 0;
    offset = 0;
    while (1) {
        if (stricmp(*(const char **)((char *)lbl_803580A4 + offset), name_r) == 0)
            break;
        offset += 0x10;
        i++;
        if (i >= *(volatile s32 *)((char *)&lbl_803580A4 + 4)) {
            i = -1;
            break;
        }
    }
    p = (char *)lbl_803580A4 + i * 0x10 + 4;
    if (i < 0) p = 0;
    if (p != 0) {
        *out0 = *(s32 *)p;
        *out1 = *(s32 *)(p + 4);
        return 1;
    }
    return 0;
}
#pragma pop
extern s32 fn_8001EFC0(s32, s32);
extern void *lbl_802FD2A0;
#pragma push
#pragma use_lmw_stmw off
#pragma small_data off
#pragma scheduling invalid_target
void fn_8001931C(s32 name) {
    register s32 name_r = name;
    register char *strings = (char *)&lbl_802FD2A0;
    register s32 i = 0;
    register s32 offset = 0;
    char *p;

loop:
    if (stricmp(*(const char **)(*(char **)&lbl_803580A4 + offset), (const char *)name_r) != 0)
        goto advance;
    goto found;
advance:
    i++;
    offset += 0x10;
    if (i < *(volatile s32 *)((char *)&lbl_803580A4 + 4))
        goto loop;
    i = -1;
found:
    p = *(char **)&lbl_803580A4 + i * 0x10 + 4;
    if (i < 0)
        p = 0;
    if (p != 0) {
        s32 inRange = *(s32 *)p <= fn_8001EFC0(0, name_r);
        s32 pastEnd = fn_8001EFC0(1, name_r) >= *(s32 *)(p + 4);
        if (pastEnd) {
            fn_80131234(strings + 0x94);
            return;
        }
        if (inRange) {
            fn_80131234(strings + 0xBC);
            return;
        }
    }
    fn_80131234(strings + 0xE4);
}
#pragma pop
s32 fn_80019438(void) {
    s32 i = 0;

    while (i < (fn_80019088)()) {
        void *entry = fn_80019054(i);
        if (stricmp((char *)entry, lbl_80558C54) == 0) {
            s32 val = ((s32 *)entry)[1];
            if (fn_80019098(val) != 0 && fn_80019144(val) == 0) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

s32 fn_800194CC(void) {
    s32 var_r31;
    s32 (* volatile check194C8)(void);
    check194C8 = fn_800194C8;
    if ((s32)(u8)lbl_8055D588 != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
        if ((fn_80019430() != 0) || (check194C8() != 0) || (fn_80019604() != 0)) {
            var_r31 = 1;
        }
    }
    return var_r31;
}

#pragma push
#pragma use_lmw_stmw off
#pragma scheduling on
#pragma dont_inline on
s32 fn_80018FB4(s32 arg0) {
    register s32 offset;
    register const char *target;
    register s32 i;
    register const char *entry;

    target = lbl_802FD2F4;
    i = 0;
    offset = 0;
    do {
        entry = *(const char **)((u8 *)*(void **)lbl_80357E0C + offset);
        if (stricmp(entry, target) == 0) {
            return *(s32 *)((u8 *)*(void **)lbl_80357E0C + i * 0x14 + 8);
        }
        offset += 0x14;
        i++;
    } while (i < *(s32 *)(lbl_80357E0C + 4));
    ((s32 (*)(const char *, ...))fn_802E317C)(lbl_802FD308, target);
    return 0;
}
#pragma pop
void fn_80018F7C(void) {
    s32 val = (s32)lbl_8055D58C;
    fn_80131818(val);
    lbl_8055D58C = 0;
}

void *fn_80019054(s32 arg0) {
    void *result;
    if (arg0 < 0) goto done;
    if (arg0 >= *(s32 *)(lbl_80357E0C + 4)) goto done;
    result = (void *)((u8 *)*(void **)lbl_80357E0C + arg0 * 0x14);
    return result;
done:
    return 0;
}

s32 fn_80019088(void) {
    return ((s32*)lbl_80357E0C)[1];
}

__declspec(section ".data") extern void *lbl_802FD2DC;
void fn_80018F40(void) {
    lbl_8055D58C = fn_80131808(&lbl_802FD2DC);
    fn_80018BA4();
    fn_80018CCC();
    lbl_8055D588 = 0;
}
void fn_80018B74(void) {
    fn_8001EF60(0);
}
