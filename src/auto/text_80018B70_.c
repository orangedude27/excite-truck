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

void fn_80018BA4(void) {
    extern void *lbl_8055D58C;
    extern unsigned char lbl_80357E0C[12];
    extern void *lbl_802FD2A0;
    extern int strcmp(const char *, const char *);
    extern int fn_80265DCC(void *, int, int, void *);
    extern char lbl_80558C30[];
    extern char lbl_80558C38[];
    extern char lbl_80558C40[];
    // Fix note: scans the manager's objects, appends matching metadata, and sorts the global result table.
    int found = 0, index = 0, count;
    void *object, *manager = lbl_8055D58C, *entry;
    for (;;) {
        object = ((void *(*)(void *, int))((void **)*(void **)manager)[3])(manager, index);
        if (object == 0) break;
        if (strcmp(((const char *(*)(void *))((void **)*(void **)object)[2])(object),
                   (const char *)lbl_802FD2A0) == 0) {
            count = *(int *)((char *)lbl_80357E0C + 4);
            *(int *)((char *)lbl_80357E0C + 4) = count + 1;
            entry = (char *)*(void **)lbl_80357E0C + count * 0x14;
            *(int *)entry = ((int (*)(void *, const char *))((void **)*(void **)object)[5])(object, lbl_80558C30);
            *(int *)((char *)entry + 4) = ((int (*)(void *, const char *))((void **)*(void **)object)[5])(object, lbl_80558C38);
            *(int *)((char *)entry + 8) = ((int (*)(void *, const char *))((void **)*(void **)object)[7])(object, lbl_80558C40);
            *(char *)((char *)entry + 0xC) = 0;
            *(int *)((char *)entry + 0x10) = found++;
        }
        index++;
    }
    fn_80265DCC(*(void **)lbl_80357E0C, *(int *)((char *)lbl_80357E0C + 4), 0x14, fn_80018B7C);
}

void fn_80018CCC(void) {
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

void fn_80018E3C(void) {
    fn_80018B74();
}

void fn_80018E40(void) {
    fn_80018B70();
}

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
    s32 result;
    s8 tmp;

    tmp = lbl_8055D588;
    if (tmp == 0) {
        var_r31 = 0;
        fn_80019430();
        result = fn_8027DE68(2);
        if (result != 0) {
            var_r31 = 1;
        }
    } else {
        var_r31 = 1;
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
    if (lbl_8055D58C != 0) {
        if (((Dummy_80019534 *)lbl_8055D58C)->f2(lbl_802FD3A0) != 0) {
            return ((Dummy_80019534 *)lbl_8055D58C)->f0(lbl_802FD3A0)->f4(lbl_802FD3B4, 0);
        }
    }
    return 0;
}
#pragma cplusplus off
s32 fn_80019098(s32 arg0) {
    void **tbl = (void **)lbl_803580A4;
    s32 count = ((s32 *)tbl)[1];
    s32 idx;
    
    for (idx = 0; idx < count; idx++) {
        char **strs = (char **)((u8 *)tbl[0] + (idx * 0x10));
        if (stricmp(strs[0], (const char *)arg0) == 0) {
            s32 val = ((s32 *)strs[0])[1];
            if (val != 0) {
                s32 result = ((s32 *)strs[0])[2];
                return result;
            }
        }
    }
    
    return 0;
}

s32 fn_8001EFC0(s32, s32);
s32 fn_80019144(s32 arg0) {
    s32 i = 0;
    s32 offset = 0;
    s32 found;
    void *entry;
    s32 value0;
    s32 value1;

    while (1) {
        if (stricmp(*(const char **)(*(char **)lbl_803580A4 + offset), (const char *)arg0) == 0)
            break;
        offset += 0x10;
        i++;
        if (i >= ((s32 *)lbl_803580A4)[1]) {
            i = -1;
            break;
        }
    }
    entry = *(char **)lbl_803580A4 + i * 0x10 + 4;
    if (i < 0)
        entry = 0;
    if (entry == 0)
        return 0;
    if (lbl_8055D588 != 0)
        return 1;
    value0 = fn_8001EFC0(0, arg0);
    found = *(s32 *)entry <= value0;
    value1 = fn_8001EFC0(1, arg0);
    if (found != 0)
        return 1;
    if (*(s32 *)((char *)entry + 4) <= value1)
        return 1;
    return 0;
}

__declspec(section ".data") extern void *lbl_803580A4;
__declspec(section ".data") extern void *lbl_802FD2A0;
int fn_80019258(const char *name, int *out0, int *out1, int unused) {
    int i = 0;
    int offset = 0;
    while (1) {
        if (stricmp(*(const char **)(*(char **)lbl_803580A4 + offset), name) == 0)
            break;
        offset += 0x10;
        i++;
        if (i >= ((int *)lbl_803580A4)[1]) {
            i = -1;
            break;
        }
    }
    {
        char *p = *(char **)lbl_803580A4 + i * 0x10 + 4;
        if (i < 0) p = 0;
        if (p != 0) {
            *out0 = *(int *)p;
            *out1 = *(int *)(p + 4);
            return 1;
        }
    }
    return 0;
}

extern s32 fn_8001EFC0(s32, s32);
extern void *lbl_802FD2A0;
#pragma push
#pragma use_lmw_stmw off
void fn_8001931C(const char *name) {
    void **tbl = (void **)lbl_803580A4;
    s32 count = ((s32 *)tbl)[1];
    s32 i = 0;
    s32 offset = 0;
    while (1) {
        if (stricmp(*(const char **)(*(char **)tbl + offset), name) == 0)
            break;
        offset += 0x10;
        i++;
        if (i >= count) {
            i = -1;
            break;
        }
    }
    {
        char *p = *(char **)tbl + i * 0x10 + 4;
        if (i < 0) p = 0;
        if (p != 0) {
            s32 val0 = *(s32 *)p;
            s32 val1 = fn_8001EFC0(0, (s32)name);
            if (val0 <= val1) {
                if (*(s32 *)(p + 4) != fn_8001EFC0(1, (s32)name)) {
                    fn_80131234((char *)lbl_802FD2A0 + 0x94);
                    return;
                }
                fn_80131234((char *)lbl_802FD2A0 + 0xBC);
                return;
            }
        }
    }
    fn_80131234((char *)lbl_802FD2A0 + 0xE4);
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
    if (lbl_8055D588 != 0) {
        return 1;
    }
    if (fn_80019430() != 0) {
        return 1;
    }
    if (fn_800194C8() != 0) {
        return 1;
    }
    if (fn_80019604() != 0) {
        return 1;
    }
    return 0;
}

s32 fn_80018FB4(s32 arg0) {
    void **base;
    const char *target;
    s32 count;
    s32 idx;
    s32 len;
    void *entry;
    
    base = (void **)lbl_80357E0C;
    target = lbl_802FD2F4;
    count = ((s32 *)base)[1];
    idx = 0;
    len = 0;
    
    while (1) {
        entry = (void *)((u8 *)base[0] + idx * 0x14);
        if (stricmp((char *)entry, target) == 0) {
            return ((s32 *)entry)[2];
        }
        idx++;
        if (idx >= count) {
            break;
        }
    }
    
    fn_802E317C((void *)lbl_802FD308, (void *)lbl_802FD2F4);
    return 0;
}

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
