#include <types.h>

s32 fn_80019430(void);
s32 fn_80019438(void);
void *fn_80019054(s32);
s32 fn_80019088(void);
s32 fn_80019098(s32);
s32 fn_80019144(s32);
s32 fn_8027DE68(s32);
void fn_80131234(void *);
void fn_80018B74(void);
void fn_8027DEAC(void);

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

s32 fn_80019430(void) {
    return 0;
}

void fn_800194C8(void) {
    fn_80019438();
}

extern char lbl_8055D588;
extern void *lbl_8055D58C;
extern void *lbl_802FD404;
extern void *lbl_802FD3CC;
extern void *lbl_802FD3A0;
extern void *lbl_802FD3B4;
extern const char *lbl_80558C54;
extern void *lbl_803580A4;
extern void *lbl_80357E0C;

s32 fn_80019088(void);
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

