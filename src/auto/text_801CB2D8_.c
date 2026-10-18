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
#pragma push
#pragma small_data off
extern char lbl_80338024[];
extern char lbl_80338038[];
#pragma pop
extern int fn_8001BF34(f32);
extern void fn_8001BF0C(f32, f32);
extern int fn_80161C38(void);
extern s32 *lbl_8055E884;
extern unsigned char *fn_801EA9A0(void);
extern int fn_801EA994(void);
extern void fn_801CCBA4(void);
extern void fn_801CCAEC(int);
extern void fn_801CCB48(int);
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
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCAEC(arg0);
done:
    return;
}

void fn_801CB3AC(int arg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CCB48(arg0);
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
#pragma scheduling off
void fn_801CB5DC(int arg0, int arg1, int arg2) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD5B4(arg0, arg1, arg2);
done:
    return;
}
#pragma scheduling off
void fn_801CB648(int arg0, int arg1, f32 farg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD7BC(arg0, arg1, farg0);
done:
    return;
}
#pragma scheduling on
void fn_801CB6B4(void) {
    if (fn_80019BA8() == 0) {
        if (fn_80161C38() != 0) return;
    }
}

extern void fn_801CD970(int);
void fn_801CB7BC(int arg0) {
    if (fn_80019BA8() != 0) goto done;
    switch (fn_80161C38()) {
    case 0:
        goto action;
    default:
        goto done;
    }
action:
    fn_801CD970(arg0);
done:
    return;
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
    extern void fn_801CBD04(void *);
    if (arg0) {
        *(void **)((char *)arg0 + 4) = lbl_80338038;
        fn_801CBD04(arg0);
        if (arg1 > 0)
            fn_80128668(arg0);
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

void fn_801CCAEC(int arg0) {
    int index;
    unsigned char *manager;
    char *base;
    (void)arg0;
    base = (char *)lbl_8055E884;
    manager = fn_801EA9A0();
    if (*manager != 0) {
        index = manager[0xB4] & 3;
    } else {
        index = -1;
    }
    if (index >= 0) {
        *(signed char *)(base + index + 0x11) = 1;
    }
}

void fn_801CCB48(int arg0) {
    int index;
    unsigned char *manager;
    char *base;
    (void)arg0;
    base = (char *)lbl_8055E884;
    manager = fn_801EA9A0();
    if (*manager != 0) {
        index = manager[0xB4] & 3;
    } else {
        index = -1;
    }
    if (index >= 0) {
        *(signed char *)(base + index + 0x11) = 0;
    }
}

void fn_801CCBA4(void) {
    *((s8 *)lbl_8055E884 + 0x10) = 1;
}

void fn_801CCBB4(void) {
    *((signed char *)lbl_8055E884 + 0x10) = 0;
}

extern void fn_80235380(void);
extern void deleteThreads__6SystemFv(void *);
void fn_801CCCAC(void) {
    s32 i;
    s32 offset;
    s32 *state;
    void *object;

    state = lbl_8055E884;
    if (state != 0) {
        if (state[3] != 0) fn_80235380();
        state[3] = 0;
        object = *(void **)((char *)state + 8);
        if (object != 0) {
            if (object != 0)
                ((void (*)(void *, int))((u32 *)*(u32 *)object)[2])(object, 1);
        }
        deleteThreads__6SystemFv((char *)state + 0x40);
        deleteThreads__6SystemFv((char *)state + 0x2A4);
        i = 0;
        offset = 0;
        do {
            object = *(void **)((char *)*(void **)((char *)state + 0x18) + offset);
            if (object != 0)
                ((void (*)(void *, int))((u32 *)*(u32 *)((char *)object + 4))[2])(object, 1);
            offset += 4;
            i++;
        } while (i < *(s32 *)((char *)state + 0x1C));
        *(s32 *)((char *)state + 0x1C) = 0;
        if ((char *)state + 0x18 != 0) {
            *(s32 **)((char *)state + 0x18) = 0;
            *(s32 *)((char *)state + 0x1C) = 0;
            *(s32 *)((char *)state + 0x20) = 0;
        }
        fn_80128668(state);
    }
    lbl_8055E884 = 0;
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
extern s32 *lbl_8055E884;
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

extern unsigned int fn_801CE898(void);
extern void fn_802ADE60(int);
void fn_801CE7A0(void) {
    s32 *state;
    void *ptr;
    if (fn_801CE898() != 0) return;
    state = lbl_8055E884;
    ptr = (void *)state[0x2C8 / 4];
    if (ptr != 0) { fn_802ADE60(1); state[0x2C8 / 4] = 0; }
    ptr = (void *)state[0x2CC / 4];
    if (ptr != 0) { if (ptr != 0) ((void (*)(void *, int))((u32 *)*(u32 *)ptr)[2])(ptr, 1); state[0x2CC / 4] = 0; }
    ptr = (void *)state[0x2D0 / 4];
    if (ptr != 0) { if (ptr != 0) ((void (*)(void *, int))((u32 *)*(u32 *)ptr)[2])(ptr, 1); state[0x2D0 / 4] = 0; }
    ptr = (void *)state[0x2D4 / 4];
    if (ptr != 0) { if (ptr != 0) ((void (*)(void *, int))((u32 *)*(u32 *)ptr)[2])(ptr, 1); state[0x2D4 / 4] = 0; }
}

unsigned int fn_801CE898(void) {
    int value = fn_800167F4();
    int temp = value ^ 1;
    int half = temp >> 1;
    temp &= value;
    return (unsigned int)(half - temp) >> 31;
}

extern s32 *__AXFXGetLfoSinTable_801769CC(void);
extern int fn_8000DA10(void);
extern void *fn_8001BB58(s32, s32, s32);
extern int fn_80160AB4(void);
extern void fn_801CD730(s32 *, s32 *);
#pragma dont_inline on
int fn_801CE8CC(void) {
    s32 spC;
    s32 sp8;
    s32 *temp_r30;
    s32 *temp_r31;
    s32 temp_r0;
    s32 temp_r29;
    void *temp_r3;
    if (fn_801CE898() != 0) return 1;
    temp_r29 = fn_80160AB4();
    temp_r30 = __AXFXGetLfoSinTable_801769CC();
    temp_r31 = __AXFXGetLfoSinTable_801769CC();
    temp_r3 = (void *)fn_8000DA10();
    temp_r3 = ((void *(*)(int, s32, s32, s32))fn_8001BB58)((int)temp_r3, *temp_r31, temp_r30[2], 0);
    if (temp_r3 != NULL) {
        temp_r0 = ((s32 *)temp_r3)[2];
        if ((temp_r0 >= 0) && (temp_r0 <= temp_r29)) return 1;
    }
    spC = -1;
    sp8 = 0;
    fn_801CD730(&sp8, &spC);
    if ((spC >= 0) && (spC <= temp_r29)) return 1;
    return 0;
}
#pragma dont_inline reset
void *fn_801CE9A0(void *arg0, s32 arg1) {
    if (arg0 != 0) {
        *(void **)((char *)arg0 + 4) = lbl_80338024;
        fn_801CEA28((char *)arg0 + 8);
        fn_801CEA28((char *)arg0 + 0xC);
    }
    if (arg0 != 0) {
        void (*cleanup)(void *) = fn_801CBD04;
        *(void **)((char *)arg0 + 4) = lbl_80338038;
        cleanup(arg0);
    }
    if (arg1 > 0)
        fn_80128668(arg0);
    return arg0;
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
extern int fn_8001C0EC(int);
extern int fn_8001C0E8(int, int);
#pragma scheduling off
int fn_801CEA6C(void *arg0, int arg1) {
    int value;
    value = *(int *)arg0;
    if (fn_8001C0EC(value) == 0) goto fail;
    fn_8001C0E8(value, arg1);
    value = *(int *)((char *)arg0 + 8);
    if (value == 0) goto fail;
    if (((int (*)(int, int))fn_8001C0EC)(value, arg1) == 0) goto fail;
    value = *(int *)((char *)arg0 + 0xC);
    if (value == 0) goto fail;
    if (((int (*)(int, int))fn_8001C0EC)(value, arg1) == 0) goto fail;
    return 1;
fail:
    return 0;
}
#pragma scheduling on
void fn_801CEB94(void *arg0) {
    void *buf = *(void **)arg0;
    if (buf != NULL) {
        fn_80128668(buf);
        *(void **)arg0 = NULL;
    }
}

s32 fn_801CEBD8(void *arg0, f32 farg0) {
    s32 temp = *(s32 *)arg0;
    if (fn_8001BF34(farg0) != 0) {
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

