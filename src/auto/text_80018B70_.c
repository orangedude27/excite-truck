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
void fn_80018E44(const char *, s32);
s32 fn_802E317C(void *, void *);
void fn_80018BA4(void);
void fn_80018CCC(void);
void *fn_80131808(void *);
extern const char lbl_80558C50[];
extern const char lbl_802FD2F4[];
extern const char lbl_802FD308[];
void fn_80018B74(void);
void fn_8027DEAC(void);
s32 stricmp(const char *, const char *);

// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

void fn_80018B70(void) {
    fn_8027DEAC();
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
extern void *lbl_802FD404;
extern void *lbl_802FD3CC;
extern void *lbl_802FD3A0;
extern void *lbl_802FD3B4;
extern void *lbl_802FD2DC;
extern const char lbl_80558C54[];
extern void *lbl_803580A4;
extern void *lbl_80357E0C;
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
    void *ptr = (void *)0x802FD404;
    fn_80131234(ptr);
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

void fn_800195C0(void) {
    if (fn_80019438() != 0) {
        fn_80131234((void *)0x802FD3CC);
        return;
    }
    fn_80131234((void *)0x802FD404);
}

s32 fn_80019534(void) {
    s32 ret;
    void **obj;
    void **vtable;

    obj = (void **)lbl_8055D58C;
    if (obj != 0) {
        vtable = (void **)obj[0];
        ret = ((s32 (*)(void *))vtable[4])((void *)0x802FD3A0);
        if (ret != 0) {
            obj = (void **)lbl_8055D58C;
            vtable = (void **)obj[0];
            ret = ((s32 (*)(void *))vtable[2])((void *)0x802FD3A0);
            ret = ((s32 (*)(void *, s32))vtable[6])((void *)0x802FD3B4, 0);
        }
    }
    return ret;
}

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

s32 fn_80019438(void) {
    s32 i = 0;

    while (i < fn_80019088()) {
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
    void *base = lbl_80357E0C;
    const char *target = lbl_802FD2F4;
    s32 count = ((s32 *)base)[1];
    s32 idx;
    
    for (idx = 0; idx < count; idx++) {
        char **entry = (char **)((u8 *)((void **)base)[0] + idx * 0x14);
        if (stricmp(entry[0], target) == 0) {
            return ((s32 *)entry)[2];
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
    void *base;
    s32 count;
    void *result;
    if (arg0 < 0) {
        goto ret_zero;
    }
    base = lbl_80357E0C;
    count = ((s32 *)base)[1];
    if (arg0 >= count) {
        goto ret_zero;
    }
    result = (void *)((u8 *)((s32 *)base)[0] + arg0 * 0x14);
    return result;
ret_zero:
    return (void *)0;
}

void fn_80018F40(void) {
    lbl_8055D58C = fn_80131808(&lbl_802FD2DC);
    fn_80018BA4();
    fn_80018CCC();
    lbl_8055D588 = 0;
}

