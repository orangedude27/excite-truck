#include "revolution/BTE/stack/include/btm_api.h"
#include "revolution/BTE/stack/btm/btm_int.h"
#include "revolution/BTE/stack/include/hcimsgs.h"
#include "revolution/BTE/gki/platform/gki_int.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern int fn_80019BA8(void);
extern int fn_800167F4(void);
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
extern int fn_80128668(void *);
extern int lbl_80338024;
extern int lbl_80338038;
extern int fn_8001BF34(f32);
extern void fn_8001BF0C(f32, f32);
extern int fn_80161C38(void);
extern int fn_801EA994(void);
extern void fn_801CCBA4(void);
extern void fn_801CCAEC(int);
extern void fn_801CCCAC(void);
extern int fn_801CE874(int);
extern void fn_801CCDAC(int, int, int);
extern void fn_801CD4CC(int, int);
extern signed char lbl_8055E880;
extern void fn_801CEA28(void *);
typedef struct {
    s32 field0;
    s32 field4;
    s32 field8;
} Struct_801CE670;
extern void fn_801CB3F8(void);
extern void fn_801CC470(void);
extern void fn_801CC918(void);
void fn_801CB2D8(void) {
    if (fn_80019BA8() == 0) {
        if (fn_80161C38() != 0) return;
        lbl_8055E880 = 1;
        fn_801CC470();
        fn_801CB3F8();
    }
}

void fn_801CB320(void) {
    if (fn_80019BA8() == 0) {
        if (fn_80161C38() != 0) return;
        fn_801CC918();
        fn_801CB3F8();
    }
}

void fn_801CB360(int arg0) {
    if (fn_80019BA8() != 0) return;
    if (fn_80161C38() != 0) goto done;
    fn_801CCAEC(arg0);
done:
    return;
}

void fn_801CB3F8(void) {
    int count, i;
    if (fn_80019BA8() || fn_80161C38()) return;
    count = fn_801EA994();
    for (i = 0; i < count; i++) fn_801CCAEC(i);
}

void fn_801CB464(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBA4();
}

extern void fn_801CCBB4(void);
void fn_801CB4A0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBB4();
}

extern void fn_801CCBC4(void);
void fn_801CB4DC(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CCBC4();
}

void fn_801CB518(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    lbl_8055E880 = 0;
    fn_801CCCAC();
}

void fn_801CB55C(int arg0, int arg1) {
    if (fn_80019BA8() || fn_80161C38()) return;
    if (fn_801CE874(arg0)) {
        fn_801CCDAC(0x22205, arg0, arg1);
        fn_801CD4CC(arg0, arg1);
    }
}

extern void fn_801CC918(void);
extern void fn_801CC470(void);
extern void fn_801CD5B4(int, int, int);
void fn_801CB5DC(int arg0, int arg1, int arg2) {
    if (fn_80019BA8() != 0) return;
    if (fn_80161C38() != 0) goto done;
    fn_801CD5B4(arg0, arg1, arg2);
done:
    return;
}

void fn_801CB648(int arg0, int arg1, f32 farg0) {
    if (fn_80019BA8() != 0) goto done;
    if (fn_80161C38() == 0) {
        fn_801CD7BC(arg0, arg1, farg0);
    }
done:
    return;
}

void fn_801CB6B4(void) {
    if (fn_80019BA8() == 0) {
        int result = fn_80161C38();
        (void)result;
    }
}

extern void fn_801CDDCC(void);
void fn_801CB808(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CDDCC();
}

extern void fn_801CE6F8(void);
void fn_801CB844(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CE6F8();
}

s32 fn_801CB880(void) {
    if ((fn_80019BA8() != 0) || (fn_80161C38() != 0)) {
        return 1;
    }
    return fn_801CE75C();
}

extern void fn_801CE7A0(void);
void fn_801CB8C0(void) {
    if (fn_80019BA8() || fn_80161C38()) return;
    fn_801CE7A0();
}

void fn_801CB8FC(void) {
    fn_801CE8CC();
}

int fn_801CB900(int *arg0, int arg1) {
    int result = 0;
    if (arg0 != 0 && arg1 == fn_8001BD28(*arg0)) {
        result = 1;
    }
    return result;
}

void *__dt__Q34nw4r2ef6EffectFv_801CBCA4(void *arg0, int arg1) {
    extern void fn_801CBCA0(void);
    if (arg0) {
        *(void **)arg0 = (void *)lbl_80338038;
        fn_801CBCA0();
        if (arg1 > 0) fn_80128668(arg0);
    }
    return arg0;
}

void fn_801CBD04(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

void fn_801CC768(void *arg0, float arg1) {
    if (arg1 != *(float *)((char *)arg0 + 8)) {
        *(float *)((char *)arg0 + 8) = arg1;
        *((char *)arg0 + 0x4D) = 1;
    }
}

void **fn_801CC784(void *arg0) {
    void **base = *(void ***)arg0;
    int index = *(int *)((char *)arg0 + 4);
    *(int *)((char *)arg0 + 4) = index + 1;
    return (void **)((char *)base + (index << 2));
}

void fn_801CC8EC(void *arg0) {
    *(void **)((char *)arg0 + 4) = arg0;
    *(int *)arg0 = 0;
}

void fn_801CC8FC(void *arg0) {
    *(int *)arg0 = (int)((char *)arg0 + 12);
    *(int *)((char *)arg0 + 8) = 7;
    *(int *)((char *)arg0 + 4) = 0;
}

void fn_801CE670(Struct_801CE670 *arg0, s32 arg1, s32 arg2) {
    Struct_801CE670 local;
    local.field4 = arg1;
    local.field0 = 5;
    local.field8 = arg2;
    *arg0 = local;
}

void fn_801CE698(void) {

}

void fn_801CE69C(void) {

}

void fn_801CE6A0(void) {

}

void fn_801CE6A4(Struct_801CE670 *arg0, s32 arg1, s32 arg2) {
    Struct_801CE670 local;
    local.field4 = arg1;
    local.field0 = 1;
    local.field8 = arg2;
    *arg0 = local;
}

void fn_801CE6CC(void) {

}

extern unsigned char *fn_801EA9A0(void);
extern void *lbl_8055E884;
extern void fn_801CBD48(void *, void *);
extern void fn_802AE220(void *);
extern void fn_8001DFCC(void);
void fn_801CE6D0(void *arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    spC = arg1;
    sp8 = 3;
    sp10 = arg2;
    *(s32 *)((char *)arg0 + 0) = 3;
    *(s32 *)((char *)arg0 + 4) = arg1;
    *(s32 *)((char *)arg0 + 8) = arg2;
}

unsigned int fn_801CE898(void) {
    int value = fn_800167F4();
    int temp = value ^ 1;
    int half = temp >> 1;
    temp &= value;
    return (unsigned int)(half - temp) >> 31;
}

void fn_801CEA28(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

extern int fn_80128668(void *);
extern void fn_801CBD04(void *);
extern int lbl_80338024;
extern int lbl_80338038;
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
int fn_801CEA6C(void *arg0, int arg1) {
    int value = *(int *)arg0;
    if (fn_8001C0EC(value) == 0) goto done;
    fn_8001C0E8(value, arg1);
    value = *(int *)((char *)arg0 + 8);
    if (value != 0 && fn_8001C0EC(arg1) == 0) goto done;
    value = *(int *)((char *)arg0 + 0xC);
    if (value != 0 && fn_8001C0EC(arg1) == 0) goto done;
    return 1;
done:
    return 0;
}

void fn_801CEB94(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

s32 fn_801CEBD8(void *arg0, f32 farg0) {
    f32 temp = *(f32 *)arg0;
    if (fn_8001BF34(temp) != 0) {
        fn_8001BF0C(temp, farg0);
        if (*(s32 *)((char *)arg0 + 8) != 0) {
            if (fn_8001BF34(farg0) != 0) {
                if (*(s32 *)((char *)arg0 + 0xC) != 0) {
                    if (fn_8001BF34(farg0) != 0) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

