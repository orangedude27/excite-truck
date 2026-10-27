// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void fn_80137C80(s32);
extern void fn_80137C78(s32);

extern void fn_802411C8(void);
extern int fn_8023FF1C(int);
extern void fn_8023BB0C(void);
extern void fn_8023B9EC(int, int, int, int, int);
extern void fn_8001EFC8(void);
extern int fn_8024A4CC(int *, int *, int *);
extern s32 fn_80128668(void);
extern void fn_8000BF20(void *);
extern void fn_8000C0E8(void);
extern u8 lbl_803413A8[];
extern s32 atoi(void);
extern void fn_802E317C(const char *);
extern const char lbl_80341354[];
extern s32 lbl_8055BB30;
extern s32 fn_802054EC(s32, s32, s32);
extern void fn_802ECC18(s32);
extern void fn_802445FC(s32, s32, s32);
extern void fn_8020A634(void);
extern void fn_8027B77C(void);
extern void fn_80211F4C(void);
extern void fn_8023C0EC(void *, s32, s32);
extern void fn_80018318(void *, s32);
extern void fn_800126B4(void *, void *, s32, s32);
extern void fn_80018440(s32 *, s32, void *);
extern void fn_8000AB48(void *, s32 *);
extern s32 fn_802C9A58(void);
extern void fn_802CED50(s32, s32, s32, s32);
extern const char lbl_80341308[];
s32 fn_8023B764(s32 arg0, s32 arg1) {
    return fn_802054EC((s32)&lbl_80341308, arg0, arg1);
}

#pragma dont_inline on
#pragma scheduling invalid_target
void fn_8023B77C(void) {
    s32 var_r31;
    s32 var_r30;

    var_r31 = 0x129;
    var_r30 = 0x18D;
    if (fn_802C9A58() == 0) {
        var_r31 = 0x136;
        var_r30 = 0x1BC;
    }
    fn_802CED50((var_r31 * 0x280) / 512, 0x188, ((var_r30 - var_r31) * 0x280) / 512, 0x1F);
}
#pragma scheduling on
#pragma dont_inline reset

#pragma push
#pragma scheduling invalid_target
void fn_8023B7EC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8[16];

    fn_802ECC18(0);
    fn_802445FC(arg1, arg2, arg3);
    fn_8023B77C();
    fn_8020A634();
    fn_8027B77C();
    fn_80211F4C();
    fn_8023C0EC(arg0, arg1, arg2);
    fn_80018318((u8 *)arg0 + 0x3F8, arg1);
    fn_800126B4(arg0, (u8 *)arg0 + 0x3F8, 0, 1);
    fn_80018440(sp8, *(s32 *)((u8 *)arg0 + 0x3E4), (u8 *)arg0 + 0x3F8);
    fn_8000AB48(arg0, sp8);
}
#pragma pop
void fn_8023B8AC(s32 arg0) {
    fn_8000ABE0();
    fn_800126C0(arg0, arg0 + 0x3F8);
    fn_80244738();
    fn_8023B77C();
    fn_80211F44();
    if (fn_80019B3C() == 0) fn_8027B690();
    fn_8020A600();
}

#pragma scheduling invalid_target
void fn_8023B904(void *arg0, void *dest, s32 flag) {
    struct Buffer {
        u8 *data;
        s32 field0;
        s32 field1;
        s32 field2;
        u8 bytes[4];
        s32 tail[40];
    } local;
    s32 *source;
    s32 *target;
    s32 count;

    if (flag == 0) {
        local.data = lbl_803413A8;
        ((void (*)(void *, void *))fn_8000BF20)(arg0, &local);
        if (dest != 0) {
            *(s32 *)dest = local.field0;
            target = (s32 *)((u8 *)dest + 0xC);
            *(s32 *)((u8 *)dest + 4) = local.field1;
            *(s32 *)((u8 *)dest + 8) = local.field2;
            ((u8 *)dest)[0xC] = local.bytes[0];
            ((u8 *)dest)[0xD] = local.bytes[1];
            ((u8 *)dest)[0xE] = local.bytes[2];
            source = (s32 *)local.bytes;
            count = 0x14;
            do {
                target[1] = source[1];
                target[2] = source[2];
                source += 2;
                target += 2;
            } while (--count != 0);
        }
    } else {
        fn_8000C0E8();
    }
}
#pragma scheduling on
s32 fn_8023B9AC(s32 arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        fn_80128668();
    }
    return arg0;
}

extern s32 fn_80128314(s32);
extern s32 fn_80265D58(void);
extern s32 fn_80204024(void);
extern void fn_8012BF28(void);
extern void fn_801E952C(void *);
extern void fn_802E30C8(const char *, ...);
extern void fn_80129AEC(s32);
extern s32 fn_802ECEEC(void);
extern void fn_802ECEC0(void);
extern void fn_802ECEC4(void);
extern char lbl_80341314[];
extern char lbl_80341328[];
#pragma scheduling invalid_target
#pragma use_lmw_stmw off
#pragma dont_inline on
void fn_8023B9EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct Context {
        u8 pad[0x3E4];
        s32 value;
        s32 unk;
        s32 arg3;
        s32 zero;
        s32 flags;
        u8 trailing[0x50];
    };
    struct Frame {
        const char *resource;
        s32 resource0;
        s32 resource1;
        s32 resource2;
        struct Context context;
    } frame;
    const char *resource;
    s32 zero;
    s32 active = fn_802ECEEC();
    if (active != 0) {
        fn_802ECEC0();
        resource = lbl_80341314;
        zero = 0;
        frame.resource = resource;
        frame.resource0 = fn_80128314(zero);
        frame.resource1 = fn_80128314(1);
        frame.resource2 = fn_80265D58();
        if (fn_80204024() != 0)
            fn_8012BF28();
        do {
            fn_801E952C(&frame.context);
            fn_8023B7EC(&frame.context, arg0, arg1, arg3);
            frame.context.arg3 = arg3;
            frame.context.zero = zero;
            if (fn_8023B764(arg3, frame.context.value) != 0) {
                fn_802E30C8(resource + 0x14);
                frame.context.flags |= 2;
            }
            fn_8023B904(&frame.context, (void *)arg2, arg4);
            fn_8023B8AC((s32)&frame.context);
        } while (fn_80204024() != 0);
        fn_80129AEC(0);
        if (active != 0)
            fn_802ECEC4();
    }
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
#pragma scheduling on
void fn_8023BB0C(void) {
    s32 sp10, spC, sp8;
    s32 temp_r31 = fn_802411CC();
    s32 var_r30;
    s32 temp_r29;
    fn_800167FC();
    for (var_r30 = 0; var_r30 < temp_r31; var_r30++) {
        temp_r29 = *(s32 *)((u8 *)fn_80016464(var_r30) + 4);
        fn_802411D0(var_r30, &sp10, &sp8, &spC);
        fn_80137C84(spC, var_r30);
        fn_80016A44(var_r30);
        fn_80016970(var_r30, temp_r29, sp10, sp8);
    }
}

#pragma dont_inline on
void fn_8023BBA8(void) {
    s32 sp10;
    s32 spC;
    s32 sp8;

    sp10 = 0;
    spC = 0;
    sp8 = 0;
    goto check;
body:
    fn_802411C8();
    if (fn_8023FF1C(1) != 1) {
        fn_8023BB0C();
        fn_8023B9EC(sp10, spC, 0, sp8, 0);
        fn_8001EFC8();
    }
check:
    if (fn_8024A4CC(&sp10, &spC, &sp8) != 0) goto body;
}
#pragma dont_inline reset

#pragma dont_inline reset
#pragma scheduling on
int fn_8023BC24(int ignored, int arg1, int arg2) {
    int *obj = (int *)fn_8027DB40(1);
    int result = fn_8024DAE0(arg1, arg2, 0, (int)obj, 0, 0);
    if (obj != 0) ((void (*)(int *, int))(*(int **)obj)[2])(obj, 1);
    return result;
}

int fn_8023BCAC(int arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) fn_80128668();
    return arg0;
}

extern u8 lbl_8055F291;
#pragma opt_propagation off
void fn_8023BCEC(void) {
    s32 sp20[0x2C];
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 temp_r31;

    fn_80137C78(1);
    fn_80137C84(fn_802E4A10(), 0);
    sp1C = *(s32 *)((u8 *)fn_80016464(0) + 4);
    sp18 = *(s32 *)((u8 *)fn_80016510(*(s32 *)((u8 *)fn_80016464(0) + 0x4C)) + 4);
    sp14 = *(s32 *)((u8 *)fn_80016464(0) + 0x50);
    sp10 = 0;
    spC = 0;
    sp8 = 0;
loop:
    if (((int (*)(s32 *, s32 *, s32 *, s32))fn_8023BC24)(&sp1C, &sp18, &sp14, 0) == 0) {
        goto loop;
    }
    temp_r31 = lbl_8055F291;
    fn_8000DA10();
    fn_800169F8(fn_8000DB34(), 0);
    fn_80016970(0, sp1C, sp18, sp14);
    fn_8023B9EC(sp10, spC, (s32)sp20, sp8, temp_r31);
    fn_80137C80(0);
    if (fn_8024A4C4((s32)&sp10, (s32)&spC, (s32)&sp8) != 0) {
        goto loop;
    }
}
#pragma opt_propagation reset
extern int fn_80128668(void);
extern int fn_8027DB40(int);
extern int fn_8024DAE0(int, int, int, int, int, int);
extern void fn_802411C8(void);
extern int fn_8023FF1C(int);
extern void fn_8023BB0C(void);
extern void fn_8023B9EC(int, int, int, int, int);
extern void fn_8001EFC8(void);
extern int fn_8024A4CC(int *, int *, int *);
extern int fn_80137C74(void);
extern void fn_80137C80(int);
extern void fn_80137C78(int);
void fn_8023BDEC(void) {
    int i = 0;
    goto check;
body:
    fn_80137C80(i);
    i++;
check:
    if (i < fn_80137C74()) goto body;
    fn_80137C78(1);
}

#pragma dont_inline on
void fn_8023BE38(int ignored, int flag) {
    fn_80012794();
    fn_80012790(0x130);
    fn_802411C8();
    if (flag != 0) {
        fn_8023BBA8();
    } else {
        while (fn_8023FF1C(flag) != 1) {
            fn_8023BB0C();
            fn_8023B5E0();
        }
    }
    fn_8023BDEC();
    fn_80012794();
    fn_80012778();
}
#pragma dont_inline reset

#pragma scheduling off
void fn_8023BEA8(void) {
    extern const char lbl_80341340[];
    fn_8023BE38((int)lbl_80341340, 1);
}
#pragma scheduling reset
extern void *fn_8001285C(void);
extern void *fn_80012820(s32);
extern s32 *fn_80012870(s32, s32);
extern void fn_8023B9EC(s32, s32, s32, s32, s32);
extern void fn_8023BE38(int, int);
extern const char lbl_80341340[];
#pragma dont_inline on
void fn_8023BEB8(s32 arg0, s32 arg1, s32 arg2) {
    fn_8023B9EC(arg0, arg1, arg2, 0, 0);
}
#pragma dont_inline reset

#pragma use_lmw_stmw off
#pragma scheduling invalid_target
void fn_8023BEC4(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r30;
    s32 var_r29;

    temp_r31 = *(s32 *)((u8 *)fn_8001285C() + 4);
    var_r30 = -1;
    var_r29 = *(s32 *)((u8 *)fn_80012820(temp_r31) + 0x70);
    goto check;
body:
    if (arg0 == *fn_80012870(temp_r31, var_r29)) {
        var_r30 = var_r29;
    }
check:
    if (var_r29-- > 0) {
        goto body;
    }
    fn_8023BEB8(temp_r31, var_r30, arg1);
}
#pragma scheduling on
#pragma use_lmw_stmw reset
void fn_8023BF4C(void *arg0) {
    fn_8023B9EC(*(s32 *)((u8 *)arg0 + 0),
                *(s32 *)((u8 *)arg0 + 4),
                *(s32 *)((u8 *)arg0 + 0xC),
                *(s32 *)((u8 *)arg0 + 8), 0);
}

extern s32 atoi(void);
extern void fn_802E317C(const char *);
extern const char lbl_80341354[];
extern s32 lbl_8055BB30;
void fn_8023BF68(void) {
    s32 value = atoi();
    lbl_8055BB30 = value;
    if (value == 0 || (((value >> 31) ^ value) - (value >> 31)) > 4) {
        ((void (*)(const char *, ...))fn_802E317C)(lbl_80341354, value);
    }
}

extern void fn_8000824C(void *, s32);
extern u32 lbl_8055BB3C;
#pragma cplusplus on
void fn_8023C0EC(void *arg0, s32 arg1, s32 arg2) {
    struct StringObject {
        virtual void f0();
        virtual s32 check(const char *);
        virtual void f2();
        virtual const char *get(const char *);
    };
    void *temp_r30 = fn_80012820(arg1);
    s32 *temp_r31 = fn_80012870(arg1, arg2);
    char *source;
    s32 count;
    char *dest;
    if (((StringObject *)*(void **)((u8 *)temp_r31 + 0x20))->check((const char *)&lbl_8055BB3C) != 0) {
        source = (char *)((StringObject *)*(void **)((u8 *)temp_r31 + 0x20))->get((const char *)&lbl_8055BB3C);
        count = 0x20;
        dest = (char *)arg0;
        while ((s8)(*dest++ = *source++) != 0) {
            if (--count <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    } else {
        source = (char *)temp_r30 + 8;
        count = 0x20;
        dest = (char *)arg0;
        while ((s8)(*dest++ = *source++) != 0) {
            if (--count <= 0) {
                dest[-1] = 0;
                break;
            }
        }
    }
    fn_8000824C((u8 *)arg0 + 0x3e4, *temp_r31);
}
#pragma cplusplus reset

void fn_8023C20C(void) {}

void fn_8023C210(void *dst, void *src) {
    register u32 *source;
    register u32 *target;
    int count;
    *(s32 *)((u8 *)dst + 4) = *(s32 *)((u8 *)src + 0);
    *(s32 *)((u8 *)dst + 8) = *(s32 *)((u8 *)src + 4);
    *(s32 *)((u8 *)dst + 0xC) = *(s32 *)((u8 *)src + 8);
    *(u8 *)((u8 *)dst + 0x10) = *((u8 *)src + 0xC);
    *(u8 *)((u8 *)dst + 0x11) = *((u8 *)src + 0xD);
    *(u8 *)((u8 *)dst + 0x12) = *((u8 *)src + 0xE);
    source = (u32 *)((u8 *)src + 0xC);
    target = (u32 *)((u8 *)dst + 0x10);
    count = 0x14;
    do {
        target[1] = source[1];
        target[2] = source[2];
        source += 2;
        target += 2;
    } while (--count != 0);
}

void fn_8023C268(void) {}
#pragma cplusplus on
extern "C" void fn_8023BFBC(s32 arg0, s32 arg1) {}
#pragma cplusplus reset
